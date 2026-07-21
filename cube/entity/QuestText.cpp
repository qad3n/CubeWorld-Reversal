// QuestText (entity) — cube. 15 functions. Bodies = Ghidra pseudo-C.
#include "QuestText.h"

/* [AUDIT] proposed: QuestText_copyTree  (confidence: high)
 * purpose: Copies a QuestText std::map red-black tree, then fixes leftmost/rightmost pointers
 * vars: in_ECX map header
 */
/* Global::QuestText_copyTree @ 004d9b10 */

void QuestText_copyTree(int *srcRoot,undefined4 param_2)

{
  char cVar1;
  int dstNode;
  int *root;
  int *child;
  int parent;
  int *leaf;
  undefined4 uVar7;
  int *in_ECX;
  
  dstNode = *in_ECX;
  uVar7 = QuestText_copyTreeNode(*(undefined4 *)(*srcRoot + 4),dstNode,param_2);
  *(undefined4 *)(dstNode + 4) = uVar7;
  root = (int *)*in_ECX;
  in_ECX[1] = srcRoot[1];
  child = (int *)root[1];
  if (*(char *)((int)child + 0xd) != '\0') {
    *root = (int)root;
    *(int *)(*in_ECX + 8) = *in_ECX;
    return;
  }
  cVar1 = *(char *)(*child + 0xd);
  leaf = (int *)*child;
  while (cVar1 == '\0') {
    cVar1 = *(char *)(*leaf + 0xd);
    child = leaf;
    leaf = (int *)*leaf;
  }
  *root = (int)child;
  dstNode = *(int *)(*in_ECX + 4);
  parent = *(int *)(dstNode + 8);
  cVar1 = *(char *)(parent + 0xd);
  while (cVar1 == '\0') {
    cVar1 = *(char *)(*(int *)(parent + 8) + 0xd);
    dstNode = parent;
    parent = *(int *)(parent + 8);
  }
  *(int *)(*in_ECX + 8) = dstNode;
  return;
}




/* [AUDIT] proposed: QuestText_copyTreeNode  (confidence: high)
 * purpose: Recursively copies a red-black tree subtree (left/right) into destination map
 * vars: recursion via 004d9b90
 */
/* Global::QuestText_copyTreeNode @ 004d9b90 */

undefined4 * QuestText_copyTreeNode(undefined4 *srcNode,undefined4 parent,undefined4 param_3)

{
  undefined4 *newNode;
  undefined4 childNode;
  int *in_ECX;
  undefined4 *root;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_006e8e30;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  root = (undefined4 *)*in_ECX;
  if (*(char *)((int)srcNode + 0xd) == '\0') {
    newNode = (undefined4 *)QuestText_cloneNode(srcNode + 4);
    newNode[1] = parent;
    *(undefined1 *)(newNode + 3) = *(undefined1 *)(srcNode + 3);
    if (*(char *)((int)root + 0xd) != '\0') {
      root = newNode;
    }
    local_8 = 0;
    childNode = QuestText_copyTreeNode(*srcNode,newNode,param_3);
    *newNode = childNode;
    childNode = QuestText_copyTreeNode(srcNode[2],newNode,param_3);
    newNode[2] = childNode;
  }
  ExceptionList = local_10;
  return root;
}




/* [AUDIT] proposed: std_map_insert_unique  (confidence: med)
 * purpose: std::map lower_bound + insert-unique using wide-string comparator (u16string_compare)
 * vars: param_3=key;in_ECX=tree
 */
/* Global::std_map_insert_unique @ 004da050 */

void std_map_insert_unique(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  int *in_ECX;
  bool bVar7;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puVar5 = param_3;
  puStack_c = &LAB_006e8e50;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  bVar7 = true;
  local_8 = 0;
  puVar1 = (undefined4 *)*in_ECX;
  puVar4 = (undefined4 *)((undefined4 *)*in_ECX)[1];
  while (*(char *)((int)puVar4 + 0xd) == '\0') {
    if ((char)param_2 == '\0') {
      piVar3 = puVar4 + 4;
      if (7 < (uint)puVar4[9]) {
        piVar3 = (int *)*piVar3;
      }
      iVar2 = u16string_compare(0,puVar5[4],piVar3,puVar4[8]);
      bVar7 = iVar2 < 0;
    }
    else {
      puVar1 = puVar5;
      if (7 < (uint)puVar5[5]) {
        puVar1 = (undefined4 *)*puVar5;
      }
      iVar2 = u16string_compare(0,puVar4[8],puVar1,puVar5[4]);
      bVar7 = -1 < iVar2;
    }
    puVar1 = puVar4;
    if (bVar7 == false) {
      puVar4 = (undefined4 *)puVar4[2];
    }
    else {
      puVar4 = (undefined4 *)*puVar4;
    }
  }
  param_2 = puVar1;
  if (bVar7 != false) {
    if (puVar1 == *(undefined4 **)*in_ECX) {
      puVar4 = &param_2;
      bVar7 = true;
      goto LAB_004da111;
    }
    rbtree_iteratorIncrement();
  }
  puVar4 = param_2;
  puVar6 = puVar5;
  if (7 < (uint)puVar5[5]) {
    puVar6 = (undefined4 *)*puVar5;
  }
  iVar2 = u16string_compare(0,param_2[8],puVar6,puVar5[4]);
  if (-1 < iVar2) {
    *param_1 = puVar4;
    *(undefined1 *)(param_1 + 1) = 0;
    ExceptionList = local_10;
    return;
  }
  puVar4 = &param_3;
LAB_004da111:
  puVar5 = (undefined4 *)std_Tree_insert_rebalance(puVar4,bVar7,puVar1,puVar5,param_4);
  *param_1 = *puVar5;
  *(undefined1 *)(param_1 + 1) = 1;
  ExceptionList = local_10;
  return;
}




