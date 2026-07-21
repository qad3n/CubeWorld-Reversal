// CombatBehavior (ai) — server. 29 functions. Bodies = Ghidra pseudo-C.
#include "CombatBehavior.h"

/* [AUDIT] proposed: CombatState_zeroInit  (confidence: high)
 * purpose: Zero-inits small struct at param_1 (offsets 0,4,8,0x10,0x14)
 * vars: param_1=struct base
 */
/* Global::CombatState_zeroInit @ 004029b0 */

undefined1 * __fastcall CombatState_zeroInit(undefined1 *self)

{
  *self = 0;
  *(undefined4 *)(self + 4) = 0;
  *(undefined4 *)(self + 8) = 0;
  *(undefined4 *)(self + 0x10) = 0;
  *(undefined4 *)(self + 0x14) = 0;
  return self;
}




/* cube::CombatBehavior::ctor_0 @ 004029e0 */

undefined4 * __thiscall cube::CombatBehavior::ctor_0(CombatBehavior *this,undefined4 target)

{
  *(undefined ***)this = vftable;
  *(undefined4 *)(this + 4) = 20000;
  *(undefined4 *)(this + 8) = target;
  *(undefined4 *)(this + 0xc) = 0;
  *(undefined4 *)(this + 0x10) = 0;
  return (undefined4 *)this;
}




/* [AUDIT] proposed: Struct_copy0x118  (confidence: high)
 * purpose: Copies ~0x118-byte struct incl 0x20-iteration 8-byte-per-element loop; CombatBehavior state copy
 * vars: this=dest; target=src; loop 0x20 x 8B
 */
/* Global::Struct_copy0x118 @ 00402a70 */

undefined1 * __thiscall Struct_copy0x118(void *this,undefined1 *src)

{
  undefined1 *dst_ptr;
  undefined1 *src_ptr;
  int count;
  
  *(undefined1 *)this = *src;
  *(undefined1 *)((int)this + 1) = src[1];
  *(undefined4 *)((int)this + 4) = *(undefined4 *)(src + 4);
  *(undefined4 *)((int)this + 8) = *(undefined4 *)(src + 8);
  *(undefined1 *)((int)this + 0xc) = src[0xc];
  *(undefined1 *)((int)this + 0xd) = src[0xd];
  *(undefined1 *)((int)this + 0xe) = src[0xe];
  *(undefined2 *)((int)this + 0x10) = *(undefined2 *)(src + 0x10);
  src_ptr = src + 0x17;
  dst_ptr = (undefined1 *)((int)this + 0x15);
  count = 0x20;
  do {
    dst_ptr[-1] = src_ptr[-3];
    *dst_ptr = dst_ptr[(int)src - (int)this];
    dst_ptr[1] = src_ptr[-1];
    dst_ptr[2] = *src_ptr;
    *(undefined4 *)(dst_ptr + 3) = *(undefined4 *)(src_ptr + 1);
    src_ptr = src_ptr + 8;
    dst_ptr = dst_ptr + 8;
    count = count + -1;
  } while (count != 0);
  *(undefined4 *)((int)this + 0x114) = *(undefined4 *)(src + 0x114);
  return this;
}




/* [AUDIT] proposed: Vec3i64_copyAndScale  (confidence: med)
 * purpose: Copies 6 dwords then scales the resulting vec3-int64 by param_2/param_3 fraction
 * vars: this=src 6dw; param_2/param_3=scale num/den
 */
/* Global::Vec3i64_copyAndScale @ 00402bd0 */

undefined4 * __thiscall Vec3i64_copyAndScale(void *this,undefined4 *dst,uint mul_lo,int mul_hi)

{
  *dst = *(undefined4 *)this;
  dst[1] = *(undefined4 *)((int)this + 4);
  dst[2] = *(undefined4 *)((int)this + 8);
  dst[3] = *(undefined4 *)((int)this + 0xc);
  dst[4] = *(undefined4 *)((int)this + 0x10);
  dst[5] = *(undefined4 *)((int)this + 0x14);
  Vec3i64_scaleFixed(dst,mul_lo,mul_hi);
  return dst;
}




/* [AUDIT] proposed: Vec3i64_scaleFixed  (confidence: high)
 * purpose: Scales 3 int64 components by param (num) then divides by 0x10000; fixed-point vec3 scale
 * vars: this=3x int64; *0x10000 fixed-point
 */
/* Global::Vec3i64_scaleFixed @ 00402db0 */

uint * __thiscall Vec3i64_scaleFixed(void *this,uint mul_lo,int mul_hi)

{
  longlong product;
  undefined8 quotient;
  
  product = __allmul(*(uint *)this,*(int *)((int)this + 4),mul_lo,mul_hi);
  quotient = __alldiv((uint)product,(uint)((ulonglong)product >> 0x20),0x10000,0);
  *(undefined8 *)this = quotient;
  product = __allmul(*(uint *)((int)this + 8),*(int *)((int)this + 0xc),mul_lo,mul_hi);
  quotient = __alldiv((uint)product,(uint)((ulonglong)product >> 0x20),0x10000,0);
  *(undefined8 *)((int)this + 8) = quotient;
  product = __allmul(*(uint *)((int)this + 0x10),*(int *)((int)this + 0x14),mul_lo,mul_hi);
  quotient = __alldiv((uint)product,(uint)((ulonglong)product >> 0x20),0x10000,0);
  *(undefined8 *)((int)this + 0x10) = quotient;
  return this;
}




/* cube::CombatBehavior::vfunc_0 @ 00402f40 */

/* WARNING: Removing unreachable block (ram,0x004045c6) */
/* WARNING: Removing unreachable block (ram,0x0040436d) */

void __thiscall
cube::CombatBehavior::vfunc_0
          (CombatBehavior *this,void *creature,void *world,int dt,int arg4)

