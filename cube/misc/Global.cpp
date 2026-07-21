// Global (misc) — cube. 13 functions. Bodies = Ghidra pseudo-C.
#include "Global.h"

/* [AUDIT] proposed: App::render_frame  (confidence: low)
 * purpose: Per-frame tick: update timing, handle resize, Present (game)
 * vars: -
 */
/* Global::App_render_frame @ 004c85f0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void App_render_frame(void)

{
  DWORD DVar1;
  int iVar2;
  
  if ((DAT_0076b1b4 != (int *)0x0) && (DAT_0076b1c8 != (int *)0x0)) {
    DVar1 = timeGetTime();
    if (DAT_0076b234 == 0) {
      DAT_0076b234 = DVar1;
    }
    (**(code **)(*DAT_0076b1c8 + 0x28))(DVar1 - DAT_0076b234);
    if ((((DAT_0076b1c8[0x5d] != DAT_0076b1dc) || (DAT_0076b1c8[0x5e] != DAT_0076b1e0)) ||
        (DAT_0076b1c8[0x5c] != DAT_0076b1d8)) || (DAT_0076b1c8[0x5f] != DAT_0076b1e4)) {
      _DAT_0076b1d8 = *(undefined8 *)(DAT_0076b1c8 + 0x5c);
      _DAT_0076b1e0 = *(undefined8 *)(DAT_0076b1c8 + 0x5e);
      _DAT_0076b1e8 = *(undefined8 *)(DAT_0076b1c8 + 0x60);
      _DAT_0076b1f0 = *(undefined8 *)(DAT_0076b1c8 + 0x62);
      _DAT_0076b1f8 = *(undefined8 *)(DAT_0076b1c8 + 100);
      _DAT_0076b200 = *(undefined8 *)(DAT_0076b1c8 + 0x66);
      App_reset_device(0);
    }
    DAT_0076b234 = DVar1;
    (**(code **)(*DAT_0076b1c8 + 0x2c))();
    iVar2 = (**(code **)(*DAT_0076b1b4 + 0x44))(DAT_0076b1b4,0,0,0,0);
    if (iVar2 == -0x7789f798) {
      DAT_0076b1d1 = 1;
    }
  }
  return;
}




/* [AUDIT] proposed: App::init_direct3d  (confidence: med)
 * purpose: Create Direct3D9 device, D3D9Engine and CubeShader (game)
 * vars: -
 */
/* Global::App_init_direct3d @ 004c8720 */

void App_init_direct3d(void)

{
  char cVar1;
  int iVar2;
  int local_78;
  int local_74;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_44;
  void *local_40;
  tagRECT local_3c;
  void *local_2c [4];
  undefined4 local_1c;
  uint local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_006e842e;
  local_10 = ExceptionList;
  local_14 = DAT_0076aa78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  DAT_0076b1b8 = (int *)Direct3DCreate9(0x20,local_14);
  if (DAT_0076b1b8 != (int *)0x0) {
    memset(&local_78,0,0x38);
    local_68 = 0;
    local_64 = 0;
    local_78 = GetSystemMetrics(0);
    local_74 = GetSystemMetrics(1);
    local_58 = 1;
    local_60 = 1;
    local_44 = 0x80000000;
    local_54 = 1;
    local_50 = 0x4b;
    iVar2 = (**(code **)(*DAT_0076b1b8 + 0x40))
                      (DAT_0076b1b8,0,1,DAT_0076b1c0,0x44,&local_78,&DAT_0076b1b4);
    if (iVar2 == 0) {
      local_40 = operator_new(0x2d0);
      local_8 = 0;
      if (local_40 == (void *)0x0) {
        DAT_0076b1cc = (int *)0x0;
      }
      else {
        DAT_0076b1cc = (int *)plasma::D3D9Engine::ctor_1(DAT_0076b1b4);
      }
      local_8 = 0xffffffff;
      u16string_assignCStr(L"c:\\windows\\fonts");
      local_8 = 1;
      FUN_00639390(local_2c);
      local_8 = 0xffffffff;
      if (7 < local_18) {
                    /* WARNING: Subroutine does not return */
        operator_delete(local_2c[0]);
      }
      local_2c[0] = (void *)((uint)local_2c[0] & 0xffff0000);
      local_18 = 7;
      local_1c = 0;
      cVar1 = (**(code **)(*DAT_0076b1cc + 4))();
      if (cVar1 != '\0') {
        local_40 = operator_new(0x74);
        local_8 = 2;
        if (local_40 == (void *)0x0) {
          DAT_0076b1bc = (undefined4 *)0x0;
        }
        else {
          DAT_0076b1bc = (undefined4 *)cube::CubeShader::ctor_1(DAT_0076b1b4);
        }
        local_8 = 0xffffffff;
        cVar1 = Input_init_keybindings();
        if (cVar1 != '\0') {
          GetClientRect(DAT_0076b1c0,&local_3c);
          FUN_00659d70(0,0,local_3c.right,local_3c.bottom,1);
          goto LAB_004c891c;
        }
        if (DAT_0076b1bc != (undefined4 *)0x0) {
          (**(code **)*DAT_0076b1bc)(1);
        }
      }
      (**(code **)(*DAT_0076b1b4 + 8))(DAT_0076b1b4);
      DAT_0076b1b4 = (int *)0x0;
    }
    (**(code **)(*DAT_0076b1b8 + 8))(DAT_0076b1b8);
    DAT_0076b1b8 = (int *)0x0;
  }
LAB_004c891c:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}




/* [AUDIT] proposed: App::reset_device  (confidence: low)
 * purpose: Reset/resize D3D device and swap chain on resolution change (game)
 * vars: -
 */
/* Global::App_reset_device @ 004c8940 */

void App_reset_device(void)

