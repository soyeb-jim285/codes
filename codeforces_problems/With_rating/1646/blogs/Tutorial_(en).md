# Tutorial_(en)

Thanks for participating in the round! I hope you enjoyed the problems! 

[1646A - Square Counting](../problems/A._Square_Counting.md "Codeforces Round 774 (Div. 2)")

 **Solution**
### [1646A - Square Counting](../problems/A._Square_Counting.md "Codeforces Round 774 (Div. 2)")

Let the number of elements in the sequence equal to n2 be x and let the sum of all other numbers be u. Then, s=x⋅n2+u. If an element of the sequence is not equal to n2, then its value is at most is n−1. There are n+1 numbers in the sequence, so u≤(n−1)×(n+1)=n2−1. Thus, ⌊sn2⌋=⌊x⋅n2+un2⌋=⌊x+un2⌋=x, which is the value we want to find. So, to solve the problem it is enough to compute the value of ⌊sn2⌋.

Intended complexity: O(1) per test case. 

 **Code**
```cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
	int t; cin >> t;
	for(int i = 0; i < t; i++){
		long long n, s; 
		cin >> n >> s;
		cout << s / (n * n) << "n";
	}
	return 0;
}
```
[1646B - Quality vs Quantity](../problems/B._Quality_vs_Quantity.md "Codeforces Round 774 (Div. 2)")

 **Solution**
### [1646B - Quality vs Quantity](../problems/B._Quality_vs_Quantity.md "Codeforces Round 774 (Div. 2)")

 

Suppose Count(Red_)=k. If a solution exists, then there is one with Count(¯Blue)=k+1, because if there are more than k+1 numbers painted blue, we can remove some of them until we have exactly k+1 numbers, and the sum of these numbers will be smaller. 

As we want Sum(Red_)>Sum(¯Blue) to hold, the optimal way to paint the numbers is to paint the k largest numbers red, and the k+1 smallest numbers blue. 

So, to solve the problem it is enough to sort the sequence, iterate over the value of k and for each of them compute the sum of the k largest numbers, the sum of the k+1 smallest numbers and compare them. This can be done efficiently by computing the sum of every prefix and suffix of the sorted sequence in linear time. This way, we can make a constant number of operations for each k.

Intended complexity: O(nlogn)

 **Additional comment**It can be proven that (try to prove it!) if some k works, then k=⌊n−12⌋ has to work. This means that there is always an answer using n or n−1 elements, depending on parity.

 **Code**
```cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t; cin >> t;
	for(int test_number = 0; test_number < t; test_number++){
		int n; cin >> n;
		vector <long long> a(n);
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		sort(a.begin(), a.end());
		vector <long long> prefix_sums = {0};
		for(int i = 0; i < n; i++){
			prefix_sums.push_back(prefix_sums.back() + a[i]);
		}
		vector <long long> suffix_sums = {0};
		for(int i = n - 1; i >= 0; i--){
			suffix_sums.push_back(suffix_sums.back() + a[i]);
		}
		bool answer = false;
		for(int k = 1; k <= n; k++){
			if(2 * k + 1 <= n){
				long long blue_sum = prefix_sums[k + 1];
				long long red_sum = suffix_sums[k];
				if(blue_sum < red_sum){
					answer = true;
				}
			}
		}
		if(answer) cout << "YESn";
		else cout << "NOn";
	}
	return 0;
}
```
[1646C - Factorials and Powers of Two](../problems/C._Factorials_and_Powers_of_Two.md "Codeforces Round 774 (Div. 2)")

 **Solution**
### [1646C - Factorials and Powers of Two](../problems/C._Factorials_and_Powers_of_Two.md "Codeforces Round 774 (Div. 2)")

If the problem asked to represent n as a sum of distinct powers of two only (without the factorials), then there is a unique way to do it, using the binary representation of n and the number of terms will be the number of digits equal to 1 in this binary representation. Let's denote this number by ones(n).

If we fix the factorials we are going to use in the sum, then the rest of the terms are uniquely determined because of the observation above. Note that 1 and 2 will not be considered as factorials in order to avoid repeating terms.

So, to solve the problem it is enough to iterate through all possibilities of including or not including each factorial (up to 14!) and for each of them calculate the number of terms used in the sum. If we used f factorials and their sum is s, then the number of terms can be calculated as f+ones(n−s). The minimum of all these numbers will be the answer.

Intended complexity: O(2k) where k is the biggest positive integer such that k!≤n

 **Additional comment**Actually, there is no problem in repeating 1, 2, or any other power of two. This is because it can be proven that (try to prove it!) those sums are not optimal.

 **Code**
