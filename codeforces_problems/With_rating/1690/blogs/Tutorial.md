# Tutorial

[1690A - Print a Pedestal (Codeforces logo?)](../problems/A._Print_a_Pedestal_(Codeforces_logo_).md "Codeforces Round 797 (Div. 3)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1690A - Print a Pedestal (Codeforces logo?)](../problems/A._Print_a_Pedestal_(Codeforces_logo_).md "Codeforces Round 797 (Div. 3)")

In the n≤105 constraints, the problem can be solved by brute force: we will go through the value for h1 (the height for the first place), and then select suitable values for h2 and h3. Since h2>h3, we divide the remaining n−h1 blocks equally between h2 and h3. If it turns out that h2=h3, then we try to decrease h3 by 1 and increase h2 by 1. If we get the right answer (h1>h2>h3>1), output the heights and stop the process. We will go through the value of h1 in order of increasing.

 **Solution**
```cpp
#include <bits/stdc++.h>
 
using namespace std;
 
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define sz(v) (int)v.size()
#define all(v) v.begin(),v.end()
#define eb emplace_back
 
 
 
void solve() {
    int n; 
    cin >> n;
    for (int a = 3; a < n; a++) {
        int c = (n - a) / 2;
        int b = n - a - c;
        if (c > 1 && b+1 < a) {
            c--;
            b++;
        }
        if (a > b && b > c) {
            cout << b << ' ' << a << ' ' << c << endl;
            return;
        }
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
[1690B - Array Decrements](../problems/B._Array_Decrements.md "Codeforces Round 797 (Div. 3)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1690B - Array Decrements](../problems/B._Array_Decrements.md "Codeforces Round 797 (Div. 3)")

For all elements of the arrays to become equal after subtraction of units, ai>=bi for 1≤i≤n must be satisfied. In addition, if there exists bi>0, then the equality ai=bi can be obtained only by subtracting exactly ai−bi units from ai. Since the equality ai=bi must be satisfied for all i, the problem is reduced to checking that for bi>0 all differences ai−bi=dif are equal and for bi=0 the difference does not exceed dif.

 **Solution**
```cpp
#include<bits/stdc++.h>
 
#define forn(i, n) for (int i = 0; i < int(n); i++)
 
using namespace std;
const int inf = 1e9 + 7;
 
bool equals(vector<int>&a, vector<int>&b, int n){
    int dif = inf;
    forn(i, n){
        if(b[i] != 0) dif = min(dif, a[i] - b[i]);
    }
    if(dif < 0) return false; 
    if(dif == inf) return true;
    forn(i, n){
        if(a[i] - b[i] > dif) return false;
        if(b[i] != 0 && a[i] - b[i] < dif) return false;
    }
    return true;
}
 
void solve(){
    int n;
    cin >> n;
    vector<int>a(n), b(n);
    forn(i, n) cin >> a[i];
    forn(i, n) cin >> b[i];
    cout << (equals(a, b, n) ? "YESn" : "NOn");
 
}
 
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}

```
[1690C - Restoring the Duration of Tasks](../problems/C._Restoring_the_Duration_of_Tasks.md "Codeforces Round 797 (Div. 3)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1690C - Restoring the Duration of Tasks](../problems/C._Restoring_the_Duration_of_Tasks.md "Codeforces Round 797 (Div. 3)")

Accordingly, as it was said in the task, we put all tasks into the queue in the order of their arrival, then we fix the time at the beginning as cur_time=0. So, while there is a task in the queue, we proceed as follows: 

1. Take the task from the queue.
2. Take as time the maximum from the current and from the arrival time of the task (cur_time=max(cur_time,s)).
3. We subtract the current time from the time when the task was done (f=d−cur_time).
4. Replace the current time with the time the task was done (cur_time=d)
5. If there is a task in the queue, go to item 1.
 **Solution**
```cpp
#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
#define forn(i, n) for (int i = 0; i < int(n); i++)
 
 
void solve() {
    int n;
    cin >> n;
    int s[n];
    int f[n];
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }
 
    for (int i = 0; i < n; ++i) {
        cin >> f[i];
    }
    int curTime = 0;
    int d[n];
    for (int i = 0; i < n; ++i) {
        curTime = max(curTime, s[i]);
        d[i] = f[i] - curTime;
        curTime = f[i];
    }
    for (auto now: d) {
        cout << now << " ";
    }
    cout << 'n';
}
int main() {
    int tests;
    cin >> tests;
    forn(tt, tests) {
        solve();
    }
}
```
[1690D - Black and White Stripe](../problems/D._Black_and_White_Stripe.md "Codeforces Round 797 (Div. 3)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1690D - Black and White Stripe](../problems/D._Black_and_White_Stripe.md "Codeforces Round 797 (Div. 3)")

To obtain a segment of k cells of black color, we need to paint all the white cells of the segment black. Then go through all the segments of length k (there are only n−k) and choose such a segment among them that the number of white cells on it is minimal. You can quickly find out the number of white cells in the segment by prefix sums. 

 **Solution**
```cpp
#include <bits/stdc++.h>
 
using namespace std;
 
#define forn(i, n) for (int i = 0; i < int(n); i++)
 
