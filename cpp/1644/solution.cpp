#include <iostream>
#include <vector>
#include <cmath>
#define ll long long
#define endl "\n"

using namespace std;

int N;

void input() {

    cin >> N;
}

void solution() {
    input();    


    return;

    vector<bool> isPrime = vector<bool>(N+1, true);

    // 소수찾기
    for(int i=2; i<=sqrt(N); i++) {

        for(int k=i*2; k<=N; k+=i) {
            isPrime[k] = false;
        }
    }

    isPrime[1] = false;

    vector<int> prime_numbers;
    for(int i=1; i<=N; i++) {
        if(isPrime[i]) {
            prime_numbers.push_back(i);
        }
    }

    int prime_sum = 0;
    int left = 0;
    int right = prime_numbers.size()-1;

    for(int i=0; i<prime_numbers.size(); i++) {
        
        prime_sum += prime_numbers[i];

        if(prime_sum >= N) {

            right = i;
            break;
        }
    }

    int result_cnt = 0;

    while(left <= right) {

        if(prime_sum == N) {
            result_cnt ++;
        }

        if(prime_sum >= N) {

            prime_sum -= prime_numbers[left];
            left++;
        } else {    

            int next_right = right+1;
            if(next_right < prime_numbers.size()) {

                prime_sum += prime_numbers[next_right];

                right = next_right;
            } else {

                break;
            }
        }
    }

    cout << result_cnt << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
