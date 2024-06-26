#include <iostream>
#include <vector>
#include <unordered_map>
#define ll long long
#define endl "\n"

using namespace std;

int N, M;

unordered_map<int, bool> member;

vector<vector<int>> party;

void input() {

    cin >> N >> M;

    party = vector<vector<int>>(M, vector<int>());

    for(int i=1; i<=N; i++) 
        member[i] = false;

    int truth_cnt;
    cin >> truth_cnt;

    for(int i=0; i<truth_cnt; i++) {

        int truth_member;
        cin >> truth_member;

        member[truth_member] = true;
    }

    for(int i=0; i<M; i++) {

        int member_cnt;

        cin >> member_cnt;

        bool flag = false;

        for(int j=0; j<member_cnt; j++) {

            int party_member;

            cin >> party_member;

            party[i].push_back(party_member);
        }
    }

    for(int k=0; k<M; k++) {

        for(int i=M-1; i>=0; i--) {

            bool flag = false;

            for(auto m : party[i]) {

                if(member[m]) {

                    flag = true;
                    break;
                }
            }  

            if(flag) {

                for(auto m : party[i]) {

                    member[m] = true;
                }
            }
        }
    }
}

void solution() {
    input();

    int cnt = 0;

    for(int i=0; i<party.size(); i++) {

        bool flag = true;

        for(auto p : party[i]) {

            if(member[p]) {

                flag = false;
                break;
            }
        }

        if(flag)
            cnt++;
    }

    cout << cnt << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
