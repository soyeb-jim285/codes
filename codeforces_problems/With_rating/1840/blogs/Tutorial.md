# Tutorial

[1840A - Cipher Shifer](../problems/A._Cipher_Shifer.md "Codeforces Round 878 (Div. 3)")

Idea: [isosto](https://codeforces.com/profile/isosto "Candidate Master isosto"), preparation: [isosto](https://codeforces.com/profile/isosto "Candidate Master isosto")

 **Tutorial**
### [1840A - Cipher Shifer](../problems/A._Cipher_Shifer.md "Codeforces Round 878 (Div. 3)")

Note that during encryption, only characters different from $c$ are added after the character $c$. However, when the character $c$ is encrypted with different characters, another $c$ character is added to the string.

This means that for decryption, we only need to read the characters of the string after $c$ until we find the first character equal to $c$. It signals the end of the block of characters that will be converted to the character $c$ during decryption.

To decrypt the entire string, we decrypt the first character $s_1$. Let the next occurrence of the character $s_1$ be at position $pos_1$. Then the next character of the original string is $s_{pos_1 + 1}$. We apply the same algorithm to find the next paired character and so on.

 **Solution**
```cpp
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string s; cin >> s;
        int i = 0;
        while (i < n) {
            int start = i;
            cout << s[i++];
            while (s[i++] != s[start]);
        }
        cout << endl;
    }
}
```
 **Rate the problem*** Didn't solve 


[*35*](https://codeforces.com/data/like?action=like "I like this")
* Good task 

 
[*452*](https://codeforces.com/data/like?action=like "I like this")
* Average task 

 
[*102*](https://codeforces.com/data/like?action=like "I like this")
* Bad task 

 
[*62*](https://codeforces.com/data/like?action=like "I like this")
[1840B - Binary Cafe](../problems/B._Binary_Cafe.md "Codeforces Round 878 (Div. 3)")

Idea: [diskoteka](https://codeforces.com/profile/diskoteka "Master diskoteka"), preparation: [diskoteka](https://codeforces.com/profile/diskoteka "Master diskoteka")

 **Tutorial**
### [1840B - Binary Cafe](../problems/B._Binary_Cafe.md "Codeforces Round 878 (Div. 3)")

On the one hand, if Tema had an infinite number of coins, he could buy any set of desserts offered in the coffee shop. This can be done in 2k ways, since each of the desserts can either be taken or not taken.

On the other hand, if the coffee shop offered an infinite number of desserts for tasting, Tema could spend any amount of coins he has - from 0 to n. Each number of coins corresponds to its unique set of desserts, since any number 0≤k≤n is uniquely represented as a sum of powers of two.

Combining these two observations, we get the final answer - min(2k,n+1).

 **Solution**
```cpp
#include <bits/stdc++.h>
 
using namespace std;
 
int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        k = min(k, 30);
        cout << min(n, (1 << k) - 1) + 1 << "n";
    }
    return 0;
}
```
 **Rate the problem*** Didn't solve 

 
[*203*](https://codeforces.com/data/like?action=like "I like this")
* Good task 

 
[*515*](https://codeforces.com/data/like?action=like "I like this")
* Average task 

 
[*63*](https://codeforces.com/data/like?action=like "I like this")
* Bad task 

 
[*629*](https://codeforces.com/data/like?action=like "I like this")
[1840C - Ski Resort](../problems/C._Ski_Resort.md "Codeforces Round 878 (Div. 3)")

Idea: [pavlekn](https://codeforces.com/profile/pavlekn "Master pavlekn"), preparation: [playerr17](https://codeforces.com/profile/playerr17 "Expert playerr17")

 **Tutorial**
### [1840C - Ski Resort](../problems/C._Ski_Resort.md "Codeforces Round 878 (Div. 3)")

To simplify the task, let's replace all numbers in the array a. If the value of ai is greater than q, then replace it with 0. Otherwise, replace it with 1.

Now Dima can go on this day if ai=1. Therefore, we need to consider segments consisting only of 1.

Note that if the segment consists of less than k ones, then Dima will not be able to go on these dates, so the segment can be ignored.

For all remaining segments, we need to calculate the number of ways for Dima to choose travel dates on this segment. And for a segment of length l, the number of ways to choose a trip of at least length k is (l−k+2l−k).

The answer to the problem will be the sum of the number of ways to choose travel dates for all segments.

 **Solution**
```cpp
testCases = int(input())
 
for testCase in range(testCases):
    n, k, q = map(int, input().split(' '))
    a = list(map(int, input().split(' ')))
    
    ans = 0
    len = 0
    for i in range(n):
        if a[i] <= q:
            len += 1
        else:
            if len >= k:
                ans += (len - k + 1) * (len - k + 2) // 2
            len = 0
    
    if len >= k:
        ans += (len - k + 1) * (len - k + 2) // 2
    print(ans)
```
 **Rate the problem*** Didn't solve 

 
[*66*](https://codeforces.com/data/like?action=like "I like this")
* Good task 

 
[*657*](https://codeforces.com/data/like?action=like "I like this")
* Average task 

 
[*109*](https://codeforces.com/data/like?action=like "I like this")
* Bad task 

 
[*42*](https://codeforces.com/data/like?action=like "I like this")
[1840D - Wooden Toy Festival](../problems/D._Wooden_Toy_Festival.md "Codeforces Round 878 (Div. 3)")

Idea: [diskoteka](https://codeforces.com/profile/diskoteka "Master diskoteka"), preparation: [diskoteka](https://codeforces.com/profile/diskoteka "Master diskoteka")

 **Tutorial**
### [1840D - Wooden Toy Festival](../problems/D._Wooden_Toy_Festival.md "Codeforces Round 878 (Div. 3)")

Let the carvers choose patterns x1, x2, x3 for preparation. For definiteness, let us assume that x1≤x2≤x3, otherwise we will renumber the carvers.

When a person comes to the workshop with a request to make a toy of pattern p, the best solution is to give his order to the carver for whom |xi−p| is minimal.

It follows that the first cutter will take orders for toys with patterns from 1 to x1+x22, the second - for toys with patterns from x1+x22 to x2+x32, the third - for toys with patterns from x2+x32 to 109. Therefore, if you look at the sorted array of patterns a, the first carver will make some prefix of toys, the third will make some suffix, and the remaining toys will be made by the second carver.

Then the answer can be found by binary search. To check if the time t is suitable, you need to give the maximum prefix of toys to the first carver and the maximum suffix of toys to the third carver, and then check that the patterns of the remaining toys are within a segment of length 2⋅t. The maximum prefix and maximum suffix can be found with a O(n) pass through the array a.

 **Solution**
```cpp
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        int l = -1, r = 1e9;
        while (r - l > 1) {
            int m = (l + r) >> 1;
            int i = 0;
            while (i + 1 < a.size() && a[i + 1] - a[0] <= 2 * m) {
                ++i;
            }
            int j = n - 1;
            while (j - 1 >= 0 && a.back() - a[j - 1] <= 2 * m) {
                --j;
            }
            ++i; --j;
            if (i > j || a[j] - a[i] <= 2 * m) {
                r = m;
            } else {
                l = m;
            }
        }
        cout << r << "n";
    }
    return 0;
}
```
 **Rate the problem*** Didn't solve 

 
[*273*](https://codeforces.com/data/like?action=like "I like this")
* Good task 

 
[*608*](https://codeforces.com/data/like?action=like "I like this")
* Average task 

 
[*32*](https://codeforces.com/data/like?action=like "I like this")
* Bad task 

 
[*65*](https://codeforces.com/data/like?action=like "I like this")
[1840E - Character Blocking](../problems/E._Character_Blocking.md "Codeforces Round 878 (Div. 3)")

Idea: [diskoteka](https://codeforces.com/profile/diskoteka "Master diskoteka"), preparation: [diskoteka](https://codeforces.com/profile/diskoteka "Master diskoteka")

 **Tutorial**
### [1840E - Character Blocking](../problems/E._Character_Blocking.md "Codeforces Round 878 (Div. 3)")

Two strings are equal if and only if there is no position pos such that the characters at position pos are not blocked and s1[pos]≠s2[pos] (we will call such a position bad). We will use this observation to maintain the current number of bad positions, denoted by cnt.

Let Ipos be an indicator variable. Ipos=1 if position pos is bad, otherwise Ipos=0.

During an operation (blocking or swapping), we only need to subtract the indicator variables of all positions affected by the operation from cnt. There will be O(1) of them. Then, we modify the string according to the operation and add new indicator variables to cnt.

To correctly handle blocking queries, or more precisely, to unblock positions in time, we will use a queue. After each blocking query, we will add a pair of numbers to the queue. The first number of the pair is the position to unblock, and the second number is the time to unblock. Now, before each operation, we will unblock positions by looking at the head of the queue.

 **Solution**
```cpp
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    int x;
    cin >> x;
    while (x--) {
        vector<string> s(2);
        cin >> s[0] >> s[1];
        int n = s[0].size();
        int bad = 0;
        for (int i = 0; i < n; ++i) {
            if (s[0][i] != s[1][i]) {
                ++bad;
            }
        }
        int t, q;
        cin >> t >> q;
        queue<pair<int, int>> unblock;
        for (int i = 0; i < q; ++i) {
            while (!unblock.empty() && unblock.front().first == i) {
                if (s[0][unblock.front().second] != s[1][unblock.front().second]) {
                    ++bad;
                }
                unblock.pop();
            }
            int type;
            cin >> type;
            if (type == 1) {
                int pos;
                cin >> pos;
                if (s[0][pos - 1] != s[1][pos - 1]) {
                    --bad;
                }
                unblock.emplace(i + t, pos - 1);
            } else if (type == 2) {
                int num1, pos1, num2, pos2;
                cin >> num1 >> pos1 >> num2 >> pos2;
                --num1; --pos1; --num2; --pos2;
                if (s[num1][pos1] != s[1 ^ num1][pos1]) {
                    --bad;
                }
                if (s[num2][pos2] != s[1 ^ num2][pos2]) {
                    --bad;
                }
                swap(s[num1][pos1], s[num2][pos2]);
                if (s[num1][pos1] != s[1 ^ num1][pos1]) {
                    ++bad;
                }
                if (s[num2][pos2] != s[1 ^ num2][pos2]) {
                    ++bad;
                }
            } else {
                cout << (!bad ? "YES" : "NO") << "n";
            }
        }
    }
    return 0;
}
```
 **Rate the problem*** Didn't solve 

 
[*81*](https://codeforces.com/data/like?action=like "I like this")
* Good task 

 
[*295*](https://codeforces.com/data/like?action=like "I like this")
* Average task 

 
[*46*](https://codeforces.com/data/like?action=like "I like this")
* Bad task 

 
[*39*](https://codeforces.com/data/like?action=like "I like this")
[1840F - Railguns](../problems/F._Railguns.md "Codeforces Round 878 (Div. 3)")

Idea: [diskoteka](https://codeforces.com/profile/diskoteka "Master diskoteka"), preparation: [diskoteka](https://codeforces.com/profile/diskoteka "Master diskoteka")

 **Tutorial**
### [1840F - Railguns](../problems/F._Railguns.md "Codeforces Round 878 (Div. 3)")

Let's first solve it in O(nmt).

This can be done using dynamic programming. dp[i][j][k]=true if the character can be at coordinates (i,j) at time t, otherwise dp[i][j][k]=false. Such dynamics can be easily recalculated: dp[i][j][k]=dp[i−1][j][k−1]|dp[i][j−1][k−1]|dp[i][j][k−1]. If the cell is shot by one of the railguns at time t, then dp[i][j][k]=false.

Now let's notice that if the character can reach the final point (n,m), then he will have to stand still no more than r times. To prove this, we can prove another statement: if the character can reach the final point along some trajectory, then for any such trajectory the character can stand still no more than r times. And this statement can already be proven by mathematical induction.

Thus, instead of the dp[n][m][t] dynamics, we can calculate the dp[n][m][r] dynamics, where the third parameter is the number of times the character stood still. The transitions here are made similarly.

 **Solution**
```cpp
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int q;
    cin >> q;
    while (q--) {
        int n, m;
        cin >> n >> m;
        int r;
        cin >> r;
        bool free[n + 1][m + 1][r + 1];
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= m; ++j) {
                for (int k = 0; k <= r; ++k) {
                    free[i][j][k] = true;
                }
            }
        }
        for (int i = 0; i < r; ++i) {
            int t, d, coord;
            cin >> t >> d >> coord;
            if (d == 1) {
                for (int j = 0; j <= m; ++j) {
                    if (0 <= t - coord - j && t - coord - j <= r) {
                        free[coord][j][t - coord - j] = false;
                    }
                }
            } else {
                for (int j = 0; j <= n; ++j) {
                    if (0 <= t - coord - j && t - coord - j <= r) {
                        free[j][coord][t - coord - j] = false;
                    }
                }
            }
        }
        bool dp[n + 1][m + 1][r + 1];
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= m; ++j) {
                for (int k = 0; k <= r; ++k) {
                    dp[i][j][k] = !(i || j || k);
                    if (free[i][j][k]) {
                        if (i && dp[i - 1][j][k]) {
                            dp[i][j][k] = true;
                        }
                        if (j && dp[i][j - 1][k]) {
                            dp[i][j][k] = true;
                        }
                        if (k && dp[i][j][k - 1]) {
                            dp[i][j][k] = true;
                        }
                    }
                }
            }
        }
        int ans = -1;
        for (int t = r; t >= 0; --t) {
            if (dp[n][m][t]) {
                ans = n + m + t;
            }
        }
        cout << ans << "n";
    }
    return 0;
}
```
 **Rate the problem*** Didn't solve 

 
[*106*](https://codeforces.com/data/like?action=like "I like this")
* Good task 

 
[*112*](https://codeforces.com/data/like?action=like "I like this")
* Average task 

 
[*7*](https://codeforces.com/data/like?action=like "I like this")
* Bad task 

 
[*64*](https://codeforces.com/data/like?action=like "I like this")
[1840G1 - In Search of Truth (Easy Version)](../problems/G1._In_Search_of_Truth_(Easy_Version).md "Codeforces Round 878 (Div. 3)")

Idea: [pavlekn](https://codeforces.com/profile/pavlekn "Master pavlekn"), preparation: [pavlekn](https://codeforces.com/profile/pavlekn "Master pavlekn")

 **Tutorial**
### [1840G1 - In Search of Truth (Easy Version)](../problems/G1._In_Search_of_Truth_(Easy_Version).md "Codeforces Round 878 (Div. 3)")

Let a1,a2,…,an be the numbers of the sectors in clockwise order, and let the arrow initially point to the sector with number a1.

First, let's make 999 queries of "+ 1", then we will know the numbers of 1000 consecutive sectors. If n<1000, then the number of the first query that gives the answer a1 is the desired n.

If we did not find n, this means that n≥1000. Let's save a1,a2,…,a1000. Now we will make queries of "+ 1000" until we get one of the numbers a1,a2,…,a1000 as the answer. Note that we will need no more than 1000 queries of this type, after which it is easy to determine the number n.

Thus, we can determine the number n in no more than 999+1000=1999≤2023 queries.

 **Solution**
```cpp
#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
 
const int MAXN = 1e6 + 7;
 
int pos[MAXN];
 
int32_t main() {
    int num;
    cin >> num;
    int ans = 0;
    int cur = 1;
    pos[num] = 1;
    for (int i = 0; i < 1000; ++i) {
        cout << '+' << " " << 1 << endl;
        ++cur;
        cin >> num;
        if (pos[num]) {
            cout << '!' << " " << cur - pos[num] << endl;
            return 0;
        }
        pos[num] = cur;
    }
    while (true) {
        cout << '+' << " " << 1000 << endl;
        cur += 1000;
        cin >> num;
        if (pos[num]) {
            cout << '!' << " " << cur - pos[num] << endl;
            return 0;
        }
        pos[num] = cur;
    }
    return 0;
}
```
 **Rate the problem*** Didn't solve 

 
[*53*](https://codeforces.com/data/like?action=like "I like this")
* Good task 

 
[*219*](https://codeforces.com/data/like?action=like "I like this")
* Average task 

 
[*6*](https://codeforces.com/data/like?action=like "I like this")
* Bad task 

 
[*13*](https://codeforces.com/data/like?action=like "I like this")
[1840G2 - In Search of Truth (Hard Version)](../problems/G2._In_Search_of_Truth_(Hard_Version).md "Codeforces Round 878 (Div. 3)")

Idea: [pavlekn](https://codeforces.com/profile/pavlekn "Master pavlekn"), preparation: [pavlekn](https://codeforces.com/profile/pavlekn "Master pavlekn")

 **Tutorial**
### [1840G2 - In Search of Truth (Hard Version)](../problems/G2._In_Search_of_Truth_(Hard_Version).md "Codeforces Round 878 (Div. 3)")

Let's sample n by making k random queries "+ x" where we pick x each time randomly between 1 and 106 and get k random integers n1,n2,…,nk in the range [1,n] as the answers to the queries. Then, we can sample n with n0=max(n1,n2,…,nk). Now, we can assume that n0≤n≤n0+d for some integer d. Let's talk about picking the right d a bit later.

Now we can perform an algorithm similar to G1 solution and determine n within 2⋅√d queries. 

So, we have 1000 queries in total, meaning that 2⋅√d+k is approximately equals to 1000. Thus, for each k we can find optimal d=1000−k2, the probability that n is not in the range [n0,n0+d] does not exceed (n−dn)k which is less than 8.5⋅10−18 for k=320 and for each 1≤n≤106.

Therefore, by picking k somewhere between 300 and 400, we can get a solution which passes a testcase with probability of p≥1−10−16.

 **Solution**
```cpp
#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
 
const int MAXN = 1e6 + 7;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
int pos[MAXN];
 
const int K = 400;
const int T = 300;
 
int get() {
    return rng() % MAXN;
}
 
int32_t main() {
    int num;
    cin >> num;
    int start = num;
    int cur_delta = 0;
    int N0 = num;
    for (int i = 0; i < K; ++i) {
        int delta = get();
        cout << '+' << " " << delta << endl;
        cur_delta += delta;
        cin >> num;
        N0 = max(N0, num);
    }
    cout << '-' << " " << cur_delta << endl;
    cin >> num;
    cout << '+' << " " << N0 - 1 << endl;
    cur_delta = N0 - 1;
    cin >> num;
    pos[num] = N0;
    for (int i = 0; i < T; ++i) {
        ++cur_delta;
        cout << '+' << " " << 1 << endl;
        cin >> num;
        pos[num] = N0 + i + 1;
        if (num == start) {
            cout << '!' << " " << N0 + i << endl;
            return 0;
        }
    }
    cout << '-' << " " << cur_delta << endl;
    cin >> num;
    int ans = 0;
    while (true) {
        cout << '-' << " " << T << endl;
        ans += T;
        cin >> num;
        if (pos[num]) {
            cout << '!' << " " << ans + pos[num] - 1 << endl;
            return 0;
        }
    }
    return 0;
}
```
 **Rate the problem*** Didn't solve 

 
[*65*](https://codeforces.com/data/like?action=like "I like this")
* Good task 

 
[*131*](https://codeforces.com/data/like?action=like "I like this")
* Average task 

 
[*4*](https://codeforces.com/data/like?action=like "I like this")
* Bad task 

 
[*39*](https://codeforces.com/data/like?action=like "I like this")
