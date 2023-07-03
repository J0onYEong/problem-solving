#include <bits/stdc++.h>
#define ll long long
#define endl "\n"

using namespace std;
const int MAX = 500000;

int N, K;
string number_str;

void find_number(int start_index, int rest_k) {
    if(N - start_index == rest_k) {
        cout << endl;
        return;
    }

    int end_index = start_index + rest_k;

    char max_number = '0';
    for(int i=start_index; i<=end_index; i++)
        max_number = max(max_number, number_str[i]);

    cout << max_number;
    int temp_start = start_index;
    for(int i=start_index; i<=end_index; i++) {
        if(number_str[i] == max_number)
            break;
        temp_start++;
        rest_k--;
    }

    find_number(temp_start+1, rest_k)
}

void solution() {
    
    cin >> N >> K >> number_str;


    find_number(0, K);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
