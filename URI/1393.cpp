#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <string.h>
#include <string>
#include <utility>
#include <vector>
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define rep(i, n) for (int i = 0; i < (n); i = i + 1)
#define tr(it, S) for (typeof(S.begin()) it = S.begin(); it != S.end(); it++)
#define all(S) (S).begin(), (S).end()
#define setar(S, x) memset(S, x, sizeof(S))
#define pb push_back
#define sz size()
int pd[50];

int main() {
    int n;
    while (cin >> n && n) {
        pd[n] = 0;
        pd[n - 1] = 1;
        if (n - 2 >= 0)
            pd[n - 2] = 2;
        for (int i = n - 3; i >= 0; i--)
            pd[i] = pd[i + 1] + pd[i + 2];
        cout << pd[0] << endl;
    }
    return 0;
}