{
  CombatBehavior *pCVar1;
  undefined8 uVar2;
  short sVar3;
  ushort uVar4;
  void *pvVar5;
  int *piVar6;
  uint uVar7;
  int *piVar9;
  char action_type;
  int iVar11;
  undefined4 uVar12;
  uint uVar13;
  uint *puVar14;
  int iVar15;
  int iVar16;
  int *piVar17;
  undefined4 *puVar18;
  longlong *plVar19;
  float *pfVar20;
  int *piVar21;
  int iVar22;
  void *pvVar23;
  bool bVar24;
  float10 fVar25;
  float fVar26;
  double dVar27;
  float fVar28;
  float fVar29;
  int *piVar30;
  ulonglong uVar31;
  uint *puVar32;
  uint *puVar33;
  undefined1 auStack_31c [4];
  int *local_318;
  void *local_314;
  void *world_p;
  int local_30c;
  uint *local_308;
  char local_301;
  int *local_300;
  CombatBehavior *local_2fc;
  char local_2f5;
  uint *local_2f4;
  int *local_2f0;
  int *local_2ec;
  void *creature_p;
  float fStack_2e4;
  float local_2e0;
  int iStack_2dc;
  int iStack_2d8;
  undefined4 uStack_2d4;
  float fStack_2d0;
  int dt_save;
  int iStack_2c8;
  int iStack_2c4;
  undefined4 uStack_2c0;
  int *local_2bc;
  int iStack_2b8;
  int iStack_2b4;
  undefined4 uStack_2b0;
  void *pvStack_2ac;
  int iStack_2a8;
  undefined4 uStack_2a4;
  ulonglong uStack_2a0;
  ulonglong uStack_298;
  undefined8 uStack_290;
  undefined4 uStack_284;
  int local_280;
  int local_27c;
  undefined4 uStack_278;
  int local_274;
  undefined4 uStack_270;
  undefined4 uStack_26c;
  undefined4 uStack_268;
  undefined4 uStack_264;
  undefined4 uStack_260;
  int local_25c;
  undefined4 uStack_258;
  undefined4 uStack_254;
  undefined4 uStack_250;
  undefined4 uStack_24c;
  undefined4 uStack_248;
  undefined4 uStack_244;
  undefined4 uStack_240;
  undefined4 uStack_23c;
  undefined4 uStack_238;
  undefined4 uStack_234;
  undefined4 uStack_230;
  undefined4 uStack_22c;
  undefined8 local_228;
  float fStack_21c;
  float fStack_218;
  int *piStack_214;
  float local_210;
  float local_20c;
  int *local_208;
  float fStack_204;
  float fStack_200;
  float local_1f8;
  float local_1f4;
  float local_1f0;
  float fStack_1ec;
  float fStack_1e8;
  int iStack_1e0;
  int iStack_1dc;
  int iStack_1d8;
  int iStack_1d4;
  int iStack_1d0;
  int iStack_1cc;
  int local_1c8;
  int iStack_1c4;
  int local_1c0;
  int iStack_1bc;
  int local_1b8;
  int iStack_1b4;
  int local_1b0;
  int iStack_1ac;
  int local_1a8;
  int iStack_1a4;
  int local_1a0;
  int iStack_19c;
  undefined4 uStack_194;
  undefined4 uStack_190;
  float fStack_18c;
  undefined8 local_188;
  int local_17c [3];
  uint auStack_170 [6];
  uint auStack_158 [6];
  uint auStack_140 [6];
  uint auStack_128 [6];
  uint auStack_110 [6];
  uint auStack_f8 [6];
  uint auStack_e0 [6];
  uint auStack_c8 [6];
  uint auStack_b0 [6];
  uint auStack_98 [6];
  uint auStack_80 [6];
  undefined4 auStack_68 [6];
  uint auStack_50 [6];
  uint auStack_38 [7];
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 uStack_c;
  uint uVar8;
  
  uStack_c = 0xffffffff;
  puStack_10 = &LAB_0054b9ac;
  local_14 = ExceptionList;
  local_1c = DAT_00583cc8 ^ (uint)auStack_31c;
  ExceptionList = &local_14;
  dt_save = arg4;
  local_2f4 = (uint *)((int)creature + 0x10);
  *(ushort *)((int)creature + 0x124) = *(ushort *)((int)creature + 0x124) & 0xfffb;
  action_type = *(char *)((int)creature + 0x68);
  creature_p = creature;
  world_p = world;
  if ((((action_type != 'S') && (action_type != 'R')) && (action_type != 'T')) &&
     ((action_type != 'O' && (10000 < *(int *)((int)creature + 0x6c))))) {
    *(undefined1 *)((int)creature + 0x68) = 0;
  }
  local_2fc = this;
  local_228 = CONCAT44(local_228._4_4_,(uint)local_228);
  if ((*(int *)((int)creature + 0x128) != 0) ||
     ((*(char *)((int)creature + 0x68) == 'P' &&
      (local_228 = CONCAT44(local_228._4_4_,(uint)local_228), *(int *)((int)creature + 0x6c) < 3000))
     )) goto LAB_004052e0;
  local_2f0 = *(int **)((int)creature + 0x16c);
  fVar25 = Combat_computeMaxHealth((int)creature);
  local_308 = (uint *)(float)fVar25;
  if (((float)local_2f0 < (float)local_308 * 0.25) &&
     (iVar11 = Combat_getWindupAndRecovery((int)creature), iVar11 < *(int *)((int)creature + 0x6c))) {
    for (puVar18 = *(undefined4 **)((int)creature + 0x11dc);
        puVar18 != *(undefined4 **)((int)creature + 0x11e0); puVar18 = puVar18 + 3) {
      for (piVar21 = (int *)*puVar18; piVar21 != (int *)puVar18[1]; piVar21 = piVar21 + 0x47) {
        if (((*piVar21 != 0) && ((char)piVar21[1] == '\x01')) &&
           (*(char *)((int)piVar21 + 5) == '\x01')) {
          *(undefined1 *)((int)creature + 0x68) = 0x50;
          *(undefined4 *)((int)creature + 0x6c) = 0;
          Struct_copy0x118((void *)((int)creature + 0x1e8),(undefined1 *)(piVar21 + 1));
          *piVar21 = *piVar21 + -1;
          if (*piVar21 < 1) {
            *piVar21 = 0;
            *(undefined1 *)(piVar21 + 1) = 0;
            *(undefined1 *)((int)piVar21 + 5) = 0;
          }
          iVar11 = rand();
          local_308 = (uint *)(((float)iVar11 * 4.0) / 32767.0 - 2.0);
          iVar11 = rand();
          *(uint **)((int)creature + 0x40) = local_308;
          *(undefined4 *)((int)creature + 0x48) = 0;
          *(float *)((int)creature + 0x44) = ((float)iVar11 * 4.0) / 32767.0 - 2.0;
          goto LAB_004052e0;
        }
      }
    }
  }
  local_228 = Combat_findTopThreatTarget((int)creature);
  piVar21 = (int *)((int)world + 4);
  local_318 = piVar21;
  std_map_lower_bound_yx(piVar21,&local_25c,(uint *)&local_228);
  iVar11 = *piVar21;
  if (local_25c == iVar11) {
    local_30c = 0;
  }
  else {
    local_30c = *(int *)(local_25c + 0x18);
  }
  iVar22 = local_30c;
  if (*(char *)((int)creature + 0x60) == '\x05') {
    std_map_lower_bound_yx(piVar21,&local_280,(uint *)((int)creature + 0x198));
    iVar22 = local_30c;
    if ((local_280 == iVar11) || (iVar15 = *(int *)(local_280 + 0x18), iVar15 == 0))
    goto LAB_00403256;
    iVar22 = 0;
    local_30c = 0;
    if (*(char *)(iVar15 + 0x68) == 'j') goto LAB_004052e0;
    piVar21 = *(int **)(iVar15 + 0x13ac);
    local_2bc = (int *)*piVar21;
    local_2ec = (int *)0x0;
    creature = creature_p;
    if (local_2bc != piVar21) {
      do {
        local_2f0 = (int *)local_2bc[6];
        if ((float)local_2ec < (float)local_2f0) {
          local_308 = (uint *)(local_2bc + 4);
          std_map_lower_bound_yx(local_318,&local_27c,local_308);
          if ((local_27c != iVar11) && (*(int *)(local_27c + 0x18) != 0)) {
            std_map_lower_bound_yx(local_318,&local_274,local_308);
            if (local_274 == iVar11) {
              iVar22 = 0;
            }
            else {
              iVar22 = *(int *)(local_274 + 0x18);
            }
            local_2ec = local_2f0;
          }
        }
        RBTree_iterIncrement((int *)&local_2bc);
        creature = creature_p;
      } while (local_2bc != piVar21);
      goto LAB_00403256;
    }
LAB_0040329c:
    iVar11 = local_30c;
    local_2f0 = *(int **)((int)creature + 0x16c);
    fVar25 = Combat_computeMaxHealth((int)creature);
    local_308 = (uint *)(float)fVar25;
    if (((float)local_2f0 < (float)local_308 * 0.5) && (*(char *)((int)creature + 0x60) == '\x03')) {
      *(undefined1 *)((int)creature + 0x68) = 0x50;
      *(undefined4 *)((int)creature + 0x6c) = 0;
      *(undefined2 *)((int)creature + 0x1e8) = 0x401;
      *(undefined2 *)((int)creature + 0x1f8) = *(undefined2 *)((int)creature + 400);
      *(undefined4 *)((int)creature + 0x40) = 0;
      *(undefined4 *)((int)creature + 0x44) = 0;
      *(undefined4 *)((int)creature + 0x48) = 0;
      goto LAB_004052e0;
    }
  }
  else {
LAB_00403256:
    local_30c = iVar22;
    iVar11 = local_30c;
    if (local_30c == 0) goto LAB_0040329c;
  }
  pCVar1 = local_2fc + 4;
  *(int *)pCVar1 = *(int *)pCVar1 - dt;
  uVar12 = *(undefined4 *)(local_2fc + 4);
  if (*(int *)pCVar1 < 0) {
    uVar12 = 0;
  }
  *(undefined4 *)(local_2fc + 4) = uVar12;
  local_2f5 = '\0';
  for (puVar18 = (undefined4 *)**(undefined4 **)((int)creature + 0x1178);
      puVar18 != *(undefined4 **)((int)creature + 0x1178); puVar18 = (undefined4 *)*puVar18) {
    if (*(char *)(puVar18 + 2) == '\b') {
      local_2f5 = '\x01';
      break;
    }
  }
  if (iVar11 == 0) {
    if (((*(char *)((int)creature + 0x60) != '\x05') ||
        (*(int *)((int)creature + 0x198) == 0 && *(int *)((int)creature + 0x19c) == 0)) &&
       (*(int *)(local_2fc + 0x10) < 1)) {
      piVar30 = (int *)(*(float *)(local_2fc + 8) * *(float *)(local_2fc + 8));
      piVar21 = *(int **)*local_318;
      piVar17 = local_318;
      local_300 = piVar30;
      if (piVar21 != (int *)*local_318) {
        do {
          pvVar23 = creature_p;
          pvVar5 = (void *)piVar21[6];
          local_314 = pvVar5;
          if (((pvVar5 != (void *)0x0) && (pvVar5 != creature)) &&
             ((0.0 < *(float *)((int)pvVar5 + 0x16c) && (*(char *)((int)pvVar5 + 0x60) != '\x05'))))
          {
            local_2f0 = *(int **)((int)pvVar5 + 0x24);
            local_1b0 = *(uint *)((int)pvVar5 + 0x10) - *local_2f4;
            iStack_1ac = (*(int *)((int)pvVar5 + 0x14) - local_2f4[1]) -
                         (uint)(*(uint *)((int)pvVar5 + 0x10) < *local_2f4);
            local_1a8 = *(uint *)((int)pvVar5 + 0x18) - *(uint *)((int)creature_p + 0x18);
            iStack_1a4 = (*(int *)((int)pvVar5 + 0x1c) - *(int *)((int)creature_p + 0x1c)) -
                         (uint)(*(uint *)((int)pvVar5 + 0x18) < *(uint *)((int)creature_p + 0x18));
            local_1a0 = *(uint *)((int)pvVar5 + 0x20) - *(uint *)((int)creature_p + 0x20);
            iStack_19c = (int)local_2f0 +
                         (-(uint)(*(uint *)((int)pvVar5 + 0x20) < *(uint *)((int)creature_p + 0x20))
                         - *(int *)((int)creature_p + 0x24));
            local_1f8 = (float)CONCAT44(iStack_1ac,local_1b0) * 1.5258789e-05;
            local_308 = (uint *)(float)CONCAT44(iStack_19c,local_1a0);
            local_1f4 = (float)CONCAT44(iStack_1a4,local_1a8) * 1.5258789e-05;
            local_1f0 = (float)local_308 * 1.5258789e-05;
            local_2ec = (int *)(local_1f4 * local_1f4 + local_1f8 * local_1f8 +
                               local_1f0 * local_1f0);
            if (0.0 < *(float *)((int)pvVar5 + 0x1190)) {
              dVar27 = 1.5;
              libm_sse2_pow_precise();
              fVar28 = 1.0 - (float)dVar27 * *(float *)((int)pvVar5 + 0x1190);
              if (fVar28 < 0.1) {
                fVar28 = 0.1;
              }
              local_2ec = (int *)((float)local_2ec / (fVar28 * fVar28));
              piVar30 = local_300;
            }
            piVar17 = local_318;
            iVar11 = local_30c;
            creature = pvVar23;
            if ((local_2f5 == '\0') && ((float)local_2ec < (float)piVar30)) {
              uVar12 = CombatBehavior_areHostile((int)pvVar23,piVar21[6]);
              if (((char)uVar12 != '\0') ||
                 ((((piVar17 = local_318, iVar11 = local_30c, piVar30 = local_300,
                    *(char *)((int)pvVar23 + 0x60) == '\x05' &&
                    (*(int *)((int)pvVar23 + 0x198) == 0 && *(int *)((int)pvVar23 + 0x19c) == 0)) &&
                   (iVar22 = piVar21[6], *(char *)(iVar22 + 0x68) == 'R')) &&
                  ((*(char *)(iVar22 + 0x1020) == '\x14' &&
                   ((uint)*(byte *)(iVar22 + 0x1021) == *(uint *)((int)pvVar23 + 100))))))) {
                action_type = Creature_moveToward((uint *)((int)pvVar23 + 0x10),(uint *)(piVar21[6] + 0x10),
                                      '\x01',200.0);
                piVar17 = local_318;
                iVar11 = local_30c;
                piVar30 = local_300;
                if (action_type != '\0') {
                  uVar13 = Combat_isMeleeSwingOpcode((int)pvVar23);
                  piVar17 = local_318;
                  if (((char)uVar13 == '\0') ||
                     (((iVar22 = piVar21[6], iVar11 = local_30c, piVar30 = local_300,
                       *(char *)(iVar22 + 0x68) == 'R' && (*(char *)(iVar22 + 0x1020) == '\x14')) &&
                      ((uint)*(byte *)(iVar22 + 0x1021) == *(uint *)((int)pvVar23 + 100))))) {
                    local_30c = piVar21[6];
                    local_300 = local_2ec;
                    iVar11 = local_30c;
                    piVar30 = local_2ec;
                  }
                }
              }
            }
          }
          if (*(char *)((int)piVar21 + 0xd) == '\0') {
            piVar6 = (int *)piVar21[2];
            if (*(char *)((int)piVar6 + 0xd) == '\0') {
              action_type = *(char *)(*piVar6 + 0xd);
              piVar21 = piVar6;
              piVar6 = (int *)*piVar6;
              while (action_type == '\0') {
                action_type = *(char *)(*piVar6 + 0xd);
                piVar21 = piVar6;
                piVar6 = (int *)*piVar6;
              }
            }
            else {
              action_type = *(char *)(piVar21[1] + 0xd);
              piVar9 = (int *)piVar21[1];
              piVar6 = piVar21;
              while ((piVar21 = piVar9, action_type == '\0' && (piVar6 == (int *)piVar21[2]))) {
                action_type = *(char *)(piVar21[1] + 0xd);
                piVar9 = (int *)piVar21[1];
                piVar6 = piVar21;
              }
            }
          }
        } while (piVar21 != (int *)*piVar17);
        if (iVar11 != 0) {
          puVar14 = RBTree_findOrInsert((void *)((int)creature + 0x13a4),(uint *)(iVar11 + 8));
          *puVar14 = 0x3f800000;
          CombatBehavior_alertNearbyAllies(iVar11,(int)creature,dt_save);
          goto LAB_00403657;
        }
      }
    }
LAB_00403688:
    bVar24 = false;
  }
  else {
LAB_00403657:
    if (*(char *)((int)creature + 0x68) != '\0') {
      iVar22 = Combat_getAbilityCastTime(creature,0xffffffff);
      iVar15 = Combat_getAbilityCooldown(creature,0xffffffff);
      iVar16 = Combat_getAbilityRecovery(creature,0xffffffff);
      if (*(int *)((int)creature + 0x6c) <= iVar16 + iVar22 / 2 + iVar15) goto LAB_00403688;
    }
    bVar24 = true;
  }
  pvVar5 = creature_p;
  iVar22 = local_30c;
  if (bVar24) {
    *(ushort *)((int)creature + 0x124) = *(ushort *)((int)creature + 0x124) | 0x40;
  }
  else {
    *(ushort *)((int)creature + 0x124) = *(ushort *)((int)creature + 0x124) & 0xffbf;
  }
  pCVar1 = local_2fc + 0x10;
  *(int *)pCVar1 = *(int *)pCVar1 - dt;
  uVar12 = *(undefined4 *)(local_2fc + 0x10);
  if (*(int *)pCVar1 < 0) {
    uVar12 = 0;
  }
  *(undefined4 *)(local_2fc + 0x10) = uVar12;
  if (iVar11 == 0) {
    *(undefined4 *)(local_2fc + 0xc) = 0;
    goto LAB_004052e0;
  }
  local_300 = (int *)(iVar11 + 0x10);
  local_1c8 = *(uint *)(iVar11 + 0x10) - *local_2f4;
  iStack_1c4 = (*(int *)(iVar11 + 0x14) - local_2f4[1]) -
               (uint)(*(uint *)(iVar11 + 0x10) < *local_2f4);
  local_1c0 = *(uint *)(iVar11 + 0x18) - *(uint *)((int)creature_p + 0x18);
  iStack_1bc = (*(int *)(iVar11 + 0x1c) - *(int *)((int)creature_p + 0x1c)) -
               (uint)(*(uint *)(iVar11 + 0x18) < *(uint *)((int)creature_p + 0x18));
  local_1b8 = *(uint *)(iVar11 + 0x20) - *(uint *)((int)creature_p + 0x20);
  iStack_1b4 = (*(int *)(iVar11 + 0x24) - *(int *)((int)creature_p + 0x24)) -
               (uint)(*(uint *)(iVar11 + 0x20) < *(uint *)((int)creature_p + 0x20));
  local_210 = (float)CONCAT44(iStack_1c4,local_1c8) * 1.5258789e-05;
  local_314 = (void *)(float)CONCAT44(iStack_1b4,local_1b8);
  local_20c = (float)CONCAT44(iStack_1bc,local_1c0) * 1.5258789e-05;
  local_2ec = (int *)((float)local_314 * 1.5258789e-05);
  local_318 = (int *)(*(float *)((int)creature_p + 0x80) * 2.0 + *(float *)(local_30c + 0x80));
  local_208 = local_2ec;
  local_301 = Creature_moveToward((uint *)((int)creature_p + 0x10),(uint *)(local_30c + 0x10),'\x01',200.0);
  uVar12 = Combat_isBlockingState((int)pvVar5);
  if (((char)uVar12 != '\0') && (local_301 != '\0')) {
    action_type = *(char *)((int)pvVar5 + 0x68);
    if ((action_type == 'W') || ((action_type == 'V' || (action_type == 'Y')))) {
      iVar11 = Combat_getAbilityCooldown(pvVar5,0xffffffff);
      if (*(int *)((int)pvVar5 + 0x6c) < iVar11) goto LAB_00403847;
    }
    local_318 = (int *)0x42480000;
  }
LAB_00403847:
  iVar11 = *(int *)((int)pvVar5 + 100);
  if ((((iVar11 == 0x2f) || (iVar11 == 0x6f)) || (iVar11 == 0x71)) || (iVar11 == 0x70)) {
    local_318 = (int *)0x41a00000;
  }
  action_type = *(char *)((int)pvVar5 + 0x68);
  if (((action_type == '_') || (action_type == '\x1c')) || (action_type == 'l')) {
    local_318 = (int *)0x42480000;
  }
  if (action_type == 'H') {
    local_318 = (int *)(*(float *)((int)pvVar5 + 0x80) + *(float *)(iVar22 + 0x80));
  }
  local_2f0 = (int *)0x0;
  if ((*(int *)(local_2fc + 4) == 0) &&
     (iVar11 = *(int *)((int)pvVar5 + 0x13e8), iVar11 != *(int *)((int)pvVar5 + 0x13ec))) {
    iVar15 = *(int *)((int)pvVar5 + 0x13ec);
    uVar13 = rand();
    local_2f0 = *(int **)(*(int *)((int)pvVar5 + 0x13e8) +
                         (uVar13 % (uint)(iVar15 - iVar11 >> 2)) * 4);
    if ((local_2f0 == (int *)0x5d) ||
       (((local_2f0 == (int *)0x5b || (local_2f0 == (int *)0x44)) || (local_2f0 == (int *)0x45)))) {
      local_318 = (int *)0x41a00000;
    }
    if ((local_2f0 == (int *)0x56) || (local_2f0 == (int *)0x59)) {
      local_318 = (int *)(*(float *)((int)pvVar5 + 0x80) * 2.0 + *(float *)(iVar22 + 0x80));
    }
  }
  if (local_301 == '\0') {
    local_318 = (int *)0x3f800000;
  }
  local_308 = (uint *)((float)local_318 * (float)local_318);
  fVar28 = local_20c * local_20c + local_210 * local_210;
  local_314 = (void *)((float)local_2ec * (float)local_2ec + fVar28);
  if (((float)local_308 < (float)local_314) || (local_301 == '\0')) {
    *(int *)(local_2fc + 0xc) = *(int *)(local_2fc + 0xc) + dt;
    if (*(int *)(local_2fc + 0xc) < 0x4e21) {
      if ((*(char *)((int)pvVar5 + 0x68) == '_') || (*(char *)((int)pvVar5 + 0x68) == '\x1c')) {
        *(undefined1 *)((int)pvVar5 + 0x68) = 0;
      }
      if ((*(byte *)((int)pvVar5 + 0x5c) & 2) == 0) {
        local_2ec = (int *)0x0;
      }
      fVar28 = (float)local_2ec * (float)local_2ec + fVar28;
      piVar21 = local_2ec;
      fVar29 = local_20c;
      fVar26 = local_210;
      if (0.0 < fVar28) {
        dVar27 = (double)fVar28;
        libm_sse2_sqrt_precise();
        fVar29 = 1.0 / (float)dVar27;
        fVar26 = fVar29 * local_210;
        piVar21 = (int *)(fVar29 * (float)local_2ec);
        fVar29 = fVar29 * local_20c;
      }
      fVar28 = 80.0;
      if (fVar29 * fVar29 + fVar26 * fVar26 + (float)piVar21 * (float)piVar21 <
          (float)local_308 * 4.0) {
        fVar28 = 40.0;
      }
      *(float *)((int)pvVar5 + 0x40) = fVar26 * fVar28;
      *(float *)((int)pvVar5 + 0x44) = fVar29 * fVar28;
      *(float *)((int)pvVar5 + 0x48) = (float)piVar21 * fVar28;
      if (local_301 != '\0') {
        action_type = Creature_resolveSeparation(world_p,(int)pvVar5,(uint *)((int)pvVar5 + 0x10),
                              (uint *)(iVar22 + 0x10),(float)local_318);
        if ((action_type != '\0') && ((*(byte *)((int)pvVar5 + 0x5c) & 0x20) == 0)) {
          World_clearContainers((int)pvVar5);
          goto LAB_004052e0;
        }
      }
      pfVar20 = (float *)RBTree_findOrInsert((void *)((int)pvVar5 + 0x13a4),(uint *)(iVar22 + 8));
      *pfVar20 = *pfVar20 * 0.9;
      pvVar23 = world_p;
      if ((*(int *)((int)pvVar5 + 0x1464) == 0) && ((*(byte *)(iVar22 + 0x5c) & 7) != 0)) {
        *(undefined4 *)((int)pvVar5 + 0x1440) = *(undefined4 *)(iVar22 + 0x10);
        *(undefined4 *)((int)pvVar5 + 0x1444) = *(undefined4 *)(iVar22 + 0x14);
        *(undefined4 *)((int)pvVar5 + 0x1448) = *(undefined4 *)(iVar22 + 0x18);
        *(undefined4 *)((int)pvVar5 + 0x144c) = *(undefined4 *)(iVar22 + 0x1c);
        *(undefined4 *)((int)pvVar5 + 0x1450) = *(undefined4 *)(iVar22 + 0x20);
        *(undefined4 *)((int)pvVar5 + 0x1454) = *(undefined4 *)(iVar22 + 0x24);
        local_2e0 = (*(float *)(iVar22 + 0x88) * 0.5 - 0.1) * 65536.0;
        uVar31 = ftol2();
        puVar14 = (uint *)((int)pvVar5 + 0x1450);
        uVar13 = *puVar14;
        *puVar14 = *puVar14 - (uint)uVar31;
        *(int *)((int)pvVar5 + 0x1454) =
             (*(int *)((int)pvVar5 + 0x1454) - (int)(uVar31 >> 0x20)) -
             (uint)(uVar13 < (uint)uVar31);
        *(uint *)((int)pvVar5 + 0x1428) = *(uint *)((int)pvVar5 + 0x10);
        *(undefined4 *)((int)pvVar5 + 0x142c) = *(undefined4 *)((int)pvVar5 + 0x14);
        *(undefined4 *)((int)pvVar5 + 0x1430) = *(undefined4 *)((int)pvVar5 + 0x18);
        *(undefined4 *)((int)pvVar5 + 0x1434) = *(undefined4 *)((int)pvVar5 + 0x1c);
        *(undefined4 *)((int)pvVar5 + 0x1438) = *(undefined4 *)((int)pvVar5 + 0x20);
        *(undefined4 *)((int)pvVar5 + 0x143c) = *(undefined4 *)((int)pvVar5 + 0x24);
        local_2e0 = (*(float *)((int)pvVar5 + 0x88) * 0.5 - 0.1) * 65536.0;
        uVar31 = ftol2();
        pvVar23 = world_p;
        puVar14 = (uint *)((int)pvVar5 + 0x1438);
        uVar13 = *puVar14;
        *puVar14 = *puVar14 - (uint)uVar31;
        *(int *)((int)pvVar5 + 0x143c) =
             (*(int *)((int)pvVar5 + 0x143c) - (int)(uVar31 >> 0x20)) -
             (uint)(uVar13 < (uint)uVar31);
        *(float *)((int)pvVar5 + 0x1458) =
             *(float *)((int)pvVar5 + 0x80) + *(float *)(iVar22 + 0x80);
        NavGraph_expandNeighbors(world_p,pvVar5);
      }
      if (*(int *)((int)pvVar5 + 0x1410) != 0) {
        iVar11 = 0;
        piVar21 = (int *)((int)pvVar5 + 0x1428);
        do {
          if ((*piVar21 != piVar21[6]) || (piVar21[1] != piVar21[7])) {
            iVar11 = 0;
            goto LAB_00405241;
          }
          iVar11 = iVar11 + 1;
          piVar21 = piVar21 + 2;
        } while (iVar11 < 3);
      }
    }
    else {
      local_2f0 = (int *)((int)pvVar5 + 0x13a4);
      piVar21 = *(int **)(*(int *)((int)pvVar5 + 0x13a4) + 4);
      action_type = *(char *)((int)piVar21 + 0xd);
      while (action_type == '\0') {
        std_Rb_tree_destroy_recursive_B((int *)piVar21[2]);
        piVar17 = (int *)*piVar21;
        operator_delete(piVar21);
        piVar21 = piVar17;
        pvVar5 = creature_p;
        action_type = *(char *)((int)piVar17 + 0xd);
      }
      *(int *)(*local_2f0 + 4) = *local_2f0;
      *(int *)*local_2f0 = *local_2f0;
      *(int *)(*local_2f0 + 8) = *local_2f0;
      local_2f0[1] = 0;
      World_clearContainers((int)pvVar5);
      *(undefined4 *)(local_2fc + 0x10) = 3000;
      *(undefined4 *)(local_2fc + 0xc) = 0;
    }
    goto LAB_004052e0;
  }
  *(undefined4 *)(local_2fc + 0xc) = 0;
  World_clearContainers((int)pvVar5);
  pvVar23 = creature_p;
  *(undefined4 *)((int)pvVar5 + 0x13e0) = 0;
  *(undefined4 *)((int)pvVar5 + 0x40) = 0;
  *(undefined4 *)((int)pvVar5 + 0x44) = 0;
  *(undefined4 *)((int)pvVar5 + 0x48) = 0;
  if ((((((local_2f5 == '\0') && (*(char *)(iVar22 + 0x68) == 'R')) &&
        (*(char *)(iVar22 + 0x1020) == '\x14')) &&
       ((uint)*(byte *)(iVar22 + 0x1021) == *(uint *)((int)pvVar5 + 100))) &&
      ((*(char *)((int)pvVar5 + 0x60) != '\x05' ||
       (*(int *)((int)pvVar5 + 0x198) == 0 && *(int *)((int)pvVar5 + 0x19c) == 0)))) &&
     ((float)local_314 <= (float)local_308)) {
    *(undefined4 *)((int)pvVar5 + 0x11d0) = *(undefined4 *)(iVar22 + 8);
    *(undefined4 *)((int)pvVar5 + 0x11d4) = *(undefined4 *)(iVar22 + 0xc);
    iVar11 = Combat_getWindupAndRecovery((int)pvVar5);
    if (iVar11 < *(int *)((int)pvVar5 + 0x6c)) {
      if (*(char *)((int)pvVar5 + 0x68) != 'n') {
        *(undefined4 *)((int)pvVar5 + 0x70) = 0;
      }
      if (*(int *)((int)pvVar5 + 0x70) < 5) {
        *(undefined1 *)((int)pvVar5 + 0x68) = 0x6e;
        *(undefined4 *)((int)pvVar5 + 0x6c) = 0;
      }
      else {
        local_301 = '\0';
        CombatState_zeroInit((undefined1 *)&uStack_2a0);
        piVar21 = *(int **)((int)pvVar5 + 0x1178);
        piVar17 = (int *)*piVar21;
        action_type = local_301;
        if (piVar17 != piVar21) {
          do {
            if ((char)piVar17[2] == '\a') {
              uStack_2a0 = *(ulonglong *)(piVar17 + 2);
              uStack_298 = *(ulonglong *)(piVar17 + 4);
              uStack_290 = *(undefined8 *)(piVar17 + 6);
              action_type = '\x01';
            }
            piVar17 = (int *)*piVar17;
          } while (piVar17 != piVar21);
          iVar22 = local_30c;
          if (action_type != '\0') {
            uStack_298 = uStack_298 & 0xffffffff00000000;
            uStack_2a0 = uStack_2a0 & 0xffffffff;
            CombatBehavior_pushTargetPos(pvVar5,(char *)&uStack_2a0,dt_save);
          }
        }
        uStack_290 = *(undefined8 *)(iVar22 + 8);
        uStack_2a0 = CONCAT71(uStack_2a0._1_7_,8);
        uStack_298 = CONCAT44(uStack_298._4_4_,20000);
        uStack_2a0 = uStack_2a0 & 0xffffffff;
        CombatBehavior_pushTargetPos(pvVar5,(char *)&uStack_2a0,dt_save);
      }
    }
    goto LAB_004052e0;
  }
  iStack_1e0 = *(uint *)(iVar22 + 0x10) - *local_2f4;
  iStack_1dc = (*(int *)(iVar22 + 0x14) - local_2f4[1]) -
               (uint)(*(uint *)(iVar22 + 0x10) < *local_2f4);
  iStack_1d8 = *(uint *)(iVar22 + 0x18) - *(uint *)((int)creature_p + 0x18);
  iStack_1d4 = (*(int *)(iVar22 + 0x1c) - *(int *)((int)creature_p + 0x1c)) -
               (uint)(*(uint *)(iVar22 + 0x18) < *(uint *)((int)creature_p + 0x18));
  iStack_1d0 = *(uint *)(iVar22 + 0x20) - *(uint *)((int)creature_p + 0x20);
  iStack_1cc = (*(int *)(iVar22 + 0x24) - *(int *)((int)creature_p + 0x24)) -
               (uint)(*(uint *)(iVar22 + 0x20) < *(uint *)((int)creature_p + 0x20));
  puVar14 = (uint *)((int)creature_p + 0x10);
  fStack_21c = (float)CONCAT44(iStack_1dc,iStack_1e0) * 1.5258789e-05;
  local_314 = (void *)(float)CONCAT44(iStack_1cc,iStack_1d0);
  fStack_218 = (float)CONCAT44(iStack_1d4,iStack_1d8) * 1.5258789e-05;
  *(ushort *)((int)creature_p + 0x124) = *(ushort *)((int)creature_p + 0x124) | 4;
  local_318 = (int *)((float)local_314 * 1.5258789e-05);
  world_p = (void *)(fStack_218 * fStack_218 + fStack_21c * fStack_21c +
                      (float)local_318 * (float)local_318);
  piStack_214 = local_318;
  if (local_2f0 != (int *)0x0) {
    *(undefined4 *)(local_2fc + 4) = 20000;
    *(char *)((int)creature_p + 0x68) = (char)local_2f0;
    *(undefined4 *)((int)creature_p + 0x6c) = 0;
    fVar28 = fStack_218;
    fVar29 = fStack_21c;
    goto LAB_00404f21;
  }
  iVar11 = *(int *)((int)creature_p + 100);
  if (iVar11 == 0x74) {
    iVar11 = Combat_getWindupAndRecovery((int)creature_p);
    fVar28 = fStack_218;
    fVar29 = fStack_21c;
    if (iVar11 < *(int *)((int)pvVar23 + 0x6c)) {
      pvStack_2ac = (void *)0x0;
      iStack_2a8 = 0;
      uStack_2a4 = 0;
      uStack_c = 0;
      uStack_244 = 0x45;
      std_vector_push_back_int(&pvStack_2ac,&uStack_244);
      uStack_23c = 0x4a;
      std_vector_push_back_int(&pvStack_2ac,&uStack_23c);
      uStack_234 = 0x49;
      std_vector_push_back_int(&pvStack_2ac,&uStack_234);
      uVar13 = rand();
      *(undefined1 *)((int)pvVar23 + 0x68) =
           *(undefined1 *)
            ((int)pvStack_2ac + (uVar13 % (uint)(iStack_2a8 - (int)pvStack_2ac >> 2)) * 4);
      *(undefined4 *)((int)pvVar23 + 0x6c) = 0;
      fVar28 = fStack_218;
      fVar29 = fStack_21c;
      if (pvStack_2ac != (void *)0x0) {
        operator_delete(pvStack_2ac);
        fVar28 = fStack_218;
        fVar29 = fStack_21c;
      }
    }
    goto LAB_00404f21;
  }
  if (iVar11 == 0x76) {
    iVar11 = Combat_getWindupAndRecovery((int)creature_p);
    if (iVar11 < *(int *)((int)pvVar23 + 0x6c)) {
      iStack_2c8 = 0;
      iStack_2c4 = 0;
      uStack_2c0 = 0;
      uStack_c = 1;
      uStack_22c = 7;
      std_vector_push_back_int(&iStack_2c8,&uStack_22c);
      uStack_24c = 6;
      std_vector_push_back_int(&iStack_2c8,&uStack_24c);
      uStack_250 = 0x14;
      std_vector_push_back_int(&iStack_2c8,&uStack_250);
      if (*(short *)((int)pvVar23 + 0x8c) == 0x86a) {
        uStack_278 = 0x5f;
        puVar18 = &uStack_278;
      }
      else {
        uStack_230 = 0x56;
        puVar18 = &uStack_230;
      }
      std_vector_push_back_int(&iStack_2c8,puVar18);
      iVar11 = iStack_2c8;
      iVar22 = iStack_2c4 - iStack_2c8;
      uVar13 = rand();
      pvVar23 = creature_p;
      uStack_c = 0xffffffff;
      *(undefined1 *)((int)creature_p + 0x68) =
           *(undefined1 *)(iVar11 + (uVar13 % (uint)(iVar22 >> 2)) * 4);
      *(undefined4 *)((int)creature_p + 0x6c) = 0;
      std_vector_free(&iStack_2c8);
    }
    fVar28 = fStack_218;
    fVar29 = fStack_21c;
    if (*(char *)((int)pvVar23 + 0x68) == '_') {
      puVar14 = (uint *)Combat_getProjectileSpawnPos(pvVar23,auStack_b0);
      puVar14 = Vec3i64_subtract(local_300,auStack_158,puVar14);
      Vec3i64_toFloatScaled(&fStack_21c,(longlong *)puVar14);
      local_318 = piStack_214;
      fVar28 = fStack_218;
      fVar29 = fStack_21c;
    }
    goto LAB_00404f21;
  }
  if (((iVar11 == 0x2f) || (iVar11 == 0x6f)) || ((iVar11 == 0x71 || (iVar11 == 0x70)))) {
    iVar11 = Combat_getWindupAndRecovery((int)creature_p);
    fVar28 = fStack_218;
    fVar29 = fStack_21c;
    if (iVar11 < *(int *)((int)pvVar23 + 0x6c)) {
      iStack_2b8 = 0;
      iStack_2b4 = 0;
      uStack_2b0 = 0;
      uStack_c = 2;
      uStack_26c = 0x6c;
      std_vector_push_back_int(&iStack_2b8,&uStack_26c);
      uStack_264 = 0x36;
      std_vector_push_back_int(&iStack_2b8,&uStack_264);
      local_2e0 = 1.06499e-43;
      std_vector_push_back_int(&iStack_2b8,&local_2e0);
      uVar13 = rand();
      action_type = *(char *)(iStack_2b8 + (uVar13 % (uint)(iStack_2b4 - iStack_2b8 >> 2)) * 4);
      *(char *)((int)pvVar23 + 0x68) = action_type;
      *(undefined4 *)((int)pvVar23 + 0x6c) = 0;
      if (action_type == '6') {
        uVar13 = 0x20000;
        iVar11 = 0;
        puVar18 = auStack_68;
        puVar14 = Vec3i64_subtract(local_300,auStack_38,(uint *)((int)pvVar23 + 0x10));
        plVar19 = (longlong *)Vec3i64_copyAndScale(puVar14,puVar18,uVar13,iVar11);
        Vec3i64_toFloatScaled((void *)((int)pvVar23 + 0x34),plVar19);
        *(undefined4 *)((int)pvVar23 + 0x3c) = 0x41700000;
      }
      piVar21 = &iStack_2b8;
LAB_00404f0a:
      std_vector_free(piVar21);
      fVar28 = fStack_218;
      fVar29 = fStack_21c;
    }
    goto LAB_00404f21;
  }
  if (iVar11 == 0x77) {
    iVar11 = Combat_getWindupAndRecovery((int)creature_p);
    fVar28 = fStack_218;
    fVar29 = fStack_21c;
    if (iVar11 < *(int *)((int)pvVar23 + 0x6c)) {
      iStack_2dc = 0;
      iStack_2d8 = 0;
      uStack_2d4 = 0;
      sVar3 = *(short *)((int)pvVar23 + 0x8c);
      uStack_c = 3;
      if (((sVar3 == 0x863) || (sVar3 == 0x864)) || (sVar3 == 0x865)) {
        uStack_248 = 0x45;
        puVar18 = &uStack_248;
      }
      else {
        uStack_270 = 0x44;
        puVar18 = &uStack_270;
      }
      std_vector_push_back_int(&iStack_2dc,puVar18);
      if ((*(short *)((int)pvVar23 + 0x96) == 0x867) || (*(short *)((int)pvVar23 + 0x96) == 0x868))
      {
        uStack_268 = 0x46;
        std_vector_push_back_int(&iStack_2dc,&uStack_268);
      }
      if ((*(short *)((int)pvVar23 + 0x90) == 0x85f) || (*(short *)((int)pvVar23 + 0x90) == 0x860))
      {
        uStack_260 = 0x4b;
        puVar18 = &uStack_260;
      }
      else {
        uStack_238 = 0x4a;
        puVar18 = &uStack_238;
      }
      std_vector_push_back_int(&iStack_2dc,puVar18);
      if ((*(short *)((int)pvVar23 + 0x94) == 0x85c) || (*(short *)((int)pvVar23 + 0x94) == 0x85d))
      {
        uStack_240 = 0x4d;
        std_vector_push_back_int(&iStack_2dc,&uStack_240);
        uStack_258 = 0x4e;
        std_vector_push_back_int(&iStack_2dc,&uStack_258);
      }
      sVar3 = *(short *)((int)pvVar23 + 0x94);
      if ((((sVar3 == 0x857) || (sVar3 == 0x858)) || (sVar3 == 0x859)) ||
         ((sVar3 == 0x85a || (sVar3 == 0x85b)))) {
        uStack_254 = 0x4c;
        std_vector_push_back_int(&iStack_2dc,&uStack_254);
      }
      if (((*(char *)((int)pvVar23 + 0x68) != 'G') && (*(char *)((int)pvVar23 + 0x68) != 'H')) &&
         (*(short *)((int)pvVar23 + 0x94) == 0x855)) {
        uVar13 = rand();
        uVar13 = uVar13 & 0x80000001;
        bVar24 = uVar13 == 0;
        if ((int)uVar13 < 0) {
          bVar24 = (uVar13 - 1 | 0xfffffffe) == 0xffffffff;
        }
        if (!bVar24) {
          uStack_284 = 0x47;
          std_vector_push_back_int(&iStack_2dc,&uStack_284);
        }
      }
      if (((*(char *)((int)pvVar23 + 0x68) != 'G') && (*(char *)((int)pvVar23 + 0x68) != 'H')) &&
         (*(short *)((int)pvVar23 + 0x94) == 0x856)) {
        uVar13 = rand();
        uVar13 = uVar13 & 0x80000001;
        bVar24 = uVar13 == 0;
        if ((int)uVar13 < 0) {
          bVar24 = (uVar13 - 1 | 0xfffffffe) == 0xffffffff;
        }
        if (!bVar24) {
          fStack_2d0 = 1.00893e-43;
          std_vector_push_back_int(&iStack_2dc,&fStack_2d0);
        }
      }
      if (*(char *)((int)pvVar23 + 0x68) != 'I') {
        fStack_2e4 = 1.02295e-43;
        std_vector_push_back_int(&iStack_2dc,&fStack_2e4);
      }
      iVar11 = iStack_2d8;
      if (iStack_2dc != iStack_2d8) {
        uVar13 = rand();
        *(undefined1 *)((int)pvVar23 + 0x68) =
             *(undefined1 *)(iStack_2dc + (uVar13 % (uint)(iVar11 - iStack_2dc >> 2)) * 4);
        *(undefined4 *)((int)pvVar23 + 0x6c) = 0;
      }
      piVar21 = &iStack_2dc;
      goto LAB_00404f0a;
    }
    goto LAB_00404f21;
  }
  uVar12 = Combat_isSpiritChanneling((int)creature_p);
  fVar28 = fStack_218;
  fVar29 = fStack_21c;
  if ((char)uVar12 != '\0') {
    if (3600.0 <= (float)world_p) goto LAB_00404f21;
    if (*(float *)((int)pvVar23 + 0x170) <= 0.5) {
LAB_004041dc:
      Combat_updateAttackState((int)pvVar23);
    }
    else {
      uVar13 = rand();
      uVar13 = uVar13 & 0x80000001;
      bVar24 = uVar13 == 0;
      if ((int)uVar13 < 0) {
        bVar24 = (uVar13 - 1 | 0xfffffffe) == 0xffffffff;
      }
      if (bVar24) goto LAB_004041dc;
      Combat_updateAbilityAndProc((int)pvVar23);
    }
    action_type = *(char *)((int)pvVar23 + 0x68);
    if (((action_type == '\x1e') || (action_type == '\x1f')) || ((action_type == ' ' || (action_type == '!')))) {
      iVar11 = Combat_getAbilityCooldown(pvVar23,0xffffffff);
      if (iVar11 < *(int *)((int)pvVar23 + 0x6c) - dt) {
        puVar14 = Vec3i64_subtract((void *)((int)pvVar23 + 0x1320),auStack_110,puVar14);
        Vec3i64_toFloatScaled(&fStack_21c,(longlong *)puVar14);
        local_318 = piStack_214;
      }
      else {
        Copy24Bytes((void *)((int)pvVar23 + 0x1320),(undefined4 *)(local_30c + 0x1350));
      }
    }
    fVar28 = fStack_218;
    fVar29 = fStack_21c;
    if ((*(char *)((int)pvVar23 + 0x68) == '\x1c') && (25.0 < (float)world_p)) {
      fStack_2e4 = (float)*(int *)((int)pvVar23 + 0x6c) * 0.005;
      dVar27 = (double)fStack_2e4;
      libm_sse2_cos_precise();
      fStack_2d0 = (float)dVar27 * 1.5 + fStack_21c;
      dVar27 = (double)fStack_2e4;
      libm_sse2_sin_precise();
      fVar28 = (float)dVar27 * 1.5 + fStack_218;
      fVar29 = fStack_2d0;
    }
    goto LAB_00404f21;
  }
  if (*(int *)((int)pvVar23 + 100) == 0x65) {
    if (64.0 <= (float)world_p) {
      if ((float)world_p < 3600.0) {
        iVar11 = Combat_getWindupAndRecovery((int)pvVar23);
        fVar28 = fStack_218;
        fVar29 = fStack_21c;
        if (iVar11 < *(int *)((int)pvVar23 + 0x6c)) {
          *(undefined4 *)((int)pvVar23 + 0x6c) = 0;
          *(undefined1 *)((int)pvVar23 + 0x68) = 0x25;
          fStack_18c = *(float *)(local_30c + 0x88) * 0.4;
          uStack_194 = 0;
          uStack_190 = 0;
          Vec3i64_randomize((int)auStack_170);
          puVar33 = auStack_170;
          puVar32 = auStack_80;
          puVar14 = Vec3i64_subtract(local_300,auStack_140,puVar14);
          puVar14 = Vec3i64_add(puVar14,puVar32,puVar33);
          Vec3i64_toFloatScaled((void *)((int)pvVar23 + 0x160),(longlong *)puVar14);
          fVar28 = fStack_218;
          fVar29 = fStack_21c;
        }
      }
    }
    else {
      puVar14 = Vec3i64_subtract(local_300,auStack_50,puVar14);
      Vec3i64_toFloatScaled((void *)((int)pvVar23 + 0x160),(longlong *)puVar14);
      *(ushort *)((int)pvVar23 + 0x124) = *(ushort *)((int)pvVar23 + 0x124) | 4;
      fVar28 = fStack_218;
      fVar29 = fStack_21c;
      if (2000 < *(int *)((int)pvVar23 + 0x6c)) {
        uVar13 = rand();
        uVar13 = uVar13 & 0x80000001;
        bVar24 = uVar13 == 0;
        if ((int)uVar13 < 0) {
          bVar24 = (uVar13 - 1 | 0xfffffffe) == 0xffffffff;
        }
        if (!bVar24) {
          uVar13 = *(uint *)((int)pvVar23 + 0x20);
          uVar7 = *(uint *)(local_30c + 0x20);
          uVar8 = *(uint *)(local_30c + 0x20);
          iVar11 = *(int *)((int)pvVar23 + 0x24);
          iVar22 = *(int *)(local_30c + 0x24);
          uVar31 = ftol2();
          if (CONCAT44((iVar11 - iVar22) - (uint)(uVar13 < uVar7),uVar13 - uVar8) <=
              (longlong)uVar31) {
            *(undefined4 *)((int)pvVar23 + 0x3c) = 0x41f00000;
            fVar28 = fStack_218;
            fVar29 = fStack_21c;
            goto LAB_00404f21;
          }
        }
        *(undefined4 *)((int)pvVar23 + 0x6c) = 0;
        *(undefined1 *)((int)pvVar23 + 0x68) = 0x33;
        puVar14 = Vec3i64_subtract(local_300,auStack_e0,(uint *)((int)pvVar23 + 0x10));
        Vec3i64_toFloatScaled((void *)((int)pvVar23 + 0x34),(longlong *)puVar14);
        fVar28 = fStack_218;
        fVar29 = fStack_21c;
        if (0.0 < *(float *)((int)pvVar23 + 0x34) * *(float *)((int)pvVar23 + 0x34) +
                  *(float *)((int)pvVar23 + 0x38) * *(float *)((int)pvVar23 + 0x38) +
                  *(float *)((int)pvVar23 + 0x3c) * *(float *)((int)pvVar23 + 0x3c)) {
          fStack_2e4 = *(float *)((int)pvVar23 + 0x34);
          dVar27 = (double)(fStack_2e4 * fStack_2e4 +
                            *(float *)((int)pvVar23 + 0x38) * *(float *)((int)pvVar23 + 0x38) +
                           *(float *)((int)pvVar23 + 0x3c) * *(float *)((int)pvVar23 + 0x3c));
          libm_sse2_sqrt_precise();
LAB_00404420:
          fVar28 = 1.0 / (float)dVar27;
          *(float *)((int)pvVar23 + 0x34) = fStack_2e4 * fVar28;
          *(float *)((int)pvVar23 + 0x38) = *(float *)((int)pvVar23 + 0x38) * fVar28;
          *(float *)((int)pvVar23 + 0x3c) = *(float *)((int)pvVar23 + 0x3c) * fVar28;
          *(float *)((int)pvVar23 + 0x34) = *(float *)((int)pvVar23 + 0x34) * 10.0;
          *(float *)((int)pvVar23 + 0x38) = *(float *)((int)pvVar23 + 0x38) * 10.0;
          *(float *)((int)pvVar23 + 0x3c) = *(float *)((int)pvVar23 + 0x3c) * 10.0;
          fVar28 = fStack_218;
          fVar29 = fStack_21c;
        }
      }
    }
    goto LAB_00404f21;
  }
  uVar4 = *(ushort *)((int)pvVar23 + 0x7e);
  if (((uVar4 & 2) != 0) && ((uVar4 & 0x10) != 0)) {
    *(ushort *)((int)pvVar23 + 0x124) = *(ushort *)((int)pvVar23 + 0x124) & 0xfffb;
    if ((float)world_p < 64.0) {
      puVar14 = Vec3i64_subtract(local_300,auStack_128,puVar14);
      Vec3i64_toFloatScaled((void *)((int)pvVar23 + 0x160),(longlong *)puVar14);
      *(ushort *)((int)pvVar23 + 0x124) = *(ushort *)((int)pvVar23 + 0x124) | 4;
      fVar28 = fStack_218;
      fVar29 = fStack_21c;
      if (2000 < *(int *)((int)pvVar23 + 0x6c)) {
        uVar13 = rand();
        uVar13 = uVar13 & 0x80000001;
        bVar24 = uVar13 == 0;
        if ((int)uVar13 < 0) {
          bVar24 = (uVar13 - 1 | 0xfffffffe) == 0xffffffff;
        }
        if (!bVar24) {
          uVar13 = *(uint *)((int)pvVar23 + 0x20);
          uVar7 = *(uint *)(local_30c + 0x20);
          uVar8 = *(uint *)(local_30c + 0x20);
          iVar11 = *(int *)((int)pvVar23 + 0x24);
          iVar22 = *(int *)(local_30c + 0x24);
          uVar31 = ftol2();
          if (CONCAT44((iVar11 - iVar22) - (uint)(uVar13 < uVar7),uVar13 - uVar8) <=
              (longlong)uVar31) {
            *(undefined4 *)((int)pvVar23 + 0x3c) = 0x40a00000;
            fVar28 = fStack_218;
            fVar29 = fStack_21c;
            goto LAB_00404f21;
          }
        }
        *(undefined4 *)((int)pvVar23 + 0x6c) = 0;
        *(undefined1 *)((int)pvVar23 + 0x68) = 0x33;
        puVar14 = Vec3i64_subtract(local_300,auStack_f8,(uint *)((int)pvVar23 + 0x10));
        Vec3i64_toFloatScaled((void *)((int)pvVar23 + 0x34),(longlong *)puVar14);
        fVar28 = fStack_218;
        fVar29 = fStack_21c;
        if (0.0 < *(float *)((int)pvVar23 + 0x34) * *(float *)((int)pvVar23 + 0x34) +
                  *(float *)((int)pvVar23 + 0x38) * *(float *)((int)pvVar23 + 0x38) +
                  *(float *)((int)pvVar23 + 0x3c) * *(float *)((int)pvVar23 + 0x3c)) {
          fStack_2e4 = *(float *)((int)pvVar23 + 0x34);
          dVar27 = (double)(fStack_2e4 * fStack_2e4 +
                            *(float *)((int)pvVar23 + 0x38) * *(float *)((int)pvVar23 + 0x38) +
                           *(float *)((int)pvVar23 + 0x3c) * *(float *)((int)pvVar23 + 0x3c));
          libm_sse2_sqrt_precise();
          goto LAB_00404420;
        }
      }
    }
    goto LAB_00404f21;
  }
  if ((((*(int *)((int)pvVar23 + 100) != 0x68) &&
       (action_type = *(char *)((int)pvVar23 + 0xaa9), action_type != '\x06')) && (action_type != '\a')) &&
     (action_type != '\b')) {
    if ((uVar4 & 0x10) == 0) {
      if ((uVar4 & 8) == 0) {
        fVar26 = (*(float *)((int)pvVar23 + 0x80) + *(float *)(local_30c + 0x80)) * 3.0;
        if ((float)world_p < fVar26 * fVar26) {
          action_type = *(char *)((int)pvVar23 + 0x68);
          if (((action_type != ';') && (action_type != '?')) &&
             ((action_type != '\b' && (*(int *)((int)pvVar23 + 0x128) == 0)))) {
            iVar11 = rand();
            if (iVar11 % 10 == 0) {
              iVar11 = Combat_isRangedOrSpecialOpcode((int)pvVar23);
              if (((char)iVar11 == '\0') &&
                 (*(float *)((int)pvVar23 + 0x80) <= 2.0 && *(float *)((int)pvVar23 + 0x80) != 2.0))
              {
                iVar11 = Combat_getWindupAndRecovery((int)pvVar23);
                if ((iVar11 <= *(int *)((int)pvVar23 + 0x6c)) &&
                   ((*(byte *)((int)pvVar23 + 0x5c) & 3) != 0)) {
                  puVar14 = Vec3i64_subtract(local_300,auStack_c8,puVar14);
                  Vec3i64_toFloatScaled(&fStack_1ec,(longlong *)puVar14);
                  fVar26 = fStack_1e8 * fStack_1e8 + fStack_1ec * fStack_1ec + 0.0;
                  fVar28 = fStack_218;
                  fVar29 = fStack_21c;
                  if (0.0 < fVar26) {
                    dVar27 = (double)fVar26;
                    libm_sse2_sqrt_precise();
                    fVar28 = 1.0 / (float)dVar27;
                    local_2fc = (CombatBehavior *)(fStack_1ec * fVar28);
                    local_2f4 = (uint *)(fStack_1e8 * fVar28);
                    world_p = (void *)(fVar28 * 0.0);
                    uVar13 = rand();
                    uVar13 = uVar13 & 0x80000003;
                    if ((int)uVar13 < 0) {
                      uVar13 = (uVar13 - 1 | 0xfffffffc) + 1;
                    }
                    switch(uVar13) {
                    case 0:
                      goto switchD_00404866_caseD_0;
                    case 1:
                      goto switchD_00404866_caseD_1;
                    case 2:
                      goto switchD_00404866_caseD_2;
                    case 3:
                      goto switchD_00404866_caseD_3;
                    }
                    goto switchD_00404866_default;
                  }
                  goto LAB_00404f21;
                }
              }
            }
          }
          if ((((*(float *)((int)pvVar23 + 0x170) < 0.8) &&
               (action_type = *(char *)((int)pvVar23 + 0x68), action_type != ';')) && (action_type != '?')) &&
             (action_type != '\b')) goto LAB_004046f3;
          fVar28 = fStack_218;
          fVar29 = fStack_21c;
          if (*(int *)((int)pvVar23 + 0x128) == 0) {
            iVar11 = Combat_getWindupAndRecovery((int)pvVar23);
            fVar28 = fStack_218;
            fVar29 = fStack_21c;
            if (iVar11 < *(int *)((int)pvVar23 + 0x6c)) {
              if (*(char *)((int)pvVar23 + 0xaa9) == '\x05') {
                *(undefined1 *)((int)pvVar23 + 0x68) = 5;
                *(undefined4 *)((int)pvVar23 + 0x6c) = 0;
              }
              else if ((*(char *)((int)pvVar23 + 0xaa8) == '\0') ||
                      (*(char *)((int)pvVar23 + 0x990) != '\0')) {
                action_type = *(char *)((int)pvVar23 + 0x991);
                if (action_type == '\r') {
                  if (*(char *)((int)pvVar23 + 0x68) == '\b') {
                    if (*(float *)((int)pvVar23 + 0x170) <= *(float *)((int)pvVar23 + 0x144)) {
                      *(undefined1 *)((int)pvVar23 + 0x68) = 0x68;
                      *(undefined4 *)((int)pvVar23 + 0x6c) = 0;
                      goto LAB_00404f21;
                    }
                  }
                  else {
                    *(undefined4 *)((int)pvVar23 + 0x6c) = 0;
                  }
                  *(undefined1 *)((int)pvVar23 + 0x68) = 8;
                }
                else if (action_type == '\x03') {
                  *(undefined1 *)((int)pvVar23 + 0x68) = 0x11;
                  *(undefined4 *)((int)pvVar23 + 0x6c) = 0;
                }
                else if (action_type == '\x04') {
                  *(undefined1 *)((int)pvVar23 + 0x68) = 0x14;
                  *(undefined4 *)((int)pvVar23 + 0x6c) = 0;
                }
                else if (*(char *)((int)pvVar23 + 0xaa8) == '\0') {
                  bVar24 = Combat_canCastAbility(pvVar23,0x36);
                  if (bVar24) {
LAB_00404a35:
                    *(float *)((int)pvVar23 + 0x3c) = *(float *)((int)pvVar23 + 0x3c) + 20.0;
                    *(undefined1 *)((int)pvVar23 + 0x68) = 0x36;
                    *(undefined4 *)((int)pvVar23 + 0x6c) = 0;
                    fVar28 = fStack_218;
                    fVar29 = fStack_21c;
                  }
                  else {
                    Combat_updateAbilityAndProc((int)pvVar23);
                    fVar28 = fStack_218;
                    fVar29 = fStack_21c;
                  }
                }
                else if ((*(char *)((int)pvVar23 + 0x68) != '?') ||
                        (*(float *)((int)pvVar23 + 0x144) < *(float *)((int)pvVar23 + 0x170))) {
                  bVar24 = Combat_canCastAbility(pvVar23,0x36);
                  if (bVar24) goto LAB_00404a35;
                  if (*(char *)((int)pvVar23 + 0x68) != '?') {
                    *(undefined4 *)((int)pvVar23 + 0x6c) = 0;
                  }
                  *(undefined1 *)((int)pvVar23 + 0x68) = 0x3f;
                  fVar28 = fStack_218;
                  fVar29 = fStack_21c;
                }
                else {
                  *(undefined1 *)((int)pvVar23 + 0x68) = 0xb;
                  iVar11 = Combat_getAbilityCooldown(pvVar23,0xffffffff);
                  *(int *)((int)pvVar23 + 0x6c) = iVar11;
                  fVar28 = fStack_218;
                  fVar29 = fStack_21c;
                }
              }
              else if ((*(char *)((int)pvVar23 + 0x68) != ';') ||
                      (*(float *)((int)pvVar23 + 0x144) < *(float *)((int)pvVar23 + 0x170))) {
                bVar24 = Combat_canCastAbility(pvVar23,0x36);
                if (bVar24) goto LAB_00404a35;
                if (*(char *)((int)pvVar23 + 0x68) != ';') {
                  *(undefined4 *)((int)pvVar23 + 0x6c) = 0;
                }
                *(undefined1 *)((int)pvVar23 + 0x68) = 0x3b;
                fVar28 = fStack_218;
                fVar29 = fStack_21c;
              }
              else if (*(char *)((int)pvVar23 + 0x141) == '\x01') {
                *(undefined1 *)((int)pvVar23 + 0x68) = 0x3d;
                *(undefined4 *)((int)pvVar23 + 0x6c) = 0;
              }
              else {
                *(undefined1 *)((int)pvVar23 + 0x68) = 0x3c;
                iVar11 = Combat_getAbilityCooldown(pvVar23,0xffffffff);
                *(int *)((int)pvVar23 + 0x6c) = iVar11;
                fVar28 = fStack_218;
                fVar29 = fStack_21c;
              }
            }
          }
        }
      }
      else {
LAB_004046f3:
        Combat_updateAttackState((int)pvVar23);
        fVar28 = fStack_218;
        fVar29 = fStack_21c;
      }
    }
    else {
      iVar11 = Combat_getWindupAndRecovery((int)pvVar23);
      fVar28 = fStack_218;
      fVar29 = fStack_21c;
      if (iVar11 < *(int *)((int)pvVar23 + 0x6c)) {
        if (*(int *)((int)pvVar23 + 100) == 0x19) {
          bVar24 = Combat_canCastAbility(pvVar23,0x48);
          if (bVar24) {
            *(undefined1 *)((int)pvVar23 + 0x68) = 0x48;
            *(undefined4 *)((int)pvVar23 + 0x6c) = 0;
            fVar28 = fStack_218;
            fVar29 = fStack_21c;
            goto LAB_00404f21;
          }
        }
        *(undefined1 *)((int)pvVar23 + 0x68) = 0x4b;
        *(undefined4 *)((int)pvVar23 + 0x6c) = 0;
        fVar28 = fStack_218;
        fVar29 = fStack_21c;
      }
    }
    goto LAB_00404f21;
  }
  if (3600.0 <= (float)world_p) goto LAB_00404f21;
  action_type = *(char *)((int)pvVar23 + 0x68);
  if ((((action_type == '\x18') || (action_type == '\x19')) || (action_type == '\x1b')) ||
     (*(int *)((int)pvVar23 + 0x128) != 0)) {
LAB_00404cdf:
    if ((((*(float *)((int)pvVar23 + 0x170) < 0.8) &&
         (action_type = *(char *)((int)pvVar23 + 0x68), action_type != '\x18')) && (action_type != '\x19')) &&
       (action_type != '\x1b')) goto LAB_004046f3;
    fVar28 = fStack_218;
    fVar29 = fStack_21c;
    if (*(int *)((int)pvVar23 + 0x128) == 0) {
      iVar11 = Combat_getWindupAndRecovery((int)pvVar23);
      fVar28 = fStack_218;
      fVar29 = fStack_21c;
      if (iVar11 < *(int *)((int)pvVar23 + 0x6c)) {
        action_type = *(char *)((int)pvVar23 + 0xaa8);
        if (action_type == '\0') {
LAB_00404dd1:
          if (*(int *)((int)pvVar23 + 100) == 0x68) {
LAB_00404ddb:
            if (*(char *)((int)pvVar23 + 0x68) == '\x19') {
              if (*(float *)((int)pvVar23 + 0x170) <= *(float *)((int)pvVar23 + 0x144)) {
                *(undefined1 *)((int)pvVar23 + 0x68) = 0x37;
                *(undefined4 *)((int)pvVar23 + 0x6c) = 0;
                goto LAB_00404f21;
              }
            }
            else {
              *(undefined4 *)((int)pvVar23 + 0x6c) = 0;
            }
            *(undefined1 *)((int)pvVar23 + 0x68) = 0x19;
          }
        }
        else {
          if (*(char *)((int)pvVar23 + 0xaa9) != '\a') {
            if (action_type == '\0') goto LAB_00404dd1;
            if (*(char *)((int)pvVar23 + 0xaa9) == '\b') {
              if (*(char *)((int)pvVar23 + 0x68) == '\x1b') {
                if (*(float *)((int)pvVar23 + 0x170) <= *(float *)((int)pvVar23 + 0x144)) {
                  *(undefined1 *)((int)pvVar23 + 0x68) = 0x1a;
                  *(undefined4 *)((int)pvVar23 + 0x6c) = 0;
                  goto LAB_00404f21;
                }
              }
              else {
                *(undefined4 *)((int)pvVar23 + 0x6c) = 0;
              }
              *(undefined1 *)((int)pvVar23 + 0x68) = 0x1b;
              goto LAB_00404f21;
            }
            if ((action_type == '\0') || (*(char *)((int)pvVar23 + 0xaa9) != '\x06')) goto LAB_00404dd1;
            goto LAB_00404ddb;
          }
          if (*(char *)((int)pvVar23 + 0x68) == '\x18') {
            if (*(float *)((int)pvVar23 + 0x170) <= *(float *)((int)pvVar23 + 0x144)) {
              *(undefined1 *)((int)pvVar23 + 0x68) = 0x16;
              *(undefined4 *)((int)pvVar23 + 0x6c) = 0;
              goto LAB_00404f21;
            }
          }
          else {
            *(undefined4 *)((int)pvVar23 + 0x6c) = 0;
          }
          *(undefined1 *)((int)pvVar23 + 0x68) = 0x18;
        }
      }
    }
    goto LAB_00404f21;
  }
  iVar11 = rand();
  if (iVar11 % 10 != 0) goto LAB_00404cdf;
  iVar11 = Combat_isRangedOrSpecialOpcode((int)pvVar23);
  if (((char)iVar11 != '\0') ||
     (2.0 < *(float *)((int)pvVar23 + 0x80) || *(float *)((int)pvVar23 + 0x80) == 2.0))
  goto LAB_00404cdf;
  iVar11 = Combat_getWindupAndRecovery((int)pvVar23);
  if ((*(int *)((int)pvVar23 + 0x6c) < iVar11) || ((*(byte *)((int)pvVar23 + 0x5c) & 3) == 0))
  goto LAB_00404cdf;
  puVar14 = Vec3i64_subtract(local_300,auStack_98,puVar14);
  Vec3i64_toFloatScaled(&fStack_204,(longlong *)puVar14);
  fVar26 = fStack_200 * fStack_200 + fStack_204 * fStack_204 + 0.0;
  fVar28 = fStack_218;
  fVar29 = fStack_21c;
  if (fVar26 <= 0.0) goto LAB_00404f21;
  dVar27 = (double)fVar26;
  libm_sse2_sqrt_precise();
  fVar28 = 1.0 / (float)dVar27;
  local_2fc = (CombatBehavior *)(fStack_204 * fVar28);
  local_2f4 = (uint *)(fStack_200 * fVar28);
  world_p = (void *)(fVar28 * 0.0);
  uVar13 = rand();
  uVar13 = uVar13 & 0x80000003;
  if ((int)uVar13 < 0) {
    uVar13 = (uVar13 - 1 | 0xfffffffc) + 1;
  }
  switch(uVar13) {
  case 0:
switchD_00404866_caseD_0:
    fVar28 = (float)local_2fc * 20.0;
    fVar29 = (float)local_2f4 * 20.0;
    *(float *)((int)pvVar23 + 0x3c) = (float)world_p * 20.0;
    goto LAB_0040493b;
  case 1:
switchD_00404866_caseD_1:
    *(float *)((int)pvVar23 + 0x34) = (float)local_2fc * -20.0;
    *(float *)((int)pvVar23 + 0x38) = (float)local_2f4 * -20.0;
    *(float *)((int)pvVar23 + 0x3c) = (float)world_p * -20.0;
    break;
  case 2:
switchD_00404866_caseD_2:
    *(float *)((int)pvVar23 + 0x34) = ((float)local_2f4 - (float)world_p * 0.0) * 20.0;
    *(float *)((int)pvVar23 + 0x38) = ((float)world_p * 0.0 - (float)local_2fc) * 20.0;
    *(float *)((int)pvVar23 + 0x3c) = ((float)local_2fc * 0.0 - (float)local_2f4 * 0.0) * 20.0;
    break;
  case 3:
switchD_00404866_caseD_3:
    fVar28 = ((float)local_2f4 - (float)world_p * 0.0) * -20.0;
    fVar29 = ((float)world_p * 0.0 - (float)local_2fc) * -20.0;
    *(float *)((int)pvVar23 + 0x3c) = ((float)local_2fc * 0.0 - (float)local_2f4 * 0.0) * -20.0;
LAB_0040493b:
    *(float *)((int)pvVar23 + 0x38) = fVar29;
    *(float *)((int)pvVar23 + 0x34) = fVar28;
  }
switchD_00404866_default:
  *(float *)((int)pvVar23 + 0x3c) = *(float *)((int)pvVar23 + 0x3c) + 5.0;
  *(undefined4 *)((int)pvVar23 + 0x128) = 600;
  fVar28 = fStack_218;
  fVar29 = fStack_21c;
LAB_00404f21:
  *(float *)((int)pvVar23 + 0x160) = fVar29;
  *(float *)((int)pvVar23 + 0x164) = fVar28;
  *(int **)((int)pvVar23 + 0x168) = local_318;
LAB_004052e0:
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_31c);
  return;
  while( true ) {
    if (*(int *)((int)pvVar5 + 0x1464) != 0) {
      iVar22 = *(int *)(*(int *)((int)pvVar5 + 0x1460) + 4);
      piVar21 = (int *)Vec3i64_toBlockCoords(local_17c,(uint *)((int)pvVar5 + 0x1440));
      uVar2 = *(undefined8 *)(iVar22 + 8);
      iVar16 = *(int *)(iVar22 + 0x10) - piVar21[2];
      local_188._4_4_ = (int)((ulonglong)uVar2 >> 0x20);
      iVar22 = local_188._4_4_ - piVar21[1];
      local_188._0_4_ = (int)uVar2;
      iVar15 = (int)local_188 - *piVar21;
      pvVar23 = world_p;
      local_188 = uVar2;
      if ((float)(iVar16 * iVar16 + iVar22 * iVar22 + iVar15 * iVar15) <=
          *(float *)((int)pvVar5 + 0x80) * *(float *)((int)pvVar5 + 0x80)) break;
    }
    NavGraph_findPath(pvVar23,pvVar5);
    NavGraph_reconstructPath(pvVar5);
    iVar11 = iVar11 + 1;
    if (9 < iVar11) break;
LAB_00405241:
    if (0x32 < *(int *)((int)pvVar5 + 0x1464)) break;
  }
  goto LAB_004052e0;
}




