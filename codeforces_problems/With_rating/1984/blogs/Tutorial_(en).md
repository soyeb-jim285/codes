# Tutorial_(en)

Thank you for participating! We put a lot of effort into this contest. Special thanks to [TheScrasse](https://codeforces.com/profile/TheScrasse "Grandmaster TheScrasse") for contributing to these problems.

 **Rating Predictions**

| Person | A | B | C1 | C2 | D | E | F | G | H |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| [null_awe](https://codeforces.com/profile/null_awe "Grandmaster null_awe") | 800 | 1000 | 1200 | 1700 | 2200 | 2400 | 2500 | 2900 | 3400 |
| [buffering](https://codeforces.com/profile/buffering "Expert buffering") | 800 | 1000 | 1300 | 1800 | 2300 | 2400 | 2600 | 3100 | 3500 |
| [redpanda](https://codeforces.com/profile/redpanda "Expert redpanda") | 800 | 1100 | 1200 | 1800 |  |  |  |  |  |
| [TheScrasse](https://codeforces.com/profile/TheScrasse "Grandmaster TheScrasse") | 800 | 1000 | 1200 | 1600 | 2200 | 2500 | 2500 | 3100 | 3400 |
| [bronze_coder](https://codeforces.com/profile/bronze_coder "Grandmaster bronze_coder") | 800 | 1000 | 1600 | 1800 | 2400 |  |  | 2700 | 3500 |
| [awesomeguy856](https://codeforces.com/profile/awesomeguy856 "Master awesomeguy856") | 800 | 1100 | 1300 | 1700 | 2200 | 2300 | 2600 |  |  |
| [flamestorm](https://codeforces.com/profile/flamestorm "Master flamestorm") | 800 | 1100 | 1200 | 1600 | 2200 | 2400 | 2500 | 3100 | 3200 |
| [Ste](https://codeforces.com/profile/Ste "Master Ste") | 800 | 1100 | 1000 | 1600 | 2000 | 2400 | 2400 |  |  |

 

|  | A | B | C1 | C2 | D | E | F | G | H |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| Average | 800 | 1050 | 1250 | 1700 | 2214 | 2400 | 2516 | 2980 | 3400 |
| Actual | 800 | 1100 | 1300 | 1700 | 2000 | 2400 | 2500 | 3200 | 3300 |

Also, check out this video editorial for problems A through C2 by one of our testers! [https://www.youtube.com/watch?v=hS8Z3k57f6Q](https://codeforces.com/https://www.youtube.com/watch?v=hS8Z3k57f6Q)

#### Solutions

##### [1984A - Strange Splitting](../problems/A._Strange_Splitting.md "Codeforces Global Round 26")

Problem Credits: [buffering](https://codeforces.com/profile/buffering "Expert buffering")   
Analysis: [buffering](https://codeforces.com/profile/buffering "Expert buffering")

 **Hint 1**When is it impossible?

 **Answer**When a=[x,x…x] for some x.

 **Hint 2**Only color one element red to make the range 0. Which one do you pick to make the blue range different?

 **Solution**Read the hints.

It is impossible to color the array when all the elements are the same, because the range for the red and blue elements will always be 0. 

Otherwise, notice there will always be at least 2 distinct values in the array. This means there is a way to get a positive range for the blue elements, by taking the maximum value and the minimum value and coloring them blue. This works because n≥3, so there is at least one element left.

Since we can get a positive range, we can then try to get the red elements to have a range of 0, by coloring exactly one value red. So, we can color any ai for 2≤i≤n−1 red since it will not affect the positive range we constructed for the blue elements. For simplicity sake, our solution chooses i=2. Then, the remaining elements can be colored blue.

Therefore, our final solution is to check if it is impossible, or color a2 red and the rest blue.

 **Code (C++)**
```cpp
#include <iostream>
using namespace std;
int main(){
    int T; cin >> T;

    while (T--) {

        int n; cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        if (a[0] == a[n - 1]) {
            cout << "NO" << "n";
        }
        else {
            cout << "YES" << "n";
            string s(n, 'R'); 
            s[1] = 'B';
            cout << s << "n";

        }

        
    }
}
```
##### [1984B - Large Addition](../problems/B._Large_Addition.md "Codeforces Global Round 26")

Problem Credits: [flamestorm](https://codeforces.com/profile/flamestorm "Master flamestorm")   
Analysis: [null_awe](https://codeforces.com/profile/null_awe "Grandmaster null_awe")

Solution 1

 **Hint 1**What must the first (largest) digit be?

 **Hint 2**What must the other non-unit digits be?

 **Hint 3**What must the last digit be?

 **Solution**Because every digit is large, every two digits being added together will carry to the next digit. The two addends have the same length, so the sum must be one greater in length, with the largest digit equal to 1.

For all other digits except for the units digit, we have the value to be the sum of two large digits, plus 1 being carried over from the previous column. This makes the acceptable range of values be from 1 to 9, inclusive.

For the units digit, there is no previous column to carry over a 1, so the acceptable range of values is from 0 to 8, inclusive.

 **Code (C++)**
```cpp
  
#include <iostream>
using namespace std;
 
#define ll long long
 
void solve() {
  ll n; cin >> n;
  n = n - n % 10 + (n % 10 + 1) % 10;
  while (n > 9) {
    if (n % 10 == 0) {
      cout << "NOn";
      return;
    }
    n /= 10;
  }
  cout << (n == 1 ? "YESn" : "NOn");
}
 
int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int t; cin >> t;
  for (int i = 0; i < t; ++i) solve();
  return 0;
}


```
##### [1984C1 - Magnitude (Easy Version)](../problems/C1._Magnitude_(Easy_Version).md "Codeforces Global Round 26") and [1984C2 - Magnitude (Hard Version)](../problems/C2._Magnitude_(Hard_Version).md "Codeforces Global Round 26")

Problem Credits: [buffering](https://codeforces.com/profile/buffering "Expert buffering")   
Analysis: [null_awe](https://codeforces.com/profile/null_awe "Grandmaster null_awe")

 **Hint 1**How many times do we need to pick option 2?

 **Hint 2**We only need to pick it once. How can we calculate the final value for every position we can pick?

 **Solution (Easy Version)**We only need to pick option 2 once. Why? Assume we picked option 2 more than once, and consider the last two times it was picked. Both of these must occur when c+ai is negative, otherwise there is no reason to pick option 2 over option 1. Thus, if we chose option 1 the first of these times instead of option 2, that would cause the value of c before the second operation to decrease. Because it was negative, this increases the magnitude, and thus it was more optimal to choose option 1 for the first operation.

Because we only need to use option 2 once, we can brute force where we use that operation and compute the final value of c with prefix sums.

 **Solution (Hard Version)**Read the solution to the easy version first.

Let's think a bit more. Where do we actually end up using option 2? We only use option 2 when our prefix sum up to this point is minimum in the whole array.

Now, focus on each individual "important" use of option 2 (where it actually makes a difference from option 1), Let's say it is done at index i. Let's consider indices before. Since the operation at index i is the only important option 2, any option 2's we use before must not have been different from option 1 (meaning that the value of c+aj has to be non-negative). Thus, we have the choice of using option 2 or option 1 at any index j<i where the prefix sum is non-negative. Let's say there exists x unique values of j.

Now, let's consider indices after. Since index i is at a minimum prefix sum, that guarantees that all indices after will never have a lower value of c than what c is after doing the operation at index i. Thus, since we use option 2 at index i, we can use any of the two options moving forward. Thus, any index j>i has two choices on which option to pick. Let's say there exists y unique values of j.

The contribution of index i to the answer is then 2x+y.

Special case: the prefix sum never becomes negative. What is the answer then?

 **Code (C++)****Easy Version**
```cpp
  
#include <iostream>
#include <vector>
#include <climits>
using namespace std;
 
#define ll long long
 
void solve() {
  int n; cin >> n;
  vector<int> arr(n); for (int i = 0; i < n; ++i) cin >> arr[i];
  ll sum = 0, mn = 0;
  for (int i = 0; i < n; ++i) sum += arr[i], mn = min(mn, sum);
  cout << sum - 2 * mn << 'n';
}
 
int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int t; cin >> t;
  for (int i = 0; i < t; ++i) solve();
  return 0;
}

```
 **Hard Version**
```cpp
  
#include <iostream>
#include <vector>
#include <climits>
using namespace std;
 
#define ll long long
 
const ll MAX_N = 400001;
const ll MOD = 998244353;
 
vector<ll> p2(MAX_N);
 
void solve() {
  int n; cin >> n;
  vector<int> arr(n); for (int i = 0; i < n; ++i) cin >> arr[i];
  ll sum = 0, mn = 0, ans = 0, abses = 0;
  for (int i = 0; i < n; ++i) sum += arr[i], mn = min(mn, sum);
  if (mn == 0) {
      cout << p2[n] << 'n';
      return;
  }
  sum = 0;
  for (int i = 0; i < n; ++i) {
    sum += arr[i];
    if (sum == mn) {
      ans = (ans + p2[n - i - 1 + abses]) % MOD;
    }
    if (sum >= 0) ++abses;
  }
  cout << ans << 'n';
}
 
int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  p2[0] = 1;
  for (int i = 1; i < MAX_N; ++i) p2[i] = 2 * p2[i - 1] % MOD;
  int t; cin >> t;
  for (int i = 0; i < t; ++i) solve();
  return 0;
}

```
#### [1984D - ''a'' String Problem](../problems/D._''a''_String_Problem.md "Codeforces Global Round 26")

Problem Credits: [le0n](https://codeforces.com/profile/le0n "International Grandmaster le0n")   
Analysis: [null_awe](https://codeforces.com/profile/null_awe "Grandmaster null_awe")

 **Hint 1**What does t have to include?

 **Solution**Special case: the string consists of only "a", then answer is n−1.

Otherwise, t has to contain a character that is not "a". Let's consider one approach of counting. Let's force all t to start with the first non-a character, and see how many work.

To see if one of these strings t will work, we can start with i=0. As long as i does not point to the end of the string, we can find the next non-a character in s, and then see if the next |t| characters in s matches t. The last check mentioned can be done through hashing or using the Z-function. If it doesn't, this value of t doesn't work. Otherwise, we update i to the new current position and continue checking.

Now, if we find a string t that does work, we need to count its contribution to the answer. We can just add 1, but obviously not all working t will start with a non-a character. Instead, we can find the minimum unused "a"s before all of the substrings equal to t (call this m), and the current t will be able to extend out up to m "a"s at the beginning of the string. Thus, the contribution is m+1 to the answer.

How fast is this? Because we are checking at most one string t of each length, and the check itself can be made to take O(n|t|), we have a total time complexity of O(nlogn) due to harmonic sums.

 **Code (C++)**
```cpp
  
#include <iostream>
#include <vector>
#include <climits>
#include <set>
using namespace std;
 
#define ll long long
 
vector<int> z_function(string s) {
  int n = s.size();
  vector<int> z(n);
  int l = 0, r = 0;
  for(int i = 1; i < n; ++i) {
    if (i < r) z[i] = min(r - i, z[i - l]);
    while (i + z[i] < n && s[z[i]] == s[i + z[i]]) ++z[i];
    if (i + z[i] > r) l = i, r = i + z[i];
  }
  return z;
}
 
void solve() {
  int n; // cin >> n;
  string s; cin >> s;
  n = s.length();
  vector<int> nona(n, n);
  for (int i = n - 1; i >= 0; --i) {
    if (s[i] != 'a') nona[i] = i;
    else if (i + 1 < n) nona[i] = nona[i + 1];
  }
  if (nona[0] == n) {
    cout << n - 1 << 'n';
    return;
  }
  string s2 = "";
  int i1 = nona[0];
  for (int i = i1; i < n; ++i) s2 += s[i];
  vector<int> z = z_function(s2);
  ll ans = 0;
  for (int len = 1; i1 + len <= n; ++len) {
    int cur = i1 + len;
    int mn = i1;
    bool works = true;
    while (cur < n) {
      if (nona[cur] == n) break;
      int bt = nona[cur] - cur;
      mn = min(mn, bt);
      cur += bt;
      if (z[cur - i1] < len) {
        works = false;
        break;
      }
      cur += len;
    }
    if (works) ans += mn + 1;
  }
  cout << ans << 'n';
}
 
int main() {
  int t; cin >> t;
  for (int i = 0; i < t; ++i) solve();
  return 0;
}

```
#### [1984E - Shuffle](../problems/E._Shuffle.md "Codeforces Global Round 26")

Problem Credits: [null_awe](https://codeforces.com/profile/null_awe "Grandmaster null_awe"), thanks to [wavelets](https://codeforces.com/profile/wavelets "Grandmaster wavelets") for helping with brainstorming   
Analysis: [null_awe](https://codeforces.com/profile/null_awe "Grandmaster null_awe")

 **Solution**Excluding the root, the maximum number of leaves we have is the maximum independent set (MIS) of the rest of the tree. Why? First of all, after rooting tree T2, no two adjacent nodes can both be leaves. This is because, no matter which one you choose to add to T2 first, it must be the ancestor of the other one. Thus, the first chosen node will not be a leaf. Furthermore, any chosen MIS of nodes can all become leaves. This is because we can essentially choose to add all of the nodes not in the MIS first to the tree, leaving all of the remaining nodes to be childless nodes, making them all leaves.

To find the answer, we want to find the maximum MIS of all subtrees that are missing one leaf. The answer will be one greater than this maximum MIS due to the root of T2 being also a leaf.

There are multiple dynamic programming approaches to compute this efficiently, including rerooting and performing dynamic programming on tree edges.

Time complexity: O(n) or O(nlogn), depending on implementation.

 **Code (C++)**
```cpp
  
#include <iostream>
#include <vector>
#include <map>
using namespace std;
 
#define pii pair<int, int>
 
int n;
vector<vector<int>> adj;
vector<pii> edges;
map<pii, int> mp;
 
vector<vector<int>> dp;
vector<vector<int>> from;
vector<int> miss;
 
void dfs(int e) {
  if (dp[0][e] >= 0 || dp[1][e] >= 0) return;
  int p = edges[e].first, v = edges[e].second;
  dp[0][e] = 0, dp[1][e] = 1;
  if (miss[v] < 0) {
    for (int u : adj[v]) {
      if (u == p) continue;
      int ne = mp[{v, u}];
      dfs(ne);
      from[0][v] += max(dp[1][ne], dp[0][ne]);
      from[1][v] += dp[0][ne];
    }
    miss[v] = p;
  }
  if (miss[v] != p && miss[v] != n) {
    int ne = mp[{v, miss[v]}];
    dfs(ne);
    from[0][v] += max(dp[1][ne], dp[0][ne]);
    from[1][v] += dp[0][ne];
    miss[v] = n;
  }
  if (miss[v] == n) {
    int nne = mp[{v, p}];
    dp[0][e] += from[0][v] - max(dp[1][nne], dp[0][nne]);
    dp[1][e] += from[1][v] - dp[0][nne];
  } else if (miss[v] == p) {
    dp[0][e] += from[0][v];
    dp[1][e] += from[1][v];
  }
}
 
void solve() {
  cin >> n;
  adj.clear(), edges.clear();
  adj.resize(n), edges.resize(2 * n - 2);
  for (int i = 0; i < n - 1; ++i) {
    int a, b; cin >> a >> b; --a, --b;
    adj[a].push_back(b);
    adj[b].push_back(a);
    edges[2 * i] = {a, b};
    edges[2 * i + 1] = {b, a};
    mp[{a, b}] = 2 * i;
    mp[{b, a}] = 2 * i + 1;
  }
  from = vector<vector<int>>(2, vector<int>(n));
  miss = vector<int>(n, -1);
  dp = vector<vector<int>>(2, vector<int>(2 * n - 2, -1));
  for (int i = 0; i < 2 * n - 2; ++i) dfs(i);
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    if (adj[i].size() != 1) continue;
    int e = mp[{i, adj[i][0]}];
    ans = max(ans, 1 + max(dp[0][e], dp[1][e]));
  }
  cout << ans << 'n';
}
 
int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int t; cin >> t;
  for (int i = 0; i < t; ++i) solve();
  return 0;
}

```
#### [1984F - Reconstruction](../problems/F._Reconstruction.md "Codeforces Global Round 26")

Problem Credits: [buffering](https://codeforces.com/profile/buffering "Expert buffering")   
Analysis: [buffering](https://codeforces.com/profile/buffering "Expert buffering")

 **Hint 1**Solve for no question marks in the string first.

 **Hint 2**Add a 0 on both sides of a and b, and add a P before the start of the string and a S after the string. Now you are guaranteed to have a PS somewhere in the string. How does this help?

 **Answer**You know the sum of the array.

 **Hint 3**Look at adjacent elements in b, and its corresponding characters in the string, and see if you can determine anything about a.

 **Hint 4**Go back to the original problem, with question marks. We do not know the sum now, but how many possible ones can there be?

 **Solution**How to solve with no question marks?

To simplify things, let's extend all arrays both ways by 1 element. In array a and b, we can keep both values at 0, and in the string s, we can assign the left value to "P" and the right value to "S" (the other values will still be satisfied -- why?)

Now, somewhere within the string, we are guaranteed to see the combination "PS" because we now have a string that starts with "P" and ends with "S", therefore it must transition somewhere in between.

Notice, if we add the values in b of the "PS", we can gather the sum of the array.

Now, solving becomes simpler. We can focus on adjacent elements in the array. Say we are currently examining indices i and i+1. There are four cases:

 1. We are currently at a "PP". We then know bi+ai+1=bi+1, so ai+1 is now known.
2. We are currently at a "PS". Again, this must be the sum. All we have to do here is check that our sum is correct.
3. We are currently at an "SP". Here, we have bi+bi+1−SUM=ai+ai+1 (why?). Our left side is known, and the only requirement on the right side is that both ai and ai+1 have to have a magnitude of at most m. Thus, to make their maximum magnitude as small as possible, we make them as close as possible to each other. If the left side is x, we assign ai=floor(x/2), and ai+1=x−ai.
4. We are currently at an "SS". This is similar to the first case, as we know that bi=ai+bi+1. Thus, a[i] will be known.

If ai is always possible, then we know our answer exists.

Thus, this solves a version without question marks. For the version with question marks, we can only try to guess what the sum of the entire array is, since we don't know where "PS" might be for sure every time. There are only n possibilities — the sum of every pair of adjacent numbers in b.

For every possibility, we can run a `dp[i][j]` where we are currently at index i and the last character within "P" and "S" in string s used was j. This dynamic programming will run in linear time because of constant-time transitions and linear amount of states. Note that this is only possible due to the independent nature of adjacent pairs as described earlier.

With this DP, we can calculate how many paths are possible, adding to our answer.

Time complexity O(n2)

 **Code (C++)**
```cpp
  
#include <iostream>
#include <vector>
#include <cstring>
#include <assert.h>
#include <set>
using namespace std;
 
#define ll long long
 
const int INF = 998244353;
// const int BOUND = 1e9;
 
void solve() {
  int n; cin >> n;
  int BOUND; cin >> BOUND;
  string s; cin >> s;
  s = "P" + s + "S";
  vector<ll> b(n + 2);
  for (int i = 0; i < n; ++i) cin >> b[i + 1];
  ll ans = 0;
  set<ll> done;
  for (int i = 0; i < n + 1; ++i) {
    ll sum = b[i] + b[i + 1];
    if (done.count(sum)) continue;
    int dp[n + 2][2];
    for (int j = 0; j < n + 2; ++j) for (int k = 0; k < 2; ++k) dp[j][k] = -1;
    // ["P", "S"]
    dp[0][0] = 1;
    for (int j = 1; j < n + 2; ++j) {
      bool tr[2]; tr[0] = tr[1] = true;
      if (s[j] == 'P') tr[1] = false;
      else if (s[j] == 'S') tr[0] = false;
      if (abs(b[j] - b[j - 1]) <= BOUND) {
        for (int k = 0; k < 2; ++k)
          if (dp[j - 1][k] > -1 && tr[k]) dp[j][k] = dp[j - 1][k];
      }
      if (dp[j - 1][0] > -1 && tr[1] && sum == b[j] + b[j - 1]) {
        // "P" -> "S":
        if (dp[j][1] < 0) dp[j][1] = 0;
        dp[j][1] = (dp[j][1] + dp[j - 1][0]) % INF;
      }
      if (dp[j - 1][1] > -1 && tr[0]) {
        // "S" -> "P":
        ll add = b[j] + b[j - 1] - sum;
        ll large = max(abs(add / 2), abs(add - add / 2));
        if (large <= BOUND) {
          if (dp[j][0] < 0) dp[j][0] = 0;
          dp[j][0] = (dp[j][0] + dp[j - 1][1]) % INF;
        }
      }
    }
    if (dp[n + 1][1] < 0) continue;
    ans = (ans + dp[n + 1][1]) % INF;
    done.insert(sum);
  }
  cout << ans << 'n';
}
 
int main() {
  ios::sync_with_stdio(false); cin.tie(NULL);
  int t; cin >> t;
  for (int i = 0; i < t; ++i) solve();
  return 0;
}

```
#### [1984G - Magic Trick II](../problems/G._Magic_Trick_II.md "Codeforces Global Round 26")

Problem Credits: [null_awe](https://codeforces.com/profile/null_awe "Grandmaster null_awe")   
Analysis: [null_awe](https://codeforces.com/profile/null_awe "Grandmaster null_awe")

 **Hint 1**Solve what the maximum k will be for different types of arrays.

 **Hint 2**The maximum is always close to n.

 **Solution**There exists two trivial cases. If array is already sorted, k=n. If array is cyclic shift of sorted array, k=n−1. Now, k=n−2 and k=n−3 is sufficient to sort any array.

Let's assume n is odd first, and construct an answer in the general case with k=n−2. Because k is so large, our operations are limited in choices. If we represent the array as a cyclic array with a divider representing the end of the array, an operation can be seen as two choices:

 1. Move the divider 2 positions in any direction.
2. Swap the two numbers around the divider, then move the divider by 1 position in any direction.

With this representation, the construction becomes quite easy. Because n is odd, we can use the first type of operation to put the divider wherever we want. Then, using the second type of operation, if our divider is on the right side of a specific number, we can move it all the way to the right by swapping, then moving the divider right by 1 position.

Because we are able to do this, we can bubble sort. For each number, position the divider in O(n) moves, then move it to the very right in another O(n) moves. There are n numbers total, so this takes a total of around 2n2 operations, less if optimized.

What if n is even? In this case k=n−2 is not always guaranteed to work. The motivation for seeing this can come from the fact that you can't place the divider anywhere just by using type 1 operations.

As a lower bound, we know that k=n−3 will always work. We can use operations to move the largest number to the very end, then we basically have an array of length n−1 with k=n−3, which is the odd case we presented earlier.

So, when can we use k=n−2 in the even case? Let's consider the number of inversions in the array at any given time. If n is even, then k=n−2 is also even, meaning that the parity of the number of inversions will never change with operations. Thus, since a sorted array will have no inversions, we cannot use k=n−2 if the initial array had an odd number of inversions.

If we have an even number of inversions, we can sort in a similar manner. Except, now, if the inversion constraint prevents moving the divider to the immediate right of our current number with only type 1 operations, we can use a few type 2 operations to fix the position of the divider (many possible strategies for this, one possible way is shown in the implementation). Overall, this should also take around 2n2 operations total.

 **Code (C++)**
```cpp
  
#include <iostream>
#include <vector>
using namespace std;
 
#define pii pair<int, int>
 
bool sorted(vector<int> arr, int n) {
  for (int i = 1; i < n; ++i) if (arr[i] < arr[i - 1]) return false;
  return true;
}
 
bool cyclic(vector<int> arr, int n) {
  for (int i = 1; i < n; ++i) if (arr[i] % n != (arr[i - 1] + 1) % n) return false;
  return true;
}
 
void solve() {
  int n; cin >> n;
  vector<int> arr(n); for (int i = 0; i < n; ++i) cin >> arr[i];
  if (sorted(arr, n)) {
    cout << n << "n0n";
    return;
  }
  if (cyclic(arr, n)) {
    cout << n - 1 << 'n';
    int pos;
    for (pos = 0; pos < n; ++pos) if (arr[pos] == 1) break;
    cout << pos << 'n';
    for (int i = 0; i < pos; ++i) {
      cout << "2 1n";
    }
    return;
  }
  vector<pii> ops;
  if (n % 2 == 0) {
    int inv = 0;
    for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) if (arr[i] > arr[j]) ++inv;
    if (inv & 1) {
      int pos;
      for (pos = 0; pos < n; ++pos) if (arr[pos] == n) break;
      if (pos < 3) {
        for (int i = 0; i <= pos; ++i) ops.push_back({2, 1});
        vector<int> tmp = arr;
        for (int i = 0; i < n - 2; ++i) arr[i] = tmp[(i + pos + 1) % (n - 2)];
      }
      for (pos = 0; pos < n; ++pos) if (arr[pos] == n) break;
      for (int i = pos; i < n - 1; ++i) ops.push_back({3, 4});
      vector<int> tmp = arr;
      for (int i = 2; i < n; ++i) arr[i] = tmp[((i + pos - 3) % (n - 2)) + 2];
      --n;
    }
  }
  cout << n - 2 << 'n';
  int div = 0;
  for (int i = n; i > 0; --i) {
    int pos;
    for (pos = 0; pos < n; ++pos) if (arr[pos] == i) break;
    pos += 1;
    if (pos == i) continue;
    if (div % 2 != pos % 2) {
      if (n & 1) {
        while (div < n) {
          ops.push_back({3, 1});
          div += 2;
        }
        div %= n;
      } else {
        while (div != pos - 1) {
          if (div < pos - 1) {
            ops.push_back({3, 1});
            div += 2;
          } else {
            ops.push_back({1, 3});
            div -= 2;
          }
        }
        if (pos > 1) {
          ops.push_back({2, 3});
          swap(arr[(div + n - 1) % n], arr[div]);
          div = (div + n - 1) % n;
          --pos;
        }
        ops.push_back({3, 1});
        div += 2;
        ops.push_back({2, 3});
        swap(arr[(div + n - 1) % n], arr[div]);
        div = (div + n - 1) % n;
      }
    }
    while (div != pos) {
      if (div < pos) {
        ops.push_back({3, 1});
        div += 2;
      } else {
        ops.push_back({1, 3});
        div -= 2;
      }
    }
    for (int j = pos; j < i; ++j) {
      ops.push_back({2, 1});
      swap(arr[div - 1], arr[div]);
      ++div;
    }
  }
  if (div % 2 == 1) {
    while (div < n) {
      ops.push_back({3, 1});
      div += 2;
    }
    div %= n;
  }
  while (div > 0) {
    ops.push_back({1, 3});
    div -= 2;
  }
  cout << ops.size() << 'n';
  for (pii p : ops) {
    cout << p.first << ' ' << p.second << 'n';
  }
}
 
int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int t; cin >> t;
  for (int i = 0; i < t; ++i) solve();
  return 0;
}

```
#### [1984H - Tower Capturing](../problems/H._Tower_Capturing.md "Codeforces Global Round 26")

Problem Credits: [flamestorm](https://codeforces.com/profile/flamestorm "Master flamestorm")   
Analysis: [flamestorm](https://codeforces.com/profile/flamestorm "Master flamestorm")

 **Hint 1**Are there any useless points?

 **Hint 2**Draw all triangles that contain all points inside their circumcircle. What do you notice?

 **Solution****Claim.** We can't ever pick a tower inside the convex hull.

**Proof.** A circle can only contain all the points if the points on the circle are on the convex hull; otherwise, the circle will necessarily split the convex hull into two parts, one of which is outside.

It follows that if our initial two towers aren't on the convex hull, the answer is 0. Also, we can safely ignore all points in the convex hull, since we'll capture them anyway, as the convex hull is the union of all triangles whose vertices are vertices of the convex hull. From now on we'll only consider points on the convex hull.

Now comes the key claim of the problem.

**Claim.** Call a triangle *covering* if its circumcircle contains all the points. Draw all covering triangles. We claim that these triangles form a triangulation of the convex hull.

**Proof.** Recall that a triangulation is a set of triangles with pairwise non-intersecting interiors whose union is the polygon. There are two parts to the proof:

 1. the triangles are pairwise non-intersecting.
2. their union is the polygon.

Let's prove them separately. 

First we'll prove point (1) directly.

Consider two circles through points ABC and DEF. Of course, the convex hull needs to lie in the intersection of the two circles. In particular, the circle through ABC must contain the points DEF, while the circle through DEF must contain the points ABC. It follows that the two circumcircles (say, Ω and Ψ respectively) have the following property:

 * the points A, B, C lie on an arc of Ω inside Ψ, and
* the points D, E, F lie on an arc of Ψ inside Ω.

The claim follows. Formally, we can define U and V as the intersection points of Ω and Ψ. Then if we walk along the digon UV (whose edges are arcs of Ω and Ψ), we will pass through A, B, C along one of the arcs, and D, E, F on the other. This means that there is some closed convex loop passing through the points A, B, C before D, E, F, implying those two triangles don't intersect. The proof remains the same even if some of A, B, C, D, E, F overlap.

Now we'll move on to the proof of (2). Consider any covering triangle ABC. WLOG suppose AB is not an edge of the convex hull. Consider the points in the halfplane of AB not containing C, and let C′ be the point among these such that ∠AC′B is minimized. Then it follows that ABC′ is also covering. It's easy to see why this works and why C′ is unique by the inscribed angle theorem.

As a result, given any covering triangle, we can recursively triangulate the regions it cuts off by a chord. Thus, inductively, the whole polygon will be triangulated. We are done with the proof.

Note that this implies our original three towers in the problem must form a covering triangle, since we create a covering triangle after every operation; thus, at the end of these operations, all but possibly one of these triangles is covering (the "possibly one" is the initial triangle). But such a covering triangulation exists and is unique, as shown, so our initial triangle in fact must be covering.

Now on to the actual operations present in the problem. Using them, we can "construct" the triangulation one step at a time using operations like the one mentioned. Of course, the triangulation is unique, so the only change we can do is the order in which we construct the triangles.

Consider the dual tree of the triangulation (that is, make a vertex for each triangle and an edge between those vertices corresponding to two triangles that share a diagonal of the convex hull). In an operation, we attach a leaf to any vertex, and in the end we end up with the final dual tree. Note that we can start growing the tree at either triangle adjacent to our original diagonal; that is, if our original points are A and B, then we need to consider rooting our tree at either T1 or T2, where those are the two triangles that contain the edge AB (note that T2 may not exist).

Let's reverse time. Then given the final tree (rooted at either T1 or T2), in an operation we prune a leaf (a leaf here is a vertex with no children). How many ways can we prune all the leaves?

This is a standard dynamic programming problem, since at each step we need to prune all of our children before we prune ourselves. In particular, if the sizes of our childrens' subtrees are s1,…,sk, then our answer is (s1+⋯+sks1,…,sk)⋅∏ki=1ans(childi). This DP runs in O(n) time, so it is not a problem to compute.

We can easily compute the triangulation in O(n2) time as follows: given an edge PQ, we need to find the point R in a halfplane such that (PQR) covers all points, and as mentioned before, by the inscribed angle theorem this is precisely the point R such that PQR′ is minimized. So you can find it with an O(n) sweep and add the new edges to our triangulation.

Therefore the solution runs in O(n2), but the validator takes O(n3) to check. We accepted slower solutions in O(n3) as well, and even O(n4) with a decent constant factor (which are relatively hard to cut).

A note about implementation: I'm not very good at it, so my code below is a bit messy. Also, to keep the computations in integers, I needed to use big integers at exactly one point, but it's not so bad: you only need to implement big integer multiplication and comparison, which I shamelessly stole from [jeroenodb](https://codeforces.com/profile/jeroenodb "International Grandmaster jeroenodb"). You may not need to use it, and can pass using floating-point numbers.

 **Code (C++)**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 998244353;

struct bignum {
    static constexpr long long B = 1LL<<30;
    static constexpr int N = 6;
    array<long long, N> b = {};
    bignum() {}
    bignum(long long a) {
        b[2] = (a / B) / B;
        b[1] = (a / B) % B;
        b[0] = a % B;
    }
    bignum operator*(const bignum& o) {
        bignum res;
        for (int i = 0; i < N; i++) {
		    for (int j = 0; j + i < N; j++) {
		        res.b[i + j] += b[i] * o.b[j];
		        for (int k = i + j; k + 1 < N; k++) {
		            auto tmp = res.b[k] / B;
		            res.b[k + 1] += tmp;
		            res.b[k] -= tmp * B;
		        }
		    }
		}
        return res;
    }
    bool operator<=(const bignum& o) const {
        if (b == o.b) return true;
        return lexicographical_compare(b.rbegin(),b.rend(),o.b.rbegin(),o.b.rend());
    }
};

template <class T> int sgn(T x) { return (x > 0) - (x < 0); }
template<class T>
struct Point {
	typedef Point P;
	T x, y;
	explicit Point(T x=0, T y=0) : x(x), y(y) {}
	bool operator<(P p) const { return tie(x,y) < tie(p.x,p.y); }
	bool operator==(P p) const { return tie(x,y)==tie(p.x,p.y); }
	P operator+(P p) const { return P(x+p.x, y+p.y); }
	P operator-(P p) const { return P(x-p.x, y-p.y); }
	P operator*(T d) const { return P(x*d, y*d); }
	P operator/(T d) const { return P(x/d, y/d); }
	T dot(P p) const { return x*p.x + y*p.y; }
	T cross(P p) const { return x*p.y - y*p.x; }
	T cross(P a, P b) const { return (a-*this).cross(b-*this); }
	T dist2() const { return x*x + y*y; }
	double dist() const { return sqrt((double)dist2()); }
	// angle to x-axis in interval [-pi, pi]
	double angle() const { return atan2(y, x); }
	P unit() const { return *this/dist(); } // makes dist()=1
	P perp() const { return P(-y, x); } // rotates +90 degrees
	P normal() const { return perp().unit(); }
	// returns point rotated 'a' radians ccw around the origin
	P rotate(double a) const {
		return P(x*cos(a)-y*sin(a),x*sin(a)+y*cos(a)); }
	friend ostream& operator<<(ostream& os, P p) {
		return os << "(" << p.x << "," << p.y << ")"; }
	friend istream& operator>>(istream& is, P& p) {
		return is >> p.x >> p.y; }
};

typedef Point<long long> P;
vector<P> convexHull(vector<P> pts) {
	if (pts.size() <= 1) return pts;
	sort(pts.begin(), pts.end());
	vector<P> h(pts.size()+1);
	int s = 0, t = 0;
	for (int it = 2; it--; s = --t, reverse(pts.begin(), pts.end()))
		for (P p : pts) {
			while (t >= s + 2 && h[t-2].cross(h[t-1], p) <= 0) t--;
			h[t++] = p;
		}
	return {h.begin(), h.begin() + t - (t == 2 && h[0] == h[1])};
}

int n, t;
long long inv[MAX], fact[MAX], invfact[MAX];
vector<P> v;

void orient(P &a, P &b, P &c) {
	// move points a, b, c to be in counterclockwise order
	long long val = (b - a).cross(c - a);
	assert(val != 0);
	if (val < 0) {swap(a, c);} 
}

pair<long long, long long> angleComp(P a, P b, P c) {
	// get a (scaled) value of f(cos(angle ABC))
	P ab = a - b, cb = c - b;
	long long dt = ab.dot(cb);
	dt *= dt;
	int sgn = (ab.dist2() + cb.dist2() >= (a - c).dist2() ? 1 : -1);
	return make_pair(sgn * dt, ab.dist2() * cb.dist2());
}

bool inCircle(P a, P b, P c, P d) {
	// is D in (or on) (ABC)?
	orient(a, b, c);
	P ad = a - d, bd = b - d, cd = c - d;
	return (
		ad.dist2() * (bd.x * cd.y - bd.y * cd.x) -
		bd.dist2() * (ad.x * cd.y - ad.y * cd.x) +
		cd.dist2() * (ad.x * bd.y - ad.y * bd.x)
	) >= 0;
}

pair<bool, int> check(int l, int r) {
	int start = l, finish = r;
	if (finish < start) {finish += n;}
	pair<long long, long long> best = make_pair(-MOD, 1);
	int w = -1;
	for (int i = start + 1; i < finish; i++) {
		pair<long long, long long> val = angleComp(v[l], v[i % n], v[r]);
		bignum v1 = bignum(val.first) * bignum(best.second);
		bignum v2 = bignum(val.second) * bignum(best.first);
		if (!(v1 <= v2)) {
			best = val;
			w = i % n;
		}
	}
	if (w == -1) {
		// cout << v[l] << ' ' << v[r] << " empty?n";
		return make_pair(true, -1);
	}
	// cout << v[l] << ' ' << v[r] << " connects to " << v[w] << "?n";
	for (P Q : v) {
		if (!inCircle(v[l], v[w], v[r], Q)) {return make_pair(false, -1);}
	}
	return make_pair(true, w);
}

void reset(int n) {
	v.clear();
	// for (int i = 0; i < n + 5; i++) {
		// g[i].clear();
		// child[i].clear();
	// }
	t = 1;
}

void solve() {
	cin >> n;
	reset(n);
	vector<P> pts(n);
	for (int i = 0; i < n; i++) {
		cin >> pts[i];
	}
	vector<P> us{pts[0], pts[1]};
	vector<int> us_vals;
	v = convexHull(pts);
	n = v.size();
	for (auto P : us) {
		int i = 0; bool hit = false;
		for (auto Q : v) {
			if (P == Q) {us_vals.push_back(i); hit = true;}
			i++;
		}
		if (!hit) {cout << 0 << 'n'; return;}
	}
	if (v.size() <= 3) {cout << 1 << 'n'; return;}
	queue<pair<pair<int, int>, int>> q;
	vector<int> child[MAX];
	q.push(make_pair(make_pair(us_vals[0], us_vals[1]), -1));
	q.push(make_pair(make_pair(us_vals[1], us_vals[0]), -1));
	while (!q.empty()) {
		auto p = q.front();
		q.pop();
		pair<bool, int> resp = check(p.first.first, p.first.second);
		if (!resp.first) {cout << 0 << 'n'; return;}
		if (resp.second == -1) {continue;}
		q.push(make_pair(make_pair(p.first.first, resp.second), t));
		q.push(make_pair(make_pair(resp.second, p.first.second), t));
		if (p.second != -1) {
			child[p.second].push_back(t);
		}
		t++;
	}
	// for (int i = 1; i <= n - 2; i++) {
		// cout << i << ": ";
		// for (int j : child[i]) {cout << j << ' ';}
		// cout << 'n';
	// }
	bool edge_case = true; // both 1 and 2 are roots
	for (int j : child[1]) {
		if (j == 2) {edge_case = false;} // only 1 is root
	}
	
	vector<long long> dp(n + 7);
	vector<int> sz(n + 7);
	
	auto cnt = [&](auto self, int v) -> int {
		if (sz[v] != -1) {return sz[v];}
		int res = 1;
		if (!child[v].empty()) {
			for (int u : child[v]) {
				res += self(self, u);
			}
		}
		sz[v] = res;
		return res;
	};
	
	auto f = [&](auto self, int v) -> long long {
		if (dp[v] != -1LL) {return dp[v];}
		long long res = 1LL;
		if (!child[v].empty()) {
			res = (res * fact[cnt(cnt, v) - 1]) % MOD;
			for (int u : child[v]) {
				res = (res * self(self, u)) % MOD;
				res = (res * invfact[cnt(cnt, u)]) % MOD;
			}
		}
		dp[v] = res;
		return res;
	};

	if (edge_case) {child[1].push_back(2);}
	
	fill(dp.begin(), dp.end(), -1LL);
	fill(sz.begin(), sz.end(), -1);
	long long res = f(f, 1);
	
	if (edge_case) {
		child[1].erase(remove(child[1].begin(), child[1].end(), 2), child[1].end());
		child[2].push_back(1);
		fill(dp.begin(), dp.end(), -1LL);
		fill(sz.begin(), sz.end(), -1);
		res = (res + f(f, 2)) % MOD;
	}
	
	cout << res << 'n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	inv[0] = inv[1] = 1;
	for (int i = 2; i < MAX; i++) {
		inv[i] = MOD - (long long)(MOD / i) * inv[MOD % i] % MOD;
	}
	fact[0] = fact[1] = 1; invfact[0] = invfact[1] = 1;
	for (int i = 2; i < MAX; i++) {
		fact[i] = (fact[i - 1] * (long long)i) % MOD;
		invfact[i] = (invfact[i - 1] * inv[i]) % MOD;
	}
	int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
	// solve();
}
```