/* cube::QuestText::ctor_1 @ 004da380 */

void cube::QuestText::ctor_1(void)

{
  undefined4 list;
  undefined4 *self;
  
  *self = vftable;
  self[1] = 0;
  self[2] = 0;
  self[3] = 0;
  list = rbtree_allocHeaderNode_28();
  self[2] = list;
  return;
}




/* cube::QuestText::ctor_2 @ 004da4c0 */

void cube::QuestText::ctor_2(void)

{
  uint cookie;
  undefined4 *self;
  undefined1 local_14 [4];
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_006e8eeb;
  local_10 = ExceptionList;
  cookie = DAT_0076aa78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *self = vftable;
  local_8 = 0;
  if ((undefined4 *)self[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)self[1])(1,cookie);
  }
  local_8 = 0xffffffff;
  std_map_eraseRange_661a20(local_14,*(undefined4 *)self[2],(undefined4 *)self[2]);
                    /* WARNING: Subroutine does not return */
  operator_delete((void *)self[2]);
}




/* cube::QuestText::vfunc_0 @ 004da670 */

void cube::QuestText::vfunc_0(void)

{
  uint cookie;
  undefined4 *self;
  undefined1 local_14 [4];
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_006e8f7b;
  local_10 = ExceptionList;
  cookie = DAT_0076aa78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *self = vftable;
  local_8 = 0;
  if ((undefined4 *)self[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)self[1])(1,cookie);
  }
  local_8 = 0xffffffff;
  std_map_eraseRange_661a20(local_14,*(undefined4 *)self[2],(undefined4 *)self[2]);
                    /* WARNING: Subroutine does not return */
  operator_delete((void *)self[2]);
}




/* [AUDIT] proposed: cube_QuestTextNode_destroyTree  (confidence: med)
 * purpose: Recursively destroy QuestTextNode tree: free child maps and node lists
 * vars: param_1=node
 */
/* Global::cube_QuestTextNode_destroyTree @ 004da770 */

void cube_QuestTextNode_destroyTree(uint param_1)

{
  int *piVar1;
  uint uVar2;
  int *piVar3;
  
  uVar2 = param_1;
  if (param_1 != 0) {
    piVar3 = (int *)(param_1 + 4);
    std_Tree_destroy_subtree(**(undefined4 **)(param_1 + 4),*(undefined4 **)(param_1 + 4));
    piVar1 = (int *)(param_1 + 0xc);
    if (piVar1 != piVar3) {
      std_map_eraseTreeRec(*(undefined4 *)(*piVar1 + 4));
      param_1 = param_1 & 0xffffff00;
      *(int *)(*piVar1 + 4) = *piVar1;
      *(int *)*piVar1 = *piVar1;
      *(int *)(*piVar1 + 8) = *piVar1;
      *(undefined4 *)(uVar2 + 0x10) = 0;
      QuestText_copyTree(piVar3,param_1);
    }
    piVar3 = (int *)**(int **)(uVar2 + 0x38);
    if (piVar3 != *(int **)(uVar2 + 0x38)) {
      do {
        cube_QuestTextNode_destroyTree(piVar3[2]);
        std_Tree_destroy_subtree(**(undefined4 **)(piVar3[2] + 0xc),*(undefined4 **)(piVar3[2] + 0xc));
        piVar3 = (int *)*piVar3;
      } while (piVar3 != (int *)*(int *)(uVar2 + 0x38));
    }
  }
  return;
}




/* [AUDIT] proposed: QuestText_isPunctuation  (confidence: med)
 * purpose: Return 1 if wide char is punctuation (. : - , ; ! ? / ( ))
 * vars: param_1=ch
 */
/* Global::QuestText_isPunctuation @ 004da800 */

undefined2 QuestText_isPunctuation(short param_1)

{
  if ((((((param_1 != 0x2e) && (param_1 != 0x3a)) && (param_1 != 0x2d)) &&
       ((param_1 != 0x2c && (param_1 != 0x3b)))) &&
      ((param_1 != 0x21 && ((param_1 != 0x3f && (param_1 != 0x2f)))))) &&
     ((param_1 != 0x28 && (param_1 != 0x29)))) {
    return 0;
  }
  return 1;
}




