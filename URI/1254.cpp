#include <cstring>
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
string text;

void find_tags(int ini, int fim, string pattern, string subst) {
    int lenp = pattern.size(), lens = subst.size();
    if ((fim - ini) < lenp)
        return;

    for (int i = ini, j, k; i < fim; i++) {
        if (tolower(text[i]) == tolower(pattern[0])) {
            k = i;
            j = 0;
            while (k < fim && tolower(text[k++]) == tolower(pattern[j++])) {
                if (j == lenp) {
                    text.replace(i, j, subst);
                    i = i + lens - 1;
                    fim = fim + (lens - lenp);
                }
            }
        }
    }
}

int main() {

    string tag, ntag;
    int lent;
    while (getline(cin, tag), getline(cin, ntag), getline(cin, text)) {

        for (int i = 0, j; i < text.size(); i++) {
            if (text[i] == '<') {
                j = i + 1;
                while (j < text.size() && text[j] != '>') {
                    if (text[j] == '<')
                        break;
                    j++;
                }
                if (text[j] == '>') {
                    find_tags(i + 1, j, tag, ntag);
                }
            }
        }
        cout << text << "\n";
    }
    return 0;
}
