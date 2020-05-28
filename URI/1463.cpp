#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(c) (c).begin(), (c).end()
#define F first
#define S second
#define debug(x) cout << __LINE__ << ": " << #x << " = " << x << endl;
#define debug2(x, y) cout << #x << " = " << x << "  " << #y << " = " << y << endl;
#define pb push_back
#define mk make_pair

const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;
typedef long long ll;
typedef pair<int, int> ii;

struct no {
    char info;
    struct no *left, *right;
};
typedef struct no *ptree;

bool operador(char op) { return (op == '+' || op == '-' || op == '*' || op == '/' || op == '^'); }
void buildTree(string str) {
    stack<struct no *> pilha;
    queue<pair<ptree, int>> fila;
    ptree root;
    vector<string> rows;

    for (int i = 0; i < str.size(); i++) {
        ptree aux;
        aux = (struct no *)malloc(sizeof(struct no));
        aux->info = str[i];
        aux->left = aux->right = NULL;

        if (!operador(str[i])) {
            pilha.push(aux);
        } else {
            ptree E, D;
            D = pilha.top();
            pilha.pop();

            E = pilha.top();
            pilha.pop();

            aux->left = E;
            aux->right = D;
            pilha.push(aux);
        }
    }

    root = pilha.top();
    pilha.pop();
    fila.push({root, 0});

    while (!fila.empty()) {
        ptree node;
        node = fila.front().first;
        int dist = fila.front().second;
        fila.pop();

        if (dist == rows.size()) {
            rows.push_back("");
        }
        rows[dist] += node->info;

        if (node->left != NULL)
            fila.push({node->left, dist + 1});
        if (node->right != NULL)
            fila.push({node->right, dist + 1});
    }

    for (int i = 0; i < rows.size(); i++) {
        printf("Nivel %d: %s\n", i, rows[i].c_str());
    }
}

string infixToPosfix(string express) {
    map<char, int> prior;
    prior['+'] = 1;
    prior['-'] = 1;
    prior['*'] = 2;
    prior['/'] = 2;
    prior['^'] = 3;

    stack<char> pilha;
    stringstream ss;
    string posfix;

    rep(i, 0, express.size()) {
        if (express[i] == ' ')
            continue;

        if (isdigit(express[i]) || isalpha(express[i])) {
            ss << express[i];
            continue;
        }

        if (pilha.empty() || express[i] == '(') {
            pilha.push(express[i]);
            continue;
        }

        if (express[i] == ')') {
            while (pilha.top() != '(') {
                ss << pilha.top();
                pilha.pop();
            }
            pilha.pop();
            continue;
        }

        if (prior[express[i]] > prior[pilha.top()]) {
            pilha.push(express[i]);
        } else {
            while (!pilha.empty() && prior[pilha.top()] >= prior[express[i]]) {
                ss << pilha.top();
                pilha.pop();
            }
            pilha.push(express[i]);
        }
    }

    while (!pilha.empty()) {
        ss << pilha.top();
        pilha.pop();
    }
    ss >> posfix;
    return posfix;
}

int main() {

    string str;
    bool flag = 0;
    while (getline(cin, str)) {

        if (flag)
            printf("\n");
        flag = true;

        string resp;
        resp = infixToPosfix(str);
        // cout << resp << "\n";
        buildTree(resp);
    }

    return 0;
}
