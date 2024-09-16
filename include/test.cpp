#include <iostream>
#include <ostream>
#include "Bar.hpp"
#include <chrono>
#include <thread>
using namespace loadingBar;
using namespace std;

int main(){
  bar b;
  b.set_fg_color(Color::FG_GREEN);
  b.set_bg_color(Color::BG_DEFAULT);
  while(!b.is_complete()){
        // Print the initial line
        b.print_bar();
        // Simulate some processing delay
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        b.flush();    
        b.add_progress();
        // Clear the line
    }
  
}

