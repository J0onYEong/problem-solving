#include <bits/stdc++.h>
#define ll long long
#define endl "\n"

using namespace std;

const int max_N = 100000+1;
const int max_tree_size = 262143+1;
const int MAX_NUMBER = 1000000000;
const int MIN_NUMBER = 1;

int numbersArray[max_N];

// 0-최소값 1-최대값
int segmentTree[max_tree_size][2];

int N, M;
vector<pair<int, int>> inputRanges;

void input() {
    cin >> N >> M;

    for(int i=1; i<=N; i++) 
        cin >> numbersArray[i];

    for(int i=1; i<=M; i++) {
        int a, b;
        cin >> a >> b;
        inputRanges.push_back({a, b});
    }
}

void insert_number_to_tree(int value, int pos, int start, int end, int index) {
    if(segmentTree[index][0] > value)
        segmentTree[index][0] = value;
    if(segmentTree[index][1] < value)
        segmentTree[index][1] = value;
    
    if(start == end)
        return;

    int mid = (start+end)/2;

    if(pos <= mid)
        insert_number_to_tree(value, pos, start, mid, index*2);
    else
        insert_number_to_tree(value, pos, mid+1, end, index*2+1);
}

pair<int, int> find_max_and_min(int left, int right, int start, int end, int index) {
    if(right < start || left > end)
        return {MAX_NUMBER, MIN_NUMBER};

    if(left <= start && end <= right)
        return {segmentTree[index][0], segmentTree[index][1]};

    if(start == end)
        return {segmentTree[index][0], segmentTree[index][1]};

    int mid = (start+end)/2;

    pair<int, int> leftResult = find_max_and_min(left, right, start, mid, index*2);
    pair<int, int> rightResult= find_max_and_min(left, right, mid+1, end, index*2+1);

    return {min(leftResult.first, rightResult.first), max(leftResult.second, rightResult.second)};
}

void solution() {
    input();

    for(int i=1; i<max_tree_size; i++) {
        segmentTree[i][0] = MAX_NUMBER;
        segmentTree[i][1] = MIN_NUMBER;
    }

    //숫자를 세그먼트 트리에 삽입
    for(int i=1; i<=N; i++)
        insert_number_to_tree(numbersArray[i], i, 1, N, 1);

    for(auto query : inputRanges) {
        pair<int, int> result = find_max_and_min(query.first, query.second, 1, N, 1);
        cout << result.first << " " << result.second << endl;
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
