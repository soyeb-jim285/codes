# Tutorial

[1759A - Yes-Yes?](../problems/A._Yes-Yes_.md "Codeforces Round  834 (Div. 3)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1759A - Yes-Yes?](../problems/A._Yes-Yes_.md "Codeforces Round  834 (Div. 3)")

Note that it is enough to consider the string full=YesYes...Yes, where Yes is written 18 times, since 18⋅3=54, and our substring s has size |s|≤50.

Then we just use the built-in function find to find out if our string s is a substring of the string full.

 **Solution**
```cpp
full = 'Yes' * 18
t = int(input())
for _ in range(t):
    if full.find(input()) >= 0:
        print('YES')
    else:
        print('NO')
```
[1759B - Lost Permutation](../problems/B._Lost_Permutation.md "Codeforces Round  834 (Div. 3)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1759B - Lost Permutation](../problems/B._Lost_Permutation.md "Codeforces Round  834 (Div. 3)")

Let us add to s the sum of the elements of the array b and try to find a suitable permutation. To do this, greedily add elements 1,2,…,cnt until their sum is less than s. And at the end we will check that the sum has matched. 

Also check that the maximal element from b: max(b)≤cnt, and that the total elements in b: n≤cnt.

 **Solution**
```cpp
t = int(input())
for _ in range(t):
    n, s = map(int, input().split())
    a = [int(x) for x in input().split()]
    s += sum(a)
    sm = 0
    cnt = 0
    for i in range(1, s + 1):
        if sm >= s:
            break
        sm += i
        cnt = i
    if sm != s or max(a) > cnt or cnt <= n:
        print("NO");
    else:
        print("YES")
```
[1759C - Thermostat](../problems/C._Thermostat.md "Codeforces Round  834 (Div. 3)")

Idea: [Vladosiya](https://codeforces.com/profile/Vladosiya "Expert Vladosiya")

 **Tutorial**
### [1759C - Thermostat](../problems/C._Thermostat.md "Codeforces Round  834 (Div. 3)")

First let's consider the cases when the answer exists:

* If a=b, then the thermostat is already set up and the answer is 0.
* else if |a−b|≥x, then it is enough to reconfigure the thermostat in 1 operation.
* else if exist such temperature c, that |a−c|≥x and |b−c|≥x, then you can configure the thermostat in 2 operations. If such c exists between l and r, we can chose one of bounds: a→l→b or a→r→b.
* we need to make 3 operations if times if we cannot reconfigure through one of the boundaries as above, but we can through both: a→l→r→b or a→r→l→b

If we can't get the temperature b in one of these ways, the answer is −1.

 **Solution**
```cpp
def solve():
    l, r, x = map(int, input().split())
    a, b = map(int, input().split())
    if a == b:
        return 0
    if abs(a - b) >= x:
        return 1
    if r - max(a, b) >= x or min(a, b) - l >= x:
        return 2
    if r - b >= x and a - l >= x or r - a >= x and b - l >= x:
        return 3
    return -1


t = int(input())
for _ in range(t):
    print(solve())
```
[1759D - Make It Round](../problems/D._Make_It_Round.md "Codeforces Round  834 (Div. 3)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1759D - Make It Round](../problems/D._Make_It_Round.md "Codeforces Round  834 (Div. 3)")

The answer is n⋅k.

First, count two numbers: cnt2,cnt5 which denote the degree of occurrence of 2 and 5 in the number n respectively, that is n=2cnt2⋅5cnt5⋅d. Where d is not divisible by either 2 or 5. Now while cnt2≠cnt5 we will increase the corresponding value. For example, if cnt2<cnt5, then as long as cnt2≠cnt5 and at that k⋅2≤m we will increase cnt2 by 1 and multiply k by 2 times. 

That way we can get the most round number possible by spending the least possible k.

Now we either have cnt2=cnt5, or k⋅5>m or k⋅2>m. Then in the first case, we will multiply the number k by 10 as long as we can. That is, until k⋅10≤m.

Now in either case we have: k⋅10>m. Then ⌊mk⌋=x<10. Then we multiply k by x times and get our desired answer.

In the last step, we can no longer get a rounder number, but just find the maximal possible number.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define sz(v) (int)v.size()
#define all(v) v.begin(),v.end()
#define eb emplace_back

using ll = long long;

void solve() {
    ll n,m; cin >> n >> m;
    ll n0 = n;
    int cnt2 = 0, cnt5 = 0;
    ll k = 1;
    while (n > 0 && n % 2 == 0) {
        n /= 2;
        cnt2++;
    }
    while (n > 0 && n % 5 == 0) {
        n /= 5;
        cnt5++;
    }
    while (cnt2 < cnt5 && k * 2 <= m) {
        cnt2++;
        k *= 2;
    }
    while (cnt5 < cnt2 && k * 5 <= m) {
        cnt5++;
        k *= 5;
    }
    while (k * 10 <= m) {
        k *= 10;
    }
    if (k == 1) {
        cout << n0 * m << endl;
    } else {
        k *= m / k; // 1 <= m/k < 10
        cout << n0 * k << endl;
    }
}

int main() {
    int t;
    cin >> t;

    forn(tt, t) {
        solve();
    }
}
```
[1759E - The Humanoid](../problems/E._The_Humanoid.md "Codeforces Round  834 (Div. 3)")

Idea: [Gornak40](https://codeforces.com/profile/Gornak40 "Expert Gornak40")

 **Tutorial**
### [1759E - The Humanoid](../problems/E._The_Humanoid.md "Codeforces Round  834 (Div. 3)")

Let's make two obvious remarks:

1. If we can absorb two astronauts with power x≤y, then we can always first absorb an astronaut with power x, and then an astronaut with power y;
2. If we can absorb some astronaut, it is effective for us to do it right now.

Let's sort the astronauts powers in increasing order.

Now let's lock the sequence of serums we use. There are only three of them: blue serum can be the first, second or third.

Let's absorb the astronauts in increasing order of their powers, and if we can't, then use the next serum in a locked sequence or stop.

This solution works for O(n).

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200200;

int n;
int arr[MAXN];

int solve(int i, long long h, int s2, int s3) {
	if (i == n) return 0;
	if (arr[i] < h)
		return solve(i + 1, h + (arr[i] / 2), s2, s3) + 1;
	int ans1 = (s2 ? solve(i, h * 2, s2 - 1, s3) : 0);
	int ans2 = (s3 ? solve(i, h * 3, s2, s3 - 1) : 0);
	return max(ans1, ans2);
}

int main() {
	int t; cin >> t;
	while(t--) {
		long long h; cin >> n >> h;
		for (int i = 0; i < n; ++i)
			cin >> arr[i];
		sort(arr, arr + n);
		cout << solve(0, h, 2, 1) << endl;
	}
}
```
[1759F - All Possible Digits](../problems/F._All_Possible_Digits.md "Codeforces Round  834 (Div. 3)")

Idea: [senjougaharin](https://codeforces.com/profile/senjougaharin "Master senjougaharin")

 **Tutorial**
### [1759F - All Possible Digits](../problems/F._All_Possible_Digits.md "Codeforces Round  834 (Div. 3)")

If all digits from 0 to p−1 are initially present in the number, then the answer is 0.

Each time we will increase the number by 1. If the last digit is less than p−1, then only it will change. Otherwise, all digits equal to p−1 at the end will become equal to 0, and the previous one will increase by 1 (or a new digit equal to 1 will be added if all digits were equal to p−1).

For a p−1 operation, the last digit will run through all possible values. However, we can get all the numbers earlier. We will solve the problem using binary search, sorting through the number of operations.

We can have 2 options: whether 0 was at the end or not. Depending on this, one or two subsegments of the segment [0,p−1] — a subsegment in the middle or a prefix and a suffix remained uncovered by the last digit of the number. They need to be completely covered with numbers that were already in positions, except for the last one — these are the original numbers and, in case there was 0 at the end, the number into which the transfer was made. There are at most n+1 of them.

 **Solution**
```cpp
#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef tree<pair<int, int>, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int newDigit = -1;

bool check(set<int> digits, int l, int r, bool useNewDigit) {
    for (int i = l; i <= r; ++i) {
        if (useNewDigit && i == newDigit) {
            continue;
        }
        if (!digits.count(i)) {
            return false;
        }
    }
    return true;
}

void solve() {
    int n, p;
    cin >> n >> p;
    vector<int> a(n + 1);
    set<int> digits;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        digits.insert(a[i]);
    }
    if (digits.size() == p) {
        cout << "0n";
        return;
    }
    for (int i = n - 1; i >= 0; --i) {
        if (a[i] < p - 1) {
            newDigit = a[i] + 1;
            break;
        }
    }
    int l = 0, r = p - 1;
    int x = a[n];
    while (l < r) {
        int m = (l + r) >> 1;
        bool res = false;
        if (x + m >= p) {
            if (check(digits, x + m + 1 - p, x - 1, true)) {
                res = true;
            }
        } else {
            if (check(digits, 0, x - 1, false) && check(digits, x + m + 1, p - 1, false)) {
                res = true;
            }
        }
        if (res) {
            r = m;
        } else {
            l = m + 1;
        }
    }
    cout << l << 'n';
}

bool multitest = true;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout.precision(25);
    size_t number_of_tests = 1;
    if (multitest) {
        cin >> number_of_tests;
    }
    for (size_t _ = 0; _ < number_of_tests; ++_) {
        solve();
    }
    return 0;
}
```
[1759G - Restore the Permutation](../problems/G._Restore_the_Permutation.md "Codeforces Round  834 (Div. 3)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1759G - Restore the Permutation](../problems/G._Restore_the_Permutation.md "Codeforces Round  834 (Div. 3)")

First, let's check the b array for correctness, that is, that it has no repeating elements.

Then let's look at the following ideas: 

* each number bi must be paired with another permutation element pj, with pj<bi by the definition of array b. Then, since we want a lexicographically minimal permutation, it is always more advantageous to put element pj before bi.
* for the permutation to be lexicographically minimal, the smallest possible numbers must be placed at the beginning. Consequently, the largest numbers must be placed at the end.

Let's proceed as follows: 

1. Let's select the set of unused numbers that are not included in the b array.
2. For an element bn2, find the maximum number k of the set unused such that bn2>k and put that number in front of the element bn2.
3. moving from the end of the array to its beginning, each element bi will be matched with such an element. If at some point k can not be matched — array b is not composed correctly, and the answer to the query — "NO".
4. Otherwise, print "YES" and the resulting permutation p.
 **Solution**
```cpp
#include "bits/stdc++.h"
using namespace std;
int n;

void solve(){
    cin >> n;
    vector<int>b(n / 2), p(n);
    vector<bool>isUsed(n + 1, false);
    set<int>unused;

    for(int i = 0; i < n / 2; i++){
        cin >> b[i];
        p[i * 2 + 1] = b[i];
        isUsed[b[i]] = true;
    }
    for(int i = 1; i <= n; i++){
        if(!isUsed[i]) unused.insert(i);
    }


    if(int(unused.size()) != n / 2){
        cout << "-1n";
        return;
    }

    for(int i = n / 2 - 1; i >= 0; i--){
        auto k = unused.upper_bound(p[2 * i + 1]);
        if(k == unused.begin()){
            cout << "-1n";
            return;
        }

        k--;


        if(*k < p[2 * i + 1]){
            p[2 * i] = *k;
            unused.erase(k);
        }
        else{
            cout << "-1n";
            return;
        }
    }
    for(auto i : p) cout << i << ' ';
    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        solve();
    }

}
```
