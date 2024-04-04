/*
FFT
reference: https://blog.myungwoo.kr/54
*/
namespace FFT{
    using ld = long double;
    using _base = complex<ld>;
    const ld PI = acos(ld(-1));
    void fft(vector <_base> &a, bool invert){
        int n = size(a);
        for (int i=1,j=0;i<n;i++){
            int bit = n >> 1;
            for (;j>=bit;bit>>=1) j -= bit;
            j += bit;
            if (i < j) swap(a[i],a[j]);
        }
        for (int len=2;len<=n;len<<=1){
            ld ang = 2*PI/len*(invert?-1:1);
            _base wlen(cos(ang),sin(ang));
            for (int i=0;i<n;i+=len){
                _base w(1);
                for (int j=0;j<len/2;j++){
                    _base u = a[i+j], v = a[i+j+len/2]*w;
                    a[i+j] = u+v;
                    a[i+j+len/2] = u-v;
                    w *= wlen;
                }
            }
        }
        // accurate version, but slower
        // we precompute w array with cos&sin, and use it
        // the original version multiplies w reapeatively
        /*
        for (int len=2;len<=n;len<<=1){
            vector<_base> w(len/2);
            for(int i=0;i<len/2;i++){
                RN ang = 2*PI*i/len*(invert?-1:1);
                w[i] = _base(cos(ang),sin(ang));
            }
            for (int i=0;i<n;i+=len){
                for (int j=0;j<len/2;j++){
                    _base u = a[i+j], v = a[i+j+len/2]*w[j];
                    a[i+j] = u+v;
                    a[i+j+len/2] = u-v;
                }
            }
        }
        */
        if (invert){
            for (int i=0;i<n;i++) a[i] /= n;
        }
    }
    template<typename T=ll>
    vector<T> convolution(const vector<T>&a, vector<T>&b){
        vector<_base> fa(begin(a),end(a)), fb(begin(b),end(b));
        // mxsize = sz(a)+sz(b)-1
        int n = 1;
        while(n<size(fa)+size(fb)-1) n<<=1;
        fa.resize(n); fb.resize(n);
        fft(fa,false); fft(fb,false);
        for (int i=0;i<n;i++) fa[i] *= fb[i];
        fft(fa,true);
        vector<T> res(n);
        int SZ = 0;
        for (int i=0;i<n;i++) {
            res[i] = round(fa[i].real());
            if(res[i]!=0) SZ=i+1;
        }
        //res.resize(SZ); // Use this for size opt. min(SZ,N) can be an alternative
        return res;
    }
}
