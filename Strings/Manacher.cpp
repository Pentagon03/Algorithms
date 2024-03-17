/*
Mancher Algorithm: Finding all sub-palindrome-strings in O(n)
returns vector d, length of 2*n-1
extends the original string. "abc" -> "a#b#c"
each d(i) represents the length of palindrome substring, which the center is $i$
Longest palindrome of s: max(d)
number of palindrome substrings: sum((d[i]+1)/2)
reference: https://00ad-8e71-00ff-055d.tistory.com/91
*/
vector<int> manacher(string s){
    int n = s.size();
    s.resize(2 * n - 1);
    for(int i = n - 1; i; i--){
        s[2 * i] = s[i];
        s[2 * i - 1] = '#';
    }
    n = s.length();
    vector<int> d(n);
    int p = 0, v = 0;
    for(int i = 1; i < n; i++){
        if(i <= v)d[i] = min(d[2 * p - i], v - i);
        while(i - d[i] - 1 >= 0 && i + d[i] + 1 < n && s[i - d[i] - 1] == s[i + d[i] + 1])
            d[i]++;
        if(i + d[i] > v){
            p = i;
            v = i + d[i];
        }
    }
    for(int i=0; i<n; i++) 
        d[i] +=(i % 2 == d[i] % 2);
    return d;
}
