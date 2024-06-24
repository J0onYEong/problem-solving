#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
#define endl "\n"

using namespace std;

int N;

vector<int> balls;

void input() {

    cin >> N;

    for(int i=0; i<N; i++) {

        int ball;

        cin >> ball;

        balls.push_back(ball);
    }
}

// void solution() {
//     input();

//     sort(balls.begin(), balls.end());

//     int result = 1000000000;

//     for(int i=0; i<balls.size()-3; i++) {

//         for(int j=i+3; j<balls.size(); j++) {

//             int inner_i = i+1;
//             int inner_j = j-1;

//             int outer_sum = balls[i]+balls[j];

//             while(inner_i < inner_j) {

//                 int inner_sum = balls[inner_i]+balls[inner_j];

//                 result = min(result, abs(inner_sum-outer_sum));

//                 if(inner_sum > outer_sum) {

//                     inner_j--;
//                 } else {

//                     inner_i++;
//                 }
//             } 
//         }
//     }

//     cout << result << endl;
// }

struct Snowman {

    int p1, p2, sum;
};

bool cmp(Snowman lhs, Snowman rhs) {

    return lhs.sum < rhs.sum;
}

void combination_solution() {
    input();

    vector<Snowman> comb;

    for(int i=0; i<balls.size()-1; i++) {
        for(int j=i+1; j<balls.size(); j++) {

            comb.push_back({i, j, balls[i]+balls[j]});
        }
    }

    sort(comb.begin(), comb.end(), cmp);

    int result = 1000000000;

    for(int i=0; i<comb.size()-1; i++) {

        Snowman c = comb[i];

        for(int j=i+1; j<comb.size(); j++) {

            Snowman n = comb[j];

            if(c.p1 != n.p1 && c.p1 != n.p2 && c.p2 != n.p1 && c.p2 != n.p2) {

                result = min(result, n.sum - c.sum);
                
                break; 
            }   
        }
    }

    cout << result << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // solution();
    combination_solution();
    return 0;
}
