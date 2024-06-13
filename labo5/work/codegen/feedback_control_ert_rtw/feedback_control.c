/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: feedback_control.c
 *
 * Code generated for Simulink model 'feedback_control'.
 *
 * Model version                  : 14.59
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Mon May 13 16:51:41 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objective: Traceability
 * Validation result: Not run
 */

#include "feedback_control.h"
#include "feedback_control_private.h"
#include "rtwtypes.h"
#include <string.h>
#include "xcp.h"
#include "ext_mode.h"

extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T) 0;

/* Block signals (default storage) */
BlockIO_feedback_control feedback_control_B;

/* Block states (default storage) */
D_Work_feedback_control feedback_control_DWork;

/* External inputs (root inport signals with default storage) */
ExternalInputs_feedback_control feedback_control_U;

/* Real-time model */
static RT_MODEL_feedback_control feedback_control_M_;
RT_MODEL_feedback_control *const feedback_control_M = &feedback_control_M_;
static void rate_monotonic_scheduler(void);

#ifndef __TMS320C28XX_CLA__

uint16_T MW_adcCInitFlag = 0;

#endif

#ifndef __TMS320C28XX_CLA__

uint16_T MW_adcAInitFlag = 0;

#endif

#ifndef __TMS320C28XX_CLA__

uint16_T MW_adcBInitFlag = 0;

#endif

/* Hardware Interrupt Block: '<Root>/C28x Hardware Interrupt' */
void isr_int1pie1_task_fcn(void)
{
  if (1 == runModel) {
    /* Call the system: <Root>/Three Phase Converter Control */
    {
      /* Reset subsysRan breadcrumbs */
      srClearBC(feedback_control_DWork.IfActionSubsystem_SubsysRanBC);

      /* Reset subsysRan breadcrumbs */
      srClearBC(feedback_control_DWork.IfActionSubsystem1_SubsysRanBC);

      /* Reset subsysRan breadcrumbs */
      srClearBC(feedback_control_DWork.PositionNoReset_SubsysRanBC);

      /* Reset subsysRan breadcrumbs */
      srClearBC(feedback_control_DWork.PositionResetAtIndex_SubsysRanB);

      /* Reset subsysRan breadcrumbs */
      srClearBC(feedback_control_DWork.ThreePhaseConverterControl_Subs);

      /* RateTransition generated from: '<Root>/Three Phase Converter Control' */
      feedback_control_B.TmpRTBAtThreePhaseConverterCont =
        feedback_control_DWork.TmpRTBAtThreePhaseConverterCont;

      /* S-Function (c28xisr_c2000): '<Root>/C28x Hardware Interrupt' */

      /* Output and update for function-call system: '<Root>/Three Phase Converter Control' */
      {
        real32_T rtb_ManualSwitch[3];
        real32_T rtb_Add_c;
        real32_T rtb_Gain2_p;
        uint32_T y;
        uint16_T rtb_Merge_c;
        uint16_T rtb_Sum3;

        /* Asynchronous task reads absolute time. Data (absolute time)
           transfers from low priority task (base rate) to high priority
           task (asynchronous rate). Double buffers are used to ensure
           data integrity.
           -- rtmL2HLastBufWr is the buffer index that is written last.
         */
        feedback_control_M->Timing.clockTick2 =
          feedback_control_M->Timing.rtmL2HDbBufClockTick
          [feedback_control_M->Timing.rtmL2HLastBufWr];

        /* Sum: '<S24>/Sum of Elements' incorporates:
         *  UnitDelay: '<S24>/Unit Delay'
         */
        feedback_control_B.SumofElements =
          feedback_control_DWork.UnitDelay_DSTATE;

        /* S-Function (c2802xadc): '<S19>/ADC' */
        {
          /*  Internal Reference Voltage : Fixed scale 0 to 3.3 V range.  */
          /*  External Reference Voltage : Allowable ranges of VREFHI(ADCINA0) = 3.3 and VREFLO(tied to ground) = 0  */
          feedback_control_B.ADC = (AdccResultRegs.ADCRESULT0);
        }

        /* S-Function (c2802xadc): '<S19>/ADC3' */
        {
          /*  Internal Reference Voltage : Fixed scale 0 to 3.3 V range.  */
          /*  External Reference Voltage : Allowable ranges of VREFHI(ADCINA0) = 3.3 and VREFLO(tied to ground) = 0  */
          feedback_control_B.ADC3 = (AdcaResultRegs.ADCRESULT3);
        }

        /* Gain: '<S23>/Gain1' incorporates:
         *  Constant: '<S23>/Offset'
         *  DataTypeConversion: '<S23>/Data Type Conversion'
         *  Sum: '<S23>/Add'
         */
        feedback_control_DWork.UnitDelay_DSTATE = (((real32_T)
          feedback_control_B.ADC3) - feedback_control_P.Calibrate_Vdc_Offset) *
          feedback_control_P.Calibrate_Vdc_Gain;

        /* Constant: '<S5>/V_Ref' */
        feedback_control_B.V_Ref = feedback_control_P.V_Ref_Value;

        /* Sum: '<S16>/Add' incorporates:
         *  Constant: '<S16>/Constant'
         *  UnitDelay: '<S16>/Unit Delay1'
         */
        feedback_control_B.Times_Interrupt = feedback_control_P.Constant_Value_n
          + feedback_control_DWork.UnitDelay1_DSTATE_h;

        /* Math: '<S16>/Math Function' incorporates:
         *  Constant: '<S16>/Constant1'
         */
        if (feedback_control_P.Constant1_Value_j == 0UL) {
          y = 0UL;
        } else {
          y = feedback_control_B.Times_Interrupt %
            feedback_control_P.Constant1_Value_j;
        }

        /* End of Math: '<S16>/Math Function' */

        /* Switch: '<S16>/Switch' incorporates:
         *  Constant: '<S16>/Constant2'
         *  Sum: '<S16>/Add1'
         */
        if ((y - feedback_control_P.Constant2_Value_h) >
            feedback_control_P.Switch_Threshold) {
          /* SignalConversion generated from: '<S5>/Variant Source' incorporates:
           *  Constant: '<S16>/Constant3'
           */
          feedback_control_B.I_Reference = feedback_control_P.Constant3_Value;
        } else {
          /* SignalConversion generated from: '<S5>/Variant Source' incorporates:
           *  Constant: '<S16>/Constant4'
           */
          feedback_control_B.I_Reference = feedback_control_P.Constant4_Value;
        }

        /* End of Switch: '<S16>/Switch' */

        /* Gain: '<S20>/Gain1' incorporates:
         *  Constant: '<S20>/Offset'
         *  DataTypeConversion: '<S20>/Data Type Conversion'
         *  Sum: '<S20>/Add'
         */
        feedback_control_B.Gain1 = (((real32_T)feedback_control_B.ADC) -
          feedback_control_P.Calibrate_Ir_Offset) *
          feedback_control_P.Calibrate_Ir_Gain;

        /* Sum: '<S13>/Add' */
        rtb_Add_c = feedback_control_B.I_Reference - feedback_control_B.Gain1;

        /* Sum: '<S13>/Add1' incorporates:
         *  Gain: '<S13>/Gain'
         *  Gain: '<S13>/Gain1'
         *  UnitDelay: '<S13>/Unit Delay'
         *  UnitDelay: '<S13>/Unit Delay1'
         */
        feedback_control_DWork.UnitDelay1_DSTATE +=
          (feedback_control_P.Gain_Gain * rtb_Add_c) +
          (feedback_control_P.Gain1_Gain_c *
           feedback_control_DWork.UnitDelay_DSTATE_g);

        /* Switch: '<S18>/Switch2' incorporates:
         *  RelationalOperator: '<S18>/LowerRelop1'
         */
        if (feedback_control_DWork.UnitDelay1_DSTATE >
            feedback_control_DWork.UnitDelay_DSTATE) {
          /* Sum: '<S13>/Add1' */
          feedback_control_DWork.UnitDelay1_DSTATE =
            feedback_control_DWork.UnitDelay_DSTATE;
        } else {
          /* Gain: '<S13>/Gain2' */
          rtb_Gain2_p = feedback_control_P.Gain2_Gain *
            feedback_control_DWork.UnitDelay_DSTATE;

          /* Switch: '<S18>/Switch' incorporates:
           *  RelationalOperator: '<S18>/UpperRelop'
           */
          if (feedback_control_DWork.UnitDelay1_DSTATE < rtb_Gain2_p) {
            /* Sum: '<S13>/Add1' */
            feedback_control_DWork.UnitDelay1_DSTATE = rtb_Gain2_p;
          }

          /* End of Switch: '<S18>/Switch' */
        }

        /* End of Switch: '<S18>/Switch2' */

        /* ManualSwitch: '<S17>/Manual Switch' incorporates:
         *  Constant: '<S15>/Constant1'
         *  Constant: '<S17>/Constant2'
         *  Constant: '<S5>/Constant4'
         *  Gain: '<S17>/Period'
         *  Sum: '<S15>/Sum'
         */
        if (feedback_control_P.ManualSwitch_CurrentSetting_j == 1U) {
          /* ManualSwitch: '<S15>/Manual Switch' incorporates:
           *  Constant: '<S15>/Constant2'
           *  Constant: '<S15>/Constant3'
           *  Gain: '<S15>/Gain1'
           *  ManualSwitch: '<S5>/Manual Switch'
           *  Product: '<S15>/Divide'
           *  Sum: '<S15>/Sum1'
           */
          if (feedback_control_P.ManualSwitch_CurrentSetting_d == 1U) {
            /* ManualSwitch: '<S5>/Manual Switch' */
            if (feedback_control_P.ManualSwitch_CurrentSetting == 1U) {
              rtb_Gain2_p = feedback_control_B.V_Ref;
            } else {
              rtb_Gain2_p = feedback_control_DWork.UnitDelay1_DSTATE;
            }

            rtb_Gain2_p = ((feedback_control_P.Gain1_Gain * rtb_Gain2_p) /
                           feedback_control_DWork.UnitDelay_DSTATE) +
              feedback_control_P.Constant2_Value;
          } else {
            rtb_Gain2_p = feedback_control_P.Constant3_Value_l;
          }

          /* End of ManualSwitch: '<S15>/Manual Switch' */
          rtb_ManualSwitch[0] = feedback_control_P.Period_Gain * rtb_Gain2_p;
          rtb_ManualSwitch[1] = (feedback_control_P.Constant1_Value_i -
            rtb_Gain2_p) * feedback_control_P.Period_Gain;
          rtb_ManualSwitch[2] = feedback_control_P.Period_Gain *
            feedback_control_P.Constant4_Value_f;
        } else {
          rtb_ManualSwitch[0] = feedback_control_P.Constant2_Value_a[0];
          rtb_ManualSwitch[1] = feedback_control_P.Constant2_Value_a[1];
          rtb_ManualSwitch[2] = feedback_control_P.Constant2_Value_a[2];
        }

        /* End of ManualSwitch: '<S17>/Manual Switch' */

        /* S-Function (c2802xpwm): '<S17>/PWM for the Halfbridge 1' incorporates:
         *  Constant: '<S17>/Constant1'
         */
        {
          EPwm1Regs.TBPRD = (uint16_T)(feedback_control_P.Constant1_Value_c);
        }

        /*-- Update CMPA value for ePWM1 --*/
        {
          EPwm1Regs.CMPA.bit.CMPA = (uint16_T)(rtb_ManualSwitch[0]);
        }

        /* S-Function (c2802xpwm): '<S17>/PWM for the Halfbridge 2' incorporates:
         *  Constant: '<S17>/Constant1'
         */
        {
          EPwm2Regs.TBPRD = (uint16_T)(feedback_control_P.Constant1_Value_c);
        }

        /*-- Update CMPA value for ePWM2 --*/
        {
          EPwm2Regs.CMPA.bit.CMPA = (uint16_T)(rtb_ManualSwitch[1]);
        }

        /* S-Function (c2802xpwm): '<S17>/PWM for the Halfbridge 3' incorporates:
         *  Constant: '<S17>/Constant1'
         */
        {
          EPwm3Regs.TBPRD = (uint16_T)(feedback_control_P.Constant1_Value_c);
        }

        /*-- Update CMPA value for ePWM3 --*/
        {
          EPwm3Regs.CMPA.bit.CMPA = (uint16_T)(rtb_ManualSwitch[2]);
        }

        /* MATLABSystem: '<S5>/DAC1' incorporates:
         *  Constant: '<S12>/Offset'
         *  Gain: '<S12>/Gain2'
         *  Sum: '<S12>/Add'
         */
        MW_C2000DAC(1U, (feedback_control_P.AdaptDAC1_Gain *
                         feedback_control_B.Gain1) -
                    feedback_control_P.AdaptDAC1_Offset);

        /* MATLABSystem: '<S5>/DAC' incorporates:
         *  Constant: '<S11>/Offset'
         *  Gain: '<S11>/Gain2'
         *  Sum: '<S11>/Add'
         */
        MW_C2000DAC(0U, (feedback_control_P.AdaptDAC_Gain *
                         feedback_control_B.I_Reference) +
                    feedback_control_P.AdaptDAC_Offset);

        /* S-Function (c280xgpio_do): '<S17>/Digital Output' */
        {
          if (feedback_control_B.TmpRTBAtThreePhaseConverterCont) {
            GpioDataRegs.GPDSET.bit.GPIO124 = 1U;
          } else {
            GpioDataRegs.GPDCLEAR.bit.GPIO124 = 1U;
          }
        }

        /* S-Function (c2802xadc): '<S19>/ADC1' */
        {
          /*  Internal Reference Voltage : Fixed scale 0 to 3.3 V range.  */
          /*  External Reference Voltage : Allowable ranges of VREFHI(ADCINA0) = 3.3 and VREFLO(tied to ground) = 0  */
          feedback_control_B.ADC1 = (AdcbResultRegs.ADCRESULT1);
        }

        /* S-Function (c2802xadc): '<S19>/ADC2' */
        {
          /*  Internal Reference Voltage : Fixed scale 0 to 3.3 V range.  */
          /*  External Reference Voltage : Allowable ranges of VREFHI(ADCINA0) = 3.3 and VREFLO(tied to ground) = 0  */
          feedback_control_B.ADC2 = (AdcaResultRegs.ADCRESULT2);
        }

        /* S-Function (c280xqep): '<S25>/eQEP' */
        {
          feedback_control_B.eQEP_o1 = EQep1Regs.QPOSCNT;/*eQEP Position Counter*/
          feedback_control_B.eQEP_o2 = EQep1Regs.QPOSILAT;
          /* The position-counter value is latched into this register on an IEL*/
        }

        /* If: '<S30>/If1' incorporates:
         *  Constant: '<S30>/ResetMode'
         */
        if (feedback_control_P.ResetMode_Value > 0) {
          /* Outputs for IfAction SubSystem: '<S30>/PositionNoReset' incorporates:
           *  ActionPort: '<S40>/Action Port'
           */
          /* Sum: '<S40>/Sum3' */
          rtb_Sum3 = feedback_control_B.eQEP_o1 - feedback_control_B.eQEP_o2;

          /* Sum: '<S40>/Sum7' incorporates:
           *  Constant: '<S45>/Constant'
           */
          rtb_Merge_c = rtb_Sum3 + feedback_control_P.Constant_Value_m;

          /* MinMax: '<S40>/MinMax' */
          if (rtb_Sum3 <= rtb_Merge_c) {
            rtb_Merge_c = rtb_Sum3;
          }

          /* End of MinMax: '<S40>/MinMax' */
          /* End of Outputs for SubSystem: '<S30>/PositionNoReset' */

          /* Update for IfAction SubSystem: '<S30>/PositionNoReset' incorporates:
           *  ActionPort: '<S40>/Action Port'
           */
          /* Update for If: '<S30>/If1' */
          feedback_control_DWork.PositionNoReset_SubsysRanBC = 4;

          /* End of Update for SubSystem: '<S30>/PositionNoReset' */
        } else {
          /* Outputs for IfAction SubSystem: '<S30>/PositionResetAtIndex' incorporates:
           *  ActionPort: '<S41>/Action Port'
           */
          /* SignalConversion generated from: '<S41>/Count' */
          rtb_Merge_c = feedback_control_B.eQEP_o1;

          /* End of Outputs for SubSystem: '<S30>/PositionResetAtIndex' */

          /* Update for IfAction SubSystem: '<S30>/PositionResetAtIndex' incorporates:
           *  ActionPort: '<S41>/Action Port'
           */
          /* Update for If: '<S30>/If1' */
          feedback_control_DWork.PositionResetAtIndex_SubsysRanB = 4;

          /* End of Update for SubSystem: '<S30>/PositionResetAtIndex' */
        }

        /* End of If: '<S30>/If1' */

        /* Switch: '<S32>/Switch' incorporates:
         *  Constant: '<S29>/ReplaceInport_Offset'
         *  Constant: '<S32>/Constant'
         *  Constant: '<S32>/Constant1'
         */
        if (feedback_control_P.Constant_Value_ei >
            feedback_control_P.Switch_Threshold_f) {
          rtb_Gain2_p = feedback_control_P.Constant1_Value;
        } else {
          rtb_Gain2_p = feedback_control_P.ReplaceInport_Offset_Value;
        }

        /* If: '<S33>/If' incorporates:
         *  Constant: '<S46>/Constant'
         *  DataTypeConversion: '<S43>/DTC'
         *  Product: '<S30>/Product'
         *  Switch: '<S32>/Switch'
         */
        if ((((real32_T)rtb_Merge_c) * feedback_control_P.Constant_Value_o) <=
            rtb_Gain2_p) {
          /* Update for IfAction SubSystem: '<S33>/If Action Subsystem' incorporates:
           *  ActionPort: '<S35>/Action Port'
           */
          /* Update for If: '<S33>/If' */
          feedback_control_DWork.IfActionSubsystem_SubsysRanBC = 4;

          /* End of Update for SubSystem: '<S33>/If Action Subsystem' */
        } else {
          /* Update for IfAction SubSystem: '<S33>/If Action Subsystem1' incorporates:
           *  ActionPort: '<S36>/Action Port'
           */
          /* Update for If: '<S33>/If' */
          feedback_control_DWork.IfActionSubsystem1_SubsysRanBC = 4;

          /* End of Update for SubSystem: '<S33>/If Action Subsystem1' */
        }

        /* End of If: '<S33>/If' */

        /* Update for UnitDelay: '<S16>/Unit Delay1' */
        feedback_control_DWork.UnitDelay1_DSTATE_h =
          feedback_control_B.Times_Interrupt;

        /* Update for UnitDelay: '<S13>/Unit Delay' */
        feedback_control_DWork.UnitDelay_DSTATE_g = rtb_Add_c;
        feedback_control_DWork.ThreePhaseConverterControl_Subs = 4;
      }

      /* End of Outputs for S-Function (c28xisr_c2000): '<Root>/C28x Hardware Interrupt' */
    }

    currentTime = (extmodeSimulationTime_T)
      feedback_control_M->Timing.clockTick0;
    extmodeEvent(2,currentTime);
  }
}

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to remember which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void feedback_control_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(feedback_control_M, 1));
}

