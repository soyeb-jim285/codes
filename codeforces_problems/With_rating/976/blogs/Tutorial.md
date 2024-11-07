# Tutorial

[976A - Minimum Binary Number](../problems/A._Minimum_Binary_Number.md "Educational Codeforces Round 43 (Rated for Div. 2)")

 **Editorial**
### [976A - Minimum Binary Number](../problems/A._Minimum_Binary_Number.md "Educational Codeforces Round 43 (Rated for Div. 2)")

If *n* = 1 then the answer is equal to *s*. Otherwise answer will be equal to 2*cnt*0, where *cnt*0 is the count of the zeroes in the given string (i.e. the answer is the binary string of length *cnt*0 + 1, in which the first character is one and the other characters are zeroes).

 **Solution (Vovuh)**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

	int n;
	string s;
	cin >> n >> s;
	if (n == 1) {
		cout << s << endl;
	} else {
		int cnt0 = 0;
		for (int i = 0; i < n; ++i)
			cnt0 += s[i] == '0';
		cout << 1;
		for (int i = 0; i < cnt0; ++i)
			cout << 0;
		cout << endl;
	}
	
	return 0;
}
```
[976B - Lara Croft and the New Game](../problems/B._Lara_Croft_and_the_New_Game.md "Educational Codeforces Round 43 (Rated for Div. 2)")

 **Editorial**
### [976B - Lara Croft and the New Game](../problems/B._Lara_Croft_and_the_New_Game.md "Educational Codeforces Round 43 (Rated for Div. 2)")

Naive solution would be just simulate the tranversal and break when *k* steps are made. Obviously, this won't fit into time limit. Then we can decompose the path to some parts which can be calculated separately.

1. Walk from the top left to the bottom left corner;
2. Walk from second column to *m*-th on even rows;
3. Walk from *m*-th column to second on odd rows.

If *k* < *n* then it's the first part. Otherwise you can use the fact that rows are of the same length. (*k* - *n*)*div*(*m* - 1) will tell you the row and (*k* - *n*)*mod*(*m* - 1) will get you the number of steps Lara have made along this row.

Overall complexity: *O*(1).

 **Solution (PikMike)**
```cpp
#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

int n, m;
long long k;

int main() {
	scanf("%d%d%lld", &n, &m, &k);
	if (k < n){
		printf("%lld 1n", k + 1);
		return 0;
	}
	k -= n;
	long long row = k / (m - 1);
	printf("%lld ", n - row);
	if (row & 1)
		printf("%lldn", m - k % (m - 1));
	else
		printf("%lldn", k % (m - 1) + 2);
	return 0;
}
```
[976C - Nested Segments](../problems/C._Nested_Segments.md "Educational Codeforces Round 43 (Rated for Div. 2)")

 **Editorial**
### [976C - Nested Segments](../problems/C._Nested_Segments.md "Educational Codeforces Round 43 (Rated for Div. 2)")

Let's sort segments firstly by their left border in increasing order and in case of equal by their right border in decreasing order. If there is any valid pair then the inner segment will always go after the outer one. 

Now you can go from left to right, keep the maximum right border of processed segments and compare it to the current segment. 

Overall complexity: ![](images/dcf41d727454fb39feadcb6f172d2403752185b8.png).

 **Solution (PikMike)**
```cpp
#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define x first
#define y second

using namespace std;

typedef pair<int, int> pt;

const int N = 300 * 1000 + 13;

int n;
pair<pt, int> a[N];

int main() {
	scanf("%d", &n);
	forn(i, n){
		scanf("%d%d", &a[i].x.x, &a[i].x.y);
		a[i].y = i + 1;
	}
	
	sort(a, a + n, [&](pair<pt, int> a, pair<pt, int> b){if (a.x.x != b.x.x) return a.x.x < b.x.x; return a.x.y > b.x.y;});
	
	set<pt> cur;
	forn(i, n){
		while (!cur.empty() && cur.begin()->x < a[i].x.x)
			cur.erase(cur.begin());
		if (!cur.empty() && (--cur.end())->x >= a[i].x.y){
			printf("%d %dn", a[i].y, (--cur.end())->y);
			return 0;
		}
		cur.insert({a[i].x.y, a[i].y});
	}
	
	puts("-1 -1");
	return 0;
}
```
[976D - Degree Set](../problems/D._Degree_Set.md "Educational Codeforces Round 43 (Rated for Div. 2)")

 **Editorial**
### [976D - Degree Set](../problems/D._Degree_Set.md "Educational Codeforces Round 43 (Rated for Div. 2)")

We prove that the answer always always exists by constructing it. 

* Graph for *n* = 0 is a single vertex;
* Graph for *n* = 1 is a clique of *d*1 + 1 vertices;
* Graph for some (*d*1, *d*2, ..., *d**k*) is obtained from the graph (*d*2 - *d*1, *d*3 - *d*1, ..., *d**k* - 1 - *d*1) by adding (*d**k* - *d**k* - 1) vertices initially connected to nothing and *d*1 vertices connected to all previously mentioned ones.

The vertices connected to nothing got degrees *d*1, the vertices from the previous step increased their degrees by *d*1 and finally there appeared vertices of degree *d**k*. The number is vertices is *d**k* + 1 as needed.

 **Solution (PikMike)**
```cpp
#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

