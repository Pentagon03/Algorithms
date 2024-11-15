template<typename T>
struct BIT_2D{
	int n,m;
	vector<vector<T>> v;
	BIT_2D(int a=0,int b=0){
		n=a; m=b;
		v.assign(n+1,vector<T>(m+1));
	}
    void upd(int x,int y,T val){
		for(int i=x;i<=n;i+=i&-i)for(int j=y;j<=m;j+=j&-j)v[i][j]+=val;
	}
    // (1,1) to (x,y)
	T qry(int x,int y) const{
		T sum=0;
		for(int i=x;i>0;i-=i&-i)for(int j=y;j>0;j-=j&-j)sum+=v[i][j];
		return sum;
	}
    // (a,b) to (c,d)
    T qry(int a, int b, int c, int d){
        if(a > c or b > d) return 0;
        return qry(c, d) - qry(c, b-1) - qry(a-1, d) + qry(a-1, b-1);
    }
};