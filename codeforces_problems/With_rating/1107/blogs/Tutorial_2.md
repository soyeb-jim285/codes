# Tutorial_2

[1107A - Digits Sequence Dividing](../problems/A._Digits_Sequence_Dividing.md "Educational Codeforces Round 59 (Rated for Div. 2)")

 **Tutorial**
### [1107A - Digits Sequence Dividing](../problems/A._Digits_Sequence_Dividing.md "Educational Codeforces Round 59 (Rated for Div. 2)")

The only case when the answer is "NO" — $n=2$ and $s_1 \ge s_2$. Then you cannot divide the initial sequence as needed in the problem. Otherwise you always can divide it into two parts: the first digit of the sequence and the remaining sequence.

 **Solution (Vovuh)**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	int q;
	cin >> q;
	for (int i = 0; i < q; ++i) {
		int n;
		string s;
		cin >> n >> s;
		if (n == 2 && s[0] >= s[1]) {
			cout << "NO" << endl;
		} else {
			cout << "YES" << endl << 2 << endl << s[0] << " " << s.substr(1) << endl;
		}
	}
	
	return 0;
}
```
[1107B - Digital root](../problems/B._Digital_root.md "Educational Codeforces Round 59 (Rated for Div. 2)")

 **Tutorial**
### [1107B - Digital root](../problems/B._Digital_root.md "Educational Codeforces Round 59 (Rated for Div. 2)")

Let's derive the formula $S(x) = (x-1)~mod~9 + 1$ from the digital root properties (that's a known fact but I could only find a link to some russian blog about it). Using that formula, you can easily get that $k$-th number with the digital root of $x$ is $(k-1) \cdot 9 + x$.

 **Solution (Ne0n25)**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		long long k, x;
		cin >> k >> x;
		cout << (k - 1) * 9 + x << endl;
	}
}
```
[1107C - Brutality](../problems/C._Brutality.md "Educational Codeforces Round 59 (Rated for Div. 2)")

 **Tutorial**
### [1107C - Brutality](../problems/C._Brutality.md "Educational Codeforces Round 59 (Rated for Div. 2)")

All you need in this problem is two simple technique: two pointers and sorting. Let's consider maximum by inclusion segments of equal letters in the initial string. Let the current segment be $[l; r]$ and its length is $len = r - l + 1$. If $len < k$ then we can press all buttons and deal all damage corresponding to them. Otherwise it is obviously more profitable to press $k$ best (by damage) buttons. So let's create the array $val$, push all values $a_i$ such that $l \le i \le r$ in this array, sort them, take $min(|val|, k)$ best by damage ($|val|$ is the size of the array $val$) and go to the next segment.

 **Solution (Vovuh)**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	string s;
	cin >> s;
	
	long long ans = 0;
	for (int i = 0; i < n; ++i) {
		int j = i;
		vector<int> vals;
		while (j < n && s[i] == s[j]) {
			vals.push_back(a[j]);
			++j;
		}
		sort(vals.rbegin(), vals.rend());
		ans += accumulate(vals.begin(), vals.begin() + min(k, int(vals.size())), 0ll);
		i = j - 1;
	}
	
	cout << ans << endl;
	
	return 0;
}
```
[1107D - Compression](../problems/D._Compression.md "Educational Codeforces Round 59 (Rated for Div. 2)")

 **Tutorial**
### [1107D - Compression](../problems/D._Compression.md "Educational Codeforces Round 59 (Rated for Div. 2)")

It is very easy to decompress the input (the input was given in the compressed form to make the constraints bigger but less dependent of the time to read the data).

The authors solution is the following:

Let $x$ be the answer to the problem and initially it equals to $n$. Let's iterate over all rows of the matrix and calculate lengths of maximum by inclusion segments consisting only of zeros or only of ones. Let the length of the current segment be $len$. Then let's set $x := gcd(x, len)$, where $gcd$ is the function calculating the greatest common divisor. Then let's do the same for columns of the matrix and print the answer.

How to prove that this solution works?

On the one hand, if some segment of kind $[1 + lx, 1 + (l + 1)x]$, where $l$ is the value from the range $[0; \frac{n}{x} - 1]$, contains different digits then we cannot compress the given matrix.

On the other hand, if the previous condition is true, then we can compress each string by the following algorithm: cut off the first $x$ characters of the string and compress the remaining string recursively. After such compression we obtain the matrix of size $n \times \frac{n}{x}$. And because of the first condition we can compress the remaining matrix again by this algorithm if we apply it to columns instead of rows.

 **Solution (Vovuh)**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int N = 5200;

int n;
bool a[N][N];

void parse_char(int x, int y, char c) {
	int num = -1;
	if (isdigit(c)) {
		num = c - '0';
	} else {
		num = c - 'A' + 10;
	}
	for (int i = 0; i < 4; ++i) {
		a[x][y + 3 - i] = num & 1;
		num >>= 1;
	}
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	
	scanf("%d", &n);
	char buf[N];
	for (int i = 0; i < n; ++i) {
		scanf("%s", buf);
		for (int j = 0; j < n / 4; ++j) {
			parse_char(i, j * 4, buf[j]);
		}
	}
	
	int g = n;
	
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			int k = j;
			while (k < n && a[i][k] == a[i][j]) ++k;
			g = __gcd(g, k - j);
			j = k - 1;
		}
	}
	
	for (int j = 0; j < n; ++j) {
		for (int i = 0; i < n; ++i) {
			int k = i;
			while (k < n && a[k][j] == a[i][j]) ++k;
			g = __gcd(g, k - i);
			i = k - 1;
		}
	}
	
	cout << g << endl;
	
	return 0;
}
```
[1107E - Vasya and Binary String](../problems/E._Vasya_and_Binary_String.md "Educational Codeforces Round 59 (Rated for Div. 2)")

 **Tutorial**
