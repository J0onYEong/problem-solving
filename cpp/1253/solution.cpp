#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
#define endl "\n"

using namespace std;


int N;
vector<int> numbers;

void input() {

    cin >> N;
    numbers = vector<int>(N, 0);
    for(int i=0; i<N; i++)
        cin >> numbers[i];

}

void solution() {
    input();

    sort(numbers.begin(), numbers.end());

    int fine_cnt = 0;

    for(int i=0; i<N; i++) {

        int start_index = 0;
        int end_index = N-1;
        int goal = numbers[i];

        while(start_index < end_index) {
            
            int temp = numbers[start_index] + numbers[end_index];

            if(temp == goal) {
                if(start_index == i) {

                    start_index += 1;

                } else if(end_index == i) {

                    end_index -= 1;
                } else {

                    fine_cnt+=1;
                    break;
                }

            } else if(temp < goal){

                start_index += 1;

            } else {

                end_index -= 1;
            }

        }

    }

    cout << fine_cnt << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
