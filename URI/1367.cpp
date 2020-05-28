#include <cstdlib>
#include <iostream>

using namespace std;

int main() {
    int n, s, p, mat[26], k, i, time;
    char id;
    string resp;

    while (cin >> n && n) {
        s = 0;
        p = 0;
        for (i = 0; i < 26; i++)
            mat[i] = 0;

        for (k = 0; k < n; k++) {
            cin >> id >> time >> resp;
            if (resp == "incorrect")
                mat[id - 'A'] += 1;
            else if (resp == "correct") {
                s++;
                p = p + time + mat[id - 'A'] * 20;
            } // else
        }     // for

        cout << s << " " << p << endl;

    } // while
    // system("PAUSE");
    return EXIT_SUCCESS;
}
