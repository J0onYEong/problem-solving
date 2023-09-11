#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define DirectedEdge pair<int, int>

using namespace std;

const int NOT_SETTED = 10000000;

const int MAX_N = 500;
const int MAX_M = 10000;

int N, M;
int startNumber, destinationNumber; 
int startToNode[MAX_N];
vector<DirectedEdge> nodeToNode[MAX_N];
vector<DirectedEdge> nodeToNode_reverse[MAX_N];

bool edgeAvailalbility[MAX_N][MAX_N];

bool checkedNode[MAX_N];

void input() {
    cin >> N >> M;
    if(N==0 && M==0)
        return;

    cin >> startNumber >> destinationNumber;

    for(int i=0; i<MAX_N; i++) {
        nodeToNode[i].clear();
        nodeToNode_reverse[i].clear();
    }

    memset(edgeAvailalbility, false, sizeof(edgeAvailalbility));
    
    for(int i=0; i<M; i++) {
        int U, V, P;
        cin >> U >> V >> P;
        edgeAvailalbility[U][V] = true;
        nodeToNode[U].push_back({V, P});
        nodeToNode_reverse[V].push_back({U, P});
    }
}

void backTracing(int node, int restOfCost) {
    if(node == startNumber) 
        return;
    
    checkedNode[node] = true;

    for(DirectedEdge reverseEdge : nodeToNode_reverse[node]) {
        int preNodeNumber = reverseEdge.first;
        int cost = reverseEdge.second;
        int startToPreNodeCost = startToNode[preNodeNumber];

        if(startToPreNodeCost == restOfCost-cost) {
            edgeAvailalbility[preNodeNumber][node] = false;

            if(!checkedNode[preNodeNumber])
                backTracing(preNodeNumber, restOfCost-cost);
        }
    }
}

struct cmp {
    bool operator()(DirectedEdge& lhs, DirectedEdge& rhs) {
        return lhs.second > rhs.second;
    }
};

priority_queue<DirectedEdge, vector<DirectedEdge>, cmp> *pq;

void dijkstra(int node, int cumulatedEdge) {
    
    if(node == destinationNumber)
        return;
    
    for(auto edge : nodeToNode[node]) {
        int nextNode = edge.first;
        int cost = cumulatedEdge + edge.second;

        if(edgeAvailalbility[node][nextNode] && startToNode[nextNode] > cost) {
            startToNode[nextNode] = cost;

            pq->push({nextNode, cost});
        }
    }  

    if(!pq->empty()) {
        DirectedEdge temp = pq->top();
        pq->pop();

        dijkstra(temp.first, temp.second);
    }
}

void solution() {
    while(true) {
        input();
        if(N==0 && M==0)
            break;

        for(int i=0; i<N; i++)
            startToNode[i] = NOT_SETTED;
        startToNode[startNumber] = 0;

        pq = new priority_queue<DirectedEdge, vector<DirectedEdge>, cmp>();
        dijkstra(startNumber, 0);

        memset(checkedNode, false, sizeof(checkedNode));
        backTracing(destinationNumber, startToNode[destinationNumber]);

        for(int i=0; i<N; i++)
            startToNode[i] = NOT_SETTED;
        startToNode[startNumber] = 0;

        pq = new priority_queue<DirectedEdge, vector<DirectedEdge>, cmp>();
        dijkstra(startNumber, 0);
        
        int result = startToNode[destinationNumber];

        cout << (result == NOT_SETTED ? -1 : result) << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
