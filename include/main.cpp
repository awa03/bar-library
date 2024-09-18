#include <iostream>
#include "Animation.hpp"
#include "Bar.hpp"
#include <chrono>
#include <thread>

using namespace std;
using namespace loadingBar;
int main(){
  loadingBar::bar b;
  b.set_remain("");
  b.set_fg_color(Color::FG_RED);
  b.set_lead_animation(premade::spinning);

  while(!b.is_complete()){
      // Simulate some processing delay
      b.print_bar();
      std::this_thread::sleep_for(std::chrono::milliseconds(500));
      b.flush();    

      b.print_bar();
      b.next_lead_frame();
      std::this_thread::sleep_for(std::chrono::milliseconds(500));
      b.flush();    

      b.print_bar();
      b.next_lead_frame();
      std::this_thread::sleep_for(std::chrono::milliseconds(500));
      b.flush();    

      b.next_lead_frame();
      b.add_progress();
      // Clear the line
  }

}
