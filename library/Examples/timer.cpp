#include <iostream>
#include "../include/Animation.hpp"
#include "../include/Bar.hpp"
#include "../include/Symbols.hpp"
#include <chrono>
#include <thread>

using namespace std;
using namespace loadingBar;

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cerr << "Usage: timer {seconds}" << endl;
        return 1;
    }

    int seconds = atoi(argv[1]);
    if (seconds <= 0) {
        cerr << "Please provide a positive number of seconds." << endl;
        return 1;
    }

    loadingBar::bar b;
    b.set_width(30);
    b.set_fill(symbol::bar);
    b.set_remain(symbol::fade_bar);
    b.set_lead_animation(premade::none);

    int total_time = seconds * 1000; 
    int increments = b.get_width(); 
    int time_per_increment = total_time / increments;

    // Main loop until the bar is complete
    for (int i = 0; i < increments; i++) {
        auto start = std::chrono::steady_clock::now();

        b.flush();
        b.print_bar();
        b.add_progress();
        b.next_lead_frame();

        auto end = std::chrono::steady_clock::now();
        auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

        // Sleep for the remaining time
        std::this_thread::sleep_for(std::chrono::milliseconds(time_per_increment - elapsed));
    }

    return 0;
}

