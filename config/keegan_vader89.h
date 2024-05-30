#ifdef CONFIG_TOP
#include "proffieboard_v3_config.h"
#define NUM_BLADES 2
#define NUM_BUTTONS 2
#define VOLUME 1800
const unsigned int maxLedsPerStrip = 128;
// Was 4.5 before
#define CLASH_THRESHOLD_G 4.0
#define ENABLE_AUDIO
#define ENABLE_MOTION
#define ENABLE_WS2811
#define ENABLE_SD
#define ENABLE_SERIAL
#define ORIENTATION ORIENTATION_USB_TOWARDS_BLADE
#define SAVE_STATE
#define SAVE_PRESET

#define DISABLE_DIAGNOSTIC_COMMANDS
#define FETT263_MULTI_PHASE

//#define FETT263_TWIST_ON_NO_BM
// #define FETT263_TWIST_ON
//#define FETT263_TWIST_OFF

#define FETT263_STAB_ON_NO_BM
#define FETT263_STAB_ON

//#define FETT263_SWING_ON_SPEED 500
//#define FETT263_SWING_ON_NO_BM
//#define FETT263_SWING_ON
//#define FETT263_SWING_OFF

#define MOTION_TIMEOUT 60 * 3 * 1000

#define FETT263_THRUST_ON
#define FETT263_THRUST_OFF
#define FETT263_DISABLE_COPY_PRESET

// #define ENABLE_SSD1306
// // Max 20 characters
// #define BLE_PASSWORD "your password"
// // Max 32 characters.
// #define BLE_NAME "Your Saber Name"
// // Max 9 characters
// #define BLE_SHORTNAME "Saber"

#define MOTION_TIMEOUT 60 * 3 * 800
#endif

#ifdef CONFIG_PROP
#include "../props/saber_fett263_buttons.h"

#endif

#ifdef CONFIG_PRESETS

/*--------------------------------- ControlMainHyperResponsiveRotoscopeOriginalTrilogyBaseColor -------------------------
copyright Fett263 Rotoscope (Primary Blade) OS7 Style
https://www.fett263.com/fett263-proffieOS7-style-library.html#Rotoscope
OS7.14 v2.241p
Single Style
Base Style: Hyper Responsive Rotoscope (Original Trilogy)


--Effects Included--
Ignition Effect: Standard Ignition [Color: IgnitionColorArg]
Retraction Effect: Standard Retraction [Color: RetractionColorArg]
Lockup Effect:
0: mainLockMulti0Shape - Begin: Real Clash - Style: Intensity AudioFlicker - End: Full Blade Absorb
[Color: LockupColorArg]
Lightning Block Effect:
0: mainLBMulti0Shape - Begin: Responsive Impact - Style: Strobing AudioFlicker - End: Full Blade Absorb
[Color: LBColorArg]
Drag Effect:
0: mainDragMulti0Shape - Begin: Wipe In - Style: Intensity Sparking Drag - End: Wipe Out
[Color: DragColorArg]
Melt Effect:
0: mainMeltMulti0Shape - Begin: Wipe In - Style: Intensity Melt - End: Wipe Out
[Color: StabColorArg]
Blast Effect: Blast Wave (Random) [Color: BlastColorArg]
Clash Effect: Real Clash V1 [Color: ClashColorArg]
*/
using ControlMainHyperResponsiveRotoscopeOriginalTrilogyBaseColor = Layers<Mix<HoldPeakF<SwingSpeed<250>,Scale<SwingAcceleration<100>,Int<50>,Int<500>>,Scale<SwingAcceleration<>,Int<20000>,Int<10000>>>,RandomFlicker<StripesX<Int<15000>,Scale<HoldPeakF<SwingSpeed<200>,Scale<SwingAcceleration<100>,Int<50>,Int<300>>,Scale<SwingAcceleration<100>,Int<24000>,Int<16000>>>,Int<-3200>,Int<-200>>,RgbArg<BASE_COLOR_ARG,Rgb<2,72,255>>,RgbArg<BASE_COLOR_ARG,Rgb<2,72,255>>,Mix<Int<7710>,Black,RgbArg<BASE_COLOR_ARG,Rgb<2,72,255>>>,RgbArg<BASE_COLOR_ARG,Rgb<2,72,255>>,Mix<Int<19276>,Black,RgbArg<BASE_COLOR_ARG,Rgb<2,72,255>>>>,RgbArg<BASE_COLOR_ARG,Rgb<2,72,255>>>,RgbArg<BASE_COLOR_ARG,Rgb<2,72,255>>>,TransitionEffectL<TrWaveX<RgbArg<BLAST_COLOR_ARG,Rgb<255,255,255>>,Scale<EffectRandomF<EFFECT_BLAST>,Int<100>,Int<400>>,Int<100>,Scale<EffectPosition<EFFECT_BLAST>,Int<100>,Int<400>>,Scale<EffectPosition<EFFECT_BLAST>,Int<28000>,Int<8000>>>,EFFECT_BLAST>,Mix<IsLessThan<ClashImpactF<>,Int<26000>>,TransitionEffectL<TrConcat<TrInstant,AlphaL<RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<ClashImpactF<>,Int<12000>,Int<60000>>>>,TrFadeX<Scale<ClashImpactF<>,Int<200>,Int<400>>>>,EFFECT_CLASH>,TransitionEffectL<TrWaveX<RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>,Scale<ClashImpactF<>,Int<100>,Int<400>>,Int<100>,Scale<ClashImpactF<>,Int<100>,Int<400>>,Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>>,EFFECT_CLASH>>,LockupTrL<TransitionEffect<AlphaL<AlphaMixL<Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<22000>>>,AudioFlicker<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<12000>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>>>,BrownNoiseFlicker<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<12000>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>>,300>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<22000>>>>,AlphaL<AudioFlicker<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<20000>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,TrExtend<5000,TrInstant>,TrFade<5000>,EFFECT_LOCKUP_BEGIN>,TrConcat<TrJoin<TrDelay<50>,TrInstant>,Mix<IsLessThan<ClashImpactF<>,Int<26000>>,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,AlphaL<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<ClashImpactF<>,Int<20000>,Int<60000>>>>>,TrFade<300>>,TrConcat<TrInstant,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,TrFade<400>>,SaberBase::LOCKUP_NORMAL,Int<1>>,ResponsiveLightningBlockL<Strobe<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,AudioFlicker<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,Blue>,50,1>,TrConcat<TrExtend<200,TrInstant>,AlphaL<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,Bump<Scale<BladeAngle<>,Int<10000>,Int<21000>>,Int<10000>>>,TrFade<200>>,TrConcat<TrInstant,RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,TrFade<400>>,Int<1>>,LockupTrL<AlphaL<TransitionEffect<RandomPerLEDFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<255,255,255>>>,BrownNoiseFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<255,255,255>>,Int<300>>,TrExtend<4000,TrInstant>,TrFade<4000>,EFFECT_DRAG_BEGIN>,SmoothStep<Scale<TwistAngle<>,IntArg<DRAG_SIZE_ARG,28000>,Int<30000>>,Int<3000>>>,TrWipeIn<200>,TrWipe<200>,SaberBase::LOCKUP_DRAG,Int<1>>,LockupTrL<AlphaL<Stripes<2000,4000,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>,Mix<Sin<Int<50>>,Black,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>>,Mix<Int<4096>,Black,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>>>,SmoothStep<Scale<TwistAngle<>,IntArg<MELT_SIZE_ARG,28000>,Int<30000>>,Int<3000>>>,TrConcat<TrExtend<4000,TrWipeIn<200>>,AlphaL<HumpFlicker<Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>,RotateColorsX<Int<3000>,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>>,100>,SmoothStep<Scale<TwistAngle<>,IntArg<MELT_SIZE_ARG,28000>,Int<30000>>,Int<3000>>>,TrFade<4000>>,TrWipe<200>,SaberBase::LOCKUP_MELT,Int<1>>,InOutTrL<TrWipeX<BendTimePowInvX<IgnitionTime<300>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrWipeInX<BendTimePowInvX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,Black>>;
/*
Add to preset as StylePtr<ControlMainHyperResponsiveRotoscopeOriginalTrilogyBaseColor>()
--------------------------------------------------------------------------*/

