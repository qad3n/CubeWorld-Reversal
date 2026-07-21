// QuestText (cube) — reconstructed declarations.
#ifndef CUBE_ENTITY_QUESTTEXT_H
#define CUBE_ENTITY_QUESTTEXT_H
#include "../include/cube_types.h"

void QuestText_copyTree(int *param_1,undefined4 param_2);
undefined4 * QuestText_copyTreeNode(undefined4 *param_1,undefined4 param_2,undefined4 param_3);
void std_map_insert_unique(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3,undefined4 param_4);
void cube::QuestText::ctor_1(void);
void cube::QuestText::ctor_2(void);
void cube::QuestText::vfunc_0(void);
void cube_QuestTextNode_destroyTree(uint param_1);
undefined2 QuestText_isPunctuation(short param_1);
/* WARNING: Type propagation algorithm not settling */ void cube::QuestText::parseTemplate(undefined4 *param_1);
int cube::QuestText::ctor_3(int param_1);
undefined4 * QuestText_insertHint_str(undefined4 *param_1,int *param_2,undefined4 *param_3,undefined4 param_4);
void QuestText_insertUnique_str(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3,undefined4 param_4);
void QuestText_member_ctor(undefined4 param_1);
void cube::QuestText::ctor_0(int param_1);
void QuestText_delete_node(void *param_1);

#endif
