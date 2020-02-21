
#ifndef __PCA9536_API__
#define __PCA9536_API__

#include "pca9536_platform.h"

/* Register Map */
#define PCA9536_REG_I2C_SLAVE_ADDR                      (0x41 << 1)

/* I/O DATA Bus Bit Pos */          
#define PCA9536_REG_I_O_DATA_BUS_P0_BIT_POS             (0x01)
#define PCA9536_REG_I_O_DATA_BUS_P1_BIT_POS             (0x01 << 1)
#define PCA9536_REG_I_O_DATA_BUS_P2_BIT_POS             (0x01 << 2)
#define PCA9536_REG_I_O_DATA_BUS_P3_BIT_POS             (0x01 << 3)

/* Control Register Command byte */
#define PCA9536_CTRL_CMD_INPUT_PORT                     (0x00)
#define PCA9536_CTRL_CMD_OUTPUT_PORT                    (0x01)
#define PCA9536_CTRL_CMD_POLARITY_INVERSION_REG         (0x02)
#define PCA9536_CTRL_SET_POLARITY_INVERSION_ENABLE      (0)
#define PCA9536_CTRL_SET_POLARITY_INVERSION_DISABLE     (1)


#define PCA9536_CTRL_CMD_CONFIGURATION_REG              (0x03)
#define PCA9536_CTRL_SET_OUTPUT_ENABLE                  (0)
#define PCA9536_CTRL_SET_INPUT_ENABLE                   (1)

#define PCA9536_ERR_NONE                                (0x00)
#define PCA9536_ERR_FAIL                                (0xff)
#define PCA9536_ERR_I2C_WR                              (0x01)
#define PCA9536_ERR_I2C_RD                              (0x02)
#define PCA9536_ERR_CONFIG_LEVEL_SET                    (0x03)
#define PCA9536_ERR_CONFIG_GPIO_DIRECTION_SET           (0x04)
#define PCA9536_ERR_POLARITY_INVERSION_SET              (0x05)
#define PCA9536_ERR_INIT_CHECK_I2C                      (0x06)
#define PCA9536_ERR_INIT_DATA_CEHCK                     (0x07)


#define PCA9536_BIT_SET(a,b)                            ( (a) |= (1 << (b) ))
#define PCA9536_BIT_CLEAR(a,b)                          ( (a) &= ~(1 << (b) ))

#endif