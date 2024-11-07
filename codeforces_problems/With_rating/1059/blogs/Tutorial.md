# Tutorial

[1059A - Cashier](../problems/A._Cashier.md "Codeforces Round 514 (Div. 2)")

 **Tutorial**
### [1059A - Cashier](../problems/A._Cashier.md "Codeforces Round 514 (Div. 2)")

There are only $n + 1$ possible segments of time when Vasya can take breaks: between the consecutive clients, before the first client, and after the last client. If the length of the $i$-th such segment is $s$, Vasya may take at most $\left \lfloor \frac{s}{a}\right\rfloor$ breaks, so we just sum those values over the $n + 1$ possible segments. Time complexity is $O(n)$.

 **Code**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 5;

int n, L, a;
int t[maxn], l[maxn];

int main(){
	scanf("%d%d%d", &n, &L, &a);
	for(int i = 0; i < n; i++){
		scanf("%d%d", &t[i], &l[i]);
	}
	int start = 0;
	int ans = 0;
	for(int i = 0; i < n; i++){
		ans += (t[i] - start)/a;
		start = t[i] + l[i];
	}
	ans += (L - start)/a;
	printf("%d", ans);
	return 0;
}
```
[1059B - Forgery](../problems/B._Forgery.md "Codeforces Round 514 (Div. 2)")

 **Tutorial**
### [1059B - Forgery](../problems/B._Forgery.md "Codeforces Round 514 (Div. 2)")

Each empty cell forbids to put a pen into every neighbor. Also, the border of the grid is forbidden. Let's mark all the forbidden cells. Now we have to check if for each filled cell there is at least one non-forbidden neighbor. Time complexity is $O(nm)$.

 **Code**
```cpp
#include<bits/stdc++.h>

using namespace std;

const int maxn = (int)1e3 + 3;

int n, m;
char a[maxn][maxn];
bool can[maxn][maxn];
vector<int> must_have[maxn][maxn];

inline bool inside(int x, int y){
	return x >= 0 && y >= 0 && x < n && y < m;
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			can[i][j] = true;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++){
			do{
				a[i][j] = getc(stdin);
			}while(a[i][j] != '.' && a[i][j] != '#');
			for(int dx = -1; dx <= 1; dx++)
				for(int dy = -1; dy <= 1; dy++){
					if(abs(dx) + abs(dy) == 0 || !inside(i + dx, j + dy))continue;
					if(a[i][j] == '.')can[i + dx][j + dy] = false;
					else if (i + dx != 0 && j + dy != 0 && i + dx != n - 1 && j + dy != m - 1)must_have[i][j].push_back((i + dx) * m + j + dy);
				}
		}
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++){
			bool good = false;
			if(a[i][j] == '.')continue;
			for(int cand : must_have[i][j]){
				int x = cand/m, y = cand%m;
				good |= can[x][y];
			}
			if(!good){printf("NO"); return 0;}
		}
	printf("YES");
	return 0;
}
```
[1059C - Sequence Transformation](../problems/C._Sequence_Transformation.md "Codeforces Round 514 (Div. 2)")

 **Tutorial**
### [1059C - Sequence Transformation](../problems/C._Sequence_Transformation.md "Codeforces Round 514 (Div. 2)")

The answers for $n \le 3$ are given in the samples. Now suppose that $n \ge 4$. The maximum result must have the earliest appearance of an integer different from $1$. If $n \ge 4$, the earliest integer that may appear is $2$. So initially we must remove all odd integers and for each of them append $1$ to the answer. But now the rest of the answer is simply the answer for $\left\lfloor\frac{n}{2}\right\rfloor$ multiplied by $2$. That gives us an $O(n)$ solution.

 **Code**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6 + 6;

int seq[maxn];
int ans[maxn];
int ptr = 0;

void solve(int n, int mul){
	if(n == 1){ans[ptr++] = mul; return;}
	if(n == 2){ans[ptr++] = mul; ans[ptr++] = mul * 2; return;}
	if(n == 3){ans[ptr++] = mul; ans[ptr++] = mul; ans[ptr++] = mul * 3; return;}
	for(int i = 0; i < n; i++)if(seq[i]&1)ans[ptr++] = mul;
	for(int i = 0; i < n/2; i++)seq[i] = seq[2*i + 1]/2;
	solve(n/2, mul * 2);
}

int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)seq[i] = i + 1;
	solve(n, 1);
	for(int i = 0; i < n; i++)printf("%d ", ans[i]);
	return 0;
}
```
[1059D - Nature Reserve](../problems/D._Nature_Reserve.md "Codeforces Round 514 (Div. 2)")

 **Tutorial**
