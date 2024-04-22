/*
 * blikingled_28069M_launchpad.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "blikingled_28069M_launchpad".
 *
 * Model version              : 1.29
 * Simulink Coder version : 9.9 (R2023a) 19-Nov-2022
 * C source code generated on : Mon Apr 22 17:06:50 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "blikingled_28069M_launchpad.h"
#include "blikingled_28069M_launchpad_private.h"
#include "rtwtypes.h"
#include <string.h>
#include "xcp.h"
#include "ext_mode.h"

extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T) 0;

/* Block signals (default storage) */
B_blikingled_28069M_launchpad_T blikingled_28069M_launchpad_B;

/* Block states (default storage) */
DW_blikingled_28069M_launchpa_T blikingled_28069M_launchpad_DW;

/* Real-time model */
static RT_MODEL_blikingled_28069M_la_T blikingled_28069M_launchpad_M_;
RT_MODEL_blikingled_28069M_la_T *const blikingled_28069M_launchpad_M =
  &blikingled_28069M_launchpad_M_;

#ifndef __TMS320C28XX_CLA__

uint16_T MW_adcInitFlag = 0;

#endif

/* Hardware Interrupt Block: '<Root>/C28x Hardware Interrupt' */
void isr_int1pie1_task_fcn(void)
{
  if (1 == runModel) {
    /* Call the system: <Root>/Simulink Function */
    {
      /* Reset subsysRan breadcrumbs */
      srClearBC(blikingled_28069M_launchpad_DW.SimulinkFunction_SubsysRanBC);

      /* S-Function (c28xisr_c2000): '<Root>/C28x Hardware Interrupt' */

      /* Output and update for function-call system: '<Root>/Simulink Function' */

      /* Asynchronous task reads absolute time. Data (absolute time)
         transfers from low priority task (base rate) to high priority
         task (asynchronous rate). Double buffers are used to ensure
         data integrity.
         -- rtmL2HLastBufWr is the buffer index that is written last.
       */
      blikingled_28069M_launchpad_M->Timing.clockTick1 =
        blikingled_28069M_launchpad_M->
        Timing.rtmL2HDbBufClockTick
        [blikingled_28069M_launchpad_M->Timing.rtmL2HLastBufWr];

      /* S-Function (c2802xadc): '<S1>/ADC' */
      {
        /*  Internal Reference Voltage : Fixed scale 0 to 3.3 V range.  */
        /*  External Reference Voltage : Allowable ranges of VREFHI(ADCINA0) = 3.3 and VREFLO(tied to ground) = 0  */
        blikingled_28069M_launchpad_B.A0andB0[0] = (AdcResult.ADCRESULT0);
        blikingled_28069M_launchpad_B.A0andB0[1] = (AdcResult.ADCRESULT1);
      }

      /* S-Function (c2802xadc): '<S1>/ADC1' */
      {
        /*  Internal Reference Voltage : Fixed scale 0 to 3.3 V range.  */
        /*  External Reference Voltage : Allowable ranges of VREFHI(ADCINA0) = 3.3 and VREFLO(tied to ground) = 0  */
        blikingled_28069M_launchpad_B.ADC1[0] = (AdcResult.ADCRESULT2);
        blikingled_28069M_launchpad_B.ADC1[1] = (AdcResult.ADCRESULT3);
      }

      /* S-Function (c2802xadc): '<S1>/ADC2' */
      {
        /*  Internal Reference Voltage : Fixed scale 0 to 3.3 V range.  */
        /*  External Reference Voltage : Allowable ranges of VREFHI(ADCINA0) = 3.3 and VREFLO(tied to ground) = 0  */
        blikingled_28069M_launchpad_B.ADC2[0] = (AdcResult.ADCRESULT4);
        blikingled_28069M_launchpad_B.ADC2[1] = (AdcResult.ADCRESULT5);
      }

      /* Gain: '<S5>/Gain' incorporates:
       *  Constant: '<S5>/Constant'
       *  Constant: '<S9>/Constant'
       *  Gain: '<S9>/Gain'
       *  Sum: '<S5>/Sum'
       *  Sum: '<S9>/Sum'
       */
      blikingled_28069M_launchpad_B.Gain = (((real_T)
        blikingled_28069M_launchpad_B.ADC2[1] -
        blikingled_28069M_launchpad_P.calibration3_Offset) *
        blikingled_28069M_launchpad_P.calibration3_Gain -
        blikingled_28069M_launchpad_P.TranslatetoVolts_Offset) *
        blikingled_28069M_launchpad_P.TranslatetoVolts_Gain;

      /* Gain: '<S4>/Gain' incorporates:
       *  Constant: '<S4>/Constant'
       *  Constant: '<S8>/Constant'
       *  Gain: '<S8>/Gain'
       *  Sum: '<S4>/Sum'
       *  Sum: '<S8>/Sum'
       */
      blikingled_28069M_launchpad_B.Gain_l = (((real_T)
        blikingled_28069M_launchpad_B.ADC1[0] -
        blikingled_28069M_launchpad_P.calibration2_Offset) *
        blikingled_28069M_launchpad_P.calibration2_Gain -
        blikingled_28069M_launchpad_P.TranslatetoAmps2_Offset) *
        blikingled_28069M_launchpad_P.TranslatetoAmps2_Gain;

      /* Gain: '<S3>/Gain' incorporates:
       *  Constant: '<S3>/Constant'
       *  Constant: '<S7>/Constant'
       *  Gain: '<S7>/Gain'
       *  Sum: '<S3>/Sum'
       *  Sum: '<S7>/Sum'
       */
      blikingled_28069M_launchpad_B.Gain_h = (((real_T)
        blikingled_28069M_launchpad_B.A0andB0[1] -
        blikingled_28069M_launchpad_P.calibration1_Offset) *
        blikingled_28069M_launchpad_P.calibration1_Gain -
        blikingled_28069M_launchpad_P.TranslatetoAmps1_Offset) *
        blikingled_28069M_launchpad_P.TranslatetoAmps1_Gain;

      /* Gain: '<S2>/Gain' incorporates:
       *  Constant: '<S2>/Constant'
       *  Constant: '<S6>/Constant'
       *  Gain: '<S6>/Gain'
       *  Sum: '<S2>/Sum'
       *  Sum: '<S6>/Sum'
       */
      blikingled_28069M_launchpad_B.Gain_b = (((real_T)
        blikingled_28069M_launchpad_B.A0andB0[0] -
        blikingled_28069M_launchpad_P.calibration_Offset) *
        blikingled_28069M_launchpad_P.calibration_Gain -
        blikingled_28069M_launchpad_P.TranslatetoAmps_Offset) *
        blikingled_28069M_launchpad_P.TranslatetoAmps_Gain;
      blikingled_28069M_launchpad_DW.SimulinkFunction_SubsysRanBC = 4;

      /* End of Outputs for S-Function (c28xisr_c2000): '<Root>/C28x Hardware Interrupt' */
    }

    currentTime = (extmodeSimulationTime_T)
      blikingled_28069M_launchpad_M->Timing.clockTick0;
    extmodeEvent(1,currentTime);
  }
}

