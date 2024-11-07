# Tutorial

[1620A - Equal or Not Equal](../problems/A._Equal_or_Not_Equal.md "Educational Codeforces Round 119 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1620A - Equal or Not Equal](../problems/A._Equal_or_Not_Equal.md "Educational Codeforces Round 119 (Rated for Div. 2)")

Let's look at a group of E: it's easy to see that each such a group is equal to the same number. Now, let's look at how these groups are distributed on the circle:

1. If there are no N then all ai are just equal to each other. It's okay.
2. If there is exactly one N then from one side, all of them are still in one group, so they should be equal, but from the other side, one pair should have different values. It's contradiction.
3. If there are more than one N then all numbers are divided in several groups with different values. It's okay.

As a result, array a exists as long as the number of N isn't 1.

 **Solution (Neon)**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    cout << (count(s.begin(), s.end(), 'N') == 1 ? "NOn" : "YESn");
  }
} 
```
[1620B - Triangles on a Rectangle](../problems/B._Triangles_on_a_Rectangle.md "Educational Codeforces Round 119 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1620B - Triangles on a Rectangle](../problems/B._Triangles_on_a_Rectangle.md "Educational Codeforces Round 119 (Rated for Div. 2)")

The area of a triangle is equal to its base multiplied by its height divided by 2. Let the two points that have to be on the same side of a rectangle form its base. To maximize it, let's choose such two points that are the most apart from each other — the first and the last in the list.

Then the height will be determined by the distance from that side to the remaining point. Since there are points on all sides, the points on the opposite side are the furthest. Thus, the height is always one of h or w, depending on whether we picked the horizontal or the vertical side.

So we have to check four options to pick the side and choose the best answer among them.

 **Solution (awoo)**
```cpp
for _ in range(int(input())):
  w, h = map(int, input().split())
  ans = 0
  for i in range(4):
    a = [int(x) for x in input().split()][1:]
    ans = max(ans, (a[-1] - a[0]) * (h if i < 2 else w))
  print(ans)
```
[1620C - BA-String](../problems/C._BA-String.md "Educational Codeforces Round 119 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1620C - BA-String](../problems/C._BA-String.md "Educational Codeforces Round 119 (Rated for Div. 2)")

Find all segments of asterisks in the string. Let there be t of them, and the number of asterisks in them be c1,c2,…,ct. That tells us that the i-th segment of asterisks can be replaced with at most ci⋅k letters 'b'.

Notice that we can compare two strings lexicographically using just the number of letters 'b' that replace each of t segments of asterisks. Let that sequence for some string a be A1,A2,…,At and that sequence for some string b be B1,B2,…,Bt. Then a<b if and only if A<B. That is, there exists such position i that Ai<Bi. The proof is trivial.

So we can actually look at the sequence A1,A2,…,At as some kind of number in a mixed base. The lowest "digit" At can be of one of ct⋅k+1 values (from 0 to ct⋅k). The second lowest — one of ct−1⋅k+1. And so on. Then, comparison of two strings is the same as comparison of these two mixed base numbers.

Thus, the task is to convert number x−1 to this mixed base. Turns out, it's not that hard. In base 10, for example, the lowest digit can be determined as the remainder of the number of dividing by 10. Here it will be the remainder of dividing by ct⋅k+1. After that, divide and floor the number and proceed to the next "digit".

After t steps are done, the "digits" of that mixed base number tell exactly how many letters 'b' should replace each segment of asterisks.

Overall complexity: O(n) per testcase to recover the string, O(nk) to print it.

 **Solution (awoo)**
```cpp
for _ in range(int(input())):
  n, k, x = map(int, input().split())
  x -= 1
  s = input()[::-1]
  res = []
  i = 0
  while i < n:
    if s[i] == 'a':
      res.append(s[i])
    else:
      j = i
      while j + 1 < n and s[j + 1] == s[i]:
        j += 1
      cur = (j - i + 1) * k + 1
      res.append('b' * (x % cur))
      x //= cur
      i = j
    i += 1
  print(''.join(res[::-1]))
