#include <bits/stdc++.h>
#define ll long long
#define endl "\n"

using namespace std;

void solution() {
    int n;
    cin >> n;
    int A[1000];
    set<int> num_set;
    for(int i=0; i<n; i++) {
        cin >> A[i];
        num_set.insert(A[i]);
    }
    vector<int> num_vec(num_set.begin(), num_set.end());
    sort(num_vec.begin(), num_vec.end());
    
    ll result = 0;

    for(int i=0; i<num_vec.size()-1; i++) {
        bool isCotinuous = false;
        for(int j=0; j<n; j++) {
            if(A[j] == num_vec[i]) {
                A[j] = num_vec[i+1];
                if(!isCotinuous) {
                    result += num_vec[i+1]-num_vec[i];
                    isCotinuous = true;
                }
            }
            else 
                isCotinuous = false;
        }
    }
    cout << result << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
