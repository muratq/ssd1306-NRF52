#include <string.h>
#include "USER_I2C.h"
#include "nrf_delay.h"
#include "boards.h"
/*---------------------------------------------------------------------------*/
/* Global variables                                                          */
/*---------------------------------------------------------------------------*/
uint8_t txDat = 0x08; // Read Touch-key Status Data Register Address
uint8_t rxDat[2];

#define TWI_INSTANCE_ID     0

#define I2C_SCL_PIN       23
#define I2C_SDA_PIN       22

void twi_init (void)
{
    ret_code_t err_code;

    const nrf_drv_twi_config_t ssd1306_config = {
       .scl                = I2C_SCL_PIN,
       .sda                = I2C_SDA_PIN,
       .frequency          = NRF_DRV_TWI_FREQ_400K,
       .interrupt_priority = APP_IRQ_PRIORITY_LOW_MID,
       .clear_bus_init     = false
    };

    err_code = nrf_drv_twi_init(&m_twi, &ssd1306_config,NULL, NULL);
    APP_ERROR_CHECK(err_code);

}

void I2C_Enable(void)
{

    nrf_drv_twi_enable(&m_twi);
    
}




void ssd1306_I2C_WriteMulti(uint8_t address, uint8_t reg, uint8_t* data, uint16_t count) 
{
    uint8_t dt[256];
    dt[0] = reg;
    uint8_t i;
    for(i = 0; i < count; i++)
    dt[i+1] = data[i];
    nrf_drv_twi_tx(&m_twi, address, dt,count+1, false);
}


void I2C0_Write(uint8_t address, uint8_t reg, int8_t data)
{
    ret_code_t err_code;
    uint8_t dt[2];
    dt[0] = reg;
    dt[1] = data;
    if(!nrf_drv_twi_is_busy(&m_twi))
    {
        err_code = nrf_drv_twi_tx(&m_twi, address,dt,2,false);
    }
    APP_ERROR_CHECK(err_code);
}


void I2C0_Read(uint8_t u8Address, uint8_t *pu8Data , uint8_t u8Byte)
{
 //if(!nrf_drv_twi_is_busy(&m_twi))
  //  {
        nrf_drv_twi_rx(&m_twi,u8Address,pu8Data,u8Byte);
  //  }
}


void driver_i2c_deinit(void)
{

}
