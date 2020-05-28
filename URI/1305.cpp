#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int main() {
    double num, cutoff;

    while (scanf("%lf%lf", &num, &cutoff) == 2) {
        if ((num - int(num)) > cutoff)
            cout << int(num) + 1;
        else
            cout << int(num);
        cout << endl;
    }
    return 0;
}
