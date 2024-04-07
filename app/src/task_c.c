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
 * @file   : task_c.c
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
#define G_TASK_C_CNT_INI	0u

#define TASK_C_DEL_INI		0u
#define TASK_C_DEL_MAX		50000u

/********************** internal data declaration ****************************/

/********************** internal functions declaration ***********************/

/********************** internal data definition *****************************/
const char *p_task_c 		= "Task C (LED) (Actuator Modeling)";

/********************** external data declaration *****************************/
uint32_t g_task_c_cnt;

s_task_c_t g_state_task_c;

e_task_c_t g_event_task_c;
bool g_b_event_task_c;


const char *const names_e_task_c[] = {
        "ev_LED_ON",
        "ev_LED_OFF"
    };

const char *const names_s_task_c[] = {
        "LED_FIXED_st",
        "LED_BLINKING_st"
    };


/********************** external functions definition ************************/
void task_c_init(void *parameters)
{

	/* Print out: Task Initialized */
	LOGGER_LOG("  %s is running - %s\r\n", GET_NAME(task_c_init), p_task_c);

	g_task_c_cnt = G_TASK_C_CNT_INI;

	/* Print out: Task execution counter */
	LOGGER_LOG("   %s = %d\r\n", GET_NAME(g_task_c_cnt), (int)g_task_c_cnt);

	g_state_task_c = LED_FIXED_st;
	g_event_task_c = ev_LED_OFF;
	g_b_event_task_c = false;

	/***
	 *
	 * MI CAMBIO - START
	 * ***/
	/* Print out: Task execution FSM */
	LOGGER_LOG("   %s = %s\r\n", GET_NAME(g_state_task_c), names_s_task_c[(int)g_state_task_c]);
	LOGGER_LOG("   %s = %s\r\n", GET_NAME(g_event_task_c), names_e_task_c[(int)g_event_task_c]);
	/***
	 *
	 * MI CAMBIO - END
	 * ***/
}


/***
 *
 * MI CAMBIO - START
 * ***/
void task_c_update(void *parameters)
{   
	/* Update Task A Counter */
	g_task_c_cnt++;


    
	if (true == g_b_event_task_c)
	{
		g_b_event_task_c = false;

		/* Print out: Application Update */
		LOGGER_LOG("  %s is is running - %s\r\n", GET_NAME(task_c_update), p_task_c);

		/* Print out: Task execution counter */
		LOGGER_LOG("   %s = %d\r\n", GET_NAME(g_task_c_cnt), (int)g_task_c_cnt);

		switch (g_state_task_c){
			case LED_FIXED_st:
				if (ev_LED_ON == g_event_task_c)
					g_state_task_c = LED_BLINKING_st;

				break;

			case LED_BLINKING_st:
                if (ev_LED_OFF == g_event_task_c)
					g_state_task_c = LED_FIXED_st;

				break;

            default:
                LOGGER_LOG("ERROR - default case - Task C (LED) \r\n");
                break;

		}
		/* Print out: Task execution FSM */
		LOGGER_LOG("   %s = %s\r\n", GET_NAME(g_state_task_c), names_s_task_c[(int)g_state_task_c]);
		LOGGER_LOG("   %s = %s\r\n", GET_NAME(g_event_task_c), names_e_task_c[(int)g_event_task_c]);
	}
}

	/***
	 *
	 * MI CAMBIO - END
	 * ***/

/********************** end of file ******************************************/