### [1059D - Nature Reserve](../problems/D._Nature_Reserve.md "Codeforces Round 514 (Div. 2)")

If there are both positive and negative $y_i$, the answer is $-1$. Now assume that $y_i > 0$. Key observation: the answer can be binary searched. How to check if there is a valid circle with radius $R$? Firstly, the center of such circle is on the line $y = R$. Every point must be not farther than $R$ from the center. It means that the center is inside or on the boundary of all circles $(p_i, R)$. The intersection of every such circle with $y = R$ creates a segment (possibly empty). If the intersection of all such segments is non-empty, there exists some valid circle. Total complexity is $O(n\log C)$. There is also an $O(n\log n)$ solution, but it's much harder to implement.

 **Code**
```cpp
#include<bits/stdc++.h>

using namespace std;

typedef long double dbl;

const dbl eps = 1e-9;

inline bool gt(const dbl & x, const dbl & y){
	return x > y + eps;
}

inline bool lt(const dbl & x, const dbl & y){
	return y > x + eps;
}

inline dbl safe_sqrt(const dbl & D){
	return D < 0 ? 0 : sqrt(D);
}

struct pt{
	dbl x, y;
	pt(){}
	pt(dbl a, dbl b):x(a), y(b){}
};


const int N = 1e5 + 5;
const int STEPS = 150;

int n;
pt p[N];

inline bool can(dbl R){
	dbl l = -1e16 - 1, r = 1e16 + 1;
	for(int i = 0; i < n; i++){
		dbl b = -2 * p[i].x;
		dbl c = p[i].x * p[i].x + p[i].y * p[i].y - 2 * p[i].y * R;
		dbl D = b * b - 4 * c;
		if(lt(D, 0))
			return false;
		D = safe_sqrt(D);
		dbl x1 = p[i].x - D/2, x2 = p[i].x + D/2;
		l = max(l, x1);
		r = min(r, x2);
	}
	return !gt(l, r);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	bool has_positive = false, has_negative = false;
	for(int i = 0; i < n; i++){
		int x, y;
		cin >> x >> y;
		p[i] = pt(x, y);
		if(y > 0)has_positive = true;
		else has_negative = true;
	}
	if(has_positive && has_negative){
		cout << -1 << endl;
		return 0;
	}
	if(has_negative){
		for(int i = 0; i < n; i++)
			p[i].y = -p[i].y;
	}
	dbl L = 0, R = 1e16;
	std::function<dbl(dbl, dbl)> get_mid;
	if(can(1)){
		R = 1;
		get_mid = [](dbl l, dbl r){return (l + r)/2.0;};
	}
	else{
		L = 1;
		get_mid = [](dbl l, dbl r){return sqrt(l * r);};
	}
	for(int step = 0; step < STEPS; step++){
		dbl mid = get_mid(L, R);
		if(can(mid))
			R = mid;
		else
			L = mid;
	}
	cout.precision(16);
	cout << fixed << get_mid(L, R) << endl;
}
```
[1059E - Split the Tree](../problems/E._Split_the_Tree.md "Codeforces Round 514 (Div. 2)")

 **Tutorial**
### [1059E - Split the Tree](../problems/E._Split_the_Tree.md "Codeforces Round 514 (Div. 2)")

