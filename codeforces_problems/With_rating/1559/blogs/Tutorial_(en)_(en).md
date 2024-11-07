# Tutorial_(en)_(en)


### [1559A - Mocha and Math](../problems/A._Mocha_and_Math.md "Codeforces Round 738 (Div. 2)")

We assume the answer is xx. In its binary representation, one bit will be 1 only if in all the ai's binary representation,this bit is 1. Otherwise, we can use one operation to make this bit in x become 0, which is a smaller answer.

So we can set x=a1 initially. Then we iterate over the sequence and make x=x&ai, the x is the anwser finally.

 **solution**
```cpp
#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define maxm 100005
#define maxn 2005
#define PII pair<int, int>
#define fi first
#define se second
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
const double pi = acos(-1);
const int mod = 998244353;
const double eps = 1e-10;
const int N =1e2+10;
int n;
int a[N];
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    //int a,b,c;
    int t;
    cin>>t;
    while(t--){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    int res=a[1];
    for(int i=2;i<=n;i++)res&=a[i];
    cout<<res<<endl;
    }
    return 0;
}
```
 
### [1559B - Mocha and Red and Blue](../problems/B._Mocha_and_Red_and_Blue.md "Codeforces Round 738 (Div. 2)")

For a longest period of "?", it is optimized to paint either "RBRB..." or "BRBR...", so the imperfectness it made is only related to the colors of both sides of it.

Choose the one with the lower imperfectness for each longest period of "?" in O(n) is acceptable.

More elegantly, if the square on the left or on the right of a "?" is painted, simply paint "?" with the different color from it. This can be proved to reach the minimum imperfectness by considering the parity.

 **solution**
```cpp
#include <cstdio>
using namespace std;
const int N=105;
int t,n,cnt;
char s[N];
int main()
{
	scanf("%d",&t);
	while (t--)
	{
		cnt=0;
		scanf("%d",&n);
		scanf("%s",s+1);
		for (int i=1;i<=n;i++)
			cnt+=(s[i]!='?');
		if (!cnt)
			s[1]='R';
		for (int i=2;i<=n;i++)
			if (s[i]=='?'&&s[i-1]!='?')
				s[i]=s[i-1]^('B'^'R');
		for (int i=n-1;i;i--)
			if (s[i]=='?'&&s[i+1]!='?')
				s[i]=s[i+1]^('B'^'R');
		printf("%sn",s+1);
	}
	return 0;
}
```
 
### [1559C - Mocha and Hiking](../problems/C._Mocha_and_Hiking.md "Codeforces Round 738 (Div. 2)")

If a1=1, then the path [(n+1)→1→2→⋯→n] is valid.

If an=0, then the path [1→2→⋯→n→(n+1)] is valid.

Otherwise, since a1=0∧an=1, there must exists an integer i (1≤i<n) where ai=0∧ai+1=1, then the path [1→2→⋯→i→(n+1)→(i+1)→(i+2)→⋯n] is valid.

This is a step to prove that there always exists an Hamiltonian path in a tournament graph.

 **solution**
```cpp
#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n;
int a[maxn];

void solve(){
	scanf("%d", &n);
	for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
	if(a[1]){
		printf("%d ", n + 1);
		for(int i = 1;i <= n;i++) printf("%d ", i);
		return;
	}
	for(int i = 1;i < n;i++){
		if(!a[i] && a[i + 1]){
			for(int j = 1;j <= i;j++) printf("%d ", j);
			printf("%d ", n + 1);
			for(int j = i + 1;j <= n;j++) printf("%d ", j);
			return;
		}
	}
	for(int i = 1;i <= n;i++) printf("%d ", i);
	printf("%d ", n + 1);
}

int main(){
    scanf("%d", &t);
    while(t--) solve(), puts("");
}

```
 
### [1559D1 - Mocha and Diana (Easy Version)](../problems/D1._Mocha_and_Diana_(Easy_Version).md "Codeforces Round 738 (Div. 2)")

In the final situation, if one forest has more than one tree, we choose two trees from it, such as tree A and tree B. Then we consider node a in A and node b in B, they must be connected in another forest. We can easily find node b is connected with all the nodes in A and node a is connected with all the nodes in B. So nodes in A and B are in the same tree in another forest. If we consider other trees, we can get the same conclusion. Hence nodes in another forest form only one tree.

So we can enumerate every pair (i,j) and check if this edge can be added. When the edge can be added, we can just add it. This can be done in the complexity of O(n2).

 **solution**
