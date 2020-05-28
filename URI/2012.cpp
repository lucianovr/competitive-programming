#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(c) (c).begin(), (c).end()
#define F first
#define S second
#define debug(x) cout << __LINE__ << ": " << #x << " = " << x << endl;
#define debug2(x, y) #x << " = " << x << "  " << #y << " = " << y << endl;
#define pb push_back
#define mk make_pair

const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;
typedef long long ll;
typedef pair<int, int> ii;

int R, C;
int a[110][110], tmp[110][110], faces;
int vis[110][110];
int di[] = {0, 0, -1, 1}, dj[] = {-1, 1, 0, 0};

bool dentro(int i, int j) { return i >= 1 && i <= R && j >= 1 && j <= C; }

void dfs(int i, int j) {
    if (vis[i][j])
        return;
    vis[i][j] = 1;
    rep(k, 0, 4) {
        int ii = i + di[k];
        int jj = j + dj[k];
        if (dentro(ii, jj) && a[ii][jj] == a[i][j])
            dfs(ii, jj);
    }
}

int ncomp() {
    int comp = 0;
    memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= R; i++)
        for (int j = 1; j <= C; j++)
            if (vis[i][j] == 0) {
                comp++;
                dfs(i, j);
            }
    return comp;
}

void contLeft() { // conta as faces da esquerda
    // linha (i=0) esta zerada
    /*cout<< "\n";
    for (int i=0; i<=R+1; i++){
            for (int j=0; j<=C+1; j++) cout << a[i][j] << " ";
            cout << "\n";
    } cout << "\n";
    */
    int aux = 0;
    for (int i = 1; i <= R; i++)
        for (int j = 1; j <= C; j++) {
            if (a[i][j] < a[i][j - 1])
                aux++;
            if (a[i][j] < a[i][j - 1] && a[i - 1][j] < a[i - 1][j - 1])
                if (a[i][j - 1] > a[i - 1][j] && a[i - 1][j - 1] > a[i][j])
                    aux--;
        }
    // debug(aux);
    faces += aux;
}

void rot() { // rotaciona a matriz
    memset(tmp, 0, sizeof tmp);
    for (int i = 1; i <= R; i++)
        for (int j = 1; j <= C; j++) {
            tmp[C - j + 1][i] = a[i][j];
        }
    memset(a, 0, sizeof a);
    swap(R, C);
    for (int i = 1; i <= R; i++)
        for (int j = 1; j <= C; j++)
            a[i][j] = tmp[i][j];
}

int main() {

    while (cin >> R >> C) {

        memset(a, 0, sizeof a);
        for (int i = 1; i <= R; i++)
            for (int j = 1; j <= C; j++)
                cin >> a[i][j];

        faces = ncomp(); // faces superiores

        contLeft();
        rot();
        contLeft();
        rot();
        contLeft();
        rot();
        contLeft();

        cout << faces + 5 << "\n"; // mais as faceis dos lados
    }
    return 0;
}
