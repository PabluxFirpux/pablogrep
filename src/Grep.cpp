//
// Created by Pablo Firpo Molina on 10/12/2023.
//

#include "Grep.h"
#include <iostream>
#include <string>
#include <fstream>
#include <regex>
#include <filesystem>

namespace pablo {

    Grep::Grep() = default;

    Grep::~Grep() = default;

    void Grep::grep(std::string pattern, std::string filename) {
        if (is_directory(filename)) {
            directory_grep(pattern, filename);
        } else if (isfile(filename)) {
            check_file(pattern, filename, false);
        } else {
            std::cout << "File is not a file." << std::endl;
            return;
        }
    }

    //Bad way to check if is file
    bool Grep::is_file(std::string filename) {
        std::ifstream infile;
        infile.open(filename);
        if (!infile.is_open()) {
            return false;
        } else {
            return true;
        }
    }

    bool Grep::match(std::string pattern, std::string line) {
        if(std::regex_search(line, std::regex(pattern))) {
            return true;
        } else {
            return false;
        }
    }

    void Grep::check_file(std::string pattern, std::string filename, bool is_recursive) {
        std::ifstream infile;
        infile.open(filename);
        std::string line;
        while (std::getline(infile, line)) {
            if (match(pattern, line)) {
                if (is_recursive) {
                    std::cout << filename << ": ";
                }
                std::cout << line << std::endl;
            }
        }
    }

    void Grep::recursive_grep(std::string pattern, std::string directory) {
        for (auto const& dir_entry : std::filesystem::recursive_directory_iterator(directory))
            if(is_directory(dir_entry.path().string())) {
                recursive_grep(pattern, dir_entry.path().string());
            } else if (isfile(dir_entry.path().string())){
                check_file(pattern, dir_entry.path().string(), true);
            }
    }

    bool Grep::is_directory(std::string path) {
        return std::filesystem::is_directory(path);
    }

    bool Grep::isfile(std::string path) {
        return std::filesystem::is_regular_file(path);
    }

    void Grep::directory_grep(std::string pattern, std::string directory) {
        for (auto const& dir_entry : std::filesystem::directory_iterator(directory))
            if(is_directory(dir_entry.path().string())) {

            } else if (isfile(dir_entry.path().string())){
                check_file(pattern, dir_entry.path().string(), true);
            }

    }
} // pablo