/* [AUDIT] proposed: cube::QuestText::parseTemplate  (confidence: med)
 * purpose: Parse quest-text template string into QuestTextNode tree, splitting {..}/[..]/word tokens
 * vars: param_1=out;in_ECX=QuestText
 */
/* cube::QuestText::parseTemplate @ 004da850 */
/* NOTE(re) 2026-07-15 audit: RECLASSIFIED lib->game. Identity (RE-inferred, high): cube::QuestText::parseTemplate.
 * operator_new(0x44)+cube::QuestTextNode::ctor_0 (twice), scans wide chars for 0x20(space)/0x7b('{') building an IntMap node tree (IntMap_SetScalar). Caller 004e1970=cube::Speech::ctor_1. RTTI AUQuestTextNode@cube@@. Quest-text templating, not string code.
 * Routed to its true class unit by curated_override.tsv (reconstruct2). See scratchpad/audit/verdicts.json. */

/* WARNING: Type propagation algorithm not settling */

void cube::QuestText::parseTemplate(undefined4 *param_1)

{
  short sVar1;
  char cVar2;
  undefined4 uVar3;
  int *piVar4;
  int iVar5;
  undefined4 *puVar6;
  int *piVar7;
  int iVar8;
  short *******pppppppsVar9;
  undefined4 *puVar10;
  int in_ECX;
  uint extraout_ECX;
  uint uVar11;
  short *psVar12;
  undefined4 *extraout_EDX;
  uint uVar13;
  int in_stack_00000014;
  uint in_stack_00000018;
  undefined1 local_68 [8];
  undefined1 local_60 [8];
  int local_58;
  void *local_54;
  int local_50;
  short local_4c [2];
  undefined4 *local_48;
  int *local_44;
  uint local_40;
  int *local_3c;
  int *local_38;
  int local_34;
  undefined4 *local_30;
  short *******local_2c [5];
  uint local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_006e9005;
  local_10 = ExceptionList;
  local_14 = DAT_0076aa78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  puVar10 = (undefined4 *)(in_ECX + 4);
  local_8 = 0;
  local_58 = in_ECX;
  if (*(undefined4 **)(in_ECX + 4) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(in_ECX + 4))(1,local_14);
    *puVar10 = 0;
  }
  local_54 = operator_new(0x44);
  local_8._0_1_ = 1;
  if (local_54 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = cube::QuestTextNode::ctor_0();
  }
  *puVar10 = uVar3;
  local_8._0_1_ = 0;
  std_map_eraseTreeRec(*(undefined4 *)(*(int *)(in_ECX + 8) + 4));
  *(int *)(*(int *)(in_ECX + 8) + 4) = *(int *)(in_ECX + 8);
  *(undefined4 *)*(undefined4 *)(in_ECX + 8) = *(undefined4 *)(in_ECX + 8);
  *(int *)(*(int *)(in_ECX + 8) + 8) = *(int *)(in_ECX + 8);
  *(undefined4 *)(in_ECX + 0xc) = 0;
  local_40 = 0;
  piVar4 = (int *)list_buyNode_0c(0,0);
  local_8._0_1_ = 2;
  local_44 = piVar4;
  iVar5 = IntMap_SetScalar(piVar4,piVar4[1],puVar10);
  piVar4[1] = iVar5;
  **(int **)(iVar5 + 4) = iVar5;
  uVar13 = 1;
  local_40 = 1;
  local_54 = (void *)in_stack_00000014;
  local_50 = -1;
  local_34 = 0;
  uVar11 = in_stack_00000018;
  puVar10 = param_1;
  if (-1 < in_stack_00000014) {
    do {
      iVar5 = local_34;
      puVar6 = &param_1;
      if (7 < uVar11) {
        puVar6 = puVar10;
      }
      if (*(short *)((int)puVar6 + local_34 * 2) == 0x20) {
LAB_004da9f8:
        puVar6 = &param_1;
        if (7 < uVar11) {
          puVar6 = puVar10;
        }
        if (*(short *)((int)puVar6 + iVar5 * 2) == 0x7b) {
          local_30 = operator_new(0x44);
          local_8._0_1_ = 3;
          if (local_30 == (undefined4 *)0x0) {
            piVar7 = (int *)0x0;
          }
          else {
            piVar7 = (int *)cube::QuestTextNode::ctor_0();
          }
          piVar7[0x10] = 2;
          local_38 = (int *)(*(int *)(piVar4[1] + 8) + 0x38);
          local_48 = (undefined4 *)*local_38;
          local_8._0_1_ = 2;
          local_3c = piVar7;
          local_30 = (undefined4 *)IntMap_SetScalar(local_48,local_48[1],&local_3c);
          if (local_38[1] == 0x15555554) goto LAB_004db0eb;
          local_38[1] = local_38[1] + 1;
          local_48[1] = local_30;
          *(undefined4 **)local_30[1] = local_30;
          piVar7[0xd] = *(int *)(piVar4[1] + 8);
          iVar5 = IntMap_SetScalar(piVar4,piVar4[1],&local_3c);
          if (uVar13 == 0x15555554) goto LAB_004db0eb;
          piVar4[1] = iVar5;
          **(int **)(iVar5 + 4) = iVar5;
          local_40 = uVar13 + 1;
          local_30 = operator_new(0x44);
          local_8._0_1_ = 4;
          if (local_30 == (undefined4 *)0x0) {
            local_3c = (int *)0x0;
          }
          else {
            local_3c = (int *)cube::QuestTextNode::ctor_0();
          }
          iVar5 = *(int *)(piVar4[1] + 8);
          local_30 = *(undefined4 **)(iVar5 + 0x38);
          local_8._0_1_ = 2;
          local_38 = local_3c;
          iVar8 = IntMap_SetScalar(local_30,local_30[1],&local_38);
          if (*(int *)(iVar5 + 0x3c) == 0x15555554) goto LAB_004db0eb;
          *(int *)(iVar5 + 0x3c) = *(int *)(iVar5 + 0x3c) + 1;
          local_30[1] = iVar8;
          **(int **)(iVar8 + 4) = iVar8;
          local_3c[0xd] = *(int *)(piVar4[1] + 8);
          iVar5 = IntMap_SetScalar(piVar4,piVar4[1],&local_38);
          if (uVar13 + 1 == 0x15555554) goto LAB_004db0eb;
          piVar4[1] = iVar5;
          uVar13 = uVar13 + 2;
          **(int **)(iVar5 + 4) = iVar5;
          local_40 = uVar13;
          uVar11 = in_stack_00000018;
          puVar10 = param_1;
          iVar5 = local_34;
        }
        puVar6 = &param_1;
        if (7 < uVar11) {
          puVar6 = puVar10;
        }
        if (*(short *)((int)puVar6 + iVar5 * 2) == 0x5b) {
          local_30 = operator_new(0x44);
          local_8._0_1_ = 5;
          if (local_30 == (undefined4 *)0x0) {
            piVar7 = (int *)0x0;
          }
          else {
            piVar7 = (int *)cube::QuestTextNode::ctor_0();
          }
          piVar7[0x10] = 3;
          local_30 = (undefined4 *)(*(int *)(piVar4[1] + 8) + 0x38);
          local_48 = (undefined4 *)*local_30;
          local_8._0_1_ = 2;
          local_38 = piVar7;
          local_3c = (int *)IntMap_SetScalar(local_48,local_48[1],&local_38);
          if (local_30[1] == 0x15555554) goto LAB_004db0eb;
          local_30[1] = local_30[1] + 1;
          local_48[1] = local_3c;
          *(int **)local_3c[1] = local_3c;
          piVar7[0xd] = *(int *)(piVar4[1] + 8);
          iVar5 = IntMap_SetScalar(piVar4,piVar4[1],&local_38);
          if (uVar13 == 0x15555554) goto LAB_004db0eb;
          piVar4[1] = iVar5;
          uVar13 = uVar13 + 1;
          **(int **)(iVar5 + 4) = iVar5;
          local_40 = uVar13;
          uVar11 = in_stack_00000018;
          puVar10 = param_1;
        }
        if (local_50 + 1 < local_34) {
LAB_004dac89:
          wstring_ctorFromRange(local_2c,local_50 + 1,(local_34 - local_50) + -1);
          pppppppsVar9 = (short *******)local_2c;
          if (7 < local_18) {
            pppppppsVar9 = local_2c[0];
          }
          local_8._0_1_ = 6;
          if (*(short *)pppppppsVar9 == 0x23) {
            std_map_insert_unique(local_68,0,local_2c,DAT_0076b2a6);
          }
          else {
            pppppppsVar9 = (short *******)local_2c;
            if (7 < local_18) {
              pppppppsVar9 = local_2c[0];
            }
            if (*(short *)pppppppsVar9 == 0x24) {
              std_map_insert_unique(local_60,0,local_2c,DAT_0076b2a6);
            }
            else {
              local_30 = operator_new(0x44);
              local_8._0_1_ = 7;
              if (local_30 == (undefined4 *)0x0) {
                puVar10 = (undefined4 *)0x0;
              }
              else {
                puVar10 = (undefined4 *)cube::QuestTextNode::ctor_0();
              }
              local_8._0_1_ = 6;
              local_30 = puVar10;
              if ((short ********)(puVar10 + 7) != local_2c) {
                u16string_replaceRange(local_2c,0,0xffffffff);
              }
              local_48 = (undefined4 *)(*(int *)(piVar4[1] + 8) + 0x38);
              local_38 = (int *)*local_48;
              local_30 = (undefined4 *)IntMap_SetScalar(local_38,local_38[1],&local_30);
              if (local_48[1] == 0x15555554) goto LAB_004db0eb;
              local_48[1] = local_48[1] + 1;
              local_38[1] = (int)local_30;
              *(undefined4 **)local_30[1] = local_30;
              puVar10[0xd] = *(undefined4 *)(piVar4[1] + 8);
              puVar10 = &param_1;
              if (7 < in_stack_00000018) {
                puVar10 = param_1;
              }
              sVar1 = *(short *)((int)puVar10 + local_34 * 2);
              if (((((sVar1 == 0x2e) || (sVar1 == 0x3a)) || (sVar1 == 0x2d)) ||
                  (((sVar1 == 0x2c || (sVar1 == 0x3b)) ||
                   ((sVar1 == 0x21 || ((sVar1 == 0x3f || (sVar1 == 0x2f)))))))) ||
                 ((sVar1 == 0x28 || (sVar1 == 0x29)))) {
                puVar10 = &param_1;
                if (7 < in_stack_00000018) {
                  puVar10 = param_1;
                }
                local_4c[0] = *(short *)((int)puVar10 + local_34 * 2);
                local_4c[1] = 0;
                local_30 = operator_new(0x44);
                local_8._0_1_ = 8;
                if (local_30 == (undefined4 *)0x0) {
                  puVar10 = (undefined4 *)0x0;
                }
                else {
                  puVar10 = (undefined4 *)cube::QuestTextNode::ctor_0();
                }
                local_8._0_1_ = 6;
                local_30 = puVar10;
                if (local_4c[0] == 0) {
                  iVar5 = 0;
                }
                else {
                  psVar12 = local_4c;
                  do {
                    sVar1 = *psVar12;
                    psVar12 = psVar12 + 1;
                  } while (sVar1 != 0);
                  iVar5 = (int)psVar12 - (int)(local_4c + 1) >> 1;
                }
                u16string_assignPtrLen(local_4c,iVar5);
                puVar10[0x10] = 1;
                puVar10[0xd] = *(undefined4 *)(piVar4[1] + 8);
                iVar5 = *(int *)(piVar4[1] + 8);
                local_48 = *(undefined4 **)(iVar5 + 0x38);
                iVar8 = IntMap_SetScalar(local_48,local_48[1],&local_30);
                if (*(int *)(iVar5 + 0x3c) == 0x15555554) goto LAB_004db0eb;
                *(int *)(iVar5 + 0x3c) = *(int *)(iVar5 + 0x3c) + 1;
                local_48[1] = iVar8;
                **(int **)(iVar8 + 4) = iVar8;
              }
            }
          }
          local_8._0_1_ = 2;
          puVar10 = param_1;
          if (7 < local_18) {
                    /* WARNING: Subroutine does not return */
            operator_delete(local_2c[0]);
          }
        }
        else {
          puVar6 = &param_1;
          if (7 < uVar11) {
            puVar6 = puVar10;
          }
          sVar1 = *(short *)((int)puVar6 + local_34 * 2);
          if (((((((sVar1 == 0x2e) || (sVar1 == 0x3a)) || (sVar1 == 0x2d)) ||
                ((sVar1 == 0x2c || (sVar1 == 0x3b)))) ||
               ((sVar1 == 0x21 || ((sVar1 == 0x3f || (sVar1 == 0x2f)))))) || (sVar1 == 0x28)) ||
             (sVar1 == 0x29)) goto LAB_004dac89;
        }
        puVar6 = &param_1;
        if (7 < in_stack_00000018) {
          puVar6 = puVar10;
        }
        local_50 = local_34;
        if (*(short *)((int)puVar6 + local_34 * 2) == 0x7c) {
          if (uVar13 < 2) goto LAB_004db094;
          piVar7 = (int *)piVar4[1];
          if (piVar7 != piVar4) {
            *(int *)piVar7[1] = *piVar7;
            *(int *)(*piVar7 + 4) = piVar7[1];
                    /* WARNING: Subroutine does not return */
            operator_delete(piVar7);
          }
          local_30 = operator_new(0x44);
          local_8._0_1_ = 9;
          if (local_30 == (undefined4 *)0x0) {
            local_3c = (int *)0x0;
          }
          else {
            local_3c = (int *)cube::QuestTextNode::ctor_0();
          }
          iVar5 = *(int *)(piVar4[1] + 8);
          local_30 = *(undefined4 **)(iVar5 + 0x38);
          local_8._0_1_ = 2;
          local_38 = local_3c;
          iVar8 = IntMap_SetScalar(local_30,local_30[1],&local_3c);
          if (*(int *)(iVar5 + 0x3c) == 0x15555554) {
LAB_004db0eb:
                    /* WARNING: Subroutine does not return */
            std::_Xlength_error("list<T> too long");
          }
          *(int *)(iVar5 + 0x3c) = *(int *)(iVar5 + 0x3c) + 1;
          local_30[1] = iVar8;
          **(int **)(iVar8 + 4) = iVar8;
          local_38[0xd] = *(int *)(piVar4[1] + 8);
          iVar5 = IntMap_SetScalar(piVar4,piVar4[1],&local_3c);
          if (uVar13 == 0x15555554) goto LAB_004db0eb;
          piVar4[1] = iVar5;
          uVar13 = uVar13 + 1;
          **(int **)(iVar5 + 4) = iVar5;
          local_40 = uVar13;
          puVar10 = param_1;
        }
        puVar6 = &param_1;
        if (7 < in_stack_00000018) {
          puVar6 = puVar10;
        }
        if (*(short *)((int)puVar6 + local_34 * 2) == 0x7d) {
          if (uVar13 < 3) goto LAB_004db094;
          piVar7 = (int *)piVar4[1];
          if (piVar7 != piVar4) {
            *(int *)piVar7[1] = *piVar7;
            *(int *)(*piVar7 + 4) = piVar7[1];
                    /* WARNING: Subroutine does not return */
            operator_delete(piVar7);
          }
          piVar7 = (int *)piVar4[1];
          if (piVar7 != piVar4) {
            *(int *)piVar7[1] = *piVar7;
            *(int *)(*piVar7 + 4) = piVar7[1];
                    /* WARNING: Subroutine does not return */
            operator_delete(piVar7);
          }
        }
        puVar6 = &param_1;
        if (7 < in_stack_00000018) {
          puVar6 = puVar10;
        }
        uVar11 = in_stack_00000018;
        iVar5 = local_34;
        if (*(short *)((int)puVar6 + local_34 * 2) == 0x5d) {
          if (uVar13 < 2) goto LAB_004db094;
          piVar7 = (int *)piVar4[1];
          if (piVar7 != piVar4) {
            *(int *)piVar7[1] = *piVar7;
            *(int *)(*piVar7 + 4) = piVar7[1];
                    /* WARNING: Subroutine does not return */
            operator_delete(piVar7);
          }
        }
      }
      else {
        puVar6 = &param_1;
        if (7 < uVar11) {
          puVar6 = puVar10;
        }
        if (*(short *)((int)puVar6 + local_34 * 2) == 10) goto LAB_004da9f8;
        puVar6 = &param_1;
        if (7 < uVar11) {
          puVar6 = puVar10;
        }
        if (*(short *)((int)puVar6 + local_34 * 2) == 9) goto LAB_004da9f8;
        puVar6 = &param_1;
        if (7 < uVar11) {
          puVar6 = puVar10;
        }
        if (*(short *)((int)puVar6 + local_34 * 2) == 0) goto LAB_004da9f8;
        puVar6 = &param_1;
        if (7 < uVar11) {
          puVar6 = puVar10;
        }
        cVar2 = QuestText_isPunctuation(*(undefined2 *)((int)puVar6 + local_34 * 2));
        uVar11 = extraout_ECX;
        puVar10 = extraout_EDX;
        if (cVar2 != '\0') goto LAB_004da9f8;
        puVar6 = &param_1;
        if (7 < extraout_ECX) {
          puVar6 = extraout_EDX;
        }
        if (*(short *)((int)puVar6 + iVar5 * 2) == 0x7b) goto LAB_004da9f8;
        puVar6 = &param_1;
        if (7 < extraout_ECX) {
          puVar6 = extraout_EDX;
        }
        if (*(short *)((int)puVar6 + iVar5 * 2) == 0x7d) goto LAB_004da9f8;
        puVar6 = &param_1;
        if (7 < extraout_ECX) {
          puVar6 = extraout_EDX;
        }
        if (*(short *)((int)puVar6 + iVar5 * 2) == 0x5b) goto LAB_004da9f8;
        puVar6 = &param_1;
        if (7 < extraout_ECX) {
          puVar6 = extraout_EDX;
        }
        if (*(short *)((int)puVar6 + iVar5 * 2) == 0x5d) goto LAB_004da9f8;
        puVar6 = &param_1;
        if (7 < extraout_ECX) {
          puVar6 = extraout_EDX;
        }
        if (*(short *)((int)puVar6 + iVar5 * 2) == 0x7c) goto LAB_004da9f8;
      }
      local_34 = iVar5 + 1;
    } while (iVar5 + 1 <= (int)local_54);
  }
  cube_QuestTextNode_destroyTree(*(undefined4 *)(local_58 + 4));
