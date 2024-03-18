/*
 * blikingled_28069M_launchpad_data.c
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

/* Block parameters (default storage) */
P_blikingled_28069M_launchpad_T blikingled_28069M_launchpad_P = {
  /* Mask Parameter: TranslatetoAmps2_Offset
   * Referenced by: '<S4>/Constant'
   */
  2047.5,

  /* Mask Parameter: TranslatetoAmps1_Offset
   * Referenced by: '<S3>/Constant'
   */
  2047.5,

  /* Mask Parameter: TranslatetoAmps_Offset
   * Referenced by: '<S2>/Constant'
   */
  2047.5,

  /* Mask Parameter: TranslatetoAmps2_Gain
   * Referenced by: '<S4>/Gain'
   */
  32768U,

  /* Mask Parameter: TranslatetoAmps1_Gain
   * Referenced by: '<S3>/Gain'
   */
  32768U,

  /* Mask Parameter: TranslatetoAmps_Gain
   * Referenced by: '<S2>/Gain'
   */
  32768U,

  /* Expression: [1 1]
   * Referenced by: '<Root>/Constant'
   */
  { 1.0, 1.0 },

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
  1.0,

  /* Expression: 227.7826404571533
   * Referenced by: '<Root>/Sine Wave'
   */
  227.78264045715329,

  /* Expression: 2300
   * Referenced by: '<Root>/Sine Wave'
   */
  2300.0,

  /* Expression: 100
   * Referenced by: '<Root>/Sine Wave'
   */
  100.0,

  /* Expression: 0
   * Referenced by: '<Root>/Sine Wave'
   */
  0.0,

  /* Expression: 2300
   * Referenced by: '<Root>/Constant2'
   */
  2300.0
};
