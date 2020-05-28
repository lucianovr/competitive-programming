#include <algorithm>
#include <iostream>
#include <map>
#include <stdio.h>
#include <vector>
using namespace std;
#define pb push_back
#define rep(i, a, b) for (int i(a); i < (b); i++)
#define debgu(x) cout << #x << " = " << x;
#define nl cout << "\n";

map<string, string> m;

int main() {

    m["brasil"] = "Feliz Natal!";
    m["alemanha"] = "Frohliche Weihnachten!";
    m["austria"] = "Frohe Weihnacht!";
    m["coreia"] = "Chuk Sung Tan!";
    m["espanha"] = "Feliz Navidad!";
    m["grecia"] = "Kala Christougena!";
    m["estados-unidos"] = "Merry Christmas!";
    m["inglaterra"] = "Merry Christmas!";
    m["australia"] = "Merry Christmas!";
    m["portugal"] = "Feliz Natal!";
    m["suecia"] = "God Jul!";
    m["turquia"] = "Mutlu Noeller";
    m["argentina"] = "Feliz Navidad!";
    m["chile"] = "Feliz Navidad!";
    m["mexico"] = "Feliz Navidad!";
    m["antardida"] = "Merry Christmas!";
    m["canada"] = "Merry Christmas!";
    m["irlanda"] = "Nollaig Shona Dhuit!";
    m["belgica"] = "Zalig Kerstfeest!";
    m["italia"] = "Buon Natale!";
    m["libia"] = "Buon Natale!";
    m["siria"] = "Milad Mubarak!";
    m["marrocos"] = "Milad Mubarak!";
    m["japao"] = "Merii Kurisumasu!";

    string IN;
    while (cin >> IN) {
        // for(int i=0; i < IN.size(); i++)
        //	IN[i] = tolower(IN[i]);

        string res = m[IN];
        if (res.size()) {
            cout << res << "\n";

        } else
            cout << "--- NOT FOUND ---\n";
    }
}
