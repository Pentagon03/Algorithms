int lo = $1, hi = $2, mid;
// chk(lo) = true, chk(hi) = false
auto chk = [&](auto x)->bool{
    $0
};
while(lo + 1 < hi) chk(mid = midpoint(lo, hi)) ? lo = mid, hi = mid;