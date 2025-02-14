# lis.cpp

```cpp
/*
 * Function: lis
 * Description: Calculates the length of the longest increasing subsequence.
 * Parameters:
 *   - v: The input vector.
 *   - cmp: Comparator function (default: less<T>).
 * Returns: The length of the longest increasing subsequence.
 */
template<typename T = int, typename cmp = less<T>>
int lis(const vector<T> &v);

/*
 * Function: lis_recover
 * Description: Recovers one of the longest increasing subsequences.
 * Parameters:
 *   - v: The input vector.
 *   - cmp: Comparator function (default: less<T>).
 * Returns: A vector representing one of the longest increasing subsequences.
 */
template<typename T = int, typename cmp = less<T>>
vector<int> lis_recover(const vector<T> &v);
