#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define debug(x) cout << #x << " = " << x << "\n";
#define all(v) v.begin(), v.end()
#define clear(v) memset(v, 0, sizeof v)
#define initpd(v) memset(v, -1, sizeof v)
#define pb push_back

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int main() {
    string a, b, c;

    cin >> a >> b >> c;
    if (c == "carnivoro") {
        cout << "aguia\n";
        return 0;
    }

    if (c == "herbivoro") {
        cout << (b == "mamifero" ? "vaca\n" : "lagarta\n");
        return 0;
    }

    if (c == "hematofago") {
        cout << (b == "inseto" ? "pulga\n" : "sanguessuga\n");
        return 0;
    }

    if (c == "onivoro") {
        cout << (b == "ave" ? "pomba\n" : (b == "mamifero" ? "homem\n" : "minhoca\n"));
        return 0;
    }

    return 0;
}
