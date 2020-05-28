#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <utility>
#include <vector>

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

struct Tipo {
    string name;
    int pts, gols, vit, id;
    Tipo(string _Name = "-", int _pts = 0, int _gols = 0, int _vit = 0, int _id = 0) {
        name = _Name;
        pts = _pts;
        gols = _gols;
        vit = _vit;
        id = _id;
    }
};

vector<Tipo> V;
map<string, int> mp;

bool comp(Tipo a, Tipo b) {
    if (a.pts > b.pts)
        return true;
    if (b.pts > a.pts)
        return false;
    if (a.vit > b.vit)
        return true;
    if (a.vit < b.vit)
        return false;
    if (a.gols > b.gols)
        return true;
    if (a.gols < b.gols)
        return false;
    return a.id < b.id;
}

int main() {

    int t, n, m;
    string A, B;
    int a, b, x, y;
    cin >> t;

    while (t--) {
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            cin >> A;
            mp[A] = i;
            V.push_back(Tipo(A, 0, 0, 0, i));
        }

        while (m--) {
            cin >> a >> A >> b >> B;
            x = mp[A];
            y = mp[B];
            V[x].gols += a;
            V[y].gols += b;

            if (a == b) {
                V[x].pts++;
                V[y].pts++;
            } else if (a > b) {
                V[x].pts += 3;
                V[x].vit++;
            } else {
                V[y].pts += 3;
                V[y].vit++;
            }
        }
        sort(V.begin(), V.end(), comp);

        for (int i = 0; i < n; i++) {
            cout << V[i].name << "\n";
        }

        V.clear();
        mp.clear();
    }
    return 0;
}