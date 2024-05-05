#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
#define endl "\n"

using namespace std;

int N;
vector<int> plus_numbers;
vector<int> minus_numbers;

void input() {

    cin >> N;

    for(int i=0; i<N; i++) {

        int temp;
        cin >> temp;

        if(temp <= 0) {

            minus_numbers.push_back(temp);
        } else {
            
            plus_numbers.push_back(temp);
        }
    }
}

int result = 0;

void calcurate(const vector<int> &arr) {

    if(!arr.empty()) {

        for(int i=0; i<arr.size(); i+=2) {

            if(i == arr.size()-1) {

                result += arr[i];
            } else {

                int mul = arr[i] * arr[i+1];
                int plu = arr[i] + arr[i+1];

                if(plu > mul) {
                    result += plu;
                } else {
                    result += mul;
                }
            }
        }
    }
}

bool cmp(int lhs, int rhs) {

    return lhs > rhs;
}

void solution() {
    input();

    sort(minus_numbers.begin(), minus_numbers.end());
    sort(plus_numbers.begin(), plus_numbers.end(), cmp);

    calcurate(minus_numbers);
    calcurate(plus_numbers);

    cout << result << endl;
}   

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
