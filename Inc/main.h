/*
 * main.h
 *
 *  Created on: Sep 12, 2026
 *      Author: steep
 */

#ifndef MAIN_H_
#define MAIN_H_

#define MAX_TASKS				5

//SRAM mapping
#define START_SRAM_ADDR			0x20000000U
#define SIZE_SRAM  				((128) * (1024))
#define END_SRAM_ADDR   		((START_SRAM_ADDR) + (SIZE_SRAM))

#define SIZE_TASK_STACK      	1024U
#define SIZE_SCHEDULER_STACK 	1024U

#define T1_STACK_START  		END_SRAM_ADDR
#define T2_STACK_START  		((T1_STACK_START) - (SIZE_TASK_STACK))
#define T3_STACK_START  		((T2_STACK_START) - (SIZE_TASK_STACK))
#define T4_STACK_START  		((T3_STACK_START) - (SIZE_TASK_STACK))
#define IDLE_STACK_START		((T4_STACK_START) - (SIZE_TASK_STACK))
#define SCHEDULER_START 		((IDLE_STACK_START) - (SIZE_SCHEDULER_STACK))

//Ticking
#define SYSTICK_TIM				16000000U
#define TICK_HZ					1000U

// States of task
#define TASK_RUNNING_STATE  0x00
#define TASK_BLOCKED_STATE  0xFF

//Miscellaneous
#define DUMMY_XPSR              0x01000000U

// Addresses

// for faults
#define SHCRS_addr 				0xE000ED24

// for systick
#define SYST_RVR_addr			0xE000E014
#define SYST_CSR_addr			0xE000E010

// for pendSV
#define ICSR_ADDR 				0xE000ED04

// Interrupt macros
#define INTERRUPT_DISABLE() do{__asm volatile ("MOV R0, #0X1"); __asm volatile ("MSR PRIMASK, R0"); } while(0)
#define INTERRUPT_ENABLE() do{__asm volatile ("MOV R0, #0X0"); __asm volatile ("MSR PRIMASK, R0"); } while(0)

// Functions
__attribute__ ((naked)) void initialize_task_scheduler(uint32_t scheduler_start);

__attribute__ ((naked)) void switch_to_psp(void);

uint32_t get_psp_value(void);

void enable_faults(void);

void initialize_systick(uint32_t tick_hz);

void initialize_task_stack(void);


#endif /* MAIN_H_ */
