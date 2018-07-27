#ifndef HERO_HPP
#define HERO_HPP


#include <iostream>
#include "battle.hpp"
#include <string>
using namespace std;

int roll(int, int);

class hero{
protected:
  int attack_dice;
  int attack_sides;
  int defence_dice;
  int defence_sides;
  int armour;
  int hit_points;
  string name;

public:
  int get_hit_points(){
    return hit_points;
  }
  void set_hit_points(int hp){
    hit_points = hp;
  }
  int get_attack_dice(){
    return attack_dice;
  }
  string get_name(){
    return name;
  }
  void set_attack_dice(int new_dice){
    attack_dice = new_dice;
  }
  hero(int a,int b,int c,int d,int e,int f, string g){
    attack_dice = a;
    attack_sides = b;
    defence_dice = c;
    defence_sides = d;
    armour = e;
    hit_points = f;
    name = g;
  }

  virtual int attack(){
    int attack;
    attack = roll(attack_dice, attack_sides);
    cout << get_name() << "'s ATTACK DOES " << attack << " DAMAGE!!!" << endl;
    return attack;
  }
  virtual void defend(int attack_dmg){
    int defense;
    defense = (roll(defence_dice,defence_sides));
    cout << get_name() << "'s DEFENDED " << defense << " POINTS!" << endl;
    if((defense+armour) > attack_dmg){
      cout << get_name() << "'s DEFENSE WAS SUPERIOR!" << endl;
      cout << "No Damage Was Taken" << endl;
    } else {
    int damage = attack_dmg - defense - armour;
    int new_life = (get_hit_points() - damage);
    cout << get_name() << " took " << damage << " points of damage..." << endl;
    cout << get_name() << "'s current hp is at " << new_life << "." << endl;
    set_hit_points(new_life);
  }
  }
};


class barbarian : public hero {
public:

  barbarian() : hero(2,6,2,6,0,12,"Barbarian"){}
};

class medusa : public hero {
public:
  medusa() : hero(2,6,1,6,3,8,"Medusa"){}

  virtual int attack(){
    int attack;
    attack = roll(attack_dice,attack_sides);
    if(attack == 12){
      cout << "YOU LOOKED INTO MEDUSA'S EYES AND HAVE TURNED TO STONE!!!!" << endl;
      attack = 1000000;
    }
    cout << get_name() << "'s ATTACK DOES " << attack << " DAMAGE!!!" << endl;
    return attack;
  }
};

class blue_men : public hero {
public:
  blue_men() : hero(2,10,3,6,3,12,"Blue Men"){}
};

class hydra : public hero {
public:
  hydra() : hero(1,6,1,6,3,12,"Hydra"){}

  virtual void defend(int attack_dmg){
    int defense;
    defense = (roll(defence_dice,defence_sides));
    cout << get_name() << " DEFENDED " << defense << " POINTS!" << endl;

    int head =roll(1,5);
    if(head == 1){
      cout << get_name() << "HAS CUT OFF THE HYDRA'S HEAD AND 2 GREW IN ITS PLACE!" << endl;
      set_attack_dice((get_attack_dice() + 1));
    }

    if((defense+armour) > attack_dmg){
      cout << get_name() << "'s DEFENSE WAS SUPERIOR!" << endl;
      cout << "No Damage Was Taken" << endl;
    } else {
    int damage = attack_dmg - defense - armour;
    int new_life = (get_hit_points() - damage);
    cout << get_name() << " took " << damage << " points of damage..." << endl;
    cout << get_name() << "'s current hp is at " << new_life << "." << endl;
    set_hit_points(new_life);
  }
  }
};

#endif
