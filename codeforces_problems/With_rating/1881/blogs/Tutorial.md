# Tutorial

[1881A - Don't Try to Count](../problems/A._Don't_Try_to_Count.md "Codeforces Round 903 (Div. 3)")

Idea: [Vladosiya](https://codeforces.com/profile/Vladosiya "Expert Vladosiya")

 **Tutorial**
### [1881A - Don't Try to Count](../problems/A._Don't_Try_to_Count.md "Codeforces Round 903 (Div. 3)")

Note that the answer is always not greater than $5$. When $n=1$, $m=25$, the answer is either $5$ or $-1$, it is easy to see that the answer cannot be greater.

This allows us to simply iterate over the number of operations, each time checking if $s$ occurs in $x$. The time complexity of this solution is $O(2^5\cdot n \cdot m)$.

 **Solution**
```cpp
def solve():
    n, m = map(int, input().split())
    x = input()
    s = input()
    for i in range(6):
        if s in x:
            print(i)
            return
        x += x
    print(-1)


for _ in range(int(input())):
    solve()
```
[1881B - Three Threadlets](../problems/B._Three_Threadlets.md "Codeforces Round 903 (Div. 3)")

Idea: [Gornak40](https://codeforces.com/profile/Gornak40 "Expert Gornak40")

 **Tutorial**
### [1881B - Three Threadlets](../problems/B._Three_Threadlets.md "Codeforces Round 903 (Div. 3)")

If the lengths of the threadlets are equal, the answer is "YES".

Otherwise, let's denote the length of the minimum threadlet as $a$. If we cut it, we will have only two operations, which is not enough.

Therefore, the desired length should be equal to $a$. If $b$ or $c$ are not divisible by $a$, the answer is "NO". Otherwise, we will check if $\frac{b}{a} - 1 + \frac{c}{a} - 1 \le 3$.

 **Solution**
```cpp
for _ in range(int(input())):
    a, b, c = sorted(map(int, input().split()))
    if a == b and b == c:
        print('YES')
    elif b % a == 0 and c % a == 0 and (b // a - 1) + (c // a - 1) <= 3:
        print('YES')
    else:
        print('NO')
```
[1881C - Perfect Square](../problems/C._Perfect_Square.md "Codeforces Round 903 (Div. 3)")

Idea: [myav](https://codeforces.com/profile/myav "Pupil myav"), [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov"), [Vladosiya](https://codeforces.com/profile/Vladosiya "Expert Vladosiya")

 **Tutorial**
### [1881C - Perfect Square](../problems/C._Perfect_Square.md "Codeforces Round 903 (Div. 3)")

When rotating a matrix of size $n$ by $n$ by $90$ degrees: 

* element $a[i][j]$ takes the position of element $a[j][n - 1 - i]$;
* element $a[n - 1 - j][i]$ takes the position of element $a[i][j]$;
* element $a[n - 1 - i][n - 1 - j]$ takes the position of element $a[n - 1 - j][i]$.

In order for the matrix to be a perfect square, the symbols at all of these positions must be equal. Since we can only maximize a symbol, we do the following:

1. Among these 4 symbols, let's find the lexicographically maximal one, that is, the one that is in the alphabet not before all the others;
2. For all characters that are not equal to the maximum, calculate the number of operations that must be applied to them to make them equal to the maximum character. This number of operations is equal to the difference of positions of symbols in the alphabet.
 **Solution**
```cpp
#include <bits/stdc++.h>
#define all(arr) arr.begin(), arr.end()

using namespace std;

const int MAXN = 1010;

int n;
string A[MAXN];

int solve() {
    int ans = 0;
    for (int i = 0; i * 2 < n; ++i)
        for (int j = 0; j * 2 < n; ++j) {
            vector<char> M {A[i][j], A[n - 1 - j][i], A[n - 1 - i][n - 1 - j], A[j][n - 1 - i]};
            char c = *max_element(all(M));
            for(char e: M)
                ans += c - e;
        }
    return ans;
}

int main() {
    int t; cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; ++i)
            cin >> A[i];
        cout << solve() << endl;
    }
}
```
[1881D - Divide and Equalize](../problems/D._Divide_and_Equalize.md "Codeforces Round 903 (Div. 3)")

Idea: [myav](https://codeforces.com/profile/myav "Pupil myav")

 **Tutorial**
### [1881D - Divide and Equalize](../problems/D._Divide_and_Equalize.md "Codeforces Round 903 (Div. 3)")

To solve the problem, we need to decompose all numbers in the array into prime divisors. After that, let's calculate the number of each divisor, summarizing the decompositions of all numbers.

If each divisor enters $k\cdot n$ times, where $k$ is a natural number, then we can equalize all the numbers in the array: we will sequentially apply the operation so that each number consists of the same set of prime divisors.

If some divisor enters a different number of times, then it will not be possible to equalize the numbers in the array.

 **Solution**
```cpp
#include<bits/stdc++.h>
using namespace std;
const int maxv = 1000000;

void add_divs(int x, map<int, int>&divs){
    int i = 2;
    while(i * i <= x){
        while (x % i == 0){
            divs[i]++;
            x /= i;
        }
        i++;
    }
    if(x > 1) divs[x]++;
}

bool solve(){
    int n;
    cin >> n;
    vector<int>a(n);
    map<int, int> divs;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        add_divs(a[i], divs);
    }
    for(auto e: divs){
        if(e.second % n != 0) return false;
    }
    return true;
}

int main(){
    int t;
    cin >> t;
    while(t--) {
        cout << (solve() ? "YES" : "NO") << "n";
    }
}
```
[1881E - Block Sequence](../problems/E._Block_Sequence.md "Codeforces Round 903 (Div. 3)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1881E - Block Sequence](../problems/E._Block_Sequence.md "Codeforces Round 903 (Div. 3)")

Let's use the dynamic programming approach: let $dp[i]$ be the number of operations required to make the segment from $i$ to $n$ beautiful. There are two possible ways to achieve this:

* Remove the element at position $i$ and make the segment from $i + 1$ to $n$ beautiful, then $dp[i] = dp[i+1] + 1$;
* Make the segment from $i + a_i + 1$ to $n$ beautiful, then $dp[i] = dp[i + a_i + 1]$ (cases where $i + a_i + 1 > n$ need to be handled separately).
 **Solution**
```cpp
def solve():
    n = int(input())
    a = [int(x) for x in input().split()]
    dp = [n + 1] * n

    def get(pos):
        if pos > n:
            return n + 1
        if pos == n:
            return 0
        return dp[pos]

    dp[-1] = 1
    for i in range(n - 2, -1, -1):
        dp[i] = min(dp[i + 1] + 1, get(i + a[i] + 1))
    print(dp[0])


for _ in range(int(input())):
    solve()
```
[1881F - Minimum Maximum Distance](../problems/F._Minimum_Maximum_Distance.md "Codeforces Round 903 (Div. 3)")

Idea: [senjougaharin](https://codeforces.com/profile/senjougaharin "Master senjougaharin")

 **Tutorial**
### [1881F - Minimum Maximum Distance](../problems/F._Minimum_Maximum_Distance.md "Codeforces Round 903 (Div. 3)")

Let's run a breadth-first traversal from any labeled vertex $v_1$ and find the farthest other labeled vertex $v_2$ from it. Then we run a traversal from $v_2$ and find the farthest labeled vertex $v_3$ from it (it may coincide with $v_1$). Then the answer is $\lceil \frac{d}{2} \rceil$, where $d$ is the distance between $v_2$ and $v_3$. It is worth considering separately the case when there is only one labeled vertex in the tree. Then the answer is $0$.

 **Solution**
```cpp
#include<bits/stdc++.h>

using namespace std;

int n;
vector<vector<int>> g;

void dfs(int v, int p, vector<int> &d){
	if(p != -1) d[v] = d[p] + 1;
	for(int u: g[v]){
		if(u != p){
			dfs(u, v, d);
		}
	}
}

int main(){
    int t;
	cin>>t;
	while(t--){
	    int k;
		cin>>n>>k;
		g.assign(n, vector<int>(0));
		vector<int> marked(k);
		for(int &e: marked) cin >> e, --e;
		for(int i=1;i<n;i++){
			int u, v;
			cin >> u >> v;
			--u, --v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		if(k==1){
			cout<<0<<"n";
			continue;
		}
		vector<int> d1(n);
		dfs(marked[0], -1, d1);
		int mx = marked[0];
		for(int e: marked){
		    if(d1[e] > d1[mx]) mx = e;
		}
		vector<int> d2(n);
		dfs(mx, -1, d2);
		mx = marked[0];
		for(int e: marked){
		    if(d2[e] > d2[mx]) mx = e;
		}
		cout << (d2[mx] + 1) / 2 << "n";
	}
	return 0;
}
```
[1881G - Anya and the Mysterious String](../problems/G._Anya_and_the_Mysterious_String.md "Codeforces Round 903 (Div. 3)")

Idea: [Gornak40](https://codeforces.com/profile/Gornak40 "Expert Gornak40")

 **Tutorial**
### [1881G - Anya and the Mysterious String](../problems/G._Anya_and_the_Mysterious_String.md "Codeforces Round 903 (Div. 3)")

Let's make two obvious observations about palindromes of length at least $2$: 

* Palindromes of length $2n$ contain a palindrome substring $[n \ldots n + 1]$;
* Palindromes of length $2n + 1$ contain a palindrome substring $[n \ldots n + 2]$.

Now we need to learn how to track only palindromes of length $2$ and $3$. Let's call an index bad if a palindrome of length $2$ starts from it, and terrible if a palindrome of length $3$ starts from it. We will store the bad and terrible indices in a pair of std::set.

Let's assume that there are no modification queries and we need to check the substring $[l \ldots r]$ for beauty. If there exists a bad index $i$ ($l \le i \le r - 1$) or a terrible index $j$ ($l \le j \le r - 2$), then the substring is not beautiful; otherwise, it is beautiful. This can be checked using binary search on the set.

Now let's learn how to make modifications. Notice that palindromes do not appear or disappear inside a segment, but they can appear or disappear at its boundaries. Let's use a data structure that can add values on a segment and retrieve a value at a point. If such a structure exists, we will add $x \mod 26$ to the segment $[l \ldots r]$, and then process the nearest $10$ indices to $l$ and the nearest $10$ indices to $r$. We can describe more precisely which bad and terrible indices should be processed, but the author is lazy it does not affect the solution, because the number of such indices is still $O(1)$. When processing the indices, we use point queries and insertion/deletion operations in std::set.

Now we need to implement such a data structure. The author suggests using a Fenwick tree on a difference array. A segment tree with lazy propagation will also work. This gives a solution with $O((n + q) \log n)$ time complexity.

 **Solution**
```cpp
#include <iostream>
#include <string>
#include <set>
#include <cstring>
#define int long long

using namespace std;

const int L = 26;
const int MAXN = 200200;

int n, m;
string s;
set<int> M2, M3;
int fen[MAXN];

void fenadd(int i, int x) {
	x = (x % L + L) % L;
	for (; i < n; i |= (i + 1))
		fen[i] = (fen[i] + x) % L;
}

int fenget(int i) {
	int ans = 0;
	for (; i >= 0; i = (i & (i + 1)) - 1)
		ans = (ans + fen[i]) % L;
	return ans;
}

void relax(int l, int r) {
	l = max(l, 0LL);
	r = min(r, n);
	for (int i = l; i + 1 < r; ++i) {
		int c1 = fenget(i);
		int c2 = fenget(i + 1);

		if (c1 == c2) M2.insert(i);
		else M2.erase(i);

		if (i + 2 >= r) continue;

		int c3 = fenget(i + 2);
		if (c1 == c3) M3.insert(i);
		else M3.erase(i);
	}
}

void build() {
	M2.clear();
	M3.clear();
	memset(fen, 0, n * sizeof(int));
	fenadd(0, s[0] - 'a');
	for (int i = 1; i < n; ++i) {
		fenadd(i, s[i] - s[i - 1] + L);
	}
	for (int i = 0; i + 1 < n; ++i) {
		if (s[i] == s[i + 1]) M2.insert(i);
		if (i + 2 < n && s[i] == s[i + 2]) M3.insert(i);
	}
}

void update(int l, int r, int x) {
	fenadd(l, x);
	relax(l - 5, l + 5);
	fenadd(r, L - x);
	relax(r - 5, r + 5);
}

bool query(int l, int r) {
	auto it = M2.lower_bound(l);
	if (it != M2.end() && *it + 1 < r) return false;
	it = M3.lower_bound(l);
	if (it != M3.end() && *it + 2 < r) return false;
	return true;
}

signed main() {
	int t; cin >> t;
	while (t--) {
		cin >> n >> m >> s;
		build();
		while (m--) {
			int tp, l, r; cin >> tp >> l >> r, --l;
			if (tp == 1) {
				int x; cin >> x;
				update(l, r, x);
			} else {
				cout << (query(l, r) ? "YES" : "NO") << 'n';
			}
		}
	}
}
```
