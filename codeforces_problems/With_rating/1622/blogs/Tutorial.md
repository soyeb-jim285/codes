# Tutorial

[1622A - Construct a Rectangle](../problems/A._Construct_a_Rectangle.md "Educational Codeforces Round 120 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1622A - Construct a Rectangle](../problems/A._Construct_a_Rectangle.md "Educational Codeforces Round 120 (Rated for Div. 2)")

First, the condition about being able to construct a rectangle is the same as having two pairs of sticks of equal length.

Let's fix the stick that we are going to break into two parts. Now there are two cases.

The remaining two sticks can be the same. In that case, you can break the chosen stick into equal parts to make the second equal pair of sticks. Note, however, that the stick should have an even length, because otherwise the length of the resulting parts won't be integer.

The remaining two sticks can be different. In that case, the chosen stick should have the length equal to their total length, because the only way to make two pairs of equal sticks is to produce the same two sticks as the remaining ones.

Overall complexity: O(1) per testcase.

 **Solution (Neon)**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    vector<int> l(3);
    for (int i = 0; i < 3; ++i)
      cin >> l[i];
    bool ok = false;
    for (int i = 0; i < 3; ++i)
      ok |= l[i] == l[(i + 1) % 3] + l[(i + 2) % 3];
    for (int i = 0; i < 3; ++i) if (l[i] % 2 == 0)
      ok |= l[(i + 1) % 3] == l[(i + 2) % 3];
    cout << (ok ? "YESn" : "NOn");
  }
} 
```
[1622B - Berland Music](../problems/B._Berland_Music.md "Educational Codeforces Round 120 (Rated for Div. 2)")

Idea: [adedalic](https://codeforces.com/profile/adedalic "International Master adedalic")

 **Tutorial**
### [1622B - Berland Music](../problems/B._Berland_Music.md "Educational Codeforces Round 120 (Rated for Div. 2)")

Since we know that every disliked song should have lower rating than every liked song, we actually know which new ratings should belong to disliked songs and which should belong to the liked ones.

The disliked songs take ratings from 1 to the number of zeros in s. The liked songs take ratings from the number of zeros in s plus 1 to n. Thus, we have two independent tasks to solve.

Let the disliked songs have ratings d1,d2,…,dk. Their new ratings should be 1,2,…,k. We can show that if we sort the array d, then |d′1−1|+|d′2−2|+⋯+|d′k−k| will be the lowest possible. The general way to prove it is to show that if the order has any inversions, we can always fix the leftmost of them (swap two adjacent values), and the cost doesn't increase.

So the solution can be to sort triples (si,pi,i) and restore q from the order of i in these.

Overall complexity: O(nlogn) per testcase.

 **Solution (awoo)**
```cpp
for _ in range(int(input())):
	n = int(input())
	p = [int(x) for x in input().split()]
	s = input()
	l = sorted([[s[i], p[i], i] for i in range(n)])
	q = [-1 for i in range(n)]
	for i in range(n):
		q[l[i][2]] = i + 1
	print(*q)
