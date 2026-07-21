// InventoryWidget (ui) — cube. 6 functions. Bodies = Ghidra pseudo-C.
#include "InventoryWidget.h"

/* [AUDIT] proposed: InventoryWidget_dispatchEvent  (confidence: high)
 * purpose: Recursively walks child widgets, matches focus (u16string_compare) and fires a MemberFunctionConnection callback
 * vars: 0x40=focus; 0x2c=children list
 */
/* Global::InventoryWidget_dispatchEvent @ 004c1a10 */

void InventoryWidget_dispatchEvent(undefined4 *pName,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  undefined4 *pSlot;
  int cmp;
  int pThis;
  int *pChild;
  
  if (*(int *)(pThis + 0x40) != 0) {
    pSlot = pName;
    if (7 < (uint)pName[5]) {
      pSlot = (undefined4 *)*pName;
    }
    cmp = u16string_compare(0,*(undefined4 *)(*(int *)(pThis + 0x40) + 0x1c),pSlot,pName[4]);
    if (cmp == 0) {
      plasma::Widget::MemberFunctionConnection<cube::InventoryWidget>::ctor_0
                (param_2,param_3,param_4,param_5,param_6,1);
    }
  }
  pChild = (int *)**(int **)(pThis + 0x2c);
  if (pChild != *(int **)(pThis + 0x2c)) {
    do {
      InventoryWidget_dispatchEvent(pName,param_2,param_3,param_4,param_5,param_6);
      pChild = (int *)*pChild;
    } while (pChild != (int *)*(int *)(pThis + 0x2c));
  }
  return;
}




/* plasma::Widget::MemberFunctionConnection<cube::InventoryWidget>::ctor_0 @ 004c1a90 */

void plasma::Widget::MemberFunctionConnection<cube::InventoryWidget>::ctor_0
               (undefined4 pName,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5,undefined4 param_6)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 *pSlot;
  undefined4 *pConn;
  int *pChild;
  int *pList;
  undefined4 local_18;
  void *savedExcList;
  undefined1 *ehHandler;
  undefined4 ehState;
  
  ehState = 0xffffffff;
  ehHandler = &LAB_006e1e48;
  savedExcList = ExceptionList;
  ExceptionList = &savedExcList;
  pSlot = (undefined4 *)rbtree_findOrInsert_intKey(&pName);
  if ((void *)*pSlot != (void *)0x0) {
                    /* WARNING: Subroutine does not return */
    operator_delete((void *)*pSlot);
  }
  pConn = operator_new(0x18);
  uVar2 = param_5;
  uVar1 = param_2;
  if (pConn == (undefined4 *)0x0) {
    pConn = (undefined4 *)0x0;
  }
  else {
    *(char *)(pConn + 1) = (char)param_6;
    *pConn = vftable;
    pConn[2] = param_2;
    pConn[4] = param_3;
    pConn[5] = param_4;
  }
  *pSlot = pConn;
  if ((char)param_5 != '\0') {
    tree_clear(&pList);
    ehState = 0;
    pChild = (int *)*pList;
    if (pChild != pList) {
      do {
        ctor_0(pName,uVar1,param_3,param_4,uVar2,param_6);
        pChild = (int *)*pChild;
      } while (pChild != pList);
    }
    pChild = (int *)*pList;
    *pList = (int)pList;
    pList[1] = (int)pList;
    local_18 = 0;
    if (pChild != pList) {
                    /* WARNING: Subroutine does not return */
      operator_delete(pChild);
    }
                    /* WARNING: Subroutine does not return */
    operator_delete(pList);
  }
  ExceptionList = savedExcList;
  return;
}




/* cube::InventoryWidget::ctor_0 @ 004c1bb0 */

