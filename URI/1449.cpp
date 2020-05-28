#include <iostream>
#include <map>
#include <stdio.h>
#include <string.h>

using namespace std;

int main() {

    int i, T, M, N;
    string word;
    char ans[1000];
    map<string, string> dic;
    map<string, bool> teste;
    char c;
    int j, tam;

    cin >> T;
    for (int t = 0; t < T; t++) {
        dic.clear();
        teste.clear();
        scanf("%d%d", &M, &N);
        for (i = 0; i < M; i++) {
            cin >> word;
            scanf("\n");
            cin.getline(ans, 1000);
            dic[word] = ans;
            teste[word] = true;
        }
        for (i = 0; i < N; i++) {
            cin.getline(ans, 1000);
            tam = strlen(ans);
            word.clear();
            if (ans[0] == '\0')
                cout << endl; // linha vazia printa linha vazia
            else {
                for (j = 0; j < tam; j++) {
                    if (ans[j] != ' ') {
                        while (j < tam && ans[j] != ' ') {
                            word += ans[j];
                            j++;
                        }
                        if (teste[word] == false)
                            cout << word; // se n tiver significado
                        else
                            cout << dic[word];
                        if (ans[j] == ' ')
                            cout << " ";
                        word.clear();
                    }
                }
                cout << endl;
            }
        }
        cout << endl;
    }

    // system("PAUSE");
    return 0;
}