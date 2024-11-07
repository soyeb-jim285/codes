# Tutorial_(en)

[1955A - Yogurt Sale](../problems/A._Yogurt_Sale.md "Codeforces Round 938 (Div. 3)")

Idea: [mainyutin](https://codeforces.com/profile/mainyutin "Expert mainyutin"), prepared: [mainyutin](https://codeforces.com/profile/mainyutin "Expert mainyutin")

 **Tutorial**
### [1955A - Yogurt Sale](../problems/A._Yogurt_Sale.md "Codeforces Round 938 (Div. 3)")

You can always buy yogurts one by one without using the promotion, then the answer is $n \cdot a$.

Suppose it is more advantageous to buy yogurts on promotion than one by one, that is, $b < 2 \cdot a$. If $n$ is even, the answer is ${n \over 2} \cdot b$, otherwise ${(n - 1) \over 2} \cdot b + a$.

Now you just need to choose whether to buy yogurts one by one or on promotion, taking the minimum of the two options.

 **Solution**
```cpp
#include <bits/stdc++.h>
 
using ll = signed long long int;
 
using namespace std;
 
void solve() {
    ll n, a, b;
    cin >> n >> a >> b;
    ll ans = n * a;
    if (b < 2 * a) {
        ans = (n / 2) * b + (n % 2) * a;
    }
    cout << ans << 'n';
}
 
int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}

```
[1955B - Progressive Square](../problems/B._Progressive_Square.md "Codeforces Round 938 (Div. 3)")

Idea: [ssor96](https://codeforces.com/profile/ssor96 "Master ssor96"), [mainyutin](https://codeforces.com/profile/mainyutin "Expert mainyutin"), prepared: [Vladosiya](https://codeforces.com/profile/Vladosiya "Expert Vladosiya")

 **Tutorial**
### [1955B - Progressive Square](../problems/B._Progressive_Square.md "Codeforces Round 938 (Div. 3)")

Since $c > 0$ and $d > 0$, the elements of the square increase starting from the top left corner. Thus, $a_{1,1}$ is the minimum element in the square, and consequently in the found elements.

Given $n$, $c$, $d$, and the found $a_{1,1}$, we will reconstruct the square. It remains to check that the given numbers in the input form the same square. The easiest way is to sort both arrays of numbers and check for equality. The complexity of the solution is $O(n ^ 2 \cdot \log{n})$.

 **Solution**
```cpp
#include <bits/stdc++.h>
 
using namespace std;
 
#define all(x) (x).begin(), (x).end()
 
using ll = signed long long int;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
 
void solve() {
    int n;
    ll c, d;
    cin >> n >> c >> d;
    vl a(n * n);
    for (int i = 0; i < n * n; ++i) {
        cin >> a[i];
    }
    sort(all(a));
    vl b(n * n);
    b[0] = a[0];
    for (int i = 1; i < n; ++i) {
        b[i] = b[i - 1] + c;
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            b[i * n + j] = b[(i - 1) * n + j] + d;
        }
    }
    sort(all(b));
    cout << (a == b ? "YEs" : "nO") << 'n';
}
 
int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}

```
[1955C - Inhabitant of the Deep Sea](../problems/C._Inhabitant_of_the_Deep_Sea.md "Codeforces Round 938 (Div. 3)")

Idea: [ssor96](https://codeforces.com/profile/ssor96 "Master ssor96"), [Vladosiya](https://codeforces.com/profile/Vladosiya "Expert Vladosiya"), prepared: [mainyutin](https://codeforces.com/profile/mainyutin "Expert mainyutin")

 **Tutorial**
### [1955C - Inhabitant of the Deep Sea](../problems/C._Inhabitant_of_the_Deep_Sea.md "Codeforces Round 938 (Div. 3)")

To solve the problem, let's model the behavior of the Kraken. Suppose initially there are two or more ships in the sea, we will consider the first and last ship, denote their durabilities as $a_l$ and $a_r$, and also let $m = \min(a_l, a_r)$, initially setting $l = 1$ and $r = n$.

After two attacks, the durability of both ships will decrease by $1$. If $k \ge 2 \cdot m$, then we need to subtract $m$ from the durabilities of both ships, and also reduce the remaining attacks of the Kraken by $2 \cdot m$. If $k < 2 \cdot m$, then the Kraken will inflict $\lfloor {k \over 2} \rfloor$ damage to the $r$-th ship. In this case, if $k$ is odd, the $l$-th ship will receive $\lfloor {k \over 2} \rfloor + 1$ damage, otherwise $\lfloor {k \over 2} \rfloor$ damage.

After these attacks, some ships may have sunk. If $a_l = 0$, we increase $l$ by $1$, if $a_r = 0$, we decrease $r$ by $1$, and move on to considering the next pair of ships that will be under attack by the Kraken. If at some point $l = r$, it means that there is only one ship left in the sea, and the Kraken can sink it if $k \ge a_l$.

A deque is perfect for this problem, allowing us to not think about $l$ and $r$ and simply look at the first and last elements in the queue. At each step of considering a pair of ships, either the Kraken's attacks end, or at least one ship sinks. The final complexity of the solution is $O(n)$.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()

using ll = signed long long int;

void solve() {
    int n;
    ll k;
    cin >> n >> k;
    deque<ll> dq(n);
    for (int i = 0; i < n; ++i) {
        cin >> dq[i];
    }
    while (dq.size() > 1 && k) {
        ll mn = min(dq.front(), dq.back());
        if (k < 2 * mn) {
            dq.front() -= k / 2 + k % 2;
            dq.back() -= k / 2;
            k = 0;
        } else {
            dq.front() -= mn;
            dq.back() -= mn;
            k -= 2 * mn;
        }
        if (dq.front() == 0) {
            dq.pop_front();
        }
        if (dq.back() == 0) {
            dq.pop_back();
        }
    }
    int ans = n - dq.size();
    cout << ans + (dq.size() && dq.front() <= k) << 'n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
```
[1955D - Inaccurate Subsequence Search](../problems/D._Inaccurate_Subsequence_Search.md "Codeforces Round 938 (Div. 3)")

Idea: [mainyutin](https://codeforces.com/profile/mainyutin "Expert mainyutin"), [Vladosiya](https://codeforces.com/profile/Vladosiya "Expert Vladosiya"), prepared: [mainyutin](https://codeforces.com/profile/mainyutin "Expert mainyutin")

 **Tutorial**
### [1955D - Inaccurate Subsequence Search](../problems/D._Inaccurate_Subsequence_Search.md "Codeforces Round 938 (Div. 3)")

How to check if two arrays are good? For each element of $b$, try to pair it with an element from array $a$. If we managed to create $k$ or more pairs, then the arrays are good.

Since rearranging the elements of the array is allowed, we will maintain three multisets $C$, $D$, and $E$. In $D$, we will store all elements from $b$ for which we found a pair, and in $C$ and $E$, all elements from $b$ and $a$ for which a pair was not found, i.e., $C \cap E = \emptyset$. Then the arrays are good if $|D| \ge k$.

It remains to understand how to find all good subsegments using this data organization. Suppose we shift the left boundary $l$ by $1$, simultaneously moving the right boundary, where $r = l + m - 1$. We need to remove the pair with the element $a_l$ from $D$, if it exists, and immediately try to find a replacement for the removed pair in $E$. After that, we try to find a pair for $a_r$ from $C$, and if a pair cannot be found, we place the element in $E$.

The complexity of the solution is $O(n \log n)$ or $O(n)$ if a hash table is used.

 **Solution**
```cpp
#include <bits/stdc++.h>
 
using ll = signed long long int;
 
#define all(x) (x).begin(), (x).end()
 
using pii = std::pair<int, int>;
using pll = std::pair<ll, ll>;
 
using namespace std;
 
void solve() {
    int n, m;
    size_t k;
    cin >> n >> m >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    multiset<int> todo, done, extra;
    for (int j = 0; j < m; ++j) {
        int b;
        cin >> b;
        todo.insert(b);
    }
    for (int j = 0; j < m; ++j) {
        if (todo.find(a[j]) != todo.end()) {
            todo.erase(todo.find(a[j]));
            done.insert(a[j]);
        } else {
            extra.insert(a[j]);
        }
    }
    int ans = (done.size() >= k);
    for (int r = m; r < n; ++r) {
        int old = a[r - m];
        if (extra.find(old) != extra.end()) {
            extra.erase(extra.find(old));
        } else if (done.find(old) != done.end()) {
            done.erase(done.find(old));
            todo.insert(old);
        }
        if (todo.find(a[r]) != todo.end()) {
            todo.erase(todo.find(a[r]));
            done.insert(a[r]);
        } else {
            extra.insert(a[r]);
        }
        ans += (done.size() >= k);
    }
    cout << ans << 'n';
}
 
int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}

```
[1955E - Long Inversions](../problems/E._Long_Inversions.md "Codeforces Round 938 (Div. 3)")

Idea: [ssor96](https://codeforces.com/profile/ssor96 "Master ssor96"), prepared: [Vladosiya](https://codeforces.com/profile/Vladosiya "Expert Vladosiya")

 **Tutorial**
### [1955E - Long Inversions](../problems/E._Long_Inversions.md "Codeforces Round 938 (Div. 3)")

No substring of the string needs to be inverted twice, as it does not change the string in any way. Let's fix $k$ and try to check if all the characters of the string can be made equal to 1. Suppose the first $i$ characters are already equal to 1, and $s_{i + 1}=0$. Then we need to invert all the bits starting from the $i + 1$-th to the $i + k$-th inclusive, i.e., not invert the first $i$ characters. If we invert any of the first $i$ characters, then we will have to invert it again. Either we will invert $s_{i + 1}$ again, so it will become equal to 0, or we will invert the characters to the left and come to the same situation, but for a smaller prefix.

Naive checking for a fixed $k$ takes $O(n \cdot k)$ time, if we honestly invert $k$ characters every time we encounter 0. We will maintain an inversion counter — how many times we need to invert a character of the string. Getting the actual value of a character is simple — if the counter is odd, invert the character. If $s_{i} = 0$, add $1$ to the counter, and remember that we need to subtract $1$ from the counter after position $i + k$, forming a segment $[i, i + k)$. This way, the complexity of the check will be $O(n)$.

It remains to iterate over $k$ and find the maximum for which it was possible to bring the string to all 1s. The complexity of the solution is $O(n ^ 2)$.

 **Solution**
```cpp
#include <bits/stdc++.h>
 
using ll = signed long long int;
 
#define all(x) (x).begin(), (x).end()
 
using pii = std::array<int, 2>;
using pll = std::array<ll, 2>;
using vi = std::vector<int>;
using vl = std::vector<ll>;
 
using namespace std;
 
void solve() {
    int n;
    string s;
    cin >> n >> s;
    for (int k = n; k > 0; --k) {
        vector<char> t(n), end(n + 1);
        for (int i = 0; i < n; ++i) {
            t[i] = s[i] - '0';
        }
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            cnt -= end[i];
            t[i] ^= (cnt & 1);
            if (t[i] == 0) {
                if (i + k <= n) {
                    ++end[i + k];
                    ++cnt;
                    t[i] = 1;
                } else {
                    break;
                }
            }
        }
        if (*min_element(all(t)) == 1) {
            cout << k << 'n';
            return;
        }
    }
    assert(false);
}
 
int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}

```
[1955F - Unfair Game](../problems/F._Unfair_Game.md "Codeforces Round 938 (Div. 3)")

Idea: [mainyutin](https://codeforces.com/profile/mainyutin "Expert mainyutin"), prepared: [mainyutin](https://codeforces.com/profile/mainyutin "Expert mainyutin")

 **Tutorial**
### [1955F - Unfair Game](../problems/F._Unfair_Game.md "Codeforces Round 938 (Div. 3)")

Let's try to solve the problem if all the numbers in the sequence are equal to $4$. If the number of elements is even, the bitwise XOR is zero, and if it's odd, then it's equal to $4$. By removing one $4$ at a time, Eve will change the parity, so the answer will be $\lfloor {p_4 \over 2} \rfloor$.

Suppose there are some other numbers in the sequence besides $4$. For Bob to win, the number of $4$s still needs to be even. Therefore, we can solve the problem for the remaining numbers separately from the fours.

One of the solutions uses dynamic programming. Let's denote $dp_{i,j,k}$ as the maximum number of Bob's wins, if there were initially $i$ ones, $j$ twos, and $k$ threes. Since an empty sequence is not considered in the answer, then $dp_{0,0,0} = 0$. We will iterate over which number to remove, and get the following transitions: $dp_{i,j,k} = \max(dp_{i - 1,j,k}, dp_{i,j - 1,k}, dp_{i,j,k - 1}) + x(i,j,k)$. Here, $x(i,j,k) = 1$ if the bitwise XOR of $i$ ones, $j$ twos, and $k$ threes is zero, and $x(i,j,k) = 0$ otherwise. The complexity of calculating these values is $O(N ^ 3)$, where $N = 200$.

Another solution is analytical. Bob wins in two cases: if the number of ones, twos, and threes is even; if the number of ones, twos, and threes is odd. In the first case, the bitwise XOR is zero, because each number occurs an even number of times, and in the second case, $1 \oplus 2 \oplus 3 = 0$.

To maintain the parities, Eve needs to remove the same number, so with two removals, Bob will win once. If the second condition is not initially met, it is always more advantageous to remove numbers to reach the first case, then the answer is $\sum^{3}_{i = 1} \lfloor{cnt_i \over 2}\rfloor$. If the second condition is already met, then $1$ needs to be added to the answer.

 **Solution**
```cpp
#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 201;
 
int dp[N][N][N];
 
void precalc() {
    dp[0][0][0] = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k < N; ++k) {
                int prev = 0;
                if (i) prev = max(prev, dp[i - 1][j][k]);
                if (j) prev = max(prev, dp[i][j - 1][k]);
                if (k) prev = max(prev, dp[i][j][k - 1]);
                dp[i][j][k] = prev;
                int xr = ((i & 1) * 1) ^ ((j & 1) * 2) ^ ((k & 1) * 3);
                if (xr == 0 && (i || j || k)) {
                    ++dp[i][j][k];
                }
            }
        }
    }
}
 
