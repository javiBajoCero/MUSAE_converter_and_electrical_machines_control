/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: feedback_plant.h
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

#ifndef feedback_plant_h_
#define feedback_plant_h_
#ifndef feedback_plant_COMMON_INCLUDES_
#define feedback_plant_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "ext_mode.h"
#endif                                 /* feedback_plant_COMMON_INCLUDES_ */

#include <stddef.h>
#include "feedback_plant_types.h"
#include <string.h>
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetContStateDisabled
#define rtmGetContStateDisabled(rtm)   ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
#define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
#define rtmGetContStates(rtm)          ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
#define rtmSetContStates(rtm, val)     ((rtm)->contStates = (val))
#endif

#ifndef rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm) ((rtm)->CTOutputIncnstWithState)
#endif

#ifndef rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm, val) ((rtm)->CTOutputIncnstWithState = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
#define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
#define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetIntgData
#define rtmGetIntgData(rtm)            ((rtm)->intgData)
#endif

#ifndef rtmSetIntgData
#define rtmSetIntgData(rtm, val)       ((rtm)->intgData = (val))
#endif

#ifndef rtmGetOdeF
#define rtmGetOdeF(rtm)                ((rtm)->odeF)
#endif

#ifndef rtmSetOdeF
#define rtmSetOdeF(rtm, val)           ((rtm)->odeF = (val))
#endif

#ifndef rtmGetOdeY
#define rtmGetOdeY(rtm)                ((rtm)->odeY)
#endif

#ifndef rtmSetOdeY
#define rtmSetOdeY(rtm, val)           ((rtm)->odeY = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
#define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
#define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
#define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
#define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
#endif

#ifndef rtmGetRTWExtModeInfo
#define rtmGetRTWExtModeInfo(rtm)      ((rtm)->extModeInfo)
#endif

#ifndef rtmGetZCCacheNeedsReset
#define rtmGetZCCacheNeedsReset(rtm)   ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
#define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetdX
#define rtmGetdX(rtm)                  ((rtm)->derivs)
#endif

#ifndef rtmSetdX
#define rtmSetdX(rtm, val)             ((rtm)->derivs = (val))
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
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

#ifndef rtmGetTStart
#define rtmGetTStart(rtm)              ((rtm)->Timing.tStart)
#endif

/* Block signals (default storage) */
typedef struct {
  real_T Constant;                     /* '<Root>/Constant' */
  real_T Product;                      /* '<S6>/Product' */
  real_T Product1;                     /* '<S6>/Product1' */
  real_T Product2;                     /* '<S6>/Product2' */
  real_T Vrst[3];
  /* '<S5>/TmpSignal ConversionAtTAQSigLogging_InsertedFor_Three Phase Interter (Average Model)_at_outport_0Inport1' */
  real_T Add1;                         /* '<S5>/Add1' */
  real_T TransferFcn;                  /* '<S7>/Transfer Fcn' */
  real_T Sum;                          /* '<S1>/Sum' */
  real_T I;                            /* '<S1>/Transfer Fcn' */
  real_T T_Motor;                      /* '<S1>/Gain' */
  real_T Mechanical_Position;          /* '<Root>/Integrator' */
} B_feedback_plant_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  struct {
    void *LoggedData;
  } Scope1_PWORK;                      /* '<S6>/Scope1' */
} DW_feedback_plant_T;

/* Continuous states (default storage) */
typedef struct {
  real_T TransferFcn_CSTATE;           /* '<S7>/Transfer Fcn' */
  real_T TransferFcn_CSTATE_l;         /* '<S1>/Transfer Fcn' */
  real_T Integrator_CSTATE;            /* '<Root>/Integrator' */
} X_feedback_plant_T;

/* State derivatives (default storage) */
typedef struct {
  real_T TransferFcn_CSTATE;           /* '<S7>/Transfer Fcn' */
  real_T TransferFcn_CSTATE_l;         /* '<S1>/Transfer Fcn' */
  real_T Integrator_CSTATE;            /* '<Root>/Integrator' */
} XDot_feedback_plant_T;

/* State disabled  */
typedef struct {
  boolean_T TransferFcn_CSTATE;        /* '<S7>/Transfer Fcn' */
  boolean_T TransferFcn_CSTATE_l;      /* '<S1>/Transfer Fcn' */
  boolean_T Integrator_CSTATE;         /* '<Root>/Integrator' */
} XDis_feedback_plant_T;

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
} ODE3_IntgData;

#endif

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T DutyCyclesDaDbDc[3];          /* '<Root>/Duty Cycles (Da, Db, Dc)' */
} ExtU_feedback_plant_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T I;                            /* '<Root>/I' */
  real_T TransOut;                     /* '<Root>/Trans Out' */
  real_T Vdc;                          /* '<Root>/Vdc' */
} ExtY_feedback_plant_T;

