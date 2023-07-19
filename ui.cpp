#include <iostream>
#include <cmath>
#include <string>
#include "Ui.h"


Ui::Ui(int length) {
    if(length > 40) {
        // border, length, padding, fileSize
        this->length = 2 + length + 2 + 4;
    } else {
        this->length = 48;
    }
}

void Ui::border(std::string pos) {
    std::string line;

    for (int i=0;i<this->length+2;i++) {
        line+="─";
    }

    if (pos == "top") {
        std::cout << "╭" << line << "╮" << std::endl;
    } else {
        std::cout << "╰" << line << "╯" << std::endl;
    }
};

void Ui::line( std::string start, std::string end) {
    int gapSize;
    std::string whiteSpace;
    std::string content;

    gapSize = this->length - (start.length() + end.length());
    for (int i = 0; i < gapSize; i++) {
        whiteSpace += " ";
    }

    std::cout << "│ " << start << whiteSpace << end << " │" << std::endl;
};

std::string Ui::readable(uintmax_t fileSize) {
    std::string metric;
    std::string shortSize;
    double rawFactor;
    int factor;

    rawFactor = std::log(fileSize) / std::log(1024);
    factor = (int)std::round(rawFactor);

    switch (factor - 1) {
        case 0:
            metric="b";
            shortSize = std::to_string(fileSize);
            break;
        case 1:
            metric="kb";
            shortSize = std::to_string(fileSize /(1024 * std::floor(rawFactor)));
            break;
        case 2:
            metric="mb";
            shortSize = std::to_string(fileSize /(1024 * std::floor(rawFactor)));
            break;
        case 3:
            metric="gb";
            shortSize = std::to_string(fileSize /(1024 * std::floor(rawFactor)));
            break;
    }

    return shortSize + metric;
}
