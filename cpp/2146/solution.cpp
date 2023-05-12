#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define pos pair<int, int> // 노드 좌표

using namespace std;

int n;
int m[100][100];
// 노드 1~10000
int parent[10000];
// 좌표 탐색
int X[] = {1, 0, -1, 0};
int Y[] = {0, 1, 0, -1};

int nodeNum(int x, int y)
{
    return n * (x) + y;
}

int find_root(int node)
{
    if (parent[node] == node)
    {
        return node;
    }
    return parent[node] = find_root(parent[node]);
}

bool check_union(int n1, int n2)
{
    return find_root(n1) == find_root(n2);
}

void union_node(int n1, int n2)
{
    int r1 = find_root(n1);
    int r2 = find_root(n2);

    if (r1 < r2)
        parent[r2] = r1;
    else if (r1 > r2)
        parent[r1] = r2;
}

void solution()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> m[i][j];
    for (int i = 0; i < n * n; i++)
        parent[i] = i;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            if (m[i][j] == 1)
            {
                for (int k = 0; k < 2; k++)
                {
                    int t1 = i + X[k];
                    int t2 = j + Y[k];
                    if (t1 >= 0 && t1 < n && t2 >= 0 && t2 < n && m[t1][t2])
                        union_node(nodeNum(i, j), nodeNum(t1, t2));
                }
            }
        }

    int result = 10001;
    bool visit[100][100];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (m[i][j])
            {   
                for(int l=0; l<100; l++)
                    memset(visit[l], 0, sizeof(bool)*100);
                queue<pair<int, pos> > q;
                // cost, direc, x, y
                q.push(make_pair(0, make_pair(i, j)));
                while (!q.empty())
                {
                    int cost = q.front().first;
                    pos temp = q.front().second;
                    q.pop();
                    if (cost >= result)
                        break;

                    for (int k = 0; k < 4; k++)
                    {
                        int t1 = temp.first + X[k];
                        int t2 = temp.second + Y[k];
                        if (t1 >= 0 && t1 < n && t2 >= 0 && t2 < n)
                        {
                            
                            if(visit[t1][t2]) 
                                continue;
                            
                            if (m[t1][t2])
                            {
                                // land
                                if (!check_union(nodeNum(i, j), nodeNum(t1, t2))) {
                                    result = min(result, cost);
                                    while(!q.empty()) 
                                        q.pop();
                                    break;
                                }
                            }
                            else
                            {
                                // sea
                                visit[t1][t2] = true;
                                q.push(make_pair(cost+1, make_pair(t1, t2)));
                            }
                        }
                    }
                }
            }    
    cout << result << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
