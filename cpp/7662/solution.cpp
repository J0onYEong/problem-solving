#include <iostream>
#include <vector>
#include <queue>
#include <string.h>

#define ll long long
#define endl "\n"
#define Queries vector<pair<char, int>>
#define Element pair<int, int> // number, order

using namespace std;

int t;

vector<Queries> testCases;

void input() {
    cin >> t;

    for(int i=0; i<t; i++) {
        int k;
        cin >> k;

        Queries queries;

        for(int j=0; j<k; j++) {

            char keyword;
            int opt;

            cin >> keyword >> opt;

            queries.push_back({keyword, opt});

        }

        testCases.push_back(queries);

    }

}


struct max_cmp {
    bool operator()(Element lhs, Element rhs) {
        return lhs.first < rhs.first;
    }
};

struct min_cmp {
    bool operator()(Element lhs, Element rhs) {
        return lhs.first > rhs.first;
    }
};


void solveTestCase(Queries queries) {

    priority_queue<Element, vector<Element>, max_cmp> max_pq;
    priority_queue<Element, vector<Element>, min_cmp> min_pq;

    int isInsertNumberExist[1000000];

    memset(isInsertNumberExist, 0, sizeof(isInsertNumberExist));

    int insert_order = 0;

    int element_count = 0;

    for(auto q : queries) {

        char opcode = q.first;
        int value = q.second;

        if(opcode == 'I') {

            max_pq.push({value, insert_order});
            min_pq.push({value, insert_order});

            isInsertNumberExist[insert_order] = 1;

            insert_order++;

            element_count+=1;

        } else {

            if(element_count > 0) {
            
                if(value == 1) {
                    while (true)
                    {
                        int order = max_pq.top().second;

                        max_pq.pop();

                        if(isInsertNumberExist[order]) {
                            isInsertNumberExist[order] = 0;
                            break;
                        }
                    }
                    
                }
                else {
                    while (true)
                    {
                        int order = min_pq.top().second;

                        min_pq.pop();

                        if(isInsertNumberExist[order]) {
                            isInsertNumberExist[order] = 0;
                            break;
                        }
                    }
                }

                element_count -= 1; 
                
                if(element_count == 0) {

                    while(!max_pq.empty()) max_pq.pop();
                    while(!min_pq.empty()) min_pq.pop();

                }

            }

        }

    }

    if(element_count == 0) {

        cout << "EMPTY" << endl;

    } else {

        while(!isInsertNumberExist[max_pq.top().second]) max_pq.pop();
        while(!isInsertNumberExist[min_pq.top().second]) min_pq.pop();

        int max_value = max_pq.top().first;
        int min_value = min_pq.top().first;
        
        cout << max_value << " " << min_value << endl;

    }

}

void solution() {
    input();

    for(auto queries : testCases) {

        solveTestCase(queries);        

    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
