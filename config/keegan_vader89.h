#ifdef CONFIG_TOP
#include "proffieboard_v3_config.h"

// #define SABER_DOOKU
// #define SABER_VADER
#define SABER_VEEONE
// #define SABER_CAL

#if defined(SABER_DOOKU)
#define ORIENTATION ORIENTATION_USB_TOWARDS_BLADE
#define ORIENTATION_ROTATION 0,40.0,0
#define AUDIO_CLASH_SUPPRESSION_LEVEL 1
#define CLASH_THRESHOLD_G 1.50
#define FILTER_CUTOFF_FREQUENCY 75
#define VOLUME 1800
#define NUM_BLADES 2
#elif defined(SABER_VADER)
#define ORIENTATION ORIENTATION_USB_TOWARDS_BLADE
#define AUDIO_CLASH_SUPPRESSION_LEVEL 3
#define CLASH_THRESHOLD_G 1.0
#define FILTER_CUTOFF_FREQUENCY 150
#define VOLUME 1800
#define NUM_BLADES 2
#elif defined(SABER_VEEONE)
#define ORIENTATION ORIENTATION_FETS_TOWARDS_BLADE
#define AUDIO_CLASH_SUPPRESSION_LEVEL 3
#define CLASH_THRESHOLD_G 1.0
#define FILTER_CUTOFF_FREQUENCY 150
#define VOLUME 1800
#define NUM_BLADES 5
#define SHARED_POWER_PINS
#elif defined(SABER_CAL)
#define ORIENTATION ORIENTATION_USB_TOWARDS_BLADE
#define AUDIO_CLASH_SUPPRESSION_LEVEL 1.5
#define CLASH_THRESHOLD_G 1.25
#define FILTER_CUTOFF_FREQUENCY 75
#define VOLUME 2500
#define NUM_BLADES 2
#endif

#define NUM_BUTTONS 2
#define BOOT_VOLUME 100

const unsigned int maxLedsPerStrip = 144;

#define ENABLE_AUDIO
#define ENABLE_MOTION
#define ENABLE_WS2811
#define ENABLE_SD
#define ENABLE_SERIAL

#define SAVE_STATE
#define SAVE_PRESET

#define ENABLE_ALL_EDIT_OPTIONS // required for Edit Mode functionality
#define FETT263_EDIT_MODE_MENU // required for menu system
#define DISABLE_BASIC_PARSER_STYLES // required for memory saving and using built-in styles for ProffieOS Workbench
#define FETT263_SAY_COLOR_LIST // recommended to enable spoken color names in Color List editing
#define FETT263_SAY_COLOR_LIST_CC // recommended to enable spoken color names for Color List Color Change Mode
#define FETT263_SAY_BATTERY_PERCENT // Spoken Battery Level in volts and percent (point down for volts, parallel or up for percent)

#define FETT263_QUOTE_PLAYER_START_ON

// Only want to change color from the edit menu
#define DISABLE_COLOR_CHANGE
#define FETT263_FORCE_PUSH_ALWAYS_ON
#define FETT263_DISABLE_CHANGE_FONT

#define FETT263_USE_BC_MELT_STAB 
#define FETT263_CIRCULAR_VOLUME_MENU
#define FETT263_CIRCULAR_DIM_MENU

#define COLORWHEEL_ZOOM
//#define DISABLE_DIAGNOSTIC_COMMANDS

//#define FETT263_MULTI_PHASE
#define FETT263_SPECIAL_ABILITIES
#define DISABLE_BASIC_PARSER_STYLES

//#define FETT263_TWIST_ON_NO_BM
//#define FETT263_TWIST_ON
//#define FETT263_TWIST_OFF

//#define FETT263_STAB_ON_NO_BM
//#define FETT263_STAB_ON

//#define FETT263_SWING_ON_SPEED 500
//#define FETT263_SWING_ON_NO_BM
//#define FETT263_SWING_ON
//#define FETT263_SWING_OFF

#define MOTION_TIMEOUT 60 * 1 * 1000
#define IDLE_OFF_TIME 60 * 3 * 1000

#define COLOR_CHANGE_DIRECT
#define NO_REPEAT_RANDOM
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

using BlinkyRedPreset = Layers<Red,InOutTrL<TrInstant,TrInstant,TransitionLoop<Black,TrConcat<TrDelay<3000>,Red,TrBoing<2000,5>>>>>;

using BlinkyGreenPreset = Layers<Green,InOutTrL<TrInstant,TrInstant,TransitionLoop<Green,TrConcat<TrBoing<3000,9>,Black,TrDelay<2000>>>>>;
//TOP CC
/* copyright Fett263 KyloRen (Accent LED / PCB) OS6 Style
https://fett263.com/fett263-proffieOS6-style-library.html#KyloRen
OS6.7 v4.021
Single Style
Base Style: Kylo Ren Unstable (Film Based)

Off Behavior: Slow Pulse Off-On

Base Color: Rgb<0,0,255> (0)

--Effects Included--
Ignition Effect: Glitch On
Retraction Effect: Cycle Down
CoolDown Effect: Unstable Cool Down Reverse
Lockup Effect: Lockup Flash
LightningBlock Effect: Lightning After Effect
Blast Effect: Blast Wave Up (Sound Based)
Clash Effect: Real Clash V1 Up
*/
using CrystalChamberTopPreset = Layers<StaticFire<BrownNoiseFlicker<RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,RandomPerLEDFlicker<Mix<Int<3213>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>,Mix<Int<7710>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>>,300>,Mix<Int<10280>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>,0,6,10,1000,2>,TransitionEffectL<TrConcat<TrJoin<TrDelayX<RetractionTime<5000>>,TrInstant>,Stripes<3000,3500,RgbArg<RETRACTION_COLOR_ARG,Rgb<255,255,255>>,RandomPerLEDFlicker<Mix<Int<7710>,Black,RgbArg<RETRACTION_COLOR_ARG,Rgb<255,255,255>>>,Black>,BrownNoiseFlicker<RgbArg<RETRACTION_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<3855>,Black,RgbArg<RETRACTION_COLOR_ARG,Rgb<255,255,255>>>,200>,RandomPerLEDFlicker<Mix<Int<3137>,Black,RgbArg<RETRACTION_COLOR_ARG,Rgb<255,255,255>>>,Mix<Int<3855>,Black,RgbArg<RETRACTION_COLOR_ARG,Rgb<255,255,255>>>>>,TrFade<800>>,EFFECT_RETRACTION>,TransitionEffectL<TrWaveX<RgbArg<BLAST_COLOR_ARG,Rgb<255,255,255>>,Scale<WavLen<>,Int<100>,Int<400>>,Int<100>,Scale<WavLen<>,Int<100>,Int<400>>,Int<0>>,EFFECT_BLAST>,Mix<IsLessThan<ClashImpactF<>,Int<26000>>,TransitionEffectL<TrWaveX<RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>,Scale<ClashImpactF<>,Int<100>,Int<400>>,Int<100>,Scale<ClashImpactF<>,Int<100>,Int<400>>,Int<0>>,EFFECT_CLASH>,AlphaL<White,Int<0>>>,TransitionEffectL<TrConcat<TrInstant,AlphaL<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,SmoothStep<ClashImpactF<>,Int<-4000>>>,TrFadeX<Scale<ClashImpactF<>,Int<100>,Int<300>>>>,EFFECT_LOCKUP_BEGIN>,TransitionEffectL<TrConcat<TrInstant,AlphaL<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,SmoothStep<ClashImpactF<>,Int<-4000>>>,TrFadeX<Scale<ClashImpactF<>,Int<100>,Int<300>>>>,EFFECT_LOCKUP_END>,LockupTrL<AlphaL<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,Int<0>>,TrInstant,TrConcat<TrInstant,Strobe<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,AudioFlicker<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,Blue>,50,1>,TrFade<1000>>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,InOutTrL<TrConcat<TrJoin<TrDelayX<Mult<IgnitionTime<3000>,Int<16384>>>,TrWipeX<Mult<IgnitionTime<3000>,Int<16384>>>>,Mix<SmoothStep<NoisySoundLevel,Int<-1>>,Black,RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>>,TrWipeX<Mult<IgnitionTime<3000>,Int<16384>>>>,TrColorCycleX<RetractionTime<5000>>,Pulsing<Black,RgbArg<OFF_COLOR_ARG,Rgb<2,72,255>>,8000>>>;

//BOTTOM CC

/* copyright Fett263 KyloRen (Accent LED / PCB) OS6 Style
https://fett263.com/fett263-proffieOS6-style-library.html#KyloRen
OS6.7 v4.021
Single Style
Base Style: Kylo Ren Unstable (Film Based)

Off Behavior: Slow Pulse Off-On

Base Color: Rgb<0,0,255> (0)

--Effects Included--
Ignition Effect: Glitch On
Retraction Effect: Cycle Down
CoolDown Effect: Unstable Cool Down Reverse
Lockup Effect: Lockup Flash
LightningBlock Effect: Lightning After Effect
Blast Effect: Blast Wave Up (Sound Based)
Clash Effect: Real Clash V1 Up
*/
using CrystalChamberBottomPreset = Layers<StaticFire<BrownNoiseFlicker<RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,RandomPerLEDFlicker<Mix<Int<3213>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>,Mix<Int<7710>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>>,300>,Mix<Int<10280>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>,0,6,10,1000,2>,TransitionEffectL<TrConcat<TrJoin<TrDelayX<RetractionTime<5000>>,TrInstant>,Stripes<3000,3500,RgbArg<RETRACTION_COLOR_ARG,Rgb<255,255,255>>,RandomPerLEDFlicker<Mix<Int<7710>,Black,RgbArg<RETRACTION_COLOR_ARG,Rgb<255,255,255>>>,Black>,BrownNoiseFlicker<RgbArg<RETRACTION_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<3855>,Black,RgbArg<RETRACTION_COLOR_ARG,Rgb<255,255,255>>>,200>,RandomPerLEDFlicker<Mix<Int<3137>,Black,RgbArg<RETRACTION_COLOR_ARG,Rgb<255,255,255>>>,Mix<Int<3855>,Black,RgbArg<RETRACTION_COLOR_ARG,Rgb<255,255,255>>>>>,TrFade<800>>,EFFECT_RETRACTION>,TransitionEffectL<TrWaveX<RgbArg<BLAST_COLOR_ARG,Rgb<255,255,255>>,Scale<WavLen<>,Int<100>,Int<400>>,Int<100>,Scale<WavLen<>,Int<100>,Int<400>>,Int<0>>,EFFECT_BLAST>,Mix<IsLessThan<ClashImpactF<>,Int<26000>>,TransitionEffectL<TrWaveX<RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>,Scale<ClashImpactF<>,Int<100>,Int<400>>,Int<100>,Scale<ClashImpactF<>,Int<100>,Int<400>>,Int<0>>,EFFECT_CLASH>,AlphaL<White,Int<0>>>,TransitionEffectL<TrConcat<TrInstant,AlphaL<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,SmoothStep<ClashImpactF<>,Int<-4000>>>,TrFadeX<Scale<ClashImpactF<>,Int<100>,Int<300>>>>,EFFECT_LOCKUP_BEGIN>,TransitionEffectL<TrConcat<TrInstant,AlphaL<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,SmoothStep<ClashImpactF<>,Int<-4000>>>,TrFadeX<Scale<ClashImpactF<>,Int<100>,Int<300>>>>,EFFECT_LOCKUP_END>,LockupTrL<AlphaL<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,Int<0>>,TrInstant,TrConcat<TrInstant,Strobe<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,AudioFlicker<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,Blue>,50,1>,TrFade<1000>>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,InOutTrL<TrConcat<TrJoin<TrDelayX<Mult<IgnitionTime<3000>,Int<16384>>>,TrWipeX<Mult<IgnitionTime<3000>,Int<16384>>>>,Mix<SmoothStep<NoisySoundLevel,Int<-1>>,Black,RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>>,TrWipeX<Mult<IgnitionTime<3000>,Int<16384>>>>,TrColorCycleX<RetractionTime<5000>>,Pulsing<Black,RgbArg<OFF_COLOR_ARG,Rgb<2,72,255>>,8000>>>;

