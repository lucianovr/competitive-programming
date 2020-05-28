#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef vector<int> vi;

#define rep(i, a, b) for (int i = a; i < b; ++i)
#define pb push_back

const int INF = 0x3F3F3F3F;

char arr[1000001];
int f[1510];

int main() {

    int t, sum, sz;
    scanf("%d\n", &t);
    f[0] = 1;
    f[1] = 1;

    for (int i = 2; i < 1501; i++)
        f[i] = (f[i - 1] + f[i - 2]) % 1000;

    while (t--) {
        gets(arr);
        sz = strlen(arr);
        sum = 0;
        for (int i = 0; i < sz; i++) {
            sum *= 10;
            sum += (arr[i] - '0');
            sum = sum % 1500;
        }
        printf("%03d\n", f[sum - 1]);
    }
    return 0;
}