There are two solutions. Both of them find the answer for each subtree in dfs: firstly for children, then for the vertex itself. In both solutions, we firstly calculate for each vertex how far up a vertical path starting at this vertex may go. It can be done with binary lifting in $O(n\log n)$.

Now let's describe the first solution. Let $dp_i$ be the answer for the subtree of the $i$-th vertex. Let $dp\\_sum_i$ be the sum of $dp_j$ where $j$ is a child of $i$. Suppose we want to include the $i$-th vertex in the path starting at some vertex $j$. Let $\{v_k\}$ be the set of vertices on the path between $i$ and $j$. Then the answer for $i$ in this case equals $1 + \sum\limits_{v_k} (dp\\_sum_{v_k} - dp_{v_k})$ (if we assume that initially $dp_i = 0$). So we need to calculate the minimum such value for all $j$ in the subtree of $i$, for which we can create a path from $j$ to $i$. Let's build a segment tree over the Euler tour of the tree. After processing vertex $i$, we add $dp\\_sum_i - dp_i$ on the segment that corresponds to the subtree of $i$. If after processing the vertex there are some vertices in it's subtree, for which there can be a vertical path to $i$, but there cannot be a vertical path to $p_i$, we set the value at the corresponding position in the Euler tour to $\infty$.

The second solution is much simpler. When calculating the answers, in case of tie let's choose the answer where the path going through the root of the subtree may go further. Then the answers can be updated greedily.

Both solutions work in $O(n \log n)$.

 **Code (first solution)**
```cpp
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 1e5 + 5;
const int lg = 20;
const ll inf = 1e18;

int n, L;
ll S;
ll t[4 * maxn];
ll t_add[4 * maxn];
int cid = 0;
int w[maxn];
vector<int> down[maxn];
ll sum[maxn];
int up[maxn];
int p[maxn][lg];
ll dp[maxn];
int id[maxn], rb[maxn];
ll dp_sum[maxn];
vector<int> rm[maxn];

inline ll get_sum(int v){
	return v == -1 ? 0 : sum[v];
}

void preprocess(int v, int pr = -1){
	sum[v] = get_sum(pr) + w[v];
	p[v][0] = pr;
	up[v] = v;
	id[v] = rb[v] = cid++;
	for(int i = 1; i < lg; i++)
		p[v][i] = p[v][i - 1] == -1 ? -1 : p[p[v][i - 1]][i - 1];
	int dist = L - 1;
	for(int i = lg - 1; i >= 0; i--){
		if(p[up[v]][i] == -1 || (1<<i) > dist)continue;
		if(get_sum(v) - get_sum(p[up[v]][i]) + w[p[up[v]][i]] <= S){
			dist -= 1<<i;
			up[v] = p[up[v]][i];
		}
	}
	rm[up[v]].push_back(v);
	for(int u : down[v]){
		preprocess(u, v);
		rb[v] = max(rb[v], rb[u]);
	}
}

inline void push(int v){
	t[2*v] += t_add[v];
	t[2*v + 1] += t_add[v];
	t_add[2*v] += t_add[v];
	t_add[2*v + 1] += t_add[v];
	t_add[v] = 0;
}

void build_tree(int v, int l, int r){
	t[v] = inf;
	if(l == r)
		return;
	int mid = (l + r)/2;
	build_tree(2*v, l, mid);
	build_tree(2*v + 1, mid + 1, r);
}

ll get_tree(int v, int l, int r, int ul, int ur){
	if(ul > ur)
		return inf;
	if(l == ul && r == ur)
		return t[v];
	push(v);
	int mid = (l + r)/2;
	return min(get_tree(2*v, l, mid, ul, min(ur, mid)), get_tree(2*v + 1, mid + 1, r, max(ul, mid + 1), ur));
}

void set_tree(int v, int l, int r, int pos, ll val){
	if(l == r){
		t[v] = val;
		return;
	}
	push(v);
	int mid = (l + r)/2;
	if(pos <= mid)
		set_tree(2*v, l, mid, pos, val);
	else
		set_tree(2*v + 1, mid + 1, r, pos, val);
	t[v] = min(t[2*v], t[2*v + 1]);
}

void add_tree(int v, int l, int r, int ul, int ur, ll val){
	if(ul > ur)return;
	if(l == ul && r == ur){
		t[v] += val;
		t_add[v] += val;
		return;
	}
	push(v);
	int mid = (l + r)/2;
	add_tree(2*v, l, mid, ul, min(ur, mid), val);
	add_tree(2*v + 1, mid + 1, r, max(ul, mid + 1), ur, val);
	t[v] = min(t[2*v], t[2*v + 1]);
}

inline void upd(int v){
	dp[v] = 1 + get_tree(1, 0, n - 1, id[v], rb[v]);
}

inline void add(int v){
	set_tree(1, 0, n - 1, id[v], 0);
	add_tree(1, 0, n - 1, id[v], rb[v], dp_sum[v] - dp[v]);
}

inline void remove(int v){
	set_tree(1, 0, n - 1, id[v], inf);
}

void solve(int v){
	for(int u : down[v]){
		solve(u);
		dp_sum[v] += dp[u];
	}
	add(v);
	dp[v] = maxn;
	upd(v);
	add_tree(1, 0, n - 1, id[v], rb[v], -dp[v]);
	for(int u : rm[v])
		remove(u);
}

int main(){
	scanf("%d%d%lld", &n, &L, &S);
	for(int i = 0; i < n; i++){
		scanf("%d", &w[i]);
		if(w[i] > S){printf("-1"); return 0;}
	}
	for(int i = 1; i < n; i++){
		int j;
		scanf("%d", &j);
		down[--j].push_back(i);
	}
	preprocess(0);
	build_tree(1, 0, n - 1);
	solve(0);
	printf("%lld", dp[0]);
}
```
 **Code (second solution)**
