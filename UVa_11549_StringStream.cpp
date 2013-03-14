#include<set>
#include<iostream>
#include<sstream>
using namespace std;

int next(int n, int k) {
    stringstream ss;
    ss << (long long)k*k;
    string s = ss.str();
    if(s.length() > n) s = s.substr(0, n);
    int ans = 0;
    stringstream ss2(s);
    ss2 >> ans;
    return ans;
}

int main() {
    int T;
    cin >> T;
    while(T --) {
        int n, k, ans = 0;
        cin >> n >> k;
        set<int> s;
        while(!s.count(k)) {
            s.insert(k);
            ans = max(ans, k);
            k = next(n, k);
        }
        cout << ans << endl;
    }
}