/* cube::CombatBehavior::vfunc_1 @ 004053e0 */

undefined4 * __fastcall cube::CombatBehavior::vfunc_1(int src)

{
  undefined4 *new_obj;
  
  new_obj = operator_new(0x14);
  if (new_obj != (undefined4 *)0x0) {
    *new_obj = vftable;
    new_obj[1] = *(undefined4 *)(src + 4);
    new_obj[2] = *(undefined4 *)(src + 8);
    new_obj[3] = 0;
    new_obj[4] = 0;
    return new_obj;
  }
  return (undefined4 *)0x0;
}




/* [AUDIT] proposed: Combat_getAbilityCooldown  (confidence: high)
 * purpose: Returns cooldown/duration ticks for an ability id: constant/(attackSpeed * this+0x17c); many per-ability constants
 * vars: this+0x68=current ability; this+0x17c=speed scale; this+0xaa9=spirit state
 */
/* Global::Combat_getAbilityCooldown @ 00407db0 */

int __thiscall Combat_getAbilityCooldown(void *this,uint ability)

{
  float10 fVar1;
  float base_ms;
  float speed;
  
  if ((int)ability < 0) {
    ability = (uint)*(byte *)((int)this + 0x68);
  }
  switch(ability) {
  case 0:
  case 8:
  case 0xb:
  case 0x1c:
  case 0x32:
  case 0x37:
  case 0x3c:
  case 0x3d:
  case 0x3e:
  case 0x60:
  case 0x62:
  case 0x68:
    return 0;
  case 1:
  case 9:
    fVar1 = Combat_computeAttackSpeed((int)this);
    speed = (float)fVar1;
    base_ms = 300.0;
    break;
  case 2:
  case 3:
  case 4:
    fVar1 = Combat_computeAttackSpeed((int)this);
    speed = (float)fVar1;
    base_ms = 100.0;
    break;
  case 5:
    fVar1 = Combat_computeAttackSpeed((int)this);
    speed = (float)fVar1;
    base_ms = 100.0;
    break;
  case 6:
  case 7:
    fVar1 = Combat_computeAttackSpeed((int)this);
    speed = (float)fVar1;
    base_ms = 50.0;
    break;
  case 10:
    fVar1 = Combat_computeAttackSpeed((int)this);
    speed = (float)fVar1;
    base_ms = 100.0;
    break;
  case 0xc:
  case 0x10:
  case 0x43:
    fVar1 = Combat_computeAttackSpeed((int)this);
    speed = (float)fVar1;
    base_ms = 200.0;
    break;
  case 0xd:
    fVar1 = Combat_computeAttackSpeed((int)this);
    speed = (float)fVar1;
    base_ms = 200.0;
    break;
  case 0xe:
    fVar1 = Combat_computeAttackSpeed((int)this);
    speed = (float)fVar1;
    base_ms = 100.0;
    break;
  case 0xf:
    fVar1 = Combat_computeAttackSpeed((int)this);
    speed = (float)fVar1;
    base_ms = 200.0;
    break;
  case 0x11:
  case 0x12:
  case 0x13:
  case 0x14:
  case 0x15:
    fVar1 = Combat_computeAttackSpeed((int)this);
    speed = (float)fVar1;
    base_ms = 100.0;
    break;
  case 0x16:
    fVar1 = Combat_computeAttackSpeed((int)this);
    goto LAB_00408115;
  case 0x17:
    fVar1 = Combat_computeAttackSpeed((int)this);
    speed = (float)fVar1;
    base_ms = 50.0;
    break;
  case 0x18:
  case 0x19:
  case 0x1b:
  case 0x24:
  case 0x3b:
  case 0x3f:
  case 0x40:
    fVar1 = Combat_computeAttackSpeed((int)this);
    speed = (float)fVar1;
    base_ms = 50.0;
    break;
  case 0x1a:
    fVar1 = Combat_computeAttackSpeed((int)this);
    speed = (float)fVar1;
    base_ms = 300.0;
    break;
  default:
    fVar1 = Combat_computeAttackSpeed((int)this);
LAB_00408115:
    speed = (float)fVar1;
    base_ms = 400.0;
    break;
  case 0x1e:
  case 0x20:
    fVar1 = Combat_computeAttackSpeed((int)this);
    speed = (float)fVar1;
    base_ms = 800.0;
    break;
  case 0x1f:
  case 0x21:
    fVar1 = Combat_computeAttackSpeed((int)this);
    speed = (float)fVar1;
    base_ms = 1600.0;
    break;
  case 0x22:
    fVar1 = Combat_computeAttackSpeed((int)this);
    speed = (float)fVar1;
    base_ms = 1600.0;
    break;
  case 0x25:
  case 0x2b:
  case 0x59:
    if (*(char *)((int)this + 0xaa9) == '\f') {
      fVar1 = Combat_computeAttackSpeed((int)this);
      speed = (float)fVar1;
      base_ms = 600.0;
    }
    else {
      fVar1 = Combat_computeAttackSpeed((int)this);
      speed = (float)fVar1;
      base_ms = 1200.0;
    }
    break;
  case 0x26:
  case 0x2c:
    fVar1 = Combat_computeAttackSpeed((int)this);
    speed = (float)fVar1;
    base_ms = 500.0;
    break;
  case 0x27:
  case 0x28:
  case 0x29:
  case 0x2a:
    fVar1 = Combat_computeAttackSpeed((int)this);
    speed = (float)fVar1;
    base_ms = 200.0;
    break;
  case 0x2d:
  case 0x2e:
    fVar1 = Combat_computeAttackSpeed((int)this);
    speed = (float)fVar1;
    base_ms = 1200.0;
    break;
  case 0x30:
  case 0x65:
    return 100;
  case 0x36:
    return 400;
  case 0x39:
  case 0x3a:
    fVar1 = Combat_computeAttackSpeed((int)this);
    speed = (float)fVar1;
    base_ms = 800.0;
    break;
  case 0x41:
  case 0x42:
    fVar1 = Combat_computeAttackSpeed((int)this);
    speed = (float)fVar1;
    base_ms = 300.0;
    break;
  case 0x44:
  case 0x45:
  case 0x46:
  case 0x49:
  case 0x4a:
  case 0x4b:
  case 0x4c:
  case 0x4d:
  case 0x4e:
    fVar1 = Combat_computeAttackSpeed((int)this);
    speed = (float)fVar1;
    base_ms = 300.0;
    break;
  case 0x47:
  case 0x48:
    return 200;
  case 0x57:
    fVar1 = Combat_computeAttackSpeed((int)this);
    speed = (float)fVar1;
    base_ms = 5000.0;
    break;
  case 0x5b:
    fVar1 = Combat_computeAttackSpeed((int)this);
    speed = (float)fVar1;
    base_ms = 1000.0;
    break;
  case 0x5d:
    fVar1 = Combat_computeAttackSpeed((int)this);
    speed = (float)fVar1;
    base_ms = 800.0;
    break;
  case 0x5e:
    fVar1 = Combat_computeAttackSpeed((int)this);
    speed = (float)fVar1;
    base_ms = 500.0;
    break;
  case 0x5f:
    fVar1 = Combat_computeAttackSpeed((int)this);
    speed = (float)fVar1;
    base_ms = 1000.0;
    break;
  case 0x69:
    return 5000;
  }
  return (int)(base_ms / (speed * *(float *)((int)this + 0x17c)));
}




