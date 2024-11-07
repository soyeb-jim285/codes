# Tutorial_2_(en)

Thanks for participating. We hope you enjoyed the contest!

[1999A - A+B Again?](../problems/A._A+B_Again_.md "Codeforces Round 964 (Div. 4)")

Idea: [flamestorm](https://codeforces.com/profile/flamestorm "Master flamestorm")

 **Tutorial**
### [1999A - A+B Again?](../problems/A._A+B_Again_.md "Codeforces Round 964 (Div. 4)")

You can take the input as a string and output the sum of the two characters in the string.

There is also a formula: ⌊n10⌋+nmod10. The first term is the tens digit, the second term — the ones digit.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	cin >> n;
	cout << (n / 10) + (n % 10) << 'n';	
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
	// solve();
}
```
[1999B - Card Game](../problems/B._Card_Game.md "Codeforces Round 964 (Div. 4)")

Idea: [SlavicG](https://codeforces.com/profile/SlavicG "Master SlavicG")

 **Tutorial**
### [1999B - Card Game](../problems/B._Card_Game.md "Codeforces Round 964 (Div. 4)")

For each test case, we can brute force through all possible games (there are only four of them) and calculate who is the winner of the game by simulating the game.

 **Solution**
```cpp
def f(a, b):
    if (a > b): return 1
    if (a == b): return 0
    if (a < b): return -1
for _ in range(int(input())):
    a, b, c, d = map(int, input().split())
    ans = 0
    if f(a, c) + f(b, d) > 0:
        ans += 1
    if f(a, d) + f(b, c) > 0:
        ans += 1
    if f(b, c) + f(a, d) > 0:
        ans += 1
    if f(b, d) + f(a, c) > 0:
        ans += 1
    print(ans)
```
[1999C - Showering](../problems/C._Showering.md "Codeforces Round 964 (Div. 4)")

Idea: [SlavicG](https://codeforces.com/profile/SlavicG "Master SlavicG")

 **Tutorial**
### [1999C - Showering](../problems/C._Showering.md "Codeforces Round 964 (Div. 4)")

We just need to find the lengths of the gaps between intervals. Note that from the additional constraint on the input, the intervals are in sorted order. So you need to find if for any i>1, li−ri−1≥s, and also if l1≥s (the initial interval), or if m−rn≥s (the final interval).

 **Solution**
```cpp
def solve():
    n, s, m = map(int, input().split())
    segs = [[0, 0], [m, m]] + [list(map(int, input().split())) for i in range(n)]
    segs.sort()
    for i in range(1, n + 2):
        if segs[i][0] - segs[i - 1][1] >= s:
            print('YES')
            return
    print('NO')


#sys.stdin = open('in', 'r')
for _ in range(int(input())):
    solve()
```
[1999D - Slavic's Exam](../problems/D._Slavic's_Exam.md "Codeforces Round 964 (Div. 4)")

Idea: [SlavicG](https://codeforces.com/profile/SlavicG "Master SlavicG")

 **Tutorial**
### [1999D - Slavic's Exam](../problems/D._Slavic's_Exam.md "Codeforces Round 964 (Div. 4)")

Let's use a greedy strategy with two pointers, one at the start of s (called i) and one at the start of t (called j). At each step, advance i by 1. If si=?, then we set it to tj and increment j. If si=tj then we also increment j (because there is a match).

It works because if there is ever a question mark, it never makes it worse to match the current character in t earlier than later. The complexity is O(n).

 **Solution**
```cpp
  
#include <bits/stdc++.h>
using namespace std;

