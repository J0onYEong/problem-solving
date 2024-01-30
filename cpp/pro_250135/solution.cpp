#include <iostream>
#include <vector>
#define ll long long
#define endl "\n"
#define Bound pair<int, int>

using namespace std;

 // 시침의 이동단위: 60분 5칸 => 1분 1/12칸 => 1초 => 1/720칸
int d_hour = 1;
        
// 분침 1분에 1칸 => 1초에 1/60칸
int d_minute = 12; 
        
// 시침 1초에 1칸
int d_second = 720;
    
// 60초 마다 초기화
// 60x720마다 초기화 43,200칸
int move_limit = 43200;

Bound getBound(int pos, int dis) {
    
    int min_b = pos-dis;
    int max_b = pos-1;
    
    if(min_b < 0) {
        
        min_b = move_limit - min_b;
    }
    
    if(max_b < 0) {
        
        max_b = move_limit - max_b;
    }
    
    return {min_b, max_b};
}

bool inBoundCheock(int b1, int b2, int origin, int target) {

    if(b1 > origin && b2 < origin) {
        
        return (b1 <= target) || (0 <= target && target <=b2);
 
    } else {

        return (b1 <= target) && (target <= b2);
    }

}

int solution(int h1, int m1, int s1, int h2, int m2, int s2) {
    int answer = 0;
    
    // 한번의 이동은 1초이다 범위가 초단위로 주어지기 때문이다.
    // 초침이 다른 침과 마주치는 조건
    // - 이동 후 초침이 분침 혹은 시침 보다 같거나 앞에 위치 
    
    int cycle = ((h2-h1)*720 + (m2-m1)*60 + (s2-s1));

    cout << cycle << endl;

    int cur_h = h1 * 5 * d_second + (m1 * 720 + s1);
    int cur_m = m1 * d_second + cycle * d_minute;
    int cur_s = s1 * d_second;

    for(int i=0; i<=cycle; i++) {
        
        Bound h_bound = getBound(cur_h, d_second-d_hour);
        Bound m_bound = getBound(cur_m, d_second-d_minute);
        
        int temp = 0;    

        cout << cur_h << " " << cur_m << " " << cur_s << endl;
    
        if(inBoundCheock(h_bound.first, h_bound.second, cur_h, cur_s)) 
            temp+=1;

        cout << "시간 바운드 " << h_bound.first << " : " << h_bound.second << endl;

        cout << "분 바운드 " << m_bound.first << " : " << m_bound.second << endl;

        if(inBoundCheock(m_bound.first, m_bound.second, cur_m, cur_s)) 
            temp+=1; 

        // 다음에 3침이 한번에 겹칩
        if(cur_s == h_bound.first && cur_s == m_bound.first) {
            temp = 1;
        }
        
        answer += temp;

        if(temp > 0) {
            cout << "HEAT" << endl;
        }
        
        cur_h = (cur_h + d_hour) % move_limit;
        cur_m = (cur_m + d_minute) % move_limit;
        cur_s = (cur_s + d_second) % move_limit;
    }
    
    return answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int h1, m1, s1, h2, m2, s2;

    cin >> h1 >> m1 >> s1 >> h2 >> m2 >> s2;

    solution(h1, m1, s1, h2, m2, s2);

    return 0;
}