/* [AUDIT] proposed: Combat_getWindupAndRecovery  (confidence: med)
 * purpose: Two-stage per-ability timing: computes windup then recovery ticks via constant/(speed*this+0x17c) (body truncated)
 * vars: ability+0x68=ability id; +0x17c=speed; +0xaa9=state; +0x6c=current timer
 */
/* Global::Combat_getWindupAndRecovery @ 004084b0 */

int __fastcall Combat_getWindupAndRecovery(int creature)

{
  int cast_ms;
  int recover_ms;
  float10 fVar3;
  float base_ms;
  float speed;
  
  switch(*(undefined1 *)(creature + 0x68)) {
  case 0:
  case 8:
  case 0xb:
  case 0x1c:
  case 0x32:
  case 0x37:
  case 0x3c:
  case 0x3d:
  case 0x3e:
  case 0x60:
  case 0x62:
  case 0x68:
    cast_ms = 0;
    goto LAB_00408820;
  case 1:
  case 9:
    fVar3 = Combat_computeAttackSpeed(creature);
    speed = (float)fVar3;
    base_ms = 300.0;
    break;
  case 2:
  case 3:
  case 4:
    fVar3 = Combat_computeAttackSpeed(creature);
    speed = (float)fVar3;
    base_ms = 100.0;
    break;
  case 5:
    fVar3 = Combat_computeAttackSpeed(creature);
    speed = (float)fVar3;
    base_ms = 100.0;
    break;
  case 6:
  case 7:
    fVar3 = Combat_computeAttackSpeed(creature);
    speed = (float)fVar3;
    base_ms = 50.0;
    break;
  case 10:
    fVar3 = Combat_computeAttackSpeed(creature);
    speed = (float)fVar3;
    base_ms = 100.0;
    break;
  case 0xc:
  case 0x10:
  case 0x43:
    fVar3 = Combat_computeAttackSpeed(creature);
    speed = (float)fVar3;
    base_ms = 200.0;
    break;
  case 0xd:
    fVar3 = Combat_computeAttackSpeed(creature);
    speed = (float)fVar3;
    base_ms = 200.0;
    break;
  case 0xe:
    fVar3 = Combat_computeAttackSpeed(creature);
    speed = (float)fVar3;
    base_ms = 100.0;
    break;
  case 0xf:
    fVar3 = Combat_computeAttackSpeed(creature);
    speed = (float)fVar3;
    base_ms = 200.0;
    break;
  case 0x11:
  case 0x12:
  case 0x13:
  case 0x14:
  case 0x15:
    fVar3 = Combat_computeAttackSpeed(creature);
    speed = (float)fVar3;
    base_ms = 100.0;
    break;
  case 0x16:
    fVar3 = Combat_computeAttackSpeed(creature);
    goto LAB_00408808;
  case 0x17:
    fVar3 = Combat_computeAttackSpeed(creature);
    speed = (float)fVar3;
    base_ms = 50.0;
    break;
  case 0x18:
  case 0x19:
  case 0x1b:
  case 0x24:
  case 0x3b:
  case 0x3f:
  case 0x40:
    fVar3 = Combat_computeAttackSpeed(creature);
    speed = (float)fVar3;
    base_ms = 50.0;
    break;
  case 0x1a:
    fVar3 = Combat_computeAttackSpeed(creature);
    speed = (float)fVar3;
    base_ms = 300.0;
    break;
  default:
    fVar3 = Combat_computeAttackSpeed(creature);
LAB_00408808:
    speed = (float)fVar3;
    base_ms = 400.0;
    break;
  case 0x1e:
  case 0x20:
    fVar3 = Combat_computeAttackSpeed(creature);
    speed = (float)fVar3;
    base_ms = 800.0;
    break;
  case 0x1f:
  case 0x21:
    fVar3 = Combat_computeAttackSpeed(creature);
    speed = (float)fVar3;
    base_ms = 1600.0;
    break;
  case 0x22:
    fVar3 = Combat_computeAttackSpeed(creature);
    speed = (float)fVar3;
    base_ms = 1600.0;
    break;
  case 0x25:
  case 0x2b:
  case 0x59:
    if (*(char *)(creature + 0xaa9) == '\f') {
      fVar3 = Combat_computeAttackSpeed(creature);
      speed = (float)fVar3;
      base_ms = 600.0;
    }
    else {
      fVar3 = Combat_computeAttackSpeed(creature);
      speed = (float)fVar3;
      base_ms = 1200.0;
    }
    break;
  case 0x26:
  case 0x2c:
    fVar3 = Combat_computeAttackSpeed(creature);
    speed = (float)fVar3;
    base_ms = 500.0;
    break;
  case 0x27:
  case 0x28:
  case 0x29:
  case 0x2a:
    fVar3 = Combat_computeAttackSpeed(creature);
    speed = (float)fVar3;
    base_ms = 200.0;
    break;
  case 0x2d:
  case 0x2e:
    fVar3 = Combat_computeAttackSpeed(creature);
    speed = (float)fVar3;
    base_ms = 1200.0;
    break;
  case 0x30:
  case 0x65:
    cast_ms = 100;
    goto LAB_00408820;
  case 0x36:
    cast_ms = 400;
    goto LAB_00408820;
  case 0x39:
  case 0x3a:
    fVar3 = Combat_computeAttackSpeed(creature);
    speed = (float)fVar3;
    base_ms = 800.0;
    break;
  case 0x41:
  case 0x42:
    fVar3 = Combat_computeAttackSpeed(creature);
    speed = (float)fVar3;
    base_ms = 300.0;
    break;
  case 0x44:
  case 0x45:
  case 0x46:
  case 0x49:
  case 0x4a:
  case 0x4b:
  case 0x4c:
  case 0x4d:
  case 0x4e:
    fVar3 = Combat_computeAttackSpeed(creature);
    speed = (float)fVar3;
    base_ms = 300.0;
    break;
  case 0x47:
  case 0x48:
    cast_ms = 200;
    goto LAB_00408820;
  case 0x57:
    fVar3 = Combat_computeAttackSpeed(creature);
    speed = (float)fVar3;
    base_ms = 5000.0;
    break;
  case 0x5b:
    fVar3 = Combat_computeAttackSpeed(creature);
    speed = (float)fVar3;
    base_ms = 1000.0;
    break;
  case 0x5d:
    fVar3 = Combat_computeAttackSpeed(creature);
    speed = (float)fVar3;
    base_ms = 800.0;
    break;
  case 0x5e:
    fVar3 = Combat_computeAttackSpeed(creature);
    speed = (float)fVar3;
    base_ms = 500.0;
    break;
  case 0x5f:
    fVar3 = Combat_computeAttackSpeed(creature);
    speed = (float)fVar3;
    base_ms = 1000.0;
    break;
  case 0x69:
    cast_ms = 5000;
    goto LAB_00408820;
  }
  cast_ms = (int)(base_ms / (speed * *(float *)(creature + 0x17c)));
LAB_00408820:
  switch(*(undefined1 *)(creature + 0x68)) {
  case 0:
  case 0x31:
    recover_ms = 0;
    break;
  case 1:
  case 2:
  case 9:
    fVar3 = Combat_computeAttackSpeed(creature);
    speed = (float)fVar3;
    base_ms = 200.0;
    goto LAB_00408b04;
  case 3:
  case 4:
  case 0x3e:
    fVar3 = Combat_computeAttackSpeed(creature);
    speed = (float)fVar3;
    base_ms = 100.0;
    goto LAB_00408b04;
  case 5:
  case 0xc:
  case 0x10:
  case 0x11:
  case 0x41:
  case 0x42:
    fVar3 = Combat_computeAttackSpeed(creature);
    speed = (float)fVar3;
    base_ms = 400.0;
    goto LAB_00408b04;
  case 6:
  case 7:
    fVar3 = Combat_computeAttackSpeed(creature);
    speed = (float)fVar3;
    base_ms = 150.0;
    goto LAB_00408b04;
  default:
    fVar3 = Combat_computeAttackSpeed(creature);
    speed = (float)fVar3;
    goto LAB_00408afc;
  case 10:
    recover_ms = 200;
    break;
  case 0xb:
    fVar3 = Combat_computeAttackSpeed(creature);
    speed = (float)fVar3;
    goto LAB_00408afc;
  case 0xd:
  case 0xe:
  case 0xf:
    fVar3 = Combat_computeAttackSpeed(creature);
    speed = (float)fVar3;
    base_ms = 200.0;
    goto LAB_00408b04;
  case 0x12:
  case 0x13:
    fVar3 = Combat_computeAttackSpeed(creature);
    speed = (float)fVar3;
    base_ms = 150.0;
    goto LAB_00408b04;
  case 0x14:
  case 0x15:
    fVar3 = Combat_computeAttackSpeed(creature);
    speed = (float)fVar3;
    base_ms = 400.0;
    goto LAB_00408b04;
  case 0x16:
    fVar3 = Combat_computeAttackSpeed(creature);
    recover_ms = (int)(50.0 / ((float)fVar3 * *(float *)(creature + 0x17c)));
    break;
  case 0x17:
    fVar3 = Combat_computeAttackSpeed(creature);
    recover_ms = (int)(50.0 / ((float)fVar3 * *(float *)(creature + 0x17c)));
    break;
  case 0x1a:
    fVar3 = Combat_computeAttackSpeed(creature);
    recover_ms = (int)(1200.0 / ((float)fVar3 * *(float *)(creature + 0x17c)));
    break;
  case 0x1e:
  case 0x20:
  case 0x49:
  case 0x5d:
    recover_ms = 600;
    break;
  case 0x1f:
  case 0x21:
    recover_ms = 0x4b0;
    break;
  case 0x22:
    fVar3 = Combat_computeAttackSpeed(creature);
    recover_ms = (int)(1200.0 / ((float)fVar3 * *(float *)(creature + 0x17c)));
    break;
  case 0x25:
  case 0x2b:
    fVar3 = Combat_computeAttackSpeed(creature);
    speed = (float)fVar3;
    base_ms = 100.0;
    goto LAB_00408b04;
  case 0x26:
  case 0x27:
  case 0x28:
  case 0x29:
  case 0x2a:
  case 0x2c:
    fVar3 = Combat_computeAttackSpeed(creature);
    speed = (float)fVar3;
    goto LAB_00408afc;
  case 0x2d:
  case 0x2e:
    fVar3 = Combat_computeAttackSpeed(creature);
    speed = (float)fVar3;
    base_ms = 500.0;
    goto LAB_00408b04;
  case 0x32:
  case 0x4c:
  case 0x4d:
  case 0x4e:
  case 0x60:
    recover_ms = 500;
    break;
  case 0x36:
    recover_ms = 100;
    break;
  case 0x37:
    fVar3 = Combat_computeAttackSpeed(creature);
    speed = (float)fVar3;
    base_ms = 500.0;
    goto LAB_00408b04;
  case 0x43:
    fVar3 = Combat_computeAttackSpeed(creature);
    speed = (float)fVar3;
    base_ms = 200.0;
    goto LAB_00408b04;
  case 0x44:
  case 0x45:
    recover_ms = 1000;
    break;
  case 0x47:
    recover_ms = 3000;
    break;
  case 0x48:
  case 0x56:
    recover_ms = 5000;
    break;
  case 0x4b:
    fVar3 = Combat_computeAttackSpeed(creature);
    speed = (float)fVar3;
    goto LAB_00408afc;
  case 0x5b:
    recover_ms = 6000;
    break;
  case 0x5e:
    fVar3 = Combat_computeAttackSpeed(creature);
    speed = (float)fVar3;
    base_ms = 500.0;
    goto LAB_00408b04;
  case 0x5f:
    recover_ms = 2000;
    break;
  case 0x68:
    fVar3 = Combat_computeAttackSpeed(creature);
    speed = (float)fVar3;
LAB_00408afc:
    base_ms = 300.0;
LAB_00408b04:
    recover_ms = (int)(base_ms / (speed * *(float *)(creature + 0x17c)));
  }
  switch(*(undefined1 *)(creature + 0x68)) {
  case 0:
  case 0x32:
  case 0x60:
    return recover_ms + 100 + cast_ms;
  default:
    fVar3 = Combat_computeAttackSpeed(creature);
    speed = (float)fVar3;
    base_ms = 500.0;
    break;
  case 3:
  case 4:
  case 5:
  case 0x3e:
    fVar3 = Combat_computeAttackSpeed(creature);
    speed = (float)fVar3;
    base_ms = 300.0;
    break;
  case 7:
  case 0xe:
  case 0x12:
    fVar3 = Combat_computeAttackSpeed(creature);
    speed = (float)fVar3;
    base_ms = 200.0;
    break;
  case 10:
    return recover_ms + 600 + cast_ms;
  case 0xb:
  case 0x3c:
  case 0x3d:
  case 0x68:
    fVar3 = Combat_computeAttackSpeed(creature);
    speed = (float)fVar3;
    base_ms = 100.0;
    break;
  case 0xf:
    fVar3 = Combat_computeAttackSpeed(creature);
    speed = (float)fVar3;
    base_ms = 400.0;
    break;
  case 0x16:
  case 0x1a:
  case 0x1e:
  case 0x1f:
  case 0x20:
  case 0x21:
  case 0x22:
  case 0x25:
  case 0x26:
  case 0x27:
  case 0x28:
  case 0x29:
  case 0x2a:
  case 0x2b:
  case 0x2c:
  case 0x2d:
  case 0x2e:
  case 0x5e:
  case 0x5f:
    fVar3 = Combat_computeAttackSpeed(creature);
    speed = (float)fVar3;
    base_ms = 100.0;
    break;
  case 0x17:
    fVar3 = Combat_computeAttackSpeed(creature);
    return (int)(10.0 / ((float)fVar3 * *(float *)(creature + 0x17c))) + recover_ms + cast_ms;
  case 0x30:
    return recover_ms + cast_ms;
  case 0x36:
    return recover_ms + 400 + cast_ms;
  case 0x39:
  case 0x3a:
    fVar3 = Combat_computeAttackSpeed(creature);
    speed = (float)fVar3;
    base_ms = 300.0;
    break;
  case 0x41:
  case 0x42:
    fVar3 = Combat_computeAttackSpeed(creature);
    speed = (float)fVar3;
    base_ms = 200.0;
    break;
  case 0x43:
    fVar3 = Combat_computeAttackSpeed(creature);
    speed = (float)fVar3;
    base_ms = 100.0;
    break;
  case 0x44:
  case 0x45:
  case 0x5d:
    fVar3 = Combat_computeAttackSpeed(creature);
    speed = (float)fVar3;
    base_ms = 800.0;
    break;
  case 0x47:
  case 0x48:
    return recover_ms + 200 + cast_ms;
  }
  return (int)(base_ms / (speed * *(float *)(creature + 0x17c))) + recover_ms + cast_ms;
}




