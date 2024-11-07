# Tutorial

All problems were invented [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov") and developed by me [Supermagzzz](https://codeforces.com/profile/Supermagzzz "Master Supermagzzz") and [Stepavly](https://codeforces.com/profile/Stepavly "Master Stepavly").

[1472A - Cards for Friends](../problems/A._Cards_for_Friends.md "Codeforces Round 693 (Div. 3)")

 **Editorial**
### [1472A - Cards for Friends](../problems/A._Cards_for_Friends.md "Codeforces Round 693 (Div. 3)")

If we cut the sheet in width, we will reduce its width by half, without changing the height. Therefore, the width and height dimensions do not affect each other in any way.

Let's calculate the maximum number of sheets that we can get by cutting. Let's say that initially this number is 11. Let's cut the sheet in width. Then the sheets number will become 22, but they will be the same. If we can cut the sheet again, it is more profitable to cut all the sheets we have, because this way we will get more new sheets and their size will still be the same.

So we can maintain the current number of identical sheets and as long as either the width or height is divided by 22, divide it, and multiply the number of sheets by two.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int w, h, n;
  cin >> w >> h >> n;
  int res = 1;
  while (w % 2 == 0) {
    w /= 2;
    res *= 2;
  }
  while (h % 2 == 0) {
    h /= 2;
    res *= 2;
  }
  cout << (res >= n ? "YESn" : "NOn");
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
```
[1472B - Fair Division](../problems/B._Fair_Division.md "Codeforces Round 693 (Div. 3)")

 **Editorial**
### [1472B - Fair Division](../problems/B._Fair_Division.md "Codeforces Round 693 (Div. 3)")

If the sum of all the weights is not divisible by two, then it is impossible to divide the candies between two people. If the sum is divisible, then let's count the number of candies with a weight of 11 and 22. Now, if we can find a way to collect half the sum with some candies, then these candies can be given to Alice, and all the rest can be given to Bob.

Simple solution — let's iterate through how many candies of weight 22 we will give to Alice, then the remaining weight should be filled by candies of weight 11. If there are enough of them, then we have found a way of division.

In fact, if the sum is even and there are at least two candies with weight 11 (there can't be one candy), then the answer is always "YES" (we can collect the weight as close to half as possible with weight 22 and then add weight 11). If there are no candies with weight 11, then you need to check whether nn is even (since all the candies have the same weight, you just need to divide them in half).

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  int cnt1 = 0, cnt2 = 0;
  for (int i = 0; i < n; i++) {
    int c;
    cin >> c;
    if (c == 1) {
      cnt1++;
    } else {
      cnt2++;
    }
  }
  if ((cnt1 + 2 * cnt2) % 2 != 0) {
    cout << "NOn";
  } else {
    int sum = (cnt1 + 2 * cnt2) / 2;
    if (sum % 2 == 0 || (sum % 2 == 1 && cnt1 != 0)) {
      cout << "YESn";
    } else {
      cout << "NOn";
    }
  }
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
```
[1472C - Long Jumps](../problems/C._Long_Jumps.md "Codeforces Round 693 (Div. 3)")

 **Editorial**
### [1472C - Long Jumps](../problems/C._Long_Jumps.md "Codeforces Round 693 (Div. 3)")

Let score(i)score(i) be the result of the game if we chose ii as the starting position.

Let's look at some starting position jj. After making a move from it, we will get a[j]a[j] points and move to the position j+a[j]j+a[j], continuing the same game. This means that by choosing the position jj, we can assume that we will get a result a[j]a[j] more than if we chose the position j+a[j]j+a[j]. Formally, score(j)=score(j+a[j])+a[j]score(j)=score(j+a[j])+a[j].

Let's calculate all the results of scorescore and store them in an array. Let's start iterating through the positions from the end, then being in the position ii we will know score(j)score(j) for all j>ij>i. Using the formula above, we can calculate score(i)score(i) in one operation. It remains only to choose the maximum of all such values.

 **Solution**
```cpp
#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int &x : a) {
    cin >> x;
  }

  vector<int> dp(n);
  for (int i = n - 1; i >= 0; i--) {
    dp[i] = a[i];
    int j = i + a[i];
    if (j < n) {
      dp[i] += dp[j];
    }
  }
  cout << *max_element(dp.begin(), dp.end()) << endl;
}

int main() {
  int tests;
  cin >> tests;
  while (tests-- > 0) {
    solve();
  }
  return 0;
}
```
[1472D - Even-Odd Game](../problems/D._Even-Odd_Game.md "Codeforces Round 693 (Div. 3)")

 **Editorial**
### [1472D - Even-Odd Game](../problems/D._Even-Odd_Game.md "Codeforces Round 693 (Div. 3)")

Let's look at an analogy for this game. 

* If Alice takes an even number xx, she adds xx points to the global result, otherwise 00;
* If Bob takes an odd number xx, he adds −x−x points to the global result, otherwise 00;
* Alice wants to maximize the global result and Bob wants to minimize it.

Obviously, this game is completely equivalent to the conditional game.

Suppose now it's Alice's move. Let's look at some number xx in the array. 

* If this number is even, then taking it will add xx points, and giving it to Bob will add 00 points.
* If this number is odd, then taking it will add 00 points, and giving it to Bob will add −x−x points.

So taking the number xx by xx points is more profitable than not taking it (regardless of the parity). To maximize the result, Alice should always take the maximum number in the array.

Similar reasoning can be done for Bob. In the task, it was necessary to sort the array and simulate the game.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (int &e : v) {
    cin >> e;
  }
  sort(v.rbegin(), v.rend());
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    if (i % 2 == 0) {
      if (v[i] % 2 == 0) {
        ans += v[i];
      }
    } else {
      if (v[i] % 2 == 1) {
        ans -= v[i];
      }
    }
  }
  if (ans == 0) {
    cout << "Tien";
  } else if (ans > 0) {
    cout << "Alicen";
  } else {
    cout << "Bobn";
  }
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
```
[1472E - Correct Placement](../problems/E._Correct_Placement.md "Codeforces Round 693 (Div. 3)")

 **Editorial**
### [1472E - Correct Placement](../problems/E._Correct_Placement.md "Codeforces Round 693 (Div. 3)")

Let's sort all people by their height in descending order.

Now let's go through all the people and look for the position of the person in the sorted array, the height of which is strictly less than ours (for example, by binary search). Obviously, only those people who are in the sorted array later than the found person can stand in front of us (all of them have a height strictly less than ours).

Among all these people, it is more profitable for us to take a person with minimum width. In order to find such a person quickly, we can find a person with the minimum width for each suffix of the sorted array.

To handle a situation where a person is lying down, we need to swap the width and height and repeat the algorithm above.

 **Solution**
```cpp
#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;

