#include <iostream>
#include "classi.h"
#include "test.h"

using namespace std;

int main()
{
    test1();
    cout << endl;
    test2();
    cout << endl;
    test3();
    cout << endl;
    test4();
    cout << endl;

    for(int i = 0; i < 5; i++)
    {
        test1();
        cout << endl;
    }

    test12();

    return 0;
}