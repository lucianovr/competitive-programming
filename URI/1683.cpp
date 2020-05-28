#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <stdio.h>
#include <string.h>
#include <utility>
#include <vector>
using namespace std;

typedef pair<int, int> ii;

int main() {
    int n;
    while (cin >> n && n) {
        long long v[n];
        stack<int> s;
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        long long area = -1;
        int top;
        for (int i = 0; i < n;) {
            if (s.empty() || v[s.top()] <= v[i])
                s.push(i++);
            else {
                top = s.top();
                s.pop();
                if (s.empty())
                    area = max(area, v[top] * i);
                else
                    area = max(area, v[top] * (i - s.top() - 1));
            }
        }
        int i = n;
        while (!s.empty()) {
            top = s.top();
            s.pop();
            if (s.empty())
                area = max(area, v[top] * i);
            else
                area = max(area, v[top] * (i - s.top() - 1));
        }

        cout << area << "\n";
    }
    return 0;
}
