#include <cstring>
#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

int main() {

    char s[100];
    char num[100], n[100];
    bool flag;
    int i, k;
    long long int lli;

    while (cin.getline(s, 100)) {
        n[0] = '\0';
        num[0] = '\0';
        if (s[0] == '\0')
            cout << "error";
        else // fim 2
        {
            flag = false;
            k = 0;
            for (i = 0; i < strlen(s); i++) {
                if (s[i] >= '0' && s[i] <= '9')
                    num[k++] = s[i];
                else if (s[i] == 'o' || s[i] == 'O')
                    num[k++] = '0';
                else if (s[i] == 'l')
                    num[k++] = '1';
                else if ((tolower(s[i]) >= 'a' && tolower(s[i]) <= 'z')) {
                    flag = true;
                    break;
                }
            }
            num[k] = '\0';
            if (flag || strlen(num) == 0)
                cout << "error";
            else {
                if (num[0] == '0') {
                    i = 0;
                    while (i < strlen(num) && num[i] == '0')
                        i++;
                    if (i == strlen(num)) {
                        cout << "0";
                        flag = true;
                    } else {
                        k = 0;
                        for (i; i < strlen(num); i++)
                            n[k++] = num[i];
                        n[k] = '\0';
                    }
                } else
                    strcpy(n, num);
                if (flag == false) {
                    if (strlen(n) > 12)
                        cout << "error";
                    else {
                        lli = atoll(n);
                        if (lli > 2147483647)
                            cout << "error";
                        else
                            cout << lli;
                    }
                }
            }
        } // else 1
        cout << endl;
    } // while

    return 0;
}