#include <iostream>
#include <ostream>
#include "../Bar.hpp"
#include <chrono>
#include <thread>
using namespace loadingBar;
using namespace std;

int main(){
  bar b;
  b.set_fg_color(Color::FG_BLACK);
  b.set_bg_color(Color::BG_WHITE);
  b.set_width(100);
  b.set_fill("█");
  b.set_lead_animation({animation::frame("█")});
  b.set_remain("-");
  while(!b.is_complete()){
        // Print the initial line
        b.print_bar();
        // Simulate some processing delay
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
        b.flush();    
        b.add_progress();
        // Clear the line
    }
  
}

