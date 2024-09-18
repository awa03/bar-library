#include <ostream>

namespace loadingBar {
  namespace Color {
      enum Code {
    // Foreground colors
    FG_BLACK     = 30,
    FG_RED       = 31,
    FG_GREEN     = 32,
    FG_YELLOW    = 33,
    FG_BLUE      = 34,
    FG_MAGENTA   = 35,
    FG_CYAN      = 36,
    FG_WHITE     = 37,
    FG_DEFAULT   = 39,
    
    // Background colors
    BG_BLACK     = 40,
    BG_RED       = 41,
    BG_GREEN     = 42,
    BG_YELLOW    = 43,
    BG_BLUE      = 44,
    BG_MAGENTA   = 45,
    BG_CYAN      = 46,
    BG_WHITE     = 47,
    BG_DEFAULT   = 49,

    // Styles
    STYLE_RESET  = 0,
    STYLE_BOLD   = 1,
    STYLE_DIM    = 2,
    STYLE_UNDERLINE = 4,
    STYLE_BLINK  = 5,
    STYLE_REVERSE = 7,
    STYLE_HIDDEN = 8
    };


      class Modifier {
          Code code;

      public:
          Modifier(Code pCode) : code(pCode) {}
          friend std::ostream&
          operator<<(std::ostream& os, const Modifier& mod) {
              return os << "\033[" << mod.code << "m";
          }
      };
  }
}

// src -- https://stackoverflow.com/questions/2616906/how-do-i-output-coloured-text-to-a-linux-terminal
