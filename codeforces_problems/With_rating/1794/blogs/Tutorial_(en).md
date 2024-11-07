# Tutorial_(en)

Thanks for participating in the round! I hope you enjoyed the problems! 

[1794A - Prefix and Suffix Array](../problems/A._Prefix_and_Suffix_Array.md "Codeforces Round 856 (Div. 2)")

 **Solution**
### [1794A - Prefix and Suffix Array](../problems/A._Prefix_and_Suffix_Array.md "Codeforces Round 856 (Div. 2)")

Observe that there are exactly two strings of length n−1 (one prefix and one suffix). We will call them x and y. Then, s is a palindrome if and only if rev(x)=y, where rev(x) is the reversal of string x.

So, to solve the problem it is enough to find the two strings of length n−1 and check if one of them is equal to the reversal of the other. This solution also works for any length greater or equal to ⌊n2⌋.

Intended complexity: O(n2) per test case. (reading the input)

 **Code**
```cpp
#include <bits/stdc++.h>
using namespace std;
 
int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	for(int test_number = 0; test_number < t; test_number++){
		int n; cin >> n;
		vector <string> long_subs;
		for(int i = 0; i < 2 * n - 2; i++){
			string s; 
			cin >> s;
			if((int)s.size() == n - 1){
				long_subs.push_back(s);
			}
		}
		reverse(long_subs[1].begin(), long_subs[1].end());
		if(long_subs[0] == long_subs[1]){
			cout<<"YESn";
		}else{
			cout<<"NOn";
		}
	}
	
	return 0;
}
```
 **Feedback*** Amazing problem: 


