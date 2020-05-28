#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i(a); i < (b); i++)
#define all(c) (c).begin(), (c).end()
#define fst first
#define snd second
#define db(x) cerr << __LINE__ << ": " << #x << " = " << x << endl

#define pb push_back
#define mp make_pair

const int INF = 0x3f3f3f3f;
typedef long long ll;
typedef pair<int, int> ii;

map<int, string> MP;

void preencheMapa() {
    MP.insert(pair<int, string>(0, "zero"));
    MP.insert(pair<int, string>(1, "um"));
    MP.insert(pair<int, string>(2, "dois"));
    MP.insert(pair<int, string>(3, "tres"));
    MP.insert(pair<int, string>(4, "quatro"));
    MP.insert(pair<int, string>(5, "cinco"));
    MP.insert(pair<int, string>(6, "seis"));
    MP.insert(pair<int, string>(7, "sete"));
    MP.insert(pair<int, string>(8, "oito"));
    MP.insert(pair<int, string>(9, "nove"));
    MP.insert(pair<int, string>(10, "dez"));
    MP.insert(pair<int, string>(11, "onze"));
    MP.insert(pair<int, string>(12, "doze"));
    MP.insert(pair<int, string>(13, "treze"));
    MP.insert(pair<int, string>(14, "quatorze"));
    MP.insert(pair<int, string>(15, "quinze"));
    MP.insert(pair<int, string>(16, "dezesseis"));
    MP.insert(pair<int, string>(17, "dezessete"));
    MP.insert(pair<int, string>(18, "dezoito"));
    MP.insert(pair<int, string>(19, "dezenove"));
    MP.insert(pair<int, string>(20, "vinte"));
    MP.insert(pair<int, string>(30, "trinta"));
    MP.insert(pair<int, string>(40, "quarenta"));
    MP.insert(pair<int, string>(50, "cinquenta"));
    MP.insert(pair<int, string>(60, "sessenta"));
    MP.insert(pair<int, string>(70, "setenta"));
    MP.insert(pair<int, string>(80, "oitenta"));
    MP.insert(pair<int, string>(90, "noventa"));
    MP.insert(pair<int, string>(100, "cem"));
    MP.insert(pair<int, string>(101, "cento"));
    MP.insert(pair<int, string>(200, "duzentos"));
    MP.insert(pair<int, string>(300, "trezentos"));
    MP.insert(pair<int, string>(400, "quatrocentos"));
    MP.insert(pair<int, string>(500, "quinhentos"));
    MP.insert(pair<int, string>(600, "seiscentos"));
    MP.insert(pair<int, string>(700, "setecentos"));
    MP.insert(pair<int, string>(800, "oitocentos"));
    MP.insert(pair<int, string>(900, "novecentos"));
    MP.insert(pair<int, string>(1000, "mil"));
}

#define E "e"

int main() {
#ifndef ONLINE_JUDGE
    // freopen("_in.txt", "r", stdin);
    freopen("luciano.txt", "w", stdout);
#endif
    preencheMapa();

    ll n;
    ll x, D[6];
    vector<string> resp;

    while (cin >> n) {
        if (n <= 20) {
            cout << MP[n] << "\n";
            continue;
        }
        ll p10 = 1;
        rep(i, 0, 6) {
            D[i] = (n % 10) * p10;
            p10 *= 10;
            n /= 10;
        }
        /*
        rep(i,0,6){
                cout << D[i] << " ";
        } cout <<"\n";
        */
        resp.clear();
        ll V;
        V = D[5] + D[4] + D[3];
        if (V > 0) {
            if (V == 100000)
                resp.pb("cem mil");
            else if (V > 100000 && V < 200000) {
                resp.pb("cento");
                if (D[4] + D[3] >= 10000 && D[4] + D[3] < 20000) {
                    if (D[5])
                        resp.pb(E);
                    resp.pb(MP[(D[4] + D[3]) / 1000]);
                } else {
                    if (D[4])
                        resp.pb(E), resp.pb(MP[D[4] / 1000]);
                    if (D[3])
                        resp.pb(E), resp.pb(MP[D[3] / 1000]);
                }
                resp.pb("mil");
            } else if (V == 1000)
                resp.pb("mil");
            else {

                if (V >= 10000 && V < 20000) {
                    resp.pb(MP[V / 1000]);
                } else {
                    if (D[5])
                        resp.pb(MP[D[5] / 1000]);
                    V = D[4] + D[3];
                    if (V >= 10000 && V < 20000) {
                        if (D[5])
                            resp.pb(E);
                        resp.pb(MP[(D[4] + D[3]) / 1000]);
                    } else {
                        if (D[4]) {
                            if (D[5])
                                resp.pb(E);
                            resp.pb(MP[D[4] / 1000]);
                        }
                        if (D[3]) {
                            if (D[5] + D[4])
                                resp.pb(E);
                            resp.pb(MP[D[3] / 1000]);
                        }
                    }
                }
                resp.pb("mil");
            }
            if (D[2] == 0 && D[1] + D[0] || D[2] != 0 && (D[1] + D[0] == 0))
                resp.pb(E);
        }

        V = D[2] + D[1] + D[0];
        if (V == 100)
            resp.pb("cem");
        else {
            if (V > 100 && V < 200)
                resp.pb("cento");
            else if (D[2])
                resp.pb(MP[D[2]]);

            V = D[1] + D[0];
            if (V >= 10 && V < 20) {
                if (D[2])
                    resp.pb(E);
                resp.pb(MP[V]);
            } else {
                if (D[1]) {
                    if (D[2])
                        resp.pb(E);
                    resp.pb(MP[D[1]]);
                }
                if (D[0]) {
                    if (D[2] + D[1])
                        resp.pb(E);
                    resp.pb(MP[D[0]]);
                }
            }
        }
        // 5 4 3 2 1 0
        // C D U c d u
        rep(i, 0, resp.size()) {
            if (i)
                cout << " ";
            cout << resp[i];
        }
        cout << "\n";
    }
    return 0;
}