/* Model step function */
void blikingled_28069M_launchpad_step(void)
{
  /* DiscretePulseGenerator: '<Root>/2Hz pulse' */
  blikingled_28069M_launchpad_B.uHzpulse =
    (blikingled_28069M_launchpad_DW.clockTickCounter <
     blikingled_28069M_launchpad_P.uHzpulse_Duty) &&
    (blikingled_28069M_launchpad_DW.clockTickCounter >= 0L) ?
    blikingled_28069M_launchpad_P.uHzpulse_Amp : 0.0;

  /* DiscretePulseGenerator: '<Root>/2Hz pulse' */
  if (blikingled_28069M_launchpad_DW.clockTickCounter >=
      blikingled_28069M_launchpad_P.uHzpulse_Period - 1.0) {
    blikingled_28069M_launchpad_DW.clockTickCounter = 0L;
  } else {
    blikingled_28069M_launchpad_DW.clockTickCounter++;
  }

  /* S-Function (c280xgpio_do): '<Root>/RED LED' */
  {
    if (blikingled_28069M_launchpad_B.uHzpulse) {
      GpioDataRegs.GPBSET.bit.GPIO34 = 1U;
    } else {
      GpioDataRegs.GPBCLEAR.bit.GPIO34 = 1U;
    }
  }

  /* S-Function (c280xgpio_do): '<Root>/ENABLE THE DRV8305' incorporates:
   *  Constant: '<Root>/Constant1'
   */
  {
    if (blikingled_28069M_launchpad_P.Constant1_Value) {
      GpioDataRegs.GPBSET.bit.GPIO50 = 1U;
    } else {
      GpioDataRegs.GPBCLEAR.bit.GPIO50 = 1U;
    }
  }

  {                                    /* Sample time: [0.25s, 0.0s] */
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

  {
    /* Base rate updates double buffers of absolute time for
       asynchronous task. Double buffers are used to ensure
       data integrity when asynchronous task reads absolute
       time.
       -- rtmL2HLastBufWr is the buffer index that is written last.
     */
    boolean_T bufIdx = !(blikingled_28069M_launchpad_M->Timing.rtmL2HLastBufWr
                         != 0U);
    blikingled_28069M_launchpad_M->Timing.rtmL2HDbBufClockTick[bufIdx] =
      blikingled_28069M_launchpad_M->Timing.clockTick0;
    blikingled_28069M_launchpad_M->Timing.rtmL2HLastBufWr = bufIdx ? 1U : 0U;
  }
}

/* Model initialize function */
void blikingled_28069M_launchpad_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)blikingled_28069M_launchpad_M, 0,
                sizeof(RT_MODEL_blikingled_28069M_la_T));
  rtmSetTFinal(blikingled_28069M_launchpad_M, -1);
  blikingled_28069M_launchpad_M->Timing.stepSize0 = 0.25;

  /* External mode info */
  blikingled_28069M_launchpad_M->Sizes.checksums[0] = (2553170977U);
  blikingled_28069M_launchpad_M->Sizes.checksums[1] = (3389296948U);
  blikingled_28069M_launchpad_M->Sizes.checksums[2] = (1267224937U);
  blikingled_28069M_launchpad_M->Sizes.checksums[3] = (3940932301U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[2];
    blikingled_28069M_launchpad_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = (sysRanDType *)
      &blikingled_28069M_launchpad_DW.SimulinkFunction_SubsysRanBC;
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

  /* Start for DiscretePulseGenerator: '<Root>/2Hz pulse' */
  blikingled_28069M_launchpad_DW.clockTickCounter = 0L;

  /* Start for S-Function (c280xgpio_do): '<Root>/RED LED' */
  EALLOW;
  GpioCtrlRegs.GPBMUX1.all &= 0xFFFFFFCFU;
  GpioCtrlRegs.GPBDIR.all |= 0x4U;
  EDIS;

  /* Start for S-Function (c280xgpio_do): '<Root>/ENABLE THE DRV8305' */
  EALLOW;
  GpioCtrlRegs.GPBMUX2.all &= 0xFFFFFFCFU;
  GpioCtrlRegs.GPBDIR.all |= 0x40000U;
  EDIS;

  /* SystemInitialize for S-Function (c28xisr_c2000): '<Root>/C28x Hardware Interrupt' incorporates:
   *  SubSystem: '<Root>/Simulink Function'
   */

  /* System initialize for function-call system: '<Root>/Simulink Function' */

  /* Asynchronous task reads absolute time. Data (absolute time)
     transfers from low priority task (base rate) to high priority
     task (asynchronous rate). Double buffers are used to ensure
     data integrity.
     -- rtmL2HLastBufWr is the buffer index that is written last.
   */
  blikingled_28069M_launchpad_M->Timing.clockTick1 =
    blikingled_28069M_launchpad_M->
    Timing.rtmL2HDbBufClockTick
    [blikingled_28069M_launchpad_M->Timing.rtmL2HLastBufWr];

  /* Start for S-Function (c2802xadc): '<S1>/ADC' */
  if (MW_adcInitFlag == 0U) {
    InitAdc();
    MW_adcInitFlag = 1U;
  }

  config_ADC_SOC0_SOC1 ();

  /* Start for S-Function (c2802xadc): '<S1>/ADC1' */
  if (MW_adcInitFlag == 0U) {
    InitAdc();
    MW_adcInitFlag = 1U;
  }

  config_ADC_SOC2_SOC3 ();

  /* Start for S-Function (c2802xadc): '<S1>/ADC2' */
  if (MW_adcInitFlag == 0U) {
    InitAdc();
    MW_adcInitFlag = 1U;
  }

  config_ADC_SOC4_SOC5 ();

  /* End of SystemInitialize for S-Function (c28xisr_c2000): '<Root>/C28x Hardware Interrupt' */
}

/* Model terminate function */
void blikingled_28069M_launchpad_terminate(void)
{
  /* (no terminate code required) */
}
