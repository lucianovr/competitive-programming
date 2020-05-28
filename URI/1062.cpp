#include <cstdlib>
#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> A;
    stack<int> E;
    int n, k, vagao, s[1010];
    bool Avaz, Evaz;

    while (cin >> n && n) // while 1
    {
        while (cin >> s[0] && s[0]) // while 2
        {
            for (k = 1; k < n; k++)
                cin >> s[k];

            while (!A.empty())
                A.pop();
            for (k = n; k >= 1; k--)
                A.push(k);
            while (!E.empty())
                E.pop();
            k = 0;
            while (true) // while 3
            {
                vagao = s[k];
                Avaz = !A.empty();
                Evaz = !E.empty();
                if (Avaz && vagao == A.top())
                    A.pop();
                else if (Evaz && vagao == E.top())
                    E.pop();
                else if (Avaz && A.top() < vagao) {
                    while (vagao != A.top()) {
                        E.push(A.top());
                        A.pop();
                    }
                    A.pop();
                } else if (Evaz && vagao < E.top()) {
                    cout << "No\n";
                    break;
                } else if (!Avaz && !Evaz) {
                    cout << "Yes\n";
                    break;
                }
                k++;
            } // w3

        } // w2
        cout << endl;
    } // w1

    return 0;
}
