#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <string.h>
#include <utility>
#include <vector>

using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define rep(i, n) for (int i = 0; i < (n); i = i + 1)
#define tr(it, S) for (typeof(S.begin()) it = S.begin(); it != S.end(); it++)
#define all(S) (S).begin(), (S).end()
#define pb push_back
#define contem(s, x) (s.find(x) != s.end())

int Reverse(int n) {
    string s;
    // passando para string ja invertendo
    while (n) {
        s += (char(n % 10 + '0'));
        n = n / 10;
    }
    // passando string para int;
    int num = 0;
    int size = s.size();
    for (int i = 0; i < size; i++) {
        num *= 10;
        num += (s[i] - '0');
    }

    return num;
}

int main() {

    int t;
    cin >> t;

    while (t--) {
        int a;
        int b;
        bool vis[11111]; // informara se i ja foi visitado

        memset(vis, false, sizeof(vis));

        cin >> a >> b;
        queue<ii> q;
        q.push(ii(a, 0));

        while (!q.empty()) {
            int n = q.front().first;
            int dist = q.front().second;
            q.pop();

            if (n < 11111 && !vis[n]) {
                vis[n] = true;

                if (n == b) {
                    cout << dist << endl;
                    break;
                }

                int r = Reverse(n);
                q.push(ii(n + 1, dist + 1));
                q.push(ii(r, dist + 1));
            }
        }
    }
    return 0;
}
