/**
 * FASTIO
 * https://github.com/Pentagon03/Algorithms/blob/master/Etc/fastio.cpp
 * Just use as if we use cin, cout. + u dont have to get rid of cin.tie(0)->sync_with_stdio(0);
 * Or manually. ex) int a=3; string b = "hello"; _in.scan(a,b); int z = _in.geti();
 * Special function: vector, pair input/output => vector<int> v(3); cin>>v; // Works!
 * Default floating point length is 6
 */
#define FASTIO 1
#if FASTIO
constexpr int SIZ = 1<<20;
class _IN{
    private:
        char buf[SIZ+1],*p=buf;
        int __END_FLAG__{}, __GETLINE_FLAG__{};
    public:
        explicit operator bool(){return !__END_FLAG__;}
        inline bool isEnd(char c){ return c == '\0';}
        inline bool isBlank(char c){return c=='\n'||c==' '||c=='\t'||c=='\r';}
        inline char read(){
            if(__END_FLAG__) return '\0';
            if(isEnd(*p)) {
                buf[fread(buf,sizeof(char),SIZ,stdin)] = 0; 
                p = buf;
                if(isEnd(*p)){
                    return '\0';
                }
            };
            return *p++;
        }
        inline void scan(char&c){
            do c=read(); while(isBlank(c));
            if(isEnd(c)) __END_FLAG__ = true;
        }
        inline void scan(string&s){
            s.clear(); char c; scan(c);
            while(!isBlank(c) && !isEnd(c)) s.push_back(c), c=read();
        }
        inline void scan(float&f){string t; scan(t); f=stof(t);}
        inline void scan(double&f){string t; scan(t); f=stod(t);}
        inline void scan(long double&f){string t; scan(t); f=stold(t);}
        template<typename T=int> inline T geti(){
            char c; scan(c);
            T res=0; bool f=1;
            if(c=='-') f=0, c=read();
            while(c>='0'&& c<='9') res=res*10+(c-'0'), c=read();
            return f?res:-res;
        }
        inline void getline(string&s){
            s.clear(); char c = read();
            for(;c!='\n' && !isEnd(c); c = read()) s.push_back(c);
            if(__GETLINE_FLAG__) __END_FLAG__ = true;
            if(isEnd(c)) __GETLINE_FLAG__ =  true;
        }
        template<typename T1,typename T2> inline void scan(pair<T1,T2>&p){scan(p.first);scan(p.second);}
        template<typename T> inline void scan(T&n){ n = geti<T>(); }
        template<typename T> inline void scan(vector<T>&v){for(auto&k:v) scan(k);}
        template<typename T, typename... Args> inline void scan(T&n, Args&...args){
            scan(n); scan(args...);
        }
        struct tmp{void sync_with_stdio(int _){}}_t;
        tmp* tie(int _){return &_t;}
} _in;
class _OUT{
    private:
    char buf[SIZ+1],*p=buf, tmp[21];
    public:
        explicit operator bool(){return true;}
        inline void flush(){fwrite(buf,1,p-buf,stdout); p=buf;}
        inline void mark(const char c){{if(p==buf+SIZ) flush();} *p++=c; }
        inline void mark(const char*s){for(int i=0;s[i];i++) mark(s[i]); }
        inline void mark(const string&s){for(char c:s) mark(c);}
        inline void mark(const float f){mark(to_string(f));}
        inline void mark(const double f){mark(to_string(f));}
        inline void mark(const long double f){mark(to_string(f));}
        template<typename T> inline void mark(const vector<T>&v){for(auto k:v) mark(k), mark(' ');}
        template<typename T1,typename T2> inline void mark(const pair<T1,T2>&p){mark(p.first); mark(' '); mark(p.second);}
        template<typename T> inline void mark(T ans){
            if(ans<0) mark('-'),ans*=-1;
            int cnt=0;
            do tmp[cnt++]=(ans%10)+'0', ans/=10; while(ans>0);
            for(;cnt--;) mark(tmp[cnt]);
        }
        ~_OUT(){flush();}
} _out;
template<typename T> _IN& operator>> (_IN&in, T&i){in.scan(i); return in; }
template<typename T> _OUT& operator<< (_OUT&out, T i){out.mark(i); return out; }
#define cin _in
#define cout _out

#else
template<typename T1,typename T2> istream& operator>> (istream&in, pair<T1,T2>&p){ in>>p.first>>p.second; return in; }
template<typename T> istream& operator>> (istream&in, vector<T>&v){for(auto&k:v) in>>k; return in; }
template<typename T1,typename T2> ostream& operator<< (ostream&out, pair<T1,T2>&p){out<<p.first<<' '<<p.second; return out; }
template<typename T> ostream& operator<< (ostream&out, vector<T> v){for(auto k:v) out<<k<<' '; return out; }

#endif
// END FASTIO
