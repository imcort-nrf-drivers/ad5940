#include "ad5940_config.h"

#define SIN_FREQ      25000     /* 25kHz */
#define SYS_CLOCK_HZ 16000000.0 /* System clock frequency */

void ad5940_config(void)
{

    CLKCfg_Type clk_cfg;
    clk_cfg.SysClkSrc = AD5940_Cfg_SysClkSrc;       /**< System clock source @ref SYSCLKSRC_Const */
    clk_cfg.ADCCLkSrc = AD5940_Cfg_ADCCLkSrc;       /**< ADC clock source @ref ADCCLKSRC_Const */
    clk_cfg.SysClkDiv = AD5940_Cfg_SysClkDiv;       /**< System clock divider. Use this to ensure System clock < 16MHz. */
    clk_cfg.ADCClkDiv = AD5940_Cfg_ADCClkDiv;       /**< ADC control clock divider. ADC core clock is @ADCCLkSrc, but control clock should be <16MHz.  */
    clk_cfg.HFOSCEn = AD5940_Cfg_HFOSCEn;         /**< Enable internal 16MHz/32MHz HFOSC */
    clk_cfg.HfOSC32MHzMode = AD5940_Cfg_HfOSC32MHzMode;  /**< Enable internal HFOSC to output 32MHz */
    clk_cfg.LFOSCEn = AD5940_Cfg_LFOSCEn;         /**< Enable internal 32kHZ OSC */
    clk_cfg.HFXTALEn = AD5940_Cfg_HFXTALEn;        /**< Enable XTAL driver */
    AD5940_CLKCfg(&clk_cfg);
    
    AFERefCfg_Type aferef_cfg;
    /* ADC/DAC/TIA reference and buffer */
    aferef_cfg.HpBandgapEn = AD5940_Cfg_HpBandgapEn;     /**< Enable High power band-gap. Clear bit AFECON.HPREFDIS will enable Bandgap, while set this bit will disable bandgap */
    aferef_cfg.Hp1V8BuffEn = AD5940_Cfg_Hp1V8BuffEn;     /**< High power 1.8V reference buffer enable */
    aferef_cfg.Hp1V1BuffEn = AD5940_Cfg_Hp1V1BuffEn;     /**< High power 1.1V reference buffer enable */
    aferef_cfg.Lp1V8BuffEn = AD5940_Cfg_Lp1V8BuffEn;     /**< Low power 1.8V reference buffer enable */
    aferef_cfg.Lp1V1BuffEn = AD5940_Cfg_Lp1V1BuffEn;     /**< Low power 1.1V reference buffer enable */
    /* Low bandwidth loop reference and buffer */
    aferef_cfg.LpBandgapEn = AD5940_Cfg_LpBandgapEn;     /**< Enable Low power band-gap. */
    aferef_cfg.LpRefBufEn = AD5940_Cfg_LpRefBufEn;      /**< Enable the 2.5V low power reference buffer */
    aferef_cfg.LpRefBoostEn = AD5940_Cfg_LpRefBoostEn;    /**< Boost buffer current */
    /* DAC Reference Buffer */
    aferef_cfg.HSDACRefEn = AD5940_Cfg_HSDACRefEn;      /**< Enable DAC reference buffer from HP Bandgap */
    /* Misc. control  */
    aferef_cfg.Hp1V8ThemBuff = AD5940_Cfg_Hp1V8ThemBuff;   /**< Thermal Buffer for internal 1.8V reference to AIN3 pin  */              
    aferef_cfg.Hp1V8Ilimit = AD5940_Cfg_Hp1V8Ilimit;     /**< Current limit for High power 1.8V reference buffer */
    aferef_cfg.Disc1V8Cap = AD5940_Cfg_Disc1V8Cap;      /**< Discharge 1.8V capacitor. Short external 1.8V decouple capacitor to ground. Be careful when use this bit  */
    aferef_cfg.Disc1V1Cap = AD5940_Cfg_Disc1V1Cap;      /**< Discharge 1.1V capacitor. Short external 1.1V decouple capacitor to ground. Be careful when use this bit  */
    AD5940_REFCfgS(&aferef_cfg);	

    HSLoopCfg_Type HpLoopCfg;
    HpLoopCfg.HsDacCfg.ExcitBufGain = EXCITBUFGAIN_2;
    HpLoopCfg.HsDacCfg.HsDacGain = HSDACGAIN_1;
    HpLoopCfg.HsDacCfg.HsDacUpdateRate = 2;

    HpLoopCfg.HsTiaCfg.DiodeClose = bFALSE;
    HpLoopCfg.HsTiaCfg.HstiaBias = HSTIABIAS_1P1;
    HpLoopCfg.HsTiaCfg.HstiaCtia = 16; /* 16pF */
    HpLoopCfg.HsTiaCfg.HstiaDeRload = HSTIADERLOAD_OPEN;
    HpLoopCfg.HsTiaCfg.HstiaDeRtia = HSTIADERTIA_TODE;
    HpLoopCfg.HsTiaCfg.HstiaRtiaSel = HSTIARTIA_160K;

    HpLoopCfg.SWMatCfg.Dswitch = SWD_CE0;
    HpLoopCfg.SWMatCfg.Pswitch = SWP_CE0;
    HpLoopCfg.SWMatCfg.Nswitch = SWN_SE0LOAD;
    HpLoopCfg.SWMatCfg.Tswitch = SWT_TRTIA|SWT_SE0LOAD;

    HpLoopCfg.WgCfg.WgType = WGTYPE_SIN;
    HpLoopCfg.WgCfg.GainCalEn = bFALSE;
    HpLoopCfg.WgCfg.OffsetCalEn = bFALSE;
    HpLoopCfg.WgCfg.SinCfg.SinFreqWord = AD5940_WGFreqWordCal(SIN_FREQ,SYS_CLOCK_HZ);
    HpLoopCfg.WgCfg.SinCfg.SinAmplitudeWord = 2047;
    HpLoopCfg.WgCfg.SinCfg.SinOffsetWord = 0;
    HpLoopCfg.WgCfg.SinCfg.SinPhaseWord = 0;
    AD5940_HSLoopCfgS(&HpLoopCfg);

    AD5940_AFECtrlS(AFECTRL_DACREFPWR, bTRUE);
    AD5940_AFECtrlS(AFECTRL_EXTBUFPWR|AFECTRL_INAMPPWR|AFECTRL_HSTIAPWR|AFECTRL_HSDACPWR, bTRUE);
    AD5940_AFECtrlS(AFECTRL_WG, bTRUE);

    AD5940_AFEPwrBW(AFEPWR_LP, AFEBW_250KHZ);

}
