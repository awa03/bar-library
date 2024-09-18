/* "##::::::::"#######:::::"###::::"########::"####:"##::: ##::"######:::"########:::::"###::::"########:: */
/*  ##:::::::"##.... ##:::"## ##::: ##.... ##:. ##:: ###:: ##:"##... ##:: ##.... ##:::"## ##::: ##.... ##: */
/*  ##::::::: ##:::: ##::"##:. ##:: ##:::: ##:: ##:: ####: ##: ##:::..::: ##:::: ##::"##:. ##:: ##:::: ##: */
/*  ##::::::: ##:::: ##:"##:::. ##: ##:::: ##:: ##:: ## ## ##: ##::"####: ########::"##:::. ##: ########:: */
/*  ##::::::: ##:::: ##: #########: ##:::: ##:: ##:: ##. ####: ##::: ##:: ##.... ##: #########: ##.. ##::: */
/*  ##::::::: ##:::: ##: ##.... ##: ##:::: ##:: ##:: ##:. ###: ##::: ##:: ##:::: ##: ##.... ##: ##::. ##:: */
/*  ########:. #######:: ##:::: ##: ########::"####: ##::. ##:. ######::: ########:: ##:::: ##: ##:::. ##: */
/* ........:::.......:::..:::::..::........:::....::..::::..:::......::::........:::..:::::..::..:::::..:: */

#ifndef BAR_HPP
#define BAR_HPP

#include <ostream>
#include <iostream>
#include "Animation.hpp"
#include "Color.hpp"
#include "Symbols.hpp"

using namespace loadingBar::Color;

namespace loadingBar {
  class bar {
    public: 

      // Constructors
      bar();

      // Getters
      int get_width();
      int get_progress();
      animation get_lead_animation();
      std::string get_fill();
      std::string get_remain();
      Modifier get_fg_color();
      Modifier get_bg_color();
      void print_bar();
      bar get_bar();
      float get_percent();

      void flush();
      bool is_complete();
      bool toggle_percentage();

      // Setters
      bar set_width(int w);
      bar set_progress(int p); 
      bar set_lead_animation(animation a); 
      bar set_fill(std::string f);
      bar set_remain(std::string r);
      bar set_fg_color(Modifier fg);
      bar set_bg_color(Modifier bg);

      void set_animation_frame(int index);
      void next_lead_frame();

  // TODO Add Frame Option

      bar add_progress();
      bar remove_progress();

    private:    
      int width;
      int progress;

      // Settings 
      std::string fill;
      std::string remain;
      Modifier fgcolor;
      Modifier bgcolor;
      bool isPercent = true;
      std::string Complete_Message = "";
      std::string CurrMessage = "";
      animation lead_frames;
  };

  inline bar::bar() : width(50), lead_frames(">"), fill("#"), remain("-"), fgcolor(Color::FG_DEFAULT), bgcolor(Color::BG_DEFAULT), progress(0){
  }

// Constructors ------------------------------------------------------------------------------------------------
// TODO

// EO Constructors ---------------------------------------------------------------------------------------------

// Getters -----------------------------------------------------------------------------------------------------
inline int bar::get_width(){
  return width;
}

inline int bar::get_progress(){
  return progress;
}

inline animation bar::get_lead_animation(){
  return lead_frames;
}

inline std::string bar::get_fill(){
  return fill;
}

inline std::string bar::get_remain(){
  return remain;
}

inline Modifier bar::get_fg_color(){
  return fgcolor;
}

inline Modifier bar::get_bg_color(){
  return bgcolor;
}

inline void bar::print_bar(){
  std::cout << fgcolor;
  for(int i = 0; i < progress; i++){
      std::cout << fill;
  }
  std::cout << lead_frames.get_curr_frame_icon();
  for(int i = progress; i < width; i++){
    std::cout << remain;
  }
  if(isPercent){
    std::cout << ' ' << this->get_percent() << "%";
  }
  std::cout << bgcolor; 
  std::cout.flush();
}

inline bar bar::get_bar(){
  return *this;
}

inline float bar::get_percent(){
  return (float)(static_cast<float>(progress) / static_cast<float>(width)) * 100.00;
}

// EO Getters --------------------------------------------------------------------------------------------------
//
inline bool bar::is_complete(){
  return width == progress;
}

inline void bar::flush(){
  std::cout << "\033[2K" << "\033[0G";
}

inline bool bar::toggle_percentage(){
  if(isPercent){
    isPercent = false;
  }
  else {
    isPercent = true;
  }
  return isPercent;
}

// Setters -----------------------------------------------------------------------------------------------------
inline bar bar::set_width(int w){
  width = w;
  return *this;
}

inline bar bar::set_progress(int p){
  progress = p;
  return *this;
}

inline bar bar::set_lead_animation(animation a){
  lead_frames = a;
  return *this;
}

inline bar bar::set_fill(std::string f){
  fill = f;
  return *this;
}

inline bar bar::set_remain(std::string r){
  remain = r;
  return *this;
}

inline bar bar::set_fg_color(Modifier fg){
  fgcolor = fg;
  return *this;
}

inline bar bar::set_bg_color(Modifier bg){
  bgcolor = bg;
  return *this;
}

inline void bar::set_animation_frame(int index){
  lead_frames.set_curr_frame(index); 
}

inline void bar::next_lead_frame(){
  lead_frames.next_frame();
}

inline bar bar::add_progress(){
  if (progress < width) progress++;
  return *this;
}
inline bar bar::remove_progress(){
  if(progress > 0) progress--;
  return *this;
}

// EO Setters --------------------------------------------------------------------------------------------------

}
#endif
