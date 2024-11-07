# Tutorial_(en)


### [1316A - Grade Allocation](../problems/A._Grade_Allocation.md "CodeCraft-20 (Div. 2)")

**Author:** [gaurav172](https://codeforces.com/profile/gaurav172 "Candidate Master gaurav172")  
**Development:** [gaurav172](https://codeforces.com/profile/gaurav172 "Candidate Master gaurav172"), [firebolt](https://codeforces.com/profile/firebolt "Specialist firebolt"), [night_fury208](https://codeforces.com/profile/night_fury208 "Candidate Master night_fury208")

 **Tutorial**
### [1316A - Grade Allocation](../problems/A._Grade_Allocation.md "CodeCraft-20 (Div. 2)")

Since the average score of the class must remain same ,this means the sum of the scores of all students in the class must remain same. We want to maximize the score of the first student and since the minimum score of each student can be zero we can add the scores of the rest of students to the first student as long as his score is less than or equal to m. Therefore the answer is $ \min {(a_1+\sum_{i=2}^{i = n} a_{i} , m )} $

Time complexity : $O(n)$ per testcase

 **Solution**
```cpp
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
	ll test;
	cin>>test;
	while(test--)
	{
		ll n,m;
		cin>>n>>m;
		ll s=0;
		for(ll i=1;i<=n;i++)
		{
			ll x;
			cin>>x;
			s=s+x;
		}
		cout<<min(s,m)<<"n";
	}
	return 0;
}
```
### [1316B - String Modification](../problems/B._String_Modification.md "CodeCraft-20 (Div. 2)")

**Author:** [preet_t](https://codeforces.com/profile/preet_t "Specialist preet_t")  
**Development:** [preet_t](https://codeforces.com/profile/preet_t "Specialist preet_t"), [shaanknight](https://codeforces.com/profile/shaanknight "Master shaanknight"), [night_fury208](https://codeforces.com/profile/night_fury208 "Candidate Master night_fury208")

 **Tutorial**
### [1316B - String Modification](../problems/B._String_Modification.md "CodeCraft-20 (Div. 2)")

Let the input string $s$ be $s_{1}s_{2}..s_{n}$. We observe the sequence of modifications that the string goes through for some value of $k$. After reversing the first sub-string of length $k$, the string becomes $s_{k}s_{k-1}..s_{1}s_{k+1}s_{k+2}..s_{n}$. Notice that the first character of this string will not be part of any subsequent modifications. After the next step of modification, the string becomes $s_{k}s_{k+1}s_{1}..s_{k-1}s_{k+2}..s_{n}$. Again, notice that the first two characters of this string will not be part of any subsequent modifications. Keep repeating the steps of modification. Do you see any pattern?

It is easy to realise that after $i$ steps of modifications, the prefix of the resulting string will be $s_{k}s_{k+1}..s_{k+i-1}$. Since the number of sub-strings to reverse is $(n - k + 1)$, the prefix of our answer string will be $s_{k}s_{k+1}..s_{k+(n-k+1)-1}$, which is just the suffix string $s_{k}..s_{n}$. What about the suffix of our answer string? It can be observed that the suffix will be $s_{1}..s_{k-1}$ if $n$ and $k$ have the same parity and $s_{k-1}..s_{1}$ otherwise.

We can generate and compare the modified string for each possible value of $k$ from $1$ to $n$ and find the lexicographically smallest among them. Additionally, we need to take care that the solution outputs the smallest possible $k$ in case when multiple values give the optimal string.

Time complexity: $\mathcal{O}(n^{2})$ per testcase.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

string modified(string& s, int n, int k) {
	string result_prefix = s.substr(k - 1, n - k + 1);
	string result_suffix = s.substr(0, k - 1);
	if (n % 2 == k % 2)
		reverse(result_suffix.begin(), result_suffix.end());
	return result_prefix + result_suffix;
}

int main () {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string s, best_s, temp;
	int t, n, best_k;
	cin >> t;
	while (t--) {
		cin >> n >> s;
		best_s = modified(s, n, 1);
		best_k = 1;
		for (int k = 2; k <= n; ++k) {
			temp = modified(s, n, k);
			if (temp < best_s) {
				best_s = temp;
				best_k = k;
			}
		}
		cout << best_s << 'n' << best_k << 'n';
	}
	return 0;
}
```
### [1316C - Primitive Primes](../problems/C._Primitive_Primes.md "CodeCraft-20 (Div. 2)")

**Author:** [lazyneuron](https://codeforces.com/profile/lazyneuron "Specialist lazyneuron")  
**Development:** [lazyneuron](https://codeforces.com/profile/lazyneuron "Specialist lazyneuron"), [shaanknight](https://codeforces.com/profile/shaanknight "Master shaanknight"),[firebolt](https://codeforces.com/profile/firebolt "Specialist firebolt")

 **Tutorial**
### [1316C - Primitive Primes](../problems/C._Primitive_Primes.md "CodeCraft-20 (Div. 2)")

We will prove a simple result thereby giving one of the power that satisfies the constraint:

We know that cumulative gcd of coefficients is one in both cases. Hence no prime divides all the coefficients of the polynomial. We call such polynomials primitive polynomials. This question in a way tells us that the product of two primitive polynomials is also a primitive polynomial.

Let $x_i$ be the lowest power of $x$ in $f(x)$ whose coefficient is coprime to given prime $p$, and $x_j$ be the lowest power of $x$ in $g(x)$ whose coefficient is coprime to given prime $p$. Since both such coefficients exist, the answer is proved to exist.

When we multiply $f(x)$ and $g(x)$, we get the following as the coefficient for $x^{i + j}$, 

$(a_0 * b_{i + j} + a_1 * b_{i + j - 1} + ...) + a_i * b_j + (a_{i + 1} * b_{j - 1} + a_{i + 2} * b_{j - 2} +...)$

We see the terms inside parentheses are all divisible by the prime $p$, and only $a_i * b_j$ is not divisible by $p$. So, we can say that the coefficient of $x^{i+j}$ is not divisible by $p$.

Time complexity : $O(n+m)$

 **Solution**
```cpp
#include<bits/stdc++.h>
using namespace std;

#define ll long long int
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);

	ll n,i,m,x,a,p,fir,sec;
	
	cin >> n >> m >> p;
	a=0;
	for(i=0;i<n;i++)
	{
		cin >> x;
		if(x%p && !a)
		{
			a=1;
			fir=i;
		}
	}
	a=0;
	for(i=0;i<m;i++)
	{
		cin >> x;
		if(x%p && !a)
		{
			a=1;
			sec=i;
		}
	}
	cout << fir+sec << endl;
	return 0;
}

```
### [1316D - Nash Matrix](../problems/D._Nash_Matrix.md "CodeCraft-20 (Div. 2)")

**Author:** [shaanknight](https://codeforces.com/profile/shaanknight "Master shaanknight")  
**Development:** [shaanknight](https://codeforces.com/profile/shaanknight "Master shaanknight"), [riz_1_](https://codeforces.com/profile/riz_1_ "Expert riz_1_"), [coder_h](https://codeforces.com/profile/coder_h "Expert coder_h"),[Altitude](https://codeforces.com/profile/Altitude "Expert Altitude") 

 **Tutorial**
### [1316D - Nash Matrix](../problems/D._Nash_Matrix.md "CodeCraft-20 (Div. 2)")

If there exists a valid board satisfying the input matrix, one can notice two types of clusters in the input matrix, first, a cluster of connected cells having the same stopping point and second, a cluster of connected cells which do not have any stopping point, i.e., all having pair $(-1,-1)$ . 

Among the cells, having a stopping point, we can start a dfs/bfs from all the cells having stopping point as the cell itself , i.e., cells $(i,j)$ has stopping cell as $(i,j)$. While performing the traversal, we move into any neighbouring cell from current cell if it has the same stopping cell as the current cell. This way, all the cells in clusters of first kind will have an instruction associated  — $U$, $D$, $L$, $R$ or $X$  — .

For the cells having no stopping cell, we need to put instructions on them such that starting on them, a player keeps moving in a cycle. So these cells are either a part of cycle, or have paths starting from them leading into a cycle. The simplest way to do so is to try to put such cells into disjoint pairs (cycles of length 2 of neighbouring cells), each cell in pair pointing towards the other. Note that after trying to pair up these cells having no stopping point, there are no more two adjacent such cells both unpaired. Now for any such cell which could not be paired up, if it has no adjacent paired up cell, then it is a case of INVALID , else , just put a direction on the cell so that player moves into the adjacent paired up cell.

Now if any cell remains without having any instruction alloted, it is a case of INVALID.

The complexity of the above solution : $O(n*n)$. 

 **Solution**
```cpp
#include<bits/stdc++.h>
using namespace std;

const int M = (1<<10)+5;
char mat[M][M];
int x[M][M],y[M][M];
int n;

bool connect(int p,int q,int r,int s,char d1,char d2)
{
	if(x[r][s] == -1)
	{
		mat[p][q] =  d1;
		if(mat[r][s] == '0') mat[r][s] = d2;
		return 1;
	}
	else
		return 0;
}

void dfs(int p,int q,char d)
{
	if(mat[p][q] != '0') return;
	mat[p][q] = d;

	if(x[p][q] == x[p+1][q] && y[p][q] == y[p+1][q])
		dfs(p+1,q,'U');
	if(x[p][q] == x[p-1][q] && y[p][q] == y[p-1][q])
		dfs(p-1,q,'D');
	if(x[p][q] == x[p][q+1] && y[p][q] == y[p][q+1])
		dfs(p,q+1,'L');
	if(x[p][q] == x[p][q-1] && y[p][q] == y[p][q-1])
		dfs(p,q-1,'R');
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int i,j;

	cin >> n;

	for(i=1;i<=n;++i)
	{
		for(j=1;j<=n;++j)
			cin >> x[i][j] >> y[i][j];
	}

	for(i=1;i<=n;++i)
	{
		for(j=1;j<=n;++j)
		{
			if(x[i][j] == -1)
			{
				bool res = (mat[i][j] != '0');
				if(res == 0) res = connect(i,j,i+1,j,'D','U');
				if(res == 0) res = connect(i,j,i,j+1,'R','L');
				if(res == 0) res = connect(i,j,i-1,j,'U','D');
				if(res == 0) res = connect(i,j,i,j-1,'L','R');
				if(res == 0)
				{
					cout << "INVALID" << "n";
					return 0;
				}
			}
			else if(x[i][j] == i && y[i][j] == j)
				dfs(i,j,'X');
		}
	}

	for(i=1;i<=n;++i)
	{
		for(j=1;j<=n;++j)
		{
			if(mat[i][j] == '0')
			{
				cout << "INVALID" << "n";
				return 0;
			}
		}	
	}

	cout << "VALID" << "n";

	for(i=1;i<=n;++i)
	{
		for(j=1;j<=n;++j)
		{
			cout << mat[i][j];
		}	
		cout << "n";
	}

	return 0;
}
```
### [1316E - Team Building](../problems/E._Team_Building.md "CodeCraft-20 (Div. 2)")

**Author:** [gaurav172](https://codeforces.com/profile/gaurav172 "Candidate Master gaurav172")  
**Development:** [gaurav172](https://codeforces.com/profile/gaurav172 "Candidate Master gaurav172"), [shaanknight](https://codeforces.com/profile/shaanknight "Master shaanknight"), [coder_h](https://codeforces.com/profile/coder_h "Expert coder_h"), [madlad](https://codeforces.com/profile/madlad "Expert madlad")

 **Tutorial**
### [1316E - Team Building](../problems/E._Team_Building.md "CodeCraft-20 (Div. 2)")

Idea is DP(bitmask)

First sort the people in non-increasing order of $a_{i}$.

let $dp[i][mask]$ = maximum strength of the club if we choose players from $1 \ldots i$, mask tells us about the positions in the team which have been covered. Don't worry about the audience part as of now, we will see how it is handled during transitions.

$dp[0][0]=0$ — initial state.

Lets try to find $dp[i][mask]$

If the $i$-th person is chosen to play in $j$-th position, $dp[i][mask] = dp[i-1][mask \oplus 2^j] + s_{i,j}$ — $(1)$.

If we don't choose $i$ as a player, then we can take him as an audience member or not take him at all. I claim that if the no. of audience members chosen till now < $k$, then we must select $i$ as an audience member , We can prove this. If we don't select $i$ as audience, we will need to select some $j$ ($j>i$), strength in that case will include $a_j$ but not $a_i$ , but as $a_i \geq a_j$, it is always better to select $i$.

We now need to know how many audience members have been selected for state $(i-1,mask)$.

let $c$ be the no. of persons who have not been selected as players, then $c$ = $i-1$ - no. of set bits in mask.By the above logic, we can say that if $c \geq k $, we have chosen already k audience members.

So, the solution becomes:

if $c < k$ , then $dp[i][mask] = dp[i-1][mask] + a_i$ — (2), else $dp[i][mask] = dp[i-1][mask]$ — (2), 

You need to choose maximum of $(1)$ and $(2)$ as $dp[i][mask]$. $dp[n][2^p-1]$ would be the answer to our question.

Time Complexity : $O(n \cdot p \cdot 2^p)$.

 **Solution**
```cpp
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
const ll M=1e5+5;
ll dp[M][(1<<7)+1],skill[M][7];
ll ind[M],a[M];
bool cmp(ll p,ll q)
{
	return a[p]>a[q];
}
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n,p,k;
	cin>>n>>p>>k;
	memset(dp,-1,sizeof(dp));
	for(ll i=1;i<=n;i++)
		cin>>a[i];
	for(ll i=1;i<=n;i++)
		for(ll j=0;j<p;j++)
			cin>>skill[i][j];
	for(ll i=1;i<=n;i++)
		ind[i]=i;
	sort(ind+1,ind+n+1,cmp);	
	dp[0][0]=0;
	for(ll i=1;i<=n;i++)
	{
		ll x=ind[i];
		for(ll mask=0;mask<(1<<p);mask++)
		{
			ll ct=0;
			for(ll j=0;j<p;j++)
				if((mask&(1<<j)))
					ct++;
			ll z=(i-1)-ct;
			if(z<k)
			{
				if(dp[i-1][mask]!=-1)
					dp[i][mask]=dp[i-1][mask]+a[x];
			}
			else
			{
				if(dp[i-1][mask]!=-1)
					dp[i][mask]=dp[i-1][mask];
			}
			for(ll j=0;j<p;j++)
			{
				if((mask&(1<<j)) && dp[i-1][(mask^(1<<j))]!=-1)
				{
					ll z=dp[i-1][(mask^(1<<j))]+skill[x][j];
					if(z>dp[i][mask])
						dp[i][mask]=z;
				}
			}
		}
	}
	cout<<dp[n][(1<<p)-1]<<"n";
	return 0;
}

```
### [1316F - Battalion Strength](../problems/F._Battalion_Strength.md "CodeCraft-20 (Div. 2)")

**Author:** [gaurav172](https://codeforces.com/profile/gaurav172 "Candidate Master gaurav172")  
**Development:** [gaurav172](https://codeforces.com/profile/gaurav172 "Candidate Master gaurav172"), [shaanknight](https://codeforces.com/profile/shaanknight "Master shaanknight")

 **Tutorial**
### [1316F - Battalion Strength](../problems/F._Battalion_Strength.md "CodeCraft-20 (Div. 2)")

First lets try to find the initial strength of the army. Let $p_1,p_2,\ldots,p_n$ be the powers of officers in sorted order. .

Consider a pair ($i,j$) ($i < j$) and find how much it contributes to the answer, the term $p_i \cdot p_j$ will be present in the strength of the subsets in which both $i$ and $j$ are present and there is no $k$ such that $i < k < j$. Probability of this happening is $\frac {1}{2^{j-i+1}}$. By linearity of expectation we can say that the contribution of ($i,j$) to the strength of the army is $p_i \cdot p_j \cdot \frac {1}{2^{j-i+1}}$. 

So the strenth of the army can be written as $S = \sum_{i=1}^{n} \sum_{j=i+1}^{n} prob_{i,j} \cdot p_i \cdot p_j $ where $prob_{i,j} = \frac {1}{2^{j-i+1}}$.

We can keep a sorted array having $p_1,p_2,\ldots,p_n$, we can maintain a prefix sum of $pref_i$ = $p_i \cdot 2^{i-1}$,so $S = \sum_{j=1}^{n} pref_{j-1} \cdot \frac{p_j}{2^{j}}$. But this will not help in handling the updtes.

To support updates, we need to process queries offline and use coordinate compression such that all powers lie in range $(1,10^6)$. We can build a segment tree on the compressed powers.

For each node of the segment tree, let its range be $(s,e)$, consider that powers(mapped values by coordinate compression) $p_1,p_2,\ldots,p_k$ line in the range of this node ($s \leq p_1 \leq p_2 \leq \ldots \leq p_k \leq e$).

At each node, we need to maintain 4 values. 

* $val: \sum_{i=1}^{k} \sum_{j=i+1}^{k} prob_{i,j} \cdot p_i \cdot p_j$
* $Lval: \sum_{i=1}^{k} p_i \cdot 2^{i-1}$
* $Rval: \sum_{j=1}^{k} \frac{p_j}{2^{j}}$
* $count: k$

If we map each power to a unique value, the computation for this values at leaf node $(s=e)$ is trivial. If some power $p$ in the initial set is mapped to s, then values for this node are as follows

* $val: 0$
* $Lval: p$
* $Rval: \frac{p}{2}$
* $count: 1$.

 if no power in the initial set maps to s , all these values are set to zero.Lets try to compute these 4 values for non-leaf nodes of the segment tree. (lc and rc denote left and right children of the current node). If we try to write break these values in terms of their counterparts in lc and rc, we can easily write them as: 

* $val : val_{lc}+val_{rc}+\frac{Lval_{lc} \cdot Rval_{rc}}{2^{count_{lc}}}$
* $Lval : Lval_{lc} + Lval_{rc} \cdot 2^{count_{lc}}$
* $Rval : Rval_{lc} + \frac {Rval_{rc}}{2^{count_{lc}}}$
* $count : count_{lc} + count_{rc}$

Whenver we get a query ,we will need to update 2 leaves, reduce count of the power for old $p_i$ and increase the count of the new_power $p_i = x$. Answer to our problem would be $val$ at root node of the segment tree.

Time Complexity: $O((n+q)log(n))$

 **Solution**
```cpp
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ff first
#define ss second
#define pb push_back
#define all(a) a.begin(),a.end()
#define sz(a) (ll)(a.size())
const ll M=6e5+6;
const ll mod=1e9+7;
ll val[4*M],lt[4*M],rt[4*M];
int no[4*M];
ll pw[M],ipw[M];
int P[M],idx[M],qr[M],n,q;
vector<pair<int,int> > v;
ll power(ll a,ll b)
{
	ll val=1;
	while(b)
	{
		if(b%2)
			val=(val*a)%mod;
		b/=2;
		a=(a*a)%mod;
	}
	return val;
}
void build(int i,int s,int e)
{
	if(s==e)
	{
		if(v[s].ss>n)
			return;
		val[i]=0;
		lt[i]=v[s].ff;
		rt[i]=(v[s].ff*ipw[1])%mod;
		no[i]=1;
		return;
	}
	int m=(s+e)/2;
	int lc=2*i,rc=2*i+1;
	build(lc,s,m);
	build(rc,m+1,e);
	ll tp=(ipw[no[lc]]*rt[rc])%mod;
	tp=(tp*lt[lc])%mod;
	val[i]=(val[lc]+val[rc]+tp)%mod;
	lt[i]=(lt[lc]+pw[no[lc]]*lt[rc])%mod;
	rt[i]=(rt[lc]+ipw[no[lc]]*rt[rc])%mod;
	no[i]=(no[lc]+no[rc]);
}
void update(int i,int s,int e,int x,int y)
{
	if(s==e)
	{
		if(y==-1)
		{
			val[i]=0;
			lt[i]=0;
			rt[i]=0;
			no[i]=0;
		}
		else
		{
			val[i]=0;
			lt[i]=v[s].ff;
			rt[i]=(v[s].ff*ipw[1])%mod;
			no[i]=1;
		}
		return;
	}
	int m=(s+e)/2;
	int lc=(i<<1),rc=(lc|1);
	if(x<=m)
		update(lc,s,m,x,y);
	else
		update(rc,m+1,e,x,y);
	ll tp=(ipw[no[lc]]*rt[rc])%mod;
	tp=(tp*lt[lc])%mod;
	val[i]=(val[lc]+val[rc]+tp)%mod;
	lt[i]=(lt[lc]+pw[no[lc]]*lt[rc])%mod;
	rt[i]=(rt[lc]+ipw[no[lc]]*rt[rc])%mod;
	no[i]=(no[lc]+no[rc]);
}
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	pw[0]=1;
	ipw[0]=1;
	ll inv=power(2,mod-2);
	for(int i=1;i<M;i++)
	{
		pw[i]=(pw[i-1]*2)%mod;
		ipw[i]=(ipw[i-1]*inv)%mod;
	}
	cin>>n;
	v.pb({-1LL,-1});
	for(int i=1;i<=n;i++)
	{
		cin>>P[i];
		v.pb({P[i],i});
	}
	cin>>q;
	for(int i=1;i<=q;i++)
	{
		cin>>idx[i]>>qr[i];
		v.pb({qr[i],n+i});
	}
	sort(all(v));
	std::vector<int> pos(n+q+1,0);
	for(int i=1;i<sz(v);i++)
		pos[v[i].ss]=i;
	build(1,1,n+q);
	cout<<val[1]<<"n";
	for(int i=1;i<=q;i++)
	{
		update(1,1,n+q,pos[idx[i]],-1);
		pos[idx[i]]=pos[n+i];
		update(1,1,n+q,pos[idx[i]],1);
		cout<<val[1]<<"n";
	}
	return 0;
}
```