// Following presets taken from https://www.dropbox.com/s/8xzmpui0thjk68u/fontss.txt?e=2&dl=0 based on older fett263 work
using twistyLukeANH = Layers<
    HumpFlicker<RotateColorsX<Variation, SteelBlue>, RotateColorsX<Variation, DodgerBlue>, 50>,
    LockupTrL<
        Layers<
            AlphaL<AudioFlickerL<White>,
                   Bump<Scale<BladeAngle<>, Scale<BladeAngle<0, 16000>, Int<4000>, Int<26000>>,
                              Int<6000>>,
                        Scale<SwingSpeed<100>, Int<14000>, Int<18000>>>>,
            AlphaL<White, Bump<Scale<BladeAngle<>,
                                     Scale<BladeAngle<0, 16000>, Int<4000>, Int<26000>>, Int<6000>>,
                               Int<10000>>>>,
        TrConcat<TrInstant, White, TrFade<400>>, TrConcat<TrInstant, White, TrFade<400>>,
        SaberBase::LOCKUP_NORMAL>,
    ResponsiveLightningBlockL<
        Strobe<White, AudioFlicker<White, Blue>, 50, 1>,
        TrConcat<TrInstant, AlphaL<White, Bump<Int<12000>, Int<18000>>>, TrFade<200>>,
        TrConcat<TrInstant, HumpFlickerL<AlphaL<White, Int<16000>>, 30>, TrSmoothFade<600>>>,
    ResponsiveStabL<Red, TrWipeIn<600>, TrWipe<600>>,
    ResponsiveBlastL<White, Int<400>, Scale<SwingSpeed<200>, Int<100>, Int<400>>, Int<400>>,
    ResponsiveClashL<White, TrInstant, TrFade<400>,
                     Scale<BladeAngle<0, 16000>, Int<4000>, Int<26000>>, Int<6000>, Int<20000>>,
    LockupTrL<AlphaL<BrownNoiseFlickerL<White, Int<300>>, SmoothStep<Int<30000>, Int<5000>>>,
              TrWipeIn<400>, TrFade<300>, SaberBase::LOCKUP_DRAG>,
    LockupTrL<AlphaL<Mix<TwistAngle<>, Red, Orange>, SmoothStep<Int<28000>, Int<5000>>>,
              TrWipeIn<600>, TrFade<300>, SaberBase::LOCKUP_MELT>,
    InOutTrL<TrWipe<200>, TrWipeIn<150>, Black>>;

using twistyLukeROTJ = Layers<
    HumpFlicker<RotateColorsX<Variation, Green>, RotateColorsX<Variation, Rgb<0, 128, 0>>, 50>,
    LockupTrL<
        Layers<AlphaL<AudioFlickerL<Rgb<255, 240, 80>>,
                      Bump<Scale<BladeAngle<>, Scale<BladeAngle<0, 16000>, Int<10000>, Int<30000>>,
                                 Int<10000>>,
                           Scale<SwingSpeed<100>, Int<14000>, Int<18000>>>>,
               AlphaL<LemonChiffon,
                      Bump<Scale<BladeAngle<>, Scale<BladeAngle<0, 16000>, Int<10000>, Int<30000>>,
                                 Int<10000>>,
                           Int<10000>>>>,
        TrConcat<TrInstant,
                 AlphaL<TransitionEffect<Rgb<255, 180, 50>, LemonChiffon, TrInstant, TrFade<200>,
                                         EFFECT_LOCKUP_BEGIN>,
                        Bump<Scale<BladeAngle<>,
                                   Scale<BladeAngle<0, 16000>, Int<10000>, Int<30000>>, Int<10000>>,
                             Int<20000>>>,
                 TrFade<400>>,
        TrConcat<TrInstant, AlphaL<White, Int<0>>,
                 TrWaveX<TransitionEffect<LemonChiffon, Rgb<255, 180, 50>, TrInstant, TrFade<200>,
                                          EFFECT_LOCKUP_BEGIN>,
                         Int<300>, Int<100>, Int<400>,
                         Scale<BladeAngle<>, Scale<BladeAngle<0, 16000>, Int<10000>, Int<30000>>,
                               Int<10000>>>>,
        SaberBase::LOCKUP_NORMAL>,
    ResponsiveLightningBlockL<
        Strobe<White, AudioFlicker<White, Blue>, 50, 1>,
        TrConcat<TrInstant, AlphaL<White, Bump<Int<12000>, Int<18000>>>, TrFade<200>>,
        TrConcat<TrInstant, HumpFlickerL<AlphaL<White, Int<16000>>, 30>, TrSmoothFade<600>>>,
    ResponsiveStabL<Red, TrWipeIn<600>, TrWipe<600>>,
    ResponsiveBlastL<
        TransitionEffect<Rgb<255, 240, 80>, LemonChiffon, TrInstant, TrFade<50>, EFFECT_BLAST>,
        Int<400>, Scale<SwingSpeed<200>, Int<100>, Int<400>>>,
    ResponsiveClashL<
        TransitionEffect<Rgb<255, 240, 80>, LemonChiffon, TrInstant, TrFade<100>, EFFECT_CLASH>,
        TrInstant, TrFade<400>, Scale<BladeAngle<0, 16000>, Int<10000>, Int<30000>>, Int<10000>,
        Int<20000>>,
    LockupTrL<AlphaL<BrownNoiseFlickerL<White, Int<300>>, SmoothStep<Int<30000>, Int<5000>>>,
              TrWipeIn<400>, TrFade<300>, SaberBase::LOCKUP_DRAG>,
    LockupTrL<AlphaL<Mix<TwistAngle<>, Red, Orange>, SmoothStep<Int<28000>, Int<5000>>>,
              TrWipeIn<600>, TrFade<300>, SaberBase::LOCKUP_MELT>,
    InOutTrL<TrWipe<200>, TrWipeIn<300>, Black>>;


