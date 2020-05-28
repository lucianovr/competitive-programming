#include <iostream>
#include <map>
using namespace std;

int main() {
    int n, c, k;
    int i, j, num, me, id;
    map<int, int> mapa;

    while (cin >> n >> c >> k && n + c + k) {
        mapa.clear();
        for (i = 0; i < n; i++)
            for (j = 0; j < c; j++) {
                cin >> num;
                mapa[num]++;
            }
        me = 1000000;
        for (i = 1; i <= k; i++)
            if (mapa[i] < me) {
                me = mapa[i];
                id = i;
                if (me == 0)
                    break;
            }
        cout << id;
        for (i = id + 1; i <= k; i++)
            if (mapa[i] == me)
                cout << " " << i;

        cout << endl;
    }

    return 0;
}
