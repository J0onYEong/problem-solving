#include <iostream>
#include <vector>
#include <queue>
#define ll long long
#define endl "\n"

using namespace std;

int N, K, M;

vector<vector<int>> hyper_link;
vector<vector<int>> station_hl;

void input() {

    cin >> N >> K >> M;

    hyper_link = vector<vector<int>>(M, vector<int>());
    station_hl = vector<vector<int>>(N, vector<int>());

    for(int i=0; i<M; i++) {

        for(int k=0; k<K; k++) {

            int station;

            cin >> station;

            int index = station-1;

            hyper_link[i].push_back(index);

            station_hl[index].push_back(i);
        }
    }  
}

void solution() {
    input();

    if(N == 1) { 

        cout << 1 << endl;
        return;
    }

    // station_number, 거쳐간 역의수
    queue<pair<int, int>> q;

    // station 방문
    vector<bool> isVisited = vector<bool>(N, false);

    vector<bool> isVisited_hl = vector<bool>(M, false);

    q.push({0, 1});

    isVisited[0] = true;

    int des = N-1;

    while(!q.empty()) {

        int current_station = q.front().first;
        int station_cnt = q.front().second;

        q.pop();

        for(auto hl : station_hl[current_station]) {

            if(!isVisited_hl[hl]) {

                isVisited_hl[hl] = true;

                for(auto next_station : hyper_link[hl]) {

                    if(!isVisited[next_station]) {

                        isVisited[next_station] = true;

                        if(next_station == des) {

                            cout << station_cnt + 1 << endl;
                            return;
                        }   
                    
                        q.push({next_station, station_cnt+1});
                    }
                }
            }
        }
    }

    cout << -1 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