void solve() {
    vector<int> cnt(4);
    for (int i = 0; i < 4; ++i) {
        cin >> cnt[i];
    }
    cout << dp[cnt[0]][cnt[1]][cnt[2]] + cnt[3] / 2 << 'n';
}
 
int main() {
    precalc();
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}

```
[1955G - GCD on a grid](../problems/G._GCD_on_a_grid.md "Codeforces Round 938 (Div. 3)")

Idea: [ZergTricky](https://codeforces.com/profile/ZergTricky "Master ZergTricky"), prepared: [mainyutin](https://codeforces.com/profile/mainyutin "Expert mainyutin")

 **Tutorial**
### [1955G - GCD on a grid](../problems/G._GCD_on_a_grid.md "Codeforces Round 938 (Div. 3)")

First, let's learn how to check for a fixed $x$ if there exists a path from $(1,1)$ to $(n,m)$ with a GCD of $x$. It is necessary for all numbers along the path to be divisible by $x$. Let's define a grid $b$ of size $n$ by $m$, where $b_{i,j} = 1$ if $a_{i,j}$ is divisible by $x$, and $b_{i,j} = 0$ otherwise. If there exists a path of ones in $b$, then there exists a path in $a$ with a GCD of $x$.

To check if there exists a path consisting entirely of ones, dynamic programming can be used. Let $dp_{i, j}$ denote whether it is possible to reach $(i,j)$ from $(1,1)$. Then the transitions are $dp_{i,j} = dp_{i - 1,j} \lor dp_{i,j - 1}$, with the base case of the dynamic programming being $dp_{1,1} = b_{1,1}$.

Since the path will definitely pass through the cells $(1,1)$ and $(n,m)$, we iterate through all divisors of the number $g = \gcd(a_{1,1}, a_{n,m})$, check for each one if there exists a path with that GCD, and take the maximum such divisor. The complexity of the solution is $O(n \cdot m \cdot \sqrt[3]{A})$, where $A \le 10^6$.

 **Solution**
```cpp
#include <bits/stdc++.h>
 
