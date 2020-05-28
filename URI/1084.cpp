#include <iostream>
#include <stack>
using namespace std;

int main() {

    stack<char> pil;
    int n, d, psz, tam, i;
    string s;

    while (cin >> n >> d && n + d) {
        cin >> s;
        while (!pil.empty())
            pil.pop();
        pil.push(s[0]);
        tam = n - d;
        psz = i = 1;
        while (true) {
            if (d == 0)
                break;
            if (s[i] > pil.top()) {
                while (!pil.empty() && d && s[i] > pil.top()) {
                    pil.pop();
                    d--;
                    psz--;
                }
                pil.push(s[i]);
                i++;
                psz++;
            } else if (psz < tam) {
                pil.push(s[i]);
                i++;
                psz++;
            } else {
                d--;
                i++;
            }
        }

        stack<char> temp;
        while (!pil.empty()) {
            temp.push(pil.top());
            pil.pop();
        }
        while (!temp.empty()) {
            cout << temp.top();
            temp.pop();
        }

        if (psz != tam)
            for (int j = i; j < s.size(); j++)
                cout << s[j];
        cout << endl;
    }
    return 0;
}
