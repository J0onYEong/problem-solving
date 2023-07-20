#include <bits/stdc++.h>
#define ll long long
#define endl "\n"

using namespace std;

const int max_n = 1001;

int T; 
int N; //1~1000

int priority[max_n];

int middle_order[max_n];

//0 - left, 1-right
int tree[max_n][2]; 

void post_order(int node) {
    if(node == 0)
        return;

    post_order(tree[node][0]);
    post_order(tree[node][1]);

    cout << node << " ";
}

void recursive(int start, int end, int parent, int isLeft) {
    int rootIndex = start;
    int max_p = -1;

    if(start != end) {
        for(int i=start; i<=end; i++) {
            int number = middle_order[i];

            if(max_p < priority[number]) {
                max_p = priority[number];
                rootIndex = i;
            }
        }

        int temp_root = middle_order[rootIndex];

        if(start < rootIndex)
            recursive(start, rootIndex-1, temp_root, true);
        
        if(rootIndex < end)
            recursive(rootIndex+1, end, temp_root, false);

    }

    tree[parent][isLeft ? 0 : 1] = middle_order[rootIndex];
}


void solution() {
    cin >> T;

    for(int i=0; i<T; i++) {
        cin >> N;

        int root;
        for(int p=N; p>=1; p--) {
            //preorder
            int pre_number;
            cin >> pre_number;
            priority[pre_number]=p;

            if(p == N)
                root = pre_number;
        }

        for(int i=1; i<=N; i++) {
            //middleorder
            int middle_number;
            cin >> middle_number;
            middle_order[i] = middle_number;
        }

        memset(tree, 0, sizeof(tree));

        recursive(1, N, 0, false); 

        post_order(root);
        cout << endl;
    }
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