/*--------------------------------- MainPresetFett263OriginalTrilogyFett263 -------------------------
copyright Fett263 Rotoscope (Primary Blade) OS7 Style
https://fett263library.com/early-access/#Rotoscope
OS7.14 v3.1
Single Style
Base Style: Audio Rotoscope - Single Color (Original Trilogy)


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
Stab Effect: AudioFlicker Stab [Color: StabColorArg]
Interactive Blast: Random Blasts - Default Level (Uses Style Option 2 for Editing): 1000 ms
Interactive Blast control requires blast.wav files in font. When Blast is triggered blast.wav will play, to deflect blast (blst.wav and visual effect) swing within 1000ms of blaster sound ending. Random number of blasts from 1 to multiple possible. Only one style per preset can contain.
Blast Effect: Blast Wave (Random) [Color: BlastColorArg]
Clash Effect: Real Clash V1 [Color: ClashColorArg]
Battery Level: % Blade (Base Color)
Display Volume: % Blade [Color: BaseColorArg]
*/
using MainPresetFett263OriginalTrilogyFett263 = Layers<AudioFlicker<Stripes<10000,-2600,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,Mix<Int<7710>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,Mix<Int<16448>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>,TransitionEffectL<TrConcat<TrJoin<TrDelayX<WavLen<>>,TrWipeIn<200>>,AlphaL<AudioFlickerL<RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>,SmoothStep<IntArg<MELT_SIZE_ARG,28000>,Int<2000>>>,TrWipe<200>>,EFFECT_STAB>,TransitionEffectL<TrWaveX<RgbArg<BLAST_COLOR_ARG,Rgb<255,28,0>>,Scale<EffectRandomF<EFFECT_BLAST>,Int<100>,Int<400>>,Int<100>,Scale<EffectPosition<EFFECT_BLAST>,Int<100>,Int<400>>,Scale<EffectPosition<EFFECT_BLAST>,Int<28000>,Int<8000>>>,EFFECT_BLAST>,Mix<IsLessThan<ClashImpactF<>,Int<26000>>,TransitionEffectL<TrConcat<TrInstant,AlphaL<RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<ClashImpactF<>,Int<12000>,Int<60000>>>>,TrFadeX<Scale<ClashImpactF<>,Int<200>,Int<400>>>>,EFFECT_CLASH>,TransitionEffectL<TrWaveX<RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>,Scale<ClashImpactF<>,Int<100>,Int<400>>,Int<100>,Scale<ClashImpactF<>,Int<100>,Int<400>>,Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>>,EFFECT_CLASH>>,LockupTrL<TransitionEffect<AlphaL<AlphaMixL<Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<22000>>>,AudioFlicker<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<12000>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>>>,BrownNoiseFlicker<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<12000>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>>,300>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<22000>>>>,AlphaL<AudioFlicker<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<20000>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,TrExtend<5000,TrInstant>,TrFade<5000>,EFFECT_LOCKUP_BEGIN>,TrConcat<TrJoin<TrDelay<50>,TrInstant>,Mix<IsLessThan<ClashImpactF<>,Int<26000>>,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,AlphaL<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<ClashImpactF<>,Int<20000>,Int<60000>>>>>,TrFade<300>>,TrConcat<TrInstant,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,TrFade<400>>,SaberBase::LOCKUP_NORMAL,Int<1>>,ResponsiveLightningBlockL<Strobe<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,AudioFlicker<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,Blue>,50,1>,TrConcat<TrExtend<200,TrInstant>,AlphaL<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,Bump<Scale<BladeAngle<>,Int<10000>,Int<21000>>,Int<10000>>>,TrFade<200>>,TrConcat<TrInstant,RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,TrFade<400>>,Int<1>>,LockupTrL<AlphaL<TransitionEffect<RandomPerLEDFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<255,255,255>>>,BrownNoiseFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<255,255,255>>,Int<300>>,TrExtend<4000,TrInstant>,TrFade<4000>,EFFECT_DRAG_BEGIN>,SmoothStep<Scale<TwistAngle<>,IntArg<DRAG_SIZE_ARG,28000>,Int<30000>>,Int<3000>>>,TrWipeIn<200>,TrWipe<200>,SaberBase::LOCKUP_DRAG,Int<1>>,LockupTrL<AlphaL<Stripes<2000,4000,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>,Mix<Sin<Int<50>>,Black,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>>,Mix<Int<4096>,Black,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>>>,SmoothStep<Scale<TwistAngle<>,IntArg<MELT_SIZE_ARG,28000>,Int<30000>>,Int<3000>>>,TrConcat<TrExtend<4000,TrWipeIn<200>>,AlphaL<HumpFlicker<Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>,RotateColorsX<Int<3000>,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>>,100>,SmoothStep<Scale<TwistAngle<>,IntArg<MELT_SIZE_ARG,28000>,Int<30000>>,Int<3000>>>,TrFade<4000>>,TrWipe<200>,SaberBase::LOCKUP_MELT,Int<1>>,TransitionEffectL<TrConcat<TrDelay<100>,AlphaL<White,Int<0>>,TrDoEffect<TrInstant,EFFECT_GAME_CHOICE>>,EFFECT_INTERACTIVE_BLAST>,TransitionEffectL<TrConcat<TrExtendX<Sum<WavLen<EFFECT_INTERACTIVE_BLAST>,IntArg<STYLE_OPTION2_ARG,1000>>,TrInstant>,TransitionPulseL<TrDoEffect<TrInstant,EFFECT_BLAST>,ThresholdPulseF<SwingSpeed<300>,Int<16000>>>,TrConcat<TrDelay<150>,TrRandom<TrDoEffect<TrInstant,EFFECT_INTERACTIVE_BLAST>,TrInstant,TrDoEffect<TrInstant,EFFECT_INTERACTIVE_BLAST>,TrDoEffect<TrInstant,EFFECT_INTERACTIVE_BLAST>>>>,EFFECT_GAME_CHOICE>,InOutTrL<TrWipeX<BendTimePowInvX<IgnitionTime<300>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrWipeInX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,Black>,TransitionEffectL<TrConcat<TrJoin<TrDelay<2000>,TrWipe<1000>>,AlphaL<RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,SmoothStep<BatteryLevel,Int<-10>>>,TrWipeIn<1000>>,EFFECT_BATTERY_LEVEL>,TransitionEffectL<TrConcat<TrExtend<2000,TrWipe<100>>,AlphaL<RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,SmoothStep<VolumeLevel,Int<-1>>>,TrFade<300>>,EFFECT_VOLUME_LEVEL>>;
/*
Add to preset as StylePtr<MainPresetFett263OriginalTrilogyFett263>()
--------------------------------------------------------------------------*/

/*--------------------------------- AccentPresetFett263OriginalTrilogyFett263 -------------------------
copyright Fett263 Rotoscope (Accent LED / PCB) OS7 Style
https://fett263library.com/early-access/#Rotoscope
OS7.14 v3.1
Single Style
Base Style: Hyper Responsive Rotoscope (Original Trilogy)

Off Behavior: Off [Color: OffColorArg]


--Effects Included--
Ignition Effect: Instant [Color: IgnitionColorArg]
Retraction Effect: Instant [Color: RetractionColorArg]
Lockup Effect: NoneLightning Block Effect: NoneDrag Effect:
0: accentDragMulti0Shape - Begin: Wipe In - Style: Intensity Sparking Drag - End: Wipe Out
[Color: DragColorArg]
Melt Effect:
0: accentMeltMulti0Shape - Begin: Wipe In - Style: Intensity Melt - End: Wipe Out
[Color: StabColorArg]
*/
using AccentPresetFett263OriginalTrilogyFett263 = Layers<Mix<HoldPeakF<SwingSpeed<250>,Scale<SwingAcceleration<100>,Int<50>,Int<500>>,Scale<SwingAcceleration<>,Int<20000>,Int<10000>>>,RandomFlicker<StripesX<Int<15000>,Scale<HoldPeakF<SwingSpeed<200>,Scale<SwingAcceleration<100>,Int<50>,Int<300>>,Scale<SwingAcceleration<100>,Int<24000>,Int<16000>>>,Int<-3200>,Int<-200>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,Mix<Int<7710>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,Mix<Int<19276>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>,LockupTrL<AlphaL<TransitionEffect<RandomPerLEDFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<255,255,255>>>,BrownNoiseFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<255,255,255>>,Int<300>>,TrExtend<4000,TrInstant>,TrFade<4000>,EFFECT_DRAG_BEGIN>,SmoothStep<Scale<TwistAngle<>,IntArg<DRAG_SIZE_ARG,31000>,Int<30000>>,Int<3000>>>,TrWipeIn<200>,TrWipe<200>,SaberBase::LOCKUP_DRAG,Int<1>>,LockupTrL<AlphaL<Stripes<2000,4000,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>,Mix<Sin<Int<50>>,Black,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>>,Mix<Int<4096>,Black,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>>>,SmoothStep<Scale<TwistAngle<>,IntArg<MELT_SIZE_ARG,26000>,Int<30000>>,Int<3000>>>,TrConcat<TrExtend<4000,TrWipeIn<200>>,AlphaL<HumpFlicker<Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>,RotateColorsX<Int<3000>,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>>,100>,SmoothStep<Scale<TwistAngle<>,IntArg<MELT_SIZE_ARG,26000>,Int<30000>>,Int<3000>>>,TrFade<4000>>,TrWipe<200>,SaberBase::LOCKUP_MELT,Int<1>>,InOutTrL<TrInstant,TrInstant,Black>>;
/*
Add to preset as StylePtr<AccentPresetFett263OriginalTrilogyFett263>()
--------------------------------------------------------------------------*/


/*--------------------------------- MainPresetFett263PrequelsFett263 -------------------------
copyright Fett263 Rotoscope (Primary Blade) OS7 Style
https://fett263library.com/early-access/#Rotoscope
OS7.14 v3.1
Single Style
Base Style: Audio Rotoscope - Single Color (Prequels)


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
Stab Effect: AudioFlicker Stab [Color: StabColorArg]
Interactive Blast: Random Blasts - Default Level (Uses Style Option 2 for Editing): 1000 ms
Interactive Blast control requires blast.wav files in font. When Blast is triggered blast.wav will play, to deflect blast (blst.wav and visual effect) swing within 1000ms of blaster sound ending. Random number of blasts from 1 to multiple possible. Only one style per preset can contain.
Blast Effect: Blast Wave (Random) [Color: BlastColorArg]
Clash Effect: Real Clash V1 [Color: ClashColorArg]
Battery Level: % Blade (Base Color)
Display Volume: % Blade [Color: BaseColorArg]
*/
using MainPresetFett263PrequelsFett263 = Layers<AudioFlicker<Stripes<24000,-1400,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,Mix<Int<11565>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,Mix<Int<16448>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>,TransitionEffectL<TrConcat<TrJoin<TrDelayX<WavLen<>>,TrWipeIn<200>>,AlphaL<AudioFlickerL<RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>,SmoothStep<IntArg<MELT_SIZE_ARG,28000>,Int<2000>>>,TrWipe<200>>,EFFECT_STAB>,TransitionEffectL<TrWaveX<RgbArg<BLAST_COLOR_ARG,Rgb<255,28,0>>,Scale<EffectRandomF<EFFECT_BLAST>,Int<100>,Int<400>>,Int<100>,Scale<EffectPosition<EFFECT_BLAST>,Int<100>,Int<400>>,Scale<EffectPosition<EFFECT_BLAST>,Int<28000>,Int<8000>>>,EFFECT_BLAST>,Mix<IsLessThan<ClashImpactF<>,Int<26000>>,TransitionEffectL<TrConcat<TrInstant,AlphaL<RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<ClashImpactF<>,Int<12000>,Int<60000>>>>,TrFadeX<Scale<ClashImpactF<>,Int<200>,Int<400>>>>,EFFECT_CLASH>,TransitionEffectL<TrWaveX<RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>,Scale<ClashImpactF<>,Int<100>,Int<400>>,Int<100>,Scale<ClashImpactF<>,Int<100>,Int<400>>,Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>>,EFFECT_CLASH>>,LockupTrL<TransitionEffect<AlphaL<AlphaMixL<Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<22000>>>,AudioFlicker<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<12000>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>>>,BrownNoiseFlicker<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<12000>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>>,300>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<22000>>>>,AlphaL<AudioFlicker<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<20000>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,TrExtend<5000,TrInstant>,TrFade<5000>,EFFECT_LOCKUP_BEGIN>,TrConcat<TrJoin<TrDelay<50>,TrInstant>,Mix<IsLessThan<ClashImpactF<>,Int<26000>>,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,AlphaL<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<ClashImpactF<>,Int<20000>,Int<60000>>>>>,TrFade<300>>,TrConcat<TrInstant,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,TrFade<400>>,SaberBase::LOCKUP_NORMAL,Int<1>>,ResponsiveLightningBlockL<Strobe<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,AudioFlicker<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,Blue>,50,1>,TrConcat<TrExtend<200,TrInstant>,AlphaL<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,Bump<Scale<BladeAngle<>,Int<10000>,Int<21000>>,Int<10000>>>,TrFade<200>>,TrConcat<TrInstant,RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,TrFade<400>>,Int<1>>,LockupTrL<AlphaL<TransitionEffect<RandomPerLEDFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<255,255,255>>>,BrownNoiseFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<255,255,255>>,Int<300>>,TrExtend<4000,TrInstant>,TrFade<4000>,EFFECT_DRAG_BEGIN>,SmoothStep<Scale<TwistAngle<>,IntArg<DRAG_SIZE_ARG,28000>,Int<30000>>,Int<3000>>>,TrWipeIn<200>,TrWipe<200>,SaberBase::LOCKUP_DRAG,Int<1>>,LockupTrL<AlphaL<Stripes<2000,4000,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>,Mix<Sin<Int<50>>,Black,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>>,Mix<Int<4096>,Black,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>>>,SmoothStep<Scale<TwistAngle<>,IntArg<MELT_SIZE_ARG,28000>,Int<30000>>,Int<3000>>>,TrConcat<TrExtend<4000,TrWipeIn<200>>,AlphaL<HumpFlicker<Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>,RotateColorsX<Int<3000>,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>>,100>,SmoothStep<Scale<TwistAngle<>,IntArg<MELT_SIZE_ARG,28000>,Int<30000>>,Int<3000>>>,TrFade<4000>>,TrWipe<200>,SaberBase::LOCKUP_MELT,Int<1>>,TransitionEffectL<TrConcat<TrDelay<100>,AlphaL<White,Int<0>>,TrDoEffect<TrInstant,EFFECT_GAME_CHOICE>>,EFFECT_INTERACTIVE_BLAST>,TransitionEffectL<TrConcat<TrExtendX<Sum<WavLen<EFFECT_INTERACTIVE_BLAST>,IntArg<STYLE_OPTION2_ARG,1000>>,TrInstant>,TransitionPulseL<TrDoEffect<TrInstant,EFFECT_BLAST>,ThresholdPulseF<SwingSpeed<300>,Int<16000>>>,TrConcat<TrDelay<150>,TrRandom<TrDoEffect<TrInstant,EFFECT_INTERACTIVE_BLAST>,TrInstant,TrDoEffect<TrInstant,EFFECT_INTERACTIVE_BLAST>,TrDoEffect<TrInstant,EFFECT_INTERACTIVE_BLAST>>>>,EFFECT_GAME_CHOICE>,InOutTrL<TrWipeX<BendTimePowInvX<IgnitionTime<300>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrWipeInX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,Black>,TransitionEffectL<TrConcat<TrJoin<TrDelay<2000>,TrWipe<1000>>,AlphaL<RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,SmoothStep<BatteryLevel,Int<-10>>>,TrWipeIn<1000>>,EFFECT_BATTERY_LEVEL>,TransitionEffectL<TrConcat<TrExtend<2000,TrWipe<100>>,AlphaL<RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,SmoothStep<VolumeLevel,Int<-1>>>,TrFade<300>>,EFFECT_VOLUME_LEVEL>>;
/*
Add to preset as StylePtr<MainPresetFett263PrequelsFett263>()
--------------------------------------------------------------------------*/

