#include <iostream>
#include "classi.h"
#include "test.h"

using namespace std;

int main()
{
    test1();
    test2();
    test3();
    test4();

    for(int i = 0; i < 4; i++)
    {
        test1();
    }

    test12();

    return 0;
}