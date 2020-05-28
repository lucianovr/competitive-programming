#include <iostream>
using namespace std;
int main() {
    int n;
    char m[101][101];

    while (cin >> n) {

        int count = 0, resp = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> m[i][j];

        int j = 0;
        for (int i = 0; i < n; i++) {
            if (j < n)
                for (j = 0; j < n; j++) {
                    if (count > resp)
                        resp = count;
                    if (m[i][j] != '.' && m[i][j] != 'A')
                        count++;
                    else if (m[i][j] == 'A')
                        count = 0;
                }
            else
                for (j = n - 1; j >= 0; j--) {
                    if (count > resp)
                        resp = count;
                    if (m[i][j] != '.' && m[i][j] != 'A')
                        count++;
                    else if (m[i][j] == 'A')
                        count = 0;
                }
            if (count > resp)
                resp = count;
        }

        cout << resp << endl;
    }
    return 0;
}
