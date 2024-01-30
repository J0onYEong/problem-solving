#include <iostream>
#include <vector>
#define ll long long
#define endl "\n"
#define Edge pair<int, int> // des, weight
#define INF 1000000000

using namespace std;

int n, m;

ll distance_from1[501];

vector<pair<Edge, int>> edges;

void input() {

    cin >> n >> m;

    for(int i=0; i<m; i++) {
        int a, b, c;
        
        cin >> a >> b >> c;

        edges.push_back({{a, b}, c});
    }

    for(int i=2; i<=n; i++)
        distance_from1[i] = INF;
}


void solution() {

    input();

    distance_from1[1] = 0;

    for(int i=0; i<n; i++) {

        for(pair<Edge, int> e : edges) {
            int srt = e.first.first;
            int des = e.first.second;
            int weight = e.second;

            if(distance_from1[srt] != INF && distance_from1[des] > distance_from1[srt] + weight) {

                distance_from1[des] = distance_from1[srt] + weight;

                if(i == n-1) {
                    cout << -1 << endl;
                    return;
                }
            }
        }
    }

    for(int i=2; i<=n; i++) {
        if(distance_from1[i] == INF) {
            cout << -1 << endl;
            continue;
        }
        cout << distance_from1[i] << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
