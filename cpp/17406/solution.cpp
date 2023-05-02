#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define pos pair<int, int>

using namespace std;
int n, m, k;
vector< pair<pos, int> > con;
int matrix[51][51];
bool visit_k[6];

void rollin(pair<pos, int> data, int **mat) {
    int center_x = data.first.first;
    int center_y = data.first.second;
    int value = data.second;
    int gap_x = center_x - value;
    int gap_y = center_y - value;
    int d_x[] = {0, 1, 0, -1};
    int d_y[] = {1, 0, -1, 0};
    int size = 2 * value + 1;
    int **tempMetrix = new int *[size];
    for (int i = 0; i < size; i++) {
        tempMetrix[i] = new int[size];
        memset(tempMetrix[i], 0, sizeof(int) * size);
    }
    tempMetrix[value][value] = mat[center_x][center_y];

    int d = 0;
    for (int i = 1; i <= value; i++) {
        int x = center_x - i;
        int y = center_y - i;
        d = 0;
        while (!tempMetrix[value - i][value - i]) {
            int now_value = mat[x][y];
            int next_x = x + d_x[d];
            int next_y = y + d_y[d];
            int next_d = (d + 1) % 4;
            if (next_x < center_x - i || next_x > center_x + i || next_y < center_y - i || next_y > center_y + i) {
                next_x = x + d_x[next_d];
                next_y = y + d_y[next_d];
                d = next_d;
            }
            tempMetrix[next_x - gap_x][next_y - gap_y] = mat[x][y];
            x = next_x;
            y = next_y;
        }
    }

    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            mat[i+gap_x][j+gap_y] = tempMetrix[i][j];

    for(int i=0; i<size; i++)
        delete[] tempMetrix[i];
}


int makeList(vector<int> order) {
    if(order.size() == k) {
        int **temp;
        temp = new int*[51];
        for(int i=0; i<51; i++)
            temp[i] = new int[51];

        for(int i=1; i<=n; i++)
            for(int j=1; j<=m; j++)
                temp[i][j] = matrix[i][j];

        for(int i=0; i<k; i++)
            rollin(con[order[i]], temp);

        int result = 5000;
        for(int i=1; i<=n; i++) {
            int sum = 0;
            for(int j=1; j<=m; j++)
                sum += temp[i][j];
            result = min(result, sum);
        }
        for(int i=0; i<51; i++)
            delete []temp[i];
        return result;
    }
    int result = 5000;
    for(int i=0; i<k; i++) {
        if(!visit_k[i]) {
            visit_k[i] = true;
            order.push_back(i);
            result = min(result, makeList(order));
            order.pop_back();
            visit_k[i] = false;
        }
    }
    return result;
}



void solution() {
    cin >> n >> m >> k;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            cin >> matrix[i][j];

    for(int i=0; i<k; i++)
        visit_k[i] = false;
    for(int i=0; i<k; i++) {
        pair<pos, int> temp;
        // r, c
        cin >> temp.first.first >> temp.first.second;
        // s
        cin >> temp.second;
        con.push_back(temp);
    }
    vector<int> order;
    cout << makeList(order) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}