```cpp
#include <bits/stdc++.h>
using namespace std;

const long long MAXAI = 1000000000000ll;

int get_first_bit(long long n){
	return 63 - __builtin_clzll(n);
}

int get_bit_count(long long n){
	return __builtin_popcountll(n);
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t; cin >> t;
	for(int test_number = 0; test_number < t; test_number++){
		long long n; cin >> n;
		//Computing factorials <= MAXAI
		vector<long long> fact;
		long long factorial = 6, number = 4;
		while(factorial <= MAXAI){
			fact.push_back(factorial);
			factorial *= number;
			number++;
		}
		//Computing masks of factorials
		vector<pair<long long, long long>> fact_sum(1 << fact.size());
		fact_sum[0] = {0, 0};
		for(int mask = 1; mask < (1 << fact.size()); mask++){
			auto first_bit = get_first_bit(mask);
			fact_sum[mask].first = fact_sum[mask ^ (1 << first_bit)].first + fact[first_bit];
			fact_sum[mask].second = get_bit_count(mask);
		}
		long long res = get_bit_count(n);
		for(auto i : fact_sum){
			if(i.first <= n){
				res = min(res, i.second + get_bit_count(n - i.first));
			}
		}
		cout << res << "n";
	}
	
	return 0;
}
```
[1646D - Weight the Tree](../problems/D._Weight_the_Tree.md "Codeforces Round 774 (Div. 2)")

 **Solution**
### [1646D - Weight the Tree](../problems/D._Weight_the_Tree.md "Codeforces Round 774 (Div. 2)")

If n=2, we can assign w1=1 and w2=1 and there is no way to get a better answer because all vertices are good and the sum of weights cannot be smaller because the weights have to be positive.

If n>2, two vertices sharing an edge cannot be both good. To prove this, we are going to analyze two cases. If the two vertices have distinct weights, then the one with a smaller weight cannot be good, because the one with a larger weight is its neighbor. Otherwise, if both vertices have the same weight, then none of them can have another neighbor, as that would increase the sum of their neighbors by at least 1. So, the only way this could happen is if n=2, but we are assuming that n>2.

Thus, the set of good vertices must be an independent set. We will see that for each independent set of vertices in the tree, there is an assignment of weights where all the vertices from this set are good. We can assign a weight of 1 to each vertex that is not in the set, and assign its degree to each vertex in the set. Because all neighbors of a vertex in the set are not in the set, then all of them have a weight of 1 and this vertex is good.

Therefore, the maximum number of good vertices is the same as the maximum size of an independent set in this tree. For a fixed independent set of the maximum size, the construction above leads to a configuration with the minimum sum of weights. This is because all vertices must have a weight of at least 1, and the vertices in the set must have a weight of at least its degree.

So, to solve the problem it is enough to root the tree in an arbitrary vertex and solve a tree dp. Let's call f(x,b) to the pair (g,s), where g is the maximum number of good vertices in the subtree of vertex x assuming that x is good (if b=1) or that it is not good (if b=0), and s is the minimum sum of weights for that value g.

The values of f(x,b) can be computed with a dp, using the values of f in the children of node x. If b=1, then for each child c you must sum f(c,0). If b=0, for each child c you can choose the best answer between f(c,0) and f(c,1). The answer to the problem will be the best between f(root,0) and f(root,1)

To construct the assignment of weights, you can do it recursively considering for each vertex if it has to be good or not, in order to keep the current value of the answer. In case both options (making it good or not) work, you have to choose to not make it good, as you do not know if its father was good or not.

Intended complexity: O(n)

 **Code**
