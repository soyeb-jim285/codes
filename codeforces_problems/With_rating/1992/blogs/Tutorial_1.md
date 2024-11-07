# Tutorial_1

Thanks [K1o0n](https://codeforces.com/profile/K1o0n "Specialist K1o0n") for being the mvp of this round.

[1992A - Only Pluses](../problems/A._Only_Pluses.md "Codeforces Round 957 (Div. 3)")

Idea: [Vladosiya](https://codeforces.com/profile/Vladosiya "Candidate Master Vladosiya") 

Preparation: [K1o0n](https://codeforces.com/profile/K1o0n "Specialist K1o0n")

 **Tutorial**Let's prove why it's always better to add to the smallest number, let a≤b≤c, then compare the three expressions: (a+1)×b×c, a×(b+1)×c, and a×b×(c+1). Remove the common part a×b×c, and we get: b×c, a×c, a×b.

b×c≥a×c, since a≤b, similarly, b×c≥a×b, since a≤c. Therefore, we can simply find the minimum 5 times and add one to it. And thus, obtain the answer.

Another, primitive approach is to simply iterate through what we will add to a, b, and c with three loops.

Since we can only add 5 times, the time complexity of the solution is O(1).

 **Solution (Python)**
```cpp
for _ in range(int(input())):
    arr = sorted(list(map(int,input().split())))
    for i in range(5):
        arr[0]+=1
        arr.sort()
    print(arr[0] * arr[1] * arr[2])
```
[1992B - Angry Monk](../problems/B._Angry_Monk.md "Codeforces Round 957 (Div. 3)")

Idea: [Noobish_Monk](https://codeforces.com/profile/Noobish_Monk "Master Noobish_Monk")

Preparation: [K1o0n](https://codeforces.com/profile/K1o0n "Specialist K1o0n")

 **Tutorial**Let's say we want to connect two casseroles with lengths x and y. We can disassemble one of them into pieces of length 1 and then attach them to the casserole of size y. In total, we will perform 2x−1 operations. Since we want to connect k pieces, at least k−1 of them will have to be disassembled and then attached to something. If we attach something to a piece, there is no point in disassembling it, because to disassemble it, we will need to remove these pieces as well. Therefore, we want to choose a piece to which we will attach all the others. It will be optimal to choose a piece with the maximum size and attach everything to it. Thus, the answer is 2⋅(n−mx)−k+1, where mx − the length of the maximum piece.

Solution complexity: O(n).

 **Solution (C++)**
```cpp
#include <bits/stdc++.h>
using namespace std;
signed main() {
    int T;
    cin >> T;
    while (T--){
        int n, k;
        cin >> n >> k;
        vector<int> s(k);
        int m = -1;
        for (int i = 0; i < k; i++){
            cin >> s[i];
            m = max(m, s[i]);
        }
        cout << 2 * (n - m) - k + 1 << 'n';
    }
}
```
 **Solution (Python)**
```cpp
for _ in range(int(input())):
    n,k = map(int,input().split())
    mx = max(map(int, input().split()))
    print((n - mx) * 2 - (k - 1))
```
[1992C - Gorilla and Permutation](../problems/C._Gorilla_and_Permutation.md "Codeforces Round 957 (Div. 3)")

Idea: [K1o0n](https://codeforces.com/profile/K1o0n "Specialist K1o0n")

Preparation: [K1o0n](https://codeforces.com/profile/K1o0n "Specialist K1o0n")

 **Tutorial**Let p be some permutation. Let's look at the contribution of the number pi to the sum ∑ni=1f(i). If it is less than k, the contribution is 0, otherwise the contribution is pi⋅(n−i+1). Similarly, let's look at the contribution of pi to the sum ∑ni=1g(i). If it is greater than m, the contribution is 0, otherwise it is pi⋅(n−i+1). Since m<k, each number gives a contribution greater than 0 in at most one sum. Therefore, it is advantageous to place numbers not less than k at the beginning, and numbers not greater than m at the end. Also, numbers not less than k should be in descending order to maximize the sum of f(i). Similarly, numbers not greater than m should be in ascending order to minimize the sum of g(i).

For example, you can construct such a permutation: n,n−1,…,k,m+1,m+2,…,k−1,1,2,…,m. It is easy to see that ∑ni=1f(i) cannot be greater for any other permutation, and ∑ni=1g(i) cannot be less for any other permutation, so our answer is optimal.

Solution complexity: O(n).

 **Solution (Python)**
```cpp
for _ in range(int(input()):
    n,m,k = map(int,input().split())
    print(*range(n,m,-1), *range(1,m))
```
[1992D - Test of Love](../problems/D._Test_of_Love.md "Codeforces Round 957 (Div. 3)")

Idea: [ArSarapkin](https://codeforces.com/profile/ArSarapkin "International Master ArSarapkin")

Preparation: [K1o0n](https://codeforces.com/profile/K1o0n "Specialist K1o0n")

 **Tutorial**In this problem, there are two main solutions: dynamic programming and greedy algorithm.

Dynamic programming solution: dpi − the minimum number of meters that need to be swum to reach the i-th cell. The base case of the dynamic programming is dp0=0. Then, the update rule is: dpi=minimum of{dpi−1+1if Ai='W'min(dpj)for all j,where:max(0,i—m)≤j<i and Aj='L' Solution complexity: O(nm).

Greedy algorithm solution: If we can jump, we want to jump to the shore if possible. If we can't, we want to jump to any log ahead to jump from it later. If we can't, we jump as far as possible to avoid crocodiles and swim as little as possible.

Solution complexity: O(n).

 **Solution (greedy)**
```cpp
def run() -> None:
    n,m,k = map(int, input().split())
    A = input()
    logs = [i for i in range(n) if A[i] == "L"]
    logs.append(n+1)
    i = -1
    next_log = 0
    while i < n-1:
        if m >= logs[next_log] - i:
            i = logs[next_log]
        else:
            i+=m
            if i > n-1:
                print("YES")
                return
            while i < n and i < logs[next_log]:
                if A[i] != "C" and k > 0:
                    i+=1
                    k-=1
                else:
                    print("NO")
                    return
        next_log +=1
    print("YES")
 
for _ in range(int(input())):
    run()
```
 **Solution (DP)**
```cpp
#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, k; 
        cin >> n >> m >> k;
        string s;
        cin >> s;
        vector<int> dp(n + 2, -1);
        dp[0] = k;
        for (int i = 1; i <= n + 1; i++) {
            if (i != n + 1 && s[i - 1] == 'C') 
                continue;
            for (int t = 1; t <= m; t++)
                if (i - t >= 0 && (i - t == 0 || s[i - t - 1] == 'L'))
                    dp[i] = max(dp[i], dp[i - t]);
            if (i > 1 && s[i - 2] == 'W') 
                dp[i] = max(dp[i], dp[i - 1] - 1);
        }
        if (dp[n + 1] >= 0) 
            cout << "YESn";
        else 
            cout << "NOn";
    }
}
```
[1992E - Novice's Mistake](../problems/E._Novice's_Mistake.md "Codeforces Round 957 (Div. 3)")

Idea: [Noobish_Monk](https://codeforces.com/profile/Noobish_Monk "Master Noobish_Monk"), [K1o0n](https://codeforces.com/profile/K1o0n "Specialist K1o0n")

Preparation: [K1o0n](https://codeforces.com/profile/K1o0n "Specialist K1o0n")

 **Tutorial**Notice that n∗a−b is strictly less than 106, i.e., it has no more than 6 digits. The number of characters in the strange calculation n∗a−b is equal to |n|∗a−b, where |n| is the number of digits in n. Let's iterate over the value of a, and then determine the boundaries minB and maxB for it, such that |n|∗a>maxB and |n|∗a−minB≤6. Then: {minB=|n|∗a−6maxB=|n|∗a−1 Let's iterate over all b from minB to maxB. To quickly check the strange calculation, let's only find its first |n|∗a−b digits. This way, we can find all suitable pairs (a,b).

Solution complexity: O(a).

 **Solution (Python)**
```cpp
for _ in range(int(input())):
    n = int(input())
    sn = str(n)
    lenN = len(str(n))
    ans = []
    for a in range(1, 10001):
        minB = max(1, lenN * a - 5)
        maxB = lenN * a
        for b in range(minB, maxB):
            x = n * a - b
            y = 0
            for i in range(lenN * a - b):
                y = y * 10 + int(sn[i % lenN])
            if x == y:
                ans.append((a, b))
    print(len(ans))
    for p in ans:
        print(*p)
```
[1992F - Valuable Cards](../problems/F._Valuable_Cards.md "Codeforces Round 957 (Div. 3)")

Idea: [Noobish_Monk](https://codeforces.com/profile/Noobish_Monk "Master Noobish_Monk")

Preparation: [Noobish_Monk](https://codeforces.com/profile/Noobish_Monk "Master Noobish_Monk")

 **Tutorial**Let's consider the greedy algorithm ``take as long as you can''. Let's prove that it works. In any optimal division, if we take the first segment of non-maximum length, we will not violate the criteria if we transfer one element from the second segment to the first. Therefore, the given greedy algorithm is correct.

Now let's figure out how to quickly understand if the segment can be extended. First, find all divisors of the number x. If the number ai is not a divisor of it, then it cannot be included in any set of numbers whose product is equal to x, so we can simply add it to the segment. If ai is a divisor, we need to somehow learn to understand whether it, in combination with some other divisors, gives the number x on the segment. We will maintain a set of divisors that are products of some numbers in the segment. To update the set when adding ai, we will go through all the divisors of this set and for each divisor d add d⋅ai to the set. If we added the number x to the set, ai will already be in the next segment and we need to clear the set.

P. S.: About implementation details and runtime. If you maintain the set in a set structure, then we get a runtime of O(n⋅d(x)⋅log(d(x))), where d(x) is the number of divisors of x. Instead of a set, you can use, for example, a global array used of size 105+1, as well as maintain a vector of reachable divisors. Using these structures, you can achieve a runtime of O(n⋅d(x)).

 **Solution (C++)**
```cpp
#include <iostream>
#include <vector>

using namespace std;

const int A = 1e6 + 1;
bool used[A];
bool divs[A];

void solve() {
	int n, x;
	cin >> n >> x;
	vector<int> a(n);
	vector<int> vecDivs;
	for (int d = 1; d * d <= x; d++) {
		if (x % d == 0) {
			divs[d] = true;
			vecDivs.push_back(d);
			if (d * d < x) {
			    vecDivs.push_back(x / d);
				divs[x / d] = true;
			}
		}
	}
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int ans = 1;
	used[1] = true;
	vector<int> cur{ 1 };
	for (int i = 0; i < n; i++) {
		if (!divs[a[i]])
			continue;
		vector<int> ncur;
		bool ok = true;
		for (int d : cur)
			if (1ll * d * a[i] <= x && divs[d * a[i]] && !used[d * a[i]]) {
				ncur.push_back(d * a[i]);
				used[d * a[i]] = true;
				if (d * a[i] == x)
					ok = false;
			}
		for (int d : ncur)
			cur.push_back(d);
		if (!ok) {
			ans++;
			for (int d : cur)
				used[d] = false;
			used[1] = true;
			used[a[i]] = true;
			cur = vector<int>{ 1, a[i] };
		}
	}
	for (int d : vecDivs) {
	    divs[d] = false;
	    used[d] = false;
	}
	cout << ans << 'n';
}

signed main() {
    int T;
    cin >> T;
    while (T--)
	    solve();
	return 0;
}
```
[1992G - Ultra-Meow](../problems/G._Ultra-Meow.md "Codeforces Round 957 (Div. 3)")

Idea: [Noobish_Monk](https://codeforces.com/profile/Noobish_Monk "Master Noobish_Monk"), [K1o0n](https://codeforces.com/profile/K1o0n "Specialist K1o0n")

Preparation: [K1o0n](https://codeforces.com/profile/K1o0n "Specialist K1o0n")

 **Tutorial**We will iterate over the size of the set k and its MEOW, m. If 2k⩾n, then the set x will fill all the remaining numbers up to n, and there may still be some larger than n in it, so the MEOW of all such sets will be 2k+1, and there will be a total of C(n,k) such sets for each k. If 2k<n, m lies in the interval from k+1 to 2k+1. Notice that there can be exactly m−1−k numbers before m, and correspondingly 2k+1−m numbers to the right of m, so the answer needs to be added with Cm−1−km−1⋅C2k+1−mn−m⋅m.

Asymptotic complexity of the solution: O(n2).

 **Solution (C++)**
```cpp
#include <iostream>

using namespace std;

const int mod = 1e9 + 7;

int add(int a, int b) {
    if (a + b >= mod)
        return a + b - mod;
    return a + b;
}

int sub(int a, int b) {
    if (a < b)
        return a + mod - b;
    return a - b;
}

int mul(int a, int b) {
    return (int)((1ll * a * b) % mod);
}

int binpow(int a, int pw) {
    int b = 1;
    while (pw) {
        if (pw & 1)
            b = mul(b, a);
        a = mul(a, a);
        pw >>= 1;
    }
    return b;
}

int inv(int a) {
    return binpow(a, mod - 2);
}

const int N = 15000;
int f[N], r[N];

void precalc() {
    f[0] = 1;
    for (int i = 1; i < N; i++)
        f[i] = mul(f[i - 1], i);
    r[N - 1] = inv(f[N - 1]);
    for (int i = N - 2; i > -1; i--)
        r[i] = mul(r[i + 1], i + 1);
}

int C(int n, int k) {
    if (n < 0 || k < 0 || n < k)
        return 0;
    return mul(f[n], mul(r[k], r[n - k]));
}

inline void solve() {
    int n;
    cin >> n;
    int ans = 1;
    for (int k = 1; k <= n; k++) {
        if (2 * k >= n) {
            ans = add(ans, mul(2 * k + 1, C(n, k)));
            continue;
        }
        for (int m = k + 1; m <= 2 * k + 1; m++) {
            int c = mul(C(m - 1, m - 1 - k), C(n - m, 2 * k + 1 - m));
            ans = add(ans, mul(mul(C(m - 1, m - 1 - k), C(n - m, 2 * k + 1 - m)), m));
        }
    }
    cout << ans << 'n';
}

signed main() {
    int T = 1;
    cin >> T;
    precalc();
    while(T--)
        solve();
    return 0;
}

```
