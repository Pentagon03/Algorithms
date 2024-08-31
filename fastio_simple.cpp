constexpr int SZ = 1 << 18;
struct IN{
    char buf[SZ + 1], *p = buf;
    inline char read(){
        if(*p == 0){
            buf[fread(buf, 1, SZ, stdin)] = 0;
            p = buf;
        }
        return *p++;
    }
    template<typename T>
    inline void scan(T &x){
        char c; do c = read(); while(isblank(c));
        T ans = 0; bool sign = true;
        if(c == '-') sign = false, c = read();
        while(isdigit(c)) ans = ans * 10 + c - '0', c = read();
        x = sign?ans:-ans;
    }
}_in;
template<typename T> IN& operator >> (IN &in, T&x){in.scan(x); return in;}
#define cin _in

struct OUT{
    char buf[SZ + 1], *p = buf, tmp[42];
    inline void flush(){
        fwrite(buf, 1, p - buf, stdout); p = buf;
    }
    inline void print(char c){
        if(p == buf + SZ) flush();
        *p++ = c;
    }
    template<typename T>
    inline void print(T x){
        if(x < 0) print('-');
        int cnt = 0;
        do tmp[cnt++] = x % 10 + '0', x /= 10; while(x > 0);
        for(int i=cnt-1;i>=0;i--) print(tmp[i]);
    }
    ~OUT(){flush();}
}_out;
template<typename T> OUT& operator << (OUT &out, T x){out.print(x); return out;}
#define cout _out
