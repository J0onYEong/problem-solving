#include <bits/stdc++.h>

using namespace std;

signed long long int memo[100][1801]; // 0~900(0 ~ +900), 901~1800(-1 ~ -900) 
int N;

int cti(int num) {
    return num < 0 ? 900+abs(num) : num;
}

// 특정 수에 축적된 값이 전달됬을 때  경우의 수를 반환
signed long long int recursive(int* list, int n, int sum) {
    if(n==N-1) return sum == list[N-1] ? 1 : 0;

    int index = cti(sum);
    if(memo[n][index] != -1) return memo[n][index];
    memo[n][index] = 0;
    int plusResult = sum + list[n];
    int minusResult = sum - list[n];
    int next = n+1;
    if(plusResult <= 20) memo[n][index] += recursive(list, next, plusResult);
    if(minusResult >= 0) memo[n][index] += recursive(list, next, minusResult);
    return memo[n][index];
}

void solution() {
    cin >> N;
    int *numbers = new int[N];

    for(int i=0; i<100; i++)
        for(int j=0; j<1801; j++)
            memo[i][j] = -1;

    for(int i=0; i<N; i++) 
        cin >> numbers[i];

    // 0부터 합을 시작한다 헸을 때 첫수는 무조건 총합에 더해지며 시작해야 한다.
    // 첫수가 0일 경우 +-가 모두 가능하기 때문에 전체 경우의 수가 2배가 된다.
    // +0~, -0~
    cout << recursive(numbers, 1, numbers[0]) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}