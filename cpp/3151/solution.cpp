#include <iostream>
#include <vector>
#include<algorithm>

#define ll long long
#define endl "\n"

using namespace std;

int N;
vector<int> numbers;

void input() {

    cin >> N;
    numbers = vector<int>(N, 0);

    for(int i=0; i<N; i++) {

        cin >> numbers[i];
    }
}

void solution() {
    input();

    // *
    ll result = 0;

    sort(numbers.begin(), numbers.end());

    for(int i=0; i<N-2; i++) {

        for(int j=i+1; j<N-1; j++) {

            int temp = numbers[i] + numbers[j];
            
            // *
            int start = lower_bound(numbers.begin()+(j+1), numbers.end(), temp * -1) - numbers.begin();
            int end = upper_bound(numbers.begin()+(j+1), numbers.end(), temp * -1) - numbers.begin();
            
            // *
            result += (end-start);
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
