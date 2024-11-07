# Tutorial_(en)

[1957A - Stickogon](../problems/A._Stickogon.md "Codeforces Round 940 (Div. 2) and CodeCraft-23")
====================================================================================================================

**Idea:** [keyurchd_11](https://codeforces.com/profile/keyurchd_11 "Master keyurchd_11")  
**Problem Setting:** [shakr](https://codeforces.com/profile/shakr "Expert shakr") [lezirtin](https://codeforces.com/profile/lezirtin "Expert lezirtin")  
**Editorial**: [shakr](https://codeforces.com/profile/shakr "Expert shakr") [TheRaja](https://codeforces.com/profile/TheRaja "Candidate Master TheRaja") 

There were a few solutions which passes pre-tests with the assumption that ai≤n. We apologize for the pre-tests on A not including this case. 

 **Hint 1**To create the most polygons, you should use as few sticks as possible per polygon. What polygon has the least number of sides? 

 **Solution**
### [1957A - Stickogon](../problems/A._Stickogon.md "Codeforces Round 940 (Div. 2) and CodeCraft-23")

The first observation that needs to be made in this problem is that we have to greedily try to build triangles from the sticks available.

The number of triangles that can be created simultaneously by S sticks of the same length is ⌊S3⌋. Hence, the answer is just the sum of the count of all triangles for all stick lengths, 100∑i=1⌊Si3⌋, where Si denotes the number of sticks of length i.

The time complexity of the problem is therefore O(n)+O(100)=O(n).

 **Rate this problem*** [*92*](https://codeforces.com/data/like?action=like "I like this")





 Great Problem
* [*270*](https://codeforces.com/data/like?action=like "I like this")




 Ok Problem
* [*21*](https://codeforces.com/data/like?action=like "I like this")




 Bad Problem
* [*10*](https://codeforces.com/data/like?action=like "I like this")




 Didn't solve
 **C++ Code**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main(){ 
  int t; 
  cin >> t;
  while(t--) {
    int n; 
    cin >> n; 
    vector<int> a(101, 0);
    for (int i = 0; i < n; i++) {
      int x; 
      cin >> x;
      a[x]++;
    }
    int sum = 0;
    for (auto& s : a) 
      sum += s / 3;
    cout << sum << "n";
  }
}
```
[1957B - A BIT of a Construction](../problems/B._A_BIT_of_a_Construction.md "Codeforces Round 940 (Div. 2) and CodeCraft-23")
==================================================================================================================================

**Idea:** [akcube](https://codeforces.com/profile/akcube "Master akcube")  
**Problem Setting:** [Prakul_Agrawal](https://codeforces.com/profile/Prakul_Agrawal "Specialist Prakul_Agrawal")  
**Editorial**: [Prakul_Agrawal](https://codeforces.com/profile/Prakul_Agrawal "Specialist Prakul_Agrawal") [TheRaja](https://codeforces.com/profile/TheRaja "Candidate Master TheRaja") 

 **Hint 1**Given that the sum is bounded, which bits could be set in the bitwise OR? 

 **Solution**
### [1957B - A BIT of a Construction](../problems/B._A_BIT_of_a_Construction.md "Codeforces Round 940 (Div. 2) and CodeCraft-23")

The case n=1 needs to be handled separately, as we can only output k itself.

For n>1, we make the following observations. Let x be the position of the most significant bit in k, that is 2x≤k<2x+1. From this, we learn that the bitwise OR of the sequence cannot have more than x+1 set bits because that would make the sum greater than 2x+1.

Now, having x+1 bits set in the bitwise OR of the sequence is only possible if k=2x+1−1 (or k=111…12). Any k less than this cannot have x+1 bits set in the bitwise OR of the sequence, as otherwise the sum would exceed k. 

However, we can always set x bits, as we can always have one number in the sequence as 2x−1 (which has exactly x bits set). Using these observations, we get our solution as 2x−1,k−(2x−1),0,0,0,…,0. This ensures that we have at least x bits set in the bitwise OR, and additionally also handles the case where x+1 bits can be set, while maintaining the sum.

 **Rate this problem*** [*279*](https://codeforces.com/data/like?action=like "I like this")




 Great Problem
* [*246*](https://codeforces.com/data/like?action=like "I like this")




 Ok Problem
* [*53*](https://codeforces.com/data/like?action=like "I like this")




 Bad Problem
* [*53*](https://codeforces.com/data/like?action=like "I like this")




 Didn't solve
 **C++ Code**
```cpp
#include <bits/stdc++.h>

using namespace std;
 
int main(){
    int t; 
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        if (n == 1) {
            a[0] = k;
        }
        else {
            int msb = 0;
            // find the msb of k
            for (int i = 0; i < 31; i++) {
                if (k & (1 << i)) {
                    msb = i;
                }
            }
            a[0] = (1 << msb) - 1;
            a[1] = k - a[0];
            for (int i = 2; i < n; i++) {
                a[i] = 0;
            }
        }
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << "n";
    }
    return 0;
}
```
[1957C - How Does the Rook Move?](../problems/C._How_Does_the_Rook_Move_.md "Codeforces Round 940 (Div. 2) and CodeCraft-23")
==================================================================================================================================

**Idea:** [SilverTongue1729](https://codeforces.com/profile/SilverTongue1729 "Expert SilverTongue1729")  
**Problem Setting:** [ppt1524](https://codeforces.com/profile/ppt1524 "Expert ppt1524") [GenghizKhan](https://codeforces.com/profile/GenghizKhan "Candidate Master GenghizKhan")  
**Editorial**: [ppt1524](https://codeforces.com/profile/ppt1524 "Expert ppt1524") [TheRaja](https://codeforces.com/profile/TheRaja "Candidate Master TheRaja") 

There are 2 ways to approach the problem. The combinatorics approach is slightly more involved and might be more difficult to come up with. 

 **Hint 1**You can ignore the exact positions of the rooks in the initial configurations. Only the number of free rows and columns matter.

 **Hint 2**For each move you can make, how does the number of free rows/columns change?

 **Solution**
### [1957C - How Does the Rook Move?](../problems/C._How_Does_the_Rook_Move_.md "Codeforces Round 940 (Div. 2) and CodeCraft-23")

There are essentially two types of moves:

1. Placing a rook at some (i,i): This reduces the number of free rows and columns available by 1.
2. Placing a rook at some (i,j), where i≠j: The computer now mirrors this by placing a rook at (j,i), blocking rows i and j along with columns i and j. So the number of free rows and columns is reduced by 2.

First, we account for the k moves played earlier and count the number of free columns/rows remaining to place rooks in, and call it m.

Notice that the order of removing rows/columns doesn't affect the final configuration of rooks, and hence only the count of rows matters, to determine the number of final configurations.

We can use a dynamic programming approach where dp[i] represents the number of final configurations when i rows and columns are left.

Since the order of removing rows/columns is unimportant, let's start by removing the last row or column.

When removing the last row or column in an i×i grid, we have two options: 

* We place a rook (i,i), resulting in the deletion of only the last row and column leaving an (i−1)×(i−1) grid. The number of final configurations in this case are given by dp[i−1].
* Alternatively, we can place a rook at (i,j) or (j,i) for any j∈{1,2,…,i−1}. After this move, both the j-th and the i-th rows and columns are deleted, leaving an (i−2)×(i−2) grid. This contributes 2(i−1)⋅dp[i−2] to dp[i].

Overall, we compute dp[i]=dp[i−1]+2(i−1)⋅dp[i−2] for all i∈{2,3,…,n}, with the base case of dp[0]=dp[1]=1.

Our final answer is dp[m].

 **Alternate Solution**Altenatively, we can iterate on the number of type 1 moves we play. Let's term this to be c.

There are {m\choose c} ways to choose the c type 1 moves. Now, we have m - c rows/columns left, and this must be even (type 2 moves cannot exhaust an odd number of rows/columns).

We can see that each of the (m - c)! permutations of the remaining columns correspond to a set of moves we can play. For example, if we have the columns (1, 4, 5, 6) remaining, a permutation (4, 5, 6, 1) corresponds to playing the moves (4, 5), (6, 1). However, if we simply count the number of permutations, we would also be counting the permutation (6, 1, 4, 5), which corresponds to the same set of moves.

To remove overcounting, we can just divide (m - c)! by ((m - c)/2)! (removing the permutations of the pairs chosen).

Hence, the answer becomes

\sum\limits_{c = 0}^m [(m - c) \bmod 2 = 0] {m \choose c} \frac{(m - c)!}{\left(\frac{m - c}{2}\right)!}

 **Rate this problem*** [*593*](https://codeforces.com/data/like?action=like "I like this")




 Great Problem
* [*66*](https://codeforces.com/data/like?action=like "I like this")




 Ok Problem
* [*93*](https://codeforces.com/data/like?action=like "I like this")




 Bad Problem
* [*102*](https://codeforces.com/data/like?action=like "I like this")




 Didn't solve
 **C++ Code**
```cpp
#include <bits/stdc++.h>
using namespace std;
 
int dp[(int) 3e5+5];
const int MOD = 1e9 + 7;
 
int main() {
    cin.tie(0), cout.tie(0)->sync_with_stdio(0);
    int t; 
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int used = 0;
        for (int i = 0; i < k; i++) {
            int r, c; cin >> r >> c;
            used += 2 - (r == c);
        }
        int m = n - used;
        dp[0] = dp[1] = 1;
        for (int i = 2; i <= m; i++)
            dp[i] = (dp[i-1] + 2ll * (i-1) * dp[i-2] % MOD) % MOD;
        cout << dp[m] << "n";    
    }
    
}
```
[1957D - A BIT of an Inequality](../problems/D._A_BIT_of_an_Inequality.md "Codeforces Round 940 (Div. 2) and CodeCraft-23")
=================================================================================================================================

**Idea:** [fangahawk](https://codeforces.com/profile/fangahawk "Master fangahawk")  
**Problem Setting:** [fangahawk](https://codeforces.com/profile/fangahawk "Master fangahawk") [shiven](https://codeforces.com/profile/shiven "Master shiven")  
**Editorial**: [JadeReaper](https://codeforces.com/profile/JadeReaper "Candidate Master JadeReaper") [TheRaja](https://codeforces.com/profile/TheRaja "Candidate Master TheRaja") 

 **Hint 1**How can you simplify the given inequality? Use the fact that the XOR of a number with itself is 0.

 **Hint 2**The inequality simplifies to f(x, z) \oplus a_y > f(x, z). For a given a_y what subarrays (that include a_y) would satisfy this?

 **Solution**First we may rewrite the inequality as f(x, z) \oplus a_y > f(x, z). So, for each index y, we want to find the total number of subarrays that contain y but whose \text{xor} decreases when we include the contribution of a_y.

Including a_y in some subarray [x, z] (where x \le y \le z) can make the \text{xor} lower only when some set bit of a_y cancels out an existing set bit in f(x, y - 1) \oplus f(y + 1, z). Consider the most signicant set bit in a_y. Call this bit i. Including a_y would decrease the subarray \text{xor} in subarrays where f(x, y - 1) has i set while f(y+1, z) is unset or vice-versa.

Now, for the subarrays where both the prefix subarray ([x \dots y - 1]) as well as the suffix subarray ([y + 1 \dots z]) where either both have bit i set or both have it unset, by including a_y, we increment the xor by at least 2^i. Even if by including a_y, every other smaller bit gets unset (because of cancelling out with a_y), this sum of these decrements is still less than 2^i thereby resulting in an overall positive contribution by including a_y.

 **Rate this problem*** [*359*](https://codeforces.com/data/like?action=like "I like this")




 Great Problem
* [*50*](https://codeforces.com/data/like?action=like "I like this")




 Ok Problem
* [*42*](https://codeforces.com/data/like?action=like "I like this")




 Bad Problem
* [*97*](https://codeforces.com/data/like?action=like "I like this")




 Didn't solve
 **C++ Code**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int Z = 30;
const int MAX_N = 1e5 + 3;
int pref[Z][MAX_N][2];
int suff[Z][MAX_N][2];

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 0; i < Z; i++) suff[i][n + 1][0] = suff[i][n + 1][1] = 0;
    for (int i = 0; i < Z; i++) {
        for (int j = 1; j <= n; j++) {
            int t = !!(a[j] & (1 << i));
            for (int k = 0; k < 2; k++) pref[i][j][k] = (t == k) + pref[i][j - 1][k ^ t];
        }
        for (int j = n; j >= 1; j--) {
            int t = !!(a[j] & (1 << i));
            for (int k = 0; k < 2; k++) suff[i][j][k] = (t == k) + suff[i][j + 1][k ^ t];
        }
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        int z = 31 - __builtin_clz(a[i]);
        ans += 1ll * pref[z][i - 1][1] * (1 + suff[z][i + 1][0]);
        ans += 1ll * (1 + pref[z][i - 1][0]) * suff[z][i + 1][1];
    }
    cout << ans << "n";
}

int main() {
    int tc;
    cin >> tc;
    while (tc--)
        solve();
    return 0;
}
```
[1957E - Carousel of Combinations](../problems/E._Carousel_of_Combinations.md "Codeforces Round 940 (Div. 2) and CodeCraft-23")
===================================================================================================================================

**Idea:** [SilverTongue1729](https://codeforces.com/profile/SilverTongue1729 "Expert SilverTongue1729")  
**Problem Setting:** [JadeReaper](https://codeforces.com/profile/JadeReaper "Candidate Master JadeReaper")  
**Editorial**: [SilverTongue1729](https://codeforces.com/profile/SilverTongue1729 "Expert SilverTongue1729") [JadeReaper](https://codeforces.com/profile/JadeReaper "Candidate Master JadeReaper") [TheRaja](https://codeforces.com/profile/TheRaja "Candidate Master TheRaja") 

 **Hint 1**For what values of j is C(i,j) \bmod j = 0?

 **Hint 2**For all other values of j, how can you precompute the result?

 **Hint 3**To precompute, switch around the loop order.

 **Solution**The number of distinct ways you can select k distinct numbers from the set {1, 2, \ldots, i} and arrange them in a line is i(i-1)\cdots(i-k+1), and since arranging in a circle introduces rotational symmetry we have to divide by k, so we have C(i,k) = \frac{i(i-1)\cdots(i-k+1)}{k}.

Therefore C(i,j) \bmod j = \frac{i(i-1)\cdots(i-j+1)}{j} \bmod j. Now since the numerator is a product of j consecutive integers, atleast one of them will be divisible by j. More precisely the exact integer which will be divisible by j will be  j \times \lfloor \frac{i}{j} \rfloor. Hence we can simplify the fraction by removing the denominator and replacing the term  j \times \lfloor \frac{i}{j} \rfloor with \lfloor \frac{i}{j} \rfloor in the numerator. Each of the other j-1 integers in the numerator, after applying \bmod j would cover all integers from 1 to j-1. Hence

 C(i,j) \bmod j = \frac{i(i-1)\cdots(i-j+1)}{j} \bmod j = \left( (j-1)! \times \left\lfloor \frac{i}{j} \right\rfloor \right) \bmod jHere we can notice that all proper factors of j will occur in (j-1)!, so based on this we can tell that C(i,j) \bmod j = 0 for all composite numbers j except j=4.

We first can handle the case of j being prime. Using Wilson's Theorem, we know that (j-1)! \equiv -1 \bmod j when j is prime. Hence

 C(i,j) \bmod j = - \left\lfloor \frac{i}{j} \right\rfloorNow we can reverse the order of loops to sum over all primes, and to calculate the contribution of each prime we can maintain a update array called delta.

To calculate the contribution for a single prime p, we know that for all n from kp to (k + 1)p - 1 (for all k such that kp < 1e6) the contribution would be -k. So, in the delta array, we increment index kp with -k \bmod p and decrement index (k + 1)p with -k \mod p. Now, when we perform a prefix sum on this delta array, we obtain the correct contributions from all primes.

For the case of j=4, we just need to handle it as a prime.

 **Rate this problem*** [*192*](https://codeforces.com/data/like?action=like "I like this")




 Great Problem
* [*15*](https://codeforces.com/data/like?action=like "I like this")




 Ok Problem
* [*45*](https://codeforces.com/data/like?action=like "I like this")




 Bad Problem
* [*32*](https://codeforces.com/data/like?action=like "I like this")




 Didn't solve
 **C++ Code**
```cpp
#include <bits/stdc++.h>
 
using namespace std;
 
const int MOD = 1e9 + 7;
const int MAX_N = 1e6 + 3;
bitset<MAX_N> isprime;
vector<int> primes;
 
vector<int> eratosthenesSieve(int lim) {
    isprime.set();
    isprime[0] = isprime[1] = false;
    for (int i = 4; i < lim; i += 2) isprime[i] = false;
    for (int i = 3; i * i < lim; i += 2)
        if (isprime[i])
            for (int j = i * i; j < lim; j += i * 2) isprime[j] = false;
    vector<int> pr;
    for (int i = 2; i < lim; i++)
        if (isprime[i]) pr.push_back(i);
    return pr;
}
 
vector<int> ans(MAX_N, 0);
 
signed main() {
    primes = eratosthenesSieve(MAX_N);
    vector<int> del(MAX_N, 0);
    // Handle the contribution for all primes
    for (auto &p: primes) {
        for (int curr = p; curr < MAX_N; curr += p) {
            int inc = (p - ((curr / p) % p)) % p;
            del[curr] = (del[curr] + inc) % MOD;
            if (curr + p < MAX_N) del[curr + p] = (del[curr + p] - inc + MOD) % MOD;
        }
    }
    //Special case of 4
    for (int curr = 4; curr < MAX_N; curr += 4) {
        int inc = (2 * (curr / 4)) % 4;
        del[curr] = (del[curr] + inc) % MOD;
        if (curr + 4 < MAX_N) del[curr + 4] = (del[curr + 4] - inc + MOD) % MOD;
    }
    int pref = 0;
    for (int i = 1; i < MAX_N; i++) {
        pref = (pref + del[i]) % MOD;
        ans[i] = (ans[i - 1] + pref) % MOD;
    }
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        cout << ans[n] << "n";
    }
}
```
[1957F1 - Frequency Mismatch (Easy Version)](../problems/F1._Frequency_Mismatch_(Easy_Version).md "Codeforces Round 940 (Div. 2) and CodeCraft-23")
==============================================================================================================================================

**Idea:** [fangahawk](https://codeforces.com/profile/fangahawk "Master fangahawk")  
**Problem Setting:** [fangahawk](https://codeforces.com/profile/fangahawk "Master fangahawk")  
**Editorial:** [akcube](https://codeforces.com/profile/akcube "Master akcube")

 **Hint 1**Let's try answering a different question. Given two multisets of elements how can we check if they differ? Hashing? How to multiset hash efficiently?

 **Hint 2**Okay if we can now differentiate two multisets of unequal elements, can we try to answer queries by inserting into these hypothetical multisets and binary search the differing point to identify the element?

 **Solution**Let's discuss how to hash a multiset of elements a, b and c. Here, I will link you to a famous blog by [rng_58](https://codeforces.com/profile/rng_58 "Legendary Grandmaster rng_58") [Hashing and Probability of Collision](https://codeforces.com/https://rng-58.blogspot.com/2017/02/hashing-and-probability-of-collision.html). Quoting, let's take a random integer r from the interval [0, MOD), and compute the hash (r+a_1)(r+a_2)\dots(r+a_n). This is a polynomial of r of degree n, so again from Schwartz-Zippel lemma, the collision probability is at most \frac{n}{MOD}. The nice thing about this construction is that we can compute rolling hashes using this idea fast. To make implementation easier, this bound applies for summing the random numbers as well. You can check [this](https://codeforces.com/blog/entry/85900#comment-736594) for proof. 

Let's try to answer a single query (u_1, v_1, u_2, v_2) using binary search. We will solve this query in nlog^2(n) using this idea. To check for some mid in our binary search, we insert the values of all nodes which have values from 1 to mid into a data structure that we can query the path sum of u to v using. Querying path sum is a fairly standard problem that can be solved using BIT / Segment trees and ETT (Euler-Tour Trick). Now to solve this query, we only need to binary search and find the first vertex where the hashes differ for both the paths. This vertex is guaranteed to have mismatched frequency on the two paths since it's addition into the path multi-sets changed their hashes. So now we can solve a single query in nlog^2(n) time using hashing + BIT / Segtree.

Now to solve this problem for all Q queries. We can use the idea of parallel binary search here to improve our idea to answering all Q queries efficiently. We can run the binary search for all queries in parallel. For each iteration, sort queries by the current position of their mid values. Then insert values from 1 to mid of the first query into the BIT and query range sum to determine for that particular query how to adjust mid. You can then move the mid pointer to that of the next query and so on. This solution will run in O(nlog(n) + qlog^2(n)). 

**Upd:** Thanks to [IceKnight1093](https://codeforces.com/profile/IceKnight1093 "Master IceKnight1093") for pointing this out. If we just use a single `int` hash with a field size of \approx 10^9, it gives us a probability of failure of \frac{1}{10^9} per query. Since we're doing somewhere of the order 10^6 comparisons per hash representation, this gives a rough 1 - \Big(1 - \frac{1}{10^9}\Big)^{10^6} \approx 10^{-3} chance of failure. This is not a great bound theoretically speaking, but from a practical standpoint, it is a loose bound and it is extremely unlikely that this solution can be hacked. That said, if we want better theoretical bounds we can just use a hash with field size \approx 10^{18} or use double hashing. Even if we were to query all {n \choose 2} paths, the chance of collision is \approx \frac{n^2}{10^{18}} \approx 10^{-8}, which is more than good enough. TL's were set to allow double hashing solutions to pass comfortably. 

 **Rate this problem*** [*35*](https://codeforces.com/data/like?action=like "I like this")




 Great Problem
* [*8*](https://codeforces.com/data/like?action=like "I like this")




 Ok Problem
* [*14*](https://codeforces.com/data/like?action=like "I like this")




 Bad Problem
* [*19*](https://codeforces.com/data/like?action=like "I like this")




 Didn't solve
 **C++ Code**
```cpp
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
using ll = long long;
using dbl = long double;
//#define int ll

using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vii = vector<pii>;
using vvii = vector<vii>;
using vll = vector<ll>;

#define ff first
#define ss second
#define pb push_back
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define tc int t; cin>>t; while(t--)
#define fightFight cin.tie(0) -> sync_with_stdio(0)

template<class T>
struct RMQ {
    vector<vector<T>> jmp;
    RMQ(const vector<T>& V) : jmp(1, V) {
        for (int pw = 1, k = 1; pw * 2 <= sz(V); pw *= 2, ++k) {
            jmp.emplace_back(sz(V) - pw * 2 + 1);
            rep(j,0,sz(jmp[k]))
                jmp[k][j] = min(jmp[k - 1][j], jmp[k - 1][j + pw]);
        }
    }
    T query(int a, int b) {
        assert(a <= b); // tie(a, b) = minimax(a, b)
        int dep = 31 - __builtin_clz(b-a+1);
        return min(jmp[dep][a], jmp[dep][b - (1 << dep) + 1]);
    }
};

struct LCA {
    int T = 0;
    vi st, path, ret; vi en, d;
    RMQ<int> rmq;
    LCA(vector<vi>& C) : st(sz(C)), en(sz(C)), d(sz(C)), rmq((dfs(C,0,-1), ret)) {}
    void dfs(vvi &adj, int v, int par) {
        st[v] = T++;
        for (auto to : adj[v]) if (to != par) {
            path.pb(v), ret.pb(st[v]);
            d[to] = d[v] + 1;
            dfs(adj, to, v);
        }
        en[v] = T-1;
    }
    bool anc(int p, int c) { return st[p] <= st[c] and en[p] >= en[c]; }
    int lca(int a, int b) {
        if (a == b) return a;
        tie(a, b) = minmax(st[a], st[b]);
        return path[rmq.query(a, b-1)];
    }
    int dist(int a, int b) { return d[a] + d[b] - 2*d[lca(a,b)]; }
};

template<const int mod>
struct mint {
    constexpr mint(int x = 0) : val((x % mod + mod) % mod) {}
    mint& operator+=(const mint &b) { val += b.val; val -= mod * (val >= mod); return *this; }
    mint& operator-=(const mint &b) { val -= b.val; val += mod * (val < 0); return *this; }
    mint& operator*=(const mint &b) { val = 1ll * val * b.val % mod; return *this; }
    mint& operator/=(const mint &b) { return *this *= b.inv(); }
    mint inv() const {
        int x = 1, y = 0, t;
        for(int a=val, b=mod; b; swap(a, b), swap(x, y))
            t = a/b, a -= t * b, x -= t * y;
        return mint(x);
    }
    mint pow(int b) const {
        mint a = *this, res(1);
        for(; b; a *= a, b /= 2)  if(b&1) res *= a;
        return res;
    }
    friend mint operator+(const mint &a, const mint &b) {return mint(a) += b;}
    friend mint operator-(const mint &a, const mint &b) {return mint(a) -= b;}
    friend mint operator*(const mint &a, const mint &b) {return mint(a) *= b;}
    friend mint operator/(const mint &a, const mint &b) {return mint(a) /= b;}
    friend bool operator==(const mint &a, const mint &b) {return a.val == b.val;}
    friend bool operator!=(const mint &a, const mint &b) {return a.val != b.val;}
    friend bool operator<(const mint &a, const mint &b) {return a.val < b.val;}
    friend ostream& operator<<(ostream &os, const mint &a) {return os << a.val;}
    int val;
};
using Mint = mint<MOD>;

template<typename... Ts, size_t... Is, typename F>
void __op(index_sequence<Is...>, tuple<Ts...>& a, const tuple<Ts...>& b, F op) { ((get<Is>(a) = op(get<Is>(a), get<Is>(b))), ...); }
#define OVERLOAD(OP, F) 
template<typename... Ts> auto& operator OP##=(tuple<Ts...> &a, const tuple<Ts...> &b) { __op(index_sequence_for<Ts...>(), a, b, F<>{}); return a; } 
template<typename... Ts> auto operator OP(const tuple<Ts...> &a, const tuple<Ts...> &b) { auto c = a; c OP##= b; return c; }
OVERLOAD(+, plus) OVERLOAD(-, minus) OVERLOAD(*, multiplies) OVERLOAD(/, divides)

constexpr int NUM_HASHES = 2; // *
constexpr array<int, NUM_HASHES> mods = {127657753, 987654319}; // *
template <size_t N = NUM_HASHES>
constexpr auto mint_ntuple(const int &v) {
    return [&]<size_t... Is>(index_sequence<Is...>) { return make_tuple(mint<mods[Is]>(v)...); }(make_index_sequence<N>{}); }

using HT = decltype(mint_ntuple(0));

template<typename T>
struct FT {
    vector<T> s;
    T def;
    FT(int n, T def) : s(n, def), def(def) {}
    void update(int pos, T dif) { // a[pos] += dif
        for (; pos < sz(s); pos |= pos + 1) s[pos] += dif;
    }
    T query(int pos) { // sum of values in [0, pos)
        pos++;
        T res = def;
        for (; pos > 0; pos &= pos - 1) res += s[pos-1];
        return res;
    }
};

struct Query {
    int u1, v1, u2, v2, k;
    int l, r, ans, i;
    int mid(){ return l + (r-l)/2; }
};

auto rng = std::mt19937(std::random_device()());
constexpr const int MXN = 1e5+5;

void solve(){
    int n; cin >> n;
    vi a(n); for(auto &x : a) cin >> x, x--;
    vvi adj(n);
    for(int i=0; i < n-1; i++){
        int u, v; cin >> u >> v; u--, v--;
        adj[u].pb(v); adj[v].pb(u);
    }

    int q; cin >> q;
    vector<Query> queries(q);
    int idx=0;
    for(auto &[u1, v1, u2, v2, k, l, r, ans, i] : queries) cin >> u1 >> v1 >> u2 >> v2 >> k, u1--, v1--, u2--, v2--, l=0, ans=-1, i=idx++;

    LCA lca(adj);
    vi uni(a); sort(all(uni)); uni.resize(unique(all(uni)) - uni.begin());
    vvi cnode(MXN);
    for(int v=0; v < n; v++) cnode[a[v]].pb(v);
    vector<HT> hash(MXN);
    for(auto &c : uni) hash[c] = {rng(), rng()};    

    auto get_ett = [&](vvi &adj){
        vi tin(n), tout(n);
        int timer = 0;
        function<void(int,int)> dfs = [&](int v, int p){
            tin[v] = timer++;
            for(auto &to : adj[v]) if(to != p) dfs(to, v);
            tout[v] = timer++;
        };
        dfs(0, -1);
        return make_pair(tin, tout);
    };
    auto [tin, tout] = get_ett(adj);

    for(auto &q : queries) q.r = sz(uni)-1;

    vi vis(MXN);
    for(int _=0; _<20; _++){
        FT<HT> st(2*n, mint_ntuple(0));
        sort(all(queries), [&](Query &a, Query &b) { return a.mid() < b.mid(); });
        for(int qq=0, cptr=0; qq < q; qq++) if(queries[qq].l <= queries[qq].r) {
            auto &[u1, v1, u2, v2, k, l, r, ans, i] = queries[qq];
            for(; cptr < sz(uni) and cptr <= queries[qq].mid(); cptr++){
                for(auto &v : cnode[uni[cptr]])
                    st.update(tin[v], hash[uni[cptr]]), st.update(tout[v], mint_ntuple(0)-hash[uni[cptr]]);
                vis[uni[cptr]] = true;
            }

            int lca1 = lca.lca(u1, v1), lca2 = lca.lca(u2, v2);
            HT r1 = st.query(tin[lca1]), r2 = st.query(tin[lca2]);
            HT hash1 = (st.query(tin[u1]) + st.query(tin[v1]) - (r1 + r1));
            if(vis[a[lca1]]) hash1 += hash[a[lca1]];
            HT hash2 = (st.query(tin[u2]) + st.query(tin[v2]) - (r2 + r2));
            if(vis[a[lca2]]) hash2 += hash[a[lca2]];

            if(hash1 != hash2){
                ans = queries[qq].mid();
                r = queries[qq].mid()-1;
            }
            else l = queries[qq].mid()+1;
        }
        for(auto &c : uni) vis[c] = false;
    }
    
    sort(all(queries), [&](Query &a, Query &b) { return a.i < b.i; });
    for(auto &[u1, v1, u2, v2, k, l, r, ans, i] : queries){
        if(ans == -1) cout << 0 << 'n';
        else cout << 1 << ' ' << uni[ans]+1 << 'n';
    }
}
signed main(){ 
    fightFight; 
    solve(); 
}
```
[1957F2 - Frequency Mismatch (Hard Version)](../problems/F2._Frequency_Mismatch_(Hard_Version).md "Codeforces Round 940 (Div. 2) and CodeCraft-23")
==============================================================================================================================================

**Idea:** [fangahawk](https://codeforces.com/profile/fangahawk "Master fangahawk")  
**Problem Setting:** [fangahawk](https://codeforces.com/profile/fangahawk "Master fangahawk")  
**Editorial**: [fangahawk](https://codeforces.com/profile/fangahawk "Master fangahawk") [TheRaja](https://codeforces.com/profile/TheRaja "Candidate Master TheRaja") 

 **Hint 1**How would you find the smallest element with different frequencies in two static arrays using a segment tree? Consider hashing.

 **Hint 2**Try extending this idea to finding the smallest element with different frequencies in two different paths on a tree. Think persistent data structures.

 **Hint 3**Once you solve that, you can be extend it to finding the k smallest elements.

 **Solution**
### [1957F2 - Frequency Mismatch (Hard Version)](../problems/F2._Frequency_Mismatch_(Hard_Version).md "Codeforces Round 940 (Div. 2) and CodeCraft-23")

Let's start by first solving the problem for k = 1, and extend the idea to k > 1 later. To solve for k = 1, we'll find the smallest value that occurs with different frequencies on the two paths.

We'll solve an easier version by solving for two static arrays, instead of solving the problem of two paths. To find the smallest value that has a different frequency between the two arrays, we can have a segment tree on the frequency array for each static array. Then, we can store the hash of each segment tree node and perform a descent to find the first point at which the hashes in the two segment trees differ. The hash of a node is the polynomial hash of the subarray it corresponds to.

Now, in order to use the same technique on the path, we want the frequency array of the path u \rightarrow v. To achieve this, we can use persistent segment trees. We define seg(u \rightarrow v) to be the segment tree that corresponds to the frequency array of the values on the path u \rightarrow v. With the idea of persistence, we can quickly compute seg(1 \rightarrow u) for all u, when we root at 1.

To compute seg(u \rightarrow v), we can use this:

seg(u \rightarrow v) = seg(1 \rightarrow u) + seg(1 \rightarrow v) - seg(1 \rightarrow lca(u, v)) - seg(1 \rightarrow parent(lca(u, v))) for every node in the segment tree that we want.

Hence, we are able to get the segment tree for the two paths we need to compare in a query. In our solution with the static arrays, we used the polynomial hash to find the first point of difference between the two frequency arrays. So, we need a way to quickly compute the hash of the pseudo node we computed for seg(u \rightarrow v).

If we have two frequency arrays f_1, f_2, hash(f_1) + hash(f_2) = hash(f_1 + f_2), where the hash of a node is the polynomial hash of the subarray that corresponds to that node.

Hence, we can say:

hash(seg(u \rightarrow v)) = hash(seg(1 \rightarrow u)) + hash(seg(1 \rightarrow v)) - hash(seg(1 \rightarrow lca(u, v))) - hash(seg(1 \rightarrow parent(lca(u, v)))

Hence, we can perform the same descent that we talked about earlier on the derived segment tree.

Now to solve this for k > 1, you can perform a dfs on seg(u \rightarrow v), and keep entering nodes of the segment tree which have differing hashes, until we find k values.

The total time complexity comes out to O(nlogn) + O(q) \times O(k) \times O(logn) = O(qklogn + nlogn)

You can also use an idea similar to the hashing technique used in F1 to hash the segment tree nodes.

 **Rate this problem*** [*28*](https://codeforces.com/data/like?action=like "I like this")




 Great Problem
* [*8*](https://codeforces.com/data/like?action=like "I like this")




 Ok Problem
* [*21*](https://codeforces.com/data/like?action=like "I like this")




 Bad Problem
* [*17*](https://codeforces.com/data/like?action=like "I like this")




 Didn't solve
 **C++ Code**
```cpp
#include <bits/stdc++.h>
using namespace std;
 
const int MOD1 = 1e9 + 7;
const int MOD2 = 998244353;
using ll = long long;
using dbl = long double;
//#define int ll
 
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vii = vector<pii>;
using vvii = vector<vii>;
using vll = vector<ll>;
 
#define ff first
#define ss second
#define pb push_back
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define tc int t; cin>>t; while(t--)
#define fightFight cin.tie(0) -> sync_with_stdio(0)
template<class T>
struct RMQ {
    vector<vector<T>> jmp;
    RMQ(const vector<T>& V) : jmp(1, V) {
        for (int pw = 1, k = 1; pw * 2 <= sz(V); pw *= 2, ++k) {
            jmp.emplace_back(sz(V) - pw * 2 + 1);
            rep(j,0,sz(jmp[k]))
                jmp[k][j] = min(jmp[k - 1][j], jmp[k - 1][j + pw]);
        }
    }
    T query(int a, int b) {
        assert(a <= b); // tie(a, b) = minimax(a, b)
        int dep = 31 - __builtin_clz(b-a+1);
        return min(jmp[dep][a], jmp[dep][b - (1 << dep) + 1]);
    }
};
struct LCA {
    int T = 0;
    vi st, path, ret; vi en, d;
    RMQ<int> rmq;
    LCA(vector<vi>& C) : st(sz(C)), en(sz(C)), d(sz(C)), rmq((dfs(C,1,-1), ret)) {}
    void dfs(vvi &adj, int v, int par) {
        st[v] = T++;
        for (auto to : adj[v]) if (to != par) {
            path.pb(v), ret.pb(st[v]);
            d[to] = d[v] + 1;
            dfs(adj, to, v);
        }
        en[v] = T-1;
    }
    bool anc(int p, int c) { return st[p] <= st[c] and en[p] >= en[c]; }
    int lca(int a, int b) {
        if (a == b) return a;
        tie(a, b) = minmax(st[a], st[b]);
        return path[rmq.query(a, b-1)];
    }
    int dist(int a, int b) { return d[a] + d[b] - 2*d[lca(a,b)]; }
};
template<const int mod>
struct mint {
    constexpr mint(int x = 0) : val((x % mod + mod) % mod) {}
    mint& operator+=(const mint &b) { val += b.val; val -= mod * (val >= mod); return *this; }
    mint& operator-=(const mint &b) { val -= b.val; val += mod * (val < 0); return *this; }
    mint& operator*=(const mint &b) { val = 1ll * val * b.val % mod; return *this; }
    mint& operator/=(const mint &b) { return *this *= b.inv(); }
    mint inv() const {
        int x = 1, y = 0, t;
        for(int a=val, b=mod; b; swap(a, b), swap(x, y))
            t = a/b, a -= t * b, x -= t * y;
        return mint(x);
    }
    mint pow(int b) const {
        mint a = *this, res(1);
        for(; b; a *= a, b /= 2)  if(b&1) res *= a;
        return res;
    }
    friend mint operator+(const mint &a, const mint &b) { return mint(a) += b; }
    friend mint operator-(const mint &a, const mint &b) { return mint(a) -= b; }
    friend mint operator*(const mint &a, const mint &b) { return mint(a) *= b; }
    friend mint operator/(const mint &a, const mint &b) { return mint(a) /= b; }
    friend bool operator==(const mint &a, const mint &b) { return a.val == b.val; }
    friend bool operator!=(const mint &a, const mint &b) { return a.val != b.val; }
    friend bool operator<(const mint &a, const mint &b) { return a.val < b.val; }
    friend ostream& operator<<(ostream &os, const mint &a) { return os << a.val; }
    int val;
};
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<ll> rnd(20,10000);
using Mint1 = mint<MOD1>;
using Mint2 = mint<MOD2>;
using Mint = pair<Mint1,Mint2>;
const int N = 3e5 + 10, LOGN = 20;
int p1, p2;
int blen = 0;
int L[N * LOGN], R[N * LOGN];
Mint ST[N * LOGN], p_pow[N];
void prec() {
    p1 = rnd(rng);
    p2 = p1; 
    while (p2 == p1) p2 = rnd(rng);
    p_pow[0].ff = 1;
    p_pow[0].ss = 1;
    for (int i = 1; i < N; i++) {
        p_pow[i].ff = p_pow[i - 1].ff * p1;
        p_pow[i].ss = p_pow[i - 1].ss * p2;
    }
}
int update(int pos, int l, int r, int id) {
    if (pos < l || pos > r) return id;
    int ID = ++blen, m = (l + r) / 2;
    if (l == r) return (ST[ID] = {ST[id].ff + 1, ST[id].ss + 1}, ID);
    L[ID] = update(pos, l, m, L[id]);
    R[ID] = update(pos, m + 1, r, R[id]);
    return (ST[ID] = {ST[L[ID]].ff + p_pow[m - l + 1].ff * ST[R[ID]].ff, ST[L[ID]].ss + p_pow[m - l + 1].ss * ST[R[ID]].ss}, ID);
}
vi vals;
using a4 = array<int,4>;
void descent(int l, int r, const array<int, 4>& a, const array<int, 4>& b, int k) {
    if (l == r) return void(vals.push_back(l));
    int m = (l + r) / 2;
#define stm(X, y) {ST[X[y[0]]].ff + ST[X[y[1]]].ff - ST[X[y[2]]].ff - ST[X[y[3]]].ff, ST[X[y[0]]].ss + ST[X[y[1]]].ss - ST[X[y[2]]].ss - ST[X[y[3]]].ss}
#define arr(X, y) (a4{X[y[0]], X[y[1]], X[y[2]], X[y[3]]})
    Mint l1 = stm(L, a), l2 = stm(L, b), r1 = stm(R, a), r2 = stm(R, b);
    if (sz(vals) < k && l1 != l2) descent(l, m, arr(L, a), arr(L, b), k);
    if (sz(vals) < k && r1 != r2) descent(m + 1, r, arr(R, a), arr(R, b), k);
}
 
vvi adj;
vi a, roots, par; 
void dfs(int x, int p) {
    par[x] = p;
    roots[x] = update(a[x], 0, N, roots[par[x]]);
    for (auto& s : adj[x]) if (s != p) {
        dfs(s, x);
    }
}
void solve(){
    int n; cin >> n;        
    adj = vvi(n + 1);
    a = roots = par = vi(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b;
        adj[a].pb(b), adj[b].pb(a);
    }
    dfs(1, 0);
    LCA lca(adj);
    int q; cin >> q;
    while (q--) {
        vals.clear();
        int u1, v1, u2, v2, k; cin >> u1 >> v1 >> u2 >> v2 >> k;
        int l1 = lca.lca(u1, v1), l2 = lca.lca(u2, v2);
        a4 a{roots[u1], roots[v1], roots[l1], roots[par[l1]]};
        a4 b{roots[u2], roots[v2], roots[l2], roots[par[l2]]};
        descent(0, N, a, b, k);
        cout << sz(vals) << " ";
        for (auto& s : vals) cout << s << " ";
        cout << "n";
    }
}
signed main(){ 
    fightFight; 
    prec();
    solve(); 
}
```
