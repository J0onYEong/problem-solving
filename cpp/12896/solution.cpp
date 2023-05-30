#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

const int MAX = 100001;

class Vertex {

public:
    int index;
    vector<int> neighbors;

    void Init(int i);
};

void Vertex::Init(int i) {
    index = i;
}

int N;
Vertex vertice[MAX];

void findNodeWithDFS(int last, int index, int weight, int temp[], bool isFirst = false) {
    if(!isFirst && vertice[index].neighbors.size() == 1) {
        temp[index] = weight;
        return;
    }

    for(auto nb : vertice[index].neighbors) {
        if(last == nb)
            continue;
        findNodeWithDFS(index, nb, weight+1, temp);
    }
}


void solution() {
    cin >> N;

    for(int i=1; i<=N; i++) {
        Vertex temp;
        temp.Init(i);
        vertice[i] = temp;
    }

    for(int i=0; i<N-1; i++) {
        int u, v;
        cin >> u >> v;
        vertice[u].neighbors.push_back(v);
        vertice[v].neighbors.push_back(u);

    }


    int temp[N+1];
    memset(temp, 0, sizeof(int)*(N+1));
    findNodeWithDFS(-1, 1, 0, temp, true);
    int maxWeight = -1;
    int A;
    for(int i=1; i<=N; i++) {
        if(maxWeight < temp[i]) {
            maxWeight = temp[i];
            A = i;
        }
    }

    memset(temp, 0, sizeof(int)*(N+1));
    findNodeWithDFS(-1, A, 0, temp, true);
    maxWeight = -1;
    for(int i=1; i<=N; i++) 
        maxWeight = max(maxWeight, temp[i]);

    //최장거리 경로상의 중앙에 소방서를 배치하는 것이 가장 효율적이다.
    cout << (maxWeight+1)/2 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
