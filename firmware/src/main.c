/*******************************************************************************
  Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This file contains the "main" function for a project.

  Description:
    This file contains the "main" function for a project.  The
    "main" function calls the "SYS_Initialize" function to initialize the state
    machines of all modules in the system
 *******************************************************************************/

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include <stddef.h>                     // Defines NULL
#include <stdbool.h>                    // Defines true
#include <stdlib.h>                     // Defines EXIT_FAILURE
#include <stdio.h>
#include "definitions.h"                // SYS function prototypes
#include "task.h"
#include "queue.h"
#include "semphr.h"
#include "FreeRTOS.h"

// Main LED Flash
static void TaskBlinkLED(void* led)
{
  while (true)
  {
    // LED on
    TRISD.TRISD0 = 0;          /* Tristate 0 for Output */
    LATD.LATD0 = 1;            /* Output latch register bit = 1 for High output. */
    
    vTaskDelay(250);

    // LED off
    LATD.LATD0 = 0;
    vTaskDelay(250);


  }

  vTaskDelete(NULL);
}

int main()
{
  /* Initialize all modules */
  SYS_Initialize (NULL);
  
  xTaskCreate(TaskBlinkLED, (const portCHAR*) "LED", 1024, NULL, 1, NULL);

  vTaskStartScheduler();
  
  while ( true )
  {
      /* Maintain state machines of all polled MPLAB Harmony modules. */
      SYS_Tasks ( );
  }
  /* Execution should not come here during normal operation */
  return ( EXIT_FAILURE );

}
/*******************************************************************************
 End of File
*/

