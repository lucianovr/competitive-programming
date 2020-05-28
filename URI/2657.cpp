#include <bits/stdc++.h>
using namespace std;

struct UnionFind {
    int n;
    vector<int> pai;
    vector<int> score;
    UnionFind(int _n, vector<int> _score) {
        n = _n;
        score = _score;

        pai.resize(n);
        for (int i = 0; i < n; i++)
            pai[i] = i;
    }

    int find(int x) {
        if (x != pai[x])
            pai[x] = find(pai[x]);
        return pai[x];
    }

    void join(int a, int b) {
        a = find(a), b = find(b);
        if (a != b) {
            pai[b] = a;
            score[a] = max(score[b], score[a]);
        }
    }
};

int main() {
    int N, M, Q;

    cin >> N >> M >> Q;

    string nome[N], a, b;
    map<string, int> mapa;
    int score[N];

    for (int i = 0; i < N; i++) {
        cin >> nome[i] >> score[i];
        mapa[nome[i]] = i;
    }

    UnionFind UF(N, vector<int>(score, score + N));

    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        UF.join(mapa[a], mapa[b]);
    }
    for (int i = 0; i < Q; i++) {
        cin >> a;
        if (mapa.count(a) == 0) {
            cout << "S\n";
        } else if (score[mapa[a]] >= 5) {
            cout << "S\n";
        } else {
            int st = UF.find(mapa[a]);
            if (UF.score[st] <= 5) {
                cout << "S\n";
            } else {
                cout << "N\n";
            }
        }
    }
    return 0;
}