typedef pair<int, int> pt;

const int N = 100 * 1000 + 13;

int n;
vector<int> d;
vector<int> g[N];

vector<pt> construct(int st, vector<int> d){
	if (d.empty())
		return vector<pt>();
	
	vector<pt> res;
	forn(i, d[0])
		for (int j = st + i + 1; j <= st + d.back(); ++j)
			res.push_back({st + i, j});
	
	int nxt = st + d[0];
	for (int i = 1; i < int(d.size()); ++i)
		d[i] -= d[0];
	d.erase(d.begin());
	if (!d.empty())
		d.pop_back();
	
	auto tmp = construct(nxt, d);
	for (auto it : tmp)
		res.push_back(it);
	
	return res;
}

int main() {
	scanf("%d", &n);
	d.resize(n);
	forn(i, n)
		scanf("%d", &d[i]);
	auto res = construct(0, d);
	printf("%dn", int(res.size()));
	for (auto it : res)
		printf("%d %dn", it.first + 1, it.second + 1);
	return 0;
}
```
[976E - Well played!](../problems/E._Well_played!.md "Educational Codeforces Round 43 (Rated for Div. 2)")

 **Editorial**
### [976E - Well played!](../problems/E._Well_played!.md "Educational Codeforces Round 43 (Rated for Div. 2)")

At first let's prove that in optimal solution all spells of 1-st type are assigned to single creature. By contradiction: let's optimal answer contains indices *i* ≠ *j* where *hp*'*i* = *hp**i*·2*x* and *hp*'*j* = *hp**j*·2*y*. If *hp*'*i*(*j*) ≤ *dmg**i*(*j*) using spells of 1-st type is meaningless. Otherwise, if (in general case) *hp*'*i* ≥ *hp*'*j* then *hp**i*·2*x* + 1 + *hp**j*·2*y* - 1 > *hp*'*i* + *hp*'*j*. Contradiction.

So, we can check for each creature maximal damage with its health multiplied.

At second, if we sort all creatures in order by decreasing (*hp**i* - *dmg**i*), using *b* spells on first *b* creatures gives best answer *ans*. So, calculating answer for chosen creature invokes 2 cases: 

* if chosen creature is belong to first *b* creatures, then subtract from *ans* its contribution, calculate new value and add it to *ans*;
* otherwise, we need one spell of second type, which is optimal to take from *b*-th creature, so along with replacing old value of chosen one we need to replace in *ans* contribution of *b*-th creature.

Result complexity is *O*(*n*·*log*(*n*))

 **Solution (Ajosteen)**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int N = 200 * 1000 + 9;

int n, a, b;
int hp[N], dmg[N];

bool cmp(int i, int j){
	if(hp[i] - dmg[i] != hp[j] - dmg[j])
		return hp[i] - dmg[i] > hp[j] - dmg[j];
	return i < j;
}

int get(int id){
	return  hp[id] > dmg[id]? hp[id] : dmg[id];
}

int main(){
	scanf("%d %d %d", &n, &a, &b);
	for(int i = 0; i < n; ++i)
		scanf("%d %d", hp + i, dmg + i);
	
	b = min(b, n);
	vector <int> p(n);
	for(int i = 0; i < n; ++i) p[i] = i;
	sort(p.begin(), p.end(), cmp);
	long long res = 0, sum = 0;
	for(int i = 0; i < n; ++i){
		int id = p[i];
		if(i < b) sum += get(id);
		else sum += dmg[id];
	}
	res = sum; 

	if(b == 0){
		printf("%lldn", res);
		return 0;
	}
	
	long long x = (1LL << a);
	for(int i = 0; i < n; ++i){
		int id = p[i];
		long long nres = sum;
		if(i < b){ 
			nres -= get(id);
			nres += hp[id] * x;
			res = max(res, nres);
		}
		else{
			nres -= dmg[id];
			nres += hp[id] * x;			
			int id2 = p[b - 1];
			nres -= get(id2);
			nres += dmg[id2];
			res = max(res, nres);
			
		}		
	}
	
	printf("%lldn", res);
	return 0;
}
```
[976F - Minimal k-covering](../problems/F._Minimal_k-covering.md "Educational Codeforces Round 43 (Rated for Div. 2)")

 **Editorial**
### [976F - Minimal k-covering](../problems/F._Minimal_k-covering.md "Educational Codeforces Round 43 (Rated for Div. 2)")