```
[1620D - Exact Change](../problems/D._Exact_Change.md "Educational Codeforces Round 119 (Rated for Div. 2)")

Idea: [adedalic](https://codeforces.com/profile/adedalic "International Master adedalic")

 **Tutorial**
### [1620D - Exact Change](../problems/D._Exact_Change.md "Educational Codeforces Round 119 (Rated for Div. 2)")

Let's define m=max(ai), then it should be obvious that we need at least r=⌈m3⌉ coins to buy a bag of chips of cost m. Now, it's not hard to prove that r+1 coins is always enough to buy a bag of chips of any cost c≤m. Proof: 

* if m≡0(mod3), we'll take r−1 coins of value 3, coin 1 and coin 2;
* if m≡2(mod3), we'll take r−1 coins 3 and two coins 1;
* if m≡1(mod3), we'll take r−2 coins 3, one coin 2 and two coins 1.

So the question is how to decide, is r coins enough. The solution is to note that there is no need to take more than 3 coins 1 and more than 3 coins 2, so we can just brute force the number of coins 1 we'll take c1 and the number of coins 2 we'll take c2. Then, the number of coins 3 c3=⌈m−c1−2c23⌉, and we can check: is it possible to pay exactly ai using at most c1, c2 and c3 coins respectively. 

There exists casework solution as well, but it's quite tricky, so brute force is preferable. The main problem for case work is the case m≡1(mod3), since there are two different ways to take r coins: either r−1 coins 3 and coin 1 or r−2 coins 3 and two coins 2. In the first way, you can't gather exactly ai≡2(mod3) and in the second one, you can gather neither ai=m−1 nor ai=1.

 **Solution (adedalic)**
```cpp
#include<bits/stdc++.h>

using namespace std;

#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define sz(a) int((a).size())

template<class A, class B> ostream& operator <<(ostream& out, const pair<A, B> &p) {
  return out << "(" << p.x << ", " << p.y << ")";
}
template<class A> ostream& operator <<(ostream& out, const vector<A> &v) {
  fore(i, 0, sz(v)) {
    if(i) out << " ";
    out << v[i];
  }
  return out;
}

int n;
vector<int> a;

inline bool read() {
  if(!(cin >> n))
    return false;
  a.resize(n);
  fore (i, 0, n)
    cin >> a[i];
  return true;
}

bool p(int val, int c1, int c2, int c3) {
  fore (cur1, 0, c1 + 1) fore (cur2, 0, c2 + 1) {
    if (cur1 + 2 * cur2 > val)
      continue;
    if ((val - cur1 - 2 * cur2) % 3 != 0)
      continue;
    if ((val - cur1 - 2 * cur2) / 3 <= c3)
      return true;
  }
  return false;
}

bool possible(int c1, int c2, int c3) {
  for (int v : a) {
    if (!p(v, c1, c2, c3))
      return false;
  }
  return true;
}

inline void solve() {
  int m = *max_element(a.begin(), a.end());
  int ans = int(1e9);
  
  const int MAG = 3;
  fore (c1, 0, MAG) fore (c2, 0, MAG) {
    int c3 = max(0, (m - c1 - 2 * c2 + 2) / 3);
    assert(c1 + 2 * c2 + 3 * c3 >= m);
    
    if (possible(c1, c2, c3))
      ans = min(ans, c1 + c2 + c3);
  }
  cout << ans << endl;
}

int main() {
#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
#endif
  int t; cin >> t;
  while(t--) {
    read();
    solve();
  }
  return 0;
}
```
[1620E - Replace the Numbers](../problems/E._Replace_the_Numbers.md "Educational Codeforces Round 119 (Rated for Div. 2)")

Idea: [Neon](https://codeforces.com/profile/Neon "Candidate Master Neon")

 **Tutorial**
### [1620E - Replace the Numbers](../problems/E._Replace_the_Numbers.md "Educational Codeforces Round 119 (Rated for Div. 2)")

Let's solve the problem from the end. Let's maintain the array $p_x$ — what number will $x$ become if we apply to it all the already considered queries of type $2$. If the current query is of the first type, then we simply add $p_x$ to the resulting array. If the current query is of the second type, then we have to change the value of $p_x$. Since all occurrences of $x$ must be replaced with $y$, it is enough to assign $p_x = p_y$.

Since we process each query in $O(1)$, the final complexity is $O(n)$.

There is also an alternative solution. Let's process queries in the direct order. Let's store all its positions in an array for each number. Then for the first query, it is enough to put the index in the corresponding array of positions. And for a query of the second type, we have to move all the positions of the number $x$ into an array of positions of the number $y$. The naive implementation is obviously too slow, but we can use the small to large method, then the complexity of the solution will be $O(n \log{n})$.

 **Solution 1 (Neon)**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int N = 500 * 1000 + 13;

int main() {
  int q;
  scanf("%d", &q);
  vector<int> t(q), x(q), y(q);
  for (int i = 0; i < q; ++i) {
    scanf("%d%d", &t[i], &x[i]);
    if (t[i] == 2) scanf("%d", &y[i]);
  }
  vector<int> p(N);
  iota(p.begin(), p.end(), 0);
  vector<int> ans;
  for (int i = q - 1; i >= 0; --i) {
    if (t[i] == 1) {
      ans.push_back(p[x[i]]);
    } else {
      p[x[i]] = p[y[i]];
    }
  }
  reverse(ans.begin(), ans.end());
  for (int &x : ans) printf("%d ", x);
} 
```
 **Solution 2 (Neon)**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int N = 500 * 1000 + 13;

