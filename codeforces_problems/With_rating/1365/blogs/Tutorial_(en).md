# Tutorial_(en)

[1365A - Matrix Game](../problems/A._Matrix_Game.md "Codeforces Round 648 (Div. 2)")

 **Tutorial**
### [1365A - Matrix Game](../problems/A._Matrix_Game.md "Codeforces Round 648 (Div. 2)")

Key Idea:

Vivek and Ashish can never claim cells in rows and columns which already have at least one cell claimed. So we need to look at the parity of minimum of the number of rows and columns which have no cells claimed initially.

Solution:

Let $a$ be the number of rows which do not have any cell claimed in them initially and similarly $b$ be the number of columns which do not have any cell claimed initially. Each time a player makes a move both $a$ and $b$ decrease by $1$, since they only claim cells in rows and columns with no claimed cells. 

If either one of $a$ or $b$ becomes $0$, the player whose turn comes next loses the game. Since both $a$ and $b$ decrease by $1$ after each move, $\min(a, b)$ becomes $0$ first. So, if $\min(a, b)$ is odd, Ashish wins the game otherwise Vivek wins.

Time complexity: $O(n \cdot m)$

 **Code**
```cpp

#include 
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "n"
#define int long long

const int N = 51;

int n, m;
int a[N][N];

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n >> m;
		set< int > r, c;
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= m; j++)
			{
				cin >> a[i][j];
				if(a[i][j] == 1)
					r.insert(i), c.insert(j);
			}
		}
		int mn = min(n — r.size(), m — c.size());
		if(mn % 2)
			cout << "Ashish" << endl;
		else
			cout << "Vivek" << endl;
	}
	return 0;
}
```
This problem was prepared by [Ashishgup](https://codeforces.com/profile/Ashishgup "Master Ashishgup")

[1365B - Trouble Sort](../problems/B._Trouble_Sort.md "Codeforces Round 648 (Div. 2)")

 **Tutorial**
### [1365B - Trouble Sort](../problems/B._Trouble_Sort.md "Codeforces Round 648 (Div. 2)")

Key Idea:

If there is at least one element of type $0$ and at least one element of type $1$, we can always sort the array.

Solution:

If all the elements are of the same type, we cannot swap any two elements. So, in this case, we just need to check if given elements are already in sorted order.

Otherwise, there is at least one element of type $0$ and at least one element of type $1$. In this case, it is possible to swap any two elements! We can swap elements of different types using only one operation. Suppose we want to swap two elements $a$ and $b$ of the same type. We can do it in $3$ operations. Let $c$ be an element of the type different from $a$ and $b$. We can first swap $a$ and $c$, then swap $b$ and $c$ and then swap $a$ and $c$ again. In doing so, $c$ remains at its initial position and $a$, $b$ are swapped. This is exactly how we swap two integers using a temporary variable. Since we can swap any two elements, it is always possible to sort the array in this case.

Time complexity: $O(n)$

 **Code**
```cpp

#include 
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "n"
#define int long long

const int N = 1e3 + 5;

int n;
int a[N], b[N];

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n;
		bool sorted = 1, have0 = 0, have1 = 0;
		for(int i = 1; i <= n; i++)
		{
			cin >> a[i];
			if(i >= 2 && a[i] < a[i - 1])
				sorted = 0;
		}
		for(int i = 1; i <= n; i++)
		{
			cin >> b[i];
			if(!b[i])
				have0 = 1;
			else
				have1 = 1;
		}
		if(have0 && have1)
			cout << "Yes" << endl;
		else if(sorted)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}
```
This problem was prepared by [Ashishgup](https://codeforces.com/profile/Ashishgup "Master Ashishgup")

[1365C - Rotation Matching](../problems/C._Rotation_Matching.md "Codeforces Round 648 (Div. 2)")

 **Tutorial**
### [1365C - Rotation Matching](../problems/C._Rotation_Matching.md "Codeforces Round 648 (Div. 2)")

Key Idea:

We only need to perform shifts on one of the arrays. Moreover, all the shifts can be of the same type (right or left)!

Solution:

First of all, a left cyclic shift is the same as $n - 1$ right cyclic shifts and vice versa. So we only need to perform shifts of one type, say right.

Moreover, a right cyclic shift of $b$ is the same as performing a left cyclic shift on $a$ and vice versa. So we don't need to perform any shifts on $b$.

Now the problem reduces to finding the maximum number of matching pairs over all right cyclic shifts of $a$. Since $n$ right cyclic shifts on $a$ results in $a$ again, there are only $n - 1$ right cyclic shifts possible. 

Since both arrays are a permutation, each element in $a$ would match with its corresponding equal element in $b$ only for one of the shifts. For example, if $a$ is $\{{2, 3, 1\}}$ and $b$ is $\{{3, 1, 2\}}$, the number $3$ in $a$ would match with the number $3$ in $b$ only if one right cyclic shift is performed. So for each element in $a$ we can find the number of right cyclic shifts after which it would match with its corresponding equal element in $b$. If $a_i$ = $b_j$, then $a_i$ would match with $b_j$ after $k = j - i$ right cyclic shifts. If $j - i \lt 0$, then $a_i$ would with $b_j$ after $n - j + i$ shifts.

Now for each shift, we can find the number of matching pairs and take the maximum.

Time complexity: $O(n)$ or $O(n \cdot log(n))$ if you use a map.

 **Code**
```cpp

#include 
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "n"
#define int long long

const int N = 2e5 + 5;

int n;
int a[N], b[N], pos[N];
map< int, int > offset;

int32_t main()
{
	IOS;
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		pos[a[i]] = i;
	}
	for(int i = 1; i <= n; i++)
		cin >> b[i];
	for(int i = 1; i <= n; i++)
	{
		int cur = pos[b[i]] - i;
		if(cur < 0)
			cur += n;
		offset[cur]++;
	}
	int ans = 0;
	for(auto &it:offset)
		ans = max(ans, it.second);
	cout << ans;
	return 0;
}
```
This problem was prepared by [Ashishgup](https://codeforces.com/profile/Ashishgup "Master Ashishgup") and [ridbit10](https://codeforces.com/profile/ridbit10 "Expert ridbit10")

[1365D - Solve The Maze](../problems/D._Solve_The_Maze.md "Codeforces Round 648 (Div. 2)")

 **Tutorial**
### [1365D - Solve The Maze](../problems/D._Solve_The_Maze.md "Codeforces Round 648 (Div. 2)")

Key Idea:

We can block all empty neighbouring cells of bad people and then check if all good people can escape and no bad people are able to escape.

Solution:

Consider all the neighbouring cells of bad people. There shouldn't be any path from these cells to the cell $(n, m)$. If there is a path from any such cell, the bad person adjacent to that cell can also then reach the cell $(n, m)$. So, if any good and bad people are in adjacent cells, the answer is "No".

Based on this idea, we can block any empty cell neighbouring a bad person. Suppose there is another solution in which a cell $(i, j)$ neighbouring a bad person does not need to be blocked. There still won't be any path from $(i, j)$ to $(n, m)$ in that solution. So we can block $(i, j)$ in that solution too without affecting the solution itself.

It is sufficient to block only the empty neighbouring cells of bad people and check the required conditions, which can be done using a bfs on the grid.

Proof:

We will assume there are no adjacent good and bad people since in that case, the answer is "No". There are three cases: 

* A bad person is adjacent to the cell $(n, m)$. In this case, the cell $(n, m)$ must be blocked. Now no one will be able to escape. If there is at least one good person present, the answer is "No".
* If after blocking the neighbouring cells of bad people, there is some good person who is not able to escape, then the answer is again "No".
* Otherwise, the answer is always "Yes". Suppose there is some path from a bad person at cell $(i, j)$ to the cell $(n, m)$. One of the neighbours of this person must be another bad person since the only other case is an adjacent good person (which is already covered above). Extending this, all the cells on the path from $(i, j)$ to $(n, m)$ must have bad people. This is not possible since in this case, there must be a bad person adjacent to $(n, m)$ and this case is already covered above.

Time complexity: $O(n \cdot m)$

 **Code**
```cpp

#include 
using namespace std;
#define int long long
typedef int ll;
typedef long double ld;
const ll N = 55;
char en = 'n';
ll inf = 1e16;
ll mod = 1e9 + 7;
ll power(ll x, ll n, ll mod) {
  ll res = 1;
  x %= mod;
  while (n) {
    if (n & 1)
      res = (res * x) % mod;
    x = (x * x) % mod;
    n >>= 1;
  }
  return res;
}
ll n, m;
char arr[N][N];
ll dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

bool valid(ll i, ll j) { return i >= 1 && i <= n && j >= 1 && j <= m; }
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll t;
  cin >> t;
  while (t--) {

    cin >> n >> m;

    for (ll i = 1; i <= n; i++) {
      cin >> (arr[i] + 1);
    }

    for (ll i = 1; i <= n; i++) {
      for (ll j = 1; j <= m; j++) {
        if (arr[i][j] == 'B') {
          for (ll k = 0; k < 4; k++) {
            ll ni = i + dir[k][0];
            ll nj = j + dir[k][1];
            if (valid(ni, nj) && arr[ni][nj] == '.')
              arr[ni][nj] = '#';
          }
        }
      }
    }

    queue> que;
    bool visited[n + 5][m + 5];
    memset(visited, false, sizeof(visited));
    if (arr[n][m] == '.') {
      que.push({n, m});
      visited[n][m] = true;
    }
    while (!que.empty()) {
      pair curr = que.front();
      que.pop();
      for (ll k = 0; k < 4; k++) {
        ll ni = curr.first + dir[k][0];
        ll nj = curr.second + dir[k][1];
        if (valid(ni, nj) && !visited[ni][nj] && arr[ni][nj] != '#') {
          que.push({ni, nj});
          visited[ni][nj] = true;
        }
      }
    }
    bool good = true;
    for (ll i = 1; i <= n; i++) {
      for (ll j = 1; j <= m; j++) {
        if ((arr[i][j] == 'G' && !visited[i][j]) or
            (arr[i][j] == 'B' && visited[i][j])) {
          good = false;
          break;
        }
      }
    }
    cout << (good ? "Yes" : "No") << en;
  }

  return 0;
}

```
This problem was prepared by [Vivek1998299](https://codeforces.com/profile/Vivek1998299 "Master Vivek1998299")

[1365E - Maximum Subsequence Value](../problems/E._Maximum_Subsequence_Value.md "Codeforces Round 648 (Div. 2)")

 **Tutorial**
### [1365E - Maximum Subsequence Value](../problems/E._Maximum_Subsequence_Value.md "Codeforces Round 648 (Div. 2)")

Key Idea:

For subsets of size up to $3$, their value is the bitwise OR of all elements in it. For any subset $s$ of size greater than $3$, it turns out that if we pick any subset of $3$ elements within it, then its value is greater than or equal to the value of $s$!

Solution:

Let $k$ be the size of the chosen subset. For $k \le 3$, $\max(k - 2, 1)$ is equal to $1$. This implies that their value is equal to the bitwise OR of all the elements in it (since we need to add $2^i$ for all $i$ such that at least $1$ element in the subset has $i$-th bit set in its binary representation).

Consider any subset $s$ of size $k \gt 3$. Let $i$ be any number such that the $i$-th bit is set in at least $k - 2$ elements of $s$. If we pick any $3$ elements of this subset, then by [Pigeonhole principle](https://codeforces.com/https://en.wikipedia.org/wiki/Pigeonhole_principle) the $i$-th bit would also be set in at least one of these elements! If this is not true then the there are $3$ elements in $s$ which do not have the $i$-th bit set, which is not possible.

So for any subset $s$ of size greater than $3$, its value is less than or equal to the value of any subset consisting of $3$ elements from $s$. Hence, we only need to check all subsets of size up to $3$.

Time complexity: $O(n^3)$

 **Code**
```cpp

#include 
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "n"
#define int long long

const int N = 505;

int n;
int a[N];

int32_t main()
{
	IOS;
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	int ans = 0;
	for(int i = 1; i <= n; i++)
		for(int j = i; j <= n; j++)
			for(int k = j; k <= n; k++)
				ans = max(ans, (a[i] | a[j] | a[k]));
	cout << ans;
	return 0;
}
```
This problem was prepared by [Ashishgup](https://codeforces.com/profile/Ashishgup "Master Ashishgup") and [ridbit10](https://codeforces.com/profile/ridbit10 "Expert ridbit10")

[1365F - Swaps Again](../problems/F._Swaps_Again.md "Codeforces Round 648 (Div. 2)")

 **Tutorial**
### [1365F - Swaps Again](../problems/F._Swaps_Again.md "Codeforces Round 648 (Div. 2)")

Key Idea:

If we consider the unordered pair of elements $\{{a_i, a_{n - i + 1}\}}$, then after any operation, the multiset of these pairs (irrespective of the ordering of elements within the pair) stays the same!

Solution:

First of all, if the multiset of numbers in $a$ and $b$ are not the same, the answer is "No".

Moreover, if $n$ is odd, it is not possible to change the middle element of $a$, i.e., $a_{(n + 1) / 2}$. So when $n$ is odd and elements at the position $(n + 1) / 2$ do not match in $a$ and $b$, the answer is again "No".

Suppose we pair up the elements at equal distance from the middle element in $a$ (if $n$ is even, the middle element does not exist but we can treat it as the one between positions $n / 2$ and $n / 2 + 1$). That is, we pair up $\{{a_i, a_{n - i + 1}\}}$ (their individual order within the pair doesn't matter). After any operation on $a$, the multiset of these pairs does not change!

If we swap a prefix of length $l$ with the suffix of length $l$, then consider any element at position $i \le l$ before the swap. It's new position is $n - l + i$ and the element it was paired with, i.e. the element at position $n - i + 1$ goes to the position $l - i + 1$. $(n - l + i) + (l - i + 1) = n + 1$, so these two elements are still paired after the swap.

For example, if $a$ is $[1, 4, 2, 3]$, then the pairs are $\{{1, 3\}}$ and $\{{2, 4\}}$ (their individual ordering in the pair doesn't matter). Suppose we first apply the operation on the prefix of length $1$ and then the prefix of length $2$. After the first operation, $a$ is $[3, 4, 2, 1]$ and after the second operation, $a$ is $[2, 1, 3, 4]$. Note that in both these arrays, the pairings are still the same, i.e., $\{{1, 3\}}$ and $\{{2, 4\}}$.

We conclude that in any array resulting after some number of operations, these pairings do not change with respect to the initial array. It turns out that all such arrays with same pairings as the initial array can be formed by performing these operations! So we only need to check if the multiset of these pairs in $b$ is the same as the multiset of pairs in $a$.

Proof:

We will show that given any array $b$ such that the multiset of pairs in $b$ is the same as the multiset of pairs in $a$, then we can form $b$ from $a$ in atmost $\lfloor{\frac{3 n}{2}}\rfloor$ operations. We will start constructing the pairs in $b$ starting from $b_{n / 2}$ to $b_{1}$, i.e., we first bring elements $b_{n / 2}$ and $b_{n - n / 2 + 1}$ to their position in $a$ followed by $b_{n / 2 - 1}$ and so on. 

Note that if we bring the elements $b_{n / 2}$ and $b_{n - n / 2 + 1}$ to their respective positions in $a$ then we can delete them in both $a$ and $b$ and continue the construction. Suppose we currently want to bring elements $b_i$ and $b_{n - i + 1}$ $(i \le n/2)$ to their respective positions in $a$. If $b_i$ is at position $j$ in $a$, then $b_{n - i + 1}$ must be at the position $n - j + 1$. There are three cases:

1. If $j = n$, then we can swap the prefix and suffix of length $i$ in $a$ to achieve this.
2. Otherwise if $j = 1$, then we can first swap prefix and suffix of length $1$ and then swap prefix and suffix of length $i$.
3. Else we can swap prefix and suffix of length $j$ in $a$ and proceed to steps $1$ and $2$.

In atmost $3$ steps, we can bring each pair in $a$ to its required position in $b$. So we need atmost $\lfloor{\frac{3 n}{2}}\rfloor$ operations overall.

Time complexity: $O(n \cdot \log{n})$

 **Code**
```cpp

#include
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		map< pair < int, int >, int > pairs;
		vector< int > a(n), b(n);
		bool possible = 1;

		for(int i = 0; i < n; i++)
			cin >> a[i];

		for(int i = 0; i < n; i++)
			cin >> b[i];

		if(n % 2 == 1 && a[n / 2] != b[n / 2])
			possible = 0;

		for(int i = 0; i < n / 2; i++){
			pair< int, int > p = {min(a[i], a[n — 1 — i]), max(a[i], a[n — 1 — i])};
			pairs[p]++;
		}

		for(int i = 0; i < n / 2; i++){
			pair< int, int > p = {min(b[i], b[n — 1 — i]), max(b[i], b[n — 1 — i])};
			if(pairs[p] <= 0)
				possible = 0;
			pairs[p]--;
		}

		if(possible)
			cout << "Yes" << endl;

		else cout << "No" << endl;
	}
}
```
This problem was prepared by [FastestFinger](https://codeforces.com/profile/FastestFinger "Master FastestFinger"), [Ashishgup](https://codeforces.com/profile/Ashishgup "Master Ashishgup") and [Vivek1998299](https://codeforces.com/profile/Vivek1998299 "Master Vivek1998299")

[1365G - Secure Password](../problems/G._Secure_Password.md "Codeforces Round 648 (Div. 2)")

 **Tutorial**
### [1365G - Secure Password](../problems/G._Secure_Password.md "Codeforces Round 648 (Div. 2)")

Key Idea:

Unlike the last version of the problem, this is not doable using a binary search.

Solution using more queries:

It is possible to solve the problem using $2\cdot \log{n}$ queries in the following way:

For each $i$, we ask the bitwise OR of all numbers at indices which have the $i$-th bit set in their binary representation. We also ask the bitwise OR of all numbers at indices which do not have the $i$-th bit set in their binary representation.

Suppose we want to calculate the bitwise OR of all numbers except the $i$-th number. Let the bitwise OR be equal to $a$ (initialize $a= 0$). We iterate on all indices $j$ from $1$ to $n$ (except $i$). If $j$ is a submask of $i$, that is $j \wedge i = j$ (where $\wedge$ is the bitwise AND operator), then there must be some bit $k$ that is set in $i$ but not in $j$ (since $i \ne j$). In this case we replace $a$ by $a \vee x$ where $\vee$ is the bitwise OR operator and $x$ is the bitwise OR of numbers at indices that do no have the $k$-th bit set. Similarly, if $j$ is not a submask of $i$ then there must be some bit $k$ which is set in $j$ but not in $i$. In that case we use the bitwise OR of numbers at indices that have the $k$-th bit set.

In doing so, we included the contribution of each element except $i$ at least once. Note that this works because taking the bitwise OR with the same number more than once does not affect the answer.

For example, if $n=4$ and indices are number $0$ to $3$, then we need to ask $4$ queries: $\{{0, 2\}}$ (bit $0$ not set), $\{{1, 3\}}$ (bit $0$ set), $\{{0, 1\}}$ (bit $1$ not set), $\{{2, 3\}}$ (bit $1$ set).

Solution:

Note that in the suboptimal solution, we assigned a bitmask to each index (in that case bitmask for index $i$ was equal to $i$). What if we assign these masks in a different way?

Suppose we are able to assign the masks in such a way that no two masks assigned to two indices are submasks of each other. In this case, we do not need to ask bitwise OR of indices which do not have the $i$-th bit set since for each pair of indices, there is a bit which is set in one but not in the other.

For example, if $n = 4$, we can assign masks 1100, 1010, 1001 and 0110 (in binary representation). Now for each bit $i$, we will only query the indices which have the $i$-th bit set. In this case, for bit $0$ we ask $\{{3\}}$, for bit $1$ we ask $\{{2, 4\}}$, for bit $2$ we ask $\{{1, 4\}}$ and for bit $3$ we ask $\{{1, 2, 3\}}$. Let $x_0, x_1, x_2, x_3$ be bitwise OR of these four subsets respectively. Then the elements of the password are $x_0 \vee x_1$, $x_0 \vee x_2$, $x_1 \vee x_2$ and $x_0 \vee x_3$ respectively.

What is the minimum number of bits we need to assign masks in such a way?

We are given the bound of $13$ queries. There are $1716$ numbers upto $2^{13}$ which have $6$ bits set in their binary representation. Clearly no two of these numbers would be submaks of each other. So we can use them to assign the masks!

It can be shown using [Sperner's theorem](https://codeforces.com/https://bit.ly/2XAUBoa) that we need at least $13$ queries to assign submaks in the above manner.

Time complexity: $O(2^q + n \cdot q)$ where $q$ is the number of queries asked.

 **Code**
```cpp

#include
using namespace std;

#define ll long long
#define vint vector< int >

const int Q = 13;

ll query(vint v){
	cout << "? " << v.size() << ' ';
	for(ll i : v)
		cout << i + 1 << ' ';
	cout << endl;
	fflush(stdout);
	ll or_value;
	cin >> or_value;
	return or_value;
}

int main(){
	int n;
	cin >> n;

	vector< vint > ask(Q);
	vint assign_mask(n);

	vector< ll > or_value(Q), answer(n);

	int assigned = 0;

	for(int i = 1; i < (1 << Q); i++){
		if(__builtin_popcount(i) != Q / 2)
			continue;
		assign_mask[assigned] = i;
		for(int j = 0; j < Q; j++)
			if((i >> j & 1) == 0)
				ask[j].push_back(assigned);
		assigned++;
		if(assigned == n)
			break;
	}

	for(int i = 0; i < Q; i++)
		if(!ask[i].empty())
			or_value[i] = query(ask[i]);

	for(int i = 0; i < n; i++)
		for(int j = 0; j < Q; j++)
			if(assign_mask[i] >> j & 1)
				answer[i] |= or_value[j];

	cout << "! ";

	for(ll i : answer)
		cout << i << ' ';

	cout << endl;
}
```
This problem was prepared by [FastestFinger](https://codeforces.com/profile/FastestFinger "Master FastestFinger")

