/**
 * Title: "Min" Persistent Leftist Heap
 * Repository: https://github.com/Pentagon03/Algorithms/blob/master/Data%20Structure/persistent_leftist_heap.cpp
 * Concept: https://en.wikipedia.org/wiki/Leftist_tree
 * Code Reference: nor( https://judge.yosupo.jp/submission/87297 )
 */
template <typename Key, typename Value>
struct PersistentLeftistHeap {
    using self_t = PersistentLeftistHeap<Key, Value>;
    int node_rank;
    Key key;
    Value value;
    self_t *left, *right;
    PersistentLeftistHeap(int rank_, Key key_, Value value_, self_t* left_,
                self_t* right_)
            : node_rank{rank_}, key{key_}, value{value_}, left{left_}, right{right_} {}
    // contains PersistentLeftistheap itself for each node. We use deque for non-reallocation such as vector. pointers don't get invalidated.
    inline static thread_local std::deque<PersistentLeftistHeap> alloc;
    friend self_t* heap_insert(PersistentLeftistHeap* a, const Key &k, const Value &v) {
        if (not a or not (a->key < k)) { // Important: k == a.key case should be considerd. if not, k will be repeatively inserted through the whole heap.
            alloc.emplace_back(1, k, v, a, nullptr);
            return &alloc.back();
        }
        auto l = a->left, r = heap_insert(a->right, k, v);
        // Guarantee that l->rank >= r->rank
        if (not l or l->node_rank < r->node_rank)
            std::swap(l, r);
        alloc.emplace_back(r ? r->node_rank + 1 : 0, a->key, a->value, l, r);
        return &alloc.back();
    }
};