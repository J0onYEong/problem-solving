#include <bits/stdc++.h>
#define ll long long
#define endl "\n"

using namespace std;

const int MAX_VERTEX_COUNT = 100000+1;
const int MAX_EDGE_COUNT = 100000+1;

int vetexCount, edgeCount;

vector<int> nodesDirectedByEdge[MAX_VERTEX_COUNT];

int discorveredTime[MAX_VERTEX_COUNT];
int sccNumberOfNode[MAX_VERTEX_COUNT];


void input() {
    cin >> vetexCount >> edgeCount;

    for(int i=1; i<=edgeCount; i++) {
        int from, to;
        cin >> from >> to;
        nodesDirectedByEdge[from].push_back(to);
    }
}

int nodeDiscoveryTime = 0;
int sccNumber = 1;
stack<int> nodeStack;

vector<vector<int>> sccList;

int dfs(int node) {
    int minOrder = discorveredTime[node] = nodeDiscoveryTime++;

    nodeStack.push(node);

    for(int adjNode : nodesDirectedByEdge[node]) {
        if(discorveredTime[adjNode] == -1) 
            minOrder = min(minOrder, dfs(adjNode));
        else if(sccNumberOfNode[adjNode] == -1) {
            //발견되었지만 SCC에 포함되지 않음
            minOrder = min(minOrder, discorveredTime[adjNode]);
        }
    }

    if(minOrder == discorveredTime[node]) {
        vector<int> scc;
        while(true) {
            int topNode = nodeStack.top();
            nodeStack.pop();

            scc.push_back(topNode);
            sccNumberOfNode[topNode] = sccNumber;
            
            if(topNode == node) 
                break;
        }
        sort(scc.begin(), scc.end());
        scc.push_back(-1);
        sccList.push_back(scc);

        sccNumber++;
    }

    return minOrder;
}

bool cmp(vector<int>& scc1, vector<int>& scc2) {
    return scc1.front() < scc2.front();
}


void solution() {
    input();

    memset(discorveredTime, -1, sizeof(discorveredTime));
    memset(sccNumberOfNode, -1, sizeof(sccNumberOfNode));

    for(int i=1; i<=vetexCount; i++) {
        if(discorveredTime[i] == -1) {
            dfs(i);
        }
    }

    sort(sccList.begin(), sccList.end(), cmp);

    cout << sccList.size() << endl;

    for(auto scc : sccList) {
        for(auto element : scc) {
            cout << element << " ";
        }
        cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
