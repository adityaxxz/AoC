#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    map<ll, ll> mpp;
    ll num;
    while (cin >> num) {
        mpp[num]++;
    }
    
    for (int i =0; i<75; i++) { 
        map<ll, ll> vec;
        for(auto pp: mpp){
            ll num = pp.first;
            ll cnt = pp.second;
            
            if (num == 0) {
                vec[1] += cnt;
            }
            else if (to_string(num).size() % 2 == 0) {
                string s = to_string(num);
                int mid = s.size() / 2;
                vec[stoll(s.substr(0, mid))] += cnt;
                vec[stoll(s.substr(mid))] += cnt;

            }
            else{ 
                vec[num * 2024] += cnt;
            }
        }
        mpp=vec;
    }

    ll tot = 0;
    for (auto pp: mpp){
        tot += pp.second;
    }

    cout << tot << endl;

    return 0;
}