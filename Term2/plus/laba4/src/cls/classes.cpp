#include "classes.hpp"
#include <raylib.h>
#include <cstdlib>

void unit::attack(unit& target){
   int hitrate = rand()%20 + 1;
   int dmg = rand()%dmgDice + 1;
   target.getDmg(hitrate, dmg);
}

unit::unit(int HP, int dmg, int defend, Vector2 posVal){
   Hp = HP;
   dmgDice = dmg;
   def = defend;
   pos = posVal;
};

unit::unit(const unit& newcl){
   Hp = newcl.Hp;
   dmgDice = newcl.dmgDice;
   def = newcl.def;
};

unit::~unit(){};

void unit::getDmg(int hit, int dmg){
   if (hit >= def){
      if (dmg > Hp) {
         isAlive = 0;
         Hp = 0;
      } else {
         Hp -= dmg;
      };
   } else if (dmg < 0/*heal is -dmg*/){
      Hp -= dmg;
   }
}

void unit::move(Vector2 mv){
   pos.x += mv.x;
   pos.y += mv.y;
}

Vector2 unit::getpos(){
   return pos;
}


void cleric::heal(
      int healrate,
      int flatheal/*+ ваш модификатор базовой характеристики. */,
      unit& target
      )
{
   int healVal = rand()%healrate + 1;
   healVal = healVal * -1;/*heal is -dmg*/
   target.getDmg(0, healVal); // ckep hitrate check when (dmg <= 0)
}

void cleric::Healing_word(unit& target){
   heal(4, mainStat, target);
}

void cleric::cure_wounds(unit& target){
   heal(8, mainStat, target);
}

