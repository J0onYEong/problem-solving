#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#define ll long long
#define endl "\n"

using namespace std;

int n;
vector<int> number_set;

void input() {
    cin >> n;

    for(int i=0; i<n; i++) {
        int u;
        cin >> u;
        number_set.push_back(u);
    }
}

void solution() {
    input();

    vector<int> apb;

    sort(number_set.begin(), number_set.end());

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            int a = number_set[i];
            int b = number_set[j];

            apb.push_back(a+b);
        }   
    }

    sort(apb.begin(), apb.end());
 
    for(int i=n-1; i>=0; i--) {
        for(int j=i; j>=0; j--) {
            int d = number_set[i];
            int c = number_set[j];
            int dmc = d-c;

            int l = 0, r = apb.size()-1;

            while(l <= r) {
                int m = (l + r) / 2;

                if(dmc == apb[m]) {
                    cout << d << endl;
                    return;
                } else if(dmc < apb[m])
                    r = m-1;
                else
                    l = m+1;
            }
        }   
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