/*
 *         This function updates active task flag for each subrate
 *         and rate transition flags for tasks that exchange data.
 *         The function assumes rate-monotonic multitasking scheduler.
 *         The function must be called at model base rate so that
 *         the generated code self-manages all its subrates and rate
 *         transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (feedback_control_M->Timing.TaskCounters.TID[1])++;
  if ((feedback_control_M->Timing.TaskCounters.TID[1]) > 4999) {/* Sample time: [0.5s, 0.0s] */
    feedback_control_M->Timing.TaskCounters.TID[1] = 0;
  }
}

/* Model step function for TID0 */
void feedback_control_step0(void)      /* Sample time: [0.0001s, 0.0s] */
{
  uint16_T rtb_Add_d;

  {                                    /* Sample time: [0.0001s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* Reset subsysRan breadcrumbs */
  srClearBC(feedback_control_DWork.Subsystem_SubsysRanBC);

  /* Outputs for Enabled SubSystem: '<S1>/Subsystem' incorporates:
   *  EnablePort: '<S7>/Enable'
   */
  /* RelationalOperator: '<S6>/FixPt Relational Operator' incorporates:
   *  Constant: '<S1>/Write//Read1'
   *  UnitDelay: '<S6>/Delay Input1'
   */
  if (feedback_control_P.WriteRead1_Value !=
      feedback_control_DWork.DelayInput1_DSTATE) {
    /* Sum: '<S7>/Add1' incorporates:
     *  Constant: '<S7>/Inc'
     *  UnitDelay: '<S7>/Unit Delay'
     */
    feedback_control_B.Add1 = feedback_control_P.Inc_Value +
      feedback_control_DWork.Ticks;

    /* Switch: '<S7>/Switch' incorporates:
     *  Constant: '<S1>/Write//Read'
     *  Constant: '<S7>/Constant'
     *  Constant: '<S7>/Constant1'
     */
    if (feedback_control_P.WriteRead_Value >
        feedback_control_P.Switch_Threshold_p) {
      rtb_Add_d = feedback_control_P.Constant_Value_e;
    } else {
      rtb_Add_d = feedback_control_P.Constant1_Value_iy;
    }

    /* Sum: '<S7>/Add' incorporates:
     *  Constant: '<S1>/Address'
     *  Gain: '<S7>/Gain'
     *  Switch: '<S7>/Switch'
     */
    rtb_Add_d = ((feedback_control_P.Gain_Gain_m *
                  feedback_control_P.Address_Value) + rtb_Add_d) +
      feedback_control_P.WriteRead1_Value;

    /* MATLABSystem: '<S7>/SPI Transmit' */
    MW_SPI_SetSlaveSelect(feedback_control_DWork.obj.MW_SPI_HANDLE, 0U, true);
    feedback_control_B.SPITransmit = MW_SPI_SetFormat
      (feedback_control_DWork.obj.MW_SPI_HANDLE, 16U, MW_SPI_MODE_0,
       MW_SPI_MOST_SIGNIFICANT_BIT_FIRST);
    if (feedback_control_B.SPITransmit == 0U) {
      /* MATLABSystem: '<S7>/SPI Transmit' */
      feedback_control_B.SPITransmit = MW_SPI_Write_16bits
        (feedback_control_DWork.obj.MW_SPI_HANDLE, &rtb_Add_d, 1UL, 0U);
    }

    /* End of MATLABSystem: '<S7>/SPI Transmit' */

    /* Update for UnitDelay: '<S7>/Unit Delay' */
    feedback_control_DWork.Ticks = feedback_control_B.Add1;
    srUpdateBC(feedback_control_DWork.Subsystem_SubsysRanBC);
  }

  /* End of RelationalOperator: '<S6>/FixPt Relational Operator' */
  /* End of Outputs for SubSystem: '<S1>/Subsystem' */
  /* Update for UnitDelay: '<S6>/Delay Input1' incorporates:
   *  Constant: '<S1>/Write//Read1'
   */
  feedback_control_DWork.DelayInput1_DSTATE =
    feedback_control_P.WriteRead1_Value;

  /* Update for RateTransition generated from: '<Root>/Three Phase Converter Control' incorporates:
   *  Constant: '<Root>/Enable'
   */
  feedback_control_DWork.TmpRTBAtThreePhaseConverterCont =
    feedback_control_P.Enable_Value;

  /* Update absolute time */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  feedback_control_M->Timing.taskTime0 =
    ((time_T)(++feedback_control_M->Timing.clockTick0)) *
    feedback_control_M->Timing.stepSize0;
  switch (feedback_control_M->Timing.rtmDbBufReadBuf3) {
   case 0:
    feedback_control_M->Timing.rtmDbBufWriteBuf3 = 1;
    break;

   case 1:
    feedback_control_M->Timing.rtmDbBufWriteBuf3 = 0;
    break;

   default:
    feedback_control_M->Timing.rtmDbBufWriteBuf3 =
      !feedback_control_M->Timing.rtmDbBufLastBufWr3;
    break;
  }

  feedback_control_M->Timing.rtmDbBufClockTick3
    [feedback_control_M->Timing.rtmDbBufWriteBuf3] =
    feedback_control_M->Timing.clockTick0;
  feedback_control_M->Timing.rtmDbBufLastBufWr3 =
    feedback_control_M->Timing.rtmDbBufWriteBuf3;
  feedback_control_M->Timing.rtmDbBufWriteBuf3 = 0xFF;

  {
    /* Base rate updates double buffers of absolute time for
       asynchronous task. Double buffers are used to ensure
       data integrity when asynchronous task reads absolute
       time.
       -- rtmL2HLastBufWr is the buffer index that is written last.
     */
    boolean_T bufIdx = !(feedback_control_M->Timing.rtmL2HLastBufWr != 0U);
    feedback_control_M->Timing.rtmL2HDbBufClockTick[bufIdx] =
      feedback_control_M->Timing.clockTick0;
    feedback_control_M->Timing.rtmL2HLastBufWr = bufIdx ? 1U : 0U;
  }
}

/* Model step function for TID1 */
void feedback_control_step1(void)      /* Sample time: [0.5s, 0.0s] */
{
  /* S-Function (c280xgpio_do): '<S3>/Digital Output1' incorporates:
   *  Constant: '<S3>/Constant'
   */
  {
    GpioDataRegs.GPATOGGLE.bit.GPIO31 = (uint16_T)
      (feedback_control_P.Constant_Value_d != 0);
  }

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.5, which is the step size
   * of the task. Size of "clockTick1" ensures timer will not overflow during the
   * application lifespan selected.
   */
  feedback_control_M->Timing.clockTick1++;
}

/* Model initialize function */
void feedback_control_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)feedback_control_M, 0,
                sizeof(RT_MODEL_feedback_control));
  rtmSetTFinal(feedback_control_M, -1);
  feedback_control_M->Timing.stepSize0 = 0.0001;

  /* External mode info */
  feedback_control_M->Sizes.checksums[0] = (3103752828U);
  feedback_control_M->Sizes.checksums[1] = (233994000U);
  feedback_control_M->Sizes.checksums[2] = (3093894009U);
  feedback_control_M->Sizes.checksums[3] = (3368452328U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[24];
    feedback_control_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = (sysRanDType *)&feedback_control_DWork.Subsystem_SubsysRanBC;
    systemRan[2] = (sysRanDType *)&feedback_control_DWork.Subsystem_SubsysRanBC;
    systemRan[3] = (sysRanDType *)&feedback_control_DWork.Subsystem_SubsysRanBC;
    systemRan[4] = (sysRanDType *)&feedback_control_DWork.Subsystem_SubsysRanBC;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    systemRan[7] = &rtAlwaysEnabled;
    systemRan[8] = (sysRanDType *)
      &feedback_control_DWork.ThreePhaseConverterControl_Subs;
    systemRan[9] = (sysRanDType *)
      &feedback_control_DWork.ThreePhaseConverterControl_Subs;
    systemRan[10] = (sysRanDType *)
      &feedback_control_DWork.ThreePhaseConverterControl_Subs;
    systemRan[11] = (sysRanDType *)
      &feedback_control_DWork.IfActionSubsystem_SubsysRanBC;
    systemRan[12] = (sysRanDType *)
      &feedback_control_DWork.IfActionSubsystem1_SubsysRanBC;
    systemRan[13] = (sysRanDType *)
      &feedback_control_DWork.ThreePhaseConverterControl_Subs;
    systemRan[14] = (sysRanDType *)
      &feedback_control_DWork.ThreePhaseConverterControl_Subs;
    systemRan[15] = (sysRanDType *)
      &feedback_control_DWork.PositionNoReset_SubsysRanBC;
    systemRan[16] = (sysRanDType *)
      &feedback_control_DWork.PositionResetAtIndex_SubsysRanB;
    systemRan[17] = (sysRanDType *)
      &feedback_control_DWork.ThreePhaseConverterControl_Subs;
    systemRan[18] = (sysRanDType *)
      &feedback_control_DWork.ThreePhaseConverterControl_Subs;
    systemRan[19] = (sysRanDType *)
      &feedback_control_DWork.ThreePhaseConverterControl_Subs;
    systemRan[20] = (sysRanDType *)
      &feedback_control_DWork.ThreePhaseConverterControl_Subs;
    systemRan[21] = (sysRanDType *)
      &feedback_control_DWork.ThreePhaseConverterControl_Subs;
    systemRan[22] = (sysRanDType *)
      &feedback_control_DWork.ThreePhaseConverterControl_Subs;
    systemRan[23] = (sysRanDType *)
      &feedback_control_DWork.ThreePhaseConverterControl_Subs;
    rteiSetModelMappingInfoPtr(feedback_control_M->extModeInfo,
      &feedback_control_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(feedback_control_M->extModeInfo,
                        feedback_control_M->Sizes.checksums);
    rteiSetTPtr(feedback_control_M->extModeInfo, rtmGetTPtr(feedback_control_M));
  }

  /* block I/O */
  (void) memset(((void *) &feedback_control_B), 0,
                sizeof(BlockIO_feedback_control));

  /* states (dwork) */
  (void) memset((void *)&feedback_control_DWork, 0,
                sizeof(D_Work_feedback_control));

  /* external inputs */
  (void)memset(&feedback_control_U, 0, sizeof(ExternalInputs_feedback_control));

  {
    uint32_T SPIPinsLoc;
    uint16_T status;
    feedback_control_M->Timing.rtmDbBufReadBuf3 = 0xFF;
    feedback_control_M->Timing.rtmDbBufWriteBuf3 = 0xFF;
    feedback_control_M->Timing.rtmDbBufLastBufWr3 = 0;

    /* Start for S-Function (c280xgpio_do): '<S3>/Digital Output1' */
    EALLOW;
    GpioCtrlRegs.GPAMUX2.all &= 0x3FFFFFFFU;
    GpioCtrlRegs.GPADIR.all |= 0x80000000U;
    EDIS;

    /* InitializeConditions for UnitDelay: '<S6>/Delay Input1' */
    feedback_control_DWork.DelayInput1_DSTATE =
      feedback_control_P.DetectChange_vinit;

    /* InitializeConditions for RateTransition generated from: '<Root>/Three Phase Converter Control' */
    feedback_control_DWork.TmpRTBAtThreePhaseConverterCont =
      feedback_control_P.TmpRTBAtThreePhaseConverterCont;

    /* SystemInitialize for Enabled SubSystem: '<S1>/Subsystem' */
    /* InitializeConditions for UnitDelay: '<S7>/Unit Delay' */
    feedback_control_DWork.Ticks =
      feedback_control_P.UnitDelay_InitialCondition_l;

    /* Start for MATLABSystem: '<S7>/SPI Transmit' */
    feedback_control_DWork.obj.matlabCodegenIsDeleted = false;
    feedback_control_DWork.obj.isInitialized = 1L;
    SPIPinsLoc = MW_UNDEFINED_VALUE;
    feedback_control_DWork.obj.MW_SPI_HANDLE = MW_SPI_Open(0UL, SPIPinsLoc,
      SPIPinsLoc, SPIPinsLoc, MW_UNDEFINED_VALUE, true, 0U);
    MW_SPI_SetFormat(feedback_control_DWork.obj.MW_SPI_HANDLE, 16U,
                     MW_SPI_MODE_0, MW_SPI_MOST_SIGNIFICANT_BIT_FIRST);
    feedback_control_DWork.obj.isSetupComplete = true;

    /* SystemInitialize for Sum: '<S7>/Add1' incorporates:
     *  Outport: '<S7>/Ticks'
     */
    feedback_control_B.Add1 = feedback_control_P.Ticks_Y0;

    /* SystemInitialize for MATLABSystem: '<S7>/SPI Transmit' incorporates:
     *  Outport: '<S7>/Status'
     */
    feedback_control_B.SPITransmit = feedback_control_P.Status_Y0;

    /* End of SystemInitialize for SubSystem: '<S1>/Subsystem' */

    /* SystemInitialize for S-Function (c28xisr_c2000): '<Root>/C28x Hardware Interrupt' incorporates:
     *  SubSystem: '<Root>/Three Phase Converter Control'
     */
    /* System initialize for function-call system: '<Root>/Three Phase Converter Control' */

    /* Asynchronous task reads absolute time. Data (absolute time)
       transfers from low priority task (base rate) to high priority
       task (asynchronous rate). Double buffers are used to ensure
       data integrity.
       -- rtmL2HLastBufWr is the buffer index that is written last.
     */
    feedback_control_M->Timing.clockTick2 =
      feedback_control_M->Timing.rtmL2HDbBufClockTick
      [feedback_control_M->Timing.rtmL2HLastBufWr];

    /* Start for S-Function (c2802xadc): '<S19>/ADC' */
    if (MW_adcCInitFlag == 0U) {
      InitAdcC();
      MW_adcCInitFlag = 1U;
    }

    config_ADCC_SOC0 ();

    /* Start for S-Function (c2802xadc): '<S19>/ADC3' */
    if (MW_adcAInitFlag == 0U) {
      InitAdcA();
      MW_adcAInitFlag = 1U;
    }

    config_ADCA_SOC3 ();

    /* Start for S-Function (c2802xpwm): '<S17>/PWM for the Halfbridge 1' incorporates:
     *  Constant: '<S17>/Constant1'
     */

    /*** Initialize ePWM1 modules ***/
    {
      /*  // Time Base Control Register
         EPwm1Regs.TBCTL.bit.CTRMODE              = 2U;          // Counter Mode
         EPwm1Regs.TBCTL.bit.SYNCOSEL             = 1U;          // Sync Output Select

         EPwm1Regs.TBCTL.bit.PRDLD                = 0U;          // Shadow select

         EPwm1Regs.TBCTL2.bit.PRDLDSYNC           = 0U;          // Shadow select

         EPwm1Regs.TBCTL.bit.PHSEN                = 0U;          // Phase Load Enable
         EPwm1Regs.TBCTL.bit.PHSDIR               = 0U;          // Phase Direction Bit
         EPwm1Regs.TBCTL.bit.HSPCLKDIV            = 0U;          // High Speed TBCLK Pre-scaler
         EPwm1Regs.TBCTL.bit.CLKDIV               = 0U;          // Time Base Clock Pre-scaler
       */
      EPwm1Regs.TBCTL.all = (EPwm1Regs.TBCTL.all & ~0x3FFFU) | 0x12U;
      EPwm1Regs.TBCTL2.all = (EPwm1Regs.TBCTL2.all & ~0xC000U) | 0x0U;

      /*-- Setup Time-Base (TB) Submodule --*/
      EPwm1Regs.TBPRD = 1000U;         // Time Base Period Register

      /* // Time-Base Phase Register
         EPwm1Regs.TBPHS.bit.TBPHS               = 0U;          // Phase offset register
       */
      EPwm1Regs.TBPHS.all = (EPwm1Regs.TBPHS.all & ~0xFFFF0000U) | 0x0U;

      // Time Base Counter Register
      EPwm1Regs.TBCTR = 0x0000U;       /* Clear counter*/

      /*-- Setup Counter_Compare (CC) Submodule --*/
      /*	// Counter Compare Control Register

         EPwm1Regs.CMPCTL.bit.LOADASYNC           = 0U;          // Active Compare A Load SYNC Option
         EPwm1Regs.CMPCTL.bit.LOADBSYNC           = 0U;          // Active Compare B Load SYNC Option
         EPwm1Regs.CMPCTL.bit.LOADAMODE           = 2U;          // Active Compare A Load
         EPwm1Regs.CMPCTL.bit.LOADBMODE           = 0U;          // Active Compare B Load
         EPwm1Regs.CMPCTL.bit.SHDWAMODE           = 0U;          // Compare A Register Block Operating Mode
         EPwm1Regs.CMPCTL.bit.SHDWBMODE           = 0U;          // Compare B Register Block Operating Mode
       */
      EPwm1Regs.CMPCTL.all = (EPwm1Regs.CMPCTL.all & ~0x3C5FU) | 0x2U;

      /* EPwm1Regs.CMPCTL2.bit.SHDWCMODE           = 0U;          // Compare C Register Block Operating Mode
         EPwm1Regs.CMPCTL2.bit.SHDWDMODE           = 0U;          // Compare D Register Block Operating Mode
         EPwm1Regs.CMPCTL2.bit.LOADCSYNC           = 0U;          // Active Compare C Load SYNC Option
         EPwm1Regs.CMPCTL2.bit.LOADDSYNC           = 0U;          // Active Compare D Load SYNC Option
         EPwm1Regs.CMPCTL2.bit.LOADCMODE           = 0U;          // Active Compare C Load
         EPwm1Regs.CMPCTL2.bit.LOADDMODE           = 0U;          // Active Compare D Load
       */
      EPwm1Regs.CMPCTL2.all = (EPwm1Regs.CMPCTL2.all & ~0x3C5FU) | 0x0U;
      EPwm1Regs.CMPA.bit.CMPA = 1000U; // Counter Compare A Register
      EPwm1Regs.CMPB.bit.CMPB = 32000U;// Counter Compare B Register
      EPwm1Regs.CMPC = 32000U;         // Counter Compare C Register
      EPwm1Regs.CMPD = 32000U;         // Counter Compare D Register

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
         EPwm1Regs.DBCTL.bit.OUT_MODE             = 3U;          // Dead Band Output Mode Control
         EPwm1Regs.DBCTL.bit.IN_MODE              = 0U;          // Dead Band Input Select Mode Control
         EPwm1Regs.DBCTL.bit.POLSEL               = 2U;          // Polarity Select Control
         EPwm1Regs.DBCTL.bit.HALFCYCLE            = 0U;          // Half Cycle Clocking Enable
         EPwm1Regs.DBCTL.bit.SHDWDBREDMODE        = 0U;          // DBRED shadow mode
         EPwm1Regs.DBCTL.bit.SHDWDBFEDMODE        = 0U;          // DBFED shadow mode
         EPwm1Regs.DBCTL.bit.LOADREDMODE          = 4U;        // DBRED load
         EPwm1Regs.DBCTL.bit.LOADFEDMODE          = 4U;        // DBFED load
       */
      EPwm1Regs.DBCTL.all = (EPwm1Regs.DBCTL.all & ~0x8FFFU) | 0xBU;
      EPwm1Regs.DBRED.bit.DBRED = (uint16_T)(20.0);
                         // Dead-Band Generator Rising Edge Delay Count Register
      EPwm1Regs.DBFED.bit.DBFED = (uint16_T)(20.0);
                        // Dead-Band Generator Falling Edge Delay Count Register

      /*-- Setup Event-Trigger (ET) Submodule --*/
      /*	// Event Trigger Selection and Pre-Scale Register
         EPwm1Regs.ETSEL.bit.SOCAEN               = 1U;          // Start of Conversion A Enable
         EPwm1Regs.ETSEL.bit.SOCASELCMP           = 0U;
         EPwm1Regs.ETSEL.bit.SOCASEL              = 2U;          // Start of Conversion A Select
         EPwm1Regs.ETPS.bit.SOCPSSEL              = 1U;          // EPWM1SOC Period Select
         EPwm1Regs.ETSOCPS.bit.SOCAPRD2           = 1U;
         EPwm1Regs.ETSEL.bit.SOCBEN               = 0U;          // Start of Conversion B Enable
         EPwm1Regs.ETSEL.bit.SOCBSELCMP           = 0U;
         EPwm1Regs.ETSEL.bit.SOCBSEL              = 1U;          // Start of Conversion A Select
         EPwm1Regs.ETPS.bit.SOCPSSEL              = 1;          // EPWM1SOCB Period Select
         EPwm1Regs.ETSOCPS.bit.SOCBPRD2           = 1U;
         EPwm1Regs.ETSEL.bit.INTEN                = 0U;          // EPWM1INTn Enable
         EPwm1Regs.ETSEL.bit.INTSELCMP            = 0U;
         EPwm1Regs.ETSEL.bit.INTSEL               = 1U;          // Start of Conversion A Select
         EPwm1Regs.ETPS.bit.INTPSSEL              = 1U;          // EPWM1INTn Period Select
         EPwm1Regs.ETINTPS.bit.INTPRD2            = 1U;
       */
      EPwm1Regs.ETSEL.all = (EPwm1Regs.ETSEL.all & ~0xFF7FU) | 0x1A01U;
      EPwm1Regs.ETPS.all = (EPwm1Regs.ETPS.all & ~0x30U) | 0x30U;
      EPwm1Regs.ETSOCPS.all = (EPwm1Regs.ETSOCPS.all & ~0xF0FU) | 0x101U;
      EPwm1Regs.ETINTPS.all = (EPwm1Regs.ETINTPS.all & ~0xFU) | 0x1U;

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
      EPwm1Regs.TZSEL.all = 0U;        // Trip Zone Select Register

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
         EPwm1Regs.DCACTL.bit.EVT1SOCE            = 1U;          // DCAEVT1 SOC Enable
         EPwm1Regs.DCACTL.bit.EVT1FRCSYNCSEL      = 0U;          // DCAEVT1 Force Sync Signal
         EPwm1Regs.DCACTL.bit.EVT1SRCSEL          = 0U;          // DCAEVT1 Source Signal
         EPwm1Regs.DCACTL.bit.EVT2FRCSYNCSEL      = 0U;          // DCAEVT2 Force Sync Signal
         EPwm1Regs.DCACTL.bit.EVT2SRCSEL          = 0U;          // DCAEVT2 Source Signal
       */
      EPwm1Regs.DCACTL.all = (EPwm1Regs.DCACTL.all & ~0x30FU) | 0x4U;

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
      EPwm1Regs.DCFOFFSET = 0U;        // Digital Compare Filter Offset Register
      EPwm1Regs.DCFWINDOW = 0U;        // Digital Compare Filter Window Register

      /*	// Digital Compare Capture Control Register
         EPwm1Regs.DCCAPCTL.bit.CAPE              = 0U;          // Counter Capture Enable
       */
      EPwm1Regs.DCCAPCTL.all = (EPwm1Regs.DCCAPCTL.all & ~0x1U) | 0x0U;

      /*	// HRPWM Configuration Register
         EPwm1Regs.HRCNFG.bit.SWAPAB              = 0U;          // Swap EPWMA and EPWMB Outputs Bit
         EPwm1Regs.HRCNFG.bit.SELOUTB             = 0U;          // EPWMB Output Selection Bit
       */
      EPwm1Regs.HRCNFG.all = (EPwm1Regs.HRCNFG.all & ~0xA0U) | 0x0U;

      /* Update the Link Registers with the link value for all the Compare values and TBPRD */
      /* No error is thrown if the ePWM register exists in the model or not */
      EPwm1Regs.EPWMXLINK.bit.TBPRDLINK = 0U;
      EPwm1Regs.EPWMXLINK.bit.CMPALINK = 0U;
      EPwm1Regs.EPWMXLINK.bit.CMPBLINK = 0U;
      EPwm1Regs.EPWMXLINK.bit.CMPCLINK = 0U;
      EPwm1Regs.EPWMXLINK.bit.CMPDLINK = 0U;

      /* SYNCPER - Peripheral synchronization output event
         EPwm1Regs.HRPCTL.bit.PWMSYNCSEL            = 0U;          // EPWMSYNCPER selection
         EPwm1Regs.HRPCTL.bit.PWMSYNCSELX           = 0U;          //  EPWMSYNCPER selection
       */
      EPwm1Regs.HRPCTL.all = (EPwm1Regs.HRPCTL.all & ~0x72U) | 0x0U;
      EDIS;
    }

    /* Start for S-Function (c2802xpwm): '<S17>/PWM for the Halfbridge 2' incorporates:
     *  Constant: '<S17>/Constant1'
     */

    /*** Initialize ePWM2 modules ***/
    {
      /*  // Time Base Control Register
         EPwm2Regs.TBCTL.bit.CTRMODE              = 2U;          // Counter Mode
         EPwm2Regs.TBCTL.bit.SYNCOSEL             = 0U;          // Sync Output Select

         EPwm2Regs.TBCTL.bit.PRDLD                = 0U;          // Shadow select

         EPwm2Regs.TBCTL2.bit.PRDLDSYNC           = 0U;          // Shadow select

         EPwm2Regs.TBCTL.bit.PHSEN                = 1U;          // Phase Load Enable
         EPwm2Regs.TBCTL.bit.PHSDIR               = 1U;          // Phase Direction Bit
         EPwm2Regs.TBCTL.bit.HSPCLKDIV            = 0U;          // High Speed TBCLK Pre-scaler
         EPwm2Regs.TBCTL.bit.CLKDIV               = 0U;          // Time Base Clock Pre-scaler
       */
      EPwm2Regs.TBCTL.all = (EPwm2Regs.TBCTL.all & ~0x3FFFU) | 0x2006U;
      EPwm2Regs.TBCTL2.all = (EPwm2Regs.TBCTL2.all & ~0xC000U) | 0x0U;

      /*-- Setup Time-Base (TB) Submodule --*/
      EPwm2Regs.TBPRD = 1000U;         // Time Base Period Register

      /* // Time-Base Phase Register
         EPwm2Regs.TBPHS.bit.TBPHS               = 0U;          // Phase offset register
       */
      EPwm2Regs.TBPHS.all = (EPwm2Regs.TBPHS.all & ~0xFFFF0000U) | 0x0U;

      // Time Base Counter Register
      EPwm2Regs.TBCTR = 0x0000U;       /* Clear counter*/

      /*-- Setup Counter_Compare (CC) Submodule --*/
      /*	// Counter Compare Control Register

         EPwm2Regs.CMPCTL.bit.LOADASYNC           = 0U;          // Active Compare A Load SYNC Option
         EPwm2Regs.CMPCTL.bit.LOADBSYNC           = 0U;          // Active Compare B Load SYNC Option
         EPwm2Regs.CMPCTL.bit.LOADAMODE           = 2U;          // Active Compare A Load
         EPwm2Regs.CMPCTL.bit.LOADBMODE           = 0U;          // Active Compare B Load
         EPwm2Regs.CMPCTL.bit.SHDWAMODE           = 0U;          // Compare A Register Block Operating Mode
         EPwm2Regs.CMPCTL.bit.SHDWBMODE           = 0U;          // Compare B Register Block Operating Mode
       */
      EPwm2Regs.CMPCTL.all = (EPwm2Regs.CMPCTL.all & ~0x3C5FU) | 0x2U;

      /* EPwm2Regs.CMPCTL2.bit.SHDWCMODE           = 0U;          // Compare C Register Block Operating Mode
         EPwm2Regs.CMPCTL2.bit.SHDWDMODE           = 0U;          // Compare D Register Block Operating Mode
         EPwm2Regs.CMPCTL2.bit.LOADCSYNC           = 0U;          // Active Compare C Load SYNC Option
         EPwm2Regs.CMPCTL2.bit.LOADDSYNC           = 0U;          // Active Compare D Load SYNC Option
         EPwm2Regs.CMPCTL2.bit.LOADCMODE           = 0U;          // Active Compare C Load
         EPwm2Regs.CMPCTL2.bit.LOADDMODE           = 0U;          // Active Compare D Load
       */
      EPwm2Regs.CMPCTL2.all = (EPwm2Regs.CMPCTL2.all & ~0x3C5FU) | 0x0U;
      EPwm2Regs.CMPA.bit.CMPA = 1000U; // Counter Compare A Register
      EPwm2Regs.CMPB.bit.CMPB = 32000U;// Counter Compare B Register
      EPwm2Regs.CMPC = 32000U;         // Counter Compare C Register
      EPwm2Regs.CMPD = 32000U;         // Counter Compare D Register

      /*-- Setup Action-Qualifier (AQ) Submodule --*/
      EPwm2Regs.AQCTLA.all = 150U;
                               // Action Qualifier Control Register For Output A
      EPwm2Regs.AQCTLB.all = 2310U;
                               // Action Qualifier Control Register For Output B

      /*	// Action Qualifier Software Force Register
         EPwm2Regs.AQSFRC.bit.RLDCSF              = 0U;          // Reload from Shadow Options
       */
      EPwm2Regs.AQSFRC.all = (EPwm2Regs.AQSFRC.all & ~0xC0U) | 0x0U;

      /*	// Action Qualifier Continuous S/W Force Register
         EPwm2Regs.AQCSFRC.bit.CSFA               = 0U;          // Continuous Software Force on output A
         EPwm2Regs.AQCSFRC.bit.CSFB               = 0U;          // Continuous Software Force on output B
       */
      EPwm2Regs.AQCSFRC.all = (EPwm2Regs.AQCSFRC.all & ~0xFU) | 0x0U;

      /*-- Setup Dead-Band Generator (DB) Submodule --*/
      /*	// Dead-Band Generator Control Register
         EPwm2Regs.DBCTL.bit.OUT_MODE             = 3U;          // Dead Band Output Mode Control
         EPwm2Regs.DBCTL.bit.IN_MODE              = 0U;          // Dead Band Input Select Mode Control
         EPwm2Regs.DBCTL.bit.POLSEL               = 2U;          // Polarity Select Control
         EPwm2Regs.DBCTL.bit.HALFCYCLE            = 0U;          // Half Cycle Clocking Enable
         EPwm2Regs.DBCTL.bit.SHDWDBREDMODE        = 0U;          // DBRED shadow mode
         EPwm2Regs.DBCTL.bit.SHDWDBFEDMODE        = 0U;          // DBFED shadow mode
         EPwm2Regs.DBCTL.bit.LOADREDMODE          = 4U;        // DBRED load
         EPwm2Regs.DBCTL.bit.LOADFEDMODE          = 4U;        // DBFED load
       */
      EPwm2Regs.DBCTL.all = (EPwm2Regs.DBCTL.all & ~0x8FFFU) | 0xBU;
      EPwm2Regs.DBRED.bit.DBRED = (uint16_T)(20.0);
                         // Dead-Band Generator Rising Edge Delay Count Register
      EPwm2Regs.DBFED.bit.DBFED = (uint16_T)(20.0);
                        // Dead-Band Generator Falling Edge Delay Count Register

      /*-- Setup Event-Trigger (ET) Submodule --*/
      /*	// Event Trigger Selection and Pre-Scale Register
         EPwm2Regs.ETSEL.bit.SOCAEN               = 0U;          // Start of Conversion A Enable
         EPwm2Regs.ETSEL.bit.SOCASELCMP           = 0U;
         EPwm2Regs.ETSEL.bit.SOCASEL              = 1U;          // Start of Conversion A Select
         EPwm2Regs.ETPS.bit.SOCPSSEL              = 1U;          // EPWM2SOC Period Select
         EPwm2Regs.ETSOCPS.bit.SOCAPRD2           = 1U;
         EPwm2Regs.ETSEL.bit.SOCBEN               = 0U;          // Start of Conversion B Enable
         EPwm2Regs.ETSEL.bit.SOCBSELCMP           = 0U;
         EPwm2Regs.ETSEL.bit.SOCBSEL              = 1U;          // Start of Conversion A Select
         EPwm2Regs.ETPS.bit.SOCPSSEL              = 1;          // EPWM2SOCB Period Select
         EPwm2Regs.ETSOCPS.bit.SOCBPRD2           = 1U;
         EPwm2Regs.ETSEL.bit.INTEN                = 0U;          // EPWM2INTn Enable
         EPwm2Regs.ETSEL.bit.INTSELCMP            = 0U;
         EPwm2Regs.ETSEL.bit.INTSEL               = 1U;          // Start of Conversion A Select
         EPwm2Regs.ETPS.bit.INTPSSEL              = 1U;          // EPWM2INTn Period Select
         EPwm2Regs.ETINTPS.bit.INTPRD2            = 1U;
       */
      EPwm2Regs.ETSEL.all = (EPwm2Regs.ETSEL.all & ~0xFF7FU) | 0x1101U;
      EPwm2Regs.ETPS.all = (EPwm2Regs.ETPS.all & ~0x30U) | 0x30U;
      EPwm2Regs.ETSOCPS.all = (EPwm2Regs.ETSOCPS.all & ~0xF0FU) | 0x101U;
      EPwm2Regs.ETINTPS.all = (EPwm2Regs.ETINTPS.all & ~0xFU) | 0x1U;

      /*-- Setup PWM-Chopper (PC) Submodule --*/
      /*	// PWM Chopper Control Register
         EPwm2Regs.PCCTL.bit.CHPEN                = 0U;          // PWM chopping enable
         EPwm2Regs.PCCTL.bit.CHPFREQ              = 0U;          // Chopping clock frequency
         EPwm2Regs.PCCTL.bit.OSHTWTH              = 0U;          // One-shot pulse width
         EPwm2Regs.PCCTL.bit.CHPDUTY              = 0U;          // Chopping clock Duty cycle
       */
      EPwm2Regs.PCCTL.all = (EPwm2Regs.PCCTL.all & ~0x7FFU) | 0x0U;

      /*-- Set up Trip-Zone (TZ) Submodule --*/
      EALLOW;
      EPwm2Regs.TZSEL.all = 0U;        // Trip Zone Select Register

      /*	// Trip Zone Control Register
         EPwm2Regs.TZCTL.bit.TZA                  = 3U;          // TZ1 to TZ6 Trip Action On EPWM2A
         EPwm2Regs.TZCTL.bit.TZB                  = 3U;          // TZ1 to TZ6 Trip Action On EPWM2B
         EPwm2Regs.TZCTL.bit.DCAEVT1              = 3U;          // EPWM2A action on DCAEVT1
         EPwm2Regs.TZCTL.bit.DCAEVT2              = 3U;          // EPWM2A action on DCAEVT2
         EPwm2Regs.TZCTL.bit.DCBEVT1              = 3U;          // EPWM2B action on DCBEVT1
         EPwm2Regs.TZCTL.bit.DCBEVT2              = 3U;          // EPWM2B action on DCBEVT2
       */
      EPwm2Regs.TZCTL.all = (EPwm2Regs.TZCTL.all & ~0xFFFU) | 0xFFFU;

      /*	// Trip Zone Enable Interrupt Register
         EPwm2Regs.TZEINT.bit.OST                 = 0U;          // Trip Zones One Shot Int Enable
         EPwm2Regs.TZEINT.bit.CBC                 = 0U;          // Trip Zones Cycle By Cycle Int Enable
         EPwm2Regs.TZEINT.bit.DCAEVT1             = 0U;          // Digital Compare A Event 1 Int Enable
         EPwm2Regs.TZEINT.bit.DCAEVT2             = 0U;          // Digital Compare A Event 2 Int Enable
         EPwm2Regs.TZEINT.bit.DCBEVT1             = 0U;          // Digital Compare B Event 1 Int Enable
         EPwm2Regs.TZEINT.bit.DCBEVT2             = 0U;          // Digital Compare B Event 2 Int Enable
       */
      EPwm2Regs.TZEINT.all = (EPwm2Regs.TZEINT.all & ~0x7EU) | 0x0U;

      /*	// Digital Compare A Control Register
         EPwm2Regs.DCACTL.bit.EVT1SYNCE           = 0U;          // DCAEVT1 SYNC Enable
         EPwm2Regs.DCACTL.bit.EVT1SOCE            = 1U;          // DCAEVT1 SOC Enable
         EPwm2Regs.DCACTL.bit.EVT1FRCSYNCSEL      = 0U;          // DCAEVT1 Force Sync Signal
         EPwm2Regs.DCACTL.bit.EVT1SRCSEL          = 0U;          // DCAEVT1 Source Signal
         EPwm2Regs.DCACTL.bit.EVT2FRCSYNCSEL      = 0U;          // DCAEVT2 Force Sync Signal
         EPwm2Regs.DCACTL.bit.EVT2SRCSEL          = 0U;          // DCAEVT2 Source Signal
       */
      EPwm2Regs.DCACTL.all = (EPwm2Regs.DCACTL.all & ~0x30FU) | 0x4U;

      /*	// Digital Compare B Control Register
         EPwm2Regs.DCBCTL.bit.EVT1SYNCE           = 0U;          // DCBEVT1 SYNC Enable
         EPwm2Regs.DCBCTL.bit.EVT1SOCE            = 0U;          // DCBEVT1 SOC Enable
         EPwm2Regs.DCBCTL.bit.EVT1FRCSYNCSEL      = 0U;          // DCBEVT1 Force Sync Signal
         EPwm2Regs.DCBCTL.bit.EVT1SRCSEL          = 0U;          // DCBEVT1 Source Signal
         EPwm2Regs.DCBCTL.bit.EVT2FRCSYNCSEL      = 0U;          // DCBEVT2 Force Sync Signal
         EPwm2Regs.DCBCTL.bit.EVT2SRCSEL          = 0U;          // DCBEVT2 Source Signal
       */
      EPwm2Regs.DCBCTL.all = (EPwm2Regs.DCBCTL.all & ~0x30FU) | 0x0U;

      /*	// Digital Compare Trip Select Register
         EPwm2Regs.DCTRIPSEL.bit.DCAHCOMPSEL      = 0U;          // Digital Compare A High COMP Input Select

         EPwm2Regs.DCTRIPSEL.bit.DCALCOMPSEL      = 0U;          // Digital Compare A Low COMP Input Select
         EPwm2Regs.DCTRIPSEL.bit.DCBHCOMPSEL      = 0U;          // Digital Compare B High COMP Input Select
         EPwm2Regs.DCTRIPSEL.bit.DCBLCOMPSEL      = 0U;          // Digital Compare B Low COMP Input Select
       */
      EPwm2Regs.DCTRIPSEL.all = (EPwm2Regs.DCTRIPSEL.all & ~ 0xFFFFU) | 0x0U;

      /*	// Trip Zone Digital Comparator Select Register
         EPwm2Regs.TZDCSEL.bit.DCAEVT1            = 0U;          // Digital Compare Output A Event 1
         EPwm2Regs.TZDCSEL.bit.DCAEVT2            = 0U;          // Digital Compare Output A Event 2
         EPwm2Regs.TZDCSEL.bit.DCBEVT1            = 0U;          // Digital Compare Output B Event 1
         EPwm2Regs.TZDCSEL.bit.DCBEVT2            = 0U;          // Digital Compare Output B Event 2
       */
      EPwm2Regs.TZDCSEL.all = (EPwm2Regs.TZDCSEL.all & ~0xFFFU) | 0x0U;

      /*	// Digital Compare Filter Control Register
         EPwm2Regs.DCFCTL.bit.BLANKE              = 0U;          // Blanking Enable/Disable
         EPwm2Regs.DCFCTL.bit.PULSESEL            = 1U;          // Pulse Select for Blanking & Capture Alignment
         EPwm2Regs.DCFCTL.bit.BLANKINV            = 0U;          // Blanking Window Inversion
         EPwm2Regs.DCFCTL.bit.SRCSEL              = 0U;          // Filter Block Signal Source Select
       */
      EPwm2Regs.DCFCTL.all = (EPwm2Regs.DCFCTL.all & ~0x3FU) | 0x10U;
      EPwm2Regs.DCFOFFSET = 0U;        // Digital Compare Filter Offset Register
      EPwm2Regs.DCFWINDOW = 0U;        // Digital Compare Filter Window Register

      /*	// Digital Compare Capture Control Register
         EPwm2Regs.DCCAPCTL.bit.CAPE              = 0U;          // Counter Capture Enable
       */
      EPwm2Regs.DCCAPCTL.all = (EPwm2Regs.DCCAPCTL.all & ~0x1U) | 0x0U;

      /*	// HRPWM Configuration Register
         EPwm2Regs.HRCNFG.bit.SWAPAB              = 0U;          // Swap EPWMA and EPWMB Outputs Bit
         EPwm2Regs.HRCNFG.bit.SELOUTB             = 0U;          // EPWMB Output Selection Bit
       */
      EPwm2Regs.HRCNFG.all = (EPwm2Regs.HRCNFG.all & ~0xA0U) | 0x0U;

      /* Update the Link Registers with the link value for all the Compare values and TBPRD */
      /* No error is thrown if the ePWM register exists in the model or not */
      EPwm2Regs.EPWMXLINK.bit.TBPRDLINK = 1U;
      EPwm2Regs.EPWMXLINK.bit.CMPALINK = 1U;
      EPwm2Regs.EPWMXLINK.bit.CMPBLINK = 1U;
      EPwm2Regs.EPWMXLINK.bit.CMPCLINK = 1U;
      EPwm2Regs.EPWMXLINK.bit.CMPDLINK = 1U;

      /* SYNCPER - Peripheral synchronization output event
         EPwm2Regs.HRPCTL.bit.PWMSYNCSEL            = 0U;          // EPWMSYNCPER selection
         EPwm2Regs.HRPCTL.bit.PWMSYNCSELX           = 0U;          //  EPWMSYNCPER selection
       */
      EPwm2Regs.HRPCTL.all = (EPwm2Regs.HRPCTL.all & ~0x72U) | 0x0U;
      EDIS;
    }

    /* Start for S-Function (c2802xpwm): '<S17>/PWM for the Halfbridge 3' incorporates:
     *  Constant: '<S17>/Constant1'
     */

    /*** Initialize ePWM3 modules ***/
    {
      /*  // Time Base Control Register
         EPwm3Regs.TBCTL.bit.CTRMODE              = 2U;          // Counter Mode
         EPwm3Regs.TBCTL.bit.SYNCOSEL             = 0U;          // Sync Output Select

         EPwm3Regs.TBCTL.bit.PRDLD                = 0U;          // Shadow select

         EPwm3Regs.TBCTL2.bit.PRDLDSYNC           = 0U;          // Shadow select

         EPwm3Regs.TBCTL.bit.PHSEN                = 1U;          // Phase Load Enable
         EPwm3Regs.TBCTL.bit.PHSDIR               = 1U;          // Phase Direction Bit
         EPwm3Regs.TBCTL.bit.HSPCLKDIV            = 0U;          // High Speed TBCLK Pre-scaler
         EPwm3Regs.TBCTL.bit.CLKDIV               = 0U;          // Time Base Clock Pre-scaler
       */
      EPwm3Regs.TBCTL.all = (EPwm3Regs.TBCTL.all & ~0x3FFFU) | 0x2006U;
      EPwm3Regs.TBCTL2.all = (EPwm3Regs.TBCTL2.all & ~0xC000U) | 0x0U;

      /*-- Setup Time-Base (TB) Submodule --*/
      EPwm3Regs.TBPRD = 1000U;         // Time Base Period Register

      /* // Time-Base Phase Register
         EPwm3Regs.TBPHS.bit.TBPHS               = 0U;          // Phase offset register
       */
      EPwm3Regs.TBPHS.all = (EPwm3Regs.TBPHS.all & ~0xFFFF0000U) | 0x0U;

      // Time Base Counter Register
      EPwm3Regs.TBCTR = 0x0000U;       /* Clear counter*/

      /*-- Setup Counter_Compare (CC) Submodule --*/
      /*	// Counter Compare Control Register

         EPwm3Regs.CMPCTL.bit.LOADASYNC           = 0U;          // Active Compare A Load SYNC Option
         EPwm3Regs.CMPCTL.bit.LOADBSYNC           = 0U;          // Active Compare B Load SYNC Option
         EPwm3Regs.CMPCTL.bit.LOADAMODE           = 2U;          // Active Compare A Load
         EPwm3Regs.CMPCTL.bit.LOADBMODE           = 0U;          // Active Compare B Load
         EPwm3Regs.CMPCTL.bit.SHDWAMODE           = 0U;          // Compare A Register Block Operating Mode
         EPwm3Regs.CMPCTL.bit.SHDWBMODE           = 0U;          // Compare B Register Block Operating Mode
       */
      EPwm3Regs.CMPCTL.all = (EPwm3Regs.CMPCTL.all & ~0x3C5FU) | 0x2U;

      /* EPwm3Regs.CMPCTL2.bit.SHDWCMODE           = 0U;          // Compare C Register Block Operating Mode
         EPwm3Regs.CMPCTL2.bit.SHDWDMODE           = 0U;          // Compare D Register Block Operating Mode
         EPwm3Regs.CMPCTL2.bit.LOADCSYNC           = 0U;          // Active Compare C Load SYNC Option
         EPwm3Regs.CMPCTL2.bit.LOADDSYNC           = 0U;          // Active Compare D Load SYNC Option
         EPwm3Regs.CMPCTL2.bit.LOADCMODE           = 0U;          // Active Compare C Load
         EPwm3Regs.CMPCTL2.bit.LOADDMODE           = 0U;          // Active Compare D Load
       */
      EPwm3Regs.CMPCTL2.all = (EPwm3Regs.CMPCTL2.all & ~0x3C5FU) | 0x0U;
      EPwm3Regs.CMPA.bit.CMPA = 1000U; // Counter Compare A Register
      EPwm3Regs.CMPB.bit.CMPB = 32000U;// Counter Compare B Register
      EPwm3Regs.CMPC = 32000U;         // Counter Compare C Register
      EPwm3Regs.CMPD = 32000U;         // Counter Compare D Register

      /*-- Setup Action-Qualifier (AQ) Submodule --*/
      EPwm3Regs.AQCTLA.all = 150U;
                               // Action Qualifier Control Register For Output A
      EPwm3Regs.AQCTLB.all = 2310U;
                               // Action Qualifier Control Register For Output B

      /*	// Action Qualifier Software Force Register
         EPwm3Regs.AQSFRC.bit.RLDCSF              = 0U;          // Reload from Shadow Options
       */
      EPwm3Regs.AQSFRC.all = (EPwm3Regs.AQSFRC.all & ~0xC0U) | 0x0U;

      /*	// Action Qualifier Continuous S/W Force Register
         EPwm3Regs.AQCSFRC.bit.CSFA               = 0U;          // Continuous Software Force on output A
         EPwm3Regs.AQCSFRC.bit.CSFB               = 0U;          // Continuous Software Force on output B
       */
      EPwm3Regs.AQCSFRC.all = (EPwm3Regs.AQCSFRC.all & ~0xFU) | 0x0U;

      /*-- Setup Dead-Band Generator (DB) Submodule --*/
      /*	// Dead-Band Generator Control Register
         EPwm3Regs.DBCTL.bit.OUT_MODE             = 3U;          // Dead Band Output Mode Control
         EPwm3Regs.DBCTL.bit.IN_MODE              = 0U;          // Dead Band Input Select Mode Control
         EPwm3Regs.DBCTL.bit.POLSEL               = 2U;          // Polarity Select Control
         EPwm3Regs.DBCTL.bit.HALFCYCLE            = 0U;          // Half Cycle Clocking Enable
         EPwm3Regs.DBCTL.bit.SHDWDBREDMODE        = 0U;          // DBRED shadow mode
         EPwm3Regs.DBCTL.bit.SHDWDBFEDMODE        = 0U;          // DBFED shadow mode
         EPwm3Regs.DBCTL.bit.LOADREDMODE          = 4U;        // DBRED load
         EPwm3Regs.DBCTL.bit.LOADFEDMODE          = 4U;        // DBFED load
       */
      EPwm3Regs.DBCTL.all = (EPwm3Regs.DBCTL.all & ~0x8FFFU) | 0xBU;
      EPwm3Regs.DBRED.bit.DBRED = (uint16_T)(20.0);
                         // Dead-Band Generator Rising Edge Delay Count Register
      EPwm3Regs.DBFED.bit.DBFED = (uint16_T)(20.0);
                        // Dead-Band Generator Falling Edge Delay Count Register

      /*-- Setup Event-Trigger (ET) Submodule --*/
      /*	// Event Trigger Selection and Pre-Scale Register
         EPwm3Regs.ETSEL.bit.SOCAEN               = 0U;          // Start of Conversion A Enable
         EPwm3Regs.ETSEL.bit.SOCASELCMP           = 0U;
         EPwm3Regs.ETSEL.bit.SOCASEL              = 1U;          // Start of Conversion A Select
         EPwm3Regs.ETPS.bit.SOCPSSEL              = 1U;          // EPWM3SOC Period Select
         EPwm3Regs.ETSOCPS.bit.SOCAPRD2           = 1U;
         EPwm3Regs.ETSEL.bit.SOCBEN               = 0U;          // Start of Conversion B Enable
         EPwm3Regs.ETSEL.bit.SOCBSELCMP           = 0U;
         EPwm3Regs.ETSEL.bit.SOCBSEL              = 1U;          // Start of Conversion A Select
         EPwm3Regs.ETPS.bit.SOCPSSEL              = 1;          // EPWM3SOCB Period Select
         EPwm3Regs.ETSOCPS.bit.SOCBPRD2           = 1U;
         EPwm3Regs.ETSEL.bit.INTEN                = 0U;          // EPWM3INTn Enable
         EPwm3Regs.ETSEL.bit.INTSELCMP            = 0U;
         EPwm3Regs.ETSEL.bit.INTSEL               = 1U;          // Start of Conversion A Select
         EPwm3Regs.ETPS.bit.INTPSSEL              = 1U;          // EPWM3INTn Period Select
         EPwm3Regs.ETINTPS.bit.INTPRD2            = 1U;
       */
      EPwm3Regs.ETSEL.all = (EPwm3Regs.ETSEL.all & ~0xFF7FU) | 0x1101U;
      EPwm3Regs.ETPS.all = (EPwm3Regs.ETPS.all & ~0x30U) | 0x30U;
      EPwm3Regs.ETSOCPS.all = (EPwm3Regs.ETSOCPS.all & ~0xF0FU) | 0x101U;
      EPwm3Regs.ETINTPS.all = (EPwm3Regs.ETINTPS.all & ~0xFU) | 0x1U;

      /*-- Setup PWM-Chopper (PC) Submodule --*/
      /*	// PWM Chopper Control Register
         EPwm3Regs.PCCTL.bit.CHPEN                = 0U;          // PWM chopping enable
         EPwm3Regs.PCCTL.bit.CHPFREQ              = 0U;          // Chopping clock frequency
         EPwm3Regs.PCCTL.bit.OSHTWTH              = 0U;          // One-shot pulse width
         EPwm3Regs.PCCTL.bit.CHPDUTY              = 0U;          // Chopping clock Duty cycle
       */
      EPwm3Regs.PCCTL.all = (EPwm3Regs.PCCTL.all & ~0x7FFU) | 0x0U;

      /*-- Set up Trip-Zone (TZ) Submodule --*/
      EALLOW;
      EPwm3Regs.TZSEL.all = 0U;        // Trip Zone Select Register

      /*	// Trip Zone Control Register
         EPwm3Regs.TZCTL.bit.TZA                  = 3U;          // TZ1 to TZ6 Trip Action On EPWM3A
         EPwm3Regs.TZCTL.bit.TZB                  = 3U;          // TZ1 to TZ6 Trip Action On EPWM3B
         EPwm3Regs.TZCTL.bit.DCAEVT1              = 3U;          // EPWM3A action on DCAEVT1
         EPwm3Regs.TZCTL.bit.DCAEVT2              = 3U;          // EPWM3A action on DCAEVT2
         EPwm3Regs.TZCTL.bit.DCBEVT1              = 3U;          // EPWM3B action on DCBEVT1
         EPwm3Regs.TZCTL.bit.DCBEVT2              = 3U;          // EPWM3B action on DCBEVT2
       */
      EPwm3Regs.TZCTL.all = (EPwm3Regs.TZCTL.all & ~0xFFFU) | 0xFFFU;

      /*	// Trip Zone Enable Interrupt Register
         EPwm3Regs.TZEINT.bit.OST                 = 0U;          // Trip Zones One Shot Int Enable
         EPwm3Regs.TZEINT.bit.CBC                 = 0U;          // Trip Zones Cycle By Cycle Int Enable
         EPwm3Regs.TZEINT.bit.DCAEVT1             = 0U;          // Digital Compare A Event 1 Int Enable
         EPwm3Regs.TZEINT.bit.DCAEVT2             = 0U;          // Digital Compare A Event 2 Int Enable
         EPwm3Regs.TZEINT.bit.DCBEVT1             = 0U;          // Digital Compare B Event 1 Int Enable
         EPwm3Regs.TZEINT.bit.DCBEVT2             = 0U;          // Digital Compare B Event 2 Int Enable
       */
      EPwm3Regs.TZEINT.all = (EPwm3Regs.TZEINT.all & ~0x7EU) | 0x0U;

      /*	// Digital Compare A Control Register
         EPwm3Regs.DCACTL.bit.EVT1SYNCE           = 0U;          // DCAEVT1 SYNC Enable
         EPwm3Regs.DCACTL.bit.EVT1SOCE            = 1U;          // DCAEVT1 SOC Enable
         EPwm3Regs.DCACTL.bit.EVT1FRCSYNCSEL      = 0U;          // DCAEVT1 Force Sync Signal
         EPwm3Regs.DCACTL.bit.EVT1SRCSEL          = 0U;          // DCAEVT1 Source Signal
         EPwm3Regs.DCACTL.bit.EVT2FRCSYNCSEL      = 0U;          // DCAEVT2 Force Sync Signal
         EPwm3Regs.DCACTL.bit.EVT2SRCSEL          = 0U;          // DCAEVT2 Source Signal
       */
      EPwm3Regs.DCACTL.all = (EPwm3Regs.DCACTL.all & ~0x30FU) | 0x4U;

      /*	// Digital Compare B Control Register
         EPwm3Regs.DCBCTL.bit.EVT1SYNCE           = 0U;          // DCBEVT1 SYNC Enable
         EPwm3Regs.DCBCTL.bit.EVT1SOCE            = 0U;          // DCBEVT1 SOC Enable
         EPwm3Regs.DCBCTL.bit.EVT1FRCSYNCSEL      = 0U;          // DCBEVT1 Force Sync Signal
         EPwm3Regs.DCBCTL.bit.EVT1SRCSEL          = 0U;          // DCBEVT1 Source Signal
         EPwm3Regs.DCBCTL.bit.EVT2FRCSYNCSEL      = 0U;          // DCBEVT2 Force Sync Signal
         EPwm3Regs.DCBCTL.bit.EVT2SRCSEL          = 0U;          // DCBEVT2 Source Signal
       */
      EPwm3Regs.DCBCTL.all = (EPwm3Regs.DCBCTL.all & ~0x30FU) | 0x0U;

      /*	// Digital Compare Trip Select Register
         EPwm3Regs.DCTRIPSEL.bit.DCAHCOMPSEL      = 0U;          // Digital Compare A High COMP Input Select

         EPwm3Regs.DCTRIPSEL.bit.DCALCOMPSEL      = 0U;          // Digital Compare A Low COMP Input Select
         EPwm3Regs.DCTRIPSEL.bit.DCBHCOMPSEL      = 0U;          // Digital Compare B High COMP Input Select
         EPwm3Regs.DCTRIPSEL.bit.DCBLCOMPSEL      = 0U;          // Digital Compare B Low COMP Input Select
       */
      EPwm3Regs.DCTRIPSEL.all = (EPwm3Regs.DCTRIPSEL.all & ~ 0xFFFFU) | 0x0U;

      /*	// Trip Zone Digital Comparator Select Register
         EPwm3Regs.TZDCSEL.bit.DCAEVT1            = 0U;          // Digital Compare Output A Event 1
         EPwm3Regs.TZDCSEL.bit.DCAEVT2            = 0U;          // Digital Compare Output A Event 2
         EPwm3Regs.TZDCSEL.bit.DCBEVT1            = 0U;          // Digital Compare Output B Event 1
         EPwm3Regs.TZDCSEL.bit.DCBEVT2            = 0U;          // Digital Compare Output B Event 2
       */
      EPwm3Regs.TZDCSEL.all = (EPwm3Regs.TZDCSEL.all & ~0xFFFU) | 0x0U;

      /*	// Digital Compare Filter Control Register
         EPwm3Regs.DCFCTL.bit.BLANKE              = 0U;          // Blanking Enable/Disable
         EPwm3Regs.DCFCTL.bit.PULSESEL            = 1U;          // Pulse Select for Blanking & Capture Alignment
         EPwm3Regs.DCFCTL.bit.BLANKINV            = 0U;          // Blanking Window Inversion
         EPwm3Regs.DCFCTL.bit.SRCSEL              = 0U;          // Filter Block Signal Source Select
       */
      EPwm3Regs.DCFCTL.all = (EPwm3Regs.DCFCTL.all & ~0x3FU) | 0x10U;
      EPwm3Regs.DCFOFFSET = 0U;        // Digital Compare Filter Offset Register
      EPwm3Regs.DCFWINDOW = 0U;        // Digital Compare Filter Window Register

      /*	// Digital Compare Capture Control Register
         EPwm3Regs.DCCAPCTL.bit.CAPE              = 0U;          // Counter Capture Enable
       */
      EPwm3Regs.DCCAPCTL.all = (EPwm3Regs.DCCAPCTL.all & ~0x1U) | 0x0U;

      /*	// HRPWM Configuration Register
         EPwm3Regs.HRCNFG.bit.SWAPAB              = 0U;          // Swap EPWMA and EPWMB Outputs Bit
         EPwm3Regs.HRCNFG.bit.SELOUTB             = 0U;          // EPWMB Output Selection Bit
       */
      EPwm3Regs.HRCNFG.all = (EPwm3Regs.HRCNFG.all & ~0xA0U) | 0x0U;

      /* Update the Link Registers with the link value for all the Compare values and TBPRD */
      /* No error is thrown if the ePWM register exists in the model or not */
      EPwm3Regs.EPWMXLINK.bit.TBPRDLINK = 2U;
      EPwm3Regs.EPWMXLINK.bit.CMPALINK = 2U;
      EPwm3Regs.EPWMXLINK.bit.CMPBLINK = 2U;
      EPwm3Regs.EPWMXLINK.bit.CMPCLINK = 2U;
      EPwm3Regs.EPWMXLINK.bit.CMPDLINK = 2U;

      /* SYNCPER - Peripheral synchronization output event
         EPwm3Regs.HRPCTL.bit.PWMSYNCSEL            = 0U;          // EPWMSYNCPER selection
         EPwm3Regs.HRPCTL.bit.PWMSYNCSELX           = 0U;          //  EPWMSYNCPER selection
       */
      EPwm3Regs.HRPCTL.all = (EPwm3Regs.HRPCTL.all & ~0x72U) | 0x0U;
      EDIS;
    }

    /* Start for S-Function (c280xgpio_do): '<S17>/Digital Output' */
    EALLOW;
    GpioCtrlRegs.GPDMUX2.all &= 0xFCFFFFFFU;
    GpioCtrlRegs.GPDDIR.all |= 0x10000000U;
    EDIS;

    /* Start for S-Function (c2802xadc): '<S19>/ADC1' */
    if (MW_adcBInitFlag == 0U) {
      InitAdcB();
      MW_adcBInitFlag = 1U;
    }

    config_ADCB_SOC1 ();

    /* Start for S-Function (c2802xadc): '<S19>/ADC2' */
    if (MW_adcAInitFlag == 0U) {
      InitAdcA();
      MW_adcAInitFlag = 1U;
    }

    config_ADCA_SOC2 ();

    /* Start for S-Function (c280xqep): '<S25>/eQEP' */
    config_QEP_eQEP1((uint32_T)65535U,(uint32_T)0, (uint32_T)0, (uint32_T)0,
                     (uint16_T)0, (uint16_T)448, (uint16_T)8232, (uint16_T)32768,
                     (uint16_T)119,(uint16_T)0);

    /* InitializeConditions for Gain: '<S23>/Gain1' incorporates:
     *  UnitDelay: '<S24>/Unit Delay'
     */
    feedback_control_DWork.UnitDelay_DSTATE =
      feedback_control_P.UnitDelay_InitialCondition;

    /* InitializeConditions for UnitDelay: '<S16>/Unit Delay1' */
    feedback_control_DWork.UnitDelay1_DSTATE_h =
      feedback_control_P.UnitDelay1_InitialCondition_m;

    /* InitializeConditions for UnitDelay: '<S13>/Unit Delay' */
    feedback_control_DWork.UnitDelay_DSTATE_g =
      feedback_control_P.UnitDelay_InitialCondition_c;

    /* InitializeConditions for Sum: '<S13>/Add1' incorporates:
     *  UnitDelay: '<S13>/Unit Delay1'
     */
    feedback_control_DWork.UnitDelay1_DSTATE =
      feedback_control_P.UnitDelay1_InitialCondition;

    /* Start for MATLABSystem: '<S5>/DAC1' */
    MW_ConfigureDACB();

    /* Start for MATLABSystem: '<S5>/DAC' */
    MW_ConfigureDACA();

    /* Start for MATLABSystem: '<S10>/SPI Master Transfer1' */
    feedback_control_DWork.obj_i.matlabCodegenIsDeleted = false;
    feedback_control_DWork.obj_i.isInitialized = 1L;
    SPIPinsLoc = MW_UNDEFINED_VALUE;
    feedback_control_DWork.obj_i.MW_SPI_HANDLE = MW_SPI_Open(0UL, SPIPinsLoc,
      SPIPinsLoc, SPIPinsLoc, MW_UNDEFINED_VALUE, true, 0U);
    MW_SPI_SetFormat(feedback_control_DWork.obj_i.MW_SPI_HANDLE, 16U,
                     MW_SPI_MODE_0, MW_SPI_MOST_SIGNIFICANT_BIT_FIRST);
    feedback_control_DWork.obj_i.isSetupComplete = true;

    /* End of SystemInitialize for SubSystem: '<S9>/Enable DRV8305 for motor 1' */
    /* End of SystemInitialize for SubSystem: '<Root>/Hardware Init' */

    /* Outputs for Atomic SubSystem: '<Root>/Hardware Init' */
    /* Outputs for Atomic SubSystem: '<S9>/Enable DRV8305 for motor 1' */
    /* MATLABSystem: '<S10>/SPI Master Transfer1' incorporates:
     *  Constant: '<S10>/ADC_Gain_Setting'
     */
    MW_SPI_SetSlaveSelect(feedback_control_DWork.obj_i.MW_SPI_HANDLE, 0U, true);
    status = MW_SPI_SetFormat(feedback_control_DWork.obj_i.MW_SPI_HANDLE, 16U,
      MW_SPI_MODE_0, MW_SPI_MOST_SIGNIFICANT_BIT_FIRST);
    if (status == 0U) {
      MW_SPI_MasterWriteRead_8bits(feedback_control_DWork.obj_i.MW_SPI_HANDLE,
        &feedback_control_P.ADC_Gain_Setting_Value,
        &feedback_control_B.SPIMasterTransfer1, 1UL);
    }

    /* End of MATLABSystem: '<S10>/SPI Master Transfer1' */
  }
}

