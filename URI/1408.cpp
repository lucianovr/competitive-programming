#include <algorithm>
#include <cstring>
#include <iostream>
#include <map>
#include <stdio.h>
#include <string.h>
#include <utility>
#include <vector>
#define f first
#define s second
#define rdi(a) scanf("%d", &a)
#define rdii(a, b) scanf("%d%d", &a, &b)
#define ulli unsigned long long int
#define inf 100001
using namespace std;

int main() {

    int n, m, ele, last, j, cont, me;
    map<int, pair<bool, int>> mp;
    vector<int> vec;
    bool flag;

    while (scanf("%d%d", &n, &m) && n + m) {
        mp.clear();
        vec.clear();
        me = inf;
        for (int i = 0; i < m; i++) {
            scanf("%d", &ele);
            mp[ele] = make_pair(true, i);
            vec.push_back(ele);
        }
        for (int i = 0; i < m; i++) {
            last = vec[i] + n - 1;
            if (mp[last].f)
                cont = mp[last].s - i + 1;
            else {
                flag = true;
                for (int k = i; k < m; k++) {
                    if (vec[k] > last) {
                        cont = mp[vec[k]].s - i;
                        flag = false;
                        break;
                    }
                }
                if (flag)
                    cont = m - i;
            }
            cont = n - cont;
            if (cont < me) {
                me = cont;
                if (!me)
                    break;
            }
        }
        printf("%d\n", me);
    }
    return 0;
}