void cube::InventoryWidget::ctor_0
               (int pGame,undefined4 param_2,undefined4 pParent,undefined4 param_4,
               undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  uint stackCookie;
  undefined4 uVar2;
  int pButton;
  undefined4 *pThis;
  void *local_44 [5];
  uint local_30;
  void *strBuf [4];
  undefined4 local_1c;
  uint local_18;
  uint local_14;
  void *savedExcList;
  undefined1 *ehHandler;
  undefined4 ehState;
  
  ehState = 0xffffffff;
  ehHandler = &LAB_006e7fb4;
  savedExcList = ExceptionList;
  stackCookie = DAT_0076aa78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &savedExcList;
  local_18 = 7;
  local_1c = 0;
  strBuf[0] = (void *)((uint)strBuf[0] & 0xffff0000);
  local_14 = stackCookie;
  u16string_assignPtrLen(&PTR_006fccac,0);
  ehState = 0;
  plasma::NamedObject::ctor_4(*(undefined4 *)(pGame + 0x800710),pParent,strBuf);
  ehState._0_1_ = 2;
  if (7 < local_18) {
                    /* WARNING: Subroutine does not return */
    operator_delete(strBuf[0]);
  }
  pThis[0x58] = 0;
  strBuf[0] = (void *)((uint)strBuf[0] & 0xffff0000);
  pThis[0x5a] = param_4;
  pThis[0x5b] = param_8;
  pThis[0x5c] = param_5;
  pThis[0x5d] = param_6;
  *pThis = vftable;
  pThis[9] = vftable;
  pThis[0x59] = pGame;
  pThis[0x5e] = param_7;
  local_18 = 7;
  local_1c = 0;
  pThis[0x5f] = 0;
  pThis[0x60] = 0;
  uVar2 = list_buyNode_0c(0,0);
  pThis[0x5f] = uVar2;
  pThis[0x61] = 0xffffffff;
  pThis[0x62] = 0xffffffff;
  pThis[99] = 0;
  pThis[100] = 0;
  pThis[0x65] = param_2;
  pThis[0x66] = 0;
  pThis[0x67] = 0;
  pThis[0x68] = 0;
  ehState._0_1_ = 4;
  pThis[0x69] = 1;
  pThis[0x6a] = 0x28;
  pThis[0x6b] = 0x28;
  pThis[0x6c] = 0xffffffff;
  pThis[0x6d] = 0;
  if (pThis[0x5b] != 0) {
    pButton = Node_clone_subtree_v2(pParent);
    pThis[0x5b] = pButton;
    uVar2 = (**(code **)(**(int **)(pButton + 0x38) + 8))(stackCookie);
    Node_set_style_slot(uVar2);
    uVar2 = (**(code **)(**(int **)(pThis[0x5b] + 0x3c) + 8))();
    Node_set_font_slot(uVar2);
    *(undefined4 *)
     (*(int *)(*(int *)(pThis[0x5b] + 0x3c) + 0x94) +
     *(int *)(*(int *)(pThis[0x5b] + 0x3c) + 0x68) * 4) = 0;
  }
  if (pThis[0x5c] != 0) {
    pButton = Node_clone_subtree_v2(pParent);
    pThis[0x5c] = pButton;
    uVar2 = (**(code **)(**(int **)(pButton + 0x38) + 8))();
    Node_set_style_slot(uVar2);
    uVar2 = (**(code **)(**(int **)(pThis[0x5c] + 0x3c) + 8))();
    Node_set_font_slot(uVar2);
    u16string_assignCStr(L"upbutton");
    ehState._0_1_ = 5;
    InventoryWidget_dispatchEvent(strBuf,2,pThis,GameController_decrement_tab_value,0,1);
    ehState._0_1_ = 4;
    if (7 < local_18) {
                    /* WARNING: Subroutine does not return */
      operator_delete(strBuf[0]);
    }
  }
  if (pThis[0x5d] != 0) {
    pButton = Node_clone_subtree_v2(pParent);
    pThis[0x5d] = pButton;
    uVar2 = (**(code **)(**(int **)(pButton + 0x38) + 8))();
    Node_set_style_slot(uVar2);
    uVar2 = (**(code **)(**(int **)(pThis[0x5d] + 0x3c) + 8))();
    Node_set_font_slot(uVar2);
    u16string_assignCStr(L"downbutton");
    ehState._0_1_ = 6;
    InventoryWidget_dispatchEvent(strBuf,2,pThis,GameController_increment_tab_value,0,1);
    ehState._0_1_ = 4;
    if (7 < local_18) {
                    /* WARNING: Subroutine does not return */
      operator_delete(strBuf[0]);
    }
  }
  if (pThis[0x5e] != 0) {
    pButton = Node_clone_subtree_v2(pParent);
    pThis[0x5e] = pButton;
    uVar2 = (**(code **)(**(int **)(pButton + 0x38) + 8))();
    Node_set_style_slot(uVar2);
    uVar2 = (**(code **)(**(int **)(pThis[0x5e] + 0x3c) + 8))();
    Node_set_font_slot(uVar2);
    u16string_assignCStr(L"scrollbutton");
    ehState._0_1_ = 7;
    InventoryWidget_dispatchEvent(local_44,0xc,pThis,GameController_set_slider_from_mouse,0,1);
    ehState._0_1_ = 4;
    if (7 < local_30) {
                    /* WARNING: Subroutine does not return */
      operator_delete(local_44[0]);
    }
  }
  if (pThis[0x5a] != 0) {
    Widget_measureGuarded();
    uVar2 = float_to_uint64_round_guarded();
    pThis[0x6a] = uVar2;
    Widget_measure();
    uVar2 = float_to_uint64_round_guarded();
    pThis[0x6b] = uVar2;
  }
  ExceptionList = savedExcList;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}




