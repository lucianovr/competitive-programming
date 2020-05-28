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

typedef long long int ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define rep(i, a, b) for (int i = a; i < b; ++i)
#define pb push_back

const int INF = 0x3F3F3F3F;

int gcd(int a, int b) {
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

int main() {

    int a, b, c;

    while (scanf("%d%d%d", &a, &b, &c) == 3) {
        if (a > b) {
            swap(a, b);
        }
        if (b > c) {
            swap(b, c);
        }

        if (a > b) {
            swap(a, b);
        }

        if (b > c) {
            swap(b, c);
        }

        if (c * c == a * a + b * b) {
            if (gcd(a, gcd(b, c)) == 1)
                printf("tripla pitagorica primitiva\n");
            else
                printf("tripla pitagorica\n");
        } else
            printf("tripla\n");
    }

    return 0;
}
