#include <iostream>
#include <cmath>
#include <string>

class ui {
    public:
        static void startBox() {
            std::cout << "╭──────────────────────────────────────────────────────────────────╮" << std::endl;
        };



        static void makeLine( std::string start="", std::string end="") {
            int gapSize;
            std::string whiteSpace;
            std::string content;

            gapSize = 64 - (start.length() + end.length());

            for (int i = 0; i < gapSize; i++) {
                whiteSpace += " ";
            }

            std::cout << "│ " << start <<  whiteSpace << end << " │" << std::endl;
        };


        static void endBox() {
            std::cout << "╰──────────────────────────────────────────────────────────────────╯" << std::endl;
        };

        static std::string readableBytes(uintmax_t size) {
            std::string metric;
            std::string shortSize;

            int factor = std::log(size) / std::log(1024);

            switch (factor) {
                case 0:
                    metric="b";
                    shortSize = size;
                    break;
                case 1:
                    metric="kb";
                    shortSize = size;
                    break;
                case 2:
                    metric="mb";
                    break;
                case 3:
                    metric="gb";
                    break;

            }
            return std::to_string(size).at(0) + metric;
        }
};
