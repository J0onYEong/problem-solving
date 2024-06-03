#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#define ll long long
#define endl "\n"

using namespace std;

int N, M;
// 문제, 난이도
map<int, int> difficulty;

set<pair<int, int>> problem;

void input() {

    cin >> N;
    
    for(int i=0; i<N; i++) {
        int p, l;

        cin >> p >> l;
        
        // 난이도, 문제
        problem.insert({l, p});
        difficulty[p] = l;
    }

    cin >> M;
}

void solution() {
    input();

    for(int i=0; i<M; i++) {

        string q;
        cin >> q;

        if(q == "recommend") {
            int x;
            cin >> x;

            if(x == 1) {

                auto mod = problem.rbegin();

                cout << mod -> second << endl;
            } else {

                auto mod = problem.begin();

                cout << mod -> second << endl;
            }


        } else if(q == "add") {

            int p, l;

            cin >> p >> l;

            problem.insert({l, p});

            difficulty[p]=l;
        } else {

            int p;
            cin >> p;

            problem.erase({difficulty[p], p});
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
