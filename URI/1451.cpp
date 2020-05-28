#include <cstring>
#include <iostream>
#include <list>
#include <stdio.h>
using namespace std;

int main() {

    string s;
    list<char> dq;
    list<char>::iterator it;
    int slen;
    bool inicio;

    while (cin >> s) {
        dq.clear();
        inicio = false;
        it = dq.begin();
        slen = s.size();
        for (int i = 0; i < slen; i++) {
            if (s[i] == ']')
                inicio = false;
            else if (s[i] == '[') {
                inicio = true;
                it = dq.begin();
            } else if (inicio)
                dq.insert(it, s[i]);
            else
                dq.push_back(s[i]);
        }

        for (it = dq.begin(); it != dq.end(); it++)
            cout << *it;
        cout << endl;
        s.clear();
    }

    return 0;
}
