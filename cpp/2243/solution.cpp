#include <bits/stdc++.h>
#define ll long long
#define endl "\n"

using namespace std;

const int MAX_QUERY_COUNT = 100000+1;
const int MAX_VALUE_OF_FlAVOR = 1000000;

int countOfQuery;

vector<int> segmentTree;

vector<pair<int, pair<int, int>>> query;

void input() {
    cin >> countOfQuery;
    for(int i=1; i<=countOfQuery; i++) {
        int queryType;
        cin >> queryType;

        if(queryType == 1) {
            int orderOfCandy;
            cin >> orderOfCandy;

            query.push_back({queryType, {orderOfCandy, 0}});
        }
        
        if(queryType == 2) {
            int flavorOfCandy, countOfCandy;
            cin >> flavorOfCandy >> countOfCandy;

            query.push_back({queryType, {flavorOfCandy, countOfCandy}});
        }
    }
}

int findCandyByOrder(int start, int end, int index, int candyCntOfBelow) {
    if(start == end) {
        return start;    
    }

    int sumOfLeft = segmentTree[index*2];
    int sumOfRight = segmentTree[index*2+1];
    int middle = (start+end)/2;

    if(candyCntOfBelow >= sumOfLeft) {
        return findCandyByOrder(middle+1, end, index*2+1, candyCntOfBelow-sumOfLeft);
    }
    
    return findCandyByOrder(start, middle, index*2, candyCntOfBelow);
}

void insertCandyToBox(int start, int end, int flavor, int count, int index) {
    int middle = (start+end)/2;

    segmentTree[index] += count;

    if(start == end)
        return;

    if(flavor <= middle)
        insertCandyToBox(start, middle, flavor, count, index*2);
    else
        insertCandyToBox(middle+1, end, flavor, count, index*2+1);
}

void setSegmentTree() {
    //가장낮은 단계를 1로한다.
    //가능한 맛의수가 8일 경우 4단계로 구현
    int treeHeight = (int)ceil(log2(MAX_VALUE_OF_FlAVOR)) + 1;
    int vectorSizeForTree = 1 << treeHeight;

    //사이즈는 정확하지만 1부터 시작하기 위해 1의 공간을 더 할당한다.
    segmentTree.resize(vectorSizeForTree+1);

    for(int i=1; i<= vectorSizeForTree; i++)
        segmentTree[i] = 0;
}


void solution() {
    input();

    setSegmentTree();

    for(auto q : query) {
        int queryType = q.first;

        if(queryType == 1) {
            int orderOfCandy = q.second.first;
            int flavorNumber = findCandyByOrder(1, MAX_VALUE_OF_FlAVOR, 1, orderOfCandy-1);
            insertCandyToBox(1, MAX_VALUE_OF_FlAVOR, flavorNumber, -1, 1);
            cout << flavorNumber << endl;
        }

        if(queryType == 2) {
            int flavorOfCandy = q.second.first;
            int countOfCandy = q.second.second;
            insertCandyToBox(1, MAX_VALUE_OF_FlAVOR, flavorOfCandy, countOfCandy, 1);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
