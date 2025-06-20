#include <bits/stdc++.h>
using namespace std;

int main(void) {
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

        int n = arr.size();
        bool isvalid = true, asc = true, dsc = true;

        for (int i = 0; i<n-1; i++) {
            int diff = arr[i+1] - arr[i];

            if (diff > 0) dsc = false;  //alwsys increasing
            if (diff < 0) asc = false;  //always decreasing

            if (abs(diff) < 1 || abs(diff) > 3) {
                isvalid = false;
            }
        }

        if (isvalid && (asc || dsc)) {
            tot++;
        }
    }

    cout << tot << endl;
}
