#pragma once

#include <raylib.h>
#include <cstdlib>

class unit{
protected:
   bool isAlive = 1;
   int Hp;
   int dmgDice;
   int def;
   Vector2 pos;

   void attack(unit& target){
      int hitrate = rand()%20 + 1;
      int dmg = rand()%dmgDice + 1;
      target.getDmg(hitrate, dmg);
   }
public:
   unit(int HP, int dmg, int defend, Vector2 posVal){
      Hp = HP;
      dmgDice = dmg;
      def = defend;
      pos = posVal;
   };

   unit(const unit& newcl){
      Hp = newcl.Hp;
      dmgDice = newcl.dmgDice;
      def = newcl.def;
   };

   ~unit(){};

   void getDmg(int hit, int dmg){
      if (hit >= def){
         if (dmg > Hp) {
            isAlive = 0;
            Hp = 0;
         } else {
            Hp -= dmg;
         };
      }
   }

   void move(Vector2 mv){
      pos.x += mv.x;
      pos.y += mv.y;
   }

   Vector2 getpos(){
      return pos;
   }
};

/*
class cleric : public unit{
public:

};
*/
