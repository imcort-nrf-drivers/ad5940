/**  
 * @file       NRF52832Port.c
 * @brief      NRF52832 board port file.
 * @version    V0.1.0
 * @author     YZ
 * @date       October 2022
 * @par Revision History:
 * 
**/

#include "transfer_handler.h"

volatile uint8_t ucInterrupted = 0;       /* Flag to indicate interrupt occurred */

/**
	@brief Using SPI to transmit N bytes and return the received bytes. This function targets to 
                     provide a more efficent way to transmit/receive data.
	@param pSendBuffer :{0 - 0xFFFFFFFF}
      - Pointer to the data to be sent.
	@param pRecvBuff :{0 - 0xFFFFFFFF}
      - Pointer to the buffer used to store received data.
	@param length :{0 - 0xFFFFFFFF}
      - Data length in SendBuffer.
	@return None.
**/

void AD5940_ReadWriteNBytes(unsigned char *pSendBuffer, unsigned char *pRecvBuff, unsigned long length)
{
    
    if (length == 1)
    {
        spi_transfer(pSendBuffer, length, pRecvBuff, 0);
    }
    else
    {
        spi_transfer(pSendBuffer, length, pRecvBuff, length);
    }
    
}

void AD5940_CsClr(void)
{
	digitalWrite(AD5940_SS_PIN, 0);
}

void AD5940_CsSet(void)
{
    digitalWrite(AD5940_SS_PIN, 1);
}

void AD5940_RstSet(void)
{
    #ifdef AD5940_RST_PIN
        digitalWrite(AD5940_RST_PIN, 1);
    #endif
}

void AD5940_RstClr(void)
{
    #ifdef AD5940_RST_PIN
        digitalWrite(AD5940_RST_PIN, 0);
    #endif
}

void AD5940_Delay10us(uint32_t time)
{
	if (time == 0)
	{
			return;
	}
	do {
			nrf_delay_us(10);
	} while (--time);
}

uint32_t AD5940_GetMCUIntFlag(void)
{
	return ucInterrupted;//!digitalRead(AD5940_INT_PIN);
}

uint32_t AD5940_ClrMCUIntFlag(void)
{
    //NVIC_ClearPendingIRQ(GPIOTE_IRQn);
	ucInterrupted = 0;
	return 1;
}

#include "nrf_drv_gpiote.h"

void AD5940_interrupt_handler(nrf_drv_gpiote_pin_t pin, nrf_gpiote_polarity_t action)
{

    if((pin == AD5940_INT_PIN) && (action == NRF_GPIOTE_POLARITY_HITOLO))
    {
        //NVIC_ClearPendingIRQ(GPIOTE_IRQn);
        //Debug("INT");
        ucInterrupted = 1;
    }
    
}

uint32_t AD5940_MCUResourceInit(void *pCfg)
{
	
	spi_init();
    pinMode(AD5940_SS_PIN, OUTPUT);
    
    #ifdef AD5940_RST_PIN
        pinMode(AD5940_RST_PIN, OUTPUT);
    #endif
    
    attachInterrupt(AD5940_INT_PIN, AD5940_interrupt_handler, FALLING);

	AD5940_CsSet();
	AD5940_RstSet();
	
	return 0;
}




