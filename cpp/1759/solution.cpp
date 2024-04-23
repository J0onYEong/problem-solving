#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long
#define endl "\n"

using namespace std;

// 97~122

int L, C;
vector<char> list;

// 해당 값이 true인 경우 모음
vector<bool> mappedChar;

void input() {

    cin >> L >> C;

    for(int i=0; i<C; i++) {

        char temp;
        cin >> temp;
        list.push_back(temp);
    }
}

bool isVowel(char c) {

    int vowels[5] = {'a', 'e', 'i', 'o', 'u'};

    for(char v : vowels) {

        if(v == c) return true;
    }

    return false;
}

void backTracking(int lastIndex, vector<char> chars) {

    // L개를 만족한 경우
    if(chars.size() == L) {

        int v_count = 0;
        int c_count = 0;
        
        for(auto c : chars) {

            // 모음인 경우
            if(mappedChar[c-97]) v_count++;
            else c_count++;
        }

        if(v_count >= 1 && c_count >= 2) {

            for(auto c : chars) {

                cout << c;
            }

            cout << endl;
        }

        return;
    }

    // 탐색
    int numOfTheRest = L - chars.size();

    for(int i=lastIndex+1; i<C-numOfTheRest+1; i++) {

        chars.push_back(list[i]);
        
        backTracking(i, chars);
        
        chars.pop_back();
    }
}

void solution() {
    input();

    // 자음모음 전처리

    mappedChar = vector<bool>(26, false);

    for(int i=0; i<26; i++) {

        char c = i+97;

        mappedChar[i] = isVowel(c);
    }

    sort(list.begin(), list.end());

    backTracking(-1, vector<char>(0));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
