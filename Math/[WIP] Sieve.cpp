//Number Theory
namespace Sieve{
    template<typename T=int, typename U=int64_t>
    T fpow(T a,T b,U mod=0){
        T ans = 1;
        while(b){
            if(b&1) mod?(ans=ans*a%mod):(ans*=a);
            mod?(a=a*a%mod):(a*=a);
            b>>=1;
        }
        return ans;
    }
    bool isprime_naive(int n){
        if(n<2) return false;
        for(int i=2;i*i<=n;i++) if(n%i==0) return false;
        return true;
    }
    struct Sieve{
        int SZ;
        vector<int> p, spf, e, phi, mu, tau, sigma;
        vector<bool> isp;
        //mode 1: linear, mode 2: get other factors
        Sieve(int n=1e6){
            SZ = n+1;
            spf.resize(SZ);
            e=phi=mu=tau=sigma=spf;
            phi[1]=mu[1]=tau[1]=sigma[1]=1;
            for(int i=2;i<SZ;i++){
                if(!spf[i]){
                    p.push_back(i);
                    spf[i] = i;
                    initPrime(i);
                }
                for(auto j:p){ 
                    if(i*j>=SZ) break;
                    spf[i*j] = j;
                    if(i%j==0){
                        handleDivisibleCase(i, j);
                        break;
                    }
                    handleCoprimePCase(i, j);
                }
            }
        }
        inline bool isprime(int n){
            return n>1 && spf[n]==n;
        }
        vector<pii> factor(int n){
            vector<pii> v;
            while(n>1){
                if(!v.empty() && v.back().first == spf[n]) v.back().second++;
                else v.emplace_back(spf[n],1);
                n /= spf[n];
            }
            return v;
        }
        // [A, B)
        template<typename T>
        vector<T> primelist(T A,T B){
            assert((T)SZ*SZ >= B);
            isp.assign(B-A,true);
            for(T i:p){
                for(T j = max(2*i, (A+i-1)/i*i);j<B;j+=i){
                    isp[j-A] = false;
                }
            }
            vector<T> v;
            for(T i=A;i<B;i++){
                if(i<2) continue;
                if(isp[i-A]) v.push_back(i);
            }
            return v;
        }
    private:
        void initPrime(int i) {
            e[i] = 1;
            phi[i] = i-1;
            mu[i] = -1;
            tau[i] = 2;
            sigma[i] = i+1;
        }

        void handleDivisibleCase(int i, int j) {
            int nxt = i*j;
            e[nxt] = e[i] + 1;
            phi[nxt] = phi[i] * j;
            mu[nxt] = 0;
            tau[nxt] = tau[i] / (e[i]+1) * (e[nxt]+1);
            sigma[nxt] = sigma[i]*(j-1)/(fpow(j, e[nxt])-1)*(fpow(j, e[nxt]+1)-1)/(j-1);
        }

        void handleCoprimePCase(int i, int j) {
            int nxt = i*j;
            e[nxt] = 1;
            phi[nxt] = phi[i] * phi[j];
            mu[nxt] = mu[i] * mu[j];
            tau[nxt] = tau[i] * tau[j];
            sigma[nxt] = sigma[i] * sigma[j];
        }
    };
}