/* [AUDIT] proposed: Combat_canCastAbility  (confidence: high)
 * purpose: Tests if an ability may be used: mana/cost (0040fb20) <= pool this+0x170 and cooldown map slot free; returns bool
 * vars: this+0x12c=count guard; +0x170=resource pool; +0x139c=cooldown map; creature=ability id
 */
/* Global::Combat_canCastAbility @ 004096b0 */

bool __thiscall Combat_canCastAbility(void *this,int ability)

{
  int ability_save;
  float10 fVar2;
  void *range;
  
  ability_save = ability;
  if ((*(int *)((int)this + 300) < 1) || (ability == 0x65)) {
    range = this;
    fVar2 = Combat_getAbilityResourceCost((int)this,ability,-1);
    range = (void *)(float)fVar2;
    if ((float)range < *(float *)((int)this + 0x170) ||
        (float)range == *(float *)((int)this + 0x170)) {
      Combat_mapLowerBound((void *)((int)this + 0x139c),(int *)&range,&ability);
      if ((range == *(void **)((int)this + 0x139c)) || (*(int *)((int)range + 0x14) == 0)) {
        if (ability_save != 0x1c) {
          return true;
        }
        return 0.0 < *(float *)((int)this + 0x170);
      }
    }
  }
  return false;
}




