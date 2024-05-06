/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: feedback_plant.c
 *
 * Code generated for Simulink model 'feedback_plant'.
 *
 * Model version                  : 17.16
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Mon May  6 19:22:25 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "feedback_plant.h"
#include "rtwtypes.h"
#include "feedback_plant_private.h"
#include <string.h>

/* Block signals (default storage) */
B_feedback_plant_T feedback_plant_B;

/* Continuous states */
X_feedback_plant_T feedback_plant_X;

/* Disabled State Vector */
XDis_feedback_plant_T feedback_plant_XDis;

/* Block states (default storage) */
DW_feedback_plant_T feedback_plant_DW;

/* External inputs (root inport signals with default storage) */
ExtU_feedback_plant_T feedback_plant_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_feedback_plant_T feedback_plant_Y;

/* Real-time model */
static RT_MODEL_feedback_plant_T feedback_plant_M_;
RT_MODEL_feedback_plant_T *const feedback_plant_M = &feedback_plant_M_;

/*
 * This function updates continuous states using the ODE3 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static const real_T rt_ODE3_A[3] = {
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3] = {
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = (ODE3_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 3;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  feedback_plant_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  feedback_plant_step();
  feedback_plant_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  feedback_plant_step();
  feedback_plant_derivatives();

  /* tnew = t + hA(3);
     ynew = y + f*hB(:,3); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model step function */
