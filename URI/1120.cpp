#include <cstring>
#include <iostream>

using namespace std;

int main() {
    string n, r, d;
    int i, t;
    bool flag;
    while (cin >> d >> n && (d[0] - '0' + n[0] - '0')) {
        flag = false;
        r.clear();
        t = n.size();

        for (i = 0; i < t; i++)
            if (n[i] != d[0])
                if (flag || n[i] != '0') {
                    flag = true;
                    r += n[i];
                }

        if (!r.size())
            cout << "0";
        else
            cout << r;

        cout << endl;
    }
    return 0;
}
