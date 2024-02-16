	/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  IntCtrl.c
 *        \brief  Nested Vector Interrupt Controller Deiver  
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Int_ctrl.h"
#include "Registers_Ops.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
static void SetPriorityGrouping();
static void IntCtrl_SetPriority(IntCtrl_InterruptType IntrNum, uint8 u8_IntPriorty);
static void IntCtrl_EnableInterrupt(IntCtrl_InterruptType IntrNum);
static void IntCtrl_DisableInterrupt(IntCtrl_InterruptType IntrNum);


/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

static void SetPriorityGrouping()
{
	#if(INTCTRL_GRP_SUBGRP == GRP_3_SUBGRP_0_MODE)
		SCB_APINT->REG = GRP_3_SUBGRP_0_MODE
	
	#elif(INTCTRL_GRP_SUBGRP == GRP_2_SUBGRP_1_MODE)
		SCB_APINT->REG = GRP_2_SUBGRP_1_MODE
	
	#elif(INTCTRL_GRP_SUBGRP == GRP_1_SUBGRP_2_MODE)
		SCB_APINT->REG = GRP_1_SUBGRP_2_MODE
	
	#else
		SCB_APINT->REG = GRP_0_SUBGRP_3_MODE;

	#endif

}

static void IntCtrl_SetPriority(IntCtrl_InterruptType IntrNum, uint8 u8_IntPriorty )
{
	uint32 u32PRI_RegLoc = 0 , u32PRI_BitLoc = 0;
	

	u32PRI_RegLoc = (uint32)IntrNum / 4 ;
	u32PRI_BitLoc = (uint32)IntrNum % 4;

	NVIC_PRI->PRI[u32PRI_RegLoc] |=  (u8_IntPriorty <<((u32PRI_BitLoc*8u)+ 5u));
}

static void IntCtrl_EnableInterrupt(IntCtrl_InterruptType IntrNum)
{
	uint32 u32INT_RegLoc = 0 , u32INT_BitLoc =0;

	u32INT_RegLoc = (uint32) IntrNum /32;
	u32INT_BitLoc = (uint32) IntrNum %32;

	/* to use this: the "*"" in the Macro defintion of NVIC_EN shall be removed
		SET_BIT(NVIC_EN->EN[u32INT_RegLoc], u32INT_BitLoc);
	*/
	NVIC_EN->EN[u32INT_RegLoc] |= (1u<<u32INT_BitLoc);
}

static void IntCtrl_DisableInterrupt(IntCtrl_InterruptType IntrNum)
{
	uint32 u32INT_Dis_RegLoc = 0 , u32INT_Dis_BitLoc =0;

	u32INT_Dis_RegLoc = (uint32) IntrNum /32;
	u32INT_Dis_BitLoc = (uint32) IntrNum %32;

	/* to use this: the "*"" in the Macro defintion of NVIC_EN shall be removed
		SET_BIT(NVIC_EN->EN[u32INT_RegLoc], u32INT_BitLoc);
	*/
	NVIC_DIS->DIS[u32INT_Dis_RegLoc] |= (1u<<u32INT_Dis_BitLoc);

}




/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/******************************************************************************
* \Syntax          : void IntCtrl_Init(void)        
* \Description     : initialize Nvic\SCB Module by parsing the configuration
                     into Nvic\SCB registers
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None                                
*******************************************************************************/
void IntCtrl_Init(void)
{
	
	/*TODO Configure Grouping\SubGrouping system in APINT register in SCB */
	/*
	APINT = 0xFA05 | 0x00001234;
	INTCTRL.B.VECPEND = 0x5;
	*/
	SetPriorityGrouping();

	
	uint32 i =0 ;

	for (; i < INTCTRL_NB_OF_INTRS; i++)
	{
	/*TODO : Assign Group\SubGroup priority in NVIC_PRIx Nvic and SCB_SYSPRIx Registers */

		IntCtrl_SetPriority(IntConfigStruct[i].NVIC_Intr_perif , IntConfigStruct[i].Priority);

	/*TODO : Enable\Disable based om user configuration in NVIC_ENx and SCB_Sys Registers */

		if(IntConfigStruct[i].Status == INT_ENABLE ) 
			IntCtrl_EnableInterrupt(IntConfigStruct[i].NVIC_Intr_perif);
		
		else
			IntCtrl_DisableInterrupt(IntConfigStruct[i].NVIC_Intr_perif);
	}
	
}

/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/
