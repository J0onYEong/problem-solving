#include <iostream>
#include <vector>
#define ll long long
#define endl "\n"

using namespace std;

int N, K;
const int line_max = 1000000;
int line_sum[line_max+1];

void input() {

    cin >> N >> K;

    for(int i=0; i<=line_max; i++) { line_sum[i]=0; }

    for(int i=0; i<N; i++) {
        int start, end;

        cin >> start >> end;

        line_sum[start] += 1;

        if(end < line_max) 
            line_sum[end] -= 1;

    }
}

void solution() {
    input();

    for(int i=1; i<=line_max; i++)
        line_sum[i] += line_sum[i-1];

    int start = 0;
    int end = 1;
    int temp_sum = line_sum[start];

    bool flag = false;

    while(true) {

        if(temp_sum < K) {

            if(end <= line_max) {
                temp_sum += line_sum[end];
                end+=1;
            }
            else
                break;
        } else if(temp_sum > K) {

            if(start-1 < end) {

                temp_sum -= line_sum[start];
                start+=1;
            } else {

                if(end <= line_max) {
                    temp_sum += line_sum[end];
                    end+=1;
                }
                else
                    break;
            }
        } else {

            flag = true;
            break;
        }
    }

    if(flag) {
        cout << start << " " << end << endl;
        return;
    } 
    cout << 0 << " " << 0 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
