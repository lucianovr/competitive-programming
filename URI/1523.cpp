#include <algorithm>
#include <cstring>
#include <iostream>
#include <stack>
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
int chega[100000];
int sai[100000];

string func(int MAX, int k) {
    stack<int> pilha;
    int size = 0;

    for (int t = 0; t <= MAX; t++) {
        if (sai[t]) {
            if (pilha.top() == t) {
                size--;
                pilha.pop();
            } else
                return "Nao";
        }

        if (chega[t]) {
            if (size == k)
                return "Nao";
            pilha.push(chega[t]);
            size++;
        }
    }

    return "Sim";
}

int main() {
    int motoristas, carros, maior_tempo;

    while (cin >> motoristas >> carros && motoristas + carros) {
        memset(chega, 0, sizeof(chega));
        memset(sai, 0, sizeof(sai));
        maior_tempo = 0;

        int t1, t2;

        for (int i = 0; i < motoristas; i++) {
            cin >> t1 >> t2;
            chega[t1] = t2;
            sai[t2] = 1;
            maior_tempo = max(maior_tempo, max(t1, t2));
        }

        cout << func(maior_tempo, carros) << endl;
    }

    return 0;
}