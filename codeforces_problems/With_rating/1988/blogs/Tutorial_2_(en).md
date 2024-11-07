# Tutorial_2_(en)

Thanks for participation!

**Update**: added alternative solutions/proofs for A,B,D,F

[1988A - Split the Multiset](../problems/A._Split_the_Multiset.md "Codeforces Round 958 (Div. 2)")

 **Hint 1**The optimal sequence of operations is very simple.

 **Solution**The optimal sequence of operations is adding k−1 1-s into the set each time, at the same time decreasing n by k−1. This implies that the answer is ⌈n−1k−1⌉.

 **Why?**I failed to find a Div2-A level proof. If you have a simpler proof please share it in the comments.

Consider the number of elements that is ≡1(mod(k−1)) in the set. The number of such elements increase by at most k−1 in each operation, and the aforementioned sequence of operation achieves the maximum increment.

 

---

A simpler proof in the comments: consider the number of elements in the set. It increases by at most k−1 each time, and our construction reaches the maximum increment.

 **Code (python)**
```cpp
t = (int)(input())
for _ in range(t):
    n, k = map(int, input().split())
    print((n - 1 + k - 2) // (k - 1))
```
[1988B - Make Majority](../problems/B._Make_Majority.md "Codeforces Round 958 (Div. 2)")

 **Hint 1**"Most sequences" can be transformed into [1]. Conditions for a sequence to be un-transformable is stringent.

 **Hint 2**Find several simple substrings that make the string transformable.

 **Solution**We list some simple conditions for a string to be transformable:

 * If 111 exists somewhere (as a substring) in the string, the string is always transformable.
* If 11 appears at least twice in the string, the string is always transformable.
* If the string both begins and ends with 1, it is always transformable.
* If the string begins or ends with 1 and 11 exists in the string, it is always transformable.

These can be found by simulating the operation for short strings on paper.

Contrarily, if a string does not meet any of the four items, it is always not transformable. This can be proved using induction (as an exercise).

 **Another Solution**Observe that the number of 1 never increases in an operation. We can change a continuous segment of zeros into one zero. After that, it suffices to check that the number of occurences of 1 is larger than the number of occurences of 0.

 **Code (python)**
```cpp
t = (int)(input())
for _ in range(t):
    n = (int)(input())
    a = input()
    ok = 0
    if a.count("111") >= 1:
        ok = 1
    if a.count("11") >= 2:
        ok = 1
    if a.count("11") >= 1 and (a[0] == "1" or a[-1] == "1"):
        ok = 1
    if a[0] == "1" and a[-1] == "1":
        ok = 1
    if ok:
        print("Yes")
    else:
        print("No")
```
[1988C - Increasing Sequence with Fixed OR](../problems/C._Increasing_Sequence_with_Fixed_OR.md "Codeforces Round 958 (Div. 2)")

 **Hint 1**The answer is a simple construction.

 **Hint 2**The maximum length for 2k−1 (k>1) is k+1.

 **Solution**It's obvious that the answer only depends on the popcount of n. Below, we assume n=2k−1. If k=1, it is shown in the samples that the length is 1.

Otherwise, the maximum sequence length for 2k−1 is k+1. This can be achived by ai=n−2i−1 (1≤i≤k),ak+1=n.

 **Why?**Consider the value of a1. Note that its k-th bit (indexed from 20 to 2k−1) should be 0, otherwise we would not make use of the largest bit.

Since a1 and a2's OR is n, a2's k-th bit should be 1, and thus the construction of a2∼ak+1 boils down to the subproblem when n=2k−1−1. This shows that f(k)≤f(k−1)+1 where k is the popcount of n and f(k) is the maximum sequence length. We know that f(2)=3, so f(k)≤k+1 for all k≥2.

 **Code (python)**
```cpp
t = (int)(input())
for _ in range(t):
    n = (int)(input())
    a = []
    for i in range(62, -1, -1):
        x = 1 << i
        if ((x & n) == x) and (x != n):
            a.append(n - x)
    a.append(n)
    print(len(a))
    for i in a:
        print(i, end=" ")
    print("")
```
[1988D - The Omnipotent Monster Killer](../problems/D._The_Omnipotent_Monster_Killer.md "Codeforces Round 958 (Div. 2)")

 **Hint 1**Formulate the problem.

 **Hint 2**Some variables can't be large.

 **Solution**Suppose monster i is killed in round bi. Then, the total health decrement is the sum of ai×bi. The "independent set" constraint means that for adjacent vertices, their b-s must be different.

