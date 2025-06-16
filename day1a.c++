#include <bits/stdc++.h>
using namespace std;

const int N = 1000;

int main() {
    vector<int> arr1, arr2;

    for(int i=0; i<N; i++) {
        int x, y;
        cin >> x >> y;
        arr1.push_back(x);
        arr2.push_back(y);
    }
    sort(begin(arr1), end(arr1));
    sort(begin(arr2), end(arr2));
    
    int tot=0;
    for(int i=0; i<arr1.size(); i++){
        int dist = abs(arr1[i] - arr2[i]);
        tot += dist;
    }

    printf("%d\n", tot);

    return 0;
}