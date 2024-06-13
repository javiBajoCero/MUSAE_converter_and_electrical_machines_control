/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: feedback_control_private.h
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

#ifndef feedback_control_private_h_
#define feedback_control_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "feedback_control_types.h"
#include "feedback_control.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmSetTFinal
#define rtmSetTFinal(rtm, val)         ((rtm)->Timing.tFinal = (val))
#endif

void config_QEP_eQEP1(uint32_T pcmaximumvalue, uint32_T pcInitialvalue, uint32_T
                      unittimerperiod, uint32_T comparevalue, uint16_T
                      watchdogtimer, uint16_T qdecctl, uint16_T qepctl, uint16_T
                      qposctl, uint16_T qcapctl, uint16_T qeint);
void InitAdcC (void);
void config_ADCC_SOC0 (void);
void InitAdcA (void);
void config_ADCA_SOC3 (void);
void InitAdcB (void);
void config_ADCB_SOC1 (void);
void config_ADCA_SOC2 (void);
extern uint16_T MW_adcCInitFlag;
extern uint16_T MW_adcAInitFlag;
extern uint16_T MW_adcBInitFlag;
void isr_int1pie1_task_fcn(void);
extern void configureGPIOExtInterrupt(void);
void isr_int1pie1_task_fcn(void);

#endif                                 /* feedback_control_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