LAB_004db094:
  piVar7 = (int *)*piVar4;
  *piVar4 = (int)piVar4;
  piVar4[1] = (int)piVar4;
  if (piVar7 == piVar4) {
                    /* WARNING: Subroutine does not return */
    operator_delete(piVar4);
  }
                    /* WARNING: Subroutine does not return */
  operator_delete(piVar7);
}




/* cube::QuestText::ctor_3 @ 004e0250 */

int cube::QuestText::ctor_3(int src)

{
  int srcSaved;
  int node;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_006e9489;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  node = rbtree_alloc_node();
  srcSaved = src;
  *(undefined2 *)(node + 0xc) = 0;
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  if (node != -0x10) {
    u16string_moveConstruct(src);
    *(undefined ***)(node + 0x28) = vftable;
    *(undefined4 *)(node + 0x2c) = *(undefined4 *)(srcSaved + 0x1c);
    local_8 = CONCAT31(local_8._1_3_,2);
    QuestText_member_ctor(srcSaved + 0x20,(int)&src + 3);
  }
  ExceptionList = local_10;
  return node;
}




/* [AUDIT] proposed: QuestText_insertHint_str  (confidence: high)
 * purpose: QuestText std::map insert-with-hint for string key; compares and rebalances via QuestText_insertRebalance
 * vars: param_3 key; +8 node str
 */
