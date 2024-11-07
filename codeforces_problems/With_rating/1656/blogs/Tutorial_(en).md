# Tutorial_(en)

[1656A - Good Pairs](../problems/A._Good_Pairs.md)

Author: [FelixMP](https://codeforces.com/profile/FelixMP "Master FelixMP") Preparator: [FelixMP](https://codeforces.com/profile/FelixMP "Master FelixMP")

 **Solution**
### [1656A - Good Pairs](../problems/A._Good_Pairs.md "CodeTON Round 1 (Div. 1 + Div. 2, Rated, Prizes!)")

By the [triangle inequality](https://codeforces.com/https://en.wikipedia.org/wiki/Triangle_inequality), for all real numbers x,y,z, we have: |x−y|+|y−z|≥|x−z|

with equality if and only if min(x,z)≤y≤max(x,z).

Now, take indices i and j such that ai and aj are the maximum and minimum values of the array, respectively. Then, for each index k, we have ai≥ak≥aj, meaning that |ai−ak|+|ak−aj|=ai−ak+ak−aj=ai−aj=|ai−aj|, as we desired.

 **Code**
```cpp
#include<bits/stdc++.h>
 
using namespace std;
 
int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		int minv = 1e9+1;
		int maxv = -1;
		int mini;
		int maxi;
		for(int i=0; i < n; ++i) {
			int a;
			cin >> a;
			if(a > maxv) {
				maxi = i+1;
				maxv = a;
			}
			if(a < minv) {
				mini = i+1;
				minv =  a;
			}
		}
		cout << mini << " " << maxi << endl;
	}
 
}

```
[1656B - Subtract Operation](../problems/B._Subtract_Operation.md)

Author: [FelixMP](https://codeforces.com/profile/FelixMP "Master FelixMP") Preparator: [xpov1LL](https://codeforces.com/profile/xpov1LL "Candidate Master xpov1LL")

 **Solution**
### [1656B - Subtract Operation](../problems/B._Subtract_Operation.md "CodeTON Round 1 (Div. 1 + Div. 2, Rated, Prizes!)")

Note that, after deleting element aj, all numbers in the set are of the form ai−aj, since the previous substractions are cancelled. Therefore, the final element will be the difference between the last element and the previous element which was erased. So we just need to check if k is the difference of two elements in the set, which can be done by sorting and using the double pointer technique in O(nlogn) time.

 **Code**
```cpp
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
 
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, a;
    	cin >> n >> a;
    	vector<int> v(n);
    	for(int& x : v) cin >> x;
    	bool ans = false;
    	if(n == 1) ans = (v[0] == a);
    	else {
    		sort(v.begin(), v.end());
    		int i = 0;
    		int j = 1;
    		while(j < n and i < n) {
    			if(v[i] + abs(a) == v[j]) {
    				ans = true;
    				break;
    			}
    			else if(v[i] + abs(a) < v[j]) ++i;
    			else ++j;
    		}
    	}
    	cout << (ans? "YES" : "NO") << 'n';   
    }
}
```
[1656C - Make Equal With Mod](../problems/C._Make_Equal_With_Mod.md)

Author: [FelixMP](https://codeforces.com/profile/FelixMP "Master FelixMP") Preparator: [FelixMP](https://codeforces.com/profile/FelixMP "Master FelixMP")

 **Solution**
### [1656C - Make Equal With Mod](../problems/C._Make_Equal_With_Mod.md "CodeTON Round 1 (Div. 1 + Div. 2, Rated, Prizes!)")

Note that, if 1 is not present in the array, we can always make all elements equal to 0 by repeatedly applying the operation with x=max(ai) until all elements become 0, as this operation will set the elements equal to the maximum to 0, while maintaining the others intact. So the answer is YES.

If 1 is present and there are no two consecutive numbers in the array, we can similarly apply repeatedly the operation with x=max(ai)−1 until all elements become 1, as this operation will set the elements equal to the maximum to 1, while maintaining the others intact. So the answer is again YES.

If 1 is present in the array, and there are two consecutive numbers m,m+1 in the array, the answer is NO. Note that if we have a 0 and a 1 in the array, we won't be able to make them equal after any number of operations, and so we cannot have any operation with an x that divides one of the ai's. The rest of operations will cause that m,m+1 remain consecutive (and thus different), meaning that it is impossible to make all the array equal.

 **Code**
```cpp
#include<bits/stdc++.h>
 
using namespace std;
 
typedef vector<int> vi;
 
 
int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vi a(n);
		for(int i=0; i < n; ++i) cin >> a[i];
		sort(a.begin(), a.end());
		bool one = false;
		bool consec = false;
		for(int i=0; i < n; ++i) {
			if(a[i] == 1) one = true;
			if(i < n-1 && a[i]+1 == a[i+1]) consec = true;
		}
 
		cout << ((one && consec) ? "NO" : "YES") << endl;
	}
 
}

```
[1656D - K-good](../problems/D._K-good.md)

Author: [FelixMP](https://codeforces.com/profile/FelixMP "Master FelixMP") Preparator: [FelixMP](https://codeforces.com/profile/FelixMP "Master FelixMP")

 **Solution**
### [1656D - K-good](../problems/D._K-good.md "CodeTON Round 1 (Div. 1 + Div. 2, Rated, Prizes!)")

n is k-good if and only if

* n≥1+2+…+k=k(k+1)2.
* n≡1+2+…+k≡k(k+1)2(modk).

It is clear that both conditions are necessary, and it turns out they're sufficient too since k(k+1)2+m⋅k is attainable for any integer m≥0 by repeatedly adding k to one of the terms in the sum 1+2+…+k.

Note that, if k is even, the second condition is n≡k2(modk), which is true if and only if 2n is a multiple of k but n is not a multiple of k. So all k which divide 2n but do not divide n satisfy the second condition, and we want the smallest of them in order to have the best chance of satisfying the first condition. The smallest of such k is k1=2ν2(n)+1, i. e. the smallest power of 2 that does not divide n. We can compute k1 in O(logn) (or in O(1) with some architecture-specific functions) and check if it satisfies the first condition.

If it doesn't, consider k2=2nk1. Note that k2 is odd, and therefore the second condition is satisfied since k2 is a divisor of n. Since k1 did not satisfy the condition, we have k1(k1+1)>2n⟹k2<k1+1⟹k2≤k1−1 (since k2 is odd), so:

k2(k2+1)2≤k2⋅k12=n

So k2 satisfies the first condition.

Note that k2 is only a valid answer if k2≠1. If k2=1, then we have that n is a power of 2, and in this case there is no answer since all odd candidates of k must be odd divisors of n, of which there is only 1, and the smallest even candidate for k was k1=2n, which does not work. So we have to answer −1. 

 **Code**
```cpp
#include<bits/stdc++.h>
 
using namespace std;
 
#define endl 'n'
 
typedef long long ll;
 
int main() {
    ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while(T--) {
		ll n;
		cin >> n;
		ll x = n;
		while(x % 2 == 0) x /= 2;
		if(x == 1) {
			cout << -1 << endl;
		}
		else if(x <= 2e9 && (x*(x+1))/2 <= n) {
			cout << x << endl;
		}
		else {
			cout << 2*(n/x) << endl;
		}
	}
}

```
[1656E - Equal Tree Sums](../problems/E._Equal_Tree_Sums.md)

Author: [FelixMP](https://codeforces.com/profile/FelixMP "Master FelixMP") Preparator: [FelixMP](https://codeforces.com/profile/FelixMP "Master FelixMP")

 **Solution**
### [1656E - Equal Tree Sums](../problems/E._Equal_Tree_Sums.md "CodeTON Round 1 (Div. 1 + Div. 2, Rated, Prizes!)")

Bicolor the tree, and put +deg(v) in vertices of one color and −deg(v) in vertices of the other color. 

Consider removing one vertex u. In each subtree, for each edge not incident with u, +1 will be added for one of the endpoints and −1 for the other endpoint, so the total contribution is 0. For the one edge in each subtree incident with u, the contribution will be +1 or −1 depending on the color of u. So the sums of the subtrees will all be equal to +1 or −1. 

 **Code**
```cpp
#include<bits/stdc++.h>
 
using namespace std;
 
typedef vector<int> vi;
typedef vector<vi> vvi;
 
vvi al;
vi ans;
 
void dfs(int u, int p, int c) {
	ans[u] = ((int)al[u].size())*c;
	for(int v : al[u]) {
		if(v != p) {
			dfs(v, u, -c);
		}
	}
}
 
int main() {
	int T;
	cin >> T;
	while(T--) {
		int n;
		cin >> n;
		al = vvi(n);
		for(int i=0; i < n-1; ++i) {
			int u, v;
			cin >> u >> v;
			u--;
			v--;
			al[u].push_back(v);
			al[v].push_back(u);
		}
		ans = vi(n);
		dfs(0, -1, 1);
		for(int i=0; i < n; ++i) {
			cout << ans[i];
			if(i < n-1) cout << " ";
		}
		cout << endl;
	}
}

```
[1656F - Parametric MST](../problems/F._Parametric_MST.md)

Author: [FelixMP](https://codeforces.com/profile/FelixMP "Master FelixMP") Preparator: [FelixMP](https://codeforces.com/profile/FelixMP "Master FelixMP")

 **Solution**
### [1656F - Parametric MST](../problems/F._Parametric_MST.md "CodeTON Round 1 (Div. 1 + Div. 2, Rated, Prizes!)")

Assume a1≤…≤an. We will try to connect each node u to the neighbour v that minimizes the cost function c(u,v)=auav+t(au+av). If by doing this we obtain a tree which is connected, it will clearly be an MST.

Let bi(t)=ai+t. We can rewrite c(u,v) as c(u,v)=bu(t)bv(t)−t2. So, if we fix t and u, this value will be minimized if v=n when bu(t)≤0 or v=1 when bu(t)≥0.

We have three cases: If there are positive and negative values of bi(t), connect all i with bi(t)<0 to v=n, and connect the rest to v=1. We see that we are adding n−1 edges (since we are counting the edge {1,n} twice), and that the resulting graph is connected since every node is connected to either 1 or n.

If all bi(t) are positive, connect all u≠1 to v=1; and if all are negative, connect all u≠n to v=n.

Now it is immediate to see that the MST will only change when some bi(t) changes its sign, that is, when t=−ak for some k, and that the total cost function will be piecewise affine. Furthermore, updating the total cost at each t=−ak can be done in O(1) time if we process nodes from 1 to n and we mantain some cumulative sums.

We are left with checking whether the MST total cost function goes to +∞ when t→±∞, which can be done by computing the slope of the MST total cost function at the limiting values t=−a1 and t=−an (which can be computed by adding the slopes of the cost functions of the edges, the construction of which we have previously mentioned).

 **Code**
```cpp
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;

int main() {
	int T;
	cin >> T;
	while(T--) {
		ll n;
		cin >> n;
		vi a(n);
		ll tsum = 0;
		for(int i=0; i < n; ++i) {
			cin >> a[i];
			tsum += a[i];
		}
		sort(a.begin(), a.end());
		if(a[n-1]*(n-2) + tsum < 0 || a[0]*(n-2) + tsum > 0) {
			cout << "INF" << endl;
			continue;
		}

		ll cslope = a[n-1]*(n-2) + tsum;
		ll cvalue = -(n-1)*a[n-1]*a[n-1];
		

		ll ans = cvalue;
		for(ll i=1; i < n; ++i) {
			ll d = a[n-i]-a[n-i-1];
			cvalue += cslope*d;
			ans = max(cvalue, ans);

			cslope += a[0]-a[n-1];


		}
		cout << ans << endl;
	}
}
```
[1656G - Cycle Palindrome](../problems/G._Cycle_Palindrome.md)

Author: [FelixMP](https://codeforces.com/profile/FelixMP "Master FelixMP") Preparator: [FelixMP](https://codeforces.com/profile/FelixMP "Master FelixMP")

 **Solution**
### [1656G - Cycle Palindrome](../problems/G._Cycle_Palindrome.md "CodeTON Round 1 (Div. 1 + Div. 2, Rated, Prizes!)")

We clearly see that the following two conditions are necessary:

* Each number must be repeated an even number of time except possibly one of the numbers. (This is necessary to find any permutation that results in a palindrome, not just a cycle).
* If n is odd, it can not be that the number a(n+1)/2 appears only one time. (Otherwise, the permutation would need to have one fixed point).

We will see that those two conditions are sufficient. First, let's focus on the n even case. Find any permutation σ so that applying it results in a palindrome. This permutation will have a cycle decomposition. We are going to merge all those cycles in one big cycle. 

To do so, we will first merge the cycles so that indices i and n−i+1 are in the same cycle for all i. Note that, since aσ(i)=aσ(n−i+1) we can define a new permutation σ′ with σ′(n−i+1)=σ(i) and σ′(i)=σ(n−i+1) and the permutation σ′ will still generate a palindrome and i and n−i+1 will be in the same cycle. We iterate over all the is and merge all such cycles. Note that we need to keep track efficiently of which indices are in the same cycle, so we should use union-find data structure.

Now we have m disjoint cycles which are symmetric, that is i and n−i+1 are in the same cycle. If m=1 we've won. Otherwise, let i1,…,im be indices belonging to each of the cycles and let σ be our current permutation. Note that if we define σ′(ij)=σ(n−ij+1+1) and σ′(n−ij+1)=σ(ij+1) for j=1,…,m−1 and σ′(im)=σ(i1), σ′(n−im+1)=σ(n−i1+1), we have another permutation σ′ which results in a palindrome and consists of only one cycle, so we're done.

There are different ways of handling the case when n is odd, the one that requires least casework for this solution is noticing that in the n odd case we can still merge symmetric cycles with no issues, and that the only thing that could make the last step fail would be to choose some index ij so that n−ij+1=ij. So we have to be careful not to choose ij=n+12, and in particular this means that the cycle that contains the middle element can not be a fixed point. If the second condition is satisfied, this can be achieved easily in the initial permutation we choose. 

Alternative solution:

Notice that the above solution has O(nα(n)) complexity because of union-find. Actually, a O(n) complexity can be achieved, we describe briefly an alternative solution with that complexity. We focus on the case when n is even. The idea is to start with a permutation whose cycles are already symmetric. In order to do so, we construct a graph whose vertices are the numbers that appear in the sequence and for each 1≤i≤n2 we add an edge between ai and an−i+1. Now note that for each of the connected components of the graph we can obtain a symmetric cycle resulting in a palindrome from an Eulerian tour of the graph. 

 **Code**
```cpp
#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

vi obtain_p_permutation(const vi& a) {
	int n = a.size();
	vi pp(n, -1);
	vi p(n);
	int cp = 0;
	vi cnt(n);
	for(int i=0; i < n; ++i) {
		cnt[a[i]]++;
	}
	for(int i=0; i < n; ++i) {
		if(pp[a[i]] == -1) {
			if(cnt[a[i]] == 1) {
				p[i] = n/2;
			}
			else {
				p[i] = cp;
				pp[a[i]] = n-cp-1;
				cp++;
				cnt[a[i]]--;
			}
		}
		else {
			p[i] = pp[a[i]];
			pp[a[i]] = -1;
			cnt[a[i]]--;
		}
	}
	return p;
}

vvi find_cycles(vi p, vi& in_cyc) {
	int n = p.size();
	vi vis = vi(n);
	vvi cycles;
	for(int i=0; i < n; ++i) {
		if(!vis[i]) {
			vi cyc;
			int v = i;
			while(!vis[v]) {
				cyc.push_back(v);
				in_cyc[v] = cycles.size();
				vis[v] = true;
				v = p[v];
			}
			cycles.push_back(cyc);
		}
	}
	return cycles;
}

int find_set(vi& dsu, int x) {
	if(dsu[x] == x) return x;
	return dsu[x] = find_set(dsu, dsu[x]);
}

void solve() {
	int n;
	cin >> n;
	vi a(n);
	vi cnt(n);
	for(int i=0; i < n; ++i) {
		cin >> a[i];
		a[i]--;
		cnt[a[i]]++;
	}
	int odd_i = -1;
	for(int i=0; i < n; ++i) {
		if(cnt[i]%2 == 1) {
			if(odd_i == -1) {
				odd_i = i;
			}
			else {
				odd_i = -2;
			}
		}
	}
	if(odd_i == -2) {
		cout << "NO" << endl;
	}
	else if(odd_i != -1 && (cnt[odd_i] == 1 && odd_i == a[n/2])) {
		cout << "NO" << endl;
	}
	else {

		vi p = obtain_p_permutation(a);
		if(odd_i != -1 && p[n/2] == n/2) {
			for(int i=0; i < n; ++i) {
				if(i != n/2 && a[i] == odd_i) {
					p[n/2] = p[i];
					p[i] = n/2;
					break;
				}
			}
		}
		vi rp(n);
		for(int i=0; i < n; ++i) {
			rp[p[i]] = i;
		}
		vvi cycles;
		vi in_cyc(n);
		cycles = find_cycles(p, in_cyc);


		vi dsu(n);
		for(int i=0; i < n; ++i) dsu[i] = i;
		for(int i=0; i < n; ++i) {
			if(find_set(dsu, in_cyc[i]) != find_set(dsu, in_cyc[n-i-1])) {
				dsu[find_set(dsu, in_cyc[i])] = find_set(dsu, in_cyc[n-i-1]);
				int j1 = rp[i];
				int j2 = rp[n-i-1];
				p[j2] = i;
				rp[i] = j2;
				p[j1] = n-i-1;
				rp[n-i-1] = j1;  
			}
		}
		cycles = find_cycles(p, in_cyc);
		int nc = cycles.size();
	

		vi prev_p = vi(p);
		vi prev_rp = vi(rp);

		for(int i=0; i < nc-1; ++i) {
			int i0 = cycles[i][0];
			int ip1 = cycles[(i+1)][0];
			p[prev_rp[n-i0-1]] = ip1;
			rp[ip1] = prev_rp[n-i0-1]; 
		}
		p[prev_rp[n-cycles[nc-1][0]-1]] = n-cycles[0][0]-1;
		rp[n-cycles[0][0]-1] = prev_rp[n-cycles[nc-1][0]-1];
		for(int i=0; i < nc-1; ++i) {
			int i0 = cycles[i][0];
			int ip1 = cycles[(i+1)][0];
			p[prev_rp[i0]] = n-ip1-1;
			rp[n-ip1-1] = prev_rp[i0];
		}
		p[prev_rp[cycles[nc-1][0]]] = cycles[0][0];
		rp[cycles[0][0]] = prev_rp[cycles[nc-1][0]];

		cout << "YES" << endl;
		for(int i=0; i < n; ++i) {
			cout << rp[i]+1 << " ";
		}
		cout << endl;

	}
	


}

int main() {
	int T;
	cin >> T;
	while(T--) {
		solve();
	}
}
```
[1656H - Equal LCM Subsets](../problems/H._Equal_LCM_Subsets.md)

Author: [FelixMP](https://codeforces.com/profile/FelixMP "Master FelixMP") Preparator: [FelixMP](https://codeforces.com/profile/FelixMP "Master FelixMP")

 **Solution**
### [1656H - Equal LCM Subsets](../problems/H._Equal_LCM_Subsets.md "CodeTON Round 1 (Div. 1 + Div. 2, Rated, Prizes!)")

First, we see how to check if the two entire sets have the same LCM (without subsets).

To do this, for each element a∈A let us compute f(a,B)=gcd(a/gcd(a,b1),…,a/gcd(a,bn)) and check if it is 1. If it is greater than 1, that means a has some prime power pk dividing it with exponent greater than any of the corresponding exponents in B, and therefore the LCM cannot be equal. We perform the same computations with the elements of B (i.e., f(b,A)). If all the results were 1, then the LCMs are equal. Complexity is O(n2⋅U), where U=log(1036).

If f(a,B)>1, we can simply delete a from A and solve recursively using the remaining sets (similarly if f(b,A)>1). We need to update the values f(a,B) and f(b,A) efficiently. We can do it using many segment tree (one for each a∈A, and one for each b∈B).

The segment tree of a∈A, STa, will have the elements of B as its leaves, and the node u of STa, which will include a range [i,j] of elements of B will be gcd(a/gcd(a,bi),…,a/gcd(a,bj)), meaning that after removing an element of B, we will need to recompute all of the n segment trees in O(logn+U) time each (it is O(logn+U) and not O(logn⋅U) by a similar argument to the one used to compute the complexity of computing the gcd of an array of numbers) . Since we have to repeat this for O(n) steps, the total time complexity will be O(n2⋅(logn+U)) and the memory complexity is O(n2).

 **Code**
```cpp
#include<bits/stdc++.h>
 
using namespace std;
 
typedef __int128 ll; 
typedef vector<ll> vi;
typedef vector<vi> vvi;
 
 
ll read_ll() {
	string s;
	cin >> s;
	ll x = 0;
	for(int i=0; i < (int)s.length(); ++i) {
		x *= 10;
		x += ll(s[i]-'0');
	}
	return x;
}
 
void print_ll(ll x) {
	vector<int> p;
	while(x > 0) {
		p.push_back((int)(x%10));
		x /= 10;
	}
	reverse(p.begin(), p.end());
	for(int y : p) cout << y;
}
 
inline ll ctz(ll x) {
	long long a = x&((ll(1)<<ll(63))-ll(1));
	long long b = x>>ll(63);
	if(a == 0) return ll(63)+__builtin_ctzll(b);
	return __builtin_ctzll(a);  
}
 
inline ll abll(ll x) {
	return x >= 0 ? x : -x;
}
 
ll gcd(ll a, ll b) {
	if(b == 0) return a;
	if(a == 0) return b;
 
	int az = ctz(a);
	int bz = ctz(b);
	int shift = min(az, bz);
	b >>= bz;
 
	while(a != 0) {
		a >>= az;
		ll diff = b-a;
		if(diff) az = ctz(diff);
		b = min(a, b);
		a = abll(diff);
	}
	return b << shift;
}
 
void init_st(vi& st, const vi& v) {
	int n = v.size();
	for(int i=0; i < n; ++i) {
		st[n+i] = v[i];
	}
	for(int i=n-1; i >= 1; --i) {
		st[i] = gcd(st[2*i], st[2*i+1]);
	}
}

void update_st(vi& st, int i, ll x) {
	int n = (int)st.size() / 2;
	int pos = n+i;
	st[pos] = x;
	while(pos > 1) {
		pos /= 2;
		st[pos] = gcd(st[2*pos], st[2*pos+1]);
	}
}
 
void solve(const vi& a, const vi& b, vector<bool>& ai, vector<bool>& bi) {
	int n = a.size();
	int m = b.size();
	vvi st_a = vvi(n, vi(2*m, 0));
	vvi st_b = vvi(m, vi(2*n, 0));
	for(int i=0; i < n; ++i) {
		vi af(m);
		for(int j=0; j < m; ++j) {
			af[j] = a[i]/gcd(a[i], b[j]);
		}
		init_st(st_a[i], af);
	}
	for(int i=0; i < m; ++i) {
		vi bf(n);
		for(int j=0; j < n; ++j) {
			bf[j] = b[i]/gcd(b[i], a[j]);
		}
		init_st(st_b[i], bf);
	}
	queue<int> dq;
	for(int i=0; i < n; ++i) {
		if(st_a[i][1] > 1) {
		       	dq.push(i);
			ai[i] = false;
		}
	}
	for(int i=0; i < m; ++i) {
		if(st_b[i][1] > 1) {
		       	dq.push(n+i);
			bi[i] = false;
		}
	}
	while(!dq.empty()) {
		int idx = dq.front();
		dq.pop();
		if(idx < n) {
			int i = idx;
			for(int j=0; j < m; ++j) {
				if(bi[j]) {
					update_st(st_b[j], i, b[j]);
					if(st_b[j][1] > 1) {
						dq.push(n+j);
						bi[j] = false;
					}
				}
			}
		}
		else {
			int i = idx-n;
			for(int j=0; j < n; ++j) {
				if(ai[j]) {
					update_st(st_a[j], i, a[j]);
					if(st_a[j][1] > 1) { 
						dq.push(j);
						ai[j] = false;
					}
				}
			}
		}
	}	
 
}
 
 
 
int main() {
	int T;
	cin >> T;
	while(T--) {
		int n, m;
		cin >> n >> m;
		vi a(n);
		vi b(m);
		for(int i=0; i < n; ++i) a[i] = read_ll();
		for(int i=0; i < m; ++i) b[i] = read_ll();
		vector<bool> ai(n, true);
		vector<bool> bi(m, true);
		solve(a, b, ai, bi);
		int as = 0;
		int bs = 0;
		for(int i=0; i < n; ++i) {
			if(ai[i]) as++;
		}
		for(int i=0; i < m; ++i) {
			if(bi[i]) bs++;
		}
		if(as == 0 || bs == 0) cout << "NO" << endl;
		else {
			cout << "YES" << endl;
			cout << as << " " << bs << endl;
			for(int i=0; i < n; ++i) {
				if(ai[i]) {
					print_ll(a[i]);
					cout << " ";
				}
			}
			cout << endl;
			for(int i=0; i < m; ++i) {
				if(bi[i]) {
					print_ll(b[i]);
					cout << " ";
				}
			}
			cout << endl;
			
 
		}
	}
}

```
[1656I - Neighbour Ordering](../problems/I._Neighbour_Ordering.md)

Author: [FelixMP](https://codeforces.com/profile/FelixMP "Master FelixMP") Preparator: [FelixMP](https://codeforces.com/profile/FelixMP "Master FelixMP")

 **Solution**
### [1656I - Neighbour Ordering](../problems/I._Neighbour_Ordering.md "CodeTON Round 1 (Div. 1 + Div. 2, Rated, Prizes!)")

First, note that, for each vertex v, the relative order between neighbours that belong to different biconnected components (i. e., neighbours u and w so that the edges vu and vw belong to different biconnected components) is irrelevant, since there can not be any (vertex-disjoint) cycle using edges from different biconnected components. Therefore, a good ordering for the entire graph will be possible if and only if a good ordering for each of the biconnected components is possible, and if so the ordering for the entire graph can be obtained from the orderings for each of the components by arbitrarily merging the lists of each component for each vertex (preserving the relative order for the lists of each component). Therefore, from now on we will assume that the graph is biconnected. Also, we assume that the graph has at least 3 vertices to avoid trivialities.

Lemma 1: If the graph G has a cycle C, and there are two vertices u,v∈C not adjacent in the cycle such that there is a path from u to v that passes through a vertex w∉C, then the graph G can not have a good ordering.

Proof: Assume the graph has a good ordering, and label the vertices of the cycle v1,v2,…,vn so that vi≤vi+1vi+2 and u=v1 and v=vj with j≠1,2,n. Let the path between vj and v1 be vj,w1,…,wp, where wp=v1, p>1, and we can assume that all wi lie outside the cycle. Considering the cycle v1,v2,…,vj,w1,…, we can see that since v1≤v2v3, it must happen too that vj≤w1w2. Now, considering the cycle wp,…,w1,vj,vj+1,…,vn, we see that since vj≤vj+1vj+2 (with possibly vj+2=v1), we must have w2≤w1vj. Since w2≠vj, we can't have the inequality both ways and we reach a contradiction. ◻

Theorem: If the (biconnected) graph G has a good ordering, then it has a hamiltonian cycle.

Proof: Assume it doesn't have a hamiltonian cycle. Since it is biconnected with at least 3 vertices, it must have some cycle. Let v1,…,vc be a longest cycle of the graph. Because the cycle does not visit all the vertices of the graph and the graph is connected, there must be some vertex u not in the cycle which is a neighbour of a vertex vi in the cycle. Because the graph is biconnected, there must be some path w1,…,wd not passing through vi with w1=u and wd=vj, a vertex in the cycle. We can choose the path so that vertices w1,…,wd−1 are not in the cycle, since we can just finish the path at the first vertex that is in the cycle. Now we consider two cases:

* Case 1: vi and vj are adjacent in the cycle (i. e. j=i+1 or j=i−1, where we admit taking indices modulo c). Now we can consider the cycle v1,…,vi,w1,…,wd−1,vj,…,vc, which is strictly longer than the original cycle, but we said it was a longest cycle, contradiction.
* Case 2: vi and vj are not adjacent in the cycle. Assume i<j and consider the cycle v1,…,vi,w1,…,wd−1,vj,…,vc. We have a path vi,vi+1,…,vj that passes through vertices not in the cycle, so by the first lemma it is not possible to have a good ordering, contradiction.

 ◻Now, let's see how we can compute this hamiltonian cycle efficiently. The argument we used in the proof already gives a good algorithm: we find a cycle, and repeatedly find paths that go out of the cycle and then return to it. We will either find a path which returns to an adjacent vertex and therefore we can use it to augment the cycle (Case 1) or we will find that it is impossible to have a good ordering and halt (Case 2). However, implementing this directly is in worst case O(n2). We will find a way to implement this idea in O(n) time, using properties of the DFS tree. 

Lemma 2: In a DFS tree of a (biconnected) graph G with a good ordering, each vertex can have at most two children.

Proof: Suppose that some vertex u has more than two children. Because the graph is biconnected, we have u can not be the root, and that from each of the child subtrees there is a back edge to a proper ancestor of u. Let v1,v2,v3 be three children of u that have back edges (in their respective subtrees) to three vertices w1,w2,w3 with depth(w1)≤depth(w2)≤depth(w3), where depth is the depth in the DFS tree. Consider the cycle v1,u,v2,…,w2,…,w1,… (goes back to v1) and the path w2,…,w3,…,v3,u between w2 and u, two non-adjacent vertices in the cycle. This contradicts lemma 1. ◻ 

Lemma 3: In a DFS tree of a (biconnected) graph G with a good ordering, consider a vertex u that is not the root and whose parent v is not the root either with two children u1 and u2, and let Low(ui) be the vertex with least depth that can be reached with a back edge from the subtree of ui. Then there is exactly one i such that Low(ui)=v

Proof: Assume that Low(u1) and Low(u2) are both proper ancestors of v (they can not be descendants of v since the graph is biconnected). Then, if we consider the cycle which includes the path u1,u,u2 and then cycles back using back edges without passing through v, we have a contradiction with lemma 1 considering the path from some vertex in the cycle which is a proper ancestor of v to u going down the DFS tree. Therefore, at least one of Low(u1) or Low(u2) is equal to v. 

Now let's see that it can not happen that Low(u1)=Low(u2)=v. Assume that it is the case. Since the graph is biconnected, we must have that Low(u)≠v since it must be a proper ancestor of v (note that here we are using that v is not the root). Therefore, since the two children subtrees don't have back edges to vertices higher than v, u must have a back edge to Low(u). Consider the cycle u,u1,…,v,parent(v),…,Low(u). Now with the path u,u2,…,v lemma 1 is violated. ◻

Lemma 4: In a DFS tree of a (biconnected) graph G with a good ordering, consider a vertex u that is not the root with parent v and with only one child u1. If Low(u1)≠Low(u), then Low(u1)=v.

Proof: Consider the cycle u,u1,…,Low(u1),…. If u1 and Low(u1) are not adjacent, the path u,Low(u),…,Low(u1) violates lemma 1. ◻

Theorem: In a DFS tree of a (biconnected) graph G with a good ordering, we can partition the front edges into:

* One path of the form u1,…,up, where ui+1 is the parent of ui for 1≤i<p, and up is the root, and there is a back edge between u1 and up.
* Some paths of the form u1,…,up, where ui+1 is the parent of ui for 1≤i<p, and there is a back edge between u1 and the parent of up.

Proof: Let u be a vertex which is not the root. We say that the representative back edge associated with vertex u is the back edge from u's subtree that goes to Low(u): if there are multiple such back edges, we choose the one that has as the other vertex the one that has a highest DFS visitation number. We partition the front edges (u,parent(u)) into groups with the same representative edge associated with u. We have to prove that this partition has the desired properties.

Let u,v be vertices with the same representative edge. One vertex must be an ancestor of the other (otherwise their subtrees would be disjoint and they can not have the same back edges), and every vertex in the path going from one to the other in the tree has the same representative edge (if there was some better edge, the higher vertex would have it as a representative). This proves that the groups form paths of the form u1,…,up, where ui+1 is the parent of ui for 1≤i<p (note that here u1,…,up−1 would be the vertices with the same representative edge but up wouldn't; up is in the path because the partition is of edges, not vertices, and (up−1,parent(up−1)) is an edge in the group).

Now, let's see the other property. It is clear that u1, the vertex with most depth of the path, has the representative edge of the path as one of its back edges. Now consider up. We have multiple cases:

1. up is not the root and it has only one child up−1. Then since it doesn't have the same representative edge necessarily it must have a back edge and Low(up)≠Low(up−1). By lemma 4, we must have Low(up−1)=parent(up) and the back edge from u1 goes to the parent of up, as desired.
2. up is not the root, its parent is not the root either, and it has two children, one of which is up−1. Then by lemma 3, exactly one of the two children has its Low value equal to the parent of up. If it were not up−1, then up would have the same representative edge as up−1, which is not possible since it is the endpoint of the path. Therefore again we have Low(up−1)=parent(up), and the back edge from u1 goes to the parent of up.
3. up is the child of the root and it has two children. Now we must have once again Low(up−1)=parent(up) once again because there is no other vertex with least depth than the parent of up, and the back from u1 goes to the parent of up.
4. up is the root. This happens for only for one path, and clearly there must be a back edge from u1 to up.

 ◻This is just what we wanted: doing just one DFS we can get one initial cycle and a series of paths we can use to successively augment our cycle until we have a hamiltonian cycle. One way to implement this is the following: first, we partition the graph into paths as in the previous theorem (we can mantain the representative back edge during the DFS; if a violation of the properties proven in the lemmas is detected, we halt). Then, we begin exploring the initial path (the one that forms a cycle with the root) in a downwards direction that is, first we visit up, then its child up−1, until we visit u1, which has a edge back to up. When we visit one vertex, we push it into a vector that will contain the hamiltonian cycle at the end. If at some point we visit a vertex that is the parent of the endpoint of another path, we recursively visit that path and after visiting it we continue with our original path. But when recursively visiting the new path, we traverse it upwards, that is, we start with u1 and go up to the parent of the vertex. If at some point we visit the endpoint of some other path, we again do a recursive visit of that path, this time in downwards direction. This way, we end up visiting all paths in a DFS-like way, and since we alternate between upward and downward traversals we end up having all the vertices of the graph in the vector ordered in a way that they form a hamiltonian cycle. 

Now that we have found how to compute that hamiltonian cycle in linear time (or halt if we find that some of the necessary conditions for a good ordering are violated), let's see an additional necessary condition for a good ordering.

Theorem: In a (biconnected) graph G with a good ordering, for any hamiltonian cycle, then there can not be any pair of edges that "cross", that is, if we draw the graph with vertices placed in a circle in the hamiltonian cycle order and with non-cycle edges drawn as chords, no two chords intersect. 

Proof: Assume that two edges cross. We can label the vertices v1,…,vn so that v1,…,vn forms the hamiltonian cycle in that order, vk≤vk+1vk+2 and the endpoints of the chords are v1,vi and vp,vq, with 1<p<i<q≤n. Consider the cycle v1,v2,…,vp,vq,vj+1,…. Because of the orientation of the hamiltonian cycle (note that there are at least three consecutive vertices from the hamiltonian cycle in this cycle) we have that vp−1≤vpvq. Similarly for the cycle v1,vi,vi+1,…,vn, we see that v1≤vivi+1. But now consider the cycle v1,vi,vi+1,…,vq,vp,vp−1,…. Because v1≤vivi+1, we must also have vq≤vpvp−1, contradiction. ◻

Once we have found the hamiltonian cycle, this property can be checked in linear time. And now the properties we have checked are not only necessary but also sufficient:

Theorem: A biconnected graph G with a hamiltonian cycle v1,…,vn such that non-cycle edges do not cross admits a good ordering. 

Proof: We assign an ordering by choosing one orientation of the cycle, and ordering the edges of each vertex by how far is the endpoint of the edge traversing the cycle in that orientation. We have to prove that this is a good ordering. Let vi1,vi2,…,vic be any cycle, and label the vertices v1,…,vn so that i1=1 and vi1≤vi2vi3 according to the orientation. If we show that i1<…<ic, we will have shown that the cycle is consistent with the ordering. We already have i1<i2<i3 by the labelling choice. Note that is ik<ik−1 is the first index to break the inequality, then if 1<ik<ik−2 the edge between ik−1 and ik crosses some previous edge, and if ik−2<ik, then the cycle from then onwards be contained in the interval between vertices vik−2 and vik−1, which is not possible since vertex v1 lies outside. ◻

This ordering can be reconstructed in time O(mlogm) by applying any standard sorting algorithm to the adjacency lists of the vertices (the comparison function is different for each vertex), and it can be improved to linear time by making an array of pairs consisting on the information of all the adjacency lists (each edge is included two times in the array, one for each end), sorting the array in linear time using counting sort, and then for each of the vertices the sorted adjacency list can be restored by applying one splice operation to the list given in the order in which the array was sorted. 

 **Code**
```cpp
#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;

struct graph {
	int n;
	int m;

	vvi al;
	vi morphism;

	vvi dfs_children;
	vi dfs_parent;
	vi dfs_num;
	vi dfs_low;
	int dfs_count;

	bool is_root_ac = false;

	bool bad_biccon = false;
	vii repr_edge;

	void dt_dfs(int v, int par) {
		dfs_parent[v] = par;
		dfs_num[v] = dfs_low[v] = dfs_count++;
		for(int u : al[v]) {
			if(u == par) {
				//Nothing
			}
			else if(dfs_num[u] == -1) {
				dfs_children[v].push_back(u);
				dt_dfs(u, v);
				dfs_low[v] = min(dfs_low[v], dfs_low[u]);
			}
			else {
				dfs_low[v] = min(dfs_low[v], dfs_num[u]);
			}
		}
	}

	ii min_repr_edge(ii a, ii b) {
		if(a.first == -1) return b;
		if(b.first == -1) return a;
		if(dfs_num[a.second] < dfs_num[b.second]) return a;
		if(dfs_num[a.second] > dfs_num[b.second]) return b;
		if(dfs_num[a.first] > dfs_num[b.first]) return a;
		if(dfs_num[a.first] < dfs_num[b.first]) return b;
		return a;
	}

	void dt_dfs_hamil(int v) {
		repr_edge[v] = ii(-1, -1);

		for(int u : dfs_children[v]) {
			dt_dfs_hamil(u);
			repr_edge[v] = min_repr_edge(repr_edge[v], repr_edge[u]);
		}

		for(int u : al[v]) {
			if(u == dfs_parent[v]) {
				//Nothing
			}
			else if(dfs_num[u] < dfs_num[v]) {
				repr_edge[v] = min_repr_edge(repr_edge[v], ii(v, u));
			}

		}

		if(dfs_parent[v] == -1) {
			//Root case
			
			//Nothing more to check, repr_edge will always be set correctly.
		}
		else {
			if(dfs_children[v].size() == 0) {
				//Nothing to check
			}
			else if(dfs_children[v].size() == 1) {
				//Lemma 4
				if(dfs_low[dfs_children[v][0]] != dfs_low[v] && dfs_low[dfs_children[v][0]] != dfs_num[dfs_parent[v]]) {
					bad_biccon = true;
				}
			}
			else if(dfs_children[v].size() == 2) {
				//Lemma 3
				if(dfs_parent[dfs_parent[v]] != -1) {
					if(!((dfs_low[dfs_children[v][0]] == dfs_num[dfs_parent[v]]) ^ (dfs_low[dfs_children[v][1]] == dfs_num[dfs_parent[v]]))) {
						bad_biccon = true;
					}
				}
				if(dfs_low[v] < min(dfs_low[dfs_children[v][0]], dfs_low[dfs_children[v][1]])) {
					bad_biccon = true;
				}
			}
			else {
				bad_biccon = true;
			}
		}
	}

	void dt_dfs_cedges(vvii& cedges, vii& edge_stack, int v, int par) {
		dfs_parent[v] = par;
		dfs_num[v] = dfs_low[v] = dfs_count++;
		for(int u : al[v]) {
			if(u == par) {
				//Nothing
			}
			else if(dfs_num[u] == -1) {
				dfs_children[v].push_back(u);
				edge_stack.emplace_back(v, u);
				dt_dfs_cedges(cedges, edge_stack, u, v);
				dfs_low[v] = min(dfs_low[v], dfs_low[u]);

				if((par == -1 && is_root_ac) || (par != -1 && dfs_low[u] >= dfs_num[v])) {
					vii comp;
					while(edge_stack.back().first != v || edge_stack.back().second != u) {
						comp.push_back(edge_stack.back());
						edge_stack.pop_back();
					}
					comp.push_back(edge_stack.back());
					edge_stack.pop_back();
					cedges.push_back(comp);
				}
			}
			else {
				dfs_low[v] = min(dfs_low[v], dfs_num[u]);
				if(dfs_num[u] < dfs_num[v]) {
					edge_stack.emplace_back(v, u);
				}
			}
		}
	}

	void generate_dfs_tree(int root) {
		dfs_children = vvi(n, vi());
		dfs_parent = vi(n);
		dfs_count = 0;
		dfs_num = vi(n, -1);
		dfs_low = vi(n, -1);
		dt_dfs(root, -1);
	}

	void generate_edge_partition(vvii& cedges, vii& edge_stack, int root) {
		generate_dfs_tree(root);
		is_root_ac = (dfs_children[root].size() > 1);

		dfs_children = vvi(n, vi());
		dfs_parent = vi(n);
		dfs_count = 0;
		dfs_num = vi(n, -1);
		dfs_low = vi(n, -1);
		dt_dfs_cedges(cedges, edge_stack, root, -1);
		if(!edge_stack.empty()) cedges.push_back(edge_stack);
	}

	void generate_hamil_dfs_tree(int root) {
		generate_dfs_tree(root);
		repr_edge = vii(n, ii());
		dt_dfs_hamil(root);
	}
};

vector<graph> partition_biconnected(graph& g) {
	vvii cedges;
	vii edge_stack;
	g.generate_edge_partition(cedges, edge_stack, 0);
	vector<graph> comp;
	for(vii& vec : cedges) {
		graph h;
		h.n = 0;
		h.m = vec.size();
		unordered_map<int, int> rmorph;
		for(ii e : vec) {
			if(rmorph.find(e.first) == rmorph.end()) {
				rmorph[e.first] = h.n++;
			}
			if(rmorph.find(e.second) == rmorph.end()) {
				rmorph[e.second] = h.n++;
			}
		}
		h.morphism = vi(h.n);
		h.al = vvi(h.n);
		for(ii e : vec) {
			int u = rmorph[e.first];
			int v = rmorph[e.second];
			h.morphism[u] = g.morphism[e.first];
			h.morphism[v] = g.morphism[e.second];
			h.al[u].push_back(v);
			h.al[v].push_back(u);
		}
		comp.push_back(h);
	}
	return comp;
}

void upwards_path(graph& g, vi& hc, int v, int tar);

void downwards_path(graph& g, vi& hc, int v, int tar);

void upwards_path(graph& g, vi& hc, int v, int tar) {
	if(g.dfs_children[v].size() == 2) {
		int u1 = g.dfs_children[v][0];
		int u2 = g.dfs_children[v][1];
		if(g.repr_edge[u1] == g.repr_edge[v]) swap(u1, u2);
		hc.push_back(v);
		downwards_path(g, hc, u1, g.repr_edge[u1].first);
		if(v != tar) { 
			upwards_path(g, hc, g.dfs_parent[v], tar);
		}
	}
	else if(g.dfs_children[v].size() == 1) {
		int u = g.dfs_children[v][0];
		hc.push_back(v);
		if(g.repr_edge[u] != g.repr_edge[v]) {
			downwards_path(g, hc, u, g.repr_edge[u].first);
		}
		if(v != tar) {
			upwards_path(g, hc, g.dfs_parent[v], tar);
		}
	}
	else {
		hc.push_back(v);
		if(v != tar) {
			upwards_path(g, hc, g.dfs_parent[v], tar);
		}
	}
}

void downwards_path(graph& g, vi& hc, int v, int tar) {
	if(g.dfs_children[v].size() == 2) {
		int u1 = g.dfs_children[v][0];
		int u2 = g.dfs_children[v][1];
		if(g.repr_edge[u1] == g.repr_edge[v]) swap(u1, u2);
		upwards_path(g, hc, g.repr_edge[u1].first, u1);
		hc.push_back(v);
		downwards_path(g, hc, u2, tar);
	}
	else if(g.dfs_children[v].size() == 1) {
		int u = g.dfs_children[v][0];
		if(v == tar) {
			upwards_path(g, hc, g.repr_edge[u].first, u);
			hc.push_back(v);
		}
		else {
			hc.push_back(v);
			downwards_path(g, hc, u, tar);
		}
	}
	else {
		hc.push_back(v);
	}
}

vi hamiltonian_cycle(graph& g) {
	g.generate_hamil_dfs_tree(0);
	if(g.bad_biccon) return vi();
	vi hc;
	downwards_path(g, hc, 0, g.repr_edge[0].first);
	assert((int)hc.size() == g.n);
	return hc;
}

int comp_index;
bool cyclic_comparator(int a, int b) {
	if(a < comp_index) a += 1e7;
	if(b < comp_index) b += 1e7;
	return a < b;
}

graph sort_graph(const graph& g, const vi& hc) {
	graph h;
	h.n = g.n;
	h.m = g.m;
	h.morphism = vi(g.n);
	h.al = vvi(g.n);
	vi rhc(g.n);
	for(int i=0; i < g.n; ++i) {
		h.morphism[i] = g.morphism[hc[i]];
		rhc[hc[i]] = i;
	}
	for(int i=0; i < g.n; ++i) {
		for(int j : g.al[hc[i]]) {
			h.al[i].push_back(rhc[j]);
		}
		comp_index = i;
		//This is m log m, can be improved
		sort(h.al[i].begin(), h.al[i].end(), cyclic_comparator);
	}
	return h;
}

bool has_crossing(const graph& g) {
	vii bad_stack;
	for(int i=0; i < g.n; ++i) {
		comp_index = i;
		while(!bad_stack.empty() && i == bad_stack.back().first) bad_stack.pop_back();
		for(int j=(int)g.al[i].size()-2; j > 0; --j) {
			int u = g.al[i][j];
			if(!bad_stack.empty() && cyclic_comparator(bad_stack.back().first, u) && cyclic_comparator(u, bad_stack.back().second)) {
				return true;
			}
			if(u > i && (bad_stack.empty() || u != bad_stack.back().first)) {
				bad_stack.emplace_back(u, i);
			}
		}
	}
	return false;
}

void merge_ans(const graph& g, vvi& ans) {
	for(int i=0; i < g.n; ++i) {
		for(int j : g.al[i]) {
			ans[g.morphism[i]].push_back(g.morphism[j]);
		}
	}
}

void merge_single_edge_ans(const graph& g, vvi& ans) {
	int u = g.morphism[0];
	int v = g.morphism[1];
	ans[u].push_back(v);
	ans[v].push_back(u);
}

vvi solve(graph& input_graph) {
	vvi ans(input_graph.n);
	vector<graph> components = partition_biconnected(input_graph);
	for(graph g : components) {
		if(g.n == 1) {
			//Nothing
		}
		else if(g.n == 2) {
			merge_single_edge_ans(g, ans);
		}
		else {
			vi hc = hamiltonian_cycle(g);
			if(hc.empty()) {
				return vvi();
			}
			graph g2 = sort_graph(g, hc);
			if(has_crossing(g2))  return vvi();
			merge_ans(g2, ans);
		}
	}	
	return ans;
}

graph read_graph() {
	graph g;
	int n, m;
	cin >> n >> m;
	g.n = n;
	g.m = m;
	g.al = vvi(n, vi());
	g.morphism = vi(n, 0);
	for(int i=0; i < n; ++i) {
		g.morphism[i] = i;
	}
	for(int i=0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		g.al[u].push_back(v);
		g.al[v].push_back(u);
	}
	return g;
}

void print_ans(const vvi& ans) {
	int n = ans.size();
	if(n == 0) {
		cout << "NO" << endl;
	}
	else {
		cout << "YES" << endl;
		for(int i=0; i < n; ++i) {
			for(int x : ans[i]) {
				cout << x << " ";
			}
			cout << endl;
		}
	}
}

int main() {
	int T;
	cin >> T;
	while(T--) {
		graph input_graph = read_graph();
		vvi ans = solve(input_graph);
		print_ans(ans);
	}
}
```
