# Tutorial_(en)

[1156A - Inscribed Figures](../problems/A._Inscribed_Figures.md "Educational Codeforces Round 64 (Rated for Div. 2)")

 **Tutorial**
### [1156A - Inscribed Figures](../problems/A._Inscribed_Figures.md "Educational Codeforces Round 64 (Rated for Div. 2)")

Firstly, let's find out when the answer is infinite.

Obviously, any point of intersection is produced by at least a pair of consecutive figures. Take a look at every possible pair and you'll see that only square inscribed in triangle and vice verse produce infinite number of points in intersection. The other cases are finite.

From now we assume that initial sequence has no 2 and 3 next to each other. Basically, it's all triangles and squares separated by circles.

If the task was to count all pairs of intersecting figures, the solution will be the following. Square next to circle gives 4 points, triangle next to circle gives 3 points.

Unfortunately, the task asked for distinct points. Notice that there is a single subsegment which can produce coinciding points (square $\rightarrow$ circle $\rightarrow$ triangle). So you have to find each triplet (3 1 2) and subtract their count from the sum.

Overall complexity: $O(n)$.

 **Solution (PikMike)**
```cpp
#include <bits/stdc++.h>

#define forn(i, n) for(int i = 0; i < int(n); i++) 

using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	int sum = 0;
	int lst = 1;
	vector<int> figs;
	forn(i, n){
		int x;
		scanf("%d", &x);
		if (lst != 1 && x != 1){
			puts("Infinite");
			return 0;
		}
		if (x != 1){
			figs.push_back(x);
			sum += x + 1;
			if (i != 0 && i != n - 1)
				sum += x + 1;
		}
		lst = x;
	}
	forn(i, int(figs.size()) - 1) if (figs[i] == 3 && figs[i + 1] == 2)
		--sum;
	printf("Finiten%dn", sum);
}
```
[1156B - Ugly Pairs](../problems/B._Ugly_Pairs.md "Educational Codeforces Round 64 (Rated for Div. 2)")

 **Tutorial**
### [1156B - Ugly Pairs](../problems/B._Ugly_Pairs.md "Educational Codeforces Round 64 (Rated for Div. 2)")

To be honest, the solution to this problem is easier to code than to prove.

Let's follow the next strategy. Write down all the letters of the string which have odd positions in alphabet ("aceg$\dots$") and even positions in alphabet ("bdfi$\dots$"). Sort both of these lists in non-decreasing order. The answer is either concatenation of the lists (odd + even or even + odd) or "No answer".

Now for the proof part. Let's establish that we don't care about equal letters and leave just a single copy of each letter of the string. Let's check some cases:

1. There is just a single letter. That's trivial.
2. There are two letters of the same parity. There is no incorrect arrangement for this.
3. There are two letters of different parity. If they differ by one then no answer exists. Otherwise any arrangement works.
4. There are three letters and they are consecutive in alphabet. No answer exists.
5. There are other types of three letters. Then the one of the different parity can put on the side (e.g. "acd" and "dac"). As the difference between at least one of these letters and that one isn't 1, that arrangement will be ok.
6. Finally, there are at least 4 letters. It means that the difference between either the smallest odd and the largest even or between the smallest even and the largest odd isn't 1.

The only thing you need to do is to implement the check function the most straightforward way possible and check both arrangements.

Overall complexity: $O(n \log n)$.

 **Solution (PikMike)**
```cpp
#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

bool check(string s){
	bool ok = true;
	forn(i, int(s.size()) - 1)
		ok &= (abs(s[i] - s[i + 1]) != 1);
	return ok;
}

int main() {
	int T;
	scanf("%d", &T);
	static char buf[120];
	forn(_, T){
		scanf("%s", buf);
		string s = buf;
		string odd = "", even = "";
		forn(i, s.size()){
			if (s[i] % 2 == 0)
				odd += s[i];
			else
				even += s[i];
		}
		sort(odd.begin(), odd.end());
		sort(even.begin(), even.end());
		if (check(odd + even))
			printf("%sn", (odd + even).c_str());
		else if (check(even + odd))
			printf("%sn", (even + odd).c_str());
		else
			puts("No answer");
	}
	return 0;
}
```
[1156C - Match Points](../problems/C._Match_Points.md "Educational Codeforces Round 64 (Rated for Div. 2)")

 **Tutorial**Tutorial is loading... **Solution (BledDest)**