```
[1622C - Set or Decrease](../problems/C._Set_or_Decrease.md "Educational Codeforces Round 120 (Rated for Div. 2)")

Idea: [adedalic](https://codeforces.com/profile/adedalic "International Master adedalic")

 **Tutorial**
### [1622C - Set or Decrease](../problems/C._Set_or_Decrease.md "Educational Codeforces Round 120 (Rated for Div. 2)")

First, we can prove that the optimal way to perform operations is first, decrease the minimum value several (maybe, zero) times, then take several (maybe, zero) maximums and make them equal to the minimum value. 

The proof consists of several steps: 

1. Prove that first, we make decreases, only then sets:
	* if some ai=ai−1 is done after some aj=ak then if there were no modification of ai then you can just move ai=ai−1 earlier. Otherwise, there were ai=ak, and you can replace (... ai=ak, ai=ai−1 ...) with (... ak=ak−1, ai=ak ...). We demonstrated how to move decrease operations before set operations.
2. Prove that it's optimal to decrease only one element ai:
	* instead of decreasing ai by x and aj by y (where ai≤aj), we can decrease ai by x+y and replace all ak=aj with ak=ai.
3. It's optimal to decrease the minimum element — it follows from proof of previous step.
4. If we make y set operations, it's optimal to set minimum value to y maximum elements — should be obvious.

To use the strategy, we'll firstly sort array a in non-decreasing order. In this case, we'll decrease a1 by x and perform set to y elements an−y+1,…,an. The question is: how to minimize value of x+y?

Note, that 0≤y<n (since setting the same position multiple times has no sense). Let's iterate over all possible values of y and determine the minimum x needed.

The resulting array will consists of (a1−x),a2,a3,…,an−y,(a1−x),(a1−x),…,(a1−x). Let's say that P(i)=a1+a2+⋯+ai (and all P(i) can be precomputed beforehand). Then the sum of array will become (a1−x)(y+1)+P(n−y)−a1, and we need (a1−x)(y+1)+P(n−y)−a1≤k (a1−x)(y+1)≤k−P(n−y)+a1 a1−x≤⌊k−P(n−y)+a1y+1⌋ or, since we need minimum possible x, x=a1−⌊k−P(n−y)+a1y+1⌋

Using the formula above, we can for each y (0≤y<n) calculate minimum x required. But to be accurate, value k−P(n−y)+a1 may be negative, and, usually in programming languages, integer division cd for negative c returns ⌈cd⌉ instead of ⌊cd⌋.

There is an alternative solution: note that if ∑ai≤k, then a1≤kn. Note that if a1≥kn then resulting value of a1−x is in kn−n<a1−x≤nk and there are at most n possible value for x. So, you can iterate over all possible x and for each x calculate minimum required y either with binary search or two pointers.

 **Solution (adedalic)**
```cpp
#include<bits/stdc++.h>

using namespace std;

#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define sz(a) int((a).size())

typedef long long li;

const int INF = int(1e9);
const li INF64 = li(1e18);

int n;
li k;
vector<int> a;

inline bool read() {
	if(!(cin >> n >> k))
		return false;
	a.resize(n);
	fore (i, 0, n)
		cin >> a[i];
	return true;
}

li accurateFloor(li a, li b) {
	li val = a / b;
	while (val * b > a)
		val--;
	return val;
}

inline void solve() {
	sort(a.begin(), a.end());
	vector<li> pSum(n + 1, 0);
	fore (i, 0, n)
		pSum[i + 1] = pSum[i] + a[i];
	
	li ans = 1e18;
	fore (y, 0, n) {
		//(a[0] - x)(y + 1) + (pSum[n - y] - a[0]) <= k
		//a[0] - x <= (k - pSum[n - y] + a[0]) / (y + 1)
		//x == a[0] - (k - pSum[n - y] + a[0]) / (y + 1)
		
		li x = a[0] - accurateFloor(k - pSum[n - y] + a[0], y + 1);
		ans = min(ans, y + max(0LL, x));
	}
	cout << ans << endl;
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	int t; cin >> t;
	while (t--) {
		read();
		solve();
	}
	return 0;
}
```
[1622D - Shuffle](../problems/D._Shuffle.md "Educational Codeforces Round 120 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1622D - Shuffle](../problems/D._Shuffle.md "Educational Codeforces Round 120 (Rated for Div. 2)")

We could iterate on the substrings we want to shuffle and try to count the number of ways to reorder their characters, but, unfortunately, there's no easy way to take care of the fact that shuffling different substrings may yield the same result.

Instead, we will iterate on the first and the last character that are changed. Let these characters be i and j. First of all, let's check that they can belong to the same substring we can shuffle — it is the case if the string contains at least k characters 1, and the substring from the i-th character to the j-th character contains at most k characters 1.

Then, after we've fixed the first and the last characters that are changed, we have to calculate the number of ways to shuffle the characters between them (including them) so that both of these characters are changed. Let's calculate c0 and c1 — the number of characters 0 and 1 respectively in the substring. Then, we need to modify these two values: for example, if the i-th character is 0, then since it is the first changed character, it should become 1, so we need to put 1 there and decrease c1 by one. The same for the j-th character. Let c′0 and c′1 be the values of c0 and c1 after we take care of the fact that the i-th and the j-th character are fixed. The remaining characters can be in any order, so the number of ways to arrang them is {{c'_0 + c'_1}\choose{c'_0}}.

We can add up these values for all pairs (i, j) such that we can shuffle a substring containing these two characters. We won't be counting any string twice because we ensure that i is the first changed character, and j is the last changed character. Don't forget to add 1 to the answer — the string we didn't count is the original one.

This solution works in O(n^2), but the problem is solvable in O(n).

 **Solution (BledDest)**
```cpp
#include <bits/stdc++.h>     

