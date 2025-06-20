#include <bits/stdc++.h>
using namespace std;

int check(vector<int> arr) {
    int n = arr.size();
    bool isvalid = true, asc = true, dsc = true;

    for (int i = 0; i<n-1; i++) {
        int diff = arr[i+1] - arr[i];

        if (diff > 0) dsc = false;
        if (diff < 0) asc = false;

        if (abs(diff) < 1 || abs(diff) > 3) {
            isvalid = false;
        }
    }
    return (isvalid && (asc || dsc));
}


int main() {
    string line;
    int tot = 0;

    // process multiple lines of input
    while (getline(cin, line)) {
        stringstream ss(line);
        vector<int> arr;
        int x;
        while (ss >> x) {
            arr.push_back(x);
        }

        bool ok = false;
        auto process = [&](int i ) {
            vector<int> b = arr;
            b.erase(begin(b) + i);
            if(check(b)){
                ok = true;
            }
        };

        int n = arr.size();
        process(0);
        
        for (int i = 0; i<n-1; i++) {
            int diff = arr[i+1] - arr[i];
            if (abs(diff) < 1 || abs(diff) > 3) {
                process(i);
                process(i+1);
                break;
            }
            
            if(i+2 < n) {
                int diff2 = arr[i+2] - arr[i+1];
                if((diff > 0) != (diff2 > 0)) {
                    process(i);
                    process(i+1);
                    process(i+2);
                    break;
                }
            }
        }

        if(ok) tot++;
    }

    cout << tot << endl;
}