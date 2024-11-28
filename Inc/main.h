/*
 * main.h
 *
 *  Created on: Nov 21, 2024
 *      Author: root
 */

#ifndef MAIN_H_
#define MAIN_H_

//
//#define TASK_STACK_SIZE					1024U
//#define SCHEDULER_STACK_SIZE			1024U
//
//#define SRAM_SIZE                       ((128) * (1024))
//#define SRAM_START 						(0x20000000U)
//#define SRAM_END 						((SRAM_START) + (SRAM_SIZE))
//
//
//#define T1_STACK_START					SRAM_END
//#define T2_STACK_START					(  (T1_STACK_START) - (TASK_STACK_SIZE)  )
//
//#define T3_STACK_START					(  (T2_STACK_START) - (TASK_STACK_SIZE)  )
//#define T4_STACK_START					(  (T3_STACK_START) - (TASK_STACK_SIZE)  )
//
//#define SCHED_STACK_START				0x20126976U//(  (T4_STACK_START) - (TASK_STACK_SIZE)  )
//
//
//#define TICK_HZ						1000U
//#define HSI_CLK						16000000U
//#define SYSTICK_TIMER_CLK			HSI_CLK
//
//#define MAX_TASKS					4
//
//
//#define DUMMY_XPSR					(uint32_t)(0x01000000U)


#define MAX_TASKS   4

/* some stack memory calculations */
#define SIZE_TASK_STACK          1024U
#define SIZE_SCHED_STACK         1024U

#define SRAM_START               0x20000000U
#define SIZE_SRAM                ( (128) * (1024))
#define SRAM_END                 ((SRAM_START) + (SIZE_SRAM) )

#define T1_STACK_START           SRAM_END
#define T2_STACK_START           ( (SRAM_END) - (1 * SIZE_TASK_STACK) )
#define T3_STACK_START           ( (SRAM_END) - (2 * SIZE_TASK_STACK) )
#define T4_STACK_START           ( (SRAM_END) - (3 * SIZE_TASK_STACK) )
#define IDLE_STACK_START         ( (SRAM_END) - (4 * SIZE_TASK_STACK) )
#define SCHED_STACK_START        ( (SRAM_END) - (5 * SIZE_TASK_STACK) )

#define TICK_HZ 1000U

#define HSI_CLOCK         		16000000U
#define SYSTICK_TIM_CLK   		HSI_CLOCK


#define DUMMY_XPSR  0x01000000U

#define TASK_READY_STATE  0x00
#define TASK_BLOCKED_STATE  0XFF

#define INTERRUPT_DISABLE()  do{__asm volatile ("MOV R0,#0x1"); asm volatile("MSR PRIMASK,R0"); } while(0)

#define INTERRUPT_ENABLE()  do{__asm volatile ("MOV R0,#0x0"); asm volatile("MSR PRIMASK,R0"); } while(0)



#endif /* MAIN_H_ */
