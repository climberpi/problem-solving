#include<cstdio>
#include<vector>
using namespace std;

template<class T>
bool LexicographicallySmaller(vector<T> a, vector<T> b) {
    int n = a.size(), m = b.size(), i;
    for(int i = 0; i < n && i < m; i++)
        if(a[i] < b[i]) return 1;
        else if(b[i] < a[i]) return 0;
    return (i == n && n < m);
}

int main(){
    return 0;
}
