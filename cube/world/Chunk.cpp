// Chunk (world) — cube. 3 functions. Bodies = Ghidra pseudo-C.
#include "Chunk.h"

/* cube::Chunk::ctor_0 @ 004596e0 */

void cube::Chunk::ctor_0(void)

{
  undefined4 allocated;
  undefined4 *pThis;
  void *savedExcList;
  undefined1 *ehHandler;
  undefined4 ehState;
  
  ehState = 0xffffffff;
  ehHandler = &LAB_006e3b14;
  savedExcList = ExceptionList;
  ExceptionList = &savedExcList;
  *pThis = vftable;
  pThis[2] = 0;
  pThis[3] = 0;
  allocated = list_buyNode_0c(0,0);
  pThis[2] = allocated;
  ehState = 0;
  pThis[4] = 0;
  pThis[5] = 0;
  allocated = list_buyNode_0c(0,0);
  pThis[4] = allocated;
  pThis[6] = 0xffffffff;
  pThis[7] = 0xffffffff;
  pThis[0x1c] = 0;
  *(undefined1 *)(pThis + 0x1d) = 0;
  pThis[0x8f] = 0;
  ehState._0_1_ = 1;
  pThis[0x90] = 0;
  pThis[0x91] = 0;
  allocated = list_allocNode(0,0);
  pThis[0x90] = allocated;
  ehState = CONCAT31(ehState._1_3_,2);
  pThis[0x92] = 0;
  pThis[0x93] = 0;
  allocated = list_allocNode(0,0);
  pThis[0x92] = allocated;
  InitializeCriticalSectionAndSpinCount((LPCRITICAL_SECTION)(pThis + 0x94),0x80000400);
  ExceptionList = savedExcList;
  return;
}




/* cube::Chunk::ctor_1 @ 00466bf0 */

void cube::Chunk::ctor_1(void)

{
  undefined4 *pList;
  void *pFirst;
  uint stackCookie;
  undefined4 *pThis;
  int *pNode;
  void *savedExcList;
  undefined1 *ehHandler;
  undefined4 ehState;
  
  ehHandler = &LAB_006e50b2;
  savedExcList = ExceptionList;
  stackCookie = DAT_0076aa78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &savedExcList;
  *pThis = vftable;
  ehState = 3;
  pNode = *(int **)pThis[2];
  if (pNode != (int *)pThis[2]) {
    do {
      if ((undefined4 *)pNode[2] != (undefined4 *)0x0) {
        (*(code *)**(undefined4 **)pNode[2])(1,stackCookie);
      }
      pNode = (int *)*pNode;
    } while (pNode != (int *)pThis[2]);
  }
  pNode = *(int **)pThis[4];
  if (pNode != (int *)pThis[4]) {
    do {
      if ((undefined4 *)pNode[2] != (undefined4 *)0x0) {
        (*(code *)**(undefined4 **)pNode[2])(1);
      }
      pNode = (int *)*pNode;
    } while (pNode != (int *)pThis[4]);
  }
  DeleteCriticalSection((LPCRITICAL_SECTION)(pThis + 0x94));
  pList = (undefined4 *)pThis[0x92];
  pFirst = (void *)*pList;
  *pList = pList;
  *(undefined4 *)(pThis[0x92] + 4) = pThis[0x92];
  pThis[0x93] = 0;
  if (pFirst == (void *)pThis[0x92]) {
                    /* WARNING: Subroutine does not return */
    operator_delete((void *)pThis[0x92]);
  }
                    /* WARNING: Subroutine does not return */
  operator_delete(pFirst);
}




/* cube::Chunk::vfunc_0 @ 0046d260 */

void * cube::Chunk::vfunc_0(uint flags)

{
  void *pThis;
  
  if ((flags & 2) != 0) {
    _eh_vector_destructor_iterator_(pThis,0x268,*(int *)((int)pThis + -4),ctor_1);
    if ((flags & 1) != 0) {
      operator_delete__((void *)((int)pThis + -4));
    }
    return (void *)((int)pThis + -4);
  }
  ctor_1();
  if ((flags & 1) != 0) {
                    /* WARNING: Subroutine does not return */
    operator_delete(pThis);
  }
  return pThis;
}