{
  LONG LVar1;
  LONG LVar2;
  int iVar3;
  int *piVar4;
  int local_54;
  int local_50;
  undefined4 local_4c;
  int local_44;
  undefined4 local_40;
  undefined4 local_3c;
  uint local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_20;
  char local_19;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_0076aa78 ^ (uint)&stack0xfffffffc;
  local_19 = DAT_0076b1d8 != 0;
  if ((bool)local_19) {
    local_18.right = DAT_0076b1dc;
    local_18.bottom = DAT_0076b1e0;
  }
  else {
    GetClientRect(DAT_0076b1c0,&local_18);
  }
  if ((0 < local_18.right) && (0 < local_18.bottom)) {
    if (DAT_0076b1b4 != (int *)0x0) {
      if (DAT_0076b1cc != 0) {
        FUN_0068a710();
        FUN_00659d70(0,0,local_18.right,local_18.bottom,1);
      }
      LVar2 = local_18.bottom;
      LVar1 = local_18.right;
      piVar4 = DAT_0076b1b4;
      memset(&local_54,0,0x38);
      if (DAT_0076b1e4 == 0) {
        local_44 = DAT_0076b1e4;
      }
      else {
        local_44 = DAT_0076b1e4 * 2;
      }
      local_40 = 0;
      local_34 = (uint)(local_19 == '\0');
      local_4c = 0x15;
      local_3c = 1;
      local_20 = 0x80000000;
      local_30 = 1;
      local_2c = 0x4b;
      local_54 = LVar1;
      local_50 = LVar2;
      if (DAT_0076b1c8 != (int *)0x0) {
        GameController_acquire_render_locks();
        piVar4 = DAT_0076b1b4;
      }
      iVar3 = (**(code **)(*piVar4 + 0x40))(piVar4,&local_54);
      while (iVar3 != 0) {
        Sleep(100);
        iVar3 = (**(code **)(*DAT_0076b1b4 + 0x40))(DAT_0076b1b4,&local_54);
      }
      if (DAT_0076b1c8 != (int *)0x0) {
        GameController_release_render_locks();
        piVar4 = DAT_0076b1c8;
        iVar3 = *DAT_0076b1c8;
        DAT_0076b1c8[0x47] = local_18.right;
        piVar4[0x48] = local_18.bottom;
        (**(code **)(iVar3 + 0x10))(local_18.right,local_18.bottom);
      }
      if (DAT_0076b1cc != 0) {
        FUN_0068a6b0();
      }
    }
    DAT_0076b1d1 = 0;
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}




/* [AUDIT] proposed: WinMain  (confidence: high)
 * purpose: Entry: RegisterClass/CreateWindow 'Cube World', init D3D/audio/input, run loop
 * vars: param_1=hInstance
 */
/* WinMain @ 004c8ae0 */
/* NOTE(re) 2026-07-15 audit: RECLASSIFIED lib->game. Identity (RE-inferred, high): WinMain.
 * RegisterClassW(CubeWndProc,L"Cube")+CreateWindowExW 800x600, App_init_direct3d + 'Cube World' D3D MsgBox, cube::XAudio2Engine::ctor_0, cube::GameController::ctor_0 (new 0x1001018), PeekMessageW/DispatchMessageW loop, DI 0x100/0x10 input into GC bools, App_render_frame. Game entry, not CRT.
 * Routed to its true class unit by curated_override.tsv (reconstruct2). See scratchpad/audit/verdicts.json. */

void WinMain(HINSTANCE param_1)

{
  uint uVar1;
  char cVar2;
  ATOM AVar3;
  int *piVar4;
  int iVar5;
  LPWSTR lpCmdLine;
  LPWSTR *hMem;
  undefined4 uVar6;
  void *pvVar7;
  BOOL BVar8;
  HWND pHVar9;
  DWORD DVar10;
  int *piVar11;
  int iVar12;
  wchar_t *pwVar13;
  undefined1 local_3a8 [52];
  tagMSG local_374;
  WNDCLASSW local_358;
  int local_330;
  tagPOINT local_32c;
  HINSTANCE local_324;
  int *local_320;
  tagPOINT local_31c;
  int *local_314;
  tagPOINT local_310;
  int *local_308;
  int *local_304;
  int *local_300;
  int *local_2fc;
  undefined1 local_2f8 [400];
  undefined1 local_168 [8];
  tagRECT local_160;
  undefined4 local_150;
  undefined4 uStack_14c;
  void *local_148 [4];
  undefined4 local_138;
  uint local_134;
  undefined1 local_130 [8];
  int local_128;
  uint local_124;
  char local_11c;
  char local_11b;
  char local_11a;
  int local_118 [2];
  int local_110;
  uint uStack_10c;
  undefined1 local_108 [2];
  char local_106;
  char local_105;
  char local_104;
  char local_103;
  char local_f8;
  char local_f7;
  char local_f6;
  char local_f5;
  char local_f4;
  char local_eb;
  char local_ea;
  char local_e9;
  char local_e8;
  char local_de;
  char local_cf;
  uint local_8;
  
  local_8 = DAT_0076aa78 ^ (uint)&stack0xfffffffc;
  local_324 = param_1;
  DAT_0076b1c4 = param_1;
  Ordinal_115(0x202,local_2f8);
  local_358.style = 0;
  local_358.lpfnWndProc = CubeWndProc;
  local_358.cbClsExtra = 0;
  local_358.cbWndExtra = 0;
  local_358.hInstance = DAT_0076b1c4;
  local_358.hIcon = LoadIconW(DAT_0076b1c4,L"Cube");
  local_358.hCursor = (HCURSOR)0x0;
  local_358.hbrBackground = (HBRUSH)0x6;
  local_358.lpszMenuName = L"Cube";
  local_358.lpszClassName = L"Cube";
  AVar3 = RegisterClassW(&local_358);
  if ((AVar3 == 0) ||
     (DAT_0076b1c0 = CreateWindowExW(0,L"Cube",L"Cube",0x6cf0000,200,200,800,600,(HWND)0x0,
                                     (HMENU)0x0,DAT_0076b1c4,(LPVOID)0x0), DAT_0076b1c0 == (HWND)0x0
     )) goto LAB_004c9534;
  cVar2 = App_init_direct3d();
  if (cVar2 == '\0') {
    MessageBoxA(DAT_0076b1c0,
                "Could not initialize Direct3D. Please make sure the latest DirectX End-User Runtime is installed: http://www.microsoft.com/en-us/download/details.aspx?id=35"
                ,"Cube World",0);
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  local_31c.y = (**(code **)(*DAT_0076b1b8 + 0x18))(DAT_0076b1b8,0,0x16);
  local_304 = (int *)0x0;
  local_300 = (int *)0x0;
  local_2fc = (int *)0x0;
  local_310.y = 0;
  if (local_31c.y != 0) {
    do {
      (**(code **)(*DAT_0076b1b8 + 0x1c))(DAT_0076b1b8,0,0x16,local_310.y,&local_128);
      local_32c.y = (LONG)local_304;
      if (local_304 != local_300) {
        local_110 = local_128;
        uStack_10c = local_124;
        iVar5 = (int)&local_110 - (int)local_304;
        piVar4 = local_304;
        do {
          iVar12 = 0;
          piVar11 = piVar4;
          while (*piVar11 == *(int *)(iVar5 + (int)piVar11)) {
            iVar12 = iVar12 + 1;
            piVar11 = piVar11 + 1;
            if (1 < iVar12) goto LAB_004c8d73;
          }
          piVar4 = piVar4 + 2;
          iVar5 = iVar5 + -8;
        } while (piVar4 != local_300);
      }
      local_118[0] = local_128;
      local_118[1] = local_124;
      if ((local_118 < local_300) && (local_304 <= local_118)) {
        iVar5 = (int)local_118 - (int)local_304 >> 3;
        if (local_300 == local_2fc) {
          vector_reserveGrow(1);
        }
        if (local_300 != (int *)0x0) {
          *local_300 = local_304[iVar5 * 2];
          local_300[1] = local_304[iVar5 * 2 + 1];
        }
      }
      else {
        if (local_300 == local_2fc) {
          vector_reserveGrow(1);
        }
        if (local_300 != (int *)0x0) {
          *(ulonglong *)local_300 = CONCAT44(local_118[1],local_118[0]);
        }
      }
      local_300 = local_300 + 2;
LAB_004c8d73:
      local_310.y = local_310.y + 1;
      param_1 = local_324;
    } while ((uint)local_310.y < (uint)local_31c.y);
  }
  DAT_0076b1dc = GetSystemMetrics(0);
  DAT_0076b1e0 = GetSystemMetrics(1);
  Options_loadFromCfg();
  cube::XAudio2Engine::ctor_0();
  cVar2 = cube::XAudio2Engine::initialize();
  if (cVar2 == '\0') {
    MessageBoxA(DAT_0076b1c0,
                "Could not initialize XAudio2. Please make sure the latest DirectX End-User Runtime is installed: http://www.microsoft.com/en-us/download/details.aspx?id=35"
                ,"Cube World",0);
  }
  else {
    cube::XAudio2Engine::vfunc_5((float)DAT_0076b1f0 * 0.01,0);
    iVar5 = DirectInput8Create(param_1,0x800,&DAT_0071e290,&local_320,0);
    if (iVar5 == 0) {
      (**(code **)(*local_320 + 0xc))(local_320,&DAT_0071e2f0,&local_314);
      (**(code **)(*local_314 + 0x2c))(local_314,&DAT_0071e6f4);
      (**(code **)(*local_314 + 0x1c))(local_314);
      (**(code **)(*local_320 + 0xc))(local_320,&DAT_0071e2e0,&local_308,0);
      (**(code **)(*local_308 + 0x2c))(local_308,&DAT_0071e4ec);
      (**(code **)(*local_308 + 0x34))(local_308,DAT_0076b1c0,10);
      (**(code **)(*local_308 + 0x1c))(local_308);
      piVar4 = &local_330;
      local_330 = 0;
      local_310.y = local_310.y & 0xffffff00;
      local_134 = 0xf;
      local_138 = 0;
      local_148[0] = (void *)((uint)local_148[0] & 0xffffff00);
      lpCmdLine = GetCommandLineW();
      hMem = CommandLineToArgvW(lpCmdLine,piVar4);
      if (hMem != (LPWSTR *)0x0) {
        if (1 < local_330) {
          pwVar13 = L"server";
          uVar6 = u16string_assignCStr(hMem[1]);
          cVar2 = wstring_equalsCI(uVar6,pwVar13);
          std_string_FreeMember();
          if (cVar2 == '\0') {
            u16string_assignCStr(hMem[1]);
            uVar6 = std_string_assignFromString(local_130,local_168);
            string_moveAssign(uVar6);
            string_dtor();
            std_string_FreeMember();
          }
          else {
            local_310.y = CONCAT31(local_310.y._1_3_,1);
          }
        }
        LocalFree(hMem);
      }
      _mkdir("Save");
      pvVar7 = operator_new(0x1001018);
      if (pvVar7 == (void *)0x0) {
        DAT_0076b1c8 = (int *)0x0;
      }
      else {
        DAT_0076b1c8 = (int *)cube::GameController::ctor_0
                                        (DAT_0076b1b4,DAT_0076b1bc,DAT_0076b1cc,local_3a8,
                                         &DAT_0076b1d8,&local_304,local_310.y,local_148);
      }
      ShowWindow(DAT_0076b1c0,3);
      SetCursor((HCURSOR)0x0);
      ShowCursor(0);
      UpdateWindow(DAT_0076b1c0);
      SetFocus(DAT_0076b1c0);
      timeBeginPeriod(1);
LAB_004c9057:
      local_324 = (HINSTANCE)timeGetTime();
      BVar8 = PeekMessageW(&local_374,(HWND)0x0,0,0,0);
      if (BVar8 == 1) {
        BVar8 = GetMessageW(&local_374,(HWND)0x0,0,0);
        if (BVar8 == 0) goto LAB_004c9461;
        TranslateMessage(&local_374);
        DispatchMessageW(&local_374);
      }
      if ((char)DAT_0076b1c8[0x68] != '\0') {
        PostQuitMessage(0);
      }
      if (DAT_00766218 != '\0') {
        GetClientRect(DAT_0076b1c0,&local_160);
        GetCursorPos(&local_31c);
        ScreenToClient(DAT_0076b1c0,&local_31c);
        cVar2 = (**(code **)(*DAT_0076b1c8 + 4))();
        if (cVar2 == '\0') {
          pHVar9 = GetFocus();
          if (pHVar9 == DAT_0076b1c0) {
            local_31c.x = local_160.right / 2;
            local_31c.y = local_160.bottom / 2;
            DAT_0076b1d0 = '\0';
            ClientToScreen(DAT_0076b1c0,&local_31c);
            SetCursorPos(local_31c.x,local_31c.y);
          }
        }
        else {
          if (DAT_0076b1d0 == '\0') {
            local_32c.x = (LONG)(float)DAT_0076b1cc[0x35];
            local_32c.y = (LONG)(float)DAT_0076b1cc[0x36];
            ClientToScreen(DAT_0076b1c0,&local_32c);
            SetCursorPos(local_32c.x,local_32c.y);
          }
          DAT_0076b1d0 = '\x01';
        }
        if ((DAT_00766218 != '\0') && (pHVar9 = GetFocus(), pHVar9 == DAT_0076b1c0)) {
          (**(code **)(*local_314 + 0x24))(local_314,0x100,local_108);
          *(bool *)((int)DAT_0076b1c8 + 0xb) = local_f7 != '\0';
          *(bool *)(DAT_0076b1c8 + 3) = local_e9 != '\0';
          *(bool *)((int)DAT_0076b1c8 + 0xd) = local_ea != '\0';
          *(bool *)((int)DAT_0076b1c8 + 0xe) = local_e8 != '\0';
          *(bool *)((int)DAT_0076b1c8 + 0x11) = local_f6 != '\0';
          *(bool *)((int)DAT_0076b1c8 + 0xf) = local_f5 != '\0';
          *(bool *)(DAT_0076b1c8 + 4) = local_f4 != '\0';
          *(bool *)((int)DAT_0076b1c8 + 0x12) = local_cf != '\0';
          *(bool *)(DAT_0076b1c8 + 5) = local_de != '\0';
          *(bool *)((int)DAT_0076b1c8 + 0x13) = local_eb != '\0';
          *(bool *)((int)DAT_0076b1c8 + 0x17) = local_f8 != '\0';
          (**(code **)(*local_308 + 0x24))(local_308,0x10,&local_128);
          cVar2 = (**(code **)(*DAT_0076b1c8 + 4))();
          iVar5 = local_128;
          uVar1 = local_124;
          if ((cVar2 != '\0') &&
             (GetCursorPos(&local_310), iVar5 = local_310.x, uVar1 = local_310.y, DAT_0076b1d8 == 0)
             ) {
            ScreenToClient(DAT_0076b1c0,&local_310);
            iVar5 = local_310.x;
            uVar1 = local_310.y;
          }
          (**(code **)(*DAT_0076b1c8 + 0x18))((float)iVar5,(float)(int)uVar1);
          *(bool *)(DAT_0076b1c8 + 1) = local_11c != '\0';
          *(bool *)((int)DAT_0076b1c8 + 0x15) = local_de != '\0';
          *(bool *)((int)DAT_0076b1c8 + 10) = local_11a != '\0';
          *(bool *)((int)DAT_0076b1c8 + 5) = local_11b != '\0';
          *(bool *)((int)DAT_0076b1c8 + 6) = local_106 != '\0';
          *(bool *)((int)DAT_0076b1c8 + 7) = local_105 != '\0';
          *(bool *)(DAT_0076b1c8 + 2) = local_104 != '\0';
          *(bool *)((int)DAT_0076b1c8 + 9) = local_103 != '\0';
          local_110 = 0;
          uStack_10c = 0;
          piVar4 = DAT_0076b1c8;
          piVar4[0x49] = 0;
          piVar4[0x4a] = 0;
          local_150 = 0;
          uStack_14c = 0;
          piVar4 = DAT_0076b1c8;
          piVar4[0x4b] = 0;
          piVar4[0x4c] = 0;
        }
      }
      App_render_frame();
      DVar10 = timeGetTime();
      if ((int)(DVar10 - (int)local_324) < DAT_0076b1c8[0x67]) {
        Sleep(DAT_0076b1c8[0x67] - (DVar10 - (int)local_324));
      }
      goto LAB_004c9057;
    }
    MessageBoxA(DAT_0076b1c0,
                "Could not initialize DirectInput8. Please make sure the latest DirectX End-User Runtime is installed: http://www.microsoft.com/en-us/download/details.aspx?id=35"
                ,"Cube World",0);
  }
  goto LAB_004c9514;
LAB_004c9461:
  timeEndPeriod(1);
  if (DAT_0076b1c8 != (int *)0x0) {
    (**(code **)*DAT_0076b1c8)(1);
  }
  if (DAT_0076b1cc != (undefined4 *)0x0) {
    (**(code **)*DAT_0076b1cc)(1);
  }
  (**(code **)(*local_314 + 8))(local_314);
  (**(code **)(*local_308 + 8))(local_308);
  (**(code **)(*local_320 + 8))(local_320);
  if (DAT_0076b1bc != (undefined4 *)0x0) {
    (**(code **)*DAT_0076b1bc)(1);
  }
  if (DAT_0076b1b4 != (int *)0x0) {
    (**(code **)(*DAT_0076b1b4 + 8))(DAT_0076b1b4);
  }
  if (DAT_0076b1b8 != (int *)0x0) {
    (**(code **)(*DAT_0076b1b8 + 8))(DAT_0076b1b8);
  }
  Ordinal_116();
  if (0xf < local_134) {
                    /* WARNING: Subroutine does not return */
    operator_delete(local_148[0]);
  }
  local_134 = 0xf;
  local_138 = 0;
  local_148[0] = (void *)((uint)local_148[0] & 0xffffff00);
LAB_004c9514:
  cube::XAudio2Engine::ctor_1();
  if (local_304 != (int *)0x0) {
                    /* WARNING: Subroutine does not return */
    operator_delete(local_304);
  }
LAB_004c9534:
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}




/* [AUDIT] proposed: Options_loadFromCfg  (confidence: high)
 * purpose: Load game settings from options.cfg: parse key/value lines (fullscreen,resolutionX/Y,volumes,language...)
 * vars: local_e4=ifstream;in_ECX=Options
 */
/* Global::Options_loadFromCfg @ 004ce6e0 */

void Options_loadFromCfg(void)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int *in_ECX;
  byte *****pppppbVar6;
  char *pcVar7;
  bool bVar8;
  int local_e4 [3];
  int aiStack_d8 [25];
  basic_ios<char,std::char_traits<char>_> local_74 [72];
  byte ****local_2c [4];
  uint local_1c;
  uint local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_006e8643;
  local_10 = ExceptionList;
  uVar3 = DAT_0076aa78 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = uVar3;
  std::basic_filebuf<char,std::char_traits<char>_>::ctor_3("options.cfg",1,0x40,1);
  local_8._0_1_ = 0;
  local_8._1_3_ = 0;
  iVar1 = *(int *)((int)aiStack_d8 + *(int *)(local_e4[0] + 4));
  do {
    local_8._0_1_ = 0;
    if (iVar1 != 0) {
LAB_004cef4a:
      std::basic_filebuf<char,std::char_traits<char>_>::ctor_1();
      std::basic_ios<char,std::char_traits<char>_>::~basic_ios<char,std::char_traits<char>_>
                (local_74);
      ExceptionList = local_10;
      __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
      return;
    }
    local_18 = 0xf;
    local_1c = 0;
    local_2c[0] = (byte ****)((uint)local_2c[0] & 0xffffff00);
    local_8._0_1_ = 1;
    std_operator_istream_string(local_e4,local_2c,uVar3);
    uVar5 = local_1c;
    if (*(int *)((int)aiStack_d8 + *(int *)(local_e4[0] + 4)) != 0) {
      if (0xf < local_18) {
                    /* WARNING: Subroutine does not return */
        operator_delete(local_2c[0]);
      }
      goto LAB_004cef4a;
    }
    pppppbVar6 = local_2c;
    if (0xf < local_18) {
      pppppbVar6 = (byte *****)local_2c[0];
    }
    uVar4 = 10;
    if (local_1c < 10) {
      uVar4 = local_1c;
    }
    if (uVar4 == 0) {
LAB_004ce806:
      if (local_1c < 10) {
        uVar4 = 0xffffffff;
      }
      else {
        uVar4 = (uint)(local_1c != 10);
      }
      bVar8 = uVar4 == 0;
    }
    else {
      pcVar7 = "fullscreen";
      while (uVar2 = uVar4 - 4, 3 < uVar4) {
        if (*pppppbVar6 != *(byte *****)pcVar7) goto LAB_004ce7cc;
        pppppbVar6 = pppppbVar6 + 1;
        pcVar7 = pcVar7 + 4;
        uVar4 = uVar2;
      }
      if (uVar2 == 0xfffffffc) {
LAB_004ce800:
        uVar4 = 0;
      }
      else {
LAB_004ce7cc:
        bVar8 = *(byte *)pppppbVar6 < (byte)*pcVar7;
        if ((*(byte *)pppppbVar6 == *pcVar7) &&
           ((uVar2 == 0xfffffffd ||
            ((bVar8 = *(byte *)((int)pppppbVar6 + 1) < (byte)pcVar7[1],
             *(byte *)((int)pppppbVar6 + 1) == pcVar7[1] &&
             ((uVar2 == 0xfffffffe ||
              ((bVar8 = *(byte *)((int)pppppbVar6 + 2) < (byte)pcVar7[2],
               *(byte *)((int)pppppbVar6 + 2) == pcVar7[2] &&
               ((uVar2 == 0xffffffff ||
                (bVar8 = *(byte *)((int)pppppbVar6 + 3) < (byte)pcVar7[3],
                *(byte *)((int)pppppbVar6 + 3) == pcVar7[3])))))))))))) goto LAB_004ce800;
        uVar4 = -(uint)bVar8 | 1;
      }
      bVar8 = false;
      if (uVar4 == 0) goto LAB_004ce806;
    }
    if (bVar8) {
      std::basic_istream<char,std::char_traits<char>_>::operator>>
                ((basic_istream<char,std::char_traits<char>_> *)local_e4,in_ECX);
    }
    pppppbVar6 = local_2c;
    if (0xf < local_18) {
      pppppbVar6 = (byte *****)local_2c[0];
    }
    uVar4 = 0xb;
    if (uVar5 < 0xb) {
      uVar4 = uVar5;
    }
    if (uVar4 == 0) {
LAB_004ce8a1:
      if (uVar5 < 0xb) {
        uVar4 = 0xffffffff;
      }
      else {
        uVar4 = (uint)(uVar5 != 0xb);
      }
      bVar8 = uVar4 == 0;
    }
    else {
      pcVar7 = "resolutionX";
      while (uVar2 = uVar4 - 4, 3 < uVar4) {
        if (*pppppbVar6 != *(byte *****)pcVar7) goto LAB_004ce867;
        pppppbVar6 = pppppbVar6 + 1;
        pcVar7 = pcVar7 + 4;
        uVar4 = uVar2;
      }
      if (uVar2 == 0xfffffffc) {
LAB_004ce89b:
        uVar4 = 0;
      }
      else {
LAB_004ce867:
        bVar8 = *(byte *)pppppbVar6 < (byte)*pcVar7;
        if ((*(byte *)pppppbVar6 == *pcVar7) &&
           ((uVar2 == 0xfffffffd ||
            ((bVar8 = *(byte *)((int)pppppbVar6 + 1) < (byte)pcVar7[1],
             *(byte *)((int)pppppbVar6 + 1) == pcVar7[1] &&
             ((uVar2 == 0xfffffffe ||
              ((bVar8 = *(byte *)((int)pppppbVar6 + 2) < (byte)pcVar7[2],
               *(byte *)((int)pppppbVar6 + 2) == pcVar7[2] &&
               ((uVar2 == 0xffffffff ||
                (bVar8 = *(byte *)((int)pppppbVar6 + 3) < (byte)pcVar7[3],
                *(byte *)((int)pppppbVar6 + 3) == pcVar7[3])))))))))))) goto LAB_004ce89b;
        uVar4 = -(uint)bVar8 | 1;
      }
      bVar8 = false;
      if (uVar4 == 0) goto LAB_004ce8a1;
    }
    if (bVar8) {
      std::basic_istream<char,std::char_traits<char>_>::operator>>
                ((basic_istream<char,std::char_traits<char>_> *)local_e4,in_ECX + 1);
    }
    pppppbVar6 = local_2c;
    if (0xf < local_18) {
      pppppbVar6 = (byte *****)local_2c[0];
    }
    uVar4 = 0xb;
    if (uVar5 < 0xb) {
      uVar4 = uVar5;
    }
    if (uVar4 == 0) {
LAB_004ce940:
      if (uVar5 < 0xb) {
        uVar4 = 0xffffffff;
      }
      else {
        uVar4 = (uint)(uVar5 != 0xb);
      }
      bVar8 = uVar4 == 0;
    }
    else {
      pcVar7 = "resolutionY";
      while (uVar2 = uVar4 - 4, 3 < uVar4) {
        if (*pppppbVar6 != *(byte *****)pcVar7) goto LAB_004ce906;
        pppppbVar6 = pppppbVar6 + 1;
        pcVar7 = pcVar7 + 4;
        uVar4 = uVar2;
      }
      if (uVar2 == 0xfffffffc) {
LAB_004ce93a:
        uVar4 = 0;
      }
      else {
LAB_004ce906:
        bVar8 = *(byte *)pppppbVar6 < (byte)*pcVar7;
        if ((*(byte *)pppppbVar6 == *pcVar7) &&
           ((uVar2 == 0xfffffffd ||
            ((bVar8 = *(byte *)((int)pppppbVar6 + 1) < (byte)pcVar7[1],
             *(byte *)((int)pppppbVar6 + 1) == pcVar7[1] &&
             ((uVar2 == 0xfffffffe ||
              ((bVar8 = *(byte *)((int)pppppbVar6 + 2) < (byte)pcVar7[2],
               *(byte *)((int)pppppbVar6 + 2) == pcVar7[2] &&
               ((uVar2 == 0xffffffff ||
                (bVar8 = *(byte *)((int)pppppbVar6 + 3) < (byte)pcVar7[3],
                *(byte *)((int)pppppbVar6 + 3) == pcVar7[3])))))))))))) goto LAB_004ce93a;
        uVar4 = -(uint)bVar8 | 1;
      }
      bVar8 = false;
      if (uVar4 == 0) goto LAB_004ce940;
    }
    if (bVar8) {
      std::basic_istream<char,std::char_traits<char>_>::operator>>
                ((basic_istream<char,std::char_traits<char>_> *)local_e4,in_ECX + 2);
    }
    pppppbVar6 = local_2c;
    if (0xf < local_18) {
      pppppbVar6 = (byte *****)local_2c[0];
    }
    uVar4 = 0xc;
    if (uVar5 < 0xc) {
      uVar4 = uVar5;
    }
    if (uVar4 == 0) {
LAB_004ce9e0:
      if (uVar5 < 0xc) {
        uVar4 = 0xffffffff;
      }
      else {
        uVar4 = (uint)(uVar5 != 0xc);
      }
      bVar8 = uVar4 == 0;
    }
    else {
      pcVar7 = "antiAliasing";
      while (uVar2 = uVar4 - 4, 3 < uVar4) {
        if (*pppppbVar6 != *(byte *****)pcVar7) goto LAB_004ce9a6;
        pppppbVar6 = pppppbVar6 + 1;
        pcVar7 = pcVar7 + 4;
        uVar4 = uVar2;
      }
      if (uVar2 == 0xfffffffc) {
LAB_004ce9da:
        uVar4 = 0;
      }
      else {
LAB_004ce9a6:
        bVar8 = *(byte *)pppppbVar6 < (byte)*pcVar7;
        if ((*(byte *)pppppbVar6 == *pcVar7) &&
           ((uVar2 == 0xfffffffd ||
            ((bVar8 = *(byte *)((int)pppppbVar6 + 1) < (byte)pcVar7[1],
             *(byte *)((int)pppppbVar6 + 1) == pcVar7[1] &&
             ((uVar2 == 0xfffffffe ||
              ((bVar8 = *(byte *)((int)pppppbVar6 + 2) < (byte)pcVar7[2],
               *(byte *)((int)pppppbVar6 + 2) == pcVar7[2] &&
               ((uVar2 == 0xffffffff ||
                (bVar8 = *(byte *)((int)pppppbVar6 + 3) < (byte)pcVar7[3],
                *(byte *)((int)pppppbVar6 + 3) == pcVar7[3])))))))))))) goto LAB_004ce9da;
        uVar4 = -(uint)bVar8 | 1;
      }
      bVar8 = false;
      if (uVar4 == 0) goto LAB_004ce9e0;
    }
    if (bVar8) {
      std::basic_istream<char,std::char_traits<char>_>::operator>>
                ((basic_istream<char,std::char_traits<char>_> *)local_e4,in_ECX + 3);
    }
    pppppbVar6 = local_2c;
    if (0xf < local_18) {
      pppppbVar6 = (byte *****)local_2c[0];
    }
    uVar4 = 0xe;
    if (uVar5 < 0xe) {
      uVar4 = uVar5;
    }
    if (uVar4 == 0) {
LAB_004cea80:
      if (uVar5 < 0xe) {
        uVar4 = 0xffffffff;
      }
      else {
        uVar4 = (uint)(uVar5 != 0xe);
      }
      bVar8 = uVar4 == 0;
    }
    else {
      pcVar7 = "renderDistance";
      while (uVar2 = uVar4 - 4, 3 < uVar4) {
        if (*pppppbVar6 != *(byte *****)pcVar7) goto LAB_004cea46;
        pppppbVar6 = pppppbVar6 + 1;
        pcVar7 = pcVar7 + 4;
        uVar4 = uVar2;
      }
      if (uVar2 == 0xfffffffc) {
LAB_004cea7a:
        uVar4 = 0;
      }
      else {
LAB_004cea46:
        bVar8 = *(byte *)pppppbVar6 < (byte)*pcVar7;
        if ((*(byte *)pppppbVar6 == *pcVar7) &&
           ((uVar2 == 0xfffffffd ||
            ((bVar8 = *(byte *)((int)pppppbVar6 + 1) < (byte)pcVar7[1],
             *(byte *)((int)pppppbVar6 + 1) == pcVar7[1] &&
             ((uVar2 == 0xfffffffe ||
              ((bVar8 = *(byte *)((int)pppppbVar6 + 2) < (byte)pcVar7[2],
               *(byte *)((int)pppppbVar6 + 2) == pcVar7[2] &&
               ((uVar2 == 0xffffffff ||
                (bVar8 = *(byte *)((int)pppppbVar6 + 3) < (byte)pcVar7[3],
                *(byte *)((int)pppppbVar6 + 3) == pcVar7[3])))))))))))) goto LAB_004cea7a;
        uVar4 = -(uint)bVar8 | 1;
      }
      bVar8 = false;
      if (uVar4 == 0) goto LAB_004cea80;
    }
    if (bVar8) {
      std::basic_istream<char,std::char_traits<char>_>::operator>>
                ((basic_istream<char,std::char_traits<char>_> *)local_e4,in_ECX + 4);
    }
    pppppbVar6 = local_2c;
    if (0xf < local_18) {
      pppppbVar6 = (byte *****)local_2c[0];
    }
    uVar4 = 0xb;
    if (uVar5 < 0xb) {
      uVar4 = uVar5;
    }
    if (uVar4 == 0) {
LAB_004ceb20:
      if (uVar5 < 0xb) {
        uVar4 = 0xffffffff;
      }
      else {
        uVar4 = (uint)(uVar5 != 0xb);
      }
      bVar8 = uVar4 == 0;
    }
    else {
      pcVar7 = "soundVolume";
      while (uVar2 = uVar4 - 4, 3 < uVar4) {
        if (*pppppbVar6 != *(byte *****)pcVar7) goto LAB_004ceae6;
        pppppbVar6 = pppppbVar6 + 1;
        pcVar7 = pcVar7 + 4;
        uVar4 = uVar2;
      }
      if (uVar2 == 0xfffffffc) {
LAB_004ceb1a:
        uVar4 = 0;
      }
      else {
LAB_004ceae6:
        bVar8 = *(byte *)pppppbVar6 < (byte)*pcVar7;
        if ((*(byte *)pppppbVar6 == *pcVar7) &&
           ((uVar2 == 0xfffffffd ||
            ((bVar8 = *(byte *)((int)pppppbVar6 + 1) < (byte)pcVar7[1],
             *(byte *)((int)pppppbVar6 + 1) == pcVar7[1] &&
             ((uVar2 == 0xfffffffe ||
              ((bVar8 = *(byte *)((int)pppppbVar6 + 2) < (byte)pcVar7[2],
               *(byte *)((int)pppppbVar6 + 2) == pcVar7[2] &&
               ((uVar2 == 0xffffffff ||
                (bVar8 = *(byte *)((int)pppppbVar6 + 3) < (byte)pcVar7[3],
                *(byte *)((int)pppppbVar6 + 3) == pcVar7[3])))))))))))) goto LAB_004ceb1a;
        uVar4 = -(uint)bVar8 | 1;
      }
      bVar8 = false;
      if (uVar4 == 0) goto LAB_004ceb20;
    }
    if (bVar8) {
      std::basic_istream<char,std::char_traits<char>_>::operator>>
                ((basic_istream<char,std::char_traits<char>_> *)local_e4,in_ECX + 5);
    }
    pppppbVar6 = local_2c;
    if (0xf < local_18) {
      pppppbVar6 = (byte *****)local_2c[0];
    }
    uVar4 = 0xb;
    if (uVar5 < 0xb) {
      uVar4 = uVar5;
    }
    if (uVar4 == 0) {
LAB_004cebc0:
      if (uVar5 < 0xb) {
        uVar4 = 0xffffffff;
      }
      else {
        uVar4 = (uint)(uVar5 != 0xb);
      }
      bVar8 = uVar4 == 0;
    }
    else {
      pcVar7 = "musicVolume";
      while (uVar2 = uVar4 - 4, 3 < uVar4) {
        if (*pppppbVar6 != *(byte *****)pcVar7) goto LAB_004ceb86;
        pppppbVar6 = pppppbVar6 + 1;
        pcVar7 = pcVar7 + 4;
        uVar4 = uVar2;
      }
      if (uVar2 == 0xfffffffc) {
LAB_004cebba:
        uVar4 = 0;
      }
      else {
LAB_004ceb86:
        bVar8 = *(byte *)pppppbVar6 < (byte)*pcVar7;
        if ((*(byte *)pppppbVar6 == *pcVar7) &&
           ((uVar2 == 0xfffffffd ||
            ((bVar8 = *(byte *)((int)pppppbVar6 + 1) < (byte)pcVar7[1],
             *(byte *)((int)pppppbVar6 + 1) == pcVar7[1] &&
             ((uVar2 == 0xfffffffe ||
              ((bVar8 = *(byte *)((int)pppppbVar6 + 2) < (byte)pcVar7[2],
               *(byte *)((int)pppppbVar6 + 2) == pcVar7[2] &&
               ((uVar2 == 0xffffffff ||
                (bVar8 = *(byte *)((int)pppppbVar6 + 3) < (byte)pcVar7[3],
                *(byte *)((int)pppppbVar6 + 3) == pcVar7[3])))))))))))) goto LAB_004cebba;
        uVar4 = -(uint)bVar8 | 1;
      }
      bVar8 = false;
      if (uVar4 == 0) goto LAB_004cebc0;
    }
    if (bVar8) {
      std::basic_istream<char,std::char_traits<char>_>::operator>>
                ((basic_istream<char,std::char_traits<char>_> *)local_e4,in_ECX + 6);
    }
    pppppbVar6 = local_2c;
    if (0xf < local_18) {
      pppppbVar6 = (byte *****)local_2c[0];
    }
    uVar4 = 0xb;
    if (uVar5 < 0xb) {
      uVar4 = uVar5;
    }
    if (uVar4 == 0) {
LAB_004cec60:
      if (uVar5 < 0xb) {
        uVar4 = 0xffffffff;
      }
      else {
        uVar4 = (uint)(uVar5 != 0xb);
      }
      bVar8 = uVar4 == 0;
    }
    else {
      pcVar7 = "cameraSpeed";
      while (uVar2 = uVar4 - 4, 3 < uVar4) {
        if (*pppppbVar6 != *(byte *****)pcVar7) goto LAB_004cec26;
        pppppbVar6 = pppppbVar6 + 1;
        pcVar7 = pcVar7 + 4;
        uVar4 = uVar2;
      }
      if (uVar2 == 0xfffffffc) {
LAB_004cec5a:
        uVar4 = 0;
      }
      else {
LAB_004cec26:
        bVar8 = *(byte *)pppppbVar6 < (byte)*pcVar7;
        if ((*(byte *)pppppbVar6 == *pcVar7) &&
           ((uVar2 == 0xfffffffd ||
            ((bVar8 = *(byte *)((int)pppppbVar6 + 1) < (byte)pcVar7[1],
             *(byte *)((int)pppppbVar6 + 1) == pcVar7[1] &&
             ((uVar2 == 0xfffffffe ||
              ((bVar8 = *(byte *)((int)pppppbVar6 + 2) < (byte)pcVar7[2],
               *(byte *)((int)pppppbVar6 + 2) == pcVar7[2] &&
               ((uVar2 == 0xffffffff ||
                (bVar8 = *(byte *)((int)pppppbVar6 + 3) < (byte)pcVar7[3],
                *(byte *)((int)pppppbVar6 + 3) == pcVar7[3])))))))))))) goto LAB_004cec5a;
        uVar4 = -(uint)bVar8 | 1;
      }
      bVar8 = false;
      if (uVar4 == 0) goto LAB_004cec60;
    }
    if (bVar8) {
      std::basic_istream<char,std::char_traits<char>_>::operator>>
                ((basic_istream<char,std::char_traits<char>_> *)local_e4,in_ECX + 7);
    }
    pppppbVar6 = local_2c;
    if (0xf < local_18) {
      pppppbVar6 = (byte *****)local_2c[0];
    }
    uVar4 = 0x10;
    if (uVar5 < 0x10) {
      uVar4 = uVar5;
    }
    if (uVar4 == 0) {
LAB_004ced00:
      if (uVar5 < 0x10) {
        uVar4 = 0xffffffff;
      }
      else {
        uVar4 = (uint)(uVar5 != 0x10);
      }
      bVar8 = uVar4 == 0;
    }
    else {
      pcVar7 = "cameraSmoothness";
      while (uVar2 = uVar4 - 4, 3 < uVar4) {
        if (*pppppbVar6 != *(byte *****)pcVar7) goto LAB_004cecc6;
        pppppbVar6 = pppppbVar6 + 1;
        pcVar7 = pcVar7 + 4;
        uVar4 = uVar2;
      }
      if (uVar2 == 0xfffffffc) {
LAB_004cecfa:
        uVar4 = 0;
      }
      else {
LAB_004cecc6:
        bVar8 = *(byte *)pppppbVar6 < (byte)*pcVar7;
        if ((*(byte *)pppppbVar6 == *pcVar7) &&
           ((uVar2 == 0xfffffffd ||
            ((bVar8 = *(byte *)((int)pppppbVar6 + 1) < (byte)pcVar7[1],
             *(byte *)((int)pppppbVar6 + 1) == pcVar7[1] &&
             ((uVar2 == 0xfffffffe ||
              ((bVar8 = *(byte *)((int)pppppbVar6 + 2) < (byte)pcVar7[2],
               *(byte *)((int)pppppbVar6 + 2) == pcVar7[2] &&
               ((uVar2 == 0xffffffff ||
                (bVar8 = *(byte *)((int)pppppbVar6 + 3) < (byte)pcVar7[3],
                *(byte *)((int)pppppbVar6 + 3) == pcVar7[3])))))))))))) goto LAB_004cecfa;
        uVar4 = -(uint)bVar8 | 1;
      }
      bVar8 = false;
      if (uVar4 == 0) goto LAB_004ced00;
    }
    if (bVar8) {
      std::basic_istream<char,std::char_traits<char>_>::operator>>
                ((basic_istream<char,std::char_traits<char>_> *)local_e4,in_ECX + 8);
    }
    pppppbVar6 = local_2c;
    if (0xf < local_18) {
      pppppbVar6 = (byte *****)local_2c[0];
    }
    uVar4 = 8;
    if (uVar5 < 8) {
      uVar4 = uVar5;
    }
    if (uVar4 == 0) {
LAB_004ceda0:
      if (uVar5 < 8) {
        uVar4 = 0xffffffff;
      }
      else {
        uVar4 = (uint)(uVar5 != 8);
      }
      bVar8 = uVar4 == 0;
    }
    else {
      pcVar7 = "language";
      while (uVar2 = uVar4 - 4, 3 < uVar4) {
        if (*pppppbVar6 != *(byte *****)pcVar7) goto LAB_004ced66;
        pppppbVar6 = pppppbVar6 + 1;
        pcVar7 = pcVar7 + 4;
        uVar4 = uVar2;
      }
      if (uVar2 == 0xfffffffc) {
LAB_004ced9a:
        uVar4 = 0;
      }
      else {
LAB_004ced66:
        bVar8 = *(byte *)pppppbVar6 < (byte)*pcVar7;
        if ((*(byte *)pppppbVar6 == *pcVar7) &&
           ((uVar2 == 0xfffffffd ||
            ((bVar8 = *(byte *)((int)pppppbVar6 + 1) < (byte)pcVar7[1],
             *(byte *)((int)pppppbVar6 + 1) == pcVar7[1] &&
             ((uVar2 == 0xfffffffe ||
              ((bVar8 = *(byte *)((int)pppppbVar6 + 2) < (byte)pcVar7[2],
               *(byte *)((int)pppppbVar6 + 2) == pcVar7[2] &&
               ((uVar2 == 0xffffffff ||
                (bVar8 = *(byte *)((int)pppppbVar6 + 3) < (byte)pcVar7[3],
                *(byte *)((int)pppppbVar6 + 3) == pcVar7[3])))))))))))) goto LAB_004ced9a;
        uVar4 = -(uint)bVar8 | 1;
      }
      bVar8 = false;
      if (uVar4 == 0) goto LAB_004ceda0;
    }
    if (bVar8) {
      std::basic_istream<char,std::char_traits<char>_>::operator>>
                ((basic_istream<char,std::char_traits<char>_> *)local_e4,in_ECX + 10);
    }
    pppppbVar6 = local_2c;
    if (0xf < local_18) {
      pppppbVar6 = (byte *****)local_2c[0];
    }
    uVar4 = 7;
    if (uVar5 < 7) {
      uVar4 = uVar5;
    }
    if (uVar4 == 0) {
LAB_004cee40:
      if (uVar5 < 7) {
        uVar4 = 0xffffffff;
      }
      else {
        uVar4 = (uint)(uVar5 != 7);
      }
      bVar8 = uVar4 == 0;
    }
    else {
      pcVar7 = "invertY";
      while (uVar2 = uVar4 - 4, 3 < uVar4) {
        if (*pppppbVar6 != *(byte *****)pcVar7) goto LAB_004cee06;
        pppppbVar6 = pppppbVar6 + 1;
        pcVar7 = pcVar7 + 4;
        uVar4 = uVar2;
      }
      if (uVar2 == 0xfffffffc) {
LAB_004cee3a:
        uVar4 = 0;
      }
      else {
LAB_004cee06:
        bVar8 = *(byte *)pppppbVar6 < (byte)*pcVar7;
        if ((*(byte *)pppppbVar6 == *pcVar7) &&
           ((uVar2 == 0xfffffffd ||
            ((bVar8 = *(byte *)((int)pppppbVar6 + 1) < (byte)pcVar7[1],
             *(byte *)((int)pppppbVar6 + 1) == pcVar7[1] &&
             ((uVar2 == 0xfffffffe ||
              ((bVar8 = *(byte *)((int)pppppbVar6 + 2) < (byte)pcVar7[2],
               *(byte *)((int)pppppbVar6 + 2) == pcVar7[2] &&
               ((uVar2 == 0xffffffff ||
                (bVar8 = *(byte *)((int)pppppbVar6 + 3) < (byte)pcVar7[3],
                *(byte *)((int)pppppbVar6 + 3) == pcVar7[3])))))))))))) goto LAB_004cee3a;
        uVar4 = -(uint)bVar8 | 1;
      }
      bVar8 = false;
      if (uVar4 == 0) goto LAB_004cee40;
    }
    if (bVar8) {
      std::basic_istream<char,std::char_traits<char>_>::operator>>
                ((basic_istream<char,std::char_traits<char>_> *)local_e4,in_ECX + 9);
    }
    pppppbVar6 = local_2c;
    if (0xf < local_18) {
      pppppbVar6 = (byte *****)local_2c[0];
    }
    uVar4 = 0xb;
    if (uVar5 < 0xb) {
      uVar4 = uVar5;
    }
    if (uVar4 == 0) {
LAB_004ceee0:
      if (uVar5 < 0xb) {
        uVar5 = 0xffffffff;
      }
      else {
        uVar5 = (uint)(uVar5 != 0xb);
      }
      bVar8 = uVar5 == 0;
    }
    else {
      pcVar7 = "minTimeStep";
      while (uVar2 = uVar4 - 4, 3 < uVar4) {
        if (*pppppbVar6 != *(byte *****)pcVar7) goto LAB_004ceea6;
        pppppbVar6 = pppppbVar6 + 1;
        pcVar7 = pcVar7 + 4;
        uVar4 = uVar2;
      }
      if (uVar2 == 0xfffffffc) {
LAB_004ceeda:
        uVar4 = 0;
      }
      else {
LAB_004ceea6:
        bVar8 = *(byte *)pppppbVar6 < (byte)*pcVar7;
        if ((*(byte *)pppppbVar6 == *pcVar7) &&
           ((uVar2 == 0xfffffffd ||
            ((bVar8 = *(byte *)((int)pppppbVar6 + 1) < (byte)pcVar7[1],
             *(byte *)((int)pppppbVar6 + 1) == pcVar7[1] &&
             ((uVar2 == 0xfffffffe ||
              ((bVar8 = *(byte *)((int)pppppbVar6 + 2) < (byte)pcVar7[2],
               *(byte *)((int)pppppbVar6 + 2) == pcVar7[2] &&
               ((uVar2 == 0xffffffff ||
                (bVar8 = *(byte *)((int)pppppbVar6 + 3) < (byte)pcVar7[3],
                *(byte *)((int)pppppbVar6 + 3) == pcVar7[3])))))))))))) goto LAB_004ceeda;
        uVar4 = -(uint)bVar8 | 1;
      }
      bVar8 = false;
      if (uVar4 == 0) goto LAB_004ceee0;
    }
    if (bVar8) {
      std::basic_istream<char,std::char_traits<char>_>::operator>>
                ((basic_istream<char,std::char_traits<char>_> *)local_e4,in_ECX + 0xb);
    }
    local_8._0_1_ = 0;
    if (0xf < local_18) {
                    /* WARNING: Subroutine does not return */
      operator_delete(local_2c[0]);
    }
    iVar1 = *(int *)((int)aiStack_d8 + *(int *)(local_e4[0] + 4));
  } while( true );
}




/* Global::FUN_00639390 @ 00639390 */

void FUN_00639390(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 0x1c);
  iVar2 = map_insertVal_strKey(iVar1,*(undefined4 *)(iVar1 + 4),param_1);
  if (*(int *)(in_ECX + 0x20) == 0x7fffffe) {
                    /* WARNING: Subroutine does not return */
    std::_Xlength_error("list<T> too long");
  }
  *(int *)(in_ECX + 0x20) = *(int *)(in_ECX + 0x20) + 1;
  *(int *)(iVar1 + 4) = iVar2;
  **(int **)(iVar2 + 4) = iVar2;
  return;
}




