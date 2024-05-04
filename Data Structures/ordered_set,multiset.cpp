/*
ordered set and ordered multiset inheritted by gnu policy-based-structures
kth_element(idx): get iterator of idx-th element. O(log |size|) => ex) {0,1,3,6,7}, auto it = kth_element(3); cout<< (*it); // prints 6
index(value): return index of lower bound of value. O(log |size|) => int idx = index(5); // lower bound is 6, so idx = 3;
reference: https://codeforces.com/blog/entry/11080
source: me
code help(class inherittence): frozenca (https://github.com/frozenca)
*/

// ORDERED_SET START
#include "ext/pb_ds/assoc_container.hpp"
using namespace __gnu_pbds;
template <typename Typename = int, class Parent = tree<Typename, null_type, less<Typename>, rb_tree_tag,tree_order_statistics_node_update>>
struct ordered_set : Parent{
    using iterator = typename Parent::iterator;
    // this returns the element of idx-th index in O(log n)
    iterator kth_element(int idx){
        assert(0 <= idx && idx < Parent::size());
        return Parent::find_by_order(idx);
    }
    // this returns the index of lower bound of val in O(log n)
    int index(Typename val){
        assert(Parent::size() > 0);
        return Parent::order_of_key(val);
    }
};
// ORDERED_SET END

// ORDERED_MULTISET START
#include "ext/pb_ds/assoc_container.hpp"
using namespace __gnu_pbds;

template <typename Typename = int, class Parent = tree<Typename, null_type, less_equal<Typename>, rb_tree_tag,tree_order_statistics_node_update>>
struct ordered_multiset : Parent{
    /*
        for multiset, functions of lower_bound and upper_bound swap.
        see the declaration
        lower_bound: smallest idx that "a[idx] '<=' val" is false; thus val < a[idx]
        upper_bound: smallest idx that "val '<=' a[i]" is true; thus val <= a[idx]
    */
    using iterator = typename Parent::iterator;
    iterator lower_bound(Typename val){return Parent::upper_bound(val);}
    iterator upper_bound(Typename val){return Parent::lower_bound(val);}
    void erase(iterator it){Parent::erase(it);}
    bool erase(Typename val){
        auto it = Parent::lower_bound(val);
        if(it != Parent::end() && *it == val){
            Parent::erase(it); return true;
        }
        return false;
    }
    // this returns the element of idx-th index in O(log n)
    iterator kth_element(int idx){
        assert(0 <= idx && idx < Parent::size());
        return Parent::find_by_order(idx);
    }
    // this returns the index of lower bound of val in O(log n)
    int index(Typename val){
        assert(Parent::size() > 0);
        return Parent::order_of_key(val);
    }
};
// ORDERED_MULTISET END
