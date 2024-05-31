#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
#define endl "\n"

using namespace std;

int T, N, M;

vector<int> A, B;

void input() {

    cin >> T;

    cin >> N;

    A = vector<int>(N);

    for(int i=0; i<N; i++) {
        cin >> A[i];
    }

    cin >> M;

    B = vector<int>(M);

    for(int i=0; i<M; i++) {
        cin >> B[i];
    }
}

void solution() {
    input();

    vector<vector<int>> sum_A = vector<vector<int>>(N, vector<int>(N, 0));
    vector<vector<int>> sum_B = vector<vector<int>>(M, vector<int>(M, 0));

    for(int i=0; i<N; i++) {

        for(int j=i; j<N; j++) {

            if(i==j) {
                sum_A[i][j] = A[i];
                continue;    
            }

            sum_A[i][j] = sum_A[i][j-1] + A[j];
        }
    }

    vector<int> flatSume_B;

    for(int i=0; i<M; i++) {

        for(int j=i; j<M; j++) {

            if(i==j) {

                sum_B[i][j] = B[i];

            } else {
                
                sum_B[i][j] = sum_B[i][j-1] + B[j];
            }

            flatSume_B.push_back(sum_B[i][j]);
        }
    }

    sort(flatSume_B.begin(), flatSume_B.end());

    ll result = 0;

    for(int i=0; i<N; i++) {

        for(int j=i; j<N; j++) {
            
            int partA = sum_A[i][j];

            int partB = T - partA;

            auto iter1 = lower_bound(flatSume_B.begin(), flatSume_B.end(), partB);
            auto iter2 = upper_bound(flatSume_B.begin(), flatSume_B.end(), partB);

            result += (iter2-iter1);
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
