#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <stdio.h>
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
#define contem(s, x) (s.find(x) != s.end())

int main() {
    double r, a, aa, b, bb;
    int t;
    cin >> t;
    while (t--) {
        cin >> a >> aa >> b >> bb;
        r = (bb - aa) / (b - a);
        char result[100];
        sprintf(result, "%lf", r);

        int len = strlen(result);

        for (int i = 0; i < len; i++) {
            if (result[i] == '.') {
                cout << "," << result[i + 1] << result[i + 2];
                break;
            } else
                cout << result[i];
        }
        cout << endl;
    }
    return 0;
}
