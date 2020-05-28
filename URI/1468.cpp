#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define rep(i, a, b) for (int i(a); i < (b); i++)
#define debug(x) cout << #x << " = " << x << "\n";
#define MAXN 100000 + 10
#define MAXC 100000 + 10

#define SEG 0
#define BALAO 1
#define IN 2
#define OUT 3
#define ESCAPOU -1

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

struct ponto {
    int x, y;
    ponto(){};
    ponto(int x, int y) : x(x), y(y){};
};

struct segmento {
    ponto p1, p2, top;
    segmento(){};
    segmento(ponto P1, ponto P2, ponto Top = ponto(0, 0)) {
        p1 = P1;
        p2 = P2;
        if (p1.y > p2.y)
            top = p1;
        else
            top = p2;
    }
} seg[MAXN];

int up[MAXN + MAXC], n, c, k;

long long cross(ponto a, ponto b, ponto c) {
    long long dx1 = a.x - b.x, dy1 = a.y - b.y;
    long long dx2 = c.x - b.x, dy2 = c.y - b.y;
    return dx1 * dy2 - dx2 * dy1;
}

struct comp {
    inline bool operator()(const int i, const int j) {
        segmento sa = seg[i], sb = seg[j];
        if (sa.p1.x >= sb.p1.x)
            return cross(sb.p1, sa.p1, sb.p2) < 0;
        else
            return cross(sa.p1, sb.p1, sa.p2) > 0;
    }
};

struct evento {
    int X, tipo, id, estado;
    evento(){};
    evento(int X, int tipo, int id, int estado) : X(X), tipo(tipo), id(id), estado(estado){};
};

// estruturas de dados
set<int, comp> s; // set que mantem ordenados os segmentos
set<int, comp>::iterator it;
vector<evento> eventos; // lista com os eventos para o linesweep

bool compara_eventos(evento A, evento B) { // ordena os eventos
    if (A.X != B.X)
        return A.X < B.X; // ok

    if (A.tipo == SEG && B.tipo == BALAO) {
        if (A.estado == IN)
            return true;
        else
            return false;
    }
    if (A.tipo == BALAO && B.tipo == SEG) {
        if (B.estado == IN)
            return false;
        else
            return true;
    }
    return true;
}

int procura(int i) { // encontra segmento acima
    it = s.find(i);
    it++;
    if (it == s.end())
        return -1;
    else
        return *it;
}

void line_sweep() {

    for (int i = 0; i < eventos.size(); i++) {
        evento e = eventos[i];
        if (e.tipo == SEG) {
            if (e.estado == IN) {
                s.insert(e.id); // adiciono o segmento na estrutura

                if (seg[e.id].p1.y > seg[e.id].p2.y) // balao sai pelo segmento seg[e.id].p1
                    up[e.id] = procura(e.id);
                else if (seg[e.id].p1.y == seg[e.id].p2.y)
                    up[e.id] = 0; // bal?o fica preso nesse segmento horizontal
            }
            if (e.estado == OUT) {
                if (seg[e.id].p2.y > seg[e.id].p1.y) // balao sai pelo segmento seg[e.id].p2
                    up[e.id] = procura(e.id);
                else if (seg[e.id].p1.y == seg[e.id].p2.y)
                    up[e.id] = 0; // bal?o fica preso nesse segmento horizontal

                s.erase(e.id); // retiro o segmento da estrutura
            }
        } else if (e.tipo == BALAO) {
            if (s.empty())
                up[e.id] = ESCAPOU;
            else
                up[e.id] = *s.begin();
        }
    }
}

void caminho(ponto p, int i, int u) {
    if (u == -1)
        printf("%d\n", seg[i].top.x);
    else if (u == 0)
        printf("%d %d\n", p.x, seg[i].top.y);
    else
        caminho(seg[i].top, u, up[u]);
}

void show(evento e) {
    cout << e.X << " " << (e.tipo == SEG ? "seg" : "balao") << " " << (e.estado == IN ? "IN" : "OUT") << " " << e.id
         << "\n";
}

int main() {
    while (scanf("%d %d", &n, &c) != EOF) {

        s.clear();
        eventos.clear();

        int x1, x2, y1, y2;
        int balaox[MAXC];

        for (int i = 0; i < n; i++) {
            scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
            if (x1 > x2) {
                swap(x1, x2);
                swap(y1, y2);
            }

            seg[i] = segmento(ponto(x1, y1), ponto(x2, y2));
            eventos.push_back(evento(x1, SEG, i, IN));
            eventos.push_back(evento(x2, SEG, i, OUT));
        }

        for (int i = 0; i < c; i++) {
            scanf("%d", &x1);
            eventos.push_back(evento(x1, BALAO, i + n, -1));
            balaox[i] = x1;
        }

        sort(eventos.begin(), eventos.end(), compara_eventos);

        // rep(i,0,eventos.size())	cout << i << " -> ", show(eventos[i]);

        line_sweep();
        for (int i = 0; i < c; i++) {
            if (up[i + n] == ESCAPOU)
                printf("%d\n", balaox[i]);
            else
                caminho(ponto(balaox[i], -1), up[i + n], up[up[i + n]]);
        }
    }

    return 0;
}
