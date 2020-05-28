#include <iostream>
#include <vector>
using namespace std;
#define fi first
#define se second
#define rep(i, n) for (int i = 0; i < (n); i = i + 1)
#define tr(it, S) for (typeof(S.begin()) it = S.begin(); it != S.end(); it++)
#define all(S) (S).begin(), (S).end()
#define pb push_back
#define sz size()
int main() {

    int n, v[100], cont[100];

    cin >> n;
    rep(i, n) {
        cont[i] = 0;
        cin >> v[i];
    }

    rep(i, n) {
        if (i)
            if (v[i - 1])
                cont[i]++;
        if (i < n - 1)
            if (v[i + 1])
                cont[i]++;
        if (v[i])
            cont[i]++;
    }
    rep(i, n) cout << cont[i] << "\n";
    return 0;
}