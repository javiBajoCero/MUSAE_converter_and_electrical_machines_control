#include "c2000BoardSupport.h"
#include "F2806x_Device.h"
#include "F2806x_Examples.h"
#include "F2806x_GlobalPrototypes.h"
#include "rtwtypes.h"
#include "blikingled_28069M_launchpad.h"
#include "blikingled_28069M_launchpad_private.h"

void config_ADC_SOC0_SOC1(void)
{
  EALLOW;
  AdcRegs.ADCCTL2.bit.CLKDIV2EN = 1U;  /* Set ADC clock division */
  AdcRegs.ADCCTL2.bit.CLKDIV4EN = 0U;  /* Set ADC clock division */
  AdcRegs.ADCCTL2.bit.ADCNONOVERLAP = 0U;
                                 /* Set ADCNONOVERLAP contorl bit to  Allowed */
  AdcRegs.ADCSAMPLEMODE.bit.SIMULEN0 = 1U;
                                /* Simultaneous sample mode set for SOC0_SOC1.*/
  AdcRegs.ADCSOC0CTL.bit.CHSEL = 0U;
                             /* Set SOC0 channel select to ADCINA0 and ADCINB0*/
  AdcRegs.ADCSOC0CTL.bit.TRIGSEL = 5U;
  AdcRegs.ADCSOC0CTL.bit.ACQPS = (uint16_T)6.0;
                                /* Set SOC0 S/H Window to 7.0 ADC Clock Cycles*/
  AdcRegs.ADCINTSOCSEL1.bit.SOC0 = 0U;
                                   /* SOCx No ADCINT Interrupt Trigger Select.*/
  AdcRegs.ADCOFFTRIM.bit.OFFTRIM = (uint16_T)AdcRegs.ADCOFFTRIM.bit.OFFTRIM;/* Set Offset Error Correctino Value*/
  AdcRegs.ADCCTL1.bit.ADCREFSEL = 0U ; /* Set Reference Voltage*/
  AdcRegs.ADCCTL1.bit.INTPULSEPOS = 1U;
                                /* Late interrupt pulse trips AdcResults latch*/
  AdcRegs.SOCPRICTL.bit.SOCPRIORITY = 0U;/* All in round robin mode SOC Priority*/
  EDIS;
}

void config_ADC_SOC2_SOC3(void)
{
  EALLOW;
  AdcRegs.ADCCTL2.bit.CLKDIV2EN = 1U;  /* Set ADC clock division */
  AdcRegs.ADCCTL2.bit.CLKDIV4EN = 0U;  /* Set ADC clock division */
  AdcRegs.ADCCTL2.bit.ADCNONOVERLAP = 0U;
                                 /* Set ADCNONOVERLAP contorl bit to  Allowed */
  AdcRegs.ADCSAMPLEMODE.bit.SIMULEN2 = 1U;
                                /* Simultaneous sample mode set for SOC2_SOC3.*/
  AdcRegs.ADCSOC2CTL.bit.CHSEL = 1U;
                             /* Set SOC2 channel select to ADCINA1 and ADCINB1*/
  AdcRegs.ADCSOC2CTL.bit.TRIGSEL = 5U;
  AdcRegs.ADCSOC2CTL.bit.ACQPS = (uint16_T)6.0;
                                /* Set SOC2 S/H Window to 7.0 ADC Clock Cycles*/
  AdcRegs.ADCINTSOCSEL1.bit.SOC2 = 0U;
                                   /* SOCx No ADCINT Interrupt Trigger Select.*/
  AdcRegs.ADCOFFTRIM.bit.OFFTRIM = (uint16_T)AdcRegs.ADCOFFTRIM.bit.OFFTRIM;/* Set Offset Error Correctino Value*/
  AdcRegs.ADCCTL1.bit.ADCREFSEL = 0U ; /* Set Reference Voltage*/
  AdcRegs.ADCCTL1.bit.INTPULSEPOS = 1U;
                                /* Late interrupt pulse trips AdcResults latch*/
  AdcRegs.SOCPRICTL.bit.SOCPRIORITY = 0U;/* All in round robin mode SOC Priority*/
  EDIS;
}

void config_ADC_SOC4_SOC5(void)
{
  EALLOW;
  AdcRegs.ADCCTL2.bit.CLKDIV2EN = 1U;  /* Set ADC clock division */
  AdcRegs.ADCCTL2.bit.CLKDIV4EN = 0U;  /* Set ADC clock division */
  AdcRegs.ADCCTL2.bit.ADCNONOVERLAP = 0U;
                                 /* Set ADCNONOVERLAP contorl bit to  Allowed */
  AdcRegs.ADCSAMPLEMODE.bit.SIMULEN4 = 1U;
                                /* Simultaneous sample mode set for SOC4_SOC5.*/
  AdcRegs.ADCSOC4CTL.bit.CHSEL = 2U;
                             /* Set SOC4 channel select to ADCINA2 and ADCINB2*/
  AdcRegs.ADCSOC4CTL.bit.TRIGSEL = 5U;
  AdcRegs.ADCSOC4CTL.bit.ACQPS = (uint16_T)6.0;
                                /* Set SOC4 S/H Window to 7.0 ADC Clock Cycles*/
  AdcRegs.INTSEL1N2.bit.INT1E = 1U;    /* Enabled/Disable ADCINT1 interrupt*/
  AdcRegs.INTSEL1N2.bit.INT1SEL = 5U;  /* Setup EOC5 to trigger ADCINT1*/
  AdcRegs.INTSEL1N2.bit.INT1CONT = 1U;
                                     /* Enable/Disable ADCINT1 Continuous mode*/
  AdcRegs.ADCINTSOCSEL1.bit.SOC4 = 0U;
                                   /* SOCx No ADCINT Interrupt Trigger Select.*/
  AdcRegs.ADCOFFTRIM.bit.OFFTRIM = (uint16_T)AdcRegs.ADCOFFTRIM.bit.OFFTRIM;/* Set Offset Error Correctino Value*/
  AdcRegs.ADCCTL1.bit.ADCREFSEL = 0U ; /* Set Reference Voltage*/
  AdcRegs.ADCCTL1.bit.INTPULSEPOS = 1U;
                                /* Late interrupt pulse trips AdcResults latch*/
  AdcRegs.SOCPRICTL.bit.SOCPRIORITY = 0U;/* All in round robin mode SOC Priority*/
  EDIS;
}
