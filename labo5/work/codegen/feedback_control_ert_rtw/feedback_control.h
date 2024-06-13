/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: feedback_control.h
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

#ifndef feedback_control_h_
#define feedback_control_h_
#ifndef feedback_control_COMMON_INCLUDES_
#define feedback_control_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "c2000BoardSupport.h"
#include "MW_f2837xD_includes.h"
#include "IQmathLib.h"
#include "MW_c2000DAC.h"
#include "MW_SPI.h"
#endif                                 /* feedback_control_COMMON_INCLUDES_ */

#include <stddef.h>
#include "feedback_control_types.h"
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

#ifndef rtmStepTask
#define rtmStepTask(rtm, idx)          ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
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

#ifndef rtmTaskCounter
#define rtmTaskCounter(rtm, idx)       ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

extern void config_ePWMSyncSource(void);
extern void config_ePWM_GPIO (void);
extern void config_ePWM_TBSync (void);
extern void config_ePWM_XBAR(void);

/* Block signals (default storage) */
typedef struct {
  uint32_T Times_Interrupt;            /* '<S16>/Add' */
  real32_T SumofElements;              /* '<S24>/Sum of Elements' */
  real32_T V_Ref;                      /* '<S5>/V_Ref' */
  real32_T I_Reference;                /* '<S5>/Variant Source' */
  real32_T Gain1;                      /* '<S20>/Gain1' */
  uint16_T TmpRTBAtThreePhaseConverterCont;/* '<Root>/Enable' */
  uint16_T SPIMasterTransfer1;         /* '<S10>/SPI Master Transfer1' */
  uint16_T Add1;                       /* '<S7>/Add1' */
  uint16_T SPITransmit;                /* '<S7>/SPI Transmit' */
  uint16_T ADC;                        /* '<S19>/ADC' */
  uint16_T ADC3;                       /* '<S19>/ADC3' */
  uint16_T ADC1;                       /* '<S19>/ADC1' */
  uint16_T ADC2;                       /* '<S19>/ADC2' */
  uint16_T eQEP_o1;                    /* '<S25>/eQEP' */
  uint16_T eQEP_o2;                    /* '<S25>/eQEP' */
} BlockIO_feedback_control;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_tic2000_blocks_SPIW obj; /* '<S7>/SPI Transmit' */
  codertarget_tic2000_blocks_SPIM obj_i;/* '<S10>/SPI Master Transfer1' */
  real32_T UnitDelay_DSTATE;           /* '<S24>/Unit Delay' */
  real32_T UnitDelay_DSTATE_g;         /* '<S13>/Unit Delay' */
  real32_T UnitDelay1_DSTATE;          /* '<S13>/Unit Delay1' */
  uint32_T UnitDelay1_DSTATE_h;        /* '<S16>/Unit Delay1' */
  int32_T DigitalOutput1_FRAC_LEN;     /* '<S3>/Digital Output1' */
  int32_T DigitalOutput_FRAC_LEN;      /* '<S17>/Digital Output' */
  uint16_T DelayInput1_DSTATE;         /* '<S6>/Delay Input1' */
  uint16_T Ticks;                      /* '<S7>/Unit Delay' */
  volatile uint16_T TmpRTBAtThreePhaseConverterCont;/* synthesized block */
  int16_T Subsystem_SubsysRanBC;       /* '<S1>/Subsystem' */
  int16_T ThreePhaseConverterControl_Subs;
                                    /* '<Root>/Three Phase Converter Control' */
  int16_T PositionResetAtIndex_SubsysRanB;/* '<S30>/PositionResetAtIndex' */
  int16_T PositionNoReset_SubsysRanBC; /* '<S30>/PositionNoReset' */
  int16_T IfActionSubsystem1_SubsysRanBC;/* '<S33>/If Action Subsystem1' */
  int16_T IfActionSubsystem_SubsysRanBC;/* '<S33>/If Action Subsystem' */
} D_Work_feedback_control;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real32_T Feedback[3];                /* '<Root>/Feedback' */
} ExternalInputs_feedback_control;

