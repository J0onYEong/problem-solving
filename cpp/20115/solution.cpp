#include <bits/stdc++.h>

using namespace std;

void solution() {
    int n;
    cin >> n;
    int index = -1;
    int maxValue = -1;
    int* drinks = new int[n];
    for(int i=0; i<n; i++) {
        cin >> drinks[i];
        if(drinks[i] > maxValue) {
            maxValue = drinks[i];
            index = i;
        }
    }
    double result = 0;
    for(int i=0; i<n; i++) 
        result += double(drinks[i]) / (i == index ? 1.0 : 2.0);
    cout << result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}