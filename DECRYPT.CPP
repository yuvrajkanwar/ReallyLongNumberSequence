#include <iostream>
#include <string.h>
using namespace std;
int main()
{
    cout << "\n\t\t\t\tDecryption using a really long list of numbers\n\n";
    int i, j = 2, k = 0, a[10100], mod[10100], count = 0;
    char ciphertext[100], str[100], ch;
    a[0] = 1;
    int diff[] = { 4, 3, 3, 4, 3, 3 };
    int diff2[] = { 5, 6, 7, 5, 5, 8, 6, 5, 5, 6, 9, 5, 5, 10, 6, 5 };
    cout << "Enter the CIPHER Text : ";
    cin.getline(ciphertext, sizeof(ciphertext));
    int ctsize = strlen(ciphertext);
    for (i = 1; i < 10100; i++, j++) {
        if (j == 6)
            j = 0;
        if (k == 15)
            k = 0;
        a[i] = a[i - 1] + diff[j];
        if (j == 3 || j == 5) {
            a[i + 1] = a[i] + diff2[k];
            k++;
            i++;
        }
    }
    for (i = 10000; i < 10100; i++) {
        mod[i] = a[i] % 7;
    }
    cout << "\nThe 10000th term to the 10100 term in the sequence is as given below :";
    cout << "\n\n(";
    for (i = 10000; i < 10100; i++) {
        if (i == 10099)
            cout << mod[i];
        else
            cout << mod[i] << ",";
    }
    cout << ") \n";
    cout << "\nDecrypted text : ";
    for (i = 10000; i < 10100; i++) {
        if (count >= ctsize)
            break;
        ch = ciphertext[count];
            if (ch >= 'a' && ch <= 'z') {
                ch = ciphertext[count] - mod[i];
                if (ch < 'a')
                    ch = ch + 'z' - 'a' + 1;
                str[count] = ch;
            }
            else if (ch >= 'A' && ch <= 'Z') {
                ch = ch - mod[i];
                if (ch < 'A') {
                    ch = ch + 'Z' - 'A' + 1;
                }
                str[count] = ch;
            }
            cout << str[count];
            count++;
    }
    cout << "\n\n";
    return 1;
}
