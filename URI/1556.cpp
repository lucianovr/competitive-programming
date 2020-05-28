#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctype.h>
#include <iostream>
#include <queue>
#include <set>
#include <utility>
#include <vector>

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define rep(i, a, b) for (int i = a; i < b; ++i)
#define pb push_back

const int INF = 0x3F3F3F3F;

int sz;
set<string> s;
string seq;

void func(string c, int i, int b) {
    if (b) {
        if (s.find(c) != s.end())
            return;
        s.insert(c);
    }

    if (i == sz)
        return;

    func(c + seq[i], i + 1, 1);
    func(c, i + 1, 0);
}

int main() {
    while (cin >> seq) {
        s.clear();
        sz = seq.size();
        func("", 0, 0);

        for (set<string>::iterator it = s.begin(); it != s.end(); ++it)
            cout << *it << "\n";
        printf("\n");
    }
}