using matrix = vector<vector<int>>;
matrix fail = {{-1}};
const int MOD = 1e9+7;
template<typename T>
void init(T&A,int r,int c){
	A.resize(r);
	for(int i=0;i<r;i++) A[i].resize(c);
}
template<typename T>
T operator*(T A,T B){
	int r1=A.size(),c1=A[0].size(),r2=B.size(),c2=B[0].size();
	if(c1!=r2) return fail;
	T C; init(C,r1,c2);
	for(int i=0;i<r1;i++) C[i].resize(c2);
	for(int i=0;i<r1;i++)
		for(int k=0;k<c1;k++){
			const ll tmp = A[i][k];
			for(int j=0;j<c2;j++){
				C[i][j] += tmp*B[k][j]%MOD;
				C[i][j] %= MOD;
			}
		}
	return C;
}

template<typename T1,typename T2>
T1 operator^(T1 A,T2 x){
	if(x==0) return fail;
	T1 ans = A; --x;
	while(x>0){
		if(x&1)
			ans = ans * A;
		x>>=1;
		A = A*A;
	}
	return ans;
}
