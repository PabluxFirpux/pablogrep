#include <iostream>
#include <string>
using namespace std;

int main(int argc, char **argv)
{
    cout << "Program name is: " << argv[0] << endl;

    if (argc == 1)
    {
        cout << "No extra Command Line Argument passed "
                "other than program name"
             << endl;
    }
    if (argc > 1)
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