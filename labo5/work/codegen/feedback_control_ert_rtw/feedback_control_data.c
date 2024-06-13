/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: feedback_control_data.c
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

/* Block parameters (default storage) */
Parameters_feedback_control feedback_control_P = {
  /* Mask Parameter: Calibrate_Vdc_Gain
   * Referenced by: '<S23>/Gain1'
   */
  0.00987476949F,

  /* Mask Parameter: Calibrate_Ir_Gain
   * Referenced by: '<S20>/Gain1'
   */
  0.00057575549F,

  /* Mask Parameter: AdaptDAC1_Gain
   * Referenced by: '<S12>/Gain2'
   */
  1736.84851F,

  /* Mask Parameter: AdaptDAC_Gain
   * Referenced by: '<S11>/Gain2'
   */
  0.00981685F,

  /* Mask Parameter: Calibrate_Vdc_Offset
   * Referenced by: '<S23>/Offset'
   */
  0.1525F,

  /* Mask Parameter: Calibrate_Ir_Offset
   * Referenced by: '<S20>/Offset'
   */
  2251.7F,

  /* Mask Parameter: AdaptDAC1_Offset
   * Referenced by: '<S12>/Offset'
   */
  2048.0F,

  /* Mask Parameter: AdaptDAC_Offset
   * Referenced by: '<S11>/Offset'
   */
  2252.8F,

  /* Mask Parameter: DetectChange_vinit
   * Referenced by: '<S6>/Delay Input1'
   */
  0U,

  /* Computed Parameter: Gain2_Gain
   * Referenced by: '<S13>/Gain2'
   */
  -1.0F,

  /* Computed Parameter: Constant_Value
   * Referenced by: '<S35>/Constant'
   */
  1.0F,

  /* Computed Parameter: Constant1_Value
   * Referenced by: '<S32>/Constant1'
   */
  0.0F,

  /* Computed Parameter: ReplaceInport_Offset_Value
   * Referenced by: '<S29>/ReplaceInport_Offset'
   */
  0.0F,

  /* Computed Parameter: Constant3_Value
   * Referenced by: '<S16>/Constant3'
   */
  1.0F,

  /* Computed Parameter: Constant4_Value
   * Referenced by: '<S16>/Constant4'
   */
  -1.0F,

  /* Computed Parameter: Constant2_Value
   * Referenced by: '<S15>/Constant2'
   */
  0.5F,

  /* Computed Parameter: Gain1_Gain
   * Referenced by: '<S15>/Gain1'
   */
  0.5F,

  /* Computed Parameter: Constant3_Value_l
   * Referenced by: '<S15>/Constant3'
   */
  0.6F,

  /* Computed Parameter: Constant4_Value_f
   * Referenced by: '<S5>/Constant4'
   */
  0.0F,

  /* Computed Parameter: Constant1_Value_i
   * Referenced by: '<S15>/Constant1'
   */
  1.0F,

  /* Computed Parameter: Period_Gain
   * Referenced by: '<S17>/Period'
   */
  2000.0F,

  /* Computed Parameter: Constant2_Value_a
   * Referenced by: '<S17>/Constant2'
   */
  { 100.0F, 0.0F, 0.0F },

  /* Computed Parameter: UnitDelay_InitialCondition
   * Referenced by: '<S24>/Unit Delay'
   */
  0.0F,

  /* Computed Parameter: V_Ref_Value
   * Referenced by: '<S5>/V_Ref'
   */
  0.0F,

  /* Computed Parameter: Gain_Gain
   * Referenced by: '<S13>/Gain'
   */
  21.6806984F,

  /* Computed Parameter: UnitDelay_InitialCondition_c
   * Referenced by: '<S13>/Unit Delay'
   */
  0.0F,

  /* Computed Parameter: Gain1_Gain_c
   * Referenced by: '<S13>/Gain1'
   */
  -19.2093029F,

  /* Computed Parameter: UnitDelay1_InitialCondition
   * Referenced by: '<S13>/Unit Delay1'
   */
  0.0F,

  /* Computed Parameter: Constant1_Value_c
   * Referenced by: '<S17>/Constant1'
   */
  2000.0F,

  /* Computed Parameter: Constant_Value_o
   * Referenced by: '<S46>/Constant'
   */
  6.25E-5F,

  /* Computed Parameter: Constant_Value_d
   * Referenced by: '<S3>/Constant'
   */
  1.0F,

  /* Computed Parameter: Constant_Value_n
   * Referenced by: '<S16>/Constant'
   */
  1U,

  /* Computed Parameter: UnitDelay1_InitialCondition_m
   * Referenced by: '<S16>/Unit Delay1'
   */
  0U,

  /* Computed Parameter: Constant1_Value_j
   * Referenced by: '<S16>/Constant1'
   */
  10000U,

  /* Computed Parameter: Constant2_Value_h
   * Referenced by: '<S16>/Constant2'
   */
  5000U,

  /* Computed Parameter: Switch_Threshold
   * Referenced by: '<S16>/Switch'
   */
  0U,

  /* Computed Parameter: ResetMode_Value
   * Referenced by: '<S30>/ResetMode'
   */
  1,

  /* Computed Parameter: Constant_Value_m
   * Referenced by: '<S45>/Constant'
   */
  16000U,

  /* Computed Parameter: Constant_Value_e
   * Referenced by: '<S7>/Constant'
   */
  0U,

  /* Computed Parameter: Constant1_Value_iy
   * Referenced by: '<S7>/Constant1'
   */
  0U,

  /* Computed Parameter: Ticks_Y0
   * Referenced by: '<S7>/Ticks'
   */
  0U,

  /* Computed Parameter: Status_Y0
   * Referenced by: '<S7>/Status'
   */
  0U,

  /* Computed Parameter: Inc_Value
   * Referenced by: '<S7>/Inc'
   */
  1U,

  /* Computed Parameter: UnitDelay_InitialCondition_l
   * Referenced by: '<S7>/Unit Delay'
   */
  0U,

  /* Computed Parameter: Switch_Threshold_p
   * Referenced by: '<S7>/Switch'
   */
  0U,

  /* Computed Parameter: Gain_Gain_m
   * Referenced by: '<S7>/Gain'
   */
  2048U,

  /* Expression: 0x503F
   * Referenced by: '<S10>/ADC_Gain_Setting'
   */
  20543U,

  /* Computed Parameter: Enable_Value
   * Referenced by: '<Root>/Enable'
   */
  1U,

  /* Computed Parameter: Address_Value
   * Referenced by: '<S1>/Address'
   */
  10U,

  /* Computed Parameter: WriteRead_Value
   * Referenced by: '<S1>/Write//Read'
   */
  0U,

  /* Computed Parameter: WriteRead1_Value
   * Referenced by: '<S1>/Write//Read1'
   */
  63U,

  /* Computed Parameter: TmpRTBAtThreePhaseConverterCont
   * Referenced by:
   */
  0U,

  /* Computed Parameter: ManualSwitch_CurrentSetting
   * Referenced by: '<S5>/Manual Switch'
   */
  1U,

  /* Computed Parameter: ManualSwitch_CurrentSetting_d
   * Referenced by: '<S15>/Manual Switch'
   */
  1U,

  /* Computed Parameter: ManualSwitch_CurrentSetting_j
   * Referenced by: '<S17>/Manual Switch'
   */
  1U,

  /* Computed Parameter: Constant_Value_ei
   * Referenced by: '<S32>/Constant'
   */
  2U,

  /* Computed Parameter: Switch_Threshold_f
   * Referenced by: '<S32>/Switch'
   */
  1U
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
