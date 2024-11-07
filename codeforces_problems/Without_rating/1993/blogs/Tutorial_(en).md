# Tutorial_(en)

[1993A - Question Marks](../problems/A._Question_Marks.md "Codeforces Round 963 (Div. 2)")

 **Hint**What is the pattern of Tim's answer sheet that can give him maximum score?

 **Solution**Let's say there are n problems take A as the answer, therefore he can only get n points with the answer A. The same is correct for B, C and D. Therefore, the maximum score can be achieved is min(n,A)+min(n,B)+min(n,C)+min(n,D).

Time complexity: O(4n) 

 **Code (python)**
```cpp
t = int(input())
for _ in range(t):
    n = int(input())
    s = input()

    print(sum(min(n, s.count(c)) for c in "ABCD"))
```
[1993B - Parity and Sum](../problems/B._Parity_and_Sum.md "Codeforces Round 963 (Div. 2)")

 **Hint 1**Find a way to make all the elements even. Then odd.

 **Hint 2**In the worst case, the number of operations required is the number of even elements + 1. Why?

 **Solution**First, if all elements already have the same parity, we don't need to do perform any operation.

Next, if the array contains both even and odd numbers. In this case, it is impossible to convert all elements to even numbers.

 **Why?**If we apply an operation on:

 * two odd elements, one of them remains odd.
* two elements of distinct parities, one of them is replaced with their sum, which is an odd number.

This implies even if we want to change an odd element to even number, it fails in both ways possible.

So we just want to convert all of them to odd numbers. Now come the greedy part:

 * even+even=even⟶ it doesn't reduce the number of even elements, so skip it.
* odd+odd=even⟶ this creates another even number, indeed very awful.
* even+odd=odd⟶ this is great, but only if the sum replaces the even one (which means even<odd).

Let's find the largest odd element and call it s. Then traverse each even elements t in non-decreasing order and apply an operation on s and t:

 1. If t<s, s+t becomes largest odd number. Thus, we set s:=s+t. This reduce the number of even element by 1.
2. If t>s, before we do this operation, we need to do another on s and the largest even element to make s the largest in the array. Note that this case only happens at most once.

As a result, the answer is the number of even elements (plus 1 if the second case occurs).

Time complexity: O(nlogn).

 **Code (python)**
```cpp
t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))

    s = -1
    v = []
    for x in a:
        if x%2 == 0:
            v.append(x)
        elif x > s:
            s = x
    v.sort()

    if s == -1 or v == []:
        print(0)
        continue
    
    ans = len(v)
    for t in v:
        if t < s:
            s += t
        else:
            ans += 1
            break

    print(ans)
```
[1993C - Light Switches](../problems/C._Light_Switches.md "Codeforces Round 963 (Div. 2)")

 **Hint 1**Try to find the segments of moments when a light is on.

 **Hint 2**Select this segment from each light. The answer should be the intersection of all of them.

 **Solution**
> As soon as a chip is installed, it changes the light's status every k minutes.

Let's first list the segments of the moments when a light is on if we install a chip at moment x:

 * x→x+k−1
* x+2k→x+3k−1
* x+4k→x+5k−1
* …

Have you seen the pattern yet? Apparently each segment in the list (except the first one) is actually the segment before it, shifted by 2k minutes. This also means that if we divide by 2k and take the remainder at both ends of each segment, all these segments become equal. With that, let's call (aimod2k,(ai+k−1)mod2k) the segment of the i-th chip.

Our problem is thus simplified to: find the smallest integer s such that:

 1. max(a)≤s
2. smod2k appears in every segments of all chips.

In order to satisfy the first condition, it seems if we figure out some r=smod2k that satisfy the second condition, we may come up with: 

 s=max(a)+((r−max(a))mod2k)Next, in order for a segment to contain r, this inequality must be satisfied: r−k+1≤ai≤r(mod2k). This is because a light is on only for at most k minutes (before it gets turned off), so it must come not long before the moment r. Let's call d[z] the number of chips that has ai≡z(mod2k), then in order for all lights to be on at moment s, the condition is: 

 r∑z=r−k+1d[z]=nThis idea can be implemented using two-pointer technique, that traverse all r from 0 to 2k−1. As there can be many possible values of r, we only take one that produces s with minimum value. Be careful when handling signs in problems with modules to avoid unnecessary errors.

