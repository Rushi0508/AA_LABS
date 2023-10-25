#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    string text;
    string pattern;
    cout << "Enter the Text : " << endl;
    cin >> text;
    cout << "Enter the Pattern : " << endl;
    cin >> pattern;
    int n = text.length();
    int m = pattern.length();
    int text_mod[n - m + 1] = {0};
    int q = 13;
    int x = pow(10, m - 1);
    x %= q;
    int pattern_mod = 0;
    for(int i = 0; i < m; i++){
        text_mod[0] = (text_mod[0]*10 + (text[i] - 48)) % q;
        pattern_mod = (pattern_mod*10 + (pattern[i] - 48)) % q;
    }
    int count = 0;
    for(int i = 0; i < n - m; i++){
        if(text_mod[i] == pattern_mod){
            int a = 0;
            int b = 0;
            while(b != m){
                if(text[i + a] != pattern[b]){
                    break;
                }
                a++;
                b++;
            }
            if(b == m){
                cout << "Shift : " << i << endl;
                count++;
            }
        }
        text_mod[i + 1] = (10 * (text_mod[i] - (text[i] - 48)*x) + (text[i + m] - 48)) % q;
        if(text_mod[i + 1] < 0){
            text_mod[i + 1] += q;
        }
    }
    cout << endl;
    if(count == 0){
        cout << "Pattern not Found" << endl;
    }
    return 0;
}