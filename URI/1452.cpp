#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {

    int n, m, count;
    vector<string> vect[202];
    bool flag[202];
    string word;

    while (cin >> n >> m && n + m) {
        for (int i = 0; i < n; i++) {
            flag[i] = false;
            vect[i].clear();
        }
        int qt;
        for (int i = 0; i < n; i++) { // lendo os servidores
            cin >> qt;
            while (qt--) {
                cin >> word;
                vect[i].push_back(word);
            }
        }

        count = 0;
        while (m--) {
            cin >> qt;
            while (qt--) {
                cin >> word;                // para cada conexao lida
                for (int i = 0; i < n; i++) // percorro o array de vector...
                {
                    if (!flag[i]) {
                        for (vector<string>::iterator it = vect[i].begin(); it != vect[i].end(); it++)
                            if (*it == word) {
                                count++;
                                flag[i] = true;
                                break;
                            }
                    }
                }
            }
            for (int i = 0; i < n; i++)
                flag[i] = false;
        }
        cout << count << endl;
    }
    return 0;
}
