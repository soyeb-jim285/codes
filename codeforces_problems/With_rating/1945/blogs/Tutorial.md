# Tutorial

[1945A - Setting up Camp](../problems/A._Setting_up_Camp.md "Codeforces Round 935 (Div. 3)")

Idea: [Kirill_Maglysh](https://codeforces.com/profile/Kirill_Maglysh "Expert Kirill_Maglysh")

 **Tutorial**
### [1945A - Setting up Camp](../problems/A._Setting_up_Camp.md "Codeforces Round 935 (Div. 3)")

First, let's consider introverts. Since each of them needs exactly one tent, we simply add a to the answer. Then let's consider extroverts. If their number is divisible by 3, we add b3 to the answer. Otherwise, we calculate d=3−bmod, where x \bmod y denotes the remainder from dividing x by y. If d > c, then there is no answer, as it is not possible to accommodate the extroverts in the tents. Otherwise, we subtract d from c and add \frac{c}{3} to the answer.

The general formula when there is an answer: a + \frac{b + d}{3} + \lceil\frac{c - d + 2}{3}\rceil.

Complexity: \mathcal{O}(1).

 **Solution**
```cpp
#include <iostream>

using namespace std;
using ll = long long;

void solve() {
    ll single, poly, uni;
    cin >> single >> poly >> uni;
    ll needPoly = (3 - poly % 3) % 3;
    if (poly > 0 && needPoly > uni) {
        cout << "-1n";
        return;
    }

    uni -= needPoly;
    poly += needPoly;

    ll mn = single + uni / 3 + (uni % 3 + 1) / 2 + poly / 3;
    cout << mn << 'n';
}

int32_t main() {
    ll T;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
```
[1945B - Fireworks](../problems/B._Fireworks.md "Codeforces Round 935 (Div. 3)")

Idea: [NToneE](https://codeforces.com/profile/NToneE "Master NToneE"), [Gadget](https://codeforces.com/profile/Gadget "Pupil Gadget")

 **Tutorial**
### [1945B - Fireworks](../problems/B._Fireworks.md "Codeforces Round 935 (Div. 3)")

Let's consider the moment in time T = \text{LCM}(a, b) ([least common multiple](https://codeforces.com/https://en.wikipedia.org/wiki/Least_common_multiple) of numbers a and b). It is easy to notice that since T > 0 and T is divisible by both a and b, at this moment both camps will release a firework, each of which will disappear after m + 1 minutes.

Let's look at the sky at the T + m-th minute. We will still see two fireworks released at the moment T, the first camp managed to release \lfloor\frac{m}{a}\rfloor fireworks, and the second, similarly, \lfloor\frac{m}{b}\rfloor fireworks (this follows from the fact that T is divisible by a and b). Taking into account the two fireworks released at the moment T, we will reach the answer \lfloor\frac{m}{a}\rfloor + \lfloor\frac{m}{b}\rfloor + 2.

Why can't we achieve a greater answer? Let's consider two setups for launching fireworks independently. Without loss of generality, consider the first setup (releasing fireworks every a minutes). Consider the moment when the fireworks from this setup are visible in the sky. Let the first firework among the visible ones disappear at the moment x, then at the moment x we will see no fewer fireworks, but at the moment x + 1 — fewer. At the moment x, there will be fireworks in the sky, released at moments [x, x + a, \dots, x + a \cdot \lfloor\frac{m}{a}\rfloor]. Thus, from the first setup, we can see no more than \lfloor\frac{m}{a}\rfloor + 1 fireworks simultaneously. The same formula is applicable to the second setup. We have proved that the answer does not exceed \lfloor\frac{m}{a}\rfloor + 1 + \lfloor\frac{m}{b}\rfloor + 1 = \lfloor\frac{m}{a}\rfloor + \lfloor\frac{m}{b}\rfloor + 2, so that is the answer.

Complexity: \mathcal{O}(1).

 **Solution**
```cpp
t = int(input())
for qi in range(t):
    a, b, m = [int(x) for x in  input().split()]
    ans = m // a + m // b + 2
    print(ans)
```
[1945C - Left and Right Houses](../problems/C._Left_and_Right_Houses.md "Codeforces Round 935 (Div. 3)")

Idea: [Gadget](https://codeforces.com/profile/Gadget "Pupil Gadget"), [NToneE](https://codeforces.com/profile/NToneE "Master NToneE")

 **Tutorial**
### [1945C - Left and Right Houses](../problems/C._Left_and_Right_Houses.md "Codeforces Round 935 (Div. 3)")

According to the statement, to the left of the road there should be no less elements a_i such that a_i = 0 than such that a_i = 1, and to the right of the road there should be no less elements a_i than such that a_i = 1 than such that a_i = 0.

We will consider each position of the road and check the compliance with the road design condition. To do this, we will use the prefix sum method to access the number of 1's in the suffix in \mathcal{O}(1) (the number of such i that i > x and a_i = 1 for any x). We will also maintain the count of 0's among the elements to the left of the road and the optimal answer. If the road position x is suitable and it is closer to the middle than the most optimal answer found before, we will update it (and will not forget to increase the count of 0 if the next element a_{x + 1} = 0).

It is convenient to double the distance to the middle of the village: instead of \left|\frac{n}{2} - i\right|, consider it as 2\left|\frac{n}{2} - i\right| = \left|n - 2\cdot i\right|. This way, we can get rid of calculations in non-integer numbers.

Complexity: \mathcal{O}(n)

 **Solution**
```cpp
for case in range(int(input())):
    n = int(input())
    a = input()
    suf_cnt = [0] * (n + 1)
    for i in range(n - 1, -1, -1):
        suf_cnt[i] = suf_cnt[i + 1] + (a[i] == '1')
    pref_cnt = 0
     
    opt_ans = -1
    opt_dist = n * 2
    threshold = (n + 1) // 2
     
    for i in range(n + 1):
        if pref_cnt >= (i + 1) // 2 and suf_cnt[i] >= (n - i + 1) // 2 and abs(n - 2 * i) < opt_dist:
            opt_dist = abs(n - 2 * i)
            opt_ans = i
        if i != n:
            pref_cnt += (a[i] == '0')
     
    print(opt_ans)

```
[1945D - Seraphim the Owl](../problems/D._Seraphim_the_Owl.md "Codeforces Round 935 (Div. 3)")

Idea: [Kirill_Maglysh](https://codeforces.com/profile/Kirill_Maglysh "Expert Kirill_Maglysh")

 **Tutorial**
### [1945D - Seraphim the Owl](../problems/D._Seraphim_the_Owl.md "Codeforces Round 935 (Div. 3)")

Let's consider a greedy approach. Suppose we are standing at position i. Find the first j such that j < i and a_j < b_j. If such j exists and j > m, then swap with j. This will be optimal, because in any case we will have to pay the people at positions i - 1, i - 2, \dots, j some amount of coins, and in this way we will pay each person at position k where i > k > j, b_k coins. According to the greedy condition b_k > a_k, so b_k is the minimum amount of coins we can pay k-th person. We will also pay the j-th person a_j coins. a_j < b_j, hence we will pay the minimum amount of coins to all people.

If such j does not exist, then it is advantageous for us to choose the final position f, such that 1 \le f \le m, in order to finish the movements and overpay as little as possible. Simply check each f, recalculating the answer using prefix sums on array b and choose the smallest one.

Asymptotics: \mathcal{O}(n).

 **Solution**
```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

void solve() {
    ll n, k;
    cin >> n >> k;
    vector<ll> A(n);
    for (auto& item : A) {
        cin >> item;
    }
    reverse(A.begin(), A.end());

    vector<ll> B(n);
    for (auto& item : B) {
        cin >> item;
    }
    reverse(B.begin(), B.end());

    ll bSum = 0;
    ll pref = 0;
    for (ll i = 0; i < n - k; ++i) {
        if (A[i] < B[i]) {
            pref += bSum;
            pref += A[i];
            bSum = 0;
        } else {
            bSum += B[i];
        }
    }

    ll res = 1e18;
    for (ll i = n - k; i < n; ++i) {
        res = min(res, pref + bSum + A[i]);
        bSum += B[i];
    }

    cout << res << 'n';
}

int32_t main() {
    ll testN;
    cin >> testN;
    while (testN--) {
        solve();
    }
    return 0;
}
```
[1945E - Binary Search](../problems/E._Binary_Search.md "Codeforces Round 935 (Div. 3)")

Idea: [Kirill_Maglysh](https://codeforces.com/profile/Kirill_Maglysh "Expert Kirill_Maglysh")

 **Tutorial**
### [1945E - Binary Search](../problems/E._Binary_Search.md "Codeforces Round 935 (Div. 3)")

In fact, the problem can be solved in a single operation.

Let's start a binary search on the initial permutation. We will get some index l. Then, it is enough to swap p_l and x. Now our binary search will stop exactly at the number x. Notice that in the search, any number less than or equal to x affects the result like x. Indeed, p_l \le x remains true if we replace p_l with x.

Note that if we swapped two numbers that give the same result in the condition of the binary search, then the final l will not change.

The previous statements assumed that p_l \le x. Indeed, in the algorithm description, after changing l, the number p_l cannot become greater than x. It is also necessary to consider the case when l = 1 after executing the algorithm. If l = 1, then at each iteration of the algorithm, p_m > x, in particular, this means that p_m was never equal to x. In this case, swapping p_1 and x will also not affect the result (l) of the binary search.

Complexity: \mathcal{O}(n).

 **Solution**
```cpp
#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> src(n);
    int P = 0;
    for (int i = 0; i < n; ++i) {
        cin >> src[i];
        if (src[i] == x) {
            P = i;
        }
    }

    int l = 0;
    int r = n;
    while (r - l > 1) {
        int m = (l + r) / 2;

        if (src[m] <= x) {
            l = m;
        } else {
            r = m;
        }
    }

    cout << "1n";
    cout << P + 1 << ' ' << l + 1 << 'n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}
```
[1945F - Kirill and Mushrooms](../problems/F._Kirill_and_Mushrooms.md "Codeforces Round 935 (Div. 3)")

Idea: [Kirill_Maglysh](https://codeforces.com/profile/Kirill_Maglysh "Expert Kirill_Maglysh")

 **Tutorial**
### [1945F - Kirill and Mushrooms](../problems/F._Kirill_and_Mushrooms.md "Codeforces Round 935 (Div. 3)")

Consider a fixed number k — the amount of mushrooms in the elixir. In this case, we need to maximize the minimum of the taken numbers. We will iterate through the numbers in descending order: until we collect k numbers, we iterate over the next number. If its index is greater than or equal to k, we take this number as the answer, otherwise we skip it.

If we iterate through k, we get a solution in \mathcal{O}(n^2) time. How can we speed it up? Notice that at incrementing k, only a few numbers change: v_{p_k} becomes zero, if we have already taken it, then we need to take the next one in descending order. Also, we need to take the next number in descending order, because we are incrementing k. After sorting, we can traverse the array in linear time. We keep a pointer j to the last taken element, as well as an array \text{used} — whether the i-th number is taken, and an array \text{zero} — whether the i-th number is turned into zero. Every time we move j, we check that \text{zero}_j = \text{false}, and if so, we take the number and set \text{used}_j = \text{true}.

Complexity: \mathcal{O}(n \log n).

 **Solution**
```cpp
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;
using ll = long long;

void solve() {
    ll n;
    cin >> n;
    vector<ll> src(n);
    vector<pair<ll, ll>> can(n);
    for (ll i = 0; i < n; ++i) {
        cin >> src[i];
        can[i] = {src[i], i};
    }

    vector<ll> ord(n);
    for (auto& item : ord) {
        cin >> item;
        --item;
    }

    sort(can.rbegin(), can.rend());
    ll best = can[0].first;
    ll take = 1;

    ll cur;
    ll P = 1;
    vector<bool> burn(n);
    vector<bool> used(n);
    used[can[0].second] = true;
    for (ll k = 0; k + 1 < n && P < n; ++k) {
        while (P < n && burn[can[P].second]) {
            ++P;
        }

        if (P == n) {
            break;
        }

        used[can[P].second] = true;
        cur = can[P].first;
        ++P;

        burn[ord[k]] = true;
        if (used[ord[k]]) {
            while (P < n && burn[can[P].second]) {
                ++P;
            }

            if (P == n) {
                break;
            }

            used[can[P].second] = true;
            cur = can[P].first;
            ++P;
        }

        if (best < cur * (k + 2)) {
            take = k + 2;
            best = cur * (k + 2);
        }
    }

    cout << best << ' ' << take << 'n';
}

int32_t main() {
    ll testN;
    cin >> testN;
    while (testN--) {
        solve();
    }
    return 0;
}
```
[1945G - Cook and Porridge](../problems/G._Cook_and_Porridge.md "Codeforces Round 935 (Div. 3)")

Idea: [Kirill_Maglysh](https://codeforces.com/profile/Kirill_Maglysh "Expert Kirill_Maglysh")

 **Tutorial**
### [1945G - Cook and Porridge](../problems/G._Cook_and_Porridge.md "Codeforces Round 935 (Div. 3)")

Let's divide the queue into two parts: the original queue \text{Q1} and the returning people queue \text{Q2}. \text{Q1} will simply be an array with a pointer P to the current person at the front. And \text{Q2} will be a priority queue. Now the problem can be formulated as follows: find out how much time it will take for P to become equal to n + 1.

Let's iterate through the time. At each moment, the cook serves porridge to either a person from \text{Q1} or from \text{Q2}. How do we know which one? Let's calculate \text{sufMax} — an array of suffix maximums for k. Now it's clear that if \text{sufMax}_P \le k(\text{Q2}_\text{front}) (here k(x) is the priority of student x), then there is still someone in \text{Q1} with a higher k than the one who wants to return, so at the next moment the cook will serve porridge to a person from \text{Q1}. Otherwise, the person with the maximum appetite from \text{Q2} can bypass everyone from \text{Q1} and get the porridge.

To form \text{Q2}, we will store an array of arrays \text{eat}, where \text{eat}_i is the list of people who will return to the queue at the end of the i-th minute.

Then we simply need to simulate this process. The answer will be the moment when P becomes equal to n + 1.

Complexity: \mathcal{O}(d \log n)

 **Solution**
```cpp
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using ll = long long;

const int MAX_N = 2e5;
const int MAX_D = 3e5;

struct Student {
    int k;
    int s;
    int tin = 0;

    bool operator<(const Student& other) const {
        if (k == other.k) {
            if (tin == other.tin) {
                return s > other.s;
            }
            return tin > other.tin;
        }
        return k < other.k;
    }
};

int n, D, x;
Student qu1[MAX_N];
int sufMax[MAX_N];
vector<Student> eat[MAX_D];

int check() {
    int origPos = 0;
    priority_queue<Student> qu2;
    for (int i = 0; i < D && origPos < n; ++i) {
        if (qu2.empty() || qu2.top().k <= sufMax[origPos]) {
            ll nxtTime = ll(i) + ll(x) * ll(qu1[origPos].s);
            if (nxtTime < D) {
                eat[nxtTime].push_back(qu1[origPos]);
            }

            ++origPos;
            if (origPos == n) {
                for (int tm = 0; tm < D; ++tm) {
                    eat[tm].clear();
                }

                return i + 1;
            }
        } else {
            ll nxtTime = ll(i) + ll(x) * ll(qu2.top().s);
            if (nxtTime < D) {
                eat[nxtTime].push_back(qu2.top());
            }
            qu2.pop();
        }

        for (const auto& student : eat[i]) {
            qu2.push({student.k, student.s, i});
        }
    }

    for (int i = 0; i < D; ++i) {
        eat[i].clear();
    }

    return -1;
}

void solve() {
    cin >> n >> D;
    x = 1;
    for (int i = 0; i < n; ++i) {
        cin >> qu1[i].k >> qu1[i].s;
    }

    sufMax[n - 1] = qu1[n - 1].k;
    for (int i = n - 2; i >= 0; --i) {
        sufMax[i] = max(qu1[i].k, sufMax[i + 1]);
    }

    cout << check() << 'n';
}

int32_t main() {
    ll testN;
    cin >> testN;
    while (testN--) {
        solve();
    }
    return 0;
}
```
[1945H - GCD is Greater](../problems/H._GCD_is_Greater.md "Codeforces Round 935 (Div. 3)")

Idea: [Kirill_Maglysh](https://codeforces.com/profile/Kirill_Maglysh "Expert Kirill_Maglysh")

 **Tutorial**
### [1945H - GCD is Greater](../problems/H._GCD_is_Greater.md "Codeforces Round 935 (Div. 3)")

Let's notice that it is sufficient to take the greatest common divisor (GCD) of two numbers. Indeed, suppose we take the GCD of a larger number of numbers. Then we can move one of them to the set of AND. Then the GCD will not decrease, and the AND will not increase.

Also, pre-calculate the number of ones in the given numbers and remember it.

Notice that if a certain bit y is equal to zero in more than two numbers, then in the AND of all these numbers bit y will also be zero. For all the bits that are equal to zero in no more than two numbers, we will save these numbers. We will iterate through each of these numbers as one of the red numbers, and iterate through the second one for n. This will require \mathcal{O}(2\cdot \log(\text{maxA}) \cdot \log(\text{maxA}) \cdot n) time. The additional logarithm comes from calculating the GCD for a pair of numbers. After this, we remove all such numbers from our list.

Let A be the bitwise AND of all the numbers in the initial array.

Now we can consider that the GCD should be greater than A + X.

We will iterate through the GCD from (A + X + 1) to maxA and check: if there is a pair of numbers in the array (not counting the discarded ones) that are divisible by it, then the answer is to color these numbers in red, and the rest in blue. Otherwise, if such a GCD is not found, the answer is "NO".

 **Solution**
```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int BITS = 20;
const int MAX_N = 4e5 + 10;
int n;
int x;

int src[MAX_N];

void coutYES(int fId, int sId) {
    cout << "YESn";
    cout << "2 " << src[fId] << ' ' << src[sId] << 'n';
    cout << n - 2 << ' ';
    for (int i = 0; i < n; i++) {
        if (i == fId || i == sId) {
            continue;
        }
        cout << src[i] << ' ';
    }
    cout << 'n';
}

void solve() {
    cin >> n >> x;
    vector<int> bitCnt[BITS];

    int maxA = 1;
    for (int i = 0; i < n; i++) {
        cin >> src[i];
        maxA = max(maxA, src[i] + 1);
        for (int bit = 0; bit < BITS; bit++) {
            if ((1 << bit) & src[i]) {
                continue;
            }

            bitCnt[bit].push_back(i);
        }
    }

    bool incr[n];
    int cnt[maxA];
    int divBy[maxA];
    for (int i = 0; i < maxA; ++i) {
        cnt[i] = 0;
        divBy[i] = 0;
    }

    int pref[n];
    int suf[n];
    for (int i = 0; i < n; i++) {
        incr[i] = false;
        pref[i] = src[i];
        if (i) {
            pref[i] = pref[i - 1] & src[i];
        }
    }

    for (int i = n - 2; i >= 0; i--) {
        suf[n - 1] = src[n - 1];
        if (i < n - 1) {
            suf[i] = suf[i + 1] & src[i];
        }
    }

    for (const auto& item : bitCnt) {
        if (item.size() <= 2) {
            for (const int& id : item) {
                incr[id] = true;
                int myAnd = -1;
                for (int j = id + 1; j < n; j++) {
                    int curAND = (1 << BITS) - 1;
                    if (j + 1 < n) curAND &= suf[j + 1];
                    if (id - 1 >= 0) curAND &= pref[id - 1];
                    if (myAnd != -1) curAND &= myAnd;

                    if (curAND + x < __gcd(src[id], src[j])) {
                        coutYES(id, j);
                        return;
                    }

                    if (myAnd == -1) {
                        myAnd = src[j];
                    } else {
                        myAnd &= src[j];
                    }
                }

                myAnd = -1;
                for (int j = id - 1; j >= 0; j--) {
                    int curAND = (1 << BITS) - 1;

                    if (j - 1 >= 0) curAND &= pref[j - 1];
                    if (id + 1 < n) curAND &= suf[id + 1];
                    if (myAnd != -1) curAND &= myAnd;

                    if (curAND + x < __gcd(src[id], src[j])) {
                        coutYES(id, j);
                        return;
                    }

                    if (myAnd == -1) {
                        myAnd = src[j];
                    } else {
                        myAnd &= src[j];
                    }
                }
            }
        }
    }

    int AND = (1 << BITS) - 1;
    for (int i = 0; i < BITS; i++) {
        if (!bitCnt[i].empty()) {
            AND ^= (1 << i);
        }
    }

    for (int i = 0; i < n; i++) {
        if (!incr[i]) {
            ++cnt[src[i]];
        }
    }

    for (int i = 1; i < maxA; i++) {
        for (int j = i; j < maxA; j += i) {
            divBy[i] += cnt[j];
        }
    }

    for (int g = maxA - 1; g > AND + x; g--) {
        if (divBy[g] < 2) {
            continue;
        }

        int fId = -1;
        int sId = -1;
        for (int i = 0; i < n; i++) {
            if (!incr[i]) {
                if (src[i] % g == 0) {
                    if (fId == -1) {
                        fId = i;
                    } else {
                        sId = i;
                    }
                }
            }
        }
        coutYES(fId, sId);
        return;
    }

    cout << "NOn";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int testN;
    cin >> testN;
    while (testN--) {
        solve();
    }
    return 0;
}
```
