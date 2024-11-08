#include<bits/stdc++.h>
using namespace std;

// Generator for A+B
int seed;
int rd(int l, int r){
    static mt19937_64 gen(seed);
    return uniform_int_distribution<int>(l,r)(gen);
}
int main(int argc, char* argv[]){
    if(argc >= 2) seed = stoi(string(argv[1]));
    else seed = time(NULL);

    int n = rd(1, 10); printf("%d\n", n);
    for(int i=0;i<n;i++){
        int a = rd(1, 10); int b = rd(1, 10);
        printf("%d %d\n", a, b);
    }
}