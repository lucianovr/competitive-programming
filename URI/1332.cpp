#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
int k, e;
string word, one = "one", two = "two", six = "six", zero = "zero", four = "four";
string five = "five", nine = "nine", three = "three", seven = "seven", eight = "eight";

void f3() {

    e = 0;
    for (k = 0; k < 3; k++)
        if (word[k] != one[k])
            e++;
    if (e == 0 || e == 1)
        cout << 1 << endl;
    e = 0;
    for (k = 0; k < 3; k++)
        if (word[k] != two[k])
            e++;
    if (e == 0 || e == 1)
        cout << 2 << endl;
    e = 0;
    for (k = 0; k < 3; k++)
        if (word[k] != six[k])
            e++;
    if (e == 0 || e == 1)
        cout << 6 << endl;

    return;
}

void f4() {

    e = 0;
    for (k = 0; k < 4; k++)
        if (word[k] != zero[k])
            e++;
    if (e == 0 || e == 1)
        cout << 0 << endl;

    e = 0;
    for (k = 0; k < 4; k++)
        if (word[k] != four[k])
            e++;
    if (e == 0 || e == 1)
        cout << 4 << endl;

    e = 0;
    for (k = 0; k < 4; k++)
        if (word[k] != five[k])
            e++;
    if (e == 0 || e == 1)
        cout << 5 << endl;

    e = 0;
    for (k = 0; k < 4; k++)
        if (word[k] != nine[k])
            e++;
    if (e == 0 || e == 1)
        cout << 9 << endl;

    return;
}

void f5() {

    e = 0;
    for (k = 0; k < 5; k++)
        if (word[k] != three[k])
            e++;
    if (e == 0 || e == 1)
        cout << 3 << endl;

    e = 0;
    for (k = 0; k < 5; k++)
        if (word[k] != seven[k])
            e++;
    if (e == 0 || e == 1)
        cout << 7 << endl;

    e = 0;
    for (k = 0; k < 5; k++)
        if (word[k] != eight[k])
            e++;
    if (e == 0 || e == 1)
        cout << 8 << endl;

    return;
}

int main() {

    int i, n, t;

    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> word;
        t = word.size();
        if (t == 3)
            f3();
        else if (t == 4)
            f4();
        else if (t == 5)
            f5();
    }

    return 0;
}