/* Parameters (default storage) */
struct P_feedback_plant_T_ {
  real_T DCMotor_Kf;                   /* Mask Parameter: DCMotor_Kf
                                        * Referenced by:
                                        *   '<S1>/Gain'
                                        *   '<S1>/Gain1'
                                        */
  real_T Step_Time;                    /* Expression: 0.1
                                        * Referenced by: '<Root>/Step'
                                        */
  real_T Step_Y0;                      /* Expression: 0.6
                                        * Referenced by: '<Root>/Step'
                                        */
  real_T Step_YFinal;                  /* Expression: 0.4
                                        * Referenced by: '<Root>/Step'
                                        */
  real_T Constant1_Value;              /* Expression: 1
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T Constant2_Value;              /* Expression: 0
                                        * Referenced by: '<Root>/Constant2'
                                        */
  real_T Constant_Value;               /* Expression: 24
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T Constant_Value_n;             /* Expression: 1/2
                                        * Referenced by: '<S6>/Constant'
                                        */
  real_T TransferFcn_A;                /* Computed Parameter: TransferFcn_A
                                        * Referenced by: '<S7>/Transfer Fcn'
                                        */
  real_T TransferFcn_C;                /* Computed Parameter: TransferFcn_C
                                        * Referenced by: '<S7>/Transfer Fcn'
                                        */
  real_T TransferFcn_A_e;              /* Computed Parameter: TransferFcn_A_e
                                        * Referenced by: '<S1>/Transfer Fcn'
                                        */
  real_T TransferFcn_C_l;              /* Computed Parameter: TransferFcn_C_l
                                        * Referenced by: '<S1>/Transfer Fcn'
                                        */
  real_T Integrator_IC;                /* Expression: 0
                                        * Referenced by: '<Root>/Integrator'
                                        */
  uint16_T ManualSwitch1_CurrentSetting;
                             /* Computed Parameter: ManualSwitch1_CurrentSetting
                              * Referenced by: '<Root>/Manual Switch1'
                              */
  uint16_T ManualSwitch_CurrentSetting;
                              /* Computed Parameter: ManualSwitch_CurrentSetting
                               * Referenced by: '<Root>/Manual Switch'
                               */
};

/* Real-time Model Data Structure */
struct tag_RTM_feedback_plant_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;
  X_feedback_plant_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  XDis_feedback_plant_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeY[3];
  real_T odeF[3][3];
  ODE3_IntgData intgData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
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
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    time_T tStart;
    time_T tFinal;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block parameters (default storage) */
extern P_feedback_plant_T feedback_plant_P;

/* Block signals (default storage) */
extern B_feedback_plant_T feedback_plant_B;

/* Continuous states (default storage) */
extern X_feedback_plant_T feedback_plant_X;

/* Disabled states (default storage) */
extern XDis_feedback_plant_T feedback_plant_XDis;

/* Block states (default storage) */
extern DW_feedback_plant_T feedback_plant_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_feedback_plant_T feedback_plant_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_feedback_plant_T feedback_plant_Y;

/* Model entry point functions */
extern void feedback_plant_initialize(void);
extern void feedback_plant_step(void);
extern void feedback_plant_terminate(void);

/* Real-time Model object */
extern RT_MODEL_feedback_plant_T *const feedback_plant_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S5>/Constant' : Unused code path elimination
 * Block '<S6>/Add' : Unused code path elimination
 * Block '<S6>/Product3' : Unused code path elimination
 * Block '<S6>/Product4' : Unused code path elimination
 * Block '<S6>/Product5' : Unused code path elimination
 */

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
 * '<Root>' : 'feedback_plant'
 * '<S1>'   : 'feedback_plant/DC Motor'
 * '<S2>'   : 'feedback_plant/DC//DC Full Bridge FB Conveter'
 * '<S3>'   : 'feedback_plant/Mechanical Load'
 * '<S4>'   : 'feedback_plant/Mechanical Transducer'
 * '<S5>'   : 'feedback_plant/DC//DC Full Bridge FB Conveter/DC//DC FB Converter (Average Model)'
 * '<S6>'   : 'feedback_plant/DC//DC Full Bridge FB Conveter/DC//DC FB Converter (Average Model)/Three Phase Interter (Average Model)'
 * '<S7>'   : 'feedback_plant/Mechanical Load/Simple Inertia'
 * '<S8>'   : 'feedback_plant/Mechanical Transducer/Resolver'
 */
#endif                                 /* feedback_plant_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
