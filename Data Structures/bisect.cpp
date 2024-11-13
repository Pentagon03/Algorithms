int lo = $0, hi = $1, mid;
// chk(lo) = true, chk(hi) = false
auto chk = [&](auto x)->bool{
    $2
};
while(lo + 1 < hi) chk(mid = midpoint(lo, hi)) ? lo = mid, hi = mid;