/* Global::QuestText_insertHint_str @ 004e0fe0 */

undefined4 * QuestText_insertHint_str(undefined4 *param_1,int *hint,undefined4 *key,undefined4 value)

{
  char cVar1;
  int cmp;
  int *root;
  undefined4 *keyPtr;
  int *in_ECX;
  undefined4 insertLeft;
  uint uStack_2c;
  undefined1 local_1c [4];
  int *local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_006e9570;
  local_10 = ExceptionList;
  uStack_2c = DAT_0076aa78 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_2c;
  ExceptionList = &local_10;
  local_8 = 0;
  if (in_ECX[1] == 0) {
    hint = (int *)*in_ECX;
    local_14 = (undefined1 *)&uStack_2c;
  }
  else {
    root = (int *)*in_ECX;
    if (hint != (int *)*root) {
      if (hint == root) {
        keyPtr = key;
        if (7 < (uint)key[5]) {
          keyPtr = (undefined4 *)*key;
        }
        local_14 = (undefined1 *)&uStack_2c;
        cmp = u16string_compare(0,*(undefined4 *)(root[2] + 0x20),keyPtr,key[4]);
        if (-1 < cmp) goto LAB_004e1181;
        hint = *(int **)(*in_ECX + 8);
        insertLeft = 0;
        goto LAB_004e1029;
      }
      root = hint + 4;
      if (7 < (uint)hint[9]) {
        root = (int *)*root;
      }
      local_18 = in_ECX;
      cmp = u16string_compare(0,key[4],root,hint[8]);
      if (cmp < 0) {
        rbtree_iteratorIncrement();
        cVar1 = less_stringKey_map(hint + 4,key);
        if (cVar1 == '\0') goto LAB_004e1126;
        if (*(char *)(hint[2] + 0xd) == '\0') {
          insertLeft = 1;
          goto LAB_004e1029;
        }
      }
      else {
LAB_004e1126:
        cVar1 = less_stringKey_map(hint + 4,key);
        if ((cVar1 == '\0') ||
           ((rbtree_iterator_increment(), hint != (int *)*local_18 &&
            (cVar1 = less_stringKey_map(key,hint + 4), cVar1 == '\0')))) {
LAB_004e1181:
          local_8 = 0xffffffff;
          keyPtr = (undefined4 *)QuestText_insertUnique_str(local_1c,0,key,value);
          *param_1 = *keyPtr;
          ExceptionList = local_10;
          return param_1;
        }
        if (*(char *)(hint[2] + 0xd) == '\0') {
          insertLeft = 1;
          goto LAB_004e1029;
        }
      }
      insertLeft = 0;
      goto LAB_004e1029;
    }
    root = hint + 4;
    if (7 < (uint)hint[9]) {
      root = (int *)*root;
    }
    local_14 = (undefined1 *)&uStack_2c;
    cmp = u16string_compare(0,key[4],root,hint[8]);
    if (-1 < cmp) goto LAB_004e1181;
  }
  insertLeft = 1;
LAB_004e1029:
  QuestText_insertRebalance(param_1,insertLeft,hint,key,value);
  ExceptionList = local_10;
  return param_1;
}