/*--------------------------------- AccentPresetFett263PrequelsFett263 -------------------------
copyright Fett263 Rotoscope (Accent LED / PCB) OS7 Style
https://fett263library.com/early-access/#Rotoscope
OS7.14 v3.1
Single Style
Base Style: Hyper Responsive Rotoscope (Prequels)

Off Behavior: Off [Color: OffColorArg]


--Effects Included--
Ignition Effect: Instant [Color: IgnitionColorArg]
Retraction Effect: Instant [Color: RetractionColorArg]
Lockup Effect: NoneLightning Block Effect: NoneDrag Effect:
0: accentDragMulti0Shape - Begin: Wipe In - Style: Intensity Sparking Drag - End: Wipe Out
[Color: DragColorArg]
Melt Effect:
0: accentMeltMulti0Shape - Begin: Wipe In - Style: Intensity Melt - End: Wipe Out
[Color: StabColorArg]
*/
using AccentPresetFett263PrequelsFett263 = Layers<Mix<HoldPeakF<SwingSpeed<250>,Scale<SwingAcceleration<100>,Int<50>,Int<500>>,Scale<SwingAcceleration<>,Int<20000>,Int<10000>>>,RandomFlicker<StripesX<Int<24000>,Scale<HoldPeakF<SwingSpeed<200>,Scale<SwingAcceleration<100>,Int<50>,Int<300>>,Scale<SwingAcceleration<100>,Int<24000>,Int<16000>>>,Int<-1400>,Int<-100>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,Mix<Int<7710>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,Mix<Int<19276>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>,LockupTrL<AlphaL<TransitionEffect<RandomPerLEDFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<255,255,255>>>,BrownNoiseFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<255,255,255>>,Int<300>>,TrExtend<4000,TrInstant>,TrFade<4000>,EFFECT_DRAG_BEGIN>,SmoothStep<Scale<TwistAngle<>,IntArg<DRAG_SIZE_ARG,31000>,Int<30000>>,Int<3000>>>,TrWipeIn<200>,TrWipe<200>,SaberBase::LOCKUP_DRAG,Int<1>>,LockupTrL<AlphaL<Stripes<2000,4000,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>,Mix<Sin<Int<50>>,Black,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>>,Mix<Int<4096>,Black,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>>>,SmoothStep<Scale<TwistAngle<>,IntArg<MELT_SIZE_ARG,26000>,Int<30000>>,Int<3000>>>,TrConcat<TrExtend<4000,TrWipeIn<200>>,AlphaL<HumpFlicker<Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>,RotateColorsX<Int<3000>,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>>,100>,SmoothStep<Scale<TwistAngle<>,IntArg<MELT_SIZE_ARG,26000>,Int<30000>>,Int<3000>>>,TrFade<4000>>,TrWipe<200>,SaberBase::LOCKUP_MELT,Int<1>>,InOutTrL<TrInstant,TrInstant,Black>>;
/*
Add to preset as StylePtr<AccentPresetFett263PrequelsFett263>()
--------------------------------------------------------------------------*/

/*--------------------------------- MainPresetFett263SequelsFett263 -------------------------
copyright Fett263 Rotoscope (Primary Blade) OS7 Style
https://fett263library.com/early-access/#Rotoscope
OS7.14 v3.1
Single Style
Base Style: Audio Rotoscope - Single Color (Sequels)


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
Stab Effect: AudioFlicker Stab [Color: StabColorArg]
Interactive Blast: Random Blasts - Default Level (Uses Style Option 2 for Editing): 1000 ms
Interactive Blast control requires blast.wav files in font. When Blast is triggered blast.wav will play, to deflect blast (blst.wav and visual effect) swing within 1000ms of blaster sound ending. Random number of blasts from 1 to multiple possible. Only one style per preset can contain.
Blast Effect: Blast Wave (Random) [Color: BlastColorArg]
Clash Effect: Real Clash V1 [Color: ClashColorArg]
Battery Level: % Blade (Base Color)
Display Volume: % Blade [Color: BaseColorArg]
*/
using MainPresetFett263SequelsFett263 = Layers<AudioFlicker<Stripes<14000,-4000,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,Mix<Int<7710>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,Mix<Int<16448>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>,TransitionEffectL<TrConcat<TrJoin<TrDelayX<WavLen<>>,TrWipeIn<200>>,AlphaL<AudioFlickerL<RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>,SmoothStep<IntArg<MELT_SIZE_ARG,28000>,Int<2000>>>,TrWipe<200>>,EFFECT_STAB>,TransitionEffectL<TrWaveX<RgbArg<BLAST_COLOR_ARG,Rgb<255,28,0>>,Scale<EffectRandomF<EFFECT_BLAST>,Int<100>,Int<400>>,Int<100>,Scale<EffectPosition<EFFECT_BLAST>,Int<100>,Int<400>>,Scale<EffectPosition<EFFECT_BLAST>,Int<28000>,Int<8000>>>,EFFECT_BLAST>,Mix<IsLessThan<ClashImpactF<>,Int<26000>>,TransitionEffectL<TrConcat<TrInstant,AlphaL<RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<ClashImpactF<>,Int<12000>,Int<60000>>>>,TrFadeX<Scale<ClashImpactF<>,Int<200>,Int<400>>>>,EFFECT_CLASH>,TransitionEffectL<TrWaveX<RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>,Scale<ClashImpactF<>,Int<100>,Int<400>>,Int<100>,Scale<ClashImpactF<>,Int<100>,Int<400>>,Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>>,EFFECT_CLASH>>,LockupTrL<TransitionEffect<AlphaL<AlphaMixL<Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<22000>>>,AudioFlicker<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<12000>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>>>,BrownNoiseFlicker<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<12000>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>>,300>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<22000>>>>,AlphaL<AudioFlicker<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<20000>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,TrExtend<5000,TrInstant>,TrFade<5000>,EFFECT_LOCKUP_BEGIN>,TrConcat<TrJoin<TrDelay<50>,TrInstant>,Mix<IsLessThan<ClashImpactF<>,Int<26000>>,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,AlphaL<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<ClashImpactF<>,Int<20000>,Int<60000>>>>>,TrFade<300>>,TrConcat<TrInstant,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,TrFade<400>>,SaberBase::LOCKUP_NORMAL,Int<1>>,ResponsiveLightningBlockL<Strobe<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,AudioFlicker<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,Blue>,50,1>,TrConcat<TrExtend<200,TrInstant>,AlphaL<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,Bump<Scale<BladeAngle<>,Int<10000>,Int<21000>>,Int<10000>>>,TrFade<200>>,TrConcat<TrInstant,RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,TrFade<400>>,Int<1>>,LockupTrL<AlphaL<TransitionEffect<RandomPerLEDFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<255,255,255>>>,BrownNoiseFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<255,255,255>>,Int<300>>,TrExtend<4000,TrInstant>,TrFade<4000>,EFFECT_DRAG_BEGIN>,SmoothStep<Scale<TwistAngle<>,IntArg<DRAG_SIZE_ARG,28000>,Int<30000>>,Int<3000>>>,TrWipeIn<200>,TrWipe<200>,SaberBase::LOCKUP_DRAG,Int<1>>,LockupTrL<AlphaL<Stripes<2000,4000,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>,Mix<Sin<Int<50>>,Black,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>>,Mix<Int<4096>,Black,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>>>,SmoothStep<Scale<TwistAngle<>,IntArg<MELT_SIZE_ARG,28000>,Int<30000>>,Int<3000>>>,TrConcat<TrExtend<4000,TrWipeIn<200>>,AlphaL<HumpFlicker<Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>,RotateColorsX<Int<3000>,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>>,100>,SmoothStep<Scale<TwistAngle<>,IntArg<MELT_SIZE_ARG,28000>,Int<30000>>,Int<3000>>>,TrFade<4000>>,TrWipe<200>,SaberBase::LOCKUP_MELT,Int<1>>,TransitionEffectL<TrConcat<TrDelay<100>,AlphaL<White,Int<0>>,TrDoEffect<TrInstant,EFFECT_GAME_CHOICE>>,EFFECT_INTERACTIVE_BLAST>,TransitionEffectL<TrConcat<TrExtendX<Sum<WavLen<EFFECT_INTERACTIVE_BLAST>,IntArg<STYLE_OPTION2_ARG,1000>>,TrInstant>,TransitionPulseL<TrDoEffect<TrInstant,EFFECT_BLAST>,ThresholdPulseF<SwingSpeed<300>,Int<16000>>>,TrConcat<TrDelay<150>,TrRandom<TrDoEffect<TrInstant,EFFECT_INTERACTIVE_BLAST>,TrInstant,TrDoEffect<TrInstant,EFFECT_INTERACTIVE_BLAST>,TrDoEffect<TrInstant,EFFECT_INTERACTIVE_BLAST>>>>,EFFECT_GAME_CHOICE>,InOutTrL<TrWipeX<BendTimePowInvX<IgnitionTime<300>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrWipeInX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,Black>,TransitionEffectL<TrConcat<TrJoin<TrDelay<2000>,TrWipe<1000>>,AlphaL<RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,SmoothStep<BatteryLevel,Int<-10>>>,TrWipeIn<1000>>,EFFECT_BATTERY_LEVEL>,TransitionEffectL<TrConcat<TrExtend<2000,TrWipe<100>>,AlphaL<RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,SmoothStep<VolumeLevel,Int<-1>>>,TrFade<300>>,EFFECT_VOLUME_LEVEL>>;
/*
Add to preset as StylePtr<MainPresetFett263SequelsFett263>()
--------------------------------------------------------------------------*/

/*--------------------------------- AccentPresetFett263SequelsFett263 -------------------------
copyright Fett263 Rotoscope (Accent LED / PCB) OS7 Style
https://fett263library.com/early-access/#Rotoscope
OS7.14 v3.1
Single Style
Base Style: Hyper Responsive Rotoscope (Sequels)

Off Behavior: Off [Color: OffColorArg]


--Effects Included--
Ignition Effect: Instant [Color: IgnitionColorArg]
Retraction Effect: Instant [Color: RetractionColorArg]
Lockup Effect: NoneLightning Block Effect: NoneDrag Effect:
0: accentDragMulti0Shape - Begin: Wipe In - Style: Intensity Sparking Drag - End: Wipe Out
[Color: DragColorArg]
Melt Effect:
0: accentMeltMulti0Shape - Begin: Wipe In - Style: Intensity Melt - End: Wipe Out
[Color: StabColorArg]
*/
using AccentPresetFett263SequelsFett263 = Layers<Mix<HoldPeakF<SwingSpeed<250>,Scale<SwingAcceleration<100>,Int<50>,Int<500>>,Scale<SwingAcceleration<>,Int<20000>,Int<10000>>>,RandomFlicker<StripesX<Int<14000>,Scale<HoldPeakF<SwingSpeed<200>,Scale<SwingAcceleration<100>,Int<50>,Int<300>>,Scale<SwingAcceleration<100>,Int<24000>,Int<16000>>>,Int<-4000>,Int<-400>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,Mix<Int<7710>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,Mix<Int<19276>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>,LockupTrL<AlphaL<TransitionEffect<RandomPerLEDFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<255,255,255>>>,BrownNoiseFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<255,255,255>>,Int<300>>,TrExtend<4000,TrInstant>,TrFade<4000>,EFFECT_DRAG_BEGIN>,SmoothStep<Scale<TwistAngle<>,IntArg<DRAG_SIZE_ARG,31000>,Int<30000>>,Int<3000>>>,TrWipeIn<200>,TrWipe<200>,SaberBase::LOCKUP_DRAG,Int<1>>,LockupTrL<AlphaL<Stripes<2000,4000,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>,Mix<Sin<Int<50>>,Black,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>>,Mix<Int<4096>,Black,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>>>,SmoothStep<Scale<TwistAngle<>,IntArg<MELT_SIZE_ARG,26000>,Int<30000>>,Int<3000>>>,TrConcat<TrExtend<4000,TrWipeIn<200>>,AlphaL<HumpFlicker<Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>,RotateColorsX<Int<3000>,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>>,100>,SmoothStep<Scale<TwistAngle<>,IntArg<MELT_SIZE_ARG,26000>,Int<30000>>,Int<3000>>>,TrFade<4000>>,TrWipe<200>,SaberBase::LOCKUP_MELT,Int<1>>,InOutTrL<TrInstant,TrInstant,Black>>;
/*
Add to preset as StylePtr<AccentPresetFett263SequelsFett263>()
--------------------------------------------------------------------------*/
/*--------------------------------- MainPresetFett263KyloRen -------------------------
copyright Fett263 KyloRen (Primary Blade) OS7 Style
https://fett263library.com/early-access/#KyloRen
OS7.14 v3.1
Single Style
Base Style: Kylo Ren Unstable (Film Based)


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
Stab Effect: Sparking Stab [Color: StabColorArg]
Interactive Blast: Random Blasts - Default Level (Uses Style Option 2 for Editing): 1000 ms
Interactive Blast control requires blast.wav files in font. When Blast is triggered blast.wav will play, to deflect blast (blst.wav and visual effect) swing within 1000ms of blaster sound ending. Random number of blasts from 1 to multiple possible. Only one style per preset can contain.
Blast Effect: Blast Wave (Random) [Color: BlastColorArg]
Clash Effect: Real Clash V1 [Color: ClashColorArg]
Battery Level: Blade Location (Green to Red)
Display Volume: Blade Location [Color: BaseColorArg]
*/
using MainPresetFett263KyloRen = Layers<StaticFire<BrownNoiseFlicker<RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,RandomPerLEDFlicker<Mix<Int<3213>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>,Mix<Int<7710>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>>,300>,Mix<Int<10280>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>,0,6,10,1000,2>,TransitionEffectL<TrConcat<TrJoin<TrDelayX<WavLen<>>,TrWipeIn<200>>,AlphaL<RandomPerLEDFlickerL<RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>,SmoothStep<IntArg<MELT_SIZE_ARG,28000>,Int<2000>>>,TrWipe<200>>,EFFECT_STAB>,TransitionEffectL<TrWaveX<RgbArg<BLAST_COLOR_ARG,Rgb<255,255,255>>,Scale<EffectRandomF<EFFECT_BLAST>,Int<100>,Int<400>>,Int<100>,Scale<EffectPosition<EFFECT_BLAST>,Int<100>,Int<400>>,Scale<EffectPosition<EFFECT_BLAST>,Int<28000>,Int<8000>>>,EFFECT_BLAST>,Mix<IsLessThan<ClashImpactF<>,Int<26000>>,TransitionEffectL<TrConcat<TrInstant,AlphaL<RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<ClashImpactF<>,Int<12000>,Int<60000>>>>,TrFadeX<Scale<ClashImpactF<>,Int<200>,Int<400>>>>,EFFECT_CLASH>,TransitionEffectL<TrWaveX<RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>,Scale<ClashImpactF<>,Int<100>,Int<400>>,Int<100>,Scale<ClashImpactF<>,Int<100>,Int<400>>,Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>>,EFFECT_CLASH>>,LockupTrL<TransitionEffect<AlphaL<AlphaMixL<Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<22000>>>,AudioFlicker<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<12000>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>>>,BrownNoiseFlicker<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<12000>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>>,300>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<22000>>>>,AlphaL<AudioFlicker<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<20000>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,TrExtend<5000,TrInstant>,TrFade<5000>,EFFECT_LOCKUP_BEGIN>,TrConcat<TrJoin<TrDelay<50>,TrInstant>,Mix<IsLessThan<ClashImpactF<>,Int<26000>>,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,AlphaL<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<ClashImpactF<>,Int<20000>,Int<60000>>>>>,TrFade<300>>,TrConcat<TrInstant,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,TrFade<400>>,SaberBase::LOCKUP_NORMAL,Int<1>>,ResponsiveLightningBlockL<Strobe<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,AudioFlicker<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,Blue>,50,1>,TrConcat<TrExtend<200,TrInstant>,AlphaL<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,Bump<Scale<BladeAngle<>,Int<10000>,Int<21000>>,Int<10000>>>,TrFade<200>>,TrConcat<TrInstant,RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,TrFade<400>>,Int<1>>,LockupTrL<AlphaL<TransitionEffect<RandomPerLEDFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<255,255,255>>>,BrownNoiseFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<255,255,255>>,Int<300>>,TrExtend<4000,TrInstant>,TrFade<4000>,EFFECT_DRAG_BEGIN>,SmoothStep<Scale<TwistAngle<>,IntArg<DRAG_SIZE_ARG,28000>,Int<30000>>,Int<3000>>>,TrWipeIn<200>,TrWipe<200>,SaberBase::LOCKUP_DRAG,Int<1>>,LockupTrL<AlphaL<Stripes<2000,4000,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>,Mix<Sin<Int<50>>,Black,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>>,Mix<Int<4096>,Black,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>>>,SmoothStep<Scale<TwistAngle<>,IntArg<MELT_SIZE_ARG,28000>,Int<30000>>,Int<3000>>>,TrConcat<TrExtend<4000,TrWipeIn<200>>,AlphaL<HumpFlicker<Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>,RotateColorsX<Int<3000>,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>>,100>,SmoothStep<Scale<TwistAngle<>,IntArg<MELT_SIZE_ARG,28000>,Int<30000>>,Int<3000>>>,TrFade<4000>>,TrWipe<200>,SaberBase::LOCKUP_MELT,Int<1>>,TransitionEffectL<TrConcat<TrDelay<100>,AlphaL<White,Int<0>>,TrDoEffect<TrInstant,EFFECT_GAME_CHOICE>>,EFFECT_INTERACTIVE_BLAST>,TransitionEffectL<TrConcat<TrExtendX<Sum<WavLen<EFFECT_INTERACTIVE_BLAST>,IntArg<STYLE_OPTION2_ARG,1000>>,TrInstant>,TransitionPulseL<TrDoEffect<TrInstant,EFFECT_BLAST>,ThresholdPulseF<SwingSpeed<300>,Int<16000>>>,TrConcat<TrDelay<150>,TrRandom<TrDoEffect<TrInstant,EFFECT_INTERACTIVE_BLAST>,TrInstant,TrDoEffect<TrInstant,EFFECT_INTERACTIVE_BLAST>,TrDoEffect<TrInstant,EFFECT_INTERACTIVE_BLAST>>>>,EFFECT_GAME_CHOICE>,InOutTrL<TrWipeX<BendTimePowInvX<IgnitionTime<300>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrWipeInX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,Black>,TransitionEffectL<TrConcat<TrJoin<TrDelay<2000>,TrInstant>,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<BatteryLevel,Int<10000>>>,TrFade<300>>,EFFECT_BATTERY_LEVEL>,TransitionEffectL<TrConcat<TrExtend<2000,TrFade<100>>,AlphaL<RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,Bump<VolumeLevel,Int<8000>>>,TrFade<300>>,EFFECT_VOLUME_LEVEL>>;
/*
Add to preset as StylePtr<MainPresetFett263KyloRen>()
--------------------------------------------------------------------------*/


