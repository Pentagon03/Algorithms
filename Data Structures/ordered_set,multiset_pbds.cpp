// ORDERED_SET START
#include "ext/pb_ds/assoc_container.hpp"
using namespace __gnu_pbds;

using Typename = int;
struct ordered_set : tree<Typename, null_type, less<Typename>, rb_tree_tag,tree_order_statistics_node_update>{
    // this returns the element of idx-th index in O(log n)
    iterator kth_element(int idx){
        assert(0 <= idx && idx < size());
        return find_by_order(idx);
    }
    // this returns the index of lower bound of val in O(log n)
    int index(Typename val){
        assert(size() > 0);
        return order_of_key(val);
    }
};
// ORDERED_SET END

// ORDERED_MULTISET START
#include "ext/pb_ds/assoc_container.hpp"
using namespace __gnu_pbds;
using Typename = int;
using parent_ordered_multiset = tree<Typename, null_type, less_equal<Typename>, rb_tree_tag,tree_order_statistics_node_update>;
struct ordered_multiset : parent_ordered_multiset{
    /*
        for multiset, functions of lower_bound and upper_bound swap.
        see the declaration
        lower_bound: smallest idx that "a[idx] '<=' val" is false; thus val < a[idx]
        upper_bound: smallest idx that "val '<=' a[i]" is true; thus val <= a[idx]
    */
    iterator lower_bound(Typename val){return parent_ordered_multiset::upper_bound(val);}
    iterator upper_bound(Typename val){return parent_ordered_multiset::lower_bound(val);}
    void erase(iterator it){parent_ordered_multiset::erase(it);}
    bool erase(Typename val){
        auto it = lower_bound(val);
        if(it != end() && *it == val){
            erase(it); return true;
        }
        return false;
    }
    // this returns the element of idx-th index in O(log n)
    iterator kth_element(int idx){
        assert(0 <= idx && idx < size());
        return find_by_order(idx);
    }
    // this returns the index of lower bound of val in O(log n)
    int index(Typename val){
        assert(size() > 0);
        return order_of_key(val);
    }
};
// ORDERED_MULTISET END