[*73*](https://codeforces.com/data/like?action=like "I like this")
* Good problem: 

 
[*313*](https://codeforces.com/data/like?action=like "I like this")
* Bad problem: 

 
[*68*](https://codeforces.com/data/like?action=like "I like this")
* Didn't solve: 

 
[*30*](https://codeforces.com/data/like?action=like "I like this")
[1794B - Not Dividing](../problems/B._Not_Dividing.md "Codeforces Round 856 (Div. 2)")

 **Solution**
### [1794B - Not Dividing](../problems/B._Not_Dividing.md "Codeforces Round 856 (Div. 2)")

First, we add one to all the numbers in the array equal to 1. This uses at most n operations. Then, we iterate through the elements of the array from left to right, starting from the second element. At each step, let ax be the element we are iterating. If ax is divisible by ax−1, we add one to ax. Now this element is not divisible by ax−1, because otherwise both ax and ax+1 are divisible by ax−1, but that means 1 is also divisible by ax−1 which cannot happen since all the elements in the array are at least 2 (because of the first step we did). This part also uses at most n operations, so we used at most 2n operations in total. The resulting array will satisfy the statement property.

Intended complexity: O(n) per test case.

 **Code**
```cpp
#include <bits/stdc++.h>
using namespace std;
 
int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	for(int test_number = 0; test_number < t; test_number++){
		int n; cin >> n;
		vector <int> a(n);
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		for(int i = 0; i < n; i++){
			if(a[i] == 1){
				a[i]++;
			}
		}
		for(int i = 1; i < n; i++){
			if(a[i] % a[i - 1] == 0){
				a[i]++;
			}
		}
		for(auto i : a){
			cout << i << " ";
		}
		cout << "n";
	}
	return 0;
}
```
 **Additional comment**Actually, the maximum number of operations performed by this algorithm is 32n. Try to prove it!

 **Feedback*** Amazing problem: 

 
[*125*](https://codeforces.com/data/like?action=like "I like this")
* Good problem: 

 
[*327*](https://codeforces.com/data/like?action=like "I like this")
* Bad problem: 

 
[*58*](https://codeforces.com/data/like?action=like "I like this")
* Didn't solve: 

 
[*25*](https://codeforces.com/data/like?action=like "I like this")
[1794C - Scoring Subsequences](../problems/C._Scoring_Subsequences.md "Codeforces Round 856 (Div. 2)")

 **Solution**
### [1794C - Scoring Subsequences](../problems/C._Scoring_Subsequences.md "Codeforces Round 856 (Div. 2)")

We will first see how to find the cost of a single non-decreasing sequence s1,s2,…,sℓ.

If we choose a subsequence with k elements, to achieve the maximum score it is optimal to choose the k largest elements. As the sequence is in non-decreasing order, the k largest elements will be the last k elements of the sequence. Thus, all possible candidates to be the answer are the suffixes of the sequence.

Now let's divide the i-th element from the right by i. The sequence now turns into s1ℓ,s2ℓ−1,…,sℓ−12,sℓ1. Observe that the score of a suffix in the original sequence is equal to the product of the suffix of the same size in the new sequence. 

The original sequence satisfies s1≤s2≤…≤sℓ−1≤sℓ. It also true that 1ℓ≤1ℓ−1≤…≤12≤11 then combining these two inequalities we have s1ℓ≤s2ℓ−1≤…≤sℓ−12≤sℓ1 so the new sequence is also in non-decreasing order.

In order to maximize the product of a suffix in the new sequence, we will choose all the elements in the new sequence which are greater or equal to 1 (these elements form a suffix because the new sequence is non-decreasing). If there are elements equal to 1 in the new sequence, we have to choose them in order to get the subsquence with maximum length (among all the ones with maximum score). 

Therefore, the cost of a sequence s1,s2,…,sℓ is the maximum length of a suffix of s1ℓ,s2ℓ−1,…,sℓ−12,sℓ1 such that each element is at least 1.

Now, we have to find the cost of every prefix of the given sequence [a1,a2,…,an]. For a fixed k, the cost of [a1,a2,…,ak] will be the maximum length of a suffix of a1k,a2k−1,…,ak−12,ak1 such that each element is at least 1. We can find this length using binary search. Observe that we cannot compute the transformed sequence for every prefix, as that will be too slow. Instead, we can compute in each step of the binary search what would the number in that position be in the transformed sequence. By doing these, we can find the score of each prefix in O(logn) time. 

Intended complexity: O(nlogn) per test case.

 **Code**
```cpp
#include <bits/stdc++.h>
using namespace std;
 
int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	for(int test_number = 0; test_number < t; test_number++){
		int n; cin >> n;
		vector <int> a(n);
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		vector<int> res;
		for(int i = 0; i < n; i++){
			int l = 1, r = i + 1;
			while(l <= r){
				int m = (l + r) / 2;
				if(a[i - m + 1] >= m){
					l = m + 1;
				}else{
					r = m - 1;
				}
			}
			res.push_back(r);
		}
		for(auto i : res){
			cout << i << " ";
		}
		cout<<"n";
	}
	return 0;
}

```
 **Feedback*** Amazing problem: 

 
[*217*](https://codeforces.com/data/like?action=like "I like this")
* Good problem: 

 
[*276*](https://codeforces.com/data/like?action=like "I like this")
* Bad problem: 

 
[*38*](https://codeforces.com/data/like?action=like "I like this")
* Didn't solve: 

 
[*49*](https://codeforces.com/data/like?action=like "I like this")
[1794D - Counting Factorizations](../problems/D._Counting_Factorizations.md "Codeforces Round 856 (Div. 2)")

 **Solution**
### [1794D - Counting Factorizations](../problems/D._Counting_Factorizations.md "Codeforces Round 856 (Div. 2)")

First, we will count how many times each different element in a occurs and check which of these elements are prime numbers. This can be done by checking for each element if it has a divisor up to its square root or using the Sieve of Eratosthenes.

To construct a number m such that f(m)={a1,a2,…,a2n} we have to choose n elements of a to be the primes in its factorization and n elements to be the exponents. The numbers we choose to be the primes in the factorization have to be prime numbers and distinct. If there are less than n distinct primes in a, then there is no number m satisfying the property. So, from now on we will assume there are at least n distinct prime numbers in a.

Let b1,b2,…,bs be the number of occurrences of each non-prime number in a and let c1,c2,…,ct be the number of occurrences of each prime number in a. After we choose the primes for the factorization, let c′1,c′2,…,c′t be the remaining number of occurrences of each prime number. As we can choose each prime number at most once, then c′i=ci or c′i=ci−1. For each way of choosing the primes, the number of possible values for m is n!b1!b2!…bs!c′1!c′2!…c′t! because this is the number of ways to choose where to place the exponents. The answer to the problem is the sum of all these numbers over all ways of choosing the prime numbers.

Observe that when we sum terms of the form n!b1!b2!…bs!c′1!c′2!…c′t!, the value n!b1!b2!…bs! is a common factor over all these terms. Thus, we just need to find the sum of the terms 1c′1!c′2!…c′t! and then multiply by the common factor.

To find this sum, we will use dynamic programming. Let g(x,y) be the sum considering only the primes from the x-th of them and assuming that y primes need to be chosen (or that n−y primes are already chosen). Then g(x,y)=1cx!×g(x+1,y)+1(cx−1)!×g(x+1,y−1). The value of g(1,n) will give the desired sum.

Intended complexity: O(n2) (plus the complexity of primality checking)

 **Code**
```cpp
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
const ll MOD = 998244353;
 
//checks if n is prime
bool is_prime(ll n){
	if(n == 1){
		return false;
	}
	for(ll i = 2; i * i <= n; i++){
		if(n %i == 0){
			return false;
		}
	}
	return true;
}
 
//computes b ** e % MOD
ll fast_pow(ll b, ll e){
	ll res = 1;
	while(e > 0){
		if(e % 2 == 1){
			res = res * b % MOD;
		}
		b = b * b % MOD;
		e /= 2;
	}
	return res;
}
 
vector<pair<ll, ll>> primes;
 
const int MAXN = 5050;
 
ll dp[MAXN][MAXN];
 
ll fact[MAXN], fact_inv[MAXN];
 
ll f(ll x, ll y){
	ll &res = dp[x][y];
	if(res >= 0){
		return res;
	}
	if(x == (int)primes.size()){
		return res = (y == 0);
	}
	res = fact_inv[primes[x].second] * f(x + 1, y) % MOD;
	if(y > 0){
		res = (res + fact_inv[primes[x].second - 1] * f(x + 1, y - 1)) % MOD;	
	}
	return res;
}
 
int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//reading the input
	int n; cin >> n;
	vector<ll> a(2 * n);
	for(int i = 0; i < 2 * n; i++){
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	//compressed version of a, pairs {value, #occurrences}
	vector<pair<ll, ll>> a_comp;
	for(int i = 0; i < 2 * n; i++){
		if(a_comp.size() == 0u || a_comp.back().first != a[i]){
			a_comp.push_back({a[i], 1});
		}else{
			a_comp.back().second++;
		}
	}
	//computing factorials and inverses
	fact[0] = 1;
	for(ll i = 1; i < MAXN; i++){
		fact[i] = fact[i-1] * i % MOD;
	}
	fact_inv[0] = 1;
	for(ll i = 0; i < MAXN; i++){
		fact_inv[i] = fast_pow(fact[i], MOD - 2);
	}
	//adding only primes for the dp
	for(auto i : a_comp){
		if(is_prime(i.first)){
			primes.push_back(i);
		}
	}
	memset(dp, -1, sizeof(dp));
	ll res = f(0, n);
	//we have to consider the contribution of non-primes too!
	for(auto i : a_comp){
		if(!is_prime(i.first)){
			res = res * fact_inv[i.second] % MOD;
		}
	}
	res = res * fact[n] % MOD;
	cout << res << "n";
	return 0;
}
```
 **Additional comment**It is possible to solve the problem with greater constraints, like n≤105. Try to solve it with this new constraint!

 **Feedback*** Amazing problem: 

 
[*371*](https://codeforces.com/data/like?action=like "I like this")
* Good problem: 

 
[*57*](https://codeforces.com/data/like?action=like "I like this")
* Bad problem: 

 
[*11*](https://codeforces.com/data/like?action=like "I like this")
* Didn't solve: 

 
[*85*](https://codeforces.com/data/like?action=like "I like this")
[1794E - Labeling the Tree with Distances](../problems/E._Labeling_the_Tree_with_Distances.md "Codeforces Round 856 (Div. 2)")

 **Solution**
### [1794E - Labeling the Tree with Distances](../problems/E._Labeling_the_Tree_with_Distances.md "Codeforces Round 856 (Div. 2)")

First, count the number of occurrences of each element in the list a. Let these numbers be c0,c1,…,cn−1. Then, compute the polynomial hash of the array c, that is H=n−1∑i=0cibi where b is the base of the hash. Because the tree is unweighted, there are only n possible values to write in the unlabeled vertex (all integers between 0 and n−1). Including this extra number, the hash has n possibilities: H+bi for each i=0,1,…,n−1.

Now, let's compute the same hash for each vertex of the tree. That is, for each vertex x count how many vertices are at distances 0,1,…,n−1, and if these numbers are d0,d1,…,dn−1 compute the value hx=n−1∑i=0dibi. 

To compute these values efficiently, we will use rerooting dynamic programming: We will make two DFS. In the first one, compute the parent of each node and the hash of each node only considering the nodes in its subtree. For each vertex x, if we call this hash dpx then dpx=1+b∑childidpi. In the second one (which must be performed after the first one), for each vertex x compute the hash of the parent of x considering the nodes which are not in the subtree of vertex x. If we call this hash dp2x then dp2x=dppax−bdpx+bdp2pax where pax is the parent of x.

Now, observe that hx=dpx+bdp2x. With these hashes, we can compute the good vertices. A vertex x will be good if and only if hx=H+bi for some i=0,1,…,n−1. Doing a two pointers algorithm with the two sorted lists h1,h2,…,hn and H+1,H+b,H+b2,…,H+bn−1 is enough to find for each hx if there is a number on the other list equal to it.

To make the solution pass, it is advisable to use hashing with multiple modules or just one big modulo.

Intended complexity: O(nlogn).

 **Code**
```cpp
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
const int MAXN = 200005;
mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());
 
//Hashing stuff
const ll MOD[3] = {999727999, 1070777777, 1000000007};
ll B[3];
 
vector<ll> shift(vector<ll> h, ll val = 0){
	for(int k = 0; k < 3; k++){
		h[k] = (h[k] * B[k] + val) % MOD[k];
	}
	return h;
}
 
vector<ll> add(vector<ll> a, vector<ll> b){
	vector<ll> res(3);
	for(int k = 0; k < 3; k++){
		res[k] = (a[k] + b[k]) % MOD[k];
	}
	return res;
}
 
vector<ll> sub(vector<ll> a, vector<ll> b){
	vector<ll> res(3);
	for(int k = 0; k < 3; k++){
		res[k] = (a[k] - b[k] + MOD[k]) % MOD[k];
	}
	return res;
}
 
//Tree stuff
vector<int> g[MAXN];
 
bool vis[MAXN];
int parent[MAXN];
vector<ll> dp[MAXN], dp2[MAXN];
 
void dfs(int x){
	vis[x] = true;
	for(auto i : g[x]){
		if(!vis[i]){
			parent[i] = x;
			dfs(i);
			dp[x] = add(dp[x], shift(dp[i]));
		}
	}
	dp[x] = add(dp[x], {1, 1, 1});
}
 
void dfs2(int x){
	if(x != 0){
		dp2[x] = sub(dp[parent[x]], shift(dp[x]));
		dp2[x] = add(dp2[x], shift(dp2[parent[x]]));
	}
	for(auto i : g[x]){
		if(i != parent[x]){
			dfs2(i);
		}
	}
}
 
int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	for(int k = 0; k < 3; k++){
		B[k] = rng() % MOD[k];
	}
	//reading the input
	int n; cin >> n;
	vector<int> occurrences(n);
	for(int i = 0; i < n - 1; i++){
		int a; cin >> a;
		occurrences[a]++;
	}
	for(int i = 0; i < n - 1; i++){
		int u, v; cin >> u >> v;
		u--; v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	//calculating possible list hashes
	vector<vector<ll>> list_hashes;
	vector<ll> h = {0, 0, 0};
	for(int i = n - 1; i >= 0; i--){
		h = shift(h, occurrences[i]);
	}
	vector<ll> extra = {1, 1, 1};
	for(int i = 0; i < n; i++){
		list_hashes.push_back(add(h, extra));
		extra = shift(extra);
	}
	//calculating possible tree hashes
	for(int i = 0; i < n; i++){
		dp[i] = {0, 0, 0};
		dp2[i] = {0, 0, 0};
	}
	parent[0] = -1;
	dfs(0);
	dfs2(0);
	vector<pair<vector<ll>, int>> tree_hashes;
	for(int i = 0; i < n; i++){
		if(i == 0){
			tree_hashes.push_back({dp[i], i});
		}else{
			tree_hashes.push_back({add(dp[i], shift(dp2[i])), i});
		}
	}
	//calculting the answer
	sort(list_hashes.begin(), list_hashes.end());
	sort(tree_hashes.begin(), tree_hashes.end());
	vector<int> res;
	int pos = 0;
	for(auto lh : list_hashes){
		while(pos < n && tree_hashes[pos].first < lh){
			pos++;
		}
		while(pos < n && tree_hashes[pos].first == lh){
			res.push_back(tree_hashes[pos].second);
			pos++;
		}
	}
	sort(res.begin(), res.end());
	cout << res.size() << "n";
	for(auto i : res){
		cout << i + 1 << " ";
	}
	cout << "n";
	return 0;
}
```
 **Feedback*** Amazing problem: 

 
[*77*](https://codeforces.com/data/like?action=like "I like this")
* Good problem: 

 
[*15*](https://codeforces.com/data/like?action=like "I like this")
* Bad problem: 

 
[*13*](https://codeforces.com/data/like?action=like "I like this")
* Didn't solve: 

 
[*82*](https://codeforces.com/data/like?action=like "I like this")
