#include <bits/stdc++.h>
#define ll long long
#define endl "\n"

using namespace std;

void solution() {
    int C;
    cin >> C;

    for(int c=0; c<C; c++) {
        int N;
        cin >> N;

        double sum = 0;
        double temp[1000];
        for(int i=0; i<N; i++) {
            cin >> temp[i];
            sum+=temp[i];
        }        

        double m = sum / N;

        int count = 0;
        for(int i=0; i<N; i++) {
            if(m < temp[i]) 
                count++;
        }

        double temp_result = (count / double(N)) * 100000;

        int temp_result2 = temp_result;
        temp_result = temp_result2 * 0.001;

        cout << temp_result << '%' << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
