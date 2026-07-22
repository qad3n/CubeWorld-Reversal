// Speech (cube) — reconstructed declarations.
#ifndef CUBE_ENTITY_SPEECH_H
#define CUBE_ENTITY_SPEECH_H
#include "../include/cube_types.h"

void xml_memoryPool_ctor(void);
uint xml_iterator_notEqual(uint *param_1);
int xml_iterator_isValid(void);
void xml_iterator_deref_advance(int *param_1);
void xml_node_findChildByName(int *param_1,ushort *param_2);
void xml_node_firstChild(undefined4 *param_1);
void xml_node_findAttributeByName(int *param_1,ushort *param_2);
undefined ** xml_document_firstElementNode(void);
void xml_memoryPool_initArena(void);
void xml_memoryPool_freeAll(void);
void xml_node_ctor_setParent(undefined4 *param_1);
void xml_document_firstNode(undefined4 *param_1);
void xml_document_parseWithEncoding(undefined8 *param_1,int param_2,undefined4 param_3,undefined4 param_4, undefined4 param_5);
undefined ** xml_document_root(void);
void xml_parse_setjmpWrapper(undefined8 *param_1,int param_2,int param_3,int param_4,undefined4 param_5);
void QuestText_copyTree_b(int *param_1,undefined4 param_2);
void std_list_resize_insert(undefined4 *param_1,undefined4 *param_2);
void cube::Speech::ctor_1(void);
void cube::Speech::ctor_0(void);
void map_insert_string_key2(int param_1);
void cube::Speech::vfunc_0(byte param_1);
void node_alloc(void);
undefined4 * Speech_map_erase_range(undefined4 *param_1,int *param_2,int *param_3);
void Speech_map_erase_node(undefined4 param_1,int *param_2);
undefined4 * Speech_map_erase_range2(undefined4 *param_1,int *param_2,int *param_3);
void Speech_map_erase_node_qt(undefined4 param_1,int *param_2);

#endif
