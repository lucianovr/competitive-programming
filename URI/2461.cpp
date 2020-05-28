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

int bs(int lo, int hi, const vector<int> &v, int x) {
    int mid;
    while (lo <= hi) {
        mid = (lo + hi) / 2;
        if (v[mid] == x)
            return mid;
        else if (v[mid] < x)
            lo = mid + 1;
        else
            hi = mid - 1;
    }
    return -1;
}

int main() {
    vector<int> A, B, C;
    int a, b, x, ans, pos, complemento, k;
    bool ok, achou;

    while (scanf("%d %d", &a, &b) == 2) {
        A.clear();
        B.clear();
        C.clear();

        A.resize(a);
        rep(i, 0, a) scanf("%d", &A[i]);
        sort(A.begin(), A.end());
        C.resize(b);
        for (int i = 0; i < b; i++) {
            scanf("%d", &C[i]);
        }

        ok = true;
        for (int i = 0; ok && i < b; i++) {

            pos = bs(0, a - 1, A, C[i]); // m log n
            if (pos != -1)
                ;

            else { // nao existe em A
                achou = false;
                //				for(int j=0; j < B.size() && !achou; j++){
                //					complemento = C[i] - B[j];
                //					pos = bs(0, B.size()-1, B, complemento); // m log m
                //					if(pos != -1){
                //						achou = true;
                //					}
                //				}
                int ini = 0;
                int fim = B.size() - 1;
                //	D(C[i]);
                while (ini <= fim) {
                    //	D(B[ini] + B[fim]);
                    if (B[ini] + B[fim] == C[i]) {
                        achou = true;
                        break;
                    } else if (B[ini] + B[fim] > C[i])
                        fim--;
                    else
                        ini++;
                }

                if (achou == false) {
                    ans = C[i];
                    ok = false;
                }
            }

            // ajuste
            // k=B.size()-1;
            // while(k-1>=0 && B[k-1] > B[k]){ // m
            //	swap(B[k-1], B[k]); k--;
            //}

            vector<int>::iterator it = lower_bound(ALL(B), C[i]);
            B.insert(it, C[i]);

            // rep(i,0,B.size()) cout << B[i] << " "; cout << "\n";
        }
        if (ok)
            printf("sim\n");
        else
            printf("%d\n", ans);
    }
    return 0;
}