**Observation: bi does not exceed ⌊log2n⌋+1**. In this problem, bi≤19 always holds for at least one optimal ai.

 **Proof**Let the mex of a set be the smallest positive integer that does not appear in it. Note that in an optimal arrangement, bi=mex(j,i)∈Ebj.

Consider an vertex with the maximum b, equal to u. Root the tree at this vertex x. The vertices connected with x should take all b-s from 1 to u−1. Denote f(u) as the minimum number of vertices to make this happen, we have

 f(1)=1, f(u)≥1+∑1≤i<uf(i)→f(u)≥2u−1This ends the proof.

By dp, we can find the answer in O(nlogn) or O(nlog2n), depending on whether you use prefix/suffix maximums to optimize the taking max part.

**Bonus**: Find a counterexample for bi≤18 when n=300000. (Pretest 2 is one case)

 **Another Solution**Note that bx≤degx. By carefully handing the dp transitions, we can achieve a O(∑degx)=O(n) solution.

 **Code (C++)**
```cpp
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll a[300005], f[300005][24], smn[30];
vector<int> g[300005];
void dfs(int x, int fa) {
	for (int i = 1; i <= 22; i++) f[x][i] = i * a[x];
	for (int y : g[x]) {
		if (y == fa) continue;
		dfs(y, x);
		ll tt = 8e18;
		smn[23] = 8e18;
		for (int i = 22; i >= 1; i--) {
			smn[i] = min(smn[i + 1], f[y][i]);
		}
		for (int i = 1; i <= 22; i++) {
			f[x][i] += min(tt, smn[i + 1]);
			tt = min(tt, f[y][i]);
		}
	}
}
void Solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1, x, y; i < n; i++) {
		cin >> x >> y;
		g[x].push_back(y), g[y].push_back(x);
	}
	dfs(1, 0);
	cout << *min_element(f[1] + 1, f[1] + 23) << 'n';
	for (int i = 1; i <= n; i++) {
		g[i].clear();
		memset(f[i], 0, sizeof(f[i]));
	}
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int t;
	cin >> t;
	while (t--) Solve();
}
```
[1988E - Range Minimum Sum](../problems/E._Range_Minimum_Sum.md "Codeforces Round 958 (Div. 2)")

 **Hint 1**Formulate the problem on a cartesian tree.

 **Hint 2**Find a clever bruteforce. Calculate the time complexity carefully.

 **Solution**Build the cartesian tree of a. Let lcx,rcx respectively be x's left and right children.

Consider a vertex x. If we delete it, what would happen to the tree? Vertices that are on the outside of x's subtree will not be affected. Vertices inside the subtree of x will "merge". Actually, we can see that, only the right chain of x's left child (lcx→rclcx→rcrclcx→…) and the left chain of x's right child will merge in a way like what we do in mergesort.

Now, if we merge the chains by bruteforce (use sorting or std::merge), the time complexity is O(n)! It's easy to see that each vertex will only be considered O(1) times.

 **Code (C++)**
