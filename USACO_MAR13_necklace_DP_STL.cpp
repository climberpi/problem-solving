#include<iostream>
#include<fstream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
#define REP(i, n) for(int i = 0; i < (n); i++)

int main() {
    //ifstream in;
    //ofstream out;
    //in.open("necklace.in");
    //out.open("necklace.out");

    string text, pattern;
    cin >> text >> pattern;

    int n = text.size(), m = pattern.size();
    REP(i, n) text[i] -= 'a';
    REP(i, m) pattern[i] -= 'a';

    vector<vector<int> > next(m, vector<int>(26, 0));

    REP(i, m) if(i) {
        int prev = next[i-1][pattern[i-1]];
        next[i-1][pattern[i-1]] = i;
        printf("(%d, %d)\n", i, prev);
        REP(j, 26) next[i][j] = next[prev][j];
    }
    next[m-1][pattern[m-1]] = m;
    REP(i, m) REP(j, 26) printf("next[%d][%c] = %d\n", i, j+'a', next[i][j]);

    vector<int> max_taken(m, -n-1);
    max_taken[0] = 0;
    REP(i, n) {
        vector<int> next_taken = max_taken;
        REP(j, m) {
            int cur = next[j][text[i]];
            if(cur < m) next_taken[cur] = max(next_taken[cur], max_taken[j] + 1);
        }
        max_taken = next_taken;
    }

    int result = 0;
    REP(i, m) result = max(result, max_taken[i]);

    cout << n - result << endl;

    //in.close();
    //out.close();
}
