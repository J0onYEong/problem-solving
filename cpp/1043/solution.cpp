#include <iostream>
#include <vector>
#include <unordered_map>
#define ll long long
#define endl "\n"

using namespace std;

int N, M;

vector<vector<int>> party;
vector<int> parent;

unordered_map<int, bool> truth_people;

int find_root(int member) {

    int p = parent[member];

    if(member == p) 
        return p;
    else 
        return parent[member] = find_root(p);
}

void union_people(int m1, int m2) {

    int p1 = find_root(m1);
    int p2 = find_root(m2);

    if(p1 < p2)
        parent[p2] = p1;
    else if(p2 < p1) 
        parent[p1] = p2;
}

void input() {

    cin >> N >> M;

    party = vector<vector<int>>(M, vector<int>());

    parent = vector<int>(N+1, -1);

    for(int i=1; i<=N; i++)
        parent[i] = i;

    int truth_cnt;
    cin >> truth_cnt;

    vector<int> truth_members;

    for(int i=0; i<truth_cnt; i++) {

        int truth_member;
        cin >> truth_member;   

        truth_members.push_back(truth_member);
    }

    for(int i=0; i<M; i++) {

        int member_cnt;

        cin >> member_cnt;

        int prev, current;

        for(int j=0; j<member_cnt; j++) {

            cin >> current;

            party[i].push_back(current);

            if(j > 0)
                union_people(prev, current);

            prev = current;
        }
    }

    for(auto m : truth_members) {

        int r = find_root(m);

        truth_people[r] = true;
    }

    // for(int i=1; i<=N; i++) {

    //     cout << parent[i] << " ";
    // }
    // cout << endl;
}

void solution() {
    input();

    int cnt = 0;

    for(int i=0; i<M; i++) {

        int r = find_root(party[i][0]);

        if(!truth_people[r]) 
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