```cpp
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pr;
int n, a[500005], st[500005], c[500005][2], top, sz[500005];
ll ans[500005], atv[500005], sum;
void dfs1(int x) {
	sz[x] = 1;
	for (int i = 0; i < 2; i++)
		if (c[x][i]) dfs1(c[x][i]), sz[x] += sz[c[x][i]];
	sum += (atv[x] = (sz[c[x][0]] + 1ll) * (sz[c[x][1]] + 1ll) * a[x]);
}
void dfs2(int x, ll dlt) {
	ll val = sum - dlt - atv[x];
	vector<int> lr, rl;
	vector<pr> ve;
	int y = c[x][0];
	while (y) lr.push_back(y), val -= atv[y], y = c[y][1];
	y = c[x][1];
	while (y) rl.push_back(y), val -= atv[y], y = c[y][0];
	{
		int i = 0, j = 0;
		while (i < lr.size() || j < rl.size()) {
			if (j >= rl.size() || (i < lr.size() && j < rl.size() && a[lr[i]] < a[rl[j]])) {
				ve.push_back(pr(lr[i], 0));
				i++;
			} else {
				ve.push_back(pr(rl[j], 1));
				j++;
			}
		}
	}
	// cout << x << ' ' << val << 'n';
	int cursz = 0;
	for (int i = (int)ve.size() - 1; i >= 0; i--) {
		int p = ve[i].first, q = ve[i].second;
		// cout << "I:" << i << ' ' << cursz << 'n';
		val += (cursz + 1ll) * (sz[c[p][q]] + 1ll) * a[p];
		cursz += sz[c[p][q]] + 1;
	}
	ans[x] = val;
	for (int i = 0; i < 2; i++)
		if (c[x][i]) dfs2(c[x][i], dlt + 1ll * (sz[c[x][i ^ 1]] + 1) * a[x]);
}
void Solve() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	st[top = 0] = 0;
	for (int i = 1; i <= n; i++) {
		while (top && a[st[top]] > a[i]) top--;
		c[i][0] = c[st[top]][1], c[st[top]][1] = i;
		st[++top] = i;
	}
	int rt = st[1];
	sum = 0, dfs1(rt), dfs2(rt, 0);
	for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
	cout << 'n';
	for (int i = 0; i <= n; i++) c[i][0] = c[i][1] = 0;
}
int main() {
	int t;
	scanf("%d", &t);
	while (t--) Solve();
}
```
[1988F - Heartbeat](../problems/F._Heartbeat.md "Codeforces Round 958 (Div. 2)")

 **Solution**We can use dp to calculate the number of permutations of 1∼n with i prefix maximums and j ascents, f(n,i,j): consider where 1 is inserted, we will have a O(n3) dp that finds f(n,i,j) for all suitable (n,i,j)-s.

For suffix maximums, (the number of permutations of 1∼n with i prefix maximums and j ascents, g(n,i,j), we can just reverse some dimension of f).

To calculate the answer, consider the position of n. Suppose it's p. The the answer is

 ∑np=1∑p−1i=0∑n−pj=0∑p−1x=0∑n−py=0f(p−1,i,x)g(n−p,j,y)(n−1p−1)ai+1bj+1cx+y+[p>1]Let u(x,y)=∑if(x,i,y)ai+1, v(x,y)=∑zg(x,i,y)bi+1 (both of these are calculated in O(n3)), then the answer is

 ∑np=1∑p−1x=0∑n−py=0u(p−1,x)v(n−p,y)(n−1p−1)cx+y+[p>1]By seeing u and v as 2D polynomials, this can be calculated with 2D FFT in O(n2logn).

 **I don't know what FFT is, can I also solve the problem?**Of course! This problem can also be solved with modulo 109+7 or on an algebraic structure where FFT is not easy, but interpolation can be successfully carried out.

We still need to consider u(p−1,∗) and v(n−p,∗) as polynomials ∑iu(p−1,i)xi,∑iv(n−p,i)xi. Instead of doing FFT, consider substitute x with 0,1,…,n+1, and use interpolation to recover the final coefficients.

Suppose we have a value of x. Then, calculating u(p−1) and v(n−p) takes O(n2) in total. For fixed x and n, the answer for n is (here, note how x is multiplied)

 ∑np=1u(p−1)v(n−p)(n−1p−1)xp>1This also takes O(n2) in total. So, for each x, the calculation is O(n2).

For each n, the naive implementation of interpolation runs in O(n2). After we recover the coefficients, we multiply it with c and update the answer.

So, the time complexity is O(n3).

 **An even easier solution, found by jiangly**We are trying to iterate over i,x,j,y and do ansi+j←f(i,x)g(j,y)hx+y. We can achieve this with two steps: first, iterate over i,x,y and do vi,y←f(i,x)hx+y. Then, iterate over i,j,y and do ansi+j←g(j,y)vi,y.

This runs in O(n3), and does not need to calculate inverses, and thus can be carried out on any ring.

 **Code (C++, FFT)**
