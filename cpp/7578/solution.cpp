#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define NumberAndPos pair<int, int>
#define StartAndEnd pair<int, int>

using namespace std;

const int MAX_N = 500000;

const int TREE_SIZE = 1500000;

int N;
int segmentTree[TREE_SIZE];

vector<NumberAndPos> numberAndPoses;

bool cmp(NumberAndPos& lhs, NumberAndPos& rhs) {
    return lhs.first < rhs.first;
}

bool cmp2(StartAndEnd& lhs, StartAndEnd& rhs) {
    return lhs.first < rhs.first;
}

vector<StartAndEnd> startAndEnds;

int binarySearch(int start, int end, int target) {
    int mid = (start+end)/2;
    int midValue = numberAndPoses[mid].first;

    if(target == midValue) 
        return numberAndPoses[mid].second;

    if(target < midValue)
        return binarySearch(start, mid, target);
    else
        return binarySearch(mid+1, end, target);
}


void input() {
    cin >> N;

    for(int startIndex=0; startIndex<N; startIndex++) {
        int itemNumber;
        cin >> itemNumber;
        numberAndPoses.push_back({itemNumber, startIndex});
    }

    sort(numberAndPoses.begin(), numberAndPoses.end(), cmp);

    for(int endIndex=0; endIndex<N; endIndex++) {
        int itemNumber;
        cin >> itemNumber;

        int startIndex = binarySearch(0, numberAndPoses.size()-1, itemNumber);
        startAndEnds.push_back({startIndex, endIndex});
    }

    sort(startAndEnds.begin(), startAndEnds.end(), cmp2);
}

void updateSegementTree(int nodeIndex, int start, int end, int number) {
    segmentTree[nodeIndex]+=1;

    if(start==end) 
        return;

    int mid = (start+end)/2;

    if(number <= mid)
        updateSegementTree(nodeIndex*2, start, mid, number);
    else
        updateSegementTree(nodeIndex*2+1, mid+1, end, number);
}

int sumOfRange(int nodeIndex, int start, int end, int rs, int re) {
    if(rs > end || re < start)
        return 0;
    
    if(rs <= start && end <=re)
        return segmentTree[nodeIndex];

    int mid = (start+end)/2;

    int leftSum = sumOfRange(nodeIndex*2, start, mid, rs, re);
    int rightSum = sumOfRange(nodeIndex*2+1, mid+1, end, rs, re);

    return leftSum+rightSum;
}


void solution() {
    input();
    memset(segmentTree, 0, sizeof(segmentTree));

    ll result = 0;
    for(StartAndEnd se : startAndEnds) {
        int endIndex = se.second;

        updateSegementTree(1, 0, N-1, endIndex);
        
        int nextIndex = endIndex+1;
        if(nextIndex < N) 
            result+=sumOfRange(1, 0, N-1, nextIndex, N-1);
    }

    cout << result << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
