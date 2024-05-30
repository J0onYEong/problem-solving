#include <iostream>
#include <vector>
#include <map>
#define ll long long
#define endl "\n"

using namespace std;

map<int, int> popularPlace;

int N, Q;

void input() {

    cin >> N >> Q;

    for(int i=0; i<N; i++) {

        int state;
        cin >> state;

        if(state) {

            popularPlace.insert({i, 1});
        }
    }

}

void solution() {
    input();

    int pos = 0;

    for(int i=0; i<Q; i++) {

        int query;
        cin >> query;

        switch (query)
        {
        case 1:
            int willChangePos;
            cin >> willChangePos;

            willChangePos--;

            if(popularPlace.count(willChangePos)) {

                popularPlace.erase(willChangePos);
            } else {

                popularPlace.insert({willChangePos, 1});
            }

        break;
        case 2:
            int movingCnt;
            cin >> movingCnt;

            pos = (pos + movingCnt) % N;
        break;

        case 3:

            if(popularPlace.size() == 0) {

                cout << -1 << endl;
                break;
            }
            
            int haveToMove = 0;

            auto next = popularPlace.lower_bound(pos);

            if(next == popularPlace.end()) {

                haveToMove += N-pos;

                haveToMove += (*popularPlace.begin()).first;
            } else {

                int next_pos = (*next).first;

                haveToMove += (next_pos-pos);   
            }

            cout << haveToMove << endl;
            
        break;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
