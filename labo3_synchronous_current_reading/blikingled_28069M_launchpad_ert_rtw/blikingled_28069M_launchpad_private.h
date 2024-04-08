/*
 * blikingled_28069M_launchpad_private.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "blikingled_28069M_launchpad".
 *
 * Model version              : 1.25
 * Simulink Coder version : 9.9 (R2023a) 19-Nov-2022
 * C source code generated on : Mon Apr  8 18:08:58 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_blikingled_28069M_launchpad_private_h_
#define RTW_HEADER_blikingled_28069M_launchpad_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "blikingled_28069M_launchpad_types.h"
#include "blikingled_28069M_launchpad.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmIsMajorTimeStep
#define rtmIsMajorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
#define rtmIsMinorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmSetTFinal
#define rtmSetTFinal(rtm, val)         ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmSetTPtr
#define rtmSetTPtr(rtm, val)           ((rtm)->Timing.t = (val))
#endif

void InitAdc (void);
void config_ADC_SOC0_SOC1 (void);
void config_ADC_SOC2_SOC3 (void);
void config_ADC_SOC4_SOC5 (void);
extern uint16_T MW_adcInitFlag;
void isr_int1pie1_task_fcn(void);
extern void configureGPIOExtInterrupt(void);
void isr_int1pie1_task_fcn(void);

#endif                   /* RTW_HEADER_blikingled_28069M_launchpad_private_h_ */