Time complexity: O(n).

 **Code (C++)**
```cpp
#include <bits/stdc++.h>
using namespace std;
 
 
const int N = 2e5 + 5;
 
int n, k, d[2*N];
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int t;
    cin >> t;
 
    while (t--) {
        cin >> n >> k;
 
        int mx = -1;
        fill(d, d + 2*k, 0);
 
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            assert(x >= 1);
            d[x % (2*k)]++;
            mx = max(mx, x);
        }
 
        int cnt = 0;
        int ans = INT_MAX;
        for (int i = 0; i <= k - 2; i++) {
            cnt += d[i];
        }
 
        for (int l = 0, r = k-1; l < 2*k; l++, r++) {
            if (r >= 2*k) r -= 2*k;
 
            if (cnt += d[r]; cnt == n) {
                int wait = (r-mx) % (2*k);
                if (wait < 0) wait += 2*k;
                ans = min(ans, mx + wait);
            }
 
            cnt -= d[l];
        }
 
        if (ans == INT_MAX) {
            ans = -1;
        }
        cout << ans << 'n';
    }
}
```
[1993D - Med-imize](../problems/D._Med-imize.md "Codeforces Round 963 (Div. 2)")

 **Hint 1**Is there any method to calculate median without sorting?

 **Hint 2**Is there any relationship between the original array with the final array?

 **Solution**Note: in order to explain this solution easier, we'll suppose all arrays are 0-indexed.

If n≤k, we don't have to remove any segment since the statement only tell us to do it while the length of a is greater than k. That way, the median of a is fixed. Let's find a way to calculate this value **without** sorting the array.

Given an integer x. If x is less than or equal to the median of a, then suppose we sort a in increasing order, x is somewhat to the left of med(a). That means the number of elements greater than or equal to x is more than the number of elements less than x. Using this observation, we can create another array b of the same size as a, such that b[i]=1 if a[i]≥x, otherwise b[i]=−1. The trick here is if sum(b)>0, then the condition x≤med(a) is satisfied. Using this trick, we can easily binary search the median of a by fixing value of x, checking if sum(b)>0 and adjusting the value range of med(a).

How about n>k. In this case, we'll keep using the same strategy as above. That is: fix the value of x, find a way to delete segments of a so that the array b has largest sum, check if that sum is greater than 0 and adjust the value range of the answer.

Note that each time we delete a segment, the size of a is reduced by k. We do that until |a|≤k. Let's call the final array a after deleting segments a′. After some calculation, we come up with |a′|=((n−1)modk)+1.

Also, it can be seen that the elements a′[0],…,a′[m−1] (where m=|a′|) always originate from the elements a[i0],…,a[im−1] such that i0≡0(modk),i1≡1(modk),…,im−1≡m−1(modk).

 **Why?**Suppose we want to delete the segment [i,i+k−1] from a. This operation shift all the elements from the right by k units to the left, which means the indexes are subtracted by k units. But if we only care about the indexes modulo k before and after deleting the segments, shifting k units doesn't change their modulos at all.

With all above observations, we come up with the following DP formula to find the optimal segment deletions:

 * dp[0]=b[0]
* If i≡0(modk) and i>0, then dp[i]=max(dp[i−k],b[i])
* Otherwise dp[i]=dp[i−1]+b[i]. If i>k then maximize dp[i] by dp[i−k]

Then, the maximum sum of b in the optimal deletions equals to dp[n−1].

Time complexity: O(nlogmax(a)).

 **Code (C++)**
