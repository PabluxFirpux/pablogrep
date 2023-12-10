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
    else if (argc > 1)
    {
        cout << "Number of arguments passed: " << argc
             << endl;
        cout << "----Following are the commnand line "
                "arguments passed----"
             << endl;
        for (int i = 0; i < argc; i++)
        {
            cout << "argv[" << i << "]: " << argv[i]
                 << '\n';
        }
    }
    return 0;
}