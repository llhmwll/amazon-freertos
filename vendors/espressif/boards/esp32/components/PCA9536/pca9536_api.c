#include "pca9536_api.h"


PCA9536_Error
PCA9536_Init(void)
{
    PCA9536_Error ret = PCA9536_ERR_NONE;
    uint8_t data = NULL;

    /* Read configuration register default data */

    ret = PCA9536_RdByte( dev, PCA9536_CTRL_CMD_CONFIGURATION_REG, &data );
    if ( ret != PCA9536_ERR_NONE){
        ret = PCA9536_ERR_INIT_CHECK_I2C;
    }

    /* check default data */
    if ( data != 0xff){
        ret = PCA9536_ERR_INIT_DATA_CEHCK;
    }

    return ret;
}



PCA9536_Error
PCA9536_Configuration ( PCA9536_DEV dev, uint8_t nbitpos, uint8_t nEnable )
{
    PCA9536_Error ret = PCA9536_ERR_NONE;
    uint8_t ndata;
    
    if (nEnable != PCA9536_CTRL_SET_INPUT_ENABLE  && 
        nEnable != PCA9536_CTRL_SET_OUTPUT_ENABLE){
        return PCA9536_ERR_CONFIG_GPIO_DIRECTION_SET;
    }

    /* Read Configuration REG data */
    ret = PCA9536_RdByte( dev, PCA9536_CTRL_CMD_CONFIGURATION_REG, &ndata );
    if ( ret != PCA9536_ERR_NONE ){
        goto DONE;
    }

    if (nEnable == PCA9536_CTRL_SET_INPUT_ENABLE){
        PCA9536_BIT_SET(ndata, nbitpos);
    }
    else{
        PCA9536_BIT_CLEAR(ndata, nbitpos);
    }
    
    ret = PCA9536_WrByte( dev, PCA9536_CTRL_CMD_CONFIGURATION_REG, ndata );
    if ( ret != PCA9536_ERR_NONE ){
        goto DONE;
    }
DONE:
    return ret;
}

PCA9536_Error
PCA9536_Read_Input_data ( PCA9536_DEV dev, uint8_t* pdata )
{
    PCA9536_Error ret =  PCA9536_ERR_NONE;

    /* Read Input data */
    ret = PCA9536_RdByte( dev, PCA9536_CTRL_CMD_INPUT_PORT, pdata );

    return ret;
}

PCA9536_Error
PCA9536_SET_Output_data ( PCA9536_DEV dev, uint8_t nbitpos, uint8_t nLevel )
{
    PCA9536_Error ret = PCA9536_ERR_NONE;
    uint8_t ndata;
    
    if (nLevel != 0  && nLevel != 1 ){
        return PCA9536_ERR_CONFIG_LEVEL_SET;
    }

    /* Read Outport REG data */
    ret = PCA9536_RdByte( dev, PCA9536_CTRL_CMD_OUTPUT_PORT, &ndata );
    if ( ret != PCA9536_ERR_NONE ){
        goto DONE;
    }

    if (nLevel == 1){
        PCA9536_BIT_SET(ndata, nbitpos);
    }
    else{
        PCA9536_BIT_CLEAR(ndata, nbitpos);
    }
    
    ret = PCA9536_WrByte( dev, PCA9536_CTRL_CMD_CONFIGURATION_REG, ndata );
    if ( ret != PCA9536_ERR_NONE ){
        goto DONE;
    }
DONE:
    return ret;
}


PCA9536_Error
PCA9536_Polarity_Inversion ( PCA9536_DEV dev, uint8_t nbitpos, uint8_t nEnable )
{
    PCA9536_Error ret = PCA9536_ERR_NONE;
    uint8_t ndata;
    
    if (nEnable != PCA9536_CTRL_SET_POLARITY_INVERSION_ENABLE  && 
        nEnable != PCA9536_CTRL_SET_POLARITY_INVERSION_DISABLE){
        return PCA9536_ERR_POLARITY_INVERSION_SET;
    }

    /* Read Configuration REG data */
    ret = PCA9536_RdByte( dev, PCA9536_CTRL_CMD_POLARITY_INVERSION_REG, &ndata );
    if ( ret != PCA9536_ERR_NONE ){
        goto DONE;
    }

    if (nEnable == PCA9536_CTRL_SET_POLARITY_INVERSION_ENABLE){
        PCA9536_BIT_SET(ndata, nbitpos);
    }
    else{
        PCA9536_BIT_CLEAR(ndata, nbitpos);
    }
    
    ret = PCA9536_WrByte( dev, PCA9536_CTRL_CMD_POLARITY_INVERSION_REG, ndata );
    if ( ret != PCA9536_ERR_NONE ){
        goto DONE;
    }
DONE:
    return ret;
}