int n, q;
vector<int> pos[N];

int main() {
  scanf("%d", &q);
  while (q--) {
    int t, x, y;
    scanf("%d", &t);
    if (t == 1) {
      scanf("%d", &x);
      pos[x].push_back(n++);
    } else {
      scanf("%d%d", &x, &y);
      if (x != y) {
        if (pos[x].size() > pos[y].size()) pos[x].swap(pos[y]);
        for (int &i : pos[x]) pos[y].push_back(i);
        pos[x].clear();
      }
    }
  }
  vector<int> ans(n);
  for (int x = 0; x < N; ++x)
    for (int &i : pos[x]) 
      ans[i] = x;
  for (int &x : ans) printf("%d ", x);
} 
```
[1620F - Bipartite Array](../problems/F._Bipartite_Array.md "Educational Codeforces Round 119 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest") and [Neon](https://codeforces.com/profile/Neon "Candidate Master Neon")

 **Tutorial**
### [1620F - Bipartite Array](../problems/F._Bipartite_Array.md "Educational Codeforces Round 119 (Rated for Div. 2)")

To begin with, let's understand that an array is bipartite if and only if there is no decreasing subsequence of length 3 in the array.

Now we can write dynamic programming dpi,x,y: is there an array a of length i such that x is the maximum last element of a decreasing subsequence of length 1, and y is the maximum last element of a subsequence of length 2. Note that x>y.

Let's consider all possible transitions from the state (i,x,y) if we are trying to put the number z on the i-th position, where z=±pi:

* if z>x, then the new state will be (i+1,z,y);
* if z>y, then the new state will be (i+1,x,z);
* if z<y, then such a transition is not valid, because a decreasing subsequence of length 3 is formed in the array.

With a naive implementation, such dynamic programming works in O(n3).

We can note that for fixed values of i and x (i and y) it is enough for us to store only the minimum available value of y (x). So, we can write dynamic programming dpi,x, which is defined similarly to the above, but now instead of being Boolean, stores the minimum value of y (or infinity if the state is not valid).

We have speeded up our solution to O(n2), but it is still too slow.

To speed up the solution even more, we have to look at the transitions in dynamics and notice that for a fixed i, either x or y is always equal to ±pi−1. So we can rewrite our dynamic programming in the following form — dpi,pos,sign. Here, the pos flag says which of the numbers x and y is equal to ±pi−1, and the sign flag is responsible for the sign of pi−1, and the minimum value of y or x is stored in the value itself (depending on pos).

Thus, we got a solution with a linear running time.

In fact, this solution can be simplified if we see the following relation: the number we use on position i is not less than dpi,0,sign and not greater than dpi,1,sign. This allows us to get rid of one of the states in our dynamic programming altogether, so we get an easier solution. This optimization wasn't required to get AC, but the code becomes shorter.

 **Solution 1 (Neon)**
```cpp
#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); ++i)

const int INF = 1e9;
const int N = 1000 * 1000 + 13;

int n;
int p[N], a[N];
int dp[N][2][2];
pair<int, int> pr[N][2][2];

