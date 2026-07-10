// Database (db) — cube. 3 functions. Bodies = Ghidra pseudo-C.
#include "Database.h"

/* cube::Database::ctor_1 @ 00449380 */

void cube::Database::ctor_1(void)

{
  undefined4 *self;
  
  *self = vftable;
  self[1] = 0;
  return;
}




/* cube::Database::ctor_0 @ 00449390 */

void cube::Database::ctor_0(void)

{
  undefined4 *self;
  
  *self = vftable;
  if (self[1] != 0) {
    sqlite3_close(self[1]);
    self[1] = 0;
  }
  return;
}




/* cube::Database::vfunc_0 @ 004493c0 */

void cube::Database::vfunc_0(byte deleteFlag)

{
  undefined4 *self;
  
  *self = vftable;
  if (self[1] != 0) {
    sqlite3_close(self[1]);
    self[1] = 0;
  }
  if ((deleteFlag & 1) != 0) {
    operator_delete(self);
  }
  return;
}