/*--------------------------------- AccentPresetFett263KyloRen -------------------------
copyright Fett263 KyloRen (Accent LED / PCB) OS7 Style
https://fett263library.com/early-access/#KyloRen
OS7.14 v3.1
Single Style
Base Style: Kylo Ren Unstable (Film Based)

Off Behavior: Off [Color: OffColorArg]


--Effects Included--
Ignition Effect: Instant [Color: IgnitionColorArg]
Retraction Effect: Instant [Color: RetractionColorArg]
Lockup Effect: NoneLightning Block Effect: NoneDrag Effect:
0: accentDragMulti0Shape - Begin: Wipe In - Style: Intensity Sparking Drag - End: Wipe Out
[Color: DragColorArg]
Melt Effect:
0: accentMeltMulti0Shape - Begin: Wipe In - Style: Intensity Melt - End: Wipe Out
[Color: StabColorArg]
Interactive Blast: Random Blasts - Default Level (Uses Style Option 2 for Editing): 1000 ms
Interactive Blast control requires blast.wav files in font. When Blast is triggered blast.wav will play, to deflect blast (blst.wav and visual effect) swing within 1000ms of blaster sound ending. Random number of blasts from 1 to multiple possible. Only one style per preset can contain.
*/
using AccentPresetFett263KyloRen = Layers<StaticFire<BrownNoiseFlicker<RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,RandomPerLEDFlicker<Mix<Int<3213>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>,Mix<Int<7710>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>>,300>,Mix<Int<10280>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>,0,6,10,1000,2>,LockupTrL<AlphaL<TransitionEffect<RandomPerLEDFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<255,255,255>>>,BrownNoiseFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<255,255,255>>,Int<300>>,TrExtend<4000,TrInstant>,TrFade<4000>,EFFECT_DRAG_BEGIN>,SmoothStep<Scale<TwistAngle<>,IntArg<DRAG_SIZE_ARG,31000>,Int<30000>>,Int<3000>>>,TrWipeIn<200>,TrWipe<200>,SaberBase::LOCKUP_DRAG,Int<1>>,LockupTrL<AlphaL<Stripes<2000,4000,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>,Mix<Sin<Int<50>>,Black,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>>,Mix<Int<4096>,Black,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>>>,SmoothStep<Scale<TwistAngle<>,IntArg<MELT_SIZE_ARG,26000>,Int<30000>>,Int<3000>>>,TrConcat<TrExtend<4000,TrWipeIn<200>>,AlphaL<HumpFlicker<Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>,RotateColorsX<Int<3000>,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>>,100>,SmoothStep<Scale<TwistAngle<>,IntArg<MELT_SIZE_ARG,26000>,Int<30000>>,Int<3000>>>,TrFade<4000>>,TrWipe<200>,SaberBase::LOCKUP_MELT,Int<1>>,InOutTrL<TrInstant,TrInstant,Black>>;
/*
Add to preset as StylePtr<AccentPresetFett263KyloRen>()
--------------------------------------------------------------------------*/

/*--------------------------------- ControlMainCalKestisSurvivorBlueKyberSelectSpecialAbility -------------------------
copyright Fett263 JediSurvivor (Primary Blade) OS7 Style
https://fett263library.com/early-access/#JediSurvivor
OS7.14 v3.1
Single Style
Base Style: Cal Kestis Survivor Blue
Kyber Select Interactive Control: While Blade is On, use selected Special Ability to change color (Phase). Requires Alt Font.

NOTE:This style includes Control Layer. Only one Control Layer should be used per preset.

*This style REQUIRES Alt Fonts alt000/ to alt009/ to be set up. Uses altchng.wav on change.
See https://pod.hubbe.net/sound/alt_sounds.html for more information.
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
Stab Effect: Sparking Stab [Color: StabColorArg]
Interactive Blast: Random Blasts - Default Level (Uses Style Option 2 for Editing): 1000 ms
Interactive Blast control requires blast.wav files in font. When Blast is triggered blast.wav will play, to deflect blast (blst.wav and visual effect) swing within 1000ms of blaster sound ending. Random number of blasts from 1 to multiple possible. Only one style per preset can contain.
Blast Effect: Blast Wave (Random) [Color: BlastColorArg]
Clash Effect: Real Clash V1 [Color: ClashColorArg]
Battery Level: % Blade (Green to Red)
Display Volume: % Blade [Color: BaseColorArg]
Special Ability 1: Next Phase
Special Ability 2: Previous Phase
Special Ability 3: Select Random Phase
Special Ability 4: Toggle Swing Change (Random / Party Mode) Uses tr00.wav or tr/000/000.wav on toggle (mechanical or menu sound)

*/
using ControlMainCalKestisSurvivorBlueKyberSelectSpecialAbility = Layers<StripesX<Scale<HoldPeakF<Sum<EffectPulseF<EFFECT_IGNITION>,EffectPulseF<EFFECT_ALT_SOUND>>,Int<3000>,Int<3000>>,Int<8000>,Int<3000>>,Scale<HoldPeakF<Sum<EffectPulseF<EFFECT_IGNITION>,EffectPulseF<EFFECT_ALT_SOUND>>,Int<3000>,Int<3000>>,Int<-2600>,Int<-3600>>,ColorSelect<AltF,TrInstant,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,RgbArg<ALT_COLOR_ARG,Rgb<0,255,255>>,RgbArg<ALT_COLOR2_ARG,Rgb<0,255,0>>,RgbArg<ALT_COLOR3_ARG,Rgb<80,50,210>>,Rgb<255,0,255>,Rgb<255,68,0>,Rgb<115,15,240>,Rgb<100,100,150>,Rgb<180,130,0>,Rgb<183,12,3>>,Mix<Int<12000>,Black,ColorSelect<AltF,TrInstant,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,RgbArg<ALT_COLOR_ARG,Rgb<0,255,255>>,RgbArg<ALT_COLOR2_ARG,Rgb<0,255,0>>,RgbArg<ALT_COLOR3_ARG,Rgb<80,50,210>>,Rgb<255,0,255>,Rgb<255,68,0>,Rgb<115,15,240>,Rgb<100,100,150>,Rgb<180,130,0>,Rgb<183,12,3>>>,Pulsing<ColorSelect<AltF,TrInstant,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,RgbArg<ALT_COLOR_ARG,Rgb<0,255,255>>,RgbArg<ALT_COLOR2_ARG,Rgb<0,255,0>>,RgbArg<ALT_COLOR3_ARG,Rgb<80,50,210>>,Rgb<255,0,255>,Rgb<255,68,0>,Rgb<115,15,240>,Rgb<100,100,150>,Rgb<180,130,0>,Rgb<183,12,3>>,Mix<Int<8000>,Black,ColorSelect<AltF,TrInstant,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,RgbArg<ALT_COLOR_ARG,Rgb<0,255,255>>,RgbArg<ALT_COLOR2_ARG,Rgb<0,255,0>>,RgbArg<ALT_COLOR3_ARG,Rgb<80,50,210>>,Rgb<255,0,255>,Rgb<255,68,0>,Rgb<115,15,240>,Rgb<100,100,150>,Rgb<180,130,0>,Rgb<183,12,3>>>,1400>>,TransitionEffectL<TrDoEffectAlwaysX<TrInstant,EFFECT_ALT_SOUND,ModF<Sum<AltF,Int<1>>,Int<10>>,Int<-1>>,EFFECT_USER1>,TransitionEffectL<TrDoEffectAlwaysX<TrInstant,EFFECT_ALT_SOUND,ModF<Sum<AltF,Int<-1>>,Int<10>>,Int<-1>>,EFFECT_USER2>,TransitionEffectL<TrDoEffectAlwaysX<TrInstant,EFFECT_ALT_SOUND,ModF<Sum<AltF,Scale<RandomF,Int<1>,Int<9>>>,Int<10>>,Int<-1>>,EFFECT_USER3>,TransitionPulseL<TrSelect<IncrementModuloF<EffectPulseF<EFFECT_USER4>,Int<2>>,TrInstant,TrDoEffectX<TrInstant,EFFECT_ALT_SOUND,ModF<Sum<AltF,Scale<RandomF,Int<1>,Int<9>>>,Int<10>>,Int<-1>>>,ThresholdPulseF<SwingSpeed<320>,Int<31000>>>,TransitionEffectL<TrDoEffectX<TrInstant,EFFECT_TRANSITION_SOUND,Int<0>,Int<-1>>,EFFECT_USER4>,TransitionEffectL<TrConcat<TrJoin<TrDelayX<WavLen<>>,TrWipeIn<200>>,AlphaL<RandomPerLEDFlickerL<RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>,SmoothStep<IntArg<MELT_SIZE_ARG,28000>,Int<2000>>>,TrWipe<200>>,EFFECT_STAB>,TransitionEffectL<TrWaveX<RgbArg<BLAST_COLOR_ARG,Rgb<255,28,0>>,Scale<EffectRandomF<EFFECT_BLAST>,Int<100>,Int<400>>,Int<100>,Scale<EffectPosition<EFFECT_BLAST>,Int<100>,Int<400>>,Scale<EffectPosition<EFFECT_BLAST>,Int<28000>,Int<8000>>>,EFFECT_BLAST>,Mix<IsLessThan<ClashImpactF<>,Int<26000>>,TransitionEffectL<TrConcat<TrInstant,AlphaL<RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<ClashImpactF<>,Int<12000>,Int<60000>>>>,TrFadeX<Scale<ClashImpactF<>,Int<200>,Int<400>>>>,EFFECT_CLASH>,TransitionEffectL<TrWaveX<RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>,Scale<ClashImpactF<>,Int<100>,Int<400>>,Int<100>,Scale<ClashImpactF<>,Int<100>,Int<400>>,Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>>,EFFECT_CLASH>>,LockupTrL<TransitionEffect<AlphaL<AlphaMixL<Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<22000>>>,AudioFlicker<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<12000>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>>>,BrownNoiseFlicker<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<12000>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>>,300>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<22000>>>>,AlphaL<AudioFlicker<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<20000>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,TrExtend<5000,TrInstant>,TrFade<5000>,EFFECT_LOCKUP_BEGIN>,TrConcat<TrJoin<TrDelay<50>,TrInstant>,Mix<IsLessThan<ClashImpactF<>,Int<26000>>,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,AlphaL<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<ClashImpactF<>,Int<20000>,Int<60000>>>>>,TrFade<300>>,TrConcat<TrInstant,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,TrFade<400>>,SaberBase::LOCKUP_NORMAL,Int<1>>,ResponsiveLightningBlockL<Strobe<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,AudioFlicker<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,Blue>,50,1>,TrConcat<TrExtend<200,TrInstant>,AlphaL<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,Bump<Scale<BladeAngle<>,Int<10000>,Int<21000>>,Int<10000>>>,TrFade<200>>,TrConcat<TrInstant,RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,TrFade<400>>,Int<1>>,LockupTrL<AlphaL<TransitionEffect<RandomPerLEDFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<255,255,255>>>,BrownNoiseFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<255,255,255>>,Int<300>>,TrExtend<4000,TrInstant>,TrFade<4000>,EFFECT_DRAG_BEGIN>,SmoothStep<Scale<TwistAngle<>,IntArg<DRAG_SIZE_ARG,28000>,Int<30000>>,Int<3000>>>,TrWipeIn<200>,TrWipe<200>,SaberBase::LOCKUP_DRAG,Int<1>>,LockupTrL<AlphaL<Stripes<2000,4000,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>,Mix<Sin<Int<50>>,Black,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>>,Mix<Int<4096>,Black,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>>>,SmoothStep<Scale<TwistAngle<>,IntArg<MELT_SIZE_ARG,28000>,Int<30000>>,Int<3000>>>,TrConcat<TrExtend<4000,TrWipeIn<200>>,AlphaL<HumpFlicker<Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>,RotateColorsX<Int<3000>,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>>,100>,SmoothStep<Scale<TwistAngle<>,IntArg<MELT_SIZE_ARG,28000>,Int<30000>>,Int<3000>>>,TrFade<4000>>,TrWipe<200>,SaberBase::LOCKUP_MELT,Int<1>>,SyncAltToVarianceL,TransitionEffectL<TrConcat<TrDelay<100>,AlphaL<White,Int<0>>,TrDoEffect<TrInstant,EFFECT_GAME_CHOICE>>,EFFECT_INTERACTIVE_BLAST>,TransitionEffectL<TrConcat<TrExtendX<Sum<WavLen<EFFECT_INTERACTIVE_BLAST>,IntArg<STYLE_OPTION2_ARG,1000>>,TrInstant>,TransitionPulseL<TrDoEffect<TrInstant,EFFECT_BLAST>,ThresholdPulseF<SwingSpeed<300>,Int<16000>>>,TrConcat<TrDelay<150>,TrRandom<TrDoEffect<TrInstant,EFFECT_INTERACTIVE_BLAST>,TrInstant,TrDoEffect<TrInstant,EFFECT_INTERACTIVE_BLAST>,TrDoEffect<TrInstant,EFFECT_INTERACTIVE_BLAST>>>>,EFFECT_GAME_CHOICE>,InOutTrL<TrWipeX<BendTimePowInvX<IgnitionTime<300>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrWipeInX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,Black>,TransitionEffectL<TrConcat<TrJoin<TrDelay<2000>,TrWipe<1000>>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<BatteryLevel,Int<-10>>>,TrWipeIn<1000>>,EFFECT_BATTERY_LEVEL>,TransitionEffectL<TrConcat<TrExtend<2000,TrWipe<100>>,AlphaL<RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,SmoothStep<VolumeLevel,Int<-1>>>,TrFade<300>>,EFFECT_VOLUME_LEVEL>>;
/*
Add to preset as StylePtr<ControlMainCalKestisSurvivorBlueKyberSelectSpecialAbility>()
--------------------------------------------------------------------------*/

