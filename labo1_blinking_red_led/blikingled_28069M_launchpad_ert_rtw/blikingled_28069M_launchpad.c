/*
 * blikingled_28069M_launchpad.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "blikingled_28069M_launchpad".
 *
 * Model version              : 1.7
 * Simulink Coder version : 9.9 (R2023a) 19-Nov-2022
 * C source code generated on : Tue Feb 27 13:09:28 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "blikingled_28069M_launchpad.h"
#include "rtwtypes.h"
#include "blikingled_28069M_launchpad_private.h"
#include <string.h>

/* Block signals (default storage) */
B_blikingled_28069M_launchpad_T blikingled_28069M_launchpad_B;

/* Block states (default storage) */
DW_blikingled_28069M_launchpa_T blikingled_28069M_launchpad_DW;

/* Real-time model */
static RT_MODEL_blikingled_28069M_la_T blikingled_28069M_launchpad_M_;
RT_MODEL_blikingled_28069M_la_T *const blikingled_28069M_launchpad_M =
  &blikingled_28069M_launchpad_M_;

/* Model step function */
void blikingled_28069M_launchpad_step(void)
{
  /* DiscretePulseGenerator: '<Root>/RED_LED' */
  blikingled_28069M_launchpad_B.RED_LED =
    (blikingled_28069M_launchpad_DW.clockTickCounter <
     blikingled_28069M_launchpad_P.RED_LED_Duty) &&
    (blikingled_28069M_launchpad_DW.clockTickCounter >= 0L) ?
    blikingled_28069M_launchpad_P.RED_LED_Amp : 0.0;

  /* DiscretePulseGenerator: '<Root>/RED_LED' */
  if (blikingled_28069M_launchpad_DW.clockTickCounter >=
      blikingled_28069M_launchpad_P.RED_LED_Period - 1.0) {
    blikingled_28069M_launchpad_DW.clockTickCounter = 0L;
  } else {
    blikingled_28069M_launchpad_DW.clockTickCounter++;
  }

  /* S-Function (c280xgpio_do): '<Root>/Digital Output' */
  {
    if (blikingled_28069M_launchpad_B.RED_LED) {
      GpioDataRegs.GPBSET.bit.GPIO34 = 1U;
    } else {
      GpioDataRegs.GPBCLEAR.bit.GPIO34 = 1U;
    }
  }

  {                                    /* Sample time: [0.025s, 0.0s] */
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  blikingled_28069M_launchpad_M->Timing.taskTime0 =
    ((time_T)(++blikingled_28069M_launchpad_M->Timing.clockTick0)) *
    blikingled_28069M_launchpad_M->Timing.stepSize0;
}

/* Model initialize function */
void blikingled_28069M_launchpad_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)blikingled_28069M_launchpad_M, 0,
                sizeof(RT_MODEL_blikingled_28069M_la_T));
  rtmSetTFinal(blikingled_28069M_launchpad_M, 10.0);
  blikingled_28069M_launchpad_M->Timing.stepSize0 = 0.025;

  /* External mode info */
  blikingled_28069M_launchpad_M->Sizes.checksums[0] = (3271864882U);
  blikingled_28069M_launchpad_M->Sizes.checksums[1] = (516924145U);
  blikingled_28069M_launchpad_M->Sizes.checksums[2] = (3772957000U);
  blikingled_28069M_launchpad_M->Sizes.checksums[3] = (217896674U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    blikingled_28069M_launchpad_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(blikingled_28069M_launchpad_M->extModeInfo,
      &blikingled_28069M_launchpad_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(blikingled_28069M_launchpad_M->extModeInfo,
                        blikingled_28069M_launchpad_M->Sizes.checksums);
    rteiSetTPtr(blikingled_28069M_launchpad_M->extModeInfo, rtmGetTPtr
                (blikingled_28069M_launchpad_M));
  }

  /* block I/O */
  (void) memset(((void *) &blikingled_28069M_launchpad_B), 0,
                sizeof(B_blikingled_28069M_launchpad_T));

  /* states (dwork) */
  (void) memset((void *)&blikingled_28069M_launchpad_DW, 0,
                sizeof(DW_blikingled_28069M_launchpa_T));

  /* Start for DiscretePulseGenerator: '<Root>/RED_LED' */
  blikingled_28069M_launchpad_DW.clockTickCounter = 0L;

  /* Start for S-Function (c280xgpio_do): '<Root>/Digital Output' */
  EALLOW;
  GpioCtrlRegs.GPBMUX1.all &= 0xFFFFFFCFU;
  GpioCtrlRegs.GPBDIR.all |= 0x4U;
  EDIS;
}

/* Model terminate function */
void blikingled_28069M_launchpad_terminate(void)
{
  /* (no terminate code required) */
}
