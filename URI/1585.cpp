#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <utility>
#include <vector>

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int main() {

    int n;
    cin >> n;
    while (n--) {
        int a, b;
        cin >> a >> b;
        cout << a * b / 2 << " cm2" << endl;
    }

    return 0;
}