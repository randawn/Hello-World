#include <iostream>
#include <string>
using namespace std;

int main()
{
    string user_name_f;
    string user_name_l;
    cout << "Enter your f name:" << "\n";
    cin  >> user_name_f;
    cout << "Enter your l name:" << "\n";
    cin  >> user_name_l;
    cout << "Hello "
         << user_name_f
         << " "
         << user_name_l
         << " ... and goodbyte\n";
    return 0;
}
