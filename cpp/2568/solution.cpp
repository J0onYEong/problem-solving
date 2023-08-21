#include <bits/stdc++.h>
#define ll long long
#define endl "\n"

using namespace std;

const int max_n = 100000+1;
const int max_line_number = 500000+1;

int N;
//line[A] = B
int line[max_line_number];

int insert_pos[max_line_number];

vector<int> line_start;

void input() {
    cin >> N;

    for(int i=1; i<=N; i++) {
        int A, B;
        cin >> A >> B;
        line[A] = B;
        line_start.push_back(A);
    }

}

void solution() {
    input();

    sort(line_start.begin(), line_start.end());

    vector<int> lis;
    for(int i : line_start) {
        int line_pos_A = i;
        int line_pos_B = line[line_pos_A];

        if(lis.empty()) {
            lis.push_back(line_pos_B);
            continue;
        }

        int last = lis.back();
        int index;
        if(line_pos_B > last) {
            lis.push_back(line_pos_B);
            index = lis.size()-1;
        }
        if(line_pos_B < last) {
            index = lower_bound(lis.begin(), lis.end(), line_pos_B) - lis.begin();
            lis[index] = line_pos_B;
        }
        insert_pos[line_pos_A] = index;
    }

    int now_searching_pos = lis.size()-1;
    vector<int> removed_line;
    for(int i=line_start.size()-1; i>=0; i--) {
        int number = line_start[i];
        if(insert_pos[number] == now_searching_pos) {
            now_searching_pos--;
            continue;
        }
        removed_line.push_back(number);
    }

    int remove_cnt = N-lis.size();  
    cout << remove_cnt << endl;
    sort(removed_line.begin(), removed_line.end());
    for(int pos_A : removed_line)  
        cout << pos_A << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
