/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Mcu_Hw.h
 *       Module:  Mcu_Hw
 *
 *  Description:  Header file for Register Defination	   
 *  
 *********************************************************************************************************************/
#ifndef MCU_HW_H
#define MCU_HW_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef struct
{
	uint32 VECACT  :8;
	uint32         :3;
	uint32 RETBASE :1;
	uint32 VECPEND :8;
	uint32         :2;
	uint32 ISRPEND :1;
	uint32 ISRPRE  :1;
	uint32         :1;
	uint32 PENDSTCLR:1;
	uint32 PENDSTSET:1;
	uint32 UNPENDSV :1;
	uint32 PENDSV   :1;
	uint32          :2;
	uint32 NMISET   :1;	
	
}INTCTRL_BF;

typedef union
{
	uint32 REG;
	INTCTRL_BF BIT_FEILD; 
}SCB_INTCTRL_Type;



typedef struct 
{
	uint32 VECTRESET  :1;
    uint32 VECTCLRACT  :1;
	uint32 SYSRESREQ   :1;
	uint32 			   :5;
	uint32 PRIGROUP    :3;
	uint32 			   :4;
	uint32 ENDIANESS   :1;
	uint32 VECTKEY     :16;

}SCB_APINT_BF;

typedef union 
{
	uint32 REG;
    SCB_APINT_BF BIT
}SCB_APINT_Type;



typedef struct 
{
	uint32 EN[5];
}NVIC_ENABLE_Type;


typedef struct 
{
	uint32 DIS[5];
}NVIC_DISABLE_Type;

typedef struct 
{
	uint32 PEND[5];
}NVIC_PEND_Type;

typedef struct 
{
	uint32 UNPEND[5];
}NVIC_UNPEND_Type;

typedef struct 
{
	uint32 ACTIVE[5];
}NVIC_ACTIVE_Type;

typedef struct 
{
	uint32 PRI[35];
}NVIC_PRIORITY_Type;











/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define CORTEXM4_PERIF_BASE_ADDRESS                      0xE000E000


//#define APINT                 							*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0xD0C))
//#define INTCTRL                                         *((volatile INTCTRL_Tag*)(CORTEXM4_PERI_BASE_ADDRESS+0xD04	))

/******************************************
 *  INTERRUPT REGISTERS
 ******************************************/
 
#define NVIC_EN               ((volatile NVIC_ENABLE_Type *)      (CORTEXM4_PERIF_BASE_ADDRESS+0x100))
#define NVIC_DIS              ((volatile NVIC_DISABLE_Type *)     (CORTEXM4_PERIF_BASE_ADDRESS+0x180))
#define NVIC_PEND             ((volatile NVIC_PEND_Type *)        (CORTEXM4_PERIF_BASE_ADDRESS+0x200))
#define NVIC_UNPEND           ((volatile NVIC_UNPEND_Type *) 	  (CORTEXM4_PERIF_BASE_ADDRESS+0x280))
#define NVIC_ACTIVE           ((volatile NVIC_ACTIVE_Type *) 	  (CORTEXM4_PERIF_BASE_ADDRESS+0x300))
#define NVIC_PRI              ((volatile NVIC_PRIORITY_Type *)    (CORTEXM4_PERIF_BASE_ADDRESS+0x400))

#define NVIC_SWTRIG           ((volatile uint32 *)          (CORTEXM4_PERIF_BASE_ADDRESS+0xF00))
														      
#define SCB_APINT             ((volatile SCB_APINT_Type *)    (CORTEXM4_PERIF_BASE_ADDRESS+0xD0C))
#define SCB_INTCTRL           ((volatile SCB_INTCTRL_Type *)  (CORTEXM4_PERIF_BASE_ADDRESS+0xD04))


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/




/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/


#endif  /* MCU_HW_H */

/**********************************************************************************************************************
 *  END OF FILE: Mcu_Hw.h
 *********************************************************************************************************************/
