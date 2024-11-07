# Tutorial_(en)

Thanks [bmerry](https://codeforces.com/profile/bmerry "Legendary Grandmaster bmerry") for posting his solutions, we gently took some of them as a base for editorial.

 
### [1028A - Find Square](../problems/A._Find_Square.md "AIM Tech Round 5 (rated, Div. 1 + Div. 2)")

There are lots of possible solutions. For example, run through rows from the top until you find one with at least one 'B'. Do the same for the bottom. Average of the two row numbers is the number of the middle row. Now find the first and last 'B' in that row, their average value is the number of the middle column.

Alternative approach is to print $\dfrac{\sum\limits_{i=1}^{cnt}x_i}{cnt}, \dfrac{\sum\limits_{i=1}^{cnt}y_i}{cnt}$, where $cnt$ is the number of black points and $\{(x_i, y_i)\}_{i=1}^{cnt}$ is a list of black points.

Problem author: [VadymKa](https://codeforces.com/profile/VadymKa "Expert VadymKa")

Problem developers: [riadwaw](https://codeforces.com/profile/riadwaw "Grandmaster riadwaw"), [malcolm](https://codeforces.com/profile/malcolm "Master malcolm")

 **Code**
```cpp
static class SquareInside {
        final int inf = (int) 1e9;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.readInt(), m = in.readInt();
            char[][] s = new char[n][];
            for (int i = 0; i < n; i++) {
                s[i] = in.readWord().toCharArray();
            }
            int minX = inf, maxX = -inf, minY = inf, maxY = -inf;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (s[i][j] == 'B') {
                        minX = Math.min(minX, i);
                        minY = Math.min(minY, j);
                        maxX = Math.max(maxX, i);
                        maxY = Math.max(maxY, j);
                    }
                }
            }
            out.print((minX + maxX) / 2 + 1);
            out.print(' ');
            out.println((minY + maxY) / 2 + 1);
        }

    }
```
 
### [1028B - Unnatural Conditions](../problems/B._Unnatural_Conditions.md "AIM Tech Round 5 (rated, Div. 1 + Div. 2)")

First note, that if some output is correct for test with $n = 1129$ and $m = 1$, then it's correct for any valid test. After noticing this, we don't need to read input and output one answer for any test. One of many possible answers is

$a = 99..9900..001$ (200 nines, 199 zeroes, 1 one) 

$b = 99..99$ (200 nines) 

$a + b = 10^{400}$

$s(a) = 1801, s(b) = 1800, s(a+b) = 1$

Problem author: [VadymKa](https://codeforces.com/profile/VadymKa "Expert VadymKa")

Problem developers: [riadwaw](https://codeforces.com/profile/riadwaw "Grandmaster riadwaw"), [malcolm](https://codeforces.com/profile/malcolm "Master malcolm"), [Kostroma](https://codeforces.com/profile/Kostroma "Legendary Grandmaster Kostroma"), [Errichto](https://codeforces.com/profile/Errichto "International Grandmaster Errichto")

 **Code**
```cpp
  int len = 400;
  cout << string(len, '5') << "n";
  cout << (string(len - 1, '4') + '5') << "n";
```
 
### [1028C - Rectangles](../problems/C._Rectangles.md "AIM Tech Round 5 (rated, Div. 1 + Div. 2)")

Note that intersection of any number of rectangles is a rectangle too (possibly, empty).

Calculate $pref(i)$ — intersection of rectangles with numbers $1, 2, \ldots, i$, and $suf(i)$ — intersection of rectangles with numbers $i, i + 1, \ldots, n$. If $i$ is the index of the rectangle not included in the answer, then intersection of $pref(i-1)$ and $suf(i+1)$ must be non-empty. So, for some $i$ this condition is held, and we can print any integer point inside this rectangle.

Problem author: [malcolm](https://codeforces.com/profile/malcolm "Master malcolm")

Problem developers: [yarrr](https://codeforces.com/profile/yarrr "Candidate Master yarrr"), [Edvard](https://codeforces.com/profile/Edvard "Candidate Master Edvard"), [malcolm](https://codeforces.com/profile/malcolm "Master malcolm"), [Errichto](https://codeforces.com/profile/Errichto "International Grandmaster Errichto")

 **Code**
```cpp
static class Rectangle {
        public Point topLeft, bottomRight;

        public Rectangle(Point topLeft, Point bottomRight) {
            this.topLeft = topLeft;
            this.bottomRight = bottomRight;
        }

        public Rectangle intersect(Rectangle other) {
            if (other == null) {
                return null;
            }
            int x0 = Math.max(topLeft.x, other.topLeft.x);
            int y0 = Math.max(topLeft.y, other.topLeft.y);
            int x1 = Math.min(bottomRight.x, other.bottomRight.x);
            int y1 = Math.min(bottomRight.y, other.bottomRight.y);
            if (x0 > x1 || y0 > y1) {
                return null;
            }
            return new Rectangle(new Point(x0, y0), new Point(x1, y1));
        }
    }

    private void solve() throws IOException {
        int rectanglesCount = nextInt();
        Rectangle[] rectangles = new Rectangle[rectanglesCount];
        for (int i = 0; i < rectanglesCount; i++) {
            Point topLeft = new Point(nextInt(), nextInt());
            Point bottomRight = new Point(nextInt(), nextInt());
            rectangles[i] = new Rectangle(topLeft, bottomRight);
        }
        Rectangle[] prefixIntersection = new Rectangle[rectanglesCount + 1];
        Rectangle[] suffixIntersection = new Rectangle[rectanglesCount + 1];
        prefixIntersection[0] = suffixIntersection[0] = new Rectangle(
            new Point(Integer.MIN_VALUE, Integer.MIN_VALUE),
            new Point(Integer.MAX_VALUE, Integer.MAX_VALUE)
        );
        for (int i = 1; i <= rectanglesCount; i++) {
            prefixIntersection[i] = rectangles[i - 1].intersect(prefixIntersection[i - 1]);
            suffixIntersection[i] = rectangles[rectanglesCount - i].intersect(suffixIntersection[i - 1]);
        }

        for (int i = 0; i <= rectanglesCount; i++) {
            if (prefixIntersection[i] != null) {
                Rectangle intersection = prefixIntersection[i].intersect(suffixIntersection[rectanglesCount - i - 1]);
                if (intersection != null) {
                    out.println(intersection.topLeft);
                    return;
                }
            }
        }
        throw new AssertionError();
    }
```
**Bonus:** Solve the problem, if you need to find intersection of some *n* - *k* of *n* rectangles, if *k* ≤ 10. Without data structures.

 
### [1028D - Order book](../problems/D._Order_book.md "AIM Tech Round 5 (rated, Div. 1 + Div. 2)")

Keep track of a lower bound for the best sell $s_{best}$ and an upper bound for the best buy $b_{best}$ in the order book. If we have ACCEPT $p$ with $p > s_{best}$ or $p < b_{best}$, it's a contradiction and the answer does not exist. If either $b_{best} = p$ or $s_{best} = p$, then the answer stay the same, and if $b_{best} < p < s_{best}$, the answer is multiplied by $2$, because the removed order could've had any direction. After an ACCEPT $p$, the price of the order above it is the new $s_{best}$ and the price of the order below it is the new $b_{best}$. If in the end there are $m$ orders with undetermined direction, the answer is multiplied by $m+1$. To maintain sets of orders with determined direction (i.e. with prices $p \le b_{best}$ or $p \ge s_{best}$) one can use std::set or std::priority_queue in C++ or TreeSet or PriorityQueue in Java.

Problem author: [Errichto](https://codeforces.com/profile/Errichto "International Grandmaster Errichto")

Problem developers: [zemen](https://codeforces.com/profile/zemen "International Grandmaster zemen"), [Errichto](https://codeforces.com/profile/Errichto "International Grandmaster Errichto"), [Kostroma](https://codeforces.com/profile/Kostroma "Legendary Grandmaster Kostroma"), [riadwaw](https://codeforces.com/profile/riadwaw "Grandmaster riadwaw")

 **Code**
```cpp
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;

signed main() {
#ifdef LOCAL
  assert(freopen("test.in", "r", stdin));
#endif
  int n;
  cin >> n;
  map<int, int> a{{INT_MIN, 1}, {INT_MAX, 0}};
  set<int*> non0{&a.begin()->second};
  for (int i = 0; i < n; ++i) {
    string t;
    int x;
    cin >> t >> x;
    if (t == "ADD") {
      auto it = a.lower_bound(x);
      assert(it != a.begin());
      --it;
      int ways = it->second;
      auto m = a.emplace(x, ways).first;
      non0.insert(&m->second);
    } else {
      auto m = a.find(x);
      assert(m != a.end() && m != a.begin());
      auto it = prev(m);
      auto& w = it->second;
      w = (w + m->second) % mod;
      non0.insert(&it->second);
      non0.erase(&m->second);
      a.erase(m);
      for (auto it2 = non0.begin(); it2 != non0.end(); ) {
        if (*it2 == &it->second) {
          ++it2;
        } else {
          *(*it2) = 0;
          it2 = non0.erase(it2);
        }
      }
    }
  }
  int res = 0;
  for (auto p : a) {
    res = (res + p.second) % mod;
  }
  cout << res << 'n';
}
```
 
### [1028E - Restore Array](../problems/E._Restore_Array.md "AIM Tech Round 5 (rated, Div. 1 + Div. 2)")

Let's consider a special case at first: all numbers are equal to $M$. Then the answer exists only if $M = 0$ (prove it as an exercise).

Now let $M$ be the maximum value in array $b$. Then there exists an index $i$ such that $b_i = M$ and $b_{i-1} < M$ (we assume $b_0 = b_n$). We assume it's $b_n$, otherwise we just shift the array to make this happen. Then $a_n = b_n$ and $$a_i = \sum\limits_{j=i}^{n-1} b_j + 2 b_n,~i < n$$ satisfies all the constraints. That's true, because 

* $a_n < a_1$,
* $a_i - a_{i+1} = b_i$ for $i < n$,
* $b_i < a_{i+1}$ for $i < n - 1$ because $b_n$ is maximum value, which is greater than $0$,
* $b_{n-1} < b_n = M$,
* $b_n < a_1$ because $b_n < 2 b_n$.

Note that without multiplier $2$ before $b_n$ in the formula solution won't work if all numbers in the array except for one are zeroes, because in this case $a_n \mod a_{1} = 0$. Also instead of $2b_n$ it's possible to use something like $b_n + 10^{10}$, the proof doesn't change much in this case.

Problem author: [zemen](https://codeforces.com/profile/zemen "International Grandmaster zemen")

Problem developers: [yarrr](https://codeforces.com/profile/yarrr "Candidate Master yarrr"), [Kostroma](https://codeforces.com/profile/Kostroma "Legendary Grandmaster Kostroma")

 **Code**
```cpp
void solve(__attribute__((unused)) bool read) {
  int n;
  cin >> n;
  vector<int> b(n, 0);
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
  }
  int mx = *max_element(all(b));
  int start_pos = -1;
  for (int i = 0; i < n; ++i) {
    if (b[i] == mx && b[(i - 1 + n) % n] != mx) {
      start_pos = i;
      break;
    }
  }
  if (start_pos == -1) {
    if (mx == 0) {
      cout << "YESn";
      for (int i = 0; i < n; ++i) {
        cout << 1 << " n"[i + 1 == n];
      }
      return;
    }
    cout << "NOn";
    return;
  }
  auto a = b;
  for (int i = 1; i < n; ++i) {
    int pos = (start_pos - i + n) % n, prev_pos = (start_pos + 1 - i + n) % n;
    a[pos] += a[prev_pos];
    if (i == 1) {
      a[pos] += mx;
    }
  }
  cout << "YESn";
  for (int x : a) {
    cout << x << " ";
  }
  cout << "n";

}
```
 
### [1028F - Make Symmetrical](../problems/F._Make_Symmetrical.md "AIM Tech Round 5 (rated, Div. 1 + Div. 2)")

The key idea is the fact that the number of points $(x, y)$, where $x, y \ge 0$, with fixed $x^2 + y^2 = C$ is not large. Actually it is equal to the number of divisors of $C$ after removing all prime divisors of $4k+3$ form (because if $C$ has such prime divisor, then both $x, y$ are divisible by it). For the problem constraints it can be checked by brute force that maximum number of points with fixed $C \le 2 \cdot 10^{10}$ is $M = 144$.

Since the circumference with the center in origin is symmetrical with respect to any line containing origin, let's solve the problem for each circumference independently. We maintain two maps: $L$ holds the number of points for each line containing origin, $S$ holds the number of pairs of points that are symmetrical with respect to each line containing origin. When the point $p$ is added or removed on some circumference, we iterate over points $q_i$ lying on it and add or remove $1$ to $S[l(p + q_i)]$, as well as add or remove $1$ to $L[l(p)]$ (where $l(p)$ is the line through $(0, 0)$ and $p$). The answer for query $l$ is $n - L[l] - 2 \cdot H[l]$, where $n$ is the number of points at the moment. This solution makes $O(q_{changes} \cdot M + q_{asks})$ queries to map or unordered_map, which is fast enough since $M = 144$.

Problem author: [Errichto](https://codeforces.com/profile/Errichto "International Grandmaster Errichto")

Problem developers: [Kostroma](https://codeforces.com/profile/Kostroma "Legendary Grandmaster Kostroma"), [malcolm](https://codeforces.com/profile/malcolm "Master malcolm")

 **Code**
```cpp
struct Point {
  int x, y;
  Point() {}
  Point(int x, int y) : x(x), y(y) {}
  void scan() {
    cin >> x >> y;
  }
  auto key() const {
    return make_pair(x, y);
  }
  bool operator < (const Point& ot) const {
    return key() < ot.key();
  }
  bool operator == (const Point& ot) const {
    return key() == ot.key();
  }
  Point operator + (const Point& ot) const {
    return Point(x + ot.x, y + ot.y);
  }
  li sqr_dist() {
    return x * 1LL * x + y * 1LL * y;
  }
  void normalize() {
    auto g = gcd(x, y);
    x /= g;
    y /= g;
  }
};

struct Hasher {
  size_t operator () (const Point& pt) const {
    return pt.x * 2352345 + pt.y;
  }
};

enum Type {
  INSERT = 1,
  REMOVE = 2,
  QUERY = 3
};

struct Query {
  Type type;
  Point pt;
  int dist_id;
  void scan() {
    int type1;
    cin >> type1;
    type = Type(type1);
    pt.scan();
  }
};

void solve(__attribute__((unused)) bool read) {
  int Q;
  cin >> Q;
  vector<Query> queries(Q);
  map<li, vector<Point>> all_points;
  vector<li> dists;
  set<Point> have;
  for (int i = 0; i < Q; ++i) {
    queries[i].scan();
    auto& pt = queries[i].pt;
    if (queries[i].type != QUERY) {
      all_points[pt.sqr_dist()].push_back(pt);
      dists.push_back(pt.sqr_dist());
    } else {
      pt.normalize();
    }
  }
  make_unique(dists);
  for (auto& q : queries) {
    q.dist_id = (int)(lower_bound(all(dists), q.pt.sqr_dist()) - dists.begin());
  }
  vector<vector<char>> has_point(dists.size());
  vector<vector<Point>> points_by_dist_id(dists.size());
  vector<vector<vector<Point>>> sum_points(dists.size());
  unordered_map<Point, pair<int, int>, Hasher> point_position;
  for (auto& item : all_points) {
    make_unique(item.second);
    int dist_id = (int)(lower_bound(all(dists), item.first) - dists.begin());
    has_point[dist_id].assign(item.second.size(), false);
    points_by_dist_id[dist_id] = item.second;
    sum_points[dist_id].assign(item.second.size(), vector<Point>(item.second.size()));
    for (int i = 0; i < item.second.size(); ++i) {
      point_position[item.second[i]] = {dist_id, i};
      for (int j = 0; j < item.second.size(); ++j) {
        sum_points[dist_id][i][j] = item.second[i] + item.second[j];
        sum_points[dist_id][i][j].normalize();
      }
    }
  }
  unordered_map<Point, int, Hasher> on_line;
  unordered_map<Point, int, Hasher> good_pairs;

  auto change_on_line = [&] (Point pt, bool add) {
    pt.normalize();
    if (add) {
      ++on_line[pt];
    } else {
      assert(on_line[pt] > 0);
      --on_line[pt];
    }
  };

  int n_points = 0;
  for (auto& cur_q : queries) {
    auto& pt = cur_q.pt;
    int dist_id = cur_q.dist_id;
    if (cur_q.type == INSERT) {
      ++n_points;
      int pos = point_position[pt].second;
      assert(!has_point[dist_id][pos]);
      change_on_line(pt, true);
      for (int i = 0; i < points_by_dist_id[dist_id].size(); ++i) {
        if (i == pos || !has_point[dist_id][i]) {
          continue;
        }
        ++good_pairs[sum_points[dist_id][i][pos]];
      }
      has_point[dist_id][pos] = true;
    } else if (cur_q.type == REMOVE) {
      --n_points;
      int pos = point_position[pt].second;
      assert(has_point[dist_id][pos]);
      change_on_line(pt, false);
      for (int i = 0; i < points_by_dist_id[dist_id].size(); ++i) {
        if (i == pos || !has_point[dist_id][i]) {
          continue;
        }
        --good_pairs[sum_points[dist_id][i][pos]];
      }
      has_point[dist_id][pos] = false;
    } else if (cur_q.type == QUERY) {
      pt.normalize();
      cout << n_points - 2 * good_pairs[pt] - on_line[pt] << "n";
    }
  }

}
```
 
### [1028G - Guess the number](../problems/G._Guess_the_number.md "AIM Tech Round 5 (rated, Div. 1 + Div. 2)")

Although it looks strange, the bound on the number from the problem statement is actually tight for $5$ queries of length up to $10^4$. Let's find out how to obtain this number.

Let $dp(l, q)$ is the maximum $(r - l)$ such that we can guess the number which is known to be in $[l; r)$ using $q$ queries. The number $l$ is the bound for the number of guesses in the next query, except for the case $l > 10^4$ — then $dp(l, q) = dp(10^4, q)$, since from that time the bound for this number will be $10^4$.

The following process calculates $dp(l,q)$: 

* $r_0 = l$
* $r_{i + 1} = r_i + dp(r_i, q - 1) + 1$
* $dp(l,q) = r_{l + 1} - l$.

 The guesses for the current query will be $(r_1, r_2, \ldots, r_{l})$.The complexity of the solution can be estimated as $O(M_q \cdot M_{guesses}^2)$, where $M_q = 5$ and $M_{guesses} = 10^4$, but actually it's much faster if we calculate $dp$ only for reachable states.

Problem author: [zeliboba](https://codeforces.com/profile/zeliboba "Grandmaster zeliboba")

Problem developers: [Kostroma](https://codeforces.com/profile/Kostroma "Legendary Grandmaster Kostroma"), [riadwaw](https://codeforces.com/profile/riadwaw "Grandmaster riadwaw")

 **Code**
```cpp
private static final int MAX_WIDTH = 10000;
    private static final int QUERIES = 5;
    public static final long INF = 20000000000000000L;
    long[][] memo = new long[QUERIES + 1][MAX_WIDTH + 1];

    long dp(int guesses, long l) {
        if (guesses == 0) {
            return l;
        }
        if (l > MAX_WIDTH) {
            return Math.min(INF, dp(guesses, MAX_WIDTH) + l - MAX_WIDTH);
        }

        if (memo[guesses][(int) l] != 0) {
            return memo[guesses][(int) l];
        }
        long ans = l;
        for (int i = 0; i < l; ++i) {
            ans = dp(guesses - 1, ans);
            ++ans;
        }
        ans = dp(guesses - 1, ans);
        return memo[guesses][(int) l] = Math.min(ans, INF);
    }
    private void run() throws IOException {
        long l = 1;
        long r = dp(QUERIES, 1);
        for (int queriesNext = QUERIES - 1; queriesNext >= 0; --queriesNext) {
            List<Long> query = new ArrayList<>();
            long curL = l;
            for (int i = 0, e = (int)Math.min(l, MAX_WIDTH); i < e; ++i) {
                long end = dp(queriesNext, curL);
                query.add(end);
                curL = end + 1;
            }
            assert r == dp(queriesNext, curL);
            out.print(query.size());
            for (long x: query) {
                out.print(" ");
                out.print(x);
            }
            out.println();
            out.flush();
            System.out.flush();

            int ans = readInt();
            if (ans < 0) {
                return;
            }
            if (ans > 0) {
                l = query.get(ans - 1) + 1;
            }
            if (ans != query.size()) {
                r = query.get(ans);
            }

            assert dp(queriesNext, l) == r;
        }
    }
```
 
### [1028H - Make Square](../problems/H._Make_Square.md "AIM Tech Round 5 (rated, Div. 1 + Div. 2)")

Firstly, we can divide out all squares from the $a_i$, since they make no difference. Thus, each $a_i$ is then a product of unique primes. If we want to transform $a_i$ and $a_j$ so that their product becomes a square, the cost is the number of primes that appear in one but not in another. Each $a_i$ can have at most $7$ primes ($2 \cdot 3 \cdot 5 \cdot 7 \cdot 11 \cdot 13 \cdot 17 \cdot 19$ is too big), so at most $128$ divisors.

Sweep from left to right, maintaining $dp[val][dist]$ — the rightmost index $i$ so far that $a_i$ can be expressed as $val \cdot x$, where $x$ has $dist$ primes in its factorization. Also maintain $best[D]$ — the rightmost $l$ such that the answer for the segment $[l; i]$ is $D$, for current index $i$. To add a new $a_i$ in $dp$, consider each divisor $val$ in it, calculate $dist$ as the number of primes in $\dfrac{a_i}{val}$ and relax $dp[val][dist]$ with $i$. Before doing this for $i$, we need to update $best$ array: for each $val~|~a_i$ and $\dfrac{a_i}{val}$ having $dist$ primes in factorization and for each $k \le 7$ relax $best[k + dist]$ with $dp[val][dist]$. Then all queries with right border equal to $i$ can be answered in $O(M_{ans})$ time, where $M_{ans} \le 14$.

The complexity of this solution is $O(n \cdot M_{primes} \cdot 2^{M_{primes}} + q \cdot M_{ans})$, where $M_{primes} = 7$, $M_{ans} \le 2 M_{primes}$. Actually, the maximum possible answer for a query in this problem is $11$. You can find two numbers generating it as an exercise.

Problem author: [Kostroma](https://codeforces.com/profile/Kostroma "Legendary Grandmaster Kostroma")

Problem developers: [Kostroma](https://codeforces.com/profile/Kostroma "Legendary Grandmaster Kostroma"), [riadwaw](https://codeforces.com/profile/riadwaw "Grandmaster riadwaw"), [gchebanov](https://codeforces.com/profile/gchebanov "International Master gchebanov"), [malcolm](https://codeforces.com/profile/malcolm "Master malcolm")

 **Code**
```cpp
const int C = 5032107 + 1;
int lp[C];
int fred[C];
int num_primes[C];

const int MAX_DIVISORS = 7;
const int MAX_ANS = 2 * MAX_DIVISORS;

int max_left[MAX_DIVISORS + 1][C];
int max_border[MAX_ANS + 1];

vector<int> cur_primes;

vector<int> divs;

void get_divisors(int n) {
    divs = {1};
    while (n > 1) {
        int p = lp[n];
        n /= p;
        int sz = divs.size();
        for (int i = 0; i < sz; ++i) {
            divs.push_back(divs[i] * p);
        }
    }
}

void solve(bool read) {
    vector<int> pr;
    for (int i = 2; i < C; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.push_back(i);
        }
        for (int j = 0; j < pr.size() && pr[j] <= lp[i] && i * pr[j] < C; ++j) {
            lp[i * pr[j]] = pr[j];
        }
    }
    fred[1] = 1;
    for (int i = 2; i < C; ++i) {
        int p = lp[i];
        int cur = i / p;
        if (cur % p == 0) {
            fred[i] = fred[cur / p];
            num_primes[i] = num_primes[cur / p];
        } else {
            fred[i] = p * fred[cur];
            num_primes[i] = num_primes[cur] + 1;
        }
    }

    for (int i = 0; i < C; ++i) {
        for (int j = 0; j <= MAX_DIVISORS; ++j) {
            max_left[j][i] = -1;
        }
    }
    memset(max_border, -1, sizeof(max_border));

    int n;
    cin >> n;
    int Q;
    cin >> Q;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        a[i] = fred[a[i]];
    }

    vector<vector<pair<int, int>>> queries(n);

    vector<int> res(Q);
    for (int i = 0; i < Q; ++i) {
        int l, r;
        cin >> l >> r;
        --l; --r;
        queries[r].push_back({l, i});
    }

    for (int i = 0; i < n; ++i) {
        get_divisors(a[i]);
        for (int d : divs) {
            int first_add = num_primes[a[i]] - num_primes[d];
            for (int prev_ans = 0; prev_ans <= MAX_DIVISORS; ++prev_ans) {
                int cur_left = max_left[prev_ans][d];
                int cur_ans = first_add + prev_ans;
                if (cur_ans <= MAX_ANS) {
                    relax_max(max_border[cur_ans], cur_left);
                }
            }
        }
        for (int d : divs) {
            int first_add = num_primes[a[i]] - num_primes[d];
            relax_max(max_left[first_add][d], i);
        }
        for (auto q : queries[i]) {
            res[q.second] = MAX_ANS + 1;
            for (int cur_ans = 0; cur_ans <= MAX_ANS; ++cur_ans) {
                if (max_border[cur_ans] >= q.first) {
                    res[q.second] = cur_ans;
                    break;
                }
            }
            assert(res[q.second] <= MAX_ANS);
        }
    }

    int sum_ans = 0;
    for (int i = 0; i < Q; ++i) {
        cout << res[i] << 'n';
    }
}
```
