#include <iostream>
#include <vector>
#include <string>

#define ll long long
#define endl "\n"

using namespace std;

string s, t;

void input() {
    cin >> s >> t;
}

void solution() {

    while(true) {

        s = "";
        t = "";

        input();

        if(s.empty() || t.empty()) break;

        int index_of_s = 0;
        int index_of_t = 0;

        int length_of_s = s.length();
        int length_of_t = t.length();

        while(index_of_t < length_of_t) {
            char part_of_s = s[index_of_s];
            char part_of_t = t[index_of_t];    

            if(part_of_s == part_of_t) {
                index_of_s += 1;

                if(index_of_s == length_of_s)
                    break;

            }

            index_of_t += 1;
        }

        if(index_of_s == length_of_s)
            cout << "Yes" << endl;
        else 
            cout << "No" << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