/* [AUDIT] proposed: Combat_mapLowerBound  (confidence: high)
 * purpose: std::map lower_bound: walks tree comparing key at node+0x10 to *param_2, returns bounding node
 * vars: this=map; ability=out node; param_2=key ptr; node[4]=key
 */
/* Global::Combat_mapLowerBound @ 0040a7a0 */

void __thiscall Combat_mapLowerBound(void *this,int *out,int *key)

{
  int *head;
  int iVar2;
  int *cur;
  int *next;
  int *bound;
  
  head = *(int **)this;
  bound = head;
  if (*(char *)(head[1] + 0xd) == '\0') {
    cur = (int *)head[1];
    do {
      if (cur[4] < *key) {
        next = (int *)cur[2];
      }
      else {
        next = (int *)*cur;
        bound = cur;
      }
      cur = next;
    } while (*(char *)((int)next + 0xd) == '\0');
  }
  if ((bound == head) || (iVar2 = *key, key = bound, iVar2 < bound[4])) {
    key = head;
  }
  *out = (int)key;
  return;
}




/* [AUDIT] proposed: Combat_getAbilityCastTime  (confidence: high)
 * purpose: Per-ability cast-time table: constant/(attackSpeed*this+0x17c) with defaults 500/etc
 * vars: this+0x68=ability id; +0x17c=speed scale
 */
/* Global::Combat_getAbilityCastTime @ 0040f2f0 */

int __thiscall Combat_getAbilityCastTime(void *this,uint ability)

{
  float10 fVar1;
  float base_ms;
  float speed;
  
  if ((int)ability < 0) {
    ability = (uint)*(byte *)((int)this + 0x68);
  }
  switch(ability) {
  case 0:
  case 0x32:
  case 0x60:
    return 100;
  default:
    fVar1 = Combat_computeAttackSpeed((int)this);
    speed = (float)fVar1;
    base_ms = 500.0;
    break;
  case 3:
  case 4:
  case 5:
  case 0x3e:
    fVar1 = Combat_computeAttackSpeed((int)this);
    speed = (float)fVar1;
    base_ms = 300.0;
    break;
  case 7:
  case 0xe:
  case 0x12:
    fVar1 = Combat_computeAttackSpeed((int)this);
    speed = (float)fVar1;
    base_ms = 200.0;
    break;
  case 10:
    return 600;
  case 0xb:
  case 0x3c:
  case 0x3d:
  case 0x68:
    fVar1 = Combat_computeAttackSpeed((int)this);
    speed = (float)fVar1;
    base_ms = 100.0;
    break;
  case 0xf:
    fVar1 = Combat_computeAttackSpeed((int)this);
    speed = (float)fVar1;
    base_ms = 400.0;
    break;
  case 0x16:
  case 0x1a:
  case 0x1e:
  case 0x1f:
  case 0x20:
  case 0x21:
  case 0x22:
  case 0x25:
  case 0x26:
  case 0x27:
  case 0x28:
  case 0x29:
  case 0x2a:
  case 0x2b:
  case 0x2c:
  case 0x2d:
  case 0x2e:
  case 0x5e:
  case 0x5f:
    fVar1 = Combat_computeAttackSpeed((int)this);
    speed = (float)fVar1;
    base_ms = 100.0;
    break;
  case 0x17:
    fVar1 = Combat_computeAttackSpeed((int)this);
    speed = (float)fVar1;
    base_ms = 10.0;
    break;
  case 0x30:
    return 0;
  case 0x36:
    return 400;
  case 0x39:
  case 0x3a:
    fVar1 = Combat_computeAttackSpeed((int)this);
    speed = (float)fVar1;
    base_ms = 300.0;
    break;
  case 0x41:
  case 0x42:
    fVar1 = Combat_computeAttackSpeed((int)this);
    speed = (float)fVar1;
    base_ms = 200.0;
    break;
  case 0x43:
    fVar1 = Combat_computeAttackSpeed((int)this);
    speed = (float)fVar1;
    base_ms = 100.0;
    break;
  case 0x44:
  case 0x45:
  case 0x5d:
    fVar1 = Combat_computeAttackSpeed((int)this);
    speed = (float)fVar1;
    base_ms = 800.0;
    break;
  case 0x47:
  case 0x48:
    return 200;
  }
  return (int)(base_ms / (speed * *(float *)((int)this + 0x17c)));
}




/* [AUDIT] proposed: Combat_isBlockingState  (confidence: med)
 * purpose: Predicate over creature action/state fields returning bool in AL (blocking/channel gate)
 * vars: ability+0x140=action; +100=opcode; +0xaa8/0xaa9=spirit state
 */
/* Global::Combat_isBlockingState @ 0040f5a0 */

uint __fastcall Combat_isBlockingState(int creature)

{
  char cVar1;
  uint in_EAX;
  
  if ((((*(char *)(creature + 0x140) != '\x03') &&
       (in_EAX = *(uint *)(creature + 100), in_EAX != 0x75)) && (in_EAX != 0x56)) &&
     (((*(char *)(creature + 0xaa8) != '\x03' ||
       (((cVar1 = *(char *)(creature + 0xaa9), cVar1 != '\n' && (cVar1 != '\v')) && (cVar1 != '\f')))
       ) && (in_EAX != 0x68)))) {
    if (*(char *)(creature + 0xaa8) == '\x03') {
      cVar1 = *(char *)(creature + 0xaa9);
      in_EAX = CONCAT31((int3)(in_EAX >> 8),cVar1);
      if (((cVar1 == '\x06') || (cVar1 == '\a')) ||
         ((cVar1 == '\b' || ((cVar1 == '\n' || (cVar1 == '\v')))))) goto LAB_0040f5ff;
    }
    return in_EAX & 0xffffff00;
  }
LAB_0040f5ff:
  return CONCAT31((int3)(in_EAX >> 8),1);
}




/* [AUDIT] proposed: Combat_isRangedOrSpecialOpcode  (confidence: high)
 * purpose: Predicate: true if action opcode (creature+100) is in a whitelist of ability ids
 * vars: creature+100=current opcode
 */
/* Global::Combat_isRangedOrSpecialOpcode @ 0040f650 */

int __fastcall Combat_isRangedOrSpecialOpcode(int creature)

{
  int ability;
  uint3 uVar2;
  
  ability = *(int *)(creature + 100);
  uVar2 = (uint3)((uint)ability >> 8);
  if ((((((ability != 0x6c) && (ability != 0x6d)) && (ability != 0x72)) &&
       ((ability != 0x74 && (ability != 0x73)))) &&
      ((ability != 0x76 && ((ability != 0x6b && (ability != 0x75)))))) &&
     ((ability != 0x65 && (ability != 0x77)))) {
    return (uint)uVar2 << 8;
  }
  return CONCAT31(uVar2,1);
}




/* [AUDIT] proposed: Combat_isSpiritChanneling  (confidence: high)
 * purpose: Predicate: false for certain opcodes/spirit states, else true if spirit 0xaa9 in {0xa,0xb,0xc}
 * vars: creature+0x140=action; +100=opcode; +0xaa8/0xaa9=spirit
 */
/* Global::Combat_isSpiritChanneling @ 0040f690 */

uint __fastcall Combat_isSpiritChanneling(int creature)

{
  char cVar1;
  uint in_EAX;
  
  if (((*(char *)(creature + 0x140) != '\x03') && (in_EAX = *(uint *)(creature + 100), in_EAX != 0x75)
      ) && (in_EAX != 0x56)) {
    if (*(char *)(creature + 0xaa8) == '\x03') {
      cVar1 = *(char *)(creature + 0xaa9);
      in_EAX = CONCAT31((int3)(in_EAX >> 8),cVar1);
      if (((cVar1 == '\n') || (cVar1 == '\v')) || (cVar1 == '\f')) goto LAB_0040f6c4;
    }
    return in_EAX & 0xffffff00;
  }
LAB_0040f6c4:
  return CONCAT31((int3)(in_EAX >> 8),1);
}




/* [AUDIT] proposed: Combat_isMeleeSwingOpcode  (confidence: high)
 * purpose: Predicate: true when flags&0x1a00==0 and opcode (creature+100) is one of many melee/attack ids
 * vars: creature+0x7e=state flags; +100=opcode
 */
/* Global::Combat_isMeleeSwingOpcode @ 0040f710 */

uint __fastcall Combat_isMeleeSwingOpcode(int creature)

{
  uint ability;
  
  ability = (uint)*(ushort *)(creature + 0x7e);
  if (((*(ushort *)(creature + 0x7e) & 0x1a00) == 0) &&
     ((((((((ability = *(uint *)(creature + 100), ability == 0x5c || (ability == 0x4a)) || (ability == 0x22))
          || (((ability == 0x19 || (ability == 0x37)) ||
              ((ability == 0x35 || ((ability == 0x57 || (ability == 0x44)))))))) || (ability == 0x43)) ||
        ((((((ability == 0x5d || (ability == 0x6a)) || (ability == 0x6b)) ||
           ((ability == 0x23 || (ability == 0x3a)))) || (ability == 0x39)) ||
         (((ability == 0x93 || (ability == 0x91)) ||
          (((ability == 0x92 || (((ability == 0x16 || (ability == 0x17)) || (ability == 0x62)))) ||
           (((ability == 0x38 || (ability == 0x1e)) || (ability == 0x1f)))))))))) ||
       (((ability == 0x20 || (ability == 0x13)) ||
        ((ability == 0x1a || (((ability == 0x1b || (ability == 0x21)) || (ability == 100)))))))) ||
      ((ability == 0x14 || (ability == 0x59)))))) {
    return CONCAT31((int3)(ability >> 8),1);
  }
  return ability & 0xffffff00;
}




/* [AUDIT] proposed: Combat_getAbilityResourceCost  (confidence: high)
 * purpose: Returns resource/proc fraction for an ability id; scans buff list at 0x1178 for tag 9, defaults 0.3
 * vars: creature=creature; param_2=ability id; +0x1178=buff list
 */
/* Global::Combat_getAbilityResourceCost @ 0040fb20 */

float10 __thiscall Combat_getAbilityResourceCost(int creature,undefined4 ability,int stacks)

{
  int *buff_head;
  int *buff;
  float10 fVar3;
  
  switch(ability) {
  case 3:
  case 4:
    return (float10)0.1;
  default:
switchD_0040fb39_caseD_5:
    return (float10)0;
  case 0x1f:
  case 0x21:
  case 0x25:
  case 0x2b:
  case 0x2d:
  case 0x2e:
  case 0x5f:
    break;
  case 0x22:
    fVar3 = Combat_getResistFactor(creature,0x22,stacks);
    return (float10)((1.0 - (float)fVar3 * 0.75) * 0.125);
  }
  buff_head = *(int **)(creature + 0x1178);
  buff = (int *)*buff_head;
  if (buff != buff_head) {
    while ((char)buff[2] != '\t') {
      buff = (int *)*buff;
      if (buff == buff_head) {
        return (float10)0.3;
      }
    }
    if (buff != (int *)0xfffffff8) goto switchD_0040fb39_caseD_5;
  }
  return (float10)0.3;
}




/* [AUDIT] proposed: Combat_findTopThreatTarget  (confidence: high)
 * purpose: Walks threat map at 0x13a4, returns (id,id2) pair of entry with highest score at node+6
 * vars: creature+0x13a4=threat map; node[4]/[5]=ids; [6]=score
 */
/* Global::Combat_findTopThreatTarget @ 0040fc30 */

undefined8 __fastcall Combat_findTopThreatTarget(int creature)

{
  char cVar1;
  int *list_head;
  int *piVar3;
  int *piVar4;
  int *node;
  int res_lo;
  float max_priority;
  int res_hi;
  
  list_head = *(int **)(creature + 0x13a4);
  node = (int *)*list_head;
  max_priority = 0.0;
  if (node != list_head) {
    res_hi = 0;
    res_lo = 0;
    do {
      if ((node[4] != 0 || node[5] != 0) && (max_priority <= (float)node[6])) {
        res_lo = node[4];
        res_hi = node[5];
        max_priority = (float)node[6];
      }
      if (*(char *)((int)node + 0xd) == '\0') {
        piVar3 = (int *)node[2];
        if (*(char *)((int)piVar3 + 0xd) == '\0') {
          cVar1 = *(char *)(*piVar3 + 0xd);
          node = piVar3;
          piVar3 = (int *)*piVar3;
          while (cVar1 == '\0') {
            cVar1 = *(char *)(*piVar3 + 0xd);
            node = piVar3;
            piVar3 = (int *)*piVar3;
          }
        }
        else {
          cVar1 = *(char *)(node[1] + 0xd);
          piVar4 = (int *)node[1];
          piVar3 = node;
          while ((node = piVar4, cVar1 == '\0' && (piVar3 == (int *)node[2]))) {
            cVar1 = *(char *)(node[1] + 0xd);
            piVar4 = (int *)node[1];
            piVar3 = node;
          }
        }
      }
    } while (node != list_head);
    return CONCAT44(res_hi,res_lo);
  }
  return 0;
}




/* [AUDIT] proposed: Combat_updateAttackState  (confidence: high)
 * purpose: AI tick: computes ability timing, if timer>=windup commits next anim (0040f...) and resets timer
 * vars: creature+0x68=cur anim; +0x6c=timer; +0x70=facing; +0x128=guard
 */
/* Global::Combat_updateAttackState @ 00410400 */

undefined4 __fastcall Combat_updateAttackState(int creature)

{
  char cVar1;
  uint in_EAX;
  int cooldown;
  int cost;
  undefined3 extraout_var;
  float10 fVar4;
  float base_ms;
  float speed;
  
  if ((*(int *)(creature + 0x128) != 0) || (*(char *)(creature + 0x68) == '0')) {
    return in_EAX & 0xffffff00;
  }
  cooldown = Combat_getWindupAndRecovery(creature);
  cost = cooldown;
  if (((*(int *)(creature + 0x70) == 0) || (cVar1 = *(char *)(creature + 0x68), cVar1 == '\x1e')) ||
     (cVar1 == ' ')) goto LAB_004105ba;
  switch(cVar1) {
  case '\0':
  case '2':
  case '`':
    cost = 100;
    goto LAB_004105b8;
  default:
    fVar4 = Combat_computeAttackSpeed(creature);
    speed = (float)fVar4;
    base_ms = 500.0;
    break;
  case '\x03':
  case '\x04':
  case '\x05':
  case '>':
    fVar4 = Combat_computeAttackSpeed(creature);
    speed = (float)fVar4;
    base_ms = 300.0;
    break;
  case '\a':
  case '\x0e':
  case '\x12':
    fVar4 = Combat_computeAttackSpeed(creature);
    speed = (float)fVar4;
    base_ms = 200.0;
    break;
  case '\n':
    cost = 600;
    goto LAB_004105b8;
  case '\v':
  case '<':
  case '=':
  case 'h':
    fVar4 = Combat_computeAttackSpeed(creature);
    speed = (float)fVar4;
    base_ms = 100.0;
    break;
  case '\x0f':
    fVar4 = Combat_computeAttackSpeed(creature);
    speed = (float)fVar4;
    base_ms = 400.0;
    break;
  case '\x16':
  case '\x1a':
  case '\x1e':
  case '\x1f':
  case ' ':
  case '!':
  case '\"':
  case '%':
  case '&':
  case '\'':
  case '(':
  case ')':
  case '*':
  case '+':
  case ',':
  case '-':
  case '.':
  case '^':
  case '_':
    fVar4 = Combat_computeAttackSpeed(creature);
    speed = (float)fVar4;
    base_ms = 100.0;
    break;
  case '\x17':
    fVar4 = Combat_computeAttackSpeed(creature);
    speed = (float)fVar4;
    base_ms = 10.0;
    break;
  case '0':
    cost = 0;
    goto LAB_004105b8;
  case '6':
    cost = 400;
    goto LAB_004105b8;
  case '9':
  case ':':
    fVar4 = Combat_computeAttackSpeed(creature);
    speed = (float)fVar4;
    base_ms = 300.0;
    break;
  case 'A':
  case 'B':
    fVar4 = Combat_computeAttackSpeed(creature);
    speed = (float)fVar4;
    base_ms = 200.0;
    break;
  case 'C':
    fVar4 = Combat_computeAttackSpeed(creature);
    speed = (float)fVar4;
    base_ms = 100.0;
    break;
  case 'D':
  case 'E':
  case ']':
    fVar4 = Combat_computeAttackSpeed(creature);
    speed = (float)fVar4;
    base_ms = 800.0;
    break;
  case 'G':
  case 'H':
    cost = 200;
    goto LAB_004105b8;
  }
  cost = (int)(base_ms / (speed * *(float *)(creature + 0x17c)));
LAB_004105b8:
  cooldown = cooldown - cost;
LAB_004105ba:
  if (cooldown <= *(int *)(creature + 0x6c)) {
    cVar1 = Combat_selectNextAttackAnim(creature);
    cost = CONCAT31(extraout_var,cVar1);
    *(char *)(creature + 0x68) = cVar1;
    *(undefined4 *)(creature + 0x6c) = 0;
  }
  return CONCAT31((int3)((uint)cost >> 8),1);
}




/* [AUDIT] proposed: Combat_updateAbilityAndProc  (confidence: med)
 * purpose: AI tick variant: picks ability (0x290), checks cost/proc, applies timing and buff-list procs (truncated)
 * vars: creature+0x68=anim; +0x6c=timer; +0x170=pool; +0x1178=buff list
 */
/* Global::Combat_updateAbilityAndProc @ 00410690 */

undefined4 __fastcall Combat_updateAbilityAndProc(int creature)