/* [AUDIT] proposed: QuestText_insertUnique_str  (confidence: high)
 * purpose: QuestText std::map insert-unique for string key; finds slot, checks duplicate, rebalances via QuestText_insertRebalance
 * vars: key key; +8 str
 */
/* Global::QuestText_insertUnique_str @ 004e1480 */

void QuestText_insertUnique_str(undefined4 *param_1,undefined4 *insertLeft,undefined4 *key,undefined4 value)

{
  undefined4 *root;
  int cmp;
  int *piVar3;
  undefined4 *cur;
  undefined4 *puVar5;
  undefined4 *puVar6;
  int *in_ECX;
  bool less;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puVar5 = key;
  puStack_c = &LAB_006e95d0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  less = true;
  local_8 = 0;
  root = (undefined4 *)*in_ECX;
  cur = (undefined4 *)((undefined4 *)*in_ECX)[1];
  while (*(char *)((int)cur + 0xd) == '\0') {
    if ((char)insertLeft == '\0') {
      piVar3 = cur + 4;
      if (7 < (uint)cur[9]) {
        piVar3 = (int *)*piVar3;
      }
      cmp = u16string_compare(0,puVar5[4],piVar3,cur[8]);
      less = cmp < 0;
    }
    else {
      root = puVar5;
      if (7 < (uint)puVar5[5]) {
        root = (undefined4 *)*puVar5;
      }
      cmp = u16string_compare(0,cur[8],root,puVar5[4]);
      less = -1 < cmp;
    }
    root = cur;
    if (less == false) {
      cur = (undefined4 *)cur[2];
    }
    else {
      cur = (undefined4 *)*cur;
    }
  }
  insertLeft = root;
  if (less != false) {
    if (root == *(undefined4 **)*in_ECX) {
      cur = &insertLeft;
      less = true;
      goto LAB_004e1541;
    }
    rbtree_iteratorIncrement();
  }
  cur = insertLeft;
  puVar6 = puVar5;
  if (7 < (uint)puVar5[5]) {
    puVar6 = (undefined4 *)*puVar5;
  }
  cmp = u16string_compare(0,insertLeft[8],puVar6,puVar5[4]);
  if (-1 < cmp) {
    QuestText_delete_node(value);
    *param_1 = cur;
    *(undefined1 *)(param_1 + 1) = 0;
    ExceptionList = local_10;
    return;
  }
  cur = &key;
LAB_004e1541:
  puVar5 = (undefined4 *)QuestText_insertRebalance(cur,less,root,puVar5,value);
  *param_1 = *puVar5;
  *(undefined1 *)(param_1 + 1) = 1;
  ExceptionList = local_10;
  return;
}