/*--------------------------------- MainPresetFett263KyloRenSupremeLeader -------------------------
copyright Fett263 KyloRen (Primary Blade) OS7 Style
https://fett263library.com/early-access/#KyloRen
OS7.14 v3.1
Single Style
Base Style: Kylo Ren Unstable (Supreme Leader)


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
Stab Effect: Sparking Stab [Color: StabColorArg]
Interactive Blast: Random Blasts - Default Level (Uses Style Option 2 for Editing): 1000 ms
Interactive Blast control requires blast.wav files in font. When Blast is triggered blast.wav will play, to deflect blast (blst.wav and visual effect) swing within 1000ms of blaster sound ending. Random number of blasts from 1 to multiple possible. Only one style per preset can contain.
Blast Effect: Blast Wave (Random) [Color: BlastColorArg]
Clash Effect: Real Clash V1 [Color: ClashColorArg]
Battery Level: Blade Location (Green to Red)
Display Volume: Blade Location [Color: BaseColorArg]
*/
using MainPresetFett263KyloRenSupremeLeader = Layers<StripesX<Int<1500>,Scale<SlowNoise<Int<2500>>,Int<-3000>,Int<-5000>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,Mix<Int<10280>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,Mix<Int<2570>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>,TransitionEffectL<TrConcat<TrJoin<TrDelayX<WavLen<>>,TrWipeIn<200>>,AlphaL<RandomPerLEDFlickerL<RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>,SmoothStep<IntArg<MELT_SIZE_ARG,28000>,Int<2000>>>,TrWipe<200>>,EFFECT_STAB>,TransitionEffectL<TrWaveX<RgbArg<BLAST_COLOR_ARG,Rgb<255,255,255>>,Scale<EffectRandomF<EFFECT_BLAST>,Int<100>,Int<400>>,Int<100>,Scale<EffectPosition<EFFECT_BLAST>,Int<100>,Int<400>>,Scale<EffectPosition<EFFECT_BLAST>,Int<28000>,Int<8000>>>,EFFECT_BLAST>,Mix<IsLessThan<ClashImpactF<>,Int<26000>>,TransitionEffectL<TrConcat<TrInstant,AlphaL<RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<ClashImpactF<>,Int<12000>,Int<60000>>>>,TrFadeX<Scale<ClashImpactF<>,Int<200>,Int<400>>>>,EFFECT_CLASH>,TransitionEffectL<TrWaveX<RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>,Scale<ClashImpactF<>,Int<100>,Int<400>>,Int<100>,Scale<ClashImpactF<>,Int<100>,Int<400>>,Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>>,EFFECT_CLASH>>,LockupTrL<TransitionEffect<AlphaL<AlphaMixL<Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<22000>>>,AudioFlicker<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<12000>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>>>,BrownNoiseFlicker<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<12000>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>>,300>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<22000>>>>,AlphaL<AudioFlicker<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<20000>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,TrExtend<5000,TrInstant>,TrFade<5000>,EFFECT_LOCKUP_BEGIN>,TrConcat<TrJoin<TrDelay<50>,TrInstant>,Mix<IsLessThan<ClashImpactF<>,Int<26000>>,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,AlphaL<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<ClashImpactF<>,Int<20000>,Int<60000>>>>>,TrFade<300>>,TrConcat<TrInstant,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,TrFade<400>>,SaberBase::LOCKUP_NORMAL,Int<1>>,ResponsiveLightningBlockL<Strobe<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,AudioFlicker<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,Blue>,50,1>,TrConcat<TrExtend<200,TrInstant>,AlphaL<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,Bump<Scale<BladeAngle<>,Int<10000>,Int<21000>>,Int<10000>>>,TrFade<200>>,TrConcat<TrInstant,RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,TrFade<400>>,Int<1>>,LockupTrL<AlphaL<TransitionEffect<RandomPerLEDFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<255,255,255>>>,BrownNoiseFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<255,255,255>>,Int<300>>,TrExtend<4000,TrInstant>,TrFade<4000>,EFFECT_DRAG_BEGIN>,SmoothStep<Scale<TwistAngle<>,IntArg<DRAG_SIZE_ARG,28000>,Int<30000>>,Int<3000>>>,TrWipeIn<200>,TrWipe<200>,SaberBase::LOCKUP_DRAG,Int<1>>,LockupTrL<AlphaL<Stripes<2000,4000,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>,Mix<Sin<Int<50>>,Black,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>>,Mix<Int<4096>,Black,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>>>,SmoothStep<Scale<TwistAngle<>,IntArg<MELT_SIZE_ARG,28000>,Int<30000>>,Int<3000>>>,TrConcat<TrExtend<4000,TrWipeIn<200>>,AlphaL<HumpFlicker<Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>,RotateColorsX<Int<3000>,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>>,100>,SmoothStep<Scale<TwistAngle<>,IntArg<MELT_SIZE_ARG,28000>,Int<30000>>,Int<3000>>>,TrFade<4000>>,TrWipe<200>,SaberBase::LOCKUP_MELT,Int<1>>,TransitionEffectL<TrConcat<TrDelay<100>,AlphaL<White,Int<0>>,TrDoEffect<TrInstant,EFFECT_GAME_CHOICE>>,EFFECT_INTERACTIVE_BLAST>,TransitionEffectL<TrConcat<TrExtendX<Sum<WavLen<EFFECT_INTERACTIVE_BLAST>,IntArg<STYLE_OPTION2_ARG,1000>>,TrInstant>,TransitionPulseL<TrDoEffect<TrInstant,EFFECT_BLAST>,ThresholdPulseF<SwingSpeed<300>,Int<16000>>>,TrConcat<TrDelay<150>,TrRandom<TrDoEffect<TrInstant,EFFECT_INTERACTIVE_BLAST>,TrInstant,TrDoEffect<TrInstant,EFFECT_INTERACTIVE_BLAST>,TrDoEffect<TrInstant,EFFECT_INTERACTIVE_BLAST>>>>,EFFECT_GAME_CHOICE>,InOutTrL<TrWipeX<BendTimePowInvX<IgnitionTime<300>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrWipeInX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,Black>,TransitionEffectL<TrConcat<TrJoin<TrDelay<2000>,TrInstant>,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<BatteryLevel,Int<10000>>>,TrFade<300>>,EFFECT_BATTERY_LEVEL>,TransitionEffectL<TrConcat<TrExtend<2000,TrFade<100>>,AlphaL<RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,Bump<VolumeLevel,Int<8000>>>,TrFade<300>>,EFFECT_VOLUME_LEVEL>>;
/*
Add to preset as StylePtr<MainPresetFett263KyloRenSupremeLeader>()
--------------------------------------------------------------------------*/
/*--------------------------------- AccentPresetFett263KyloRenSupremeLeader -------------------------
copyright Fett263 KyloRen (Primary Blade) OS7 Style
https://fett263library.com/early-access/#KyloRen
OS7.14 v3.1
Single Style
Base Style: Kylo Ren Unstable (Supreme Leader)


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
using AccentPresetFett263KyloRenSupremeLeader = Layers<StripesX<Int<1500>,Scale<SlowNoise<Int<2500>>,Int<-3000>,Int<-5000>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,Mix<Int<10280>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,Mix<Int<2570>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>,TransitionEffectL<TrWaveX<RgbArg<BLAST_COLOR_ARG,Rgb<255,255,255>>,Scale<EffectRandomF<EFFECT_BLAST>,Int<100>,Int<400>>,Int<100>,Scale<EffectPosition<EFFECT_BLAST>,Int<100>,Int<400>>,Scale<EffectPosition<EFFECT_BLAST>,Int<28000>,Int<8000>>>,EFFECT_BLAST>,Mix<IsLessThan<ClashImpactF<>,Int<26000>>,TransitionEffectL<TrConcat<TrInstant,AlphaL<RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<ClashImpactF<>,Int<12000>,Int<60000>>>>,TrFadeX<Scale<ClashImpactF<>,Int<200>,Int<400>>>>,EFFECT_CLASH>,TransitionEffectL<TrWaveX<RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>,Scale<ClashImpactF<>,Int<100>,Int<400>>,Int<100>,Scale<ClashImpactF<>,Int<100>,Int<400>>,Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>>,EFFECT_CLASH>>,LockupTrL<TransitionEffect<AlphaL<AlphaMixL<Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<22000>>>,AudioFlicker<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<12000>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>>>,BrownNoiseFlicker<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<12000>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>>,300>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<22000>>>>,AlphaL<AudioFlicker<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<20000>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,TrExtend<5000,TrInstant>,TrFade<5000>,EFFECT_LOCKUP_BEGIN>,TrConcat<TrJoin<TrDelay<50>,TrInstant>,Mix<IsLessThan<ClashImpactF<>,Int<26000>>,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,AlphaL<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<ClashImpactF<>,Int<20000>,Int<60000>>>>>,TrFade<300>>,TrConcat<TrInstant,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,TrFade<400>>,SaberBase::LOCKUP_NORMAL,Int<1>>,ResponsiveLightningBlockL<Strobe<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,AudioFlicker<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,Blue>,50,1>,TrConcat<TrExtend<200,TrInstant>,AlphaL<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,Bump<Scale<BladeAngle<>,Int<10000>,Int<21000>>,Int<10000>>>,TrFade<200>>,TrConcat<TrInstant,RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,TrFade<400>>,Int<1>>,LockupTrL<AlphaL<TransitionEffect<RandomPerLEDFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<255,255,255>>>,BrownNoiseFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<255,255,255>>,Int<300>>,TrExtend<4000,TrInstant>,TrFade<4000>,EFFECT_DRAG_BEGIN>,SmoothStep<Scale<TwistAngle<>,IntArg<DRAG_SIZE_ARG,28000>,Int<30000>>,Int<3000>>>,TrWipeIn<200>,TrWipe<200>,SaberBase::LOCKUP_DRAG,Int<1>>,LockupTrL<AlphaL<Stripes<2000,4000,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>,Mix<Sin<Int<50>>,Black,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>>,Mix<Int<4096>,Black,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>>>,SmoothStep<Scale<TwistAngle<>,IntArg<MELT_SIZE_ARG,28000>,Int<30000>>,Int<3000>>>,TrConcat<TrExtend<4000,TrWipeIn<200>>,AlphaL<HumpFlicker<Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>,RotateColorsX<Int<3000>,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>>,100>,SmoothStep<Scale<TwistAngle<>,IntArg<MELT_SIZE_ARG,28000>,Int<30000>>,Int<3000>>>,TrFade<4000>>,TrWipe<200>,SaberBase::LOCKUP_MELT,Int<1>>,InOutTrL<TrWipeX<BendTimePowInvX<IgnitionTime<300>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrWipeInX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,Black>>;
/*
Add to preset as StylePtr<AccentPresetFett263KyloRenSupremeLeader>()
--------------------------------------------------------------------------*/

