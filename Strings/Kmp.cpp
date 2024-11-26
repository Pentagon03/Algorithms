/*
getPi: get Failure function(Pi) of pattern p
kmp: get occurence of pattern p in string s
*/
vector<int> getPi(const auto&p){
    vector<int> pi(size(p));
    for(int i=1,j=0;i<size(p);i++){
        while(j > 0 && p[i] != p[j]) j = pi[j-1];
        if(p[i] == p[j]) pi[i] = ++j;
    }
    return pi;
}
vector<int> kmp(const auto&s,const auto&p){
    vector<int> pi = getPi(p);
    vector<int> ansv;
    for(int i=0,j=0;i<size(s);i++){
        while(j>0 && s[i]!=p[j]) j = pi[j-1];
        if(s[i] == p[j]) ++j;
        if(j==size(p)){
            ansv.push_back(i-size(p)+1);
            j = pi[j-1];
        }
    }
    return ansv;
}
