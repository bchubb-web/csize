#include <iostream>
#include <filesystem>
#include <queue>
#include"ui.h"


int main() {

    std::string path = std::filesystem::current_path();
    std::queue<std::filesystem::directory_entry> files, dirs;

    for (const auto &entry : std::filesystem::directory_iterator(path)) {
        entry.is_directory() ? dirs.push(entry) : files.push(entry);
    }

    ui::startBox();

    ui::makeLine("cSize - file system measurement tool");
    ui::makeLine();

    while(!dirs.empty()){
        std::string end = "-";

        if (!dirs.front().is_directory()){
            end = ui::readableBytes(dirs.front().file_size());
        }

        ui::makeLine(dirs.front().path().filename(), end);
        dirs.pop();

        if (dirs.empty()){ dirs.swap(files); }
    }

    ui::endBox();
}
