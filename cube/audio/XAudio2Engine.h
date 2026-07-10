// XAudio2Engine (cube) — reconstructed declarations.
#ifndef CUBE_AUDIO_XAUDIO2ENGINE_H
#define CUBE_AUDIO_XAUDIO2ENGINE_H
#include "../include/cube_types.h"

void blob_deobfuscate(void);
void cube::XAudio2Engine::ctor_0(void);
void cube::XAudio2Engine::ctor_1(void);
void cube::XAudio2Engine::Sound::vfunc_0(byte param_1);
void cube::XAudio2Engine::vfunc_8(byte param_1);
undefined4 riff_findChunkInMemory(int *param_1,int *param_2,undefined4 *param_3,int *param_4);
uint riff_findChunkInFile(HANDLE param_1,int param_2,int *param_3,int *param_4);
undefined4 riff_readFromMemory(int *param_1,void *param_2,size_t param_3,int param_4);
uint riff_readFromFile(HANDLE param_1,LPVOID param_2,DWORD param_3,LONG param_4);
void cube::XAudio2Engine::vfunc_0(void);
undefined4 cube::XAudio2Engine::vfunc_4(void);
void cube::XAudio2Engine::vfunc_6(int *param_1,float param_2,undefined4 param_3,undefined4 param_4);
void XAudio2_loadSound(char *param_1,undefined1 param_2);
void cube::XAudio2Engine::vfunc_1(undefined4 param_1,int param_2,undefined4 param_3);
void cube::XAudio2Engine::vfunc_5(undefined4 param_1,undefined4 param_2);
void cube::XAudio2Engine::Sound::ctor_0(undefined4 *param_1);
void cube::XAudio2Engine::vfunc_3(void);
void XAudio2_decodeStream(void);
void cube::XAudio2Engine::vfunc_2(void);
undefined4 XAudio2_resetDecoder(int *param_1);
int XAudio2_decodeFrame(int param_1,uint param_2,int param_3);
int codec_readHeaderFields(int param_1,int param_2);
void XAudio2_initDecodeState(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4, undefined4 param_5,undefined4 param_6,undefined4 param_7);
void XAudio2_setupDecoder(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4);

#endif
