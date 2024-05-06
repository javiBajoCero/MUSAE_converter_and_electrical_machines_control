/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: feedback_plant_data.c
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

/* Block parameters (default storage) */
P_feedback_plant_T feedback_plant_P = {
  /* Mask Parameter: DCMotor_Kf
   * Referenced by:
   *   '<S1>/Gain'
   *   '<S1>/Gain1'
   */
  3.8089,

  /* Expression: 0.1
   * Referenced by: '<Root>/Step'
   */
  0.1,

  /* Expression: 0.6
   * Referenced by: '<Root>/Step'
   */
  0.6,

  /* Expression: 0.4
   * Referenced by: '<Root>/Step'
   */
  0.4,

  /* Expression: 1
   * Referenced by: '<Root>/Constant1'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<Root>/Constant2'
   */
  0.0,

  /* Expression: 24
   * Referenced by: '<Root>/Constant'
   */
  24.0,

  /* Expression: 1/2
   * Referenced by: '<S6>/Constant'
   */
  0.5,

  /* Computed Parameter: TransferFcn_A
   * Referenced by: '<S7>/Transfer Fcn'
   */
  -0.007,

  /* Computed Parameter: TransferFcn_C
   * Referenced by: '<S7>/Transfer Fcn'
   */
  2.0,

  /* Computed Parameter: TransferFcn_A_e
   * Referenced by: '<S1>/Transfer Fcn'
   */
  -77.900552486187834,

  /* Computed Parameter: TransferFcn_C_l
   * Referenced by: '<S1>/Transfer Fcn'
   */
  110.49723756906076,

  /* Expression: 0
   * Referenced by: '<Root>/Integrator'
   */
  0.0,

  /* Computed Parameter: ManualSwitch1_CurrentSetting
   * Referenced by: '<Root>/Manual Switch1'
   */
  1U,

  /* Computed Parameter: ManualSwitch_CurrentSetting
   * Referenced by: '<Root>/Manual Switch'
   */
  0U
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
