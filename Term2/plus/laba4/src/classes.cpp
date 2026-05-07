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
      } else if (dmg < 0/*heal is -dmg*/){
         Hp -= dmg;
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

class cleric : public unit{
protected:
   int mainStat = 2; // wisdon of cleric

   void heal(
         int healrate,
         int flatheal/*+ ваш модификатор базовой характеристики. */,
         unit& target
         )
   {
      int healVal = rand()%healrate + 1;
      healVal = healVal * -1;/*heal is -dmg*/
      target.getDmg(0, healVal); // ckep hitrate check when (dmg <= 0)
   }

public:
   void Healing_word(unit& target){
      heal(4, mainStat, target);
   }

   void cure_wounds(unit& target){
      heal(8, mainStat, target);
   }
};
