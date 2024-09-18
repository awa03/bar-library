#include <iostream>
#include "include/Animation.hpp"
#include "include/Bar.hpp"
#include "include/Symbols.hpp"
#include <chrono>
#include <thread>

using namespace std;
using namespace loadingBar;

int main(){
  loadingBar::bar b;
  b.set_fill(symbol::small_line);
  b.set_remain(symbol::dotted_line);
  b.set_fg_color(Color::FG_RED);
  b.set_lead_animation(premade::none);

  while(!b.is_complete()){
      // Simulate some processing delay
      b.print_bar();
      std::this_thread::sleep_for(std::chrono::milliseconds(100));
      b.flush();    

      b.print_bar();
      b.next_lead_frame();
      std::this_thread::sleep_for(std::chrono::milliseconds(100));
      b.flush();    

      b.print_bar();
      b.next_lead_frame();
      std::this_thread::sleep_for(std::chrono::milliseconds(100));
      b.flush();    

      b.next_lead_frame();
      b.add_progress();
      // Clear the line
  }

}
