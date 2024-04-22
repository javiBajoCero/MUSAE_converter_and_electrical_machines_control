/*
 * blikingled_28069M_launchpad_data.c
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

/* Block parameters (default storage) */
P_blikingled_28069M_launchpad_T blikingled_28069M_launchpad_P = {
  /* Mask Parameter: calibration3_Gain
   * Referenced by: '<S9>/Gain'
   */
  1.0,

  /* Mask Parameter: TranslatetoVolts_Gain
   * Referenced by: '<S5>/Gain'
   */
  0.010815918947269538,

  /* Mask Parameter: calibration2_Gain
   * Referenced by: '<S8>/Gain'
   */
  0.97360912981455061,

  /* Mask Parameter: TranslatetoAmps2_Gain
   * Referenced by: '<S4>/Gain'
   */
  -0.011509486607142856,

  /* Mask Parameter: calibration1_Gain
   * Referenced by: '<S7>/Gain'
   */
  0.97360912981455061,

  /* Mask Parameter: TranslatetoAmps1_Gain
   * Referenced by: '<S3>/Gain'
   */
  -0.011509486607142856,

  /* Mask Parameter: calibration_Gain
   * Referenced by: '<S6>/Gain'
   */
  0.975,

  /* Mask Parameter: TranslatetoAmps_Gain
   * Referenced by: '<S2>/Gain'
   */
  -0.011509486607142856,

  /* Mask Parameter: calibration3_Offset
   * Referenced by: '<S9>/Constant'
   */
  0.0,

  /* Mask Parameter: TranslatetoVolts_Offset
   * Referenced by: '<S5>/Constant'
   */
  0.0,

  /* Mask Parameter: calibration2_Offset
   * Referenced by: '<S8>/Constant'
   */
  0.0,

  /* Mask Parameter: TranslatetoAmps2_Offset
   * Referenced by: '<S4>/Constant'
   */
  2047.5,

  /* Mask Parameter: calibration1_Offset
   * Referenced by: '<S7>/Constant'
   */
  0.0,

  /* Mask Parameter: TranslatetoAmps1_Offset
   * Referenced by: '<S3>/Constant'
   */
  2047.5,

  /* Mask Parameter: calibration_Offset
   * Referenced by: '<S6>/Constant'
   */
  0.0,

  /* Mask Parameter: TranslatetoAmps_Offset
   * Referenced by: '<S2>/Constant'
   */
  2047.5,

  /* Expression: 1
   * Referenced by: '<Root>/2Hz pulse'
   */
  1.0,

  /* Computed Parameter: uHzpulse_Period
   * Referenced by: '<Root>/2Hz pulse'
   */
  2.0,

  /* Computed Parameter: uHzpulse_Duty
   * Referenced by: '<Root>/2Hz pulse'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<Root>/2Hz pulse'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<Root>/Constant1'
   */
  1.0
};
