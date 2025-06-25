/*
 * defines_pins.h
 *
 *  Created on: Sep 21, 2020
 *  Author:
 */

#ifndef APP_DRIVER_I2C_H
#define APP_DRIVER_I2C_H

#include "nrf.h"
#include "nrf_drv_twi.h"

typedef void (*I2C_FUNC)(uint32_t u32Status);
extern I2C_FUNC s_I2CHandlerFn ;

static const nrf_drv_twi_t m_twi = NRF_DRV_TWI_INSTANCE(0);

extern uint8_t txDat ; // Read Touch-key Status Data Register Address
extern uint8_t rxDat[2];

void twi_init(void);
void ssd1306_I2C_WriteMulti(uint8_t address, uint8_t reg, uint8_t* data, uint16_t count) ;
void driver_i2c_deinit(void);
void I2C0_MasterTx(uint32_t u32Status);
void I2C0_MasterRx(uint32_t u32Status);
void I2C0_Write(uint8_t address, uint8_t reg, int8_t data);
void I2C0_Read(uint8_t u8Address, uint8_t *pu8Data , uint8_t u8Byte);
void I2C_Enable(void);

#endif
