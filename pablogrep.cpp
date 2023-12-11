#include <iostream>
#include <string>
#include <chrono>
#include "src/Grep.h"
using namespace std;

void print_usage()
{
    cout << "Usage: pablogrep [FLAGS?] [PATTERN] [FILE]" << endl;
    cout << "Use \"pablogrep -h\" for more information" << endl;
}

void print_help() {
    cout << "Usage: pablogrep [FLAGS?] [PATTERN] [FILE]" << endl;
    cout << "Search for PATTERN in each FILE or standard input." << endl;
    cout << "Example: pablogrep -r 'hello world' menu.h main.cpp" << endl;
    cout << "Flags:" << endl;
    cout << "-v, --invert-match\tInvert match, select non-matching lines" << endl;
    cout << "-l, --file-names\tPrint filenames containing matches" << endl;
    cout << "-r, --recursive\tRead all files under each directory, recursively" << endl;
    cout << "-h, --help\tPrint this help message and exit" << endl;

}

int main(int argc, char **argv)
{
    auto start = std::chrono::high_resolution_clock::now();
    pablo::Grep grep;
    grep = pablo::Grep();

    if (argc == 1)
    {
        cout << "No extra Command Line Argument passed"
                "other than program name"
             << endl;
        print_usage();
    }
    else if (argc == 2)
    {
        if (string(argv[1]).compare("-h") == 0 || string(argv[1]).compare("--help") == 0) {
            print_help();
            return 0;
        }
        cout << "Missing command line argument."
             << endl;
        print_usage();
    }
    else if (argc == 3)
    {
        string pattern = argv[1];
        string filename = argv[2];
        grep.grep(pattern, filename);
    }
    else if (argc > 3)
    {
        int flags = argc - 3;
        for (int i = 0; i < flags; i++)
        {
            string flag = argv[i + 1];
            if (flag.compare("-v") == 0)
            {
                cout << "Inverted grep" << endl;
                grep.set_inverted(true);
            }
            else if (flag.compare("-l") == 0)
            {
                cout << "Show filename" << endl;
                grep.set_show_filename(true);
            }
            else if (flag.compare("-r") == 0)
            {
                cout << "Recursive grep" << endl;
                grep.set_recursive(true);
            }
            else if (flag.compare("-h") == 0 || flag.compare("--help") == 0)
            {
                print_help();
                return 0;
            }
            else
            {
                cout << "Invalid flag passed." << endl;
                print_usage();
                return 0;
            }
        }
        grep.grep(argv[argc - 2], argv[argc - 1]);
    }
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop-start);
    cout << "Time taken by grep: "
         << duration.count() << " miliseconds" << endl;
    return 0;
}