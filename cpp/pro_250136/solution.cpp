#include <string>
#include <vector>
#include <queue>
#define Pos pair<short, short>

using namespace std;

const short max_length = 500;

short ver[4] = {0,0,1,-1};
short hor[4] = {1,-1,0,0};

int solution(vector<vector<int>> land) {
    short n = land.size();
    short m = land[0].size();
    
    int answer = 0;
    
    // 그룹 포인터는 인덱스를 저장한다. 인덱스는 0부터 시작
    int group_pointer[max_length][max_length];
    
    // 그룹인덱스를 -1로 초기화: 지정되지 않음
    for(short i=0; i<n; i++) {
        
        for(short j=0; j<m; j++) {
            
            group_pointer[i][j] = -1;
            
        }
        
    }
    
    // 그룹은 그룹멤버의 수를 저장한다.
    vector<int> group;
    
    int current_group_index = -1;
    
    queue<Pos> q;
    
    for(short i=0; i<n; i++) {
        
        for(short j=0; j<m; j++) {
            
            // 기름땅이고 방문한적이 없는 경우
            if(land[i][j] == 1 && group_pointer[i][j] == -1) {
                
                current_group_index += 1;
                
                group_pointer[i][j] = current_group_index;
                
                group.push_back(1);
                
                q.push({i, j});
    
                while(!q.empty()) {
                    
                    Pos current_pos = q.front();
                    
                    q.pop();
                    
                    for(short k=0; k<4; k++) {
                        
                        short ni = current_pos.first + ver[k];
                        short nj = current_pos.second + hor[k];
                        
                        // 범위 이탈
                        if(ni < 0 || ni >= n || nj < 0 || nj >=m)
                            continue;
                        
                        // 기름땅이고 방문한적이 없는 경우
                        if(land[ni][nj] == 1 && group_pointer[ni][nj] == -1) {
                            
                            group_pointer[ni][nj] = current_group_index;
                            
                            // 그룹원이 추가되었음으로
                            group[current_group_index] += 1;
                            
                            q.push({ni, nj});
                        }
                        
                    }
                    
                }
                    
            }
            
        }
        
    }
    
    int max_oil = 0;
    
    for(short j=0; j<m; j++) {
        
        int temp_oil = 0;
        
        int current_index = -1;
        
        for(short i=0; i<n; i++) {
            
            // 중복중이 아니고 기름땅일 경우
            if(land[i][j] == 1 && group_pointer[i][j] != current_index) {
                
                current_index = group_pointer[i][j];
                
                temp_oil += group[group_pointer[i][j]];
                
            }
            
        }
        
        if(max_oil < temp_oil) {
            
            max_oil = temp_oil;
            
        }
        
    }
    
    answer = max_oil;

    return answer;
}