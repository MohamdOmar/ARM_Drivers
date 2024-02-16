/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  IntCtrl_Types.h
 *       Module:  IntCtrl
 *
 *  Description:      
 *  
 *********************************************************************************************************************/
#ifndef IntCtrl_Types_H
#define IntCtrl_Types_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "IntCtrl_Cfg.h"


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define GRP_3_SUBGRP_0_MODE    0x05FA0400
#define GRP_2_SUBGRP_1_MODE    0x05FA0500
#define GRP_1_SUBGRP_2_MODE    0x05FA0600
#define GRP_0_SUBGRP_3_MODE    0x05FA0700

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef enum
{
	GPIO_PORTA = 0,
	GPIO_PORTB = 1,
	GPIO_PORTC = 2,
	GPIO_PORTD = 3,
	GPIO_PORTE = 4,
	UART0      = 5,
	UART1      = 6,
	SSI0       = 7,
	I2C0       = 8,
	PWM0_FAULT = 9,
    PWM0_GENERATOR_0  = 10,
    PWM0_GENERATOR_1  = 11,
	PWM0_GENERATOR_2  = 12,
	QEI0              = 13,
	ADC0_SEQUENCE_0   = 14,
	ADC0_SEQUENCE_1   = 15,
	ADC0_SEQUENCE_2   = 16,
	ADC0_SEQUENCE_3   = 17,
	WATCHDOG_TIMERS_0_1=18,
	TIMER0A_16_32     = 19,
	TIMER0B_16_32     = 20,
	TIMER1A_16_32     = 21,
	TIMER1B_16_32     = 22,
	TIMER2A_16_32     = 23,
	TIMER2B_16_32     = 24,
	Analog_Comparator_0=25,
	Analog_Comparator_1=26,
	
	SYSTEM_CONTROL                          = 28,
    FLASH_MEMORY_CONTROL_AND_EEPROM_CONTROL = 29,
    GPIO_PORTF                              = 30,
	
    UART2          = 33,
    SSI1           = 34,
    TIMER_3A_16_32 = 35,
    TIMER_3B_16_32 = 36,
    I2C1           = 37,
    QEI1           = 38,
    CAN0           = 39,
    CAN1           = 40,
	
    HIBERNATION_MODULE=43,
    USB              = 44,
    PWM_GENERATOR_3  = 45,
    uDMA_SOFTWARE    = 46,
    uDMA_ERROR       = 47,
    ADC1_SEQUENCE_0  = 48,
    ADC1_SEQUENCE_1  = 49,
    ADC1_SEQUENCE_2  = 50,
    ADC1_SEQUENCE_3  = 51,
	
    SSI2  = 57,
    SSI3  = 58,
    UART3 = 59,
    UART4 = 60,
    UART5 = 61,
    UART6 = 62,
    UART7 = 63,
	
    I2C2           = 68,
    I2C3           = 69,
    TIMER4A_16_32  = 70,
    TIMER4B_16_32  = 71,
				   
    TIMER5A_16_32  = 92,
    TIMER5B_16_32  = 93,
    TIMER0A_32_64  = 94,
    TIMER0B_32_64  = 95,
    TIMER1A_32_64  = 96,
    TIMER1B_32_64  = 97,
    TIMER2A_32_64  = 98,
    TIMER2B_32_64  = 99,
    TIMER3A_32_64  = 100,
    TIMER3B_32_64  = 101,
    TIMER4A_32_64  = 102,
    TIMER4B_32_64  = 103,
    TIMER5A_32_64  = 104,
    TIMER5B_32_64  = 105,
    SYSTEM_EXCEPTION=106,
	
    PWM1_GENERATOR_0 = 134,
    PWM1_GENERATOR_1 = 135,
    PWM1_GENERATOR_2 = 136,
    PWM1_GENERATOR_3 = 137,
    PWM1_Fault       = 138

	
}IntCtrl_InterruptType	;


#if(INTCTRL_GRP_SUBGRP == GRP_3_SUBGRP_0_MODE )
    
    typedef enum
    {
      GRP_0_SUBGRP_0 ,
      GRP_1_SUBGRP_0,
      GRP_2_SUBGRP_0,
      GRP_3_SUBGRP_0,
      GRP_4_SUBGRP_0,
      GRP_5_SUBGRP_0,
      GRP_6_SUBGRP_0,
      GRP_7_SUBGRP_0
    }IntCtrl_Grp_SubGrp_Type;

#elif(INTCTRL_GRP_SUBGRP == GRP_2_SUBGRP_1_MODE)

    typedef enum
    {
      GRP_0_SUBGRP_0 ,
      GRP_0_SUBGRP_1,
      GRP_1_SUBGRP_0,
      GRP_1_SUBGRP_1,
      GRP_2_SUBGRP_0,
      GRP_2_SUBGRP_1,
      GRP_3_SUBGRP_0,
      GRP_3_SUBGRP_1
    }IntCtrl_Grp_SubGrp_Type;

#elif(INTCTRL_GRP_SUBGRP == GRP_1_SUBGRP_2_MODE)

    typedef enum
    {
      GRP_0_SUBGRP_0 ,
      GRP_0_SUBGRP_1,
      GRP_0_SUBGRP_2,
      GRP_0_SUBGRP_3,
      GRP_1_SUBGRP_0,
      GRP_1_SUBGRP_2,
      GRP_1_SUBGRP_3,
      GRP_1_SUBGRP_4
    }IntCtrl_Grp_SubGrp_Type;
    
#else 
	/* INTCTRL_GRP_SUBGRP Default value is GRP_0_SUBGRP_3_MODE */
    typedef enum
    {
      GRP_0_SUBGRP_0 ,
      GRP_0_SUBGRP_1,
      GRP_0_SUBGRP_2,
      GRP_0_SUBGRP_3,
      GRP_0_SUBGRP_4,
      GRP_0_SUBGRP_5,
      GRP_0_SUBGRP_6,
      GRP_0_SUBGRP_7
    }IntCtrl_Grp_SubGrp_Type;
#endif

typedef enum
{
  INT_DISABLE,
  INT_ENABLE
}INT_Status_Type;

typedef struct 
{
  IntCtrl_InterruptType      NVIC_Intr_perif;
  IntCtrl_Grp_SubGrp_Type    Priority;
  INT_Status_Type            Status;

}ConfigStruct_type;


extern ConfigStruct_type IntConfigStruct[INTCTRL_NB_OF_INTRS];


#endif  /* IntCtrl_Types_H */

/**********************************************************************************************************************
 *  END OF FILE: IntCtrl_Types.h
 *********************************************************************************************************************/