```cpp
#include <bits/stdc++.h>
using namespace std;

const int N = 500005;

int n, k, a[N];
int dp[N], b[N];

bool check(int med) {
    for (int i = 0; i < n; i++) {
        if (a[i] >= med) {
            b[i] = 1;
        } else {
            b[i] = -1;
        }
    }

    dp[0] = b[0];
    for (int i = 1; i < n; i++) {
        if (i%k == 0) {
            dp[i] = max(dp[i-k], b[i]);
        } else {
            dp[i] = dp[i-1] + b[i];
            if (i > k) {
                dp[i] = max(dp[i], dp[i-k]);
            }
        }
    }

    return dp[n-1] > 0;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t; cin >> t;
    while (t--) {
        cin >> n >> k;

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        int lo = 1, hi = 1e9;
        while (lo <= hi) {
            int mid = lo + hi >> 1;
            if (check(mid)) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        cout << hi << 'n';
    }
}
```
[1993E - Xor-Grid Problem](../problems/E._Xor-Grid_Problem.md "Codeforces Round 963 (Div. 2)")

 **Hint 1**Try applying an operation on the same row twice. Does it change the matrix significantly?

 **Hint 2**Now apply operations on two different rows. Does the second row (that the operation is applied) look familiar?

 **Solution**First, let's extend the original matrix by one unit in rows and columns (which means there's an additional (n+1)-th row and (m+1)-th column). Then, assign a[i][m+1]=f(i) (xorsum of the i-th row) and a[n+1][j]=g(j) (xorsum of the j-th column). That way, the operation is simplified as follows:

 1. The first-type operation becomes swapping the i-th row with the (n+1)-th row.
2. The second-type operation becomes swapping the j-th column with the (m+1)-th column.

 **Why?**As we know, the first-type operation is to select any row i, then assign a[i][j]=g(j) for all index j. But after the matrix extension, the value of g(j) is also a[n+1][j] so it means replacing the i-th row with the (n+1)-th one.

But we also need to care about the new value of g(j) for future operations right? Surprisingly, the new value of g(j) is nowhere strange, just the old value of element a[i][j] being replaced right before! This takes advantage of the fact that if we perform the operation on the same row twice, the row become unchanged. After swapping two rows, the value of a[n+1][j] then again become g(j) of the new matrix.

The change of the second-type operation can be proven the same way.

That way, the matrix can be constructed by the permutation of rows, and the permutation of columns (as we can swap them however we want). After all operations, let's say the rows ordered from the top to the bottom are r1,r2,…,rn+1. Similarly, the columns ordered from the left to the right are c1,c2,…,cm+1.

Next thing to consider is: beauty(a)=R+C — the beauty of the matrix, where:

 * R=n∑i=1m∑j=2|a[i][j]−a[i][j−1]| — sum of adjacent cells on the same row.
* C=m∑j=1n∑i=2|a[i][j]−a[i−1][j]| — sum of adjacent cells on the same column.

Note that we include **neither** the (n+1)-th row **nor** the (m+1)-th column when calculating R and C. That being said, after all operations, the rn+1-th row and the cm+1-th column is excluded and do not make any effect in further calculations anymore.

After that, we calculate two arrays:

 * dr[u][v]= sum of differences between u-th row and v-th row.
* dc[u][v]= sum of differences between u-th column and v-th column.

Then, we'll rewrite the formulas of R and C as: R=n∑i=2dr[ri−1][ri] and C=m∑i=2dc[ci−1][ci]. From now on, calculating R and C is as easy as solving the [Travelling Salesman Problem](https://codeforces.com/https://en.wikipedia.org/wiki/Travelling_salesman_problem): finding a good permutation r1,…,rn that produces the minimum R, and a good permutation c1,…,cn that produces the minimum C. At the end, by summing R+C we got the beauty for a fixed excluded row and column for the matrix a.

Time complexity: O((n+1)(m+1)22m+1+(m+1)(n+1)22n+1), or just O(n32n).

 **Code (C++)**