/* Model terminate function */
void feedback_control_terminate(void)
{
  uint32_T SPIPinsLoc;

  /* Terminate for Enabled SubSystem: '<S1>/Subsystem' */
  /* Terminate for MATLABSystem: '<S7>/SPI Transmit' */
  if (!feedback_control_DWork.obj.matlabCodegenIsDeleted) {
    feedback_control_DWork.obj.matlabCodegenIsDeleted = true;
    if ((feedback_control_DWork.obj.isInitialized == 1L) &&
        (feedback_control_DWork.obj.isSetupComplete)) {
      SPIPinsLoc = MW_UNDEFINED_VALUE;
      MW_SPI_Close(feedback_control_DWork.obj.MW_SPI_HANDLE, SPIPinsLoc,
                   SPIPinsLoc, SPIPinsLoc, MW_UNDEFINED_VALUE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S7>/SPI Transmit' */
  /* End of Terminate for SubSystem: '<S1>/Subsystem' */
  /* Terminate for Atomic SubSystem: '<Root>/Hardware Init' */
  /* Terminate for Atomic SubSystem: '<S9>/Enable DRV8305 for motor 1' */
  /* Terminate for MATLABSystem: '<S10>/SPI Master Transfer1' */
  if (!feedback_control_DWork.obj_i.matlabCodegenIsDeleted) {
    feedback_control_DWork.obj_i.matlabCodegenIsDeleted = true;
    if ((feedback_control_DWork.obj_i.isInitialized == 1L) &&
        (feedback_control_DWork.obj_i.isSetupComplete)) {
      SPIPinsLoc = MW_UNDEFINED_VALUE;
      MW_SPI_Close(feedback_control_DWork.obj_i.MW_SPI_HANDLE, SPIPinsLoc,
                   SPIPinsLoc, SPIPinsLoc, MW_UNDEFINED_VALUE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S10>/SPI Master Transfer1' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
