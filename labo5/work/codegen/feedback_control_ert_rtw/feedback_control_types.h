/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: feedback_control_types.h
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

#ifndef feedback_control_types_h_
#define feedback_control_types_h_
#include "rtwtypes.h"
#include "MW_c2000SPI.h"
#ifndef struct_tag_mJwWZQsvJAXvgRMjJItCbG
#define struct_tag_mJwWZQsvJAXvgRMjJItCbG

struct tag_mJwWZQsvJAXvgRMjJItCbG
{
  int32_T isInitialized;
};

#endif                                 /* struct_tag_mJwWZQsvJAXvgRMjJItCbG */

#ifndef typedef_codertarget_tic2000_blocks_DACW
#define typedef_codertarget_tic2000_blocks_DACW

typedef struct tag_mJwWZQsvJAXvgRMjJItCbG codertarget_tic2000_blocks_DACW;

#endif                             /* typedef_codertarget_tic2000_blocks_DACW */

/* Custom Type definition for MATLABSystem: '<S10>/SPI Master Transfer1' */
#include "MW_c2000SPI.h"
#ifndef struct_tag_olsjGCr0ajrmZ8ELSGk4HH
#define struct_tag_olsjGCr0ajrmZ8ELSGk4HH

struct tag_olsjGCr0ajrmZ8ELSGk4HH
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  MW_Handle_Type MW_SPI_HANDLE;
};

#endif                                 /* struct_tag_olsjGCr0ajrmZ8ELSGk4HH */

#ifndef typedef_codertarget_tic2000_blocks_SPIW
#define typedef_codertarget_tic2000_blocks_SPIW

typedef struct tag_olsjGCr0ajrmZ8ELSGk4HH codertarget_tic2000_blocks_SPIW;

#endif                             /* typedef_codertarget_tic2000_blocks_SPIW */

#ifndef struct_tag_RL3bf5VyBoZJTCiPpDuhAE
#define struct_tag_RL3bf5VyBoZJTCiPpDuhAE

struct tag_RL3bf5VyBoZJTCiPpDuhAE
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  MW_Handle_Type MW_SPI_HANDLE;
};

#endif                                 /* struct_tag_RL3bf5VyBoZJTCiPpDuhAE */

#ifndef typedef_codertarget_tic2000_blocks_SPIM
#define typedef_codertarget_tic2000_blocks_SPIM

typedef struct tag_RL3bf5VyBoZJTCiPpDuhAE codertarget_tic2000_blocks_SPIM;

#endif                             /* typedef_codertarget_tic2000_blocks_SPIM */

/* Parameters (default storage) */
typedef struct Parameters_feedback_control_ Parameters_feedback_control;

/* Forward declaration for rtModel */
typedef struct tag_RTM_feedback_control RT_MODEL_feedback_control;

#endif                                 /* feedback_control_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
