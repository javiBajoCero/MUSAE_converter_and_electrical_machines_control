/*
 * blikingled_28069M_launchpad.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "blikingled_28069M_launchpad".
 *
 * Model version              : 1.23
 * Simulink Coder version : 9.9 (R2023a) 19-Nov-2022
 * C source code generated on : Mon Mar 18 17:25:45 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "blikingled_28069M_launchpad.h"
#include "blikingled_28069M_launchpad_private.h"
#include "rtwtypes.h"
#include <math.h>
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
      blikingled_28069M_launchpad_M->Timing.clockTick2 =
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

      /* Sum: '<S4>/Sum' incorporates:
       *  Constant: '<S4>/Constant'
       *  Gain: '<S4>/Gain'
       */
      blikingled_28069M_launchpad_B.Sum = (real_T)((uint32_T)
        blikingled_28069M_launchpad_P.TranslatetoAmps2_Gain *
        blikingled_28069M_launchpad_B.ADC1[0]) * 3.0517578125E-5 -
        blikingled_28069M_launchpad_P.TranslatetoAmps2_Offset;

      /* Sum: '<S3>/Sum' incorporates:
       *  Constant: '<S3>/Constant'
       *  Gain: '<S3>/Gain'
       */
      blikingled_28069M_launchpad_B.Sum_h = (real_T)((uint32_T)
        blikingled_28069M_launchpad_P.TranslatetoAmps1_Gain *
        blikingled_28069M_launchpad_B.A0andB0[1]) * 3.0517578125E-5 -
        blikingled_28069M_launchpad_P.TranslatetoAmps1_Offset;

      /* Sum: '<S2>/Sum' incorporates:
       *  Constant: '<S2>/Constant'
       *  Gain: '<S2>/Gain'
       */
      blikingled_28069M_launchpad_B.Sum_f = (real_T)((uint32_T)
        blikingled_28069M_launchpad_P.TranslatetoAmps_Gain *
        blikingled_28069M_launchpad_B.A0andB0[0]) * 3.0517578125E-5 -
        blikingled_28069M_launchpad_P.TranslatetoAmps_Offset;
      blikingled_28069M_launchpad_DW.SimulinkFunction_SubsysRanBC = 4;

      /* End of Outputs for S-Function (c28xisr_c2000): '<Root>/C28x Hardware Interrupt' */
    }

    currentTime = (extmodeSimulationTime_T)
      blikingled_28069M_launchpad_M->Timing.clockTick0;
    extmodeEvent(2,currentTime);
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

  /* S-Function (c280xgpio_do): '<Root>/LOW SIDES OF THE INVERTER stay open' incorporates:
   *  Constant: '<Root>/Constant'
   */
  {
    if (blikingled_28069M_launchpad_P.Constant_Value[0]) {
      GpioDataRegs.GPASET.bit.GPIO3 = 1U;
    } else {
      GpioDataRegs.GPACLEAR.bit.GPIO3 = 1U;
    }

    if (blikingled_28069M_launchpad_P.Constant_Value[1]) {
      GpioDataRegs.GPASET.bit.GPIO5 = 1U;
    } else {
      GpioDataRegs.GPACLEAR.bit.GPIO5 = 1U;
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

  /* Sin: '<Root>/Sine Wave' */
  blikingled_28069M_launchpad_B.SineWave = sin
    (blikingled_28069M_launchpad_P.SineWave_Freq *
     blikingled_28069M_launchpad_M->Timing.t[0] +
     blikingled_28069M_launchpad_P.SineWave_Phase) *
    blikingled_28069M_launchpad_P.SineWave_Amp +
    blikingled_28069M_launchpad_P.SineWave_Bias;

  /* S-Function (c2802xpwm): '<Root>/pwm managing branch R' incorporates:
   *  Constant: '<Root>/Constant2'
   */
  {
    EPwm1Regs.TBPRD = (uint16_T)(blikingled_28069M_launchpad_P.Constant2_Value);
  }

  /*-- Update CMPA value for ePWM1 --*/
  {
    EPwm1Regs.CMPA.half.CMPA = (uint16_T)(blikingled_28069M_launchpad_B.SineWave);
  }

  {                                    /* Sample time: [0.0s, 0.0s] */
    extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
    extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T)
      ((blikingled_28069M_launchpad_M->Timing.clockTick0 * 1) + 0)
      ;

    /* Trigger External Mode event */
    errorCode = extmodeEvent(0,currentTime);
    if (errorCode != EXTMODE_SUCCESS) {
      /* Code to handle External Mode event errors
         may be added here */
    }
  }

  {                                    /* Sample time: [0.25s, 0.0s] */
    extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
    extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T)
      ((blikingled_28069M_launchpad_M->Timing.clockTick1 * 1) + 0)
      ;

    /* Trigger External Mode event */
    errorCode = extmodeEvent(1,currentTime);
    if (errorCode != EXTMODE_SUCCESS) {
      /* Code to handle External Mode event errors
         may be added here */
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  blikingled_28069M_launchpad_M->Timing.t[0] =
    ((time_T)(++blikingled_28069M_launchpad_M->Timing.clockTick0)) *
    blikingled_28069M_launchpad_M->Timing.stepSize0;

  {
    /* Update absolute timer for sample time: [0.25s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.25, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     */
    blikingled_28069M_launchpad_M->Timing.clockTick1++;
  }

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

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&blikingled_28069M_launchpad_M->solverInfo,
                          &blikingled_28069M_launchpad_M->Timing.simTimeStep);
    rtsiSetTPtr(&blikingled_28069M_launchpad_M->solverInfo, &rtmGetTPtr
                (blikingled_28069M_launchpad_M));
    rtsiSetStepSizePtr(&blikingled_28069M_launchpad_M->solverInfo,
                       &blikingled_28069M_launchpad_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&blikingled_28069M_launchpad_M->solverInfo,
                          (&rtmGetErrorStatus(blikingled_28069M_launchpad_M)));
    rtsiSetRTModelPtr(&blikingled_28069M_launchpad_M->solverInfo,
                      blikingled_28069M_launchpad_M);
  }

  rtsiSetSimTimeStep(&blikingled_28069M_launchpad_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&blikingled_28069M_launchpad_M->solverInfo,
                    "FixedStepDiscrete");
  rtmSetTPtr(blikingled_28069M_launchpad_M,
             &blikingled_28069M_launchpad_M->Timing.tArray[0]);
  rtmSetTFinal(blikingled_28069M_launchpad_M, -1);
  blikingled_28069M_launchpad_M->Timing.stepSize0 = 0.25;

  /* External mode info */
  blikingled_28069M_launchpad_M->Sizes.checksums[0] = (4231932301U);
  blikingled_28069M_launchpad_M->Sizes.checksums[1] = (2978598347U);
  blikingled_28069M_launchpad_M->Sizes.checksums[2] = (1559653003U);
  blikingled_28069M_launchpad_M->Sizes.checksums[3] = (214743051U);

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

  /* Start for S-Function (c280xgpio_do): '<Root>/LOW SIDES OF THE INVERTER stay open' */
  EALLOW;
  GpioCtrlRegs.GPAMUX1.all &= 0xFFFFF33FU;
  GpioCtrlRegs.GPADIR.all |= 0x28U;
  EDIS;

  /* Start for S-Function (c280xgpio_do): '<Root>/ENABLE THE DRV8305' */
  EALLOW;
  GpioCtrlRegs.GPBMUX2.all &= 0xFFFFFFCFU;
  GpioCtrlRegs.GPBDIR.all |= 0x40000U;
  EDIS;

  /* Start for S-Function (c2802xpwm): '<Root>/pwm managing branch R' incorporates:
   *  Constant: '<Root>/Constant2'
   */

  /*** Initialize ePWM1 modules ***/
  {
    /*  // Time Base Control Register
       EPwm1Regs.TBCTL.bit.CTRMODE              = 2U;          // Counter Mode
       EPwm1Regs.TBCTL.bit.SYNCOSEL             = 3U;          // Sync Output Select

       EPwm1Regs.TBCTL.bit.PRDLD                = 0U;          // Shadow select

       EPwm1Regs.TBCTL.bit.PHSEN                = 0U;          // Phase Load Enable
       EPwm1Regs.TBCTL.bit.PHSDIR               = 0U;          // Phase Direction Bit
       EPwm1Regs.TBCTL.bit.HSPCLKDIV            = 0U;          // High Speed TBCLK Pre-scaler
       EPwm1Regs.TBCTL.bit.CLKDIV               = 0U;          // Time Base Clock Pre-scaler
     */
    EPwm1Regs.TBCTL.all = (EPwm1Regs.TBCTL.all & ~0x3FFFU) | 0x32U;

    /*-- Setup Time-Base (TB) Submodule --*/
    EPwm1Regs.TBPRD = 64000U;          // Time Base Period Register

    /* // Time-Base Phase Register
       EPwm1Regs.TBPHS.half.TBPHS               = 0U;         // Phase offset register
     */
    EPwm1Regs.TBPHS.all = (EPwm1Regs.TBPHS.all & ~0xFFFF0000U) | 0x0U;

    // Time Base Counter Register
    EPwm1Regs.TBCTR = 0x0000U;         /* Clear counter*/

    /*-- Setup Counter_Compare (CC) Submodule --*/
    /*	// Counter Compare Control Register

       EPwm1Regs.CMPCTL.bit.LOADAMODE           = 0U;          // Active Compare A Load
       EPwm1Regs.CMPCTL.bit.LOADBMODE           = 0U;          // Active Compare B Load
       EPwm1Regs.CMPCTL.bit.SHDWAMODE           = 0U;          // Compare A Register Block Operating Mode
       EPwm1Regs.CMPCTL.bit.SHDWBMODE           = 0U;          // Compare B Register Block Operating Mode
     */
    EPwm1Regs.CMPCTL.all = (EPwm1Regs.CMPCTL.all & ~0x5FU) | 0x0U;
    EPwm1Regs.CMPA.half.CMPA = 32000U; // Counter Compare A Register
    EPwm1Regs.CMPB = 32000U;           // Counter Compare B Register

    /*-- Setup Action-Qualifier (AQ) Submodule --*/
    EPwm1Regs.AQCTLA.all = 150U;
                               // Action Qualifier Control Register For Output A
    EPwm1Regs.AQCTLB.all = 2310U;
                               // Action Qualifier Control Register For Output B

    /*	// Action Qualifier Software Force Register
       EPwm1Regs.AQSFRC.bit.RLDCSF              = 0U;          // Reload from Shadow Options
     */
    EPwm1Regs.AQSFRC.all = (EPwm1Regs.AQSFRC.all & ~0xC0U) | 0x0U;

    /*	// Action Qualifier Continuous S/W Force Register
       EPwm1Regs.AQCSFRC.bit.CSFA               = 0U;          // Continuous Software Force on output A
       EPwm1Regs.AQCSFRC.bit.CSFB               = 0U;          // Continuous Software Force on output B
     */
    EPwm1Regs.AQCSFRC.all = (EPwm1Regs.AQCSFRC.all & ~0xFU) | 0x0U;

    /*-- Setup Dead-Band Generator (DB) Submodule --*/
    /*	// Dead-Band Generator Control Register
       EPwm1Regs.DBCTL.bit.OUT_MODE             = 0U;          // Dead Band Output Mode Control
       EPwm1Regs.DBCTL.bit.IN_MODE              = 0U;          // Dead Band Input Select Mode Control
       EPwm1Regs.DBCTL.bit.POLSEL               = 0;          // Polarity Select Control
       EPwm1Regs.DBCTL.bit.HALFCYCLE            = 0U;          // Half Cycle Clocking Enable
     */
    EPwm1Regs.DBCTL.all = (EPwm1Regs.DBCTL.all & ~0x803FU) | 0x0U;
    EPwm1Regs.DBRED = 0U;// Dead-Band Generator Rising Edge Delay Count Register
    EPwm1Regs.DBFED = 0U;
                        // Dead-Band Generator Falling Edge Delay Count Register

    /*-- Setup Event-Trigger (ET) Submodule --*/
    /*	// Event Trigger Selection and Pre-Scale Register
       EPwm1Regs.ETSEL.bit.SOCAEN               = 1U;          // Start of Conversion A Enable
       EPwm1Regs.ETSEL.bit.SOCASEL              = 1U;          // Start of Conversion A Select
       EPwm1Regs.ETPS.bit.SOCAPRD               = 1U;          // EPWM1SOCA Period Select
       EPwm1Regs.ETSEL.bit.SOCBEN               = 0U;          // Start of Conversion B Enable
       EPwm1Regs.ETSEL.bit.SOCBSEL              = 1U;          // Start of Conversion B Select
       EPwm1Regs.ETPS.bit.SOCBPRD               = 1U;          // EPWM1SOCB Period Select
       EPwm1Regs.ETSEL.bit.INTEN                = 0U;          // EPWM1INTn Enable
       EPwm1Regs.ETSEL.bit.INTSEL               = 1U;          // EPWM1INTn Select
       EPwm1Regs.ETPS.bit.INTPRD                = 1U;          // EPWM1INTn Period Select
     */
    EPwm1Regs.ETSEL.all = (EPwm1Regs.ETSEL.all & ~0xFF0FU) | 0x1901U;
    EPwm1Regs.ETPS.all = (EPwm1Regs.ETPS.all & ~0x3303U) | 0x1101U;

    /*-- Setup PWM-Chopper (PC) Submodule --*/
    /*	// PWM Chopper Control Register
       EPwm1Regs.PCCTL.bit.CHPEN                = 0U;          // PWM chopping enable
       EPwm1Regs.PCCTL.bit.CHPFREQ              = 0U;          // Chopping clock frequency
       EPwm1Regs.PCCTL.bit.OSHTWTH              = 0U;          // One-shot pulse width
       EPwm1Regs.PCCTL.bit.CHPDUTY              = 0U;          // Chopping clock Duty cycle
     */
    EPwm1Regs.PCCTL.all = (EPwm1Regs.PCCTL.all & ~0x7FFU) | 0x0U;

    /*-- Set up Trip-Zone (TZ) Submodule --*/
    EALLOW;
    EPwm1Regs.TZSEL.all = 0U;          // Trip Zone Select Register

    /*	// Trip Zone Control Register
       EPwm1Regs.TZCTL.bit.TZA                  = 3U;          // TZ1 to TZ6 Trip Action On EPWM1A
       EPwm1Regs.TZCTL.bit.TZB                  = 3U;          // TZ1 to TZ6 Trip Action On EPWM1B
       EPwm1Regs.TZCTL.bit.DCAEVT1              = 3U;          // EPWM1A action on DCAEVT1
       EPwm1Regs.TZCTL.bit.DCAEVT2              = 3U;          // EPWM1A action on DCAEVT2
       EPwm1Regs.TZCTL.bit.DCBEVT1              = 3U;          // EPWM1B action on DCBEVT1
       EPwm1Regs.TZCTL.bit.DCBEVT2              = 3U;          // EPWM1B action on DCBEVT2
     */
    EPwm1Regs.TZCTL.all = (EPwm1Regs.TZCTL.all & ~0xFFFU) | 0xFFFU;

    /*	// Trip Zone Enable Interrupt Register
       EPwm1Regs.TZEINT.bit.OST                 = 0U;          // Trip Zones One Shot Int Enable
       EPwm1Regs.TZEINT.bit.CBC                 = 0U;          // Trip Zones Cycle By Cycle Int Enable
       EPwm1Regs.TZEINT.bit.DCAEVT1             = 0U;          // Digital Compare A Event 1 Int Enable
       EPwm1Regs.TZEINT.bit.DCAEVT2             = 0U;          // Digital Compare A Event 2 Int Enable
       EPwm1Regs.TZEINT.bit.DCBEVT1             = 0U;          // Digital Compare B Event 1 Int Enable
       EPwm1Regs.TZEINT.bit.DCBEVT2             = 0U;          // Digital Compare B Event 2 Int Enable
     */
    EPwm1Regs.TZEINT.all = (EPwm1Regs.TZEINT.all & ~0x7EU) | 0x0U;

    /*	// Digital Compare A Control Register
       EPwm1Regs.DCACTL.bit.EVT1SYNCE           = 0U;          // DCAEVT1 SYNC Enable
       EPwm1Regs.DCACTL.bit.EVT1SOCE            = 0U;          // DCAEVT1 SOC Enable
       EPwm1Regs.DCACTL.bit.EVT1FRCSYNCSEL      = 0U;          // DCAEVT1 Force Sync Signal
       EPwm1Regs.DCACTL.bit.EVT1SRCSEL          = 0U;          // DCAEVT1 Source Signal
       EPwm1Regs.DCACTL.bit.EVT2FRCSYNCSEL      = 0U;          // DCAEVT2 Force Sync Signal
       EPwm1Regs.DCACTL.bit.EVT2SRCSEL          = 0U;          // DCAEVT2 Source Signal
     */
    EPwm1Regs.DCACTL.all = (EPwm1Regs.DCACTL.all & ~0x30FU) | 0x0U;

    /*	// Digital Compare B Control Register
       EPwm1Regs.DCBCTL.bit.EVT1SYNCE           = 0U;          // DCBEVT1 SYNC Enable
       EPwm1Regs.DCBCTL.bit.EVT1SOCE            = 0U;          // DCBEVT1 SOC Enable
       EPwm1Regs.DCBCTL.bit.EVT1FRCSYNCSEL      = 0U;          // DCBEVT1 Force Sync Signal
       EPwm1Regs.DCBCTL.bit.EVT1SRCSEL          = 0U;          // DCBEVT1 Source Signal
       EPwm1Regs.DCBCTL.bit.EVT2FRCSYNCSEL      = 0U;          // DCBEVT2 Force Sync Signal
       EPwm1Regs.DCBCTL.bit.EVT2SRCSEL          = 0U;          // DCBEVT2 Source Signal
     */
    EPwm1Regs.DCBCTL.all = (EPwm1Regs.DCBCTL.all & ~0x30FU) | 0x0U;

    /*	// Digital Compare Trip Select Register
       EPwm1Regs.DCTRIPSEL.bit.DCAHCOMPSEL      = 0U;          // Digital Compare A High COMP Input Select

       EPwm1Regs.DCTRIPSEL.bit.DCALCOMPSEL      = 0U;          // Digital Compare A Low COMP Input Select
       EPwm1Regs.DCTRIPSEL.bit.DCBHCOMPSEL      = 0U;          // Digital Compare B High COMP Input Select
       EPwm1Regs.DCTRIPSEL.bit.DCBLCOMPSEL      = 0U;          // Digital Compare B Low COMP Input Select
     */
    EPwm1Regs.DCTRIPSEL.all = (EPwm1Regs.DCTRIPSEL.all & ~ 0xFFFFU) | 0x0U;

    /*	// Trip Zone Digital Comparator Select Register
       EPwm1Regs.TZDCSEL.bit.DCAEVT1            = 0U;          // Digital Compare Output A Event 1
       EPwm1Regs.TZDCSEL.bit.DCAEVT2            = 0U;          // Digital Compare Output A Event 2
       EPwm1Regs.TZDCSEL.bit.DCBEVT1            = 0U;          // Digital Compare Output B Event 1
       EPwm1Regs.TZDCSEL.bit.DCBEVT2            = 0U;          // Digital Compare Output B Event 2
     */
    EPwm1Regs.TZDCSEL.all = (EPwm1Regs.TZDCSEL.all & ~0xFFFU) | 0x0U;

    /*	// Digital Compare Filter Control Register
       EPwm1Regs.DCFCTL.bit.BLANKE              = 0U;          // Blanking Enable/Disable
       EPwm1Regs.DCFCTL.bit.PULSESEL            = 1U;          // Pulse Select for Blanking & Capture Alignment
       EPwm1Regs.DCFCTL.bit.BLANKINV            = 0U;          // Blanking Window Inversion
       EPwm1Regs.DCFCTL.bit.SRCSEL              = 0U;          // Filter Block Signal Source Select
     */
    EPwm1Regs.DCFCTL.all = (EPwm1Regs.DCFCTL.all & ~0x3FU) | 0x10U;
    EPwm1Regs.DCFOFFSET = 0U;          // Digital Compare Filter Offset Register
    EPwm1Regs.DCFWINDOW = 0U;          // Digital Compare Filter Window Register

    /*	// Digital Compare Capture Control Register
       EPwm1Regs.DCCAPCTL.bit.CAPE              = 0U;          // Counter Capture Enable
     */
    EPwm1Regs.DCCAPCTL.all = (EPwm1Regs.DCCAPCTL.all & ~0x1U) | 0x0U;

    /*	// HRPWM Configuration Register
       EPwm1Regs.HRCNFG.bit.SWAPAB              = 0U;          // Swap EPWMA and EPWMB Outputs Bit
       EPwm1Regs.HRCNFG.bit.SELOUTB             = 0U;          // EPWMB Output Selection Bit
     */
    EPwm1Regs.HRCNFG.all = (EPwm1Regs.HRCNFG.all & ~0xA0U) | 0x0U;
    EDIS;
  }

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
  blikingled_28069M_launchpad_M->Timing.clockTick2 =
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
