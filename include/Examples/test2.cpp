// Single Iteration Example For Scripting

#include <cstddef>
#include <iostream>
#include "../Bar.hpp"

using namespace std;
using namespace loadingBar;

int main(int argc, char* argv[]){
  if(argc < 3){
    cout << "Usage: example2.x {width} {height} {progress}";
  }

  bar b;
  b.flush();

  int w = stoi(argv[1]);
  int h = stoi(argv[2]);
  int p = stoi(argv[3]);

  b.set_width(w);
  b.set_height(h);
  b.set_progress(p);
  b.print_bar();
}
