#ifndef __PCA9536_PLATFORM__
#define __PCA9536_PLATFORM__

#include "pca9536_api.h"
#include "driver/i2c.h"

typedef i2c_port_t I2C_HandleTypeDef;

typedef struct {
	I2C_HandleTypeDef *I2cHandle;
    uint8_t   I2cDevAddr;
} PCA9536_Dev_t;

typedef PCA9536_Dev_t *PCA9536_DEV;

typedef uint8_t PCA9536_Error;


PCA9536_Error PCA9536_WrByte(PCA9536_DEV Dev, uint8_t cmd, uint8_t data);
PCA9536_Error PCA9536_RdByte(PCA9536_DEV Dev, uint8_t index, uint8_t *data);
#endif