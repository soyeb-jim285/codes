# Tutorial

[1848A - Vika and Her Friends](../problems/A._Vika_and_Her_Friends.md "Codeforces Round 885 (Div. 2)")

Idea: [diskoteka](https://codeforces.com/profile/diskoteka "Candidate Master diskoteka")

 **Tutorial**
### [1848A - Vika and Her Friends](../problems/A._Vika_and_Her_Friends.md "Codeforces Round 885 (Div. 2)")

Let's color the halls of a rectangle in a chess coloring. Then Vika will be able to escape from her friends infinitely only if none of her friends is on a cell of the same color as Vika.

This observation seems intuitively clear, but let's formalize it.

⇐) It is true, because if initially Vika and her friend were in halls of different colors, then after one move they will remain in halls of different colors.

⇒) Let's choose any of the friends who is in a hall of the same color as Vika. We will show how the friend will act to catch Vika in a finite time. First, let's define a quantity that we will call the area to Vika: 

* If Vika and the friend are in the same column, then the area to Vika is equal to the sum of the areas of all rows in the direction of Vika and the row where the friend is located.
* If Vika and the friend are in the same row, then the area to Vika is equal to the sum of the areas of all columns in the direction of Vika and the column where the friend is located.
* Otherwise, the area to Vika is equal to the area of the quadrant in which Vika is located relative to the friend.

 Now let's notice that after each action, the friend can improve the next ordered pair: (Manhattan distance to Vika, area to Vika). * If Vika is in the same column as the friend. If Vika goes towards the friend, then the friend goes towards her, reducing the distance. If Vika goes in the opposite direction, then the friend also goes towards her, reducing the area to Vika. If Vika goes along the row, then the friend goes towards Vika along the column, which also reduces the area to Vika.
* If Vika is in the same row as the friend. If Vika goes towards the friend, then the friend goes towards her, reducing the distance. If Vika goes in the opposite direction, then the friend also goes towards her, reducing the area to Vika. If Vika goes along the column, then the friend goes towards Vika along the row, which also reduces the area to Vika.
* If Vika and the friend are in different rows and columns. If Vika goes towards the friend along the row, then the friend goes towards her along the column, reducing the distance. If Vika goes towards the friend along the column, then the friend goes towards her along the row, reducing the distance. If Vika goes away from the friend, then the friend makes a move in the same direction, thereby reducing the area to Vika.

 Since each of the quantities in the ordered pair cannot decrease infinitely many times, at some point the distance will become zero, which means a successful capture of Vika. **Solution**
```cpp
#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
 
int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        int x, y;
        cin >> x >> y;
        string ans = "YESn";
        for (int i = 0; i < k; ++i) {
            int xx, yy;
            cin >> xx >> yy;
            if ((x + y) % 2 == (xx + yy) % 2) {
                ans = "NOn";
            }
        }
        cout << ans;
    }
    return 0;
}
```
[1848B - Vika and the Bridge](../problems/B._Vika_and_the_Bridge.md "Codeforces Round 885 (Div. 2)")

