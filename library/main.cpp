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
  b.set_fill(symbol::bar);
  b.set_remain(symbol::fade_bar);
  b.set_fg_color(Color::FG_RED);
  b.set_lead_animation(premade::dice);

  while(!b.is_complete()){
      // Simulate some processing delay
      b.print_bar();
      std::this_thread::sleep_for(std::chrono::milliseconds(200));
      b.flush();    

      b.print_bar();
      b.next_lead_frame();
      std::this_thread::sleep_for(std::chrono::milliseconds(200));
      b.flush();    

      b.print_bar();
      b.next_lead_frame();
      std::this_thread::sleep_for(std::chrono::milliseconds(200));
      b.flush();    

      b.print_bar();
      std::this_thread::sleep_for(std::chrono::milliseconds(200));
      b.flush();    

      b.print_bar();
      b.next_lead_frame();
      std::this_thread::sleep_for(std::chrono::milliseconds(200));
      b.flush();    

      b.next_lead_frame();
      b.print_bar();
      std::this_thread::sleep_for(std::chrono::milliseconds(200));

      b.flush();    
      b.next_lead_frame();
      b.add_progress();
      // Clear the line
  }

}