int main() {
    int t;
    cin >> t;
    forn(tt, t) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        vector<int> w(n + 1);
        for (int i = 1; i <= n; i++)
            w[i] = w[i - 1] + int(s[i - 1] == 'W');
        int result = INT_MAX;
        for (int i = k; i <= n; i++)
            result = min(result, w[i] - w[i - k]);
        cout << result << endl;
    }
}
```
[1690E - Price Maximization](../problems/E._Price_Maximization.md "Codeforces Round 797 (Div. 3)")

Idea: [Vladosiya](https://codeforces.com/profile/Vladosiya "Expert Vladosiya"), [Aris](https://codeforces.com/profile/Aris "Expert Aris")

 **Tutorial**
### [1690E - Price Maximization](../problems/E._Price_Maximization.md "Codeforces Round 797 (Div. 3)")

Note that we do not need to consider the numbers x≥k, we are only interested in the remainder of the division of x by k, and we simply add the value ⌊xk⌋ to the answer. 

We get an array a, where ai<k. Let's sort it and greedily type index pairs i<j such that ai+aj≥k. This can be done with two pointers. Then add the number of matching pairs to the answer counter. This will be the answer to the problem.

 **Solution**
```cpp
#include<bits/stdc++.h>
#define len(s) (int)s.size()
using namespace std;
using ll = long long;
 
void solve(){
    int n, k;
    cin >> n >> k;
    vector<ll>a(n);
    ll sum = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i] / k;
        a[i] = a[i] % k;
    }
    sort(a.begin(), a.end(), [] (int x, int y){
        return x > y;
    });
 
    for(int i = 0, j = n - 1; i < j; i++, j--){
        while(a[i] + a[j] < k && i < j) j--;
        if(i == j) break;
        sum++;
    }
    cout << sum << endl;
}
 
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
```
[1690F - Shifting String](../problems/F._Shifting_String.md "Codeforces Round 797 (Div. 3)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1690F - Shifting String](../problems/F._Shifting_String.md "Codeforces Round 797 (Div. 3)")

To begin with, let's understand why the string will return to its original form. In fact, the graph that the permutation sets consists of simple cycles and it turns out that after a certain number of operations, each character will return to its place.

Consider each cycle as a string that is cyclically shifted every turn. It may seem that the answer is  — lcm (the smallest common multiple) of the cycle lengths, but to become equal to the initial string, it is not necessary to go through the entire cycle. The constraints allow us to calculate the length of the minimum suitable shift kj in O(len2), where len is the length of the cycle, so just iterate over the desired shift. Note that after kj operations, the cycle will return to its original form and this will happen again after kj operations.

The answer will be lcm of all kj, since each cycle individually comes to its original form after the number of operations is a multiple of its kj. 

 **Solution**
```cpp
def gcd(a, b):
    if b == 0:
        return a;
    return gcd(b, a % b)
    
    
def shift(s):
    for i in range(1, len(s) + 1):
        if s == s[i:] + s[:i]:
            return i
    
 
def solve():
    n = int(input())
    s = input()
    p = [int(x)-1 for x in input().split()]
    used = [False] * n
    ans = 1
    i = 0
    while i < n:
        ss = ''
        while not used[i]:
            ss += s[i]
            used[i] = True
            i = p[i];
        i += 1
        if len(ss) == 0:
            continue
        ln = shift(ss)
        ans = ans * ln // gcd(ans, ln)
    print(ans)
    
 
t = int(input())
for _ in range(t):
    solve()
```
[1690G - Count the Trains](../problems/G._Count_the_Trains.md "Codeforces Round 797 (Div. 3)")

Idea: [Aris](https://codeforces.com/profile/Aris "Expert Aris")

 **Tutorial**
### [1690G - Count the Trains](../problems/G._Count_the_Trains.md "Codeforces Round 797 (Div. 3)")

In the set we will keep the indices that start the trains. That is, if the array v — the real speeds of the carriages, then we will store in the network such values 2≤i that v[i]<v[i−1]. As well as the value of 0. Thus, the size of the set —is the answer to the problem. 

Consider now the operation to reduce the speed of the carriage: find such maximal index j≤k in the set, if the value ak<aj, then we should add the value k to the set, since it will start a new train. Then we should remove all subsequent indexes j from the set such that ak<aj. Thus, for all operations we will add no more than n elements to the array, and remove in total no more than 2⋅n elements from the set. We obtain the asymptotic O(m⋅logn).

 **Solution**
```cpp
#include<bits/stdc++.h>
 
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        set<int> tmp;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (tmp.empty() || a[i] < a[*tmp.rbegin()]) {
                tmp.insert(i);
            }
        }
        for (int i = 0; i < m; i++) {
            int j, d;
            cin >> j >> d;
            j--;
            a[j] -= d;
            auto it = tmp.upper_bound(j);
            if (it != tmp.begin()) {
                it = prev(it);
                if (*it == j || a[*it] > a[j]) {
                    tmp.insert(j);
                }
            } else {
                tmp.insert(j);
            }
            while (1) {
                it = tmp.upper_bound(j);
                if (it != tmp.end() && a[*it] >= a[j]) {
                    tmp.erase(it);
                } else {
                    break;
                }
            }
            cout << (int) tmp.size() << " ";
        }
        cout << 'n';
    }
}
```