void feedback_plant_step(void)
{
  real_T rtb_ManualSwitch1_idx_1;
  real_T rtb_ManualSwitch1_idx_2;
  real_T rtb_Step;
  if (rtmIsMajorTimeStep(feedback_plant_M)) {
    /* set solver stop time */
    if (!(feedback_plant_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&feedback_plant_M->solverInfo,
                            ((feedback_plant_M->Timing.clockTickH0 + 1) *
        feedback_plant_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&feedback_plant_M->solverInfo,
                            ((feedback_plant_M->Timing.clockTick0 + 1) *
        feedback_plant_M->Timing.stepSize0 +
        feedback_plant_M->Timing.clockTickH0 *
        feedback_plant_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(feedback_plant_M)) {
    feedback_plant_M->Timing.t[0] = rtsiGetT(&feedback_plant_M->solverInfo);
  }

  /* Step: '<Root>/Step' */
  if (feedback_plant_M->Timing.t[0] < feedback_plant_P.Step_Time) {
    rtb_Step = feedback_plant_P.Step_Y0;
  } else {
    rtb_Step = feedback_plant_P.Step_YFinal;
  }

  /* End of Step: '<Root>/Step' */

  /* ManualSwitch: '<Root>/Manual Switch1' incorporates:
   *  Constant: '<Root>/Constant1'
   *  Constant: '<Root>/Constant2'
   *  Inport: '<Root>/Duty Cycles (Da, Db, Dc)'
   *  Sum: '<Root>/Sum'
   */
  if (feedback_plant_P.ManualSwitch1_CurrentSetting == 1U) {
    rtb_Step = feedback_plant_U.DutyCyclesDaDbDc[0];
    rtb_ManualSwitch1_idx_1 = feedback_plant_U.DutyCyclesDaDbDc[1];
    rtb_ManualSwitch1_idx_2 = feedback_plant_U.DutyCyclesDaDbDc[2];
  } else {
    rtb_ManualSwitch1_idx_1 = feedback_plant_P.Constant1_Value - rtb_Step;
    rtb_ManualSwitch1_idx_2 = feedback_plant_P.Constant2_Value;
  }

  /* End of ManualSwitch: '<Root>/Manual Switch1' */
  if (rtmIsMajorTimeStep(feedback_plant_M)) {
    /* Constant: '<Root>/Constant' */
    feedback_plant_B.Constant = feedback_plant_P.Constant_Value;
  }

  /* Product: '<S6>/Product' incorporates:
   *  Constant: '<S6>/Constant'
   *  Sum: '<S6>/Sum'
   */
  feedback_plant_B.Product = (rtb_Step - feedback_plant_P.Constant_Value_n) *
    feedback_plant_B.Constant;

  /* Product: '<S6>/Product1' incorporates:
   *  Constant: '<S6>/Constant'
   *  Sum: '<S6>/Sum1'
   */
  feedback_plant_B.Product1 = (rtb_ManualSwitch1_idx_1 -
    feedback_plant_P.Constant_Value_n) * feedback_plant_B.Constant;

  /* Product: '<S6>/Product2' incorporates:
   *  Constant: '<S6>/Constant'
   *  Sum: '<S6>/Sum2'
   */
  feedback_plant_B.Product2 = (rtb_ManualSwitch1_idx_2 -
    feedback_plant_P.Constant_Value_n) * feedback_plant_B.Constant;
  if (rtmIsMajorTimeStep(feedback_plant_M)) {
    /* SignalConversion generated from: '<S5>/Three Phase Interter (Average Model)' */
    feedback_plant_B.Vrst[0] = feedback_plant_B.Product;
    feedback_plant_B.Vrst[1] = feedback_plant_B.Product1;
    feedback_plant_B.Vrst[2] = feedback_plant_B.Product2;
  }

  /* Sum: '<S5>/Add1' */
  feedback_plant_B.Add1 = feedback_plant_B.Product - feedback_plant_B.Product1;
  if (rtmIsMajorTimeStep(feedback_plant_M)) {
  }

  /* TransferFcn: '<S7>/Transfer Fcn' */
  feedback_plant_B.TransferFcn = 0.0;
  feedback_plant_B.TransferFcn += feedback_plant_P.TransferFcn_C *
    feedback_plant_X.TransferFcn_CSTATE;

  /* ManualSwitch: '<Root>/Manual Switch' */
  if (feedback_plant_P.ManualSwitch_CurrentSetting == 1U) {
    rtb_ManualSwitch1_idx_2 = feedback_plant_B.Constant;
  } else {
    rtb_ManualSwitch1_idx_2 = feedback_plant_B.Add1;
  }

  /* Sum: '<S1>/Sum' incorporates:
   *  Gain: '<S1>/Gain1'
   *  ManualSwitch: '<Root>/Manual Switch'
   */
  feedback_plant_B.Sum = rtb_ManualSwitch1_idx_2 - feedback_plant_P.DCMotor_Kf *
    feedback_plant_B.TransferFcn;
  if (rtmIsMajorTimeStep(feedback_plant_M)) {
    /* Outport: '<Root>/Vdc' */
    feedback_plant_Y.Vdc = feedback_plant_B.Constant;
  }

  /* TransferFcn: '<S1>/Transfer Fcn' */
  feedback_plant_B.I = 0.0;
  feedback_plant_B.I += feedback_plant_P.TransferFcn_C_l *
    feedback_plant_X.TransferFcn_CSTATE_l;

  /* Outport: '<Root>/I' */
  feedback_plant_Y.I = feedback_plant_B.I;
  if (rtmIsMajorTimeStep(feedback_plant_M)) {
  }

  /* Gain: '<S1>/Gain' */
  feedback_plant_B.T_Motor = feedback_plant_P.DCMotor_Kf * feedback_plant_B.I;

  /* Integrator: '<Root>/Integrator' */
  feedback_plant_B.Mechanical_Position = feedback_plant_X.Integrator_CSTATE;

  /* Outport: '<Root>/Trans Out' */
  feedback_plant_Y.TransOut = feedback_plant_B.Mechanical_Position;
  if (rtmIsMajorTimeStep(feedback_plant_M)) {
  }

  if (rtmIsMajorTimeStep(feedback_plant_M)) {
    if (rtmIsMajorTimeStep(feedback_plant_M)) {/* Sample time: [5.0E-6s, 0.0s] */
      extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
      extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T)
        (((feedback_plant_M->Timing.clockTick1+
           feedback_plant_M->Timing.clockTickH1* 4294967296.0) * 1) + 0)
        ;

      /* Trigger External Mode event */
      errorCode = extmodeEvent(1,currentTime);
      if (errorCode != EXTMODE_SUCCESS) {
        /* Code to handle External Mode event errors
           may be added here */
      }
    }
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(feedback_plant_M)) {
    rt_ertODEUpdateContinuousStates(&feedback_plant_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick0 and the high bits
     * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++feedback_plant_M->Timing.clockTick0)) {
      ++feedback_plant_M->Timing.clockTickH0;
    }

    feedback_plant_M->Timing.t[0] = rtsiGetSolverStopTime
      (&feedback_plant_M->solverInfo);

    {
      /* Update absolute timer for sample time: [5.0E-6s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 5.0E-6, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       * Timer of this task consists of two 32 bit unsigned integers.
       * The two integers represent the low bits Timing.clockTick1 and the high bits
       * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
       */
      feedback_plant_M->Timing.clockTick1++;
      if (!feedback_plant_M->Timing.clockTick1) {
        feedback_plant_M->Timing.clockTickH1++;
      }
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void feedback_plant_derivatives(void)
{
  XDot_feedback_plant_T *_rtXdot;
  _rtXdot = ((XDot_feedback_plant_T *) feedback_plant_M->derivs);

  /* Derivatives for TransferFcn: '<S7>/Transfer Fcn' */
  _rtXdot->TransferFcn_CSTATE = feedback_plant_P.TransferFcn_A *
    feedback_plant_X.TransferFcn_CSTATE;
  _rtXdot->TransferFcn_CSTATE += feedback_plant_B.T_Motor;

  /* Derivatives for TransferFcn: '<S1>/Transfer Fcn' */
  _rtXdot->TransferFcn_CSTATE_l = feedback_plant_P.TransferFcn_A_e *
    feedback_plant_X.TransferFcn_CSTATE_l;
  _rtXdot->TransferFcn_CSTATE_l += feedback_plant_B.Sum;

  /* Derivatives for Integrator: '<Root>/Integrator' */
  _rtXdot->Integrator_CSTATE = feedback_plant_B.TransferFcn;
}

/* Model initialize function */
void feedback_plant_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)feedback_plant_M, 0,
                sizeof(RT_MODEL_feedback_plant_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&feedback_plant_M->solverInfo,
                          &feedback_plant_M->Timing.simTimeStep);
    rtsiSetTPtr(&feedback_plant_M->solverInfo, &rtmGetTPtr(feedback_plant_M));
    rtsiSetStepSizePtr(&feedback_plant_M->solverInfo,
                       &feedback_plant_M->Timing.stepSize0);
    rtsiSetdXPtr(&feedback_plant_M->solverInfo, &feedback_plant_M->derivs);
    rtsiSetContStatesPtr(&feedback_plant_M->solverInfo, (real_T **)
                         &feedback_plant_M->contStates);
    rtsiSetNumContStatesPtr(&feedback_plant_M->solverInfo,
      &feedback_plant_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&feedback_plant_M->solverInfo,
      &feedback_plant_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&feedback_plant_M->solverInfo,
      &feedback_plant_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&feedback_plant_M->solverInfo,
      &feedback_plant_M->periodicContStateRanges);
    rtsiSetContStateDisabledPtr(&feedback_plant_M->solverInfo, (boolean_T**)
      &feedback_plant_M->contStateDisabled);
    rtsiSetErrorStatusPtr(&feedback_plant_M->solverInfo, (&rtmGetErrorStatus
      (feedback_plant_M)));
    rtsiSetRTModelPtr(&feedback_plant_M->solverInfo, feedback_plant_M);
  }

  rtsiSetSimTimeStep(&feedback_plant_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetIsMinorTimeStepWithModeChange(&feedback_plant_M->solverInfo, false);
  rtsiSetIsContModeFrozen(&feedback_plant_M->solverInfo, false);
  feedback_plant_M->intgData.y = feedback_plant_M->odeY;
  feedback_plant_M->intgData.f[0] = feedback_plant_M->odeF[0];
  feedback_plant_M->intgData.f[1] = feedback_plant_M->odeF[1];
  feedback_plant_M->intgData.f[2] = feedback_plant_M->odeF[2];
  feedback_plant_M->contStates = ((X_feedback_plant_T *) &feedback_plant_X);
  feedback_plant_M->contStateDisabled = ((XDis_feedback_plant_T *)
    &feedback_plant_XDis);
  feedback_plant_M->Timing.tStart = (0.0);
  rtsiSetSolverData(&feedback_plant_M->solverInfo, (void *)
                    &feedback_plant_M->intgData);
  rtsiSetSolverName(&feedback_plant_M->solverInfo,"ode3");
  rtmSetTPtr(feedback_plant_M, &feedback_plant_M->Timing.tArray[0]);
  rtmSetTFinal(feedback_plant_M, -1);
  feedback_plant_M->Timing.stepSize0 = 5.0E-6;

  /* External mode info */
  feedback_plant_M->Sizes.checksums[0] = (234776342U);
  feedback_plant_M->Sizes.checksums[1] = (3443776229U);
  feedback_plant_M->Sizes.checksums[2] = (3184573118U);
  feedback_plant_M->Sizes.checksums[3] = (767476806U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[2];
    feedback_plant_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(feedback_plant_M->extModeInfo,
      &feedback_plant_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(feedback_plant_M->extModeInfo,
                        feedback_plant_M->Sizes.checksums);
    rteiSetTPtr(feedback_plant_M->extModeInfo, rtmGetTPtr(feedback_plant_M));
  }

  /* block I/O */
  (void) memset(((void *) &feedback_plant_B), 0,
                sizeof(B_feedback_plant_T));

  /* states (continuous) */
  {
    (void) memset((void *)&feedback_plant_X, 0,
                  sizeof(X_feedback_plant_T));
  }

  /* disabled states */
  {
    (void) memset((void *)&feedback_plant_XDis, 0,
                  sizeof(XDis_feedback_plant_T));
  }

  /* states (dwork) */
  (void) memset((void *)&feedback_plant_DW, 0,
                sizeof(DW_feedback_plant_T));

  /* external inputs */
  (void)memset(&feedback_plant_U, 0, sizeof(ExtU_feedback_plant_T));

  /* external outputs */
  (void)memset(&feedback_plant_Y, 0, sizeof(ExtY_feedback_plant_T));

  /* InitializeConditions for TransferFcn: '<S7>/Transfer Fcn' */
  feedback_plant_X.TransferFcn_CSTATE = 0.0;

  /* InitializeConditions for TransferFcn: '<S1>/Transfer Fcn' */
  feedback_plant_X.TransferFcn_CSTATE_l = 0.0;

  /* InitializeConditions for Integrator: '<Root>/Integrator' */
  feedback_plant_X.Integrator_CSTATE = feedback_plant_P.Integrator_IC;
}

/* Model terminate function */
void feedback_plant_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