```cpp
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 1e5 + 5;
const int lg = 20;
const ll inf = 1e18;

int n, L;
ll S;
int w[maxn];
vector<int> down[maxn];
ll sum[maxn];
int up[maxn];
int h[maxn];
int p[maxn][lg];
int path[maxn];

inline ll get_sum(int v){
	return v == -1 ? 0 : sum[v];
}

void preprocess(int v, int pr = -1){
	sum[v] = get_sum(pr) + w[v];
	p[v][0] = pr;
	h[v] = pr == -1 ? 0 : (1 + h[pr]);
	up[v] = v;
	for(int i = 1; i < lg; i++)
		p[v][i] = p[v][i - 1] == -1 ? -1 : p[p[v][i - 1]][i - 1];
	int dist = L - 1;
	for(int i = lg - 1; i >= 0; i--){
		if(p[up[v]][i] == -1 || (1<<i) > dist)continue;
		if(get_sum(v) - get_sum(p[up[v]][i]) + w[p[up[v]][i]] <= S){
			dist -= 1<<i;
			up[v] = p[up[v]][i];
		}
	}
	for(int u : down[v]){
		preprocess(u, v);
	}
}

int solve(int v){
	int ans = 0;
	int best = -1;
	for(int u : down[v]){
		ans += solve(u);
		if(path[u] == u)continue;
		if(best == -1 || h[best] > h[path[u]])
			best = path[u];
	}
	if(best == -1){
		best = up[v];
		++ans;
	}
	path[v] = best;
	return ans;
}

int main(){
	scanf("%d%d%lld", &n, &L, &S);
	for(int i = 0; i < n; i++){
		scanf("%d", &w[i]);
		if(w[i] > S){printf("-1"); return 0;}
	}
	for(int i = 1; i < n; i++){
		int j;
		scanf("%d", &j);
		down[--j].push_back(i);
	}
	preprocess(0);
	printf("%d", solve(0));
}
```
