#ifndef ANIMATION_HPP
#define ANIMATION_HPP

#include <iostream>
#include <vector>
#include <string>
#include <cstring>

namespace loadingBar {
    class animation {
        public: 
        class frame {
          public:
            frame();
            frame(const std::string& t_f);
            frame(char t_f);
            
            std::string get_frame_icon();
          private:
            std::string f;
        };

        animation();
        animation(frame f);
        animation(char t_f);
        animation(const std::string& t_f);
        animation(const std::vector<frame>& t_v);

        frame get_curr_frame();
        std::string get_curr_frame_icon();

        void next_frame();
        void set_curr_frame(int index);


      private:
        std::vector<frame> frames;
        int curr_frame_index;
        void init();
    };

    namespace premade {
      static animation spinning({animation::frame("\\"), animation::frame("|"), animation::frame("/"), animation::frame("-")});

      static animation loading({animation::frame(" Loading"), animation::frame(" Loading."), animation::frame(" Loading.."), animation::frame(" Loading...")});
    }


    // Definitions of frame methods
    inline animation::frame::frame() : f("#") {}
    
    inline animation::frame::frame(const std::string& t_f) : f(t_f) {}

    inline animation::frame::frame(char t_f) : f(1, t_f) {}

    inline std::string animation::frame::get_frame_icon(){
      return f;
    }

    // Definitions of animation methods
    inline void animation::init() {
      curr_frame_index = 0;
    }

    inline animation::animation() {
      frame c;
      frames.push_back(c);
      init();
    }

    inline animation::animation(frame f) {
      frames.push_back(f);
      init();
    }

    inline animation::animation(char t_f) {
      frame c(t_f);
      frames.push_back(c);
      init();
    }


    inline animation::animation(const std::string& t_f) {
      frame c(t_f);
      frames.push_back(c);
      init();
    }

    inline animation::animation(const std::vector<frame>& t_v) : frames(t_v) {
      init();
    }

    inline animation::frame animation::get_curr_frame(){
      return frames[curr_frame_index];
    }

    inline std::string animation::get_curr_frame_icon(){
      return frames[curr_frame_index].get_frame_icon();
    }
    inline void animation::next_frame(){
      (curr_frame_index >= frames.size() - 1)?
        curr_frame_index = 0 
        : curr_frame_index++;
    }

    inline void animation::set_curr_frame(int index){
      curr_frame_index = index % frames.size();
    }

} // namespace Animation

#endif // ANIMATION_HPP

