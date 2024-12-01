// SOS DP

// F[mask] = sum of A[i] where i is subset of mask
// 1. Naive, O(3^N)
F[mask] = A[0];
for(int i = mask; i > 0; i = i-1 & mask)
	F[mask] += A[i];

// 2. SOS DP, O(N 2^N).  S(i, mask) as set of subsets such that it differ for the first $i$ bits. (0-based)
for(int i=0;i<(1<<N);i++) F[i] = A[i];
for(int i=0;i<N;i++) for(int mask=0;mask<(1<<N);mask++)
	if(mask & (1<<i))
		F[mask] += F[mask ^ (1<<i)]  

// 3. Next Lexicographical number with same bit count
int mxb = 30, mx = (1<<mxb) - 1; // max bit count
int b; // b개의 비트를 가지는 수들을 x부터 사전순으로 순회
// 혹은 x = mask로 시작
for(int x = (1<<b)-1; x <= mx; c = x&-x, r = x+c, x = ( (((rˆx) >> 2)/c) | r) ){
  // do smth with x
}