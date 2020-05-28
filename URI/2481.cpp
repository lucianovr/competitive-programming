#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

#define INF 0x3f3f3f3f

#define MAXN 100010

ll pd[MAXN];
ll X[MAXN];
ll C[MAXN];
int N;

int pointer;
vector<ll> M;
vector<ll> B;

bool bad(int l1, int l2, int l3) {
    /*
    intersection(l1,l2) has x-coordinate (b1-b2)/(m2-m1)
    intersection(l1,l3) has x-coordinate (b1-b3)/(m3-m1)
    set the former greater than the latter, and cross-multiply to
    eliminate division
    */
    return (B[l1] - B[l3]) * (M[l2] - M[l1]) < (B[l1] - B[l2]) * (M[l3] - M[l1]);
}

// Adds a new line (with lowest slope) to the structure
void add(long long m, long long b) {
    // First, let's add it to the end
    M.push_back(m);
    B.push_back(b);
    // If the penultimate is now made irrelevant between the antepenultimate
    // and the ultimate, remove it. Repeat as many times as necessary
    while (M.size() >= 3 && bad(M.size() - 3, M.size() - 2, M.size() - 1)) {
        M.erase(M.end() - 2);
        B.erase(B.end() - 2);
    }
}

// Returns the maximum y-coordinate of any intersection between a given vertical
// line and the lower envelope
long long query(long long x) {
    // If we removed what was the best line for the previous query, then the
    // newly inserted line is now the best for that query
    if (pointer >= M.size())
        pointer = M.size() - 1;
    // Any better line must be to the right, since query values are
    // non-decreasing
    while (pointer < M.size() - 1 && M[pointer + 1] * x + B[pointer + 1] > M[pointer] * x + B[pointer])
        pointer++;
    return M[pointer] * x + B[pointer];
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &N);

        for (int i = 1; i <= N; i++)
            scanf("%lld %lld", &X[i], &C[i]);

        M.clear();
        B.clear();
        pd[0] = X[0] = 0;
        add(0, 0);
        pointer = 0;
        for (int i = 1; i <= N; i++) {
            pd[i] = query(X[i]) - C[i];
            if (i <= N)
                add((X[i]), (pd[i] - X[i] * X[i]));
        }
        string resp = (pd[N] <= 0 ? "Perde" : "Ganha");
        if (pd[N] < 0)
            pd[N] *= -1;
        cout << resp << " " << pd[N] << "\n";
    }
    return 0;
}