```cpp
#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int Power(int x, int y) {
	int r = 1;
	while (y) {
		if (y & 1) r = 1ll * r * x % mod;
		x = 1ll * x * x % mod, y >>= 1;
	}
	return r;
}
namespace Conv_998244353 {

const int g = 3, invg = ((mod + 1) % 3 == 0 ? (mod + 1) / 3 : (2 * mod + 1) / 3);
int wk[1050005], ta[1050005], tb[1050005];
void DFT(int *a, int n) {
	for (int i = n >> 1; i; i >>= 1) {
		int w = Power(g, (mod - 1) / (i << 1));
		wk[0] = 1;
		for (int j = 1; j < i; j++) wk[j] = 1ll * wk[j - 1] * w % mod;
		for (int j = 0; j < n; j += (i << 1)) {
			for (int k = 0; k < i; k++) {
				int x = a[j + k], y = a[i + j + k], z = x;
				x += y, (x >= mod && (x -= mod)), a[j + k] = x;
				z -= y, (z < 0 && (z += mod)), a[i + j + k] = 1ll * z * wk[k] % mod;
			}
		}
	}
}
void IDFT(int *a, int n) {
	for (int i = 1; i < n; i <<= 1) {
		int w = Power(invg, (mod - 1) / (i << 1));
		wk[0] = 1;
		for (int j = 1; j < i; j++) wk[j] = 1ll * wk[j - 1] * w % mod;
		for (int j = 0; j < n; j += (i << 1)) {
			for (int k = 0; k < i; k++) {
				int x = a[j + k], y = 1ll * a[i + j + k] * wk[k] % mod, z = x;
				x += y, (x >= mod && (x -= mod)), a[j + k] = x;
				z -= y, (z < 0 && (z += mod)), a[i + j + k] = z;
			}
		}
	}
	for (int i = 0, inv = Power(n, mod - 2); i < n; i++) a[i] = 1ll * a[i] * inv % mod;
}
vector<int> conv(vector<int> A, vector<int> B) {
	for (auto &i : A) i %= mod;
	for (auto &i : B) i %= mod;
	int sa = A.size(), sb = B.size();
	vector<int> ret(sa + sb - 1);
	int len = 1;
	while (len < ret.size()) len <<= 1;
	for (int i = 0; i < len; i++) ta[i] = tb[i] = 0;
	for (int i = 0; i < sa; i++) ta[i] = A[i];
	for (int i = 0; i < sb; i++) tb[i] = B[i];
	DFT(ta, len), DFT(tb, len);
	for (int i = 0; i < len; i++) ta[i] = 1ll * ta[i] * tb[i] % mod;
	IDFT(ta, len);
	for (int i = 0; i < ret.size(); i++) ret[i] = ta[i];
	return ret;
}

} // namespace Conv_998244353
vector<int> conv(vector<int> A, vector<int> B) {
	return Conv_998244353::conv(A, B);
}
int n, a[705], b[705], c[705], f[705][705], u[705][705], v[705][705];
int ny[705], jc[705];
void upd(int &x, int y) { x += y, (x >= mod && (x -= mod)); }
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cin >> b[i];
	for (int i = 0; i < n; i++) cin >> c[i];
	f[0][0] = jc[0] = ny[0] = 1;
	for (int i = 1; i <= n; i++) {
		jc[i] = 1ll * jc[i - 1] * i % mod, ny[i] = Power(jc[i], mod - 2);
	}
	vector<int> A(500000), B(500000);
	for (int i = 0; i <= n; i++) {
		for (int j = i; j >= 0; j--) {
			for (int k = i; k >= 0; k--) {
				if (!f[j][k]) continue;
				// cout << i << ' ' << j << ' ' << k << ' ' << f[j][k] << 'n';
				upd(u[i][k], 1ll * f[j][k] * a[j + 1] % mod);
				upd(v[i][k], 1ll * f[j][k] * b[j + 1] % mod);
				upd(f[j + 1][k + (i != 0)], f[j][k]);
				upd(f[j][k + 1], 1ll * f[j][k] * (i - (i != 0) - k) % mod);
				f[j][k] = 1ll * f[j][k] * (k + (i != 0)) % mod;
			}
		}
		if (i > 0) reverse(v[i], v[i] + i);
		for (int j = 0; j <= i; j++) {
			if (i) A[703 * i + j] = 1ll * u[i][j] * ny[i] % mod;
			B[703 * i + j] = 1ll * v[i][j] * ny[i] % mod;
		}
	}
	A = conv(A, B);
	for (int i = 1; i <= n; i++) {
		int ans = 0;
		for (int y = 0; y <= i - 1; y++) {
			ans = (ans + 1ll * u[0][0] * v[i - 1][y] % mod * c[y]) % mod;
		}
		for (int j = 0; j < i; j++) {
			ans = (ans + 1ll * A[703 * (i - 1) + j] * jc[i - 1] % mod * c[j + 1]) % mod;
		}
		cout << ans << ' ';
	}
}
```
 **Code (C++, Interpolation)**