struct man {
  int h, w, id;
};

bool operator<(const man &a, const man &b) {
  return tie(a.h, a.w, a.id) < tie(b.h, b.w, b.id);
}

struct my_min {
  pii mn1, mn2;
};

vector<pair<int, my_min>> createPrefMins(const vector<man>& a) {
  vector<pair<int, my_min>> prefMin;
  my_min curMin{pii(INT_MAX, -1), pii(INT_MAX, -1)};
  for (auto x : a) {
    if (x.w < curMin.mn1.first) {
      curMin.mn2 = curMin.mn1;
      curMin.mn1 = pii(x.w, x.id);
    } else {
      curMin.mn2 = min(curMin.mn2, pii(x.w, x.id));
    }
    prefMin.emplace_back(x.h, curMin);
  }
  return prefMin;
}

int findAny(const vector<pair<int, my_min>> &mins, int h, int w, int id) {
  int l = -1, r = (int) mins.size();
  while (r - l > 1) {
    int m = (l + r) / 2;
    if (mins[m].first < h) {
      l = m;
    } else {
      r = m;
    }
  }
  if (l == -1) {
    return -1;
  }

  auto mn1 = mins[l].second.mn1;
  auto mn2 = mins[l].second.mn2;
  if (mn1.second != id) {
    return mn1.first < w ? mn1.second + 1 : -1;
  }
  return mn2.first < w ? mn2.second + 1 : -1;
}

void solve() {
  int n;
  cin >> n;
  vector<man> hor, ver;
  vector<pii> a;
  for (int i = 0; i < n; i++) {
    int h, w;
    cin >> h >> w;
    hor.push_back({h, w, i});
    ver.push_back({w, h, i});
    a.emplace_back(h, w);
  }

  sort(hor.begin(), hor.end());
  sort(ver.begin(), ver.end());

  auto horMins = createPrefMins(hor);
  auto verMins = createPrefMins(ver);

  for (int i = 0; i < n; i++) {
    auto[h, w] = a[i];
    int id = findAny(horMins, h, w, i);
    if (id == -1) {
      id = findAny(verMins, h, w, i);
    }
    cout << id << " ";
  }
  cout << endl;
}