{
  int *piVar1;
  bool bVar2;
  int cooldown;
  int cost;
  uint uVar5;
  uint extraout_EAX;
  int *piVar6;
  int *piVar7;
  char cVar8;
  bool bVar9;
  float10 fVar10;
  float base_ms;
  float speed;
  
  cooldown = Combat_getWindupAndRecovery(creature);
  if (*(int *)(creature + 0x70) == 0) goto LAB_00410820;
  switch(*(undefined1 *)(creature + 0x68)) {
  case 0:
  case 0x32:
  case 0x60:
    cost = 100;
    goto LAB_0041081e;
  default:
    fVar10 = Combat_computeAttackSpeed(creature);
    speed = (float)fVar10;
    base_ms = 500.0;
    break;
  case 3:
  case 4:
  case 5:
  case 0x3e:
    fVar10 = Combat_computeAttackSpeed(creature);
    speed = (float)fVar10;
    base_ms = 300.0;
    break;
  case 7:
  case 0xe:
  case 0x12:
    fVar10 = Combat_computeAttackSpeed(creature);
    speed = (float)fVar10;
    base_ms = 200.0;
    break;
  case 10:
    cost = 600;
    goto LAB_0041081e;
  case 0xb:
  case 0x3c:
  case 0x3d:
  case 0x68:
    fVar10 = Combat_computeAttackSpeed(creature);
    speed = (float)fVar10;
    base_ms = 100.0;
    break;
  case 0xf:
    fVar10 = Combat_computeAttackSpeed(creature);
    speed = (float)fVar10;
    base_ms = 400.0;
    break;
  case 0x16:
  case 0x1a:
  case 0x1e:
  case 0x1f:
  case 0x20:
  case 0x21:
  case 0x22:
  case 0x25:
  case 0x26:
  case 0x27:
  case 0x28:
  case 0x29:
  case 0x2a:
  case 0x2b:
  case 0x2c:
  case 0x2d:
  case 0x2e:
  case 0x5e:
  case 0x5f:
    fVar10 = Combat_computeAttackSpeed(creature);
    speed = (float)fVar10;
    base_ms = 100.0;
    break;
  case 0x17:
    fVar10 = Combat_computeAttackSpeed(creature);
    speed = (float)fVar10;
    base_ms = 10.0;
    break;
  case 0x30:
    cost = 0;
    goto LAB_0041081e;
  case 0x36:
    cost = 400;
    goto LAB_0041081e;
  case 0x39:
  case 0x3a:
    fVar10 = Combat_computeAttackSpeed(creature);
    speed = (float)fVar10;
    base_ms = 300.0;
    break;
  case 0x41:
  case 0x42:
    fVar10 = Combat_computeAttackSpeed(creature);
    speed = (float)fVar10;
    base_ms = 200.0;
    break;
  case 0x43:
    fVar10 = Combat_computeAttackSpeed(creature);
    speed = (float)fVar10;
    base_ms = 100.0;
    break;
  case 0x44:
  case 0x45:
  case 0x5d:
    fVar10 = Combat_computeAttackSpeed(creature);
    speed = (float)fVar10;
    base_ms = 800.0;
    break;
  case 0x47:
  case 0x48:
    cost = 200;
    goto LAB_0041081e;
  }
  cost = (int)(base_ms / (speed * *(float *)(creature + 0x17c)));
LAB_0041081e:
  cooldown = cooldown - cost;
LAB_00410820:
  uVar5 = Combat_selectSpiritAttackId(creature);
  if (((*(char *)(creature + 0x140) == '\x04') && (*(char *)(creature + 0x141) == '\x01')) &&
     ((uVar5 == 0x11 || ((uVar5 == 5 || (uVar5 == 0x14)))))) {
    bVar2 = true;
  }
  else {
    bVar2 = false;
  }
  if ((*(int *)(creature + 0x6c) < cooldown) ||
     (((*(int *)(creature + 0x128) != 0 && (!bVar2)) ||
      (fVar10 = Combat_getAbilityResourceCost(creature,uVar5,-1), uVar5 = extraout_EAX,
      *(float *)(creature + 0x170) <= (float)fVar10 && (float)fVar10 != *(float *)(creature + 0x170)))
     )) {
    return uVar5 & 0xffffff00;
  }
  piVar6 = (int *)Combat_selectSpiritAttackId(creature);
  cVar8 = (char)piVar6;
  *(char *)(creature + 0x68) = cVar8;
  *(undefined4 *)(creature + 0x6c) = 0;
  if (((cVar8 == '%') || (cVar8 == '.')) ||
     ((cVar8 == '_' || ((cVar8 == '\x1f' || (piVar7 = piVar6, cVar8 == '!')))))) {
    piVar1 = *(int **)(creature + 0x1178);
    piVar7 = (int *)*piVar1;
    if (piVar7 != piVar1) {
LAB_004108c7:
      if ((char)piVar7[2] != '\t') goto code_r0x004108cd;
      bVar9 = piVar7 != (int *)0xfffffff8;
      piVar7 = (int *)0x0;
      if (bVar9) {
        switch((uint)piVar6 & 0xff) {
        case 0:
        case 8:
        case 0xb:
        case 0x1c:
        case 0x32:
        case 0x37:
        case 0x3c:
        case 0x3d:
        case 0x3e:
        case 0x60:
        case 0x62:
        case 0x68:
          piVar7 = (int *)0x0;
          goto LAB_00410d39;
        case 1:
        case 9:
          fVar10 = Combat_computeAttackSpeed(creature);
          speed = (float)fVar10;
          base_ms = 300.0;
          break;
        case 2:
        case 3:
        case 4:
          fVar10 = Combat_computeAttackSpeed(creature);
          speed = (float)fVar10;
          base_ms = 100.0;
          break;
        case 5:
          fVar10 = Combat_computeAttackSpeed(creature);
          speed = (float)fVar10;
          base_ms = 100.0;
          break;
        case 6:
        case 7:
          fVar10 = Combat_computeAttackSpeed(creature);
          piVar7 = (int *)(int)(50.0 / ((float)fVar10 * *(float *)(creature + 0x17c)));
          goto LAB_00410d39;
        case 10:
          fVar10 = Combat_computeAttackSpeed(creature);
          speed = (float)fVar10;
          base_ms = 100.0;
          break;
        case 0xc:
        case 0x10:
        case 0x43:
          fVar10 = Combat_computeAttackSpeed(creature);
          speed = (float)fVar10;
          base_ms = 200.0;
          break;
        case 0xd:
          fVar10 = Combat_computeAttackSpeed(creature);
          speed = (float)fVar10;
          base_ms = 200.0;
          break;
        case 0xe:
          fVar10 = Combat_computeAttackSpeed(creature);
          speed = (float)fVar10;
          base_ms = 100.0;
          break;
        case 0xf:
          fVar10 = Combat_computeAttackSpeed(creature);
          speed = (float)fVar10;
          base_ms = 200.0;
          break;
        case 0x11:
        case 0x12:
        case 0x13:
        case 0x14:
        case 0x15:
          fVar10 = Combat_computeAttackSpeed(creature);
          speed = (float)fVar10;
          base_ms = 100.0;
          break;
        case 0x16:
          fVar10 = Combat_computeAttackSpeed(creature);
          goto LAB_00410d21;
        case 0x17:
          fVar10 = Combat_computeAttackSpeed(creature);
          piVar7 = (int *)(int)(50.0 / ((float)fVar10 * *(float *)(creature + 0x17c)));
          goto LAB_00410d39;
        case 0x18:
        case 0x19:
        case 0x1b:
        case 0x24:
        case 0x3b:
        case 0x3f:
        case 0x40:
          fVar10 = Combat_computeAttackSpeed(creature);
          piVar7 = (int *)(int)(50.0 / ((float)fVar10 * *(float *)(creature + 0x17c)));
          goto LAB_00410d39;
        case 0x1a:
          fVar10 = Combat_computeAttackSpeed(creature);
          speed = (float)fVar10;
          base_ms = 300.0;
          break;
        default:
          fVar10 = Combat_computeAttackSpeed(creature);
LAB_00410d21:
          speed = (float)fVar10;
          base_ms = 400.0;
          break;
        case 0x1e:
        case 0x20:
          fVar10 = Combat_computeAttackSpeed(creature);
          speed = (float)fVar10;
          base_ms = 800.0;
          break;
        case 0x1f:
        case 0x21:
          fVar10 = Combat_computeAttackSpeed(creature);
          piVar7 = (int *)(int)(1600.0 / ((float)fVar10 * *(float *)(creature + 0x17c)));
          goto LAB_00410d39;
        case 0x22:
          fVar10 = Combat_computeAttackSpeed(creature);
          piVar7 = (int *)(int)(1600.0 / ((float)fVar10 * *(float *)(creature + 0x17c)));
          goto LAB_00410d39;
        case 0x25:
        case 0x2b:
        case 0x59:
          if (*(char *)(creature + 0xaa9) == '\f') {
            fVar10 = Combat_computeAttackSpeed(creature);
            piVar7 = (int *)(int)(600.0 / ((float)fVar10 * *(float *)(creature + 0x17c)));
          }
          else {
            fVar10 = Combat_computeAttackSpeed(creature);
            piVar7 = (int *)(int)(1200.0 / ((float)fVar10 * *(float *)(creature + 0x17c)));
          }
          goto LAB_00410d39;
        case 0x26:
        case 0x2c:
          fVar10 = Combat_computeAttackSpeed(creature);
          speed = (float)fVar10;
          base_ms = 500.0;
          break;
        case 0x27:
        case 0x28:
        case 0x29:
        case 0x2a:
          fVar10 = Combat_computeAttackSpeed(creature);
          speed = (float)fVar10;
          base_ms = 200.0;
          break;
        case 0x2d:
        case 0x2e:
          fVar10 = Combat_computeAttackSpeed(creature);
          piVar7 = (int *)(int)(1200.0 / ((float)fVar10 * *(float *)(creature + 0x17c)));
          goto LAB_00410d39;
        case 0x30:
        case 0x65:
          piVar7 = (int *)0x64;
          goto LAB_00410d39;
        case 0x36:
          piVar7 = (int *)0x190;
          goto LAB_00410d39;
        case 0x39:
        case 0x3a:
          fVar10 = Combat_computeAttackSpeed(creature);
          speed = (float)fVar10;
          base_ms = 800.0;
          break;
        case 0x41:
        case 0x42:
          fVar10 = Combat_computeAttackSpeed(creature);
          speed = (float)fVar10;
          base_ms = 300.0;
          break;
        case 0x44:
        case 0x45:
        case 0x46:
        case 0x49:
        case 0x4a:
        case 0x4b:
        case 0x4c:
        case 0x4d:
        case 0x4e:
          fVar10 = Combat_computeAttackSpeed(creature);
          speed = (float)fVar10;
          base_ms = 300.0;
          break;
        case 0x47:
        case 0x48:
          piVar7 = (int *)0xc8;
          goto LAB_00410d39;
        case 0x57:
          fVar10 = Combat_computeAttackSpeed(creature);
          piVar7 = (int *)(int)(5000.0 / ((float)fVar10 * *(float *)(creature + 0x17c)));
          goto LAB_00410d39;
        case 0x5b:
          fVar10 = Combat_computeAttackSpeed(creature);
          piVar7 = (int *)(int)(1000.0 / ((float)fVar10 * *(float *)(creature + 0x17c)));
          goto LAB_00410d39;
        case 0x5d:
          fVar10 = Combat_computeAttackSpeed(creature);
          speed = (float)fVar10;
          base_ms = 800.0;
          break;
        case 0x5e:
          fVar10 = Combat_computeAttackSpeed(creature);
          speed = (float)fVar10;
          base_ms = 500.0;
          break;
        case 0x5f:
          fVar10 = Combat_computeAttackSpeed(creature);
          piVar7 = (int *)(int)(1000.0 / ((float)fVar10 * *(float *)(creature + 0x17c)));
          goto LAB_00410d39;
        case 0x69:
          piVar7 = (int *)0x1388;
          goto LAB_00410d39;
        }
        piVar7 = (int *)(int)(base_ms / (speed * *(float *)(creature + 0x17c)));
LAB_00410d39:
        *(int **)(creature + 0x6c) = piVar7;
      }
    }
  }
LAB_00410d3c:
  if (!bVar2) {
    *(undefined4 *)(creature + 0x128) = 0;
  }
  return CONCAT31((int3)((uint)piVar7 >> 8),1);
code_r0x004108cd:
  piVar7 = (int *)*piVar7;
  if (piVar7 == piVar1) goto LAB_00410d3c;
  goto LAB_004108c7;
}




/* [AUDIT] proposed: Combat_getProjectileSpawnPos  (confidence: high)
 * purpose: Computes projectile/muzzle world position: rotates offset by yaw (cos/sin) around creature 64-bit coords
 * vars: this+0x30=yaw deg; +0x84/0x88=offsets; +0x10..0x24=64-bit x/y/z; creature=out coords
 */
/* Global::Combat_getProjectileSpawnPos @ 00411800 */

void __thiscall Combat_getProjectileSpawnPos(void *this,uint *out_pos)