```cpp
#include<bits/stdc++.h>
#define maxn 2005
#define fi first
#define se second
#define PII pair<int, int>

using namespace std;

typedef long long ll;
const ll mod = 10007; 

inline ll read(){
    ll x = 0, f = 1;char ch = getchar();
    while(ch > '9' || ch < '0'){if(ch == '-') f = -1;ch = getchar();}
    while(ch >= '0' && ch <= '9'){x = x * 10 + ch -'0';ch = getchar();}
    return x * f;
}

int n, m1, m2, f[2][maxn];

int getf(int id, int x){return x == f[id][x] ? x : f[id][x] = getf(id, f[id][x]);}

vector<PII> ans;

int main() {
	n = read(), m1 = read(), m2 = read();
	
	for(int i = 1; i <= n; i++)
		f[0][i] = f[1][i] = i;
	
	for(int i = 1; i <= m1; i++){
		int u = read(), v = read();
		int fu = getf(0, u), fv = getf(0, v);
		f[0][fu] = fv;
	}
	
	for(int i = 1; i <= m2; i++){
		int u = read(), v = read();
		int fu = getf(1, u), fv = getf(1, v);
		f[1][fu] = fv;
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = i + 1; j <= n; j++){
			if(getf(0, i) != getf(0, j) && getf(1, i) != getf(1, j)){
				ans.push_back({i, j});
				f[0][getf(0, i)] = getf(0, j);
				f[1][getf(1, i)] = getf(1, j); 
			}
		}
	}
	
	printf("%dn", ans.size());
	for(auto i: ans) printf("%d %dn", i.fi, i.se);
	return 0;
}


```
 
### [1559D2 - Mocha and Diana (Hard Version)](../problems/D2._Mocha_and_Diana_(Hard_Version).md "Codeforces Round 738 (Div. 2)")

To have a clearer understanding, let's visualize the problem with a grid where each row is a component in the left forest and each column is a component in the right forest. For example, the cell (i,j) contains vertexes which belongs to ith component in the left forest and jth component in the right tree. (Some cells may be empty.) An operation corresponds to finding two filled cells in different rows and different columns, merging the two rows, and merging the two columns.

Now we need to make operation rapidly. For each row, we maintain a set of the different columns with filled cells in this row. Symmetrically, for each column we maintain a set of the different rows with filled cells in this column.

To merge two rows, we insert the elements of the smaller set into the larger set. The smaller set is now useless, and we delete it from every column in the set and insert the larger one. Since the data structure is symmetric, merging two columns is similar.

Without loss of generality, assume there are fewer rows than columns. If there is a row whose set has more than 1 element, we can pick it and any other row, and find an operation we can make. Otherwise if all rows are singletons, then we know the sets are all disjoint because there are more columns than rows. So we can pick any two sets and make an operation, and then there's a set with more than 1 element. Maintaining which rows have sets with size more than 1 is not hard.

For each operation, we need to output the corresponding vertex in the original two forest. Firstly, choose a vertex as the representative of each cell, because all vertexes in a cell can be seen as equivalent. Then, when merging two rows or columns, we just insert the representative vertexes at the same time.

There can be at most 2n merge operations and the total complexity of them will be O(nlog2n). This is because an element moves to a new row/column O(logn) times and each move is O(logn) time (using STL set in cpp).

Overall, it's O(nlog2n)time and O(nlogn) space.

 **solution**
```cpp
#include<bits/stdc++.h>
using namespace std;
#define N 100010
int fa1[N],fa2[N];
set<pair<int,int> > rows;
set<int> row[N],col[N];
set<int>::iterator it;
map<int,int> mp[N];
pair<int,int> Ans[N];
int getfa(int *fa,int x){
	if (x==fa[x]){
		return x;
	}
	return fa[x]=getfa(fa,fa[x]);
}
void Merge_row(int x,int y){
	for (it=row[y].begin();it!=row[y].end();it++){
		mp[x][*it]=mp[y][*it];
		row[x].insert(*it);
		col[*it].erase(y);
		col[*it].insert(x);
	}
}
void Merge_col(int x,int y){
	for (it=col[y].begin();it!=col[y].end();it++){
		mp[*it][x]=mp[*it][y];
		col[x].insert(*it);
		row[*it].erase(y);
		row[*it].insert(x);
	}
}
int main(){
	int n,m1,m2,h=0,i;
	scanf("%d%d%d",&n,&m1,&m2);
	for (i=1;i<=n;i++){
		fa1[i]=fa2[i]=i;
	}
	for (i=1;i<=m1;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		int p=getfa(fa1,x),q=getfa(fa1,y);
		fa1[p]=q;
	}
	for (i=1;i<=m2;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		int p=getfa(fa2,x),q=getfa(fa2,y);
		fa2[p]=q;
	}
	if (m1<m2){
		swap(fa1,fa2);
	}
	
	for (i=1;i<=n;i++){
		int p1=getfa(fa1,i),p2=getfa(fa2,i);
		mp[p1][p2]=i;
		row[p1].insert(p2);
		col[p2].insert(p1);
	}
	for (i=1;i<=n;i++){
		if (getfa(fa1,i)==i){
			rows.insert(make_pair(-row[i].size(),i));
		}
	}
	
	while (rows.size()>1){
		int x=rows.begin()->second;
		rows.erase(rows.begin());
		int y=rows.begin()->second;
		rows.erase(rows.begin());
		if (row[x].size()<row[y].size()){
			swap(x,y);
		}
		it=row[x].begin();
		int a=*it,b=*row[y].begin();
		if (a==b){
			a=*++it;
		}
		Ans[++h]=make_pair(mp[x][a],mp[y][b]);
		if (col[a].size()<col[b].size()){
			swap(a,b);
		}
		Merge_row(x,y);
		Merge_col(a,b);
		rows.insert(make_pair(-row[x].size(),x));
	}
	
	printf("%dn",h);
	for (i=1;i<=h;i++){
		printf("%d %dn",Ans[i].first,Ans[i].second);
	}
	return 0;
}

```
 
