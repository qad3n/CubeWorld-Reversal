// WorldInfo (world) — cube. 21 functions. Bodies = Ghidra pseudo-C.
#include "WorldInfo.h"

/* [AUDIT] proposed: db::storeBlobVec  (confidence: med)
 * purpose: Computes [begin,end) range from param_2 vector and stores as blob via 004499f0
 * vars: param_2=byte vector
 */
/* Global::db_storeBlobVec @ 004499c0 */

void db_storeBlobVec(undefined4 key,int *dataVec)

{
  int dataSize;
  int dataBegin;
  
  dataBegin = *dataVec;
  dataSize = dataVec[1] - dataBegin;
  if (dataBegin == dataVec[1]) {
    dataBegin = 0;
  }
  db_storeBlob(key,dataBegin,dataSize);
  return;
}




/* [AUDIT] proposed: db::storeBlob  (confidence: high)
 * purpose: SQLite upsert blob: SELECT existence then UPDATE or INSERT (prepared stmts); logs 'DATABASE WRITE ERROR'
 * vars: stmts; key=key str
 */
/* Global::db_storeBlob @ 004499f0 */

undefined4 db_storeBlob(undefined4 *key,undefined4 data,undefined4 len)

{
  undefined4 lenSave;
  int rc;
  undefined4 uVar3;
  basic_ostream<char,std::char_traits<char>_> *this;
  int self;
  _func_basic_ostream<char,struct_std::char_traits<char>_>_ptr_basic_ostream<char,struct_std::char_traits<char>_>_ptr
  *p_Var4;
  int stmt;
  
  stmt = self;
  rc = sqlite3_prepare_v2_526480(*(undefined4 *)(self + 4),"SELECT 1 FROM blobs WHERE key = ?",0xffffffff,
                       &stmt,0);
  if (rc != 0) {
    return 0;
  }
  if (0xf < (uint)key[5]) {
    key = (undefined4 *)*key;
  }
  rc = sqlite3_bind_blob_526b60(stmt,1,key,0xffffffff,0);
  if (rc == 0) {
    rc = sqlite3_step(stmt);
    sqlite3_finalize(stmt);
    lenSave = len;
    if (rc == 100) {
      while (rc = sqlite3_prepare_v2_526480(*(undefined4 *)(self + 4),"UPDATE blobs SET value=? WHERE key=?"
                                  ,0xffffffff,&len,0), rc == 0) {
        sqlite3_bind_text(len,1,data,lenSave,0);
        uVar3 = string_data(0xffffffff,0);
        sqlite3_bind_blob_526b60(len,2,uVar3);
        sqlite3_step(len);
        rc = sqlite3_finalize(len);
        if (rc != 0x11) {
          return 1;
        }
      }
    }
    else {
      while (rc = sqlite3_prepare_v2_526480(*(undefined4 *)(self + 4),
                                  "INSERT INTO blobs(key, value) VALUES(?, ?)",0xffffffff,&len,0
                                 ), rc == 0) {
        uVar3 = string_data(0xffffffff,0);
        sqlite3_bind_blob_526b60(len,1,uVar3);
        sqlite3_bind_text(len,2,data,lenSave,0);
        sqlite3_step(len);
        rc = sqlite3_finalize(len);
        if (rc != 0x11) {
          return 1;
        }
      }
      p_Var4 = endl_exref;
      this = (basic_ostream<char,std::char_traits<char>_> *)
             ostream_writePadded(cout_exref,"DATABASE WRITE ERROR");
      std::basic_ostream<char,std::char_traits<char>_>::operator<<(this,p_Var4);
    }
    return 0;
  }
  return 0;
}




/* [AUDIT] proposed: WorldInfo_mapInsertUnique  (confidence: med)
 * purpose: WorldInfo: find (0044b880) then insert region/world entry keyed by int+string into map (00449fe0)
 * vars: SEH; key compare 0040c520
 */
/* Global::WorldInfo_mapInsertUnique @ 0044b460 */

void WorldInfo_mapInsertUnique(int *entry)

{
  int node;
  int *keyPtr;
  int cmp;
  int *self;
  undefined1 local_68 [4];
  undefined1 local_64 [4];
  void *local_60;
  uint local_4c;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  uint cookie;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_006e2d58;
  local_10 = ExceptionList;
  cookie = DAT_0076aa78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  node = WorldInfo_mapLowerBound(entry);
  if (node != *self) {
    if (*(int *)(node + 0x10) <= *entry) {
      if (*(int *)(node + 0x10) < *entry) goto LAB_0044b534;
      keyPtr = (int *)(node + 0x14);
      if (0xf < *(uint *)(node + 0x28)) {
        keyPtr = (int *)*keyPtr;
      }
      cmp = string_compare(0,entry[5],keyPtr,*(undefined4 *)(node + 0x24));
      if (-1 < cmp) goto LAB_0044b534;
    }
  }
  WorldInfo_move_string(entry,0);
  local_44 = local_2c;
  local_40 = local_28;
  local_3c = local_24;
  local_38 = local_20;
  local_34 = local_1c;
  local_30 = local_18;
  local_8 = 0;
  cmp = WorldInfo_allocMapNodeCopyKey(local_64);
  map_insertUnique_findPos(local_68,node,cmp + 0x10,cmp);
  if (0xf < local_4c) {
    operator_delete(local_60);
  }
LAB_0044b534:
  ExceptionList = local_10;
  __security_check_cookie(cookie ^ (uint)&stack0xfffffffc);
  return;
}




/* [AUDIT] proposed: WorldInfo_mapLowerBound  (confidence: med)
 * purpose: RB-tree lower_bound by int+string key (memcmp 0040c590) returning candidate node
 * vars: key int at *, str +1/+5
 */
/* Global::WorldInfo_mapLowerBound @ 0044b880 */

undefined4 * WorldInfo_mapLowerBound(int *key)

{
  int keyVal;
  uint lenA;
  uint lenB;
  uint cmp;
  int *self;
  int *keyPtrA;
  undefined4 *result;
  int *keyPtrB;
  undefined4 *node;
  undefined4 *child;
  undefined4 *parent;
  
  result = (undefined4 *)*self;
  if (*(char *)((int)result[1] + 0xd) == '\0') {
    keyVal = *key;
    node = (undefined4 *)result[1];
    parent = result;
    do {
      if ((int)node[4] < keyVal) {
LAB_0044b902:
        child = (undefined4 *)node[2];
      }
      else {
        if ((int)node[4] <= keyVal) {
          keyPtrA = key + 1;
          keyPtrB = node + 5;
          lenA = key[5];
          if (0xf < (uint)key[6]) {
            keyPtrA = (int *)*keyPtrA;
          }
          lenB = node[9];
          if (0xf < (uint)node[10]) {
            keyPtrB = (int *)*keyPtrB;
          }
          cmp = lenA;
          if (lenB < lenA) {
            cmp = lenB;
          }
          cmp = memcmp_traits(keyPtrB,keyPtrA,cmp);
          result = parent;
          if (cmp == 0) {
            if (lenB < lenA) goto LAB_0044b902;
            cmp = (uint)(lenB != lenA);
          }
          if ((int)cmp < 0) goto LAB_0044b902;
        }
        child = (undefined4 *)*node;
        result = node;
        parent = node;
      }
      node = child;
    } while (*(char *)((int)child + 0xd) == '\0');
  }
  return result;
}




/* cube::WorldInfo::ctor_1 @ 00466a70 */

void cube::WorldInfo::ctor_1(void)

{
  undefined4 *pThis;
  
  *pThis = vftable;
  pThis[1] = 0;
  pThis[7] = 0xf;
  pThis[6] = 0;
  *(undefined1 *)(pThis + 2) = 0;
  pThis[9] = 0;
  return;
}




/* cube::WorldInfo::ctor_0 @ 0046a8a0 */

void cube::WorldInfo::ctor_0(void)

{
  int *piVar1;
  undefined4 **ppuVar2;
  undefined4 **ppuVar3;
  undefined4 **ppuVar4;
  uint cookieTmp;
  int iVar6;
  DWORD DVar7;
  uint uVar8;
  undefined4 *puVar9;
  int *piVar10;
  undefined4 uVar11;
  int *pWorldInfo;
  byte *pbVar12;
  char needUpdate;
  uint uVar14;
  uint uVar15;
  byte *pbVar16;
  int *piVar17;
  int *piVar18;
  uint uVar19;
  int iVar20;
  uint *puVar21;
  int worldPtr;
  bool bVar23;
  undefined8 uVar24;
  int local_f4;
  float local_f0;
  int local_ec;
  DWORD startTime;
  int bestDistSq;
  void *local_e0;
  undefined4 local_dc;
  undefined4 local_d8;
  int local_d4;
  undefined4 *local_d0;
  int maxY;
  int *local_c8;
  undefined4 local_c4;
  int refX;
  int *refY;
  int *local_b8;
  uint maxX;
  char foundFlag;
  uint minX;
  uint local_a8;
  int *pWorldInfoCopy;
  uint local_a0;
  char needUpdateSaved;
  undefined1 local_98 [4];
  void *local_94;
  uint local_80;
  undefined1 local_7c [4];
  void *local_78;
  uint local_64;
  void *local_60 [4];
  undefined4 local_50;
  uint local_4c;
  uint local_48;
  int *piStack_44;
  uint local_40;
  int *piStack_3c;
  undefined8 local_38;
  int local_30;
  int iStack_2c;
  undefined4 local_28;
  undefined4 uStack_24;
  undefined4 local_20;
  undefined8 local_1c;
  uint stackCookie;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_006e54e1;
  local_10 = ExceptionList;
  cookieTmp = DAT_0076aa78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  pWorldInfoCopy = pWorldInfo;
  stackCookie = cookieTmp;
  startTime = timeGetTime();
  if (*(char *)(*pWorldInfo + 0x8005b0) == '\0') {
    ExceptionList = local_10;
    __security_check_cookie(stackCookie ^ (uint)&stack0xfffffffc);
    return;
  }
  EnterCriticalSection((LPCRITICAL_SECTION)(*pWorldInfo + 0x8005d0));
  worldPtr = *pWorldInfo;
  if (*(int *)(worldPtr + 0x800a50) == *(int *)(worldPtr + 0x800448)) {
    uVar14 = *(uint *)(worldPtr + 0x388);
    piVar17 = (int *)(worldPtr + 0x378);
    piVar10 = (int *)(worldPtr + 0x800a54);
    if (0xf < *(uint *)(worldPtr + 0x38c)) {
      piVar17 = (int *)*piVar17;
    }
    uVar19 = *(uint *)(worldPtr + 0x800a64);
    if (0xf < *(uint *)(worldPtr + 0x800a68)) {
      piVar10 = (int *)*piVar10;
    }
    uVar8 = uVar14;
    if (uVar19 < uVar14) {
      uVar8 = uVar19;
    }
    iVar6 = memcmp_traits(piVar10,piVar17,uVar8,cookieTmp);
    bVar23 = false;
    if (iVar6 == 0) {
      if (uVar19 < uVar14) {
        cookieTmp = 0xffffffff;
      }
      else {
        cookieTmp = (uint)(uVar19 != uVar14);
      }
      bVar23 = cookieTmp == 0;
    }
    if (!bVar23) goto LAB_0046a96f;
    needUpdate = '\0';
  }
  else {
LAB_0046a96f:
    needUpdate = '\x01';
  }
  local_1c = *(undefined8 *)(worldPtr + 0x2ac);
  refX = *(int *)(worldPtr + 0x2b4);
  refY = *(int **)(worldPtr + 0x2b8);
  needUpdateSaved = needUpdate;
  std_list_copyConstruct_nodeSz_ccbf0(worldPtr + 0x2c4);
  piVar17 = pWorldInfoCopy;
  local_8 = 0;
  LeaveCriticalSection((LPCRITICAL_SECTION)(*pWorldInfoCopy + 0x8005d0));
  piVar10 = pWorldInfoCopy;
  if (needUpdate == '\0') {
    foundFlag = '\0';
    local_b8 = (int *)*local_c8;
    bestDistSq = 0x90000;
    if (local_b8 != local_c8) {
      do {
        local_30 = local_b8[2];
        iStack_2c = local_b8[3];
        minX = local_30 - 3;
        maxX = local_30 + 3;
        piVar18 = (int *)(iStack_2c + -3);
        maxY = iStack_2c + 3;
        if ((int)minX < 0) {
          minX = 0;
        }
        if (0xffff < (int)maxX) {
          maxX = 0xffff;
        }
        if ((int)piVar18 < 0) {
          piVar18 = (int *)0x0;
        }
        if (0xffff < maxY) {
          maxY = 0xffff;
        }
        if ((int)minX <= (int)maxX) {
          local_a8 = minX * 0x100 + 0x80;
          do {
            if ((int)piVar18 <= maxY) {
              local_a0 = (int)piVar18 * 0x100 + 0x80;
              piVar17 = piVar18;
              do {
                worldPtr = (refX - local_a8) * (refX - local_a8) +
                         ((int)refY - local_a0) * ((int)refY - local_a0);
                if (worldPtr < bestDistSq) {
                  if ((((-1 < (int)minX) && (-1 < (int)piVar17)) && ((int)local_a8 < 0x1000080))
                     && ((int)piVar17 < 0x10000)) {
                    iVar6 = (int)(((int)minX >> 0x1f & 0x3fU) + minX) >> 6;
                    iVar20 = (int)(((int)piVar17 >> 0x1f & 0x3fU) + (int)piVar17) >> 6;
                    if (((-1 < iVar6) && (-1 < iVar20)) &&
                       ((iVar6 < 0x400 &&
                        ((iVar20 < 0x400 &&
                         (iVar6 = *(int *)(*pWorldInfoCopy + 0x3a0 + (iVar6 * 0x400 + iVar20) * 4),
                         iVar6 != 0)))))) {
                      cookieTmp = minX & 0x8000003f;
                      if ((int)cookieTmp < 0) {
                        cookieTmp = (cookieTmp - 1 | 0xffffffc0) + 1;
                      }
                      uVar14 = (uint)piVar17 & 0x8000003f;
                      if ((int)uVar14 < 0) {
                        uVar14 = (uVar14 - 1 | 0xffffffc0) + 1;
                      }
                      if (*(int *)(iVar6 + 0x10018 + (cookieTmp * 0x40 + uVar14) * 4) != 0)
                      goto LAB_0046ac49;
                    }
                  }
                  foundFlag = '\x01';
                  bestDistSq = worldPtr;
                  local_48 = minX;
                  piStack_44 = piVar17;
                  local_40 = minX;
                  piStack_3c = piVar17;
                }
LAB_0046ac49:
                piVar17 = (int *)((int)piVar17 + 1);
                local_a0 = local_a0 + 0x100;
                local_38 = CONCAT44(refY,refX);
              } while ((int)piVar17 <= maxY);
            }
            minX = minX + 1;
            local_a8 = local_a8 + 0x100;
          } while ((int)minX <= (int)maxX);
        }
        piVar1 = piStack_44;
        cookieTmp = local_48;
        local_b8 = (int *)*local_b8;
      } while (local_b8 != local_c8);
      piVar17 = piVar10;
      refY = piVar18;
      if (foundFlag != '\0') {
        WorldInfo_generateBiomeContent(local_48,piStack_44);
        World_enterCriticalSection();
        worldPtr = hash_or_index_compute(cookieTmp,piVar1);
        if (worldPtr != 0) {
          *(undefined1 *)(worldPtr + 0x28) = 1;
        }
        leave_critical_section_b();
        EnterCriticalSection((LPCRITICAL_SECTION)(*piVar10 + 0x8005d0));
        LeaveCriticalSection((LPCRITICAL_SECTION)(*piVar10 + 0x8005d0));
      }
    }
  }
  else {
    EnterCriticalSection((LPCRITICAL_SECTION)(*piVar17 + 0x800600));
    worldPtr = *(int *)(*piVar17 + 0x2dc);
    iVar6 = (int)local_1c;
    if ((int)local_1c < (int)local_1c + worldPtr) {
      do {
        iVar20 = local_1c._4_4_;
        if (local_1c._4_4_ < local_1c._4_4_ + worldPtr) {
          do {
            if ((((-1 < iVar6) && (-1 < iVar20)) && (iVar6 < 0x80000)) && (iVar20 < 0x80000)) {
              WorldInfo_clearUnderLock();
            }
            iVar20 = iVar20 + 1;
          } while (iVar20 < local_1c._4_4_ + *(int *)(*pWorldInfoCopy + 0x2dc));
        }
        iVar6 = iVar6 + 1;
        worldPtr = *(int *)(*pWorldInfoCopy + 0x2dc);
        piVar17 = pWorldInfoCopy;
      } while (iVar6 < (int)local_1c + worldPtr);
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)(*piVar17 + 0x800600));
  }
  DVar7 = timeGetTime();
  if ((needUpdateSaved == '\0') && ((int)(DVar7 - startTime) < 0x3e9)) goto LAB_0046b6a3;
  local_a0 = 0;
  minX = 0xe8;
  piVar10 = local_c8;
  needUpdate = needUpdateSaved;
  startTime = DVar7;
  do {
    local_a8 = 0;
    cookieTmp = local_a0;
    uVar14 = minX;
    do {
      uVar19 = local_a8;
      if (((-1 < (int)cookieTmp) && (-1 < (int)local_a8)) &&
         (((int)uVar14 < 0x1000e8 &&
          (((int)local_a8 < 0x400 &&
           (worldPtr = *(int *)(*piVar17 + (uVar14 + local_a8) * 4), cookieTmp = local_a0,
           uVar14 = minX, worldPtr != 0)))))) {
        piVar18 = (int *)(worldPtr + 0x10018);
        maxX = 0x40;
        do {
          local_b8 = (int *)0x40;
          do {
            piVar17 = pWorldInfoCopy;
            worldPtr = *piVar18;
            if (worldPtr != 0) {
              if (needUpdate == '\0') {
                for (piVar1 = (int *)*piVar10; piVar1 != piVar10; piVar1 = (int *)*piVar1) {
                  iVar20 = *(int *)(worldPtr + 0x60) - piVar1[2];
                  iVar6 = *(int *)(worldPtr + 100) - piVar1[3];
                  needUpdate = needUpdateSaved;
                  if (iVar20 * iVar20 + iVar6 * iVar6 < 0x10) goto LAB_0046ae42;
                }
              }
              WorldGrid_destroyBlockObjectAt(*(undefined4 *)(worldPtr + 0x60),*(undefined4 *)(worldPtr + 100));
              piVar10 = local_c8;
              needUpdate = needUpdateSaved;
            }
LAB_0046ae42:
            uVar19 = local_a8;
            piVar18 = piVar18 + 1;
            local_b8 = (int *)((int)local_b8 + -1);
          } while (local_b8 != (int *)0x0);
          maxX = maxX - 1;
        } while (maxX != 0);
        if (needUpdate == '\0') {
          for (piVar18 = (int *)*piVar10; piVar18 != piVar10; piVar18 = (int *)*piVar18) {
            cookieTmp = local_a0 - ((int)((piVar18[2] >> 0x1f & 0x3fU) + piVar18[2]) >> 6);
            uVar14 = (int)cookieTmp >> 0x1f;
            if (((int)((cookieTmp ^ uVar14) - uVar14) < 3) &&
               (cookieTmp = local_a8 - ((int)((piVar18[3] >> 0x1f & 0x3fU) + piVar18[3]) >> 6),
               uVar14 = (int)cookieTmp >> 0x1f, (int)((cookieTmp ^ uVar14) - uVar14) < 3))
            goto LAB_0046aed2;
          }
        }
        WorldGrid_destroyCellObject(local_a0,local_a8);
        piVar10 = local_c8;
        if (needUpdateSaved == '\0') {
LAB_0046aed2:
          for (piVar18 = (int *)*piVar10; piVar18 != piVar10; piVar18 = (int *)*piVar18) {
            cookieTmp = local_a0 - ((int)((piVar18[2] >> 0x1f & 0x3fU) + piVar18[2]) >> 6);
            uVar14 = (int)cookieTmp >> 0x1f;
            if (((int)((cookieTmp ^ uVar14) - uVar14) < 5) &&
               (uVar8 = uVar19 - ((int)((piVar18[3] >> 0x1f & 0x3fU) + piVar18[3]) >> 6),
               uVar15 = (int)uVar8 >> 0x1f, cookieTmp = local_a0, uVar14 = minX, needUpdate = needUpdateSaved,
               (int)((uVar8 ^ uVar15) - uVar15) < 5)) goto LAB_0046af42;
          }
        }
        WorldGrid_freeCellPtr(local_a0,uVar19);
        cookieTmp = local_a0;
        uVar14 = minX;
        piVar10 = local_c8;
        needUpdate = needUpdateSaved;
      }
LAB_0046af42:
      local_a8 = uVar19 + 1;
    } while ((int)local_a8 < 0x400);
    minX = uVar14 + 0x400;
    local_a0 = cookieTmp + 1;
  } while ((int)minX < 0x1000e8);
  if (needUpdate == '\0') goto LAB_0046b6a3;
  enter_critical_section();
  World_enterCriticalSection();
  std::basic_stringbuf<char,std::char_traits<char>,std::allocator<char>_>::ctor_15
            (*(undefined4 *)(*piVar17 + 0x800a50),*piVar17 + 0x800a54);
  std::basic_stringbuf<char,std::char_traits<char>,std::allocator<char>_>::ctor_2();
  if (*(int *)(*piVar17 + 0x800a64) != 0) {
    *(undefined4 *)(*piVar17 + 0x800a10) = 0xffffffff;
    worldPtr = *piVar17;
    minX = 0;
    if (0 < (int)(*(int *)(worldPtr + 0x8009e0) - *(int *)(worldPtr + 0x8009dc) & 0xfffffffcU)) {
      maxX = *(uint *)(worldPtr + 0x800a64);
      local_b8 = *(int **)(worldPtr + 0x8009dc);
      do {
        pbVar16 = (byte *)(worldPtr + 0x800a54);
        refY = (int *)*local_b8;
        pbVar12 = (byte *)(refY + 2);
        if (0xf < *(uint *)(worldPtr + 0x800a68)) {
          pbVar16 = *(byte **)pbVar16;
        }
        cookieTmp = refY[6];
        if (0xf < (uint)refY[7]) {
          pbVar12 = *(byte **)pbVar12;
        }
        uVar14 = maxX;
        if (cookieTmp < maxX) {
          uVar14 = cookieTmp;
        }
        if (uVar14 == 0) {
LAB_0046b0a8:
          if (cookieTmp < maxX) {
            cookieTmp = 0xffffffff;
          }
          else {
            cookieTmp = (uint)(cookieTmp != *(uint *)(worldPtr + 0x800a64));
          }
          bVar23 = cookieTmp == 0;
        }
        else {
          while (uVar19 = uVar14 - 4, 3 < uVar14) {
            if (*(int *)pbVar12 != *(int *)pbVar16) goto LAB_0046b068;
            pbVar12 = pbVar12 + 4;
            pbVar16 = pbVar16 + 4;
            uVar14 = uVar19;
          }
          if (uVar19 == 0xfffffffc) {
LAB_0046b09c:
            uVar14 = 0;
          }
          else {
LAB_0046b068:
            bVar23 = *pbVar12 < *pbVar16;
            if ((*pbVar12 == *pbVar16) &&
               ((uVar19 == 0xfffffffd ||
                ((bVar23 = pbVar12[1] < pbVar16[1], pbVar12[1] == pbVar16[1] &&
                 ((uVar19 == 0xfffffffe ||
                  ((bVar23 = pbVar12[2] < pbVar16[2], pbVar12[2] == pbVar16[2] &&
                   ((uVar19 == 0xffffffff ||
                    (bVar23 = pbVar12[3] < pbVar16[3], pbVar12[3] == pbVar16[3]))))))))))))
            goto LAB_0046b09c;
            uVar14 = -(uint)bVar23 | 1;
          }
          bVar23 = false;
          if (uVar14 == 0) goto LAB_0046b0a8;
        }
        piVar17 = pWorldInfoCopy;
        if ((bVar23) && (refY[8] == *(int *)(worldPtr + 0x800a50))) {
          *(uint *)(worldPtr + 0x800a10) = minX;
          break;
        }
        minX = minX + 1;
        local_b8 = local_b8 + 1;
      } while ((int)minX < *(int *)(worldPtr + 0x8009e0) - *(int *)(worldPtr + 0x8009dc) >> 2);
    }
    worldPtr = *piVar17;
    if (*(int *)(worldPtr + 0x800a10) < 0) {
      local_e0 = (void *)0x0;
      local_dc = 0;
      local_d8 = 0;
      local_d4 = 0;
      iVar6 = *(int *)(worldPtr + 0x8009e0);
      worldPtr = *(int *)(worldPtr + 0x8009dc);
      local_8._0_1_ = 1;
      Vector_Resize(4);
      *(int *)(local_d4 + (int)local_e0) = (iVar6 - worldPtr >> 2) + 1;
      local_d4 = local_d4 + 4;
      local_4c = 0xf;
      local_50 = 0;
      local_60[0] = (void *)((uint)local_60[0] & 0xffffff00);
      string_assignPtrLen(&DAT_00700e68,3);
      piVar17 = pWorldInfoCopy;
      local_8._0_1_ = 2;
      db_storeBlobVec(local_60,&local_e0);
      local_8 = CONCAT31(local_8._1_3_,1);
      if (0xf < local_4c) {
        operator_delete(local_60[0]);
      }
      puVar9 = operator_new(0x28);
      if (puVar9 == (undefined4 *)0x0) {
        puVar9 = (undefined4 *)0x0;
      }
      else {
        *puVar9 = vftable;
        puVar9[1] = 0;
        puVar9[7] = 0xf;
        puVar9[6] = 0;
        *(undefined1 *)(puVar9 + 2) = 0;
        puVar9[9] = 0;
      }
      puVar9[8] = *(undefined4 *)(*piVar17 + 0x800a50);
      local_d0 = puVar9;
      if (puVar9 + 2 != (undefined4 *)(*piVar17 + 0x800a54)) {
        string_assignSubstr((undefined4 *)(*piVar17 + 0x800a54),0,0xffffffff);
      }
      worldPtr = *piVar17;
      puVar21 = (uint *)(worldPtr + 0x8009dc);
      ppuVar2 = *(undefined4 ***)(worldPtr + 0x8009e0);
      if (&local_d0 < ppuVar2) {
        ppuVar3 = (undefined4 **)*puVar21;
        if (&local_d0 < ppuVar3) goto LAB_0046b2eb;
        ppuVar4 = *(undefined4 ***)(worldPtr + 0x8009e4);
        if ((ppuVar2 == ppuVar4) && ((int)ppuVar4 - (int)ppuVar2 >> 2 == 0)) {
          iVar6 = (int)((int)ppuVar2 - *puVar21) >> 2;
          if (iVar6 == 0x3fffffff) goto LAB_0046b731;
          refY = (int *)(iVar6 + 1);
          cookieTmp = (int)((int)ppuVar4 - *puVar21) >> 2;
          if (0x3fffffff - (cookieTmp >> 1) < cookieTmp) {
            piVar17 = (int *)0x0;
          }
          else {
            piVar17 = (int *)(cookieTmp + (cookieTmp >> 1));
          }
          if (piVar17 < refY) {
            piVar17 = refY;
          }
          std_vector_grow_realloc_stride4(piVar17);
        }
        if (*(undefined4 **)(worldPtr + 0x8009e0) != (undefined4 *)0x0) {
          **(undefined4 **)(worldPtr + 0x8009e0) =
               *(undefined4 *)(*puVar21 + ((int)&local_d0 - (int)ppuVar3 >> 2) * 4);
        }
      }
      else {
LAB_0046b2eb:
        ppuVar3 = *(undefined4 ***)(worldPtr + 0x8009e4);
        if ((ppuVar2 == ppuVar3) && ((int)ppuVar3 - (int)ppuVar2 >> 2 == 0)) {
          iVar6 = (int)((int)ppuVar2 - *puVar21) >> 2;
          if (iVar6 == 0x3fffffff) {
LAB_0046b731:
            std::_Xlength_error("vector<T> too long");
          }
          refY = (int *)(iVar6 + 1);
          cookieTmp = (int)((int)ppuVar3 - *puVar21) >> 2;
          if (0x3fffffff - (cookieTmp >> 1) < cookieTmp) {
            piVar17 = (int *)0x0;
          }
          else {
            piVar17 = (int *)(cookieTmp + (cookieTmp >> 1));
          }
          if (piVar17 < refY) {
            piVar17 = refY;
          }
          std_vector_grow_realloc_stride4(piVar17);
        }
        if (*(undefined4 **)(worldPtr + 0x8009e0) != (undefined4 *)0x0) {
          **(undefined4 **)(worldPtr + 0x8009e0) = puVar9;
        }
      }
      piVar17 = pWorldInfoCopy;
      *(int *)(worldPtr + 0x8009e0) = *(int *)(worldPtr + 0x8009e0) + 4;
      worldPtr = *pWorldInfoCopy;
      *(int *)(worldPtr + 0x800a10) =
           (*(int *)(worldPtr + 0x8009e0) - *(int *)(worldPtr + 0x8009dc) >> 2) + -1;
      cube::GameController::saveStructureBlob
                (*(undefined4 *)(*pWorldInfoCopy + 0x800a10),puVar9,0);
      GameController_buildWorldList();
      local_8 = local_8 & 0xffffff00;
      if (local_e0 != (void *)0x0) {
        operator_delete(local_e0);
      }
    }
  }
  piVar10 = (int *)string_assignSwapTmp(local_98,*piVar17 + 0x800a50,*piVar17 + 0x800a54);
  local_8._0_1_ = 3;
  worldPtr = *(int *)(*(int *)(*piVar17 + 0x8006d0) + 0x1d28);
  iVar6 = *(int *)(worldPtr + 0x1c);
  maxY = iVar6;
  refY = piVar10;
  iVar20 = WorldInfo_mapLowerBound(piVar10);
  piVar17 = pWorldInfoCopy;
  worldPtr = *(int *)(worldPtr + 0x1c);
  if (iVar20 == worldPtr) {
LAB_0046b520:
    local_f4 = worldPtr;
    piVar10 = &local_f4;
  }
  else {
    if (*piVar10 < *(int *)(iVar20 + 0x10)) goto LAB_0046b520;
    if (*piVar10 <= *(int *)(iVar20 + 0x10)) {
      local_a0 = *(uint *)(iVar20 + 0x24);
      pbVar16 = (byte *)(iVar20 + 0x14);
      pbVar12 = (byte *)(refY + 1);
      if (0xf < *(uint *)(iVar20 + 0x28)) {
        pbVar16 = *(byte **)pbVar16;
      }
      minX = refY[5];
      if (0xf < (uint)refY[6]) {
        pbVar12 = *(byte **)pbVar12;
      }
      cookieTmp = local_a0;
      if (minX < local_a0) {
        cookieTmp = minX;
      }
      if (cookieTmp == 0) {
LAB_0046b4ed:
        if (minX < local_a0) {
          cookieTmp = 0xffffffff;
        }
        else {
          cookieTmp = (uint)(minX != local_a0);
        }
      }
      else {
        while (local_a8 = cookieTmp - 4, 3 < cookieTmp) {
          if (*(int *)pbVar12 != *(int *)pbVar16) goto LAB_0046b4a7;
          pbVar12 = pbVar12 + 4;
          pbVar16 = pbVar16 + 4;
          cookieTmp = local_a8;
        }
        if (local_a8 == 0xfffffffc) {
LAB_0046b4e7:
          cookieTmp = 0;
        }
        else {
LAB_0046b4a7:
          bVar23 = *pbVar12 < *pbVar16;
          if ((*pbVar12 == *pbVar16) &&
             ((local_a8 == 0xfffffffd ||
              ((bVar23 = pbVar12[1] < pbVar16[1], pbVar12[1] == pbVar16[1] &&
               ((local_a8 == 0xfffffffe ||
                ((bVar23 = pbVar12[2] < pbVar16[2], pbVar12[2] == pbVar16[2] &&
                 ((local_a8 == 0xffffffff ||
                  (bVar23 = pbVar12[3] < pbVar16[3], pbVar12[3] == pbVar16[3]))))))))))))
          goto LAB_0046b4e7;
          cookieTmp = -(uint)bVar23 | 1;
        }
        if (cookieTmp == 0) goto LAB_0046b4ed;
      }
      iVar6 = maxY;
      if ((int)cookieTmp < 0) goto LAB_0046b520;
    }
    local_ec = iVar20;
    piVar10 = &local_ec;
  }
  local_8 = (uint)local_8._1_3_ << 8;
  if (0xf < local_80) {
    operator_delete(local_94);
  }
  if (*piVar10 == iVar6) {
    iVar20 = 0;
    worldPtr = *pWorldInfoCopy;
    iVar6 = *(int *)(worldPtr + 0x8006d0);
    do {
      local_f0 = *(float *)(worldPtr + 0x8003d4 + iVar20 * 4) * 65536.0;
      uVar24 = float_to_uint64_round();
      *(int *)(iVar6 + 0x10 + iVar20 * 8) = (int)uVar24;
      *(int *)(iVar6 + 0x14 + iVar20 * 8) = (int)((ulonglong)uVar24 >> 0x20);
      iVar20 = iVar20 + 1;
    } while (iVar20 < 3);
  }
  else {
    uVar11 = string_assignSwapTmp(local_7c,*pWorldInfoCopy + 0x800a50,*pWorldInfoCopy + 0x800a54);
    local_8._0_1_ = 4;
    puVar9 = (undefined4 *)WorldInfo_mapInsertUnique(uVar11);
    worldPtr = *(int *)(*piVar17 + 0x8006d0);
    local_8 = (uint)local_8._1_3_ << 8;
    *(undefined4 *)(worldPtr + 0x10) = *puVar9;
    *(undefined4 *)(worldPtr + 0x14) = puVar9[1];
    *(undefined4 *)(worldPtr + 0x18) = puVar9[2];
    *(undefined4 *)(worldPtr + 0x1c) = puVar9[3];
    *(undefined4 *)(worldPtr + 0x20) = puVar9[4];
    *(undefined4 *)(worldPtr + 0x24) = puVar9[5];
    if (0xf < local_64) {
      operator_delete(local_78);
    }
  }
  local_28 = 0;
  uStack_24 = 0;
  worldPtr = *(int *)(*pWorldInfoCopy + 0x8006d0);
  *(undefined4 *)(worldPtr + 0x1350) = *(undefined4 *)(worldPtr + 0x10);
  *(undefined4 *)(worldPtr + 0x1354) = *(undefined4 *)(worldPtr + 0x14);
  *(undefined4 *)(worldPtr + 0x1358) = *(undefined4 *)(worldPtr + 0x18);
  *(undefined4 *)(worldPtr + 0x135c) = *(undefined4 *)(worldPtr + 0x1c);
  *(undefined4 *)(worldPtr + 0x1360) = *(undefined4 *)(worldPtr + 0x20);
  *(undefined4 *)(worldPtr + 0x1364) = *(undefined4 *)(worldPtr + 0x24);
  local_20 = 0;
  worldPtr = *(int *)(*pWorldInfoCopy + 0x8006d0);
  *(undefined8 *)(worldPtr + 0x34) = 0;
  *(undefined4 *)(worldPtr + 0x3c) = 0;
  leave_critical_section_b();
  leave_critical_section();
LAB_0046b6a3:
  Sleep(0x14);
  local_8 = 0xffffffff;
  piVar17 = (int *)*local_c8;
  *local_c8 = (int)local_c8;
  local_c8[1] = (int)local_c8;
  local_c4 = 0;
  if (piVar17 == local_c8) {
    operator_delete(local_c8);
  }
  operator_delete(piVar17);
}




/* cube::WorldInfo::vfunc_0 @ 0046d3b0 */

void cube::WorldInfo::vfunc_0(byte flags)

{
  uint stackCookie;
  undefined4 *pThis;
  void *savedExcList;
  undefined1 *ehHandler;
  undefined4 ehState;
  
  ehHandler = &LAB_006e564b;
  savedExcList = ExceptionList;
  stackCookie = DAT_0076aa78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &savedExcList;
  *pThis = vftable;
  ehState = 0;
  if ((undefined4 *)pThis[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)pThis[1])(1,stackCookie);
  }
  if (0xf < (uint)pThis[7]) {
    operator_delete((void *)pThis[2]);
  }
  pThis[7] = 0xf;
  pThis[6] = 0;
  *(undefined1 *)(pThis + 2) = 0;
  if ((flags & 1) != 0) {
    operator_delete(pThis);
  }
  ExceptionList = savedExcList;
  return;
}




/* [AUDIT] proposed: WorldInfo_clearUnderLock  (confidence: high)
 * purpose: Enters critical section at +0x250, destroys several intrusive lists (call vfunc(1)) and buffers, then leaves lock
 * vars: pThis=WorldInfo; cs at +0x250
 */
/* Global::WorldInfo_clearUnderLock @ 00486ba0 */

void WorldInfo_clearUnderLock(void)

{
  undefined4 *pList;
  void *pFirst;
  int pThis;
  int *pNode;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(pThis + 0x250));
  *(undefined4 *)(pThis + 0x18) = 0xffffffff;
  *(undefined4 *)(pThis + 0x1c) = 0xffffffff;
  pNode = (int *)**(int **)(pThis + 8);
  if (pNode != *(int **)(pThis + 8)) {
    do {
      if ((undefined4 *)pNode[2] != (undefined4 *)0x0) {
        (*(code *)**(undefined4 **)pNode[2])(1);
      }
      pNode = (int *)*pNode;
    } while (pNode != (int *)*(int *)(pThis + 8));
  }
  pList = *(undefined4 **)(pThis + 8);
  pFirst = (void *)*pList;
  *pList = pList;
  *(int *)(*(int *)(pThis + 8) + 4) = *(int *)(pThis + 8);
  *(undefined4 *)(pThis + 0xc) = 0;
  if (pFirst != *(void **)(pThis + 8)) {
    operator_delete(pFirst);
  }
  pNode = (int *)**(int **)(pThis + 0x10);
  if (pNode != *(int **)(pThis + 0x10)) {
    do {
      if ((undefined4 *)pNode[2] != (undefined4 *)0x0) {
        (*(code *)**(undefined4 **)pNode[2])(1);
      }
      pNode = (int *)*pNode;
    } while (pNode != (int *)*(int *)(pThis + 0x10));
  }
  pList = *(undefined4 **)(pThis + 0x10);
  pFirst = (void *)*pList;
  *pList = pList;
  *(int *)(*(int *)(pThis + 0x10) + 4) = *(int *)(pThis + 0x10);
  *(undefined4 *)(pThis + 0x14) = 0;
  if (pFirst == *(void **)(pThis + 0x10)) {
    pList = *(undefined4 **)(pThis + 0x240);
    pFirst = (void *)*pList;
    *pList = pList;
    *(int *)(*(int *)(pThis + 0x240) + 4) = *(int *)(pThis + 0x240);
    *(undefined4 *)(pThis + 0x244) = 0;
    if (pFirst != *(void **)(pThis + 0x240)) {
      operator_delete(pFirst);
    }
    pList = *(undefined4 **)(pThis + 0x248);
    pFirst = (void *)*pList;
    *pList = pList;
    *(int *)(*(int *)(pThis + 0x248) + 4) = *(int *)(pThis + 0x248);
    *(undefined4 *)(pThis + 0x24c) = 0;
    if (pFirst == *(void **)(pThis + 0x248)) {
      *(undefined4 *)(pThis + 0x23c) = 0;
      *(undefined4 *)(pThis + 0x238) = 0;
      LeaveCriticalSection((LPCRITICAL_SECTION)(pThis + 0x250));
      return;
    }
    operator_delete(pFirst);
  }
  operator_delete(pFirst);
}




/* [AUDIT] proposed: WorldGrid::freeCellPtr  (confidence: high)
 * purpose: In 1024x1024 pointer grid (base +0x10002f), if cell non-null: lock two CS, null entry, operator_delete the object
 * vars: 0x400=grid dim; CS at +0x8000c0/+0x8000d8; bounds<0x400; class WorldInfo grid
 */
/* Global::WorldGrid_freeCellPtr @ 005a4780 */

void WorldGrid_freeCellPtr(int chunk_x,int chunk_z)

{
  undefined4 *slot;
  void *chunk;
  int world;
  
  if ((((-1 < chunk_x) && (-1 < chunk_z)) && (chunk_x < 0x400)) && (chunk_z < 0x400)) {
    slot = (undefined4 *)(world + (chunk_x * 0x400 + 0x10002f + chunk_z) * 4);
    chunk = (void *)*slot;
    if (chunk != (void *)0x0) {
      EnterCriticalSection((LPCRITICAL_SECTION)(world + 0x8000c0));
      EnterCriticalSection((LPCRITICAL_SECTION)(world + 0x8000d8));
      *slot = 0;
      LeaveCriticalSection((LPCRITICAL_SECTION)(world + 0x8000d8));
      LeaveCriticalSection((LPCRITICAL_SECTION)(world + 0x8000c0));
      operator_delete(chunk);
    }
  }
  return;
}




/* [AUDIT] proposed: WorldGrid::destroyCellObject  (confidence: high)
 * purpose: Grid cell (base +0x2f) removal: run cleanup ctor_17, lock CS, null entry, then virtual destructor call (**vt)(1)
 * vars: stride 0x400; ctor_17 misattrib=cleanup; (1)=deleting-destructor flag
 */
/* Global::WorldGrid_destroyCellObject @ 005a4800 */

void WorldGrid_destroyCellObject(int chunk_x,int chunk_z)

{
  int *slot;
  undefined4 *obj;
  int world;
  
  if ((((-1 < chunk_x) && (-1 < chunk_z)) && (chunk_x < 0x400)) && (chunk_z < 0x400)) {
    slot = (int *)(world + (chunk_x * 0x400 + 0x2f + chunk_z) * 4);
    obj = (undefined4 *)*slot;
    if (obj != (undefined4 *)0x0) {
      std::basic_stringbuf<char,std::char_traits<char>,std::allocator<char>_>::ctor_17
                (chunk_x,chunk_z);
      EnterCriticalSection((LPCRITICAL_SECTION)(world + 0x8000c0));
      EnterCriticalSection((LPCRITICAL_SECTION)(world + 0x8000d8));
      *slot = 0;
      LeaveCriticalSection((LPCRITICAL_SECTION)(world + 0x8000d8));
      LeaveCriticalSection((LPCRITICAL_SECTION)(world + 0x8000c0));
      (**(code **)*obj)(1);
    }
  }
  return;
}




/* [AUDIT] proposed: WorldGrid::destroyBlockObjectAt  (confidence: high)
 * purpose: Two-level world grid: region idx (coord>>6) at +0xbc, block idx (coord&63) at +0x10018; null cell under locks, virtual-destroy object
 * vars: >>6=region, &0x3f=block; +0xbc region grid; +0x10018 block subgrid; +0xb4 flag skips ctor_13
 */
/* Global::WorldGrid_destroyBlockObjectAt @ 005a4890 */

void WorldGrid_destroyBlockObjectAt(uint x,uint z)

{
  undefined4 *obj;
  int chunk;
  int *slot;
  int world;
  int chunk_z;
  
  chunk = (int)(x + ((int)x >> 0x1f & 0x3fU)) >> 6;
  chunk_z = (int)(((int)z >> 0x1f & 0x3fU) + z) >> 6;
  if ((((-1 < chunk) && (-1 < chunk_z)) && (chunk < 0x400)) &&
     ((chunk_z < 0x400 && (chunk = *(int *)(world + 0xbc + (chunk * 0x400 + chunk_z) * 4), chunk != 0))
     )) {
    x = x & 0x8000003f;
    if ((int)x < 0) {
      x = (x - 1 | 0xffffffc0) + 1;
    }
    z = z & 0x8000003f;
    if ((int)z < 0) {
      z = (z - 1 | 0xffffffc0) + 1;
    }
    slot = (int *)(chunk + (x * 0x40 + z) * 4 + 0x10018);
    obj = (undefined4 *)*slot;
    if (obj != (undefined4 *)0x0) {
      EnterCriticalSection((LPCRITICAL_SECTION)(world + 0x8000d8));
      EnterCriticalSection((LPCRITICAL_SECTION)(world + 0x8000c0));
      *slot = 0;
      LeaveCriticalSection((LPCRITICAL_SECTION)(world + 0x8000c0));
      LeaveCriticalSection((LPCRITICAL_SECTION)(world + 0x8000d8));
      if (*(char *)(world + 0xb4) == '\0') {
        std::basic_stringbuf<char,std::char_traits<char>,std::allocator<char>_>::ctor_13(obj);
      }
      (**(code **)*obj)(1);
    }
  }
  return;
}




/* [AUDIT] proposed: WorldInfo_generateBiomeContent  (confidence: med)
 * purpose: WorldInfo build entry (ctor-called): populates biome with spawns, terrain features and decorations
 * vars: World_generateWaterOrPathFeature/5cb600/5cbe00 gen; WorldInfo_rotateAndPlace place; __alldiv scaling
 */
/* Global::WorldInfo_generateBiomeContent @ 005e4850 */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void WorldInfo_generateBiomeContent(float param_1,uint param_2)

{
  undefined1 *puVar1;
  char cVar2;
  byte bVar3;
  undefined1 uVar4;
  uint uVar5;
  uint uVar6;
  undefined8 *puVar7;
  undefined2 *puVar8;
  float *pfVar9;
  undefined4 uVar10;
  void *pvVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  int *piVar14;
  undefined4 *puVar15;
  int *piVar16;
  basic_ostream<char,std::char_traits<char>_> *pbVar17;
  CRefTime *pCVar18;
  long lVar19;
  long lVar20;
  int world;
  uint uVar21;
  int iVar22;
  int iVar23;
  float *pfVar24;
  code *pcVar25;
  int iVar26;
  char *pcVar27;
  bool bVar28;
  float10 fVar29;
  float fVar30;
  float fVar31;
  double dVar32;
  float *pfVar33;
  float *pfVar34;
  byte *pbVar35;
  float *pfVar36;
  undefined8 uVar37;
  longlong lVar38;
  longlong lVar39;
  undefined8 uVar40;
  ulonglong uVar41;
  undefined1 local_1820 [172];
  float local_1774;
  float local_1768;
  undefined1 local_1758 [24];
  float local_1740;
  float local_1710;
  float local_16e0;
  float local_16c8;
  undefined8 local_16b8;
  int local_1668 [26];
  float local_1600;
  float local_15f0;
  float local_15e0;
  float local_15d0;
  undefined8 local_15c0;
  float local_15ac;
  float local_15a8;
  float local_15a0;
  float local_159c;
  float local_1594;
  float local_1590;
  float *pfStack_1588;
  float *pfStack_1584;
  float *pfStack_1580;
  float *pfStack_157c;
  undefined1 local_1578 [16];
  undefined1 local_1568 [4];
  int local_1564;
  uint local_1560;
  int local_155c;
  float *local_1558;
  float *local_1554;
  float *local_1550;
  undefined1 local_154c [4];
  undefined8 local_1548;
  float *pfStack_1540;
  float *pfStack_153c;
  undefined8 local_1538;
  undefined1 local_1528 [8];
  float local_1520 [5];
  int local_150c;
  uint local_1508;
  undefined8 local_1504;
  int local_14fc;
  uint local_14f8;
  float *local_14f4;
  float *local_14f0;
  int local_14ec;
  uint local_14e8;
  undefined8 local_14e4;
  int local_14dc;
  uint local_14d8;
  float *local_14d4;
  float *local_14d0;
  int local_14cc;
  uint local_14c8;
  undefined1 local_14c2 [2];
  int local_14c0;
  int local_14b8;
  float *pfStack_14b0;
  int local_14a8;
  float *pfStack_149c;
  undefined1 local_1498 [4];
  int local_1494;
  undefined8 local_1490;
  undefined8 local_1488;
  undefined8 local_1480;
  undefined8 local_1478;
  undefined8 local_1470;
  undefined8 local_1468;
  int local_1460;
  int local_145c;
  void *local_1448;
  undefined4 local_1444;
  undefined4 local_1440;
  undefined1 local_143c;
  undefined1 local_143b;
  undefined1 local_143a;
  undefined1 local_1439;
  undefined2 local_1438;
  undefined1 local_1436;
  undefined1 local_1435;
  undefined2 local_1434;
  undefined1 local_1432;
  undefined2 local_1430;
  undefined1 local_142e;
  undefined1 local_142d;
  undefined2 local_142c;
  undefined1 local_142a;
  undefined2 local_1428;
  undefined1 local_1426;
  undefined1 local_1425;
  undefined2 local_1424;
  undefined2 local_1422;
  uint local_1420;
  undefined2 local_141c;
  undefined1 local_141a;
  undefined2 local_1418;
  undefined1 local_1416;
  undefined1 local_1415;
  undefined2 local_1414;
  undefined1 local_1412;
  void *local_1410;
  int local_140c;
  undefined4 local_1408;
  undefined1 local_1401;
  undefined2 local_1400;
  undefined1 local_13fe;
  undefined1 local_13fd;
  undefined2 local_13fc;
  undefined1 local_13fa;
  undefined1 local_13f9;
  int local_13f8;
  undefined2 local_13f4;
  undefined1 local_13f2;
  undefined1 local_13f1;
  undefined2 local_13f0;
  undefined1 local_13ee;
  undefined1 local_13ed;
  undefined2 local_13ec;
  undefined1 local_13ea;
  undefined2 local_13e8;
  undefined1 local_13e6;
  undefined1 local_13e4 [4];
  undefined2 local_13e0;
  undefined1 local_13de;
  undefined1 local_13dd;
  undefined1 local_13dc [4];
  undefined2 local_13d8;
  undefined1 local_13d6;
  int local_13d4;
  undefined2 local_13d0;
  undefined1 local_13ce;
  undefined2 local_13cc;
  undefined1 local_13ca;
  float *local_13c8;
  int local_13c4;
  undefined8 local_13c0;
  undefined8 local_13b8;
  void *local_13b0;
  undefined8 local_13ac;
  int local_13a4;
  int local_13a0;
  int local_139c;
  float local_1398;
  byte local_1394 [4];
  float *local_1390;
  float *local_138c;
  float local_1388;
  byte local_1384 [4];
  int local_1380;
  undefined4 *local_137c;
  int local_1378;
  float *local_1374;
  undefined2 local_1370;
  undefined1 local_136e;
  byte local_136d;
  byte *local_136c;
  uint local_1368;
  float *local_1364;
  float local_1360;
  float *local_135c;
  undefined8 local_1358;
  undefined2 local_1350;
  byte local_134e;
  byte local_134d;
  float *local_134c;
  float local_1348;
  undefined8 local_1344;
  float *local_133c;
  float *local_1338;
  float *local_1334;
  float *local_1330;
  float *local_132c;
  float *local_1328;
  float *local_1324;
  float *local_1320;
  undefined4 local_131c;
  float *local_1318;
  float *local_1314;
  byte local_130d;
  uint local_130c;
  float local_1308;
  float *local_1304;
  float *local_1300;
  float *local_12fc;
  float *local_12f8;
  float *local_12f4;
  float *local_12f0;
  int *local_12ec;
  float *local_12e8;
  int local_12e4;
  float *local_12e0;
  float *local_12dc;
  float *local_12d8;
  float *local_12d4;
  float *local_12d0;
  undefined4 local_12cc;
  undefined4 local_12c8;
  int local_11a8;
  undefined4 local_1188;
  undefined1 local_1184;
  undefined1 local_1183;
  undefined1 local_1177;
  undefined4 local_1048;
  uint local_1028;
  undefined2 local_ec0 [6];
  undefined1 local_eb4;
  char local_eb3;
  undefined2 local_eb0;
  undefined1 local_da8;
  undefined1 local_da7;
  undefined2 local_d98;
  float local_c78;
  undefined4 local_c74;
  undefined1 local_c70;
  undefined1 local_c60;
  undefined1 local_c5f;
  undefined2 local_c50;
  float local_b30;
  undefined4 local_b2c;
  undefined1 local_b28;
  undefined2 uStack_ad0;
  undefined1 uStack_ac3;
  undefined2 uStack_ac0;
  int iStack_9b8;
  int iStack_9b4;
  int iStack_9b0;
  float *pfStack_9ac;
  float *pfStack_9a8;
  float *pfStack_9a4;
  float fStack_9a0;
  undefined4 uStack_99c;
  undefined4 local_988;
  int local_980;
  int local_97c;
  int local_978;
  float *local_974;
  float *local_970;
  float *local_96c;
  uint local_968;
  undefined4 local_964;
  undefined4 local_960;
  undefined4 local_95c;
  void *local_940;
  undefined4 local_93c;
  undefined1 local_7e0 [12];
  undefined1 local_7d4 [36];
  undefined1 local_7b0 [24];
  undefined1 local_798 [24];
  undefined1 local_780 [12];
  undefined1 local_774 [12];
  undefined1 local_768 [12];
  undefined1 local_75c [12];
  undefined1 local_750 [12];
  undefined1 local_744 [12];
  undefined1 local_738 [12];
  undefined1 local_72c [12];
  undefined1 local_720 [12];
  undefined1 local_714 [12];
  undefined1 local_708 [12];
  undefined4 local_6fc;
  undefined8 local_6f4;
  undefined8 local_6ec;
  float local_6e4;
  float *local_6e0;
  uint local_6dc;
  undefined4 local_6d8;
  undefined4 local_6d4;
  undefined4 local_6d0;
  void *local_6b4;
  undefined4 local_6b0;
  int aiStack_578 [11];
  undefined4 local_54c;
  float local_548;
  int local_52c;
  undefined4 local_50c;
  float local_508;
  undefined4 local_4ec;
  undefined4 local_4cc;
  float local_4c8;
  undefined4 local_4b4;
  int local_4ac;
  int local_4a8;
  int local_4a0;
  float local_480;
  float local_47c;
  uint local_468;
  undefined8 local_460;
  undefined4 local_458;
  undefined4 local_454;
  undefined8 local_450;
  undefined8 local_448;
  undefined8 local_440;
  undefined8 local_438;
  uint local_430;
  float local_410;
  float local_40c;
  uint local_3f8;
  int local_3f0;
  int local_3ec;
  int local_3e8;
  float *local_3e4;
  float *local_3e0;
  float *local_3dc;
  undefined8 local_3d8;
  undefined8 local_3d0;
  float local_3c8;
  float *local_3c4;
  int local_3c0;
  int local_3bc;
  float local_3b8;
  float *local_3b4;
  float *local_3b0;
  float *local_3ac;
  float local_3a8;
  float *local_3a4;
  float *local_3a0;
  int iStack_39c;
  int local_398;
  int iStack_394;
  int iStack_390;
  int iStack_38c;
  float *pfStack_388;
  float *pfStack_384;
  float *pfStack_380;
  int local_37c;
  float local_35c;
  float local_358;
  uint local_344;
  float *local_33c;
  float local_338;
  int local_334;
  float *local_330;
  int local_32c;
  uint local_328;
  float local_324;
  float *local_320;
  float *local_31c;
  float *local_318;
  float local_314;
  float *local_310;
  int local_30c;
  float local_2ec;
  float local_2e8;
  uint local_2d4;
  float *pfStack_2cc;
  float *pfStack_2c8;
  int iStack_2c4;
  float *local_2c0;
  float *local_2bc;
  float *local_2b8;
  int local_2b4;
  int local_2b0;
  int local_2ac;
  int local_2a8 [4];
  int local_298;
  int local_294;
  float fStack_290;
  float fStack_28c;
  float fStack_288;
  float *pfStack_284;
  float *pfStack_280;
  float *pfStack_27c;
  float local_278;
  float fStack_274;
  float local_270;
  float local_26c;
  float fStack_268;
  float local_264;
  float fStack_260;
  float fStack_25c;
  float fStack_258;
  float *pfStack_254;
  float *pfStack_250;
  float *pfStack_24c;
  float local_248;
  float fStack_244;
  float local_240;
  float *local_23c;
  float *pfStack_238;
  uint local_234;
  undefined8 local_230;
  undefined8 local_228;
  float local_220;
  float *local_21c;
  undefined4 local_218;
  undefined4 uStack_214;
  undefined4 local_210;
  float local_20c;
  float fStack_208;
  float local_204;
  undefined4 local_200;
  undefined4 uStack_1fc;
  undefined4 local_1f8;
  float local_1f4;
  float fStack_1f0;
  float local_1ec;
  float local_1e8;
  float fStack_1e4;
  float local_1e0;
  undefined4 local_1dc;
  undefined4 uStack_1d8;
  undefined4 local_1d4;
  float local_1d0;
  float fStack_1cc;
  float local_1c8;
  float *local_1c4;
  int local_1c0;
  float *local_1bc;
  float *local_1b8;
  int local_1b4;
  uint local_1b0;
  undefined8 local_1ac;
  float local_1a4;
  undefined8 local_1a0;
  undefined8 local_198;
  float local_190;
  float local_18c;
  undefined8 local_188;
  undefined8 local_180;
  undefined8 local_178;
  float *local_170;
  undefined8 local_16c;
  float local_164;
  undefined8 local_160;
  float local_158;
  undefined8 local_154;
  float local_14c;
  undefined8 local_148;
  float local_140;
  undefined8 local_13c;
  float local_134;
  undefined8 local_130;
  float local_128;
  undefined8 local_124;
  float local_11c;
  undefined8 local_118;
  float local_110;
  undefined8 local_10c;
  float local_104;
  undefined8 local_100;
  float local_f8;
  undefined8 local_f4;
  float local_ec;
  undefined8 local_e8;
  float local_e0;
  undefined8 local_dc;
  float local_d4;
  undefined8 local_d0;
  float local_c8;
  undefined8 local_c4;
  float local_bc;
  undefined8 local_b8;
  float local_b0;
  undefined8 local_ac;
  float local_a4;
  undefined8 local_a0;
  float local_98;
  undefined8 local_94;
  float local_8c;
  undefined8 local_88;
  float local_80;
  undefined8 local_7c;
  float local_74;
  undefined8 local_70;
  float local_68;
  undefined8 local_64;
  float local_5c;
  undefined8 local_58;
  float local_50;
  undefined8 local_4c;
  undefined8 local_44;
  int local_3c;
  int iStack_38;
  uint local_34;
  undefined8 local_30;
  undefined8 local_28;
  float local_20;
  undefined8 local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_006f459d;
  local_10 = ExceptionList;
  uVar5 = DAT_0076aa78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_1360 = param_1;
  local_1368 = param_2;
  local_14 = uVar5;
  local_6ec = CONCAT44(local_6ec._4_4_,(undefined4)local_6ec);
  local_6f4 = CONCAT44(local_6f4._4_4_,(undefined4)local_6f4);
  local_3d0 = CONCAT44(local_3d0._4_4_,(undefined4)local_3d0);
  local_1548 = CONCAT44(local_1548._4_4_,(undefined4)local_1548);
  local_1490 = CONCAT44(local_1490._4_4_,(undefined4)local_1490);
  local_3d8 = CONCAT44(local_3d8._4_4_,(undefined4)local_3d8);
  local_228 = CONCAT44(local_228._4_4_,(undefined4)local_228);
  local_1a0 = CONCAT44(local_1a0._4_4_,(undefined4)local_1a0);
  local_1538 = CONCAT44(local_1538._4_4_,(undefined4)local_1538);
  local_1504 = CONCAT44(local_1504._4_4_,(undefined4)local_1504);
  local_230 = CONCAT44(local_230._4_4_,(undefined4)local_230);
  local_198 = CONCAT44(local_198._4_4_,(undefined4)local_198);
  local_460 = CONCAT44(local_460._4_4_,(undefined4)local_460);
  local_448 = CONCAT44(local_448._4_4_,(undefined4)local_448);
  local_440 = CONCAT44(local_440._4_4_,(undefined4)local_440);
  if ((((-1 < (int)param_1) &&
       (local_6ec = CONCAT44(local_6ec._4_4_,(undefined4)local_6ec),
       local_6f4 = CONCAT44(local_6f4._4_4_,(undefined4)local_6f4),
       local_3d0 = CONCAT44(local_3d0._4_4_,(undefined4)local_3d0),
       local_1548 = CONCAT44(local_1548._4_4_,(undefined4)local_1548),
       local_1490 = CONCAT44(local_1490._4_4_,(undefined4)local_1490),
       local_3d8 = CONCAT44(local_3d8._4_4_,(undefined4)local_3d8),
       local_228 = CONCAT44(local_228._4_4_,(undefined4)local_228),
       local_1a0 = CONCAT44(local_1a0._4_4_,(undefined4)local_1a0),
       local_1538 = CONCAT44(local_1538._4_4_,(undefined4)local_1538),
       local_1504 = CONCAT44(local_1504._4_4_,(undefined4)local_1504),
       local_230 = CONCAT44(local_230._4_4_,(undefined4)local_230),
       local_198 = CONCAT44(local_198._4_4_,(undefined4)local_198),
       local_460 = CONCAT44(local_460._4_4_,(undefined4)local_460),
       local_448 = CONCAT44(local_448._4_4_,(undefined4)local_448),
       local_440 = CONCAT44(local_440._4_4_,(undefined4)local_440), -1 < (int)param_2)) &&
      (local_6ec = CONCAT44(local_6ec._4_4_,(undefined4)local_6ec),
      local_6f4 = CONCAT44(local_6f4._4_4_,(undefined4)local_6f4),
      local_3d0 = CONCAT44(local_3d0._4_4_,(undefined4)local_3d0),
      local_1548 = CONCAT44(local_1548._4_4_,(undefined4)local_1548),
      local_1490 = CONCAT44(local_1490._4_4_,(undefined4)local_1490),
      local_3d8 = CONCAT44(local_3d8._4_4_,(undefined4)local_3d8),
      local_228 = CONCAT44(local_228._4_4_,(undefined4)local_228),
      local_1a0 = CONCAT44(local_1a0._4_4_,(undefined4)local_1a0),
      local_1538 = CONCAT44(local_1538._4_4_,(undefined4)local_1538),
      local_1504 = CONCAT44(local_1504._4_4_,(undefined4)local_1504),
      local_230 = CONCAT44(local_230._4_4_,(undefined4)local_230),
      local_198 = CONCAT44(local_198._4_4_,(undefined4)local_198),
      local_460 = CONCAT44(local_460._4_4_,(undefined4)local_460),
      local_448 = CONCAT44(local_448._4_4_,(undefined4)local_448),
      local_440 = CONCAT44(local_440._4_4_,(undefined4)local_440), (int)param_1 < 0x10000)) &&
     (local_6ec = CONCAT44(local_6ec._4_4_,(undefined4)local_6ec),
     local_6f4 = CONCAT44(local_6f4._4_4_,(undefined4)local_6f4),
     local_3d0 = CONCAT44(local_3d0._4_4_,(undefined4)local_3d0),
     local_1548 = CONCAT44(local_1548._4_4_,(undefined4)local_1548),
     local_1490 = CONCAT44(local_1490._4_4_,(undefined4)local_1490),
     local_3d8 = CONCAT44(local_3d8._4_4_,(undefined4)local_3d8),
     local_228 = CONCAT44(local_228._4_4_,(undefined4)local_228),
     local_1a0 = CONCAT44(local_1a0._4_4_,(undefined4)local_1a0),
     local_1538 = CONCAT44(local_1538._4_4_,(undefined4)local_1538),
     local_1504 = CONCAT44(local_1504._4_4_,(undefined4)local_1504),
     local_230 = CONCAT44(local_230._4_4_,(undefined4)local_230),
     local_198 = CONCAT44(local_198._4_4_,(undefined4)local_198),
     local_460 = CONCAT44(local_460._4_4_,(undefined4)local_460),
     local_448 = CONCAT44(local_448._4_4_,(undefined4)local_448),
     local_440 = CONCAT44(local_440._4_4_,(undefined4)local_440), (int)param_2 < 0x10000)) {
    local_1328 = (float *)0xffffffff;
    local_1388 = (float)((int)(((int)param_2 >> 0x1f & 0x3fU) + param_2) >> 6);
    local_13d4 = (int)(((int)param_1 >> 0x1f & 0x3fU) + (int)param_1) >> 6;
    local_12e4 = world;
    do {
      iVar26 = -1;
      do {
        cube::GameController::generateRegion
                  ((int)local_1328 + local_13d4,(int)local_1388 + iVar26,uVar5);
        iVar26 = iVar26 + 1;
      } while (iVar26 < 2);
      local_1328 = (float *)((int)local_1328 + 1);
    } while ((int)local_1328 < 2);
    local_1380 = *(int *)(world + 0xbc + (local_13d4 * 0x400 + (int)local_1388) * 4);
    iVar26 = world_getRegionCell64(local_1360,local_1368);
    local_6ec = CONCAT44(local_6ec._4_4_,(undefined4)local_6ec);
    local_6f4 = CONCAT44(local_6f4._4_4_,(undefined4)local_6f4);
    local_3d0 = CONCAT44(local_3d0._4_4_,(undefined4)local_3d0);
    local_1548 = CONCAT44(local_1548._4_4_,(undefined4)local_1548);
    local_1490 = CONCAT44(local_1490._4_4_,(undefined4)local_1490);
    local_3d8 = CONCAT44(local_3d8._4_4_,(undefined4)local_3d8);
    local_228 = CONCAT44(local_228._4_4_,(undefined4)local_228);
    local_1a0 = CONCAT44(local_1a0._4_4_,(undefined4)local_1a0);
    local_1538 = CONCAT44(local_1538._4_4_,(undefined4)local_1538);
    local_1504 = CONCAT44(local_1504._4_4_,(undefined4)local_1504);
    local_230 = CONCAT44(local_230._4_4_,(undefined4)local_230);
    local_198 = CONCAT44(local_198._4_4_,(undefined4)local_198);
    local_460 = CONCAT44(local_460._4_4_,(undefined4)local_460);
    local_448 = CONCAT44(local_448._4_4_,(undefined4)local_448);
    local_440 = CONCAT44(local_440._4_4_,(undefined4)local_440);
    if (iVar26 == 0) {
      local_13b0 = operator_new(200);
      local_8 = 0;
      if (local_13b0 == (void *)0x0) {
        local_130c = 0;
      }
      else {
        local_130c = cube::Zone::ctor_0();
      }
      uVar5 = local_130c;
      local_8 = 0xffffffff;
      srand(*(int *)(world + 0x800188) + local_1368 * 0x10000 + (int)local_1360);
      local_12e8 = (float *)(uVar5 + 0x60);
      *local_12e8 = local_1360;
      *(uint *)(uVar5 + 100) = local_1368;
      local_1330 = (float *)(local_1368 * 0x100);
      local_138c = local_1330 + 0x20;
      local_135c = (float *)((int)local_1360 * 0x100);
      local_1390 = local_135c + 0x20;
      findNearestEntityInGrid(local_1390,local_138c);
      iVar26 = Terrain_sampleHeightNoise();
      iVar22 = 0;
      do {
        iVar23 = iVar22 * 8;
        iVar22 = iVar22 + 1;
        aiStack_578[iVar22] = (int)*(double *)(iVar26 + iVar23);
      } while (iVar22 < 2);
      local_1324 = (float *)0x0;
      local_1364 = (float *)0x0;
      local_139c = 0;
      local_1308 = 0.0;
      uVar21 = (int)(((int)local_1360 >> 0x1f & 7U) + (int)local_1360) >> 3 & 0x80000007;
      if ((int)uVar21 < 0) {
        uVar21 = (uVar21 - 1 | 0xfffffff8) + 1;
      }
      uVar6 = (int)(local_1368 + ((int)local_1368 >> 0x1f & 7U)) >> 3 & 0x80000007;
      if ((int)uVar6 < 0) {
        uVar6 = (uVar6 - 1 | 0xfffffff8) + 1;
      }
      local_1304 = (float *)((uVar6 + uVar21 * 8) * 0x68 + local_1380 + 0x14018);
      local_13c4 = 0;
      local_13c8 = (float *)list_allocNode20(0,0);
      local_1374 = local_135c + 0x40;
      local_8._0_1_ = 1;
      local_8._1_3_ = 0;
      local_12dc = local_135c;
      if ((int)local_135c < (int)local_1374) {
        pfVar9 = local_1330 + 0x40;
        local_1300 = pfVar9;
        do {
          local_12f0 = local_1330;
          if ((int)local_1330 < (int)pfVar9) {
            local_12d4 = (float *)((uint)local_12dc & 0x800000ff);
            if ((int)local_12d4 < 0) {
              local_12d4 = (float *)(((int)local_12d4 - 1U | 0xffffff00) + 1);
            }
            do {
              uVar21 = (uint)local_12f0 & 0x800000ff;
              if ((int)uVar21 < 0) {
                uVar21 = (uVar21 - 1 | 0xffffff00) + 1;
              }
              iVar26 = (int)(local_12d4 + uVar21 * 0x40) * 0x20 + *(int *)(uVar5 + 0xa8);
              fVar29 = (float10)GameController_sampleTemperatureGrid(local_12dc,local_12f0);
              *(float *)(iVar26 + 4) = (float)fVar29;
              fVar29 = (float10)GameController_sampleHumidityGrid(local_12dc,local_12f0);
              *(float *)(iVar26 + 8) = (float)fVar29;
              fVar29 = (float10)World_getRegionCellPtr(local_12dc,local_12f0);
              *(float *)(iVar26 + 0xc) = (float)fVar29;
              local_12f0 = (float *)((int)local_12f0 + 1);
              pfVar9 = local_1300;
            } while ((int)local_12f0 < (int)local_1300);
          }
          local_12dc = (float *)((int)local_12dc + 1);
          world = local_12e4;
        } while ((int)local_12dc < (int)local_1374);
      }
      local_12fc = (float *)operator_new_wrapper();
      local_1328 = local_135c;
      if ((int)local_135c <= (int)(local_135c + 0x40)) {
        pfVar9 = local_1330 + 0x40;
        do {
          iVar26 = local_12e4;
          local_1300 = local_1330;
          if ((int)local_1330 <= (int)pfVar9) {
            local_1314 = local_12fc + ((int)local_1328 - (int)local_135c);
            do {
              fVar29 = (float10)terrain_generateColumnColor();
              *local_1314 = (float)fVar29;
              local_1314 = local_1314 + 0x101;
              local_1300 = (float *)((int)local_1300 + 1);
              pfVar9 = local_1330 + 0x40;
              world = iVar26;
            } while ((int)local_1300 <= (int)pfVar9);
          }
          local_1328 = (float *)((int)local_1328 + 1);
        } while ((int)local_1328 <= (int)local_1374);
      }
      local_131c = local_135c;
      local_1334 = (float *)0x1;
      if ((int)local_135c < (int)local_1374) {
        pfVar9 = local_1330 + 0x40;
        local_136c = (byte *)&DAT_0076ddf8;
        local_13a4 = 7;
        local_13a0 = 0x1e;
        do {
          local_12cc = local_1330;
          if ((int)local_1330 < (int)pfVar9) {
            local_12d4 = (float *)((uint)local_131c & 0x800000ff);
            if ((int)local_12d4 < 0) {
              local_12d4 = (float *)(((int)local_12d4 - 1U | 0xffffff00) + 1);
            }
            dVar32 = (double)(int)local_131c;
            local_180 = dVar32 * 0.08 + 4234.0;
            local_1470 = dVar32 * 0.08 + 432.0;
            local_13ac = dVar32 * 0.01;
            local_188 = dVar32 * 0.05 + 423432.0;
            local_1468 = local_13ac + 34432.0;
            local_1488 = local_13ac + 435.0;
            local_1480 = dVar32 * 0.04 + 432.0;
LAB_005e4de0:
            world = local_12e4;
            uVar21 = (uint)local_12cc & 0x800000ff;
            if ((int)uVar21 < 0) {
              uVar21 = (uVar21 - 1 | 0xffffff00) + 1;
            }
            local_12d0 = (float *)((int)(local_12d4 + uVar21 * 0x40) * 0x20 + *(int *)(uVar5 + 0xa8)
                                  );
            iVar26 = (((int)local_12cc - (int)local_1330) * 0x101 - (int)local_135c) +
                     (int)local_131c;
            local_1300 = (float *)local_12fc[iVar26];
            if ((0.3 < ABS((float)local_1300 - local_12fc[iVar26 + 1])) ||
               (local_130d = 0, uVar5 = local_130c,
               0.3 < ABS((float)local_1300 - local_12fc[iVar26 + 0x101]))) {
              local_130d = 1;
            }
            fVar29 = (float10)World_placeObjectWithSpacing();
            local_12dc = (float *)(float)fVar29;
            if (0.25 < (float)local_12dc) {
              local_1308 = (float)((int)local_1308 + 1);
            }
            local_1c = (double)(int)local_12cc;
            local_30 = local_1c * 0.08;
            fVar29 = (float10)perlinNoise2D_cosInterp(local_1480,local_1c * 0.04 + 432.0);
            local_12f4 = (float *)(float)fVar29;
            fVar29 = (float10)perlinNoise2D_cosInterp(local_1470,local_30 + 432.0);
            local_12e0 = (float *)(float)fVar29;
            fVar30 = 1.0 - ABS((float)local_12f4 + (float)local_12e0 * 0.05);
            fVar30 = 1.0 - fVar30 * fVar30 * fVar30;
            local_12f4 = (float *)(fVar30 * fVar30 + 0.0);
            fVar29 = (float10)perlinNoise2D_cosInterp(local_180,local_30 + 234.0);
            local_12e0 = (float *)(float)fVar29;
            local_1478 = (double)(float)local_12e0 * 0.05;
            fVar29 = (float10)perlinNoise2D_cosInterp(local_188,local_1c * 0.05 + 54352.0);
            local_12e0 = (float *)(float)fVar29;
            fVar30 = (float)(1.0 - ABS(local_1478 + (double)(float)local_12e0));
            fVar30 = 1.0 - fVar30 * fVar30 * fVar30;
            local_12f8 = local_12dc;
            local_1314 = (float *)(fVar30 * fVar30 + (float)local_12f4);
            if ((local_1304[6] == 8.40779e-45) || (local_1304[6] == 1.82169e-44)) {
              local_14c8 = ((int)local_12cc >> 0x1f) << 0x10 | (uint)local_12cc >> 0x10;
              local_14cc = (int)local_12cc << 0x10;
              local_1508 = ((int)local_131c >> 0x1f) << 0x10 | (uint)local_131c >> 0x10;
              local_150c = (int)local_131c << 0x10;
              fVar29 = (float10)vec3_distanceSquared(&local_150c,&local_14cc);
              local_12e0 = (float *)(float)fVar29;
              fVar30 = 1.0 - (float)local_12e0;
              if (0.0 < fVar30) {
                fVar30 = fVar30 * fVar30;
              }
              else {
                fVar30 = 0.0;
              }
              fVar30 = fVar30 * 2.0;
              if (1.0 < fVar30) {
                fVar30 = 1.0;
              }
              fVar30 = 1.0 - fVar30 * fVar30;
              local_12f4 = (float *)(1.0 - fVar30 * fVar30);
              fVar29 = (float10)perlinNoise2D_cosInterp(local_13ac + 985.0,local_1c * 0.01 + 98584.0);
              local_12e0 = (float *)(float)fVar29;
              fVar30 = (float)local_12e0 * 1.3 + 1.0;
              if (0.0 <= fVar30) {
                if (1.0 < fVar30) {
                  fVar30 = 1.0;
                }
              }
              else {
                fVar30 = 0.0;
              }
              local_12f8 = (float *)((fVar30 * 3.0 * fVar30 - fVar30 * 2.0 * fVar30 * fVar30) *
                                     (float)local_12f4 * 0.4 + (float)local_12dc);
            }
            local_12f4 = (float *)((float)local_12f8 * (float)local_1314);
            fVar30 = (float)local_12f4 * 1.25;
            if (0.0 <= fVar30) {
              if (1.0 < fVar30) {
                fVar30 = 1.0;
              }
            }
            else {
              fVar30 = 0.0;
            }
            local_1348 = fVar30 * 3.0 * fVar30 - fVar30 * 2.0 * fVar30 * fVar30;
            local_30 = local_1c * 0.01;
            fVar29 = (float10)perlinNoise2D_cosInterp(local_1468,local_30 + 8992.0);
            local_12e0 = (float *)(float)fVar29;
            local_1320 = (float *)(((float)local_12e0 + 1.5) * 60.0 * (float)local_12dc +
                                   (float)local_12f4 * 8.0 + (float)local_1300);
            local_12d8 = (float *)(int)(float)local_1320;
            terrain_surfaceColor_blend(&local_1350,local_131c,local_12cc,local_12d8,local_12d0[1],local_12d0[2],
                         uVar5);
            if (0.5 < local_1348) {
              local_134d = 6;
            }
            local_1f4 = (float)(byte)local_1350;
            fStack_1f0 = (float)local_1350._1_1_;
            local_1398 = 1.0 - local_1348;
            local_1ec = (float)local_134e;
            local_58 = CONCAT44(fStack_1f0 * local_1398,local_1f4 * local_1398);
            local_50 = local_1ec * local_1398;
            puVar7 = (undefined8 *)vec3_store4(local_7e0,local_131c,local_12cc,local_12d8,uVar5);
            local_f4._0_4_ = (float)*puVar7;
            local_f4._0_4_ = (float)local_f4 * local_1348;
            local_f4._4_4_ = (float)((ulonglong)*puVar7 >> 0x20);
            local_f4._4_4_ = local_f4._4_4_ * local_1348;
            local_ec = *(float *)(puVar7 + 1) * local_1348;
            local_100 = CONCAT44(local_f4._4_4_ + local_58._4_4_,(float)local_f4 + (float)local_58);
            local_f8 = local_ec + local_50;
            iVar26 = 0;
            do {
              iVar22 = iVar26 + 1;
              *(char *)((int)&local_1350 + iVar26) =
                   (char)(int)*(float *)((int)&local_100 + iVar26 * 4);
              iVar26 = iVar22;
            } while (iVar22 < 3);
            local_12d0[4] = (float)local_12d8;
            if ((float)local_1320 < (float)(int)local_1324) {
              local_1324 = local_12d8;
            }
            local_12f8 = (float *)((float)local_12f8 * 8.0);
            if ((float)(int)local_1364 < (float)local_1320) {
              local_1364 = local_12d8;
            }
            if (1.0 < (float)local_12f8) {
              local_12f8 = (float *)0x3f800000;
            }
            bVar28 = local_130d == 0;
            local_130d = local_134d;
            if (bVar28) {
              puVar7 = (undefined8 *)terrain_rockColor_blend(local_720,local_131c,local_12cc,local_12d8,uVar5);
              local_5c = 1.0 - (float)local_12f8;
              local_64._0_4_ = (float)*puVar7;
              local_64._4_4_ = (float)((ulonglong)*puVar7 >> 0x20);
              local_64 = CONCAT44(local_64._4_4_ * local_5c,(float)local_64 * local_5c);
              local_5c = *(float *)(puVar7 + 1) * local_5c;
              local_26c = (float)(byte)local_1350;
              fStack_268 = (float)local_1350._1_1_;
              local_264 = (float)local_134e;
              pfVar9 = (float *)vec3_store4(local_708,local_131c,local_12cc,local_12d8,uVar5);
              local_b0 = (float)local_12f8 * 0.5;
              local_d0 = CONCAT44(pfVar9[1] + fStack_268,local_26c + *pfVar9);
              local_c8 = pfVar9[2] + local_264;
              fVar30 = (local_26c + *pfVar9) * local_b0;
              fVar31 = (pfVar9[1] + fStack_268) * local_b0;
              local_b8 = CONCAT44(fVar31,fVar30);
              local_b0 = local_c8 * local_b0;
              local_124 = CONCAT44(fVar31 + local_64._4_4_,fVar30 + (float)local_64);
              local_11c = local_b0 + local_5c;
              iVar26 = 0;
              do {
                iVar22 = iVar26 + 1;
                *(char *)((int)&local_1414 + iVar26) =
                     (char)(int)*(float *)((int)&local_124 + iVar26 * 4);
                iVar26 = iVar22;
              } while (iVar22 < 3);
              local_1370 = local_1414;
              local_136e = local_1412;
              local_136d = 6;
              if ((int)local_12d0[7] < 1) {
                sparseArray_resize(1,0);
              }
              puVar1 = (undefined1 *)local_12d0[6];
              if ((~((byte)puVar1[3] >> 7) & 1) == 0) {
                if ((local_136d & 0x1f) != 0) {
                  *puVar1 = (undefined1)local_1370;
                  puVar1[1] = local_1370._1_1_;
                  puVar1[2] = local_136e;
                  puVar1[3] = local_136d;
                  *(byte *)((int)local_12d0[6] + 3) = *(byte *)((int)local_12d0[6] + 3) | 0x80;
                }
              }
              else {
                *puVar1 = (undefined1)local_1370;
                puVar1[1] = local_1370._1_1_;
                puVar1[2] = local_136e;
                puVar1[3] = local_136d;
              }
            }
            else {
              if ((int)local_12d0[7] < 1) {
                sparseArray_resize(1,0);
              }
              puVar8 = (undefined2 *)local_12d0[6];
              if ((~(*(byte *)((int)puVar8 + 3) >> 7) & 1) == 0) {
                if ((local_130d & 0x1f) != 0) {
                  *puVar8 = local_1350;
                  *(byte *)(puVar8 + 1) = local_134e;
                  *(byte *)((int)puVar8 + 3) = local_130d;
                  *(byte *)((int)local_12d0[6] + 3) = *(byte *)((int)local_12d0[6] + 3) | 0x80;
                }
              }
              else {
                *puVar8 = local_1350;
                *(byte *)(puVar8 + 1) = local_134e;
                *(byte *)((int)puVar8 + 3) = local_130d;
              }
            }
            if ((int)local_12d0[7] < 2) {
              sparseArray_resize(2,0);
            }
            fVar30 = local_12d0[6];
            if ((~(*(byte *)((int)fVar30 + 7) >> 7) & 1) == 0) {
              if ((local_130d & 0x1f) != 0) {
                *(undefined2 *)((int)fVar30 + 4) = local_1350;
                *(byte *)((int)fVar30 + 6) = local_134e;
                *(byte *)((int)fVar30 + 7) = local_130d;
                *(byte *)((int)local_12d0[6] + 7) = *(byte *)((int)local_12d0[6] + 7) | 0x80;
              }
            }
            else {
              *(undefined2 *)((int)fVar30 + 4) = local_1350;
              *(byte *)((int)fVar30 + 6) = local_134e;
              *(byte *)((int)fVar30 + 7) = local_130d;
            }
            if ((local_130d & 0x1f) == 4) {
              local_139c = local_139c + 1;
            }
            local_12d0[5] = (float)((int)local_12d0[4] + -8);
            fVar29 = (float10)perlinNoise2D_cosInterp(local_1488,local_30 + 847.0);
            local_12e0 = (float *)(float)fVar29;
            local_132c = (float *)(((float)local_12e0 + 1.0) * 20.0 + (float)local_1300);
            if ((float)local_132c < (float)local_1320) {
              fVar29 = (float10)perlinNoise2D_cosInterp((double)(int)local_131c * 0.005 +
                                             (double)*(int *)(world + 0x800178),
                                             local_1c * 0.005 + (double)*(int *)(world + 0x80017c))
              ;
              local_12e0 = (float *)(float)fVar29;
              fVar29 = (float10)perlinNoise2D_cosInterp((double)*(int *)(world + 0x800178) + local_13ac,
                                             (double)*(int *)(world + 0x80017c) + local_30);
              local_12f4 = (float *)(float)fVar29;
              fVar30 = 1.0 - ABS((float)local_12e0 + (float)local_12f4) * 4.0;
              if (fVar30 < 0.0) goto LAB_005e6b08;
              fVar31 = 1.0 - fVar30 * fVar30;
              local_12f4 = (float *)(1.0 - fVar31 * fVar31);
              fVar30 = 1.0 - fVar30 * fVar30;
              local_133c = (float *)(1.0 - fVar30 * fVar30 * fVar30 * fVar30);
              fVar29 = (float10)perlinNoise2D_cosInterp((double)(int)local_131c * 0.03 + 7635.0,
                                             local_1c * 0.03 + 123847.0);
              local_12e0 = (float *)(float)fVar29;
              fVar30 = ((float)local_12e0 * 10.0 + (((float)local_1320 - (float)local_132c) - 20.0))
                       / 10.0;
              if (0.0 <= fVar30) {
                if (1.0 < fVar30) {
                  fVar30 = 1.0;
                }
              }
              else {
                fVar30 = 0.0;
              }
              fVar31 = 1.0 - fVar30 * fVar30;
              fVar30 = 1.0 - fVar30;
              local_12f0 = (float *)(1.0 - fVar31 * fVar31);
              fVar30 = fVar30 * fVar30 * fVar30 * fVar30 * fVar30 * fVar30 * fVar30;
              local_12f8 = (float *)((((float)local_12dc * 20.0 + 4.0) * (float)local_12f4 +
                                     (float)local_132c) * (1.0 - fVar30) +
                                    ((float)local_1320 + 2.0) * fVar30);
              fVar30 = (float)local_1314 * (float)local_12dc * 6.0 + (float)local_132c;
              local_1318 = (float *)((1.0 - (float)local_133c) * (float)local_1320 +
                                     (float)local_133c * fVar30 + 2.0);
              if (fVar30 < (float)local_1320 - 2.0) {
                local_12e0 = (float *)(1.0 - (float)local_12f0);
                local_1328 = (float *)0x0;
                do {
                  iVar26 = world_getChunkCell256();
                  if (iVar26 == 0) {
                    pbVar35 = &DAT_0076ddfc;
                  }
                  else if ((int)local_12d8 < *(int *)(iVar26 + 0x10)) {
                    pbVar35 = &DAT_0076ddfc;
                  }
                  else if ((int)local_12d8 < *(int *)(iVar26 + 0x1c) + *(int *)(iVar26 + 0x10)) {
                    pbVar35 = (byte *)array_atChecked4();
                    if ((((pbVar35[3] & 0x1f) == 0) && ((int)local_12d8 < 1)) &&
                       ((pbVar35[3] & 0x40) == 0)) {
                      pbVar35 = &DAT_0076ddf4;
                    }
                  }
                  else {
                    pbVar35 = &DAT_0076ddf4;
                    if (0 < (int)local_12d8) {
                      pbVar35 = local_136c;
                    }
                  }
                  local_1394[0] = *pbVar35;
                  local_1394[1] = pbVar35[1];
                  local_1394[2] = pbVar35[2];
                  local_1394[3] = pbVar35[3];
                  puVar7 = (undefined8 *)
                           vec3_store4(local_780,local_131c,local_12cc,
                                        (int)((float)(int)local_1328 + (float)local_1320),uVar5);
                  local_20c = (float)local_1394[0];
                  fStack_208 = (float)local_1394[1];
                  local_148._0_4_ = (float)*puVar7;
                  local_148._0_4_ = (float)local_12e0 * (float)local_148;
                  local_204 = (float)local_1394[2];
                  local_148._4_4_ = (float)((ulonglong)*puVar7 >> 0x20);
                  local_148._4_4_ = (float)local_12e0 * local_148._4_4_;
                  local_140 = (float)local_12e0 * *(float *)(puVar7 + 1);
                  local_e8 = CONCAT44(fStack_208 * (float)local_12f0,local_20c * (float)local_12f0);
                  local_e0 = local_204 * (float)local_12f0;
                  local_13c = CONCAT44(fStack_208 * (float)local_12f0 + local_148._4_4_,
                                       local_20c * (float)local_12f0 + (float)local_148);
                  local_134 = local_e0 + local_140;
                  iVar26 = 0;
                  do {
                    iVar22 = iVar26 + 1;
                    local_1394[iVar26] = (byte)(int)*(float *)((int)&local_13c + iVar26 * 4);
                    iVar26 = iVar22;
                  } while (iVar22 < 3);
                  tilemap_writeGlyphColumn(local_131c,local_12cc,local_12d8,local_1394,uVar5);
                  local_12d8 = (float *)((int)local_12d8 + 1);
                  local_1328 = (float *)((int)local_1328 + 1);
                } while ((int)local_1328 < 2);
              }
              if ((float)local_12f8 <= (float)local_1318) goto LAB_005e6b08;
              local_143c = (undefined1)DAT_0076ddf8;
              local_143a = DAT_0076ddf8._2_1_;
              local_1439 = DAT_0076ddf8._3_1_;
              local_143b = (undefined1)((uint)DAT_0076ddf8 >> 8);
              local_13d0 = 0;
              local_13e0 = 0;
              local_13dd = 0;
              local_13ce = 0;
              local_13de = 0;
              if ((float)local_12f8 < (float)local_1320) {
                local_13dd = 0x40;
              }
              local_1300 = (float *)(int)(float)local_1318;
              local_1328 = local_1300;
              if ((float)(int)local_1300 < (float)local_12f8) {
                do {
                  if ((int)local_1300 < 1) {
                    local_13cc = 0;
                    local_1424 = 0;
                    local_13ca = 0;
                    local_1422 = 0x200;
                    puVar8 = &local_1424;
                  }
                  else {
                    puVar8 = &local_13e0;
                  }
                  tilemap_writeGlyphColumn(local_131c,local_12cc,local_1300,puVar8,uVar5);
                  local_1300 = (float *)((int)local_1300 + 1);
                } while ((float)(int)local_1300 < (float)local_12f8);
              }
              local_12dc = (float *)(int)((float)local_1318 - 1.0);
              terrain_surfaceColor_blend(local_1384,local_131c,local_12cc,local_12dc,local_12d0[1],local_12d0[2],
                           uVar5);
              if ((0.5 < local_1348) || (0.5 < (float)local_12f0)) {
                local_1384[3] = 6;
              }
              local_278 = (float)local_1384[0];
              fStack_274 = (float)local_1384[1];
              local_270 = (float)local_1384[2];
              local_74 = 1.0 - (float)local_12f0;
              local_7c = CONCAT44(fStack_274 * local_74,local_278 * local_74);
              local_74 = local_270 * local_74;
              pfVar9 = (float *)vec3_store4(local_738,local_131c,local_12cc,local_12dc,uVar5);
              puVar7 = (undefined8 *)terrain_rockColor_blend(local_7b0,local_131c,local_12cc,local_12dc,uVar5);
              world = local_12e4;
              local_88._0_4_ = (float)*puVar7;
              local_88._0_4_ = (float)local_88 + *pfVar9;
              local_98 = (float)local_12f0 * 0.4;
              local_88._4_4_ = (float)((ulonglong)*puVar7 >> 0x20);
              local_88._4_4_ = pfVar9[1] + local_88._4_4_;
              local_80 = pfVar9[2] + *(float *)(puVar7 + 1);
              fVar30 = (float)local_88 * local_98;
              fVar31 = local_88._4_4_ * local_98;
              local_a0 = CONCAT44(fVar31,fVar30);
              local_98 = local_80 * local_98;
              local_130 = CONCAT44(fVar31 + local_7c._4_4_,fVar30 + (float)local_7c);
              local_128 = local_98 + local_74;
              iVar26 = 0;
              do {
                iVar22 = iVar26 + 1;
                local_1384[iVar26] = (byte)(int)*(float *)((int)&local_130 + iVar26 * 4);
                iVar26 = iVar22;
              } while (iVar22 < 3);
              local_1d0 = (float)local_1384[0];
              fStack_1cc = (float)local_1384[1];
              local_1c8 = (float)local_1384[2];
              local_70 = CONCAT44(fStack_1cc * local_1398,local_1d0 * local_1398);
              local_68 = local_1c8 * local_1398;
              puVar7 = (undefined8 *)vec3_store4(local_750,local_131c,local_12cc,local_12dc,uVar5);
              local_ac._0_4_ = (float)*puVar7;
              local_ac._0_4_ = (float)local_ac * local_1348;
              local_ac._4_4_ = (float)((ulonglong)*puVar7 >> 0x20);
              local_ac._4_4_ = local_ac._4_4_ * local_1348;
              local_a4 = *(float *)(puVar7 + 1) * local_1348;
              local_10c = CONCAT44(local_ac._4_4_ + local_70._4_4_,(float)local_ac + (float)local_70
                                  );
              local_104 = local_a4 + local_68;
              iVar26 = 0;
              do {
                iVar22 = iVar26 + 1;
                local_1384[iVar26] = (byte)(int)*(float *)((int)&local_10c + iVar26 * 4);
                iVar26 = iVar22;
              } while (iVar22 < 3);
              tilemap_writeGlyphColumn(local_131c,local_12cc,local_12dc,local_1384,uVar5);
              if (((2.0 < (float)local_12f8 - (float)local_1318) &&
                  (((int)local_131c + (int)local_12cc * 3) % local_13a4 == 0)) &&
                 (iVar26 = rand(), iVar26 % local_13a0 == 0)) {
                uVar21 = rand();
                uVar21 = uVar21 & 0x80000003;
                if ((int)uVar21 < 0) {
                  uVar21 = (uVar21 - 1 | 0xfffffffc) + 1;
                }
                switch(uVar21) {
                case 0:
                  if ((float)local_12f8 <= (float)local_1320) {
                    uVar21 = rand();
                    uVar21 = uVar21 & 0x80000003;
                    bVar28 = uVar21 == 0;
                    if ((int)uVar21 < 0) {
                      bVar28 = (uVar21 - 1 | 0xfffffffc) == 0xffffffff;
                    }
                    if (bVar28) {
                      reset_0x148Struct();
                      uStack_ac0 = 1;
                      pfStack_1584 = (float *)(((int)local_1328 >> 0x1f) << 0x10 |
                                              (uint)local_1328 >> 0x10);
                      pfStack_1588 = (float *)((int)local_1328 << 0x10);
                      local_1328 = (float *)(((int)local_12cc >> 0x1f) << 0x10 |
                                            (uint)local_12cc >> 0x10);
                      uStack_ad0 = 0x130b;
                      uStack_ac3 = 9;
                      uVar21 = (int)local_12cc * 0x10000;
                      local_1314 = pfStack_1584;
                      local_1300 = pfStack_1588;
                      uVar37 = float_to_uint64_round();
                      iVar26 = (int)((ulonglong)uVar37 >> 0x20);
                      uVar5 = (uint)uVar37;
                      iStack_9b0 = uVar21 - uVar5;
                      local_1328 = (float *)(((int)local_1328 - iVar26) - (uint)(uVar21 < uVar5));
                      iStack_9b8 = (int)local_131c * 0x10000 - uVar5;
                      iStack_9b4 = ((((int)local_131c >> 0x1f) << 0x10 | (uint)local_131c >> 0x10) -
                                   iVar26) - (uint)((uint)((int)local_131c * 0x10000) < uVar5);
                      pfStack_384 = local_1300;
                      pfStack_380 = local_1314;
                      pfStack_9a8 = local_1300;
                      pfStack_9a4 = local_1314;
                      uStack_99c = 0x3dcccccd;
                      pfStack_9ac = local_1328;
                      iStack_394 = iStack_9b8;
                      iStack_390 = iStack_9b4;
                      iStack_38c = iStack_9b0;
                      pfStack_388 = local_1328;
                      iVar26 = rand();
                      uVar5 = local_130c;
                      fStack_9a0 = ((float)iVar26 * 6.2831855) / 32767.0;
                      vector_pushBack_0x148();
                      world = local_12e4;
                    }
                  }
                  break;
                case 1:
                  if ((float)local_12f8 <= (float)local_1320) {
                    pvVar11 = operator_new(0x10f0);
                    if (pvVar11 == (void *)0x0) {
                      pfStack_149c = (float *)0x0;
                    }
                    else {
                      pfStack_149c = (float *)cube::Spawn::ctor_0();
                    }
                    pfStack_153c = (float *)(((int)local_1328 >> 0x1f) << 0x10 |
                                            (uint)local_1328 >> 0x10);
                    pfStack_1540 = (float *)((int)local_1328 << 0x10);
                    local_1328 = (float *)(((int)local_12cc >> 0x1f) << 0x10 |
                                          (uint)local_12cc >> 0x10);
                    uVar21 = (int)local_12cc * 0x10000;
                    local_1300 = pfStack_149c;
                    local_12f4 = pfStack_153c;
                    local_12e0 = pfStack_1540;
                    uVar37 = float_to_uint64_round();
                    pfVar9 = local_1300;
                    iVar26 = (int)((ulonglong)uVar37 >> 0x20);
                    uVar5 = (uint)uVar37;
                    fStack_288 = (float)(uVar21 - uVar5);
                    local_1328 = (float *)(((int)local_1328 - iVar26) - (uint)(uVar21 < uVar5));
                    fStack_290 = (float)((int)local_131c * 0x10000 - uVar5);
                    pfStack_280 = local_12e0;
                    pfStack_27c = local_12f4;
                    fStack_28c = (float)(((((int)local_131c >> 0x1f) << 0x10 |
                                          (uint)local_131c >> 0x10) - iVar26) -
                                        (uint)((uint)((int)local_131c * 0x10000) < uVar5));
                    local_1300[4] = fStack_290;
                    local_1300[5] = fStack_28c;
                    local_1300[6] = fStack_288;
                    local_1300[7] = (float)local_1328;
                    local_1300[8] = (float)local_12e0;
                    local_1300[9] = (float)local_12f4;
                    local_1300[0xd] = 1.4013e-45;
                    local_1300[10] = 8.40779e-45;
                    local_1300[0x3d6] = 25.0;
                    pfStack_284 = local_1328;
                    iVar26 = rand();
                    iVar26 = iVar26 % 10;
                    if (iVar26 == 0) {
                      pfVar9[0xb] = 1.8357e-43;
                    }
                    else if (iVar26 == 1) {
                      pfVar9[0xb] = 1.86373e-43;
                    }
                    else if (iVar26 == 3) {
                      iVar26 = rand();
                      switch(iVar26 % 100) {
                      case 0:
                        pfVar9[0xb] = 1.93379e-43;
                        break;
                      case 1:
                      case 2:
                      case 3:
                        pfVar9[0xb] = 1.91978e-43;
                        break;
                      case 4:
                      case 5:
                      case 6:
                      case 7:
                      case 8:
                        pfVar9[0xb] = 1.90577e-43;
                        break;
                      default:
                        pfVar9[0xb] = 1.89175e-43;
                      }
                    }
                    else {
                      pfVar9[0xb] = 1.84971e-43;
                    }
                    uVar5 = local_130c;
                    std_vector_push_back_4byte();
                    world = local_12e4;
                  }
                  break;
                case 2:
                  if ((float)local_12f8 <= (float)local_1320) {
                    pvVar11 = operator_new(0x10f0);
                    if (pvVar11 == (void *)0x0) {
                      pfStack_14b0 = (float *)0x0;
                    }
                    else {
                      pfStack_14b0 = (float *)cube::Spawn::ctor_0();
                    }
                    pfStack_157c = (float *)(((int)local_1328 >> 0x1f) << 0x10 |
                                            (uint)local_1328 >> 0x10);
                    pfStack_1580 = (float *)((int)local_1328 << 0x10);
                    local_1314 = (float *)(((int)local_12cc >> 0x1f) << 0x10 |
                                          (uint)local_12cc >> 0x10);
                    pfVar34 = (float *)((int)local_12cc * 0x10000);
                    local_133c = pfVar34;
                    local_132c = pfStack_157c;
                    local_1300 = pfStack_14b0;
                    local_12f4 = pfStack_1580;
                    uVar37 = float_to_uint64_round();
                    world = local_12e4;
                    pfVar9 = local_1300;
                    iVar26 = (int)((ulonglong)uVar37 >> 0x20);
                    pfVar24 = (float *)uVar37;
                    fStack_258 = (float)((int)pfVar34 - (int)pfVar24);
                    local_12e0 = (float *)((int)local_1314 + (-(uint)(pfVar34 < pfVar24) - iVar26));
                    local_1398 = (float)(((int)local_131c >> 0x1f) << 0x10 |
                                        (uint)local_131c >> 0x10);
                    local_1328 = (float *)((int)local_131c * 0x10000);
                    fStack_260 = (float)((int)local_1328 - (int)pfVar24);
                    pfStack_250 = local_12f4;
                    fStack_25c = (float)(((int)local_1398 - iVar26) - (uint)(local_1328 < pfVar24));
                    pfStack_24c = local_132c;
                    local_1300[4] = fStack_260;
                    local_1300[5] = fStack_25c;
                    local_1300[6] = fStack_258;
                    local_1300[7] = (float)local_12e0;
                    local_1300[8] = (float)local_12f4;
                    local_1300[9] = (float)local_132c;
                    pfStack_254 = local_12e0;
                    fVar30 = (float)Terrain_blockTypeAtTime(local_1328,local_1398,local_133c,local_1314);
                    uVar5 = local_130c;
                    pfVar9[0xd] = fVar30;
                    pfVar9[10] = 1.4013e-45;
                    pfVar9[0xb] = 8.26766e-44;
                    std_vector_push_back_4byte();
                  }
                  break;
                case 3:
                  pfStack_2cc = local_131c;
                  pfStack_2c8 = local_12cc;
                  iStack_2c4 = (int)((float)local_1318 + 2.0);
                  fVar30 = (float)allocObjectWithVec3();
                  if (local_13c4 == 0xccccccb) goto LAB_005e9764;
                  local_13c4 = local_13c4 + 1;
                  local_13c8[1] = fVar30;
                  **(float **)((int)fVar30 + 4) = fVar30;
                }
              }
            }
            if (local_1304[6] == 5.60519e-45) {
              local_14f8 = ((int)local_12cc >> 0x1f) << 0x10 | (uint)local_12cc >> 0x10;
              local_14fc = (int)local_12cc << 0x10;
              local_14e8 = ((int)local_131c >> 0x1f) << 0x10 | (uint)local_131c >> 0x10;
              local_14ec = (int)local_131c << 0x10;
              fVar29 = (float10)vec3_distanceSquared(&local_14ec,&local_14fc);
              local_12e0 = (float *)(float)fVar29;
              if (((float)local_12e0 < 0.25) &&
                 (local_12dc = (float *)(int)(local_1304[5] - 25.0),
                 (int)local_12d0[4] <= (int)local_12dc)) {
                do {
                  iVar26 = world_getColumnData(local_131c,local_12cc,local_12dc,uVar5);
                  if (((*(byte *)(iVar26 + 3) & 0x1f) == 0) || ((*(byte *)(iVar26 + 3) & 0x1f) == 2)
                     ) {
                    puVar8 = (undefined2 *)&DAT_0076ddf4;
                  }
                  else {
                    iVar22 = vec3_store4(local_798,local_131c,local_12cc,local_12dc,uVar5);
                    iVar26 = 0;
                    do {
                      iVar23 = iVar26 + 1;
                      *(char *)((int)&local_1434 + iVar26) =
                           (char)(int)*(float *)(iVar22 + iVar26 * 4);
                      iVar26 = iVar23;
                    } while (iVar23 < 3);
                    local_13f0 = local_1434;
                    local_13ee = local_1432;
                    puVar8 = &local_13f0;
                    local_13ed = 3;
                  }
                  tilemap_writeGlyphColumn(local_131c,local_12cc,local_12dc,CONCAT44(uVar5,puVar8));
                  local_12dc = (float *)((int)local_12dc - 1);
                } while ((int)local_12d0[4] <= (int)local_12dc);
              }
            }
LAB_005e6b08:
            local_12cc = (float *)((int)local_12cc + 1);
            pfVar9 = local_1330 + 0x40;
            if ((int)pfVar9 <= (int)local_12cc) goto LAB_005e6b3e;
            goto LAB_005e4de0;
          }
LAB_005e6b3e:
          local_131c = (float *)((int)local_131c + 1);
        } while ((int)local_131c < (int)local_1374);
      }
      operator_delete__(local_12fc);
      uVar21 = (uint)local_1360 & 0x8000003f;
      if ((int)uVar21 < 0) {
        uVar21 = (uVar21 - 1 | 0xffffffc0) + 1;
      }
      uVar6 = local_1368 & 0x8000003f;
      if ((int)uVar6 < 0) {
        uVar6 = (uVar6 - 1 | 0xffffffc0) + 1;
      }
      local_13b0 = (void *)(uVar6 + uVar21 * 0x40);
      local_1348 = (float)((int)local_13b0 * 0x10);
      *(undefined8 *)(uVar5 + 0x78) = *(undefined8 *)((int)local_1348 + 0x18 + local_1380);
      *(undefined8 *)(uVar5 + 0x80) = *(undefined8 *)((int)local_1348 + 0x20 + local_1380);
      local_1378 = 0;
      local_137c = (undefined4 *)list_allocNode32(0,0);
      local_8 = CONCAT31(local_8._1_3_,2);
      iVar26 = world_getChunkCell256();
      if (iVar26 == 0) {
        fVar29 = (float10)GameController_sampleTemperatureGrid(local_1390,local_138c);
        local_1300 = (float *)(float)fVar29;
        local_12d4 = local_1300;
      }
      else {
        local_1300 = *(float **)(iVar26 + 4);
      }
      iVar26 = world_getChunkCell256();
      if (iVar26 == 0) {
        fVar29 = (float10)GameController_sampleHumidityGrid(local_1390,local_138c);
        local_1314 = (float *)(float)fVar29;
        local_12d4 = local_1314;
      }
      else {
        local_1314 = *(float **)(iVar26 + 8);
      }
      if (local_1304[6] == 8.40779e-45) {
        local_1318 = (float *)0x0;
        do {
          local_12dc = (float *)0x0;
          do {
            uVar21 = rand();
            uVar21 = uVar21 & 0x80000003;
            bVar28 = uVar21 == 0;
            if ((int)uVar21 < 0) {
              bVar28 = (uVar21 - 1 | 0xfffffffc) == 0xffffffff;
            }
            if (!bVar28) {
              local_12f0 = (float *)(*(int *)(uVar5 + 0x60) * 0x100 + (int)local_1318 / 3 + 0x2a);
              local_1308 = (float)(*(int *)(uVar5 + 100) * 0x100 + (int)local_12dc / 3 + 0x2a);
              local_14f0 = (float *)(((int)local_1308 >> 0x1f) << 0x10 | (uint)local_1308 >> 0x10);
              local_14f4 = (float *)((int)local_1308 * 0x10000);
              local_14d0 = (float *)(((int)local_12f0 >> 0x1f) << 0x10 | (uint)local_12f0 >> 0x10);
              local_14d4 = (float *)((int)local_12f0 * 0x10000);
              local_133c = local_14d0;
              local_132c = local_14d4;
              local_12f4 = local_14f0;
              local_12e0 = local_14f4;
              fVar29 = (float10)vec3_distanceSquared(&local_14d4,&local_14f4);
              local_12d4 = (float *)(float)fVar29;
              fVar30 = 1.0 - (float)local_12d4;
              if ((0.0 < fVar30) && (0.5 <= fVar30 * fVar30)) {
                for (puVar15 = (undefined4 *)*local_137c; puVar15 != local_137c;
                    puVar15 = (undefined4 *)*puVar15) {
                  local_1344 = (double)CONCAT44((int)local_12f4 +
                                                (-(uint)(local_12e0 < (float *)puVar15[4]) -
                                                puVar15[5]),(int)local_12e0 - puVar15[4]);
                  local_1358 = (double)CONCAT44((int)local_133c +
                                                (-(uint)(local_132c < (float *)puVar15[2]) -
                                                puVar15[3]),(int)local_132c - puVar15[2]);
                  local_12d4 = (float *)(float)(longlong)local_1358;
                  local_16c8 = (float)local_12d4 * 1.5258789e-05;
                  if (local_16c8 * local_16c8 +
                      (float)(longlong)local_1344 * 1.5258789e-05 *
                      (float)(longlong)local_1344 * 1.5258789e-05 < 6400.0) goto LAB_005e6f34;
                }
                iVar26 = rand();
                local_12f4 = (float *)(iVar26 % 10 + 0x14);
                iVar26 = rand();
                local_12e0 = (float *)(iVar26 % 10 + 0x14);
                uVar21 = rand();
                uVar21 = uVar21 & 0x8000000f;
                if ((int)uVar21 < 0) {
                  uVar21 = (uVar21 - 1 | 0xfffffff0) + 1;
                }
                local_12d4 = (float *)(uVar21 + 0x14);
                local_1768 = (float)(int)local_12f0 - *(float *)(world + 0x8000f0);
                fVar30 = (float)(int)local_1308 - *(float *)(world + 0x8000f4);
                if (3600.0 <= fVar30 * fVar30 + local_1768 * local_1768) {
                  iVar26 = world_getChunkCell256();
                  World_carveTerrainFeatureB(local_12f0,local_1308,
                               *(int *)(iVar26 + 0x1c) + *(int *)(iVar26 + 0x10),local_12f4,
                               local_12e0,local_12d4,uVar5);
                }
              }
            }
LAB_005e6f34:
            local_12dc = local_12dc + 0x40;
          } while ((int)local_12dc < 0x300);
          local_1318 = local_1318 + 0x40;
        } while ((int)local_1318 < 0x300);
      }
      if ((local_1304[6] == 1.82169e-44) || (local_1304[6] == 5.60519e-45)) {
        uVar10 = __alldiv(*local_1304,local_1304[1],0x10000,0);
        local_1c = (double)CONCAT44(local_1c._4_4_,uVar10);
        iVar26 = __alldiv(local_1304[2],local_1304[3],0x10000,0);
        local_2a8[0] = (int)((int)local_1c + ((int)local_1c >> 0x1f & 0xffU)) >> 8;
        local_1c = (double)CONCAT44(iVar26,(int)local_1c);
        local_2a8[1] = (int)(iVar26 + (iVar26 >> 0x1f & 0xffU)) >> 8;
        iVar26 = 0;
        piVar14 = (int *)(uVar5 + 0x60);
        do {
          if (local_2a8[iVar26] != *piVar14) goto LAB_005e7040;
          iVar26 = iVar26 + 1;
          piVar14 = piVar14 + 1;
        } while (iVar26 < 2);
        iVar26 = world_getChunkCell256();
        local_1308 = (float)(*(int *)(iVar26 + 0x1c) + *(int *)(iVar26 + 0x10));
        while( true ) {
          iVar26 = world_getColumnData((int)local_1c,(int)((ulonglong)local_1c >> 0x20),local_1308,uVar5);
          if (((*(byte *)(iVar26 + 3) & 0x1f) != 0) && ((*(byte *)(iVar26 + 3) & 0x1f) != 2)) break;
          local_1308 = (float)((int)local_1308 - 1);
        }
      }
LAB_005e7040:
      local_12d4 = (float *)local_1304[6];
      if (local_12d4 == (float *)0xb) {
        iVar26 = __alldiv(*local_1304,local_1304[1],0x10000,0);
        local_3c0 = iVar26;
        local_3bc = __alldiv(local_1304[2],local_1304[3],0x10000,0);
        local_298 = (int)(iVar26 + (iVar26 >> 0x1f & 0xffU)) >> 8;
        local_294 = (int)(local_3bc + (local_3bc >> 0x1f & 0xffU)) >> 8;
        iVar26 = 0;
        piVar14 = (int *)(uVar5 + 0x60);
        do {
          if (local_2a8[iVar26 + 4] != *piVar14) goto LAB_005e7154;
          iVar26 = iVar26 + 1;
          piVar14 = piVar14 + 1;
        } while (iVar26 < 2);
        iVar26 = *(int *)(uVar5 + 100);
        local_1308 = (float)(*(int *)(uVar5 + 0x60) * 0x100 + 0x80);
        iVar22 = rand();
        iVar23 = world_getChunkCell256();
        World_carveTerrainFeatureB(local_1308,iVar26 * 0x100 + 0x80,
                     *(int *)(iVar23 + 0x1c) + *(int *)(iVar23 + 0x10),100,100,iVar22 % 100 + 100,
                     local_130c);
        uVar5 = local_130c;
      }
      else {
LAB_005e7154:
        if (local_12d4 == (float *)0xc) {
          iVar26 = __alldiv(*local_1304,local_1304[1],0x10000,0);
          local_4c = (double)CONCAT44(local_4c._4_4_,iVar26);
          iVar22 = __alldiv(local_1304[2],local_1304[3],0x10000,0);
          local_2a8[2] = (int)(iVar26 + (iVar26 >> 0x1f & 0xffU)) >> 8;
          local_4c = (double)CONCAT44(iVar22,(undefined4)local_4c);
          local_2a8[3] = (int)(iVar22 + (iVar22 >> 0x1f & 0xffU)) >> 8;
          piVar14 = (int *)(uVar5 + 0x60);
          iVar26 = 0;
          do {
            if (local_2a8[iVar26 + 2] != *piVar14) goto LAB_005e727a;
            iVar26 = iVar26 + 1;
            piVar14 = piVar14 + 1;
          } while (iVar26 < 2);
          local_12f0 = (float *)(*(int *)(uVar5 + 100) * 0x100 + 0x80);
          local_1308 = (float)(*(int *)(uVar5 + 0x60) * 0x100 + 0x80);
          rand();
          iVar26 = world_getChunkCell256();
          World_generateWaterOrPathFeature(local_1308,local_12f0,*(int *)(iVar26 + 0x1c) + *(int *)(iVar26 + 0x10),0x50,
                       0x50,6);
          local_1324 = (float *)(*(int *)(iVar26 + 0x1c) + *(int *)(iVar26 + 0x10));
          while( true ) {
            iVar26 = world_getColumnData(local_1308,local_12f0,local_1324,uVar5);
            if (((*(byte *)(iVar26 + 3) & 0x1f) != 0) && ((*(byte *)(iVar26 + 3) & 0x1f) != 2))
            break;
            local_1324 = (float *)((int)local_1324 - 1);
          }
        }
        else {
LAB_005e727a:
          pcVar25 = rand_exref;
          cVar2 = *(char *)((int)local_1348 + 0x18 + local_1380);
          if (((cVar2 != '\x04') && (cVar2 != '\x01')) && (cVar2 != '\x03')) {
            uVar21 = rand();
            local_1318 = (float *)(uVar21 & 0x80000003);
            if ((int)local_1318 < 0) {
              local_1318 = (float *)(((int)local_1318 - 1U | 0xfffffffc) + 1);
            }
            if (((0.6 < (float)local_1314) || ((float)local_1314 < 0.3)) &&
               ((0.7 < (float)local_1300 ||
                (((float)local_1300 < 0.4 &&
                 ((0.2 < (float)local_1300 || ((float)local_1314 < 0.8)))))))) {
              local_1318 = (float *)((int)local_1318 + 2);
            }
            if (0 < (int)local_1318) {
              do {
                iVar26 = (*pcVar25)();
                pfVar9 = (float *)(iVar26 % 0x28 + 10);
                local_12dc = pfVar9;
                iVar26 = (*pcVar25)();
                local_12f0 = (float *)(iVar26 % 0x28 + 10);
                iVar26 = (*pcVar25)();
                local_1308 = (float)(iVar26 % 0x19 + 10);
                iVar22 = 0x40 - (int)local_12f0;
                iVar26 = rand();
                local_12d8 = (float *)(iVar26 % ((0x40 - (int)pfVar9) * 4) +
                                      (int)(local_12dc + (int)*local_12e8 * 0x20) * 2);
                iVar26 = rand();
                uVar5 = local_130c;
                local_12f8 = (float *)(iVar26 % (iVar22 * 4) +
                                      (int)(local_12f0 + *(int *)(local_130c + 100) * 0x20) * 2);
                local_16e0 = (float)(int)local_12d8 - *(float *)(local_12e4 + 0x8000f0);
                fVar30 = (float)(int)local_12f8 - *(float *)(local_12e4 + 0x8000f4);
                if (3600.0 <= fVar30 * fVar30 + local_16e0 * local_16e0) {
                  puVar15 = (undefined4 *)*local_137c;
                  if (puVar15 != local_137c) {
                    local_12e0 = (float *)(((int)local_12f8 >> 0x1f) << 0x10 |
                                          (uint)local_12f8 >> 0x10);
                    local_12d4 = (float *)((int)local_12f8 * 0x10000);
                    local_133c = (float *)(((int)local_12d8 >> 0x1f) << 0x10 |
                                          (uint)local_12d8 >> 0x10);
                    local_132c = (float *)((int)local_12d8 * 0x10000);
                    do {
                      local_1344 = (double)CONCAT44((int)local_12e0 +
                                                    (-(uint)(local_12d4 < (uint)puVar15[4]) -
                                                    puVar15[5]),(int)local_12d4 - puVar15[4]);
                      local_1358 = (double)CONCAT44((int)local_133c +
                                                    (-(uint)(local_132c < (float *)puVar15[2]) -
                                                    puVar15[3]),(int)local_132c - puVar15[2]);
                      local_12f4 = (float *)(float)(longlong)local_1358;
                      local_15d0 = (float)local_12f4 * 1.5258789e-05;
                      if (local_15d0 * local_15d0 +
                          (float)(longlong)local_1344 * 1.5258789e-05 *
                          (float)(longlong)local_1344 * 1.5258789e-05 < 6400.0) goto LAB_005e767b;
                      puVar15 = (undefined4 *)*puVar15;
                    } while (puVar15 != local_137c);
                  }
                  fVar29 = (float10)Terrain_sampleHeightAtWorldXY(local_12d8,local_12f8);
                  local_12d4 = (float *)(float)fVar29;
                  if ((float)local_12d4 <= 0.6) {
                    fVar29 = (float10)WorldInfo_sampleTerrainHeight();
                    local_12d4 = (float *)(float)fVar29;
                    if (1.0 - (float)local_12d4 * 50.0 < 0.0) {
                      fVar29 = (float10)World_placeObjectWithSpacing();
                      local_12d4 = (float *)(float)fVar29;
                      iVar26 = world_getChunkCell256();
                      local_1324 = (float *)(*(int *)(iVar26 + 0x1c) + *(int *)(iVar26 + 0x10));
                      uVar21 = rand();
                      uVar21 = uVar21 & 0x80000001;
                      bVar28 = uVar21 == 0;
                      if ((int)uVar21 < 0) {
                        bVar28 = (uVar21 - 1 | 0xfffffffe) == 0xffffffff;
                      }
                      if ((bVar28) || (0.25 <= (float)local_12d4)) {
                        World_carveTerrainFeatureB(local_12d8,local_12f8,local_1324,local_12dc,local_12f0,
                                     local_1308,uVar5);
                      }
                      else {
                        World_carveTerrainFeatureA(local_12d8,local_12f8,local_1324,local_12dc,local_12f0,
                                     (int)local_1308 / 2,uVar5);
                      }
                    }
                  }
                }
LAB_005e767b:
                local_1318 = (float *)((int)local_1318 + -1);
                pcVar25 = rand_exref;
              } while (local_1318 != (float *)0x0);
              local_1318 = (float *)0x0;
            }
          }
        }
      }
      local_12d0 = local_135c;
      if ((int)local_135c < (int)local_1374) {
        pfVar9 = local_1330 + 0x40;
        do {
          local_12e8 = local_1330;
          if ((int)local_1330 < (int)pfVar9) {
            do {
              fVar29 = (float10)WorldInfo_rotateAndPlace();
              local_12d4 = (float *)(float)fVar29;
              local_1308 = 1.0 - (float)local_12d4 * 50.0;
              fVar29 = (float10)Terrain_sampleHeightAtWorldXY(local_12d0,local_12e8);
              local_12f0 = (float *)(float)fVar29;
              if (0.0 <= local_1308) {
                fVar29 = (float10)terrain_generateColumnColor();
                local_12d4 = (float *)(float)fVar29;
                local_1324 = local_12d4;
                if ((float)local_12d4 < 0.0) {
                  local_1324 = (float *)0x0;
                }
                fVar30 = 1.0 - local_1308;
                local_12d8 = (float *)(int)((float)local_1324 + 1.0);
                local_12e0 = (float *)(1.0 - fVar30 * fVar30 * fVar30);
                local_13b8 = (double)(int)local_12e8;
                local_13c0 = (double)(int)local_12d0;
                fVar29 = (float10)perlinNoise2D_cosInterp(local_13c0 * 0.02 + 55432.0,local_13b8 * 0.02 + 974.0
                                              );
                local_12d4 = (float *)(float)fVar29;
                local_12dc = (float *)(int)(((float)local_12d4 + 1.0) * 4.0 +
                                           (float)local_12e0 * 5.0 + (float)local_1324);
                iVar26 = world_getColumnData(local_12d0,local_12e8,local_12d8,uVar5);
                if ((((*(byte *)(iVar26 + 3) & 0x1f) != 0) && ((*(byte *)(iVar26 + 3) & 0x1f) != 2))
                   && (iVar26 = world_getColumnData(local_12d0,local_12e8,local_12d8,uVar5),
                      (*(byte *)(iVar26 + 3) & 0x40) == 0)) {
                  local_248 = 40.0;
                  fStack_244 = 40.0;
                  local_240 = 40.0;
                  fVar29 = (float10)perlinNoise2D_cosInterp(local_13c0 * 0.05 + 843.0,local_13b8 * 0.05 + 984.0
                                                );
                  local_12d4 = (float *)(float)fVar29;
                  local_14c = local_240 * (float)local_12d4;
                  local_1dc = 0x430c0000;
                  uStack_1d8 = 0x430c0000;
                  local_1d4 = 0x430c0000;
                  local_12e0 = (float *)(((int)local_12e8 / 2) * 0xea);
                  local_28 = CONCAT44(fStack_244 * (float)local_12d4 + 140.0,
                                      local_248 * (float)local_12d4 + 140.0);
                  local_20 = local_14c + 140.0;
                  local_12f4 = (float *)(((int)local_12d0 / 2) * 0xea);
                  local_154 = CONCAT44(fStack_244 * (float)local_12d4,local_248 * (float)local_12d4)
                  ;
                  fVar29 = (float10)perlinNoise2D_cosInterp((double)((int)local_12f4 + 0x12e2),
                                                 (double)((int)local_12e0 + 0xc11a));
                  local_12d4 = (float *)(float)fVar29;
                  if (0.5 < (float)local_12d4) {
                    local_1e8 = 20.0;
                    fStack_1e4 = 20.0;
                    local_1e0 = 20.0;
                    fVar29 = (float10)perlinNoise2D_cosInterp((double)(int)local_12f4,
                                                   (double)((int)local_12e0 + 0x31));
                    local_12d4 = (float *)(float)fVar29;
                    local_158 = local_1e0 * (float)local_12d4;
                    local_160 = CONCAT44(fStack_1e4 * (float)local_12d4,
                                         local_1e8 * (float)local_12d4);
                    local_20 = local_158 + local_20;
                    local_28 = CONCAT44(fStack_1e4 * (float)local_12d4 + local_28._4_4_,
                                        local_1e8 * (float)local_12d4 + (float)local_28);
                  }
                  iVar26 = *(int *)(local_1380 + 0x14);
                  if (((iVar26 == 1) || (iVar26 == 4)) || (iVar26 == 5)) {
                    puVar7 = (undefined8 *)
                             terrain_rockColor_blend(local_768,local_12d0,local_12e8,local_12d8,uVar5);
                    local_28 = *puVar7;
                    local_20 = *(float *)(puVar7 + 1);
                  }
                  local_178._0_4_ = (float)local_28;
                  local_12d4 = (float *)((float)local_12f0 * (float)local_178);
                  local_178._4_4_ = (float)((ulonglong)local_28 >> 0x20);
                  local_12e0 = (float *)((float)local_12f0 * local_178._4_4_);
                  local_178 = CONCAT44(local_12e0,local_12d4);
                  local_12f4 = (float *)((float)local_12f0 * local_20);
                  local_170 = local_12f4;
                  puVar7 = (undefined8 *)
                           terrain_rockColor_blend(local_7d4,local_12d0,local_12e8,local_12d8,uVar5);
                  local_bc = 1.0 - (float)local_12f0;
                  local_c4._0_4_ = (float)*puVar7;
                  local_c4._0_4_ = local_bc * (float)local_c4;
                  local_c4._4_4_ = (float)((ulonglong)*puVar7 >> 0x20);
                  local_c4._4_4_ = local_bc * local_c4._4_4_;
                  local_bc = local_bc * *(float *)(puVar7 + 1);
                  local_dc = CONCAT44(local_c4._4_4_ + (float)local_12e0,
                                      (float)local_c4 + (float)local_12d4);
                  local_d4 = local_bc + (float)local_12f4;
                  local_1a4 = local_d4;
                  local_1ac = local_dc;
                  iVar26 = 0;
                  do {
                    pfVar9 = (float *)((int)&local_1ac + iVar26 * 4);
                    if (*pfVar9 <= 0.0 && *pfVar9 != 0.0) {
                      *(undefined4 *)((int)&local_1ac + iVar26 * 4) = 0;
                    }
                    if (255.0 < *(float *)((int)&local_1ac + iVar26 * 4)) {
                      *(undefined4 *)((int)&local_1ac + iVar26 * 4) = 0x437f0000;
                    }
                    iVar26 = iVar26 + 1;
                  } while (iVar26 < 3);
                  iVar26 = 0;
                  do {
                    iVar22 = iVar26 + 1;
                    *(char *)((int)&local_13ec + iVar26) =
                         (char)(int)*(float *)((int)&local_1ac + iVar26 * 4);
                    iVar26 = iVar22;
                  } while (iVar22 < 3);
                  local_1438 = local_13ec;
                  local_1436 = local_13ea;
                  local_1435 = 0xb;
                  tilemap_writeGlyphColumn(local_12d0,local_12e8,(int)local_12d8 - 1,&local_1438,uVar5);
                  if (0.92 < (float)local_12f0) {
                    iVar26 = world_getChunkCell256();
                    local_12dc = (float *)(*(int *)(iVar26 + 0x1c) + *(int *)(iVar26 + 0x10));
                  }
                  if ((int)local_12d8 < (int)local_12dc) {
                    do {
                      iVar26 = world_getColumnData(local_12d0,local_12e8,local_12d8,uVar5);
                      if ((*(byte *)(iVar26 + 3) & 0x40) == 0) {
                        tilemap_writeGlyphColumn(local_12d0,local_12e8,local_12d8,&DAT_0076ddf8,uVar5);
                      }
                      local_12d8 = (float *)((int)local_12d8 + 1);
                    } while ((int)local_12d8 < (int)local_12dc);
                  }
                }
              }
              local_12e8 = (float *)((int)local_12e8 + 1);
              pfVar9 = local_1330 + 0x40;
            } while ((int)local_12e8 < (int)pfVar9);
          }
          local_12d0 = (float *)((int)local_12d0 + 1);
        } while ((int)local_12d0 < (int)local_1374);
      }
      local_13ac = (double)((ulonglong)local_13ac & 0xffffffff);
      uVar10 = list_allocNode20(0,0);
      local_13ac = (double)CONCAT44(local_13ac._4_4_,uVar10);
      local_8._0_1_ = 3;
      local_12e8 = local_135c;
      if ((int)local_135c < (int)(local_135c + 0x40)) {
        local_12e0 = (float *)0xc8;
        pfVar9 = local_1330 + 0x40;
        do {
          local_12d0 = local_1330;
          if ((int)local_1330 < (int)pfVar9) {
            do {
              fVar29 = (float10)WorldInfo_sampleTerrainHeight();
              local_12d4 = (float *)(float)fVar29;
              local_12f4 = (float *)(1.0 - (float)local_12d4 * 50.0);
              if (0.0 <= (float)local_12f4) {
                fVar29 = (float10)Terrain_sampleHeightAtWorldXY(local_12e8,local_12d0);
                local_12d4 = (float *)(float)fVar29;
                if ((float)local_12d4 <= 0.95) {
                  fVar29 = (float10)terrain_generateColumnColor();
                  local_1308 = (float)fVar29;
                  if (local_1308 < 0.0) {
                    local_1308 = 0.0;
                  }
                  local_12d4 = (float *)(((int)local_1308 / 5) * 5);
                  fVar31 = (float)(int)local_12d4;
                  fVar30 = (local_1308 - fVar31) / 5.0;
                  if (0.5 <= fVar30) {
                    local_12f0 = (float *)(1.0 - (fVar30 - 0.5) * 4.0);
                    if ((float)local_12f0 < 0.0) {
                      local_12f0 = (float *)(((float)local_12f0 + 1.0) * ((float)local_12f0 + 1.0) -
                                            1.0);
                    }
                  }
                  else {
                    local_12f0 = (float *)(fVar30 * 2.0);
                  }
                  local_12fc = local_12d4;
                  if ((float)local_12f0 < 0.0) {
                    local_12fc = (float *)(int)(fVar31 - (float)local_12f0 * 5.0);
                  }
                  local_12dc = (float *)(int)((fVar31 - (float)local_12f0 * 5.0) + 2.0);
                  if ((int)local_12dc <= (int)local_12d4) {
                    do {
                      iVar26 = world_getColumnData(local_12e8,local_12d0,local_12dc,uVar5);
                      if ((*(byte *)(iVar26 + 3) & 0x40) == 0) {
                        fVar30 = 1.0 - (float)local_12f0;
                        local_200 = 0;
                        uStack_1fc = 0;
                        local_218 = 0;
                        uStack_214 = 0;
                        local_1f8 = 0;
                        local_94 = CONCAT44(fVar30 * 0.0,fVar30 * 0.0);
                        local_210 = 0x437f0000;
                        local_8c = fVar30 * 255.0;
                        local_164 = (float)local_12f0 * 0.0;
                        local_118 = CONCAT44(fVar30 * 0.0 + (float)local_12f0 * 0.0,
                                             fVar30 * 0.0 + (float)local_12f0 * 0.0);
                        local_16c = CONCAT44((float)local_12f0 * 0.0,(float)local_12f0 * 0.0);
                        local_110 = local_8c + local_164;
                        iVar26 = 0;
                        do {
                          iVar22 = iVar26 + 1;
                          *(char *)((int)&local_141c + iVar26) =
                               (char)(int)*(float *)((int)&local_118 + iVar26 * 4);
                          iVar26 = iVar22;
                        } while (iVar22 < 3);
                        local_1400 = local_141c;
                        local_13fe = local_141a;
                        local_13fd = 2;
                        tilemap_writeGlyphColumn(local_12e8,local_12d0,local_12dc,&local_1400,uVar5);
                      }
                      local_12dc = (float *)((int)local_12dc + 1);
                    } while ((int)local_12dc <= (int)local_12d4);
                  }
                  if ((((int)local_12d4 <= (int)local_12fc) &&
                      (iVar26 = world_getColumnData(local_12e8,local_12d0,local_12fc,uVar5),
                      (*(byte *)(iVar26 + 3) & 0x1f) != 2)) &&
                     (iVar26 = world_getColumnData(local_12e8,local_12d0,local_12fc,uVar5),
                     (*(byte *)(iVar26 + 3) & 0x40) == 0)) {
                    iVar22 = vec3_store4(local_714,local_12e8,local_12d0,local_12fc,uVar5);
                    iVar26 = 0;
                    do {
                      iVar23 = iVar26 + 1;
                      *(char *)((int)&local_13d8 + iVar26) =
                           (char)(int)*(float *)(iVar22 + iVar26 * 4);
                      iVar26 = iVar23;
                    } while (iVar23 < 3);
                    local_1418 = local_13d8;
                    local_1416 = local_13d6;
                    local_1415 = 3;
                    tilemap_writeGlyphColumn(local_12e8,local_12d0,local_12fc,&local_1418,uVar5);
                    iVar26 = rand();
                    if (iVar26 % (int)local_12e0 == 0) {
                      local_2c0 = local_12e8;
                      local_2bc = local_12d0;
                      local_2b8 = local_12fc;
                      iVar26 = allocObjectWithVec3();
                      if (local_13ac._4_4_ == 0xccccccb) goto LAB_005e9764;
                      *(int *)((int)(float *)local_13ac + 4) = iVar26;
                      local_13ac = (double)CONCAT44(local_13ac._4_4_ + 1,(float *)local_13ac);
                      **(int **)(iVar26 + 4) = iVar26;
                    }
                  }
                  fVar30 = 1.0 - (float)local_12f4;
                  local_12f4 = (float *)(1.0 - fVar30 * fVar30 * fVar30);
                  fVar29 = (float10)perlinNoise2D_cosInterp((double)(int)local_12e8 * 0.02 + 55432.0,
                                                 (double)(int)local_12d0 * 0.02 + 974.0);
                  local_12f0 = (float *)((int)local_12fc + 1);
                  local_12d4 = (float *)(int)(((float)fVar29 + 1.0) * 2.0 +
                                             (float)local_12f4 * 5.0 + local_1308);
                  if ((int)local_12f0 < (int)local_12d4) {
                    do {
                      iVar26 = world_getColumnData(local_12e8,local_12d0,local_12f0,uVar5);
                      if ((*(byte *)(iVar26 + 3) & 0x40) == 0) {
                        tilemap_writeGlyphColumn(local_12e8,local_12d0,local_12f0,&DAT_0076ddf8,uVar5);
                      }
                      local_12f0 = (float *)((int)local_12f0 + 1);
                    } while ((int)local_12f0 < (int)local_12d4);
                  }
                }
              }
              local_12d0 = (float *)((int)local_12d0 + 1);
              pfVar9 = local_1330 + 0x40;
            } while ((int)local_12d0 < (int)pfVar9);
          }
          local_12e8 = (float *)((int)local_12e8 + 1);
        } while ((int)local_12e8 < (int)local_1374);
      }
      if (*(char *)((int)local_1348 + 0x18 + local_1380) == '\x03') {
        World_populateRegionDecorations(uVar5,local_1380,local_135c + 8,local_1330 + 8,
                     *(undefined1 *)((int)local_1348 + 0x19 + local_1380));
      }
      if (*(char *)((int)local_1348 + 0x18 + local_1380) == '\x05') {
        World_populateRegionDecorations(uVar5,local_1380,local_135c + 8,local_1330 + 8,3);
      }
      pfVar9 = (float *)*(float *)local_13ac;
      local_12d4 = pfVar9;
      if (pfVar9 != (float *)local_13ac) {
        do {
          local_12e0 = (float *)pfVar9[2];
          local_12d0 = (float *)pfVar9[3];
          local_12f4 = (float *)pfVar9[4];
          local_12d4 = pfVar9;
          iVar26 = rand();
          local_133c = (float *)(iVar26 % 3 + 2);
          iVar26 = rand();
          local_132c = (float *)(iVar26 % 3 + 2);
          iVar26 = rand();
          local_136c = (byte *)(iVar26 % 3 + 2);
          pfVar24 = (float *)((int)local_12e0 - (int)local_133c);
          local_1358 = (double)CONCAT44((int)local_133c + (int)local_12e0,(undefined4)local_1358);
          local_1318 = pfVar24;
          if ((int)pfVar24 <= (int)local_133c + (int)local_12e0) {
            local_134c = (float *)((int)local_12d0 - (int)local_132c);
            local_12f8 = (float *)((int)pfVar24 - (int)local_12e0);
            local_12e0 = (float *)((int)local_132c + (int)local_12d0);
            do {
              uVar21 = local_130c;
              local_12dc = local_134c;
              if ((int)local_134c <= (int)local_12e0) {
                local_12fc = (float *)((int)local_12f4 + (int)local_136c * -2);
                local_1338 = (float *)((int)local_136c * 2 + (int)local_12f4);
                local_1308 = (float)((int)local_134c - (int)local_12d0);
                local_1318 = pfVar24;
                do {
                  local_12d8 = local_1338;
                  if ((int)local_12fc <= (int)local_1338) {
                    fVar29 = (float10)perlinNoise2D_cosInterp((double)(int)pfVar24 * 0.05,
                                                   (double)(int)local_12dc * 0.05);
                    local_15ac = (float)(int)local_12f8 / (float)(int)local_133c;
                    local_15a8 = (float)(int)local_1308 / (float)(int)local_132c;
                    pfVar34 = (float *)((float)fVar29 * 0.8);
                    pfVar36 = (float *)(float)(int)local_136c;
                    local_12e8 = (float *)(local_15a8 * local_15a8 + local_15ac * local_15ac);
                    local_12f0 = (float *)((int)local_12d8 - (int)local_12f4);
                    pfVar9 = local_12fc;
                    local_1364 = pfVar34;
                    local_1324 = pfVar36;
                    pfVar33 = local_12e8;
                    do {
                      fVar30 = (float)(int)local_12f0 / (float)pfVar36 + (float)pfVar34;
                      if (fVar30 * fVar30 + (float)pfVar33 <= 1.0) {
                        iVar26 = world_getColumnData(local_1318,local_12dc,local_12d8,uVar21);
                        pfVar9 = local_12fc;
                        pfVar34 = local_1364;
                        pfVar36 = local_1324;
                        pfVar33 = local_12e8;
                        if (((~(*(byte *)(iVar26 + 3) >> 7) & 1) != 0) &&
                           ((*(byte *)(iVar26 + 3) & 0x40) == 0)) {
                          iVar22 = vec3_store4(local_72c,local_1318,local_12dc,local_12d8,uVar21);
                          iVar26 = 0;
                          do {
                            iVar23 = iVar26 + 1;
                            *(char *)((int)&local_142c + iVar26) =
                                 (char)(int)*(float *)(iVar22 + iVar26 * 4);
                            iVar26 = iVar23;
                          } while (iVar23 < 3);
                          local_1428 = local_142c;
                          local_1426 = local_142a;
                          local_1425 = 6;
                          tilemap_writeGlyphColumn(local_1318,local_12dc,local_12d8,&local_1428,uVar21);
                          pfVar9 = local_12fc;
                          pfVar34 = local_1364;
                          pfVar36 = local_1324;
                          pfVar33 = local_12e8;
                        }
                      }
                      local_12d8 = (float *)((int)local_12d8 - 1);
                      local_12f0 = (float *)((int)local_12f0 - 1);
                      pfVar24 = local_1318;
                    } while ((int)pfVar9 <= (int)local_12d8);
                  }
                  local_1308 = (float)((int)local_1308 + 1);
                  local_12dc = (float *)((int)local_12dc + 1);
                  uVar5 = uVar21;
                } while ((int)local_12dc <= (int)local_12e0);
              }
              pfVar24 = (float *)((int)pfVar24 + 1);
              local_12f8 = (float *)((int)local_12f8 + 1);
              pfVar9 = local_12d4;
              local_1318 = pfVar24;
            } while ((int)pfVar24 <= (int)local_1358._4_4_);
          }
          pfVar9 = (float *)*pfVar9;
          local_12d4 = pfVar9;
        } while (pfVar9 != (float *)local_13ac);
      }
      pfVar9 = (float *)*local_13c8;
      local_12e8 = pfVar9;
      if (pfVar9 != local_13c8) {
        do {
          local_1358 = (double)CONCAT44(pfVar9[2],(undefined4)local_1358);
          local_1308 = pfVar9[3];
          local_132c = (float *)pfVar9[4];
          local_12e8 = pfVar9;
          uVar21 = rand();
          uVar21 = uVar21 & 0x80000003;
          if ((int)uVar21 < 0) {
            uVar21 = (uVar21 - 1 | 0xfffffffc) + 1;
          }
          local_12e0 = (float *)(uVar21 + 4);
          uVar21 = rand();
          uVar21 = uVar21 & 0x80000003;
          if ((int)uVar21 < 0) {
            uVar21 = (uVar21 - 1 | 0xfffffffc) + 1;
          }
          local_12f4 = (float *)(uVar21 + 4);
          iVar26 = rand();
          local_12d4 = (float *)(iVar26 % 6 + 4);
          iVar26 = (int)local_1358._4_4_;
          pfVar24 = (float *)((int)local_1358._4_4_ - (int)local_12e0);
          local_1344 = (double)CONCAT44((int)local_12e0 + (int)local_1358._4_4_,
                                        (undefined4)local_1344);
          local_1318 = pfVar24;
          if ((int)pfVar24 <= (int)local_12e0 + (int)local_1358._4_4_) {
            local_12d0 = (float *)((int)local_12f4 + (int)local_1308);
            local_1358 = (double)CONCAT44((int)local_1308 - (int)local_12f4,(undefined4)local_1358);
            local_12f0 = (float *)((int)pfVar24 - iVar26);
            do {
              uVar21 = local_130c;
              local_12dc = local_1358._4_4_;
              if ((int)local_1358._4_4_ <= (int)local_12d0) {
                local_12f8 = (float *)((int)local_132c + (int)local_12d4 * -2);
                local_1338 = (float *)((int)local_12d4 * 2 + (int)local_132c);
                local_1364 = (float *)((int)local_1358._4_4_ - (int)local_1308);
                local_1318 = pfVar24;
                do {
                  local_12fc = local_1338;
                  if ((int)local_12f8 <= (int)local_1338) {
                    fVar29 = (float10)perlinNoise2D_cosInterp((double)(int)pfVar24 * 0.05,
                                                   (double)(int)local_12dc * 0.05);
                    local_134c = (float *)(float)fVar29;
                    local_15a0 = (float)(int)local_12f0 / (float)(int)local_12e0;
                    local_159c = (float)(int)local_1364 / (float)(int)local_12f4;
                    pbVar35 = (byte *)((float)local_134c * 0.8);
                    pfVar34 = (float *)(float)(int)local_12d4;
                    local_133c = (float *)(local_159c * local_159c + local_15a0 * local_15a0);
                    local_1324 = (float *)((int)local_12fc - (int)local_132c);
                    pfVar9 = local_12f8;
                    local_136c = pbVar35;
                    local_12d8 = pfVar34;
                    pfVar36 = local_133c;
                    do {
                      fVar30 = (float)(int)local_1324 / (float)pfVar34 + (float)pbVar35;
                      if ((fVar30 * fVar30 + (float)pfVar36 <= 1.0) &&
                         (iVar26 = world_getColumnData(local_1318,local_12dc,local_12fc,uVar21),
                         pfVar9 = local_12f8, pbVar35 = local_136c, pfVar34 = local_12d8,
                         pfVar36 = local_133c, (~(*(byte *)(iVar26 + 3) >> 7) & 1) != 0)) {
                        iVar22 = vec3_store4(local_744,local_1318,local_12dc,local_12fc,uVar21);
                        iVar26 = 0;
                        do {
                          iVar23 = iVar26 + 1;
                          *(char *)((int)&local_13e8 + iVar26) =
                               (char)(int)*(float *)(iVar22 + iVar26 * 4);
                          iVar26 = iVar23;
                        } while (iVar23 < 3);
                        local_1430 = local_13e8;
                        local_142e = local_13e6;
                        local_142d = 0x26;
                        tilemap_writeGlyphColumn(local_1318,local_12dc,local_12fc,&local_1430,uVar21);
                        pfVar9 = local_12f8;
                        pbVar35 = local_136c;
                        pfVar34 = local_12d8;
                        pfVar36 = local_133c;
                      }
                      local_12fc = (float *)((int)local_12fc - 1);
                      local_1324 = (float *)((int)local_1324 - 1);
                      pfVar24 = local_1318;
                    } while ((int)pfVar9 <= (int)local_12fc);
                  }
                  local_1364 = (float *)((int)local_1364 + 1);
                  local_12dc = (float *)((int)local_12dc + 1);
                  uVar5 = uVar21;
                } while ((int)local_12dc <= (int)local_12d0);
              }
              pfVar24 = (float *)((int)pfVar24 + 1);
              local_12f0 = (float *)((int)local_12f0 + 1);
              pfVar9 = local_12e8;
              local_1318 = pfVar24;
            } while ((int)pfVar24 <= (int)local_1344._4_4_);
          }
          pfVar9 = (float *)*pfVar9;
          local_12e8 = pfVar9;
        } while (pfVar9 != local_13c8);
      }
      iVar26 = local_12e4;
      if ((((*(int *)(local_12e4 + 0xa4) == 0) &&
           (local_1360 ==
            (float)((int)((int)*(float *)(local_12e4 + 0x8000f0) +
                         ((int)*(float *)(local_12e4 + 0x8000f0) >> 0x1f & 0xffU)) >> 8))) &&
          (local_1368 ==
           (int)((int)*(float *)(local_12e4 + 0x8000f4) +
                ((int)*(float *)(local_12e4 + 0x8000f4) >> 0x1f & 0xffU)) >> 8)) &&
         (iVar22 = world_getChunkCell256(), iVar22 != 0)) {
        local_2ac = *(int *)(iVar22 + 0x1c) + *(int *)(iVar22 + 0x10);
        local_1344 = (double)CONCAT44(local_2ac,(undefined4)local_1344);
        if ((int)(*(int *)(iVar26 + 0x24) - *(int *)(iVar26 + 0x20) & 0xfffffffcU) < 0x212d) {
          local_1308 = 0.0;
        }
        else {
          local_1308 = *(float *)(*(int *)(iVar26 + 0x20) + 0x212c);
        }
        local_1520[0] = 0.0;
        local_1520[1] = 0.0;
        local_1520[2] = 0.0;
        local_1520[3] = 0.0;
        iVar22 = 0;
        do {
          iVar23 = iVar22 + 4;
          *(int *)((int)local_1668 + iVar22) = (int)*(float *)((int)local_1520 + iVar22);
          iVar22 = iVar23;
        } while (iVar23 < 0x10);
        local_2b4 = (int)*(float *)(iVar26 + 0x8000f0) - *(int *)((int)local_1308 + 0x44) / 2;
        local_2b0 = (int)*(float *)(iVar26 + 0x8000f4) - *(int *)((int)local_1308 + 0x48) / 2;
        WorldInfo_placeStructure(local_1308,&local_2b4,0,6,0,uVar5,1,local_1668);
      }
      local_1364 = (float *)(local_1368 + (int)local_1360 & 0x80000001);
      if ((int)local_1364 < 0) {
        local_1364 = (float *)(((int)local_1364 - 1U | 0xfffffffe) + 1);
      }
      if (local_1364 != (float *)0x0) {
        local_133c = (float *)0x0;
        uVar37 = float_to_uint64_round();
        do {
          local_12e0 = (float *)((ulonglong)uVar37 >> 0x20);
          local_12d4 = (float *)uVar37;
          local_14e4 = 0;
          iVar22 = rand();
          uVar21 = (int)local_1330 + iVar22 % 0xa0 + 0x30;
          local_132c = (float *)((int)(uVar21 * 0x10000) - (int)local_12d4);
          local_12f4 = (float *)(((((int)uVar21 >> 0x1f) << 0x10 | uVar21 >> 0x10) - (int)local_12e0
                                 ) - (uint)((float *)(uVar21 * 0x10000) < local_12d4));
          iVar22 = rand();
          uVar21 = (int)local_135c + iVar22 % 0xa0 + 0x30;
          local_1338 = (float *)((int)(uVar21 * 0x10000) - (int)local_12d4);
          local_1c0 = ((((int)uVar21 >> 0x1f) << 0x10 | uVar21 >> 0x10) - (int)local_12e0) -
                      (uint)((float *)(uVar21 * 0x10000) < local_12d4);
          local_1bc = local_132c;
          local_1b8 = local_12f4;
          local_1b4 = (int)local_14e4;
          local_1358 = (double)CONCAT44(local_1c0,(undefined4)local_1358);
          local_1b0 = local_14e4._4_4_;
          local_1c4 = local_1338;
          if ((local_1304[6] == 1.4013e-45) || (local_1304[6] == 7.00649e-45)) {
            fVar29 = (float10)vec3_distanceSquared(&local_1c4,&local_1bc);
            local_1344 = (double)CONCAT44((float)fVar29,(undefined4)local_1344);
            fVar30 = 1.0 - (float)fVar29;
            if ((fVar30 <= 0.0) || (fVar30 * fVar30 <= 0.0)) goto LAB_005e8eda;
          }
          else {
LAB_005e8eda:
            __alldiv(local_132c,local_12f4,0x10000,0);
            __alldiv(local_1338,local_1358._4_4_,0x10000,0);
            iVar22 = world_getChunkCell256();
            if (iVar22 != 0) {
              uVar21 = *(int *)(iVar22 + 0x1c) + *(int *)(iVar22 + 0x10);
              local_1b0 = ((int)uVar21 >> 0x1f) << 0x10 | uVar21 >> 0x10;
              local_1b4 = uVar21 * 0x10000;
            }
            cVar2 = Region_scatterProps(uVar5,&local_1c4);
            puVar15 = local_137c;
            if (cVar2 != '\0') {
              iVar22 = Map_InsertVec6();
              puVar15[1] = iVar22;
              local_1378 = 1;
              **(int **)(iVar22 + 4) = iVar22;
              break;
            }
          }
          uVar37 = CONCAT44(local_12e0,local_12d4);
          local_133c = (float *)((int)local_133c + 1);
        } while ((int)local_133c < 10);
      }
      cVar2 = *(char *)((int)local_1348 + 0x18 + local_1380);
      if (((cVar2 != '\x04') && (cVar2 != '\x01')) && (cVar2 != '\x03')) {
        iVar22 = rand();
        local_1324 = (float *)(iVar22 % 10);
        if (((0.6 < (float)local_1314) || ((float)local_1314 < 0.3)) &&
           ((0.7 < (float)local_1300 ||
            (((float)local_1300 < 0.4 && ((0.2 < (float)local_1300 || ((float)local_1314 < 0.8))))))
           )) {
          local_1324 = (float *)((int)local_1324 + 10);
        }
        if (0 < (int)local_1324) {
          local_1344 = (double)CONCAT44((int)local_1360 << 7,(undefined4)local_1344);
          local_1358 = (double)CONCAT44(local_1368 << 7,(undefined4)local_1358);
          do {
            uVar5 = rand();
            uVar5 = uVar5 & 0x80000007;
            if ((int)uVar5 < 0) {
              uVar5 = (uVar5 - 1 | 0xfffffff8) + 1;
            }
            local_1300 = (float *)(uVar5 + 3);
            uVar21 = rand();
            uVar21 = uVar21 & 0x80000007;
            if ((int)uVar21 < 0) {
              uVar21 = (uVar21 - 1 | 0xfffffff8) + 1;
            }
            local_12f0 = (float *)(uVar21 + 3);
            uVar21 = rand();
            uVar21 = uVar21 & 0x80000007;
            if ((int)uVar21 < 0) {
              uVar21 = (uVar21 - 1 | 0xfffffff8) + 1;
            }
            local_12d4 = (float *)(uVar21 + 3);
            iVar23 = 0x40 - (int)local_12f0;
            iVar26 = rand();
            local_12f8 = (float *)(iVar26 % ((0x40 - (int)(uVar5 + 3)) * 4) +
                                  ((int)local_1344._4_4_ + (int)local_1300) * 2);
            iVar22 = rand();
            iVar26 = local_12e4;
            local_1710 = (float)(int)local_12f8 - *(float *)(local_12e4 + 0x8000f0);
            local_12fc = (float *)(iVar22 % (iVar23 * 4) +
                                  ((int)local_1358._4_4_ + (int)local_12f0) * 2);
            fVar30 = (float)(int)local_12fc - *(float *)(local_12e4 + 0x8000f4);
            if (400.0 <= fVar30 * fVar30 + local_1710 * local_1710) {
              puVar15 = (undefined4 *)*local_137c;
              if (puVar15 != local_137c) {
                local_1338 = (float *)(((int)local_12fc >> 0x1f) << 0x10 | (uint)local_12fc >> 0x10)
                ;
                local_12f4 = (float *)(((int)local_12f8 >> 0x1f) << 0x10 | (uint)local_12f8 >> 0x10)
                ;
                local_12e0 = (float *)((int)local_12f8 * 0x10000);
                do {
                  local_13c0 = (double)CONCAT44((int)local_1338 +
                                                (-(uint)((uint)((int)local_12fc * 0x10000) <
                                                        (uint)puVar15[4]) - puVar15[5]),
                                                (int)local_12fc * 0x10000 - puVar15[4]);
                  local_13b8 = (double)CONCAT44((int)local_12f4 +
                                                (-(uint)(local_12e0 < (float *)puVar15[2]) -
                                                puVar15[3]),(int)local_12e0 - puVar15[2]);
                  local_134c = (float *)(float)(longlong)local_13b8;
                  local_15e0 = (float)local_134c * 1.5258789e-05;
                  if ((float)(longlong)local_13c0 * 1.5258789e-05 *
                      (float)(longlong)local_13c0 * 1.5258789e-05 + local_15e0 * local_15e0 < 1600.0
                     ) goto LAB_005e9649;
                  puVar15 = (undefined4 *)*puVar15;
                } while (puVar15 != local_137c);
              }
              fVar29 = (float10)Terrain_sampleHeightAtWorldXY(local_12f8,local_12fc);
              uVar5 = local_130c;
              local_1338 = (float *)(float)fVar29;
              if ((float)local_1338 <= 0.25) {
                local_134c = (float *)world_getChunkCell256();
                local_12d8 = (float *)((int)local_134c[7] + (int)local_134c[4]);
                pfVar9 = (float *)((int)local_134c[7] - 1);
                local_1338 = pfVar9;
                for (; -1 < (int)pfVar9; pfVar9 = (float *)((int)pfVar9 - 1)) {
                  iVar26 = VoxelColumn_at();
                  uVar5 = local_130c;
                  if (((*(byte *)(iVar26 + 3) & 0x1f) != 0) && ((*(byte *)(iVar26 + 3) & 0x1f) != 2)
                     ) break;
                  local_12d8 = (float *)((int)local_12d8 - 1);
                }
                iVar26 = world_getColumnData(local_12f8,local_12fc,(int)local_12d8 - 1,uVar5);
                bVar3 = *(byte *)(iVar26 + 3) & 0x1f;
                iVar26 = local_12e4;
                if ((((bVar3 != 0xb) && (bVar3 != 8)) && (bVar3 != 7)) &&
                   (iVar22 = world_getColumnData(local_12f8,local_12fc,(int)local_12d8 - 1,uVar5),
                   iVar26 = local_12e4, (*(byte *)(iVar22 + 3) & 0x40) == 0)) {
                  pfVar9 = (float *)((int)local_12f8 - (int)local_1300);
                  local_136c = (byte *)((int)local_1300 + (int)local_12f8);
                  local_1318 = pfVar9;
                  if ((int)pfVar9 <= (int)local_136c) {
                    local_1338 = (float *)((int)local_12fc - (int)local_12f0);
                    local_133c = (float *)((int)local_12f0 + (int)local_12fc);
                    local_12e8 = (float *)((int)pfVar9 - (int)local_12f8);
                    do {
                      uVar5 = local_130c;
                      local_12dc = local_1338;
                      if ((int)local_1338 <= (int)local_133c) {
                        local_12f8 = (float *)((int)local_12d8 + (int)local_12d4 * -2);
                        local_134c = (float *)((int)local_12d4 * 2 + (int)local_12d8);
                        local_1308 = (float)((int)local_1338 - (int)local_12fc);
                        local_1318 = pfVar9;
                        do {
                          local_12d0 = local_134c;
                          if ((int)local_12f8 <= (int)local_134c) {
                            fVar29 = (float10)perlinNoise2D_cosInterp((double)(int)pfVar9 * 0.05);
                            local_1594 = (float)(int)local_12e8 / (float)(int)local_1300;
                            local_1590 = (float)(int)local_1308 / (float)(int)local_12f0;
                            pfVar34 = (float *)((float)fVar29 * 0.8);
                            pfVar36 = (float *)(float)(int)local_12d4;
                            local_12e0 = (float *)(local_1590 * local_1590 + local_1594 * local_1594
                                                  );
                            local_1314 = (float *)((int)local_12d0 - (int)local_12d8);
                            pfVar24 = local_12f8;
                            local_132c = pfVar36;
                            local_12f4 = pfVar34;
                            pfVar33 = local_12e0;
                            do {
                              fVar30 = (float)(int)local_1314 / (float)pfVar36 + (float)pfVar34;
                              if ((fVar30 * fVar30 + (float)pfVar33 <= 1.0) &&
                                 (iVar26 = world_getColumnData(local_1318,local_12dc,local_12d0,uVar5),
                                 pfVar24 = local_12f8, pfVar34 = local_12f4, pfVar36 = local_132c,
                                 pfVar33 = local_12e0, (*(byte *)(iVar26 + 3) & 0x40) == 0)) {
                                iVar22 = vec3_store4(local_75c,local_1318,local_12dc,local_12d0,
                                                      uVar5);
                                iVar26 = 0;
                                do {
                                  iVar23 = iVar26 + 1;
                                  *(char *)((int)&local_131c + iVar26) =
                                       (char)(int)*(float *)(iVar22 + iVar26 * 4);
                                  iVar26 = iVar23;
                                } while (iVar23 < 3);
                                local_13f4 = (undefined2)local_131c;
                                local_13f2 = local_131c._2_1_;
                                local_13f1 = 0x26;
                                tilemap_writeGlyphColumn(local_1318,local_12dc,local_12d0,&local_13f4,uVar5);
                                pfVar24 = local_12f8;
                                pfVar34 = local_12f4;
                                pfVar36 = local_132c;
                                pfVar33 = local_12e0;
                              }
                              local_12d0 = (float *)((int)local_12d0 - 1);
                              local_1314 = (float *)((int)local_1314 + -1);
                              pfVar9 = local_1318;
                            } while ((int)pfVar24 <= (int)local_12d0);
                          }
                          local_1308 = (float)((int)local_1308 + 1);
                          local_12dc = (float *)((int)local_12dc + 1);
                        } while ((int)local_12dc <= (int)local_133c);
                      }
                      pfVar9 = (float *)((int)pfVar9 + 1);
                      local_12e8 = (float *)((int)local_12e8 + 1);
                      iVar26 = local_12e4;
                      local_1318 = pfVar9;
                    } while ((int)pfVar9 <= (int)local_136c);
                  }
                }
              }
            }
LAB_005e9649:
            local_1324 = (float *)((int)local_1324 - 1);
          } while (local_1324 != (float *)0x0);
        }
      }
      uVar5 = local_130c;
      if ((local_1304[6] == 1.4013e-45) || (local_1304[6] == 7.00649e-45)) {
        Chunk_generateObjects(local_130c);
      }
      if (*(char *)((int)local_1348 + 0x18 + local_1380) == '\x04') {
        pfStack_238 = local_138c;
        local_23c = local_1390;
        iVar26 = world_getChunkCell256();
        local_234 = *(int *)(iVar26 + 0x10) + *(int *)(iVar26 + 0x1c);
        local_132c = (float *)(((int)local_1390 >> 0x1f) << 0x10 | (uint)local_1390 >> 0x10);
        local_1308 = (float)((int)local_1390 << 0x10);
        local_133c = (float *)(((int)local_138c >> 0x1f) << 0x10 | (uint)local_138c >> 0x10);
        local_1324 = (float *)((int)local_138c << 0x10);
        local_12f0 = (float *)(((int)local_234 >> 0x1f) << 0x10 | local_234 >> 0x10);
        local_1348 = (float)(local_234 * 0x10000);
        local_324 = local_1308;
        local_320 = local_132c;
        local_31c = local_1324;
        local_318 = local_133c;
        local_314 = local_1348;
        local_310 = local_12f0;
        iVar26 = Map_InsertVec6();
        if (local_1378 == 0x7fffffe) {
LAB_005e9764:
          std::_Xlength_error("list<T> too long");
        }
        local_1378 = local_1378 + 1;
        local_137c[1] = iVar26;
        **(int **)(iVar26 + 4) = iVar26;
        iVar26 = rand();
        local_12f4 = (float *)(iVar26 % 3 + 6);
        if (0 < (int)local_12f4) {
          local_13c0 = (double)(int)local_12f4;
          local_12e0 = (float *)0x0;
          do {
            fVar30 = (float)(((double)(int)local_12e0 * 3.141592653589793) / local_13c0);
            dVar32 = (double)fVar30;
            local_1344._4_4_ = (float *)fVar30;
            libm_sse2_sin_precise();
            local_1358 = (double)CONCAT44((float)dVar32,(undefined4)local_1358);
            dVar32 = (double)(float)local_1344._4_4_;
            libm_sse2_cos_precise();
            local_1344 = (double)CONCAT44(local_234,(undefined4)local_1344);
            local_34 = local_234;
            local_4ac = (int)((float)dVar32 * 25.0);
            local_4a8 = (int)((float)local_1358._4_4_ * 25.0);
            local_3c = (int)local_23c + local_4ac;
            iStack_38 = (int)pfStack_238 + local_4a8;
            iVar26 = world_getChunkCell256();
            if (iVar26 == 0) {
              iVar26 = (int)local_1344._4_4_;
            }
            else {
              iVar26 = *(int *)(iVar26 + 0x1c) + *(int *)(iVar26 + 0x10);
            }
            local_34 = iVar26 + 4;
            uVar5 = rand();
            uVar5 = uVar5 & 0x80000003;
            if ((int)uVar5 < 0) {
              uVar5 = (uVar5 - 1 | 0xfffffffc) + 1;
            }
            local_12d4 = (float *)(uVar5 + 3);
            uVar5 = rand();
            uVar5 = uVar5 & 0x80000003;
            if ((int)uVar5 < 0) {
              uVar5 = (uVar5 - 1 | 0xfffffffc) + 1;
            }
            local_1314 = (float *)((int)local_12d4 * 2);
            local_12fc = (float *)(local_3c + (int)local_12d4 * -2);
            local_1300 = (float *)(uVar5 + 3);
            if ((int)local_12fc <= (int)local_1314 + local_3c) {
              do {
                local_12d8 = (float *)(iStack_38 + (int)local_1300 * -2);
                if ((int)local_12d8 <= iStack_38 + (int)local_1300 * 2) {
                  do {
                    uVar5 = local_130c;
                    local_12f8 = (float *)(local_34 + 0x14);
                    if ((int)(local_34 + -0x14) <= (int)local_12f8) {
                      fVar29 = (float10)perlinNoise2D_cosInterp((double)(int)local_12d8 * 0.05,
                                                     (double)(int)local_12d8 * 0.05);
                      local_1344 = (double)CONCAT44((float)fVar29,(undefined4)local_1344);
                      local_134c = (float *)((float)fVar29 * 0.3);
                      local_136c = (byte *)(float)(int)local_1300;
                      local_13b8 = (double)(int)local_12fc * 0.05;
                      do {
                        local_1338 = (float *)((float)(int)((int)local_12f8 - local_34) / 10.0);
                        local_1358 = (double)CONCAT44((float)((int)local_12d8 - iStack_38) /
                                                      (float)local_136c + (float)local_134c,
                                                      (undefined4)local_1358);
                        fVar29 = (float10)perlinNoise2D_cosInterp(local_13b8,(double)(int)local_12f8 * 0.05);
                        local_1344 = (double)CONCAT44((float)fVar29,(undefined4)local_1344);
                        local_1774 = (float)fVar29 * 0.3 +
                                     (float)((int)local_12fc - local_3c) / (float)(int)local_12d4;
                        if ((local_1774 * local_1774 +
                             (float)local_1358._4_4_ * (float)local_1358._4_4_ +
                             (float)local_1338 * (float)local_1338 <= 1.0) &&
                           (iVar26 = world_getColumnData(local_12fc,local_12d8,local_12f8,uVar5),
                           (*(byte *)(iVar26 + 3) & 0x40) == 0)) {
                          iVar22 = vec3_store4(local_774,local_12fc,local_12d8,local_12f8,uVar5);
                          iVar26 = 0;
                          do {
                            iVar23 = iVar26 + 1;
                            *(char *)((int)&local_12cc + iVar26) =
                                 (char)(int)*(float *)(iVar22 + iVar26 * 4);
                            iVar26 = iVar23;
                          } while (iVar23 < 3);
                          local_13fc = (undefined2)local_12cc;
                          local_13fa = local_12cc._2_1_;
                          local_13f9 = 6;
                          tilemap_writeGlyphColumn(local_12fc,local_12d8,local_12f8,&local_13fc,uVar5);
                        }
                        local_12f8 = (float *)((int)local_12f8 - 1);
                      } while ((int)(local_34 + -0x14) <= (int)local_12f8);
                    }
                    local_12d8 = (float *)((int)local_12d8 + 1);
                  } while ((int)local_12d8 <= iStack_38 + (int)local_1300 * 2);
                }
                local_12fc = (float *)((int)local_12fc + 1);
              } while ((int)local_12fc <= local_3c + (int)local_1314);
            }
            local_12e0 = (float *)((int)local_12e0 + 2);
            local_12f4 = (float *)((int)local_12f4 + -1);
          } while (local_12f4 != (float *)0x0);
        }
        Struct_InitDefaults();
        local_8 = CONCAT31(local_8._1_3_,4);
        local_16b8 = 0;
        local_1548 = float_to_uint64_round();
        iVar26 = local_12e4;
        uVar5 = local_130c;
        local_3b4 = local_132c;
        local_3ac = local_133c;
        local_3a8 = local_1348;
        local_3a4 = local_12f0;
        local_3b8 = local_1308;
        local_3d8 = local_1548 + CONCAT44(local_132c,local_1308);
        local_3b0 = local_1324;
        local_6ec = local_1548 + CONCAT44(local_133c,local_1324);
        local_3c8 = local_1348;
        local_3c4 = local_12f0;
        local_438 = 0;
        lVar38 = local_3d8;
        local_3d0 = local_6ec;
        local_1538 = local_1548;
        local_448 = local_1548;
        local_440 = local_1548;
        while( true ) {
          local_6f4._4_4_ = (float *)((ulonglong)lVar38 >> 0x20);
          local_12d4 = local_6f4._4_4_;
          local_6e4 = local_1348;
          local_6e0 = local_12f0;
          local_6f4 = lVar38;
          iVar22 = world_getColumnAtFixedPos(lVar38,local_6ec,local_1348,local_12f0,uVar5);
          if (((*(byte *)(iVar22 + 3) & 0x1f) != 0) && ((*(byte *)(iVar22 + 3) & 0x1f) != 2)) break;
          local_1348 = (float)((int)local_6e4 + -0x10000);
          local_12f0 = (float *)((int)local_6e0 + ((0xffff < (uint)local_6e4) - 1));
          lVar38 = local_6f4;
        }
        while( true ) {
          iVar22 = world_getColumnAtFixedPos(local_6f4,local_6ec,local_6e4,local_6e0,uVar5);
          if (((*(byte *)(iVar22 + 3) & 0x1f) == 0) || ((*(byte *)(iVar22 + 3) & 0x1f) == 2)) break;
          bVar28 = 0xfffeffff < (uint)local_6e4;
          local_6e4 = (float)((int)local_6e4 + 0x10000);
          local_6e0 = (float *)((int)local_6e0 + (uint)bVar28);
        }
        local_6fc = 0x2d;
        local_6dc = rand();
        local_6dc = local_6dc & 0x80000003;
        if ((int)local_6dc < 0) {
          local_6dc = (local_6dc - 1 | 0xfffffffc) + 1;
        }
        local_6d8 = 0x40800000;
        local_6d4 = 0x40800000;
        local_6d0 = 0x40a00000;
        std_vector_pushBack_0x188();
        local_8._0_1_ = 3;
        if (local_6b4 != (void *)0x0) {
          std::_Container_base0::_Orphan_all((_Container_base0 *)&local_6b4);
          std_vector_destroy_ptr_elems_stride3(local_6b4,local_6b0,&local_130d,local_13b0);
          operator_delete(local_6b4);
        }
      }
      local_132c = local_1330 + 2;
      local_12dc = local_135c;
      local_12f4 = (float *)0xe;
      local_136c = (byte *)0x5;
      do {
        local_12e0 = (float *)0xe;
        local_1318 = local_132c;
        do {
          local_1348 = 0.0;
          if (local_1304[6] == 4.2039e-45) {
            local_14d8 = ((int)local_1318 >> 0x1f) << 0x10 | (uint)local_1318 >> 0x10;
            local_14dc = (int)local_1318 << 0x10;
            pfVar9 = local_12dc + 2;
            local_1488 = (double)CONCAT44(((int)pfVar9 >> 0x1f) << 0x10 | (uint)pfVar9 >> 0x10,
                                          (int)pfVar9 * 0x10000);
            fVar29 = (float10)vec3_distanceSquared(&local_1488,&local_14dc);
            local_1344 = (double)CONCAT44((float)fVar29,(undefined4)local_1344);
            local_1348 = 1.0 - (float)fVar29;
            if (0.0 < local_1348) {
              local_1348 = local_1348 * local_1348;
            }
            else {
              local_1348 = 0.0;
            }
          }
          iVar22 = world_getChunkCell256();
          if (iVar22 == 0) {
            fVar29 = (float10)GameController_sampleTemperatureGrid(local_12dc + 2,local_1318);
            local_12fc = (float *)(float)fVar29;
            local_1344 = (double)CONCAT44(local_12fc,(undefined4)local_1344);
          }
          else {
            local_12fc = *(float **)(iVar22 + 4);
          }
          iVar22 = rand();
          local_12f8 = (float *)(int)((float)(iVar22 % 5) + (float)local_12fc * 2.0 + 6.0 +
                                     local_1348 * 4.0);
          iVar22 = rand();
          local_12e8 = (float *)((int)(local_1318 + -2) + (int)local_12f8);
          local_12f0 = (float *)(int)((((float)iVar22 * 8.0) / 32767.0 + local_1348 * 6.0 + 8.0) *
                                     ((float)local_12fc * 0.5 + 1.0));
          local_12d0 = (float *)((int)local_12dc + (int)local_12f8);
          local_15f0 = (float)(int)local_12d0 - *(float *)(iVar26 + 0x8000f0);
          fVar30 = (float)(int)local_12e8 - *(float *)(iVar26 + 0x8000f4);
          if (400.0 <= fVar30 * fVar30 + local_15f0 * local_15f0) {
            pfVar9 = (float *)((int)local_135c + -((int)local_12f8 / 2) + 0x100);
            if ((int)pfVar9 <= (int)local_12d0) {
              local_12d0 = pfVar9;
            }
            pfVar9 = (float *)((int)local_1330 + -((int)local_12f8 / 2) + 0x100);
            if ((int)pfVar9 <= (int)local_12e8) {
              local_12e8 = pfVar9;
            }
            puVar15 = (undefined4 *)*local_137c;
            if (puVar15 != local_137c) {
              uVar6 = ((int)local_12e8 >> 0x1f) << 0x10 | (uint)local_12e8 >> 0x10;
              uVar21 = (int)local_12e8 * 0x10000;
              local_1344 = (double)CONCAT44(uVar21,(undefined4)local_1344);
              local_1358 = (double)CONCAT44(uVar6,(undefined4)local_1358);
              local_12d4 = (float *)(((int)local_12d0 >> 0x1f) << 0x10 | (uint)local_12d0 >> 0x10);
              local_134c = (float *)((int)local_12d0 * 0x10000);
              do {
                local_13b8 = (double)CONCAT44((uVar6 - puVar15[5]) -
                                              (uint)(uVar21 < (uint)puVar15[4]),uVar21 - puVar15[4])
                ;
                local_13c0 = (double)CONCAT44((int)local_12d4 +
                                              (-(uint)(local_134c < (float *)puVar15[2]) -
                                              puVar15[3]),(int)local_134c - puVar15[2]);
                local_1338 = (float *)(float)(longlong)local_13c0;
                local_1740 = (float)local_1338 * 1.5258789e-05;
                if ((float)(longlong)local_13b8 * 1.5258789e-05 *
                    (float)(longlong)local_13b8 * 1.5258789e-05 + local_1740 * local_1740 < 1600.0)
                goto LAB_005ea7b3;
                puVar15 = (undefined4 *)*puVar15;
              } while (puVar15 != local_137c);
            }
            local_1344 = (double)(int)local_12e8 * 0.001;
            local_1358 = (double)(int)local_12d0 * 0.001;
            fVar29 = (float10)perlinNoise2D_cosInterp((double)*(int *)(iVar26 + 0x800294) + local_1358,
                                           (double)*(int *)(iVar26 + 0x800298) + local_1344);
            local_1300 = (float *)(float)fVar29;
            uVar21 = rand();
            uVar21 = uVar21 & 0x80000001;
            if ((int)uVar21 < 0) {
              uVar21 = (uVar21 - 1 | 0xfffffffe) + 1;
            }
            local_12d8 = (float *)(-(uint)(uVar21 != 0) & 5);
            if ((float)local_1300 <= 0.3) {
              iVar22 = rand();
              if (iVar22 % 10 == 0) {
                local_12d8 = (float *)0x1;
              }
            }
            else {
              iVar22 = rand();
              if (iVar22 % 10 != 0) {
                local_12d8 = (float *)0x1;
              }
            }
            iVar22 = rand();
            if (iVar22 % 10 == 0) {
              local_12d8 = (float *)0x2;
            }
            iVar22 = world_getChunkCell256();
            if (iVar22 == 0) {
              fVar29 = (float10)GameController_sampleHumidityGrid(local_12d0,local_12e8);
              local_12d4 = (float *)(float)fVar29;
              local_1300 = local_12d4;
            }
            else {
              local_12d4 = *(float **)(iVar22 + 8);
            }
            if ((0.8 < (float)local_12d4) && (0.7 < (float)local_12fc)) {
              uVar21 = rand();
              uVar21 = uVar21 & 0x80000001;
              if ((int)uVar21 < 0) {
                uVar21 = (uVar21 - 1 | 0xfffffffe) + 1;
              }
              local_12d8 = (float *)((uVar21 != 0) + 4);
              uVar21 = rand();
              uVar21 = uVar21 & 0x80000003;
              bVar28 = uVar21 == 0;
              if ((int)uVar21 < 0) {
                bVar28 = (uVar21 - 1 | 0xfffffffc) == 0xffffffff;
              }
              if (bVar28) {
                local_12d8 = (float *)0x3;
              }
            }
            if (0.3 <= (float)local_12d4) {
              if ((float)local_12d4 < 0.7) {
                fVar29 = (float10)perlinNoise2D_cosInterp(local_1358 + 8473.0,local_1344 + 9438.0);
                local_1344 = (double)CONCAT44((float)fVar29,(undefined4)local_1344);
                if (0.8 < (float)fVar29) {
                  iVar22 = rand();
                  if (iVar22 % 5 != 0) {
                    local_12d8 = (float *)0x2;
                    goto LAB_005ea527;
                  }
                }
              }
              if (local_12d8 == (float *)0x1) goto LAB_005ea4e2;
              if (local_12d8 == (float *)0x2) {
LAB_005ea527:
                iVar26 = rand();
                local_12f0 = (float *)((int)local_12f0 + iVar26 % ((int)local_12f0 / 2));
                iVar26 = local_12e4;
              }
            }
            else {
              if (0.2 < (float)local_12d4) {
                fVar29 = (float10)perlinNoise2D_cosInterp(local_1358 + 8473.0,local_1344 + 9438.0);
                local_1344 = (double)CONCAT44((float)fVar29,(undefined4)local_1344);
                if (0.6 < (float)fVar29) {
                  iVar22 = rand();
                  if (iVar22 % 5 != 0) {
                    local_12d8 = (float *)0x2;
                    goto LAB_005ea527;
                  }
                }
              }
              local_12d8 = (float *)0x1;
LAB_005ea4e2:
              if ((float)(int)local_12f0 * 0.5 < (float)(int)local_12f8) {
                local_12f8 = (float *)(int)((float)(int)local_12f0 * 0.5);
              }
              if ((int)local_12f8 < 1) {
                local_12f8 = (float *)0x1;
              }
            }
            iVar22 = world_getChunkCell256();
            if (iVar22 == 0) {
              GameController_sampleTemperatureGrid(local_12d0,local_12e8);
            }
            if ((int)local_1374 < (int)local_12d0 + (int)local_12f8) {
              local_12d0 = (float *)((int)local_135c + (0x100 - (int)local_12f8));
            }
            if ((int)(local_1330 + 0x40) < (int)local_12f8 + (int)local_12e8) {
              local_12e8 = (float *)((int)local_1330 + (0x100 - (int)local_12f8));
            }
            fVar29 = (float10)terrainNoiseDensityAt();
            local_1344 = (double)CONCAT44((float)fVar29 + local_1348,(undefined4)local_1344);
            iVar22 = rand();
            if ((float)iVar22 / 32767.0 <= (float)local_1344._4_4_) {
              iVar22 = world_getChunkCell256();
              if (iVar22 != 0) {
                local_12fc = (float *)(*(int *)(iVar22 + 0x1c) + -1 + *(int *)(iVar22 + 0x10));
                while( true ) {
                  iVar22 = world_getColumnData(local_12d0,local_12e8,local_12fc,uVar5);
                  if (((*(byte *)(iVar22 + 3) & 0x1f) != 0) && ((*(byte *)(iVar22 + 3) & 0x1f) != 2)
                     ) break;
                  local_12fc = (float *)((int)local_12fc - 1);
                }
                if (-1 < (int)local_12fc) {
                  iVar22 = world_getColumnData(local_12d0,local_12e8,local_12fc,uVar5);
                  local_12fc = (float *)((int)local_12fc + 1);
                  local_1358 = (double)((ulonglong)
                                        CONCAT14(*(undefined1 *)(iVar22 + 3),(undefined4)local_1358)
                                       & 0xffffff1fffffffff);
                  iVar22 = world_getChunkCell256();
                  if (iVar22 == 0) {
                    fVar29 = (float10)GameController_sampleHumidityGrid(local_12d0,local_12e8);
                    fVar30 = (float)fVar29;
                    local_1344 = (double)CONCAT44(fVar30,(undefined4)local_1344);
                  }
                  else {
                    fVar30 = *(float *)(iVar22 + 8);
                  }
                  if (0.8 < fVar30) {
                    iVar22 = world_getChunkCell256();
                    if (iVar22 == 0) {
                      fVar29 = (float10)GameController_sampleTemperatureGrid(local_12d0,local_12e8);
                      local_1344 = (double)CONCAT44((float)fVar29,(undefined4)local_1344);
                    }
                  }
                  if (((local_1358._4_4_ == (float *)0x4) || (local_1358._4_4_ == (float *)0xa)) ||
                     ((local_1358._4_4_ == (float *)0x9 && ((int)local_12fc < 3)))) {
                    pfVar9 = local_12f8;
                    if ((int)local_12f8 < 1) {
                      pfVar9 = local_1334;
                    }
                    World_generateWaterOrPathFeature(local_12d0,local_12e8,local_12fc,pfVar9);
                  }
                }
              }
            }
          }
LAB_005ea7b3:
          local_1318 = (float *)((int)local_1318 + 0x12);
          local_12e0 = (float *)((int)local_12e0 - 1);
        } while (local_12e0 != (float *)0x0);
        local_12dc = (float *)((int)local_12dc + 0x12);
        local_12f4 = (float *)((int)local_12f4 + -1);
      } while (local_12f4 != (float *)0x0);
      if (local_1364 == (float *)0x0) {
        iVar26 = rand();
        local_1314 = (float *)((int)local_135c + iVar26 % 0xe0 + 0x10);
        iVar26 = rand();
        local_12d4 = (float *)((int)local_1330 + iVar26 % 0xe0 + 0x10);
        iVar26 = world_getChunkCell256();
        if (iVar26 != 0) {
          local_1300 = (float *)(*(int *)(iVar26 + 0x1c) + *(int *)(iVar26 + 0x10));
          while( true ) {
            iVar26 = world_getColumnData(local_1314,local_12d4,local_1300,uVar5);
            pfVar9 = local_1300;
            if (((*(byte *)(iVar26 + 3) & 0x1f) != 0) && ((*(byte *)(iVar26 + 3) & 0x1f) != 2))
            break;
            local_1300 = (float *)((int)local_1300 + -1);
          }
          Struct_InitDefaults();
          uVar5 = (int)pfVar9 + 1;
          local_1550 = (float *)(((int)uVar5 >> 0x1f) << 0x10 | uVar5 >> 0x10);
          local_1554 = (float *)(uVar5 * 0x10000);
          local_1300 = (float *)(((int)local_12d4 >> 0x1f) << 0x10 | (uint)local_12d4 >> 0x10);
          local_8._0_1_ = 5;
          local_988 = 0;
          uVar21 = (int)local_12d4 * 0x10000;
          local_12f4 = local_1550;
          local_12e0 = local_1554;
          uVar37 = float_to_uint64_round();
          iVar26 = (int)((ulonglong)uVar37 >> 0x20);
          uVar5 = (uint)uVar37;
          local_978 = uVar21 - uVar5;
          local_1300 = (float *)(((int)local_1300 - iVar26) - (uint)(uVar21 < uVar5));
          local_980 = (int)local_1314 * 0x10000 - uVar5;
          local_97c = ((((int)local_1314 >> 0x1f) << 0x10 | (uint)local_1314 >> 0x10) - iVar26) -
                      (uint)((uint)((int)local_1314 * 0x10000) < uVar5);
          local_3e0 = local_12e0;
          local_3dc = local_12f4;
          local_970 = local_12e0;
          local_96c = local_12f4;
          local_964 = 0x40000000;
          local_960 = 0x40000000;
          local_95c = 0x41000000;
          local_974 = local_1300;
          local_3f0 = local_980;
          local_3ec = local_97c;
          local_3e8 = local_978;
          local_3e4 = local_1300;
          local_968 = rand();
          uVar5 = local_130c;
          local_968 = local_968 & 0x80000003;
          if ((int)local_968 < 0) {
            local_968 = (local_968 - 1 | 0xfffffffc) + 1;
          }
          std_vector_pushBack_0x188();
          local_8._0_1_ = 3;
          if (local_940 != (void *)0x0) {
            std::_Container_base0::_Orphan_all((_Container_base0 *)&local_940);
            std_vector_destroy_ptr_elems_stride3(local_940,local_93c,&local_1401,local_13b0);
            operator_delete(local_940);
          }
        }
      }
      fVar30 = local_1304[6];
      if ((((fVar30 != 0.0) && (fVar30 != 1.4013e-44)) && (fVar30 != 1.96182e-44)) &&
         ((fVar30 != 1.4013e-45 && (fVar30 != 7.00649e-45)))) {
        local_1448 = (void *)0x0;
        local_1444 = 0;
        local_1440 = 0;
        local_8 = CONCAT31(local_8._1_3_,6);
        local_133c = (float *)0x0;
        local_12f0 = (float *)0x0;
        do {
          local_1364 = (float *)0x0;
          pfVar9 = local_12f0;
          local_132c = local_133c;
          do {
            if ((int)local_132c % (int)local_136c == 0) {
              local_12f4 = pfVar9 + *(int *)(uVar5 + 0x60) * 0x40 + 1;
              local_12e0 = local_1364 + *(int *)(uVar5 + 100) * 0x40 + 1;
              local_1324 = (float *)(((int)local_12e0 >> 0x1f) << 0x10 | (uint)local_12e0 >> 0x10);
              local_1344 = (double)CONCAT44((int)local_12e0 * 0x10000,(undefined4)local_1344);
              local_1468 = (double)CONCAT44(local_1324,(int)local_12e0 * 0x10000);
              local_1308 = (float)(((int)local_12f4 >> 0x1f) << 0x10 | (uint)local_12f4 >> 0x10);
              local_1314 = (float *)((int)local_12f4 * 0x10000);
              local_1478 = (double)CONCAT44(local_1308,local_1314);
              fVar29 = (float10)vec3_distanceSquared(&local_1478,&local_1468);
              local_1334 = (float *)(float)fVar29;
              fVar30 = 1.0 - (float)local_1334;
              if (0.0 < fVar30) {
                local_12d4 = (float *)(fVar30 * fVar30);
              }
              else {
                local_12d4 = (float *)0x0;
              }
              iVar26 = rand();
              pfVar9 = local_12f0;
              if ((float)iVar26 / 32767.0 <= (float)local_12d4 * 0.75) {
                iVar26 = world_getChunkCell256();
                pfVar9 = local_12f0;
                if (iVar26 != 0) {
                  local_1300 = *(float **)(iVar26 + 0x14);
                  while( true ) {
                    iVar26 = world_getColumnData(local_12f4,local_12e0,local_1300,uVar5);
                    if (((*(byte *)(iVar26 + 3) & 0x1f) == 0) ||
                       ((*(byte *)(iVar26 + 3) & 0x1f) == 2)) break;
                    local_1300 = (float *)((int)local_1300 + 1);
                  }
                  uVar5 = ((int)local_1300 >> 0x1f) << 0x10 | (uint)local_1300 >> 0x10;
                  iVar22 = (int)local_1300 << 0x10;
                  local_1564 = iVar22;
                  local_1560 = uVar5;
                  uVar37 = float_to_uint64_round();
                  iVar26 = (int)((ulonglong)uVar37 >> 0x20);
                  pfVar9 = (float *)uVar37;
                  local_334 = (int)local_1344._4_4_ - (int)pfVar9;
                  local_1324 = (float *)((int)local_1324 +
                                        (-(uint)(local_1344._4_4_ < pfVar9) - iVar26));
                  bVar28 = local_1314 < pfVar9;
                  local_1314 = (float *)((int)local_1314 - (int)pfVar9);
                  local_1308 = (float)(((int)local_1308 - iVar26) - (uint)bVar28);
                  local_33c = local_1314;
                  local_338 = local_1308;
                  local_330 = local_1324;
                  local_32c = iVar22;
                  local_328 = uVar5;
                  std_vector_push_back_5bf4f0();
                  pfVar9 = local_12f0;
                }
              }
            }
            uVar5 = local_130c;
            local_1364 = (float *)((int)local_1364 + 0x12);
            local_132c = (float *)((int)local_132c + 3);
          } while ((int)local_1364 < 0xfc);
          local_12f0 = (float *)((int)pfVar9 + 0x12);
          local_133c = (float *)((int)local_133c + 1);
        } while ((int)local_12f0 < 0xfc);
        World_buildPropInstance(local_130c,local_1304,&local_1448);
        local_8._0_1_ = 3;
        if (local_1448 != (void *)0x0) {
          std::_Container_base0::_Orphan_all((_Container_base0 *)&local_1448);
          operator_delete(local_1448);
        }
      }
      if (local_1304[6] == 1.26117e-44) {
        iVar26 = __alldiv(*local_1304,local_1304[1],0x10000,0);
        local_44 = (double)CONCAT44(local_44._4_4_,iVar26);
        iVar22 = __alldiv(local_1304[2],local_1304[3],0x10000,0);
        local_44 = (double)CONCAT44(iVar22,(undefined4)local_44);
        local_188 = (double)CONCAT44((int)(iVar22 + (iVar22 >> 0x1f & 0xffU)) >> 8,
                                     (int)(iVar26 + (iVar26 >> 0x1f & 0xffU)) >> 8);
        iVar26 = 0;
        piVar14 = (int *)(uVar5 + 0x60);
        do {
          if (*(int *)((int)&local_188 + iVar26 * 4) != *piVar14) goto LAB_005eae6a;
          iVar26 = iVar26 + 1;
          piVar14 = piVar14 + 1;
        } while (iVar26 < 2);
        pvVar11 = operator_new(0x10f0);
        if (pvVar11 == (void *)0x0) {
          iVar26 = 0;
        }
        else {
          iVar26 = cube::Spawn::ctor_0();
        }
        *(float *)(iVar26 + 0x10) = *local_1304;
        *(float *)(iVar26 + 0x14) = local_1304[1];
        *(float *)(iVar26 + 0x18) = local_1304[2];
        fVar30 = local_1304[3];
        *(float *)(iVar26 + 0x1c) = fVar30;
        local_13f8 = iVar26;
        __alldiv(*(undefined4 *)(iVar26 + 0x18),fVar30,0x10000,0);
        __alldiv(*(undefined4 *)(iVar26 + 0x10),*(undefined4 *)(iVar26 + 0x14),0x10000,0);
        iVar22 = world_getChunkCell256();
        uVar5 = *(uint *)(iVar22 + 0x10);
        *(uint *)(iVar26 + 0x20) = uVar5 << 0x10;
        *(uint *)(iVar26 + 0x24) = ((int)uVar5 >> 0x1f) << 0x10 | uVar5 >> 0x10;
        *(undefined4 *)(iVar26 + 0x28) = 1;
        *(undefined4 *)(iVar26 + 0x2c) = 0x6b;
        *(float *)(iVar26 + 0x34) = local_1304[9];
        *(undefined1 *)(iVar26 + 0x58) = *(undefined1 *)(local_1304 + 10);
        std_vector_push_back_4byte();
      }
LAB_005eae6a:
      local_1410 = (void *)0x0;
      local_140c = 0;
      local_1408 = 0;
      local_8 = CONCAT31(local_8._1_3_,7);
      local_12d4 = (float *)0x0;
      pcVar27 = (char *)(local_1380 + 0x18);
      do {
        iVar26 = 0;
        pfVar9 = local_12d4;
        do {
          if (*pcVar27 != '\0') {
            local_3a0 = pfVar9 + local_13d4 * 0x10;
            iStack_39c = (int)local_1388 * 0x40 + iVar26;
            local_180 = (double)CONCAT44(iStack_39c,local_3a0);
            iVar23 = (int)local_3a0 - (int)local_1360;
            iVar22 = iStack_39c - local_1368;
            local_30 = (double)CONCAT44(iVar22,iVar23);
            local_398 = iVar22 * iVar22 + iVar23 * iVar23;
            std_vector_push_back_0xc();
            pfVar9 = local_12d4;
          }
          iVar26 = iVar26 + 1;
          pcVar27 = pcVar27 + 0x10;
        } while (iVar26 < 0x40);
        local_12d4 = (float *)((int)pfVar9 + 1);
      } while ((int)local_12d4 < 0x40);
      local_1420 = local_1420 & 0xffffff00;
      introsort_int(local_1410,local_140c,(local_140c - (int)local_1410) / 0xc);
      local_1308 = 0.0;
      do {
        local_1314 = (float *)0x0;
        do {
          pfVar9 = local_1314;
          uVar5 = rand();
          uVar5 = uVar5 & 0x80000003;
          bVar28 = uVar5 == 0;
          if ((int)uVar5 < 0) {
            bVar28 = (uVar5 - 1 | 0xfffffffc) == 0xffffffff;
          }
          uVar5 = local_130c;
          if (!bVar28) {
            iVar26 = rand();
            pfVar24 = (float *)((int)local_135c + (int)local_1308 * 0x55 + 0x18 + iVar26 % 10);
            local_12d0 = pfVar24;
            iVar26 = rand();
            local_12d8 = (float *)((int)local_1330 + (int)pfVar9 * 0x55 + 0x18 + iVar26 % 10);
            if ((local_1304[6] != 0.0) && (local_1304[6] != 1.4013e-44)) {
              local_1470 = (double)CONCAT44(((int)local_12d8 >> 0x1f) << 0x10 |
                                            (uint)local_12d8 >> 0x10,(int)local_12d8 * 0x10000);
              local_1480 = (double)CONCAT44(((int)pfVar24 >> 0x1f) << 0x10 | (uint)pfVar24 >> 0x10,
                                            (int)pfVar24 * 0x10000);
              fVar29 = (float10)vec3_distanceSquared(&local_1480,&local_1470);
              local_1334 = (float *)(float)fVar29;
              fVar30 = 1.0 - (float)local_1334;
              if ((0.0 < fVar30) && (uVar5 = local_130c, 0.3 < fVar30 * fVar30)) goto LAB_005ebba1;
            }
            uVar5 = local_130c;
            iVar26 = world_getChunkCell256();
            if (iVar26 == 0) {
              fVar29 = (float10)GameController_sampleHumidityGrid(local_12d0,local_12d8);
              local_12d4 = (float *)(float)fVar29;
              local_1334 = local_12d4;
            }
            else {
              local_12d4 = *(float **)(iVar26 + 8);
            }
            if ((float)local_12d4 < 0.2) {
              uVar21 = rand();
              uVar21 = uVar21 & 0x80000003;
              bVar28 = uVar21 == 0;
              if ((int)uVar21 < 0) {
                bVar28 = (uVar21 - 1 | 0xfffffffc) == 0xffffffff;
              }
              if (bVar28) goto LAB_005ebba1;
            }
            iVar26 = world_getChunkCell256();
            if (iVar26 == 0) {
              fVar29 = (float10)GameController_sampleTemperatureGrid(local_12d0,local_12d8);
              local_12e0 = (float *)(float)fVar29;
              local_1334 = local_12e0;
            }
            else {
              local_12e0 = *(float **)(iVar26 + 4);
            }
            if ((float)local_12e0 < 0.2) {
              uVar21 = rand();
              uVar21 = uVar21 & 0x80000003;
              bVar28 = uVar21 == 0;
              if ((int)uVar21 < 0) {
                bVar28 = (uVar21 - 1 | 0xfffffffc) == 0xffffffff;
              }
              if (bVar28) goto LAB_005ebba1;
            }
            puVar15 = (undefined4 *)*local_137c;
            if (puVar15 != local_137c) {
              uVar21 = ((int)local_12d8 >> 0x1f) << 0x10 | (uint)local_12d8 >> 0x10;
              local_1334 = (float *)((int)local_12d8 * 0x10000);
              local_1344 = (double)CONCAT44(uVar21,(undefined4)local_1344);
              local_134c = (float *)(((int)local_12d0 >> 0x1f) << 0x10 | (uint)local_12d0 >> 0x10);
              local_1338 = (float *)((int)local_12d0 * 0x10000);
              do {
                local_13b8 = (double)CONCAT44((uVar21 - puVar15[5]) -
                                              (uint)(local_1334 < (float *)puVar15[4]),
                                              (int)local_1334 - puVar15[4]);
                local_13c0 = (double)CONCAT44((int)local_134c +
                                              (-(uint)(local_1338 < (float *)puVar15[2]) -
                                              puVar15[3]),(int)local_1338 - puVar15[2]);
                local_1358 = (double)CONCAT44((float)(longlong)local_13c0,(undefined4)local_1358);
                local_1600 = (float)(longlong)local_13c0 * 1.5258789e-05;
                if ((float)(longlong)local_13b8 * 1.5258789e-05 *
                    (float)(longlong)local_13b8 * 1.5258789e-05 + local_1600 * local_1600 < 400.0)
                goto LAB_005ebba1;
                puVar15 = (undefined4 *)*puVar15;
              } while (puVar15 != local_137c);
            }
            iVar26 = world_getChunkCell256();
            local_12dc = *(float **)(iVar26 + 0x14);
            while( true ) {
              iVar26 = world_getColumnData(local_12d0,local_12d8,local_12dc,uVar5);
              if (((*(byte *)(iVar26 + 3) & 0x1f) == 0) || ((*(byte *)(iVar26 + 3) & 0x1f) == 2))
              break;
              local_12dc = (float *)((int)local_12dc + 1);
            }
            iVar26 = world_getColumnData(local_12d0,local_12d8,(int)local_12dc - 1,uVar5);
            local_12f4 = (float *)(*(byte *)(iVar26 + 3) & 0xffffff1f);
            fVar29 = (float10)Terrain_sampleHeightAtWorldXY(local_12d0,local_12d8);
            local_1334 = (float *)(float)fVar29;
            if ((float)local_1334 <= 0.0) {
              fVar29 = (float10)WorldInfo_rotateAndPlace();
              local_1334 = (float *)(float)fVar29;
              if (1.0 <= (float)local_1334) {
                pvVar11 = operator_new(0x10f0);
                if (pvVar11 == (void *)0x0) {
                  local_1320 = (float *)0x0;
                }
                else {
                  local_1320 = (float *)cube::Spawn::ctor_0();
                }
                local_1558 = (float *)(((int)local_12dc >> 0x1f) << 0x10 | (uint)local_12dc >> 0x10)
                ;
                local_155c = (int)local_12dc << 0x10;
                local_1358 = (double)CONCAT44(local_155c,(undefined4)local_1358);
                iVar26 = (int)local_12d8 >> 0x1f;
                uVar5 = (uint)local_12d8 >> 0x10;
                iVar22 = (int)local_12d8 * 0x10000;
                local_1338 = local_1558;
                local_12e8 = local_1320;
                lVar38 = float_to_uint64_round();
                local_1334 = (float *)lVar38;
                local_228 = lVar38 + CONCAT44(iVar26 << 0x10 | uVar5,iVar22);
                local_220 = (float)local_1358._4_4_;
                local_230 = lVar38 + CONCAT44(((int)local_12d0 >> 0x1f) << 0x10 |
                                              (uint)local_12d0 >> 0x10,(int)local_12d0 * 0x10000);
                local_21c = local_1338;
                *(longlong *)(local_12e8 + 4) = local_230;
                *(longlong *)(local_12e8 + 6) = local_228;
                local_12e8[8] = (float)local_1358._4_4_;
                local_1344 = (double)CONCAT44(local_12e8 + 4,(undefined4)local_1344);
                local_12e8[9] = (float)local_1338;
                iVar26 = rand();
                pfVar9 = local_12e8;
                local_12e8[0x15] = ((float)iVar26 * 360.0) / 32767.0;
                local_12e8[0xd] = 1.4013e-45;
                fVar30 = (float)WorldInfo_scatterObjectsInArea(local_12d0,local_12d8,local_12dc,0);
                pfVar9[0xb] = fVar30;
                if (local_12f4 == (float *)0xc) {
                  uVar5 = rand();
                  uVar5 = uVar5 & 0x80000001;
                  if ((int)uVar5 < 0) {
                    uVar5 = (uVar5 - 1 | 0xfffffffe) + 1;
                  }
                  pfVar9[0xb] = (float)((-(uint)(uVar5 != 0) & 0xfffffffc) + 0x82);
LAB_005eb4c0:
                  uVar5 = local_130c;
                  pfVar9[10] = 8.40779e-45;
                  std_vector_push_back_4byte();
                }
                else {
                  uVar5 = local_130c;
                  if (-1 < (int)local_12dc) {
                    if (((local_12f4 == (float *)0x4) || (local_12f4 == (float *)0x5)) ||
                       (local_12f4 == (float *)0x9)) {
                      iVar26 = rand();
                      if (((iVar26 % 3 != 0) && (0.8 < (float)local_12d4)) &&
                         ((float)local_12e0 < 0.1)) {
                        uVar5 = rand();
                        uVar5 = uVar5 & 0x80000001;
                        if ((int)uVar5 < 0) {
                          uVar5 = (uVar5 - 1 | 0xfffffffe) + 1;
                        }
                        if (uVar5 == 0) {
                          pfVar9[0xb] = 1.73761e-43;
                        }
                        else if (uVar5 == 1) {
                          pfVar9[0xb] = 1.79366e-43;
                        }
                        goto LAB_005eb4c0;
                      }
                      uVar5 = local_130c;
                      if (local_12f4 == (float *)0x4) {
                        iVar26 = rand();
                        uVar5 = local_130c;
                        if (iVar26 % 3 != 0) {
                          iVar26 = world_getChunkCell256();
                          if (iVar26 == 0) {
                            fVar29 = (float10)GameController_sampleTemperatureGrid(local_12d0,local_12d8);
                            pfVar9 = (float *)(float)fVar29;
                            local_1334 = pfVar9;
                          }
                          else {
                            pfVar9 = *(float **)(iVar26 + 4);
                          }
                          if (0.1 < (float)pfVar9) {
                            uVar21 = rand();
                            uVar21 = uVar21 & 0x80000003;
                            if ((int)uVar21 < 0) {
                              uVar21 = (uVar21 - 1 | 0xfffffffc) + 1;
                            }
                            if (uVar21 == 1) {
                              local_12e8[0xb] = 1.7236e-43;
                            }
                            else if (uVar21 == 2) {
                              local_12e8[0xb] = 1.77965e-43;
                            }
                            else if (uVar21 == 3) {
                              local_12e8[0xb] = 1.75162e-43;
                            }
                            else {
                              local_12e8[0xb] = 1.68156e-43;
                            }
                            local_12e8[0x3d6] = 25.0;
                            local_12e8[10] = 8.40779e-45;
                            std_vector_push_back_4byte();
                            goto LAB_005ebba1;
                          }
                        }
                      }
                    }
                    else if (local_12f4 == (float *)0xa) {
                      uVar5 = rand();
                      uVar5 = uVar5 & 0x80000003;
                      bVar28 = uVar5 == 0;
                      if ((int)uVar5 < 0) {
                        bVar28 = (uVar5 - 1 | 0xfffffffc) == 0xffffffff;
                      }
                      uVar5 = local_130c;
                      if (bVar28) {
                        uVar5 = rand();
                        uVar5 = uVar5 & 0x80000003;
                        if ((int)uVar5 < 0) {
                          uVar5 = (uVar5 - 1 | 0xfffffffc) + 1;
                        }
                        if (uVar5 == 1) {
                          pfVar9[0xb] = 1.7236e-43;
                          pfVar9[0x3d6] = 25.0;
                        }
                        else if (uVar5 == 2) {
                          pfVar9[0xb] = 1.75162e-43;
                          pfVar9[0x3d6] = 25.0;
                        }
                        else if (uVar5 == 3) {
                          pfVar9[0xb] = 1.70958e-43;
                          pfVar9[0x3d6] = 25.0;
                        }
                        else {
                          pfVar9[0xb] = 1.69557e-43;
                          pfVar9[0x3d6] = 25.0;
                        }
                        goto LAB_005eb4c0;
                      }
                    }
                  }
                  if ((local_12e8[10] == 1.4013e-45) &&
                     ((*(ushort *)((int)local_12e8 + 0x7a) & 0x1000) == 0)) {
                    iVar26 = rand();
                    if (iVar26 % 100 == 0) {
                      *(ushort *)((int)local_12e8 + 0x7aU) =
                           *(ushort *)((int)local_12e8 + 0x7aU) | 0x200;
                    }
                  }
                  iVar26 = __alldiv(local_12e8[6],local_12e8[7],0x10000,0);
                  iVar26 = iVar26 + (iVar26 >> 0x1f & 0xffU);
                  iVar26 = (int)((iVar26 >> 8) + (iVar26 >> 0x1f & 7U)) >> 3;
                  iVar22 = __alldiv(*local_1344._4_4_,local_1344._4_4_[1],0x10000,0);
                  iVar22 = iVar22 + (iVar22 >> 0x1f & 0xffU);
                  local_12d4 = (float *)GameController_getVoxelColumn8((int)((iVar22 >> 8) + (iVar22 >> 0x1f & 7U)) >>
                                                     3,iVar26);
                  pfVar9 = local_12e8;
                  if (local_12e8[10] != 8.40779e-45) {
                    drop_getValueRange();
                    iVar26 = rand();
                    pfVar9[0xd] = (float)(iVar26 % ((local_145c - local_1460) + 1) + local_1460);
                    if (((local_12d4 != (float *)0x0) &&
                        (local_1460 <= *(int *)((int)local_12d4 + 0x24))) &&
                       (*(int *)((int)local_12d4 + 0x24) <= local_145c)) {
                      fVar29 = (float10)vec3_distanceSquared(pfVar9 + 4,pfVar9 + 6);
                      local_1334 = (float *)(float)fVar29;
                      fVar30 = 1.0 - (float)local_1334;
                      if ((0.0 < fVar30) && (0.0 < fVar30 * fVar30)) {
                        *(undefined1 *)(pfVar9 + 0x16) = *(undefined1 *)((int)local_12d4 + 0x28);
                      }
                    }
                  }
                  if (pfVar9[10] == 1.4013e-45) {
                    pfVar9[0x10] = 3.7026207e-38;
                    pfVar9[0x11] = 7.82218e-36;
                  }
                  local_1344 = (double)CONCAT44(uVar5 + 0x18,(undefined4)local_1344);
                  std_vector_push_back_4byte();
                  drop_getCountRange1();
                  iVar26 = rand();
                  local_1300 = (float *)0x0;
                  local_12d4 = (float *)(local_14a8 + -1 + iVar26 % ((local_14c0 - local_14a8) + 1))
                  ;
                  if (0 < (int)local_12d4) {
                    do {
                      pfVar24 = local_12d4;
                      pfVar9 = local_1300;
                      pvVar11 = operator_new(0x10f0);
                      if (pvVar11 == (void *)0x0) {
                        local_1388 = 0.0;
                      }
                      else {
                        local_1388 = (float)cube::Spawn::ctor_0();
                      }
                      *(undefined4 *)((int)local_1388 + 0x28) = 1;
                      local_1334 = (float *)(((float)(int)pfVar9 * 6.2831855) / (float)(int)pfVar24)
                      ;
                      local_15c0 = 0;
                      dVar32 = (double)(float)local_1334;
                      local_12ec = (int *)local_1388;
                      libm_sse2_sin_precise();
                      local_132c = (float *)((float)dVar32 * 8.0 * 65536.0);
                      lVar38 = float_to_uint64_round();
                      dVar32 = (double)(float)local_1334;
                      local_1490 = lVar38;
                      libm_sse2_cos_precise();
                      local_133c = (float *)((float)dVar32 * 8.0 * 65536.0);
                      lVar39 = float_to_uint64_round();
                      fVar30 = local_1388;
                      local_454 = local_1490._4_4_;
                      local_450 = 0;
                      local_1334 = (float *)local_1320[4];
                      local_190 = local_1320[8];
                      local_18c = local_1320[9];
                      local_1a0 = lVar39 + *(longlong *)(local_1320 + 4);
                      local_198 = local_1490 + *(longlong *)(local_1320 + 6);
                      *(longlong *)((int)local_1388 + 0x10) = local_1a0;
                      *(longlong *)((int)local_1388 + 0x18) = local_198;
                      *(float *)((int)local_1388 + 0x20) = local_190;
                      *(float *)((int)local_1388 + 0x24) = local_18c;
                      local_458 = (int)lVar38;
                      local_1504 = lVar39;
                      local_460 = lVar39;
                      uVar10 = __alldiv(*(undefined4 *)((int)local_1388 + 0x20),local_18c,0x10000,0)
                      ;
                      uVar12 = __alldiv(*(undefined4 *)((int)fVar30 + 0x18),
                                        *(undefined4 *)((int)fVar30 + 0x1c),0x10000,0);
                      uVar13 = __alldiv(*(undefined4 *)((int)local_1388 + 0x10),
                                        *(undefined4 *)((int)local_1388 + 0x14),0x10000,0);
                      uVar10 = WorldInfo_vectorAppend(uVar13,uVar12,uVar10,local_1320[0xb]);
                      fVar30 = local_1388;
                      *(undefined4 *)((int)local_1388 + 0x2c) = uVar10;
                      *(ushort *)((int)local_1388 + 0x7a) =
                           *(ushort *)((int)local_1388 + 0x7a) & 0xfdff;
                      if (*(int *)((int)local_1388 + 0x28) != 6) {
                        drop_getValueRange();
                        iVar26 = rand();
                        *(int *)((int)fVar30 + 0x34) =
                             iVar26 % ((local_14b8 - local_1494) + 1) + local_1494;
                        *(undefined1 *)((int)fVar30 + 0x58) = *(undefined1 *)(local_1320 + 0x16);
                      }
                      iVar26 = rand();
                      *(float *)((int)fVar30 + 0x54) = ((float)iVar26 * 360.0) / 32767.0;
                      std_vector_push_back_4byte();
                      local_1300 = (float *)((int)local_1300 + 1);
                      uVar5 = local_130c;
                    } while ((int)local_1300 < (int)local_12d4);
                  }
                }
              }
            }
          }
LAB_005ebba1:
          local_1314 = (float *)((int)local_1314 + 1);
        } while ((int)local_1314 < 3);
        local_1308 = (float)((int)local_1308 + 1);
      } while ((int)local_1308 < 3);
      local_8 = CONCAT31(local_8._1_3_,3);
      if (local_1410 != (void *)0x0) {
        std::_Container_base0::_Orphan_all((_Container_base0 *)&local_1410);
        operator_delete(local_1410);
      }
      local_12cc = local_135c;
      if ((int)local_135c < (int)local_1374) {
        local_1420 = 0x1d6;
        pfVar9 = local_1330 + 0x40;
        local_13f8 = 0x96;
        local_1334 = (float *)0x12c;
        do {
          local_1304 = local_1330;
          if ((int)local_1330 < (int)pfVar9) {
            do {
              local_12f0 = (float *)world_getChunkCell256();
              local_12dc = (float *)0x0;
              iVar26 = getDword0x1c();
              if (0 < iVar26) {
                do {
                  iVar26 = getDword0x1c();
                  if ((int)local_12dc < iVar26 + -1) {
                    local_12e0 = (float *)((int)local_12dc + 1);
                    VoxelColumn_at();
                    cVar2 = block_isSolidType();
                    if (cVar2 == '\0') goto LAB_005ebce0;
                  }
                  else {
LAB_005ebce0:
                    VoxelColumn_at();
                    local_1320 = (float *)getBlockType5bits();
                    local_12e0 = (float *)((int)local_12dc + 1);
                    VoxelColumn_at();
                    iVar26 = getBlockType5bits();
                    iVar22 = getDword0x10();
                    pfVar9 = local_1304;
                    local_12d8 = (float *)((int)local_12dc + iVar22 + 1);
                    if (iVar26 == 0) {
                      if (local_1320 == (float *)0xb) {
                        fVar29 = (float10)Terrain_sampleHeightAtWorldXY(local_12cc,local_1304);
                        local_12ec = (int *)(float)fVar29;
                        if ((0.75 < (float)local_12ec) &&
                           (((int)local_1304 * 0x5a + (int)local_12cc) % (int)local_1420 == 0)) {
                          uVar21 = rand();
                          uVar21 = uVar21 & 0x8000000f;
                          if ((int)uVar21 < 0) {
                            uVar21 = (uVar21 - 1 | 0xfffffff0) + 1;
                          }
                          if (uVar21 == 0) {
                            local_12d4 = (float *)0x0;
                            do {
                              world_getColumnData(local_12cc,local_1304,(int)local_12d4 + (int)local_12d8,
                                           uVar5);
                              cVar2 = block_isSolidType();
                              if (cVar2 != '\0') goto LAB_005ec591;
                              local_12d4 = (float *)((int)local_12d4 + 1);
                            } while ((int)local_12d4 < 7);
                            Struct_InitDefaults();
                            local_8._0_1_ = 8;
                            fVar29 = (float10)getHumidityAt();
                            local_12ec = (int *)(float)fVar29;
                            if ((float)local_12ec <= 0.8) {
                              local_1048 = 0x32;
                            }
                            else {
                              local_1048 = 0x33;
                            }
                            uVar10 = setVec3();
                            uVar40 = CONCAT44(uVar10,0x5ebe92);
                            vec3_copy();
                            uVar37 = CONCAT44(local_12d8,0x5ebea2);
                            int_toFixed16();
                            uVar10 = 0x5ebeb2;
                            pfVar9 = local_1304;
                            int_toFixed16(local_1304);
                            int_toFixed16(local_12cc);
                            vec6_set(uVar10,pfVar9,uVar37,uVar40);
                            vec6_copy();
                            local_1028 = rand();
                            local_1028 = local_1028 & 0x80000003;
                            if ((int)local_1028 < 0) {
                              local_1028 = (local_1028 - 1 | 0xfffffffc) + 1;
                            }
                            std_vector_pushBack_0x188();
                            local_8 = CONCAT31(local_8._1_3_,3);
                            Member_Destroy();
                          }
                        }
                      }
                      else if (local_1320 == (float *)0x3) {
                        fVar29 = (float10)getHumidityAt();
                        local_12ec = (int *)(float)fVar29;
                        if (0.2 < (float)local_12ec) {
                          perlinNoise2D_cosInterp((double)((float)(int)local_12cc * 0.05 + 9843.0),
                                       (double)((float)(int)local_1304 * 0.05 + 8437.0));
                          fVar29 = (float10)fabs_f();
                          local_12ec = (int *)(float)fVar29;
                          if (0.5 < (float)local_12ec) {
                            uVar21 = rand();
                            uVar21 = uVar21 & 0x80000007;
                            bVar28 = uVar21 == 0;
                            if ((int)uVar21 < 0) {
                              bVar28 = (uVar21 - 1 | 0xfffffff8) == 0xffffffff;
                            }
                            if (bVar28) {
                              Struct_InitScaleDefaults();
                              int_toFixed16(local_12cc);
                              fixed_sub_ftol_rev64();
                              arrayElem_stride8(0);
                              vec2_copy();
                              int_toFixed16(local_1304);
                              fixed_sub_ftol_rev64();
                              arrayElem_stride8(1);
                              vec2_copy();
                              arrayElem_stride8(2);
                              int_toFixed16();
                              iVar26 = rand();
                              local_4c8 = ((float)iVar26 * 360.0) / 32767.0;
                              local_4cc = 0x3db851ec;
                              local_4ec = 0x16;
                              local_4b4 = 4;
                              list_pushBack_via5c03f0();
                            }
                          }
                        }
                      }
                      else {
                        if (local_1320 != (float *)0x2) goto LAB_005ec2f6;
                        fVar29 = (float10)getHumidityAt();
                        local_12ec = (int *)(float)fVar29;
                        if ((0.2 < (float)local_12ec) && (0 < (int)local_12d8)) {
                          perlinNoise2D_cosInterp((double)((float)(int)local_12cc * 0.05 + 24234.0),
                                       (double)((float)(int)local_1304 * 0.05 + 53565.0));
                          fVar29 = (float10)fabs_f();
                          local_12ec = (int *)(float)fVar29;
                          if (0.7 < (float)local_12ec) {
                            iVar26 = rand();
                            if (iVar26 % 10 == 0) {
                              Struct_InitScaleDefaults();
                              int_toFixed16(local_12cc);
                              fixed_sub_ftol_rev64();
                              arrayElem_stride8(0);
                              vec2_copy();
                              int_toFixed16(local_1304);
                              fixed_sub_ftol_rev64();
                              arrayElem_stride8(1);
                              vec2_copy();
                              int_toFixed16(local_12d8);
                              int64_subGen();
                              arrayElem_stride8(2);
                              vec2_copy();
                              iVar26 = rand();
                              local_54c = 0x3db851ec;
                              local_548 = ((float)iVar26 * 360.0) / 32767.0;
                              uVar21 = rand();
                              uVar21 = uVar21 & 0x80000001;
                              if ((int)uVar21 < 0) {
                                uVar21 = (uVar21 - 1 | 0xfffffffe) + 1;
                              }
                              aiStack_578[3] = uVar21 + 0x1f;
                              list_pushBack_via5c03f0();
                            }
                          }
                        }
                      }
                    }
                    else {
LAB_005ec2f6:
                      if (((local_1320 == (float *)0x4) || (local_1320 == (float *)0x9)) ||
                         ((local_1320 == (float *)0xc || (local_1320 == (float *)0xa)))) {
                        local_1300 = (float *)(float)(int)local_1304;
                        local_1314 = (float *)(float)(int)local_12cc;
                        perlinNoise2D_cosInterp((double)((float)local_1314 * 0.05 + 9843.0),
                                     (double)((float)local_1300 * 0.05 + 8437.0));
                        fVar29 = (float10)fabs_f();
                        local_12ec = (int *)(float)fVar29;
                        if (0.6 < (float)local_12ec) {
                          uVar21 = rand();
                          uVar21 = uVar21 & 0x80000007;
                          bVar28 = uVar21 == 0;
                          if ((int)uVar21 < 0) {
                            bVar28 = (uVar21 - 1 | 0xfffffff8) == 0xffffffff;
                          }
                          if (bVar28) {
                            if ((int)local_12d8 < 1) {
                              if (-5 < (int)local_12d8) goto LAB_005ec591;
                              Struct_InitScaleDefaults();
                              int_toFixed16(local_12cc);
                              fixed_sub_ftol_rev64();
                              arrayElem_stride8(0);
                              vec2_copy();
                              int_toFixed16(pfVar9);
                              fixed_sub_ftol_rev64();
                              arrayElem_stride8(1);
                              vec2_copy();
                              arrayElem_stride8(2);
                              int_toFixed16();
                              uVar21 = rand();
                              uVar21 = uVar21 & 0x80000003;
                              if ((int)uVar21 < 0) {
                                uVar21 = (uVar21 - 1 | 0xfffffffc) + 1;
                              }
                              local_358 = (float)(int)(uVar21 * 0x5a);
                              local_35c = 0.1;
                              fVar29 = (float10)perlinNoise2D_cosInterp((double)(int)local_12cc * 0.01 + 9843.0
                                                             ,(double)(int)pfVar9 * 0.01 + 8437.0);
                              local_12ec = (int *)(float)fVar29;
                              if ((float)local_12ec <= 0.0) {
                                local_37c = 7;
LAB_005ec542:
                                local_35c = 0.1;
LAB_005ec54c:
                                local_344 = local_344 | 4;
                              }
                              else {
                                uVar21 = rand();
                                uVar21 = uVar21 & 0x80000001;
                                if ((int)uVar21 < 0) {
                                  uVar21 = (uVar21 - 1 | 0xfffffffe) + 1;
                                }
                                local_37c = uVar21 + 5;
                                if (local_37c == 5) {
                                  local_35c = 0.075;
                                  goto LAB_005ec54c;
                                }
                                if (local_37c == 7) goto LAB_005ec542;
                              }
                              iVar26 = rand();
                              local_35c = ((float)iVar26 / 32767.0 + 1.0) * local_35c;
                            }
                            else {
                              if (local_1320 != (float *)0xc) {
                                if (local_1320 == (float *)0xa) goto LAB_005ecb51;
                                fVar29 = (float10)getHumidityAt();
                                local_12ec = (int *)(float)fVar29;
                                if ((float)local_12ec <= 0.75) {
                                  Struct_InitScaleDefaults();
                                  int_toFixed16(local_12cc);
                                  fixed_sub_ftol_rev64();
                                  arrayElem_stride8(0);
                                  vec2_copy();
                                  int_toFixed16(local_1304);
                                  fixed_sub_ftol_rev64();
                                  arrayElem_stride8(1);
                                  vec2_copy();
                                  arrayElem_stride8(2);
                                  int_toFixed16();
                                  uVar21 = rand();
                                  uVar21 = uVar21 & 0x80000003;
                                  if ((int)uVar21 < 0) {
                                    uVar21 = (uVar21 - 1 | 0xfffffffc) + 1;
                                  }
                                  local_40c = (float)(int)(uVar21 * 0x5a);
                                  local_410 = 0.075;
                                  fVar29 = (float10)getTemperatureAt();
                                  local_12ec = (int *)(float)fVar29;
                                  local_4c = (double)(int)local_12cc * 0.01;
                                  local_44 = (double)(int)local_1304 * 0.01;
                                  if ((float)local_12ec <= 0.5) {
                                    fVar29 = (float10)perlinNoise2D_cosInterp(local_4c + 9843.0,
                                                                   local_44 + 8437.0);
                                    local_12ec = (int *)(float)fVar29;
                                    if ((float)local_12ec <= 0.0) {
                                      fVar29 = (float10)perlinNoise2D_cosInterp(local_4c + 34234.0,
                                                                     local_44 + 234234.0);
                                      goto LAB_005ed0b8;
                                    }
                                    fVar29 = (float10)perlinNoise2D_cosInterp((double)((float)local_1314 * 0.01
                                                                           + 34234.0),
                                                                   (double)((float)local_1300 * 0.01
                                                                           + 234234.0));
                                    local_12ec = (int *)(float)fVar29;
                                    local_430 = ((float)local_12ec <= 0.0) + 2;
                                  }
                                  else {
                                    fVar29 = (float10)perlinNoise2D_cosInterp(local_4c + 9843.0,
                                                                   local_44 + 8437.0);
                                    local_12ec = (int *)(float)fVar29;
                                    if ((float)local_12ec <= 0.0) {
                                      fVar29 = (float10)perlinNoise2D_cosInterp(local_4c + 34234.0,
                                                                     local_44 + 234234.0);
LAB_005ed0b8:
                                      local_12ec = (int *)(float)fVar29;
                                      local_430 = (uint)((float)local_12ec <= 0.0);
                                    }
                                    else {
                                      fVar29 = (float10)perlinNoise2D_cosInterp((double)((float)local_1314 *
                                                                              0.01 + 34234.0),
                                                                     (double)((float)local_1300 *
                                                                              0.01 + 234234.0));
                                      local_12ec = (int *)(float)fVar29;
                                      local_430 = (uint)(0.0 < (float)local_12ec) * 8 + 4;
                                    }
                                  }
                                  if (((((local_430 == 2) || (local_430 == 3)) || (local_430 == 4))
                                      || (local_430 == 0xc)) &&
                                     (local_3f8 = local_3f8 | 4, local_430 == 0xc)) {
                                    iVar26 = rand();
                                    local_410 = ((float)iVar26 * 0.02) / 32767.0 + 0.1;
                                  }
                                  if (((local_1320 == (float *)0x4) || (local_430 == 2)) ||
                                     ((local_430 == 3 || (local_430 == 4)))) goto LAB_005ecb42;
                                }
                                else {
                                  fVar29 = (float10)getTemperatureAt();
                                  local_12ec = (int *)(float)fVar29;
                                  if ((float)local_12ec <= 0.25) {
                                    iVar26 = rand();
                                    if (iVar26 % 100 == 0) {
                                      Struct_InitScaleDefaults();
                                      int_toFixed16(local_12cc);
                                      fixed_sub_ftol_rev64();
                                      arrayElem_stride8(0);
                                      vec2_copy();
                                      int_toFixed16(local_1304);
                                      fixed_sub_ftol_rev64();
                                      arrayElem_stride8(1);
                                      vec2_copy();
                                      arrayElem_stride8(2);
                                      int_toFixed16();
                                      uVar21 = rand();
                                      uVar21 = uVar21 & 0x80000003;
                                      if ((int)uVar21 < 0) {
                                        uVar21 = (uVar21 - 1 | 0xfffffffc) + 1;
                                      }
                                      local_508 = (float)(int)(uVar21 * 0x5a);
                                      local_50c = 0x3d99999a;
                                      uVar21 = rand();
                                      uVar21 = uVar21 & 0x80000001;
                                      if ((int)uVar21 < 0) {
                                        uVar21 = (uVar21 - 1 | 0xfffffffe) + 1;
                                      }
                                      local_52c = 0x1c - (uint)(uVar21 != 0);
                                      goto LAB_005ecb42;
                                    }
                                  }
                                  else {
                                    Struct_InitScaleDefaults();
                                    int_toFixed16(local_12cc);
                                    fixed_sub_ftol_rev64();
                                    arrayElem_stride8(0);
                                    vec2_copy();
                                    int_toFixed16(local_1304);
                                    fixed_sub_ftol_rev64();
                                    arrayElem_stride8(1);
                                    vec2_copy();
                                    arrayElem_stride8(2);
                                    int_toFixed16();
                                    iVar26 = rand();
                                    local_2e8 = ((float)iVar26 * 360.0) / 32767.0;
                                    local_4c = (double)(int)local_12cc * 0.01;
                                    local_44 = (double)(int)local_1304 * 0.01;
                                    local_2ec = 0.075;
                                    fVar29 = (float10)perlinNoise2D_cosInterp(local_4c + 9843.0,
                                                                   local_44 + 8437.0);
                                    local_12ec = (int *)(float)fVar29;
                                    if ((float)local_12ec <= 0.0) {
                                      fVar29 = (float10)perlinNoise2D_cosInterp(local_4c + 34234.0,
                                                                     local_44 + 234234.0);
                                      local_12ec = (int *)(float)fVar29;
                                      local_30c = ((float)local_12ec <= 0.5) + 0xb;
                                    }
                                    else {
                                      fVar29 = (float10)perlinNoise2D_cosInterp((double)((float)local_1314 *
                                                                              0.01 + 34234.0),
                                                                     (double)((float)local_1300 *
                                                                              0.01 + 234234.0));
                                      local_12ec = (int *)(float)fVar29;
                                      local_30c = (0.0 < (float)local_12ec) + 3;
                                    }
                                    if ((local_30c == 2) || (local_30c == 3)) {
                                      local_2d4 = local_2d4 | 4;
                                    }
                                    if (local_30c == 0xb) {
                                      iVar26 = rand();
                                      local_2d4 = local_2d4 | 4;
                                      local_2ec = ((float)iVar26 * 0.05) / 32767.0 + 0.05;
                                    }
                                    if (local_30c == 0xc) {
                                      iVar26 = rand();
                                      local_2d4 = local_2d4 | 4;
                                      local_2ec = ((float)iVar26 * 0.02) / 32767.0 + 0.1;
                                    }
                                    if (((local_1320 == (float *)0x4) || (local_30c == 2)) ||
                                       (local_30c == 3)) {
LAB_005ecb42:
                                      list_pushBack_via5c03f0();
                                    }
                                  }
                                }
LAB_005ecb51:
                                if (local_1320 == (float *)0x4) {
                                  iVar26 = rand();
                                  if (iVar26 % local_13f8 == 0) {
                                    reset_0x148Struct();
                                    int_toFixed16(local_12cc);
                                    fixed_sub_ftol_rev64();
                                    arrayElem_stride8(0);
                                    vec2_copy();
                                    int_toFixed16(local_1304);
                                    fixed_sub_ftol_rev64();
                                    arrayElem_stride8(1);
                                    vec2_copy();
                                    arrayElem_stride8(2);
                                    int_toFixed16();
                                    iVar26 = rand();
                                    local_c60 = 0xb;
                                    local_b30 = ((float)iVar26 / 32767.0) * 360.0;
                                    uVar21 = rand();
                                    uVar21 = uVar21 & 0x80000001;
                                    if ((int)uVar21 < 0) {
                                      uVar21 = (uVar21 - 1 | 0xfffffffe) + 1;
                                    }
                                    if (uVar21 == 0) {
                                      local_c5f = 0xf;
                                    }
                                    else if (uVar21 == 1) {
                                      local_c5f = 0x16;
                                      local_b2c = 0x3dcccccd;
                                    }
                                    local_c50 = 1;
                                    local_b28 = 2;
                                    vector_pushBack_0x148();
                                  }
                                }
                                else if (local_1320 == (float *)0xa) {
                                  iVar26 = rand();
                                  if (iVar26 % (int)local_1334 == 0) {
                                    reset_0x148Struct();
                                    int_toFixed16(local_12cc);
                                    fixed_sub_ftol_rev64();
                                    arrayElem_stride8(0);
                                    vec2_copy();
                                    int_toFixed16(local_1304);
                                    fixed_sub_ftol_rev64();
                                    arrayElem_stride8(1);
                                    vec2_copy();
                                    arrayElem_stride8(2);
                                    int_toFixed16();
                                    iVar26 = rand();
                                    local_da8 = 0xb;
                                    local_c78 = ((float)iVar26 / 32767.0) * 360.0;
                                    uVar21 = rand();
                                    uVar21 = uVar21 & 0x80000001;
                                    if ((int)uVar21 < 0) {
                                      uVar21 = (uVar21 - 1 | 0xfffffffe) + 1;
                                    }
                                    if (uVar21 < 2) {
                                      local_da7 = 0x18;
                                      local_c74 = 0x3dcccccd;
                                    }
                                    local_d98 = 1;
                                    local_c70 = 2;
                                    vector_pushBack_0x148();
                                  }
                                }
                                goto LAB_005ec591;
                              }
                              Struct_InitScaleDefaults();
                              int_toFixed16(local_12cc);
                              fixed_sub_ftol_rev64();
                              arrayElem_stride8(0);
                              vec2_copy();
                              int_toFixed16(pfVar9);
                              fixed_sub_ftol_rev64();
                              arrayElem_stride8(1);
                              vec2_copy();
                              arrayElem_stride8(2);
                              int_toFixed16();
                              uVar21 = rand();
                              uVar21 = uVar21 & 0x80000003;
                              if ((int)uVar21 < 0) {
                                uVar21 = (uVar21 - 1 | 0xfffffffc) + 1;
                              }
                              local_47c = (float)(int)(uVar21 * 0x5a);
                              local_480 = 0.075;
                              fVar29 = (float10)perlinNoise2D_cosInterp((double)(int)local_12cc * 0.01 + 9843.0
                                                             ,(double)(int)pfVar9 * 0.01 + 8437.0);
                              local_12ec = (int *)(float)fVar29;
                              local_4a0 = ((float)local_12ec <= 0.0) + 9;
                              if (local_4a0 == 9) {
                                local_468 = local_468 | 4;
                              }
                              else if (local_4a0 == 10) {
                                iVar26 = rand();
                                local_480 = ((float)iVar26 * 0.02) / 32767.0 + 0.03;
                              }
                            }
                            list_pushBack_via5c03f0();
                          }
                        }
                      }
                    }
                  }
LAB_005ec591:
                  local_12dc = local_12e0;
                  iVar26 = getDword0x1c();
                } while ((int)local_12dc < iVar26);
              }
              local_1304 = (float *)((int)local_1304 + 1);
              pfVar9 = local_1330 + 0x40;
            } while ((int)local_1304 < (int)pfVar9);
          }
          local_12cc = (float *)((int)local_12cc + 1);
        } while ((int)local_12cc < (int)local_1374);
      }
      local_12ec = (int *)(uVar5 + 0x24);
      iVar26 = std_vector_size_4();
      if (0 < iVar26) {
        iVar26 = 0;
        do {
          piVar14 = (int *)vector_at_stride4();
          if (*(int *)*piVar14 == 0 && ((int *)*piVar14)[1] == 0) {
            puVar15 = (undefined4 *)vector_at_stride4();
            uVar37 = packWorldCoord64();
            *(undefined8 *)*puVar15 = uVar37;
          }
          iVar26 = iVar26 + 1;
          iVar22 = std_vector_size_4();
          uVar5 = local_130c;
        } while (iVar26 < iVar22);
      }
      local_12cc = (float *)(uVar5 + 0x18);
      local_12d0 = (float *)0x0;
      iVar22 = std_vector_size_4();
      iVar26 = local_12e4;
      if (0 < iVar22) {
        do {
          piVar14 = (int *)vector_at_stride4();
          if (*(int *)(*piVar14 + 0x48) == 0 && *(int *)(*piVar14 + 0x4c) == 0) {
            piVar14 = (int *)vector_at_stride4();
            uVar37 = packWorldCoord64();
            *(undefined8 *)(*piVar14 + 0x48) = uVar37;
          }
          vector_at_stride4();
          vector_at_stride4();
          creature_generateAppearance();
          puVar15 = (undefined4 *)vector_at_stride4();
          creature_initBehaviorByType(*puVar15,0);
          piVar14 = (int *)vector_at_stride4();
          if ((*(ushort *)(*piVar14 + 0x7a) & 0x200) != 0) {
            state_initB();
            local_ec0[0] = 0xe0b;
            piVar14 = (int *)vector_at_stride4();
            local_eb0 = *(undefined2 *)(*piVar14 + 0x34);
            uVar5 = rand();
            uVar5 = uVar5 & 0x80000003;
            if ((int)uVar5 < 0) {
              uVar5 = (uVar5 - 1 | 0xfffffffc) + 1;
            }
            local_eb3 = (char)uVar5 + -0x80;
            local_eb4 = 2;
            vector_at_stride4();
            GameController_addItemToInventory(local_ec0,0xffffffff);
          }
          piVar14 = (int *)vector_at_stride4();
          piVar16 = (int *)vector_at_stride4();
          local_12ec = (int *)vector_at_stride4();
          uVar4 = WorldInfo_vectorElementAt(*(undefined1 *)(*piVar16 + 0x58),
                               (byte)((ushort)*(undefined2 *)(*piVar14 + 0x7a) >> 9) & 1);
          *(undefined1 *)(*local_12ec + 0x8d4) = uVar4;
          piVar14 = (int *)vector_at_stride4();
          piVar16 = (int *)vector_at_stride4();
          local_12ec = (int *)vector_at_stride4();
          uVar4 = WorldInfo_vectorElementAt(*(undefined1 *)(*piVar16 + 0x58),
                               (byte)((ushort)*(undefined2 *)(*piVar14 + 0x7a) >> 9) & 1);
          *(undefined1 *)(*local_12ec + 0x7bc) = uVar4;
          piVar14 = (int *)vector_at_stride4();
          piVar16 = (int *)vector_at_stride4();
          local_12ec = (int *)vector_at_stride4();
          uVar4 = WorldInfo_vectorElementAt(*(undefined1 *)(*piVar16 + 0x58),
                               (byte)((ushort)*(undefined2 *)(*piVar14 + 0x7a) >> 9) & 1);
          *(undefined1 *)(*local_12ec + 0x6a4) = uVar4;
          piVar14 = (int *)vector_at_stride4();
          piVar16 = (int *)vector_at_stride4();
          local_12ec = (int *)vector_at_stride4();
          uVar4 = WorldInfo_vectorElementAt(*(undefined1 *)(*piVar16 + 0x58),
                               (byte)((ushort)*(undefined2 *)(*piVar14 + 0x7a) >> 9) & 1);
          *(undefined1 *)(*local_12ec + 0x35c) = uVar4;
          piVar14 = (int *)vector_at_stride4();
          piVar16 = (int *)vector_at_stride4();
          local_12ec = (int *)vector_at_stride4();
          uVar4 = WorldInfo_vectorElementAt(*(undefined1 *)(*piVar16 + 0x58),
                               (byte)((ushort)*(undefined2 *)(*piVar14 + 0x7a) >> 9) & 1);
          *(undefined1 *)(*local_12ec + 0x58c) = uVar4;
          piVar14 = (int *)vector_at_stride4();
          piVar16 = (int *)vector_at_stride4();
          local_12ec = (int *)vector_at_stride4();
          uVar4 = WorldInfo_vectorElementAt(*(undefined1 *)(*piVar16 + 0x58),
                               (byte)((ushort)*(undefined2 *)(*piVar14 + 0x7a) >> 9) & 1);
          *(undefined1 *)(*local_12ec + 0x474) = uVar4;
          piVar14 = (int *)vector_at_stride4();
          piVar16 = (int *)vector_at_stride4();
          local_12ec = (int *)vector_at_stride4();
          iVar26 = local_12e4;
          uVar4 = WorldInfo_vectorElementAt(*(undefined1 *)(*piVar16 + 0x58),
                               (byte)((ushort)*(undefined2 *)(*piVar14 + 0x7a) >> 9) & 1);
          pfVar9 = local_12d0;
          *(undefined1 *)(*local_12ec + 0x244) = uVar4;
          piVar14 = (int *)vector_at_stride4();
          if ((*(ushort *)(*piVar14 + 0x7a) & 0x200) == 0) {
            vector_at_stride4();
            item_rerollStackCount(0x3d4ccccd,0);
            vector_at_stride4();
            item_rerollStackCount(0x3d4ccccd,0);
            vector_at_stride4();
            item_rerollStackCount(0x3d4ccccd,0);
            vector_at_stride4();
            item_rerollStackCount(0x3d4ccccd,0);
            vector_at_stride4();
            item_rerollStackCount(0x3d4ccccd,0);
            vector_at_stride4();
            item_rerollStackCount(0x3d4ccccd,0);
            vector_at_stride4();
            item_rerollStackCount(0x3d4ccccd,0);
            vector_at_stride4();
            item_rerollStackCount(0x3d4ccccd,0);
            vector_at_stride4();
            item_rerollStackCount(0x3d4ccccd,0);
          }
          piVar14 = (int *)vector_at_stride4();
          if (*(int *)(*piVar14 + 0x28) == 1) {
            piVar14 = (int *)vector_at_stride4();
            if ((*(ushort *)(*piVar14 + 0x7a) & 0x200) == 0) {
              rand();
            }
          }
          local_12d0 = (float *)((int)pfVar9 + 1U);
          iVar22 = std_vector_size_4();
          uVar5 = local_130c;
        } while ((int)((int)pfVar9 + 1U) < iVar22);
      }
      init_call_65ae80();
      local_8 = CONCAT31(local_8._1_3_,9);
      store_object_ref();
      map_getRoot();
      cVar2 = operator_ne_int();
      while (cVar2 != '\0') {
        local_12ec = (int *)getFirstDword();
        uVar12 = 0;
        copy2_helper(local_14c2,local_12ec,(undefined1 *)((int)local_12ec + 1),
                     (undefined1 *)((int)local_12ec + 0xd));
        uVar10 = copy3_helper();
        copyByteTripleToInts(uVar10,uVar12);
        piVar14 = (int *)map3i_at();
        *piVar14 = *piVar14 + 1;
        if ((*(byte *)(local_12ec + 0x4e) & 1) == 0) {
          local_12d4 = (float *)arrayElem_stride8();
          puVar15 = (undefined4 *)int64_subFn(local_1528,0x3f000000);
          local_12e0 = (float *)arrayElem_stride8();
          local_12ec = (int *)arrayElem_stride8();
          iVar26 = local_12e4;
          uVar5 = local_130c;
          world_getColumnAtFixedPos(*local_12ec,local_12ec[1],*local_12e0,local_12e0[1],*puVar15,puVar15[1],
                       local_130c);
          cVar2 = block_isSolidType();
          while (cVar2 == '\0') {
            int_toFixed16();
            int64_sub_42ca00();
            puVar15 = (undefined4 *)int64_subFn(local_1528,0x3f000000);
            world_getColumnAtFixedPos(*local_12ec,local_12ec[1],*local_12e0,local_12e0[1],*puVar15,puVar15[1],
                         uVar5);
            cVar2 = block_isSolidType();
          }
        }
        vector_pushBackSlot_0x148(local_13dc,0);
        map_getRoot();
        cVar2 = operator_ne_int();
      }
      deref_frontValue();
      store_object_ref();
      uVar37 = 0x5eda7e;
      cVar2 = operator_ne_int();
      pfVar9 = local_1390;
      while (cVar2 != '\0') {
        uVar10 = (undefined4)uVar37;
        local_12ec = (int *)iterator_at_0x10();
        if (((*local_12ec == 1) || (*local_12ec == 0xb)) && (7 < local_12ec[3])) {
          uVar40 = CONCAT44(0x5edac6,uVar10);
          ctor_obj0x140();
          local_1184 = (undefined1)*local_12ec;
          local_1183 = (undefined1)local_12ec[1];
          local_1177 = (undefined1)local_12ec[2];
          local_1188 = 9;
          uVar37 = 0x5edafc;
          int_toFixed16();
          uVar10 = 0x5edb0c;
          pfVar24 = local_138c;
          int_toFixed16(local_138c);
          int_toFixed16(pfVar9);
          vec6_set(uVar10,pfVar24,uVar37,uVar40);
          vec6_copy();
          WorldInfo_lookupCell();
        }
        iterator_deref_advance(local_154c,0);
        store_object_ref();
        uVar37 = 0x5edb6f;
        cVar2 = operator_ne_int();
        iVar26 = local_12e4;
      }
      init_call_46d4b0();
      local_8 = CONCAT31(local_8._1_3_,10);
      store_object_ref();
      map_getRoot();
      cVar2 = operator_ne_int();
      while (cVar2 != '\0') {
        piVar14 = (int *)getFirstDword();
        if (*(int *)(*piVar14 + 0x44) == 86400000) {
          pair_assign_2dword();
          piVar14 = (int *)GameController_chunkMap2i_at();
          *piVar14 = *piVar14 + 1;
        }
        iterator_postInc_4(local_13e4,0);
        map_getRoot();
        cVar2 = operator_ne_int();
        iVar26 = local_12e4;
      }
      deref_frontValue();
      store_object_ref();
      uVar37 = 0x5edc64;
      cVar2 = operator_ne_int();
      pfVar9 = local_1390;
      while (cVar2 != '\0') {
        uVar10 = (undefined4)uVar37;
        local_12ec = (int *)iterator_at_0x10();
        iVar26 = *local_12ec;
        if ((((iVar26 == 1) || (iVar26 == 6)) || (iVar26 == 5)) && (4 < local_12ec[2])) {
          uVar40 = CONCAT44(0x5edcad,uVar10);
          ctor_obj0x140();
          local_11a8 = local_12ec[1];
          local_12c8 = 10;
          uVar37 = 0x5edcd2;
          int_toFixed16();
          uVar10 = 0x5edce2;
          pfVar24 = local_138c;
          int_toFixed16(local_138c);
          int_toFixed16(pfVar9);
          vec6_set(uVar10,pfVar24,uVar37,uVar40);
          vec6_copy();
          WorldInfo_lookupCell();
        }
        iterator_deref_advance(local_1568,0);
        store_object_ref();
        uVar37 = 0x5edd45;
        cVar2 = operator_ne_int();
        iVar26 = local_12e4;
      }
      uVar10 = std_vector_size_4();
      *(undefined4 *)(uVar5 + 0xa0) = uVar10;
      World_generateTreeRecursive();
      if (*(char *)(iVar26 + 0xb4) == '\0') {
        cVar2 = isZero_off10();
        if (cVar2 == '\0') {
          std::basic_stringbuf<char,std::char_traits<char>,std::allocator<char>_>::ctor_4(3,1);
          local_8._0_1_ = 0xb;
          fVar30 = local_1360;
          uVar21 = local_1368;
          pbVar17 = (basic_ostream<char,std::char_traits<char>_> *)
                    ostream_writePadded(local_1820,&DAT_0071c764,local_1360,&DAT_0071c760);
          std::basic_ostream<char,std::char_traits<char>_>::operator<<(pbVar17,(int)fVar30);
          pbVar17 = (basic_ostream<char,std::char_traits<char>_> *)ostream_writePadded();
          std::basic_ostream<char,std::char_traits<char>_>::operator<<(pbVar17,uVar21);
          Struct_reset_4Dwords();
          local_8._0_1_ = 0xc;
          uVar10 = ostrstream_str_wrap();
          local_8._0_1_ = 0xd;
          local_130d = db_getBlobInto(uVar10,local_1578);
          local_8 = CONCAT31(local_8._1_3_,0xc);
          string_dtor();
          if (local_130d != 0) {
            uVar37 = CONCAT44(uVar5,iVar26);
            refcount_initTo1();
            deserializeRegionChunk(uVar37);
          }
          unwind_free_object();
          local_8 = CONCAT31(local_8._1_3_,10);
          std::basic_stringbuf<char,std::char_traits<char>,std::allocator<char>_>::ctor_18();
        }
      }
      VoxelChunk_propagateSunlight(local_135c,local_1330,local_1374,local_1330 + 0x40,0,uVar5);
      local_12ec = (int *)(uVar5 + 4);
      deref_frontValue();
      store_object_ref();
      cVar2 = operator_ne_int();
      while (cVar2 != '\0') {
        iVar26 = getPtrPlus8();
        uVar41 = (ulonglong)local_130c;
        pCVar18 = (CRefTime *)arrayElem_stride8();
        lVar19 = CRefTime::Millisecs(pCVar18);
        pCVar18 = (CRefTime *)arrayElem_stride8(1);
        lVar20 = CRefTime::Millisecs(pCVar18);
        uVar37 = CONCAT44(lVar19,lVar20);
        pCVar18 = (CRefTime *)arrayElem_stride8(0);
        lVar19 = CRefTime::Millisecs(pCVar18);
        iVar22 = map_getTileLightOrHeight(lVar19,uVar37,uVar41);
        *(float *)(iVar26 + 0x28) = (float)iVar22;
        list_popFront_node(local_1498,0);
        store_object_ref();
        cVar2 = operator_ne_int();
        uVar5 = local_130c;
      }
      local_12dc = (float *)0x0;
      iVar26 = vector_size_0x188();
      if (0 < iVar26) {
        pfVar9 = (float *)0;
        do {
          uVar21 = uVar5;
          vector_at_0x188(pfVar9);
          arrayElem_stride8();
          pCVar18 = (CRefTime *)int64_divScalar_double();
          lVar19 = CRefTime::Millisecs(pCVar18);
          uVar40 = CONCAT44(uVar21,lVar19);
          uVar37 = CONCAT44(8,local_1758);
          uVar10 = 0;
          vector_at_0x188(local_12dc);
          arrayElem_stride8(uVar10);
          pCVar18 = (CRefTime *)int64_divScalar_double(uVar37);
          lVar19 = CRefTime::Millisecs(pCVar18);
          local_12ec = (int *)getTileCell32();
          if (local_12ec != (int *)0x0) {
            vec3_set(local_1360,local_1368,local_12dc);
            uVar10 = vector_at_0x188(local_12dc);
            set4(uVar10,lVar19,uVar40);
            WorldInfo_mapInsertEntry();
          }
          local_12dc = (float *)((int)local_12dc + 1);
          iVar26 = vector_size_0x188();
          pfVar9 = local_12dc;
        } while ((int)local_12dc < iVar26);
      }
      *(uint *)(local_1380 + 0x10018 + (int)local_13b0 * 4) = uVar5;
      container_destroy();
      container_destroy();
      std_list_clear_4da480();
      std_list_clear_4da480();
      std_list_clear_4da480();
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}




/* [AUDIT] proposed: WorldInfo_placeStructure  (confidence: med)
 * purpose: Places a building/structure: allocates object, computes footprint, appends via vector grow + ctors
 * vars: param_2 vec3; Struct_InitDefaults build; std_vector_Reserve_grow_188; float_to_uint64_round rng
 */
/* Global::WorldInfo_placeStructure @ 005f0ce0 */

void WorldInfo_placeStructure(int dungeon,int *origin,uint param_3,byte param_4,int zone,int param_6,
                 char param_7,int *param_8,int param_9)

{
  uint *puVar1;
  char cVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  undefined4 *puVar6;
  longlong *plVar7;
  undefined4 uVar8;
  void *pvVar9;
  uint *puVar10;
  int iVar11;
  char *pcVar12;
  undefined1 *puVar13;
  int iVar14;
  uint *puVar15;
  _Container_base0 *p_Var16;
  bool bVar17;
  float10 fVar18;
  longlong lVar19;
  undefined8 uVar20;
  undefined8 uVar21;
  undefined8 uVar22;
  undefined8 *puVar23;
  undefined4 uVar24;
  undefined4 local_71c;
  undefined4 local_718;
  char local_714 [4];
  char local_710 [4];
  char local_70c [4];
  char local_708 [4];
  char local_704 [4];
  char local_700 [4];
  char local_6fc [4];
  int local_6f8;
  int local_6f4;
  int *local_6f0;
  int local_6ec;
  int local_6e8;
  uint *local_6e4;
  uint *local_6e0;
  int local_6dc;
  int local_6d8;
  int local_6d4;
  int local_6d0;
  int local_6cc;
  int local_6c8;
  undefined1 local_6c1;
  uint *local_6c0;
  int local_6bc;
  int local_6b8;
  undefined8 local_6b0;
  uint *local_6a8;
  _Container_base0 *local_6a4;
  undefined4 local_6a0;
  undefined4 local_618 [2];
  uint *local_610;
  undefined4 local_60c;
  undefined8 local_608;
  uint *local_600;
  uint local_5fc;
  uint local_5f8;
  undefined8 local_5f4;
  undefined4 local_5ec;
  void *local_5d0;
  undefined4 local_5cc;
  uint local_490 [2];
  uint local_488;
  uint local_484;
  uint local_480;
  uint local_47c;
  uint local_478;
  uint local_474;
  uint local_470;
  uint local_46c;
  uint local_468;
  uint local_464;
  char local_460;
  uint local_45c;
  uint local_458;
  undefined8 local_450;
  undefined4 *local_448;
  undefined4 *local_444;
  undefined4 local_440;
  uint local_43c;
  undefined2 local_438 [2];
  undefined4 local_434;
  undefined4 local_430;
  undefined2 local_42c;
  undefined1 local_42a;
  undefined2 local_428;
  undefined1 local_424 [256];
  undefined4 local_324;
  uint local_320;
  uint local_31c;
  uint local_318;
  uint local_314;
  uint uStack_310;
  uint local_30c;
  int local_308 [2];
  undefined8 local_300;
  undefined8 local_2f8;
  int local_2f0;
  uint local_2ec;
  uint local_2e8;
  undefined8 local_2e4;
  undefined4 local_2dc;
  _Container_base0 *local_2c0;
  _Container_base0 *local_2bc;
  undefined4 local_180;
  undefined4 uStack_17c;
  undefined4 local_178;
  undefined4 local_174;
  undefined4 uStack_170;
  undefined4 local_16c;
  undefined4 local_168;
  undefined4 uStack_164;
  undefined4 local_160;
  undefined4 local_15c;
  undefined4 uStack_158;
  undefined4 local_154;
  undefined4 local_150;
  undefined4 uStack_14c;
  undefined4 local_148;
  undefined4 local_144;
  undefined4 uStack_140;
  undefined4 local_13c;
  uint *local_138;
  uint uStack_134;
  int local_12c;
  int iStack_128;
  uint *local_120;
  uint uStack_11c;
  uint *local_114;
  uint uStack_110;
  uint *local_108;
  uint uStack_104;
  int local_fc;
  int iStack_f8;
  int local_f0;
  int iStack_ec;
  int local_e4;
  int iStack_e0;
  longlong local_d8;
  longlong local_d0;
  longlong local_c8;
  undefined1 local_c0 [24];
  int local_a8;
  int iStack_a4;
  int local_a0;
  int local_9c;
  int iStack_98;
  int local_94;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 local_80;
  int local_78 [2];
  longlong local_70;
  longlong local_68;
  longlong local_60;
  undefined4 local_58;
  float local_54;
  undefined4 local_4c;
  undefined4 uStack_48;
  undefined4 local_44;
  int local_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined2 local_28;
  undefined1 uStack_26;
  undefined1 uStack_25;
  uint uStack_24;
  uint *local_20;
  uint uStack_1c;
  uint *local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_006f4726;
  local_10 = ExceptionList;
  local_14 = DAT_0076aa78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_6b0._4_4_ = param_8;
  local_6d8 = dungeon;
  local_6f0 = origin;
  local_6e8 = param_6;
  local_6d0 = param_9;
  uVar3 = param_3 & 0x80000001;
  bVar17 = uVar3 == 0;
  if ((int)uVar3 < 0) {
    bVar17 = (uVar3 - 1 | 0xfffffffe) == 0xffffffff;
  }
  local_6e4 = *(uint **)(dungeon + 0x44);
  local_6e0 = *(uint **)(dungeon + 0x48);
  if (!bVar17) {
    local_6e4 = *(uint **)(dungeon + 0x48);
    local_6e0 = *(uint **)(dungeon + 0x44);
  }
  local_a8 = *origin;
  local_6ec = origin[2];
  iStack_a4 = origin[1];
  local_a0 = local_6ec;
  if ((param_6 == 0) ||
     ((((local_6f8 = *(int *)(param_6 + 0x60) * 0x100,
        local_300 = CONCAT44(local_300._4_4_,(undefined4)local_300),
        local_90 = CONCAT44(local_90._4_4_,(undefined4)local_90),
        uVar20 = CONCAT44(local_38._4_4_,(int)local_38),
        local_2f8 = CONCAT44(local_2f8._4_4_,(uint *)local_2f8),
        local_88 = CONCAT44(local_88._4_4_,(undefined4)local_88),
        uStack_30 = CONCAT44(uStack_30._4_4_,(uint)uStack_30),
        local_608 = CONCAT44(local_608._4_4_,(undefined4)local_608),
        local_6f8 < (int)((int)local_6e4 + local_a8) &&
        (local_6e4 = (uint *)(*(int *)(param_6 + 100) * 0x100),
        local_300 = CONCAT44(local_300._4_4_,(undefined4)local_300),
        local_90 = CONCAT44(local_90._4_4_,(undefined4)local_90),
        uVar20 = CONCAT44(local_38._4_4_,(int)local_38),
        local_2f8 = CONCAT44(local_2f8._4_4_,(uint *)local_2f8),
        local_88 = CONCAT44(local_88._4_4_,(undefined4)local_88),
        uStack_30 = CONCAT44(uStack_30._4_4_,(uint)uStack_30),
        local_608 = CONCAT44(local_608._4_4_,(undefined4)local_608),
        (int)local_6e4 < (int)((int)local_6e0 + iStack_a4))) &&
       (local_300 = CONCAT44(local_300._4_4_,(undefined4)local_300),
       local_90 = CONCAT44(local_90._4_4_,(undefined4)local_90),
       uVar20 = CONCAT44(local_38._4_4_,(int)local_38),
       local_2f8 = CONCAT44(local_2f8._4_4_,(uint *)local_2f8),
       local_88 = CONCAT44(local_88._4_4_,(undefined4)local_88),
       uStack_30 = CONCAT44(uStack_30._4_4_,(uint)uStack_30),
       local_608 = CONCAT44(local_608._4_4_,(undefined4)local_608), local_a8 < local_6f8 + 0x100))
      && (local_300 = CONCAT44(local_300._4_4_,(undefined4)local_300),
         local_90 = CONCAT44(local_90._4_4_,(undefined4)local_90),
         uVar20 = CONCAT44(local_38._4_4_,(int)local_38),
         local_2f8 = CONCAT44(local_2f8._4_4_,(uint *)local_2f8),
         local_88 = CONCAT44(local_88._4_4_,(undefined4)local_88),
         uStack_30 = CONCAT44(uStack_30._4_4_,(uint)uStack_30),
         local_608 = CONCAT44(local_608._4_4_,(undefined4)local_608),
         iStack_a4 < (int)(local_6e4 + 0x40))))) {
    iVar4 = world_getChunkCell256();
    if (iVar4 == 0) {
      fVar18 = (float10)GameController_sampleHumidityGrid(*local_6f0,local_6f0[1]);
      local_6e4 = (uint *)(float)fVar18;
      local_6a4 = (_Container_base0 *)local_6e4;
    }
    else {
      local_6e4 = *(uint **)(iVar4 + 8);
    }
    uVar20 = CONCAT44(local_38._4_4_,(int)local_38);
    local_6dc = *(int *)(local_6d8 + 0x44);
    local_6e0 = *(uint **)(local_6d8 + 0x48);
    local_6b8 = 0;
    local_6f4 = 0;
    uVar3 = param_3 & 0x80000003;
    if ((int)uVar3 < 0) {
      uVar3 = (uVar3 - 1 | 0xfffffffc) + 1;
    }
    switch(uVar3) {
    case 0:
      local_6b8 = *local_6b0._4_4_;
      local_6f4 = local_6b0._4_4_[1];
      local_6dc = local_6dc - local_6b0._4_4_[2];
      local_6e0 = (uint *)((int)local_6e0 - local_6b0._4_4_[3]);
      break;
    case 1:
      local_6b8 = local_6b0._4_4_[3];
      local_6f4 = *local_6b0._4_4_;
      local_6dc = local_6dc - local_6b0._4_4_[1];
      local_6e0 = (uint *)((int)local_6e0 - local_6b0._4_4_[2]);
      break;
    case 2:
      local_6b8 = local_6b0._4_4_[2];
      local_6f4 = local_6b0._4_4_[3];
      local_6dc = local_6dc - *local_6b0._4_4_;
      local_6e0 = (uint *)((int)local_6e0 - local_6b0._4_4_[1]);
      break;
    case 3:
      local_6b8 = local_6b0._4_4_[1];
      local_6f4 = local_6b0._4_4_[2];
      local_6dc = local_6dc - local_6b0._4_4_[3];
      local_6e0 = (uint *)((int)local_6e0 - *local_6b0._4_4_);
    }
    iVar4 = local_6d8;
    puVar10 = local_6e0;
    lVar19 = CONCAT44(local_6b0._4_4_,(uint *)local_6b0);
    if (local_6b8 < local_6dc) {
      do {
        local_6b0 = lVar19;
        local_6bc = local_6f4;
        lVar19 = local_6b0;
        if (local_6f4 < (int)puVar10) {
LAB_005f0fa4:
          iVar4 = *(int *)(iVar4 + 0x4c);
          iVar14 = 0;
          local_6c8 = 0;
          local_6cc = iVar4;
          if (0 < iVar4) {
            do {
              if ((((local_6b8 < 0) || (local_6bc < 0)) ||
                  ((iVar14 < 0 ||
                   ((*(int *)(local_6d8 + 0x44) <= local_6b8 ||
                    (*(int *)(local_6d8 + 0x48) <= local_6bc)))))) || (iVar4 <= iVar14)) {
                puVar13 = &DAT_0076b340;
              }
              else {
                puVar13 = (undefined1 *)
                          (((*(int *)(local_6d8 + 0x48) * iVar14 + local_6bc) *
                            *(int *)(local_6d8 + 0x44) + local_6b8) * 3 + *(int *)(local_6d8 + 0x30)
                          );
              }
              iVar4 = 0;
              do {
                if (puVar13[iVar4] != (&DAT_0076b340)[iVar4]) {
                  if (iVar14 < local_6cc) {
                    local_6cc = iVar14;
                  }
                  if (local_6c8 < iVar14) {
                    local_6c8 = iVar14;
                  }
                  break;
                }
                iVar4 = iVar4 + 1;
              } while (iVar4 < 3);
              iVar4 = *(int *)(local_6d8 + 0x4c);
              iVar14 = iVar14 + 1;
              param_9 = local_6d0;
              param_6 = local_6e8;
            } while (iVar14 < iVar4);
          }
          lVar19 = local_6b0;
          if (param_7 != '\0') {
            if ((((local_6b8 < 0) || (local_6bc < 0)) || (*(int *)(local_6d8 + 0x44) <= local_6b8))
               || ((*(int *)(local_6d8 + 0x48) <= local_6bc || (iVar4 < 1)))) {
              puVar13 = &DAT_0076b340;
            }
            else {
              puVar13 = (undefined1 *)
                        ((*(int *)(local_6d8 + 0x44) * local_6bc + local_6b8) * 3 +
                        *(int *)(local_6d8 + 0x30));
            }
            iVar4 = 0;
            do {
              if (puVar13[iVar4] != (&DAT_0076b340)[iVar4]) {
                switch(uVar3) {
                case 0:
                  local_9c = local_a8 + local_6b8;
                  iStack_98 = iStack_a4 + local_6bc;
                  _local_e4 = CONCAT44(iStack_98,local_9c);
                  break;
                case 1:
                  local_9c = local_a8 + local_6bc;
                  iStack_98 = iStack_a4 + (*(int *)(local_6d8 + 0x44) - local_6b8) + -1;
                  _local_fc = CONCAT44(iStack_98,local_9c);
                  break;
                case 2:
                  local_9c = local_a8 + (*(int *)(local_6d8 + 0x44) - local_6b8) + -1;
                  iStack_98 = iStack_a4 + (*(int *)(local_6d8 + 0x48) - local_6bc) + -1;
                  _local_f0 = CONCAT44(iStack_98,local_9c);
                  break;
                case 3:
                  local_9c = local_a8 + (*(int *)(local_6d8 + 0x48) - local_6bc) + -1;
                  iStack_98 = iStack_a4 + local_6b8;
                  _local_12c = CONCAT44(iStack_98,local_9c);
                  break;
                default:
                  goto switchD_005f10e9_default;
                }
                local_94 = local_6ec;
switchD_005f10e9_default:
                local_38 = uVar20;
                iVar4 = world_getChunkCell256();
                uVar20 = local_38;
                lVar19 = CONCAT44(local_6b0._4_4_,iVar4);
                if ((iVar4 != 0) &&
                   (iVar14 = local_6ec + -1, local_6b0._0_4_ = (uint *)iVar4,
                   lVar19 = CONCAT44(local_6b0._4_4_,iVar4), *(int *)(iVar4 + 0x10) < iVar14))
                goto LAB_005f1217;
                break;
              }
              iVar4 = iVar4 + 1;
            } while (iVar4 < 3);
          }
          goto LAB_005f12f5;
        }
LAB_005f4ab2:
        local_6b0._4_4_ = (int *)((ulonglong)lVar19 >> 0x20);
        local_6b0._0_4_ = (uint *)lVar19;
        local_6b8 = local_6b8 + 1;
      } while (local_6b8 < local_6dc);
    }
  }
  ExceptionList = local_10;
  local_38 = uVar20;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
  while( true ) {
    GameController_voxelAt3D();
    tilemap_writeGlyphColumn();
    iVar14 = iVar14 + -1;
    param_9 = local_6d0;
    uVar20 = local_38;
    lVar19 = CONCAT44(local_6b0._4_4_,(uint *)local_6b0);
    if (iVar14 <= *(int *)((int)(uint *)local_6b0 + 0x10)) break;
LAB_005f1217:
    iVar4 = world_getChunkCell256();
    if (iVar4 == 0) {
      puVar6 = (undefined4 *)&DAT_0076ddfc;
    }
    else {
      iVar11 = *(int *)(iVar4 + 0x10);
      if (iVar14 < iVar11) {
        puVar6 = (undefined4 *)&DAT_0076ddfc;
      }
      else if (iVar14 < *(int *)(iVar4 + 0x1c) + iVar11) {
        puVar6 = (undefined4 *)array_atChecked4(iVar14 - iVar11);
        if ((((*(byte *)((int)puVar6 + 3) & 0x1f) == 0) && (iVar14 < 1)) &&
           ((*(byte *)((int)puVar6 + 3) & 0x40) == 0)) {
          puVar6 = (undefined4 *)&DAT_0076ddf4;
        }
      }
      else {
        puVar6 = (undefined4 *)&DAT_0076ddf4;
        if (0 < iVar14) {
          puVar6 = &DAT_0076ddf8;
        }
      }
    }
    if (((*(byte *)((int)puVar6 + 3) & 0x1f) != 0) &&
       (param_9 = local_6d0, uVar20 = local_38, lVar19 = CONCAT44(local_6b0._4_4_,(uint *)local_6b0)
       , (*(byte *)((int)puVar6 + 3) & 0x1f) != 2)) break;
  }
LAB_005f12f5:
  local_6b0 = lVar19;
  iVar4 = *(int *)(local_6d8 + 0x4c) + -1;
  iVar14 = param_9;
  local_6d4 = iVar4;
  if (-1 < iVar4) {
LAB_005f1310:
    local_38._0_4_ = (int)uVar20;
    switch(uVar3) {
    case 0:
      local_20 = (uint *)(local_a8 + local_6b8);
      uStack_1c = iStack_a4 + local_6bc;
      _local_108 = CONCAT44(uStack_1c,local_20);
      local_18 = (uint *)(local_6ec + iVar4);
      goto switchD_005f131f_default;
    case 1:
      local_20 = (uint *)(local_a8 + local_6bc);
      uStack_1c = iStack_a4 + (*(int *)(local_6d8 + 0x44) - local_6b8) + -1;
      _local_120 = CONCAT44(uStack_1c,local_20);
      param_6 = local_6e8;
      break;
    case 2:
      local_20 = (uint *)(local_a8 + (*(int *)(local_6d8 + 0x44) - local_6b8) + -1);
      uStack_1c = iStack_a4 + (*(int *)(local_6d8 + 0x48) - local_6bc) + -1;
      _local_138 = CONCAT44(uStack_1c,local_20);
      break;
    case 3:
      local_20 = (uint *)(local_a8 + (*(int *)(local_6d8 + 0x48) - local_6bc) + -1);
      uStack_1c = iStack_a4 + local_6b8;
      _local_114 = CONCAT44(uStack_1c,local_20);
      break;
    default:
      goto switchD_005f131f_default;
    }
    local_18 = (uint *)(local_6ec + iVar4);
switchD_005f131f_default:
    if (((local_6b8 < 0) || (local_6bc < 0)) ||
       ((iVar4 < 0 ||
        (((*(int *)(local_6d8 + 0x44) <= local_6b8 || (*(int *)(local_6d8 + 0x48) <= local_6bc)) ||
         (*(int *)(local_6d8 + 0x4c) <= iVar4)))))) {
      local_6b0._4_4_ = (int *)&DAT_0076b340;
    }
    else {
      local_6b0._4_4_ =
           (int *)(((*(int *)(local_6d8 + 0x48) * iVar4 + local_6bc) * *(int *)(local_6d8 + 0x44) +
                   local_6b8) * 3 + *(int *)(local_6d8 + 0x30));
    }
    iVar11 = 0;
    do {
      param_9 = iVar14;
      local_6d4 = iVar4;
      if (*(char *)((int)local_6b0._4_4_ + iVar11) != (&DAT_0076b340)[iVar11]) {
        local_6a4 = (_Container_base0 *)local_18;
        uVar8 = 0x5f15a2;
        uVar5 = uStack_1c;
        local_38 = uVar20;
        iVar11 = world_getChunkCell256();
        if (iVar11 == 0) {
          puVar6 = (undefined4 *)&DAT_0076ddfc;
        }
        else if ((int)local_18 < *(int *)(iVar11 + 0x10)) {
          puVar6 = (undefined4 *)&DAT_0076ddfc;
        }
        else if ((int)local_18 < *(int *)(iVar11 + 0x1c) + *(int *)(iVar11 + 0x10)) {
          uVar5 = 0x5f15e9;
          puVar6 = (undefined4 *)array_atChecked4((int)local_18 - *(int *)(iVar11 + 0x10));
          if ((((*(byte *)((int)puVar6 + 3) & 0x1f) == 0) && ((int)local_6a4 < 1)) &&
             ((*(byte *)((int)puVar6 + 3) & 0x40) == 0)) {
            puVar6 = (undefined4 *)&DAT_0076ddf4;
          }
        }
        else {
          puVar6 = (undefined4 *)&DAT_0076ddf4;
          if (0 < (int)local_18) {
            puVar6 = &DAT_0076ddf8;
          }
        }
        if ((*(byte *)((int)puVar6 + 3) & 0x40) != 0) {
          local_6a4 = (_Container_base0 *)local_18;
          uVar8 = 0x5f1629;
          uVar5 = uStack_1c;
          iVar11 = world_getChunkCell256();
          if (iVar11 == 0) {
            puVar6 = (undefined4 *)&DAT_0076ddfc;
          }
          else if ((int)local_18 < *(int *)(iVar11 + 0x10)) {
            puVar6 = (undefined4 *)&DAT_0076ddfc;
          }
          else if ((int)local_18 < *(int *)(iVar11 + 0x1c) + *(int *)(iVar11 + 0x10)) {
            uVar5 = 0x5f1670;
            puVar6 = (undefined4 *)array_atChecked4((int)local_18 - *(int *)(iVar11 + 0x10));
            if ((((*(byte *)((int)puVar6 + 3) & 0x1f) == 0) && ((int)local_6a4 < 1)) &&
               ((*(byte *)((int)puVar6 + 3) & 0x40) == 0)) {
              puVar6 = (undefined4 *)&DAT_0076ddf4;
            }
          }
          else {
            puVar6 = (undefined4 *)&DAT_0076ddf4;
            if (0 < (int)local_18) {
              puVar6 = &DAT_0076ddf8;
            }
          }
          if (((*(byte *)((int)puVar6 + 3) & 0x1f) != 0) &&
             (uVar20 = local_38, local_6b0 = CONCAT44(local_6b0._4_4_,(uint *)local_6b0),
             (*(byte *)((int)puVar6 + 3) & 0x1f) != 2)) goto LAB_005f4a7e;
        }
        param_9 = local_6d0;
        iVar11 = local_6d4;
        if (((((zone != 1) &&
              (((((zone != 2 && (zone != 6)) && (zone != 3)) &&
                ((zone != 4 && (zone != 5)))) && (zone != 7)))) &&
             ((zone != 9 && (zone != 10)))) && (zone != 0xb)) &&
           ((((zone != 0xc && (zone != 0xd)) && (zone != 0xe)) && (zone != 0xf))))
        goto LAB_005f493b;
        local_708[0] = -1;
        local_708[1] = '\0';
        local_708[2] = 0;
        local_6a8 = (uint *)0x0;
        local_6a4 = (_Container_base0 *)((int)local_6b0._4_4_ + -(int)local_708);
        goto LAB_005f1720;
      }
      iVar11 = iVar11 + 1;
    } while (iVar11 < 3);
    local_6b0 = CONCAT44(local_6b0._4_4_,(uint *)local_6b0);
    if ((local_6cc < iVar4) &&
       (local_6b0 = CONCAT44(local_6b0._4_4_,(uint *)local_6b0), iVar4 < local_6c8)) {
      if (iVar14 != 0) {
        uStack_25 = 0xc0;
        uStack_26 = 0xff;
        local_6a4 = *(_Container_base0 **)(iVar14 + 0x18);
        local_28 = 0xffff;
        uStack_24 = 0;
        local_6a0 = (uint *)CONCAT13(0xc0,(undefined3)local_6a0);
        local_38._4_4_ = local_20;
        uStack_30._0_4_ = uStack_1c;
        uStack_30._4_4_ = local_18;
        uVar5 = map_insertVal_0x18payload();
        uVar20 = CONCAT44(local_38._4_4_,(int)local_38);
        if (*(int *)(iVar14 + 0x1c) == 0x9249248) goto LAB_005f4ae3;
        *(int *)(iVar14 + 0x1c) = *(int *)(iVar14 + 0x1c) + 1;
        *(uint *)((int)local_6a4 + 4) = uVar5;
        **(uint **)(uVar5 + 4) = uVar5;
      }
      goto LAB_005f4a73;
    }
    goto LAB_005f4a7e;
  }
LAB_005f4a91:
  local_6bc = local_6bc + 1;
  iVar4 = local_6d8;
  puVar10 = local_6e0;
  lVar19 = local_6b0;
  if ((int)local_6e0 <= local_6bc) goto LAB_005f4ab2;
  goto LAB_005f0fa4;
  while (local_6a8 = (uint *)((int)local_6a8 + 1), (int)local_6a8 < 3) {
LAB_005f1720:
    if ((local_708 + (int)local_6a8)[(int)((int)local_6b0._4_4_ + -(int)local_708)] !=
        local_708[(int)local_6a8]) {
      local_6fc[0] = '\0';
      local_6fc[1] = -1;
      local_6fc[2] = 0;
      local_6a8 = (uint *)0x0;
      local_6a4 = (_Container_base0 *)((int)local_6b0._4_4_ + -(int)local_6fc);
      goto LAB_005f1ca0;
    }
  }
  local_428 = 1;
  local_460 = '\x01';
  local_45c = 0;
  local_458 = 0;
  local_450 = 0;
  local_448 = (undefined4 *)0x0;
  local_444 = (undefined4 *)0x0;
  local_440 = 0;
  local_43c = 0;
  local_438[0] = 0;
  local_434 = 0;
  local_430 = 0;
  local_42c = 0;
  local_42a = 0;
  local_324 = 0;
  memset(local_424,0,0x100);
  local_320 = 0;
  local_31c = 0;
  local_318 = 0xffffffff;
  local_314 = 0xffffffff;
  uStack_310 = 0xffffffff;
  local_30c = 0;
  local_8 = 0;
  cVar2 = World_computeStructurePlacement(local_6d8,&local_a8,param_3,local_6b8,local_6bc,iVar4,local_490);
  iVar4 = local_6d0;
  if (cVar2 != '\0') {
    local_6a8 = (uint *)(param_6 + 0xc);
    local_6a4 = (_Container_base0 *)((zone == 7) + 1);
    local_490[0] = (uint)local_6a4;
    if ((local_490 < *(uint **)(param_6 + 0x10)) &&
       (puVar10 = (uint *)*local_6a8, param_9 = local_6d0, puVar10 <= local_490)) {
      if (*(int *)(param_6 + 0x10) == *(int *)(param_6 + 0x14)) {
        std_vector_Reserve_grow_188(1);
      }
      puVar1 = *(uint **)(param_6 + 0x10);
      puVar15 = (uint *)((((int)local_490 - (int)puVar10) / 0x188) * 0x188 +
                        *(uint *)(param_6 + 0xc));
      local_8 = CONCAT31(local_8._1_3_,1);
      puVar10 = (uint *)(param_6 + 0xc);
      local_6c0 = puVar1;
      local_6b0._0_4_ = puVar1;
      local_6a4 = (_Container_base0 *)puVar15;
      local_6a0 = puVar1;
      if (puVar1 != (uint *)0x0) {
        *puVar1 = *puVar15;
        puVar1[2] = puVar15[2];
        puVar1[3] = puVar15[3];
        puVar1[4] = puVar15[4];
        puVar1[5] = puVar15[5];
        puVar1[6] = puVar15[6];
        puVar1[7] = puVar15[7];
        puVar1[8] = puVar15[8];
        puVar1[9] = puVar15[9];
        puVar1[10] = puVar15[10];
        puVar1[0xb] = puVar15[0xb];
        *(char *)(puVar1 + 0xc) = (char)puVar15[0xc];
        puVar1[0xd] = puVar15[0xd];
        puVar1[0xe] = puVar15[0xe];
        puVar1[0x10] = puVar15[0x10];
        puVar1[0x11] = puVar15[0x11];
        std_vector_assign_stride0c(puVar15 + 0x12);
        puVar1[0x15] = puVar15[0x15];
        entityState_copy(puVar15 + 0x16);
        puVar1[0x5c] = puVar15[0x5c];
        puVar1[0x5d] = puVar15[0x5d];
        ((uint *)local_6b0)[0x5e] = *(uint *)((int)local_6a4 + 0x178);
        ((uint *)local_6b0)[0x5f] = *(uint *)((int)local_6a4 + 0x17c);
        ((uint *)local_6b0)[0x60] = *(uint *)((int)local_6a4 + 0x180);
        ((uint *)local_6b0)[0x61] = *(uint *)((int)local_6a4 + 0x184);
        puVar10 = local_6a8;
        param_6 = local_6e8;
      }
      puVar10[1] = puVar10[1] + 0x188;
      param_9 = iVar4;
    }
    else {
      if (*(uint **)(param_6 + 0x10) == *(uint **)(param_6 + 0x14)) {
        std_vector_Reserve_grow_188(1);
      }
      p_Var16 = *(_Container_base0 **)(param_6 + 0x10);
      local_8 = CONCAT31(local_8._1_3_,2);
      local_6c0 = (uint *)p_Var16;
      local_6a0 = (uint *)p_Var16;
      if (p_Var16 != (_Container_base0 *)0x0) {
        *(_Container_base0 **)p_Var16 = local_6a4;
        *(uint *)((int)p_Var16 + 8) = local_488;
        *(uint *)((int)p_Var16 + 0xc) = local_484;
        *(uint *)((int)p_Var16 + 0x10) = local_480;
        *(uint *)((int)p_Var16 + 0x14) = local_47c;
        *(uint *)((int)p_Var16 + 0x18) = local_478;
        *(uint *)((int)p_Var16 + 0x1c) = local_474;
        *(uint *)((int)p_Var16 + 0x20) = local_470;
        *(uint *)((int)p_Var16 + 0x24) = local_46c;
        *(uint *)((int)p_Var16 + 0x28) = local_468;
        *(uint *)((int)p_Var16 + 0x2c) = local_464;
        *(char *)((int)p_Var16 + 0x30) = local_460;
        *(uint *)((int)p_Var16 + 0x34) = local_45c;
        *(uint *)((int)p_Var16 + 0x38) = local_458;
        *(uint *)((int)p_Var16 + 0x40) = (uint)local_450;
        *(uint *)((int)p_Var16 + 0x44) = local_450._4_4_;
        local_6a4 = p_Var16;
        std_vector_assign_stride0c(&local_448);
        *(uint *)((int)p_Var16 + 0x54) = local_43c;
        entityState_copy(local_438);
        *(uint *)((int)p_Var16 + 0x170) = local_320;
        *(uint *)((int)p_Var16 + 0x174) = local_31c;
        *(uint *)((int)local_6a4 + 0x178) = local_318;
        *(uint *)((int)local_6a4 + 0x17c) = local_314;
        *(uint *)((int)local_6a4 + 0x180) = uStack_310;
        *(uint *)((int)local_6a4 + 0x184) = local_30c;
        p_Var16 = local_6a4;
      }
      local_6a4 = p_Var16;
      *(int *)(param_6 + 0x10) = *(int *)(param_6 + 0x10) + 0x188;
    }
    local_8 = local_8 & 0xffffff00;
  }
  if (param_9 != 0) {
    local_28 = 0;
    uStack_30._4_4_ = local_18;
    local_6a4 = *(_Container_base0 **)(param_9 + 0x18);
    uStack_24 = 0;
    local_6a0 = (uint *)CONCAT13(0x40,(undefined3)local_6a0);
    uStack_26 = 0;
    uStack_25 = 0x40;
    local_38._4_4_ = local_20;
    uStack_30._0_4_ = uStack_1c;
    uVar5 = map_insertVal_0x18payload();
    if (*(int *)(param_9 + 0x1c) == 0x9249248) {
LAB_005f4ae3:
      std::_Xlength_error("list<T> too long");
    }
    *(int *)(param_9 + 0x1c) = *(int *)(param_9 + 0x1c) + 1;
    *(uint *)((int)local_6a4 + 4) = uVar5;
    **(uint **)(uVar5 + 4) = uVar5;
  }
  tilemap_writeGlyphColumn();
  local_8 = 0xffffffff;
  iVar4 = local_6d4;
  uVar20 = local_38;
  puVar6 = local_448;
  if (local_448 != (undefined4 *)0x0) {
    while( true ) {
      if (puVar6 == local_444) {
        operator_delete(local_448);
      }
      if ((void *)*puVar6 != (void *)0x0) break;
      puVar6 = puVar6 + 3;
    }
    operator_delete((void *)*puVar6);
  }
  goto LAB_005f4a7e;
  while (local_6a8 = (uint *)((int)local_6a8 + 1), (int)local_6a8 < 3) {
LAB_005f1ca0:
    if ((local_6fc + (int)local_6a8)[(int)((int)local_6b0._4_4_ + -(int)local_6fc)] !=
        local_6fc[(int)local_6a8]) {
      local_704[0] = '\0';
      local_704[1] = '\x7f';
      local_704[2] = 0x7f;
      local_6a8 = (uint *)0x0;
      local_6a4 = (_Container_base0 *)((int)local_6b0._4_4_ + -(int)local_704);
      goto LAB_005f1eb0;
    }
  }
  Struct_InitDefaults();
  local_8 = 3;
  cVar2 = World_computeStructurePlacement();
  if (cVar2 != '\0') {
    local_308[0] = 3;
    std_vector_pushBack_0x188(local_308);
  }
  if (param_9 != 0) {
    local_6a4 = *(_Container_base0 **)(param_9 + 0x18);
    local_28 = 0;
    uStack_24 = 0;
    local_6a0 = (uint *)CONCAT13(0x40,(undefined3)local_6a0);
    uStack_26 = 0;
    uStack_25 = 0x40;
    local_38._4_4_ = local_20;
    uStack_30._0_4_ = uStack_1c;
    uStack_30._4_4_ = local_18;
    uVar5 = map_insertVal_0x18payload();
    if (*(int *)(param_9 + 0x1c) == 0x9249248) goto LAB_005f4ae3;
    *(int *)(param_9 + 0x1c) = *(int *)(param_9 + 0x1c) + 1;
    *(uint *)((int)local_6a4 + 4) = uVar5;
    **(uint **)(uVar5 + 4) = uVar5;
  }
  tilemap_writeGlyphColumn();
  local_8 = 0xffffffff;
  uVar20 = local_38;
  local_6b0 = CONCAT44(local_6b0._4_4_,(uint *)local_6b0);
  if (local_2c0 != (_Container_base0 *)0x0) {
    std::_Container_base0::_Orphan_all((_Container_base0 *)&local_2c0);
    local_6a4 = local_2bc;
    p_Var16 = local_2c0;
    while( true ) {
      if (p_Var16 == local_2bc) {
        operator_delete(local_2c0);
      }
      if (*(int *)p_Var16 != 0) break;
      p_Var16 = p_Var16 + 0xc;
    }
    std::_Container_base0::_Orphan_all(p_Var16);
    operator_delete(*(void **)p_Var16);
  }
  goto LAB_005f4a7e;
  while (local_6a8 = (uint *)((int)local_6a8 + 1), (int)local_6a8 < 3) {
LAB_005f1eb0:
    iVar14 = param_9;
    if ((local_704 + (int)local_6a8)[(int)((int)local_6b0._4_4_ + -(int)local_704)] !=
        local_704[(int)local_6a8]) {
      local_70c[0] = -1;
      local_70c[1] = '\x7f';
      local_70c[2] = 0;
      local_6a8 = (uint *)0x0;
      local_6a4 = (_Container_base0 *)((int)local_6b0._4_4_ - (int)local_70c);
      goto LAB_005f2170;
    }
  }
  uVar20 = local_38;
  local_6b0 = CONCAT44(local_6b0._4_4_,(uint *)local_6b0);
  if ((float)local_6e4 <= 0.5) goto LAB_005f4a7e;
  iVar11 = world_getColumnData(local_20,uStack_1c,local_18,param_6);
  if (((*(byte *)(iVar11 + 3) & 0x1f) != 0) &&
     (uVar20 = local_38, local_6b0 = CONCAT44(local_6b0._4_4_,(uint *)local_6b0),
     (*(byte *)(iVar11 + 3) & 0x1f) != 2)) goto LAB_005f4a7e;
  iVar11 = rand();
  uVar20 = local_38;
  if (iVar11 % 5 == 0) {
    local_4c = 0x3f800000;
    uStack_48 = 0x3f800000;
    local_44 = 0x3f800000;
    iVar4 = rand();
    local_78[0] = iVar4 % 3 + 0x29;
    lVar19 = float_to_uint64_round();
    local_d0 = float_to_uint64_round();
    param_6 = local_6e8;
    local_38._4_4_ = (uint *)(((int)local_20 >> 0x1f) << 0x10 | (uint)local_20 >> 0x10);
    local_38._0_4_ = (int)local_20 * 0x10000;
    uStack_30._4_4_ = (uint *)(((int)uStack_1c >> 0x1f) << 0x10 | uStack_1c >> 0x10);
    uStack_30._0_4_ = uStack_1c * 0x10000;
    uStack_24 = ((int)local_18 >> 0x1f) << 0x10 | (uint)local_18 >> 0x10;
    local_28 = 0;
    uStack_26 = SUB41(local_18,0);
    uStack_25 = (undefined1)((uint)local_18 >> 8);
    local_d8 = local_d0 + CONCAT44(local_38._4_4_,(int)local_38);
    local_d0 = local_d0 + CONCAT44(uStack_30._4_4_,(uint)uStack_30);
    local_c8 = lVar19 + CONCAT44(uStack_24,(int)local_18 * 0x10000);
    iVar4 = *(int *)(local_6e8 + 4);
    local_70 = local_d8;
    local_68 = local_d0;
    local_60 = local_c8;
    local_54 = (float)(int)(param_3 * -0x5a);
    local_58 = 0x3e19999a;
    local_40 = 0;
    iVar14 = ChunkBuffer_loadAndNotify();
    uVar20 = CONCAT44(local_38._4_4_,(int)local_38);
    if (*(int *)(param_6 + 8) == 0x38e38e2) goto LAB_005f4ae3;
    *(int *)(param_6 + 8) = *(int *)(param_6 + 8) + 1;
    *(int *)(iVar4 + 4) = iVar14;
    **(int **)(iVar14 + 4) = iVar14;
    iVar14 = local_6d0;
    iVar4 = local_6d4;
  }
  local_38._0_4_ = (int)uVar20;
  if (iVar14 != 0) {
    local_6a4 = *(_Container_base0 **)(iVar14 + 0x18);
    local_28 = 0;
    uStack_24 = 0;
    local_6a0 = (uint *)CONCAT13(0x40,(undefined3)local_6a0);
    uStack_26 = 0;
    uStack_25 = 0x40;
    local_38._4_4_ = local_20;
    uStack_30._0_4_ = uStack_1c;
    uStack_30._4_4_ = local_18;
    uVar5 = map_insertVal_0x18payload();
    uVar20 = CONCAT44(local_38._4_4_,(int)local_38);
    if (*(int *)(iVar14 + 0x1c) == 0x9249248) goto LAB_005f4ae3;
    *(int *)(iVar14 + 0x1c) = *(int *)(iVar14 + 0x1c) + 1;
    *(uint *)((int)local_6a4 + 4) = uVar5;
    **(uint **)(uVar5 + 4) = uVar5;
  }
  goto LAB_005f4a73;
  while (local_6a8 = (uint *)((int)local_6a8 + 1), (int)local_6a8 < 3) {
LAB_005f2170:
    if ((local_70c + (int)local_6a8)[(int)local_6b0._4_4_ - (int)local_70c] !=
        local_70c[(int)local_6a8]) {
      local_714[0] = -1;
      local_714[1] = '\x7f';
      local_714[2] = 0x7f;
      local_6b0._0_4_ = (uint *)0x0;
      local_6a4 = (_Container_base0 *)((int)local_6b0._4_4_ - (int)local_714);
      goto LAB_005f2570;
    }
  }
  Struct_InitDefaults();
  local_8 = 4;
  local_308[0] = 0x13;
  local_6b0 = float_to_uint64_round();
  local_6a4 = (_Container_base0 *)(((int)local_20 >> 0x1f) << 0x10 | (uint)local_20 >> 0x10);
  local_2ec = ((int)local_18 >> 0x1f) << 0x10 | (uint)local_18 >> 0x10;
  local_6a8 = (uint *)((int)local_18 << 0x10);
  local_300 = local_6b0 + CONCAT44(local_6a4,(int)local_20 * 0x10000);
  local_2f8 = local_6b0 +
              CONCAT44(((int)uStack_1c >> 0x1f) << 0x10 | uStack_1c >> 0x10,uStack_1c * 0x10000);
  local_160 = 0x3f800000;
  local_2dc = 0x3f800000;
  local_168 = 0x40000000;
  uStack_164 = 0x40400000;
  local_2e4 = 0x4040000040000000;
  local_2e8 = 0;
  local_2f0 = (int)local_6a8;
  std_vector_pushBack_0x188(local_308);
  Struct_InitDefaults();
  local_8 = CONCAT31(local_8._1_3_,5);
  local_618[0] = 0x14;
  lVar19 = float_to_uint64_round();
  param_6 = local_6e8;
  local_6a4 = (_Container_base0 *)((ulonglong)lVar19 >> 0x20);
  local_5fc = ((int)local_18 >> 0x1f) << 0x10 | (uint)local_18 >> 0x10;
  local_600 = (uint *)((int)local_18 << 0x10);
  lVar19 = lVar19 + CONCAT44(((int)local_20 >> 0x1f) << 0x10 | (uint)local_20 >> 0x10,
                             (int)local_20 * 0x10000);
  local_6a8 = (uint *)lVar19;
  local_60c = (undefined4)((ulonglong)lVar19 >> 0x20);
  local_608 = local_6b0 +
              CONCAT44(((int)uStack_1c >> 0x1f) << 0x10 | uStack_1c >> 0x10,uStack_1c * 0x10000);
  local_6b0._4_4_ = (int *)((ulonglong)local_608 >> 0x20);
  local_13c = 0x3f800000;
  local_5ec = 0x3f800000;
  local_144 = 0x3f800000;
  uStack_140 = 0x3f800000;
  local_5f8 = 0;
  local_5f4 = 0x3f8000003f800000;
  local_610 = local_6a8;
  std_vector_pushBack_0x188(local_618);
  param_9 = local_6d0;
  iVar4 = local_6d4;
  if ((local_6cc < local_6d4) && (local_6d4 < local_6c8)) {
    if (local_6d0 != 0) {
      local_6a4 = *(_Container_base0 **)(local_6d0 + 0x18);
      local_28 = 0;
      uStack_24 = 0;
      local_6a0 = (uint *)CONCAT13(0x40,(undefined3)local_6a0);
      uStack_26 = 0;
      uStack_25 = 0x40;
      local_38._4_4_ = local_20;
      uStack_30._0_4_ = uStack_1c;
      uStack_30._4_4_ = local_18;
      uVar5 = map_insertVal_0x18payload();
      if (*(int *)(param_9 + 0x1c) == 0x9249248) goto LAB_005f4ae3;
      *(int *)(param_9 + 0x1c) = *(int *)(param_9 + 0x1c) + 1;
      *(uint *)((int)local_6a4 + 4) = uVar5;
      **(uint **)(uVar5 + 4) = uVar5;
    }
    tilemap_writeGlyphColumn();
  }
  local_8 = CONCAT31(local_8._1_3_,4);
  goto LAB_005f2494;
  while (local_6b0._0_4_ = (uint *)((int)(uint *)local_6b0 + 1), (int)(uint *)local_6b0 < 3) {
LAB_005f2570:
    if ((local_714 + (int)(uint *)local_6b0)[(int)local_6b0._4_4_ - (int)local_714] !=
        local_714[(int)(uint *)local_6b0]) {
      local_71c._0_2_ = 0x7f7f;
      local_71c._2_1_ = 0;
      local_6b0._0_4_ = (uint *)0x0;
      local_6a4 = (_Container_base0 *)((int)&local_71c - (int)local_6b0._4_4_);
      pcVar12 = (char *)local_6b0._4_4_;
      goto LAB_005f27e0;
    }
  }
  Struct_InitDefaults();
  local_8 = 6;
  iVar4 = rand();
  local_308[0] = iVar4 % 3 + 0x20;
  lVar19 = float_to_uint64_round();
  param_6 = local_6e8;
  local_6b0._0_4_ = (uint *)((ulonglong)lVar19 >> 0x20);
  local_6a4 = (_Container_base0 *)(((int)local_20 >> 0x1f) << 0x10 | (uint)local_20 >> 0x10);
  local_2ec = ((int)local_18 >> 0x1f) << 0x10 | (uint)local_18 >> 0x10;
  local_2f0 = (int)local_18 << 0x10;
  local_300 = lVar19 + CONCAT44(local_6a4,(int)local_20 * 0x10000);
  lVar19 = lVar19 + CONCAT44(((int)uStack_1c >> 0x1f) << 0x10 | uStack_1c >> 0x10,
                             uStack_1c * 0x10000);
  local_6a8 = (uint *)lVar19;
  local_2f8._4_4_ = (undefined4)((ulonglong)lVar19 >> 0x20);
  local_2e8 = param_3;
  local_16c = 0x3f800000;
  local_2dc = 0x3f800000;
  local_174 = 0x40000000;
  uStack_170 = 0x40400000;
  local_2e4 = 0x4040000040000000;
  local_2f8._0_4_ = local_6a8;
  std_vector_pushBack_0x188(local_308);
  param_9 = local_6d0;
  iVar4 = local_6d4;
  if ((local_6cc < local_6d4) && (local_6d4 < local_6c8)) {
    if (local_6d0 != 0) {
      local_28 = 0;
      uStack_30._4_4_ = local_18;
      uStack_24 = 0;
      local_6a0 = (uint *)CONCAT13(0x40,(undefined3)local_6a0);
      uStack_26 = 0;
      uStack_25 = 0x40;
      local_38._4_4_ = local_20;
      uStack_30._0_4_ = uStack_1c;
      list_pushBack_via451e80((int)&local_38 + 4);
    }
    tilemap_writeGlyphColumn();
  }
  local_8 = 0xffffffff;
  uVar20 = local_38;
  local_6b0 = CONCAT44(local_6b0._4_4_,(uint *)local_6b0);
  if (local_2c0 != (_Container_base0 *)0x0) {
    std::_Container_base0::_Orphan_all((_Container_base0 *)&local_2c0);
    std_vector_destroy_ptr_elems_stride3(local_2c0,local_2bc,&local_6c1,local_6a0);
    operator_delete(local_2c0);
  }
  goto LAB_005f4a7e;
  while( true ) {
    local_6b0._0_4_ = (uint *)((int)(uint *)local_6b0 + 1);
    pcVar12 = pcVar12 + 1;
    if (2 < (int)(uint *)local_6b0) break;
LAB_005f27e0:
    if (*pcVar12 != *(char *)((int)((int)&local_71c - (int)local_6b0._4_4_) + (int)pcVar12)) {
      local_6c0 = (uint *)((int)&local_718 - (int)local_6b0._4_4_);
      local_718._0_2_ = 0xffff;
      local_718._2_1_ = 0;
      local_6b0._0_4_ = (uint *)0x0;
      pcVar12 = (char *)local_6b0._4_4_;
      goto LAB_005f2bf0;
    }
  }
  Struct_InitDefaults();
  local_8 = 7;
  local_308[0] = 0xc;
  local_6b0 = float_to_uint64_round();
  local_6a4 = (_Container_base0 *)(((int)local_20 >> 0x1f) << 0x10 | (uint)local_20 >> 0x10);
  local_2ec = ((int)local_18 >> 0x1f) << 0x10 | (uint)local_18 >> 0x10;
  local_6a8 = (uint *)((int)local_18 << 0x10);
  local_300 = local_6b0 + CONCAT44(local_6a4,(int)local_20 * 0x10000);
  local_2f8 = local_6b0 +
              CONCAT44(((int)uStack_1c >> 0x1f) << 0x10 | uStack_1c >> 0x10,uStack_1c * 0x10000);
  local_2f0 = (int)local_6a8;
  local_2e8 = rand();
  local_2e8 = local_2e8 & 0x80000003;
  if ((int)local_2e8 < 0) {
    local_2e8 = (local_2e8 - 1 | 0xfffffffc) + 1;
  }
  local_178 = 0x3f800000;
  local_2dc = 0x3f800000;
  local_180 = 0x40400000;
  uStack_17c = 0x40400000;
  local_2e4 = 0x4040000040400000;
  std_vector_pushBack_0x188(local_308);
  Struct_InitDefaults();
  local_8 = CONCAT31(local_8._1_3_,8);
  local_618[0] = 0x10;
  lVar19 = float_to_uint64_round();
  uVar8 = (uint *)local_6b0;
  local_6a4 = (_Container_base0 *)((ulonglong)lVar19 >> 0x20);
  local_5fc = ((int)local_18 >> 0x1f) << 0x10 | (uint)local_18 >> 0x10;
  local_6c0 = (uint *)((int)local_18 << 0x10);
  lVar19 = lVar19 + CONCAT44(((int)local_20 >> 0x1f) << 0x10 | (uint)local_20 >> 0x10,
                             (int)local_20 * 0x10000);
  local_6a8 = (uint *)lVar19;
  local_60c = (undefined4)((ulonglong)lVar19 >> 0x20);
  local_608 = local_6b0 +
              CONCAT44(((int)uStack_1c >> 0x1f) << 0x10 | uStack_1c >> 0x10,uStack_1c * 0x10000);
  local_610 = local_6a8;
  local_600 = local_6c0;
  local_5f8 = rand();
  param_6 = local_6e8;
  local_5f8 = local_5f8 & 0x80000003;
  if ((int)local_5f8 < 0) {
    local_5f8 = (local_5f8 - 1 | 0xfffffffc) + 1;
  }
  local_148 = 0x3f000000;
  local_5ec = 0x3f000000;
  local_150 = 0x3f800000;
  uStack_14c = 0x3f800000;
  local_5f4 = 0x3f8000003f800000;
  std_vector_pushBack_0x188(local_618);
  uVar20 = float_to_uint64_round();
  local_88._4_4_ = local_6b0._4_4_;
  local_38._4_4_ = (uint *)(((int)local_20 >> 0x1f) << 0x10 | (uint)local_20 >> 0x10);
  local_38._0_4_ = (int)local_20 << 0x10;
  uStack_30._4_4_ = (uint *)(((int)uStack_1c >> 0x1f) << 0x10 | uStack_1c >> 0x10);
  uStack_30._0_4_ = uStack_1c << 0x10;
  uStack_24 = ((int)local_18 >> 0x1f) << 0x10 | (uint)local_18 >> 0x10;
  local_28 = 0;
  uStack_26 = SUB41(local_18,0);
  uStack_25 = (undefined1)((uint)local_18 >> 8);
  local_88._0_4_ = uVar8;
  local_80 = 0;
  local_90 = uVar20;
  puVar6 = (undefined4 *)vec3i64_copyAdd(local_c0,&local_90);
  local_610 = (uint *)*puVar6;
  local_60c = puVar6[1];
  local_608._0_4_ = puVar6[2];
  local_608._4_4_ = puVar6[3];
  local_600 = (uint *)puVar6[4];
  local_5fc = puVar6[5];
  std_vector_pushBack_0x188(local_618);
  local_5f8 = rand();
  param_9 = local_6d0;
  iVar4 = local_6d4;
  local_5f8 = local_5f8 & 0x80000003;
  if ((int)local_5f8 < 0) {
    local_5f8 = (local_5f8 - 1 | 0xfffffffc) + 1;
  }
  if ((local_6cc < local_6d4) && (local_6d4 < local_6c8)) {
    if (local_6d0 != 0) {
      local_28 = 0;
      uStack_30._4_4_ = local_18;
      uStack_24 = 0;
      local_6a0 = (uint *)CONCAT13(0x40,(undefined3)local_6a0);
      uStack_26 = 0;
      uStack_25 = 0x40;
      local_38._4_4_ = local_20;
      uStack_30._0_4_ = uStack_1c;
      list_pushBack_via451e80((int)&local_38 + 4);
    }
    tilemap_writeGlyphColumn();
  }
  local_8 = CONCAT31(local_8._1_3_,7);
LAB_005f2494:
  if (local_5d0 != (void *)0x0) {
    std::_Container_base0::_Orphan_all((_Container_base0 *)&local_5d0);
    std_vector_destroy_ptr_elems_stride3(local_5d0,local_5cc,&local_6c1,local_6a0);
    operator_delete(local_5d0);
  }
  local_8 = 0xffffffff;
  uVar20 = local_38;
  if (local_2c0 != (_Container_base0 *)0x0) {
    std::_Container_base0::_Orphan_all((_Container_base0 *)&local_2c0);
    std_vector_destroy_ptr_elems_stride3(local_2c0,local_2bc,&local_6c1,local_6a0);
    operator_delete(local_2c0);
  }
  goto LAB_005f4a7e;
  while( true ) {
    local_6b0._0_4_ = (uint *)((int)(uint *)local_6b0 + 1);
    pcVar12 = pcVar12 + 1;
    if (2 < (int)(uint *)local_6b0) break;
LAB_005f2bf0:
    iVar4 = iVar11;
    if (*pcVar12 != *(char *)((int)local_6c0 + (int)pcVar12)) {
      local_710[0] = '?';
      local_710[1] = '\0';
      local_710[2] = 0;
      local_6b0._0_4_ = (uint *)0x0;
      local_6c0 = (uint *)((int)local_6b0._4_4_ + -(int)local_710);
      goto LAB_005f2df0;
    }
  }
  local_4c = 0x3f800000;
  uStack_48 = 0x3f800000;
  local_44 = 0x3f800000;
  local_78[0] = 0xd;
  uVar20 = float_to_uint64_round();
  local_38._4_4_ = (uint *)(((int)local_20 >> 0x1f) << 0x10 | (uint)local_20 >> 0x10);
  local_38._0_4_ = (int)local_20 << 0x10;
  uStack_30._4_4_ = (uint *)(((int)uStack_1c >> 0x1f) << 0x10 | uStack_1c >> 0x10);
  uStack_30._0_4_ = uStack_1c << 0x10;
  uStack_24 = ((int)local_18 >> 0x1f) << 0x10 | (uint)local_18 >> 0x10;
  local_28 = 0;
  uStack_26 = SUB41(local_18,0);
  uStack_25 = (undefined1)((uint)local_18 >> 8);
  local_80 = 0;
  local_90 = uVar20;
  local_88 = uVar20;
  plVar7 = (longlong *)vec3i64_copyAdd(local_c0,&local_90);
  local_154 = 0x3ecccccd;
  local_70 = *plVar7;
  local_68 = plVar7[1];
  local_60 = plVar7[2];
  local_44 = 0x3ecccccd;
  local_15c = 0x3f19999a;
  uStack_158 = 0x3f000000;
  local_58 = 0x3dcccccd;
  local_54 = 0.0;
  local_40 = 1;
  local_4c = 0x3f19999a;
  uStack_48 = 0x3f000000;
  list_pushBack_via5c03f0(local_78);
  uVar20 = CONCAT44(local_38._4_4_,(int)local_38);
  uStack_30 = CONCAT44(uStack_30._4_4_,(uint)uStack_30);
  local_6b0 = CONCAT44(local_6b0._4_4_,(uint *)local_6b0);
  if ((iVar11 <= local_6cc) ||
     (uVar20 = CONCAT44(local_38._4_4_,(int)local_38),
     uStack_30 = CONCAT44(uStack_30._4_4_,(uint)uStack_30),
     local_6b0 = CONCAT44(local_6b0._4_4_,(uint *)local_6b0), local_6c8 <= iVar11))
  goto LAB_005f4a7e;
  if (param_9 != 0) {
    local_28 = 0;
    uStack_30._4_4_ = local_18;
    uStack_24 = 0;
    local_6a0 = (uint *)CONCAT13(0x40,(undefined3)local_6a0);
    uStack_26 = 0;
    uStack_25 = 0x40;
    local_38._4_4_ = local_20;
    uStack_30._0_4_ = uStack_1c;
    list_pushBack_via451e80((int)&local_38 + 4);
  }
  local_6f0 = (int *)0x40000000;
  uVar20 = CONCAT44(local_38._4_4_,(int)local_38);
  goto LAB_005f4a73;
  while (local_6b0._0_4_ = (uint *)((int)(uint *)local_6b0 + 1), (int)(uint *)local_6b0 < 3) {
LAB_005f2df0:
    if ((local_710 + (int)(uint *)local_6b0)[(int)local_6b0._4_4_ + -(int)local_710] !=
        local_710[(int)(uint *)local_6b0]) {
      local_700[0] = '\0';
      local_700[1] = '\0';
      local_700[2] = 0xff;
      local_6b0._0_4_ = (uint *)0x0;
      goto LAB_005f2f80;
    }
  }
  local_4c = 0x3f800000;
  uStack_48 = 0x3f800000;
  local_44 = 0x3f800000;
  local_78[0] = 0x30;
  uVar20 = float_to_uint64_round();
  uStack_24 = (uint)((ulonglong)uVar20 >> 0x20);
  local_28 = (undefined2)uVar20;
  uStack_26 = (undefined1)((ulonglong)uVar20 >> 0x10);
  uStack_25 = (undefined1)((ulonglong)uVar20 >> 0x18);
  puVar23 = &local_38;
  puVar13 = local_c0;
  local_38 = uVar20;
  uStack_30 = uVar20;
  vec3ToFixed64();
  plVar7 = (longlong *)vec3i64_copyAdd(puVar13,puVar23);
  local_70 = *plVar7;
  local_68 = plVar7[1];
  local_60 = plVar7[2];
  local_54 = (float)(int)(param_3 * -0x5a);
  local_58 = 0x3d851eb8;
  local_40 = 0;
  list_pushBack_via5c03f0(local_78);
  uVar20 = local_38;
  local_6b0 = CONCAT44(local_6b0._4_4_,(uint *)local_6b0);
  if ((iVar11 <= local_6cc) ||
     (local_6b0 = CONCAT44(local_6b0._4_4_,(uint *)local_6b0), local_6c8 <= iVar11))
  goto LAB_005f4a7e;
  if (param_9 != 0) {
    local_28 = 0;
    uStack_30._4_4_ = local_18;
    uStack_24 = 0;
    local_6a0 = (uint *)CONCAT13(0x40,(undefined3)local_6a0);
    uStack_26 = 0;
    uStack_25 = 0x40;
    local_38._4_4_ = local_20;
    uStack_30._0_4_ = uStack_1c;
    list_pushBack_via451e80((int)&local_38 + 4);
  }
  local_6f8 = 0x40000000;
  uVar20 = local_38;
  goto LAB_005f4a73;
  while (local_6b0._0_4_ = (uint *)((int)(uint *)local_6b0 + 1), (int)(uint *)local_6b0 < 3) {
LAB_005f2f80:
    if ((local_700 + (int)(uint *)local_6b0)[(int)local_6b0._4_4_ - (int)local_700] !=
        local_700[(int)(uint *)local_6b0]) {
      uVar8 = setColor3b();
      cVar2 = color_equals3(uVar8);
      if (cVar2 == '\0') {
        uVar8 = setColor3b();
        uVar24 = 0x5f33ea;
        cVar2 = color_equals3(uVar8);
        if (cVar2 == '\0') {
          uVar8 = setColor3b();
          uVar24 = 0x5f39f7;
          cVar2 = color_equals3(uVar8);
          if (cVar2 != '\0') {
            uVar20 = local_38;
            local_6b0 = CONCAT44(local_6b0._4_4_,(uint *)local_6b0);
            if (zone == 0xd) {
              uVar8 = 0x5f3a14;
              Struct_InitDefaults();
              local_8 = 0xd;
              local_308[0] = 0x4d;
              uVar21 = 0x5f3a31;
              int_toFixed16();
              uVar20 = 0x3fe0000000000000;
              Store_ftol64_result(0x3fe0000000000000);
              Store_ftol64_result(0x3fe0000000000000);
              uVar8 = vec6_set(uVar20,uVar21,uVar24,uVar8);
              puVar23 = &local_90;
              vec3ToFixed64();
              uVar8 = vec3i64_copyAdd(puVar23,uVar8);
              vec6_copy(uVar8);
              local_2e8 = -param_3;
              uVar8 = setVec3();
              vec3_copy(uVar8);
              std_vector_pushBack_0x188(local_308);
              if (param_9 != 0) {
                clearTwoFields();
                uVar24 = 0x40;
                uVar8 = setColor3b(0,0,0);
                uVar8 = setColor4b(uVar8,uVar24);
                color_copy4(uVar8);
                vec3_copy(&local_20);
                list_pushBack_via451e80((int)&local_38 + 4);
              }
              setColor3b();
              goto LAB_005f3377;
            }
            goto LAB_005f4a7e;
          }
          uVar8 = setColor3b();
          uVar24 = 0x5f3b6d;
          cVar2 = color_equals3(uVar8);
          if (cVar2 == '\0') {
            uVar8 = setColor3b();
            uVar24 = 0x5f3fc4;
            cVar2 = color_equals3(uVar8);
            if (cVar2 == '\0') {
              uVar8 = setColor3b();
              cVar2 = color_equals3(uVar8);
              if (cVar2 == '\0') goto LAB_005f493b;
              pvVar9 = operator_new(0x10f0);
              if (pvVar9 == (void *)0x0) {
                puVar10 = (uint *)0x0;
              }
              else {
                puVar10 = (uint *)cube::Spawn::ctor_0();
              }
              puVar10[10] = 3;
              local_6a0 = puVar10;
              uVar5 = rand();
              uVar5 = uVar5 & 0x80000003;
              if ((int)uVar5 < 0) {
                uVar5 = (uVar5 - 1 | 0xfffffffc) + 1;
              }
              puVar10[0xb] = uVar5;
              puVar10[0x15] = (uint)(float)(int)((2 - param_3) * 0x5a);
              uVar8 = setVec3();
              vec3i64_setFromGen(uVar8);
              puVar23 = &local_90;
              puVar13 = local_c0;
              vec3ToFixed64();
              uVar8 = vec3i64_copyAdd(puVar13,puVar23);
              vec6_copy(uVar8);
              *(undefined2 *)(puVar10 + 0xd4) = 4;
              *(char *)((int)puVar10 + 0x35d) = '\x06';
              local_6a8 = (uint *)arrayElem_stride4(1);
              uVar24 = 0;
              uVar8 = 0x5f426b;
              local_6a4 = (_Container_base0 *)arrayElem_stride4(0);
              uVar20 = CONCAT44(*local_6a8,0x5f4283);
              int_toFixed16();
              int_toFixed16();
              uVar5 = Terrain_blockTypeAtTime(uVar20,uVar8,uVar24);
              puVar10[0xd] = uVar5;
              switch(zone) {
              case 6:
                *(char *)(puVar10 + 0xc) = -0x7d;
                break;
              case 7:
                puVar10[0xd] = 0x14;
                uVar5 = rand();
                uVar5 = uVar5 & 0x80000001;
                if ((int)uVar5 < 0) {
                  uVar5 = (uVar5 - 1 | 0xfffffffe) + 1;
                }
                puVar10[0xb] = uVar5 + 2;
                *(char *)(puVar10 + 0xc) = -0x77;
                break;
              case 9:
                ((char *)((int)puVar10 + 0x7a))[0] = '@';
                ((char *)((int)puVar10 + 0x7a))[1] = '\0';
                puVar10[0xd] = 0x14;
                puVar10[0xb] = 2;
                *(char *)(puVar10 + 0xc) = '\x01';
                *(char *)(puVar10 + 0x232) = '\x03';
                iVar4 = rand();
                *(char *)((int)puVar10 + 0x8c9) = (char)(iVar4 % 3) + '\x0f';
                iVar4 = rand();
                *(char *)(puVar10 + 0x235) = (char)(iVar4 % 5);
                *(short *)(puVar10 + 0x236) = (short)puVar10[0xd];
                *(char *)((int)puVar10 + 0x8d5) = '\x01';
                *(char *)(puVar10 + 0x1a6) = '\a';
                iVar4 = rand();
                *(char *)(puVar10 + 0x1a9) = (char)(iVar4 % 5);
                *(short *)(puVar10 + 0x1aa) = (short)puVar10[0xd];
                *(char *)((int)puVar10 + 0x6a5) = '\x01';
                *(char *)(puVar10 + 0xd4) = '\x04';
                iVar4 = rand();
                *(char *)(puVar10 + 0xd7) = (char)(iVar4 % 5);
                *(short *)(puVar10 + 0xd8) = (short)puVar10[0xd];
                *(char *)((int)puVar10 + 0x35d) = '\x01';
                *(char *)(puVar10 + 0x11a) = '\x06';
                iVar4 = rand();
                *(char *)(puVar10 + 0x11d) = (char)(iVar4 % 5);
                *(short *)(puVar10 + 0x11e) = (short)puVar10[0xd];
                *(char *)((int)puVar10 + 0x475) = '\x01';
                *(char *)(puVar10 + 0x160) = '\x05';
                iVar4 = rand();
                *(char *)(puVar10 + 0x163) = (char)(iVar4 % 5);
                *(short *)(puVar10 + 0x164) = (short)puVar10[0xd];
                *(char *)((int)puVar10 + 0x58d) = '\x01';
                break;
              case 10:
                ((char *)((int)puVar10 + 0x7a))[0] = '@';
                ((char *)((int)puVar10 + 0x7a))[1] = '\0';
                puVar10[0xd] = 0x14;
                puVar10[0xb] = 2;
                *(char *)(puVar10 + 0xc) = '\x02';
                *(char *)(puVar10 + 0x232) = '\x03';
                uVar5 = rand();
                uVar5 = uVar5 & 0x80000001;
                if ((int)uVar5 < 0) {
                  uVar5 = (uVar5 - 1 | 0xfffffffe) + 1;
                }
                *(char *)((int)puVar10 + 0x8c9) = (char)uVar5 + '\x06';
                iVar4 = rand();
                *(char *)(puVar10 + 0x235) = (char)(iVar4 % 5);
                *(short *)(puVar10 + 0x236) = (short)puVar10[0xd];
                *(char *)((int)puVar10 + 0x8d5) = '\x02';
                *(char *)(puVar10 + 0x1a6) = '\a';
                iVar4 = rand();
                *(char *)(puVar10 + 0x1a9) = (char)(iVar4 % 5);
                *(short *)(puVar10 + 0x1aa) = (short)puVar10[0xd];
                *(char *)((int)puVar10 + 0x6a5) = '\x1a';
                *(char *)(puVar10 + 0xd4) = '\x04';
                iVar4 = rand();
                *(char *)(puVar10 + 0xd7) = (char)(iVar4 % 5);
                *(short *)(puVar10 + 0xd8) = (short)puVar10[0xd];
                *(char *)((int)puVar10 + 0x35d) = '\x1a';
                *(char *)(puVar10 + 0x11a) = '\x06';
                iVar4 = rand();
                *(char *)(puVar10 + 0x11d) = (char)(iVar4 % 5);
                *(short *)(puVar10 + 0x11e) = (short)puVar10[0xd];
                *(char *)((int)puVar10 + 0x475) = '\x1a';
                *(char *)(puVar10 + 0x160) = '\x05';
                iVar4 = rand();
                *(char *)(puVar10 + 0x163) = (char)(iVar4 % 5);
                *(short *)(puVar10 + 0x164) = (short)puVar10[0xd];
                *(char *)((int)puVar10 + 0x58d) = '\x1a';
                break;
              case 0xb:
                ((char *)((int)puVar10 + 0x7a))[0] = '@';
                ((char *)((int)puVar10 + 0x7a))[1] = '\0';
                puVar10[0xd] = 0x14;
                puVar10[0xb] = 2;
                *(char *)(puVar10 + 0xc) = '\x04';
                *(undefined2 *)(puVar10 + 0x232) = 0x503;
                iVar4 = rand();
                *(char *)(puVar10 + 0x235) = (char)(iVar4 % 5);
                *(short *)(puVar10 + 0x236) = (short)puVar10[0xd];
                *(char *)((int)puVar10 + 0x8d5) = '\x01';
                *(char *)(puVar10 + 0x1a6) = '\a';
                iVar4 = rand();
                *(char *)(puVar10 + 0x1a9) = (char)(iVar4 % 5);
                *(short *)(puVar10 + 0x1aa) = (short)puVar10[0xd];
                *(char *)((int)puVar10 + 0x6a5) = '\x1b';
                *(char *)(puVar10 + 0xd4) = '\x04';
                iVar4 = rand();
                *(char *)(puVar10 + 0xd7) = (char)(iVar4 % 5);
                *(short *)(puVar10 + 0xd8) = (short)puVar10[0xd];
                *(char *)((int)puVar10 + 0x35d) = '\x1b';
                *(char *)(puVar10 + 0x11a) = '\x06';
                iVar4 = rand();
                *(char *)(puVar10 + 0x11d) = (char)(iVar4 % 5);
                *(short *)(puVar10 + 0x11e) = (short)puVar10[0xd];
                *(char *)((int)puVar10 + 0x475) = '\x1b';
                *(char *)(puVar10 + 0x160) = '\x05';
                iVar4 = rand();
                *(char *)(puVar10 + 0x163) = (char)(iVar4 % 5);
                *(short *)(puVar10 + 0x164) = (short)puVar10[0xd];
                *(char *)((int)puVar10 + 0x58d) = '\x1b';
                break;
              case 0xc:
                ((char *)((int)puVar10 + 0x7a))[0] = '@';
                ((char *)((int)puVar10 + 0x7a))[1] = '\0';
                puVar10[0xd] = 0x14;
                puVar10[0xb] = 2;
                *(char *)(puVar10 + 0xc) = '\x03';
                *(undefined2 *)(puVar10 + 0x232) = 0xa03;
                iVar4 = rand();
                *(char *)(puVar10 + 0x235) = (char)(iVar4 % 5);
                *(short *)(puVar10 + 0x236) = (short)puVar10[0xd];
                *(char *)((int)puVar10 + 0x8d5) = '\x02';
                *(char *)(puVar10 + 0x1a6) = '\a';
                iVar4 = rand();
                *(char *)(puVar10 + 0x1a9) = (char)(iVar4 % 5);
                *(short *)(puVar10 + 0x1aa) = (short)puVar10[0xd];
                *(char *)((int)puVar10 + 0x6a5) = '\x19';
                *(char *)(puVar10 + 0xd4) = '\x04';
                iVar4 = rand();
                *(char *)(puVar10 + 0xd7) = (char)(iVar4 % 5);
                *(short *)(puVar10 + 0xd8) = (short)puVar10[0xd];
                *(char *)((int)puVar10 + 0x35d) = '\x19';
                *(char *)(puVar10 + 0x11a) = '\x06';
                iVar4 = rand();
                *(char *)(puVar10 + 0x11d) = (char)(iVar4 % 5);
                *(short *)(puVar10 + 0x11e) = (short)puVar10[0xd];
                *(char *)((int)puVar10 + 0x475) = '\x19';
                *(char *)(puVar10 + 0x160) = '\x05';
                iVar4 = rand();
                *(char *)(puVar10 + 0x163) = (char)(iVar4 % 5);
                *(short *)(puVar10 + 0x164) = (short)puVar10[0xd];
                *(char *)((int)puVar10 + 0x58d) = '\x19';
                break;
              case 0xd:
                *(char *)(puVar10 + 0xc) = -0x7b;
                break;
              case 0xe:
                *(char *)(puVar10 + 0xc) = -0x7a;
                break;
              case 0xf:
                *(char *)(puVar10 + 0xc) = -0x79;
              }
              local_6c0 = operator_new(0xc);
              local_8 = 0x12;
              if (local_6c0 == (uint *)0x0) {
                local_6b0._4_4_ = (int *)0x0;
              }
              else {
                local_6b0._4_4_ = (int *)cube::SequentialBehavior::ctor_1();
              }
              local_8 = 0xffffffff;
              local_6c0 = operator_new(0x14);
              local_8 = 0x13;
              if (local_6c0 == (uint *)0x0) {
                local_6c0 = (uint *)0x0;
              }
              else {
                local_6c0 = (uint *)cube::CombatBehavior::ctor_0(0x41a00000);
              }
              local_8 = 0xffffffff;
              list_pushBack_via583cb0(&local_6c0);
              local_6c0 = operator_new(4);
              local_8 = 0x14;
              if (local_6c0 == (uint *)0x0) {
                local_6c0 = (uint *)0x0;
              }
              else {
                local_6c0 = (uint *)cube::LookAtPlayerBehavior::ctor_0();
              }
              local_8 = 0xffffffff;
              list_pushBack_via583cb0(&local_6c0);
              local_6c0 = operator_new(0x1c);
              local_8 = 0x15;
              if (local_6c0 == (uint *)0x0) {
                local_6b0._0_4_ = (uint *)0x0;
              }
              else {
                local_6b0._0_4_ = (uint *)cube::WalkPathBehavior::ctor_1(0x40000000);
              }
              local_8 = 0xffffffff;
              std_vector_push_back_5bf4f0(puVar10 + 4);
              local_6c0 = (uint *)local_6b0;
              list_pushBack_via583cb0(&local_6c0);
              puVar10[0x427] = (uint)local_6b0._4_4_;
              std_vector_push_back_4byte(&local_6a0);
              iVar4 = local_6d4;
              uVar20 = local_38;
              local_6b0 = CONCAT44(local_6b0._4_4_,(uint *)local_6b0);
              if ((local_6d4 <= local_6cc) ||
                 (local_6b0 = CONCAT44(local_6b0._4_4_,(uint *)local_6b0), local_6c8 <= local_6d4))
              goto LAB_005f4a7e;
              if (param_9 != 0) {
                clearTwoFields();
                uVar24 = 0x40;
                uVar8 = setColor3b(0,0,0);
                uVar8 = setColor4b(uVar8,uVar24);
                color_copy4(uVar8);
                vec3_copy(&local_20);
                list_pushBack_via451e80((int)&local_38 + 4);
              }
              setColor3b();
              setColor4b();
              arrayElem_stride4();
              uVar20 = local_38;
              goto LAB_005f4a73;
            }
            Struct_InitDefaults();
            local_8 = 0x11;
            uVar8 = 0x5f3fe4;
            iVar14 = rand();
            local_308[0] = iVar14 % 9 + 0x38;
            uVar21 = 0x5f4001;
            int_toFixed16();
            uVar20 = 0x3fe0000000000000;
            Store_ftol64_result(0x3fe0000000000000);
            Store_ftol64_result(0x3fe0000000000000);
            uVar8 = vec6_set(uVar20,uVar21,uVar24,uVar8);
            puVar23 = &local_90;
            vec3ToFixed64();
            uVar8 = vec3i64_copyAdd(puVar23,uVar8);
            vec6_copy(uVar8);
            local_2e8 = rand();
            local_2e8 = local_2e8 & 0x80000003;
            if ((int)local_2e8 < 0) {
              local_2e8 = (local_2e8 - 1 | 0xfffffffc) + 1;
            }
            uVar8 = setVec3();
            vec3_copy(uVar8);
            std_vector_pushBack_0x188(local_308);
            if ((local_6cc < iVar11) && (iVar11 < local_6c8)) {
              if (param_9 != 0) {
                clearTwoFields();
                uVar24 = 0x40;
                uVar8 = setColor3b(0,0,0);
                uVar8 = setColor4b(uVar8,uVar24);
                color_copy4(uVar8);
                vec3_copy(&local_20);
                list_pushBack_via451e80((int)&local_38 + 4);
              }
              setColor3b();
              goto LAB_005f3377;
            }
          }
          else if (zone == 0xd) {
            uVar8 = 0x5f3b8c;
            Struct_InitDefaults();
            local_8 = 0xe;
            local_308[0] = 0x48;
            uVar21 = 0x5f3ba9;
            int_toFixed16();
            uVar20 = 0x3fe0000000000000;
            Store_ftol64_result(0x3fe0000000000000);
            Store_ftol64_result(0x3fe0000000000000);
            uVar8 = vec6_set(uVar20,uVar21,uVar24,uVar8);
            puVar23 = &local_90;
            vec3ToFixed64();
            uVar8 = vec3i64_copyAdd(puVar23,uVar8);
            vec6_copy(uVar8);
            local_2e8 = -param_3;
            uVar8 = setVec3();
            vec3_copy(uVar8);
            std_vector_pushBack_0x188(local_308);
            if ((local_6cc < iVar11) && (iVar11 < local_6c8)) {
              if (param_9 != 0) {
                clearTwoFields();
                uVar24 = 0x40;
                uVar8 = setColor3b(0,0,0);
                uVar8 = setColor4b(uVar8,uVar24);
                color_copy4(uVar8);
                vec3_copy(&local_20);
                list_pushBack_via451e80((int)&local_38 + 4);
              }
              setColor3b();
              goto LAB_005f3377;
            }
          }
          else if (zone == 0xe) {
            uVar8 = 0x5f3cf1;
            Struct_InitDefaults();
            local_8 = 0xf;
            local_308[0] = 0x4c;
            uVar21 = 0x5f3d0e;
            int_toFixed16();
            uVar20 = 0x3fe0000000000000;
            Store_ftol64_result(0x3fe0000000000000);
            Store_ftol64_result(0x3fe0000000000000);
            uVar8 = vec6_set(uVar20,uVar21,uVar24,uVar8);
            puVar23 = &local_90;
            vec3ToFixed64();
            uVar8 = vec3i64_copyAdd(puVar23,uVar8);
            vec6_copy(uVar8);
            local_2e8 = -param_3;
            uVar8 = setVec3();
            vec3_copy(uVar8);
            std_vector_pushBack_0x188(local_308);
            if ((local_6cc < iVar11) && (iVar11 < local_6c8)) {
              if (param_9 != 0) {
                clearTwoFields();
                uVar24 = 0x40;
                uVar8 = setColor3b(0,0,0);
                uVar8 = setColor4b(uVar8,uVar24);
                color_copy4(uVar8);
                vec3_copy(&local_20);
                list_pushBack_via451e80((int)&local_38 + 4);
              }
              setColor3b();
              goto LAB_005f3377;
            }
          }
          else {
            uVar20 = local_38;
            local_6b0 = CONCAT44(local_6b0._4_4_,(uint *)local_6b0);
            if (zone != 0xf) goto LAB_005f4a7e;
            uVar8 = 0x5f3e56;
            Struct_InitDefaults();
            local_8 = 0x10;
            local_308[0] = 0x4a;
            uVar21 = 0x5f3e73;
            int_toFixed16();
            uVar20 = 0x3fe0000000000000;
            Store_ftol64_result(0x3fe0000000000000);
            Store_ftol64_result(0x3fe0000000000000);
            uVar8 = vec6_set(uVar20,uVar21,uVar24,uVar8);
            puVar23 = &local_90;
            vec3ToFixed64();
            uVar8 = vec3i64_copyAdd(puVar23,uVar8);
            vec6_copy(uVar8);
            local_2e8 = -param_3;
            uVar8 = setVec3();
            vec3_copy(uVar8);
            std_vector_pushBack_0x188(local_308);
            if ((local_6cc < iVar11) && (iVar11 < local_6c8)) {
              if (param_9 != 0) {
                clearTwoFields();
                uVar24 = 0x40;
                uVar8 = setColor3b(0,0,0);
                uVar8 = setColor4b(uVar8,uVar24);
                color_copy4(uVar8);
                vec3_copy(&local_20);
                list_pushBack_via451e80((int)&local_38 + 4);
              }
              setColor3b();
              goto LAB_005f3377;
            }
          }
        }
        else if (zone == 0xd) {
          uVar8 = 0x5f3409;
          Struct_InitDefaults();
          local_8 = 10;
          local_308[0] = 0x47;
          uVar21 = 0x5f3426;
          int_toFixed16();
          uVar20 = 0x3fe0000000000000;
          Store_ftol64_result(0x3fe0000000000000);
          Store_ftol64_result(0x3fe0000000000000);
          uVar8 = vec6_set(uVar20,uVar21,uVar24,uVar8);
          puVar23 = &local_90;
          vec3ToFixed64();
          uVar8 = vec3i64_copyAdd(puVar23,uVar8);
          vec6_copy(uVar8);
          local_2e8 = -param_3;
          uVar8 = setVec3();
          vec3_copy(uVar8);
          std_vector_pushBack_0x188(local_308);
          if ((local_6cc < iVar11) && (iVar11 < local_6c8)) {
            if (param_9 != 0) {
              clearTwoFields();
              uVar24 = 0x40;
              uVar8 = setColor3b(0,0,0);
              uVar8 = setColor4b(uVar8,uVar24);
              color_copy4(uVar8);
              vec3_copy(&local_20);
              list_pushBack_via451e80((int)&local_38 + 4);
            }
            setColor3b();
            goto LAB_005f3377;
          }
        }
        else if (zone == 0xe) {
          uVar8 = 0x5f356e;
          Struct_InitDefaults();
          local_8 = 0xb;
          local_308[0] = 0x4b;
          uVar21 = 0x5f358b;
          int_toFixed16();
          uVar20 = 0x3fe0000000000000;
          Store_ftol64_result(0x3fe0000000000000);
          Store_ftol64_result(0x3fe0000000000000);
          uVar8 = vec6_set(uVar20,uVar21,uVar24,uVar8);
          puVar23 = &local_90;
          vec3ToFixed64();
          uVar8 = vec3i64_copyAdd(puVar23,uVar8);
          vec6_copy(uVar8);
          local_2e8 = -param_3;
          uVar8 = setVec3();
          vec3_copy(uVar8);
          std_vector_pushBack_0x188(local_308);
          if ((local_6cc < iVar11) && (iVar11 < local_6c8)) {
            if (param_9 != 0) {
              clearTwoFields();
              uVar24 = 0x40;
              uVar8 = setColor3b(0,0,0);
              uVar8 = setColor4b(uVar8,uVar24);
              color_copy4(uVar8);
              vec3_copy(&local_20);
              list_pushBack_via451e80((int)&local_38 + 4);
            }
            setColor3b();
            goto LAB_005f3377;
          }
        }
        else {
          if (zone != 0xf) {
            pvVar9 = operator_new(0x10f0);
            if (pvVar9 == (void *)0x0) {
              local_6a8 = (uint *)0x0;
            }
            else {
              local_6a8 = (uint *)cube::Spawn::ctor_0();
            }
            local_6a8[10] = 6;
            local_6a8[0xb] = (zone != 10) + 0x8d;
            local_6a8[0x15] = (uint)(float)(int)((2 - param_3) * 0x5a);
            local_6c0 = local_6a8;
            uVar8 = setVec3();
            vec3i64_setFromGen(uVar8);
            puVar23 = &local_90;
            puVar13 = local_c0;
            vec3ToFixed64();
            uVar8 = vec3i64_copyAdd(puVar13,puVar23);
            vec6_copy(uVar8);
            local_6b0._0_4_ = (uint *)arrayElem_stride4(1);
            uVar24 = 0;
            uVar8 = 0x5f38fe;
            local_6b0._4_4_ = (int *)arrayElem_stride4(0);
            uVar20 = CONCAT44(*(uint *)local_6b0,0x5f3916);
            int_toFixed16();
            int_toFixed16();
            uVar5 = Terrain_blockTypeAtTime(uVar20,uVar8,uVar24);
            local_6a8[0xd] = uVar5;
            std_vector_push_back_4byte(&local_6c0);
            if (param_9 != 0) {
              clearTwoFields();
              uVar24 = 0x40;
              uVar8 = setColor3b(0,0,0);
              uVar8 = setColor4b(uVar8,uVar24);
              color_copy4(uVar8);
              vec3_copy(&local_20);
              list_pushBack_via451e80((int)&local_38 + 4);
            }
            setColor3b();
            setColor4b();
            arrayElem_stride4();
            uVar20 = local_38;
            goto LAB_005f4a73;
          }
          uVar8 = 0x5f36d3;
          Struct_InitDefaults();
          local_8 = 0xc;
          local_308[0] = 0x49;
          uVar21 = 0x5f36f0;
          int_toFixed16();
          uVar20 = 0x3fe0000000000000;
          Store_ftol64_result(0x3fe0000000000000);
          Store_ftol64_result(0x3fe0000000000000);
          uVar8 = vec6_set(uVar20,uVar21,uVar24,uVar8);
          puVar23 = &local_90;
          vec3ToFixed64();
          uVar8 = vec3i64_copyAdd(puVar23,uVar8);
          vec6_copy(uVar8);
          local_2e8 = -param_3;
          uVar8 = setVec3();
          vec3_copy(uVar8);
          std_vector_pushBack_0x188(local_308);
          if ((local_6cc < iVar11) && (iVar11 < local_6c8)) {
            if (param_9 != 0) {
              clearTwoFields();
              uVar24 = 0x40;
              uVar8 = setColor3b(0,0,0);
              uVar8 = setColor4b(uVar8,uVar24);
              color_copy4(uVar8);
              vec3_copy(&local_20);
              list_pushBack_via451e80((int)&local_38 + 4);
            }
            setColor3b();
            goto LAB_005f3377;
          }
        }
      }
      else {
        uVar20 = local_38;
        local_6b0 = CONCAT44(local_6b0._4_4_,(uint *)local_6b0);
        if ((float)local_6e4 <= 0.5) goto LAB_005f4a7e;
        Struct_InitDefaults();
        local_8 = 9;
        cVar2 = World_computeStructurePlacement();
        if (cVar2 != '\0') {
          iVar14 = rand();
          local_308[0] = iVar14 % 3 + 0x2f;
          std_vector_pushBack_0x188(local_308);
        }
        if ((iVar11 <= local_6cc) || (local_6c8 <= iVar11)) goto LAB_005f33b0;
        if (param_9 != 0) {
          clearTwoFields();
          uVar24 = 0x40;
          uVar8 = setColor3b(0,0,0);
          uVar8 = setColor4b(uVar8,uVar24);
          color_copy4(uVar8);
          vec3_copy(&local_20);
          list_pushBack_via451e80((int)&local_38 + 4);
        }
        setColor3b();
LAB_005f3377:
        setColor4b();
        arrayElem_stride4();
        arrayElem_stride4(1);
        arrayElem_stride4();
        tilemap_writeGlyphColumn();
      }
LAB_005f33b0:
      local_8 = 0xffffffff;
      Member_Destroy();
      uVar20 = local_38;
      local_6b0 = CONCAT44(local_6b0._4_4_,(uint *)local_6b0);
      goto LAB_005f4a7e;
    }
  }
  if (zone == 2) {
    local_4c = 0x3f800000;
    uStack_48 = 0x3f800000;
    local_44 = 0x3f800000;
    local_40 = zone;
    local_78[0] = 0x21;
    uVar22 = CONCAT44(0x5f2fe0,uVar8);
    uVar20 = float_to_uint64_round();
    uVar21 = 0x3fe0000000000000;
    Store_ftol64_result(0x3fe0000000000000);
    Store_ftol64_result(0x3fe0000000000000);
    uVar8 = vec6_set(uVar21,uVar22,uVar20);
    puVar23 = &local_90;
    vec3ToFixed64();
    uVar8 = vec3i64_copyAdd(puVar23,uVar8);
    vec6_copy(uVar8);
    local_54 = (float)(int)((-1 - param_3) * 0x5a);
    local_58 = 0x3dcccccd;
    local_40 = 0;
    list_pushBack_via5c03f0(local_78);
    iVar11 = local_6d4;
  }
  else {
    if (zone == 6) {
      uVar8 = 0x5f308f;
      Struct_InitScaleDefaults();
      local_78[0] = 0x25;
    }
    else if (zone == 3) {
      uVar8 = 0x5f30a8;
      Struct_InitScaleDefaults();
      local_78[0] = 0x22;
    }
    else if (zone == 5) {
      uVar8 = 0x5f30be;
      Struct_InitScaleDefaults();
      local_78[0] = 0x24;
    }
    else if (zone == 4) {
      uVar8 = 0x5f30d4;
      Struct_InitScaleDefaults();
      local_78[0] = 0x23;
    }
    else if (zone == 0xd) {
      uVar8 = 0x5f30ea;
      Struct_InitScaleDefaults();
      local_78[0] = 0x26;
    }
    else if (zone == 0xe) {
      uVar8 = 0x5f3100;
      Struct_InitScaleDefaults();
      local_78[0] = 0x27;
    }
    else {
      if (zone != 0xf) goto LAB_005f31cd;
      uVar8 = 0x5f311a;
      Struct_InitScaleDefaults();
      local_78[0] = 0x28;
    }
    uVar21 = 0xbfe0000000000000;
    Store_ftol64_result(0xbfe0000000000000);
    uVar20 = 0x3fe0000000000000;
    Store_ftol64_result(0x3fe0000000000000);
    Store_ftol64_result(0x3fe0000000000000);
    uVar8 = vec6_set(uVar20,uVar21,uVar5,uVar8);
    puVar23 = &local_90;
    vec3ToFixed64();
    uVar8 = vec3i64_copyAdd(puVar23,uVar8);
    vec6_copy(uVar8);
    local_54 = (float)(int)((-1 - param_3) * 0x5a);
    local_58 = 0x3dcccccd;
    local_40 = 0;
    list_pushBack_via5c03f0(local_78);
  }
LAB_005f31cd:
  iVar4 = iVar11;
  uVar20 = local_38;
  local_6b0 = CONCAT44(local_6b0._4_4_,(uint *)local_6b0);
  if ((iVar11 <= local_6cc) ||
     (local_6b0 = CONCAT44(local_6b0._4_4_,(uint *)local_6b0), local_6c8 <= iVar11))
  goto LAB_005f4a7e;
  if (param_9 != 0) {
    clearTwoFields();
    uVar24 = 0x40;
    uVar8 = setColor3b(0,0,0);
    uVar8 = setColor4b(uVar8,uVar24);
    color_copy4(uVar8);
    vec3_copy(&local_20);
    list_pushBack_via451e80((int)&local_38 + 4);
  }
  setColor3b();
LAB_005f4a46:
  setColor4b();
  arrayElem_stride4();
  arrayElem_stride4(1);
  arrayElem_stride4();
  iVar4 = iVar11;
  uVar20 = local_38;
LAB_005f4a73:
  local_38 = uVar20;
  tilemap_writeGlyphColumn();
  param_9 = iVar14;
  uVar20 = local_38;
  local_6b0 = CONCAT44(local_6b0._4_4_,(uint *)local_6b0);
LAB_005f4a7e:
  iVar4 = iVar4 + -1;
  iVar14 = param_9;
  local_6d4 = iVar4;
  if (iVar4 < 0) goto LAB_005f4a91;
  goto LAB_005f1310;
LAB_005f493b:
  iVar11 = iVar4;
  if (zone == 8) {
    uVar8 = setColor3b();
    cVar2 = color_equals3(uVar8);
    if (cVar2 != '\0') {
      if (iVar14 != 0) {
        clearTwoFields();
        uVar24 = 2;
        uVar8 = setColor3b(0xff,0xff,0xff);
        uVar8 = setColor4b(uVar8,uVar24);
        color_copy4(uVar8);
        vec3_copy(&local_20);
        list_pushBack_via451e80((int)&local_38 + 4);
      }
      setColor3b();
      goto LAB_005f4a46;
    }
  }
  if (iVar14 != 0) {
    clearTwoFields();
    uVar8 = setColor4b(local_6b0._4_4_,param_4 | 0x40);
    color_copy4(uVar8);
    vec3_copy(&local_20);
    list_pushBack_via451e80((int)&local_38 + 4);
  }
  goto LAB_005f4a46;
}




/* [AUDIT] proposed: WorldInfo_mapInsertEntry  (confidence: med)
 * purpose: Inserts an entry into a WorldInfo map/list via map_insertVec4Node
 * vars: dungeon value; map_insertVec4Node node insert
 */
/* Global::WorldInfo_mapInsertEntry @ 005f4b50 */

void WorldInfo_mapInsertEntry(undefined4 value)

{
  int head;
  int node;
  int *list;
  
  head = *list;
  node = map_insertVec4Node(head,*(undefined4 *)(head + 4),value);
  if (list[1] == 0xaaaaaa9) {
    std::_Xlength_error("list<T> too long");
  }
  list[1] = list[1] + 1;
  *(int *)(head + 4) = node;
  **(int **)(node + 4) = node;
  return;
}




/* [AUDIT] proposed: WorldInfo_lookupCell  (confidence: med)
 * purpose: Looks up/updates a cell via std_vector_reserve_grow_stride0x140/copyctor_obj0x140
 * vars: value key/coord
 */
/* Global::WorldInfo_lookupCell @ 005f4ba0 */

void WorldInfo_lookupCell(uint elem)

{
  uint end;
  uint begin;
  uint *vector;
  
  end = vector[1];
  if ((elem < end) && (begin = *vector, begin <= elem)) {
    if (end == vector[2]) {
      std_vector_reserve_grow_stride0x140(1);
    }
    if (vector[1] != 0) {
      copyctor_obj0x140(((int)(elem - begin) / 0x140) * 0x140 + *vector);
      vector[1] = vector[1] + 0x140;
      return;
    }
  }
  else {
    if (end == vector[2]) {
      std_vector_reserve_grow_stride0x140(1);
    }
    if (vector[1] != 0) {
      copyctor_obj0x140(elem);
    }
  }
  vector[1] = vector[1] + 0x140;
  return;
}




/* [AUDIT] proposed: WorldInfo_scatterObjectsInArea  (confidence: med)
 * purpose: Scatters objects across an area using sqrt spacing and World_placeObjectWithSpacing placement
 * vars: World_placeObjectWithSpacing place; std_vector_push_back_4byte list; distance checks
 */
/* Global::WorldInfo_scatterObjectsInArea @ 005f56c0 */

/* WARNING: Type propagation algorithm not settling */

void * WorldInfo_scatterObjectsInArea(undefined4 x,undefined4 z,int level,undefined4 param_4)

{
  uint uVar1;
  void *pvVar2;
  int iVar3;
  void **ppvVar4;
  float10 fVar5;
  float10 fVar6;
  void **begin;
  void **cur;
  void **end;
  float local_84;
  float local_80;
  void *local_7c;
  void *local_78;
  void *local_74;
  void *local_70;
  void *local_6c;
  void *local_68;
  void *local_64;
  void *local_60;
  void *local_5c;
  void *local_58;
  void *local_54;
  void *local_50;
  void *local_4c;
  void *local_48;
  void *local_44 [2];
  void *local_3c;
  void *local_38;
  void *local_34;
  void *local_30;
  void *local_2c [2];
  void *local_24;
  void *local_20;
  void *local_1c;
  void *local_18;
  void *local_14 [4];
  
  local_14[3] = (void *)0xffffffff;
  local_14[2] = &LAB_006f47eb;
  local_14[1] = ExceptionList;
  ExceptionList = local_14 + 1;
  fVar5 = (float10)GameController_sampleHumidityGrid(x,z);
  local_80 = (float)fVar5;
  fVar5 = (float10)GameController_sampleTemperatureGrid(x,z);
  local_84 = (float)fVar5;
  fVar5 = (float10)World_getRegionCellPtr(x,z);
  fVar6 = (float10)World_placeObjectWithSpacing(x,z,0);
  begin = (void **)0x0;
  cur = (void **)0x0;
  end = (void **)0x0;
  local_14[3] = (void *)0x0;
  if (level < 0) {
    param_4 = 0x91;
    std_vector_push_back_4byte(&param_4);
    param_4 = 0x92;
    std_vector_push_back_4byte(&param_4);
    param_4 = 0x93;
    std_vector_push_back_4byte(&param_4);
    param_4 = 0x96;
    std_vector_push_back_4byte(&param_4);
    param_4 = 0x98;
    std_vector_push_back_4byte(&param_4);
    param_4 = 0x99;
    std_vector_push_back_4byte(&param_4);
    param_4 = 0x9b;
    std_vector_push_back_4byte(&param_4);
    param_4 = 0x9a;
    std_vector_push_back_4byte(&param_4);
  }
  else if ((char)param_4 == '\0') {
    if ((float)fVar5 <= 0.1) {
      std_vector_reserve_stride4(1);
      if (cur != (void **)0x0) {
        *cur = (void *)0x15;
      }
      cur = cur + 1;
      local_2c[0] = (void *)0x2e;
      if ((local_2c < cur) && (begin <= local_2c)) {
        iVar3 = (int)local_2c - (int)begin;
        if (cur == end) {
          std_vector_reserve_stride4(1);
        }
        if (cur != (void **)0x0) {
          *cur = begin[iVar3 >> 2];
        }
      }
      else {
        if (cur == end) {
          std_vector_reserve_stride4(1);
        }
        if (cur != (void **)0x0) {
          *cur = (void *)0x2e;
        }
      }
      cur = cur + 1;
      if (0.3 < (float)fVar6) {
        local_30 = (void *)0x2f;
        if ((&local_30 < cur) && (begin <= &local_30)) {
          iVar3 = (int)&local_30 - (int)begin;
          if (cur == end) {
            std_vector_reserve_stride4(1);
          }
          if (cur != (void **)0x0) {
            *cur = begin[iVar3 >> 2];
          }
        }
        else {
          if (cur == end) {
            std_vector_reserve_stride4(1);
          }
          if (cur != (void **)0x0) {
            *cur = (void *)0x2f;
          }
        }
        cur = cur + 1;
      }
      if (3 < level) {
        if ((local_80 < 0.2) || (0.8 <= local_80)) {
          if ((local_80 < 0.8) || (0.2 <= local_84)) {
            if ((local_80 < 0.6) || (local_84 < 0.6)) {
              if (0.2 <= local_80) goto LAB_005f6ce4;
              param_4 = 0x1c;
              std_vector_push_back_4byte(&param_4);
              param_4 = 0x38;
              std_vector_push_back_4byte(&param_4);
              param_4 = 0x41;
              std_vector_push_back_4byte(&param_4);
              param_4 = 0x5a;
              std_vector_push_back_4byte(&param_4);
              param_4 = 0x5d;
              std_vector_push_back_4byte(&param_4);
              param_4 = 0x15;
              std_vector_push_back_4byte(&param_4);
              param_4 = 0x31;
              std_vector_push_back_4byte(&param_4);
              param_4 = 0x16;
              std_vector_push_back_4byte(&param_4);
              param_4 = 0x17;
              std_vector_push_back_4byte(&param_4);
              param_4 = 0x23;
            }
            else {
              param_4 = 0x36;
              std_vector_push_back_4byte(&param_4);
              param_4 = 0x59;
              std_vector_push_back_4byte(&param_4);
              param_4 = 0x4b;
              std_vector_push_back_4byte(&param_4);
              param_4 = 0x4a;
              std_vector_push_back_4byte(&param_4);
              param_4 = 0x47;
              std_vector_push_back_4byte(&param_4);
              param_4 = 0x40;
              std_vector_push_back_4byte(&param_4);
              param_4 = 0x44;
              std_vector_push_back_4byte(&param_4);
              param_4 = 0x3c;
              std_vector_push_back_4byte(&param_4);
              param_4 = 0x3a;
              std_vector_push_back_4byte(&param_4);
              param_4 = 0x43;
              std_vector_push_back_4byte(&param_4);
              param_4 = 0x53;
              std_vector_push_back_4byte(&param_4);
              param_4 = 0x54;
              std_vector_push_back_4byte(&param_4);
              param_4 = 0x19;
              std_vector_push_back_4byte(&param_4);
              param_4 = 0x66;
              std_vector_push_back_4byte(&param_4);
              param_4 = 0x68;
              std_vector_push_back_4byte(&param_4);
              param_4 = 0x69;
              std_vector_push_back_4byte(&param_4);
              param_4 = 0x58;
              std_vector_push_back_4byte(&param_4);
              param_4 = 0x3e;
              std_vector_push_back_4byte(&param_4);
              param_4 = 0x24;
              std_vector_push_back_4byte(&param_4);
              param_4 = 0x32;
              std_vector_push_back_4byte(&param_4);
              param_4 = 0x16;
              std_vector_push_back_4byte(&param_4);
              param_4 = 0x17;
            }
          }
          else {
            param_4 = 0x36;
            std_vector_push_back_4byte(&param_4);
            param_4 = 0x3d;
            std_vector_push_back_4byte(&param_4);
            param_4 = 0x48;
            std_vector_push_back_4byte(&param_4);
            param_4 = 0x2a;
            std_vector_push_back_4byte(&param_4);
            param_4 = 0x49;
            std_vector_push_back_4byte(&param_4);
            param_4 = 0x42;
            std_vector_push_back_4byte(&param_4);
            param_4 = 0x53;
            std_vector_push_back_4byte(&param_4);
            param_4 = 0x54;
            std_vector_push_back_4byte(&param_4);
            param_4 = 0x66;
            std_vector_push_back_4byte(&param_4);
            param_4 = 0x67;
            std_vector_push_back_4byte(&param_4);
            param_4 = 0x58;
            std_vector_push_back_4byte(&param_4);
            param_4 = 0x3e;
            std_vector_push_back_4byte(&param_4);
            param_4 = 0x24;
            std_vector_push_back_4byte(&param_4);
            param_4 = 99;
          }
        }
        else {
          local_44[0] = (void *)0x36;
          if ((local_44 < cur) && (begin <= local_44)) {
            iVar3 = (int)local_44 - (int)begin;
            if (cur == end) {
              std_vector_reserve_stride4(1);
            }
            if (cur != (void **)0x0) {
              *cur = begin[iVar3 >> 2];
            }
          }
          else {
            if (cur == end) {
              std_vector_reserve_stride4(1);
            }
            if (cur != (void **)0x0) {
              *cur = (void *)0x36;
            }
          }
          cur = cur + 1;
          local_48 = (void *)0x4a;
          if ((&local_48 < cur) && (begin <= &local_48)) {
            iVar3 = (int)&local_48 - (int)begin;
            if (cur == end) {
              std_vector_reserve_stride4(1);
            }
            if (cur != (void **)0x0) {
              *cur = begin[iVar3 >> 2];
            }
          }
          else {
            if (cur == end) {
              std_vector_reserve_stride4(1);
            }
            if (cur != (void **)0x0) {
              *cur = (void *)0x4a;
            }
          }
          cur = cur + 1;
          local_4c = (void *)0x1c;
          if ((&local_4c < cur) && (begin <= &local_4c)) {
            iVar3 = (int)&local_4c - (int)begin;
            if (cur == end) {
              std_vector_reserve_stride4(1);
            }
            if (cur != (void **)0x0) {
              *cur = begin[iVar3 >> 2];
            }
          }
          else {
            if (cur == end) {
              std_vector_reserve_stride4(1);
            }
            if (cur != (void **)0x0) {
              *cur = (void *)0x1c;
            }
          }
          cur = cur + 1;
          local_50 = (void *)0x38;
          if ((&local_50 < cur) && (begin <= &local_50)) {
            iVar3 = (int)&local_50 - (int)begin;
            if (cur == end) {
              std_vector_reserve_stride4(1);
            }
            if (cur != (void **)0x0) {
              *cur = begin[iVar3 >> 2];
            }
          }
          else {
            if (cur == end) {
              std_vector_reserve_stride4(1);
            }
            if (cur != (void **)0x0) {
              *cur = (void *)0x38;
            }
          }
          cur = cur + 1;
          local_54 = (void *)0x19;
          if ((&local_54 < cur) && (begin <= &local_54)) {
            iVar3 = (int)&local_54 - (int)begin;
            if (cur == end) {
              std_vector_reserve_stride4(1);
            }
            if (cur != (void **)0x0) {
              *cur = begin[iVar3 >> 2];
            }
          }
          else {
            if (cur == end) {
              std_vector_reserve_stride4(1);
            }
            if (cur != (void **)0x0) {
              *cur = (void *)0x19;
            }
          }
          cur = cur + 1;
          local_58 = (void *)0x35;
          if ((&local_58 < cur) && (begin <= &local_58)) {
            iVar3 = (int)&local_58 - (int)begin;
            if (cur == end) {
              std_vector_reserve_stride4(1);
            }
            if (cur != (void **)0x0) {
              *cur = begin[iVar3 >> 2];
            }
          }
          else {
            if (cur == end) {
              std_vector_reserve_stride4(1);
            }
            if (cur != (void **)0x0) {
              *cur = (void *)0x35;
            }
          }
          cur = cur + 1;
          local_5c = (void *)0x37;
          if ((&local_5c < cur) && (begin <= &local_5c)) {
            iVar3 = (int)&local_5c - (int)begin;
            if (cur == end) {
              std_vector_reserve_stride4(1);
            }
            if (cur != (void **)0x0) {
              *cur = begin[iVar3 >> 2];
            }
          }
          else {
            if (cur == end) {
              std_vector_reserve_stride4(1);
            }
            if (cur != (void **)0x0) {
              *cur = (void *)0x37;
            }
          }
          cur = cur + 1;
          local_60 = (void *)0x3c;
          if ((&local_60 < cur) && (begin <= &local_60)) {
            iVar3 = (int)&local_60 - (int)begin;
            if (cur == end) {
              std_vector_reserve_stride4(1);
            }
            if (cur != (void **)0x0) {
              *cur = begin[iVar3 >> 2];
            }
          }
          else {
            if (cur == end) {
              std_vector_reserve_stride4(1);
            }
            if (cur != (void **)0x0) {
              *cur = (void *)0x3c;
            }
          }
          cur = cur + 1;
          local_64 = (void *)0x3f;
          if ((&local_64 < cur) && (begin <= &local_64)) {
            iVar3 = (int)&local_64 - (int)begin;
            if (cur == end) {
              std_vector_reserve_stride4(1);
            }
            if (cur != (void **)0x0) {
              *cur = begin[iVar3 >> 2];
            }
          }
          else {
            if (cur == end) {
              std_vector_reserve_stride4(1);
            }
            if (cur != (void **)0x0) {
              *cur = (void *)0x3f;
            }
          }
          cur = cur + 1;
          local_68 = (void *)0x43;
          if ((&local_68 < cur) && (begin <= &local_68)) {
            iVar3 = (int)&local_68 - (int)begin;
            if (cur == end) {
              std_vector_reserve_stride4(1);
            }
            if (cur != (void **)0x0) {
              *cur = begin[iVar3 >> 2];
            }
          }
          else {
            if (cur == end) {
              std_vector_reserve_stride4(1);
            }
            if (cur != (void **)0x0) {
              *cur = (void *)0x43;
            }
          }
          cur = cur + 1;
          local_6c = (void *)0x45;
          if ((&local_6c < cur) && (begin <= &local_6c)) {
            iVar3 = (int)&local_6c - (int)begin;
            if (cur == end) {
              std_vector_reserve_stride4(1);
            }
            if (cur != (void **)0x0) {
              *cur = begin[iVar3 >> 2];
            }
          }
          else {
            if (cur == end) {
              std_vector_reserve_stride4(1);
            }
            if (cur != (void **)0x0) {
              *cur = (void *)0x45;
            }
          }
          cur = cur + 1;
          local_70 = (void *)0x46;
          if ((&local_70 < cur) && (begin <= &local_70)) {
            iVar3 = (int)&local_70 - (int)begin;
            if (cur == end) {
              std_vector_reserve_stride4(1);
            }
            if (cur != (void **)0x0) {
              *cur = begin[iVar3 >> 2];
            }
          }
          else {
            if (cur == end) {
              std_vector_reserve_stride4(1);
            }
            if (cur != (void **)0x0) {
              *cur = (void *)0x46;
            }
          }
          cur = cur + 1;
          local_74 = (void *)0x47;
          if ((&local_74 < cur) && (begin <= &local_74)) {
            iVar3 = (int)&local_74 - (int)begin;
            if (cur == end) {
              std_vector_reserve_stride4(1);
            }
            if (cur != (void **)0x0) {
              *cur = begin[iVar3 >> 2];
            }
          }
          else {
            if (cur == end) {
              std_vector_reserve_stride4(1);
            }
            if (cur != (void **)0x0) {
              *cur = (void *)0x47;
            }
          }
          cur = cur + 1;
          local_78 = (void *)0x57;
          if ((&local_78 < cur) && (begin <= &local_78)) {
            iVar3 = (int)&local_78 - (int)begin;
            if (cur == end) {
              std_vector_reserve_stride4(1);
            }
            if (cur != (void **)0x0) {
              *cur = begin[iVar3 >> 2];
            }
          }
          else {
            if (cur == end) {
              std_vector_reserve_stride4(1);
            }
            if (cur != (void **)0x0) {
              *cur = (void *)0x57;
            }
          }
          cur = cur + 1;
          local_7c = (void *)0x58;
          if ((&local_7c < cur) && (begin <= &local_7c)) {
            iVar3 = (int)&local_7c - (int)begin;
            if (cur == end) {
              std_vector_reserve_stride4(1);
            }
            if (cur != (void **)0x0) {
              *cur = begin[iVar3 >> 2];
            }
          }
          else {
            if (cur == end) {
              std_vector_reserve_stride4(1);
            }
            if (cur != (void **)0x0) {
              *cur = (void *)0x58;
            }
          }
          cur = cur + 1;
          param_4 = 100;
          std_vector_push_back_4byte(&param_4);
          param_4 = 0x5a;
          std_vector_push_back_4byte(&param_4);
          param_4 = 0x5b;
          std_vector_push_back_4byte(&param_4);
          param_4 = 0x5c;
          std_vector_push_back_4byte(&param_4);
          param_4 = 0x23;
          std_vector_push_back_4byte(&param_4);
          param_4 = 0x66;
          std_vector_push_back_4byte(&param_4);
          param_4 = 0x68;
          std_vector_push_back_4byte(&param_4);
          param_4 = 0x69;
          std_vector_push_back_4byte(&param_4);
          param_4 = 0x22;
          std_vector_push_back_4byte(&param_4);
          param_4 = 0x21;
          std_vector_push_back_4byte(&param_4);
          param_4 = 0x1e;
          std_vector_push_back_4byte(&param_4);
          param_4 = 0x1f;
          std_vector_push_back_4byte(&param_4);
          param_4 = 0x20;
          std_vector_push_back_4byte(&param_4);
          param_4 = 0x13;
          std_vector_push_back_4byte(&param_4);
          param_4 = 0x14;
          std_vector_push_back_4byte(&param_4);
          param_4 = 0x1a;
          std_vector_push_back_4byte(&param_4);
          param_4 = 0x1b;
          std_vector_push_back_4byte(&param_4);
          param_4 = 0x62;
          std_vector_push_back_4byte(&param_4);
          param_4 = 0x16;
          std_vector_push_back_4byte(&param_4);
          param_4 = 0x17;
          std_vector_push_back_4byte(&param_4);
          param_4 = 0x97;
        }
        std_vector_push_back_4byte(&param_4);
        goto LAB_005f6ce4;
      }
      local_34 = (void *)0x6a;
      if ((&local_34 < cur) && (begin <= &local_34)) {
        iVar3 = (int)&local_34 - (int)begin;
        if (cur == end) {
          std_vector_reserve_stride4(1);
        }
        if (cur != (void **)0x0) {
          *cur = begin[iVar3 >> 2];
        }
      }
      else {
        if (cur == end) {
          std_vector_reserve_stride4(1);
        }
        if (cur != (void **)0x0) {
          *cur = (void *)0x6a;
        }
      }
      cur = cur + 1;
      local_38 = (void *)0x39;
      if ((&local_38 < cur) && (begin <= &local_38)) {
        iVar3 = (int)&local_38 - (int)begin;
        if (cur == end) {
          std_vector_reserve_stride4(1);
        }
        if (cur != (void **)0x0) {
          *cur = begin[iVar3 >> 2];
        }
      }
      else {
        if (cur == end) {
          std_vector_reserve_stride4(1);
        }
        if (cur != (void **)0x0) {
          *cur = (void *)0x39;
        }
      }
      cur = cur + 1;
      local_3c = (void *)0x56;
      if ((&local_3c < cur) && (begin <= &local_3c)) {
        iVar3 = (int)&local_3c - (int)begin;
        if (cur == end) {
          std_vector_reserve_stride4(1);
        }
        if (cur != (void **)0x0) {
          *cur = begin[iVar3 >> 2];
        }
      }
      else {
        if (cur == end) {
          std_vector_reserve_stride4(1);
        }
        if (cur != (void **)0x0) {
          *cur = (void *)0x56;
        }
      }
      cur = cur + 1;
      ppvVar4 = local_44 + 1;
      local_44[1] = (void *)0x19;
      if ((cur <= ppvVar4) || (ppvVar4 < begin)) {
        if (cur == end) {
          std_vector_reserve_stride4(1);
        }
        if (cur != (void **)0x0) {
          *cur = (void *)0x19;
        }
        cur = cur + 1;
        goto LAB_005f6ce4;
      }
    }
    else {
      std_vector_reserve_stride4(1);
      if (cur != (void **)0x0) {
        *cur = (void *)0x49;
      }
      cur = cur + 1;
      local_14[0] = (void *)0x52;
      if ((local_14 < cur) && (begin <= local_14)) {
        iVar3 = (int)local_14 - (int)begin;
        if (cur == end) {
          std_vector_reserve_stride4(1);
        }
        if (cur != (void **)0x0) {
          *cur = begin[iVar3 >> 2];
        }
      }
      else {
        if (cur == end) {
          std_vector_reserve_stride4(1);
        }
        if (cur != (void **)0x0) {
          *cur = (void *)0x52;
        }
      }
      cur = cur + 1;
      local_18 = (void *)0x55;
      if ((&local_18 < cur) && (begin <= &local_18)) {
        iVar3 = (int)&local_18 - (int)begin;
        if (cur == end) {
          std_vector_reserve_stride4(1);
        }
        if (cur != (void **)0x0) {
          *cur = begin[iVar3 >> 2];
        }
      }
      else {
        if (cur == end) {
          std_vector_reserve_stride4(1);
        }
        if (cur != (void **)0x0) {
          *cur = (void *)0x55;
        }
      }
      cur = cur + 1;
      local_1c = (void *)0x70;
      if ((&local_1c < cur) && (begin <= &local_1c)) {
        iVar3 = (int)&local_1c - (int)begin;
        if (cur == end) {
          std_vector_reserve_stride4(1);
        }
        if (cur != (void **)0x0) {
          *cur = begin[iVar3 >> 2];
        }
      }
      else {
        if (cur == end) {
          std_vector_reserve_stride4(1);
        }
        if (cur != (void **)0x0) {
          *cur = (void *)0x70;
        }
      }
      cur = cur + 1;
      local_20 = (void *)0x67;
      if ((&local_20 < cur) && (begin <= &local_20)) {
        iVar3 = (int)&local_20 - (int)begin;
        if (cur == end) {
          std_vector_reserve_stride4(1);
        }
        if (cur != (void **)0x0) {
          *cur = begin[iVar3 >> 2];
        }
      }
      else {
        if (cur == end) {
          std_vector_reserve_stride4(1);
        }
        if (cur != (void **)0x0) {
          *cur = (void *)0x67;
        }
      }
      cur = cur + 1;
      local_24 = (void *)0x3e;
      if ((&local_24 < cur) && (begin <= &local_24)) {
        iVar3 = (int)&local_24 - (int)begin;
        if (cur == end) {
          std_vector_reserve_stride4(1);
        }
        if (cur != (void **)0x0) {
          *cur = begin[iVar3 >> 2];
        }
      }
      else {
        if (cur == end) {
          std_vector_reserve_stride4(1);
        }
        if (cur != (void **)0x0) {
          *cur = (void *)0x3e;
        }
      }
      cur = cur + 1;
      ppvVar4 = local_2c + 1;
      local_2c[1] = (void *)0x6e;
      if ((cur <= ppvVar4) || (ppvVar4 < begin)) {
        if (cur == end) {
          std_vector_reserve_stride4(1);
        }
        if (cur != (void **)0x0) {
          *cur = (void *)0x6e;
        }
        cur = cur + 1;
        goto LAB_005f6ce4;
      }
    }
    iVar3 = (int)ppvVar4 - (int)begin;
    if (cur == end) {
      std_vector_reserve_stride4(1);
    }
    if (cur != (void **)0x0) {
      *cur = begin[iVar3 >> 2];
    }
    cur = cur + 1;
  }
  else {
    param_4 = 2;
    std_vector_push_back_4byte(&param_4);
    param_4 = 4;
    std_vector_push_back_4byte(&param_4);
    param_4 = 7;
    std_vector_push_back_4byte(&param_4);
    param_4 = 9;
    std_vector_push_back_4byte(&param_4);
    param_4 = 0xb;
    std_vector_push_back_4byte(&param_4);
    param_4 = 0xf;
    std_vector_push_back_4byte(&param_4);
    param_4 = 0x33;
    std_vector_push_back_4byte(&param_4);
    param_4 = 0x30;
    std_vector_push_back_4byte(&param_4);
    param_4 = 0x4c;
    std_vector_push_back_4byte(&param_4);
  }
LAB_005f6ce4:
  if (begin == cur) {
    pvVar2 = (void *)0x3c;
  }
  else {
    iVar3 = (int)cur - (int)begin;
    uVar1 = rand();
    pvVar2 = begin[uVar1 % (uint)(iVar3 >> 2)];
  }
  local_14[3] = (void *)0xffffffff;
  if (begin == (void **)0x0) {
    ExceptionList = local_14[1];
    return pvVar2;
  }
  std::_Container_base0::_Orphan_all((_Container_base0 *)&begin);
  operator_delete(begin);
}




/* [AUDIT] proposed: WorldInfo_vectorElementAt  (confidence: med)
 * purpose: Returns/accesses a WorldInfo vector element by index/flag (external:12e copy)
 * vars: x vector; z flag
 */
/* Global::WorldInfo_vectorElementAt @ 005f8530 */

int WorldInfo_vectorElementAt(int max,char force_max)

{
  int count;
  int iVar2;
  
  count = rand();
  count = count % (max + 1);
  iVar2 = rand();
  if (iVar2 % 100 == 0) {
    count = count + 1;
  }
  iVar2 = rand();
  if (iVar2 % 1000 == 0) {
    count = count + 1;
  }
  iVar2 = rand();
  if (iVar2 % 10000 == 0) {
    count = count + 1;
  }
  if (force_max != '\0') {
    count = max + 1;
  }
  if (4 < count) {
    count = 4;
  }
  return count;
}




/* [AUDIT] proposed: WorldInfo_vectorAppend  (confidence: med)
 * purpose: Appends/moves a vector element (external:12e)
 * vars: external:0000012e
 */
/* Global::WorldInfo_vectorAppend @ 005f8590 */

uint WorldInfo_vectorAppend(void)

{
  uint roll;
  uint category;
  
  switch(category) {
  case 0:
  case 1:
    category = rand();
    category = category & 0x80000001;
    if ((int)category < 0) {
      return (category - 1 | 0xfffffffe) + 1;
    }
    break;
  case 2:
  case 3:
    roll = rand();
    roll = roll & 0x80000001;
    if ((int)roll < 0) {
      roll = (roll - 1 | 0xfffffffe) + 1;
    }
    return roll + 2;
  case 4:
  case 5:
    roll = rand();
    roll = roll & 0x80000001;
    if ((int)roll < 0) {
      roll = (roll - 1 | 0xfffffffe) + 1;
    }
    return roll + 4;
  default:
    break;
  case 7:
  case 8:
    roll = rand();
    roll = roll & 0x80000001;
    if ((int)roll < 0) {
      roll = (roll - 1 | 0xfffffffe) + 1;
    }
    return roll + 7;
  case 9:
  case 10:
    roll = rand();
    roll = roll & 0x80000001;
    if ((int)roll < 0) {
      roll = (roll - 1 | 0xfffffffe) + 1;
    }
    return roll + 9;
  case 0xb:
  case 0xc:
    roll = rand();
    roll = roll & 0x80000001;
    if ((int)roll < 0) {
      roll = (roll - 1 | 0xfffffffe) + 1;
    }
    return roll + 0xb;
  case 0xd:
  case 0xe:
    roll = rand();
    roll = roll & 0x80000001;
    if ((int)roll < 0) {
      roll = (roll - 1 | 0xfffffffe) + 1;
    }
    return roll + 0xd;
  case 0xf:
  case 0x10:
    roll = rand();
    roll = roll & 0x80000001;
    if ((int)roll < 0) {
      roll = (roll - 1 | 0xfffffffe) + 1;
    }
    return roll + 0xf;
  case 0x16:
  case 0x17:
    roll = rand();
    roll = roll & 0x80000001;
    if ((int)roll < 0) {
      roll = (roll - 1 | 0xfffffffe) + 1;
    }
    return roll + 0x16;
  case 0x25:
  case 0x26:
  case 0x27:
  case 0x28:
    roll = rand();
    roll = roll & 0x80000003;
    if ((int)roll < 0) {
      roll = (roll - 1 | 0xfffffffc) + 1;
    }
    return roll + 0x25;
  case 0x53:
  case 0x54:
    roll = rand();
    roll = roll & 0x80000001;
    if ((int)roll < 0) {
      roll = (roll - 1 | 0xfffffffe) + 1;
    }
    return roll + 0x53;
  }
  return category;
}




/* [AUDIT] proposed: WorldInfo_sampleTerrainHeight  (confidence: med)
 * purpose: Returns terrain height/noise (float10) at coord with World_findNearestObject nearest and GameController_getVoxelColumn8
 * vars: param_1 coord; param_2 scale
 */
/* Global::WorldInfo_sampleTerrainHeight @ 005f9340 */

float10 WorldInfo_sampleTerrainHeight(uint x,float y)

{
  uint uVar1;
  int iVar2;
  int world;
  uint uVar3;
  uint uVar4;
  float10 fVar5;
  float10 fVar6;
  float fVar7;
  float fVar8;
  undefined8 local_20;
  undefined8 local_18;
  int local_10;
  float noise;
  int local_8;
  
  uVar1 = (uint)y;
  local_18 = (double)(int)y * 0.001;
  local_20 = (double)(int)x * 0.001;
  local_8 = world;
  fVar5 = (float10)perlinNoise2D_cosInterp((double)*(int *)(world + 0x800170) + (double)(int)x * 0.01,
                                (double)*(int *)(world + 0x800174) + (double)(int)y * 0.01);
  fVar6 = (float10)perlinNoise2D_cosInterp((double)*(int *)(local_8 + 0x800168) + local_20,
                                (double)*(int *)(local_8 + 0x80016c) + local_18);
  noise = (float)fVar6;
  fVar7 = (float)fVar5 * 0.1 + noise;
  fVar5 = (float10)perlinNoise2D_cosInterp(local_20,local_18);
  noise = (float)fVar5;
  fVar7 = ABS(fVar7) * ((noise + 1.0) * 0.1 + 0.8);
  fVar5 = (float10)World_findNearestObject(x,y);
  noise = (float)fVar5;
  fVar8 = 1.0 - noise * 0.75;
  y = fVar7;
  if (0.0 < fVar8) {
    y = fVar8 * fVar8 * 0.05 + fVar7;
  }
  uVar3 = (int)uVar1 >> 0x1f;
  uVar4 = (int)x >> 0x1f;
  iVar2 = GameController_getVoxelColumn8((int)(x + (uVar4 & 0x7ff)) >> 0xb,(int)(uVar1 + (uVar3 & 0x7ff)) >> 0xb
                      );
  local_18 = (double)CONCAT44(iVar2,(undefined4)local_18);
  if (iVar2 != 0) {
    iVar2 = *(int *)(iVar2 + 0x18);
    if ((((iVar2 == 1) || (iVar2 == 2)) || (iVar2 == 4)) || (iVar2 == 0xd)) {
      local_20 = (double)CONCAT44(uVar3 << 0x10 | uVar1 >> 0x10,uVar1 << 0x10);
      noise = (float)(uVar4 << 0x10 | x >> 0x10);
      local_10 = x << 0x10;
      fVar5 = (float10)vec3_distanceSquared(&local_10,&local_20);
      noise = (float)fVar5;
      fVar7 = 1.0 - noise;
      if (0.0 < fVar7) {
        fVar7 = fVar7 * fVar7;
      }
      else {
        fVar7 = 0.0;
      }
      y = fVar7 + y;
    }
    if ((iVar2 == 6) || (iVar2 == 7)) {
      local_20 = (double)CONCAT44(uVar3 << 0x10 | uVar1 >> 0x10,uVar1 << 0x10);
      local_18 = (double)CONCAT44(uVar4 << 0x10 | x >> 0x10,x << 0x10);
      fVar5 = (float10)vec3_distanceSquared(&local_18,&local_20);
      fVar8 = 1.0 - (float)fVar5;
      fVar7 = 0.0;
      if (0.0 < fVar8) {
        fVar7 = fVar8 * fVar8;
      }
      y = fVar7 * 0.5 + y;
    }
  }
  iVar2 = world_getChunkCell256();
  if (iVar2 == 0) {
    fVar5 = (float10)World_getRegionCellPtr(x,uVar1);
    fVar7 = (float)fVar5;
  }
  else {
    fVar7 = *(float *)(iVar2 + 0xc);
  }
  return (float10)(fVar7 + y);
}




/* [AUDIT] proposed: WorldInfo_rotateAndPlace  (confidence: med)
 * purpose: Computes a rotated position (cos/sin via Terrain_sampleHeightNoise) and places/samples at it
 * vars: x/2 coord+angle; libm cos
 */
/* Global::WorldInfo_rotateAndPlace @ 005f9f70 */

void WorldInfo_rotateAndPlace(uint x,uint z)

{
  int iVar1;
  float10 fVar2;
  double dVar3;
  float fVar4;
  float fVar5;
  int local_2c;
  float local_28;
  int local_24;
  float local_20;
  float local_1c;
  double local_18;
  double local_10;
  uint local_8;
  
  local_8 = DAT_0076aa78 ^ (uint)&stack0xfffffffc;
  fVar2 = (float10)Terrain_sampleHeightAtWorldXY(x,z);
  local_28 = (float)fVar2;
  Terrain_sampleHeightNoise(&local_18,x,z);
  fVar2 = (float10)World_findNearestObject(x,z);
  local_1c = (float)fVar2;
  if (0.0 < local_28) {
    fVar4 = local_28 * 3.0;
    if (1.0 < fVar4) {
      fVar4 = 1.0;
    }
    fVar4 = 1.0 - fVar4 * fVar4;
    local_20 = 1.0 - fVar4 * fVar4;
    dVar3 = local_18 * 360.0;
    libm_sse2_cos_precise();
    fVar4 = (float)(dVar3 * (double)local_20 + 1.0);
    if (fVar4 < local_1c) {
      local_1c = fVar4;
    }
    dVar3 = local_10 * 360.0;
    libm_sse2_cos_precise();
    fVar4 = (float)(dVar3 * (double)local_20 + 1.0);
    if (fVar4 < local_1c) {
      local_1c = fVar4;
    }
  }
  if (0.65 < local_28) {
    fVar4 = (0.7 - local_28) / 0.05;
    if (fVar4 <= 0.0) {
      fVar4 = 0.0;
    }
    local_1c = fVar4 * local_1c;
  }
  iVar1 = GameController_getVoxelColumn8((int)(x + ((int)x >> 0x1f & 0x7ffU)) >> 0xb,
                       (int)(z + ((int)z >> 0x1f & 0x7ffU)) >> 0xb);
  if ((iVar1 != 0) && ((*(int *)(iVar1 + 0x18) == 2 || (*(int *)(iVar1 + 0x18) == 4)))) {
    local_20 = (float)(((int)z >> 0x1f) << 0x10 | z >> 0x10);
    local_24 = z << 0x10;
    local_28 = (float)(((int)x >> 0x1f) << 0x10 | x >> 0x10);
    local_2c = x << 0x10;
    fVar2 = (float10)vec3_distanceSquared(&local_2c,&local_24);
    local_20 = (float)fVar2;
    fVar5 = 1.0 - local_20;
    fVar4 = 0.0;
    if (0.0 < fVar5) {
      fVar4 = fVar5 * fVar5;
    }
    local_1c = fVar4 * 2.0 + local_1c;
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}




/* [AUDIT] proposed: WorldInfo::move_string  (confidence: high)
 * purpose: Move-construct one std::string (SSO-aware) from x into this+4, resetting source
 * vars: +1 buf; [5]=len [6]=cap
 */
/* Global::WorldInfo_move_string @ 0064aec0 */

void WorldInfo_move_string(undefined4 *src)

{
  undefined4 *_Dst;
  undefined4 *_Src;
  undefined4 *dst;
  
  _Dst = dst + 1;
  *dst = *src;
  _Src = src + 1;
  dst[6] = 0xf;
  dst[5] = 0;
  *(undefined1 *)_Dst = 0;
  if ((uint)src[6] < 0x10) {
    if (src[5] + 1 != 0) {
      memmove(_Dst,_Src,src[5] + 1);
    }
  }
  else {
    *_Dst = *_Src;
    *_Src = 0;
  }
  dst[5] = src[5];
  dst[6] = src[6];
  src[6] = 0xf;
  src[5] = 0;
  *(undefined1 *)_Src = 0;
  return;
}




