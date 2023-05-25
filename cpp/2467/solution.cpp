#include <bits/stdc++.h>
#define ll long long
#define endl "\n"

using namespace std;

void solution() {
    int n;
    cin >> n;
    int L[100000];

    for(int i=0; i<n; i++)
        cin >> L[i];
    
    sort(L, L+n);

    int left = -1, right = -1;

    for(int i=0; i<n; i++) {
        if(L[i] >= 0) {
            right = i;
            break;
        }
    }

    //전부 음수
    if(right == -1) {
        cout << L[n-2] << " " <<L[n-1] << endl;
        return;
    } else if(right == 0) {
        //음수 없음
        cout << L[0] << " " << L[1] << endl;
        return;
    } else {
        //음양 존재

        //0이 2개이상 있을 때
        if(right <= n-2 && L[right] == 0 && L[right+1] == 0) {
            cout << 0 <<" "<< 0 <<endl;
            return;
        }

        left = right-1;
    }
    int result;
    int l, r;
    if(right <= n-2) {
        result = abs(L[right]+L[right+1]);
        l = right;
        r = right+1;
    }
    if(left >= 1) {
        int temp = abs(L[left]+L[left-1]);
        if(result > temp) {
            result = temp;
            l = left-1;
            r = left;
        }
    }
    
    while(!(left < 0 || right >= n)) {
        int temp = L[left]+L[right];
        if(result > abs(temp)) {
            result = abs(temp);
            l = left;
            r = right;
        }
        if(temp < 0)
            right++;
        else
            left--;
    }
    cout << L[l] << " " << L[r] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
