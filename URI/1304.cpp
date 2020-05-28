#include <bits/stdc++.h>
using namespace std;

#define D(x)                                                                                                           \
    if (1)                                                                                                             \
        cout << __LINE__ << " " << #x " = " << (x) << endl;
#define D2(x, y) cout << #x " = " << x << "  " << #y " = " << y << endl;
#define DVEC(v, n)                                                                                                     \
    {                                                                                                                  \
        cout << #v << "[] ={ ";                                                                                        \
        rep(i, 0, n) cout << v[i] << " ";                                                                              \
        cout << "}\n";                                                                                                 \
    }

#define rep(i, n) for (int i = 0; i < (n); i = i + 1)
#define tr(it, S) for (typeof(S.begin()) it = S.begin(); it != S.end(); it++)
#define all(S) (S).begin(), (S).end()
#define pb push_back
#define contem(s, x) (s.find(x) != s.end())

typedef long long ll;

int Atoi(string x) {
    stringstream ss;
    ss << x;
    int v;
    ss >> v;
    return v;
}

double Atof(string x) {
    stringstream ss;
    ss << x;

    double v;
    ss >> v;
    return v;
}

int main() {
    //	freopen("saida.txt", "w", stdout);

    int h, m, s;
    int flag;
    int previous = 0;
    double dist = 0, vel = 0;

    string line;
    while (getline(cin, line)) {
        if (line.size() == 0)
            continue;

        vector<string> info;
        stringstream ss;
        ss << line;
        while (ss >> line)
            info.push_back(line);
        flag = 0;
        if (info.size() == 1)
            flag = 1;

        vector<string> v;
        string aux = info[0];
        vector<int> indices;
        for (int i = 0; i < aux.size(); i++)
            if (aux[i] == ':')
                indices.pb(i);

        h = Atoi(aux.substr(0, indices[0]));
        m = Atoi(aux.substr(indices[0] + 1, indices[1] - indices[0] - 1));
        s = Atoi(aux.substr(indices[1] + 1, aux.size() - indices[1] - 1));
        int atual = (h * 60 * 60 + m * 60 + s); // s
        int tempo = atual - previous;
        dist += (((double)(tempo)) * vel) / 3600.0;
        if (flag)
            printf("%02d:%02d:%02d %.2lf km\n", h, m, s, dist);
        previous = atual;

        if (info.size() == 2) {
            vel = Atof(info[1]);
        }
    }

    return 0;
}
