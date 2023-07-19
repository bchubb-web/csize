#ifndef UI_H
#define UI_H

#include <iostream>

class Ui {
    int length;

    public:
        Ui(int length);
        void border(std::string pos = "top");
        void line( std::string start="", std::string end="");
        static std::string readable(uintmax_t fileSize);
};

#endif
