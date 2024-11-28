---

# STM32 Multi-Tasking System with LED Control

This project demonstrates a basic **multi-tasking system** on an STM32 microcontroller. The program initializes a task scheduler, switches between tasks in a round-robin fashion, and toggles LEDs at varying rates. This is achieved using custom task management and SysTick timer interrupts.

---

## **Features**
- **Task Scheduling**: Implements a simple round-robin scheduler to manage multiple tasks.
- **Context Switching**: Saves and restores task states during execution using the Process Stack Pointer (PSP).
- **Fault Management**: Enables and handles processor exceptions (e.g., memory, bus, and usage faults).
- **LED Control**: Controls LEDs with different blinking patterns based on the task.
- **SysTick Timer**: Configured for 1ms ticks, driving the timing for task switching and delays.

---

## **Task Overview**
The project defines four tasks that toggle LEDs with specific patterns:
1. **Task 1**: Green LED toggles ON and OFF with delays of 1ms and 1s.
2. **Task 2**: Red LED toggles ON and OFF with delays of 125ms and 1s.
3. **Task 3**: Red LED toggles ON and OFF with delays of 1s and 250ms.
4. **Task 4**: Green LED toggles ON and OFF with delays of 250ms and 1ms.

---

## **Files**

### **Source Files**
- `main.c`: Contains the task scheduler, SysTick handler, and LED control logic.
- `my_led.h`: Provides functions for initializing and controlling LEDs.

### **Key Functions**
#### Initialization
- `init_schd_task(uint32_t schd_stack_start)`: Sets the main stack pointer (MSP) for the scheduler stack.
- `init_stack_tasks(void)`: Prepares task stacks with necessary context (e.g., xPSR, PC, LR).
- `init_systick_tim(uint32_t tm)`: Configures the SysTick timer for periodic interrupts.
- `processor_fault_enable()`: Enables memory, bus, and usage fault handlers.

#### Task Management
- `task1()`, `task2()`, `task3()`, `task4()`: Define the main behavior for each task.
- `save_psp_current_value(uint32_t curr_psp)`: Saves the current Process Stack Pointer (PSP) for a task.
- `update_the_next_task()`: Determines the next task to run in a round-robin fashion.

#### Exception Handling
- `MemManage_Handler()`: Handles memory faults.
- `BusFault_Handler()`: Handles bus faults.
- `UsageFault_Handler()`: Handles usage faults.
- `SysTick_Handler()`: Manages task switching during SysTick interrupts.

---

## **How It Works**
1. **Task Scheduler**:
   - Tasks are initialized with their stacks and contexts.
   - The current task is tracked using a global `current_task` variable.
   - On each SysTick interrupt:
     - The current task's context is saved.
     - The next task is loaded using its previously saved context.

2. **LED Control**:
   - Tasks call `led_on()` and `led_off()` to control LEDs.
   - Delays are implemented using the `delay()` function.

3. **Exception Handling**:
   - Fault exceptions are enabled to debug issues like invalid memory access or instruction execution errors.

---

## **How to Use**

### **Prerequisites**
- STM32CubeIDE or any compatible ARM Cortex-M development environment.
- STM32 development board with LEDs configured.

### **Setup**
1. Clone or download this repository.
2. Open the project in **STM32CubeIDE**.
3. Ensure `my_led.h` is configured for the correct LED pins on your board.
4. Compile and flash the code onto your STM32 board.

### **Execution**
- Once the board is powered, LEDs will toggle according to the tasks defined.
- Task switching occurs at 1ms intervals driven by the SysTick timer.

---

## **Code Breakdown**

### **Key Definitions**
- `MAX_TASKS`: Total number of tasks managed by the scheduler.
- `T1_STACK_START`, `T2_STACK_START`, etc.: Stack start addresses for each task.
- `DUMMY_XPSR`: Default xPSR value for initializing the stack.

### **Memory and Registers**
- **MSP (Main Stack Pointer)**: Used for the scheduler's stack.
- **PSP (Process Stack Pointer)**: Dedicated for task stack management.
- **CONTROL Register**: Switches between MSP and PSP.

---

## **Limitations**
- No dynamic task creation or deletion (tasks are hardcoded).
- Basic round-robin scheduler without priority management.
- LED control assumes specific GPIO pin configurations.
- The `delay` function uses a for-loop to create a delay. This isn't efficient. 

---

## **Extending the Project**
- Implement a `delay` function that utilizes one of the timers of the MCU.
- Implement a priority-based scheduler for more advanced task management (Blocking states of tasks).
- Integrate external inputs (e.g., buttons) to modify task behavior.
- Further code cleanup and optimization.
- Use of pendSV for task scheduling.
---

Feel free to reach out for further clarification or to suggest improvements! 😊
