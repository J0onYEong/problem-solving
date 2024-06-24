#include <iostream>
#include <vector>
#include <stack>

#define ll long long
#define endl "\n"

using namespace std;

int n;
vector<int> tower;

void input() {

    cin >> n;

    tower = vector<int>(n, 0);

    for(int i=0; i<n; i++) {

        cin >> tower[i];
    }
}

void solution() {
    input();

    stack<pair<int, int>> s;

    for(int order=1; order <= tower.size(); order++) {

        int t = tower[order-1];

        while(true) {

            if(s.empty()) {

                s.push({t, order});

                cout << 0 << " ";
                break;
            }

            if(s.top().first < t) {
                
                s.pop();
            } else {

                cout << s.top().second << " ";

                s.push({t, order});

                break;
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
