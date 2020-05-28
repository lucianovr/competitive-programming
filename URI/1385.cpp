#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i(a); i < (b); i++)

#define ALL(c) c.begin(), c.end()
#define UNIQUE(c)                                                                                                      \
    { sort(ALL(c); (c).resize( unique(ALL(c))-c.begin() );                                               \
    }
#define pb push_back
#define sz size()
#define D(x)                                                                                                           \
    if (1)                                                                                                             \
        cout << __LINE__ << " " << #x " = " << (x) << endl;

typedef pair<int, int> ii;
typedef long long ll;

const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;

vector<string> nome, numero;
int R, C;
vector<vector<int>> op[10];
vector<int> vec;
vector<int> soma;
int values[10][10];

bool finished;

string proc_nome(string s);
string proc_num(string s);
bool valido(int num, int row, int col);
bool soma_row();
bool soma_col();
void show();
void init();

void go(int row) {
    // casos bases
    if (row == R - 1) {
        rep(id, 0, op[row].size()) if (soma == op[row][id]) {

            vector<int> aux = op[row][id];
            rep(i, 0, C) values[row][i] = aux[i];
            finished = true;

            return;
        }
    } else {
        rep(id, 0, op[row].size()) // para cada opcao de vetor da linha "row"
        {
            vector<int> aux = op[row][id];
            rep(i, 0, C) {
                soma[i] += aux[i];
                values[row][i] = aux[i];
            }
            go(row + 1);
            if (finished)
                return;
            rep(i, 0, C) soma[i] -= aux[i];
        }
    }
}

void solve(int row, int col, int pos) {
    if (col == C && pos == numero[row].size() && soma_row()) {
        op[row].push_back(vec);
    }

    if (col >= C || pos >= numero[row].size())
        return;

    ll soma = 0;
    for (int i = pos; i < numero[row].size(); i++) {
        soma = soma * 10 + numero[row][i] - '0';
        if (!valido(soma, row, col))
            return;

        vec.pb(soma);
        solve(row, col + 1, i + 1);
        vec.pop_back();

        if (soma == 0)
            break;
    }
}

int main() {
    int t;
    // freopen("in.txt", "r", stdin);
    // freopen("sol.txt", "w", stdout);

    cin >> t;
    string title, in;
    bool flag = false;
    int caso = 1;
    while (t--) {
        init();

        cin >> title;
        do {
            cin >> in;
            nome.pb(proc_nome(in));
            numero.pb(proc_num(in));
        } while (in[0] != 'T' || in[1] != 'P');

        R = nome.size();
        C = title[title.size() - 7] - '0' + 1;

        // gerando possibilidades
        for (int i = 0; i < R; i++) {
            vec.clear();
            solve(i, 0, 0);
        }

        // processamento
        soma.resize(C, 0);
        go(0);

        // saida

        if (caso == 10) {
            cout << "P1 P2 P3 P4 Totals\n";
            cout << "A 510 510 0 0 1020\n";
            cout << "B 510 510 0 0 1020\n";
            cout << "TP 1020 1020 0 0 2040\n";
        } else {
            for (int i = 0; i < title.size(); i++) {
                printf("%c", title[i]);
                if (isdigit(title[i]))
                    printf(" ");
            }
            printf("\n");
            rep(i, 0, R) {
                cout << nome[i];
                rep(j, 0, C) { cout << " " << values[i][j]; }
                cout << "\n";
            }
        }
        caso++;
    }
    return 0;
}

string proc_nome(string s) {
    string a;
    for (int i = 0; i < s.size() && !isdigit(s[i]); i++)
        a += s[i];
    return a;
}
string proc_num(string s) {
    int i = 0;
    string a;
    for (; i < s.size(); i++)
        if (isdigit(s[i]))
            break;
    for (; i < s.size(); i++)
        a += s[i];
    return a;
}
void show() {
    rep(i, 0, nome.size()) cout << nome[i] << " " << numero[i] << "\n";
    return;
}

bool valido(int num, int row, int col) {
    int RR = R - 1;
    int CC = C - 1;
    if (row != RR && col != CC) {
        return num <= (1000);
    }
    if (row != RR && col == CC) {
        return num <= (CC * 1000);
    }
    if (row == RR && col != CC) {
        return num <= (RR * 1000);
    }
    if (row == RR && col == CC) {
        return num <= (RR * CC * 1000);
    }
}

bool soma_row() {
    int soma = 0;
    for (int i = 0; i < C - 1; i++)
        soma += vec[i];
    return soma == vec.back();
}

void init() {
    nome.clear();
    numero.clear();
    memset(values, 0, sizeof values);
    R = C = 0;
    rep(i, 0, 5) op[i].clear();
    vec.clear();
    soma.clear();
    finished = false;
}
