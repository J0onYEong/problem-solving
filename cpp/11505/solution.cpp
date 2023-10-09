#include <bits/stdc++.h>
#include <iostream>
#define ll long long
#define endl "\n"

using namespace std;

const int max_N = 1000000+1;
const int max_M = 10000+1;
const int max_K = 10000+1;

const int mod_value = 1000000007;

const int segmentTreeArrSize = 2100000;

int N, M, K;

int numbers[max_N];
ll segmentTree[segmentTreeArrSize];
vector<pair<int, pair<int, int>>> query;

void input() {

    cin >> N >> M >> K;

    for(int i=1; i<=N; i++)
        cin >> numbers[i];

    for(int i=1; i<=M+K; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        query.push_back({a, {b, c}});
    }
}

int update_nunber(int newValue, int pos, int start, int end, int index) {
    if(pos < start || pos > end) 
        return segmentTree[index];

    if(start == end)
        return segmentTree[index] = newValue;

    int mid = (start+end)/2;

    segmentTree[index] = 1;
    segmentTree[index] *= update_nunber(newValue, pos, start, mid, index*2);
    segmentTree[index] %= mod_value;
    segmentTree[index] *= update_nunber(newValue, pos, mid+1, end, index*2+1);
    segmentTree[index] %= mod_value;

    return segmentTree[index];
}

int get_product_in_range(int left, int right, int start, int end, int index) {
    if(start > right || end < left)
        return 1;
    
    if(left <= start && end <= right)
        return segmentTree[index];

    ll temp_result = 1;
    int mid = (start+end)/2;
    temp_result *= get_product_in_range(left, right, start, mid, index*2);
    temp_result %= mod_value;
    temp_result *= get_product_in_range(left, right, mid+1, end, index*2+1);
    temp_result %= mod_value;
    return temp_result;
}

void solution() {
    input();

    for(int i=0; i<segmentTreeArrSize; i++)
        segmentTree[i] = 1;

    for(int i=1; i<=N; i++)
        update_nunber(numbers[i], i, 1, N, 1);

    for(auto e : query) {
        int a = e.first;
        int b = e.second.first;
        int c = e.second.second;

        if(a == 1)
            update_nunber(c, b, 1, N, 1);
        else
            cout << get_product_in_range(b, c, 1, N, 1) << endl;
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
