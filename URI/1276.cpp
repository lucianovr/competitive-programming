#include <iostream>
#include <string.h>
#include <utility>
#include <vector>

using namespace std;

int main() {
    char s[100];
    vector<pair<int, int>> vect;
    int v[30], i, f, l;

    while (cin.getline(s, 100)) {
        if (s[0] == '\0')
            cout << "\n";
        else {
            for (i = 0; i < 30; i++)
                v[i] = 0;
            vect.clear();

            for (i = 0; i < strlen(s); i++) {
                if (s[i] >= 'a' && s[i] <= 'z')
                    v[s[i] - 'a'] = 1;
            }

            for (i = 0; i < 30; i++) {
                if (v[i]) {
                    f = i;
                    while (i < 30 && v[i])
                        i++;
                    l = i - 1;
                    vect.push_back(make_pair(f, l));
                }
            }

            for (i = 0; i < vect.size(); i++) {
                cout << char(vect[i].first + 'a') << ":" << char(vect[i].second + 'a');
                if (i != vect.size() - 1)
                    cout << ", ";
            }
            cout << endl;
        }
    }

    return 0;
}
