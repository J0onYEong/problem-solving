#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
#define endl "\n"

using namespace std;

int N;

vector<int> liquid;

// struct Pair {
//     int index1, index2;
// };

// bool cmp(const Pair& lhs, const Pair& rhs) {

//     return liquid[lhs.index1]+liquid[lhs.index2] < liquid[rhs.index1]+liquid[rhs.index2];
// }

// vector<Pair> comb;

void input() {

    cin >> N;

    liquid = vector<int>(N, 0);

    for(int i=0; i<N; i++) {

        cin >> liquid[i];
    }
}

void solution() {
    input();

    sort(liquid.begin(), liquid.end());

    ll result = 3000000001;
    vector<int> result_index;

    for(int i=0; i<N-2; i++) {

        int left = i+1;
        int right = N-1;

        while(left < right) {

            ll temp_result = 0;

            temp_result = liquid[i] + liquid[left];
            temp_result += liquid[right];

            if(abs(temp_result) < result) {

                result = abs(temp_result);
                result_index = {i, left, right};

                if(temp_result == 0) { break; }
            }

            if(temp_result > 0) {
                right--;
            } else if(temp_result < 0) {
                left++;
            }
        }

        if(result == 0) { break; }
    }

    for(auto index : result_index) { cout << liquid[index] << " "; }
    cout << endl;
}


// 두개의 조합을 정한뒤 바이너리서치 -> 시간초과
// void solution() {
//     input();

//     sort(liquid.begin(), liquid.end());

//     for(int i=0; i<N; i++) {

//         for(int j=i+1; j<N; j++) {

//             comb.push_back({i, j});
//         }
//     }

//     // sort(comb.begin(), comb.end(), cmp);

//     ll result = 3000000001;
//     vector<int> result_index;

//     for(auto c : comb) {        

//         int left = c.index2+1;
//         int right = N-1;
        
//         while(left <= right) {

//             int middle = (left+right) / 2;

//             ll temp = liquid[c.index1] + liquid[c.index2] + liquid[middle];

//             if(abs(temp) < result) {

//                 if(middle != c.index1 && middle != c.index2) {

//                     result = abs(temp);
//                     result_index = {c.index1, c.index2, middle};

//                     if(temp == 0) { break; }
//                 }
//             }

//             if(temp > 0) {

//                 right = middle-1;

//             } else if(temp < 0) {

//                 left = middle+1;
//             }
//         }
//     }

    // vector<int> result_member;

    // for(int index : result_index) 
    //     result_member.push_back(liquid[index]);

    // sort(result_member.begin(), result_member.end());

    // for(auto m : result_member) { cout << m << " "; }
    // cout << endl;
// }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