### [1107E - Vasya and Binary String](../problems/E._Vasya_and_Binary_String.md "Educational Codeforces Round 59 (Rated for Div. 2)")

We will solve the problem with dynamic programming. 

Let $ans_{l, r}$ be the answer for substring $s_{l, l + 1, \dots r}$.

If sequence is empty ($l > r$) then $ans_{l, r} = 0$.

Let $dp_{dig, l, r, cnt}$ be the maximum score that we can get if we reduce the substring $s_{l, l + r, \dots r}$ into $cnt$ digits equal to $dig$ with some operations. 

If substring $s_{l, l + r, \dots r}$ does not contain $cnt$ digit $dig$, then $dp_{dig, l, r, cnt} = -10^{18}$.

If $cnt = 0$, then $dp_{dig, l, r, cnt} = ans_{l, r}$.

To calculate $ans_{l, r}$ just fix the sequence of digits that will be deleted last:

$ans_{l, r} = \max\limits_{1 \le cnt \le r - l + 1, 0 \le dig \le 1} a_{cnt} + dp_{dig, l, r, cnt}$.

To calculate $dp_{dig, l, r, cnt}$ just fix the first element $mid$ that is left after working with the substring. Note that $s_{mid}$ must be equal to $dig$.

$dp_{dig, l, r, cnt} = \max\limits_{1 \le mid \le r, s_{mid} = dig} ans_{l, mid - 1} + dp_{dig, mid + 1, r, cnt - 1}$.

All that's left is to transform these formulas into code. Complexity of this solution is $O(n^4)$.

 **Solution (Roms)**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int N = 102;
const long long INF = 1e12;

int n;
string s;
int a[N];

long long ans[N][N];
long long dp[2][N][N][N];

long long calcDp(int c, int l, int r, int cnt);

long long calcAns(int l, int r){
	if(l >= r) return 0;
	long long &res = ans[l][r];
	if(res != -1) return res;

	res = 0;
	for(int cnt = 1; cnt <= r - l; ++cnt){
		res = max(res, calcDp(0, l, r, cnt) + a[cnt - 1]);
		res = max(res, calcDp(1, l, r, cnt) + a[cnt - 1]);
	}

	return res;
}

long long calcDp(int c, int l, int r, int cnt){
	if(cnt == 0) return calcAns(l, r);
	long long &res = dp[c][l][r][cnt];
	if(res != -1) return res;
	
	res = -INF;

	for(int i = l; i < r; ++i){
		if(c == s[i] - '0')
			res = max(res, calcAns(l, i) + calcDp(c, i + 1, r, cnt - 1));
	}

	return res;
}

int main(){
	cin >> n >> s;
	for(int i = 0; i < n; ++i)
		cin >> a[i];

	
	memset(dp, -1, sizeof dp);
	memset(ans, -1, sizeof ans);

	cout << calcAns(0, n) << endl;	

	return 0;
}
```
[1107F - Vasya and Endless Credits](../problems/F._Vasya_and_Endless_Credits.md "Educational Codeforces Round 59 (Rated for Div. 2)")

 **Tutorial**Tutorial is loading... **Solution (Roms)**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int N = 505;
const long long INF = 1e18;

int n;
long long a[N][N];
int up[N], down[N], k[N];
long long u[N], v[N];
int p[N], way[N];

int main(){
	cin >> n;
	for(int i = 0; i < n; ++i)
		cin >> up[i] >> down[i] >> k[i];
	
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j)
			a[i + 1][j + 1] = -(up[j] - min(i, k[j]) * 1LL * down[j]);

	long long res = 0;
	for(int i = 1; i <= n; ++i){
		p[0] = i;
		int j0 = 0;
		vector<long long> minv (n + 1, INF);
		vector<char> used (n + 1, false);
		do{
			used[j0] = true;
			int i0 = p[j0],   j1;
			long long delta = INF;
			for (int j = 1; j <= n; ++j)
				if (!used[j]){
					long long cur = a[i0][j] - u[i0] - v[j];
					if (cur < minv[j])
						minv[j] = cur,  way[j] = j0;
					if (minv[j] < delta)
						delta = minv[j],  j1 = j;
				}
			for (int j = 0; j <= n; ++j)
				if (used[j])
					u[p[j]] += delta,  v[j] -= delta;
				else
					minv[j] -= delta;
			j0 = j1;
		}while (p[j0] != 0);
		do {
			int j1 = way[j0];
			p[j0] = p[j1];
			j0 = j1;
		} while (j0);

		res = max(res, v[0]);
	}

	cout << res << endl;
	return 0;
}
```
[1107G - Vasya and Maximum Profit](../problems/G._Vasya_and_Maximum_Profit.md "Educational Codeforces Round 59 (Rated for Div. 2)")

 **Tutorial**