Idea: [diskoteka](https://codeforces.com/profile/diskoteka "Candidate Master diskoteka")

 **Tutorial**
### [1848B - Vika and the Bridge](../problems/B._Vika_and_the_Bridge.md "Codeforces Round 885 (Div. 2)")

In a single linear pass through the array, let's calculate, for each color, the lengths of the two maximum steps between planks of that color. To do this, we will maintain when we last encountered that color.

Now we need to consider that we can repaint one of the planks. Let's say we repaint a plank in color c. It is easy to notice that we should repaint the plank in the middle of the longest step between planks of color c. After all, if we don't repaint such a plank, we will still have to make that longest step.

Therefore, the answer for a fixed color will be the maximum of two values: half the length of the longest step between planks of that color, and the length of the second largest step between planks of that color.

Knowing the answer for each individual color, we can determine the answer to the problem. To do this, we just need to take the minimum of the answers for all colors.

 **Solution**
```cpp
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> c(n);
        for (int i = 0; i < n; ++i) {
            cin >> c[i];
        }
        vector<int> last(k, -1);
        vector<int> max_step(k), max2_step(k);
        for (int i = 0; i < n; ++i) {
            int step = i - last[c[i] - 1];
            if (step > max_step[c[i] - 1]) {
                max2_step[c[i] - 1] = max_step[c[i] - 1];
                max_step[c[i] - 1] = step;
            } else if (step > max2_step[c[i] - 1]) {
                max2_step[c[i] - 1] = step;
            }
            last[c[i] - 1] = i;
        }
        for (int i = 0; i < k; ++i) {
            int step = n - last[i];
            if (step > max_step[i]) {
                max2_step[i] = max_step[i];
                max_step[i] = step;
            } else if (step > max2_step[i]) {
                max2_step[i] = step;
            }
        }
        int ans = 1e9;
        for (int i = 0; i < k; ++i) {
            ans = min(ans, max((max_step[i] + 1) / 2, max2_step[i]));
        }
        cout << ans - 1 << "n";
    }
    return 0;
}
```
[1848C - Vika and Price Tags](../problems/C._Vika_and_Price_Tags.md "Codeforces Round 885 (Div. 2)")

Idea: [pavlekn](https://codeforces.com/profile/pavlekn "Candidate Master pavlekn")

 **Tutorial**
### [1848C - Vika and Price Tags](../problems/C._Vika_and_Price_Tags.md "Codeforces Round 885 (Div. 2)")

First of all, if ai and bi are both zero, then all numbers in the sequence will be zero.

Otherwise, if one of the numbers ai,bi is not zero, then if ai≥bi, after one operation, the sum ai−bi+bi=ai will decrease relative to the original value, or if bi>ai, after two operations, the sum bi−ai+ai=bi will also decrease relative to the original value. Since the sum of non-negative integers cannot decrease infinitely, eventually one of the numbers ai,bi will become zero. Let the first such moment occur after cnti operations. Then, notice that now zeros will alternate with a period of 3. Therefore, in the problem, we need to check that all cnti have the same remainder when divided by 3. Thus, the problem reduces to finding cnti for each pair of non-zero ai,bi modulo 3.

Solution 1: Without loss of generality, assume ai≥bi, otherwise apply one operation. Then, the sequence of numbers will have the form: (ai,bi,ai−bi,ai−2⋅bi,bi,ai−3⋅bi,ai−4⋅bi,bi,…). Let ai=k⋅bi+r. Then, using simple formulas, we can find the first moment when the neighboring pair of numbers becomes r and bi in some order, and then simply find the answer for them. Thus, the problem can be solved using the generalized Euclidean algorithm.

Solution 2: We will build the sequence from the end. Let's find the first moment when we obtain 0. Before this zero, there is some number d. It can be easily proven that d is exactly equal to gcd(ai,bi). Now, let's divide each number in the sequence by d, and obtain a new sequence of numbers, where the last number is zero and the penultimate number is 1. Then, let's denote even numbers as 0 and odd numbers as 1. In this way, the sequence can be uniquely reconstructed from the end: (0,1,1,0,1,1,0,1,1,…). Thus, we can determine the remainder cnti modulo 3 by looking at the pair (ai/d,bi/d) modulo 2.

The complexity of both solutions will be O(n⋅logai).

 **Solution**
```cpp
#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
 
int gcd(int a, int b) {
    if (a == 0) {
        return 0;
    }
    if (b == 0) {
        return 1;
    }
    if (a >= b) {
        int r = a % b;
        int k = a / b;
        if (k % 2 == 1) {
            return gcd(b, r) + k + k / 2;
        } else {
            return gcd(r, b) + k + k / 2;
        }
    }
    return 1 + gcd(b, abs(a - b));
}
 
int calc(int a, int b) {
    if (a == 0) {
        return 0;
    }
    if (b == 0) {
        return 1;
    }
    return 1 + calc(b, abs(a - b));
}
 
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for (int _ = 0; _ < t; ++_) {
        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> b(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }
        set<int> cnt;
        for (int i = 0; i < n; ++i) {
            if (a[i] == 0 && b[i] == 0) {
                continue;
            }
            cnt.insert(gcd(a[i], b[i]) % 3);
        }
        if (cnt.size() <= 1) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
```
[1848D - Vika and Bonuses](../problems/D._Vika_and_Bonuses.md "Codeforces Round 885 (Div. 2)")

Idea: [diskoteka](https://codeforces.com/profile/diskoteka "Candidate Master diskoteka")

 **Tutorial**
### [1848D - Vika and Bonuses](../problems/D._Vika_and_Bonuses.md "Codeforces Round 885 (Div. 2)")

First, let's note that the optimal strategy for Vika will be to accumulate bonuses first and then only get the discount. This simple observation is proved by greedy considerations.

Next, let's note that the last digit of the bonus number will either become zero after a few actions (in which case it makes no sense for Vika to accumulate more bonuses), or it will cycle through the digits 2, 4, 8, 6.

To begin with, let's consider two options: whether Vika will accumulate bonuses at all or always choose the option to get the discount. In the second case, the answer is trivially calculated, but in the first case, we can use the above statement.

Now let's consider four options for the last digit. With a fixed last digit, we can simulate the first actions until we reach that last digit. Then we need to determine how many times we will "scroll" through the digits 2, 4, 8, 6 for the best result. Let's say that at the moment of obtaining the desired last digit, Vika has accumulated b bonuses and she can perform a more actions. Then, if the cycle is "scroll" x times, the discount will be (b+20⋅x)⋅(a−x). This is a parabola equation. Its maximum can be found using the formula for the vertex of a parabola or by ternary search.

 **Solution**
```cpp
#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
 
int f(int s, int k) {
    // (s + 20x) * (k - 4x)
    // (-80)x^2 + (20k - 4s)x + (sk)
    // -b/2a = (5k-s)/40
    int x = (5 * k - s) / 40;
    x = min(x, k / 4);
    int res = s * k;
    if (x > 0) {
        res = max(res, (s + 20 * x) * (k - 4 * x));
    }
    x = min(x + 1, k / 4);
    if (x > 0) {
        res = max(res, (s + 20 * x) * (k - 4 * x));
    }
    return res;
}
 
int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        int s, k;
        cin >> s >> k;
        int ans = s * k;
        if (s % 10 == 5) {
            ans = max(ans, (s + 5) * (k - 1));
        } else if (s % 10) {
            if (s % 2 == 1) {
                s += s % 10;
                --k;
            }
            for (int i = 0; i < 4; ++i) {
                if (k > 0) {
                    ans = max(ans, f(s, k));
                }
                s += s % 10;
                --k;
            }
        }
        cout << ans << "n";
    }
    return 0;
}
```
[1848E - Vika and Stone Skipping](../problems/E._Vika_and_Stone_Skipping.md "Codeforces Round 885 (Div. 2)")

Idea: [diskoteka](https://codeforces.com/profile/diskoteka "Candidate Master diskoteka")

 **Tutorial**
### [1848E - Vika and Stone Skipping](../problems/E._Vika_and_Stone_Skipping.md "Codeforces Round 885 (Div. 2)")

The key observation is that the answer for coordinate x is the number of odd divisors of x. Let's prove this.

Let's see how far a pebble will fly with force f, which touches the water cnt times: f+(f−1)+…+(f−cnt+1)=x. If cnt is even, then x=(cnt/2)⋅(2⋅f−cnt+1)=(p)⋅(2⋅k+1), where p=cnt/2,k=f−p. In this case, the condition f−cnt+1>0 is necessary, which is equivalent to p≤k.

If cnt is odd, then x=cnt⋅(f−(cnt−1)/2)=(2⋅k+1)⋅(p), where p=(f−(cnt−1)/2),k=(cnt−1)/2. Thus, the necessary condition f−cnt+1>0 is equivalent to p>k.

Therefore, for each odd divisor 2⋅k+1 of the number x, we can uniquely associate one of the decomposition options, and hence the number of possible answers is exactly equal to the number of different odd divisors in the factorization of the number x.

Using this observation, it is easy to obtain the answer. We will maintain the power of each prime number in the current coordinate. The answer is the product of (powers +1). In order to quickly understand how these quantities change, we will pre-calculate the factorization of all numbers from 1 to 106. Then the query can be processed by quickly recalculating the powers using the pre-calculated factorizations.

 **Solution**
```cpp
#include <bits/stdc++.h>
 
using namespace std;
 
const int K = 1e6;
 
#define int long long
 
int mod;
 
int dp[K + 1];
int cnt[K + 1];
 
const int MM = 3e6 + 7;
 
int inv[MM];
 
int cc = 0;
 
int mul(int a, int b) {
    int bb = b;
    while (bb % mod == 0) {
        ++cc;
        bb /= mod;
    }
    return (a * (bb % mod)) % mod;
}
 
int dv(int a, int b) {
    int bb = b;
    while (bb % mod == 0) {
        --cc;
        bb /= mod;
    }
    return (a * inv[bb % mod]) % mod;
}
 
 
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int x, q;
    cin >> x >> q >> mod;
    inv[1] = 1;
    for (int i = 2; i < MM && i < mod; i++) {
        inv[i] = mod - inv[mod % i] * (mod / i) % mod;
    }
    int y = x;
    for (int i = 3; i <= K; i += 2) {
        if (dp[i]) {
            continue;
        }
        for (int j = i; j <= K; j += 2 * i) {
            dp[j] = i;
        }
    }
    int ans = 1;
    while (x % 2 == 0) {
        x /= 2;
    }
    for (int i = 3; i <= K; i += 2) {
        while (x % i == 0) {
            ans = dv(ans, cnt[i] + 1);
            ++cnt[i];
            ans = mul(ans, cnt[i] + 1);
            x /= i;
        }
    }
    int f = 1;
    if (x > 1) {
        ans = mul(ans, 2);
    }
    x = y;
    for (int i = 0; i < q; ++i) {
        int d;
        cin >> d;
        while (d % 2 == 0) {
            d /= 2;
        }
        int k = d;
        while (dp[k]) {
            ans = dv(ans, cnt[dp[k]] + 1);
            ++cnt[dp[k]];
            ans = mul(ans, cnt[dp[k]] + 1);
            k /= dp[k];
        }
        if (cc) {
            cout << 0 << 'n';
        } else {
            cout << ans << 'n';
        }
    }
    return 0;
}
```
[1848F - Vika and Wiki](../problems/F._Vika_and_Wiki.md "Codeforces Round 885 (Div. 2)")

Idea: [pavlekn](https://codeforces.com/profile/pavlekn "Candidate Master pavlekn")

 **Tutorial**
### [1848F - Vika and Wiki](../problems/F._Vika_and_Wiki.md "Codeforces Round 885 (Div. 2)")

Let's denote next(i,delta)=(i+deltamodn)+1, and a[cnt][i] represents the value of ai after cnt operations.

First, let's observe that if the array becomes all zeros, it will always remain all zeros. Therefore, we need to find the first moment in time when the array becomes all zeros.

Furthermore, let's see how the array looks like after 2t operations. We will prove by induction that a[2t][i]=a[0][i]⊕a[0][next(i,2t)] for each i. Indeed, for t=0, this is true by definition, and for t≥1:

a[2t][i]=a[2t−1][i]⊕a[2t−1][next(i,2t−1)]=a[0][i]⊕a[0][next(i,2t−1)]⊕a[0][next(i,2t−1)]⊕a[0][next(i,2t)]=a[0][i]⊕a[0][next(i,2t)].

Thus, a[n][i]=a[2k][i]=a[0][i]⊕a[0][next(i,n)]=a[0][i]⊕a[0][i]=0, which means that after n steps, the array becomes all zeros.

Now, we want to find the minimum number of operations c after which the array a becomes all zeros, knowing that c∈[0,n]. Let's check that c≤n/2, by explicitly constructing the array a[n/2][i]=a[0][i]⊕a[0][next(i,n/2)]. The condition c≤n/2 is equivalent to all elements of the array a[n/2][i] being zeros.

The algorithm can be summarized as follows:

Check if ai=anext(i,n/2) for each i. If this is true, find the answer for the prefix of the array a of length n/2. Otherwise, perform n/2 operations on the array a, specifically ai=ai⊕anext(i,n/2). Now, the array satisfies the condition ai=anext(i,n/2) for each i, so we only need to find the answer for its prefix of size n/2 and add n/2 to it.

The overall complexity of the solution is O(n).

 **Solution**
```cpp
#include <bits/stdc++.h>
 
using namespace std;
 
const int MAXN = (1 << 20);
 
int a[MAXN];
 
int solve(int n) {
    if (n == 1) {
        if (a[0] == 0) {
            return 0;
        } else {
            return 1;
        }
    }
    int fl = true;
    for (int i = 0; i < n / 2; ++i) {
        if (a[i] != a[i + n / 2]) {
            fl = false;
        }
    }
    if (fl) {
        return solve(n / 2);
    }
    for (int i = 0; i < n / 2; ++i) {
        a[i] ^= a[i + n / 2];
    }
    return n / 2 + solve(n / 2);
}
 
int32_t main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    cout << solve(n) << endl;
    return 0;
}
```