using twistyVader = Layers<
    HumpFlicker<RotateColorsX<Variation, Red>, RotateColorsX<Variation, Rgb<128, 0, 0>>, 55>,
    LockupTrL<
        Layers<AlphaL<AudioFlickerL<Rgb<255, 240, 80>>,
                      Bump<Scale<BladeAngle<>, Scale<BladeAngle<0, 16000>, Int<4000>, Int<26000>>,
                                 Int<6000>>,
                           Scale<SwingSpeed<100>, Int<14000>, Int<18000>>>>,
               AlphaL<LemonChiffon,
                      Bump<Scale<BladeAngle<>, Scale<BladeAngle<0, 16000>, Int<4000>, Int<26000>>,
                                 Int<6000>>,
                           Int<10000>>>>,
        TrConcat<TrInstant,
                 TransitionEffect<Rgb<255, 180, 50>, LemonChiffon, TrInstant, TrFade<200>,
                                  EFFECT_LOCKUP_BEGIN>,
                 TrFade<400>>,
        TrConcat<TrInstant,
                 TransitionEffect<LemonChiffon, Rgb<255, 180, 50>, TrInstant, TrFade<200>,
                                  EFFECT_LOCKUP_BEGIN>,
                 TrFade<400>>,
        SaberBase::LOCKUP_NORMAL>,
    ResponsiveLightningBlockL<
        Strobe<White, AudioFlicker<White, Blue>, 50, 1>,
        TrConcat<TrInstant, AlphaL<White, Bump<Int<12000>, Int<18000>>>, TrFade<200>>,
        TrConcat<TrInstant, HumpFlickerL<AlphaL<White, Int<16000>>, 30>, TrSmoothFade<600>>>,
    ResponsiveStabL<Orange, TrWipeIn<600>, TrWipe<600>>,
    ResponsiveBlastL<
        TransitionEffect<Rgb<255, 240, 80>, LemonChiffon, TrInstant, TrFade<50>, EFFECT_BLAST>,
        Int<400>, Scale<SwingSpeed<200>, Int<100>, Int<400>>>,
    ResponsiveClashL<
        TransitionEffect<Rgb<255, 240, 80>, LemonChiffon, TrInstant, TrFade<100>, EFFECT_CLASH>,
        TrInstant, TrFade<400>, Scale<BladeAngle<0, 16000>, Int<4000>, Int<26000>>, Int<6000>,
        Int<20000>>,
    LockupTrL<AlphaL<BrownNoiseFlickerL<White, Int<300>>, SmoothStep<Int<30000>, Int<5000>>>,
              TrWipeIn<400>, TrFade<300>, SaberBase::LOCKUP_DRAG>,
    LockupTrL<
        AlphaL<Mix<TwistAngle<>, Rgb<255, 200, 0>, DarkOrange>, SmoothStep<Int<28000>, Int<5000>>>,
        TrWipeIn<600>, TrFade<300>, SaberBase::LOCKUP_MELT>,
    InOutTrL<TrWipe<650>, TrWipeIn<350>, Black>>;

using twistyLukeYoda = Layers<
    AudioFlicker<RotateColorsX<Variation, Green>, RotateColorsX<Variation, Rgb<0, 128, 0>>>,
    TransitionEffectL<
        TrConcat<TrFade<400>,
                 StyleFire<Stripes<2500, -5000, BrownNoiseFlicker<Green, Black, 20>, Rgb<0, 10, 0>,
                                   BrownNoiseFlicker<Black, Rgb<25, 255, 25>, 70>, Rgb<0, 128, 0>>,
                           Rgb<0, 80, 0>, 0, 5, FireConfig<2, 3000, 0>, FireConfig<2, 3000, 0>,
                           FireConfig<2, 3000, 0>, FireConfig<2, 3000, 0>>,
                 TrDelay<1500>,
                 StyleFire<Stripes<2500, -5000, BrownNoiseFlicker<Green, Black, 20>, Rgb<0, 10, 0>,
                                   BrownNoiseFlicker<Black, Rgb<25, 255, 25>, 70>, Rgb<0, 128, 0>>,
                           Rgb<0, 80, 0>, 0, 5, FireConfig<2, 3000, 0>, FireConfig<2, 3000, 0>,
                           FireConfig<2, 3000, 0>, FireConfig<2, 3000, 0>>,
                 TrFade<800>>,
        EFFECT_FORCE>,
    TransitionEffectL<TrConcat<TrInstant, BrownNoiseFlickerL<AlphaL<White, Int<16000>>, Int<50>>,
                               TrSmoothFade<600>>,
                      EFFECT_LOCKUP_END>,
    ResponsiveLightningBlockL<
        Strobe<White, AudioFlicker<White, Blue>, 50, 1>,
        TrConcat<TrInstant, AlphaL<White, Bump<Int<12000>, Int<18000>>>, TrFade<200>>,
        TrConcat<TrInstant, HumpFlickerL<AlphaL<White, Int<16000>>, 30>, TrSmoothFade<600>>>,
    ResponsiveBlastL<White, Int<400>, Scale<SwingSpeed<200>, Int<100>, Int<400>>, Int<400>>,
    ResponsiveClashL<White, TrInstant, TrFade<400>,
                     Scale<BladeAngle<0, 16000>, Int<4000>, Int<26000>>, Int<6000>>,
    LockupTrL<AlphaL<BrownNoiseFlickerL<White, Int<300>>, SmoothStep<Int<30000>, Int<5000>>>,
              TrWipeIn<400>, TrFade<300>, SaberBase::LOCKUP_DRAG>,
    LockupTrL<AlphaL<Mix<TwistAngle<>, Red, Orange>, SmoothStep<Int<28000>, Int<5000>>>,
              TrWipeIn<600>, TrFade<300>, SaberBase::LOCKUP_MELT>,
    InOutTrL<TrWipe<300>, TrWipeIn<500>, Black>>;

