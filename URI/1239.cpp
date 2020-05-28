#include <iostream>
#include <string>

using namespace std;

int main() {

    string s;
    int len, f, g;
    f = g = 0;
    while (getline(cin, s)) {
        len = s.size();
        for (int i = 0; i < len; i++) {
            if (s[i] != '_' && s[i] != '*')
                cout << s[i];
            else {
                if (s[i] == '_') {
                    if (f == 0) {
                        f = 1;
                        cout << "<i>";
                    } else {
                        f = 0;
                        cout << "</i>";
                    }
                } else {
                    if (g == 0) {
                        g = 1;
                        cout << "<b>";
                    } else {
                        g = 0;
                        cout << "</b>";
                    }
                }
            }
        }
        cout << "\n";
    }
}
