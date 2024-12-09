// 브루트포스
#include<bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    srand(time(NULL));
    while(n--){
        int a, b; cin >> a >> b;
        if(rand()%4 == 0) a--;
        cout << a + b << '\n';
    }
}