```cpp
#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353, N = 705;
int n, a[N + 5], b[N + 5], c[N + 5], f[N + 5][N + 5], u[N + 5][N + 5], v[N + 5][N + 5],
    C[N + 5][N + 5];
int g[N + 5], h[N + 5], t[N + 5][N + 5], p[N + 5][N + 5], ny[N + 5], o[N + 5];
void upd(int &x, int y) { x += y, (x >= mod && (x -= mod)); }
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cin >> b[i];
	for (int i = 0; i < n; i++) cin >> c[i];
	f[0][0] = ny[1] = ny[0] = 1;
	for (int i = 0; i <= n; i++) {
		C[i][0] = 1;
		for (int j = 1; j <= i; j++) C[i][j] = (C[i &mdash; 1][j] + C[i &mdash; 1][j &mdash; 1]) % mod;
	}
	for (int i = 2; i <= n; i++) ny[i] = 1ll * ny[mod % i] * (mod &mdash; mod / i) % mod;
	for (int i = 2; i <= n; i++) ny[i] = 1ll * ny[i &mdash; 1] * ny[i] % mod;
	for (int i = 0; i < n; i++) {
		for (int j = i; j >= 0; j--) {
			for (int k = i; k >= 0; k--) {
				if (!f[j][k]) continue;
				// cout << i << ' ' << j << ' ' << k << ' ' << f[j][k] << 'n';
				upd(u[i][k], 1ll * f[j][k] * a[j + 1] % mod);
				upd(v[i][k], 1ll * f[j][k] * b[j + 1] % mod);
				upd(f[j + 1][k + (i != 0)], f[j][k]);
				upd(f[j][k + 1], 1ll * f[j][k] * (i &mdash; (i != 0) &mdash; k) % mod);
				f[j][k] = 1ll * f[j][k] * (k + (i != 0)) % mod;
			}
		}
		if (i > 0) reverse(v[i], v[i] + i);
	}
	for (int x = 1; x <= n; x++) {
		for (int i = 0; i < n; i++) {
			g[i] = h[i] = 0;
			for (int j = i; j >= 0; j--) {
				g[i] = (1ll * g[i] * x + u[i][j]) % mod;
				h[i] = (1ll * h[i] * x + v[i][j]) % mod;
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= i; j++) {
				upd(t[i][x], 1ll * g[j &mdash; 1] * h[i &mdash; j] % mod * C[i &mdash; 1][j &mdash; 1] % mod *
				                 (j > 1 ? x : 1) % mod);
			}
		}
	}
	p[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < i; j++) p[i][j] = p[0][j], o[j] = 0;
		for (int j = 0; j <= i; j++) {
			if (j != i) {
				for (int k = i &mdash; 1; k >= 0; k--) {
					upd(p[j][k + 1], p[j][k]);
					p[j][k] = 1ll * p[j][k] * (mod &mdash; i) % mod;
				}
			}
			if (!j) continue;
			int s = 1ll * t[i][j] * ny[j &mdash; 1] % mod * ny[i &mdash; j] % mod;
			if ((i &mdash; j) & 1) s = mod &mdash; s;
			for (int k = 0; k < i; k++) {
				upd(o[k], 1ll * s * p[j][k] % mod);
			}
		}
		int ans = 0;
		for (int k = 0; k < i; k++) {
			ans = (ans + 1ll * o[k] * c[k]) % mod;
		}
		cout << ans << ' ';
	}
}
```