```cpp
#include<bits/stdc++.h>

using namespace std;

const int N = 200043;

int n, z;
int a[N];

int main()
{
	scanf("%d", &n);
	scanf("%d", &z);
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	sort(a, a + n);
	int l = 0;
	int r = n / 2 + 1;
	while(r - l > 1)
	{
		int m = (l + r) / 2;
		bool good = true;
		for(int i = 0; i < m; i++)
			good &= (a[n - m + i] - a[i] >= z);
		if(good)
			l = m;
		else
			r = m;
	}
	cout << l << endl;
}
```
[1156D - 0-1-Tree](../problems/D._0-1-Tree.md "Educational Codeforces Round 64 (Rated for Div. 2)")

 **Tutorial**
### [1156D - 0-1-Tree](../problems/D._0-1-Tree.md "Educational Codeforces Round 64 (Rated for Div. 2)")

Let's divide all valid pairs into three categories: the ones containing only $0$-edges on the path, the ones containing only $1$-edges, and the ones containing both types of edges.

To calculate the number of pairs containing only $0$-edges, we may build a forest on the vertices of the original graph and $0$-edges, and choose all pairs of vertices belonging to the same connected components of this forest (we can find all connected components with DSU or any graph traversal algorithm). The same can be done for the pairs containing only $1$-edges.

If a path from $x$ to $y$ is valid and contains both types of edges, then there exists a vertex $v$ such that the simple path from $x$ to $v$ goes only through $0$-edges, and the simple path from $v$ to $y$ goes only through $1$-edges. So, let's iterate on this vertex $v$, and choose some other vertex from its component in $0$-graph as $x$, and some other vertex from its component in $1$-graph as $y$, and add the number of ways to choose them to the answer.

 **Solution (BledDest)**
```cpp
#include<bits/stdc++.h>

using namespace std;

const int N = 200043;

int p[2][N];
int siz[2][N];

int get(int x, int c)
{
	if(p[c][x] == x)
		return x;
	return p[c][x] = get(p[c][x], c);
}

void merge(int x, int y, int c)
{
	x = get(x, c);
	y = get(y, c);
	if(siz[c][x] < siz[c][y])
		swap(x, y);
	p[c][y] = x;
	siz[c][x] += siz[c][y];
}

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		p[0][i] = p[1][i] = i;
		siz[0][i] = siz[1][i] = 1;
	}
	for(int i = 0; i < n - 1; i++)
	{
		int x, y, c;
		scanf("%d %d %d", &x, &y, &c);
		--x;
		--y;
		merge(x, y, c);
	}
	long long ans = 0;
	for(int i = 0; i < n; i++)
	{
		if(p[0][i] == i)
			ans += siz[0][i] * 1ll * (siz[0][i] - 1);
		if(p[1][i] == i)
			ans += siz[1][i] * 1ll * (siz[1][i] - 1);
		ans += (siz[0][get(i, 0)] - 1) * 1ll * (siz[1][get(i, 1)] - 1);
	}
	cout << ans << endl;
}
```
[1156E - Special Segments of Permutation](../problems/E._Special_Segments_of_Permutation.md "Educational Codeforces Round 64 (Rated for Div. 2)")

 **Tutorial**Tutorial is loading... **Solution (BledDest)**
```cpp
#include<bits/stdc++.h>

using namespace std;

const int N = 200043;

int lf[N];
int rg[N];
int n;
int ans = 0;
int p[N];
int q[N];

void update(int l, int r, int l2, int r2, int sum)
{
	for(int i = l; i <= r; i++)
	{
		int o = sum - p[i];
		if(o >= 1 && o <= n && l2 <= q[o] && q[o] <= r2)
			ans++;
	}
}

int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &p[i]);
		q[p[i]] = i;
	}
	stack<pair<int, int> > s;
	s.push(make_pair(n + 1, -1));
	for(int i = 0; i < n; i++)
	{
		while(s.top().first < p[i])
			s.pop();
		lf[i] = s.top().second;
		s.push(make_pair(p[i], i));
	}
	while(!s.empty())
		s.pop();
	s.push(make_pair(n + 1, n));
	for(int i = n - 1; i >= 0; i--)
	{
		while(s.top().first < p[i])
			s.pop();
		rg[i] = s.top().second;
		s.push(make_pair(p[i], i));
	}
	for(int i = 0; i < n; i++)
	{
	//	cerr << i << " " << lf[i] << " " << rg[i] << endl;
		int lenl = i - lf[i] - 1;
		int lenr = rg[i] - i - 1;
		if(lenl == 0 || lenr == 0)
			continue;
		if(lenl < lenr)
			update(lf[i] + 1, i - 1, i + 1, rg[i] - 1, p[i]);
		else
			update(i + 1, rg[i] - 1, lf[i] + 1, i - 1, p[i]);
	}
	cout << ans << endl;
}
```
[1156F - Card Bag](../problems/F._Card_Bag.md "Educational Codeforces Round 64 (Rated for Div. 2)")

 **Tutorial**Tutorial is loading... **Solution (Roms)**
