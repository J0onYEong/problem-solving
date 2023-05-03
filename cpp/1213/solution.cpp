#include <bits/stdc++.h>
#define ll long long
#define endl "\n"

using namespace std;

void solution() {
    //최대 50글자
    string str;
    cin >> str;
    map<char, int> m;
    for(int i=0; i<str.length(); i++) {
        char temp = str[i];
        m[temp]++;
    }

    int oddCount = 0;
    char center;
    for(auto d : m) {
        if(d.second % 2 == 1) {
            oddCount++;
            center = d.first;
            d.second--;

            if(oddCount > 1) {
                cout << "I'm Sorry Hansoo" << endl;
                return;
            }
        }
    }
    vector< pair<int, int> > v(m.begin(), m.end());
    string result = "";
    int count = 0;
    for(auto d : v) {
       for(int i=0; i<d.second/2; i++) {
            result += d.first;
            count++;
       }
    }
    if(center != NULL) 
        result += center;
    for(int i = count-1; i>=0; i--)
        result += result[i];
    cout << result << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}