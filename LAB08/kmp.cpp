#include<bits/stdc++.h>
#include<iostream>

using namespace std;

int main() {
    string text;
    string pattern;
    cout << "Enter Text" << endl;
    cin >> text;
    cout << "Enter Pattern: " << endl;
    cin >> pattern;
    int n = text.length();
    int m = pattern.length();
    int cnt = 0;
    int arr[m+1] = {0};
    arr[1] = 0;
    int k = 0;
    for(int q = 2; q<=m; q++){
        while(k > 0 && ++cnt && pattern[k] != pattern[q-1]){
            k = arr[k];
        }
        if(pattern[k] == pattern[q-1]){
            k += 1;
        }
        cnt++;
        arr[q] = k;
    } 
    cout << "Printing pi table" << endl;
    for(int i = 1; i <= m; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    //kmp matcher
    int q = 0;
    int i;
    for(i = 0 ; i < n; i++){
        while(q > 0 and pattern[q] != text[i]){
            q = arr[q];
        }
        if(pattern[q] == text[i]){
            q = q + 1;
        }
        if(q == m){
            cout << "Pattern matches at shift: " << (i - m + 1) << endl;
            q = arr[q];
        }
    }; 
    return 0;
}