/*--------------------------------- ControlMainResponsiveFlameRealFlameGradientBaseColor -------------------------
copyright Fett263 ResponsiveFlame (Primary Blade) OS7 Style
https://fett263library.com/early-access/#ResponsiveFlame
OS7.14 v3.1
Single Style
Base Style: Responsive Flame (Real Flame Gradient)
Kyber Select Interactive Control: While Blade is On, use selected Special Ability to change color (Phase). Requires Alt Font.

NOTE:This style includes Control Layer. Only one Control Layer should be used per preset.

*This style REQUIRES Alt Fonts alt000/ to alt008/ to be set up. Uses altchng.wav on change.
See https://pod.hubbe.net/sound/alt_sounds.html for more information.
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
Special Ability 1: Next Phase
Special Ability 2: Previous Phase
Special Ability 3: Select Random Phase
Special Ability 4: Toggle Swing Change (Random / Party Mode) Uses tr00.wav or tr/000/000.wav on toggle (mechanical or menu sound)

*/
using ControlMainResponsiveFlameRealFlameGradientBaseColor = Mix<SmoothStep<Scale<IsLessThan<BladeAngle<>,Int<16000>>,Int<36000>,Scale<BladeAngle<>,Int<10924>,Int<54000>>>,Scale<IsLessThan<BladeAngle<>,Int<16000>>,Int<-1>,Scale<BladeAngle<>,Int<-10000>,Int<-1>>>>,Black,Remap<Scale<RampF,Int<0>,Scale<IsLessThan<BladeAngle<>,Int<15000>>,Int<32768>,Scale<BladeAngle<0,15000>,Int<60000>,Int<32768>>>>,Layers<Mix<BladeAngle<>,StaticFire<Gradient<RotateColorsX<Int<1600>,ColorSelect<AltF,TrInstant,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,RgbArg<ALT_COLOR_ARG,Rgb<0,255,255>>,RgbArg<ALT_COLOR2_ARG,Rgb<0,255,0>>,RgbArg<ALT_COLOR3_ARG,Rgb<80,50,210>>,Rgb<255,0,255>,Rgb<255,68,0>,Rgb<115,15,240>,Rgb<100,100,150>,Rgb<180,130,0>>>,RotateColorsX<Int<1000>,ColorSelect<AltF,TrInstant,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,RgbArg<ALT_COLOR_ARG,Rgb<0,255,255>>,RgbArg<ALT_COLOR2_ARG,Rgb<0,255,0>>,RgbArg<ALT_COLOR3_ARG,Rgb<80,50,210>>,Rgb<255,0,255>,Rgb<255,68,0>,Rgb<115,15,240>,Rgb<100,100,150>,Rgb<180,130,0>>>,RotateColorsX<Int<400>,ColorSelect<AltF,TrInstant,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,RgbArg<ALT_COLOR_ARG,Rgb<0,255,255>>,RgbArg<ALT_COLOR2_ARG,Rgb<0,255,0>>,RgbArg<ALT_COLOR3_ARG,Rgb<80,50,210>>,Rgb<255,0,255>,Rgb<255,68,0>,Rgb<115,15,240>,Rgb<100,100,150>,Rgb<180,130,0>>>,ColorSelect<AltF,TrInstant,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,RgbArg<ALT_COLOR_ARG,Rgb<0,255,255>>,RgbArg<ALT_COLOR2_ARG,Rgb<0,255,0>>,RgbArg<ALT_COLOR3_ARG,Rgb<80,50,210>>,Rgb<255,0,255>,Rgb<255,68,0>,Rgb<115,15,240>,Rgb<100,100,150>,Rgb<180,130,0>>>,Mix<Int<16384>,Black,ColorSelect<AltF,TrInstant,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,RgbArg<ALT_COLOR_ARG,Rgb<0,255,255>>,RgbArg<ALT_COLOR2_ARG,Rgb<0,255,0>>,RgbArg<ALT_COLOR3_ARG,Rgb<80,50,210>>,Rgb<255,0,255>,Rgb<255,68,0>,Rgb<115,15,240>,Rgb<100,100,150>,Rgb<180,130,0>>>,0,2,0,1800,10>,StaticFire<Gradient<RotateColorsX<Int<1600>,ColorSelect<AltF,TrInstant,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,RgbArg<ALT_COLOR_ARG,Rgb<0,255,255>>,RgbArg<ALT_COLOR2_ARG,Rgb<0,255,0>>,RgbArg<ALT_COLOR3_ARG,Rgb<80,50,210>>,Rgb<255,0,255>,Rgb<255,68,0>,Rgb<115,15,240>,Rgb<100,100,150>,Rgb<180,130,0>>>,RotateColorsX<Int<1200>,ColorSelect<AltF,TrInstant,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,RgbArg<ALT_COLOR_ARG,Rgb<0,255,255>>,RgbArg<ALT_COLOR2_ARG,Rgb<0,255,0>>,RgbArg<ALT_COLOR3_ARG,Rgb<80,50,210>>,Rgb<255,0,255>,Rgb<255,68,0>,Rgb<115,15,240>,Rgb<100,100,150>,Rgb<180,130,0>>>,RotateColorsX<Int<600>,ColorSelect<AltF,TrInstant,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,RgbArg<ALT_COLOR_ARG,Rgb<0,255,255>>,RgbArg<ALT_COLOR2_ARG,Rgb<0,255,0>>,RgbArg<ALT_COLOR3_ARG,Rgb<80,50,210>>,Rgb<255,0,255>,Rgb<255,68,0>,Rgb<115,15,240>,Rgb<100,100,150>,Rgb<180,130,0>>>,ColorSelect<AltF,TrInstant,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,RgbArg<ALT_COLOR_ARG,Rgb<0,255,255>>,RgbArg<ALT_COLOR2_ARG,Rgb<0,255,0>>,RgbArg<ALT_COLOR3_ARG,Rgb<80,50,210>>,Rgb<255,0,255>,Rgb<255,68,0>,Rgb<115,15,240>,Rgb<100,100,150>,Rgb<180,130,0>>>,Mix<Int<16384>,Black,ColorSelect<AltF,TrInstant,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,RgbArg<ALT_COLOR_ARG,Rgb<0,255,255>>,RgbArg<ALT_COLOR2_ARG,Rgb<0,255,0>>,RgbArg<ALT_COLOR3_ARG,Rgb<80,50,210>>,Rgb<255,0,255>,Rgb<255,68,0>,Rgb<115,15,240>,Rgb<100,100,150>,Rgb<180,130,0>>>,0,4,0,2200,2>>,TransitionEffectL<TrDoEffectAlwaysX<TrInstant,EFFECT_ALT_SOUND,ModF<Sum<AltF,Int<1>>,Int<9>>,Int<-1>>,EFFECT_USER1>,TransitionEffectL<TrDoEffectAlwaysX<TrInstant,EFFECT_ALT_SOUND,ModF<Sum<AltF,Int<-1>>,Int<9>>,Int<-1>>,EFFECT_USER2>,TransitionEffectL<TrDoEffectAlwaysX<TrInstant,EFFECT_ALT_SOUND,ModF<Sum<AltF,Scale<RandomF,Int<1>,Int<8>>>,Int<9>>,Int<-1>>,EFFECT_USER3>,TransitionPulseL<TrSelect<IncrementModuloF<EffectPulseF<EFFECT_USER4>,Int<2>>,TrInstant,TrDoEffectX<TrInstant,EFFECT_ALT_SOUND,ModF<Sum<AltF,Scale<RandomF,Int<1>,Int<8>>>,Int<9>>,Int<-1>>>,ThresholdPulseF<SwingSpeed<320>,Int<31000>>>,TransitionEffectL<TrDoEffectX<TrInstant,EFFECT_TRANSITION_SOUND,Int<0>,Int<-1>>,EFFECT_USER4>,TransitionEffectL<TrWaveX<RgbArg<BLAST_COLOR_ARG,Rgb<255,28,0>>,Scale<EffectRandomF<EFFECT_BLAST>,Int<100>,Int<400>>,Int<100>,Scale<EffectPosition<EFFECT_BLAST>,Int<100>,Int<400>>,Scale<EffectPosition<EFFECT_BLAST>,Int<28000>,Int<8000>>>,EFFECT_BLAST>,Mix<IsLessThan<ClashImpactF<>,Int<26000>>,TransitionEffectL<TrConcat<TrInstant,AlphaL<RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<ClashImpactF<>,Int<12000>,Int<60000>>>>,TrFadeX<Scale<ClashImpactF<>,Int<200>,Int<400>>>>,EFFECT_CLASH>,TransitionEffectL<TrWaveX<RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>,Scale<ClashImpactF<>,Int<100>,Int<400>>,Int<100>,Scale<ClashImpactF<>,Int<100>,Int<400>>,Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>>,EFFECT_CLASH>>,LockupTrL<TransitionEffect<AlphaL<AlphaMixL<Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<22000>>>,AudioFlicker<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<12000>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>>>,BrownNoiseFlicker<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<12000>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>>,300>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<22000>>>>,AlphaL<AudioFlicker<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<20000>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,TrExtend<5000,TrInstant>,TrFade<5000>,EFFECT_LOCKUP_BEGIN>,TrConcat<TrJoin<TrDelay<50>,TrInstant>,Mix<IsLessThan<ClashImpactF<>,Int<26000>>,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,AlphaL<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<ClashImpactF<>,Int<20000>,Int<60000>>>>>,TrFade<300>>,TrConcat<TrInstant,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,TrFade<400>>,SaberBase::LOCKUP_NORMAL,Int<1>>,ResponsiveLightningBlockL<Strobe<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,AudioFlicker<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,Blue>,50,1>,TrConcat<TrExtend<200,TrInstant>,AlphaL<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,Bump<Scale<BladeAngle<>,Int<10000>,Int<21000>>,Int<10000>>>,TrFade<200>>,TrConcat<TrInstant,RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,TrFade<400>>,Int<1>>,LockupTrL<AlphaL<TransitionEffect<RandomPerLEDFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<255,255,255>>>,BrownNoiseFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<255,255,255>>,Int<300>>,TrExtend<4000,TrInstant>,TrFade<4000>,EFFECT_DRAG_BEGIN>,SmoothStep<Scale<TwistAngle<>,IntArg<DRAG_SIZE_ARG,28000>,Int<30000>>,Int<3000>>>,TrWipeIn<200>,TrWipe<200>,SaberBase::LOCKUP_DRAG,Int<1>>,LockupTrL<AlphaL<Stripes<2000,4000,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>,Mix<Sin<Int<50>>,Black,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>>,Mix<Int<4096>,Black,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>>>,SmoothStep<Scale<TwistAngle<>,IntArg<MELT_SIZE_ARG,28000>,Int<30000>>,Int<3000>>>,TrConcat<TrExtend<4000,TrWipeIn<200>>,AlphaL<HumpFlicker<Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>,RotateColorsX<Int<3000>,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>>,100>,SmoothStep<Scale<TwistAngle<>,IntArg<MELT_SIZE_ARG,28000>,Int<30000>>,Int<3000>>>,TrFade<4000>>,TrWipe<200>,SaberBase::LOCKUP_MELT,Int<1>>,InOutTrL<TrWipeX<BendTimePowInvX<IgnitionTime<300>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrWipeInX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,Black>>>>;
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
using ControlMainBladeofTalzinBaseColor = Layers<StaticFire<Mix<SmoothStep<Scale<BladeAngle<>,Int<38000>,Int<23000>>,Int<8000>>,Mix<Int<400>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>>,Mix<Int<6000>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>>>,StripesX<Int<14000>,Scale<BladeAngle<>,Int<-5>,Int<-50>>,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>,Mix<Scale<HoldPeakF<SwingSpeed<250>,Int<1000>,Int<8000>>,Int<6000>,Int<16000>>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>>>,0,2,4,2000,2>,TransitionEffectL<TrWaveX<RgbArg<BLAST_COLOR_ARG,Rgb<255,28,0>>,Scale<EffectRandomF<EFFECT_BLAST>,Int<100>,Int<400>>,Int<100>,Scale<EffectPosition<EFFECT_BLAST>,Int<100>,Int<400>>,Scale<EffectPosition<EFFECT_BLAST>,Int<28000>,Int<8000>>>,EFFECT_BLAST>,Mix<IsLessThan<ClashImpactF<>,Int<26000>>,TransitionEffectL<TrConcat<TrInstant,AlphaL<RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<ClashImpactF<>,Int<12000>,Int<60000>>>>,TrFadeX<Scale<ClashImpactF<>,Int<200>,Int<400>>>>,EFFECT_CLASH>,TransitionEffectL<TrWaveX<RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>,Scale<ClashImpactF<>,Int<100>,Int<400>>,Int<100>,Scale<ClashImpactF<>,Int<100>,Int<400>>,Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>>,EFFECT_CLASH>>,LockupTrL<TransitionEffect<AlphaL<AlphaMixL<Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<22000>>>,AudioFlicker<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<12000>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>>>,BrownNoiseFlicker<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<12000>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>>,300>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<22000>>>>,AlphaL<AudioFlicker<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<20000>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,TrExtend<5000,TrInstant>,TrFade<5000>,EFFECT_LOCKUP_BEGIN>,TrConcat<TrJoin<TrDelay<50>,TrInstant>,Mix<IsLessThan<ClashImpactF<>,Int<26000>>,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,AlphaL<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<ClashImpactF<>,Int<20000>,Int<60000>>>>>,TrFade<300>>,TrConcat<TrInstant,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,TrFade<400>>,SaberBase::LOCKUP_NORMAL,Int<1>>,ResponsiveLightningBlockL<Strobe<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,AudioFlicker<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,Blue>,50,1>,TrConcat<TrExtend<200,TrInstant>,AlphaL<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,Bump<Scale<BladeAngle<>,Int<10000>,Int<21000>>,Int<10000>>>,TrFade<200>>,TrConcat<TrInstant,RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,TrFade<400>>,Int<1>>,LockupTrL<AlphaL<TransitionEffect<RandomPerLEDFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<255,255,255>>>,BrownNoiseFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<255,255,255>>,Int<300>>,TrExtend<4000,TrInstant>,TrFade<4000>,EFFECT_DRAG_BEGIN>,SmoothStep<Scale<TwistAngle<>,IntArg<DRAG_SIZE_ARG,28000>,Int<30000>>,Int<3000>>>,TrWipeIn<200>,TrWipe<200>,SaberBase::LOCKUP_DRAG,Int<1>>,LockupTrL<AlphaL<Stripes<2000,4000,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>,Mix<Sin<Int<50>>,Black,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>>,Mix<Int<4096>,Black,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>>>,SmoothStep<Scale<TwistAngle<>,IntArg<MELT_SIZE_ARG,28000>,Int<30000>>,Int<3000>>>,TrConcat<TrExtend<4000,TrWipeIn<200>>,AlphaL<HumpFlicker<Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>,RotateColorsX<Int<3000>,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>>,100>,SmoothStep<Scale<TwistAngle<>,IntArg<MELT_SIZE_ARG,28000>,Int<30000>>,Int<3000>>>,TrFade<4000>>,TrWipe<200>,SaberBase::LOCKUP_MELT,Int<1>>,InOutTrL<TrWipeX<BendTimePowInvX<IgnitionTime<300>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrWipeInX<BendTimePowInvX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,Black>>;
/*
Add to preset as StylePtr<ControlMainBladeofTalzinBaseColor>()
--------------------------------------------------------------------------*/


