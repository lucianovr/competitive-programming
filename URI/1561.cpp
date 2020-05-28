#include <cmath>
#include <cstring>
#include <iostream>
#include <string.h>

using namespace std;

int main()

{

    int h, m;
    char c;

    while (cin >> h >> c >> m) {

        char pos[5];
        char mt[7];

        int v[] = {8, 4, 2, 1};
        int b[] = {32, 16, 8, 4, 2, 1};

        for (int i = 0; i < 4; i++) {
            if (v[i] <= h) {
                pos[i] = 'o';
                h = h - v[i];
            } else
                pos[i] = ' ';
        }

        for (int i = 0; i < 6; i++) {
            if (b[i] <= m) {
                mt[i] = 'o';
                m = m - b[i];
            } else
                mt[i] = ' ';
        }

        cout << " ____________________________________________" << endl;
        cout << "|                                            |" << endl;
        cout << "|    ____________________________________    |_" << endl;
        cout << "|   |                                    |   |_)" << endl;
        cout << "|   |   8         4         2         1  |   |" << endl;
        cout << "|   |                                    |   |" << endl;
        cout << "|   |   " << pos[0] << "         " << pos[1] << "         " << pos[2] << "         " << pos[3]
             << "  |   |" << endl;
        cout << "|   |                                    |   |" << endl;
        cout << "|   |                                    |   |" << endl;
        cout << "|   |   " << mt[0] << "     " << mt[1] << "     " << mt[2] << "     " << mt[3] << "     " << mt[4]
             << "     " << mt[5] << "  |   |" << endl;
        cout << "|   |                                    |   |" << endl;
        cout << "|   |   32    16    8     4     2     1  |   |_" << endl;
        cout << "|   |____________________________________|   |_)" << endl;
        cout << "|                                            |" << endl;
        cout << "|____________________________________________|" << endl;
        cout << endl;
    }

    return 0;
}