```cpp
#include <bits/stdc++.h>
using namespace std;
 
const int N = 16;
 
int n, m;
int a[N][N];
 
int fr[N][N], fc[N][N];
int w[N][N], dp[N][1<<N];
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int t;
    cin >> t;
 
    while (t--) {
        cin >> n >> m;
 
        for (int i = 0; i <= n; i++) a[i][m] = 0;
        for (int j = 0; j <= m; j++) a[n][j] = 0;
 
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a[i][j];
                a[i][m] ^= a[i][j];
                a[n][j] ^= a[i][j];
                a[n][m] ^= a[i][j];
            }
        }
 
        int fullmask_n = (1 << (n+1)) - 1;
        int fullmask_m = (1 << (m+1)) - 1;
 
        for (int rmv = 0; rmv <= m; rmv++) {
            for (int i = 0; i <= n; i++) {
                for (int j = i + 1; j <= n; j++) {
                    w[i][j] = 0;
                    for (int l = 0; l <= m; l++) {
                        if (rmv == l) continue;
                        w[i][j] += abs(a[i][l] - a[j][l]);
                    }
                    w[j][i] = w[i][j];
                }
            }
 
            for (int i = 0; i <= n; i++) {
                fill(dp[i], dp[i] + fullmask_n, INT_MAX);
                dp[i][1 << i] = 0;
            }
 
            for (int mask = 0; mask <= fullmask_n; mask++) {
                for (int last = 0; last <= n; last++) {
                    if (~mask >> last & 1) continue;
                    if (__builtin_popcount(mask) == n) continue;
 
                    for (int next = 0; next <= n; next++) {
                        if (mask >> next & 1) continue;
 
                        int new_mask = mask | 1 << next;
                        dp[next][new_mask] = min(
                            dp[next][new_mask],
                            dp[last][mask] + w[last][next]
                        );
                    }
                }
            }
 
            for (int i = 0; i <= n; i++) {
                fr[i][rmv] = INT_MAX;
                int mask = fullmask_n ^ 1 << i;
 
                for (int last = 0; last <= n; last++) {
                    fr[i][rmv] = min(fr[i][rmv], dp[last][mask]);
                }
            }
        }
 
        for (int rmv = 0; rmv <= n; rmv++) {
            for (int i = 0; i <= m; i++) {
                for (int j = i + 1; j <= m; j++) {
                    w[i][j] = 0;
                    for (int l = 0; l <= n; l++) {
                        if (rmv == l) continue;
                        w[i][j] += abs(a[l][i] - a[l][j]);
                    }
                    w[j][i] = w[i][j];
                }
            }
 
            for (int i = 0; i <= m; i++) {
                fill(dp[i], dp[i] + fullmask_m, INT_MAX);
                dp[i][1 << i] = 0;
            }
 
            for (int mask = 0; mask <= fullmask_m; mask++) {
                for (int last = 0; last <= m; last++) {
                    if (~mask >> last & 1) continue;
                    if (__builtin_popcount(mask) == m) continue;
 
                    for (int next = 0; next <= m; next++) {
                        if (mask >> next & 1) continue;
 
                        int new_mask = mask | 1 << next;
                        dp[next][new_mask] = min(
                            dp[next][new_mask],
                            dp[last][mask] + w[last][next]
                        );
                    }
                }
            }
 
            for (int i = 0; i <= m; i++) {
                fc[rmv][i] = INT_MAX;
                int mask = fullmask_m ^ 1 << i;
 
                for (int last = 0; last <= m; last++) {
                    fc[rmv][i] = min(fc[rmv][i], dp[last][mask]);
                }
            }
        }
 
        int ans = INT_MAX;
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                ans = min(ans, fr[i][j] + fc[i][j]);
            }
        }
 
        cout << ans << 'n';
    }
}
```
[1993F1 - Dyn-scripted Robot (Easy Version)](../problems/F1._Dyn-scripted_Robot_(Easy_Version).md "Codeforces Round 963 (Div. 2)")

 **Hint 1**Let the robot moves freely (no modification on the script).

 **Hint 2**The new path of the robot is the "mirrored" version of how the robot must go.

 **General idea**Imagine we have two robots, let's call them Alex and Bob. Alex is the one who follows the instruction well, but Bob doesn't (if he tries to move outside the box, he keeps going without modifying the script). Then, you follow the path of each robot that is moving. How do you think their paths differ from each other?