/* [AUDIT] proposed: InventoryWidget_dtor  (confidence: high)
 * purpose: Destructor: frees buffer at +0x198 and intrusive list at +0x17c
 * vars: offsets 0x198,0x17c
 */
/* Global::InventoryWidget_dtor @ 004c1f80 */

void InventoryWidget_dtor(void)

{
  undefined4 *pList;
  void *pFirst;
  int pThis;
  
  if (*(void **)(pThis + 0x198) != (void *)0x0) {
                    /* WARNING: Subroutine does not return */
    operator_delete(*(void **)(pThis + 0x198));
  }
  pList = *(undefined4 **)(pThis + 0x17c);
  pFirst = (void *)*pList;
  *pList = pList;
  *(int *)(*(int *)(pThis + 0x17c) + 4) = *(int *)(pThis + 0x17c);
  *(undefined4 *)(pThis + 0x180) = 0;
  if (pFirst != *(void **)(pThis + 0x17c)) {
                    /* WARNING: Subroutine does not return */
    operator_delete(pFirst);
  }
                    /* WARNING: Subroutine does not return */
  operator_delete(*(void **)(pThis + 0x17c));
}




/* cube::InventoryWidget::vfunc_0 @ 004c2010 */

void cube::InventoryWidget::vfunc_0(byte flags)

{
  void *pThis;
  
  InventoryWidget_dtor();
  if ((flags & 1) != 0) {
                    /* WARNING: Subroutine does not return */
    operator_delete(pThis);
  }
  return;
}




/* cube::InventoryWidget::vfunc_10 @ 004c5d50 */

void cube::InventoryWidget::vfunc_10(void)

