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
#define pi 3.1415926535897932384626433832795028841971

typedef long long ll;
typedef pair<int, int> ii;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;

struct pt {
    int x, y;
    pt(int x = 0, int y = 0) : x(x), y(y) {}
    pt operator+(pt q) { return pt(x + q.x, y + q.y); }
    pt operator-(pt q) { return pt(x - q.x, y - q.y); }
};
ostream &operator<<(ostream &os, const pt &p) { os << p.x << " " << p.y; }

pt A[256];
pt B[256];

int N, W, H;

bool ok(int x, int y, int w, int h) {
    for (int i = 0; i < N; i++) {
        if (max(A[i].x, x) < min(B[i].x, x + w) && max(A[i].y, y) < min(B[i].y, y + h))
            return false;
    }
    return true;
}

int main() {

    // freopen("paredein.txt", "r", stdin);
    // freopen("sol.txt", "w", stdout);

    int t;
    scanf("%d", &t);
    while (t--) {
        set<int> XX, YY;
        scanf("%d %d %d", &N, &W, &H);
        int x1, x2, y1, y2;
        XX.insert(0);
        YY.insert(0);
        for (int i = 0; i < N; i++) {
            scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

            A[i] = pt(x1, y1);
            B[i] = pt(x2, y2);
            XX.insert(x1);
            XX.insert(x2);

            YY.insert(y1);
            YY.insert(y2);
        }
        int w, h;
        scanf("%d %d", &w, &h);

        int x, y;
        for (set<int>::iterator j = YY.begin(); j != YY.end(); j++) {
            y = *j;
            if (y + h > H)
                break;
            for (set<int>::iterator i = XX.begin(); i != XX.end(); i++) {
                x = *i;
                if (x + w > W)
                    break;
                if (ok(x, y, w, h)) {
                    printf("%d %d\n", x, y);
                    goto done;
                }
            }
        }
        printf("Fail!\n");
    done:;
    }
    return 0;
}