Yes! Suppose at some moment they reach the top side of the box at the same time. Suddenly, Bob wants to move up while Alex know the discipline and modify the script before executing the command and move down. Then, each of them is 1 unit away from the top side of the box. If Bob keeps moving up, Alex keep moving down. In case Bob changes his mind and move down then this time Alex changes her mind and move up.

What do we learn from this? They move like two objects facing each other through a mirror. Actually there are four mirror of them, placing at the four sides of the box.

Now, let's say Bob moves up so much that Alex follows the script and reaches the top side and the bottom side as well. Because of that, she has to change the script once again and start moving up like Bob.

When Alex reaches the bottom side at point (x,0), then Bob should be at point (x,2H) (prove it yourself!). If Bob keeps moving up to the point (x,4H),(x,6H),or(x,8H),…, at these moment Alex will also be at point (x,0). That being said, Alex's position is (x,0) then Bob's position must be (x,y) where y is a multiple of 2H.

This idea is exactly the same as if Bob were moving sideways (left or right). As we only care about the number of times Alex's position is (0,0), we know that if we don't change the script at all, the position of the robot must be (x,y) where x is a multiple of 2W, and y is a multiple of 2H.

 **Solution**So apparently, we need to calculate the number of times the robot reaches (x,y), where x is a multiple of 2W and y is a multiple of 2H (see the general idea above).

Let's call tk=(xk,yk) how much the robot moves (in direction) after executing the first k commands of the script. Then: t0=(0,0) and tk can be calculated through tk−1 and sk.

The robot will execute the script k times and the script contains n commands, so we have nk positions to check out. Each position can be represented by: (x,y)=itn+tj=(ixn+xj,iyn+yj) (where 0≤i≤k−1 and 1≤j≤n). Besides, we need:

 * x≡0(mod2W)⟹ixn+xj≡0(mod2W)⟹xj≡−ixn(mod2W)
* y≡0(mod2H)⟹iyn+yj≡0(mod2H)⟹yj≡−iyn(mod2H)

Lastly, we can traverse all possible i from 0 to k−1 and count the number of j that satisfies the above equivalence. One possible way to do this is to use a map to count each element in the array t1,t2,…,tn. Summing all the counts will give the answer for this problem.

Time complexity: O((n+k)logn)

 **Code (C++)**
```cpp
#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
const int N = 1e6 + 5;
 
string s;
ll n, k, w, h;
ll tx[2*N], ty[2*N];
map<pair<ll, ll>, ll> cnt;
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int t;
    cin >> t;
 
    while (t--) {
        cin >> n >> k >> w >> h >> s;
 
        cnt.clear();
        ll x = 0, y = 0;
 
        for (int i = 0; i < n; i++) {
            if (s[i] == 'L') x--;
            if (s[i] == 'R') x++;
            if (s[i] == 'D') y--;
            if (s[i] == 'U') y++;

            x = (x + 2*w) % (2*w);
            y = (y + 2*h) % (2*h);
            cnt[{x, y}]++;
        }
 
        ll ans = 0;
        for (int i = 0; i < k; i++) {
            ll vx = (-i*x%(2*w) + 2*w)%(2*w);
            ll vy = (-i*y%(2*h) + 2*h)%(2*h);
            ans += cnt[{vx, vy}];
        }

        cout << ans << 'n';
    }
}
```
[1993F2 - Dyn-scripted Robot (Hard Version)](../problems/F2._Dyn-scripted_Robot_(Hard_Version).md "Codeforces Round 963 (Div. 2)")

 **Solution**The idea of this version is almost the same as F1: counting the number of pairs (i,j) that satisfies:

 * ixn+xj≡0(mod2W), and
