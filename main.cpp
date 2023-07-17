#include <iostream>
#include <filesystem>
#include <queue>
#include <string>
#include"ui.h"


int main() {

    int longestName;
    std::string end;
    std::string path = std::filesystem::current_path();
    std::queue<std::filesystem::directory_entry> files, dirs;
    longestName = 0;

    for (const auto &entry : std::filesystem::directory_iterator(path)) {
        entry.is_directory() ? dirs.push(entry) : files.push(entry);
        if (entry.path().filename().wstring().length() > longestName) {
            longestName = entry.path().filename().wstring().length();
        }
    }

    ui box(longestName);

    box.border();

    box.line("cSize - file system measurement tool");
    box.line();

    while(!dirs.empty()){
        end = "-";

        if (!dirs.front().is_directory()){
            end = ui::readable(dirs.front().file_size());
        }

        box.line(dirs.front().path().filename(), end);
        dirs.pop();

        if (dirs.empty()){ dirs.swap(files); }
    }

    box.border("bottom");
}
