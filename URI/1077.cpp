#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctype.h>
#include <iostream>
#include <map>
#include <stack>
#include <stdio.h>
#include <string.h>
using namespace std;
#define fi first
#define se second
#define rep(i, n) for (int i = 0; i < (n); i = i + 1)
#define tr(it, S) for (typeof(S.begin()) it = S.begin(); it != S.end(); it++)
#define all(S) (S).begin(), (S).end()
#define pb push_back
#define sz size()
int main() {

    map<char, int> mp;
    mp['+'] = 1;
    mp['-'] = 1;
    mp['*'] = 2;
    mp['/'] = 2;
    mp['^'] = 3;
    stack<char> p;
    int n, t;
    char line[1000];

    cin >> n;
    while (n--) {
        scanf("%s", line);
        t = strlen(line);
        rep(i, t) {
            if (isdigit(line[i]) || isalpha(line[i]))
                cout << line[i];
            else if (line[i] == '(') {
                p.push(line[i]);
            } else if (p.empty()) {
                p.push(line[i]);
            } else if (line[i] == ')') {
                while (p.top() != '(') {
                    cout << p.top();
                    p.pop();
                }
                p.pop();
            } else if (mp[line[i]] > mp[p.top()]) {
                p.push(line[i]);

            } else {
                while (!p.empty() && mp[p.top()] >= mp[line[i]]) {
                    cout << p.top();
                    p.pop();
                }
                p.push(line[i]);
            }
        }
        if (!p.empty())
            while (!p.empty()) {
                cout << p.top();
                p.pop();
            }
        cout << endl;
    }
    return 0;
}
