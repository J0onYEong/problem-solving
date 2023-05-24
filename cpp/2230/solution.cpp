#include <bits/stdc++.h>
#define ll long long
#define endl "\n"

using namespace std;

int N, M;


void solution() {
    cin >> N >> M;
    vector<int> A;
    for(int i=0; i<N; i++) {
        int temp;
        cin >> temp;
        A.push_back(temp);
    }

    sort(A.begin(), A.end());

    int p1, p2;
    p1 = 0;
    p2 = 1;
    int result = 2000000000;
    while(!(p1 == N-1 && p2 == N-1)) {
        if(p1 == p2) {
            p2++;
            continue;
        }

        int temp = A[p2]-A[p1];
        if(temp >= M) {
            result = min(result, temp);
            p1++;
        }
        else {
            p2++;
            if(p2 == N) {
                p2--;
                p1++;
            }
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
