/*
RMQ (range minimum query)
usage: 
vector<int> v;
RMQ st(v, [&](int a,int b){
	return max(a,b);
});
reference: https://github.com/kth-competitive-programming/kactl/blob/main/content/data-structures/RMQ.h
*/
template<typename T, class Func = function<T(const T&, const T&)>>
struct RMQ {
	vector<vector<T>> jmp;
    Func f;
	RMQ(const vector<T>& V, Func g = std::min<T,T>) : jmp(1, V), f(g) {
		for (int pw = 1, k = 1; pw * 2 <= size(V); pw *= 2, ++k) {
			jmp.emplace_back(size(V) - pw * 2 + 1);
			for(int j=0;j<size(jmp[k]);j++)
				jmp[k][j] = f(jmp[k - 1][j], jmp[k - 1][j + pw]);
		}
	}
	T query(int a, int b) {
		assert(a < b); // or return inf if a == b
		// __builtin_clz(1) - __builtin_clz(b - a);
		int dep = 31 - __builtin_clz(b - a);
		return f(jmp[dep][a], jmp[dep][b - (1 << dep)]);
	}
};