{
  int *piVar1;
  undefined4 *puVar2;
  int cols;
  int rows;
  undefined4 *pList;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  int pThis;
  int *pNode;
  float10 fVar10;
  float fVar11;
  undefined4 uVar12;
  int count;
  int col;
  void *savedExcList;
  undefined1 *ehHandler;
  undefined4 ehState;
  
  ehState = 0xffffffff;
  ehHandler = &LAB_006e2bd8;
  savedExcList = ExceptionList;
  if (*(int *)(pThis + 0x168) == 0) {
    return;
  }
  ExceptionList = &savedExcList;
  InventoryWidget_updateScroll(DAT_0076aa78 ^ (uint)&stack0xfffffffc);
  fVar10 = (float10)Widget_measureGuarded();
  cols = (int)(((float)fVar10 - 10.0) / (float)(*(int *)(pThis + 0x1a8) + 5));
  fVar10 = (float10)Widget_measure();
  rows = (int)(((float)fVar10 - 40.0) / (float)(*(int *)(pThis + 0x1ac) + 5));
  count = 0;
  pList = (undefined4 *)list_buyNode_0c(0,0);
  ehState = 0;
  piVar1 = *(int **)(*(int *)(*(int *)(pThis + 0x148) + 0x28) + 0x2c);
  pNode = (int *)*piVar1;
  if (pNode != piVar1) {
    do {
      if (*(int *)(pNode[2] + 0x34) == *(int *)(*(int *)(pThis + 0x168) + 0x34)) {
        iVar6 = IntMap_SetScalar(pList,pList[1],pNode + 2);
        if (count == 0x15555554) {
                    /* WARNING: Subroutine does not return */
          std::_Xlength_error("list<T> too long");
        }
        pList[1] = iVar6;
        count = count + 1;
        **(int **)(iVar6 + 4) = iVar6;
      }
      pNode = (int *)*pNode;
    } while (pNode != (int *)*(int *)(*(int *)(*(int *)(pThis + 0x148) + 0x28) + 0x2c));
  }
  for (puVar2 = (undefined4 *)*pList; puVar2 != pList; puVar2 = (undefined4 *)*puVar2) {
    Node_destroy_and_unregister(puVar2[2]);
  }
  col = 0;
  if (0 < cols) {
    do {
      iVar6 = 0;
      if (0 < rows) {
        do {
          iVar7 = Node_clone_subtree_v2(0);
          uVar8 = (**(code **)(**(int **)(iVar7 + 0x38) + 8))();
          Node_set_style_slot(uVar8);
          Node_detach_or_remove_child(iVar7,*(undefined4 *)(pThis + 0x148));
          Widget_setScroll((float)((*(int *)(pThis + 0x1a8) + 5) * col + 10),
                       (float)((*(int *)(pThis + 0x1ac) + 5) * iVar6 + 0x28),1);
          iVar6 = iVar6 + 1;
        } while (iVar6 < rows);
      }
      col = col + 1;
    } while (col < cols);
  }
  if (*(int *)(pThis + 0x16c) != 0) {
    if (*(int *)(pThis + 0x1b4) < *(int *)(pThis + 0x19c) - *(int *)(pThis + 0x198) >> 2) {
      Widget_setScroll(0x41200000,0x41200000,1);
      rows = *(int *)(*(int *)(pThis + 0x16c) + 0x3c);
      *(undefined4 *)(*(int *)(rows + 0x94) + *(int *)(rows + 0x68) * 4) = 1;
      rows = *(int *)(pThis + 400) -
              *(int *)(*(int *)(pThis + 0x198) + *(int *)(pThis + 0x1b4) * 4) * cols;
      Widget_setScroll((float)((*(int *)(pThis + 0x1a8) + 5) * (rows % cols) + 10),
                   (float)((*(int *)(pThis + 0x1ac) + 5) * (rows / cols) + 0x28),1);
    }
    else {
      cols = *(int *)(*(int *)(pThis + 0x16c) + 0x3c);
      *(undefined4 *)(*(int *)(cols + 0x94) + *(int *)(cols + 0x68) * 4) = 0;
    }
  }
  if (*(int *)(pThis + 0x170) != 0) {
    uVar12 = 1;
    uVar8 = 0x41200000;
    fVar10 = (float10)Widget_measureGuarded(0x41200000,1);
    Widget_setScroll((float)fVar10 - 30.0,uVar8,uVar12);
  }
  if (*(int *)(pThis + 0x174) != 0) {
    uVar8 = 1;
    fVar10 = (float10)Widget_measure(1);
    fVar11 = (float)fVar10 - 30.0;
    fVar10 = (float10)Widget_measureGuarded(fVar11);
    Widget_setScroll((float)fVar10 - 30.0,fVar11,uVar8);
  }
  InventoryWidget_drawScrollbar();
  puVar2 = (undefined4 *)*pList;
  *pList = pList;
  pList[1] = pList;
  if (puVar2 != pList) {
                    /* WARNING: Subroutine does not return */
    operator_delete(puVar2);
  }
                    /* WARNING: Subroutine does not return */
  operator_delete(pList);
}




