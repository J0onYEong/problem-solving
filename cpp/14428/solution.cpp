#include <iostream>
#include <vector>

#define ll long long
#define endl "\n"

using namespace std;

const int MAX_N = 100000+1;
const int MAX_M = 100000+1;
const int SEG_TREE_SIZE = 513000;
const int MAX_VALUE = 1000000000+1;

// 2^19 = 1024 * 512 = 513,000

int n, m;
int A[MAX_N];

// 0 - value / 1 - index
int segmentTree[SEG_TREE_SIZE][2];

vector<pair<int, pair<int, int>>> query;

void input() {
    cin >> n;
    for(int i=1; i<=n; i++)
        cin >> A[i];
    
    cin >> m;
    for(int i=1; i<=m; i++) {
        int type, p1, p2;
        cin >> type >> p1 >> p2;
        query.push_back({type, {p1, p2}});
    }
}

void inset_element_to_tree(int start, int end, int node, int index, int value) {
    if(segmentTree[node][0] > value) {
        segmentTree[node][0] = value;
        segmentTree[node][1] = index;
    }
    else if(segmentTree[node][0] == value) {
        segmentTree[node][0] = value;
        segmentTree[node][1] = min(segmentTree[node][1], index);
    }

    if(start == end) {
        segmentTree[node][0] = value;
        segmentTree[node][1] = index;
        return;
    }

    int middle = (start+end)/2;

    if(index <= middle) 
        inset_element_to_tree(start, middle, node*2, index, value);
    else 
        inset_element_to_tree(middle+1, end, node*2+1, index, value);
}

int find_node(int start, int end, int node, int index) {
    if(start == end)
        return node;

    int mid = (start + end) / 2;

    if(index <= mid) 
        return find_node(start, mid, node*2, index);
    else
        return find_node(mid+1, end, node*2+1, index);
}

void updateTree(int index) {
    int node = find_node(1, n, 1, index);

    int parent = node / 2;

    while(parent != 0) {
        pair<int, int> left, right, target;

        target = left = {segmentTree[parent*2][0], segmentTree[parent*2][1]};
        right = {segmentTree[parent*2+1][0], segmentTree[parent*2+1][1]};

        if(right.first < left.first)
            target = right;
        else if(right.first == left.first)
            target = left.second < right.second ? left : right;

        segmentTree[parent][0] = target.first;
        segmentTree[parent][1] = target.second;
        
        parent /= 2;
    }
}

pair<int, int> find_index(int start, int end, int left, int right, int node) {
    if(end < left || right < start) 
        return {MAX_VALUE, -1};
    
    if(left <= start && end <= right)
        return {segmentTree[node][0], segmentTree[node][1]};

    int middle = (start + end)/2;
    pair<int, int> lhs = find_index(start, middle, left, right, node*2);
    pair<int, int> rhs = find_index(middle+1, end, left, right, node*2+1);

    if(lhs.first == rhs.first)
        return lhs.second < rhs.second ? lhs : rhs;
    
    return lhs.first < rhs.first ? lhs : rhs;
}

void solution() {
    input();

    for(int i=1; i<SEG_TREE_SIZE; i++) {
        segmentTree[i][0] = MAX_VALUE;
        segmentTree[i][1] = n+1; 
    }
    
    for(int i=1; i<=n; i++)
        inset_element_to_tree(1, n, 1, i, A[i]);
    
    //Query
    for(auto q : query) {
        int type = q.first;
        int p1 = q.second.first;
        int p2 = q.second.second;

        if(type == 1) {
            inset_element_to_tree(1, n, 1, p1, p2);
            updateTree(p1);
        }
        else {
            auto result = find_index(1, n, p1, p2, 1);
            cout << result.second << endl;
        }
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
