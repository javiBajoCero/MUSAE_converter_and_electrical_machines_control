#include "c2000BoardSupport.h"
#include "MW_f2837xD_includes.h"
#include "rtwtypes.h"
#include "feedback_control.h"
#include "feedback_control_private.h"

void config_ADCC_SOC0(void)
{
  EALLOW;
  AdccRegs.ADCSOC0CTL.bit.CHSEL = 2U;  /* Set SOC0 channel select to ADCIN2*/
  AdccRegs.ADCSOC0CTL.bit.TRIGSEL = 5U;
  AdccRegs.ADCSOC0CTL.bit.ACQPS = (uint16_T)14.0;
                               /* Set SOC0 S/H Window to 15.0 ADC Clock Cycles*/
  AdccRegs.ADCINTSOCSEL1.bit.SOC0 = 0U;
                                   /* SOCx No ADCINT Interrupt Trigger Select.*/
  AdccRegs.ADCOFFTRIM.bit.OFFTRIM = (uint16_T)AdccRegs.ADCOFFTRIM.bit.OFFTRIM;/* Set Offset Error Correctino Value*/
  AdccRegs.ADCCTL1.bit.INTPULSEPOS = 1U;
                                /* Late interrupt pulse trips AdcResults latch*/
  AdccRegs.ADCSOCPRICTL.bit.SOCPRIORITY = 0U;/* All in round robin mode SOC Priority*/
  EDIS;
}

void config_ADCB_SOC1(void)
{
  EALLOW;
  AdcbRegs.ADCSOC1CTL.bit.CHSEL = 2U;  /* Set SOC1 channel select to ADCIN2*/
  AdcbRegs.ADCSOC1CTL.bit.TRIGSEL = 5U;
  AdcbRegs.ADCSOC1CTL.bit.ACQPS = (uint16_T)14.0;
                               /* Set SOC1 S/H Window to 15.0 ADC Clock Cycles*/
  AdcbRegs.ADCINTSOCSEL1.bit.SOC1 = 0U;
                                   /* SOCx No ADCINT Interrupt Trigger Select.*/
  AdcbRegs.ADCOFFTRIM.bit.OFFTRIM = (uint16_T)AdcbRegs.ADCOFFTRIM.bit.OFFTRIM;/* Set Offset Error Correctino Value*/
  AdcbRegs.ADCCTL1.bit.INTPULSEPOS = 1U;
                                /* Late interrupt pulse trips AdcResults latch*/
  AdcbRegs.ADCSOCPRICTL.bit.SOCPRIORITY = 0U;/* All in round robin mode SOC Priority*/
  EDIS;
}

void config_ADCA_SOC2(void)
{
  EALLOW;
  AdcaRegs.ADCSOC2CTL.bit.CHSEL = 2U;  /* Set SOC2 channel select to ADCIN2*/
  AdcaRegs.ADCSOC2CTL.bit.TRIGSEL = 5U;
  AdcaRegs.ADCSOC2CTL.bit.ACQPS = (uint16_T)14.0;
                               /* Set SOC2 S/H Window to 15.0 ADC Clock Cycles*/
  AdcaRegs.ADCINTSOCSEL1.bit.SOC2 = 0U;
                                   /* SOCx No ADCINT Interrupt Trigger Select.*/
  AdcaRegs.ADCOFFTRIM.bit.OFFTRIM = (uint16_T)AdcaRegs.ADCOFFTRIM.bit.OFFTRIM;/* Set Offset Error Correctino Value*/
  AdcaRegs.ADCCTL1.bit.INTPULSEPOS = 1U;
                                /* Late interrupt pulse trips AdcResults latch*/
  AdcaRegs.ADCSOCPRICTL.bit.SOCPRIORITY = 0U;/* All in round robin mode SOC Priority*/
  EDIS;
}

void config_ADCA_SOC3(void)
{
  EALLOW;
  AdcaRegs.ADCSOC3CTL.bit.CHSEL = 3U;  /* Set SOC3 channel select to ADCIN3*/
  AdcaRegs.ADCSOC3CTL.bit.TRIGSEL = 5U;
  AdcaRegs.ADCSOC3CTL.bit.ACQPS = (uint16_T)14.0;
                               /* Set SOC3 S/H Window to 15.0 ADC Clock Cycles*/
  AdcaRegs.ADCINTSEL1N2.bit.INT1E = 1U;/* Enabled/Disable ADCINT1 interrupt*/
  AdcaRegs.ADCINTSEL1N2.bit.INT1SEL = 3U;/* Setup EOC3 to trigger ADCINT1*/
  AdcaRegs.ADCINTSEL1N2.bit.INT1CONT = 1U;
                                     /* Enable/Disable ADCINT1 Continuous mode*/
  AdcaRegs.ADCINTSOCSEL1.bit.SOC3 = 0U;
                                   /* SOCx No ADCINT Interrupt Trigger Select.*/
  AdcaRegs.ADCOFFTRIM.bit.OFFTRIM = (uint16_T)AdcaRegs.ADCOFFTRIM.bit.OFFTRIM;/* Set Offset Error Correctino Value*/
  AdcaRegs.ADCCTL1.bit.INTPULSEPOS = 1U;
                                /* Late interrupt pulse trips AdcResults latch*/
  AdcaRegs.ADCSOCPRICTL.bit.SOCPRIORITY = 0U;/* All in round robin mode SOC Priority*/
  EDIS;
}

void InitAdcA(void)
{
  EALLOW;
  CpuSysRegs.PCLKCR13.bit.ADC_A = 1U;
  AdcaRegs.ADCCTL2.bit.PRESCALE = 8U;
  AdcSetMode((uint16_T)ADC_ADCA, (uint16_T)ADC_RESOLUTION_12BIT,(uint16_T)
             ADC_SIGNALMODE_SINGLE);

  //power up the ADC
  AdcaRegs.ADCCTL1.bit.ADCPWDNZ = 1U;

  //delay for 1ms to allow ADC time to power up
  DELAY_US(1000);
  EDIS;
}

void InitAdcB(void)
{
  EALLOW;
  CpuSysRegs.PCLKCR13.bit.ADC_B = 1U;
  AdcbRegs.ADCCTL2.bit.PRESCALE = 8U;
  AdcSetMode((uint16_T)ADC_ADCB, (uint16_T)ADC_RESOLUTION_12BIT,(uint16_T)
             ADC_SIGNALMODE_SINGLE);

  //power up the ADC
  AdcbRegs.ADCCTL1.bit.ADCPWDNZ = 1U;

  //delay for 1ms to allow ADC time to power up
  DELAY_US(1000);
  EDIS;
}

void InitAdcC(void)
{
  EALLOW;
  CpuSysRegs.PCLKCR13.bit.ADC_C = 1U;
  AdccRegs.ADCCTL2.bit.PRESCALE = 8U;
  AdcSetMode((uint16_T)ADC_ADCC, (uint16_T)ADC_RESOLUTION_12BIT,(uint16_T)
             ADC_SIGNALMODE_SINGLE);

  //power up the ADC
  AdccRegs.ADCCTL1.bit.ADCPWDNZ = 1U;

  //delay for 1ms to allow ADC time to power up
  DELAY_US(1000);
  EDIS;
}
