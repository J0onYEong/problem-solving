#include <bits/stdc++.h>

using namespace std;

void solution() {
    int n;
    double l;
    cin >> n >> l;
    double *input = new double[n];
    double *prefix_sum = new double[n];
    for(int i=0; i<n; i++)
        cin >> input[i];
    
    prefix_sum[n-1] = input[n-1];
    for(int i=n-2; i>=0; i--) 
        prefix_sum[i] = prefix_sum[i+1] + input[i];
    

    for(int i=n-2; i>=0; i--) {
        double left = input[i]-l;
        double right = input[i]+l;
        double middle = prefix_sum[i+1]/(n-1-i);
        if(left >= middle || right <= middle) {
            cout << "unstable\n";
            return;
        } 
    }
    cout << "stable\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}