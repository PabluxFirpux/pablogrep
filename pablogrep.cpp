#include <iostream>
#include <string>
#include "src/Grep.h"
using namespace std;

void print_usage()
{
    cout << "Usage: pablogrep [PATTERN] [FILE]" << endl;
}

int main(int argc, char **argv)
{
    cout << "Program name is: " << argv[0] << endl;

    if (argc == 1)
    {
        cout << "No extra Command Line Argument passed"
                "other than program name"
             << endl;
        print_usage();
    }
    else if (argc == 2)
    {
        cout << "Missing command line argument."
             << endl;
        print_usage();
    }
    else if (argc == 3)
    {
        string pattern = argv[1];
        string filename = argv[2];
        pablo::Grep::grep(pattern, filename);
    }
    else if (argc > 3)
    {
        string flag = argv[1];
        if (flag.compare("-r") == 0) {
            cout << "Recursive grep" << endl;
            string pattern = argv[2];
            string filename = argv[3];
            pablo::Grep::recursive_grep(pattern, filename);
        } else {
            cout << "Too many arguments passed."
                 << endl;
            print_usage();
        }
    }
    return 0;
}