/* Global::FUN_00659d70 @ 00659d70 */

void FUN_00659d70(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 char param_5)

{
  int *piVar1;
  int in_ECX;
  int *piVar2;
  
  *(undefined4 *)(in_ECX + 0x104) = param_1;
  *(undefined4 *)(in_ECX + 0x108) = param_2;
  *(undefined4 *)(in_ECX + 0x10c) = param_3;
  *(undefined4 *)(in_ECX + 0x110) = param_4;
  if ((param_5 != '\0') &&
     (piVar2 = (int *)**(int **)(in_ECX + 0x7c), piVar2 != *(int **)(in_ECX + 0x7c))) {
    _param_5 = 1;
    do {
      (**(code **)(*(int *)piVar2[2] + 0x20))();
      piVar1 = (int *)rbtree_findOrInsert_intKey(&param_5);
      if ((undefined4 *)*piVar1 != (undefined4 *)0x0) {
        (*(code *)**(undefined4 **)*piVar1)();
      }
      piVar2 = (int *)*piVar2;
    } while (piVar2 != (int *)*(int *)(in_ECX + 0x7c));
  }
  return;
}




/* plasma::D3D9Engine::ctor_1 @ 006887a0 */

void plasma::D3D9Engine::ctor_1(undefined4 param_1)