/* [AUDIT] proposed: QuestText::member_ctor  (confidence: med)
 * purpose: Constructs a QuestText container member: allocs sentinel via rbtree_allocHeaderNode_28, then QuestText_copyTree init
 * vars: in_ECX=this; QuestText string node
 */
/* Global::QuestText_member_ctor @ 004e1830 */

void QuestText_member_ctor(undefined4 srcRoot)

{
  undefined4 list;
  undefined4 *self;
  uint flag;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_006e9668;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *self = 0;
  self[1] = 0;
  list = rbtree_allocHeaderNode_28();
  *self = list;
  flag = flag & 0xffffff00;
  local_8 = 1;
  QuestText_copyTree(srcRoot,flag);
  ExceptionList = local_10;
  return;
}




/* cube::QuestText::ctor_0 @ 004e3320 */

void cube::QuestText::ctor_0(int key)

{
  uint uVar1;
  int existing;
  int *keyPtr;
  int cmp;
  int *in_ECX;
  undefined1 local_41;
  undefined1 local_40 [4];
  void *local_3c [4];
  undefined4 local_2c;
  uint local_28;
  undefined **vftablePtr;
  undefined4 local_20;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_006e9a20;
  local_10 = ExceptionList;
  uVar1 = DAT_0076aa78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = uVar1;
  existing = map_lower_bound_string(key);
  if (existing != *in_ECX) {
    keyPtr = (int *)(existing + 0x10);
    if (7 < *(uint *)(existing + 0x24)) {
      keyPtr = (int *)*keyPtr;
    }
    cmp = u16string_compare(0,*(undefined4 *)(key + 0x10),keyPtr,*(undefined4 *)(existing + 0x20));
    if (-1 < cmp) goto LAB_004e3423;
  }
  cmp = ctor_1(uVar1);
  local_8 = 0;
  u16string_moveConstruct(key);
  vftablePtr = vftable;
  local_20 = *(undefined4 *)(cmp + 4);
  local_8._0_1_ = 1;
  QuestText_member_ctor(cmp + 8,&local_41);
  local_8._0_1_ = 2;
  cmp = ctor_3(local_3c);
  QuestText_insertHint_str(local_40,existing,cmp + 0x10,cmp);
  local_8 = CONCAT31(local_8._1_3_,3);
  ctor_2();
  if (7 < local_28) {
                    /* WARNING: Subroutine does not return */
    operator_delete(local_3c[0]);
  }
  local_28 = 7;
  local_2c = 0;
  local_3c[0] = (void *)((uint)local_3c[0] & 0xffff0000);
  local_8 = 0xffffffff;
  ctor_2();
LAB_004e3423:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}




/* [AUDIT] proposed: QuestText::delete_node  (confidence: med)
 * purpose: Destroys one QuestText tree node: runs dtor, frees string if cap>7, operator_delete node
 * vars: key=node; string ptr +0x10 cap +0x24
 */
/* Global::QuestText_delete_node @ 004e3550 */

void QuestText_delete_node(void *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_006e9a58;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  cube::QuestText::ctor_2(DAT_0076aa78 ^ (uint)&stack0xfffffffc);
  if (7 < *(uint *)((int)param_1 + 0x24)) {
                    /* WARNING: Subroutine does not return */
    operator_delete(*(void **)((int)param_1 + 0x10));
  }
  *(undefined4 *)((int)param_1 + 0x24) = 7;
  *(undefined4 *)((int)param_1 + 0x20) = 0;
  *(undefined2 *)((int)param_1 + 0x10) = 0;
                    /* WARNING: Subroutine does not return */
  operator_delete(param_1);
}




