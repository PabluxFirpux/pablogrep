//
// Created by Pablo Firpo Molina on 10/12/2023.
//

#ifndef PABLOGREP_GREP_H
#define PABLOGREP_GREP_H

#include <string>

namespace pablo {

    class Grep {
    public:
        Grep();
        ~Grep();
        static void grep(std::string pattern, std::string filename);
        static void recursive_grep(std::string pattern, std::string directory);
        static void directory_grep(std::string pattern, std::string directory);
    private:
        bool is_recursive;
        static bool is_file(std::string filename);
        //static bool is_readable(std::string filename);
        //static bool is_writable(std::string filename);
        static bool match(std::string pattern, std::string line);
        static void check_file(std::string pattern ,std::string filename, bool show_filename = false);
        static bool is_directory(std::string path);
        static bool isfile(std::string path);
    };

} // pablo

#endif //PABLOGREP_GREP_H
