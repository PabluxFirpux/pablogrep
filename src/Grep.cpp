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

    Grep::Grep() {
        show_filename = false;
        is_inverted = false;
        is_recursive = false;
    }

    Grep::~Grep() = default;

    void Grep::grep(std::string pattern, std::string filename) {
        if (is_recursive) {
            recursive_grep(pattern, filename);
        } else if (is_directory(filename)) {
            set_show_filename(true);
            directory_grep(pattern, filename);
        } else if (isfile(filename)) {
            check_file(pattern, filename);
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

    void Grep::check_file(std::string pattern, std::string filename) {
        std::ifstream infile;
        infile.open(filename);
        std::string line;
        int line_number = 1;
        while (std::getline(infile, line)) {
            if (match(pattern, line)  == !is_inverted) {
                if (show_filename) {
                    std::cout << filename << ": ";
                    std::cout << line_number << "- ";
                } else {
                    std::cout << line_number << "- ";
                }
                std::cout << line << std::endl;
            }
            line_number++;
        }
        infile.close();
    }

    void Grep::recursive_grep(std::string pattern, std::string directory) {
        if (!is_directory(directory)) {
            std::cout << "Path is not a directory. Can't search recursively" << std::endl;
            return;
        }
        try {
            for (auto const& dir_entry : std::filesystem::directory_iterator(directory, std::filesystem::directory_options::skip_permission_denied))
                if(is_directory(dir_entry.path().string())) {
                    recursive_grep(pattern, dir_entry.path().string());
                } else if (isfile(dir_entry.path().string())){
                    check_file(pattern, dir_entry.path().string());
                }
        } catch (std::filesystem::filesystem_error &e) {
            //std::cout << "Error: " << e.what() << std::endl;
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
            if (isfile(dir_entry.path().string())){
                check_file(pattern, dir_entry.path().string());
            }
    }

    void Grep::set_inverted(bool inverted) {
        is_inverted = inverted;
    }

    void Grep::set_show_filename(bool show_filename) {
        this->show_filename = show_filename;
    }

    void Grep::set_recursive(bool recursive) {
        is_recursive = recursive;
        if (is_recursive) {
            set_show_filename(true);
        }
    }
} // pablo