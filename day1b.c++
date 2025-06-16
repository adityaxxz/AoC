#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> arr;
    map<int, int> mpp;

    int num;
    while (cin >> num) {
        arr.push_back(num);
        cin >> num;
        mpp[num]++;
    }
    
    int tot=0;
    for(int i: arr) {
        tot += i * mpp[i];
    }

    cout << tot << endl;
}