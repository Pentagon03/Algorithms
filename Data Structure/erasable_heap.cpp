/** Eraseable heap
 * cmp는 bool operator()이 정의된 struct 또는 class
 * cmp 상으로 가장 큰 것이 반환됨
 */
template<class T, class cmp = less<T>>
struct heap{
    priority_queue<T, vector<T>, cmp> iq, dq;
    cmp f;
    bool eq(const T&l, const T&r){return not f(l, r) and not f(r, l);}
    void push(T x){iq.push(x);}
    void del(T x){dq.push(x);}
    void upd(){
        while(not dq.empty()){
            if(iq.empty() or f(iq.top(), dq.top())) dq.pop();
            else{
                if(eq(iq.top(), dq.top())) iq.pop(), dq.pop();
                else break;
            }
        }
    }
    bool empty(){upd(); return iq.empty();}
    T pop(){upd(); T x = iq.top(); iq.pop(); return x;}
    T top(){upd(); return iq.top();}
};