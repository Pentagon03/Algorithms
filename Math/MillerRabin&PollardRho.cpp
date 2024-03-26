namespace PollardRho{
  using ull = unsigned long long;
  constexpr int SZ = 100000; 
  bitset<SZ> isp; vector<int> prlist;
  bool Sieve(){
      isp.set(); isp[0]=isp[1]=false;
      for(int i=2;i<SZ;i++){
          if(isp[i]){
              prlist.push_back(i);
              if(1LL*i*i>=SZ) continue;
              for(int j=i*i;j<SZ;j+=i) isp[j] = false;
          }
      }
      return true;
  }
  ull MulMod(ull a,ull b,ull c){return (__uint128_t)a*b%c;}
  ull PowMod(ull a,ull b,ull c){
      ull ans = 1;
      while(b>0){
          if(b&1) ans = MulMod(ans,a,c);
          a = MulMod(a,a,c);
          b >>= 1;
      }
      return ans;
  }
  const int p32[]={2, 7, 61}, p64[]={2, 325, 9375, 28178, 450775, 9780504, 1795265022};
  bool MillerRabin(ull n, ull a){ // is n prime based on a
      if(a % n == 0) return true; // can't check
      int cnt = __builtin_ctzll(n-1);
      ull p = PowMod(a, n-1>>cnt, n);
      if(p==1 || p==n-1) return true;
      while(cnt--) if((p=MulMod(p,p,n))==n-1) return true;
      return false;
  }
  bool IsPrime(ull n){
      static bool start = Sieve();
      if(n<SZ) return isp[n];
      // check some base primes
      for(int i=0;i<5;i++) if(n%prlist[i]==0) return false;
      for(int p:p64) if(!MillerRabin(n,p)) return false;
      return true;
  }
  template<typename T> T get_random(T l, T r){
      static random_device rd;
      return uniform_int_distribution<T>(l,r)(rd);
  }
  ull Rho(ull n){
      while(true){
          ull x_k = get_random<ull>(2,n-1), x_2k = x_k, c = get_random<ull>(1,n-1);
          auto f = [&](ull x){
              return (MulMod(x,x,n)+c)%n;
          };
          while(true){
              x_k = f(x_k); x_2k = f(f(x_2k));
              ull p = gcd(abs((ll)x_2k-(ll)x_k), n); if(p==1) continue;
              if(IsPrime(p)) return p;
              else{ n = p; break;}
          }
      }
  }
  vector<pair<ull,ull>> Factorize(ull n){
      vector<pair<ull,ull>> v;
      int two = __builtin_ctzll(n);
      if(two>0) v.emplace_back(2, two), n >>= two;
      if(n<=1) return v;
      while(!IsPrime(n)){
          ull p = Rho(n), cnt = 0; while(n%p==0) n/=p, cnt++;
          v.emplace_back(p, cnt); if(n==1) break;
      }
      if(n>1) v.emplace_back(n,1);
      sort(all(v)); // not required
      return v;
  }
}
