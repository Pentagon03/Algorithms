constexpr int ISZ = 1 << 19, OSZ = 1 << 19;
struct IN{
    char buf[ISZ + 1], *p = buf;
    inline char read(){
        if(*p == 0){
            buf[fread(buf, sizeof(char), ISZ, stdin)] = 0;
            p = buf;
        }
        return *p++;
    }
    inline void scan(char &x){
        do x = read(); while(x == ' ' or x == '\n');
    }
    inline void scan(string &s){
        for(auto&c: s) scan(c);
    }
    template<typename T>
    inline void scan(T &x){
        char c; scan(c);
        T ans = 0; bool sign = true;
        if(c == '-') sign = false, c = read();
        while(isdigit(c)) ans = ans * 10 + c - '0', c = read();
        x = sign?ans:-ans;
    }
    IN* tie(int _){return this;}
    void sync_with_stdio(int _){}
    void exceptions(bool _){}
}_in;
template<typename T> IN& operator >> (IN &in, T&x){in.scan(x); return in;}
#define cin _in

struct OUT{
    char buf[OSZ + 1], *p = buf, tmp[42]{};
    inline void flush(){
        fwrite(buf, sizeof(char), p - buf, stdout); p = buf;
    }
    inline void print(char c){
        if(p == buf + OSZ) flush();
        *p++ = c;
    }
    inline void print(const string& s){
        for(auto c: s) print(c);
    }
    template<typename T>
    inline void print(T x){
        if(x < 0) print('-'), x *= -1;
        int cnt = 0;
        do tmp[cnt++] = x % 10 + '0', x /= 10; while(x > 0);
        for(int i=cnt-1;i>=0;i--) print(tmp[i]);
    }
    ~OUT(){flush();}
}_out;
template<typename T> OUT& operator << (OUT &out, T x){out.print(x); return out;}
#define cout _out