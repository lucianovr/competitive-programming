#include <bits/stdc++.h>

using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
#define pb push_back

#include <bits/stdc++.h>
using namespace std;

const double EPS = 1e-9;
inline int cmp(double x, double y = 0, double tol = EPS) { return ((x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1); }

struct point {
    double x, y;
    point(double x = 0, double y = 0) : x(x), y(y) {}
    point operator+(point q) { return point(x + q.x, y + q.y); }
    point operator-(point q) { return point(x - q.x, y - q.y); }
    point operator*(double t) { return point(x * t, y * t); }
    point operator/(double t) { return point(x / t, y / t); }
    point operator/(point q) { // divisao de num complexos
        return point(x * q.x + y * q.y, y * q.x - x * q.y) / q.norma2();
    }
    double norma2() { return (*this) * (*this); } // |u|^2
    double operator*(point q) { return x * q.x + y * q.y; }
    double operator%(point q) { return x * q.y - y * q.x; }
    int cmp(point q) const {
        if (int t = ::cmp(x, q.x))
            return t;
        return ::cmp(y, q.y);
    }
    bool operator==(point q) const { return cmp(q) == 0; };
    bool operator!=(point q) const { return cmp(q) != 0; };
    bool operator<(point q) const { return cmp(q) < 0; };
};
ostream &operator<<(ostream &os, const point &p) { os << "(" << p.x << "," << p.y << ")"; }
#define vec(a, b) (b - a)
typedef vector<point> polygon;

// Rotaciona um ponto em relacao a origem
point RotateCCW90(point p) { return point(-p.y, p.x); }
point RotateCW90(point p) { return point(p.y, -p.x); }

// rotaciona um ponto P em A graus no sentido anti-horario.
// para rotacionar no sentido horario, basta A ser negativo
point RotateCCW(point p, double A) {
    A = (A / 180.0) * acos(-1.0); // convertendo para radianos
    return point(p.x * cos(A) - p.y * sin(A), p.x * sin(A) + p.y * cos(A));
}

// tamanho de um vetor
double abs(point u) { return sqrt(u * u); }

/*Decide se P->Q->R forma um giro a esquerda, direita ou se sao
colineares. Retorna 1 se R estiver a esquerda da reta PQ. -1 se
estiver a direta e 0 se forem colineares.*/
int ccw(point p, point q, point r) { return cmp(vec(p, q) % (vec(p, r))); }

//	Projeta o vetor A sobre a direcao do vetor B
point project(point a, point b) { return b * ((a * b) / (b * b)); }

// Retorna a projecao do ponto P sobre reta definida por [A,B]
point projectPointLine(point p, point a, point b) { return p + project(p - a, b - a); }

//	Retorna o angulo entre os vetores AB e AC
double arg(point B, point A, point C) {
    point u = vec(A, B), v = vec(A, C);
    return atan2(u % v, u * v);
}

// verifica se x esta entre [l,r] *Tente evitar usar double!
bool is_in(double l, double r, double x) {
    if (l > r)
        swap(l, r);
    return (l <= x + EPS) && (x - EPS <= r);
}

//	Determina se P esta entre o segmento fechado [A,B], inclusive
bool between(point p, point a, point b) {
    if (ccw(p, a, b) != 0)
        return false;
    else
        return is_in(a.x, b.x, p.x) && is_in(a.y, b.y, p.x);
}

// (Opcao2) Determina se P esta entre o segmento fechado [A,B], inclusive
// Se vc nao entendeu a anterior ou se acha que ela pode ser o problema
// use essa. Se nao der certo, tente mudar a precisao usada em cmp() para 1e-15
bool between2(point p, point a, point b) { return cmp(abs(p - a) + abs(p - b), abs(a - b)) == 0; }

// Distancia de ponto P para reta que passa por [A,B]
// armazena em C (por ref) o ponto projecao de P na reta
double distancePointLine(point p, point a, point b, point &c) {
    c = projectPointLine(p, a, b);
    return fabs((b - a) % (p - a)) / abs(a - b); // or abs(p-c);
}

// Distancia de ponto P ao segmento [A,B]
// armazena em C (por ref) o ponto de projecao de P em [A,B]
// se este ponto sair do segmento, eh retornado o mais proximo
double distancePointSeg(point p, point a, point b, point &c) {
    if ((b - a) * (p - a) <= 0) {
        c = a;
        return abs(a - p);
    }
    if ((a - b) * (p - b) <= 0) {
        c = b;
        return abs(b - p);
    }

    c = projectPointLine(p, a, b);
    return fabs((b - a) % (p - a)) / abs(a - b); // or abs(p-c);
}

// Distancia entre (x,y,z) e plano ax+by+cz=d
double distancePointPlane(double x, double y, double z, double a, double b, double c, double d) {
    return fabs(a * x + b * y + c * z - d) / sqrt(a * a + b * b + c * c);
}

// Determina se os segmentos [A, B] e [C, D] se tocam
bool seg_intersect(point a, point b, point c, point d) {
    int d1, d2, d3, d4;
    d1 = ccw(c, a, d);
    d2 = ccw(c, b, d);
    d3 = ccw(a, c, b);
    d4 = ccw(a, d, b);
    if (d1 * d2 == -1 && d3 * d4 == -1)
        return true;
    if (d1 == 0 && between(c, a, d))
        return true;
    if (d2 == 0 && between(c, b, d))
        return true;
    if (d3 == 0 && between(a, c, b))
        return true;
    if (d4 == 0 && between(a, d, b))
        return true;
    return false;
}

// Encontra a interseccao das retas (p-q) e (r-s) assumindo que existe
// apenas 1 intereccao
// Se for entre segmentos, verificar se interseptam primeiro
point line_intersect(point p, point q, point r, point s) {
    point a = q - p, b = s - r, c = point(p % q, r % s);
    return point(point(a.x, b.x) % c, point(a.y, b.y) % c) / (a % b);
}

// determine if lines from a to b and c to d are parallel or collinear
bool LinesParallel(point a, point b, point c, point d) { // Nao testado
    return fabs((b - a) % (c - d)) < EPS;
}

bool LinesCollinear(point a, point b, point c, point d) { // Nao testado
    return LinesParallel(a, b, c, d) && fabs((a - b) % (a - c)) < EPS && fabs((c - d) % (c - a)) < EPS;
}

// Retas, equacao na forma: ax+by+c = 0; com (b=1)
struct line {
    double a, b, c;
    line() {}
    line(double m, point p) { // coeficiente e ponto sobre reta
        if (cmp(m) == 0)
            a = 0;
        else
            a = -m;
        b = 1;
        c = m * p.x - p.y;
    }
    line(point p1, point p2) { // dois pontos que estao na reta
        if (fabs(p1.x - p2.x) < EPS) {
            a = 1;
            b = 0;
            c = -p1.x;
        } else {
            a = -(double)(p1.y - p2.y) / (p1.x - p2.x);
            b = 1;
            c = -(double)(a * p1.x) - p1.y;
        }
    }
    bool parallelTo(line s) { // verdadeiro se forem paralelas
        return cmp(a, s.a) == 0 && cmp(b, s.b) == 0;
    }
    bool sameAs(line s) { // verdadeiro se forem retas coincidentes
        return this->parallelTo(s) && cmp(c, s.c) == 0;
    }
    point intersectPoint(line s) {
        point p;
        p.x = (s.b * c - b * s.c) / (s.a * b - a * s.b);
        if (fabs(b) > EPS)
            p.y = -(a * p.x + c) / b;
        else
            p.y = -(s.a * p.x + s.c) / s.b;
        return p;
    }
};

//	Menor distancia entre dois pontos numa esfera de raio r
//	lat = [-90,90]; long = [-180,180]
double spherical_distance(double lt1, double lo1, double lt2, double lo2, double r) {
    double pi = acos(-1);
    double a = pi * (lt1 / 180.0), b = pi * (lt2 / 180.0);
    double c = pi * ((lo2 - lo1) / 180.0);
    return r * acos(sin(a) * sin(b) + cos(a) * cos(b) * cos(c));
}

// Heron's formula - area do triangulo(a,b,c) -1 se nao existe
double area_heron(double a, double b, double c) {
    if (a < b)
        swap(a, b);
    if (a < c)
        swap(a, c);
    if (b < c)
        swap(b, c);
    if (a > b + c)
        return -1;
    return sqrt((a + (b + c)) * (c - (a - b)) * (c + (a - b)) * (a + (b - c)) / 16.0);
}

/*Dado dois pontos (A, B) de uma circunferencia e seu raio R, eh
possivel obter seus possiveis centros (C1 e C2). Para obter o
outro centro, basta inverter os paramentros */
bool circle2PtsRad(point a, point b, double r, point &c) {
    point aux = a - b;
    double d = aux * aux;
    double det = r * r / d - 0.25;
    if (det < 0.0)
        return false;
    double h = sqrt(det);
    c.x = (a.x + b.x) * 0.5 + (a.y - b.y) * h;
    c.y = (a.y + b.y) * 0.5 + (b.x - a.x) * h;
    return true;
}

struct tree {
    point centro;
    double raio;
    double dist_tangente;
    double angulo, alfa, beta;
    double maior_visivel;

    vector<pair<double, double>> ranges;

    tree(point p, double r) : centro(p), raio(r) {
        dist_tangente = sqrt(centro.norma2() - raio * raio);
        angulo = atan2(centro.y, centro.x) * 180.0 / M_PI;
        maior_visivel = sqrt(centro.norma2()) - raio;

        if (angulo < 0)
            angulo += 360;
        double abertura = asin(raio / abs(centro)) * 180.0 / M_PI;
        alfa = angulo - abertura;
        beta = angulo + abertura;

        if (alfa <= 0)
            ranges.pb(make_pair(360 + alfa, 360)), ranges.pb(make_pair(0, beta));
        else if (beta > 360)
            ranges.pb(make_pair(alfa, 360)), ranges.pb(make_pair(0, beta - 360));
        else
            ranges.pb(make_pair(alfa, beta));
    }

    bool operator<(tree q) const { return dist_tangente < q.dist_tangente; };
};
ostream &operator<<(ostream &os, const tree &t) { os << t.centro << " r" << t.raio; }

vector<tree> T;
vector<pair<double, double>> ranges;

void read(int N) {
    T.clear();
    ranges.clear();

    rep(i, 0, N) {
        point p;
        double r;
        cin >> p.x >> p.y >> r;
        T.push_back(tree(p, r));
    }
}

bool coberto(double a, double b) {
    for (int i = 0; i < ranges.size(); i++) {
        double esq = ranges[i].first, dir = ranges[i].second;
        if (a >= esq && b <= dir)
            return true;
    }
    return false;
}

bool coberto(vector<pair<double, double>> R) {
    rep(i, 0, R.size()) {
        if (!coberto(R[i].first, R[i].second))
            return false;
    }
    return true;
}

void update() {
    sort(ranges.begin(), ranges.end());

    vector<pair<double, double>> aux;
    aux.push_back(ranges[0]);
    int k = aux.size() - 1;
    rep(i, 1, ranges.size()) {
        if (ranges[i].first <= aux[k].second && ranges[i].second >= aux[k].second)
            aux[k].second = ranges[i].second;
        else if (ranges[i].first > aux[k].second) {
            aux.pb(ranges[i]);
            k++;
        }
    }
    ranges = aux;
}

void solve() {
    sort(T.begin(), T.end());

    double maior = -1;
    rep(i, 0, T.size()) {
        if (coberto(T[i].ranges)) {
            // cout <<"coberto " << T[i] << "\n";
            continue;
        } else {
            maior = max(maior, T[i].maior_visivel);
            rep(j, 0, T[i].ranges.size()) ranges.push_back(T[i].ranges[j]);
            update();
        }
    }
    printf("%.3lf\n", maior);
}

int main() {
    int N;
    while (cin >> N && N) {
        read(N);
        solve();
    }
    return 0;
}
