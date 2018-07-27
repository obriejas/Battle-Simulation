#include <iostream>
#include "hero.hpp"
using namespace std;

int roll(int dice, int sides){
  int total = 0;
  for(int i=0; i < dice; i++){
    total = total + (rand() % sides + 1);
  }
  return total;
}
