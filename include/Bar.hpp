/* "##::::::::"#######:::::"###::::"########::"####:"##::: ##::"######:::"########:::::"###::::"########:: */
/*  ##:::::::"##.... ##:::"## ##::: ##.... ##:. ##:: ###:: ##:"##... ##:: ##.... ##:::"## ##::: ##.... ##: */
/*  ##::::::: ##:::: ##::"##:. ##:: ##:::: ##:: ##:: ####: ##: ##:::..::: ##:::: ##::"##:. ##:: ##:::: ##: */
/*  ##::::::: ##:::: ##:"##:::. ##: ##:::: ##:: ##:: ## ## ##: ##::"####: ########::"##:::. ##: ########:: */
/*  ##::::::: ##:::: ##: #########: ##:::: ##:: ##:: ##. ####: ##::: ##:: ##.... ##: #########: ##.. ##::: */
/*  ##::::::: ##:::: ##: ##.... ##: ##:::: ##:: ##:: ##:. ###: ##::: ##:: ##:::: ##: ##.... ##: ##::. ##:: */
/*  ########:. #######:: ##:::: ##: ########::"####: ##::. ##:. ######::: ########:: ##:::: ##: ##:::. ##: */
/* ........:::.......:::..:::::..::........:::....::..::::..:::......::::........:::..:::::..::..:::::..:: */

#include <ostream>
#ifndef BAR_HPP
#define BAR_HPP

#include <iostream>
#include "Color.hpp"
using namespace loadingBar::Color;

namespace loadingBar {
  class bar {
    public: 

      // Constructors
      bar();
      bar(std::string ld, std::string fill, std::string remain, Modifier clr);
      bar(std::string ld, int height, int width, Modifier clr); 
      bar(std::string ld, int width, Modifier clr);
      bar(std::string ld, std::string fill, int width, Modifier clr);
      bar(std::string ld, std::string fill, std::string remain, int width, Modifier clr);
      bar(std::string ld, std::string fill, std::string remain, int width, int height, Modifier clr);
      bar(std::string ld, std::string width, std::string height, std::string lead, std::string fill, std::string remain, Modifier fg_clr, Modifier bg_clr, int prog);

      // Getters
      int get_width();
      int get_height();
      int get_progress();
      std::string get_lead();
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
      bar set_height(int h);
      bar set_progress(int p);
      bar set_lead(std::string l);
      bar set_fill(std::string f);
      bar set_remain(std::string r);
      bar set_fg_color(Modifier fg);
      bar set_bg_color(Modifier bg);

      bar add_progress();
      bar remove_progress();

    private:    
      int width;
      int height;
      int progress;

      // Settings 
      std::string lead;
      std::string fill;
      std::string remain;
      Modifier fgcolor;
      Modifier bgcolor;
      bool isPercent = true;
      std::string Complete_Message = "";
      std::string CurrMessage = "";
  };

  inline bar::bar() : width(50), height(1), lead(">"), fill("#"), remain("-"), fgcolor(Color::FG_DEFAULT), bgcolor(Color::BG_DEFAULT), progress(0){
  }

// Constructors ------------------------------------------------------------------------------------------------
inline bar::bar(std::string ld, std::string fill, std::string remain, Modifier fg_clr) : width(50), height(1), lead(ld), fill(fill), remain(remain), fgcolor(fg_clr), bgcolor(Color::BG_DEFAULT), progress(0){}

inline bar::bar(std::string ld, int height, int width, Modifier clr) : width(width), height(height), lead(ld), fill("#"), remain("-"), fgcolor(Color::FG_DEFAULT), bgcolor(Color::BG_DEFAULT), progress(0){}

inline bar::bar(std::string ld, int width, Modifier fg_clr) : width(width), height(1), lead(ld), fill("#"), remain("-"), fgcolor(fg_clr), bgcolor(Color::BG_DEFAULT), progress(0){}

inline bar::bar(std::string ld, std::string fill, int width, Modifier clr) : width(width), height(1), lead(ld), fill(fill), remain("-"), fgcolor(Color::FG_DEFAULT), bgcolor(Color::BG_DEFAULT), progress(0){}

inline bar::bar(std::string ld, std::string fill, std::string remain, int width, Modifier fg_clr) : width(width), height(1), lead(ld), fill(fill), remain(remain), fgcolor(fg_clr), bgcolor(Color::BG_DEFAULT), progress(0){}


// EO Constructors ---------------------------------------------------------------------------------------------

// Getters -----------------------------------------------------------------------------------------------------
inline int bar::get_width(){
  return width;
}

inline int bar::get_height(){
  return height;
}

inline int bar::get_progress(){
  return progress;
}

inline std::string bar::get_lead(){
  return lead;
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
  std::cout << lead;
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

inline bar bar::set_height(int h){
  height = h;
  return *this;
}

inline bar bar::set_progress(int p){
  progress = p;
  return *this;
}

inline bar bar::set_lead(std::string l){
  lead = l;
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
