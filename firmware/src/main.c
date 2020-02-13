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
#include <xc.h>

// Main LED Flash
static void TaskBlinkLED(void* led)
{
    TRISDbits.TRISD0=0;
    const TickType_t xDelay = 500 / portTICK_PERIOD_MS;
  while (1)
  {    
    /*TRISDbits.TRISD7=1;
    TRISDbits.TRISD1=0;
    LATDbits.LATD1=PORTDbits.RD7;*/
    /* Block for 500ms. */
         /* Simply toggle the LED every 500ms, blocking between each toggle. */
        LATDbits.LATD0=0;
        vTaskDelay( xDelay );
        LATDbits.LATD0=1;
        vTaskDelay( xDelay );
         
  }

  vTaskDelete(NULL);
}

int main()
{
  /* Initialize all modules */
  SYS_Initialize (NULL);
  
  xTaskCreate(TaskBlinkLED, (const portCHAR*) "LED", 1024, NULL, 1 , NULL);

  vTaskStartScheduler();
 
  /*while ( true )
  {
      SYS_Tasks ( );
  }
  */

  return ( EXIT_FAILURE );

}
/*******************************************************************************
 End of File
*/