void solve() {
  scanf("%d", &n);
  forn(i, n) scanf("%d", &p[i]);
  forn(i, n) forn(pos, 2) forn(sg, 2)
    dp[i][pos][sg] = INF;
  dp[0][0][0] = dp[0][0][1] = -INF;
  
  forn(i, n - 1) forn(pos, 2) forn(sg, 2) if (dp[i][pos][sg] != INF) {
    forn(nsg, 2) {
      int x = sg ? -p[i] : p[i];
      int y = dp[i][pos][sg];
      if (pos) swap(x, y);
      int z = nsg ? -p[i + 1] : p[i + 1];
      if (z > x) {
        if (dp[i + 1][0][nsg] > y) {
          dp[i + 1][0][nsg] = y;
          pr[i + 1][0][nsg] = make_pair(pos, sg);
        }
      } else if (z > y)  {
        if (dp[i + 1][1][nsg] > x) {
          dp[i + 1][1][nsg] = x;
          pr[i + 1][1][nsg] = make_pair(pos, sg);
        }
      }
    }
  }
  
  int pos = -1, sg = -1;
  forn(j, 2) forn(k, 2) if (dp[n - 1][j][k] != INF) 
    pos = j, sg = k;
  if (pos == -1) {
    puts("NO");
    return;
  }
  for (int i = n - 1; i >= 0; i--) {
    a[i] = sg ? -p[i] : p[i];
    tie(pos, sg) = pr[i][pos][sg];
  }
  
  puts("YES");
  forn(i, n) printf("%d ", a[i]);
  puts("");
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) solve();
} 
```
 **Solution 2 (Neon)**
```cpp
#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); ++i)

const int INF = 1e9;
const int N = 1000 * 1000 + 13;

int n;
int p[N], a[N];
int dp[N][2], pr[N][2];

void solve() {
  scanf("%d", &n);
  forn(i, n) scanf("%d", &p[i]);
  forn(i, n) forn(j, 2) dp[i][j] = INF;
  dp[0][0] = dp[0][1] = -INF;
  forn(i, n - 1) forn(j, 2) if (dp[i][j] != INF) {
    int x = j ? -p[i] : p[i];
    int y = dp[i][j];
    if (x < y) swap(x, y);
    forn(nj, 2) {
      int z = nj ? -p[i + 1] : p[i + 1];
      if (z > x) {
        if (dp[i + 1][nj] > y) {
          dp[i + 1][nj] = y;
          pr[i + 1][nj] = j;
        }
      } else if (z > y)  {
        if (dp[i + 1][nj] > x) {
          dp[i + 1][nj] = x;
          pr[i + 1][nj] = j;
        }
      }
    }
  }
  int j = -1;
  forn(i, 2) if (dp[n - 1][i] != INF) j = i;
  if (j == -1) {
    puts("NO");
    return;
  }
  for (int i = n - 1; i >= 0; i--) {
    a[i] = j ? -p[i] : p[i];
    j = pr[i][j];
  }
  puts("YES");
  forn(i, n) printf("%d ", a[i]);
  puts("");
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) solve();
}
```
[1620G - Subsequences Galore](../problems/G._Subsequences_Galore.md "Educational Codeforces Round 119 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1620G - Subsequences Galore](../problems/G._Subsequences_Galore.md "Educational Codeforces Round 119 (Rated for Div. 2)")

For a string t, let's define its characteristic mask as the mask of n bits, where i-th bit is 1 if and only if t is a subsequence of si. Let's suppose we somehow calculate the number of strings for each characteristic mask, and we denote this as G(x) for a mask x. How can we use this information to find f([si1,si2,…,sik])? Suppose this set of strings is represented by a mask x, then the strings which are not included in f are the strings such that their characteristic mask has bitwise AND with x equal to 0, i. e. these characteristic masks are submasks of 2n−1⊕x. We can use SOS DP to calculate these sums of G(x) over submasks in O(2nn).

The only problem is how to calculate G(x) for every mask. Let's analyze when a string is a subsequence of a sorted string si. The subsequence should be sorted as well, and the number of occurrences of every character in a subsequence should not exceed the number of occurrences of that character in si. So, if there are c1 characters a in si, c2 characters b in si, and so on, then the number of its subsequences is 26∏j=1(1+cj).

What about subsequences of every string from a set? These conditions on the number of occurrences should apply to every string in the set, so, for each character, we can calculate the minimum number of occurrences of this character in each string of the set, add 1, and multiply these numbers to get the number of strings that are subsequences of each string in a set.

These values can be calculated in O(2n(n+A)) for all 2n subsequences of [s1,s2,…,sn] using recursive approach. Can these numbers be used as G(x)? Not so fast. Unfortunately, these values (let's call them H(x)) are the numbers of subsequences of the chosen sets of strings, but we have no information about the strings that are not included in the chosen set of strings. To handle it, we can use the following equation: H(x)=∑x⊆yG(y), where x⊆y means that x is a submask of y. To transform the values of H(x) into the values of G(x), we can flip all bits in the masks (so H(x) is the sum of G(y) over all submasks of x), apply inverse SOS DP (also known as Mobius transformation), and then flip all bits in the masks again. So, we found a way to calculate all values of G(x) in O(2n(n+A)), and we have already discussed what to do with them in the first paragraph of the editorial.

The overall complexity of the solution is O(2n(n+A)).

 **Solution (BledDest)**
```cpp
#include<bits/stdc++.h>