```cpp
#include<bits/stdc++.h>

using namespace std;

const int MOD = 998244353;
const int N = 5005;

void upd(int &a, int b){
    a += b;
    a %= MOD;
}

int mul(int a, int b){
    return (a * 1LL * b) % MOD;
}

int bp(int a, int n){
    int res = 1;
    for(; n > 0; n >>= 1){
        if(n & 1) res = mul(res, a);
        a = mul(a, a);
    }
    return res;
}

int getInv(int a){
    int ia = bp(a, MOD - 2);
    assert(mul(a, ia) == 1);
    return ia;
}

int n;
int cnt[N];
int suf[N];
int dp[N][N];
int sum[N][N];
int inv[N];

int main(){
    for(int i = 1; i < N; ++i)
        inv[i] = getInv(i);
        
    cin >> n;
    for(int i = 0; i < n; ++i){
        int x;
        cin >> x;
        ++cnt[x];
    }
    cnt[0] = 1;
    for(int i = N - 2; i >= 0; --i)
        suf[i] = suf[i + 1] + cnt[i];
        
    for(int x = n; x >= 0; --x)
        for(int y = n; y >= 0; --y){
            if(cnt[x] == 0){
                upd(sum[x][y], sum[x + 1][y]);
                continue;
            }
            int s = n - y;
            if(s <= 0){
                upd(sum[x][y], sum[x + 1][y]);
                continue;
            }
            
            upd(dp[x][y], mul(cnt[x] - 1, inv[s]));
            upd(dp[x][y], mul(sum[x + 1][y + 1], inv[s]));
            
            upd(sum[x][y], sum[x + 1][y]);
            upd(sum[x][y], mul(cnt[x], dp[x][y]));
        }
    
    cout << dp[0][0] << endl;
	return 0;
}
```
[1156G - Optimizer](../problems/G._Optimizer.md "Educational Codeforces Round 64 (Rated for Div. 2)")

 **Tutorial**Tutorial is loading... **Solution (e-maxx)**[Solution](https://codeforces.com/contest/1156/submission/53641770) described in a tutorial.

Jury's solution:

 
```cpp
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;


struct expr {
	string t; // variable name or operation
	expr * l, * r; // only if operation
	long long hash;
	
	expr (string var)
		: t(var), l(0), r(0), hash(0)
		{ }
	expr (char op, expr * l, expr * r)
		: t(1,op), l(l), r(r), hash(0)
		{ }

	long long calc_hash() {
		if (!hash)
			if (!l) {
				long long pw = 257;
				for (size_t i=0; i<t.length(); ++i,  pw*=97)
					hash += t[i] * pw;
			}
			else
				hash += l->calc_hash() * t[0] + r->calc_hash() * 31;
		return hash;
	}
};

map<string,expr*> var;

void inc_var_name (string & cur) {
	for (size_t i=cur.length()-1; ; --i)
		if (cur[i] < 'z') {
			++cur[i];
			break;
		}
		else
			cur[i] = 'a';
}

string generate_var() {
	static string cur = "aaaa";
	while (var.count(cur))
		inc_var_name (cur);
	string res = cur;
	inc_var_name (cur);
	return res;
}

vector<string> ans;
map<long long,string> calced;

string restore (expr * e, string name = "") {
	if (!e->l)  return e->t;
	long long h = e->calc_hash();
	if (calced.count(h))  return calced[h];
	string l = restore (e->l),  r = restore (e->r);
	string my = name.empty() ? generate_var() : name;
	calced[h] = my;
	ans.push_back (my + "=" + l + e->t + r);
	return my;
}

int main() {
	int n;
	scanf ("%dn", &n);
	for (int i=0; i<n; ++i) {
		static char buf[100];
		gets (buf);
		string s = buf;

		size_t pos1 = s.find ('='),  pos2 = s.find_first_of ("&^$#");
		string lname = s.substr (0, pos1);
		string r1name = s.substr (pos1 + 1, pos2 - pos1 - 1);
		if (!var.count(r1name))
			var[r1name] = new expr (r1name);
		if (pos2 != -1) {
			string r2name = s.substr (pos2 + 1);
			if (!var.count(r2name))
				var[r2name] = new expr (r2name);
			var[lname] = new expr (s [ s.find_first_of ("&^$#") ], var[r1name], var[r2name]);
		}
		else
			var[lname] = var[r1name];
	}

	if (!var.count("res")) {
		cout << 0;
		return 0;
	}

	string name = restore (var["res"], "res");
	if (name != "res")
		ans.push_back ("res=" + name);

	cout << ans.size() << endl;
	for (size_t i=0; i<ans.size(); ++i)
		puts (ans[i].c_str());

}
```
