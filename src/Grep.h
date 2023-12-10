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
    private:
        static bool is_file(std::string filename);
        //static bool is_directory(std::string filename);
        //static bool is_readable(std::string filename);
        //static bool is_writable(std::string filename);
        static bool match(std::string pattern, std::string line);
        static void check_file(std::string pattern ,std::string filename);
    };

} // pablo

#endif //PABLOGREP_GREP_H