using namespace std;

const int N = 23;
const int A = 26;
const int S = 20043;
int n;
string inp[N];
char buf[S];
int cnt[N][A];
const int MOD = 998244353;

int add(int x, int y)
{
    x += y;
    while(x >= MOD) x -= MOD;
    while(x < 0) x += MOD;
    return x;
}

int sub(int x, int y)
{
    return add(x, -y);
}

int mul(int x, int y)
{
    return (x * 1ll * y) % MOD;
}

void flip_all(vector<int>& a)
{
    int msk = (1 << n) - 1;
    for(int i = 0; i < (1 << (n - 1)); i++)
        swap(a[i], a[i ^ msk]);
}

int val[S];
int* where[S];
int cur = 0;

void change(int& x, int y)
{
    where[cur] = &x;
    val[cur] = x;
    x = y;
    cur++;
}

void rollback()
{
    --cur;
    (*where[cur]) = val[cur];
}

void zeta_transform(vector<int>& a)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < (1 << n); j++)
            if((j & (1 << i)) == 0)
                a[j ^ (1 << i)] = add(a[j ^ (1 << i)], a[j]);
    }
}                     

void mobius_transform(vector<int>& a)
{
    for(int i = n - 1; i >= 0; i--)
    {
        for(int j = (1 << n) - 1; j >= 0; j--)
            if((j & (1 << i)) != 0)
                a[j] = sub(a[j], a[j ^ (1 << i)]);
    }
}

int cur_max[A];
vector<int> mask_cnt;

void rec(int depth, int mask)
{
    if(depth == n)
    {
        mask_cnt[mask] = 1;
        for(int i = 0; i < A; i++)
            mask_cnt[mask] = mul(mask_cnt[mask], cur_max[i] + 1);
    }
    else
    {
        int state = cur;
        for(int i = 0; i < A; i++)
            change(cur_max[i], min(cur_max[i], cnt[depth][i]));
        rec(depth + 1, mask + (1 << depth));
        while(state != cur) rollback();
        rec(depth + 1, mask);
    }   
}

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%s", buf);
        inp[i] = buf;
        for(auto x : inp[i])
            cnt[i][x - 'a']++;
    }

    for(int i = 0; i < A; i++)
        cur_max[i] = S;
    mask_cnt.resize(1 << n);
    rec(0, 0);
    flip_all(mask_cnt);
    mobius_transform(mask_cnt);
    flip_all(mask_cnt);
    int sum = 0;
    for(int i = 0; i < (1 << n); i++) sum = add(sum, mask_cnt[i]);
    zeta_transform(mask_cnt);
    vector<int> res(1 << n);
    for(int i = 0; i < (1 << n); i++)
        res[i] = sub(sum, mask_cnt[((1 << n) - 1) ^ i]);

    long long ans = 0;

    for(int i = 0; i < (1 << n); i++)
    {
        int c = 0, s = 0;
        for(int j = 0; j < n; j++)
        {
            if(i & (1 << j))
            {
                c++;
                s += j + 1;
            }   
        }
        ans ^= res[i] * 1ll * c * 1ll * s;
    }

    //for(int i = 0; i < (1 << n); i++) printf("%dn", res[i]);
    printf("%lldn", ans);
}
```