### [1107G - Vasya and Maximum Profit](../problems/G._Vasya_and_Maximum_Profit.md "Educational Codeforces Round 59 (Rated for Div. 2)")

It is clear that $gap(l, r) \le gap(l, r + 1)$ and $gap(l, r) \le gap(l - 1, r)$.

Sort all indices $2, 3, \dots, n$ with comparator based on the value of $d_i - d_{i-1}$.

Let's consider all indices in the order discussed above and for fixed index $i$ find the best answer among such segments $(l, r)$ that $gap(l, r) \le d_i$, $gap_(l-1, r) > d_i$ and $gap_(l, r+1) > d_i$. Initially, when we consider $gap = 0$, there are $n$ such segments, each containing only one task.

When we consider new index $j$, we need to merge segments $(l, j - 1)$ and $(j, r)$ and update the answer with $best(l, r) - (d_j - d_{j-1})^2$, where $best(l, r)$ is the maximum subsegment in array $a - c_l, a - c_{l+1}, \dots, a - c_r$ (that array represents the profit we get for each task).

We can store and merge such segments with $set$ in C++ or $TreeSet$ in Java.

We can answer queries $best(l, r)$ using the segment tree (we need to process queries of the form "find a subsegment having maximum sum"). Read more about it [here](https://codeforces.com/https://cp-algorithms.com/data_structures/segment_tree.html).

 **Solution (Roms)**
```cpp
#include<bits/stdc++.h>

using namespace std;

const int N = int(3e5) + 99;

struct node{
	long long sum, ans, pref, suf;
	
	node () {}
	node(int x){
		sum = x;
		x = max(x, 0);
		pref = suf = ans = x;
	}
};

node merge(const node &a, const node &b){
	node res;
	res.sum = a.sum + b.sum;
	res.pref = max(a.pref, a.sum + b.pref);
	res.suf = max(b.suf, b.sum + a.suf);
	res.ans = max(max(a.ans, b.ans), a.suf + b.pref);
	return res;
}

int n, x;
pair<int, int> p[N];
node t[N * 4];

void upd(int v, int l, int r, int pos, int x){
	if(r - l == 1){
		assert(pos == l);
		t[v] = node(x);
		return;
	}
	
	int mid = (l + r) / 2;
	if(pos < mid) upd(v * 2 + 1, l, mid, pos, x);
	else upd(v * 2 + 2, mid, r, pos, x);
	
	t[v] = merge(t[v * 2 + 1], t[v * 2 + 2]);
}

node get(int v, int l, int r, int L, int R){
	if(L >= R) return node(0);
	
	if(l == L && r == R)
		return t[v];
	
	int mid = (l + r)/ 2;
	return merge(get(v * 2 + 1, l, mid, L, min(mid, R)),
				 get(v * 2 + 2, mid, r, max(L, mid), R));	
}

int main() {
	scanf("%d %d", &n, &x);
	for(int i = 0; i < n; ++i){
		scanf("%d %d", &p[i].first, &p[i].second);
		p[i].second = x - p[i].second;
	}
	
	sort(p, p + n);
	for(int i = 0; i < n; ++i) upd(0, 0, n, i, p[i].second);
	
	vector <pair<int, int> > v;
	for(int i = 1; i < n; ++i)
		v.emplace_back(p[i].first - p[i - 1].first, i);
	sort(v.begin(), v.end());
	
	long long res = 0;
	set <pair<int, int> > s;
	for(int i = 0; i < n; ++i){
		s.insert(make_pair(i, i + 1));
		res = max(res, 1LL * p[i].second);
	}
	
	int l = 0;
	while(l < v.size()){
		int r = l + 1;
		while(r < v.size() && v[l].first == v[r].first) ++r;
		long long d = v[l].first * 1LL * v[l].first;
		
		for(int i = l; i < r; ++i){
			int id = v[i].second;
			auto it = s.upper_bound(make_pair(id, -1));
			assert(it->first == id);
			assert(it != s.begin());
			auto R = *it;
			--it;
			auto L = *it;
			s.erase(L), s.erase(R);
			L.second = R.second;
			
			auto nd = get(0, 0, n, L.first, L.second);
			res = max(res, nd.ans - d);
			s.insert(L);
		}
		
		l = r;
	}
	
	cout << res << endl;
	return 0;
}
```
