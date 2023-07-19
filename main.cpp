#include <iostream>
#include <filesystem>
#include <queue>
#include <string>
#include "ui.h"


int main() {

    int longestName;
    std::string end;
    std::string path;
    std::queue<std::filesystem::directory_entry> files, dirs;

    path = (std::string)std::filesystem::current_path();
    longestName = 0;

    for (const std::filesystem::directory_entry &entry : std::filesystem::directory_iterator(path)) {

        entry.is_directory() ? dirs.push(entry) : files.push(entry);

        if (entry.path().filename().wstring().length() > longestName) {
            longestName = entry.path().filename().wstring().length();
        }
    }

    Ui box(longestName);

    box.border();

    box.line("cSize - file system measurement tool");
    box.line();

    while(!dirs.empty()){
        end = "-";

        if (!dirs.front().is_directory()){
            end = Ui::readable(dirs.front().file_size());
        }

        box.line(dirs.front().path().filename(), end);
        dirs.pop();

        if (dirs.empty()) dirs.swap(files);
    }

    box.border("bottom");
}
