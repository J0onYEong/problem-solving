#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#define pp pair<int,int>

using namespace std;

bool cmp(const pp &lhs, const pp &rhs) {
    if(lhs.second == rhs.second)
        return lhs.first < rhs.first;
    return lhs.second > rhs.second;
}

void solution() {
    while(true) {
        int n, m;
        map<int, int> score;
        cin >> n >> m;
        if(n == 0 && m == 0) break;

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                int input;
                cin >> input;
                score[input] += 1;
            }
        }

        vector<pp> vec (score.begin(), score.end());
        sort(vec.begin(), vec.end(), cmp);

        int secondValue = vec[1].second;
        for(int i=1; i<vec.size(); i++)
            if(vec[i].second == secondValue)
                cout << vec[i].first << " ";
        cout << "\n";
    }
}


int main() {
    cin.tie(NULL);
    solution();
    return 0;
}