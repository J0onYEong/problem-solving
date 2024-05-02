#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define ll long long
#define endl "\n"

using namespace std;

// 자신보다 더작은 노드들을 가리킴
vector<vector<int>> correct_list;

// 더 무건운 노드
vector<vector<int>> reverse_list;

int N, M;

vector<bool> isVisited;

void input() {

    cin >> N >> M;

    correct_list = vector<vector<int>> (N);
    reverse_list = vector<vector<int>> (N);


    for(int i=0; i<M; i++) {
        int heavier;
        int lighter;

        cin >> heavier >> lighter;

        correct_list[heavier-1].push_back(lighter-1);
        reverse_list[lighter-1].push_back(heavier-1);

    }
}


int recursive(int current, const vector<vector<int>> &relation) {

    int cnt = 0;

    for(auto nxt : relation[current]) {

        if(!isVisited[nxt]) {

            isVisited[nxt] = true;

            cnt += ( 1 + recursive(nxt, relation) );
        }
    }

    return cnt;
}


void solution() {

    input();

    int result = 0;

    // DFS
    // for(int i=0; i<N; i++) {

    //     isVisited = vector<bool>(N, false);

    //     int smallerNodeCnt = recursive(i, correct_list);

    //     isVisited = vector<bool>(N, false);

    //     int biggerNodeCnt = recursive(i, reverse_list);

    //     if(smallerNodeCnt > N/2 || biggerNodeCnt >N/2) {

    //         result++;
    //     } 
    // }


    // BFS
    for(int i=0; i<N; i++) {


        queue<int> q;

        isVisited = vector<bool>(N, false);

        q.push(i);

        int bigger_cnt = 0;

        // 자신보다 무거운 것
        while(!q.empty()) {

            int current = q.front();

            q.pop();

            for(int nxt : correct_list[current]) {

                if(!isVisited[nxt]) {

                    isVisited[nxt] = true;

                    bigger_cnt++;

                    q.push(nxt);
                }
            }
        }

        isVisited = vector<bool>(N, false);

        q.push(i);

        int smaller_cnt = 0;

        while(!q.empty()) {

            int current = q.front();

            q.pop();

            for(int nxt : reverse_list[current]) {

                if(!isVisited[nxt]) {

                    isVisited[nxt] = true;

                    smaller_cnt++;

                    q.push(nxt);
                }
            }
        }

        if(bigger_cnt > N/2 || smaller_cnt >N/2) {

            result ++;
        }
    }

    cout << result << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
