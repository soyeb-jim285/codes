# Tutorial_(en)

Thanks for participating!

[1692A - Marathon](../problems/A._Marathon.md "Codeforces Round 799 (Div. 4)")

Idea: [mesanu](https://codeforces.com/profile/mesanu "Expert mesanu")

 **Tutorial**
### [1692A - Marathon](../problems/A._Marathon.md "Codeforces Round 799 (Div. 4)")

We can re-word the problem to count the number of numbers from b,c,d that are larger than a. A possible way to do this is by keeping a variable that gets incremented every time we checked using the if statement whether a number is larger than a. The complexity is O(1).

 **Solution**
```cpp
t = int(input())
for test in range(t):
    a,b,c,d = map(int, input().split())
    rs = (b > a) + (c > a) + (d > a)
    print(rs)
```
[1692B - All Distinct](../problems/B._All_Distinct.md "Codeforces Round 799 (Div. 4)")

Idea: [mesanu](https://codeforces.com/profile/mesanu "Expert mesanu")

 **Tutorial**
### [1692B - All Distinct](../problems/B._All_Distinct.md "Codeforces Round 799 (Div. 4)")

Note that the size of the array doesn't change parity, since it always decreases by 2. Let's count the number of distinct elements, call it x. 

If x is the same parity as n (the length of the array), then we can make sure all of these x distinct elements stay in the array by removing two elements at a time. 

Otherwise, x isn't the same parity as n. Then x−1 is the same parity as n, and we can make sure x−1 distinct elements stay in the array by removing two elements at a time. So the answer is x if x and n have the same parity, and x−1 otherwise.

For example: [15,16,16,15] has x=4, n=2. So x and n have the same parity, and we can get all distinct numbers [15,16] by removing i=3, j=4.

Time complexity: O(nlogn) or O(n), depending on the implementation.

 **Solution**
```cpp
#include <bits/stdc++.h>
typedef long long  ll;
using namespace std;

void solve()
{
	int n, x;
	cin >> n;
	set<int> a;
	for(int i = 0; i < n; i++)
	{
		cin >> x;
		a.insert(x);
	}
	if((n-a.size())%2 == 0)
	{
		cout << a.size() << endl;
	}
	else
	{
		cout << a.size()-1 << endl;
	}
}

int32_t main(){
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}
```
[1692C - Where's the Bishop?](../problems/C._Where's_the_Bishop_.md "Codeforces Round 799 (Div. 4)")

Idea: [flamestorm](https://codeforces.com/profile/flamestorm "Candidate Master flamestorm")

 **Tutorial**
### [1692C - Where's the Bishop?](../problems/C._Where's_the_Bishop_.md "Codeforces Round 799 (Div. 4)")

There are many ways to solve the problem. One way is to look for the following pattern: X.X.X.X.X There can only be one such pattern if there is one bishop and it's not on the edge of the board. We can iterate through all cells and see if we can match this pattern, and if we can we output the centre cell.

You can also look at the positions of the two diagonals and intersect them, but it requires more implementation.

Time complexity: O(1) per testcase.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

void solve() {
	char g[9][9];
	for (int i = 1; i <= 8; i++) {
		for (int j = 1; j <= 8; j++) {
			cin >> g[i][j];
		}
	}
	for (int i = 2; i <= 7; i++) {
		for (int j = 2; j <= 7; j++) {
			if (g[i][j] == '#' && g[i - 1][j - 1] == '#' && g[i - 1][j + 1] == '#' && g[i + 1][j - 1] == '#' && g[i + 1][j + 1] == '#') {
				cout << i << ' ' << j << 'n'; return;
			}
		}
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    // solve();
}
```
[1692D - The Clock](../problems/D._The_Clock.md "Codeforces Round 799 (Div. 4)")

Idea: [SlavicG](https://codeforces.com/profile/SlavicG "Expert SlavicG")

 **Tutorial**
### [1692D - The Clock](../problems/D._The_Clock.md "Codeforces Round 799 (Div. 4)")

Note that Victor looks at the clock forever, but there are only at most 1440 different times the clock can show (because there are 1440 different minutes in a day). So we only have to check the first 1440 times Victor sees, and count the palindromes (you can check a few more just to be safe, but they will repeat anyways).

Now we just have to implementing adding x minutes to a clock. There are several ways to do this. One of the slower ways might be writing functions converting a number of minutes into a time for a clock, or you can just compute all palindrome times in terms of minutes and that way you don't have to convert from clock time to number of minutes.

The complexity is O(1) per test case, since you only have to check a constant number of times. 

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

int a[5] = {600, 60, 0, 10, 1};
int good[16] = {0, 70, 140, 210, 280, 350, 601, 671, 741, 811, 881, 951, 1202, 1272, 1342, 1412};

void solve() {
	string s;
	cin >> s;
	int x;
	cin >> x;
	int tot = 0;
	for (int i = 0; i < 5; i++) {
		tot += (int)(s[i] - '0') * a[i];
	}
	set<int> t;
	for (int i = 0; i < 2022; i++) {
		t.insert(tot);
		tot += x;
		tot %= 1440;
	}
	int res = 0;
	for (int i : t) {
		for (int j = 0; j < 16; j++) {
			if (good[j] == i) {res++;}
		}
	}
	cout << res << 'n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    // solve();
}
```
[1692E - Binary Deque](../problems/E._Binary_Deque.md "Codeforces Round 799 (Div. 4)")

Idea: [flamestorm](https://codeforces.com/profile/flamestorm "Candidate Master flamestorm")

 **Tutorial**
### [1692E - Binary Deque](../problems/E._Binary_Deque.md "Codeforces Round 799 (Div. 4)")

Note that the remaining array is a subarray of the original array. There are many ways to approach the problem. Here is one solution, which the main solution uses:

Compute prefix sums on the array, so we can find out the value of al+⋯+ar quickly. Let's iterate through the left endpoint l from 1 to n. Afterwards, we can binary search on the smallest value of r such that al+⋯+ar=s, since this sum is strictly increasing.

The time complexity is O(nlogn).

 **Solution**
```cpp
#include "bits/stdc++.h"
using namespace std;
 
#define ll long long
 
#define       forn(i,n)              for(int i=0;i<n;i++)
#define          all(v)              v.begin(), v.end()
#define         rall(v)              v.rbegin(),v.rend()
 
#define            pb                push_back
#define          sz(a)               (int)a.size()


ll query(int l, int r, vector<ll>& p) {
    return p[r] - (l ? p[l - 1] : 0);
}

void solve() {  
    int n, s; cin >> n >> s;
    vector<ll> a(n), p(n);
    forn(i, n) {
        cin >> a[i];
        p[i] = a[i];
        if(i) p[i] += p[i - 1];
    }

    int ans = INT_MAX;

    for(int i = 0; i < n; ++i) {
        int l = i, r = n - 1, pos = -1;
        while(l <= r) {
            int mid = l + r >> 1;
            if(query(i, mid, p) <= s) {
                pos = mid;
                l = mid + 1;
            } else r = mid - 1;
        }
        if(pos == -1 || query(i, pos, p) != s) continue;
        ans = min(ans, n - (pos - i + 1));
    }

    cout << (ans == INT_MAX ? -1 : ans) << "n";
} 
     
int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
}   
```
[1692F - 3SUM](../problems/F._3SUM.md "Codeforces Round 799 (Div. 4)")

Idea: [flamestorm](https://codeforces.com/profile/flamestorm "Candidate Master flamestorm")

 **Tutorial**
### [1692F - 3SUM](../problems/F._3SUM.md "Codeforces Round 799 (Div. 4)")

Since we only care about the last digit of the sum ai+aj+ak, we can ignore all numbers other than the last digits of the elements of a. (For example, we can consider [20,22,19,84] to be the same as [0,2,9,4].)

Now note that if a number appears more than 3 times in the array, we can ignore all copies that occur more than 3 times, since our sum ai+aj+ak only involves three numbers. (For example, we can consider [1,1,1,1,2] to be the same as [1,1,1,2].)

Using these observations, note that there are only 10 digits, and each digit can occur at most 3 times. So we can always reduce the array to one of length 30. Since 30 is very small, we can brute force all triples ai+aj+ak, which runs quickly enough.

Time complexity: O(n+min(n,30)3).

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	cin >> n;
	int cnt[10] = {};
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		cnt[x % 10]++;
	}
	vector<int> v;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < min(cnt[i], 3); j++) {
			v.push_back(i);
		}	
	}
	int m = v.size();
	for (int i = 0; i < m; i++) {
		for (int j = i + 1; j < m; j++) {
			for (int k = j + 1; k < m; k++) {
				if ((v[i] + v[j] + v[k]) % 10 == 3) {cout << "YESn"; return;}
			}
		}
	}
	cout << "NOn";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    // solve();
}  
```
[1692G - 2^Sort](../problems/G._2^Sort.md "Codeforces Round 799 (Div. 4)")

Idea: [flamestorm](https://codeforces.com/profile/flamestorm "Candidate Master flamestorm")

 **Tutorial**
### [1692G - 2^Sort](../problems/G._2^Sort.md "Codeforces Round 799 (Div. 4)")

Note that 2x⋅ai<2x+1⋅ai+1 is the same as ai<2ai+1, since we can divide by 2x. This means that we only need to check whether ai<2ai+1 for each pair of adjacent elements.

Let's consider as an example [20,22,19]. Note that 20<2⋅22 and 22<2⋅19, so if you multiply the first element by 1, the second by 2, and the third by 22, the array is sorted.

So let's make a new array b where bi=1 if ai<2ai+1 and bi=0 otherwise. Then we know that the whole chain of inequalities holds true if all values in a subarray of length k in b have all their values equal to 1.

For example, if a=[9,5,3,2,1], b=[1,1,1,0]. Say k=2. Then [9,5,3] works, since [9,5⋅2,3⋅22] is sorted. We can write this as 9<2⋅5 and 5<2⋅3. This is equivalent to b1=1 (since a1<2a2) and b2=1 (since a2<2a3). 

So the problem is equivalent to counting the number of subarrays of length k in b whose elements are all equal to 1. There are many ways to do this. For example, you can compute prefix sums and then find the sum of all subarrays of length k, and count the number whose sum is k. The model solution uses a sliding window and updates the number of ones in the current subarray as we move from left to right.

Time complexity is O(n).

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n, k;
	cin >> n >> k;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int ok[n];
	for (int i = 0; i < n - 1; i++) {
		ok[i] = (a[i] < 2 * a[i + 1]);
	}
	int tot = 0;
	for (int i = 0; i < k; i++) {
		tot += ok[i];
	}
	int res = 0;
	if (tot == k) {res++;}
	for (int i = k; i < n - 1; i++) {
		tot += ok[i];
		tot -= ok[i - k];
		if (tot == k) {res++;}
	}
	cout << res << 'n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    // solve();
}
```
[1692H - Gambling](../problems/H._Gambling.md "Codeforces Round 799 (Div. 4)")

Idea: [mesanu](https://codeforces.com/profile/mesanu "Expert mesanu")

 **Tutorial**
### [1692H - Gambling](../problems/H._Gambling.md "Codeforces Round 799 (Div. 4)")

There are several solutions. Here is one.

If we fix the value of a, then let's make a new array b as follows: bi=1 if roundi=a, and bi=−1 otherwise. Then the total amount of money earned will just be 2bl+⋯+br, so we only need to maximize bl+⋯+br. In other words, we need to find the maximum sum of a subarray. This is a standard problem that can be solved using segment tree.

Note that we need to iterate over all values of a, of which there are n possibilities. So we have to update elements of the segment tree O(n) times and query once for each a, which means overall the solution runs in O(nlogn). 

 **Solution**
```cpp
#include "bits/stdc++.h"
using namespace std;
 
#define ll long long
 
#define       forn(i,n)              for(int i=0;i<n;i++)
#define          all(v)              v.begin(), v.end()
#define         rall(v)              v.rbegin(),v.rend()
 
#define            pb                push_back
#define          sz(a)               (int)a.size()
 
struct DynamicMaxSubarraySum {
    struct node {
        ll pref, suf, val, sum;
    };  
    int N;
    ll neutral;
    vector<node> t;
    DynamicMaxSubarraySum(int _N, ll assign_value) {
        neutral = assign_value;
        N = _N;
        t.resize(4 * N);
        forn(i, 4 * N) t[i] = {0, 0, 0, 0};
        build(1, 0, N - 1); 
    }
    void build(int i, int l, int r) {
        if(l == r) {
            t[i].pref = t[i].suf = t[i].val = t[i].sum = neutral;
            return;
        }
        int mid = (l + r) >> 1;
        build(2 * i, l, mid);
        build(2 * i + 1, mid + 1, r);
        t[i] = merge(t[2 * i], t[2 * i + 1]);
    }
    node merge(node a, node b) {
        node c;
        c.pref = max(a.pref, a.sum + b.pref);
        c.suf = max(b.suf, b.sum + a.suf);
        c.val = max({a.val, b.val, a.suf + b.pref});
        c.sum = a.sum + b.sum;
        return c;
    }
 
    void modif(int i, int l, int r, int pos, ll val) {
        if(l > pos || r < pos) return;
        if(l == pos && r == pos) {
            t[i].pref = t[i].suf = t[i].val = t[i].sum = val;
            return;
        }
        int mid = (l + r) >> 1;
        modif(2 * i, l, mid, pos, val);
        modif(2 * i + 1, mid + 1, r, pos, val);
        t[i] = merge(t[2 * i], t[2 * i + 1]);
    }
    node query(int i, int l, int r, int tl, int tr) {
        if(l > tr || r < tl) return {0, 0, 0, 0};
        if(l >= tl && r <= tr) return t[i];
        int mid = (l + r) >> 1;
        return merge(query(2 * i, l, mid, tl, tr), query(2 * i + 1, mid + 1, r, tl, tr));
    }
 
    void modif(int pos, int val) {
        modif(1, 0, N - 1, pos, val);
    }
    node query(int l, int r) {
        return query(1, 0, N - 1, l, r);
    }
    node query(int pos) {
        return query(1, 0, N - 1, pos, pos);
    }
};
 
void solve() {  
    int n; cin >> n;
    vector<int> a(n);
    forn(i, n) cin >> a[i];
    map<int, vector<int>> vv;
    forn(i, n) {
        vv[a[i]].pb(i);
    }
    DynamicMaxSubarraySum st(n, -1);
 
    ll mx = 0, ans = -1;
    for(auto i: vv) {
        vector<int> v = i.second;
        for(auto x: v) st.modif(x, 1);
        if(mx < st.query(0, n - 1).val) {
            ans = i.first;
            mx = st.query(0, n - 1).val;
        }
        for(auto x: v) st.modif(x, -1);
    }  
    int ansl = -1, ansr = -1;
    for(int i = 0; i < n; ++i) {
        if(a[i] == ans) a[i] = 1;
        else a[i] = -1;
    }
    ll sum = 0, lastl = 0;
    mx = 0;
    for(int i = 0; i < n; ++i) {
        sum += a[i];
        if(sum > mx) {
            mx = sum;
            ansr = i;
            ansl = lastl;
        }
        if(sum <= 0) {
            lastl = i + 1;
            sum = 0;
        }
    }
 
    cout << ans << " " << ansl + 1 << " " << ansr + 1 << "n"; 
}   
     
int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
}
```