using twistyAniCloneWars = Layers<
    Mix<SwingSpeed<400>,
        AudioFlicker<RotateColorsX<Variation, DeepSkyBlue>, RotateColorsX<Variation, SteelBlue>>,
        Mix<SwingSpeed<600>, RotateColorsX<Variation, DeepSkyBlue>,
            RotateColorsX<Variation, Rgb<100, 185, 255>>>>,
    TransitionEffectL<TrConcat<TrInstant, BrownNoiseFlickerL<AlphaL<White, Int<16000>>, Int<50>>,
                               TrSmoothFade<600>>,
                      EFFECT_LOCKUP_END>,
    ResponsiveLockupL<Strobe<White, BrownNoiseFlicker<White, Red, 300>, 50, 1>,
                      TrConcat<TrInstant, White, TrFade<400>>, TrFade<100>,
                      Scale<BladeAngle<0, 16000>, Int<4000>, Int<26000>>, Int<6000>,
                      Scale<SwingSpeed<100>, Int<10000>, Int<14000>>>,
    ResponsiveLightningBlockL<
        Strobe<White, AudioFlicker<White, Blue>, 50, 1>,
        TrConcat<TrInstant, AlphaL<White, Bump<Int<12000>, Int<18000>>>, TrFade<200>>,
        TrConcat<TrInstant, HumpFlickerL<AlphaL<White, Int<16000>>, 30>, TrSmoothFade<600>>>,
    ResponsiveStabL<Red, TrWipeIn<600>, TrWipe<600>>,
    ResponsiveBlastL<White, Int<400>, Scale<SwingSpeed<200>, Int<100>, Int<400>>, Int<400>>,
    ResponsiveClashL<White, TrInstant, TrFade<400>,
                     Scale<BladeAngle<0, 16000>, Int<4000>, Int<26000>>, Int<6000>>,
    LockupTrL<AlphaL<BrownNoiseFlickerL<White, Int<300>>, SmoothStep<Int<30000>, Int<5000>>>,
              TrWipeIn<400>, TrFade<300>, SaberBase::LOCKUP_DRAG>,
    LockupTrL<AlphaL<Mix<TwistAngle<>, Red, Orange>, SmoothStep<Int<28000>, Int<5000>>>,
              TrWipeIn<600>, TrFade<300>, SaberBase::LOCKUP_MELT>,
    InOutTrL<TrWipe<200>, TrWipeIn<150>, Black>>;

using twistyObiCloneWars = Layers<
    Mix<SwingSpeed<400>,
        AudioFlicker<RotateColorsX<Variation, Blue>, RotateColorsX<Variation, Rgb<0, 0, 128>>>,
        Mix<SwingSpeed<600>, RotateColorsX<Variation, Blue>, RotateColorsX<Variation, DodgerBlue>>>,
    TransitionEffectL<TrConcat<TrInstant, BrownNoiseFlickerL<AlphaL<White, Int<16000>>, Int<50>>,
                               TrSmoothFade<600>>,
                      EFFECT_LOCKUP_END>,
    ResponsiveLockupL<Strobe<White, BrownNoiseFlicker<White, Red, 300>, 50, 1>,
                      TrConcat<TrInstant, White, TrFade<400>>, TrFade<100>,
                      Scale<BladeAngle<0, 16000>, Int<4000>, Int<26000>>, Int<6000>,
                      Scale<SwingSpeed<100>, Int<10000>, Int<14000>>>,
    ResponsiveLightningBlockL<
        Strobe<White, AudioFlicker<White, Blue>, 50, 1>,
        TrConcat<TrInstant, AlphaL<White, Bump<Int<12000>, Int<18000>>>, TrFade<200>>,
        TrConcat<TrInstant, HumpFlickerL<AlphaL<White, Int<16000>>, 30>, TrSmoothFade<600>>>,
    ResponsiveStabL<Red, TrWipeIn<600>, TrWipe<600>>,
    ResponsiveBlastL<White, Int<400>, Scale<SwingSpeed<200>, Int<100>, Int<400>>, Int<400>>,
    ResponsiveClashL<White, TrInstant, TrFade<400>,
                     Scale<BladeAngle<0, 16000>, Int<4000>, Int<26000>>, Int<6000>>,
    LockupTrL<AlphaL<BrownNoiseFlickerL<White, Int<300>>, SmoothStep<Int<30000>, Int<5000>>>,
              TrWipeIn<400>, TrFade<300>, SaberBase::LOCKUP_DRAG>,
    LockupTrL<AlphaL<Mix<TwistAngle<>, Red, Orange>, SmoothStep<Int<28000>, Int<5000>>>,
              TrWipeIn<600>, TrFade<300>, SaberBase::LOCKUP_MELT>,
    InOutTrL<TrWipe<200>, TrWipeIn<300>, Black>>;

using twistyMaceROTS = Layers<
  HumpFlicker<RotateColorsX<Variation, Rgb<95, 0, 210>>,
              RotateColorsX<Variation, Rgb<42, 0, 110>>, 80>,
  LockupTrL<
      Layers<AlphaL<AudioFlickerL<Rgb<255, 225, 0>>,
                    Bump<Scale<BladeAngle<>,
                               Scale<BladeAngle<0, 16000>, Int<4000>, Int<26000>>, Int<6000>>,
                         Scale<SwingSpeed<100>, Int<14000>, Int<18000>>>>,
             AlphaL<NavajoWhite,
                    Bump<Scale<BladeAngle<>,
                               Scale<BladeAngle<0, 16000>, Int<4000>, Int<26000>>, Int<6000>>,
                         Int<10000>>>>,
      TrConcat<TrInstant,
               TransitionEffect<Rgb<255, 225, 0>, NavajoWhite, TrInstant, TrFade<200>,
                                EFFECT_LOCKUP_BEGIN>,
               TrFade<400>>,
      TrConcat<TrInstant,
               TransitionEffect<NavajoWhite, Rgb<255, 225, 0>, TrInstant, TrFade<200>,
                                EFFECT_LOCKUP_BEGIN>,
               TrFade<400>>,
      SaberBase::LOCKUP_NORMAL>,
  ResponsiveLightningBlockL<
      Strobe<White, AudioFlicker<White, Blue>, 50, 1>,
      TrConcat<TrInstant, AlphaL<White, Bump<Int<12000>, Int<18000>>>, TrFade<200>>,
      TrConcat<TrInstant, HumpFlickerL<AlphaL<White, Int<16000>>, 30>, TrSmoothFade<600>>>,
  AlphaL<RotateColorsX<Variation, Rgb<160, 0, 255>>, Bump<Int<0>, Int<8000>>>,
  ResponsiveStabL<Red, TrWipeIn<600>, TrWipe<600>>,
  ResponsiveBlastL<
      TransitionEffect<Rgb<255, 225, 0>, NavajoWhite, TrInstant, TrFade<50>, EFFECT_BLAST>,
      Int<400>, Scale<SwingSpeed<200>, Int<100>, Int<400>>>,
  ResponsiveClashL<
      TransitionEffect<Rgb<255, 225, 0>, NavajoWhite, TrInstant, TrFade<100>, EFFECT_CLASH>,
      TrInstant, TrFade<400>, Scale<BladeAngle<0, 16000>, Int<4000>, Int<26000>>, Int<6000>,
      Int<20000>>,
  LockupTrL<AlphaL<BrownNoiseFlickerL<White, Int<300>>, SmoothStep<Int<30000>, Int<5000>>>,
            TrWipeIn<400>, TrFade<300>, SaberBase::LOCKUP_DRAG>,
  LockupTrL<AlphaL<Mix<TwistAngle<>, Red, Orange>, SmoothStep<Int<28000>, Int<5000>>>,
            TrWipeIn<600>, TrFade<300>, SaberBase::LOCKUP_MELT>,
  InOutTrL<TrWipe<175>, TrWipeIn<250>, Black>>;