using ll = signed long long int;
 
#define all(x) (x).begin(), (x).end()
 
using pii = std::pair<int, int>;
using pll = std::pair<ll, ll>;
 
using namespace std;
 
void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int> > a(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }
    int ans = 1, g = gcd(a[0][0], a[n - 1][m - 1]);
    vector<vector<char> > dp(n, vector<char>(m));
    for (int x = 1; x * x <= g; ++x) {
        if (g % x > 0) {
            continue;
        }
        vector<int> cand = {x, g / x};
        for (int el : cand) {
            for (int i = 0; i < n; ++i) {
                dp[i].assign(m, 0);
            }
            dp[0][0] = 1;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    if (a[i][j] % el > 0) {
                        continue;
                    }
                    if (!dp[i][j] && i) {
                        dp[i][j] = (dp[i - 1][j] == 1 ? 1 : 0);
                    }
                    if (!dp[i][j] && j) {
                        dp[i][j] = (dp[i][j - 1] == 1 ? 1 : 0);
                    }
                }
            }
            if (dp[n - 1][m - 1]) {
                ans = max(ans, el);
            }
        }
    }
    cout << ans << 'n';
}
 
int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}

```
[1955H - The Most Reckless Defense](../problems/H._The_Most_Reckless_Defense.md "Codeforces Round 938 (Div. 3)")

Idea: [vmanosin7](https://codeforces.com/profile/vmanosin7 "Expert vmanosin7"), prepared: [mainyutin](https://codeforces.com/profile/mainyutin "Expert mainyutin")

 **Tutorial**
### [1955H - The Most Reckless Defense](../problems/H._The_Most_Reckless_Defense.md "Codeforces Round 938 (Div. 3)")

Let's solve the problem for a single tower. The tower's area of effect is a circle, so the theoretically possible number of cells in which a tower with radius $r$ will deal damage is $\pi \cdot r ^ 2$. In total, the tower will deal $p_i \cdot \pi \cdot r^2$ damage to the enemy. At the same time, the initial health of the enemy will be increased by $3^r$, so in fact, this health increase needs to be subtracted from the tower's damage. Thus, the maximum radius for the tower can be found from the inequality $500 \cdot \pi \cdot r ^ 2 - 3 ^ r > 0$, assuming that the tower has a damage of $p_i = 500$. This estimate gives $R = 12$, above which the enemy's health increase is too large for the tower to overcome.

So, there are not so many radii, and each radius can be applied to no more than one tower. We will use the subset dynamic programming method: $dp_{i,mask}$ — the maximum damage that the first $i$ towers will deal with the optimal distribution of the radii in the $mask$. The transitions are quite simple: $dp_{i, mask} = \max_{r \in mask}(dp_{i - 1, mask}, dp_{i - 1, mask \oplus r} + p_i \cdot cover(i, r))$. The answer will be the maximum value $\max_{mask} (dp_{k, mask} - \sum_{r \in mask} {3 ^ r})$.

$cover(i, r)$ — this is the number of cells covered by the $i$-th tower when the radius is set to $r$. It can be calculated for one tower and for one radius in $O(r ^ 2)$ time, just iterate through the square with a side length of $2 \cdot r$ and a center coinciding with the location of the tower. In total, the precalculation of $cover$ for all towers and all radii will take $O(k \cdot R ^ 3)$ time. The complexity of calculating the dynamic programming values is $O(k \cdot R \cdot 2 ^ R)$, so the final complexity of the solution is $O(k \cdot R \cdot (2 ^ R + R ^ 2))$.

 **Solution**
```cpp
#include <bits/stdc++.h>
 
