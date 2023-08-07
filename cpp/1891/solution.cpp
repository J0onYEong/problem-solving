#include <bits/stdc++.h>
#define ll long long
#define endl "\n"

using namespace std;

int d; 
string init;
ll x, y;
bool check = false;

string findNumber(int index, ll lastX, ll lastY) {
    if(index < 0)
        return "";

    char tar = init[index];
    ll len = pow(2, d-index);
    if(tar == '1') {
        lastX+=len/2;
        lastY+=len/2;
    } else if(tar == '2')
        lastY+=len/2;
    else if(tar == '4')
        lastX+=len/2;
    
    lastX %= len;
    lastY %= len;

    ll tempX = (lastX + x);
    ll tempY = (lastY + y);

    if(index == 0) {
        if(tempX < 0 || tempX >= len || tempY < 0 || tempY >= len) 
            check = true;
    }

    tempX %= len;
    tempY %= len;

    while(tempX < 0 || tempY < 0) {
        tempX += len;
        tempY += len;
    }
    char result;

    if(tempX < len/2 && tempY < len/2)
        result = '3';
    else if(tempX >= len/2 && tempY < len/2)
        result = '4';
    else if(tempX < len/2 && tempY >= len/2)    
        result = '2';
    else 
        result = '1';
    
    return findNumber(index-1, lastX, lastY) + result;
}

void solution() {
    cin >> d >> init;
    cin >> x >> y;

    string result = findNumber(d-1, 0, 0);
    if(check) {
        cout << -1 << endl;
        return;
    }
    cout << result << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
