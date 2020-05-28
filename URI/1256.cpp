#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>
#define MAX 101
using namespace std;

int main() {
    vector<int> v[MAX];
    int m, c, T, num;
    cin >> T;
    for (int t = 0; t < T; t++) {
        if (t)
            cout << endl;
        cin >> m >> c;
        for (int i = 0; i < c; i++) {
            cin >> num;
            v[num % m].push_back(num);
        }
        for (int i = 0; i < m; i++) {
            cout << i << " -> ";
            reverse(v[i].begin(), v[i].end());
            while (!v[i].empty()) {
                cout << v[i].back() << " -> ";
                v[i].pop_back();
            }
            cout << "\\\n";
        }
    }
    // system("PAUSE");
    return 0;
}
