#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define debug(x) cout << #x << " = " << x << "\n";
#define all(v) v.begin(), v.end()
#define pb push_back

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

string func(string A) {
    int len = A.size();
    if (len > 1) {
        if (A[len - 1] == 'y') {
            switch (A[len - 2]) {
            case 'a':
                return A + "s";
            case 'e':
                return A + "s";
            case 'i':
                return A + "s";
            case 'o':
                return A + "s";
            case 'u':
                return A + "s";
            }
            A[len - 1] = 'i';
            A += "es";
            return A;
        }
        if (A[len - 1] == 'h' && A[len - 2] == 'c' || A[len - 2] == 's')
            return A + "es";
    }

    if (A[len - 1] == 'o' || A[len - 1] == 's' || A[len - 1] == 'x')
        return A + "es";

    return A + "s";
}

int main() {
    map<string, string> mp;
    string A, B;
    int N, L;

    while (cin >> L >> N) {
        mp.clear();

        rep(i, 0, L) {
            cin >> A >> B;
            mp[A] = B;
        }

        while (N--) {
            cin >> A;
            if (mp[A] != "") {
                cout << mp[A] << "\n";
            } else
                cout << func(A) << "\n";
        }
    }

    return 0;
}
