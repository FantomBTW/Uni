#pragma once

#include <raylib.h>

class unit{
protected:
   bool isAlive = 1;
   int Hp;
   int dmgDice;
   int def;
   Vector2 pos;

   void attack(unit& target);
public:
   unit(int HP, int dmg, int defend, Vector2 posVal);;

   unit(const unit& newcl);

   ~unit(){};

   void getDmg(int hit, int dmg);

   void move(Vector2 mv);

   Vector2 getpos();
};

class cleric : public unit{
private:
   void heal(unit& target);
public:
   void Healing_word();
   void cure_wounds(unit& target);
};
