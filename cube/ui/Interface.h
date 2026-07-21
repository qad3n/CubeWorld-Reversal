// Interface (cube) — reconstructed declarations.
#ifndef CUBE_UI_INTERFACE_H
#define CUBE_UI_INTERFACE_H
#include "../include/cube_types.h"

void std_wstring_Tidy(char param_1,int param_2);
void cube::Interface::drawCharacterCreation(void);
void cube::Interface::drawCharacterStatsPanel(void);
float10 stat_calcArmor(void);
float10 Creature_compute_scale_factor(void);
float10 stat_calcManaRegen(void);
float10 Equipment_sum_slot_values(void);
float10 stat_calcSpirit(void);
void cube::Interface::drawMerchantDialog(void);
void cube::Interface::drawOptionsMenu(void);

#endif
