#include <bits/stdc++.h>
#define ll long long
#define endl "\n"

using namespace std;

void solution() {
    int n, q;
    cin >> n >> q;
    int arr[300000];
    int prefix_sum[300000];
    for(int i=0;i<n;i++) 
        cin >> arr[i];

    sort(arr, arr+n);

    for(int i=0; i<n; i++) 
        prefix_sum[i] = i==0 ? arr[i] : prefix_sum[i-1] + arr[i];
    
    for(int i=0;i<q;i++) {
        int l, r;
        cin >> l >> r;
        l-=2;
        r-=1;
        cout << prefix_sum[r] - (l<0 ? 0 : prefix_sum[l]) << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