{
  undefined4 uVar1;
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_006f9284;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  ObjectManager::ctor_1(DAT_0076aa78 ^ (uint)&stack0xfffffffc);
  *in_ECX = vftable;
  in_ECX[0x65] = 0;
  in_ECX[0x66] = 0;
  in_ECX[0x68] = 0;
  in_ECX[0x69] = 0;
  in_ECX[0x6a] = 0;
  in_ECX[0x6b] = 0;
  in_ECX[0x6c] = 0;
  in_ECX[0x6d] = 0;
  in_ECX[0x6e] = 0;
  in_ECX[0xa9] = 0x3f333333;
  local_8 = 0;
  in_ECX[0xaa] = 0;
  in_ECX[0xab] = 0;
  uVar1 = list_allocNode(0,0);
  in_ECX[0xaa] = uVar1;
  local_8._0_1_ = 1;
  in_ECX[0xac] = 0;
  in_ECX[0xad] = 0;
  uVar1 = list_allocNode(0,0);
  in_ECX[0xac] = uVar1;
  local_8 = CONCAT31(local_8._1_3_,2);
  in_ECX[0xae] = 0;
  in_ECX[0xaf] = 0;
  uVar1 = list_buyNode_0c(0,0);
  in_ECX[0xae] = uVar1;
  in_ECX[0xb0] = param_1;
  in_ECX[0xb1] = 0;
  in_ECX[0xb2] = 0;
  ExceptionList = local_10;
  return;
}




