#include <bits/stdc++.h>
#define ll long long
#define endl "\n"

using namespace std;

const int max_n = 1000000;

int N; 

int A[max_n];

int pos_in_v[max_n];

vector<int> v;

void input() {
    cin >> N;

    for(int i=0; i<N; i++)
        cin >> A[i];
}


void find_place(vector<int>& v, int i) {
    int value = A[i];

    if(v.empty()) {
        v.push_back(value);
        pos_in_v[i] = 0;
        return;
    }

    if(v.back() < value) {
        v.push_back(value);
        pos_in_v[i] = v.size()-1;
        return;
    }

    int index = lower_bound(v.begin(), v.end(), value) - v.begin();
    v[index] = value;
    pos_in_v[i] = index;
    
    return;
}

void solution() {
    input();

    for(int i=0; i<N; i++)
        find_place(v, i);
    
    int size = v.size();

    int order = size-1;
    vector<int> result;
    for(int i=N-1; i>=0; i--) {
        if(pos_in_v[i] == order) {
            order--;
            result.push_back(A[i]);
        }
        if(order == -1)
            break;
    }

    cout << size << endl;
    for(int i=size-1; i>=0; i--)
        cout << result[i] << " ";
    cout << endl;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
