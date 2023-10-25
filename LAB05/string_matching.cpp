#include <bits/stdc++.h>
using namespace std;

class StringMatch {
    string text, pattern;
public:
    void runNaive() {
        int n = text.length();
        int m = pattern.length();
        for (int s = 0; s <= n - m; s++) {
            int i = 0, j = 0;
            while (j < m and text[i + s] == pattern[j])
                i++, j++;

            if (j == m)
                cout << "pattern occurs at " << s << endl;
        }
    }

    void readStrings() {
        cout << "Enter the text : ";
        getline(cin, text);
        cout << "Enter the pattern : " << endl;
        getline(cin, pattern);
    }

    void runHorsePool() {
        int n = text.length();
        int m = pattern.length();
        map<char, int> shift;

        // pre-process
        shift[' '] = m;
        for (char i = 'a'; i <= 'z'; i++)
            shift[i] = m;

        for (int i = 0; i < m - 1; i++)
            shift[pattern[i]] = m - 1 - i;

        // searching
        int j = 0;
        while (j + m <= n) {
            if (pattern[m - 1] == text[j + m - 1]) {
                int i = m - 2;
                while (i >= 0 and pattern[i] == text[i + j])
                    i--;

                if (i == -1)
                    cout << "pattern occurs at " << j << endl;
            }
            j = j + shift[text[j + m - 1]];
        }
    }
};

int main() {
    StringMatch s;
    s.readStrings();
    s.runHorsePool();
    return 0;
}