To get the answer for some *k* we can build the following network: connect the source to every vertex of the first part with edge with capacity *deg**x*  -  *k* (where *deg**x* is the degree of vertex), then transform every edge of the original graph into a directed edge with capacity 1, and then connect each vertex from the second part to the sink with capacity *deg**x*  -  *k*. Then edges saturated by the maxflow are not present in the answer (and all other edges are in the answer).

To solve it fastly, we might just iterate on *k* from its greatest value to 0 and each time augment the flow we found on previous iteration. Since maxflow in the network is at most *m*, and we will do not more than *m* searches that don't augment the flow, this solution is *O*((*n* + *m*)2).

 **Solution (adedalic)**
```cpp
#include<bits/stdc++.h>

using namespace std;

#define fore(i, l, r) for(int i = int(l); i < int(r); i++)

#define sz(a) int((a).size())
#define x first
#define y second

const int INF = int(1e9);
const int N = 4221;

struct edge {
    int to, c, f, id;

    edge(int to = 0, int c = 0, int f = 0, int id = -1) : to(to), c(c), f(f), id(id) {}
};

vector<edge> es;
vector<int> g[N];

void add_edge(int fr, int to, int cap, int id) {
    g[fr].push_back(sz(es));
    es.emplace_back(to, cap, 0, id);
    g[to].push_back(sz(es));
    es.emplace_back(fr, 0, 0, id);
}

int pw[N];
int n1, n2, m;

inline bool read() {
    if(!(cin >> n1 >> n2 >> m))
        return false;

    fore(id, 0, m) {
        int u, v;
        assert(cin >> u >> v);
        u--, v--;

        pw[u]++;
        pw[n1 + v]++;

        add_edge(u, n1 + v, 1, id);
    }
    return true;
}

int d[N], q[N], hd, tl;
inline bool bfs(int s, int t, int n) {
    fore(i, 0, n)
        d[i] = INF;
    hd = tl = 0;

    d[s] = 0;
    q[tl++] = s;
    while(hd != tl) {
        int v = q[hd++];
        if(v == t)
            break;

        for(int id : g[v]) {
            if(es[id].c - es[id].f == 0)
                continue;

            int to = es[id].to;
            if(d[to] > d[v] + 1) {
                d[to] = d[v] + 1;
                q[tl++] = to;
            }
        }
    }
    return d[t] < INF;
}

int nxt[N];

int dfs(int v, int t, int mx) {
    if(v == t) return mx;
    if(mx == 0) return 0;

    int sum = 0;
    for(; nxt[v] < sz(g[v]); nxt[v]++) {
        int id = g[v][nxt[v]];
        int rem = es[id].c - es[id].f;
        int to = es[id].to;

        if(rem == 0 || d[to] != d[v] + 1)
            continue;

        int cur = 0;
        if((cur = dfs(to, t, min(mx - sum, rem))) > 0) {
            es[id].f += cur;
            es[id ^ 1].f -= cur;
            sum += cur;
        }

        if(sum == mx)
            break;
    }
    return sum;
}

inline int dinic(int s, int t, int n) {
    int mf = 0;
    while(bfs(s, t, n)) {
        fore(i, 0, n)
            nxt[i] = 0;

        int cf = 0;
        while((cf = dfs(s, t, INF)) > 0)
            mf += cf;
    }
    return mf;
}

vector<int> res[N];

inline void getCert(int k) {
    fore(v, 0, n1) {
        for(int id : g[v]) {
            if(es[id].to < n1 || es[id].to >= n1 + n2)
                continue;
            assert(es[id].c > 0);
            if(es[id].f > 0)
                continue;

            res[k].push_back(es[id].id);
        }
    }
}

void solve() {
    int cnt = *min_element(pw, pw + n1 + n2);

    int s = n1 + n2; int t = s + 1;
    fore(i, 0, n1)
        add_edge(s, i, pw[i] - cnt, -1);
    fore(i, n1, n1 + n2)
        add_edge(i, t, pw[i] - cnt, -1);

    int mf = 0, mn = cnt;
    while(mn >= 0) {
        mf += dinic(s, t, n1 + n2 + 2);
        getCert(mn);

        if(mn > 0) {
            for (int id : g[s]) {
                assert(es[id].id < 0);
                assert((id & 1) == 0);
                es[id].c++;
            }
            for (int id : g[t]) {
                assert(es[id].id < 0);
                assert(es[id].c == 0);
                es[id ^ 1].c++;
            }
        }
        mn--;
    }

    fore(i, 0, cnt + 1) {
        printf("%d ", sz(res[i]));
        for(int id : res[i])
            printf("%d ", id + 1);
        puts("");
    }
}

int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
#endif

    if(read()) {
        solve();
    }
    return 0;
}
```
