/** @file sys_main.c 
*   @brief Application main file
*   @date 11-Dec-2018
*   @version 04.07.01
*
*   This file contains an empty main function,
*   which can be used for the application.
*/

/* 
* Copyright (C) 2009-2018 Texas Instruments Incorporated - www.ti.com 
* 
* 
*  Redistribution and use in source and binary forms, with or without 
*  modification, are permitted provided that the following conditions 
*  are met:
*
*    Redistributions of source code must retain the above copyright 
*    notice, this list of conditions and the following disclaimer.
*
*    Redistributions in binary form must reproduce the above copyright
*    notice, this list of conditions and the following disclaimer in the 
*    documentation and/or other materials provided with the   
*    distribution.
*
*    Neither the name of Texas Instruments Incorporated nor the names of
*    its contributors may be used to endorse or promote products derived
*    from this software without specific prior written permission.
*
*  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
*  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
*  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
*  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
*  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
*  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
*  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
*  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
*  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
*  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
*  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*
*/


/* USER CODE BEGIN (0) */


/* sems 02.07.19 

To build from command line -->

ccstudio -noSplash -data "/Users/sems/Documents/Workspace/mbed/ARM/TI/" -application com.ti.ccstudio.apps.projectBuild -ccs.projects TMS570LS1224_Example --ccs.autoImport -ccs.configuration Debug ; (cd ../uniflash_osx_64/; ./dslite.sh)

Source: http://software-dl.ti.com/ccs/esd/documents/ccs_projects-command-line.html#working-with-macos

 */


/* USER CODE END */

/* Include Files */

#include "sys_common.h"
#include "system.h"

/* USER CODE BEGIN (1) */
#include "sci.h"

#define TSIZE1 10
uint8 TEXT1[TSIZE1] = {'G','U','M','U','S','H'};

void sciDisplayText(sciBASE_t *sci, uint8 *text, uint32 length);
void wait(uint32 time);

#define UART scilinREG
/* USER CODE END */

/** @fn void main(void)
*   @brief Application main function
*   @note This function is empty by default.
*
*   This function is called after startup.
*   The user can use this function to implement the application.
*/

/* USER CODE BEGIN (2) */
/* USER CODE END */

void main(void) {
/* USER CODE BEGIN (3) */
  sciInit(); 			/* initialize sci/sci-lin 
				even parity, 2 stop bits */ 
  while (true) {		/* continious display */
    sciDisplayText(UART, &TEXT1[0], TSIZE1); /*  send text code 1 */
    wait(100);
  }
/* USER CODE END */
}

/* USER CODE BEGIN (4) */

void sciDisplayText(sciBASE_t *sci, uint8 *text,uint32 length) {
  while(length--) {
    while ((UART->FLR & 0x4) == 4); /* wait until busy */
    sciSendByte(UART,*text++);      /* send out text   */
  };
}


void wait(uint32 time) {
  time--;
}

/* USER CODE END */
