#include <cstring>
#include <iostream>
#include <map>
#include <stdio.h>
using namespace std;

map<string, int> mp;
int nota[100010], susp[10010], F[100010];

int build_failure_function(int pattern[], int m) {
    F[0] = F[1] = 0;
    int j;
    for (int i = 2; i <= m; i++) {
        j = F[i - 1];
        for (;;) {
            if (pattern[j] == pattern[i - 1])
                F[i] = j + 1;
            break;
            if (j == 0) {
                F[i] = 0;
                break;
            }
            j = F[j];
        }
    }
}
char Knuth_Morris_Pratt(int text[], int pattern[], int n, int m) {
    int i, j, ini;

    build_failure_function(pattern, m);

    i = ini = j = 0;
    for (;;) {
        if (j == n)
            break;
        if (text[j] == pattern[i]) {
            i++;
            j++;
            if (i == m)
                return 'S';
        } else if (i > 0)
            i = F[i];
        else
            j++;
    }
    return 'N';
}

int main() {

    mp["A#"] = 2;
    mp["B#"] = 4;
    mp["C#"] = 5;
    mp["D#"] = 7;
    mp["E#"] = 9;
    mp["F#"] = 10;
    mp["G#"] = 0;
    mp["A"] = 1;
    mp["B"] = 3;
    mp["C"] = 4;
    mp["D"] = 6;
    mp["E"] = 8;
    mp["F"] = 9;
    mp["G"] = 11;
    mp["Ab"] = 0;
    mp["Bb"] = 2;
    mp["Cb"] = 3;
    mp["Db"] = 5;
    mp["Eb"] = 7;
    mp["Fb"] = 8;
    mp["Gb"] = 10;
    char aux[4];
    int aux1;
    int N, M;

    while (scanf("%d%d", &N, &M) && N + M) {
        scanf("\n");
        scanf("%s", aux);
        int val = mp[aux];
        for (int i = 0; i < N - 1; i++) {
            scanf("%s", aux);
            nota[i] = ((val - mp[aux]) % 12 + 12) % 12;
            val = mp[aux];
        }
        scanf("%s", aux);
        val = mp[aux];
        for (int i = 0; i < M - 1; i++) {
            scanf("%s", aux);
            susp[i] = ((val - mp[aux]) % 12 + 12) % 12;
            val = mp[aux];
        }
        if (M == 1)
            cout << "S\n";
        else {
            printf("%c\n", Knuth_Morris_Pratt(nota, susp, N - 1, M - 1));
        }
    }
    return 0;
}
