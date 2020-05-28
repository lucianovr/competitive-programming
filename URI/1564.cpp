#include <iostream>

#include <cstdlib>

#include <cstring>

#include <stdio.h>

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char **argv) {

    int x;

    while (cin >> x)

    {

        if (x == 0)

        {

            cout << "vai ter copa!\n";

        }

        else

        {

            cout << "vai ter duas!\n";
        }
    }

    return 0;
}