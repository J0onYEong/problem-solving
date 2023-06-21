#include <bits/stdc++.h>
#define ll long long
#define endl "\n"

using namespace std;

void solution() {
    string str;
    cin >> str;
    stack<char> s;

    map<char, int> p;
    p['+'] = 1;
    p['-'] = 1;
    p['*'] = 2;
    p['/'] = 2;


    for(char e : str) {
        if(65 <= e && e <= 90)
            cout << e;
        else {
            if(!s.empty()) {
                if(e == ')') {
                    while(s.top() != '(') {
                        cout<<s.top();
                        s.pop();
                    }
                    s.pop();
                } else if(e == '(') 
                    s.push(e);
                else {
                    while(!s.empty() && p[e] <= p[s.top()]) {
                        cout<<s.top();
                        s.pop();                            
                    }
                    s.push(e);
                }
            } else 
                s.push(e);
        }
    }
    while(!s.empty()) {
        cout << s.top();
        s.pop();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