using MountSaberFontsGodzilla = Layers<
  Mix<TwistAngle<>,StyleFire<RotateColorsX<Variation,Blue>,RotateColorsX<Variation,Rgb<0,0,60>>,0,3,FireConfig<0,2000,5>,FireConfig<0,2000,5>,FireConfig<0,2000,5>,FireConfig<0,2000,5>>,StyleFire<RotateColorsX<Variation,Blue>,RotateColorsX<Variation,Rgb<0,0,60>>,0,6,FireConfig<0,2000,5>,FireConfig<0,2000,5>,FireConfig<0,2000,5>,FireConfig<0,2000,5>>>,
  AlphaL<AlphaL<White,SwingSpeed<600>>,SmoothStep<Int<16000>,Int<16000>>>,
  LockupTrL<Layers<
    AlphaL<AudioFlickerL<White>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<10000>,Int<30000>>,Int<10000>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,
    AlphaL<White,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<10000>,Int<30000>>,Int<10000>>,Int<10000>>>>,TrConcat<TrInstant,AlphaL<White,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<10000>,Int<30000>>,Int<10000>>,Int<20000>>>,TrFade<400>>,TrConcat<TrInstant,AlphaL<Mix<SmoothStep<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<10000>,Int<30000>>,Int<10000>>,Int<1000>>,Stripes<1500,2000,White,Blue>,Stripes<1500,-2500,White,Blue>>,Int<18000>>,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,
  ResponsiveLightningBlockL<Strobe<White,AudioFlicker<White,Blue>,50,1>,TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,
  AlphaL<White,SmoothStep<Scale<SlowNoise<Int<2000>>,Int<1000>,Int<4000>>,Int<-4000>>>,
  ResponsiveStabL<Red>,
  ResponsiveBlastL<White,Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>>,
  ResponsiveBlastWaveL<White,Int<300>,Int<100>,Int<300>,Scale<BladeAngle<0,16000>,Int<10000>,Int<30000>>,Int<10000>,EFFECT_CLASH>,
  TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<White,40>,TrFade<1000>>,EFFECT_RETRACTION>,
  AlphaL<Black,SmoothStep<Scale<SlowNoise<Int<1800>>,Int<22000>,Int<40000>>,Int<24000>>>,
  LockupTrL<AlphaL<BrownNoiseFlickerL<White,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,
  LockupTrL<AlphaL<Mix<TwistAngle<>,Red,Orange>,SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,
  InOutTrL<TrWipe<800>,TrWipeIn<5000>>,
  TransitionEffectL<TrConcat<TrInstant,AlphaL<Rgb<100,100,150>,SmoothStep<Scale<SlowNoise<Int<2000>>,Int<1000>,Int<4000>>,Int<-4000>>>,TrDelay<10000>>,EFFECT_PREON>>;

using MountSaberFontsJurassic = Layers<
  AudioFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Red>>,
  AlphaL<Stripes<1000,-2000,RandomPerLEDFlicker<RotateColorsX<Variation,Red>,Black>,White,RotateColorsX<Variation,Red>,White>,SwingSpeed<600>>,
  LockupTrL<Layers<
    AlphaL<AudioFlickerL<Yellow>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<10000>,Int<30000>>,Int<10000>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,
    AlphaL<Yellow,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<10000>,Int<30000>>,Int<10000>>,Int<10000>>>>,TrConcat<TrInstant,White,TrFade<400>>,TrConcat<TrInstant,AlphaL<Mix<SmoothStep<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<10000>,Int<30000>>,Int<10000>>,Int<1000>>,Stripes<1500,2000,White,Red>,Stripes<1500,-2500,White,Red>>,Int<18000>>,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,
  ResponsiveLightningBlockL<Strobe<Black,AudioFlicker<Black,Blue>,50,1>,TrConcat<TrInstant,AlphaL<Black,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,
  AlphaL<White,SmoothStep<Scale<SlowNoise<Int<1600>>,Int<1000>,Int<4000>>,Int<-4000>>>,
  ResponsiveStabL<Orange>,
  ResponsiveBlastL<Yellow,Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>>,
  ResponsiveBlastWaveL<White,Int<300>,Int<100>,Int<300>,Scale<BladeAngle<0,16000>,Int<10000>,Int<30000>>,Int<10000>,EFFECT_CLASH>,
  TransitionEffectL<TrConcat<TrInstant,Stripes<3000,-3500,White,RandomPerLEDFlicker<Rgb<60,60,60>,Black>,BrownNoiseFlicker<White,Rgb<30,30,30>,200>,RandomPerLEDFlicker<Rgb<80,80,80>,Rgb<30,30,30>>>,TrFade<800>>,EFFECT_IGNITION>,
  LockupTrL<AlphaL<BrownNoiseFlickerL<Green,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,
  LockupTrL<AlphaL<Mix<TwistAngle<>,Rgb<255,200,0>,DarkOrange>,SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,
  InOutTrL<TrWipe<500>,TrWipeInSparkTip<White,500>>,
  TransitionEffectL<TrConcat<TrInstant,AlphaL<Mix<Trigger<EFFECT_PREON,Int<3000>,Int<2000>,Int<1000>>,BrownNoiseFlicker<Black,RotateColorsX<Variation,Red>,100>,RandomPerLEDFlicker<RotateColorsX<Variation,Red>,Rgb<50,50,50>>,BrownNoiseFlicker<Mix<NoisySoundLevel,RotateColorsX<Variation,Red>,RotateColorsX<Int<4000>,RotateColorsX<Variation,Red>>>,White,50>>,SmoothStep<Scale<NoisySoundLevel,Int<-10000>,Int<36000>>,Int<-4000>>>,TrDelay<2000>>,EFFECT_PREON>>;
/* copyright Fett263 UnstableBlades (Primary Blade) OS6 Style
https://fett263.com/fett263-proffieOS6-style-library.html#UnstableBlades
OS6.7 v4.014
This Style Contains 4 Unique Combinations
Style Options:
Default (0): Unstable Rage
1: Unstable Pulse
2: Unstable Anger
3: Unstable Erratic

Base Color: Rgb<255,0,0> (0)

--Effects Included--
Preon Effect: Faulty Ignition (PreOn Color)
Ignition Effect: SparkTip Ignition
PowerUp Effect: Power Surge (Unstable V2)
Retraction Effect: Glitch Off
CoolDown Effect: Unstable Cool Down Reverse
PostOff Effect: Closing the Eye of Sauron (Center)
Lockup Effect: Intensity Lockup V1, Begin Effect: Real Clash, End Effect: Full Blade Absorb
LightningBlock Effect: Responsive Lightning Block
Drag Effect: Intensity Sparking Drag
Melt Effect: Intensity Melt
Stab Effect: AudioFlicker Stab
Blast Effect: Blast Wave (Random)
Clash Effect: Real Clash V1
Swing Effect: Force Boost Aura
Emitter Effect: Unstable Flare
*/
using MountSaberFontsMechagodzilla = Layers<ColorSelect<IntArg<STYLE_OPTION_ARG,0>,TrInstant,Stripes<3000,-3500,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,RandomPerLEDFlicker<Mix<Int<7710>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,Black>,BrownNoiseFlicker<RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,Mix<Int<3855>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,200>,RandomPerLEDFlicker<Mix<Int<10280>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,Mix<Int<3855>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>>>,StripesX<Int<6000>,Scale<SlowNoise<Int<2000>>,Int<-1600>,Int<-3200>>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,RandomPerLEDFlicker<Mix<Int<10280>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,Mix<Int<1285>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>>,BrownNoiseFlicker<Mix<Int<1285>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,Mix<Int<16384>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,300>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,RandomPerLEDFlicker<Black,Mix<Int<16384>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,Layers<Stripes<2000,-2500,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,RandomPerLEDFlicker<Mix<Int<7710>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,Black>,BrownNoiseFlicker<RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,Mix<Int<3855>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,200>,RandomPerLEDFlicker<Mix<Int<10280>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,Mix<Int<3855>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>>>,TransitionLoopL<TrJoin<TrDelayX<Scale<SlowNoise<Int<1500>>,Int<200>,Int<1200>>>,TrWaveX<RandomFlicker<RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,BrownNoiseFlicker<Mix<Int<10280>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,Black,300>>,Int<400>,Int<100>,Int<200>,Int<0>>>>>,StaticFire<StripesX<Int<3000>,Scale<SlowNoise<Int<2000>>,Int<-1000>,Int<-5000>>,BrownNoiseFlicker<RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,Black,100>,RandomPerLEDFlicker<Mix<Int<7710>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,Mix<Int<1285>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>>,Mix<Int<3212>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,White>,Mix<Int<16384>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>>,Mix<Int<10280>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,0,5,3,3000,0>>,AlphaL<RandomPerLEDFlickerL<RgbArg<EMITTER_COLOR_ARG,Rgb<255,14,0>>>,SmoothStep<Scale<NoisySoundLevel,IntArg<EMITTER_SIZE_ARG,2000>,Sum<IntArg<EMITTER_SIZE_ARG,2000>,Int<6000>>>,Int<-6000>>>,TransitionEffectL<TrConcat<TrJoin<TrDelay<1000>,TrFade<300>>,AudioFlickerL<RgbArg<SWING_COLOR_ARG,Rgb<255,255,255>>>,TrFade<300>>,EFFECT_FORCE>,TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>,40>,TrFade<1200>>,EFFECT_IGNITION>,TransitionEffectL<TrConcat<TrJoin<TrDelayX<RetractionTime<0>>,TrInstant>,Stripes<3000,3500,RgbArg<RETRACTION_COLOR_ARG,Rgb<255,14,0>>,RandomPerLEDFlicker<Mix<Int<7710>,Black,RgbArg<RETRACTION_COLOR_ARG,Rgb<255,14,0>>>,Black>,BrownNoiseFlicker<RgbArg<RETRACTION_COLOR_ARG,Rgb<255,14,0>>,Mix<Int<3855>,Black,RgbArg<RETRACTION_COLOR_ARG,Rgb<255,14,0>>>,200>,RandomPerLEDFlicker<Mix<Int<3137>,Black,RgbArg<RETRACTION_COLOR_ARG,Rgb<255,14,0>>>,Mix<Int<3855>,Black,RgbArg<RETRACTION_COLOR_ARG,Rgb<255,14,0>>>>>,TrFade<800>>,EFFECT_RETRACTION>,TransitionEffectL<TrConcat<TrJoin<TrDelayX<WavLen<>>,TrWipeIn<200>>,AlphaL<AudioFlickerL<RgbArg<STAB_COLOR_ARG,Rgb<255,255,255>>>,SmoothStep<IntArg<MELT_SIZE_ARG,28000>,Int<2000>>>,TrWipe<200>>,EFFECT_STAB>,MultiTransitionEffectL<TrWaveX<RgbArg<BLAST_COLOR_ARG,Rgb<255,255,255>>,Scale<EffectPosition<EFFECT_BLAST>,Int<100>,Int<400>>,Int<100>,Scale<EffectPosition<EFFECT_BLAST>,Int<100>,Int<400>>,Scale<EffectPosition<EFFECT_BLAST>,Int<28000>,Int<8000>>>,EFFECT_BLAST>,Mix<IsLessThan<ClashImpactF<>,Int<26000>>,TransitionEffectL<TrConcat<TrInstant,AlphaL<RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<ClashImpactF<>,Int<12000>,Int<60000>>>>,TrFadeX<Scale<ClashImpactF<>,Int<200>,Int<400>>>>,EFFECT_CLASH>,TransitionEffectL<TrWaveX<RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>,Scale<ClashImpactF<>,Int<100>,Int<400>>,Int<100>,Scale<ClashImpactF<>,Int<100>,Int<400>>,Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>>,EFFECT_CLASH>>,LockupTrL<TransitionEffect<AlphaMixL<Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>,BrownNoiseFlickerL<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Int<200>>,StripesX<Int<1800>,Scale<NoisySoundLevel,Int<-3500>,Int<-5000>>,Mix<Int<6425>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>>,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<12850>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>>>>,AlphaL<AudioFlicker<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<10280>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Int<13000>>>,TrJoin<TrDelay<8000>,TrInstant>,TrFade<3000>,EFFECT_LOCKUP_BEGIN>,TrConcat<TrJoin<TrDelay<50>,TrInstant>,Mix<IsLessThan<ClashImpactF<>,Int<26000>>,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,AlphaL<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<ClashImpactF<>,Int<20000>,Int<60000>>>>>,TrFade<300>>,TrConcat<TrInstant,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,ResponsiveLightningBlockL<Strobe<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,AudioFlicker<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,Blue>,50,1>,TrConcat<TrInstant,AlphaL<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,Int<16000>>,30>,TrSmoothFade<600>>>,LockupTrL<AlphaL<RandomPerLEDFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<255,255,255>>>,SmoothStep<IntArg<DRAG_SIZE_ARG,28000>,Int<3000>>>,TrConcat<TrJoin<TrDelay<4000>,TrWipeIn<200>>,AlphaL<BrownNoiseFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<255,255,255>>,Int<300>>,SmoothStep<IntArg<DRAG_SIZE_ARG,28000>,Int<3000>>>,TrFade<4000>>,TrFade<300>,SaberBase::LOCKUP_DRAG>,LockupTrL<AlphaL<Remap<Scale<RampF,Int<65536>,Int<0>>,StaticFire<Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>>>,Mix<TwistAngle<>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>>,RotateColorsX<Int<3000>,Mix<Int<12000>,Black,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>>>>,0,3,5,3000,10>>,SmoothStep<IntArg<MELT_SIZE_ARG,28000>,Int<4000>>>,TrConcat<TrWipeIn<100>,AlphaL<RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>,SmoothStep<IntArg<MELT_SIZE_ARG,28000>,Int<4000>>>,TrJoin<TrDelay<4000>,TrFade<300>>,AlphaL<Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>>>,SmoothStep<IntArg<MELT_SIZE_ARG,28000>,Int<4000>>>,TrFade<4000>>,TrWipe<200>,SaberBase::LOCKUP_MELT>,InOutTrL<TrWipeSparkTipX<RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>,IgnitionTime<300>>,TrConcat<TrJoin<TrDelayX<Mult<RetractionTime<0>,Int<16384>>>,TrWipeInX<Mult<RetractionTime<0>,Int<16384>>>>,Mix<SmoothStep<NoisySoundLevel,Int<-1>>,Black,RgbArg<RETRACTION_COLOR_ARG,Rgb<255,14,0>>>,TrWipeInX<Mult<RetractionTime<0>,Int<16384>>>>,Black>,TransitionEffectL<TrConcat<TrInstant,AlphaL<Mix<Trigger<EFFECT_PREON,Mult<Int<16384>,WavLen<EFFECT_PREON>>,Mult<Int<10922>,WavLen<EFFECT_PREON>>,Mult<Int<5462>,WavLen<EFFECT_PREON>>>,BrownNoiseFlicker<Black,RgbArg<PREON_COLOR_ARG,Rgb<255,14,0>>,100>,RandomPerLEDFlicker<RgbArg<PREON_COLOR_ARG,Rgb<255,14,0>>,Rgb<50,50,50>>,BrownNoiseFlicker<Mix<NoisySoundLevel,RgbArg<PREON_COLOR_ARG,Rgb<255,14,0>>,RotateColorsX<Int<4000>,RgbArg<PREON_COLOR_ARG,Rgb<255,14,0>>>>,White,50>>,SmoothStep<Scale<NoisySoundLevel,Int<-10000>,Int<36000>>,Int<-4000>>>,TrDelayX<WavLen<EFFECT_PREON>>>,EFFECT_PREON>,TransitionEffectL<TrConcat<TrCenterWipeX<Int<200>>,AlphaL<AudioFlicker<RotateColorsX<Int<200>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,RotateColorsX<Int<600>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>>,Bump<Int<16384>,Scale<NoisySoundLevel,Int<14000>,Int<20000>>>>,TrJoin<TrDelayX<Mult<Scale<IsLessThan<WavLen<EFFECT_POSTOFF>,Int<200>>,WavLen<EFFECT_POSTOFF>,Int<4000>>,Int<16384>>>,TrCenterWipeX<Mult<Scale<IsLessThan<WavLen<EFFECT_POSTOFF>,Int<200>>,WavLen<EFFECT_POSTOFF>,Int<4000>>,Int<8000>>>>,Layers<AlphaL<AudioFlicker<RotateColorsX<Int<200>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,RotateColorsX<Int<600>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>>,Bump<Int<16384>,Scale<NoisySoundLevel,Int<14000>,Int<20000>>>>,AlphaL<Black,LinearSectionF<Int<16384>,Scale<NoisySoundLevel,Int<4000>,Int<8000>>>>>,TrFadeX<Mult<Scale<IsLessThan<WavLen<EFFECT_POSTOFF>,Int<200>>,WavLen<EFFECT_POSTOFF>,Int<4000>>,Int<10000>>>>,EFFECT_POSTOFF>>;