{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  float fVar4;
  float fVar5;
  double dVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  ulonglong uVar10;
  float local_6c;
  float local_68;
  float local_64;
  float local_60;
  float local_5c;
  float local_58;
  float local_54;
  float local_50;
  float local_4c;
  float local_48;
  float local_44;
  float local_40;
  float local_3c;
  float local_38;
  float local_34;
  float local_30;
  uint rnd [6];
  float local_14;
  float local_10;
  float local_c;
  uint local_8;
  
  local_8 = DAT_00583cc8 ^ (uint)&stack0xfffffffc;
  if ((*(byte *)((int)this + 0x7e) & 4) != 0) {
    Matrix4_setIdentity(&local_6c);
    fVar4 = *(float *)((int)this + 0x30) * 0.017453292;
    dVar6 = (double)fVar4;
    libm_sse2_cos_precise();
    fVar5 = (float)dVar6;
    dVar6 = (double)fVar4;
    libm_sse2_sin_precise();
    fVar7 = (float)dVar6;
    fVar9 = *(float *)((int)this + 0x84) * 0.5;
    fVar8 = *(float *)((int)this + 0x88) * 0.35;
    iVar3 = 0;
    fVar4 = 1.0 / (fVar9 * (local_50 * fVar5 - local_60 * fVar7) +
                   (local_50 * fVar7 + local_60 * fVar5) * 0.0 + local_40 * fVar8 + local_30);
    local_14 = fVar4 * (fVar9 * (local_5c * fVar5 - local_6c * fVar7) +
                        (local_5c * fVar7 + local_6c * fVar5) * 0.0 + local_4c * fVar8 + local_3c);
    local_10 = fVar4 * (fVar9 * (local_58 * fVar5 - local_68 * fVar7) +
                        (local_58 * fVar7 + local_68 * fVar5) * 0.0 + local_48 * fVar8 + local_38);
    local_c = fVar4 * (fVar9 * (local_54 * fVar5 - local_64 * fVar7) +
                       (local_54 * fVar7 + local_64 * fVar5) * 0.0 + local_44 * fVar8 + local_34);
    do {
      uVar10 = ftol2();
      rnd[iVar3 * 2] = (uint)uVar10;
      rnd[iVar3 * 2 + 1] = (uint)(uVar10 >> 0x20);
      iVar3 = iVar3 + 1;
    } while (iVar3 < 3);
    *out_pos = *(uint *)((int)this + 0x10);
    out_pos[1] = *(uint *)((int)this + 0x14);
    out_pos[2] = *(uint *)((int)this + 0x18);
    out_pos[3] = *(uint *)((int)this + 0x1c);
    out_pos[4] = *(uint *)((int)this + 0x20);
    out_pos[5] = *(uint *)((int)this + 0x24);
    uVar2 = *out_pos;
    *out_pos = *out_pos + rnd[0];
    out_pos[1] = out_pos[1] + rnd[1] + (uint)CARRY4(uVar2,rnd[0]);
    puVar1 = out_pos + 2;
    uVar2 = *puVar1;
    *puVar1 = *puVar1 + rnd[2];
    out_pos[3] = out_pos[3] + rnd[3] + (uint)CARRY4(uVar2,rnd[2]);
    puVar1 = out_pos + 4;
    uVar2 = *puVar1;
    *puVar1 = *puVar1 + rnd[4];
    out_pos[5] = out_pos[5] + rnd[5] + (uint)CARRY4(uVar2,rnd[4]);
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  *out_pos = *(uint *)((int)this + 0x10);
  out_pos[1] = *(uint *)((int)this + 0x14);
  out_pos[2] = *(uint *)((int)this + 0x18);
  out_pos[3] = *(uint *)((int)this + 0x1c);
  out_pos[4] = *(uint *)((int)this + 0x20);
  out_pos[5] = *(uint *)((int)this + 0x24);
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}




/* [AUDIT] proposed: Combat_getAbilityRecovery  (confidence: high)
 * purpose: Per-ability recovery-time table: constant/(attackSpeed*this+0x17c) with many per-id constants
 * vars: this+0x68=ability id; +0x17c=speed scale
 */
/* Global::Combat_getAbilityRecovery @ 00411d60 */

int __thiscall Combat_getAbilityRecovery(void *this,uint ability)

{
  float10 fVar1;
  float base_ms;
  float speed;
  
  if ((int)ability < 0) {
    ability = (uint)*(byte *)((int)this + 0x68);
  }
  switch(ability) {
  case 0:
  case 0x31:
    return 0;
  case 1:
  case 2:
  case 9:
    fVar1 = Combat_computeAttackSpeed((int)this);
    speed = (float)fVar1;
    base_ms = 200.0;
    break;
  case 3:
  case 4:
  case 0x3e:
    fVar1 = Combat_computeAttackSpeed((int)this);
    speed = (float)fVar1;
    base_ms = 100.0;
    break;
  case 5:
  case 0xc:
  case 0x10:
  case 0x11:
  case 0x41:
  case 0x42:
    fVar1 = Combat_computeAttackSpeed((int)this);
    speed = (float)fVar1;
    base_ms = 400.0;
    break;
  case 6:
  case 7:
    fVar1 = Combat_computeAttackSpeed((int)this);
    speed = (float)fVar1;
    base_ms = 150.0;
    break;
  default:
    fVar1 = Combat_computeAttackSpeed((int)this);
    speed = (float)fVar1;
    goto LAB_00411fd9;
  case 10:
    return 200;
  case 0xb:
    fVar1 = Combat_computeAttackSpeed((int)this);
    speed = (float)fVar1;
    goto LAB_00411fd9;
  case 0xd:
  case 0xe:
  case 0xf:
    fVar1 = Combat_computeAttackSpeed((int)this);
    speed = (float)fVar1;
    base_ms = 200.0;
    break;
  case 0x12:
  case 0x13:
    fVar1 = Combat_computeAttackSpeed((int)this);
    speed = (float)fVar1;
    base_ms = 150.0;
    break;
  case 0x14:
  case 0x15:
    fVar1 = Combat_computeAttackSpeed((int)this);
    speed = (float)fVar1;
    base_ms = 400.0;
    break;
  case 0x16:
    fVar1 = Combat_computeAttackSpeed((int)this);
    speed = (float)fVar1;
    base_ms = 50.0;
    break;
  case 0x17:
    fVar1 = Combat_computeAttackSpeed((int)this);
    speed = (float)fVar1;
    base_ms = 50.0;
    break;
  case 0x1a:
    fVar1 = Combat_computeAttackSpeed((int)this);
    speed = (float)fVar1;
    base_ms = 1200.0;
    break;
  case 0x1e:
  case 0x20:
  case 0x49:
  case 0x5d:
    return 600;
  case 0x1f:
  case 0x21:
    return 0x4b0;
  case 0x22:
    fVar1 = Combat_computeAttackSpeed((int)this);
    speed = (float)fVar1;
    base_ms = 1200.0;
    break;
  case 0x25:
  case 0x2b:
    fVar1 = Combat_computeAttackSpeed((int)this);
    speed = (float)fVar1;
    base_ms = 100.0;
    break;
  case 0x26:
  case 0x27:
  case 0x28:
  case 0x29:
  case 0x2a:
  case 0x2c:
    fVar1 = Combat_computeAttackSpeed((int)this);
    speed = (float)fVar1;
    goto LAB_00411fd9;
  case 0x2d:
  case 0x2e:
    fVar1 = Combat_computeAttackSpeed((int)this);
    speed = (float)fVar1;
    base_ms = 500.0;
    break;
  case 0x32:
  case 0x4c:
  case 0x4d:
  case 0x4e:
  case 0x60:
    return 500;
  case 0x36:
    return 100;
  case 0x37:
    fVar1 = Combat_computeAttackSpeed((int)this);
    speed = (float)fVar1;
    base_ms = 500.0;
    break;
  case 0x43:
    fVar1 = Combat_computeAttackSpeed((int)this);
    speed = (float)fVar1;
    base_ms = 200.0;
    break;
  case 0x44:
  case 0x45:
    return 1000;
  case 0x47:
    return 3000;
  case 0x48:
  case 0x56:
    return 5000;
  case 0x4b:
    fVar1 = Combat_computeAttackSpeed((int)this);
    speed = (float)fVar1;
    goto LAB_00411fd9;
  case 0x5b:
    return 6000;
  case 0x5e:
    fVar1 = Combat_computeAttackSpeed((int)this);
    speed = (float)fVar1;
    base_ms = 500.0;
    break;
  case 0x5f:
    return 2000;
  case 0x68:
    fVar1 = Combat_computeAttackSpeed((int)this);
    speed = (float)fVar1;
LAB_00411fd9:
    base_ms = 300.0;
  }
  return (int)(base_ms / (speed * *(float *)((int)this + 0x17c)));
}




/* [AUDIT] proposed: Combat_computeAttackSpeed  (confidence: high)
 * purpose: Computes attack-speed multiplier from class/subclass, health ratio, equipment bonuses and a buff (tag 0xc)
 * vars: ability+0x140/0x141=class; +0x70=hp; +0x17c; +0x1178 buff list
 */
/* Global::Combat_computeAttackSpeed @ 00412150 */

float10 __fastcall Combat_computeAttackSpeed(int creature)

{
  char cVar1;
  int *piVar2;
  int maxhp;
  int *piVar4;
  float10 fVar5;
  float ratio;
  float speed;
  
  speed = 1.0;
  if (*(char *)(creature + 0x60) != '\0') {
    speed = (float)*(byte *)(creature + 0x1a8) * 0.0625 + 0.75;
  }
  cVar1 = *(char *)(creature + 0x140);
  if ((cVar1 == '\x01') && (*(char *)(creature + 0x141) == '\0')) {
    maxhp = Combat_getStaminaRegenRate(creature);
    if ((float)*(int *)(creature + 0x70) / (float)maxhp <= 1.0) {
      maxhp = Combat_getStaminaRegenRate(creature);
      ratio = (float)*(int *)(creature + 0x70) / (float)maxhp;
    }
    else {
      ratio = 1.0;
    }
    speed = ratio * 0.5 + speed;
  }
  if ((cVar1 == '\x03') && (*(char *)(creature + 0x141) == '\x01')) {
    maxhp = Combat_getStaminaRegenRate(creature);
    if ((float)*(int *)(creature + 0x70) / (float)maxhp <= 1.0) {
      maxhp = Combat_getStaminaRegenRate(creature);
      ratio = (float)*(int *)(creature + 0x70) / (float)maxhp;
    }
    else {
      ratio = 1.0;
    }
    speed = ratio + speed;
  }
  fVar5 = Combat_sumEquipAttackBonus(creature);
  piVar2 = *(int **)(creature + 0x1178);
  speed = (float)fVar5 + speed;
  piVar4 = (int *)*piVar2;
  if (piVar4 != piVar2) {
    while ((char)piVar4[2] != '\f') {
      piVar4 = (int *)*piVar4;
      if (piVar4 == piVar2) {
        return (float10)speed;
      }
    }
    if (piVar4 != (int *)0xfffffff8) {
      maxhp = *(int *)(creature + 0x1158);
      if ((maxhp == 0) && (*(char *)(creature + 0x60) != '\0')) {
        maxhp = *(int *)(creature + 400) / 2 + *(byte *)(creature + 0x1a8) + 1;
      }
      speed = ((1.0 - 1.0 / ((float)maxhp * 0.1 + 1.0)) + 1.0) * speed;
    }
  }
  return (float10)speed;
}




/* [AUDIT] proposed: Combat_sumEquipAttackBonus  (confidence: high)
 * purpose: Sums attack-speed/stat bonuses (2^a*2^b/2^c*0.1) across all equipment slots via 00414350
 * vars: creature equip slots at 0x990,0xaa8,0x530,0x648,0x760,0x878,0x418,0xbc0,0xcd8
 */
/* Global::Combat_sumEquipAttackBonus @ 00412300 */

float10 __fastcall Combat_sumEquipAttackBonus(int creature)

{
  float10 fVar1;
  double dVar2;
  double dVar3;
  double dVar4;
  undefined4 result;
  undefined4 sum;
  
  dVar2 = 2.0;
  libm_sse2_pow_precise();
  dVar3 = 2.0;
  libm_sse2_pow_precise();
  dVar4 = 2.0;
  libm_sse2_pow_precise();
  sum = (((float)dVar2 * (float)dVar3) / (float)dVar4) * 0.1;
  if (*(char *)(creature + 0x990) == '\x03') {
    fVar1 = Combat_equipSpeedBonus((char *)(creature + 0x990));
    sum = (float)fVar1 + sum;
  }
  if (*(char *)(creature + 0xaa8) == '\x03') {
    fVar1 = Combat_equipSpeedBonus((char *)(creature + 0xaa8));
    sum = (float)fVar1 + sum;
  }
  if (*(char *)(creature + 0x530) == '\x04') {
    fVar1 = Combat_equipSpeedBonus((char *)(creature + 0x530));
    sum = (float)fVar1 + sum;
  }
  if (*(char *)(creature + 0x648) == '\x06') {
    fVar1 = Combat_equipSpeedBonus((char *)(creature + 0x648));
    sum = (float)fVar1 + sum;
  }
  if (*(char *)(creature + 0x760) == '\x05') {
    fVar1 = Combat_equipSpeedBonus((char *)(creature + 0x760));
    sum = (float)fVar1 + sum;
  }
  if (*(char *)(creature + 0x878) == '\a') {
    fVar1 = Combat_equipSpeedBonus((char *)(creature + 0x878));
    sum = (float)fVar1 + sum;
  }
  if (*(char *)(creature + 0x418) == '\b') {
    fVar1 = Combat_equipSpeedBonus((char *)(creature + 0x418));
    sum = (float)fVar1 + sum;
  }
  if (*(char *)(creature + 0xbc0) == '\t') {
    fVar1 = Combat_equipSpeedBonus((char *)(creature + 0xbc0));
    sum = (float)fVar1 + sum;
  }
  result = sum;
  if (*(char *)(creature + 0xcd8) == '\t') {
    fVar1 = Combat_equipSpeedBonus((char *)(creature + 0xcd8));
    result = (float)fVar1 + sum;
  }
  return (float10)result;
}




/* [AUDIT] proposed: Combat_equipSpeedBonus  (confidence: high)
 * purpose: Computes attack-speed bonus from an equipment slot; base 0.1/0.2 by type, scaled, min threshold 0.001
 * vars: creature=slot; [0]=type; +4=id; +0xd=subtype
 */
/* Global::Combat_equipSpeedBonus @ 00414350 */

float10 __fastcall Combat_equipSpeedBonus(char *item)

{
  char cVar1;
  char cVar2;
  float10 fVar3;
  float value;
  float multiplier;
  
  cVar1 = *item;
  if ((((cVar1 == '\b') || (cVar1 == '\t')) || (cVar1 == '\x03')) ||
     (((cVar1 == '\x04' || (cVar1 == '\a')) || ((cVar1 == '\x05' || (cVar1 == '\x06')))))) {
    multiplier = 0.1;
    if (((cVar1 == '\x03') &&
        ((((cVar2 = item[1], cVar2 == '\x0f' || (cVar2 == '\x10')) ||
          ((cVar2 == '\x11' ||
           ((((cVar2 == '\x05' || (cVar2 == '\n')) || (cVar2 == '\v')) ||
            ((cVar2 == '\x12' || (cVar2 == '\b')))))))) || ((cVar2 == '\x06' || (cVar2 == '\a'))))))
       || (cVar1 == '\x04')) {
      multiplier = 0.2;
    }
    value = ((float)(int)((ulonglong)*(uint *)(item + 4) % 0x15) + 0.0) / 20.0;
    if (item[0xd] == '\f') {
      value = value + 1.0;
    }
    fVar3 = pow2MulDiv();
    value = (float)fVar3 * multiplier * value;
    if (0.001 <= value) {
      return (float10)value;
    }
  }
  return (float10)0;
}




/* [AUDIT] proposed: CombatBehavior::pushTargetPos  (confidence: med)
 * purpose: Copies self+param coords into local struct and appends node to a list at param_3+0x58; enforces list length cap
 * vars: param_3+0x5c=list size (cap 0x5555554); local_2c..=xyz coords packed
 */
/* Global::CombatBehavior_pushTargetPos @ 004ce9f0 */

void CombatBehavior_pushTargetPos(void *dst_pos,char *target_entity,int combat_state)

{
  undefined4 *list_head;
  int list_node;
  undefined4 rec_x;
  undefined4 rec_y;
  undefined4 local_24;
  undefined4 local_20;
  undefined8 src_pos;
  undefined8 local_14;
  undefined8 local_c;
  
  Combat_upsertBuffEntry(dst_pos,target_entity);
  src_pos = *(undefined8 *)target_entity;
  rec_x = *(undefined4 *)((int)dst_pos + 8);
  rec_y = *(undefined4 *)((int)dst_pos + 0xc);
  local_14 = *(undefined8 *)(target_entity + 8);
  local_c = *(undefined8 *)(target_entity + 0x10);
  list_head = *(undefined4 **)(combat_state + 0x58);
  local_24 = rec_x;
  local_20 = rec_y;
  list_node = list_emplaceCopy40(list_head,(undefined4 *)list_head[1],(undefined8 *)&rec_x);
  if (*(int *)(combat_state + 0x5c) == 0x5555554) {
                    /* WARNING: Subroutine does not return */
    std::_Xlength_error("list<T> too long");
  }
  *(int *)(combat_state + 0x5c) = *(int *)(combat_state + 0x5c) + 1;
  list_head[1] = list_node;
  **(int **)(list_node + 4) = list_node;
  return;
}




/* [AUDIT] proposed: CombatBehavior::areHostile  (confidence: high)
 * purpose: Faction/hostility predicate between two creatures; returns bool whether they can fight (dueling/PvP flags)
 * vars: +0x60=faction/mode byte; +0x124 bit0x20=pvp flag; Combat_isMeleeSwingOpcode=get team id
 */
/* Global::CombatBehavior_areHostile @ 004cfcc0 */

int CombatBehavior_areHostile(int entity_a,int entity_b)

{
  char type_a;
  undefined4 in_EAX;
  uint3 uVar4;
  uint faction_a;
  uint faction_b;
  
  type_a = *(char *)(entity_a + 0x60);
  uVar4 = (uint3)((uint)in_EAX >> 8);
  faction_b = CONCAT31(uVar4,type_a);
  if ((((type_a == '\x05') && (*(char *)(entity_b + 0x60) == '\0')) || (type_a == '\x06')) ||
     (*(char *)(entity_b + 0x60) == '\x06')) {
    return (uint)uVar4 << 8;
  }
  if (type_a == '\x01') {
    if (*(char *)(entity_b + 0x60) != '\x01') goto LAB_004cfd44;
    faction_a = Combat_isMeleeSwingOpcode(entity_a);
    faction_b = Combat_isMeleeSwingOpcode(entity_b);
    if ((char)faction_b != (char)faction_a) goto LAB_004cfd44;
  }
  if (*(char *)(entity_b + 0x60) == '\x01') {
    if (*(char *)(entity_a + 0x60) != '\x01') goto LAB_004cfd44;
    faction_a = Combat_isMeleeSwingOpcode(entity_a);
    faction_b = Combat_isMeleeSwingOpcode(entity_b);
    if ((char)faction_a != (char)faction_b) goto LAB_004cfd44;
  }
  if (((*(byte *)(entity_a + 0x124) & 0x20) == 0) && ((*(byte *)(entity_b + 0x124) & 0x20) == 0)) {
    return faction_b & 0xffffff00;
  }
LAB_004cfd44:
  return CONCAT31((int3)(faction_b >> 8),1);
}




/* [AUDIT] proposed: CombatBehavior::alertNearbyAllies  (confidence: high)
 * purpose: On aggro, iterates creature list; for hostile creatures within range sets alert flag(0.5) and enqueues alert msg
 * vars: entity_b+0x13a4=per-target alert map; range^2=64.0; CombatBehavior_areHostile=hostile check; +0x50 list at param_3
 */
/* Global::CombatBehavior_alertNearbyAllies @ 004d5f40 */

void CombatBehavior_alertNearbyAllies(int attacker,int target,int param_3)

{
  char is_nil;
  undefined4 *puVar2;
  int iVar3;
  int *node;
  int *parent;
  uint *puVar6;
  int iVar7;
  undefined4 uVar8;
  float *pfVar9;
  int *creature_iter;
  uint *puVar11;
  undefined4 local_6c;
  undefined4 local_68;
  uint local_64;
  undefined4 local_60;
  uint local_5c;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  uint local_44;
  int attacker_ptr;
  undefined4 *aggro_list;
  int local_34;
  float local_30;
  float dx;
  float dy;
  float dz;
  undefined8 local_20;
  undefined8 local_18;
  undefined8 local_10;
  uint security_cookie;
  
  security_cookie = DAT_00583cc8 ^ (uint)&stack0xfffffffc;
  attacker_ptr = attacker;
  local_4c = *(undefined4 *)(attacker + 8);
  puVar11 = (uint *)(attacker + 8);
  local_48 = *(undefined4 *)(attacker + 0xc);
  local_54 = *(undefined4 *)(target + 8);
  local_50 = *(undefined4 *)(target + 0xc);
  puVar6 = RBTree_findOrInsert((void *)(target + 0x13a4),puVar11);
  local_44 = *puVar6;
  aggro_list = (undefined4 *)(param_3 + 0x50);
  puVar2 = (undefined4 *)*aggro_list;
  iVar7 = list_emplaceCopy24(puVar2,(undefined4 *)puVar2[1],(undefined8 *)&local_54);
  if (aggro_list[1] != 0x7fffffe) {
    aggro_list[1] = aggro_list[1] + 1;
    puVar2[1] = iVar7;
    **(int **)(iVar7 + 4) = iVar7;
    creature_iter = (int *)**(int **)(local_34 + 4);
    iVar7 = local_34;
    if (creature_iter != *(int **)(local_34 + 4)) {
      do {
        iVar3 = creature_iter[6];
        if ((((iVar3 != 0) && (iVar3 != attacker_ptr)) && (iVar3 != target)) &&
           (uVar8 = CombatBehavior_areHostile(iVar3,attacker_ptr), iVar7 = local_34, (char)uVar8 != '\0')) {
          iVar3 = creature_iter[6];
          local_20._0_4_ = (uint)*(undefined8 *)(iVar3 + 0x10);
          local_20._4_4_ = (int)((ulonglong)*(undefined8 *)(iVar3 + 0x10) >> 0x20);
          local_20 = CONCAT44((local_20._4_4_ - *(int *)(target + 0x14)) -
                              (uint)((uint)local_20 < *(uint *)(target + 0x10)),
                              (uint)local_20 - *(uint *)(target + 0x10));
          local_18._0_4_ = (uint)*(undefined8 *)(iVar3 + 0x18);
          local_18._4_4_ = (int)((ulonglong)*(undefined8 *)(iVar3 + 0x18) >> 0x20);
          local_18 = CONCAT44((local_18._4_4_ - *(int *)(target + 0x1c)) -
                              (uint)((uint)local_18 < *(uint *)(target + 0x18)),
                              (uint)local_18 - *(uint *)(target + 0x18));
          local_10._0_4_ = (uint)*(undefined8 *)(iVar3 + 0x20);
          local_10._4_4_ = (int)((ulonglong)*(undefined8 *)(iVar3 + 0x20) >> 0x20);
          local_10 = CONCAT44((local_10._4_4_ - *(int *)(target + 0x24)) -
                              (uint)((uint)local_10 < *(uint *)(target + 0x20)),
                              (uint)local_10 - *(uint *)(target + 0x20));
          dx = (float)local_20 * 1.5258789e-05;
          local_30 = (float)local_10;
          dy = (float)local_18 * 1.5258789e-05;
          dz = local_30 * 1.5258789e-05;
          if ((dy * dy + dx * dx + dz * dz < 64.0) &&
             (pfVar9 = (float *)RBTree_findOrInsert((void *)(iVar3 + 0x13a4),puVar11), iVar7 = local_34,
             *pfVar9 == 0.0)) {
            puVar6 = RBTree_findOrInsert((void *)(creature_iter[6] + 0x13a4),puVar11);
            *puVar6 = 0x3f000000;
            local_64 = *puVar11;
            iVar7 = creature_iter[6];
            local_60 = *(undefined4 *)(attacker + 0xc);
            local_6c = *(undefined4 *)(iVar7 + 8);
            local_68 = *(undefined4 *)(iVar7 + 0xc);
            puVar6 = RBTree_findOrInsert((void *)(iVar7 + 0x13a4),puVar11);
            local_5c = *puVar6;
            CombatBehavior_pushAlertMsg(aggro_list,(undefined8 *)&local_6c);
            iVar7 = local_34;
          }
        }
        if (*(char *)((int)creature_iter + 0xd) == '\0') {
          node = (int *)creature_iter[2];
          if (*(char *)((int)node + 0xd) == '\0') {
            is_nil = *(char *)(*node + 0xd);
            creature_iter = node;
            node = (int *)*node;
            while (is_nil == '\0') {
              is_nil = *(char *)(*node + 0xd);
              creature_iter = node;
              node = (int *)*node;
            }
          }
          else {
            is_nil = *(char *)(creature_iter[1] + 0xd);
            parent = (int *)creature_iter[1];
            node = creature_iter;
            while ((creature_iter = parent, is_nil == '\0' && (node == (int *)creature_iter[2]))) {
              is_nil = *(char *)(creature_iter[1] + 0xd);
              parent = (int *)creature_iter[1];
              node = creature_iter;
            }
          }
        }
      } while (creature_iter != *(int **)(iVar7 + 4));
    }
    __security_check_cookie(security_cookie ^ (uint)&stack0xfffffffc);
    return;
  }
                    /* WARNING: Subroutine does not return */
  std::_Xlength_error("list<T> too long");
}




/* [AUDIT] proposed: CombatBehavior::pushAlertMsg  (confidence: med)
 * purpose: Appends a node (coords payload) to list at this[0], enforcing list size cap 0x7ffffe
 * vars: this+4=list count; list_emplaceCopy24=list node insert
 */
/* Global::CombatBehavior_pushAlertMsg @ 004d6580 */

void __thiscall CombatBehavior_pushAlertMsg(void *this,undefined8 *value)

{
  undefined4 *head;
  int new_node;
  
  head = *(undefined4 **)this;
  new_node = list_emplaceCopy24(head,(undefined4 *)head[1],value);
  if (*(int *)((int)this + 4) == 0x7fffffe) {
                    /* WARNING: Subroutine does not return */
    std::_Xlength_error("list<T> too long");
  }
  *(int *)((int)this + 4) = *(int *)((int)this + 4) + 1;
  head[1] = new_node;
  **(int **)(new_node + 4) = new_node;
  return;
}




