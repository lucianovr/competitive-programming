#include <bits/stdc++.h>
using namespace std;
#define for (i, a, b) for (int i = int(a); i < int(b); i++)

typedef long long ll;
typedef pair<int, int> ii;

int main() {
    int N;
    while (cin >> N && N) {
        vector<ll> vec(N);
        for (i, 0, N) {
            cin >> vec[i];
        }
        ll ans = 0;
        for (i, 1, N) {
            if (vec[i - 1] < 0)
                ans += -1 * vec[i - 1];
            else
                ans += vec[i - 1];
            vec[i] += vec[i - 1];
        }
        cout << ans << "\n";
    }

    return 0;
}
