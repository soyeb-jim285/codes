# Tutorial

[1743A - Password](../problems/A._Password.md "Educational Codeforces Round 137 (Rated for Div. 2)")

Idea: [fcspartakm](https://codeforces.com/profile/fcspartakm "Candidate Master fcspartakm")

 **Tutorial**
### [1743A - Password](../problems/A._Password.md "Educational Codeforces Round 137 (Rated for Div. 2)")

There are two possible solutions for the problem.

The first solution is basically brute force. Each password can be obtained from an integer from $0$ to $9999$. If the number is from $1000$ to $9999$, then it's already a password of length $4$. Otherwise, you have to prepend it with enough zeros so that it becomes length $4$.

Then you have to check if the password is valid. First, check if it consists of exactly two different digits: make a set of all its characters (set<char> in case of C++, for example) and check its size. Then check if the first digit of the password appears exactly twice. It would mean that the other digits appears exactly twice as well. Finally, check if neither of the found digits are forbidden.

The second solution is based on combinatorics. First, choose the two digits that will appear in the password: $C(10 - n, 2)$. Since $n$ digits are prohibited, the remaining $10 - n$ are allowed. Second, choose the positions that will be taken by the first one: $C(4, 2)$. The answer is the product of these two values.

 **Solution 1 (awoo)**
```cpp
for _ in range(int(input())):
	n = int(input())
	a = set(map(int, input().split()))
	ans = 0
	for i in range(10000):
		num = str(i)
		num = (4 - len(num)) * '0' + num
		used = set(num)
		if len(used) != 2:
			continue
		d1 = int(used.pop())
		d2 = int(used.pop())
		if (not d1 in a) and (not d2 in a) and num.count(num[0]) == 2:
			ans += 1
	print(ans)
```
 **Solution 2 (fcspartakm)**
```cpp
#include <bits/stdc++.h>

using namespace std;

int n;

inline void read() {	
    cin >> n;
    int x;
    for (int i = 0; i < n; ++i)
        cin >> x;
}

inline int fac(int n) {
    int res = 1;
    for (int i = 2; i <= n; i++) {
        res *= i;
    }
    return res;
}

inline int c(int n, int k) {
    return fac(n) / fac(k) / fac(n - k);
}

inline void solve() {
    cout << c(10 - n, 2) * c(4, 2) << endl;
}

int main () {
    int t;
    cin >> t;
    while (t--){
        read();
        solve();
    }
}
```
[1743B - Permutation Value](../problems/B._Permutation_Value.md "Educational Codeforces Round 137 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1743B - Permutation Value](../problems/B._Permutation_Value.md "Educational Codeforces Round 137 (Rated for Div. 2)")

The subsegment $[1]$, as well as the whole permutation, will always be a permutation, so the value is at least $2$. Let's try to find a way to generate a permutation of $n$ elements with value equal to $2$.

Every permutation must contain the number $1$. Let's try to construct the answer in such a way that if a subsegment contains the number $1$, then it also contains the number $n$ (if it is so, it can only be a permutation if it contains all $n$ numbers). If we begin our permutation with the numbers $1$ and $n$, we will reach our goal: the only subsegment which does not contain $n$ but contains $1$ is $[1]$, and the only subsegment which contains $n$ and also a permutation is the whole permutation itself. So, any permutation that begins with $[1, n \dots]$ can be the answer.

 **Solution (BledDest)**
```cpp
#include <bits/stdc++.h>
 
using namespace std;

void solve() 
{
    int n;
    cin >> n;
    cout << 1;
    for(int i = n; i >= 2; i--)
        cout << " " << i;
    cout << endl;
}

int main()
{
    int t;
    cin >> t;
    for(int i = 0; i < t; i++)
        solve();
}
```
[1743C - Save the Magazines](../problems/C._Save_the_Magazines.md "Educational Codeforces Round 137 (Rated for Div. 2)")

Idea: [fcspartakm](https://codeforces.com/profile/fcspartakm "Candidate Master fcspartakm")

 **Tutorial**
### [1743C - Save the Magazines](../problems/C._Save_the_Magazines.md "Educational Codeforces Round 137 (Rated for Div. 2)")

Let's process the boxes from left to right.

Consider the first box. If it has a lid, then you can just add the number of magazines in it to the answer and forget about this box. To be exact, proceed to solve the problem with the first box removed.

If it doesn't have a lid, then look at the next box. If it doesn't have a lid too, then this box can never be covered. Remove it and proceed further.

If the next box has a lid, then look at the next one. Again, if it doesn't have a lid, then these two first boxes are solved independently of everything else. You can cover exactly one of them. Choose the bigger one and remove them both.

To propagate the argument, let's derive a pattern. First, there's a box without a lid. Then some number of boxes with lids in a row. Then a box without a lid again. Among the first box and the box with lids, you can choose exactly one to not be covered. However, that can be any one of them. The best box to be left uncovered is the one with the smallest number of magazines in it.

Thus, the solution is the following. As long as the first box has a lid, keep removing the first box and adding it to the answer. Then, as long as there are boxes left, take the first box and the largest number of consecutive boxes with lids after it (that number might be zero). On that segment, find the minimum value and the sum. Add the sum minus the minimum to the answer, remove the entire segment.

The removals can be done explicitly with a queue or just a reversed vector or implicitly with maintaining a pointer to the first non-removed box.

Overall complexity: $O(n)$.

 **Solution (awoo)**
```cpp
for _ in range(int(input())):
	n = int(input())
	s = '0' + input()
	a = [0] + list(map(int, input().split()))
	ans = 0
	i = 0
	while i <= n:
		mn = a[i]
		sm = a[i]
		j = i + 1
		while j <= n and s[j] == '1':
			mn = min(mn, a[j])
			sm += a[j]
			j += 1
		ans += sm - mn
		i = j
	print(ans)
```
[1743D - Problem with Random Tests](../problems/D._Problem_with_Random_Tests.md "Educational Codeforces Round 137 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1743D - Problem with Random Tests](../problems/D._Problem_with_Random_Tests.md "Educational Codeforces Round 137 (Rated for Div. 2)")

The first observation we need is that we can choose two prefixes of $s$ as the substrings used in forming the results. This can be proved easily: suppose we chose a substring which does not contain the leftmost character of $s$; if we expand it to the left, the answer won't become worse. So, it is optimal to choose two prefixes of $s$ as the substrings.

Furthermore, one of these prefixes must be $s$ itself: if the leftmost index of 1 is $i$, the length of the answer won't exceed $n - i + 1$, but the only way to have a 1 in the $(n-i+1)$-th bit of the answer is to choose a prefix of $s$ where the $(n-i+1)$-th character (from the right) is 1; and there is only one such prefix of $s$, which is $s$ itself.

So, now we can solve the problem in $O(n^2)$ — try to combine all prefixes of $s$ with $s$ itself, and choose the one that yields the best answer. To speed this up, we need to somehow cut down on the number of prefixes of $s$ we check.

Let's look at the first block of 1's in $s$. The next character after this block is 0; since we take $s$ as one of the substring, in order to get 1 instead of 0 in the corresponding position of the answer, we need to choose a prefix which has 1 in that position. This 1 represents one of the 1's from the first block of 1's, since only one of them can shift to that position. So, we need to check only the prefixes such that, by using them, we shift some character 1 from the first block to the position of the first 0 after this block. Since the tests are random, the expected length of the first block of 1's is $O(1)$ (furthermore, even the probabiliy that its length is $20$ or bigger is about $10^{-6}$), so the expected number of prefixes we need to check is also $O(1)$. Thus, the expected runtime of our solution is $O(n)$.

 **Solution (BledDest)**
```cpp
#include<bits/stdc++.h>

using namespace std;

char buf[1000043];

string normalize(const string& v)
{
    int cnt = 0;
    while(cnt < v.size() && v[cnt] == '0') cnt++;
    if(cnt == v.size()) return "0";
    return v.substr(cnt, int(v.size()) - cnt);
}

string operator |(const string& a, const string& b)
{
    int sz = max(a.size(), b.size());
    string ans(sz, '0');
    for(int i = 0; i < a.size(); i++)
        if(a[i] == '1') ans[i + sz - int(a.size())] = '1';
    for(int i = 0; i < b.size(); i++)
        if(b[i] == '1') ans[i + sz - int(b.size())] = '1';    
    return normalize(ans);
}

bool better(const string& a, const string& b)
{
    if(a.size() != b.size()) return a.size() > b.size();
    return a > b;
}

int main()
{
    int n;
    scanf("%d", &n);
    string s;
    scanf("%s", buf);
    s = buf;
    string ans = s | s;
    int pos1 = s.find("1");
    if(pos1 != string::npos)
    {
        int pos2 = s.find("0", pos1);
        if(pos2 != string::npos)
        {
            int cur = pos1;
            int not_needed = 0;
            while(true)
            {                
                if(cur == n || (s[cur] == '1' && cur > pos2)) break;
                string nw = s | s.substr(pos1, n - pos1 - not_needed);
                if(better(nw, ans)) ans = nw;
                cur++;
                not_needed++;
            }
        }
    }
    puts(ans.c_str());
}
```
[1743E - FTL](../problems/E._FTL.md "Educational Codeforces Round 137 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1743E - FTL](../problems/E._FTL.md "Educational Codeforces Round 137 (Rated for Div. 2)")

At any time, we have three possible choices: wait and shoot the first laser, the second laser and both lasers. Sometimes it makes sense to wait to both because you can deal $s$ more damage than you would do by shooting both lasers separately.

The first claim: greedy won't work. Maybe there is a sufficiently smart greedy, we weren't able to come up with it. The second claim: bruteforce won't work. The funny thing is that it actually worked on the constraints up to $2000$, but again, we couldn't code any sufficiently fast one for $5000$.

Thus, let's try some dynamic programming. Since all the times are huge, we'd want to avoid having them as the states. What is small, however, is the durability of the enemy ship and the number of shots we have to make to destroy it.

Ideally, we'd like to have some $dp[i]$ — the smallest time to deal $i$ damage to the enemy ship. This way, $dp[n]$ would be the answer. Sadly, it's not immediately clear how to get rid of reload times completely. There might be states with different times until the charge with the same damage dealt, and we don't know which of those we want to keep.

Thus, let's make the dp state more complicated. Let $dp[i]$ be the smallest time it takes to deal $i$ damage if the last shot was from both lasers at the same time. This way we know the reload times of both lasers — they are full $t_1$ and $t_2$.

$dp[0] = 0$, as moment $0$ has both lasers zero charged as if after a shot.

What are the transitions? Well, now we have to shoot each laser multiple times, then wait until both are charged and shoot both. Both lasers can now be considered independent of each other.

Let the time between the previous double shot and the next one be some value $t$. During this time, it never made sense to wait until shooting each laser. So we waited $t_1$, shot the first laser, waited another $t_1$, shot again, until we couldn't shoot anymore, since the laser wouldn't recharge in time before the double shot. Same for the second laser. Notice that if both $t \mod t_1 \neq 0$ and $t \mod t_2 \neq 0$, then you could just decrease $t$ by $1$ and shoot each laser the same number of times. Thus, only $t$ that are multiples of either $t_1$ or $t_2$ are optimal.

Thus, we can iterate over all possible waiting times $t$. Just iterate over $i \cdot t_1$ and $i \cdot t_2$ for all $i$ from $1$ to $h$. Having a fixed $t$, calculate the number of shots of each laser, calculate the damage, go into the corresponding dp state.

It could also happen that the last shot before destroying the ship wasn't a double one. However, it still follows the same ideas. It means that each laser was shooting non-stop until the ship was destroyed. Thus, the destruction time is still a multiple of either of the reload times.

Overall complexity: $O(h^2)$.

 **Solution (awoo)**
```cpp
#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

const long long INF64 = 1e18;

int main() {
	vector<int> ps(2);
	vector<long long> ts(2);
	int h, s;
	forn(i, 2) scanf("%d%lld", &ps[i], &ts[i]);
	scanf("%d%d", &h, &s);
	long long ans = INF64;
	vector<long long> dp(h + 1, INF64);
	dp[0] = 0;
	forn(i, h) for (int j = 1; j <= h - i; ++j) forn(k, 2){
		int ni = min((long long)h, i + j * (ps[k] - s) + j * ts[k] / ts[k ^ 1] * (ps[k ^ 1] - s));
		if (ni == h)
			ans = min(ans, dp[i] + j * ts[k]);
		if (j * ts[k] >= ts[k ^ 1]){
			ni = min((long long)h, i + (j - 1) * (ps[k] - s) + (j * ts[k] / ts[k ^ 1] - 1) * (ps[k ^ 1] - s) + (ps[0] + ps[1] - s));
			dp[ni] = min(dp[ni], dp[i] + j * ts[k]);
		}
	}
	ans = min(ans, dp[h]);
	printf("%lldn", ans);
}
```
[1743F - Intersection and Union](../problems/F._Intersection_and_Union.md "Educational Codeforces Round 137 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1743F - Intersection and Union](../problems/F._Intersection_and_Union.md "Educational Codeforces Round 137 (Rated for Div. 2)")

We will use the Contribution to the Sum technique to solve this problem: for every integer from $0$ to $300000$, let's calculate the number of ways to choose the operators so it belongs to the result, and add all of the results.

For a fixed integer $x$, the number of ways to choose the operators so that $x$ belongs to the result can be done as follows: let $dp_{i,f}$ be the number of ways to choose the first $i$ operators so that, after applying them, the resulting set contains $x$ if $f = 1$, and does not contain $x$ if $f = 0$. The transitions from $dp_i$ to $dp_{i+1}$ depend on whether the number $x$ belongs to the segment $i+1$.

Obviously, this is too slow if we compute the dynamic programming from scratch for every integer $x$. Instead, we can notice that the transitions from $dp_i$ to $dp_{i+1}$ are linear combinations: both $dp_{i+1,0}$ and $dp_{i+1,1}$ are linear combinations of $dp_{i,0}$ and $dp_{i,1}$ with coefficients depending on whether the element $x$ belongs to the set or not. So, transitioning from $dp_i$ to $dp_{i+1}$ can be written in terms of multiplying by a $2 \times 2$ matrix.

Let's build a segment tree where each vertex stores a transition matrix, and operations are "calculate the product of matrices on a segment" and "replace a matrix at some index". We can build a sequence of these transition matrices for $x=0$ and store them in the segment tree; for $x=1$, this sequence of transition matrices will change only in positions $j$ such that either $0$ belongs to $[l_j, r_j]$ and $1$ does not belong to it, or vice versa. So, we can go from $x=0$ to $x=1$ by replacing these transition matrices in the segment tree. For $x=2$, the only changes from $x=0$ are in positions $j$ such that either $1$ belongs to $[l_j, r_j]$ and $2$ does not belong to it, or vice versa — and we can replace the matrices in these positions as well. In total, there will be only $O(n)$ such replacements; so, we solve the problem in $O(M + n \log M)$, where $M$ is the constraint on the numbers belonging to the sets. 

 **Solution (BledDest)**
```cpp
#include<bits/stdc++.h>

using namespace std;

const int N = 300043;

typedef array<int, 2> vec;
typedef array<vec, 2> mat;

const int MOD = 998244353;

mat operator*(const mat& a, const mat& b)
{
    mat c;
    for(int i = 0; i < 2; i++)
        for(int j = 0; j < 2; j++)
            c[i][j] = 0;
    for(int i = 0; i < 2; i++)
        for(int j = 0; j < 2; j++)
            for(int k = 0; k < 2; k++)
                c[i][k] = (a[i][j] * 1ll * b[j][k] + c[i][k]) % MOD;
    return c;
}

mat ZERO = {vec({3, 0}), vec({1, 2})};
mat ONE = {vec({1, 2}), vec({1, 2})};

mat t[4 * N];

void recalc(int v)
{
    t[v] = t[v * 2 + 1] * t[v * 2 + 2];    
}

void build(int v, int l, int r)
{
    if(l == r - 1)
    {            
        t[v] = ZERO;                       
    }
    else
    {
        int m = (l + r) / 2;
        build(v * 2 + 1, l, m);
        build(v * 2 + 2, m, r);
        recalc(v);               
    }
}

void upd(int v, int l, int r, int pos, int val)
{
    if(l == r - 1)
    {
        if(val == 0) t[v] = ZERO;
        else t[v] = ONE;
    }
    else
    {
        int m = (l + r) / 2;
        if(pos < m) upd(v * 2 + 1, l, m, pos, val);
        else upd(v * 2 + 2, m, r, pos, val);
        recalc(v);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<vector<pair<int, int>>> v(N);
    for(int i = 0; i < n; i++)
    {
        int l, r;
        cin >> l >> r;
        v[l].push_back(make_pair(1, i));
        v[r + 1].push_back(make_pair(0, i));
    }    
    build(0, 0, n - 1);
    int cur = 0;
    int ans = 0;
    for(int i = 0; i <= 300000; i++)
    {
        for(auto x : v[i])
        {
            if(x.second == 0) cur = x.first;
            else upd(0, 0, n - 1, x.second - 1, x.first);
        }
        ans = (ans + t[0][cur][1]) % MOD;
    }
    cout << ans << endl;
}
```
[1743G - Antifibonacci Cut](../problems/G._Antifibonacci_Cut.md "Educational Codeforces Round 137 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1743G - Antifibonacci Cut](../problems/G._Antifibonacci_Cut.md "Educational Codeforces Round 137 (Rated for Div. 2)")

The first idea that comes to mind is running some sort of dynamic programming: $dp_i$ — the number of ways to cut the string consisting of the first $i$ characters. When we calculate $dp_i$, we need to take the sum of the previous values of $dp$, and then subtract $dp_j$ for every $j$ such that the string from the $j$-th character (inclusive) to the $i$-th character (non-inclusive) is a Fibonacci string. Unfortunately, there are two main issues with this solution: firstly, we cannot store the array $dp$ in memory; and secondly, we have to search for the Fibonacci strings ending in a certain index quickly (something like Aho-Corasick could work with a less strict memory limit, but right now we cannot use it).

We will try to resolve both of these issues with the following approach: while we process the characters, we will maintain the list of tuples $(j, dp_j)$ such that the string from the $j$-th character to the current one is a prefix of some Fibonacci string. How do we maintain them?

Every Fibonacci string $f_i$ (except for $f_0$) is a prefix of $f_{i+1}$. So, all Fibonacci strings we are interested in (except for $f_0$ again) are prefixes of the same long Fibonacci string. Suppose a tuple $(j, dp_j)$ represents some index $j$ such that the string from the $j$-th character to the current one is a prefix of that long Fibonacci string. Each time we append a character, we filter this list of tuples by trying to check if this new character matches the next character in the prefix (if it does not, the tuple is discarded). For the tuples that represent the prefixes equal to Fibonacci strings, we need to subtract the value of $dp_j$ from the new $dp$ value we are trying to calculate (checking if a prefix is a Fibonacci string is easy, we just need to check its length). How do we check that if we add a character 1 or 0, it is still a prefix? There are two ways to do this:

* either generate the first $3 \cdot 10^6$ characters of the long Fibonacci string;
* or represent the current prefix as the sum of Fibonacci strings $f_{i_1} + f_{i_2} + \dots + f_{i_k}$ such that for every $j \in [1, k - 1]$, the condition $f_{i_j} > f_{i_{j+1}} + 1$ holds (i. e. the Fibonacci strings we split the current prefix into are arranged in descending order, and there is no pair of equal or adjacent (by index) Fibonacci strings in the split). This representation is very similar to writing an integer in Zeckendorf system. The next character in the prefix depends on whether $f_1$ belongs to this split: if it belongs, it is the last string in the split, so we need to append 0 to transform $f_1$ into $f_2$; otherwise, we need to append 1.

Okay, so now we can solve the problem in $O(NM)$ time (where $N$ is the total length of the strings in the input, and $M$ is the size of the list of tuples $(j, dp_j)$ we discussed earlier). This actually works since it looks like the size of the list of tuples is bounded as $O(\log N)$. Unfortunately, we don't have a strict mathematical proof of this; we checked this by brute force with $N$ up to $3 \cdot 10^6$, so it definitely works under the constraints of the problem.

 **Solution (BledDest)**
```cpp
#include<bits/stdc++.h>

using namespace std;

const int MOD = 998244353;

int add(int x, int y)
{
    x += y;
    while(x >= MOD) x -= MOD;
    while(x < 0) x += MOD;
    return x;
}

int sub(int x, int y)
{
    return add(x, MOD - y);
}

int expected(int mask)
{
    if(mask & 2) return 0;
    return 1;
}

int last_bit(int x)
{
    if(x == 0) return -1;
    return x - (x & (x - 1));
}

bool go(int& a, int x)
{
    if(expected(a) != x)
    {
        a = 1 << x;
        return false;    
    }
    a ^= (1 << x);
    while(true)
    {
        int b = last_bit(a);
        int c = last_bit(a - b);
        if(c == 2 * b) a += b;
        else break;
    }
    return true;
}

bool is_fib(int a)
{
    return a == last_bit(a);
}

vector<pair<int, int>> go(const vector<pair<int, int>>& a, int x)
{
    vector<pair<int, int>> nw;
    for(auto b : a)
    {
        int cost = b.first;
        int seqn = b.second;
        if(go(seqn, x)) nw.push_back(make_pair(cost, seqn));
    }
    return nw;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int last = 1, sum = 1;
    vector<pair<int, int>> w;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for(auto x : s)
        {
            int c = x - '0';
            int ndp = sub(sum, last);
            w = go(w, c);
            for(int j = 0; j < w.size(); j++)
            {
                if(is_fib(w[j].second))
                    ndp = sub(ndp, w[j].first);
            }
            if(c == 1) w.push_back(make_pair(last, 2));
            sum = add(sum, ndp);
            last = ndp;
            assert(w.size() <= 60);
        }
        cout << last << endl;
    }
}
```
