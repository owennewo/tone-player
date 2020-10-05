# tone-player
This is an arduino library that can play musical tones on a speaker (boring!) or a BLDC motor (that's more like it!)

## Youtube
[![Hoverboard BLDC Motor as Jukebox -featuring storm32 gimbal controller](https://i9.ytimg.com/vi/iqQp86-zv90/mq2.jpg?sqp=CKDz7PsF&rs=AOn4CLAK7QiIxoBjsX15bIsJOOtRckXPdA)](https://youtu.be/iqQp86-zv90)

## Overview
This library has a RTTTL parser and is able to play polytones on multiple BLDC motors such as the hoverboard motor in the vid.  You can set up a jukebox of songs for it to play and repeat.  It can also play tunes on boring speakers too.

I've used a storm32 gimbal controller to drive the motors - this is a fair bit more powerful than an atmega328p but I reckon the simple examples will squeeze into the 2K of SRAM of an UNO.

##Examples
The examples folder contains:
| Example  | Description  | Piezo  | BLDC  |
|---|---|---|---|
| openloop  | This example checks whether you have your voltage limits correct for BLDC  | [bldc/0_openloop_motor.cpp](./examples/bldc/0_openloop_motor.cpp)  | n/a  | 
| frequency sweep  | Plays descending frequency from octave 8 to octave 0 (108 notes)  | [bldc/1_frequency_sweep.cpp](./examples/bldc/1_frequency_sweep.cpp)  | [piezo/1_frequency_sweep.cpp](./examples/piezo/1_frequency_sweep.cpp)  | 
| simple tones  |  Plays old macdonald (doesn't use RTTTL)  |  [bldc/2_simple_tones.cpp](./examples/bldc/2_simple_tones.cpp) | [bldc/2_simple_tones.cpp](./examples/bldc/2_simple_tones.cpp)  | 
| serial player  | Takes input from your keyboard e.g. you press c it plays c5  | [bldc/3_serial_player.cpp](./examples/bldc/3_serial_player.cpp)  |  [piezo/3_serial_player.cpp](./examples/piezo/3_serial_player.cpp) | 
| ringtone player  | Plays pink panther RTTTL  | [bldc/4_ringtone_player.cpp](./examples/bldc/4_ringtone_player.cpp)  | [piezo/4_ringtone_player.cpp](./examples/piezo/4_ringtone_player.cpp)  |
| polytone player  | Plays polyphonic (two track) super mario theme on two 'speakers'  | [bldc/5_polytone_player.cpp](./examples/bldc/5_polytone_player.cpp)  | [piezo/5_polytone_player.cpp](./examples/piezo/5_polytone_player.cpp)  |
| jukebox player  | Plays a set of RTTTL songs  | [bldc/6_jukebox_player.cpp](./examples/bldc/6_jukebox_player.cpp)  | [piezo/6_jukebox_player.cpp](./examples/piezo/6_jukebox_player.cpp)  |

## Jukebox
The jukebox is a set of RTTTL files that are found in [RTTTL.h](./RTTTL.h).  Only one is polyphonic (it sort of follows the PTTTL format)
 * RTTTL_CROATIA
 * RTTTL_FRANCE
 * RTTTL_WALES
 * RTTTL_USA
 * RTTTL_SIMPSONS
 * RTTTL_PINK_PANTHER
 * RTTTL_SUPER_MARIO_BROS
 * RTTTL_SUPER_MARIO_BROS_BASS
 * RTTTL_SUPER_MARIO_BROS_POLY
 
