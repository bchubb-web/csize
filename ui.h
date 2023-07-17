#include <iostream>
#include <cmath>

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

            int factor = std::log(size) / std::log(1024);

            std::cout << factor;

            switch (factor) {
                case 0:
                    metric="b";
                case 1:
                    metric="kb";
                case 2:
                    metric="mb";
                case 3:
                    metric="gb";
            }
            return metric;
        }
};
