#include <cstdlib>
#include <iostream>
#include <queue>
using namespace std;

int main() {
    int i, n;
    queue<int> Q;

    while (cin >> n && n) {
        while (!Q.empty())
            Q.pop();
        for (i = 1; i <= n; i++)
            Q.push(i);

        cout << "Discarded cards:";
        while (Q.size() > 1) {
            cout << " " << Q.front();
            Q.pop();
            if (Q.size() >= 2)
                cout << ",";
            Q.push(Q.front());
            Q.pop();
        }
        cout << "\nRemaining card: " << Q.front() << endl;
    }
    // system("PAUSE");
    return EXIT_SUCCESS;
}
