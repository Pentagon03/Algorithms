// source: https://github.com/kth-competitive-programming/kactl/blob/main/content/various/IntervalContainer.h

// Interval: [L, R)
class IntervalSet : public set<pii> {
public:
	using set<pii>::set; // 생성자 상속

	set<pii>::iterator add(int L, int R) {
		if (L == R) return end();
		auto it = lower_bound({L, R}), before = it;
		// not necessary starts
		if(it != end() and it->first == L) return it;
		if(it != begin() and prev(it)->second >= R) return it;
		// not necessary ends
		while (it != end() && it->first <= R) {
			R = max(R, it->second);
			before = it = erase(it);
		}
		if (it != begin() && (--it)->second >= L) {
			L = min(L, it->first);
			R = max(R, it->second);
			erase(it);
		}
		return insert(before, {L, R});
	}

	void remove(int L, int R) {
		if (L == R) return;
		auto it = add(L, R);
		auto r2 = it->second;
		if (it->first == L) erase(it);
		else (int&)it->second = L;
		if (R != r2) emplace(R, r2);
	}
};