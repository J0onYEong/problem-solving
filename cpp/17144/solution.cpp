#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define pos pair<int, int>

using namespace std;

void solution() {
    int n, m, t;
    cin >> n >> m >> t;
    int location[50][50];
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin >> location[i][j];
    int runCount = 0;
    int horizontal[4] = {1, -1 ,0, 0};
    int vertical[4] = {0, 0, 1, -1};
    while(runCount++ < t) {
        vector<pos> dust;
        vector<pos> airConditioner;
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++) {
                if(location[i][j] == -1) 
                    airConditioner.push_back(make_pair(i, j));
                else if(location[i][j] != 0) 
                    dust.push_back(make_pair(i, j));
            }

        // 먼지 확장
        int newData[50][50];
        for(int i=0; i<n; i++) 
            for(int j=0; j<m; j++)
                newData[i][j] = 0;
        for(auto d : dust) {
            int value = location[d.first][d.second];
            int part = value/5;
            for(int i=0;i<4;i++) {
                int ex_n = d.first+vertical[i];
                int ex_m = d.second+horizontal[i];
                // 좌표 유효성 검사
                if(ex_n<0 || ex_n>=n || ex_m<0 || ex_m>=m) continue;
                else if(location[ex_n][ex_m] == -1) continue;

                newData[ex_n][ex_m] += part;
                value -= part;
            }
            newData[d.first][d.second] += value;
        }
        

        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                if(location[i][j] != -1)
                    location[i][j] = newData[i][j];
        
        // 공기청정기 가동
        int newData2[50][50];
        for(int i=0; i<n; i++) 
            for(int j=0; j<m; j++) 
                newData2[i][j] = location[i][j];
        int up_h[4] = {1, 0, -1, 0};
        int up_v[4] = {0, -1, 0, 1};
        int bot_h[4] = {1, 0, -1, 0};
        int bot_v[4] = {0, 1, 0, -1};
        int x = airConditioner[0].first;
        int y = airConditioner[0].second;
        int i = 0;
        newData2[x+up_v[i]][y+up_h[i]] = 0;
        while(true) {
            x += up_v[i];
            y += up_h[i];
            int next_x = x + up_v[i];
            int next_y = y + up_h[i];
            if(next_x<0 || next_x>=n || next_y<0 || next_y>=m) {
                i++;
                next_x = x + up_v[i];
                next_y = y + up_h[i];
            }
            if(i == 4) i = 0;
            if(location[x][y] == -1) break;
            newData2[next_x][next_y] = location[x][y];
        }

        x = airConditioner[1].first;
        y = airConditioner[1].second;
        i = 0;
        newData2[x+bot_v[i]][y+bot_h[i]] = 0;
        while(true) {
            x += bot_v[i];
            y += bot_h[i];
            int next_x = x + bot_v[i];
            int next_y = y + bot_h[i];
            if(next_x<0 || next_x>=n || next_y<0 || next_y>=m) {
                i++;
                next_x = x + bot_v[i];
                next_y = y + bot_h[i];
            }
            if(i == 4) i = 0;
            if(location[x][y] == -1) break;
            newData2[next_x][next_y] = location[x][y];
        }

        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                if(location[i][j] != -1)
                    location[i][j] = newData2[i][j];
    }
    int sum = 0;

    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++) {
            sum += (location[i][j] == -1) ? 0 : location[i][j];
        }
    cout << sum << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