```cpp
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 400005;

vector<int> g[MAXN];

bool vis[MAXN];
int pa[MAXN];

//DFS to compute the parent of each node
//parent of node i is stored at pa[i]
void dfs(int v){
	vis[v] = 1;
	for(auto i : g[v]){
		if(!vis[i]){
			pa[i] = v;
			dfs(i);
		}
	}
}

pair<int, int> dp[MAXN][2];

//Computes the value of function f, using dp
//the second coordinate of the pair is negated (to take maximums)
pair<int, int> f(int x, int y){
	pair<int, int> & res = dp[x][y];
	if(res.first >= 0) return res;
	res = {y, y ? -((int) g[x].size()) : -1};
	for(auto i : g[x]){
		if(i != pa[x]){
			pair<int, int> maxi = f(i, 0);
			if(y == 0) maxi = max(maxi, f(i, 1));
			res.first += maxi.first;
			res.second += maxi.second;
		}
	}
	return res;
}

vector<int> is_good;

//Recursive construction of the answer
//is_good[i] tells whether vertex i is good or not.
void build(pair<int, int> value, int v){
	if(value == f(v, 0)){
		is_good[v] = 0;
		for(auto i : g[v]){
			if(i != pa[v]){
				build(max(f(i, 0), f(i, 1)), i);
			}
		}
	}else{
		is_good[v] = 1;
		for(auto i : g[v]){
			if(i != pa[v]){
				build(f(i, 0), i);
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n; cin >> n;
	for(int i = 0; i < n - 1; i++){
		int u, v; 
		cin >> u >> v; u--; v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	if(n == 2){
		cout<<"2 2n1 1n";
		return 0;
	}
	pa[0] = -1;
	dfs(0);
	for(int i = 0; i < n; i++) dp[i][0] = {-1, -1}, dp[i][1] = {-1, -1};
	pair<int, int> res = max(f(0, 0), f(0, 1));
	cout << res.first << " " << -res.second << "n";
	is_good.resize(n);
	build(res, 0);
	for(int i = 0; i < n; i++){
		if(is_good[i]) cout << g[i].size() << " ";
		else cout << "1 ";
	}
	cout << "n";
	return 0;
}
```
[1646E - Power Board](../problems/E._Power_Board.md "Codeforces Round 774 (Div. 2)")

 **Solution**
### [1646E - Power Board](../problems/E._Power_Board.md "Codeforces Round 774 (Div. 2)")

It is easy to see that the first row only contains the number 1 and that this number doesn't appear anywhere else on the board.

We say that an integer is a perfect power if it can be represented as xa where x and a are positive integers and a>1. For each positive integer x which is not a perfect power, we call R(x) to the set of all numbers which appear in rows x,x2,x3,….

Claim: If x≠y are not perfect powers, then R(x) and R(y) have no elements in common. Proof: Suppose there is a common element, then there exist positive integers a,b such that xa=yb. This is the same as x=yba. Because y is not a perfect power, ba has to be a positive integer. If ba=1 then x=y, which cannot happen. So then ba>1, which cannot happen as x is not a perfect power. Thus, this common element cannot exist. 

Based on the observation above, for each not perfect power x we can compute the size of R(x) independently and then sum the results. For a fixed x, let k be the number of rows that start with a power of x. Then R(x) contains all numbers of the form xi⋅j where 1≤i≤k and 1≤j≤m. But, the size of this set is the same as the size of the set containing all numbers of the form i⋅j where 1≤i≤k and 1≤j≤m. Note that the number of elements in this set does not depend on x, it just depends on k.

Thus, the size of R(x) is uniquely determined by the value of k. As xk≤n, then we have that k≤log(n). Then, for each k=1,2,…,⌊log(n)⌋ we just need to compute the number of distinct elements of the form i⋅j where 1≤i≤k and 1≤j≤m. We can do this using an array of length m⋅log(n), and at the i-th step (for i=1,2,…,⌊log(n)⌋) we mark the numbers i,2i,…,mi as visited in the array, and add one to the value we are computing for each number that was not visited before. After the i-th step we have computed this value for k=i.

So, to solve the problem it is enough to compute for each not perfect power x, how many rows in the matrix start with a power of x and using the values we calculated in the last paragraph we can know how many distinct numbers are there in R(x). 

Intended complexity: O(mlogn+n)

 **Additional comment**This solution uses the fact that m≤106, other solutions do not use this, and work for much larger values of m (like m≤1018, but taking the answer modulo some big prime number). Try to solve the problem with this new constraint!

 **Code**
```cpp
#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
using namespace std;
typedef long long ll;

const int MAXM = 1000006;

const int MAXLOGN = 20;

bool visited_mul[MAXM * MAXLOGN];

int main(){
	ll n, m; cin >> n >> m;
	vector<ll> mul_quan(MAXLOGN);
	ll current_vis = 0;
	fore(i, 1, MAXLOGN){
		fore(j, 1, m+1){
			if(!visited_mul[i * j]){
				visited_mul[i * j] = 1;
				current_vis++;
			}
		}
		mul_quan[i] = current_vis;
	}
	ll res=1;
	vector<ll> vis(n + 1);
	fore(i, 2, n+1){
		if(vis[i]) continue;
		ll power = i, power_quan = 0;
		while(power <= n){
			vis[power] = 1;
			power_quan++;
			power *= i;
		}
		res += mul_quan[power_quan];
	}
	cout << res << "n";
	
	return 0;
}
```
[1646F - Playing Around the Table](../problems/F._Playing_Around_the_Table.md "Codeforces Round 774 (Div. 2)")

 **Solution**