* iyn+yj≡0(mod2H)

However, as k is increased to 1012 we cannot brute-force the same way as the previous version. Luckily, there is a more efficient way. We need to modify these equivalences a bit:

 * ixn≡−xj(mod2W) (∗)
* iyn≡−yj(mod2H)

As we can see, these two equivalences have the same format ia≡b(modM). To solve this equivalence for i, one way to hang around is to divide a, b and M by gcd(a,M). If b is not divisible, there is no solution! Otherwise, we come up with: 

 i≡ba−1(modM)Where a−1 is the [modular inverse](https://codeforces.com/https://cp-algorithms.com/algebra/module-inverse.html) of a. We can always calculate it because the condition gcd(a,M)=1 is satisfied.

Let's define g=gcd(2W,xn), cx=−xjg(xng)−1 and W′=2Wg (similar for cy and H′). Then, the solutions of the equivalences at (∗) are:

 * i≡cx(modW′)
* i≡cy(modH′)

This system of equivalences can be solved using [Chinese Remainder Theorem](https://codeforces.com/blog/entry/61290). After some calculations, we come up with:

 * i=cx+zW′ (z is a non-negative integer).
* zW′≡cy−cx(modH′) (∗∗)

(∗∗) can be solved for z the same way as (∗). After that, calculte the number of z that satisfy i=cx+zW′≤k, sum it to the answer and we're done!

Time complexity: O(Nlog(W))

 **Code (C++)**
```cpp
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 1e6 + 5;


// Note that:
// inv(a, m) = a^(phi(m) - 1) 

ll mypow(ll a, ll n, ll mod) {
    ll res = 1;
    while (n) {
        if (n & 1) {
            res = res * a % mod;
        }
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

vector<int> primes;
bool is_composite[2 * N];
int phi[2 * N];

ll inv(ll a, ll mod) {
    return mypow(a, phi[mod] - 1, mod);
}

void precalc() {
    for (int i = 2; i < 2 * N; i++) {
        if (!is_composite[i]) {
            phi[i] = i - 1;
            primes.push_back(i);
        }
        for (int j : primes) {
            if (i * j >= 2 * N)
                break;
            is_composite[i * j] = true;
            if (i % j == 0) {
                phi[i * j] = phi[i] * j;
                break;
            } else {
                phi[i * j] = phi[i] * (j - 1);
            }
        }
    }
}

ll solve_mod(int a, int b, int M) {
    int g = gcd(a, M);
    if (b % g) return -1;

    a /= g; b /= g; M /= g;

    if (M == 1) return 0;
    return ((ll)b * inv(a, M)) % M;
}


// Main code goes here

string s;
ll n, K, W, H;
vector<pair<ll, ll>> p;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    precalc();

    while (t--) {
        cin >> n >> K >> W >> H >> s;
        K--;

        p.clear();
        ll xn = 0, yn = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == 'L') xn--;
            if (s[i] == 'R') xn++;
            if (s[i] == 'D') yn--;
            if (s[i] == 'U') yn++;
 
            xn = (xn + 2*W) % (2*W);
            yn = (yn + 2*H) % (2*H);
            p.emplace_back(xn, yn);
        }

        ll WW = 2 * W / gcd(2 * W, xn);
        ll HH = 2 * H / gcd(2 * H, yn);
        ll ans = 0, L = lcm(HH, WW);

        for (auto [xt, yt] : p) {
            if (xt) xt = 2 * W - xt;
            if (yt) yt = 2 * H - yt;

            auto kx = solve_mod(xn, xt, 2*W);
            auto ky = solve_mod(yn, yt, 2*H);
            if (kx == -1 || ky == -1)
                continue;

            ll rem = (ky - kx) % HH;
            if (rem < 0) rem += HH;
            
            int kk = solve_mod(WW, rem, HH);
            if (kk == -1) continue;

            ll a = kk * WW + kx;
            if (a <= K)
                ans += (K - a) / L + 1;
        }

        cout << ans << 'n';
    }
}
```
