/*
 * Copyright (c) 2023 Juan Manuel Cruz <jcruz@fi.uba.ar> <jcruz@frba.utn.edu.ar>.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from
 *    this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
 * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 *
 * @file   : task_c_test.c
 * @date   : Set 26, 2023
 * @author : Juan Manuel Cruz <jcruz@fi.uba.ar> <jcruz@frba.utn.edu.ar>
 * @version	v1.0.0
 */

/********************** inclusions *******************************************/
/* Project includes. */
#include "main.h"

/* Demo includes. */
#include "logger.h"
#include "dwt.h"

/* Application & Tasks includes. */
#include "board.h"
#include "app.h"
#include "task_c_fsm.h"

/********************** macros and definitions *******************************/
#define G_TASK_C_TEST_CNT_INI	0u

#define TASK_C_TEST_CNT_INI		0u
#define TASK_C_TEST_CNT_MAX		100000u

#define TASK_C_TEST_DEL_INI		0u
#define TASK_C_TEST_DEL_MAX		500u

//typedef enum {TEST_0, TEST_1, TEST_2} test_x_t;
#define TASK_C_TEST_0 (0)
#define TASK_C_TEST_1 (1)
#define TASK_C_TEST_2 (2)

#define TASK_C_TEST_X (TASK_C_TEST_0)

/********************** internal data declaration ****************************/

/********************** internal functions declaration ***********************/

/********************** internal data definition *****************************/
const char *p_task_c_test	= "Task C (LED) (Actuator Modeling) Test";

#if (TASK_C_TEST_X == TASK_C_TEST_0)
/* Array of events to excite Task A */
const e_task_c_t e_task_c_array[] = {ev_LED_OFF, ev_LED_OFF, ev_LED_ON, ev_LED_ON, ev_LED_ON, ev_LED_OFF, ev_LED_ON, ev_LED_OFF, ev_LED_OFF};
#endif

// #if (TASK_A_TEST_X == TASK_A_TEST_1)
// /* Array of events to excite Task A */
// const e_task_a_t e_task_b_array[] = {EVENT_2 EVENT_1, EVENT_0, EVENT_2 EVENT_1, EVENT_0};
// #endif

// #if (TASK_A_TEST_X == TASK_A_TEST_2)
// /* Array of events to excite Task A */
// const e_task_a_t e_task_b_array[] = {EVENT_0, EVENT_1, Event_2, EVENT_2, EVENT_1, EVENT_0};
// #endif

/********************** external data declaration *****************************/
uint32_t g_task_c_test_cnt;

/********************** external functions definition ************************/
void task_c_test_init(void *parameters)
{
	uint32_t i = TASK_C_TEST_X;

	/* Print out: Task Initialized */
	LOGGER_LOG("  %s is running - %s\r\n", GET_NAME(task_c_test_init), p_task_c_test);

	g_task_c_test_cnt = G_TASK_C_TEST_CNT_INI;

	/* Print out: Task execution counter */
	LOGGER_LOG("   %s = %d\r\n", GET_NAME(g_task_c_test_cnt), (int)g_task_c_test_cnt);

	/* Print out: Array of events to excite Task A */
	LOGGER_LOG("   %s = %d\r\n", GET_NAME(e_task_c_array), (int)i);
}

void task_c_test_update(void *parameters)
{

	#if (TEST_X == TEST_0)

	static uint32_t task_c_test_cnt = TASK_C_TEST_CNT_INI;
	uint32_t i = TASK_C_TEST_X;

	static uint32_t then = TASK_C_TEST_DEL_INI;
	static uint32_t now  = TASK_C_TEST_DEL_INI;

	#endif

	#if (TEST_X == TEST_1)

	/* Here another code */

	#endif

	#if (TEST_X == TEST_2)

	/* Here Chatbot Artificial Intelligence generated code */

	#endif

	/* Update Task A Counter */
	g_task_c_test_cnt++;

	/* Check the current tick */
	now = HAL_GetTick();
	if ((now - then) >= TASK_C_TEST_DEL_MAX)
	{
		/* Only if the current tick is TASK_A_TEST_DEL_MAX mS after the last */
		/* Reset then = now */
		then = now;

		/* Print out: Application Update */
		LOGGER_LOG("  %s is is running - %s\r\n", GET_NAME(task_c_test_update), p_task_c_test);

		/* Print out: Task execution counter */
		LOGGER_LOG("   %s = %d\r\n", GET_NAME(g_task_c_test_cnt), (int)g_task_c_test_cnt);

		/* Print out: Array of events to excite Task A */
		LOGGER_LOG("   %s = %d\r\n", GET_NAME(e_task_c_array), (int)i);

		/* Get the event to excite Task A. */
		g_event_task_c = e_task_c_array[task_c_test_cnt];
		g_b_event_task_c = true;

		if (task_c_test_cnt < (sizeof(e_task_c_array)/sizeof(e_task_c_t)))
			task_c_test_cnt++;
		else
			task_c_test_cnt = TASK_C_TEST_CNT_INI;
	}

	#if (TEST_X == TEST_1)

	/* Here another code */

	#endif

	#if (TEST_X == TEST_2)

	/* Here Chatbot Artificial Intelligence generated code */

	#endif
}

/********************** end of file ******************************************/
