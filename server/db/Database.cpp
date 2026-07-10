// Database (db) — server. 3 functions. Bodies = Ghidra pseudo-C.
#include "Database.h"

/* cube::Database::ctor_1 @ 00412940 */

undefined4 * __fastcall cube::Database::ctor_1(undefined4 *self)

{
  *self = vftable;
  self[1] = 0;
  return self;
}




/* cube::Database::ctor_0 @ 00412950 */

void __fastcall cube::Database::ctor_0(undefined4 *self)

{
  *self = vftable;
  if ((int *)self[1] != (int *)0x0) {
    sqlite3_close((int *)self[1]);
    self[1] = 0;
  }
  return;
}




/* cube::Database::vfunc_0 @ 00412ac0 */

undefined4 * __thiscall cube::Database::vfunc_0(Database *this,byte delete_flag)

{
  *(undefined ***)this = vftable;
  if (*(int **)(this + 4) != (int *)0x0) {
    sqlite3_close(*(int **)(this + 4));
    *(undefined4 *)(this + 4) = 0;
  }
  if ((delete_flag & 1) != 0) {
    operator_delete(this);
  }
  return (undefined4 *)this;
}