using twistyReyGold = Layers<
    AudioFlicker<RotateColorsX<Variation, Rgb<180, 130, 0>>,
                 RotateColorsX<Variation, Rgb<90, 65, 0>>>,
    AlphaL<RotateColorsX<Variation, Rgb<230, 180, 80>>,
           Scale<IsLessThan<SwingSpeed<600>, Int<13600>>,
                 Scale<SwingSpeed<600>, Int<-19300>, Int<32768>>, Int<0>>>,
    LockupTrL<
        Layers<
            AlphaL<AudioFlickerL<Azure>,
                   Bump<Scale<BladeAngle<>, Scale<BladeAngle<0, 16000>, Int<4000>, Int<26000>>,
                              Int<6000>>,
                        Scale<SwingSpeed<100>, Int<14000>, Int<18000>>>>,
            AlphaL<White, Bump<Scale<BladeAngle<>,
                                     Scale<BladeAngle<0, 16000>, Int<4000>, Int<26000>>, Int<6000>>,
                               Int<10000>>>>,
        TrConcat<TrInstant,
                 TransitionEffect<Azure, White, TrInstant, TrFade<200>, EFFECT_LOCKUP_BEGIN>,
                 TrFade<400>>,
        TrConcat<
            TrInstant, AlphaL<White, Int<0>>,
            TrWaveX<TransitionEffect<White, Azure, TrInstant, TrFade<200>, EFFECT_LOCKUP_BEGIN>,
                    Int<300>, Int<100>, Int<400>,
                    Scale<BladeAngle<>, Scale<BladeAngle<0, 16000>, Int<4000>, Int<26000>>,
                          Int<6000>>>>,
        SaberBase::LOCKUP_NORMAL>,
    ResponsiveLightningBlockL<
        Strobe<White, AudioFlicker<White, Blue>, 50, 1>,
        TrConcat<TrInstant, AlphaL<White, Bump<Int<12000>, Int<18000>>>, TrFade<200>>,
        TrConcat<TrInstant, HumpFlickerL<AlphaL<White, Int<16000>>, 30>, TrSmoothFade<600>>>,
    ResponsiveStabL<Red, TrWipeIn<600>, TrWipe<600>>,
    ResponsiveBlastL<TransitionEffect<Azure, White, TrInstant, TrFade<100>, EFFECT_BLAST>, Int<400>,
                     Scale<SwingSpeed<200>, Int<100>, Int<400>>>,
    ResponsiveClashL<TransitionEffect<Azure, White, TrInstant, TrFade<100>, EFFECT_CLASH>,
                     TrInstant, TrFade<400>, Scale<BladeAngle<0, 16000>, Int<4000>, Int<26000>>,
                     Int<6000>, Int<20000>>,
    TransitionEffectL<
        TrConcat<TrInstant, HumpFlickerL<RotateColorsX<Variation, Rgb<230, 180, 80>>, 40>,
                 TrFade<1200>>,
        EFFECT_IGNITION>,
    TransitionEffectL<
        TrConcat<TrInstant, AudioFlickerL<RotateColorsX<Variation, Rgb<230, 180, 80>>>,
                 TrFade<1200>>,
        EFFECT_RETRACTION>,
    LockupTrL<AlphaL<BrownNoiseFlickerL<White, Int<300>>, SmoothStep<Int<30000>, Int<5000>>>,
              TrWipeIn<400>, TrFade<300>, SaberBase::LOCKUP_DRAG>,
    LockupTrL<AlphaL<Mix<TwistAngle<>, Red, Orange>, SmoothStep<Int<28000>, Int<5000>>>,
              TrWipeIn<600>, TrFade<300>, SaberBase::LOCKUP_MELT>,
    InOutTrL<TrWipeSparkTip<White, 150>, TrWipeIn<250>, Black>,
    TransitionEffectL<TrConcat<TrInstant, AlphaL<Green, Bump<Int<0>, Int<4000>>>, TrFade<300>,
                               AlphaL<DodgerBlue, Bump<Int<0>, Int<4000>>>, TrFade<300>,
                               AlphaL<DeepSkyBlue, Bump<Int<0>, Int<400>>>, TrDelay<1>>,
                      EFFECT_PREON>>;

