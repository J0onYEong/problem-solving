#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define endl "\n"

void solution() {
    int n;
    cin >> n;
    int *speed = new int[n];
    for(int i=0;i<n;i++)
        cin >> speed[i];

    ll minSpeed = 0;
    for(int i=n-1; i>=0; i--) {
        int nowSpeed = speed[i];
        if(minSpeed > nowSpeed && minSpeed % nowSpeed != 0) 
            minSpeed = (minSpeed / nowSpeed + 1)*nowSpeed;
        else if(minSpeed < nowSpeed) 
            minSpeed = nowSpeed;
    }
    cout << minSpeed <<endl;
    free(speed);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}