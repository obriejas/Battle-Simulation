#include "battle.hpp"
using namespace std;




int main(){
  srand(time(NULL));
  int p1_choice,p2_choice;
  hero* p1;
  hero* p2;
  cout << "WELOME TO THE BATTLE SIMULATION MAKER 3000 EXTRVAGANZA" << endl;
  cout << "PLAYER ONE: CHOOSE YOUR FIGHTER" << endl << "(1) Barbarian" << endl << "(2) Medusa" << endl << "(3) Blue Men" << endl << "(4) Hydra" << endl;
  cin >> p1_choice;
  cout << "PLAYER TWO: CHOOSE YOUR FIGHTER" << endl << "(1) Barbarian" << endl << "(2) Medusa" << endl << "(3) Blue Men" << endl << "(4) Hydra" << endl;
  cin >> p2_choice;
  cin.ignore();
  cin.clear();

  switch (p1_choice) {
    case 1:
      p1 = new barbarian;
      break;
    case 2:
      p1 = new medusa;
      break;
    case 3:
      p1 = new blue_men;
      break;
    case 4:
      p1 = new hydra;
      break;
    default:
      p1 = new barbarian;
      break;
  }
  switch (p2_choice) {
    case 1:
      p2 = new barbarian;
      break;
    case 2:
      p2 = new medusa;
      break;
    case 3:
      p2 = new blue_men;
      break;
    case 4:
      p2 = new hydra;
      break;
    default:
      p2 = new barbarian;
      break;
  }

  while((p1->get_hit_points() > 0) and (p2->get_hit_points() > 0)){
    p2->defend(p1->attack());
    if(p2->get_hit_points() <= 0){
      break;
    }
    cout << "Press ENTER to continue." << endl;
    cin.get();
    p1->defend(p2->attack());
    if(p1->get_hit_points() <= 0){
      break;
    }
    cout << "Press ENTER to continue." << endl;
    cin.get();
  }
  if(p1->get_hit_points() <=0){
    cout << p2->get_name() << " WINS!" << endl;
  }else{
    cout << p1->get_name() << " WINS!" << endl;
  }
  return 0;
}
