/*
 * blikingled_28069M_launchpad.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "blikingled_28069M_launchpad".
 *
 * Model version              : 1.9
 * Simulink Coder version : 9.9 (R2023a) 19-Nov-2022
 * C source code generated on : Mon Mar  4 15:44:03 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_blikingled_28069M_launchpad_h_
#define RTW_HEADER_blikingled_28069M_launchpad_h_
#ifndef blikingled_28069M_launchpad_COMMON_INCLUDES_
#define blikingled_28069M_launchpad_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "ext_mode.h"
#include "c2000BoardSupport.h"
#include "F2806x_Device.h"
#include "F2806x_Gpio.h"
#endif                        /* blikingled_28069M_launchpad_COMMON_INCLUDES_ */

#include "blikingled_28069M_launchpad_types.h"
#include <string.h>
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWExtModeInfo
#define rtmGetRTWExtModeInfo(rtm)      ((rtm)->extModeInfo)
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                (&(rtm)->Timing.taskTime0)
#endif

/* Block signals (default storage) */
typedef struct {
  real_T enabledisableeachsecond;      /* '<Root>/enable disable each second' */
  boolean_T NOT;                       /* '<Root>/NOT' */
} B_blikingled_28069M_launchpad_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<Root>/Scope' */

  int32_T clockTickCounter;            /* '<Root>/RED_LED' */
  int32_T clockTickCounter_g;          /* '<Root>/enable disable each second' */
  int32_T DigitalOutput_FRAC_LEN;      /* '<Root>/Digital Output' */
} DW_blikingled_28069M_launchpa_T;

/* Parameters (default storage) */
struct P_blikingled_28069M_launchpad_T_ {
  real_T RED_LED_Amp;                  /* Expression: 1
                                        * Referenced by: '<Root>/RED_LED'
                                        */
  real_T RED_LED_Period;               /* Computed Parameter: RED_LED_Period
                                        * Referenced by: '<Root>/RED_LED'
                                        */
  real_T RED_LED_Duty;                 /* Computed Parameter: RED_LED_Duty
                                        * Referenced by: '<Root>/RED_LED'
                                        */
  real_T RED_LED_PhaseDelay;           /* Expression: 0
                                        * Referenced by: '<Root>/RED_LED'
                                        */
  real_T enabledisableeachsecond_Amp;  /* Expression: 1
                                        * Referenced by: '<Root>/enable disable each second'
                                        */
  real_T enabledisableeachsecond_Period;
                           /* Computed Parameter: enabledisableeachsecond_Period
                            * Referenced by: '<Root>/enable disable each second'
                            */
  real_T enabledisableeachsecond_Duty;
                             /* Computed Parameter: enabledisableeachsecond_Duty
                              * Referenced by: '<Root>/enable disable each second'
                              */
  real_T enabledisableeachsecond_PhaseDe;/* Expression: 0
                                          * Referenced by: '<Root>/enable disable each second'
                                          */
};

/* Real-time Model Data Structure */
struct tag_RTM_blikingled_28069M_lau_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    struct {
      uint16_T TID[2];
    } TaskCounters;

    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (default storage) */
extern P_blikingled_28069M_launchpad_T blikingled_28069M_launchpad_P;

/* Block signals (default storage) */
extern B_blikingled_28069M_launchpad_T blikingled_28069M_launchpad_B;

/* Block states (default storage) */
extern DW_blikingled_28069M_launchpa_T blikingled_28069M_launchpad_DW;

/* Model entry point functions */
extern void blikingled_28069M_launchpad_initialize(void);
extern void blikingled_28069M_launchpad_step(void);
extern void blikingled_28069M_launchpad_terminate(void);

/* Real-time Model object */
extern RT_MODEL_blikingled_28069M_la_T *const blikingled_28069M_launchpad_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'blikingled_28069M_launchpad'
 */
#endif                           /* RTW_HEADER_blikingled_28069M_launchpad_h_ */
