#include <iostream>
#include <vector>
using namespace std;

vector<int> vet[1000000];

int main() {

    int n, m, qt, val, num;
    while (scanf("%d%d", &n, &m) != EOF) {

        for (int i = 0; i < n; i++) {
            scanf("%d", &num);
            vet[num].push_back(i + 1);
        }
        for (int i = 0; i < m; i++) {
            scanf("%d%d", &qt, &val);
            if (qt > vet[val].size())
                printf("0\n");
            else
                printf("%d\n", vet[val][qt - 1]);
        }
        for (int i = 1; i <= 1000000; i++)
            vet[i].clear();
    }

    return 0;
}