using twistyAhsokaLive = Layers<
    HumpFlicker<RotateColorsX<Variation, Rgb<100, 100, 150>>,
                RotateColorsX<Variation, Rgb<50, 50, 75>>, 30>,
    LockupTrL<
        Layers<
            AlphaL<AudioFlickerL<Azure>,
                   Bump<Scale<BladeAngle<>, Scale<BladeAngle<0, 16000>, Int<4000>, Int<26000>>,
                              Int<6000>>,
                        Scale<SwingSpeed<100>, Int<14000>, Int<18000>>>>,
            AlphaL<White, Bump<Scale<BladeAngle<>,
                                     Scale<BladeAngle<0, 16000>, Int<4000>, Int<26000>>, Int<6000>>,
                               Int<10000>>>>,
        TrConcat<TrInstant,
                 AlphaL<TransitionEffect<Azure, White, TrInstant, TrFade<200>, EFFECT_LOCKUP_BEGIN>,
                        Bump<Scale<BladeAngle<>, Scale<BladeAngle<0, 16000>, Int<4000>, Int<26000>>,
                                   Int<6000>>,
                             Int<20000>>>,
                 TrFade<400>>,
        TrConcat<TrJoinR<TrWipe<100>, TrWipeIn<100>>,
                 TransitionEffect<White, Azure, TrInstant, TrFade<200>, EFFECT_LOCKUP_BEGIN>,
                 TrJoinR<TrWipe<100>, TrWipeIn<100>>>,
        SaberBase::LOCKUP_NORMAL>,
    ResponsiveLightningBlockL<
        Strobe<White, AudioFlicker<White, Blue>, 50, 1>,
        TrConcat<TrInstant, AlphaL<White, Bump<Int<12000>, Int<18000>>>, TrFade<200>>,
        TrConcat<TrInstant, HumpFlickerL<AlphaL<White, Int<16000>>, 30>, TrSmoothFade<600>>>,
    ResponsiveStabL<Red, TrWipeIn<600>, TrWipe<600>>,
    ResponsiveBlastFadeL<Azure, Scale<SwingSpeed<200>, Int<10000>, Int<18000>>>,
    ResponsiveBlastFadeL<White, Scale<SwingSpeed<200>, Int<4000>, Int<10000>>>,
    ResponsiveBlastL<TransitionEffect<Azure, White, TrInstant, TrFade<100>, EFFECT_CLASH>, Int<400>,
                     Int<100>, Int<400>, Scale<BladeAngle<0, 16000>, Int<4000>, Int<26000>>,
                     Int<6000>, EFFECT_CLASH>,
    LockupTrL<AlphaL<BrownNoiseFlickerL<White, Int<300>>, SmoothStep<Int<30000>, Int<5000>>>,
              TrWipeIn<400>, TrFade<300>, SaberBase::LOCKUP_DRAG>,
    LockupTrL<AlphaL<Mix<TwistAngle<>, Red, Orange>, SmoothStep<Int<28000>, Int<5000>>>,
              TrWipeIn<600>, TrFade<300>, SaberBase::LOCKUP_MELT>,
    InOutTrL<TrWipeSparkTip<White, 400>, TrWipeInSparkTip<White, 250>, Black>>;

using twistyDarksaber = Layers<
    AudioFlicker<
        BrownNoiseFlicker<Mix<SwingSpeed<400>, RotateColorsX<Variation, Rgb<100, 100, 150>>,
                              RotateColorsX<Variation, Rgb<150, 150, 225>>>,
                          Stripes<5000, -300, RotateColorsX<Variation, Rgb<25, 25, 55>>,
                                  RotateColorsX<Variation, Rgb<75, 75, 120>>,
                                  RotateColorsX<Variation, Rgb<10, 10, 20>>,
                                  RotateColorsX<Variation, Rgb<50, 50, 75>>>,
                          300>,
        RotateColorsX<Variation, Rgb<35, 35, 75>>>,
    TransitionEffectL<TrConcat<TrInstant, BrownNoiseFlickerL<AlphaL<White, Int<16000>>, Int<50>>,
                               TrSmoothFade<600>>,
                      EFFECT_LOCKUP_END>,
    ResponsiveLockupL<Strobe<White, BrownNoiseFlicker<White, Red, 300>, 50, 1>,
                      TrConcat<TrInstant, White, TrFade<400>>, TrFade<100>,
                      Scale<BladeAngle<0, 16000>, Int<4000>, Int<26000>>, Int<6000>,
                      Scale<SwingSpeed<100>, Int<10000>, Int<14000>>>,
    ResponsiveLightningBlockL<
        Strobe<White, AudioFlicker<White, Blue>, 50, 1>,
        TrConcat<TrInstant, AlphaL<White, Bump<Int<12000>, Int<18000>>>, TrFade<200>>,
        TrConcat<TrInstant, HumpFlickerL<AlphaL<White, Int<16000>>, 30>, TrSmoothFade<600>>>,
    ResponsiveStabL<Red, TrWipeIn<600>, TrWipe<600>>,
    ResponsiveBlastL<White, Int<400>, Scale<SwingSpeed<200>, Int<100>, Int<400>>, Int<400>>,
    ResponsiveClashL<White, TrInstant, TrFade<400>,
                     Scale<BladeAngle<0, 16000>, Int<4000>, Int<26000>>, Int<6000>>,
    LockupTrL<AlphaL<BrownNoiseFlickerL<White, Int<300>>, SmoothStep<Int<30000>, Int<5000>>>,
              TrWipeIn<400>, TrFade<300>, SaberBase::LOCKUP_DRAG>,
    LockupTrL<AlphaL<Mix<TwistAngle<>, Red, Orange>, SmoothStep<Int<28000>, Int<5000>>>,
              TrWipeIn<600>, TrFade<300>, SaberBase::LOCKUP_MELT>,
    InOutTrL<TrWipe<300>, TrWipeIn<500>, Black>>;

