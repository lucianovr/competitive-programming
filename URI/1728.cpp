#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a, c = b; i < c; ++i)
#define debug(x) cout << #x << " = " << x << "\n";
#define all(v) v.begin(), v.end()

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int reverseToint(char s[]) {
    int ans = 0;
    for (int i = strlen(s) - 1; i >= 0; i--) {
        ans *= 10;
        ans += (s[i] - '0');
    }
    return ans;
}

int main() {

    char line[30], a[10], b[10], c[10];
    while (scanf("%s", line) != EOF) {
        if (strcmp(line, "0+0=0") == 0)
            break;
        int i, j;

        i = j = 0;
        while (line[i] != '+')
            a[j++] = line[i++];
        i++;
        a[j] = '\0';
        j = 0;
        while (line[i] != '=')
            b[j++] = line[i++];
        i++;
        b[j] = '\0';
        j = 0;
        while (line[i] != '\0')
            c[j++] = line[i++];
        c[j] = '\0';

        int A = reverseToint(a);
        int B = reverseToint(b);
        int C = reverseToint(c);

        if (C == A + B)
            printf("True\n");
        else
            printf("False\n");
    }

    printf("True\n");

    return 0;
}
