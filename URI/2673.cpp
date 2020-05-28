#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define pb push_back
#define mk make_pair
#define debug(x) cout << __LINE__ << ": " << #x << " = " << x << endl;
#define all(c) (c).begin(), (c).end()
#define F first
#define S second
#define UNIQUE(c)                                                                                                      \
    sort(all(c));                                                                                                      \
    (c).resize(unique(all(c)) - c.begin());
#define PI 3.1415926535897932384626433832795028841971

typedef long long ll;
typedef pair<int, int> ii;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;
//(-1: x<y) (0: x==y) (1: x>y)
inline int cmp(double x, double y = 0, double tol = EPS) { return ((x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1); }

vector<string> toPosordem(string t) {
    map<string, int> priori;
    priori["|"] = priori["-"] = 1;

    vector<string> posordem;

    stringstream ss;
    ss << t;

    string str;
    stack<string> p;
    while (ss >> str) {
        if (isdigit(str[0]))
            posordem.pb(str);
        else if (str == "(") {
            p.push(str);
        } else if (p.empty()) {
            p.push(str);
        } else if (str == ")") {
            while (p.top() != "(") {
                posordem.pb(p.top());
                p.pop();
            }
            p.pop();
        } else if (priori[str] > priori[p.top()]) {
            p.push(str);
        } else {
            while (!p.empty() && priori[p.top()] >= priori[str]) {
                posordem.pb(p.top());
                p.pop();
            }
            p.push(str);
        }
    }

    while (!p.empty()) {
        posordem.pb(p.top());
        p.pop();
    }

    /*
    printf("Debug = Posordem\n");
    for (int i = 0; i < posordem.size(); i++){
            cout << posordem[i] << " ";
    } cout << "\n";
    */

    return posordem;
}

double toDouble(string num) {
    stringstream ss;
    double d;

    ss << num;
    ss >> d;
    return d;
}
double serie(double a, double b) { return a + b; }
double paralelo(double a, double b) { return (a * b) / (a + b); }
double eval(vector<string> posordem) {
    stack<double> pilha;

    for (int i = 0; i < posordem.size(); i++) {
        if (isdigit(posordem[i][0]))
            pilha.push(toDouble(posordem[i]));
        else {
            double a = pilha.top();
            pilha.pop();
            double b = pilha.top();
            pilha.pop();
            if (posordem[i] == "-") {
                pilha.push(serie(a, b));
            } else {
                pilha.push(paralelo(a, b));
            }
        }
    }
    return pilha.top();
}

int main() {

    string s;

    while (getline(cin, s)) {
        string t;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '-' || s[i] == '|' || s[i] == '(' || s[i] == ')') {
                t += " ";
                t += s[i];
                t += " ";
            } else {
                t += s[i];
            }
        }
        vector<string> posordem = toPosordem(t);
        printf("%.3lf\n", eval(posordem));
    }
    return 0;
}