/*--------------------------------- ControlMainResponsiveFlameRealFlameGradientBaseColor -------------------------
copyright Fett263 ResponsiveFlame (Primary Blade) OS7 Style
https://www.fett263.com/fett263-proffieOS7-style-library.html#ResponsiveFlame
OS7.14 v2.241p
Single Style
Base Style: Responsive Flame (Real Flame Gradient)


--Effects Included--
Ignition Effect: Standard Ignition [Color: IgnitionColorArg]
Retraction Effect: Standard Retraction [Color: RetractionColorArg]
Lockup Effect:
0: mainLockMulti0Shape - Begin: Real Clash - Style: Intensity AudioFlicker - End: Full Blade Absorb
[Color: LockupColorArg]
Lightning Block Effect:
0: mainLBMulti0Shape - Begin: Responsive Impact - Style: Strobing AudioFlicker - End: Full Blade Absorb
[Color: LBColorArg]
Drag Effect:
0: mainDragMulti0Shape - Begin: Wipe In - Style: Intensity Sparking Drag - End: Wipe Out
[Color: DragColorArg]
Melt Effect:
0: mainMeltMulti0Shape - Begin: Wipe In - Style: Intensity Melt - End: Wipe Out
[Color: StabColorArg]
Blast Effect: Blast Wave (Random) [Color: BlastColorArg]
Clash Effect: Real Clash V1 [Color: ClashColorArg]
*/
using ControlMainResponsiveFlameRealFlameGradientBaseColor = Mix<SmoothStep<Scale<IsLessThan<BladeAngle<>,Int<16000>>,Int<36000>,Scale<BladeAngle<>,Int<10924>,Int<54000>>>,Scale<IsLessThan<BladeAngle<>,Int<16000>>,Int<-1>,Scale<BladeAngle<>,Int<-10000>,Int<-1>>>>,Black,Remap<Scale<RampF,Int<0>,Scale<IsLessThan<BladeAngle<>,Int<15000>>,Int<32768>,Scale<BladeAngle<0,15000>,Int<60000>,Int<32768>>>>,Layers<Mix<BladeAngle<>,StaticFire<Gradient<RotateColorsX<Int<1600>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,RotateColorsX<Int<1000>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,RotateColorsX<Int<400>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,Mix<Int<16384>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,0,2,0,1800,10>,StaticFire<Gradient<RotateColorsX<Int<1600>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,RotateColorsX<Int<1200>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,RotateColorsX<Int<600>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,Mix<Int<16384>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,0,4,0,2200,2>>,TransitionEffectL<TrWaveX<RgbArg<BLAST_COLOR_ARG,Rgb<255,255,255>>,Scale<EffectRandomF<EFFECT_BLAST>,Int<100>,Int<400>>,Int<100>,Scale<EffectPosition<EFFECT_BLAST>,Int<100>,Int<400>>,Scale<EffectPosition<EFFECT_BLAST>,Int<28000>,Int<8000>>>,EFFECT_BLAST>,Mix<IsLessThan<ClashImpactF<>,Int<26000>>,TransitionEffectL<TrConcat<TrInstant,AlphaL<RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<ClashImpactF<>,Int<12000>,Int<60000>>>>,TrFadeX<Scale<ClashImpactF<>,Int<200>,Int<400>>>>,EFFECT_CLASH>,TransitionEffectL<TrWaveX<RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>,Scale<ClashImpactF<>,Int<100>,Int<400>>,Int<100>,Scale<ClashImpactF<>,Int<100>,Int<400>>,Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>>,EFFECT_CLASH>>,LockupTrL<TransitionEffect<AlphaL<AlphaMixL<Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<22000>>>,AudioFlicker<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<12000>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>>>,BrownNoiseFlicker<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<12000>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>>,300>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<22000>>>>,AlphaL<AudioFlicker<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<20000>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,TrExtend<5000,TrInstant>,TrFade<5000>,EFFECT_LOCKUP_BEGIN>,TrConcat<TrJoin<TrDelay<50>,TrInstant>,Mix<IsLessThan<ClashImpactF<>,Int<26000>>,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,AlphaL<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<ClashImpactF<>,Int<20000>,Int<60000>>>>>,TrFade<300>>,TrConcat<TrInstant,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,TrFade<400>>,SaberBase::LOCKUP_NORMAL,Int<1>>,ResponsiveLightningBlockL<Strobe<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,AudioFlicker<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,Blue>,50,1>,TrConcat<TrExtend<200,TrInstant>,AlphaL<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,Bump<Scale<BladeAngle<>,Int<10000>,Int<21000>>,Int<10000>>>,TrFade<200>>,TrConcat<TrInstant,RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,TrFade<400>>,Int<1>>,LockupTrL<AlphaL<TransitionEffect<RandomPerLEDFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<255,255,255>>>,BrownNoiseFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<255,255,255>>,Int<300>>,TrExtend<4000,TrInstant>,TrFade<4000>,EFFECT_DRAG_BEGIN>,SmoothStep<Scale<TwistAngle<>,IntArg<DRAG_SIZE_ARG,28000>,Int<30000>>,Int<3000>>>,TrWipeIn<200>,TrWipe<200>,SaberBase::LOCKUP_DRAG,Int<1>>,LockupTrL<AlphaL<Stripes<2000,4000,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>,Mix<Sin<Int<50>>,Black,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>>,Mix<Int<4096>,Black,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>>>,SmoothStep<Scale<TwistAngle<>,IntArg<MELT_SIZE_ARG,28000>,Int<30000>>,Int<3000>>>,TrConcat<TrExtend<4000,TrWipeIn<200>>,AlphaL<HumpFlicker<Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>,RotateColorsX<Int<3000>,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>>,100>,SmoothStep<Scale<TwistAngle<>,IntArg<MELT_SIZE_ARG,28000>,Int<30000>>,Int<3000>>>,TrFade<4000>>,TrWipe<200>,SaberBase::LOCKUP_MELT,Int<1>>,InOutTrL<TrWipeX<BendTimePowInvX<IgnitionTime<300>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrWipeInX<BendTimePowInvX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,Black>>>>;
/*
Add to preset as StylePtr<ControlMainResponsiveFlameRealFlameGradientBaseColor>()
--------------------------------------------------------------------------*/
/*--------------------------------- ControlMainBladeofTalzinBaseColor -------------------------
copyright Fett263 Ahsoka (Primary Blade) OS7 Style
https://www.fett263.com/fett263-proffieOS7-style-library.html#Ahsoka
OS7.14 v2.241p
Single Style
Base Style: Blade of Talzin


--Effects Included--
Ignition Effect: Standard Ignition [Color: IgnitionColorArg]
Retraction Effect: Standard Retraction [Color: RetractionColorArg]
Lockup Effect:
0: mainLockMulti0Shape - Begin: Real Clash - Style: Intensity AudioFlicker - End: Full Blade Absorb
[Color: LockupColorArg]
Lightning Block Effect:
0: mainLBMulti0Shape - Begin: Responsive Impact - Style: Strobing AudioFlicker - End: Full Blade Absorb
[Color: LBColorArg]
Drag Effect:
0: mainDragMulti0Shape - Begin: Wipe In - Style: Intensity Sparking Drag - End: Wipe Out
[Color: DragColorArg]
Melt Effect:
0: mainMeltMulti0Shape - Begin: Wipe In - Style: Intensity Melt - End: Wipe Out
[Color: StabColorArg]
Blast Effect: Blast Wave (Random) [Color: BlastColorArg]
Clash Effect: Real Clash V1 [Color: ClashColorArg]
*/
using ControlMainBladeofTalzinBaseColor = Layers<StaticFire<Mix<SmoothStep<Scale<BladeAngle<>,Int<38000>,Int<23000>>,Int<8000>>,Mix<Int<400>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>>,Mix<Int<6000>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>>>,StripesX<Int<14000>,Scale<BladeAngle<>,Int<-5>,Int<-50>>,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>,Mix<Scale<HoldPeakF<SwingSpeed<250>,Int<1000>,Int<8000>>,Int<6000>,Int<16000>>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>>>,0,2,4,2000,2>,TransitionEffectL<TrWaveX<RgbArg<BLAST_COLOR_ARG,Rgb<255,255,255>>,Scale<EffectRandomF<EFFECT_BLAST>,Int<100>,Int<400>>,Int<100>,Scale<EffectPosition<EFFECT_BLAST>,Int<100>,Int<400>>,Scale<EffectPosition<EFFECT_BLAST>,Int<28000>,Int<8000>>>,EFFECT_BLAST>,Mix<IsLessThan<ClashImpactF<>,Int<26000>>,TransitionEffectL<TrConcat<TrInstant,AlphaL<RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<ClashImpactF<>,Int<12000>,Int<60000>>>>,TrFadeX<Scale<ClashImpactF<>,Int<200>,Int<400>>>>,EFFECT_CLASH>,TransitionEffectL<TrWaveX<RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>,Scale<ClashImpactF<>,Int<100>,Int<400>>,Int<100>,Scale<ClashImpactF<>,Int<100>,Int<400>>,Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>>,EFFECT_CLASH>>,LockupTrL<TransitionEffect<AlphaL<AlphaMixL<Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<22000>>>,AudioFlicker<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<12000>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>>>,BrownNoiseFlicker<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<12000>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>>,300>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<22000>>>>,AlphaL<AudioFlicker<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<20000>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,TrExtend<5000,TrInstant>,TrFade<5000>,EFFECT_LOCKUP_BEGIN>,TrConcat<TrJoin<TrDelay<50>,TrInstant>,Mix<IsLessThan<ClashImpactF<>,Int<26000>>,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,AlphaL<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<ClashImpactF<>,Int<20000>,Int<60000>>>>>,TrFade<300>>,TrConcat<TrInstant,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,TrFade<400>>,SaberBase::LOCKUP_NORMAL,Int<1>>,ResponsiveLightningBlockL<Strobe<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,AudioFlicker<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,Blue>,50,1>,TrConcat<TrExtend<200,TrInstant>,AlphaL<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,Bump<Scale<BladeAngle<>,Int<10000>,Int<21000>>,Int<10000>>>,TrFade<200>>,TrConcat<TrInstant,RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,TrFade<400>>,Int<1>>,LockupTrL<AlphaL<TransitionEffect<RandomPerLEDFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<255,255,255>>>,BrownNoiseFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<255,255,255>>,Int<300>>,TrExtend<4000,TrInstant>,TrFade<4000>,EFFECT_DRAG_BEGIN>,SmoothStep<Scale<TwistAngle<>,IntArg<DRAG_SIZE_ARG,28000>,Int<30000>>,Int<3000>>>,TrWipeIn<200>,TrWipe<200>,SaberBase::LOCKUP_DRAG,Int<1>>,LockupTrL<AlphaL<Stripes<2000,4000,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>,Mix<Sin<Int<50>>,Black,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>>,Mix<Int<4096>,Black,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>>>,SmoothStep<Scale<TwistAngle<>,IntArg<MELT_SIZE_ARG,28000>,Int<30000>>,Int<3000>>>,TrConcat<TrExtend<4000,TrWipeIn<200>>,AlphaL<HumpFlicker<Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>,RotateColorsX<Int<3000>,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>>,100>,SmoothStep<Scale<TwistAngle<>,IntArg<MELT_SIZE_ARG,28000>,Int<30000>>,Int<3000>>>,TrFade<4000>>,TrWipe<200>,SaberBase::LOCKUP_MELT,Int<1>>,InOutTrL<TrWipeX<BendTimePowInvX<IgnitionTime<300>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrWipeInX<BendTimePowInvX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,Black>>;
/*
Add to preset as StylePtr<ControlMainBladeofTalzinBaseColor>()
--------------------------------------------------------------------------*/
Preset presets[] = {
    {"FatherR1", "tracks/vader7.wav", StylePtr<twistyVader>(), StylePtr<twistyVader>(), "FatherR1"},
    {"FatherANH", "tracks/vader1.wav", StylePtr<twistyVader>(), StylePtr<twistyVader>(), "FatherANH"},
    {"FatherESB", "tracks/vader5.wav", StylePtr<twistyVader>(), StylePtr<twistyVader>(), "FatherESB"},
    {"FatherROTJ", "tracks/vader2.wav", StylePtr<twistyVader>(), StylePtr<twistyVader>(), "FatherROTJ"},
    {"OB4_V2Death_Star", "tracks/obi2.wav", StylePtr<twistyObiCloneWars>(), StylePtr<twistyObiCloneWars>(), "Nomad"},
    {"BMF", "tracks/windu1.wav", StylePtr<twistyMaceROTS>(), StylePtr<twistyMaceROTS>(), "BMF"},
    {"ANH_GraflexV2", "tracks/mars.wav", StylePtr<twistyLukeANH>(), StylePtr<twistyLukeANH>(), "ANH_GraflexV2"},
    {"ANH_TrainingV2", "tracks/mars.wav", StylePtr<twistyLukeANH>(), StylePtr<twistyLukeANH>(), "ANH_TrainingV2"},
    {"ESB_Graflex_V2", "tracks/mars.wav", StylePtr<twistyLukeANH>(), StylePtr<twistyLukeANH>(), "ESB_Graflex_V2"},
    {"The_ReturnV2", "tracks/mars.wav", StylePtr<twistyLukeROTJ>(), StylePtr<twistyLukeROTJ>(), "The_ReturnV2"},
    {"OutcastKnight", "tracks/mars.wav", StylePtr<ControlMainHyperResponsiveRotoscopeOriginalTrilogyBaseColor>(), StylePtr<ControlMainHyperResponsiveRotoscopeOriginalTrilogyBaseColor>(), "OutcastKnight"},
    {"OutcastKnight", "tracks/mars.wav", StylePtr<twistyAhsokaLive>(), StylePtr<twistyAhsokaLive>(), "OutcastKnight"},
    {"OutcastKnight", "tracks/mars.wav", StylePtr<twistyReyGold>(), StylePtr<twistyReyGold>(), "OutcastKnight"},
    {"Fire", "tracks/mars.wav", StylePtr<ControlMainResponsiveFlameRealFlameGradientBaseColor>(), StylePtr<ControlMainResponsiveFlameRealFlameGradientBaseColor>(), "fire"},
    {"Great_Mother_V2", "tracks/mars.wav", StylePtr<ControlMainBladeofTalzinBaseColor>(), StylePtr<ControlMainBladeofTalzinBaseColor>(), "morgan"}
};


BladeConfig blades[] = {
    {0, WS281XBladePtr<128, bladePin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3>>(),
     WS281XBladePtr<30, blade2Pin, Color8::GRB, PowerPINS<bladePowerPin4, bladePowerPin5>>(),
     CONFIGARRAY(presets)},
};
#endif

#ifdef CONFIG_BUTTONS
Button PowerButton(BUTTON_POWER, powerButtonPin, "pow");
Button AuxButton(BUTTON_AUX, auxPin, "aux");
#endif

#ifndef CONFIG_STYLES

#endif
