#include "c2000BoardSupport.h"
#include "MW_f2837xD_includes.h"
#include "rtwtypes.h"
#include "feedback_plant.h"
#include "feedback_plant_private.h"

void enableExtInterrupt (void);
void configureGPIOExtInterrupt(void);

#include <stdint.h>

void disableWatchdog(void)
{
  int *WatchdogWDCR = (int *)(uintptr_t)0x7029;
  asm(" EALLOW ");
  *WatchdogWDCR = 0x0068;
  asm(" EDIS ");
}
