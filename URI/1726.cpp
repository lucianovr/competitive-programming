#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a, c = b; i < c; ++i)
#define debug(x) cout << #x << " = " << x << "\n";
#define all(v) v.begin(), v.end()
#define pb push_back

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

stack<char> p;
string s;
vector<string> v;

bool isOperand(char r) { return r == '+' || r == '-' || r == '*'; }

int sum(int a, int b) {
    a = a | b;
    return a;
}

int dif(int a, int b) {
    rep(i, 0, 26) if ((a & 1 << i) && (b & 1 << i)) a &= ~(1 << i);
    return a;
}

int inters(int a, int b) {
    a = a & b;
    return a;
}

int main() {
    while (cin >> s) {
        v.clear();
        rep(i, 0, s.size()) {
            if (s[i] == '{') {
                string r;
                i++;
                while (s[i] != '}')
                    r += s[i++];
                v.pb(r);
            } else {
                if (s[i] == '(')
                    p.push(s[i]);
                else if (s[i] == ')') {
                    while (!p.empty() && p.top() != '(') {
                        if (p.top() == '+')
                            v.pb("+");
                        else if (p.top() == '-')
                            v.pb("-");
                        else if (p.top() == '*')
                            v.pb("*");
                        p.pop();
                    }
                    p.pop();
                } else if (s[i] == '+' || s[i] == '-') {
                    while (!p.empty() && isOperand(p.top())) {
                        if (p.top() == '+')
                            v.pb("+");
                        else if (p.top() == '-')
                            v.pb("-");
                        else if (p.top() == '*')
                            v.pb("*");
                        p.pop();
                    }
                    p.push(s[i]);
                } else if (s[i] == '*') {
                    while (!p.empty() && p.top() == '*') {
                        if (p.top() == '+')
                            v.pb("+");
                        else if (p.top() == '-')
                            v.pb("-");
                        else if (p.top() == '*')
                            v.pb("*");
                        p.pop();
                    }
                    p.push(s[i]);
                }
            }
        }

        while (!p.empty()) {
            if (p.top() == '+')
                v.pb("+");
            else if (p.top() == '-')
                v.pb("-");
            else if (p.top() == '*')
                v.pb("*");
            p.pop();
        }
        stack<string> R;

        rep(j, 0, v.size()) {
            if (v[j] != "+" && v[j] != "-" && v[j] != "*")
                R.push(v[j]);
            else {
                string a, b;
                a = R.top();
                R.pop();
                b = R.top();
                R.pop();

                int A, B;
                A = B = 0;
                rep(i, 0, a.size()) A |= (1 << (a[i] - 'A'));
                rep(i, 0, b.size()) B |= (1 << (b[i] - 'A'));

                if (v[j] == "+")
                    B = sum(B, A);
                if (v[j] == "-")
                    B = dif(B, A);
                if (v[j] == "*")
                    B = inters(B, A);

                b.clear();
                rep(i, 0, 26) if (B & 1 << i) b += char('A' + i);

                R.push(b);
            }
        }
        cout << "{" << R.top() << "}\n";
    }
    return 0;
}
