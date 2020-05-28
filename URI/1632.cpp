#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctype.h>
#include <iostream>
#include <map>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

int main() {
    int v[26];
    for (int i = 0; i < 26; i++)
        v[i] = 2;

    char letters[] = {"aeios"};

    for (int i = 0; i < 6; i++)
        v[letters[i] - 'a'] = 3;

    int t;
    scanf("%d", &t);
    char text[20];

    while (t--) {
        scanf("%s", text);
        // printf("%s\n", text);
        int size = strlen(text);
        long long ans = 1;

        for (int i = 0; i < size; i++)
            ans = ans * v[tolower(text[i]) - 'a'];

        printf("%lld\n", ans);
    }
    return 0;
}