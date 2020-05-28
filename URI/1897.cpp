#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < b; i++)
#define mp make_pair
#define pb push_back
#define contains(s, x) (s.find(x) != s.end())

const int oo = 0x3f3f3f3f;
const double EPS = 1e-9;

int dist[1000000 * 2 + 10];
int off = 1000000;

int main() {

    int N, M;
    while (cin >> N >> M) {
        memset(dist, -1, sizeof dist);
        dist[N + off] = 0;

        queue<int> q;
        q.push(N);

        while (!q.empty()) {
            N = q.front();
            q.pop();
            //	cout << "N = " << N << "\n";
            //	getchar();
            int NN;

            NN = N * 2;
            if (abs(NN) < 100000 && dist[NN + off] == -1) {
                dist[NN + off] = dist[N + off] + 1;
                q.push(NN);
            }
            NN = N * 3;
            if (abs(NN) < 100000 && dist[NN + off] == -1) {
                dist[NN + off] = dist[N + off] + 1;
                q.push(NN);
            }
            NN = N / 2;
            if (abs(NN) < 100000 && dist[NN + off] == -1) {
                dist[NN + off] = dist[N + off] + 1;
                q.push(NN);
            }
            NN = N / 3;
            if (abs(NN) < 100000 && dist[NN + off] == -1) {
                dist[NN + off] = dist[N + off] + 1;
                q.push(NN);
            }
            NN = N + 7;
            if (abs(NN) < 100000 && dist[NN + off] == -1) {
                dist[NN + off] = dist[N + off] + 1;
                q.push(NN);
            }
            NN = N - 7;
            if (abs(NN) < 100000 && dist[NN + off] == -1) {
                dist[NN + off] = dist[N + off] + 1;
                q.push(NN);
            }
        }

        cout << dist[M + off] << "\n";
    }
    return 0;
}
