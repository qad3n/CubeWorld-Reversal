// Speech (server) — reconstructed declarations.
#ifndef SERVER_ENTITY_SPEECH_H
#define SERVER_ENTITY_SPEECH_H
#include "../include/cube_types.h"

void __fastcall Speech_scrambleBlob(int *param_1);
uint __thiscall SpeechDb_createBlobsTable(void *this,int *param_1);
undefined4 __thiscall SpeechDb_loadBlobToVector(void *this,undefined4 *param_1,undefined4 *param_2);
int * __fastcall XmlDoc_ctorInit(int *param_1);
uint __thiscall Iterator_notEqual(void *this,uint *param_1);
int __fastcall compareResultToSign(int *param_1);
void __thiscall Iterator_derefAndAdvance(void *this,int *param_1);
void __thiscall Xml_findAttributeByName(void *this,int *param_1,ushort *param_2);
void __thiscall Xml_getFirstChildHandle(void *this,undefined4 *param_1);
void __thiscall Xml_findChildByName(void *this,int *param_1,ushort *param_2);
undefined * __fastcall Xml_getFirstTextValue(int *param_1);
void __fastcall XmlDoc_initPool(int *param_1);
void __fastcall XmlDoc_freePool(int *param_1);
void __thiscall Xml_getRootHandle(void *this,undefined4 *param_1);
void __thiscall Xml_getRootValue(void *this,undefined4 *param_1);
void __thiscall Xml_loadAndParse(void *this,undefined8 *param_1,uint *param_2,uint param_3,uint param_4,uint param_5);
undefined * __fastcall Xml_getNodeName(int *param_1);
void __cdecl Xml_parseWithSetjmp(undefined8 *param_1,ushort *param_2,int param_3,uint *param_4,uint param_5);
void QuestTextNode_allocSentinel64(void);
void SpeechTree_destroyRec(int *param_1);
undefined4 * __thiscall SpeechMap_eraseRange(void *this,undefined4 *param_1,int *param_2,int *param_3);
void __thiscall Speech_parseTextToNodes(void *this,undefined4 *param_1);
undefined4 __fastcall identityReturn(undefined4 param_1);
basic_istream<wchar_t,std::char_traits<wchar_t>_> * wistream_extractWord(basic_istream<wchar_t,std::char_traits<wchar_t>_> *param_1,undefined4 *param_2);
void wistream_extractWord_ehExit(void);
void __fastcall cube::Speech::ctor_0(undefined4 *param_1);
void __fastcall cube::Speech::ctor_1(undefined4 *param_1);
void __thiscall Speech_map_insertStringEntry(void *this,ushort *param_1);
undefined4 * __thiscall cube::Speech::vfunc_0(Speech *this,byte param_1);
void __fastcall Speech_clear(int param_1);

#endif
