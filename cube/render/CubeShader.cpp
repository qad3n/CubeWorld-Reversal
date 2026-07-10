// CubeShader (render) — cube. 3 functions. Bodies = Ghidra pseudo-C.
#include "CubeShader.h"

/* cube::CubeShader::ctor_1 @ 00447c20 */

void cube::CubeShader::ctor_1(undefined4 device)

{
  undefined4 *self;
  
  self[7] = device;
  *self = vftable;
  self[1] = 0;
  self[2] = 0;
  self[3] = 0;
  self[4] = 0;
  self[5] = 0;
  self[6] = 0;
  self[8] = 0;
  return;
}




/* cube::CubeShader::ctor_0 @ 00447c70 */

void cube::CubeShader::ctor_0(void)

{
  int *resource;
  undefined4 *self;
  
  resource = (int *)self[1];
  *self = vftable;
  if (resource != (int *)0x0) {
    (**(code **)(*resource + 8))(resource);
  }
  resource = (int *)self[2];
  if (resource != (int *)0x0) {
    (**(code **)(*resource + 8))(resource);
  }
  resource = (int *)self[5];
  if (resource != (int *)0x0) {
    (**(code **)(*resource + 8))(resource);
  }
  resource = (int *)self[3];
  if (resource != (int *)0x0) {
    (**(code **)(*resource + 8))(resource);
  }
  resource = (int *)self[4];
  if (resource != (int *)0x0) {
    (**(code **)(*resource + 8))(resource);
  }
  resource = (int *)self[6];
  if (resource != (int *)0x0) {
    (**(code **)(*resource + 8))(resource);
  }
  resource = (int *)self[8];
  if (resource != (int *)0x0) {
    (**(code **)(*resource + 8))(resource);
  }
  return;
}




/* cube::CubeShader::vfunc_0 @ 00447ce0 */

void cube::CubeShader::vfunc_0(byte deleteFlag)

{
  void *self;
  
  ctor_0();
  if ((deleteFlag & 1) != 0) {
    operator_delete(self);
  }
  return;
}




