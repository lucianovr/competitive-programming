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

struct NO {
    int val;
    struct NO *esq, *dir;
};

typedef struct NO *pNo;

void inserir(struct NO **root, int num) {
    if (*root == NULL) {
        *root = new (struct NO);
        (*root)->val = num;
        (*root)->esq = NULL;
        (*root)->dir = NULL;
    } else {
        if (num > (*root)->val)
            inserir(&(*root)->dir, num);
        else
            inserir(&(*root)->esq, num);
    }
}

void dfs(struct NO **no) {
    if (*no != NULL) {
        dfs(&(*no)->esq);
        delete ((*no)->esq);
        dfs(&(*no)->dir);
        delete ((*no)->dir);
    }
}

void bfs(pNo no) {
    vector<int> v;
    queue<pNo> Q;

    Q.push(no);
    while (!Q.empty()) {
        no = Q.front();
        Q.pop();
        v.pb(no->val);
        if (no->esq != NULL)
            Q.push(no->esq);
        if (no->dir != NULL)
            Q.push(no->dir);
    }

    rep(i, 0, v.size()) {
        if (i)
            printf(" ");
        cout << v[i];
    }
    cout << "\n";
}

int main() {
    int t, q;

    cin >> t;
    for (int kkk = 0; kkk < t; kkk++) {
        cin >> q;
        int x;

        pNo root = NULL;
        while (q--) {
            cin >> x;
            inserir(&root, x);
        }
        cout << "Case " << kkk + 1 << ":\n";
        bfs(root);
        dfs(&root); // deletar apenas
        delete (root);

        cout << "\n";
    }

    return 0;
}
