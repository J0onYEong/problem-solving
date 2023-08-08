#include <bits/stdc++.h>
#define ll long long
#define endl "\n"

using namespace std;

int D;

const int result_m = 1000000007;

// 정보과학관 - A
// 전산관 - B
// 미래관 - C
// 신앙관 - D
// 한경직기념관 - E
// 진리관 - F
// 학생회관 - G 
// 형남공학관 - H
int origin[8][8] = {
  // A B C D E F G H
    {0,1,1,0,0,0,0,0},
    {1,0,1,1,0,0,0,0},
    {1,1,0,1,1,0,0,0},
    {0,1,1,0,1,1,0,0},
    {0,0,1,1,0,1,0,1},
    {0,0,0,1,1,0,1,0},
    {0,0,0,0,0,1,0,1},
    {0,0,0,0,1,0,1,0}
};

ll** temp_org;

ll** multiple(ll **a, ll **b) {
    ll** temp = new ll*[8];

    for(int i=0; i<8; i++)
        temp[i] = new ll[8];

    for(int i=0; i<8; i++) 
        for(int j=0; j<8; j++) {
            ll element = 0;
            for(int k=0; k<8; k++) {
                element += a[i][k] * b[k][j];        
                element %= result_m; 
            } 
            temp[i][j] = element % result_m;
        } 
    return temp;
}

ll** multiple_ntimes(int n) {
    if(n == 1)
        return temp_org;

    if(n % 2 == 0) {
        ll** result = multiple_ntimes(n/2);
        return multiple(result, result);
    }
    else {
        ll** result1 = multiple_ntimes(n/2);
        ll** result2 = multiple(result1, result1);

        return multiple(result2, temp_org);
    }
}


void input() {
    cin >> D;
}

void solution() {
    input();
    temp_org = new ll*[8];
    for(int i=0; i<8; i++) 
        temp_org[i] = new ll[8];
        
    for(int i=0; i<8; i++)
        for(int j=0; j<8; j++)
            temp_org[i][j] = origin[i][j];

    ll** result = multiple_ntimes(D);

    cout << result[0][0] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