using ll = signed long long int;
 
#define all(x) (x).begin(), (x).end()
 
using pii = std::pair<int, int>;
using pll = std::pair<ll, ll>;
 
using namespace std;
 
const int R = 12, INF = 2e9;
 
bool check(int x, int n) { return (0 <= x && x < n); }
 
void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<string> gr(n);
    for (int i = 0; i < n; ++i) {
        cin >> gr[i];
    }
    vector<pii> cord(k);
    vector<int> p(k);
    for (int i = 0; i < k; ++i) {
        cin >> cord[i].first >> cord[i].second >> p[i];
        --cord[i].first;
        --cord[i].second;
    }
    vector<vector<int> > cover(k, vector<int>(R + 1));
    for (int i = 0; i < k; ++i) {
        int x = cord[i].first;
        int y = cord[i].second;
        for (int r = 1; r <= R; ++r) {
            for (int dx = -r; dx <= r; ++dx) {
                for (int dy = -r; dy <= r; ++dy) {
                    int nx = x + dx;
                    int ny = y + dy;
                    if (!check(nx, n) || !check(ny, m)) {
                        continue;
                    }
                    if ((x - nx) * (x - nx) + (y - ny) * (y - ny) <= r * r) {
                        cover[i][r] += (gr[nx][ny] == '#');
                    }
                }
            }
        }
    }
    vector<vector<int> > dp(k + 1, vector<int>(1 << R, -INF));
    dp[0][0] = 0;
    for (int i = 1; i <= k; ++i) {
        for (int mask = 0; mask < (1 << R); ++mask) {
            dp[i][mask] = dp[i - 1][mask];
            for (int r = 1; r <= R; ++r) {
                int j = r - 1;
                if (!(mask & (1 << j))) {
                    continue;
                }
                dp[i][mask] = max(dp[i][mask], dp[i - 1][mask ^ (1 << j)] +
                                                   p[i - 1] * cover[i - 1][r]);
            }
        }
    }
    int ans = 0;
    for (int mask = 0; mask < (1 << R); ++mask) {
        int hp = 0, mlt = 3;
        for (int j = 0; j < R; ++j) {
            if (mask & (1 << j)) {
                hp += mlt;
            }
            mlt *= 3;
        }
        for (int i = 0; i <= k; ++i) {
            ans = max(ans, dp[i][mask] - hp);
        }
    }
    cout << ans << 'n';
}
 
int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}

```