// def getString16(red, green, blue):
//     def convertrgb16(val):
//         return int(pow(val/255, 2.2)*65535)
//     return str(convertrgb16(red)) + "," + str(convertrgb16(green)) +  "," + str(convertrgb16(blue))
// 
// baseColorValues = {
//     'Anakin3': (15, 55, 255),
//     'VaderAnh': (183,12,3),
//     'VaderEsb': (255, 0, 0),
//     'VaderRotj': (255, 0, 0),
//     'VaderRotj': (255, 0, 0),
//     'Obi3': (3,15,255),
//     'ObiAnh': (8,75,235),
//     'LukeAnh': (78,171,235),
//     'LukeDagobah': (49, 134, 229),
//     'LukeBespin': (37, 105, 255),
//     'LukeRotj': (0, 255, 0),
//     'Katarn': (2, 72, 255),
//     'Windu': (173,13,255),
//     'Yoda3': (14,237,5),
//     'Dooku3': (255,8,0),
//     'Palpatine3': (213,7,3),
// }

// for key,val in baseColorValues.items():
//    print("const char *baseColor{} = \"{}\";".format(key, getString16(val[0], val[1], val[2])))

const char *baseColorAnakin3 = "128,2243,65535";
const char *baseColorVaderAnh = "31584,78,3";
const char *baseColorVaderEsb = "65535,0,0";
const char *baseColorVaderRotj = "65535,0,0";
const char *baseColorObi1 = "0,395,65535";
const char *baseColorObi3 = "3,128,65535";
const char *baseColorObiAnh = "32,4438,54756";
const char *baseColorLukeAnh = "4838,27206,54756";
const char *baseColorLukeDagobah = "1739,15911,51727";
const char *baseColorLukeBespin = "937,9304,65535";
const char *baseColorLukeRotj = "0,65535,0";
const char *baseColorKatarn = "1,4057,65535";
const char *baseColorWindu = "27911,93,65535";
const char *baseColorYoda3 = "110,55786,11";
const char *baseColorDooku3 = "65535,32,0";
const char *baseColorMaul = "14386,110,0";
const char *baseColorPalpatine3 = "44108,24,3";

#ifdef SABER_VEEONE
#define KEEGAN_PRESET(fontdirs, track, mainPreset, baseColor, editName) fontdirs, track, StylePtr<mainPreset>(baseColor), StylePtr<CrystalChamberTopPreset>(baseColor), StylePtr<CrystalChamberBottomPreset>(baseColor), StylePtr<BlinkyRedPreset>(), StylePtr<BlinkyGreenPreset>(), editName
#else
#define KEEGAN_PRESET(fontdirs, track, mainPreset, baseColor, editName) fontdirs, track, StylePtr<mainPreset>(baseColor), StylePtr<AccentPresetFett263OriginalTrilogyFett263>(baseColor), editName
#endif

Preset presets[] = {
    // TODO Tracks probably don't make sense for father
    {KEEGAN_PRESET("FatherV2ANH;common", "tracks/track1.wav", MainPresetFett263OriginalTrilogyFett263, baseColorVaderAnh, "FatherANH")},
    {KEEGAN_PRESET("FatherV2ANH;common", "tracks/track1.wav", MainPresetFett263OriginalTrilogyFett263, baseColorVaderAnh, "FatherANH")},
    {KEEGAN_PRESET("FatherV2ESB;common", "tracks/track2.wav", MainPresetFett263OriginalTrilogyFett263, baseColorVaderEsb, "FatherESB")},
    {KEEGAN_PRESET("FatherV2ROTJ;common", "tracks/track3.wav", MainPresetFett263OriginalTrilogyFett263, baseColorVaderRotj, "FatherROTJ")},
    {KEEGAN_PRESET("FatherV2R1;common", "tracks/track4.wav", MainPresetFett263SequelsFett263, baseColorVaderAnh, "FatherR1")},
    {KEEGAN_PRESET("KSith_WhatRemains;common", "tracks/track1.wav", MainPresetFett263SequelsFett263, baseColorVaderAnh, "KSith_WhatRemains")},
    {KEEGAN_PRESET("KSith_CrimsonMenace;common", "tracks/Duel of the Fates.wav", MainPresetFett263SequelsFett263, baseColorVaderAnh, "KSith_CrimsonMenace")},
    {KEEGAN_PRESET("KSith_KRossguardTFA;common", "tracks/Kylo_Theme.wav", MainPresetFett263KyloRen, baseColorVaderAnh, "KSith_KRossguardTFA")},
    {KEEGAN_PRESET("KSith_KRossguardTLJ;common", "tracks/Kylo_Theme2.wav", MainPresetFett263KyloRen, baseColorVaderAnh, "KSith_KRossguardTLJ")},
    {KEEGAN_PRESET("KSith_KRossguardTROS;common", "tracks/Supreme_Leader_Kylo.wav", MainPresetFett263KyloRenSupremeLeader, baseColorVaderAnh, "KSith_KRossguardTROS")},
    // TODO Tracks probably don't make sense for OB4
    {KEEGAN_PRESET("OB4V2Rebels;common", "tracks/track1.wav", MainPresetFett263PrequelsFett263, baseColorObi3, "OB4V2Rebels")},
    {KEEGAN_PRESET("OB4V2Cantina;common", "tracks/track2.wav", MainPresetFett263OriginalTrilogyFett263, baseColorObiAnh, "OB4V2Cantina")},
    {KEEGAN_PRESET("OB4V2DeathStar;common", "tracks/track3.wav", MainPresetFett263OriginalTrilogyFett263, baseColorObiAnh, "OB4V2DeathStar")},
    {KEEGAN_PRESET("BMF;common", "tracks/track1.wav", MainPresetFett263SequelsFett263, baseColorWindu, "BMF")},
    {KEEGAN_PRESET("ANH_Graflex;common", "tracks/track1.wav", MainPresetFett263OriginalTrilogyFett263, baseColorLukeAnh, "ANH_GraflexV2")},
    {KEEGAN_PRESET("ANH_Training;common", "tracks/training_ambience.wav", MainPresetFett263OriginalTrilogyFett263, baseColorLukeAnh, "ANH_TrainingV2")},
    {KEEGAN_PRESET("ESB_Graflex_V2;common", "tracks/track1.wav", MainPresetFett263OriginalTrilogyFett263, baseColorLukeDagobah, "ESB_Graflex_V2")},
    {KEEGAN_PRESET("The_Return_V2;common", "tracks/track1.wav", MainPresetFett263OriginalTrilogyFett263, baseColorLukeRotj, "The_Return_V2")},
    {KEEGAN_PRESET("KSith_LS6CaveScene;common", "", MainPresetFett263OriginalTrilogyFett263, baseColorLukeRotj, "KSith_LS6CaveScene")},
    {KEEGAN_PRESET("KSith_LS6Classic;common", "", MainPresetFett263OriginalTrilogyFett263, baseColorLukeRotj, "KSith_LS6Classic")},
    {KEEGAN_PRESET("KSith_LS6OldVersion;common", "", MainPresetFett263OriginalTrilogyFett263, baseColorLukeRotj, "KSith_LS6OldVersion")},
    {KEEGAN_PRESET("KSith_Rescue;common", "tracks/Hallway_Long.wav", MainPresetFett263OriginalTrilogyFett263, baseColorLukeRotj, "KSith_LS6OldVersion")},
    {KEEGAN_PRESET("Outcast_Knight;common", "", MainPresetFett263OriginalTrilogyFett263, baseColorKatarn, "Outcast_Knight")},
    {KEEGAN_PRESET("Fire;common", "", ControlMainResponsiveFlameRealFlameGradientBaseColor, "", "fire")},
    {KEEGAN_PRESET("Great_Mother_V2;common", "tracks/track1.wav", ControlMainBladeofTalzinBaseColor,"", "morgan")},
    {KEEGAN_PRESET("SurvivorSingle;common", "", ControlMainCalKestisSurvivorBlueKyberSelectSpecialAbility,"", "SurvivorSingle")},
    {KEEGAN_PRESET("SurvivorCrossguard;common", "", ControlMainCalKestisSurvivorBlueKyberSelectSpecialAbility,"", "SurvivorCrossguard")},
    {KEEGAN_PRESET("KSith_TheChosenOneHero;common", "tracks/Battle of the Heroes.wav", MainPresetFett263PrequelsFett263, baseColorLukeAnh, "KSith_TheChosenOneHero")},
    {KEEGAN_PRESET("KSith_TheChosenOneVillain;common", "tracks/Anakin's Turn.wav", MainPresetFett263PrequelsFett263, baseColorVaderAnh, "KSith_TheChosenOneVillain")},
    {KEEGAN_PRESET("KSith_TheSenateTCW;common", "tracks/Palpy1.wav", MainPresetFett263PrequelsFett263, baseColorPalpatine3, "KSith_TheSenateTCW")},
    {KEEGAN_PRESET("KSith_TheSenateROTS;common", "tracks/Order66.wav", MainPresetFett263PrequelsFett263, baseColorPalpatine3, "KSith_TheSenateROTS")},
    {KEEGAN_PRESET("KSith_Savage;common", "tracks/track1.wav", MainPresetFett263PrequelsFett263, baseColorVaderAnh, "KSith_Savage")},
    {KEEGAN_PRESET("KSith_CrimsonMenace;common", "tracks/mars.wav", MainPresetFett263PrequelsFett263, baseColorVaderAnh, "KSith_CrimsonMenace")},
    {KEEGAN_PRESET("KSith_GrandMaster;common", "tracks/Track1_Dooku vs Yoda.wav", MainPresetFett263PrequelsFett263, baseColorYoda3, "KSith_GrandMaster")},
    {KEEGAN_PRESET("The_Counts_Claw_V2AOTC;common", "tracks/track1.wav", MainPresetFett263PrequelsFett263, baseColorDooku3, "The_Counts_Claw_V2AOTC")},
    {KEEGAN_PRESET("The_Counts_Claw_V2ROTS;common", "tracks/track2.wav", MainPresetFett263PrequelsFett263, baseColorDooku3, "The_Counts_Claw_V2ROTS")},
    {KEEGAN_PRESET("KSith_TheBoldOne;common", "tracks/Anakin vs Obi.wav", MainPresetFett263PrequelsFett263, baseColorObi3, "KSith_TheBoldOne")},
    {KEEGAN_PRESET("GODZILLA;common", "", MountSaberFontsGodzilla, "", "GODZILLA")},
    {KEEGAN_PRESET("MECHAGODZILLA;common", "", MountSaberFontsMechagodzilla, "", "MECHAGODZILLA")},
    {KEEGAN_PRESET("JURASSIC;common", "", MountSaberFontsJurassic, "", "JURASSIC")}

};

BladeConfig blades[] = {
#ifdef SABER_VEEONE
    { 0, WS281XBladePtr<133, bladePin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >(),
    WS281XBladePtr<1, blade4Pin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >(),
    WS281XBladePtr<1, blade3Pin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >(),
    SimpleBladePtr<CH1LED, NoLED, NoLED, NoLED, bladePowerPin7, -1, -1, -1>(),
	SimpleBladePtr<CH2LED, NoLED, NoLED, NoLED, bladePowerPin8, -1, -1, -1>(),
#else
    {0, WS281XBladePtr<128, bladePin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3>>(),
     WS281XBladePtr<30, blade2Pin, Color8::GRB, PowerPINS<bladePowerPin4, bladePowerPin5>>(),
#endif
     CONFIGARRAY(presets)},
};
#endif

#ifdef CONFIG_BUTTONS
Button PowerButton(BUTTON_POWER, powerButtonPin, "pow");
Button AuxButton(BUTTON_AUX, auxPin, "aux");
#endif

#ifndef CONFIG_STYLES

#endif
