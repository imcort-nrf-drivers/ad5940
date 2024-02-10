#ifndef _AD5940_CONFIG_H__
#define _AD5940_CONFIG_H__

//*** <<< Use Configuration Wizard in Context Menu >>> ***

// <h> CLKCfg

    // <o> SysClkSrc
    
        // <0=> SYSCLKSRC_HFOSC
        // <1=> SYSCLKSRC_XTAL
        // <2=> SYSCLKSRC_LFOSC
        // <3=> SYSCLKSRC_EXT
        #define AD5940_Cfg_SysClkSrc 3
    
    // <o> ADCCLkSrc
     
        // <0=> ADCCLKSRC_HFOSC
        // <1=> ADCCLKSRC_XTAL
        // <3=> ADCCLKSRC_EXT
        #define AD5940_Cfg_ADCCLkSrc 3
        
    // <o> SysClkDiv
    
        // <1=> SYSCLKDIV_1 
        // <2=> SYSCLKDIV_2
        #define AD5940_Cfg_SysClkDiv 1
        
    // <o> ADCClkDiv
         
        // <1=> ADCCLKDIV_1 
        // <2=> ADCCLKDIV_2
        #define AD5940_Cfg_ADCClkDiv 1
    
    // <q> HFOSCEn
        #define AD5940_Cfg_HFOSCEn 1
        
    // <q> HfOSC32MHzMode
        #define AD5940_Cfg_HfOSC32MHzMode 1
        
    // <q> LFOSCEn
        #define AD5940_Cfg_LFOSCEn 1
        
    // <q> HFXTALEn
        #define AD5940_Cfg_HFXTALEn 1
    
// </h>

// <h> AFERefCfg

// <h> ADC/DAC/TIA reference and buffer
    // <q> HpBandgapEn
    // <i> Enable High power band-gap. Clear bit AFECON.HPREFDIS will enable Bandgap, while set this bit will disable bandgap
        #define AD5940_Cfg_HpBandgapEn 1
        
    // <q> Hp1V8BuffEn
    // <i> High power 1.8V reference buffer enable
        #define AD5940_Cfg_Hp1V8BuffEn 1
        
    // <q> Hp1V1BuffEn
    // <i> High power 1.1V reference buffer enable
        #define AD5940_Cfg_Hp1V1BuffEn 1
        
    // <q> Lp1V8BuffEn
    // <i> Low power 1.8V reference buffer enable
        #define AD5940_Cfg_Lp1V8BuffEn 1
        
    // <q> Lp1V1BuffEn
    // <i> Low power 1.1V reference buffer enable
        #define AD5940_Cfg_Lp1V1BuffEn 1
// </h> 
// <h> Low bandwidth loop reference and buffer
    // <q> LpBandgapEn
    // <i> Enable Low power band-gap.
        #define AD5940_Cfg_LpBandgapEn 1
        
    // <q> LpRefBufEn
    // <i> Enable the 2.5V low power reference buffer
        #define AD5940_Cfg_LpRefBufEn 1
        
    // <q> LpRefBoostEn
    // <i> Boost buffer current
        #define AD5940_Cfg_LpRefBoostEn 1
// </h> 
// <h> DAC Reference Buffer
    // <q> HSDACRefEn
    // <i> Enable DAC reference buffer from HP Bandgap
        #define AD5940_Cfg_HSDACRefEn 1
// </h> 
// <h> Misc. control
    // <q> Hp1V8ThemBuff
    // <i> Thermal Buffer for internal 1.8V reference to AIN3 pin
        #define AD5940_Cfg_Hp1V8ThemBuff 1
        
    // <q> Hp1V8Ilimit
    // <i> Current limit for High power 1.8V reference buffer
        #define AD5940_Cfg_Hp1V8Ilimit 1
        
    // <q> Disc1V8Cap 
    // <i> Discharge 1.8V capacitor. Short external 1.8V decouple capacitor to ground. Be careful when use this bit
        #define AD5940_Cfg_Disc1V8Cap 0
        
    // <q> Disc1V1Cap
    // <i> Discharge 1.1V capacitor. Short external 1.1V decouple capacitor to ground. Be careful when use this bit
        #define AD5940_Cfg_Disc1V1Cap 0
// </h> 
// </h> 

// <h> HSLoopCfg

// <h> SWMatrixCfg
    
    // <h> Dswitch
        // <q.0> SWD_RCAL0
        // <q.1> SWD_AIN1
        // <q.2> SWD_AIN2
        // <q.3> SWD_AIN3
        // <q.4> SWD_CE0
        // <q.5> SWD_AFE1
        // <q.6> SWD_SE0
        // <q.7> SWD_AFE3
        #define AD5940_Cfg_Dswitch 0x2A
    // </h> 
    
    // <h> Pswitch
        // <q.0> SWP_RCAL0
        // <q.1> SWP_AIN1
        // <q.2> SWP_AIN2
        // <q.3> SWP_AIN3
        // <q.4> SWP_RE0
        // <q.5> SWP_AFE2
        // <q.6> SWP_SE0
        // <q.7> SWP_DE0
        // <q.8> SWP_AFE3
        // <q.9> SWP_DE1
        // <q.10> SWP_CE0
        // <q.11> SWP_AFE1
        // <q.13> SWP_PL
        // <q.14> SWP_PL2
        #define AD5940_Cfg_Pswitch 0x4000
    // </h> 
    
    // <h> Nswitch
        // <q.0> SWN_AIN0
        // <q.1> SWN_AIN1
        // <q.2> SWN_AIN2
        // <q.3> SWN_AIN3
        // <q.4> SWN_SE0LOAD
        // <q.5> SWN_DE0LOAD
        // <q.6> SWN_AFE3LOAD
        // <q.8> SWN_SE0
        // <q.9> SWN_RCAL1
        // <q.10> SWN_NL
        // <q.11> SWN_NL2
        #define AD5940_Cfg_Nswitch 0x2A
    // </h> 
    
    // <h> Tswitch
        // <q.0> SWT_AIN0
        // <q.1> SWT_AIN1
        // <q.2> SWT_AIN2
        // <q.3> SWT_AIN3
        // <q.4> SWT_SE0LOAD
        // <q.5> SWT_DE0
        // <q.6> SWT_AFE3LOAD
        // <q.8> SWT_TRTIA
        // <q.9> SWT_DE0LOAD
        // <q.10> SWT_DE1LOAD
        #define AD5940_Cfg_Tswitch 0x120
    // </h> 