/* Global::FUN_0068a6b0 @ 0068a6b0 */

void FUN_0068a6b0(void)

{
  int in_ECX;
  int *piVar1;
  
  if (*(int *)(in_ECX + 0x2c4) == 0) {
    (**(code **)(**(int **)(in_ECX + 0x2c0) + 0x68))
              (*(int **)(in_ECX + 0x2c0),0xc0,0x208,0,0,in_ECX + 0x2c4,0);
  }
  piVar1 = (int *)**(int **)(in_ECX + 0x2b8);
  if (piVar1 != *(int **)(in_ECX + 0x2b8)) {
    do {
      FUN_0068b6a0();
      piVar1 = (int *)*piVar1;
    } while (piVar1 != (int *)*(int *)(in_ECX + 0x2b8));
  }
  return;
}




/* Global::FUN_0068a710 @ 0068a710 */

void FUN_0068a710(void)

{
  int in_ECX;
  int iVar1;
  int *piVar2;
  
  piVar2 = *(int **)(in_ECX + 0x2c4);
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 8))(piVar2);
    *(undefined4 *)(in_ECX + 0x2c4) = 0;
  }
  iVar1 = 0;
  if (0 < (int)(*(int *)(in_ECX + 0x3c) - *(int *)(in_ECX + 0x38) & 0xfffffffcU)) {
    do {
      Object_release_if_nonnull(*(undefined4 *)(*(int *)(in_ECX + 0x38) + iVar1 * 4));
      iVar1 = iVar1 + 1;
    } while (iVar1 < *(int *)(in_ECX + 0x3c) - *(int *)(in_ECX + 0x38) >> 2);
  }
  *(undefined4 *)(in_ECX + 0x3c) = *(undefined4 *)(in_ECX + 0x38);
  piVar2 = (int *)**(int **)(in_ECX + 0x7c);
  if (piVar2 != *(int **)(in_ECX + 0x7c)) {
    do {
      if ((*(int *)(piVar2[2] + 0x3c) != 0) &&
         (iVar1 = __RTDynamicCast(*(int *)(piVar2[2] + 0x3c),0,
                                  &plasma::RenderSurface::RTTI_Type_Descriptor,
                                  &plasma::D3D9RenderSurface::RTTI_Type_Descriptor,0), iVar1 != 0))
      {
        FUN_0068d300();
      }
      piVar2 = (int *)*piVar2;
    } while (piVar2 != (int *)*(int *)(in_ECX + 0x7c));
  }
  piVar2 = (int *)**(int **)(in_ECX + 0x2b8);
  if (piVar2 != *(int **)(in_ECX + 0x2b8)) {
    do {
      FUN_0068ab30();
      piVar2 = (int *)*piVar2;
    } while (piVar2 != (int *)*(int *)(in_ECX + 0x2b8));
  }
  Object_release_if_nonnull(*(undefined4 *)(in_ECX + 0x44));
  *(undefined4 *)(in_ECX + 0x44) = 0;
  return;
}




