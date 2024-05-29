/*Hasher that uses simple dot product and unsigned long long
reference: Koosaga(https://github.com/koosaga/olympiad/blob/master/POI/poi08_poc.cpp)
*/
using hash_t = unsigned long long;
struct Hasher_Dot{
    int sz{};
    vector<hash_t> magic{};
    mt19937_64 gen;
    Hasher_Dot(int n = 0):gen(chrono::steady_clock::now().time_since_epoch().count()){
        extend(n);
    }
    void extend(int n){
        magic.resize(n);
        for(int i=sz;i<n;i++)
            magic[i] = uniform_int_distribution<hash_t>(0ull,~0ull)(gen);
        sz = n;
    }
    hash_t hash(const string& s){
        int n = s.size();
        if(n > sz) extend(n);
        hash_t h = 0;
        for(int i=0;i<n;i++)
            h += magic[i] * s[i];
        return h;
    }
};