#include <iostream>

using namespace std;

template <typename T>
void mergeSort(T* arr, int start, int end, bool (*compare)(T, T)) {
    if(start == end) return;

    int middle = (start + end) / 2;

    mergeSort(arr, start, middle, compare);
    mergeSort(arr, middle + 1, end, compare);

    int leftIndex = start;
    int rightIndex = middle+1;
    int size = end-start+1;
    T* tempList = new T[size];

    for(int i=0; i<size; i++) {
        if(leftIndex > middle) {
            tempList[i] = arr[rightIndex++];
            continue;
        }
        if(rightIndex > end) {
            tempList[i] = arr[leftIndex++];
            continue;
        }
        if(compare(arr[leftIndex], arr[rightIndex]))
            tempList[i] = arr[leftIndex++];
        else
            tempList[i] = arr[rightIndex++];
    }
    for(int i=0; i<size; i++)
        arr[i + start] = tempList[i];
    delete []tempList;
}

bool compare(pair<int, int> lhs, pair<int, int> rhs) {
    return lhs.first < rhs.first;
}

void solution() {
    int n;
    cin >> n;
    pair<int ,int> *list = new pair<int, int>[n];

    for(int i=0; i<n; i++)
        cin >> list[i].first >> list[i].second;

    mergeSort(list, 0, n-1, &compare);

    int min_value = 100001;
    int count = 0;

    for(int i=0; i<n; i++) {
        if(list[i].second < min_value) {
            count++;
            min_value = list[i].second;
        }
    }
    cout << count << "\n";
}


int main() {
    cin.tie(NULL);
    int t;
    cin >> t;
    for(int i=0; i<t; i++) solution();
    return 0;
}