/* Global::FUN_0068ab30 @ 0068ab30 */

void FUN_0068ab30(void)

{
  int *piVar1;
  int in_ECX;
  
  piVar1 = *(int **)(in_ECX + 0x128);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    *(undefined4 *)(in_ECX + 0x128) = 0;
  }
  piVar1 = *(int **)(in_ECX + 300);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    *(undefined4 *)(in_ECX + 300) = 0;
  }
  return;
}




/* Global::FUN_0068b6a0 @ 0068b6a0 */

void FUN_0068b6a0(void)

{
  undefined4 *puVar1;
  int *piVar2;
  void *in_ECX;
  void *local_8;
  
  local_8 = in_ECX;
  if ((*(int *)((int)in_ECX + 0x130) != 0) &&
     (puVar1 = (undefined4 *)((int)in_ECX + 0x128), *(int *)((int)in_ECX + 0x128) == 0)) {
    piVar2 = *(int **)(*(int *)((int)in_ECX + 0x124) + 0x2c0);
    (**(code **)(*piVar2 + 0x68))
              (piVar2,(*(int *)((int)in_ECX + 200) - *(int *)((int)in_ECX + 0xc4) >> 3) * 0x30,0x208
               ,0,0,puVar1,0);
    (**(code **)(*(int *)*puVar1 + 0x2c))
              ((int *)*puVar1,0,
               (*(int *)((int)in_ECX + 200) - *(int *)((int)in_ECX + 0xc4) >> 3) * 0x30,&local_8,
               0x2000);
    memcpy(local_8,*(void **)((int)in_ECX + 0x130),
           (*(int *)((int)in_ECX + 200) - *(int *)((int)in_ECX + 0xc4) >> 3) * 0x30);
    (**(code **)(*(int *)*puVar1 + 0x30))((int *)*puVar1);
  }
  if ((*(int *)((int)in_ECX + 0x134) != 0) &&
     (puVar1 = (undefined4 *)((int)in_ECX + 300), *(int *)((int)in_ECX + 300) == 0)) {
    piVar2 = *(int **)(*(int *)((int)in_ECX + 0x124) + 0x2c0);
    (**(code **)(*piVar2 + 0x6c))
              (piVar2,*(int *)((int)in_ECX + 0xf8) - *(int *)((int)in_ECX + 0xf4) & 0xfffffffc,0x208
               ,0x66,0,puVar1,0);
    (**(code **)(*(int *)*puVar1 + 0x2c))
              ((int *)*puVar1,0,
               *(int *)((int)in_ECX + 0xf8) - *(int *)((int)in_ECX + 0xf4) & 0xfffffffc,&local_8,
               0x2000);
    memcpy(local_8,*(void **)((int)in_ECX + 0x134),
           *(int *)((int)in_ECX + 0xf8) - *(int *)((int)in_ECX + 0xf4) & 0xfffffffc);
    (**(code **)(*(int *)*puVar1 + 0x30))((int *)*puVar1);
  }
  return;
}




/* Global::FUN_0068d300 @ 0068d300 */

void FUN_0068d300(void)

{
  int *piVar1;
  int in_ECX;
  
  piVar1 = *(int **)(in_ECX + 0x40);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    *(undefined4 *)(in_ECX + 0x40) = 0;
  }
  piVar1 = *(int **)(in_ECX + 0x3c);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    *(undefined4 *)(in_ECX + 0x3c) = 0;
  }
  piVar1 = *(int **)(in_ECX + 0x38);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    *(undefined4 *)(in_ECX + 0x38) = 0;
  }
  return;
}