int main() {
    int test_cases; cin >> test_cases;
    while(test_cases--) {
        string s, t; cin >> s >> t;
    	int idx = 0;
    
    	for(int i = 0; i < (int)s.size(); ++i) {
    		if(s[i] == '?') {
    			if(idx < (int)t.size()) s[i] = t[idx++];
    			else s[i] = 'a';
    		} else if(s[i] == t[idx]) ++idx;
    	}
    	if(idx >= t.size()) cout << "YESn" << s << "n";
    	else cout << "NOn";
    }
}
```
[1999E - Triple Operations](../problems/E._Triple_Operations.md "Codeforces Round 964 (Div. 4)")

Idea: [flamestorm](https://codeforces.com/profile/flamestorm "Master flamestorm")

 **Tutorial**
### [1999E - Triple Operations](../problems/E._Triple_Operations.md "Codeforces Round 964 (Div. 4)")

Consider writing the numbers in ternary (it is like binary but instead we use three digits, and for clarity we will use "digit" in the solution instead of "bit" or "trit").

In the operation, we will add a 0 to the end of the number x and remove the last digit of y. For example, if x=8 and y=11, then in ternary the numbers are 223 and 1023. After the operation, x=24 and y=3, and indeed in ternary they are 2203 and 103. (This is because multiplying by 3 is multiplying by 103, and similarly dividing by 3 is like dividing by 103.)

This means that the total number of digits across all numbers does not change (since we add one digit and remove one digit). So how is it possible to make all numbers 0?

Well, there is one exception to the above rule: when we use the operation with x=0, we add a 0 to the end of the number 0, but this added digit doesn't count (because 3⋅0=0). This means that if we ever do the operation with x=0, then we will lose one digit total (since x doesn't gain a digit, but y loses a digit).

This means the solution is as follows: first, we make one of the numbers equal to 0. Then, we will use this 0 to remove all the digits of all other numbers. To use the fewest number of operations possible, we should do the first step on the minimum number, since it has the fewest digits.

Let f(x) denote the number of ternary digits in the number x (actually, f(x)=⌊log3(x)⌋+1). Then the first step takes f(l) operations (since l is the smallest number in the range [l,r]), and the second step takes f(l)+⋯+f(r) operations (since we need to remove all the digits, which is the total number of digits from l to r).

This means the answer for each test case is f(l)+f(l)+⋯+f(r). To find this sum quickly, we can compute prefix sums on f so that the answer is simply f(l)+psum(r)−psum(l−1), which takes O(1) time per test case with O(n) precomputation.

 **Solution**
```cpp
  
#include <bits/stdc++.h>

using namespace std;

const int MAX = 200'007;
const int MOD = 1'000'000'007;

int a[MAX], psum[MAX];

int f(int x) {
	int cnt = 0;
	while (x) {
		x /= 3;
		cnt++;
	}
	return cnt;
}

void solve() {
	int l, r;
	cin >> l >> r;
	cout << psum[r] - psum[l - 1] + a[l] << 'n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	psum[0] = 0;
	for (int i = 1; i < MAX - 1; i++) {
		a[i] = f(i);
		psum[i] = psum[i - 1] + a[i];
	}
	
	int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
	// solve();
}
```
[1999F - Expected Median](../problems/F._Expected_Median.md "Codeforces Round 964 (Div. 4)")

Idea: [mesanu](https://codeforces.com/profile/mesanu "Candidate Master mesanu")

 **Tutorial**
### [1999F - Expected Median](../problems/F._Expected_Median.md "Codeforces Round 964 (Div. 4)")

Say the array has x ones and y zeroes.

If the median of a subsequence of length k is 1, then there are at least ⌊k2⌋+1 ones in the array.

Let's iterate over the number of ones in the subsequence from ⌊k2⌋+1 to x. Suppose there are i ones. Then there are k−i zeroes. The number of ways to choose i ones from x is \binom{x}{i}, that is, x choose i (this is the so-called [binomial coefficient](https://codeforces.com/https://en.wikipedia.org/wiki/Binomial_coefficient)). Similarly, the number of ways to choose k-i zeroes from y of them is \binom{y}{k-i}.

Therefore the answer is the sum of \binom{x}{i}\binom{y}{k-i} over all i from \lfloor \frac{k}{2} \rfloor + 1 to x. You can compute binomial coefficients in many ways, for example precomputing all factorials and then using the formula \binom{n}{k} = \frac{n!}{(n-k)!k!}. Depending on your implementation, it can take \mathcal{O}(n \log \mathrm{MOD}) or \mathcal{O}(n + \log \mathrm{MOD}) time. 

If you don't know how to do that, we recommend you read [the article](https://codeforces.com/https://cp-algorithms.com/combinatorics/binomial-coefficients.html#computing-binomial-coefficients-modulo-m).

 **Solution**
```cpp
  