### [1646F - Playing Around the Table](../problems/F._Playing_Around_the_Table.md "Codeforces Round 774 (Div. 2)")

For each player, we say it is diverse if all his cards have different numbers. For each player, we will call a card repeated if this player has two or more cards with that number. Observe that a player is diverse if and only if he has no repeated cards.

To construct the answer we are going to divide the process into two parts, each of them using at most n×(n−1)2 operations. In the first part, we are going to reach a configuration where everyone is diverse. In the second one, we will reach the desired configuration.

To do the first part, in each operation we will choose for each player a repeated card to pass. We will repeat this until all players are diverse. If some player is already diverse, he will pass a card with the same number as the card he will receive in that operation. This way, if a player was diverse before the operation, he will still be diverse after the operation.

We will prove that the above algorithm ends. If it does not end, at some point some non-diverse player will pass a card he already passed (not a card with the same number, the exact same card). At this point, all other players have at least one card with this number and this player has at least two (because it is non-diverse), but this implies that there are at least n+1 cards with this number, which cannot happen. 

Now, we will prove that this algorithm ends in at most n×(n−1)2 operations. Consider all cards having the number c, and for each of them consider the distance it moved, but when a player is diverse, we will consider his cards as static and that the card he received (or a previous one, if there are multiple diverse players before him) moved more than once in a single operation. For each x, such that 1≤x≤n−1, consider all cards having the number c that moved a distance of x or more, and look at the one that reaches its final destination first. The first x players that passed this card already had a card with the number c on it, and for each of them, one of these cards will not move anymore (remember that once the player is diverse, his cards are static) and it moved less than x, as we are considering the first card. So, there are at most n−x cards that moved a distance of x or more. Thus, the maximum sum of distances of all cards containing the number c is 1+2+…+(n−1)=n×(n−1)2 and the maximum sum of distances of all cards is n2×(n−1)2. In each operation, the sum of all distances is increased by n so there will be at most n×(n−1)2 operations in this part.

To do the second part, for each j=1,2,…,n−1 (in this order) the i-th player will pass a card with the number ((i−j)modn)+1 a total of j times. It is easy to see that after 1+2+…+(n−1)=n×(n−1)2 operations, all players are solid.

Implementing the first part naively will result in an O(n4) algorithm, which is enough to solve the problem. However, it is possible to divide the complexity by n maintaining a stack of repeated cards for each player.

Intended complexity: O(n3)

 **Code**
```cpp
#include <bits/stdc++.h>
#define fore(i, a, b) for(int i = a; i < b; ++i)
using namespace std;
 
const int MAXN = 1010;

//c[i][j] = number of cards player i has, with the number j
int c[MAXN][MAXN];
 
//extras[i] is the stack of repeated cards for player i.
vector<int> extras[MAXN];
 
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n; cin >> n;
	fore(i, 0, n){
		fore(j, 0, n){
			int x; cin >> x; x--;
			c[i][x]++;
			if(c[i][x] > 1) extras[i].push_back(x);
		}
	}
	vector<vector<int>> res;
	//First part
	while(true){
		//oper will describe the next operation to perform
		vector<int> oper(n);
		//s will be the first non-diverse player
		int s = -1;
		fore(i, 0, n){
			if(extras[i].size()){
				s = i;
				break;
			}
		}
		if(s == -1) break;
		//last_card will be the card that the previous player passed
		int last_card = -1;
		fore(i, s, s + n){
			int real_i = i % n;
			if(extras[real_i].size()){
				last_card = extras[real_i].back();
				extras[real_i].pop_back();
			}
			oper[real_i] = last_card;
		}
		res.push_back(oper);
		fore(i, 0, n){
			int i_next = (i + 1) % n;
			c[i][oper[i]]--;
			c[i_next][oper[i]]++;
		}
		fore(i, 0, n){
			int i_next = (i + 1) % n;
			if(c[i_next][oper[i]] > 1) extras[i_next].push_back(oper[i]);
		}
	}
	//Second part
	fore(j, 1, n){
		vector<int> oper;
		fore(i, 0, n) oper.push_back((i - j + n) % n);
		fore(i, 0, j) res.push_back(oper);
	}
	cout << res.size() << "n";
	for(auto i : res){
		for(auto j : i) cout<< j + 1 << " ";
		cout << "n";
	}
	return 0;
}
```
Additionally, [ak2006](https://codeforces.com/profile/ak2006 "Specialist ak2006") has made video editorials for problems [B](https://codeforces.com/https://youtu.be/MIOUg_frJps), [C](https://codeforces.com/https://youtu.be/BoyqQAXtSQg) and [D](https://codeforces.com/https://youtu.be/j7eGgZd9VF0).

