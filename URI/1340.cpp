#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <queue>
#include <stack>
#include <stdio.h>
using namespace std;

int main() {
    int n, e, c;
    bool p, f, pq, flag;
    stack<int> P;
    queue<int> F;
    priority_queue<int> PQ;

    while (scanf("%d", &n) != EOF) {
        while (!P.empty())
            P.pop();
        while (!F.empty())
            F.pop();
        while (!PQ.empty())
            PQ.pop();
        p = f = pq = true;
        flag = false;
        while (n--) {
            scanf("%d%d", &c, &e);
            if (c == 1) {
                P.push(e);
                F.push(e);
                PQ.push(e);
            }
            if (c == 2) {
                if (p || f || pq) {
                    if (p) {
                        if (e != P.top())
                            p = false;
                        else
                            P.pop();
                    }
                    if (f) {
                        if (e != F.front())
                            f = false;
                        else
                            F.pop();
                    }
                    if (pq) {
                        if (e != PQ.top())
                            pq = false;
                        else
                            PQ.pop();
                    }
                }
                if (!p && !f && !pq)
                    flag = true;
            }
        }
        if (flag)
            printf("impossible\n");
        else if (pq && !p && !f)
            printf("priority queue\n");
        else if (p && !pq && !f)
            printf("stack\n");
        else if (f && !p && !pq)
            printf("queue\n");
        else
            printf("not sure\n");
    }
    return 0;
}
