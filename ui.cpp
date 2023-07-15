#include <iostream>
#include <string>

class ui {
    public:
        int lineNum = 0;
        std::string line = "";

        static void startBox() {
            std::cout << "╭────────────────────────────────╮";
        }
        static void makeLine( std::string start="", int end=0) {
            //or { "─", "│", "─", "│", "╭", "╮", "╯", "╰" }
            int gap = start.length() + std::to_string(end).length();
            std::cout << "│ " << start << std::string(30-gap, " ") << std::to_string(end) << " │";
        }
        static void endBox() {
            std::cout << "╰────────────────────────────────╯";
        }
};