#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5, mod = 1e9 + 7;
int64_t fact[N];
int64_t pw(int64_t a, int64_t b) {
	int64_t r = 1;
	while(b > 0) {
		if(b & 1) r = (r * a) % mod;
		b /= 2;
		a = (a * a) % mod; 
	}
	return r;
}
int64_t C(int64_t n, int64_t k) {
	if(n < k) return 0LL;
	return (fact[n] * pw((fact[n - k] * fact[k]) % mod, mod - 2)) % mod;
}
int main() {
	int t; cin >> t;
	fact[0] = 1;
	for(int64_t i = 1; i < N; ++i) fact[i] = (fact[i - 1] * i) % mod;
	while(t--) {
		int n, k; cin >> n >> k;
		vector<int> a(n);
		int ones = 0;
		for(int i = 0; i < n; ++i) {
			cin >> a[i];
			ones += a[i];
		}
		//at least k/2+1 ones
		int64_t ans = 0;
		for(int cnt_ones = k / 2 + 1; cnt_ones <= min(ones, k); ++cnt_ones) {
			ans += C(ones, cnt_ones) * C(n - ones, k - cnt_ones) % mod;
			ans %= mod;
		}
		cout << ans << "n";
	}
}
```
[1999G1 - Ruler (easy version)](../problems/G1._Ruler_(easy_version).md "Codeforces Round 964 (Div. 4)")

Idea: [flamestorm](https://codeforces.com/profile/flamestorm "Master flamestorm")

 **Tutorial**
### [1999G1 - Ruler (easy version)](../problems/G1._Ruler_(easy_version).md "Codeforces Round 964 (Div. 4)")

Consider queries of the form \texttt{?}~~\texttt{1}~~y. Since x > 1, the height of the rectangle is always measured correctly. That means: 

* If y < x, the response is y.
* If y \geq x, the response is y+1.

 This is a monotonic function, which means we can use binary search to find the smallest y for which the response is y+1. The number of queries is \lceil \log_2(1000) \rceil = 10. **Solution**
```cpp
  
#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX = 200'007;
const int MOD = 1'000'000'007;
 
void solve() {
	int l = 2, r = 1000;
	while (l < r) {
		int mid = l + (r - l) / 2;
		cout << "? 1 " << mid << endl;
		int resp; cin >> resp;
		
		if (resp == mid) {
			l = mid + 1;
		} 
		else {
			r = mid;
		}
	}
	cout << "! " << l << endl;	
}
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
	// solve();
}
```
[1999G2 - Ruler (hard version)](../problems/G2._Ruler_(hard_version).md "Codeforces Round 964 (Div. 4)")

Idea: [flamestorm](https://codeforces.com/profile/flamestorm "Master flamestorm")

 **Tutorial**
### [1999G2 - Линейка (сложная версия)](../problems/G2._Ruler_(hard_version).md "Codeforces Round 964 (Div. 4)")

Consider one query of the form \texttt{?}~~a~~b for a < b. That means: 

* If a < b < x, the response is a \cdot b (both a and b are measured correctly).
* If a < x \leq b, the response is a \cdot (b + 1) (a is measured correctly, but b is not).
* If x \leq a < b, the repsone is (a + 1) \cdot (b + 1) (both a and b are measured incorrectly).

 This means that as a result of one query, we can cut the list of possible x values into three pieces: (b, 999], (a, b], or (1, a]. In other words, if we choose a and b appropriately, the number of possible x goes down by a factor of 3.If we repeat this, each time dividing the search space into three equal pieces, then the number of queries needed is \lceil \log_3(1000) \rceil = 7.

This is similar to the so-called ternary search to find the maximum of a unimodal function (although it is slightly different). You should be careful about the small case when there are only two possible values of x left.

 **Solution**
```cpp
  
#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX = 200'007;
const int MOD = 1'000'000'007;
 
void solve() {
	int l = 1, r = 999;
	while (r - l > 2) {
		int a = (2 * l + r) / 3;
		int b = (2 * r + l) / 3;
		cout << "? " << a << ' ' << b << endl;
		int resp; cin >> resp;
		
		if (resp == (a + 1) * (b + 1)) {
			r = a;
		}
		else if (resp == a * b) {
			l = b;
		}
		else {
			l = a; r = b;
		}
	}
	if (r - l == 2) {
		cout << "? 1 " << l + 1 << endl;
		int resp; cin >> resp;
		
		if (resp == l + 1) {l = l + 1;}
		else {r = l + 1;}
		
	}
	cout << "! " << r << endl;
}
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
	// solve();
}
```
