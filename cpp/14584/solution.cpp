#include <iostream>
#include <vector>
#include <string>
#define ll long long
#define endl "\n"

using namespace std;

string crpyto_string;
vector<string> dictionary_words;
int N;

void input() {

    cin >> crpyto_string >> N;

    for(int i=0; i<N; i++) {
        string word;
        cin >> word;
        dictionary_words.push_back(word);
    }
}

string add_integer_to_string(string target, int value) {

    for(int i=0; i<target.length(); i++) {

        int ascii_code = target[i];

        ascii_code += value;

        if(ascii_code > 122)
            ascii_code = (ascii_code - 123) + 97;

        target[i] = ascii_code;
        
    }
    return target;
}

void solution() {
    input();

    int bias_count = 0;

    bool isFinish = false;

    while (++bias_count < 26)
    {
        string test_string = add_integer_to_string(crpyto_string, bias_count);

        int length_of_test_string = test_string.length();

        for(int i=0; i<N; i++) {
            string word = dictionary_words[i];

            int length_of_word = word.length();
            
            int word_index = 0;

            for(int j=0; j<length_of_test_string; j++) {
                char char_of_word = word[word_index];

                if(char_of_word == test_string[j]) {
                    word_index += 1;
                    
                    if(word_index == length_of_word) {
                        isFinish = true;
                        break;
                    }

                } else {
                    word_index = 0;
                }

            }

            if(isFinish) 
                break;

        }

        if(isFinish) 
            break;
    }

    string original_string = add_integer_to_string(crpyto_string, bias_count);

    cout << original_string << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // solution();

    char a = 128;

    int b = a;

    cout << a << " " << b << endl;

    return 0;
}
