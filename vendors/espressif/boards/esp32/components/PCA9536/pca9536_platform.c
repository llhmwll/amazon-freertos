#include "pca9536_platform.h"

//#define I2C_PORT                        I2C_NUM_1
#define WRITE_BIT                       I2C_MASTER_WRITE
#define READ_BIT                        I2C_MASTER_READ
#define ACK_CHECK_EN                    0x1
#define ACK_CHECK_DIS                   0x0
#define ACK_VAL                         0x0
#define NACK_VAL                        0x1

uint8_t _I2CBuffer[2];

int
_I2CWrite(PCA9536_DEV Dev, uint8_t *buf, uint32_t len)
{
    i2c_cmd_handle_t cmd = i2c_cmd_link_create();
    i2c_master_start(cmd);
    i2c_master_write_byte(cmd, ((Dev->I2cDevAddr << 1)| WRITE_BIT), ACK_CHECK_EN);
    i2c_master_write(cmd, buf, len, ACK_CHECK_EN);
    i2c_master_stop(cmd);
    esp_err_t ret = i2c_master_cmd_begin((i2c_port_t)*Dev->I2cHandle, cmd, 1000 / portTICK_PERIOD_MS);
    i2c_cmd_link_delete(cmd);
    if (ret != ESP_OK) {
        return -1;
    }
    return 0;
}

int
_I2CRead(PCA9536_DEV Dev, uint8_t *buf, uint32_t len)
{
    i2c_cmd_handle_t cmd = i2c_cmd_link_create();
    i2c_master_start(cmd);
    i2c_master_write_byte(cmd, ((Dev->I2cDevAddr << 1) | READ_BIT), ACK_CHECK_EN);
    if (len > 1) {
        i2c_master_read(cmd, buf, len - 1, ACK_VAL);
    }
    i2c_master_read_byte(cmd, buf + len - 1, NACK_VAL);
    i2c_master_stop(cmd);
    esp_err_t ret = i2c_master_cmd_begin((i2c_port_t)*Dev->I2cHandle, cmd, 1000 / portTICK_PERIOD_MS);
    i2c_cmd_link_delete(cmd);
    if (ret != ESP_OK) {
        return -1;
    }
    return 0;
}


PCA9536_Error
PCA9536_WrByte(PCA9536_DEV Dev, uint8_t cmd, uint8_t data)
{
    PCA9536_Error Status = PCA9536_ERR_NONE;

    _I2CBuffer[0] = cmd & 0xFF;
    _I2CBuffer[1] = data;

    Status = _I2CWrite(Dev, _I2CBuffer, 2);
    if (Status != 0) {
        Status = PCA9536_ERR_I2C_WR;
    }

    return Status;
}

PCA9536_Error
PCA9536_RdByte(PCA9536_DEV Dev, uint8_t index, uint8_t *data)
{
    PCA9536_Error Status = PCA9536_ERR_NONE;

	_I2CBuffer[0] = index;

    Status = _I2CWrite(Dev, _I2CBuffer, 1);
    if( Status ){
        Status = PCA9536_ERR_I2C_WR;
        goto done;
    }
    Status = _I2CRead(Dev, data, 1);
    if (Status != 0) {
        Status = PCA9536_ERR_I2C_RD;
    }
done:
    return Status;
}