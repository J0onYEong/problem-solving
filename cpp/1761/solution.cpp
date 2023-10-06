#include <bits/stdc++.h>
#define ll long long
#define endl "\n"

using namespace std;

const int max_range_of_N = 40000+1;
const int max_range_of_M = 10000+1;

int N, M;

vector<pair<int, int>> adjacentNodes[max_range_of_N];

int levelOfNode[max_range_of_N];

int ancestorOfNode[max_range_of_N][16+1];

int distanceBetweenNodes[max_range_of_N][16+1];

vector<pair<int, int>> query;

void input() {
    cin >> N;
    for(int i=1; i<=N-1; i++) {
        int leftNodeNumber, rightNodeNumber, distanceBetweenNodes;
        cin >> leftNodeNumber >> rightNodeNumber >> distanceBetweenNodes;

        adjacentNodes[leftNodeNumber].push_back({rightNodeNumber, distanceBetweenNodes});
        adjacentNodes[rightNodeNumber].push_back({leftNodeNumber, distanceBetweenNodes});
    }

    cin >> M;
    for(int i=1; i<=M; i++) {
        int from, to;
        cin >> from >> to;
        query.push_back({from, to});
    }
}

void setFirstParent(int nodeNumber, int parentNodeNumber, int level) {
    levelOfNode[nodeNumber] = level;
    for(auto sample : adjacentNodes[nodeNumber]) {

        int adjNumber = sample.first;
        int distance = sample.second;

        if(adjNumber != parentNodeNumber) {
            ancestorOfNode[adjNumber][0] = nodeNumber;
            distanceBetweenNodes[adjNumber][0] = distance;
            setFirstParent(adjNumber, nodeNumber, level+1);   
        }
    }
}

void setAncestor() {
    for(int k=1; k<=16; k++) {
        for(int i=1 ;i<=N; i++) {
            int middleAncestorNumber = ancestorOfNode[i][k-1];
            ancestorOfNode[i][k] = ancestorOfNode[middleAncestorNumber][k-1];
            distanceBetweenNodes[i][k] = distanceBetweenNodes[i][k-1] + distanceBetweenNodes[middleAncestorNumber][k-1];
        }
    }
}

int getDistanceBetweenNodes(int leftNodeNumnber, int rightNodeNumber) {
    int result = 0;
    //#1
    int levelOfLeftNode = levelOfNode[leftNodeNumnber];
    int levelOfRightNode = levelOfNode[rightNodeNumber];

    int deeperLevel = max(levelOfLeftNode, levelOfRightNode);
    int movingNode = deeperLevel == levelOfLeftNode ? leftNodeNumnber : rightNodeNumber;
    int targetNode = deeperLevel == levelOfLeftNode ? rightNodeNumber : leftNodeNumnber;

    for(int k=16; k>=0; k--){
        int ancestorNumber = ancestorOfNode[movingNode][k];
        if(ancestorNumber == 0)
            continue;

        if(levelOfNode[movingNode] == levelOfNode[targetNode])
            break;

        if(levelOfNode[ancestorNumber] < levelOfNode[targetNode]) 
            continue;
        else {
            result += distanceBetweenNodes[movingNode][k];
            movingNode = ancestorNumber;
        }
    }

    if(movingNode == targetNode)
        return result;
    

    //#2
    int lastMovingK = 0;
    for(int k=16; k>=0; k--) {
        if(ancestorOfNode[movingNode][k] != ancestorOfNode[targetNode][k]) {
            result += distanceBetweenNodes[movingNode][k];
            result += distanceBetweenNodes[targetNode][k];
            
            movingNode = ancestorOfNode[movingNode][k];
            targetNode = ancestorOfNode[targetNode][k];
        }
    }
    result += distanceBetweenNodes[movingNode][0];
    result += distanceBetweenNodes[targetNode][0];
    
    return result;
}


void solution() {
    input();

    memset(ancestorOfNode, 0, sizeof(ancestorOfNode));

    setFirstParent(1, -1, 0);

    setAncestor();

    for(auto q : query) 
        cout << getDistanceBetweenNodes(q.first, q.second) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}