using namespace std;

const int MOD = 998244353;

int add(int x, int y)
{
    x += y;
    while(x >= MOD) x -= MOD;
    while(x < 0) x += MOD;
    return x;
}

int main()
{
    int n;
    cin >> n;
    int k;
    cin >> k;
    string s;
    cin >> s;
    vector<int> p(n + 1);
    for(int i = 0; i < n; i++) p[i + 1] = p[i] + (s[i] - '0');
    vector<vector<int>> C(n + 1);
    for(int i = 0; i <= n; i++)
    {
        C[i].resize(i + 1);
        C[i][0] = C[i][i] = 1;
        for(int j = 1; j < i; j++)
            C[i][j] = add(C[i - 1][j], C[i - 1][j - 1]);
    }
    int ans = 1;
    for(int i = 0; i < n; i++)
        for(int j = i + 1; j < n; j++)
        {
            int cnt = j + 1 - i;
            int cnt1 = p[j + 1] - p[i];
            if(cnt1 > k || p[n] < k) continue;
            cnt -= 2;
            if(s[i] == '0') cnt1--;
            if(s[j] == '0') cnt1--;
            if(cnt1 <= cnt && cnt1 >= 0 && cnt >= 0)
                ans = add(ans, C[cnt][cnt1]);
        }
    cout << ans << endl;
}
```
[1622E - Math Test](../problems/E._Math_Test.md "Educational Codeforces Round 120 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1622E - Math Test](../problems/E._Math_Test.md "Educational Codeforces Round 120 (Rated for Div. 2)")

Note that there are only two ways to fix the result of the operation of taking an absolute value in the expression |x_i - r_i|: x_i - r_i or r_i - x_i. Since the value of n is small enough that we can iterate over all 2^n options, and choose the one for which the sum is maximum.

For each student, let's fix with which sign their total points will contribute to the answer, then x_i will contribute with the opposite sign. Now, for the question j we can calculate val_j — the coefficient with which p_j will contribute to the answer. It remains to choose such a permutation p that the sum \sum\limits_{j=1}^m p_j val_j is the maximum possible. From here we can see that if val_j < val_i (for some i and j), then p_j < p_i must holds, otherwise we can swap p_j and p_i, and the answer will increase. This means that we can sort all questions in ascending order by the value in the val array, and assign the value x in the array p to the x-th question in ascending order.

For some of 2^n options, the permutations we found may be illegal because it can happen that we consider the case that some |x_i - r_i| evaluates as (x_i - r_i), but in the best permutation we found for that option, it evaluates as (r_i - x_i). We can just ignore it because this will never be the case with the option giving the highest possible surprise value — if this thing happened for some option to choose the signs of r_i, then, if we flip the signs for the students such that the conditions on them are not met in the optimal permutation, we'll get a combination of signs that yields a higher surprise value.

 **Solution (Neon)**
```cpp
#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); ++i)

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m;
    scanf("%d%d", &n, &m);
    vector<int> x(n);
    forn(i, n) scanf("%d", &x[i]);
    vector<vector<int>> a(n, vector<int>(m));
    forn(i, n) forn(j, m) scanf("%1d", &a[i][j]);
    
    int ans = -1;
    vector<int> best;
    forn(mask, 1 << n) {
      vector<int> val(m);
      forn(i, n) forn(j, m) if (a[i][j]) val[j] += ((mask >> i) & 1) ? +1 : -1;
      int res = 0;
      forn(i, n) res += ((mask >> i) & 1) ? -x[i] : x[i];
      vector<int> p(m);
      iota(p.begin(), p.end(), 0);
      sort(p.begin(), p.end(), [&](int x, int y) { return val[x] < val[y]; });
      forn(i, m) res += val[p[i]] * (i + 1);
      if (res > ans) ans = res, best = p;
    }
    
    vector<int> ansPerm(m);
    forn(i, m) ansPerm[best[i]] = i;
    forn(i, m) printf("%d ", ansPerm[i] + 1);
    puts("");
  }
} 
```
[1622F - Quadratic Set](../problems/F._Quadratic_Set.md "Educational Codeforces Round 120 (Rated for Div. 2)")

Idea: [Neon](https://codeforces.com/profile/Neon "Candidate Master Neon")

 **Tutorial**
### [1622F - Quadratic Set](../problems/F._Quadratic_Set.md "Educational Codeforces Round 120 (Rated for Div. 2)")

A good start to solve the problem would be to check the answers for small values of n. One can see that the answers (the sizes of the maximum subsets) are not much different from n itself, or rather not less than n-3. Let's try to prove that this is true for all n.

Consider n is even. Let n=2k, let's see what the product is equal to if we take all the numbers from 1 to n.

\prod\limits_{i=1}^{2k} i! = \prod\limits_{i=1}^{k} (2i-1)! (2i)! = \prod\limits_{i=1}^{k} (2i-1)!^2 2i = (\prod\limits_{i=1}^{k} (2i-1)!)^2 \prod\limits_{i=1}^{k} 2i = (\prod\limits_{i=1}^{k} (2i-1)!)^2 2^k k!

From here we can see that for even k the answer is at least n-1, because we can delete k! and the product of the remaining factorials will be the square of an integer, for odd k the answer is at least n-2, because we can delete 2! and k!.

It remains to prove that the answer is at least n-3 for odd n. This is easy to do, because the answer for n is not less than the answer for n-1 minus 1, because we can delete n! and solve the task with a smaller n value. Moreover, it can be seen from the previous arguments that the answer 3 can only be for n \equiv 3 \pmod 4, and we already know that in this case one of the correct answers is to remove the factorials 2, \frac{n-1}{2}, n.

It remains to learn how to check whether it is possible to remove 1 or 2 numbers so that the remaining product of factorials is the square of an integer.

To do this, we can use XOR hashes. Let's assign each prime number a random 64-bit number. For composite numbers, the hash is equal to the XOR of hashes of all its prime divisors from factorization. Thus, if some prime is included in the number an even number of times, it will not affect the value of the hash, which is what we need. The hash of the product of two numbers is equal to the XOR of the hashes of these numbers. Let's denote the hash function as H.

Using the above, let's calculate H(i) for all i from 1 to n, as well as H(i!) for all i from 1 to n, this is easy to do, because H(i!) = H((i-1)!) \oplus H(i). We will also store a map H(i!) \rightarrow i. Let's calculate the hash H(1!2! \cdots n!) and denote it as fp. It remains to consider the following cases:

* if fp = 0, then the current product is already the square of an integer;
* for an answer of size n-1, we have to check that there exists such a i that H(i!) \oplus fp = 0. To find such i, let's check whether the map contains fp;
* for an answer of size n-2, we have to check that there are such i and j that H(i!) \oplus H(j!) \oplus fp = 0. To do this, iterate over i, and then check whether map contains H(i!) \oplus fp;
* otherwise, the answer is n-3, and there is an answer, where all numbers except 2, \frac{n-1}{2}, n are taken.
 **Solution (Neon)**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int N = 1000 * 1000 + 13;

using li = unsigned long long;

int pr[N];
li hs[N], f[N];
unordered_map<li, int> rf;

int main() {
  int n;
  scanf("%d", &n);
  
  mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());
  iota(pr, pr + N, 0);
  for (int i = 2; i <= n; ++i) if (pr[i] == i) {
    for (int j = i; j <= n; j += i) pr[j] = min(pr[j], i);
    hs[i] = rnd();
  }
  for (int i = 2; i <= n; ++i) {
    f[i] = f[i - 1];
    int x = i;
    while (x != 1) {
      f[i] ^= hs[pr[x]];
      x /= pr[x];
    }
    rf[f[i]] = i;
  }
  
  auto solve = [&] (int n) -> vector<int> {
    li fp = 0;
    for (int i = 2; i <= n; ++i) fp ^= f[i];
    if (fp == 0) return {};
    if (rf.count(fp)) return {rf[fp]};
    for (int i = 2; i <= n; ++i) {
        li x = f[i] ^ fp;
        if (rf.count(x) && rf[x] != i) return {rf[x], i};
    }
    return {2, n / 2, n};
  };
  
  auto ans = solve(n);
  printf("%dn", n - (int)ans.size());
  for (int i = 1; i <= n; ++i)
    if (find(ans.begin(), ans.end(), i) == ans.end()) printf("%d ", i);
  puts("");
} 
```
