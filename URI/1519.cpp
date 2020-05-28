#include <iostream>
#include <map>
#include <queue>
#include <stdio.h>
#include <string.h>
#include <string>
#include <utility>
#include <vector>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i = i + 1)
#define pb push_back
#define sz size()
vector<string> v[26];
vector<string> words;

void get_words(char line[]) {
    char *p;
    p = strtok(line, " ");
    while (p != NULL) {
        v[p[0] - 'a'].pb(p);
        words.pb(p);
        p = strtok(NULL, " ");
    }
}
int main() {
    int cont;
    map<string, string> mp;
    map<string, string>::iterator itMP;
    map<string, int> qt;
    map<string, int>::iterator itQT;
    vector<string> resp;
    int n;
    char line[100000];

    while (gets(line) && strcmp(line, ".") != 0) {
        rep(i, 26) v[i].clear();
        mp.clear();
        words.clear();
        get_words(line);

        rep(i, words.sz) mp[words[i]] = words[i];
        cont = 0;
        for (int i = 0; i < 26; i++) {
            if (v[i].sz) {
                qt.clear();
                for (int j = 0, k = v[i].size(); j < k; j++) {
                    if (v[i][j].sz > 2)
                        qt[v[i][j]]++;
                }
                priority_queue<pair<int, string>> Q;

                for (itQT = qt.begin(); itQT != qt.end(); itQT++) {
                    Q.push(make_pair((itQT->second) * (itQT->first.sz - 2), itQT->first));
                }

                if (!Q.empty()) {
                    cont++;
                    string s, r;
                    s = Q.top().second;
                    r += s[0];
                    r += '.';
                    // cout << s << " " << r << endl;
                    mp[s] = r;
                }
            }
        }
        rep(i, words.sz) resp.pb(mp[words[i]]);

        cout << resp[0];
        for (int i = 1, j = resp.sz; i < j; i++)
            cout << " " << resp[i];
        cout << endl;
        cout << cont << endl;
        for (itMP = mp.begin(); itMP != mp.end(); itMP++) {
            if (itMP->first != itMP->second) {
                cout << itMP->second << " = " << itMP->first << endl;
            }
        }
        resp.clear();
    }
    return 0;
}