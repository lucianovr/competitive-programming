#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctype.h>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define rep(i, a, b) for (int i = a; i < b; ++i)
#define pb push_back

int camada;
struct point {
    int x, y;
    void read() { scanf("%d%d", &x, &y); }
    point(int x = 0, int y = 0) : x(x), y(y) {}
};
int dist(point a) { return a.x * a.x + a.y * a.y; }

point pivot;
typedef vector<point> polygon;

int ccw(point *pivot, point *a, point *b) {
    point u = point(a->x - pivot->x, a->y - pivot->y);
    point v = point(b->x - a->x, b->y - a->y);
    int ans = u.x * v.y - u.y * v.x;
    return (ans > 0 ? 1 : (ans < 0 ? -1 : 0));
}

bool comp(point a, point b) {
    int ret = ccw(&pivot, &a, &b);
    if (ret == 0) {
        if (a.x > pivot.x) {
            return dist(point(pivot.x - a.x, pivot.y - a.y)) < dist(point(pivot.x - b.x, pivot.y - b.y));
        } else {
            return dist(point(pivot.x - a.x, pivot.y - a.y)) > dist(point(pivot.x - b.x, pivot.y - b.y));
        }
    } else
        return (ret == 1);
}

int GrahamScan(polygon P) {
    polygon H, S;
    int ans = 0;
    int N = P.size(), P0;

    while (N > 2) {
        ans++;
        P0 = 0;
        rep(i, 1, N) {
            if (P[i].y < P[P0].y || P[i].y == P[P0].y && P[i].x < P[P0].x)
                P0 = i;
        }
        pivot = P[P0];
        P[P0] = P[0];
        P[0] = pivot;

        sort(++P.begin(), P.end(), comp);

        H.clear();
        S.clear();
        H.pb(P[0]);
        H.pb(P[1]);
        int size = 2;
        rep(i, 2, N) {
            while (size >= 2 && ccw(&H[size - 2], &H[size - 1], &P[i]) == -1) {
                S.pb(H.back());
                size--;
                H.pop_back();
            }
            H.pb(P[i]);
            size++;
        }
        P = S;
        N = P.size();
        // cout << H.size() << "\n";
        // rep(j,0,H.size()){
        // 	cout << "("<<H[j].x << " , " << H[j].y<< ")\n";	}
    }
    return ans;
}

bool comp1(point a, point b) {
    if (a.x < b.x)
        return true;
    if (a.x > b.x)
        return false;
    return (a.y < b.y);
}

int main() {
    int n, camada;
    point a;
    polygon pts;

    while (scanf("%d", &n) && n) {
        rep(i, 0, n) {
            a.read();
            pts.pb(a);
        }
        sort(pts.begin(), pts.end(), comp1);

        int k = 0;
        for (int i = 1; i < n; i++)
            if (pts[i].x != pts[k].x || pts[i].y != pts[k].y)
                pts[++k] = pts[i];

        pts.resize(k + 1);
        // rep(i,0,pts.size())
        //	cout << "("<<pts[i].x << " , " << pts[i].y<< ")\n";

        camada = GrahamScan(pts);

        printf("%s\n", camada % 2 == 0 ? "Do not take this onion to the lab!" : "Take this onion to the lab!");

        // cout << "camada = " << camada << "\n";
        pts.clear();
    }
    return 0;
}
