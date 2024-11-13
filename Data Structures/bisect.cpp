int lo = -1, hi = 1e9 + 1, mid;
// chk(lo) = true, chk(hi) = false
auto chk = [&](auto x)->bool{
    
};
while(lo + 1 < hi) chk(mid = midpoint(lo, hi)) ? lo = mid, hi = mid;