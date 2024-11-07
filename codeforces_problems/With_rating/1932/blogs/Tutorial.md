# Tutorial

[1932A - Thorns and Coins](../problems/A._Thorns_and_Coins.md "Codeforces Round 927 (Div. 3)")

Idea: [denk](https://codeforces.com/profile/denk "Expert denk")

 **Tutorial**
### [1932A - Thorns and Coins](../problems/A._Thorns_and_Coins.md "Codeforces Round 927 (Div. 3)")

Let's move forward by 1 if the next cell does not have spikes, and by 2 otherwise. By doing so, we will visit all spike-free cells that we can reach, and thus collect all the coins in those cells. Note that if we are in cell i, and cells i+1 and i+2 have spikes, then we can only jump into the spikes and thus end the game.

Therefore, we need to count how many coins appear in the string before the substring "**".

 **Solution**
```cpp
#include <bits/stdc++.h>
 
using namespace std;
 
signed main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
 
    int t;
    cin >> t;
    for(int _ = 0; _ < t; ++_){
        int n, ans = 0;
        cin >> n;
        string s;
        cin >> s;
        for (int i = 1; i < n; i++) {
            ans += (s[i] == '@');
            if (s[i] == '*' && s[i - 1] == '*')
                break;
        }
        cout << ans << "n";
    }
    return 0;
}
```
[1932B - Chaya Calendar](../problems/B._Chaya_Calendar.md "Codeforces Round 927 (Div. 3)")

Idea: [Vladosiya](https://codeforces.com/profile/Vladosiya "Expert Vladosiya")

 **Tutorial**
### [1932B - Chaya Calendar](../problems/B._Chaya_Calendar.md "Codeforces Round 927 (Div. 3)")

The tribe will wait for the first sign in year a1. They will expect the second event in some year x>a1, which is divisible by a2, this will happen after a2−a1moda2 years. 

Let's maintain the number cur of the year in which the i-th sign occurred, then the (i+1)-th will occur in the year cur+ai+1−curmodai+1. Since this is the smallest year number divisible by ai+1, which is strictly greater than cur.

 **Solution**
```cpp
def solve():
    n = int(input())
    a = [int(x) for x in input().split()]
    cur = 0
    for e in a:
        cur += e - cur % e
    print(cur)
 
 
for _ in range(1, int(input()) + 1):
    solve()
```
[1932C - LR-remainders](../problems/C._LR-remainders.md "Codeforces Round 927 (Div. 3)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1932C - LR-remainders](../problems/C._LR-remainders.md "Codeforces Round 927 (Div. 3)")

If we perform all deletions except the last one, only one element will remain. Let's find its index in the array.

Now we will perform the operations in reverse order, then the deletion operations will become additions, which are much easier to maintain. We will store the remainder of the division of the product of the current segment by m and multiply by the new elements when extending the segment. We will output all the obtained numbers in reverse order.

 **Solution**
```cpp
#include <bits/stdc++.h>
 
using namespace std;
 
#define forn(i, n) for (int i = 0; i < int(n); i++)
 
int main() {
    int t;
    cin >> t;
    forn(tt, t) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        forn(i, n)
            cin >> a[i];
        string s;
        cin >> s;
 
        int l = 0;
        int r = n - 1;
        forn(i, n - 1)
            if (s[i] == 'L')
                l++;
            else
                r--;
        assert(l == r);
 
        vector<int> b(n);
        b[n - 1] = a[l] % m;
 
        for (int i = n - 2; i >= 0; i--) {
            if (s[i] == 'L')
                b[i] = (b[i + 1] * a[--l]) % m;
            else
                b[i] = (b[i + 1] * a[++r]) % m;
        }
        assert(l == 0);
        assert(r == n - 1);
 
        forn(i, n)
            cout << b[i] << " ";
        cout << endl;
    }
}
```
[1932D - Card Game](../problems/D._Card_Game.md "Codeforces Round 927 (Div. 3)")

Idea: [goncharovmike](https://codeforces.com/profile/goncharovmike "Candidate Master goncharovmike")

 **Tutorial**
### [1932D - Card Game](../problems/D._Card_Game.md "Codeforces Round 927 (Div. 3)")

Let's start by solving the problem separately for each suit, except for the trump suit. To do this, we will form the maximum possible number of pairs, after which there will be no more than one card of this suit without a pair. Thus, we will need the minimum number of trump cards to beat the non-trump cards.

Now we will beat each of the remaining cards with a trump. If there are not enough trump cards, there is no solution.

All that remains is to solve the problem for the remaining trumps, just as at the beginning of the solution. Note that since the total number of cards is even, and the rest of cards are paired, there will be no extra trump card left.

 **Solution**
```cpp
#include <bits/stdc++.h>
 
#define long long long int
#define DEBUG
using namespace std;
 
// @author: pashka
 
int main() {
    ios::sync_with_stdio(false);
    
    int t;
    cin >> t;
    for (int tt = 0; tt < t; tt++) {
        int n;
        cin >> n;
    
        string suites = "CDHS";
    
        string ts;
        cin >> ts;
        int trump = suites.find(ts[0]);
    
        vector<int> bs[4];
        for (int i = 0; i < 2 * n; i++) {
            string s;
            cin >> s;
            bs[suites.find(s[1])].push_back(s[0] - '2');
        }
    
        vector<string> res;
        vector<string> left;
        for (int i = 0; i < 4; i++) {
            sort(bs[i].begin(), bs[i].end());
            if (i == trump) continue;
            if (bs[i].size() % 2 == 1) {
                int x = bs[i].back();
                left.push_back(string() + char('2' + x) + suites[i]);
                bs[i].pop_back();
            }
            for (int j = 0; j < (int) bs[i].size(); j++) {
                int x = bs[i][j];
                res.push_back(string() + char('2' + x) + suites[i]);
            }
        }
        if (left.size() > bs[trump].size()) {
            cout << "IMPOSSIBLEn";
        } else {
            for (string s : left) {
                res.push_back(s);
                int x = bs[trump].back();
                bs[trump].pop_back();
                res.push_back(string() + char('2' + x) + suites[trump]);
            }
            for (int j = 0; j < (int) bs[trump].size(); j++) {
                int x = bs[trump][j];
                res.push_back(string() + char('2' + x) + suites[trump]);
            }
            for (int i = 0; i < 2 * n; i += 2) {
                cout << res[i] << " " << res[i + 1] << "n";
            }
        }
    }
}
```
[1932E - Final Countdown](../problems/E._Final_Countdown.md "Codeforces Round 927 (Div. 3)")

Idea: [step_by_step](https://codeforces.com/profile/step_by_step "International Grandmaster step_by_step")

 **Tutorial**
### [1932E - Final Countdown](../problems/E._Final_Countdown.md "Codeforces Round 927 (Div. 3)")

Let's assume that the number s is initially displayed on the countdown. Let's see how many times each of the indicators will switch. Indicator number i (if we number the indicators from right to left, starting with 0) will switch exactly ⌊s/10i⌋ times. Thus, the answer is equal to ∑n−1i=0⌊s/10i⌋.

To calculate this sum, let's split the number s into individual digits and add their contributions. Let the digits of the number s be sn−1sn−2…s0. The contribution of the digit si to the final sum is si⋅∑ij=010j. Thus, the answer is equal to ∑n−1i=0si⋅∑ij=010j. Changing the order of summation, we get ∑n−1j=010j⋅∑n−1j=isi.

To calculate this sum, we need to pre-calculate the suffix sums ∑n−1j=isi (this can be done in linear time), and then add each of the sums to the corresponding decimal digit of the final number, carrying over to the higher digits (this can also be done in linear time).

 **Solution**
```cpp
#include <bits/stdc++.h>
#define long long long int
#define DEBUG
using namespace std;
 
// @author: pashka
 
int main() {
    ios::sync_with_stdio(false);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        reverse(s.begin(), s.end());
        vector<int> a(n + 1);
        for (int i = n - 1; i >= 0; i--) {
            a[i] = a[i + 1] + (s[i] - '0');
        }
        string res;
        int c = 0;
        for (int i = 0; i < n; i++) {
            c += a[i];
            res += (char)(c % 10 + '0');
            c /= 10;
        }
        res += (char)(c + '0');
        while (res.back() == '0') {
            res.pop_back();
        }
        reverse(res.begin(), res.end());
        cout << res << "n";
    }
 
    return 0;
}
```
[1932F - Feed Cats](../problems/F._Feed_Cats.md "Codeforces Round 927 (Div. 3)")

Idea: [denk](https://codeforces.com/profile/denk "Expert denk")

 **Tutorial**
### [1932F - Feed Cats](../problems/F._Feed_Cats.md "Codeforces Round 927 (Div. 3)")

Let's use dynamic programming. Let dpi be the answer for the first i moves (dp0=0). Then there are two possible cases: we fed the cats on step i or not.

If we did not feed the cats on step i, then dpi=dpi−1, because this is the best result for the first i−1 moves, and nothing has changed on this move.

If we fed the cats on step i, then we could not have fed the cats later than when the first of the present cats arrived, because then it would overeat. Using the multiset structure, we will find the step x at which it arrived. In this case, we will feed all the present cats and can choose the best way to feed the cats for the first x−1 moves.

At each of the n moves, we will choose the best of the two options.

To maintain the multiset with the moments of the cats' arrivals, we will add them at these moments in time and remove them at the departure moments (for each r, we can store all li that will leave at that moment).

 **Solution**
```cpp
#include <bits/stdc++.h>
 
//#define int long long
#define pb emplace_back
#define mp make_pair
#define x first
#define y second
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
 
typedef long double ld;
typedef long long ll;
 
using namespace std;
 
mt19937 rnd(time(nullptr));
 
const ll inf = 1e18;
const ll M = 998244353;
const ld pi = atan2(0, -1);
const ld eps = 1e-6;
 
void solve(int tc){
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> a(m);
    vector<int> op(n + 1);
    vector<vector<int>> del(n + 1);
    for(auto &e: a) {
        cin >> e.x >> e.y;
        op[e.x]++;
        del[e.y].emplace_back(e.x);
    }
    multiset<int> cur;
    vector<int> dp(n + 1);
    for(int i = 1; i <= n; ++i){
        dp[i] = dp[i - 1];
        for(int j = 0; j < op[i]; ++j){
            cur.insert(i);
        }
        if(!cur.empty()){
            dp[i] = max(dp[i], int(dp[*cur.begin() - 1] + cur.size()));
        }
        for(int e: del[i]){
            cur.erase(cur.find(e));
        }
    }
    cout << dp[n];
}
 
bool multi = true;
 
signed main() {
    int t = 1;
    if (multi)cin >> t;
    for (int i = 1; i <= t; ++i) {
        solve(i);
        cout << "n";
    }
    return 0;
}
```
[1932G - Moving Platforms](../problems/G._Moving_Platforms.md "Codeforces Round 927 (Div. 3)")

Idea: [denk](https://codeforces.com/profile/denk "Expert denk")

 **Tutorial**
### [1932G - Moving Platforms](../problems/G._Moving_Platforms.md "Codeforces Round 927 (Div. 3)")

First, note that the event of two platforms being on the same level at a given moment does not depend on your moves. Hence, it is always optimal to get to any vertex you may need to reach the vertex n as soon as possible. It means that you can simply run Dijkstra's algorithm to calculate the minimal number of moves needed to reach every vertex.

The only complication is that you need to determine for some vertices u, v and moment t what is the next moment when l′u=l′v, i.e. find minimal k such that k≥t and lu+ksu=lv+ksvmodH. That can be equivalently written as lu−lv=k(sv−su)modH.

a=k′bmodH can be solved in such way: 

* If a is not divisible by gcd(H,b) then there is no solution.
* Otherwise, divide a,b,H by gcd(H,b). Name them a′,b′,H′.
* Then k′=b′−1a′modH.
* b′−1 can be found using extended Eucledian algorithm.

The only thing remaining is to find minimal k such that k′=kmodH′ and k≥t.

 **Solution**
```cpp
#include <bits/stdc++.h>
#define long long long int
#define DEBUG
using namespace std;
 
// @author: pashka
 
struct triple {
    long d, x, y;
};
 
triple eucl(long a, long b) {
    if (b == 0) {
        return {a, 1, 0};
    }
    long k = a / b;
    auto [d, x, y] = eucl(b, a - k * b);
    return {d, y, x - k * y};
}
 
struct test {
    void solve() {
        int n, m, H;
        cin >> n >> m >> H;
        vector<long> l(n);
        for (int i = 0; i < n; i++) cin >> l[i];
        vector<long> s(n);
        for (int i = 0; i < n; i++) cin >> s[i];
 
        vector<vector<int>> g(n);
        for (int i = 0; i < m; i++) {
            int x, y;
            cin >> x >> y;
            x--;
            y--;
            g[x].push_back(y);
            g[y].push_back(x);
        }
 
        const long INF = 1e18;
        vector<long> d(n, INF);
        d[0] = 0;
        set<pair<long, int>> q;
        q.insert({d[0], 0});
        while (!q.empty()) {
            auto p = *q.begin();
            q.erase(p);
            int v = p.second;
            long t = d[v];
            for (int u: g[v]) {
                long a = (l[v] + (t % H) * s[v]) - (l[u] + (t % H) * s[u]);
                a %= H;
                if (a < 0) a += H;
                long b = s[u] - s[v];
                b %= H;
                if (b < 0) b += H;
                // a - bx = yH
                auto [dd, x, y] = eucl(b, H);
                // xb + yH = dd
                if (a % dd != 0) continue;
                x *= a / dd;
                x %= (H / dd);
                if (x < 0) x += H / dd;
                long dt = x;
                if (d[v] + dt + 1 < d[u]) {
                    q.erase({d[u], u});
                    d[u] = d[v] + dt + 1;
                    q.insert({d[u], u});
                }
            }
        }
        long res = d[n - 1];
        if (res == INF) res = -1;
        cout << res << "n";
    }
};
 
int main() {
    ios::sync_with_stdio(false);
 
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        test().solve();
    }
    
    return 0;
}
```
