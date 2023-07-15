#include <algorithm>
#include <cstdint>
#include <iostream>
#include <filesystem>
#include <string>
#include"ui.cpp"


int main() {
    int totalSize;
    int fileCount;
    int width = 48;

    std::string path = std::filesystem::current_path();

    for (const auto & entry : std::filesystem::directory_iterator(path)) {
        if (!entry.is_directory()){
            totalSize += entry.file_size();
            fileCount++;
        }
    }
    //        or { "─", "│", "─", "│", "╭", "╮", "╯", "╰" }
    std::string files[fileCount];
    ui::startBox();
    std::cout << "|                                                               │" << std::endl;
    std::cout << "Total path size: " << totalSize << std::endl;
    std::cout << "Number of files: " << fileCount << std::endl;
    for (const auto & entry : std::filesystem::directory_iterator(path)) {
        if (!entry.is_directory()){
            ui::makeLine(entry.path(), entry.file_size());
        }
    }
    ui::endBox();
}