int main() {
  int tests;
  cin >> tests;
  while (tests-- > 0) {
    solve();
  }
  return 0;
}
```
[1472F - New Year's Puzzle](../problems/F._New_Year's_Puzzle.md "Codeforces Round 693 (Div. 3)")

 **Editorial**
### [1472F - New Year's Puzzle](../problems/F._New_Year's_Puzzle.md "Codeforces Round 693 (Div. 3)")

If the first column is empty, we can always cover it with a vertical tile: 

* if the next column is also empty, then we will have to put either two vertical or two horizontal tiles, but they are obtained from each other by rotating;
* if the next column contains at least one blocked cell, then we have no other options but to cover the column with a vertical board.

If the first column is fully blocked, then we can just skip it.

Remove such columns from the beginning, reducing the problem. Now the first column contains one empty and one blocked cell. Obviously, in place of an empty cell, we will have to place a horizontal tile. If this did not work, then the tiling does not exist. Otherwise there are two cases: 

* if the next column is empty, it will turn into a column with one occupied cell. Then we continue to put horizontal tiles;
* if the next column contains one blocked cell, then it becomes fully blocked and we return to the first step.

It turns out the following greedy algorithm, we sort all columns with at least one cell blocked (there are no more than mm such columns) by number. Now, if we see a column with one occupied cell, then the next one must also be with one occupied cell (we skipped the empty columns), but this cell must have a different color in the chess coloring (so that we can tile the space between them with horizontal boards. This check is easy to do after sorting the columns.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n, m;
  cin >> n >> m;
  map<int, int> v;
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    v[y] |= (1 << (x - 1));
  }
  const int FULL = 3;
  v[2e9] = FULL;
  int hasLast = 0, lastColor = 0;
  for (auto[x, mask] : v) {
    if (mask != FULL && hasLast) {
      int color = (x + mask) % 2;
      if (lastColor == color) {
        cout << "NOn";
        return;
      } else {
        hasLast = false;
      }
    } else if (mask == FULL && hasLast) {
        cout << "NOn";
        return;
    } else if (mask != FULL) {
      lastColor = (x + mask) % 2;
      hasLast = true;
    }
  }
  cout << "YESn";
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
```
[1472G - Moving to the Capital](../problems/G._Moving_to_the_Capital.md "Codeforces Round 693 (Div. 3)")

 **Editorial**
### [1472G - Moving to the Capital](../problems/G._Moving_to_the_Capital.md "Codeforces Round 693 (Div. 3)")

Find the distances to all vertices and construct a new graph that has only edges that goes from a vertex with a smaller distance to a vertex with a larger distance. Such a graph cannot contain cycles.

Next, you need to run a dynamic programming similar to finding bridges in an undirected graph. First, we write the minimum distance from each vertex to the capital using no more than one edge. This distance is either equal to the distance from the capital to the vertex itself, or the distance to the vertex connected to us by one of the remote edges. We can't go through more than one remote edge.

The real answer for a vertex vv is the minimum of such values in all vertices reachable from vv in the new graph. Since the new graph is acyclic, we can calculate the answer using dynamic programming and a depth-first search started from the capital.

 **Solution**
```cpp
#include <bits/stdc++.h>
using namespace std;

vector<int> calcDist(vector<vector<int>> const &g) {
  vector<int> dist(g.size(), -1);
  dist[1] = 0;
  queue<int> pq;
  pq.push(1);
  while (!pq.empty()) {
    int u = pq.front();
    pq.pop();
    for (int v : g[u]) {
      if (dist[v] == -1) {
        dist[v] = dist[u] + 1;
        pq.push(v);
      }
    }
  }

  return dist;
}

void dfs(int u, vector<vector<int>> const &g, vector<int> const &dist, vector<int> &dp, vector<bool> &used) {
  used[u] = true;
  dp[u] = dist[u];
  for (int v : g[u]) {
    if (!used[v] && dist[u] < dist[v]) {
      dfs(v, g, dist, dp, used);
    }

    if (dist[u] < dist[v]) {
      dp[u] = min(dp[u], dp[v]);
    } else {
      dp[u] = min(dp[u], dist[v]);
    }
  }
}

void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n + 1);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
  }

  vector<int> dist = calcDist(g);
  vector<int> dp(n + 1);
  vector<bool> used(n + 1);
  dfs(1, g, dist, dp, used);
  for (int i = 1; i <= n; i++) {
    cout << dp[i] << " ";
  }
  cout << endl;
}

int main() {
  int tests;
  cin >> tests;
  while (tests-- > 0) {
    solve();
  }
  return 0;
}
```
