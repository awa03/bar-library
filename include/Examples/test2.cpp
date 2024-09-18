// Single Iteration Example For Scripting

#include <cstddef>
#include <iostream>
#include "../Bar.hpp"

using namespace std;
using namespace loadingBar;

int main(int argc, char* argv[]){
  if(argc < 2){
    cout << "Usage: example2.x {width} {progress}";
  }

  bar b;
  b.flush();

  int w = stoi(argv[1]);
  int p = stoi(argv[2]);

  b.set_width(w);
  b.set_progress(p);
  b.print_bar();
}