### [1559E - Mocha and Stars](../problems/E._Mocha_and_Stars.md "Codeforces Round 738 (Div. 2)")

We firstly ignore the constraint of gcd, let f([l1,l2,…,ln],[r1,r2,…,rn],M) be the number of integers (a1,a2,⋯,an) satisfy the following two conditions:

* For all i (1≤i≤n), ai is an integer in the range [li,ri].
* n∑i=1ai≤m.

 We can compute it in O(nM) by Knapsack DP optimized by prefix-sums.

Then we consider about the constraint of gcd, let μ(n) be Mobius function, and g(a1,a2,…,an) be 1 if (a1,a2,⋯,an) satisfies the two conditions we mentioned about (without the constraint of gcd), otherwise it will be 0.

The answer we want is: r1∑a1=l1r2∑a2=l2⋯rn∑an=ln[gcd(a1,a2,…,an)=1]g(a1,a2,…,an)=r1∑a1=l1r2∑a2=l2⋯rn∑an=lng(a1,a2,…,an)∑d∣gcd(a1,a2,…,an)μ(d)=r1∑a1=l1r2∑a2=l2⋯rn∑an=lng(a1,a2,…,an)∑d∣a1,d∣a2,…,d∣anμ(d)=M∑d=1μ(d)⌊r1d⌋∑a1=⌈l1d⌉⌊r2d⌋∑a2=⌈l2d⌉⋯⌊rnd⌋∑an=⌈lnd⌉g(a1d,a2d,…,and) Since n∑i=1aid≤M can be changed to n∑i=1ai≤⌊Md⌋, it equals: M∑d=1μ(d)f(⌈l1d⌉,⌈l2d⌉,…,⌈lnd⌉,⌊r1d⌋,⌊r2d⌋,…,⌊rnd⌋,⌊Md⌋) So we can compute it in O(nM∑i=1⌊Mi⌋)=O(nMlogM).

 **solution**
```cpp
#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

const int p = 998244353;

int n, m;
int l[maxn], r[maxn];
int f[maxn], sum[maxn];

int cal(int d){
	int M = m / d;
	f[0] = 1;
	for(int i = 1;i <= M;i++) f[i] = 0;
	for(int i = 1;i <= n;i++){
		int L = (l[i] + d - 1) / d, R = r[i] / d;
		if(L > R) return 0;
		for(int j = 0;j <= M;j++) sum[j] = (f[j] + (j ? sum[j - 1] : 0)) % p;
		for(int j = 0;j <= M;j++){
			f[j] = ((j - L >= 0 ? sum[j - L] : 0) + p - (j - R - 1 >= 0 ? sum[j - R - 1] : 0)) % p;
		}
	}
	int ans = 0;
	for(int i = 1;i <= M;i++) ans = (ans + f[i]) % p;
	return ans;
}

int prm[maxn], cnt, mu[maxn];
bool tag[maxn];

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1;i <= n;i++) scanf("%d%d", &l[i], &r[i]);
	mu[1] = 1;
	for(int i = 2;i <= m;i++){
		if(!tag[i]) prm[++cnt] = i, mu[i] = p - 1;
		for(int j = 1;j <= cnt && prm[j] * i <= m;j++){
			tag[i * prm[j]] = true;
			if(i % prm[j]) mu[i * prm[j]] = (p - mu[i]) % p;
			else break;
		} 
	}
	int ans = 0;
	for(int i = 1;i <= m;i++) ans = (ans + 1ll * mu[i] * cal(i)) % p;
	printf("%d", ans);
}

```
