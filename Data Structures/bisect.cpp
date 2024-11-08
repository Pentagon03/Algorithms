auto chk = [&](auto x)->bool{

};
int lo = -1, hi = 1e9 + 1, mid;
// assert(chk(lo) and not chk(hi));
for(lo + 1 < hi) chk(mid = lo + hi >> 1) ? lo = mid, hi = mid;