// </h> 

// <h> HSDACCfg
    
    // <o> ExcitBufGain
     
        // <0=> 2
        // <1=> 0.25
        #define AD5940_Cfg_ExcitBufGain 1
        
    // <o> HsDacGain
 
        // <0=> 1
        // <1=> 0.2
        #define AD5940_Cfg_HsDacGain 0
        
    // <o> HsDacUpdateRate <7-255>
        #define AD5940_Cfg_HsDacUpdateRate 255


// </h> 

// <h> WGCfg

    // <o> WgType 
        // <0=> WGTYPE_MMR
        // <2=> WGTYPE_SIN
        // <3=> WGTYPE_TRAPZ
        #define AD5940_Cfg_WgType 0
        
    
        
    // <q> GainCalEn
        #define AD5940_Cfg_GainCalEn 0 
        
    // <q> OffsetCalEn
        #define AD5940_Cfg_OffsetCalEn 0  

// </h> 

// <h> HSTIACfg

    // <o> HstiaBias 
        // <0=> HSTIABIAS_1P1
        // <1=> HSTIABIAS_VZERO0
        #define AD5940_Cfg_HstiaBias 0
        
    // <o> HstiaRtiaSel
        // <0=> HSTIARTIA_200
        // <1=> HSTIARTIA_1K 
        // <2=> HSTIARTIA_5K 
        // <3=> HSTIARTIA_10K 
        // <4=> HSTIARTIA_20K 
        // <5=> HSTIARTIA_40K 
        // <6=> HSTIARTIA_80K
        // <7=> HSTIARTIA_160K
        // <8=> HSTIARTIA_OPEN
        #define AD5940_Cfg_HstiaRtiaSel 1
        
    // <o> ExtRtiaValue
        #define AD5940_Cfg_ExtRtia 0
        
    // <o> HstiaCtia <1-32>
        #define AD5940_Cfg_HstiaCtia 1
        
    // <q> DiodeClose
    // <i> Close the switch for internal back to back diode
        #define AD5940_Cfg_DiodeClose 0
        
    // <o> HstiaDeRtia
        // <0=> HSTIADERTIA_50
        // <1=> HSTIADERTIA_100 
        // <2=> HSTIADERTIA_200
        // <3=> HSTIADERTIA_1K
        // <4=> HSTIADERTIA_5K 
        // <5=> HSTIADERTIA_10K 
        // <6=> HSTIADERTIA_20K 
        // <7=> HSTIADERTIA_40K
        // <8=> HSTIADERTIA_80K
        // <9=> HSTIADERTIA_160K
        // <10=> HSTIADERTIA_SHORT_TO_DE
        // <11=> HSTIADERTIA_OPEN
        #define AD5940_Cfg_HstiaDeRtia 0
        
    // <o> HstiaDeRload
        // <0=> HSTIADERLOAD_0R
        // <1=> HSTIADERLOAD_10R 
        // <2=> HSTIADERLOAD_30R
        // <3=> HSTIADERLOAD_50R
        // <4=> HSTIADERLOAD_100R
        // <5=> HSTIADERLOAD_OPEN 
        #define AD5940_Cfg_HstiaDeRload 0
        
// </h> 


// </h> 

// <h> LPLoopCfg

// <h> LpDacCfg

    // <o> LpDacSrc
    // <i> HSDAC is always connects to WG. Disable HSDAC if there is need.
        // <0=> LPDACSRC_MMR
        // <1=> LPDACSRC_WG
        #define AD5940_Cfg_LpDacSrc 1

// </h> 

// <h> LpAmpCfg

    // <q> LpPaPwrEn
    #define AD5940_Cfg_LpPaPwrEn 0
    
    // <q> LpTiaPwrEn
    #define AD5940_Cfg_LpTiaPwrEn 0

// </h> 

// </h> 

// <h> DSPCfg_Type

// <h> ADCBaseCfg

    // <o> ADCMuxP
    // <o> ADCMuxN
    // <o> ADCPga

// </h> 

// <h> ADCFilterCfg

    // <o> ADCSinc3Osr
    // <o> ADCSinc2Osr
    // <o> ADCAvgNum
    // <o> ADCRate
    // <q> BpNotch
    // <q> BpSinc3
    // <q> Sinc3ClkEnable
    // <q> Sinc2NotchClkEnable
    // <q> Sinc2NotchEnable
    // <q> DFTClkEnable
    // <q> WGClkEnable

// </h> 

// <h> ADCDigCompCfg

// </h> 

// <h> DftCfg

    // <o> DftNum
    // <o> DftSrc
    // <q> HanWinEn

// </h> 

// <h> StatCfg

// </h> 

// </h> 

// <h> LP mode

    // <q> LPModeEn
    #define AD5940_Cfg_LPModeEn 0
    
    // <o> Select system clock source for LPMODE
        // <0=> LPMODECLK_HFOSC
        // <1=> LPMODECLK_LFOSC 
    #define AD5940_Cfg_LPModeClk 0
    
// </h> 

#include "ad5940.h"

void ad5940_config(void);

#endif
