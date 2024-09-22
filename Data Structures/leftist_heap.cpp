/**
 * Title: "Min" Leftist Heap
 * Reference: nor( https://judge.yosupo.jp/submission/87297 )
 */
template <typename Key, typename Value>
struct LeftistHeap {
    using self_t = LeftistHeap<Key, Value>;
    int node_rank;
    Key key;
    Value value;
    self_t *left, *right;
    LeftistHeap(int rank_, Key key_, Value value_, self_t* left_,
                self_t* right_)
            : node_rank{rank_}, key{key_}, value{value_}, left{left_}, right{right_} {}
    friend self_t* heap_insert(LeftistHeap* a, const Key k, const Value v, std::deque<LeftistHeap>& alloc) {
        if (not a or k <= a->key) { // Important: k < a->key will lead to Low Efficiency of Leftist Heap
            alloc.emplace_back(1, k, v, a, nullptr);
            return &alloc.back();
        }
        auto l = a->left, r = heap_insert(a->right, k, v, alloc);
        // Gurantee => l valid and l->rank >= r->rank
        if (not l or l->node_rank < r->node_rank)
            std::swap(l, r);
        alloc.emplace_back(r ? r->node_rank + 1 : 0, a->key, a->value, l, r);
        return &alloc.back();
    }
};