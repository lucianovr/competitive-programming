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

int main() {
    int t, n;
    set<string> s;
    string idioma;

    cin >> t;
    while (t--) {
        cin >> n;
        while (n--) {
            cin >> idioma;
            s.insert(idioma);
        }
        if (s.size() == 1)
            cout << (*s.begin()) << endl;
        else
            cout << "ingles" << endl;
        s.clear();
    }

    return 0;
}