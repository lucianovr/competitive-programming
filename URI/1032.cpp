#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

void AchaPrimos(int MAX, int primo[]);

int main() {

    vector<int> vect;
    int del, i, n, m[32701];

    AchaPrimos(32700, m);

    while (scanf("%d", &n) && n) {
        vect.clear();
        for (i = 0; i < n; i++)
            vect.push_back(i + 1);
        del = i = 0;
        while (n > 1) {
            del = (del + m[i++] - 1) % n--;
            vect.erase(vect.begin() + del);
        }
        printf("%d\n", vect[0]);
    }
    return 0;
}

void AchaPrimos(int MAX, int primo[]) {
    int i, j, np;
    primo[1] = 0;
    primo[2] = 1;

    for (i = 3; i <= MAX; i++)
        primo[i] = i % 2;

    for (i = 3; i * i <= MAX; i += 2)
        if (primo[i])
            for (j = i * i; j <= MAX; j += i)
                primo[j] = 0;
    np = 0;
    for (i = 1; i <= MAX; i++)
        if (primo[i])
            primo[np++] = i;
}
