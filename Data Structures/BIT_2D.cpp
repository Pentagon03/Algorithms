struct BIT_2D{
	int n,m;
	vector<vector<int>> v;
	BIT_2D(int a=0,int b=0){
		n=a; m=b;
		v.resize(n+1,vector<int>(m+1));
	}
    void upd(int x,int y,int val){
		for(int i=x;i<=n;i+=i&-i)for(int j=y;j<=m;j+=j&-j)v[i][j]+=val;
	}
    // (1,1) to (x,y)
	int qry(int x,int y) const{
		int sum=0;
		for(int i=x;i>0;i-=i&-i)for(int j=y;j>0;j-=j&-j)sum+=v[i][j];
		return sum;
	}
    // (a,b) to (c, d)
    int qry(int a, int b, int c, int d){
        if(a > c or b > d) return 0;
        return qry(c, d) - qry(c, b-1) - qry(a-1, d) + qry(a-1, b-1);
    }
};