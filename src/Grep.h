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
        void grep(std::string pattern, std::string filename);
         void recursive_grep(std::string pattern, std::string directory);
         void directory_grep(std::string pattern, std::string directory);
        void set_show_filename(bool recursive);
        void set_inverted(bool inverted);
        void set_recursive(bool recursive);
    private:
        bool show_filename;
        bool is_inverted;
        bool is_recursive;
         bool is_file(std::string filename);
        //static bool is_readable(std::string filename);
        //static bool is_writable(std::string filename);
         bool match(std::string pattern, std::string line);
        void check_file(std::string pattern ,std::string filename);
         bool is_directory(std::string path);
         bool isfile(std::string path);
    };

} // pablo

#endif //PABLOGREP_GREP_H
