#include <iostream>
#include <cmath>
#include <string>

class ui {
    protected:
        int length;

        
    public:
        ui(int length) {
            if(length > 40) {
                // border, length, padding, fileSize
                this->length = 2 + length + 2 + 4;
            } else {
                this->length = 48;
            }
        }

        void border(std::string pos = "top") {
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

        void line( std::string start="", std::string end="") {
            int gapSize;
            std::string whiteSpace;
            std::string content;

            gapSize = this->length - (start.length() + end.length());
            //std::cout << this->length << std::endl;
            //std::cout << gapSize << std::endl;
            for (int i = 0; i < gapSize; i++) {
                whiteSpace += " ";
            }

            std::cout << "│ " << start << whiteSpace << end << " │" << std::endl;
        };

        static std::string readable(uintmax_t fileSize) {
            std::string metric;
            std::string shortSize;

            double rawFactor = std::log(fileSize) / std::log(1024);
            int factor = (int)std::round(rawFactor);

            switch (factor) {
                case 0:
                    shortSize = std::to_string(fileSize);
                    break;
                case 1:
                    metric="k";
                    shortSize = std::to_string(fileSize /(1024 * factor));
                    break;
                case 2:
                    metric="m";
                    shortSize = std::to_string(fileSize);
                    break;
                case 3:
                    metric="g";
                    shortSize = std::to_string(fileSize);
                    break;
            }
            return shortSize + metric + "b";
        }
};
