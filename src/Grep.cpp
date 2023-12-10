//
// Created by Pablo Firpo Molina on 10/12/2023.
//

#include "Grep.h"
#include <iostream>
#include <string>
#include <fstream>
#include <regex>

namespace pablo {

    Grep::Grep() = default;

    Grep::~Grep() = default;

    void Grep::grep(std::string pattern, std::string filename) {
        if (is_file(filename)) {
            check_file(pattern, filename);
        } else {
            std::cout << "File is not a file." << std::endl;
            return;
        }
    }

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

    void Grep::check_file(std::string pattern, std::string filename) {
        std::ifstream infile;
        infile.open(filename);
        std::string line;
        while (std::getline(infile, line)) {
            if (match(pattern, line)) {
                std::cout << line << std::endl;
            }
        }
    }
} // pablo