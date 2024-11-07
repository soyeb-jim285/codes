# Tutorial

[1251A - Broken Keyboard](../problems/A._Broken_Keyboard.md "Educational Codeforces Round 75 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1251A - Broken Keyboard](../problems/A._Broken_Keyboard.md "Educational Codeforces Round 75 (Rated for Div. 2)")

If a key malfunctions, each sequence of presses of this key gives a string with even number of characters. So, if there is a substring consisting of odd number of equal characters c, such that it cannot be extended to the left or to the right without adding other characters, then it could not be produced by presses of button c if c was malfunctioning.

The only thing that's left is to find all maximal by inclusion substrings consisting of the same character.

 **Solution (Ne0n25)**
```cpp
#include <bits/stdc++.h>

using namespace std;

bool ans[26];

void solve() {
	string s;
	cin >> s;
	
	memset(ans, 0, sizeof(ans));
	
	for (int i = 0; i < s.size(); i++) {
		int j = i;
		while (j + 1 < s.size() && s[j + 1] == s[i])
			j++;
		if ((j - i) % 2 == 0)
			ans[s[i] - 'a'] = true;
		i = j;
	}
	
	for (int i = 0; i < 26; i++) if (ans[i])
		cout << char('a' + i);
	cout << endl;
}

int main() {
	int q;
	cin >> q;
	while (q--) solve();
}
```
[1251B - Binary Palindromes](../problems/B._Binary_Palindromes.md "Educational Codeforces Round 75 (Rated for Div. 2)")

Idea: [adedalic](https://codeforces.com/profile/adedalic "International Master adedalic")

 **Tutorial**
### [1251B - Binary Palindromes](../problems/B._Binary_Palindromes.md "Educational Codeforces Round 75 (Rated for Div. 2)")

Let's make several observations. At first, note that the lengths of the strings doesn't change.

At second, note that if the string has even length then being palindromic is the same as having even number of zeroes and even number of ones. But if the string has odd length, then it always is palindromic.

So the question is how to fix "bad" strings with even length but with odd number of zeroes and ones. If we have at least one string with odd length, then you can trade between "bad" string and "odd" string either zero to one or one to zero, fixing the "bad" string.

Otherwise you can fix two "bad" strings swapping appropriate characters. In result, we can either make all strings palindromic or all strings except one in case of absence of "odd" strings and having odd number of "bad" strings.

 **Solution (adedalic)**
```cpp
fun main() {
    val q = readLine()!!.toInt()
    for (ct in 1..q) {
        val n = readLine()!!.toInt()
        var (odd, evenGood, evenBad) = listOf(0, 0, 0)
        for (i in 1..n) {
            val s = readLine()!!
            when {
                s.length % 2 == 1 -> odd++
                s.count { it == '0' } % 2 == 0 -> evenGood++
                else -> evenBad++
            }
        }
        println(n - if (odd == 0 && evenBad % 2 == 1) 1 else 0)
    }
}
```
[1251C - Minimize The Integer](../problems/C._Minimize_The_Integer.md "Educational Codeforces Round 75 (Rated for Div. 2)")

Idea: [Roms](https://codeforces.com/profile/Roms "Master Roms")

 **Tutorial**
### [1251C - Minimize The Integer](../problems/C._Minimize_The_Integer.md "Educational Codeforces Round 75 (Rated for Div. 2)")

Let's consider two sequences of digits: $e_1, e_2, \dots , e_k$ and $o_1, o_2, \dots , o_m$, there $e_1$ is the first even digit in $a$, $e_2$ is the second even digit and so on and $o_1$ is the first odd digit in $a$, $o_2$ is the second odd digit and so on.

Since you can't swap digits of same parity, the sequence $e$ of even digits of $a$ never changed. Sequence $o$ of odd digits of $a$ also never changed. So the first digit in the answer will be equal to $e_1$ or to $o_1$. And since we have to minimize the answer, we have to chose the $min(e_1, o_1)$ as the first digit in answer and them delete it from the corresponding sequence (in this way sequence $e$ turn into $e_2, e_3, \dots , e_k$ or sequence $o$ turn into $o_2, o_3, \dots , o_m$). Second, third and followings digits need to choose in the same way.

 **Solution (Roms)**
```cpp
#include <bits/stdc++.h>

using namespace std;

int t;
string a;

int main() {	
	cin >> t;
	for(int tc = 0; tc < t; ++tc){
		cin >> a;
		string s[2];
		for(auto x : a)
			s[int(x - '0') & 1] += x;
		
		reverse(s[0].begin(), s[0].end());
		reverse(s[1].begin(), s[1].end());

		string res = "";
		while(!(s[0].empty() && s[1].empty())){
			if(s[0].empty()){
				res += s[1].back();
				s[1].pop_back();
				continue;
			}
			if(s[1].empty()){
				res += s[0].back();
				s[0].pop_back();
				continue;
			}

			if(s[0].back() < s[1].back()){
				res += s[0].back();
				s[0].pop_back();
			}
			else{
				res += s[1].back();
				s[1].pop_back();
			}
		}

		cout << res << endl;
	}	
	return 0;
} 


```
[1251D - Salary Changing](../problems/D._Salary_Changing.md "Educational Codeforces Round 75 (Rated for Div. 2)")

Idea: [Roms](https://codeforces.com/profile/Roms "Master Roms")

 **Tutorial**
### [1251D - Salary Changing](../problems/D._Salary_Changing.md "Educational Codeforces Round 75 (Rated for Div. 2)")

Let $f(mid)$ be equal minimum amount of money to obtain the median salary at least $mid$. We'll solve this problem by binary search by $mid$. 

Suppose the have to calculate the minimum amount of money for obtaining median salary at least $mid$. Let's divide all salaries into three groups:

1. $r_i < mid$;
2. $mid \le l_i$;
3. $l_i < mid \le r_i$.

 In order to the median salary be at least $mid$ there must be at least $\frac{n+1}{2}$ salaries greater than or equal to $mid$. Let's denote the number of such salaries as $cnt$.

Note that salaries of the first group can't increment the value of $cnt$, so it's beneficial for us to pay the minimum salary for this group. Salaries if second group always increment the value of $cnt$, so it's also beneficial for us to pay the minimum salary.

The salaries from the third group are more interesting. For each salary $[l_i, r_i]$ in this group we can pay $mid$ and increment $cnt$, or we can pay $l_i$ and don't increase $cnt$. The value of $cnt$ should be increased by $rem = max(0, \frac{n+1}{2} - cnt)$. So, if the size of the third group is less than $rem$ than we can't obtain the median salary $mid$. Otherwise, we can define how many salaries we can take with value $l_i$ and chose the minimal ones.

 **Solution (Roms)**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int N = int(2e5) + 99;
const int INF = int(1e9) + 100;

int t;
int n;
long long s;
pair<int, int> p[N];

bool ok(int mid){
	long long sum = 0;
	int cnt = 0;
	vector <int> v;
	for(int i = 0; i < n; ++i){
		if(p[i].second < mid)
			sum += p[i].first;
		else if(p[i].first >= mid){
			sum += p[i].first;
			++cnt;
		}
		else
			v.push_back(p[i].first);
	}

	assert(is_sorted(v.begin(), v.end()));
	
	int need = max(0, (n + 1) / 2 - cnt);
	if(need > v.size()) return false;
	for(int i = 0; i < v.size(); ++i){
		if(i < v.size() - need)
			sum += v[i];
		else
			sum += mid;
	}

	return sum <= s;
}

int main() {	
	scanf("%d", &t);
	for(int tc = 0; tc < t; ++tc){
		scanf("%d %lld", &n, &s);
		for(int i = 0; i < n; ++i)
			scanf("%d %d", &p[i].first, &p[i].second);
		
		sort(p, p + n);
		int lf = 1, rg = INF; ///WA -> 10^9
		while(rg - lf > 1){
			int mid = (lf + rg) / 2;
			if(ok(mid)) lf = mid;
			else rg = mid;
		}
		
		printf("%dn", lf);
	}
	return 0;
}                             	
```
[1251E1 - Voting (Easy Version)](../problems/E1._Voting_(Easy_Version).md "Educational Codeforces Round 75 (Rated for Div. 2)")

[1251E2 - Voting (Hard Version)](../problems/E2._Voting_(Hard_Version).md "Educational Codeforces Round 75 (Rated for Div. 2)")

Idea: [Roms](https://codeforces.com/profile/Roms "Master Roms")

 **Tutorial**
### [1251E2 - Voting (Hard Version)](../problems/E2._Voting_(Hard_Version).md "Educational Codeforces Round 75 (Rated for Div. 2)")

Denote the number of voters with $m_i = x$ as $c_x$. Also denote $pref_x = \sum\limits_{i=0}^{x-1} c_x$, i.e. $pref_x$ is equal to number of voters with $m_i < x$.

Let's group all voters by value $m_i$. We'll consider all these group in decreasing value of $m_i$. Assume that now we consider group with $m_i = x$. Then there are two cases:

1. if $pref_{x} + cnt \ge x$ then all these voters will vote for you for free. $cnt$ is equal to the number of votes bought in previous steps;
2. if $pref_{x} + cnt < x$ then we have to buy $x - pref_{s} - cnt$ additional votes. Moreover the value $m_i$ of this "bought" voter must be greater than or equal to $x$. Since these voters indistinguishable we have to buy $x - pref_{s} - cnt$ cheapest voter (with a minimal value of $p_i$).

So, all we have to do it maintain values $p_i$ not yet bought voters in some data structure (for example multiset in C++).

 **Solution (Roms)**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int N = int(3e5) + 99;

int t, n;
vector <int> v[N];

int main() {	
	int t;
	scanf("%d", &t);
	for(int tc = 0; tc < t; ++tc){
		scanf("%d", &n);
		for(int i = 0; i < n; ++i)
			v[i].clear();
		for(int i = 0; i < n; ++i){
			int x, s;
			scanf("%d %d", &x, &s);
			v[x].push_back(s);
		}		
		
		multiset <int > q;
		long long res = 0;
		int pref = n;
		int cnt = 0;
		for(int i = n - 1; i >= 0; --i){
			pref -= v[i].size();
			int need = i - pref;
			for(auto x : v[i]) q.insert(x);

			while(cnt < need){
				++cnt;
				res += *q.begin();				
				q.erase(q.begin());
			}
		}		

        	printf("%lldn", res);
        }
	return 0;
}                             	
```
[1251F - Red-White Fence](../problems/F._Red-White_Fence.md "Educational Codeforces Round 75 (Rated for Div. 2)")

Idea: [Neon](https://codeforces.com/profile/Neon "Candidate Master Neon") and [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1251F - Red-White Fence](../problems/F._Red-White_Fence.md "Educational Codeforces Round 75 (Rated for Div. 2)")

Let's analyze how the perimeter of the fence can be calculated, if we know its array of lengths. Suppose there are $m$ boards in the fence. The perimeter of the fence can be composed of the three following values:

* the lower border of the fence (with length $m$);
* $m$ horizontal segments in the upper border of the fence (with total length $m$);
* $m + 1$ vertical segment of the border.

The total length of all vertical segments before the red board (including its left border) is $l_1 + (l_2 - l_1) + \dots + (l_j - l_{j - 1}) = l_j$. The total length of all vertical segments after the red board (including its right border) is $l_j$ too. So, the perimeter of the fence is $2(m + l_j)$, where $m$ is the number of boards used in constructing the fence, and $l_j$ is the length of the red board.

So, for example, if we want to create a fence that contains a red board with length $L$ and has perimeter $P$, it should contain exactly $\frac{P}{2} - L - 1$ white boards. Now let's solve the problem as follows: iterate on the length of the red board that will be used, and for each $Q_i$ calculate the number of ways to construct a fence with a red board of length $L$ and exactly $\frac{Q_i}{2} - L - 1$ white boards (which are shorter than $L$).

Suppose all white boards shorter than $L$ have distinct lengths. Then for each board, there are three options: not place it at all, place it in the left part (to the left of the red board) or place it in the right part. So, if there are $n$ different white boards shorter than $L$, the number of ways to build a fence with $k$ white boards is ${n}\choose{k}$ $2^k$.

Okay, now let's consider the opposite situation: there is no unique white board; that is, for each length, we have either $0$ boards or at least $2$ boards. Suppose the number of different lengths is $m$. For each length, we can choose whether we place a board of such length in the left side and in the right side. So, the number of ways to build a fence with $k$ white boards is ${2m}\choose{k}$.

And now let's consider the general case. Divide all boards into two categories: "unique" and "non-unique". If we want to build a fence with exactly $k$ white boards, there are $\sum \limits_{i = 0}^{k} $ ${2m}\choose{k - i}$ ${n}\choose{i}$ $ 2^i$ ways to do it. Since we should calculate these values for many different values of $k$, we have to use FFT: we should form two polynomials $\sum\limits_{i = 0}^{n}$ ${n}\choose{i}$ $2^i x^i$ and $\sum\limits_{i = 0}^{2m}$ ${2m}\choose{i}$ $x^i$, and then multiply them. Since the modulo is special, it's better to use NTT.

 **Solution (BledDest)**
```cpp
#include<bits/stdc++.h>

using namespace std;

const int LOGN = 20;
const int N = (1 << LOGN);
const int MOD = 998244353;
const int g = 3;

#define forn(i, n) for(int i = 0; i < int(n); i++)

inline int mul(int a, int b)
{
	return (a * 1ll * b) % MOD;
}

inline int norm(int a) 
{
	while(a >= MOD)
		a -= MOD;
	while(a < 0)
		a += MOD;
	return a;
}

inline int binPow(int a, int k) 
{
	int ans = 1;
	while(k > 0) 
	{
		if(k & 1)
			ans = mul(ans, a);
		a = mul(a, a);
		k >>= 1;
	}
	return ans;
}

inline int inv(int a) 
{
	return binPow(a, MOD - 2);
}

vector<int> w[LOGN];
vector<int> iw[LOGN];
vector<int> rv[LOGN];

void precalc() 
{
	int wb = binPow(g, (MOD - 1) / (1 << LOGN));
	
	for(int st = 0; st < LOGN; st++) 
	{
		w[st].assign(1 << st, 1);
		iw[st].assign(1 << st, 1);
		
		int bw = binPow(wb, 1 << (LOGN - st - 1));
		int ibw = inv(bw);
		
		int cw = 1;
		int icw = 1;
		
		for(int k = 0; k < (1 << st); k++) 
		{
			w[st][k] = cw;
			iw[st][k] = icw;
			
			cw = mul(cw, bw);
			icw = mul(icw, ibw);
		}
		
		rv[st].assign(1 << st, 0);
		
		if(st == 0) 
		{
			rv[st][0] = 0;
			continue;
		}
		int h = (1 << (st - 1));
		for(int k = 0; k < (1 << st); k++)
			rv[st][k] = (rv[st - 1][k & (h - 1)] << 1) | (k >= h);
	}
}

inline void fft(int a[N], int n, int ln, bool inverse) 
{	
	for(int i = 0; i < n; i++) 
	{
		int ni = rv[ln][i];
		if(i < ni)
			swap(a[i], a[ni]);
	}
	
	for(int st = 0; (1 << st) < n; st++) 
	{
		int len = (1 << st);
		for(int k = 0; k < n; k += (len << 1)) 
		{
			for(int pos = k; pos < k + len; pos++) 
			{
				int l = a[pos];
				int r = mul(a[pos + len], (inverse ? iw[st][pos - k] : w[st][pos - k]));
				
				a[pos] = norm(l + r);
				a[pos + len] = norm(l - r);
			}
		}
	}
	
	if(inverse) 
	{
		int in = inv(n);
		for(int i = 0; i < n; i++)
			a[i] = mul(a[i], in);
	}
}

int aa[N], bb[N], cc[N];

inline void multiply(int a[N], int sza, int b[N], int szb, int c[N], int &szc) 
{
	int n = 1, ln = 0;
	while(n < (sza + szb))
		n <<= 1, ln++;
	for(int i = 0; i < n; i++)
		aa[i] = (i < sza ? a[i] : 0);
	for(int i = 0; i < n; i++)
		bb[i] = (i < szb ? b[i] : 0);
		
	fft(aa, n, ln, false);
	fft(bb, n, ln, false);
	
	for(int i = 0; i < n; i++)
		cc[i] = mul(aa[i], bb[i]);
		
	fft(cc, n, ln, true);
	
	szc = n;
	for(int i = 0; i < n; i++)
		c[i] = cc[i];
}

vector<int> T[N];

int a[N];
int b[N];
int n, k;
int ans[N];
int Q[N];
int fact[N];
int rfact[N];

int auxa[N];
int auxb[N];
int auxc[N];

int C(int n, int k)
{
	if(n < 0 || k < 0 || k > n) return 0;
	return mul(fact[n], mul(rfact[k], rfact[n - k]));
}

vector<int> newtonExp(int a, int b, int p)
{
	vector<int> res(p + 1);
	for(int i = 0; i <= p; i++)
		res[i] = mul(C(p, i), mul(binPow(a, i), binPow(b, p - i)));
	return res;
}

int main()
{
	precalc();
	fact[0] = 1;
	for(int i = 1; i < N; i++) fact[i] = mul(fact[i - 1], i);
	for(int i = 0; i < N; i++) rfact[i] = inv(fact[i]);
	
	scanf("%d %d", &n, &k);
	for(int i = 0; i < n; i++) scanf("%d", &a[i]);
	for(int i = 0; i < k; i++) scanf("%d", &b[i]);
	int q;
	scanf("%d", &q);
	for(int i = 0; i < q; i++) scanf("%d", &Q[i]);
	
	map<int, int> cnt;
	for(int i = 0; i < n; i++)
		cnt[a[i]]++;
	
	for(int i = 0; i < k; i++)
	{
		int redL = b[i];
		int cnt1 = 0;
		int cnt2 = 0;
		for(auto x : cnt)
		{
			if(x.first >= redL) 
				break;
			if(x.second == 1)
				cnt1++;
			else
				cnt2++;
		}
		memset(auxa, 0, sizeof auxa);
		memset(auxb, 0, sizeof auxb);
		memset(auxc, 0, sizeof auxc);
		vector<int> p1 = newtonExp(2, 1, cnt1);
		vector<int> p2 = newtonExp(1, 1, cnt2 * 2);
		int sa = p1.size();
		int sb = p2.size();
		int sc;
		for(int j = 0; j < sa; j++)
			auxa[j] = p1[j];
		for(int j = 0; j < sb; j++)
			auxb[j] = p2[j];
		multiply(auxa, sa, auxb, sb, auxc, sc);
		for(int j = 0; j < q; j++)
		{
			int cntW = Q[j] / 2 - redL - 1;
			if(cntW >= 0 && cntW < sc)
				ans[j] = norm(ans[j] + auxc[cntW]);
		}
	}
	
	for(int i = 0; i < q; i++)
		printf("%dn", ans[i]);
}
```
