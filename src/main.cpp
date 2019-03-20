#include "lab5_lib.h"

int main(){
  Deanery dean("../data/grouplist.txt");
  //std::cout << "calling output method...\n";
  dean.add_marks(5);
  /*dean.console_output();
  std::cout << "\n";
  std::cout << "printing stats..." << '\n';
  dean.stats();*/
  dean.transfer("Ernesto Roy", "PMI3");
  dean.transfer("Albert Bates", "PMI2");
  /*std::cout << "\n";
  dean.console_output();
  std::cout << "\n";
  dean.stats();
  std::cout << "\n";*/
  dean.expell_unsuccesfull(3.0);
  std::cout << "\n";
  dean.console_output();
  std::cout << "\n";
  dean.stats();
  dean.update_files("../data/updated.txt");
  return 0;
}
