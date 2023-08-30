#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define WeightAndNode pair<int, int>

using namespace std;

const int MAX_N = 10000+1;
const int MAX_M = 100000+1;
const int INF = 100000000;

int N, M;

int startNodeOfProblem, endNodeOfProblem;

vector<WeightAndNode> possibleMovementNodes[MAX_N];
vector<WeightAndNode> reversePossibleMovementNodes[MAX_N];

int resultEdgeCount = 0;

int entryCountOfNode[MAX_N];

void input() {
    cin >> N >> M;

    memset(entryCountOfNode, 0, sizeof(entryCountOfNode));
    for(int i=1; i<=M; i++) {
        int startNode, endNode, timeExpense;
        cin >> startNode >> endNode >> timeExpense;

        entryCountOfNode[endNode]++;

        possibleMovementNodes[startNode].push_back({timeExpense, endNode});
        reversePossibleMovementNodes[endNode].push_back({timeExpense, startNode});
    }

    cin >> startNodeOfProblem >> endNodeOfProblem;
}

int longestTimeFromStart[MAX_N];

void dijkstra() {

    for(int i=1; i<=N; i++)
        longestTimeFromStart[i] = 0;
    
    queue<WeightAndNode> q;

    q.push({0, startNodeOfProblem});

    while(!q.empty()) {
        WeightAndNode now = q.front();
        q.pop();

        int cumulatedTime = now.first;
        int nowNode = now.second;

        for(WeightAndNode adj : possibleMovementNodes[nowNode]) {
            int adjNodeNumber = adj.second;
            int targetNodeTimeExpense = longestTimeFromStart[adjNodeNumber];
            int newTimeExpense = cumulatedTime + adj.first;

            longestTimeFromStart[adjNodeNumber] = max(longestTimeFromStart[adjNodeNumber], newTimeExpense);

            entryCountOfNode[adjNodeNumber]--;

            if(entryCountOfNode[adjNodeNumber] == 0)
                q.push({longestTimeFromStart[adjNodeNumber], adjNodeNumber});
        }
    }
}

bool visitedNode[MAX_N];

void backTracking(int node, int timeExpense) {
    visitedNode[node] = true;
    for(auto expenseAndNode : reversePossibleMovementNodes[node]) {
        int theRestTimeExpense = timeExpense - expenseAndNode.first;

        int adjacentNode = expenseAndNode.second;

        if(theRestTimeExpense == longestTimeFromStart[adjacentNode]) {
            resultEdgeCount++;

            if(!visitedNode[adjacentNode]) 
                backTracking(adjacentNode, theRestTimeExpense);
        }
    }
}

void solution() {
    input();

    dijkstra();

    int longestTimeExpense = longestTimeFromStart[endNodeOfProblem]; 

    memset(visitedNode, false, sizeof(visitedNode));
    backTracking(endNodeOfProblem, longestTimeExpense);

    cout << longestTimeExpense << endl;
    cout << resultEdgeCount << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
