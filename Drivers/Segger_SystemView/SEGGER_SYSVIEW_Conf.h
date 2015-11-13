/*********************************************************************
*               SEGGER MICROCONTROLLER GmbH & Co. KG                 *
*       Solutions for real time microcontroller applications         *
**********************************************************************
*                                                                    *
*       (c) 2015  SEGGER Microcontroller GmbH & Co. KG               *
*                                                                    *
*       www.segger.com     Support: support@segger.com               *
*                                                                    *
**********************************************************************
*                                                                    *
*       SEGGER SystemView * Real-time application analysis           *
*                                                                    *
**********************************************************************
*                                                                    *
* All rights reserved.                                               *
*                                                                    *
* * This software may in its unmodified form be freely redistributed *
*   in source form.                                                  *
* * The source code may be modified, provided the source code        *
*   retains the above copyright notice, this list of conditions and  *
*   the following disclaimer.                                        *
* * Modified versions of this software in source or linkable form    *
*   may not be distributed without prior consent of SEGGER.          *
*                                                                    *
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND             *
* CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,        *
* INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF           *
* MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE           *
* DISCLAIMED. IN NO EVENT SHALL SEGGER Microcontroller BE LIABLE FOR *
* ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR           *
* CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT  *
* OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;    *
* OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF      *
* LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT          *
* (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE  *
* USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH   *
* DAMAGE.                                                            *
*                                                                    *
**********************************************************************
*                                                                    *
*       SystemView version: V2.10                                    *
*                                                                    *
**********************************************************************
-------------------------- END-OF-HEADER -----------------------------

File    : SEGGER_SYSVIEW_Config.h
Purpose : SEGGER SYSVIEW setup configuration header
*/

#ifndef SEGGER_SYSVIEW_CONFIG_H            // Avoid multiple inclusion.
#define SEGGER_SYSVIEW_CONFIG_H

#if defined(__cplusplus)
  extern "C" {                // Make sure we have C-declarations in C++ programs.
#endif

#include "SEGGER_RTT_Conf.h"
/*********************************************************************
*
*       SysView timestamp configuration
*/
#if SEGGER_RTT_CORE_M4
  #define SEGGER_SYSVIEW_GET_TIMESTAMP()      ((*(uint32_t *)(0xE0001004)) >> 4)       // Retrieve a system timestamp. Cortex-M cycle counter. Shifted by 4 to save bandwith.
  #define SEGGER_SYSVIEW_TIMESTAMP_BITS       28                                  // Define number of valid bits low-order delivered by clock source
  #define SEGGER_SYSVIEW_GET_INTERRUPT_ID()   ((*(uint32_t *)(0xE000ED04)) & 0x1FF)   /* ICSR[8:0] */
#elif SEGGER_RTT_CORE_M0
  #define SEGGER_SYSVIEW_GET_TIMESTAMP()      0
  #define SEGGER_SYSVIEW_TIMESTAMP_BITS       0
  #define SEGGER_SYSVIEW_GET_INTERRUPT_ID()   0
#else
  #error "Unknown ARM core!"
#endif

// Number of bytes that SysView uses for a buffer.
#define SEGGER_SYSVIEW_RTT_BUFFER_SIZE    %RttBufferSize

// The RTT channel that SysView will use.
#define SEGGER_SYSVIEW_RTT_CHANNEL        %RttChannelIndex
#if SEGGER_SYSVIEW_RTT_CHANNEL>=SEGGER_RTT_MAX_NUM_UP_BUFFERS
  #error "Not enough RTT buffers allocated in RTT!"
#endif

/*********************************************************************
*
*       API functions
*
**********************************************************************
*/

void SEGGER_SYSVIEW_Conf(void);

#if defined(__cplusplus)
}                             // Make sure we have C-declarations in C++ programs.
#endif

#endif                        // Avoid multiple inclusion.

/*************************** End of file ****************************/