/* Parameters (default storage) */
struct Parameters_feedback_control_ {
  real32_T Calibrate_Vdc_Gain;         /* Mask Parameter: Calibrate_Vdc_Gain
                                        * Referenced by: '<S23>/Gain1'
                                        */
  real32_T Calibrate_Ir_Gain;          /* Mask Parameter: Calibrate_Ir_Gain
                                        * Referenced by: '<S20>/Gain1'
                                        */
  real32_T AdaptDAC1_Gain;             /* Mask Parameter: AdaptDAC1_Gain
                                        * Referenced by: '<S12>/Gain2'
                                        */
  real32_T AdaptDAC_Gain;              /* Mask Parameter: AdaptDAC_Gain
                                        * Referenced by: '<S11>/Gain2'
                                        */
  real32_T Calibrate_Vdc_Offset;       /* Mask Parameter: Calibrate_Vdc_Offset
                                        * Referenced by: '<S23>/Offset'
                                        */
  real32_T Calibrate_Ir_Offset;        /* Mask Parameter: Calibrate_Ir_Offset
                                        * Referenced by: '<S20>/Offset'
                                        */
  real32_T AdaptDAC1_Offset;           /* Mask Parameter: AdaptDAC1_Offset
                                        * Referenced by: '<S12>/Offset'
                                        */
  real32_T AdaptDAC_Offset;            /* Mask Parameter: AdaptDAC_Offset
                                        * Referenced by: '<S11>/Offset'
                                        */
  uint16_T DetectChange_vinit;         /* Mask Parameter: DetectChange_vinit
                                        * Referenced by: '<S6>/Delay Input1'
                                        */
  real32_T Gain2_Gain;                 /* Computed Parameter: Gain2_Gain
                                        * Referenced by: '<S13>/Gain2'
                                        */
  real32_T Constant_Value;             /* Computed Parameter: Constant_Value
                                        * Referenced by: '<S35>/Constant'
                                        */
  real32_T Constant1_Value;            /* Computed Parameter: Constant1_Value
                                        * Referenced by: '<S32>/Constant1'
                                        */
  real32_T ReplaceInport_Offset_Value;
                               /* Computed Parameter: ReplaceInport_Offset_Value
                                * Referenced by: '<S29>/ReplaceInport_Offset'
                                */
  real32_T Constant3_Value;            /* Computed Parameter: Constant3_Value
                                        * Referenced by: '<S16>/Constant3'
                                        */
  real32_T Constant4_Value;            /* Computed Parameter: Constant4_Value
                                        * Referenced by: '<S16>/Constant4'
                                        */
  real32_T Constant2_Value;            /* Computed Parameter: Constant2_Value
                                        * Referenced by: '<S15>/Constant2'
                                        */
  real32_T Gain1_Gain;                 /* Computed Parameter: Gain1_Gain
                                        * Referenced by: '<S15>/Gain1'
                                        */
  real32_T Constant3_Value_l;          /* Computed Parameter: Constant3_Value_l
                                        * Referenced by: '<S15>/Constant3'
                                        */
  real32_T Constant4_Value_f;          /* Computed Parameter: Constant4_Value_f
                                        * Referenced by: '<S5>/Constant4'
                                        */
  real32_T Constant1_Value_i;          /* Computed Parameter: Constant1_Value_i
                                        * Referenced by: '<S15>/Constant1'
                                        */
  real32_T Period_Gain;                /* Computed Parameter: Period_Gain
                                        * Referenced by: '<S17>/Period'
                                        */
  real32_T Constant2_Value_a[3];       /* Computed Parameter: Constant2_Value_a
                                        * Referenced by: '<S17>/Constant2'
                                        */
  real32_T UnitDelay_InitialCondition;
                               /* Computed Parameter: UnitDelay_InitialCondition
                                * Referenced by: '<S24>/Unit Delay'
                                */
  real32_T V_Ref_Value;                /* Computed Parameter: V_Ref_Value
                                        * Referenced by: '<S5>/V_Ref'
                                        */
  real32_T Gain_Gain;                  /* Computed Parameter: Gain_Gain
                                        * Referenced by: '<S13>/Gain'
                                        */
  real32_T UnitDelay_InitialCondition_c;
                             /* Computed Parameter: UnitDelay_InitialCondition_c
                              * Referenced by: '<S13>/Unit Delay'
                              */
  real32_T Gain1_Gain_c;               /* Computed Parameter: Gain1_Gain_c
                                        * Referenced by: '<S13>/Gain1'
                                        */
  real32_T UnitDelay1_InitialCondition;
                              /* Computed Parameter: UnitDelay1_InitialCondition
                               * Referenced by: '<S13>/Unit Delay1'
                               */
  real32_T Constant1_Value_c;          /* Computed Parameter: Constant1_Value_c
                                        * Referenced by: '<S17>/Constant1'
                                        */
  real32_T Constant_Value_o;           /* Computed Parameter: Constant_Value_o
                                        * Referenced by: '<S46>/Constant'
                                        */
  real32_T Constant_Value_d;           /* Computed Parameter: Constant_Value_d
                                        * Referenced by: '<S3>/Constant'
                                        */
  uint32_T Constant_Value_n;           /* Computed Parameter: Constant_Value_n
                                        * Referenced by: '<S16>/Constant'
                                        */
  uint32_T UnitDelay1_InitialCondition_m;
                            /* Computed Parameter: UnitDelay1_InitialCondition_m
                             * Referenced by: '<S16>/Unit Delay1'
                             */
  uint32_T Constant1_Value_j;          /* Computed Parameter: Constant1_Value_j
                                        * Referenced by: '<S16>/Constant1'
                                        */
  uint32_T Constant2_Value_h;          /* Computed Parameter: Constant2_Value_h
                                        * Referenced by: '<S16>/Constant2'
                                        */
  uint32_T Switch_Threshold;           /* Computed Parameter: Switch_Threshold
                                        * Referenced by: '<S16>/Switch'
                                        */
  int16_T ResetMode_Value;             /* Computed Parameter: ResetMode_Value
                                        * Referenced by: '<S30>/ResetMode'
                                        */
  uint16_T Constant_Value_m;           /* Computed Parameter: Constant_Value_m
                                        * Referenced by: '<S45>/Constant'
                                        */
  uint16_T Constant_Value_e;           /* Computed Parameter: Constant_Value_e
                                        * Referenced by: '<S7>/Constant'
                                        */
  uint16_T Constant1_Value_iy;         /* Computed Parameter: Constant1_Value_iy
                                        * Referenced by: '<S7>/Constant1'
                                        */
  uint16_T Ticks_Y0;                   /* Computed Parameter: Ticks_Y0
                                        * Referenced by: '<S7>/Ticks'
                                        */
  uint16_T Status_Y0;                  /* Computed Parameter: Status_Y0
                                        * Referenced by: '<S7>/Status'
                                        */
  uint16_T Inc_Value;                  /* Computed Parameter: Inc_Value
                                        * Referenced by: '<S7>/Inc'
                                        */
  uint16_T UnitDelay_InitialCondition_l;
                             /* Computed Parameter: UnitDelay_InitialCondition_l
                              * Referenced by: '<S7>/Unit Delay'
                              */
  uint16_T Switch_Threshold_p;         /* Computed Parameter: Switch_Threshold_p
                                        * Referenced by: '<S7>/Switch'
                                        */
  uint16_T Gain_Gain_m;                /* Computed Parameter: Gain_Gain_m
                                        * Referenced by: '<S7>/Gain'
                                        */
  uint16_T ADC_Gain_Setting_Value;     /* Expression: 0x503F
                                        * Referenced by: '<S10>/ADC_Gain_Setting'
                                        */
  uint16_T Enable_Value;               /* Computed Parameter: Enable_Value
                                        * Referenced by: '<Root>/Enable'
                                        */
  uint16_T Address_Value;              /* Computed Parameter: Address_Value
                                        * Referenced by: '<S1>/Address'
                                        */
  uint16_T WriteRead_Value;            /* Computed Parameter: WriteRead_Value
                                        * Referenced by: '<S1>/Write//Read'
                                        */
  uint16_T WriteRead1_Value;           /* Computed Parameter: WriteRead1_Value
                                        * Referenced by: '<S1>/Write//Read1'
                                        */
  uint16_T TmpRTBAtThreePhaseConverterCont;
                          /* Computed Parameter: TmpRTBAtThreePhaseConverterCont
                           * Referenced by:
                           */
  uint16_T ManualSwitch_CurrentSetting;
                              /* Computed Parameter: ManualSwitch_CurrentSetting
                               * Referenced by: '<S5>/Manual Switch'
                               */
  uint16_T ManualSwitch_CurrentSetting_d;
                            /* Computed Parameter: ManualSwitch_CurrentSetting_d
                             * Referenced by: '<S15>/Manual Switch'
                             */
  uint16_T ManualSwitch_CurrentSetting_j;
                            /* Computed Parameter: ManualSwitch_CurrentSetting_j
                             * Referenced by: '<S17>/Manual Switch'
                             */
  uint16_T Constant_Value_ei;          /* Computed Parameter: Constant_Value_ei
                                        * Referenced by: '<S32>/Constant'
                                        */
  uint16_T Switch_Threshold_f;         /* Computed Parameter: Switch_Threshold_f
                                        * Referenced by: '<S32>/Switch'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_feedback_control {
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
    uint16_T rtmL2HLastBufWr;
    uint32_T rtmL2HDbBufClockTick[2];
    uint32_T clockTick1;
    uint32_T clockTick2;
    uint32_T clockTick3;
    uint16_T rtmDbBufReadBuf3;
    uint16_T rtmDbBufWriteBuf3;
    boolean_T rtmDbBufLastBufWr3;
    uint32_T rtmDbBufClockTick3[2];
    struct {
      uint16_T TID[2];
    } TaskCounters;

    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (default storage) */
extern Parameters_feedback_control feedback_control_P;

/* Block signals (default storage) */
extern BlockIO_feedback_control feedback_control_B;

/* Block states (default storage) */
extern D_Work_feedback_control feedback_control_DWork;

/* External inputs (root inport signals with default storage) */
extern ExternalInputs_feedback_control feedback_control_U;

/* External function called from main */
extern void feedback_control_SetEventsForThisBaseStep(boolean_T *eventFlags);

/* Model entry point functions */
extern void feedback_control_initialize(void);
extern void feedback_control_step0(void);
extern void feedback_control_step1(void);
extern void feedback_control_terminate(void);
extern volatile boolean_T runModel;

/* Real-time Model object */
extern RT_MODEL_feedback_control *const feedback_control_M;
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
 * '<Root>' : 'feedback_control'
 * '<S1>'   : 'feedback_control/Gain Control'
 * '<S2>'   : 'feedback_control/Hardware Init'
 * '<S3>'   : 'feedback_control/LED Flashing'
 * '<S4>'   : 'feedback_control/Operator Terminal'
 * '<S5>'   : 'feedback_control/Three Phase Converter Control'
 * '<S6>'   : 'feedback_control/Gain Control/Detect Change'
 * '<S7>'   : 'feedback_control/Gain Control/Subsystem'
 * '<S8>'   : 'feedback_control/Hardware Init/HW_Init'
 * '<S9>'   : 'feedback_control/Hardware Init/HW_Init/HW_Init (Codegen)'
 * '<S10>'  : 'feedback_control/Hardware Init/HW_Init/HW_Init (Codegen)/Enable DRV8305 for motor 1'
 * '<S11>'  : 'feedback_control/Three Phase Converter Control/Adapt DAC'
 * '<S12>'  : 'feedback_control/Three Phase Converter Control/Adapt DAC1'
 * '<S13>'  : 'feedback_control/Three Phase Converter Control/Digital PID'
 * '<S14>'  : 'feedback_control/Three Phase Converter Control/Feedback'
 * '<S15>'  : 'feedback_control/Three Phase Converter Control/Full Bridge TF'
 * '<S16>'  : 'feedback_control/Three Phase Converter Control/Squar Wave Generator'
 * '<S17>'  : 'feedback_control/Three Phase Converter Control/Three-phase Inverter'
 * '<S18>'  : 'feedback_control/Three Phase Converter Control/Digital PID/Saturation Dynamic'
 * '<S19>'  : 'feedback_control/Three Phase Converter Control/Feedback/ADC Channels'
 * '<S20>'  : 'feedback_control/Three Phase Converter Control/Feedback/ADC Channels/Calibrate_Ir'
 * '<S21>'  : 'feedback_control/Three Phase Converter Control/Feedback/ADC Channels/Calibrate_Is'
 * '<S22>'  : 'feedback_control/Three Phase Converter Control/Feedback/ADC Channels/Calibrate_It'
 * '<S23>'  : 'feedback_control/Three Phase Converter Control/Feedback/ADC Channels/Calibrate_Vdc'
 * '<S24>'  : 'feedback_control/Three Phase Converter Control/Feedback/ADC Channels/Moving Average Filter1'
 * '<S25>'  : 'feedback_control/Three Phase Converter Control/Feedback/ADC Channels/Position Measurement'
 * '<S26>'  : 'feedback_control/Three Phase Converter Control/Feedback/ADC Channels/w calculation'
 * '<S27>'  : 'feedback_control/Three Phase Converter Control/Feedback/ADC Channels/Position Measurement/Calculate Position from QEP count '
 * '<S28>'  : 'feedback_control/Three Phase Converter Control/Feedback/ADC Channels/Position Measurement/Calculate Position from QEP count /eQEP_Decoder'
 * '<S29>'  : 'feedback_control/Three Phase Converter Control/Feedback/ADC Channels/Position Measurement/Calculate Position from QEP count /eQEP_Decoder/Mechanical to Electrical Position'
 * '<S30>'  : 'feedback_control/Three Phase Converter Control/Feedback/ADC Channels/Position Measurement/Calculate Position from QEP count /eQEP_Decoder/Quadrature Decoder'
 * '<S31>'  : 'feedback_control/Three Phase Converter Control/Feedback/ADC Channels/Position Measurement/Calculate Position from QEP count /eQEP_Decoder/Mechanical to Electrical Position/MechToElec'
 * '<S32>'  : 'feedback_control/Three Phase Converter Control/Feedback/ADC Channels/Position Measurement/Calculate Position from QEP count /eQEP_Decoder/Mechanical to Electrical Position/MechToElec/floating-point'
 * '<S33>'  : 'feedback_control/Three Phase Converter Control/Feedback/ADC Channels/Position Measurement/Calculate Position from QEP count /eQEP_Decoder/Mechanical to Electrical Position/MechToElec/floating-point/Compensate Offset'
 * '<S34>'  : 'feedback_control/Three Phase Converter Control/Feedback/ADC Channels/Position Measurement/Calculate Position from QEP count /eQEP_Decoder/Mechanical to Electrical Position/MechToElec/floating-point/Mech To Elec'
 * '<S35>'  : 'feedback_control/Three Phase Converter Control/Feedback/ADC Channels/Position Measurement/Calculate Position from QEP count /eQEP_Decoder/Mechanical to Electrical Position/MechToElec/floating-point/Compensate Offset/If Action Subsystem'
 * '<S36>'  : 'feedback_control/Three Phase Converter Control/Feedback/ADC Channels/Position Measurement/Calculate Position from QEP count /eQEP_Decoder/Mechanical to Electrical Position/MechToElec/floating-point/Compensate Offset/If Action Subsystem1'
 * '<S37>'  : 'feedback_control/Three Phase Converter Control/Feedback/ADC Channels/Position Measurement/Calculate Position from QEP count /eQEP_Decoder/Mechanical to Electrical Position/MechToElec/floating-point/Mech To Elec/Variant Subsystem'
 * '<S38>'  : 'feedback_control/Three Phase Converter Control/Feedback/ADC Channels/Position Measurement/Calculate Position from QEP count /eQEP_Decoder/Mechanical to Electrical Position/MechToElec/floating-point/Mech To Elec/Variant Subsystem/Dialog'
 * '<S39>'  : 'feedback_control/Three Phase Converter Control/Feedback/ADC Channels/Position Measurement/Calculate Position from QEP count /eQEP_Decoder/Quadrature Decoder/DT_Handle'
 * '<S40>'  : 'feedback_control/Three Phase Converter Control/Feedback/ADC Channels/Position Measurement/Calculate Position from QEP count /eQEP_Decoder/Quadrature Decoder/PositionNoReset'
 * '<S41>'  : 'feedback_control/Three Phase Converter Control/Feedback/ADC Channels/Position Measurement/Calculate Position from QEP count /eQEP_Decoder/Quadrature Decoder/PositionResetAtIndex'
 * '<S42>'  : 'feedback_control/Three Phase Converter Control/Feedback/ADC Channels/Position Measurement/Calculate Position from QEP count /eQEP_Decoder/Quadrature Decoder/Variant Subsystem'
 * '<S43>'  : 'feedback_control/Three Phase Converter Control/Feedback/ADC Channels/Position Measurement/Calculate Position from QEP count /eQEP_Decoder/Quadrature Decoder/DT_Handle/floating-point'
 * '<S44>'  : 'feedback_control/Three Phase Converter Control/Feedback/ADC Channels/Position Measurement/Calculate Position from QEP count /eQEP_Decoder/Quadrature Decoder/PositionNoReset/Variant Subsystem'
 * '<S45>'  : 'feedback_control/Three Phase Converter Control/Feedback/ADC Channels/Position Measurement/Calculate Position from QEP count /eQEP_Decoder/Quadrature Decoder/PositionNoReset/Variant Subsystem/Dialog'
 * '<S46>'  : 'feedback_control/Three Phase Converter Control/Feedback/ADC Channels/Position Measurement/Calculate Position from QEP count /eQEP_Decoder/Quadrature Decoder/Variant Subsystem/Dialog'
 */
#endif                                 /* feedback_control_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
