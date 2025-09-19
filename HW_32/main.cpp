#include "my_class.h"
#include <iostream>
using namespace std;


int main(int argc, char const *argv[])
{
    cout << "main Hello World!" << endl;
    int x = 5;
    zavisim* zav = new zavisim2();
    test_my_class t(zav);
    cout << "main Result: " << t.test(x) << endl;

    return 0;
}
