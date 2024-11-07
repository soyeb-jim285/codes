# Tutorial

[1922A - Tricky Template](../problems/A._Tricky_Template.md "Educational Codeforces Round 161 (Rated for Div. 2)")

Idea: [Roms](https://codeforces.com/profile/Roms "Master Roms")

 **Tutorial**
### [1922A - Tricky Template](../problems/A._Tricky_Template.md "Educational Codeforces Round 161 (Rated for Div. 2)")

In order for a string not to match the pattern, there must be at least one position i from 1 to n where the condition doesn't hold. Let's iterate over this position and check if it is possible to pick a letter in the pattern such that ai and bi match, while ci doesn't match. If ai or bi equal ci, then it is definitely not possible. Since ci does not match, the equal letter also doesn't match. And if both are different from ci, then it is always possible to pick the uppercase letter ci to only prohibit it.

Great, now the string c definitely doesn't match the pattern. Now we should guarantee that the strings a and b match. Complete the template as follows: for all other positions, we will pick uppercase letters that differ from both ai and bi. Obviously, among 26 letters, there will always be such a letter.

Therefore, the solution is as follows: iterate over the positions and check that there is at least one where ai differs from ci and bi differs from ci. If there is, the answer is "YES". Otherwise, the answer is "NO".

Overall complexity: O(n) for each testcase.

 **Solution (awoo)**
```cpp
for _ in range(int(input())):
	n = int(input())
	a = input()
	b = input()
	c = input()
	print("YES" if any([a[i] != c[i] and b[i] != c[i] for i in range(n)]) else "NO")
```
[1922B - Forming Triangles](../problems/B._Forming_Triangles.md "Educational Codeforces Round 161 (Rated for Div. 2)")

Idea: [Roms](https://codeforces.com/profile/Roms "Master Roms")

 **Tutorial**
### [1922B - Forming Triangles](../problems/B._Forming_Triangles.md "Educational Codeforces Round 161 (Rated for Div. 2)")

At first, let's figure out which sticks can be used to make a triangle. Let's denote the length of the longest stick as 2s0, the shortest stick as 2s2 and the middle stick as 2s1 (in other words, s is an array of length 3, consisting of three sticks for a triangle, sorted in non-ascending order). Important fact: s0==s1. It's true because if s0>s1, then 2s0≥2s1+2s2 and the triangle is degenerate. At the same time, the value of the s2 can be any integer from 0 to s0.

So all we have to do is calculate the number of triples of sticks such that there are two or three maximums in the triple. Let's create an array cnt, where cnti is the number of sticks of length 2i, and the array sumCnt, where sumCnti is the number of sticks no longer than 2i. Now let's iterate over the length of the longest stick in the triangle (denote it as m). Then there are two cases: 

* All three sticks in a triangle are equal. Then the number of such triangles can be computed with a binomial coefficient: cntm∗(cntm−1)∗(cntm−2)6;
* Only two sticks are equal (and have the same length). Then the number of such triangles is cntm∗(cntm−1)2⋅sumCntm−1.
 **Solution (Roms)**
```cpp
#include <bits/stdc++.h>
 
using namespace std;
 
int t;
 
int main() {
    cin >> t;
    for (int tc = 0; tc < t; ++tc) {
        int n;
        cin >> n;
        map<int, int> numOfLens;
        for (int i = 0; i < n; ++i){
            int x;
            cin >> x;
            ++numOfLens[x];
        }
        
        long long res = 0;
        int sum = 0;
        for (auto it : numOfLens) {
            long long cnt = it.second;
            if(cnt >= 3)
                res += cnt * (cnt - 1) * (cnt - 2) / 6;
            if(cnt >= 2)
                res += cnt * (cnt - 1) / 2 * sum;
            sum += cnt;
        }
        
        cout << res << endl;
    }
    return 0;
}
```
[1922C - Closest Cities](../problems/C._Closest_Cities.md "Educational Codeforces Round 161 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1922C - Closest Cities](../problems/C._Closest_Cities.md "Educational Codeforces Round 161 (Rated for Div. 2)")

Important observation: the answer will not change if you are allowed to move only to adjacent cities. It is true because if you move to a non-adjacent city, you can split the path to that city into parts without increasing its cost. So, the shortest way from x to y (consider the case x<y) is to move from city x to city x+1 for 1 coin if it's possible or for ax+1−ax if it's not. Then move from city x+1 to city x+2 for 1 coin if it's possible, or for ax+2−ax+1 coins if it's not. And so on, until we reach the city y.

Now let's calculate two arrays: l and r. ri is equal to the minimum amount of coins to reach the city i from city 1 (from left to right), li is equal to the minimum amount of coins to reach the city i from city n (from right to left). Both of these arrays can be precalculated just like the arrays of prefix sums are calculated. For example, r1=0, r2=dist(1,2), r3=r2+dist(2,3), r4=r3+dist(3,4) and so on. Here, dist(s,t) denotes the cheapest way to travel between two adjacent cities s and t.

Then, the cheapest way between two cities x and y can be calculated in the same way as the sum on subarray is calculated for the prefix sum array. There are two cases: 

* If x<y then the answer is ry−rx;
* If x>y then the answer is ly−lx;
 **Solution (Roms)**
```cpp
#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 200'000;
const int INF = 1'000'000'009;
int t;
 
char type(const vector <int>& a, int id) {
    int distL = (id == 0? INF : a[id] - a[id - 1]);
    int distR = (id + 1 == a.size()? INF : a[id + 1] - a[id]);
    if(distL < distR) return 'L';
    if(distL > distR) return 'R';
    assert(false);
}
 
int main() {
    ios::sync_with_stdio(false);
    cin >> t;
    for (int tc = 0; tc < t; ++tc) {
        int n;
        cin >> n;
        vector <int> a(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i];
            
        vector <int> l(n), r(n);
        for (int i = 1; i < n; ++i)
            r[i] = r[i - 1] + (type(a, i - 1) == 'R'? 1 : a[i] - a[i - 1]);
        for (int i = n - 2; i >= 0; --i)
            l[i] = l[i + 1] + (type(a, i + 1) == 'L'? 1 : a[i + 1] - a[i]);
        
        int m;
        cin >> m;
        for (int i = 0; i < m; ++i) {
            int x, y;
            cin >> x >> y;
            --x, --y;
            if (x < y) 
                cout << r[y] - r[x] << endl;
            else
                cout << l[y] - l[x] << endl;
        }
    }
    return 0;
}
```
[1922D - Berserk Monsters](../problems/D._Berserk_Monsters.md "Educational Codeforces Round 161 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1922D - Berserk Monsters](../problems/D._Berserk_Monsters.md "Educational Codeforces Round 161 (Rated for Div. 2)")

It is important to note that if during the j-th round the i-th monster did not die and none of its alive neighbors died, then there is no point in checking this monster in the (j+1)-th round. Therefore, we can solve the problem as follows: let's maintain a list of candidates (those who can die) for the current round; if the monster dies in the current round, then add its neighbors to the list of candidates for the next round.

Since killing a monster adds no more than 2 candidates, the total size of the candidate lists for all rounds does not exceed 3n (since the size of the list for the first round is equal to n plus no more than 2 for each killed monster). Therefore, we can simply iterate through these lists to check if the monster will be killed.

The only problem left is finding the alive neighbors of the monster (to check whether he is killed or not during the round). This can be done by creating an ordered set with the indices of the monsters. set allows us to remove the killed ones and find neighboring monsters in O(logn).

Thus, the solution works in O(nlogn).

 **Solution (Neon)**
```cpp
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n + 2), d(n + 2, INT_MAX);
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) cin >> d[i];
    set<int> lft, cur;
    for (int i = 0; i < n + 2; ++i) {
      lft.insert(i);
      cur.insert(i);
    }
    for (int z = 0; z < n; ++z) {
      set<int> del, ncur;
      for (int i : cur) {
        auto it = lft.find(i);
        if (it == lft.end()) continue;
        int prv = *prev(it);
        int nxt = *next(it);
        if (a[prv] + a[nxt] > d[i]) {
          del.insert(i);
          ncur.insert(prv);
          ncur.insert(nxt);
        }
      }
      cout << del.size() << ' ';
      for (auto it : del) lft.erase(it);
      cur = ncur;
    }
    cout << 'n';
  }
}
```
[1922E - Increasing Subsequences](../problems/E._Increasing_Subsequences.md "Educational Codeforces Round 161 (Rated for Div. 2)")

Idea: [Roms](https://codeforces.com/profile/Roms "Master Roms")

 **Tutorial**
### [1922E - Increasing Subsequences](../problems/E._Increasing_Subsequences.md "Educational Codeforces Round 161 (Rated for Div. 2)")

Let's consider one of the solutions for constructing the required array.

Let array a have x increasing subsequences. If we add a new minimum to the end of the array, the number of increasing subsequences in the new array equals x+1 (since the new element does not form increasing subsequences with other elements, only subsequences consisting of this element will be added). If we add a new maximum to the end of the array, the number of increasing subsequences in the new array equals 2x (since the new element forms increasing subsequences with any other elements).

Using the above facts, let's define a recursive function f(x), which returns an array with exactly x increasing subsequences. For an odd value of x, f(x)=f(x−1)+min (here + denotes adding an element to the end of the array); for an even value of x, f(x)=f(x2)+max. Now we need to estimate the number of elements in the array obtained by this algorithm. Note that there cannot be two consecutive operations of the first type (x→x−1), so every two operations, the value of x decreases by at least two times. Thus, the size of the array satisfies the limit of 200.

 **Solution (Neon)**
```cpp
#include <bits/stdc++.h>
 
using namespace std;
 
vector<int> f(long long x) {
  vector<int> res;
  if (x == 2) {
  	res.push_back(0);
  } else if (x & 1) {
    res = f(x - 1);
    res.push_back(*min_element(res.begin(), res.end()) - 1);
  } else {
    res = f(x / 2);
    res.push_back(*max_element(res.begin(), res.end()) + 1);
  }
  return res;
}
 
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long x;
    cin >> x;
    auto ans = f(x);
    cout << ans.size() << 'n';
    for (int i : ans) cout << i << ' ';
    cout << 'n';
  }
}
```
[1922F - Replace on Segment](../problems/F._Replace_on_Segment.md "Educational Codeforces Round 161 (Rated for Div. 2)")

Idea: [Roms](https://codeforces.com/profile/Roms "Master Roms")

 **Tutorial**
### [1922F - Replace on Segment](../problems/F._Replace_on_Segment.md "Educational Codeforces Round 161 (Rated for Div. 2)")

First of all, we claim the following: if you apply an operation on a segment, you may treat the resulting segment as one element (i. e. we can "merge" the elements affected by an operation into one). This is quite intuitive, but the formal proof is kinda long, so if you're not interested in it, feel free to skip the next paragraphs written in italic.

Formal proof: suppose we merged several adjacent equal elements into one. Let's show that it doesn't change the answer for the array. Let the array before merging a segment of adjacent equal elements be a, and the array after merging be a′. We will show that f(a)=f(a′), where f(x) is the minimum number of operations to solve the problem on the array x.

* f(a)≥f(a′): suppose we built a sequence of operations that turns all elements of a equal. Consider the segment of adjacent equal elements we merged to get a′. Let's discard all elements of that segment, except for the first one, from all operations in the sequence, and remove all operations which now affect zero elements. We will get a valid sequence of operations that turns all elements of a′ equal. So, any valid sequence of operations for a can be transformed into a valid sequence of operations for a′ (with possibly discarding some operations), and that's why f(a)≥f(a′);
* f(a)≤f(a′): suppose we built a sequence of operations that turns all elements of a′ equal. It can be transformed into a valid sequence of operations for a′, if we "expand" the element we got from merging the segment in all operations. So, f(a)≤f(a′);
* since f(a)≥f(a′) and f(a)≤f(a′), then f(a)=f(a′).

This means that after you've done an operation on a segment, the next operations will either affect that whole segment, or not affect any element from the segment at all.

This allows us to use the following dynamic programming idea: let dp[l][r][k] be the minimum number of operations required to turn all elements on the segment [l,r] into k. If we want to transform all elements into k, then there are two options:

* either the last operation will turn the whole segment into k, so we need to calculate the number of operations required to get rid of all elements equal to k from the segment;
* or the segment [l,r] can be split into several segments which we will turn into k separately.

The second option can be modeled quite easily: we iterate on the splitting point between two parts i, and update dp[l][r][k] with dp[l][i][k]+dp[i+1][r][k]. However, the first option is a bit more complicated.

Let's introduce a second dynamic programming to our solution: let dp2[l][r][k] be the minimum number of operations to remove all occurrences of k from the segment [l,r]. Then, the first option for computing dp[l][r][k] can be implemented by simply updating dp[l][r][k] with dp2[l][r][k]+1.

Now, let's show how to calculate dp2[l][r][k]. It's quite similar to the first dynamic programming:

* either the last operation on the segment will turn the whole segment into some other element m, so we can iterate on it and update dp2[l][r][k] with dp[l][r][m];
* or the segment [l,r] can be split into two parts, and we will get rid of elements equal to k from these parts separately (so we update dp2[l][r][k] with dp2[l][i][k]+dp2[i+1][r][k]).

Okay, it looks like we got a solution working in O(n4). There's just one problem, though. There are cyclic dependencies in our dynamic programming:

* dp[l][r][k] depends on dp2[l][r][k];
* dp2[l][r][k] depends on dp[l][r][m], where m≠k;
* dp[l][r][m] depends on dp2[l][r][m];
* dp2[l][r][m] depends on dp[l][r][k].

We have to either somehow deal with them, or get rid of them. The model solution eliminates these cyclic dependencies as follows: when we need to calculate dp[l][r][k], let's discard all elements equal to k from the ends of the segment (i. e. move l to l′ and r to r′, where l′ and r′ are the first and last occurrences of elements not equal to k). Similarly, when we need to calculate dp2[l][r][k], let's discard all elements not equal to k from the ends of the segment. It's quite easy to show that these operations won't make the answer worse (if you remove an element from an array, the minimum number of operations to "fix" the array doesn't increase). It's also not that hard to show that this method gets rid of all cyclic dependencies: if we consider the cyclic dependency we described earlier, we can see that the element al will be discarded from the segment either when computing dp[l][r][k] (if al=k) or when computing dp2[l][r][k] (if al≠k).

That way, we get a dynamic programming solution working in O(n4).

 **Solution (Neon)**
```cpp
#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 111;
 
int n, k;
int a[N];
int nxtx[N][N], prvx[N][N];
int nxtnx[N][N], prvnx[N][N];
int dp1[N][N][N], dp2[N][N][N];
 
int calc2(int, int, int);
 
int calc1(int l, int r, int x) {
  l = nxtnx[l][x], r = prvnx[r][x];
  if (l > r) return 0;
  if (dp1[l][r][x] != -1) return dp1[l][r][x];
  dp1[l][r][x] = calc2(l, r, x) + 1;
  for (int i = l; i < r; ++i) dp1[l][r][x] = min(dp1[l][r][x], calc1(l, i, x) + calc1(i + 1, r, x));
  return dp1[l][r][x];
}
 
int calc2(int l, int r, int x) {
  l = nxtx[l][x], r = prvx[r][x];
  if (l > r) return 0;
  if (dp2[l][r][x] != -1) return dp2[l][r][x];
  dp2[l][r][x] = n;
  for (int i = l; i < r; ++i) dp2[l][r][x] = min(dp2[l][r][x], calc2(l, i, x) + calc2(i + 1, r, x));
  for (int y = 0; y < k; ++y) if (x != y) dp2[l][r][x] = min(dp2[l][r][x], calc1(l, r, y)); 
  return dp2[l][r][x];
}
 
void solve() {
  cin >> n >> k;
  for (int i = 0; i < n; ++i) cin >> a[i], --a[i];
  for (int x = 0; x < k; ++x) prvx[0][x] = prvnx[0][x] = -1;
  for (int i = 0; i < n; ++i) {
    prvx[i][a[i]] = i;
    for (int x = 0; x < k; ++x) prvx[i + 1][x] = prvx[i][x];
    for (int x = 0; x < k; ++x) if (x != a[i]) prvnx[i][x] = i;
    for (int x = 0; x < k; ++x) prvnx[i + 1][x] = prvnx[i][x];
  }
  for (int x = 0; x < k; ++x) nxtx[n][x] = nxtnx[n][x] = n;
  for (int i = n - 1; i >= 0; --i) {
    for (int x = 0; x < k; ++x) nxtx[i][x] = nxtx[i + 1][x];
    nxtx[i][a[i]] = i;
    for (int x = 0; x < k; ++x) nxtnx[i][x] = nxtnx[i + 1][x];
    for (int x = 0; x < k; ++x) if (x != a[i]) nxtnx[i][x] = i;
  }
  memset(dp1, -1, sizeof(dp1));
  memset(dp2, -1, sizeof(dp2));
  int ans = n;
  for (int x = 0; x < k; ++x) ans = min(ans, calc1(0, n - 1, x));
  cout << ans << 'n';
}
 
int main() {
  int t;
  cin >> t;
  while (t--) solve();
}
```
