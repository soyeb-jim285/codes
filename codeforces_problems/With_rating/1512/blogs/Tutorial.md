# Tutorial

[1512A - Spy Detected!](../problems/A._Spy_Detected!.md "Codeforces Round 713 (Div. 3)")

Author: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1512A - Spy Detected!](../problems/A._Spy_Detected!.md "Codeforces Round 713 (Div. 3)")

To find a number that differs from the rest of the numbers in the array, you need to iterate through the array, maintaining two pairs of numbers (x1,c1) and (x2,c2), where xi is a number from the array, ci is how many times the number xi occurs in the array.

Then, to get an answer, you need to find the position of the xi that occurs in the array exactly once (i.e. ci=1).

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int &e : v) {
        cin >> e;
    }
    vector<int> a = v;
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
        if (v[i] != a[1]) {
            cout << i + 1 << "n";
        }
    }
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        solve();
    }
    return 0;
}
```
[1512B - Almost Rectangle](../problems/B._Almost_Rectangle.md "Codeforces Round 713 (Div. 3)")

Author: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1512B - Almost Rectangle](../problems/B._Almost_Rectangle.md "Codeforces Round 713 (Div. 3)")

f two asterisks are in the same row, then it is enough to select any other row and place two asterisks in the same columns in it.

If two asterisks are in the same column, then you can do the same.

If none of the above conditions are met and the asterisks are at positions (x1,y1), (x2,y2), then you can place two more asterisks at positions (x1,y2), (x2,y1).

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)

int main() {    
    int t;
    cin >> t;
    forn(tt, t) {
        int n;
        cin >> n;
        vector<string> f(n);
        vector<pair<int,int>> p;
        forn(i, n) {
            cin >> f[i];
            forn(j, n)
                if (f[i][j] == '*')
                    p.push_back({i, j});
        }

        p.push_back(p[0]);
        p.push_back(p[1]);
        if (p[0].first == p[1].first) {
            p[2].first = (p[2].first + 1) % n;
            p[3].first = (p[3].first + 1) % n;
        } else if (p[0].second == p[1].second) {
            p[2].second = (p[2].second + 1) % n;
            p[3].second = (p[3].second + 1) % n;
        } else
            swap(p[2].first, p[3].first);

        f[p[2].first][p[2].second] = '*';
        f[p[3].first][p[3].second] = '*';
        forn(i, n)
            cout << f[i] << endl;
    }
}
```
[1512C - A-B Palindrome](../problems/C._A-B_Palindrome.md "Codeforces Round 713 (Div. 3)")

Author: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1512C - A-B Palindrome](../problems/C._A-B_Palindrome.md "Codeforces Round 713 (Div. 3)")

First, let's find such positions i (1≤i≤n) such that s[i]≠'?' (symbols in symmetric positions are uniquely determined): 

* If s[n−i+1]='?', then s[n−i+1]=s[i];
* If s[i]≠s[n−i+1], then at the end we will not get a palindrome in any way, so the answer is '-1'.

Note that after such a replacement, the remaining characters '?' are split into pairs, except maybe the central one. If the center character is '?' then it is necessary to put the character '0' if a is odd, or '1' if b is odd (if neither a, nor b is odd, then the answer is '-1').

Now the remaining characters '?' are split into pairs (i.e. if s[i]='?', then s[n−i+1]='?'). This allows the remaining characters '0' and '1' to be replaced greedily: 

* If s[i]='?' and a>1, then s[i]=s[n−i+1]='0' and decrease a for 2;
* If s[i]='?' and b>1, then s[i]=s[n−i+1]='1' and decrease b for 2;
* Otherwise the answer is '-1'.
 **Solution**
```cpp
#include <bits/stdc++.h>
using namespace std;

void no() {
  cout << "-1" << endl;
}

void solve() {
  int a, b;
  cin >> a >> b;
  string s;
  cin >> s;
  for (int times = 0; times < 2; times++) {
    for (int i = 0; i < (int) s.size(); i++) {
      int j = (int) s.size() - i - 1;
      if (s[i] != '?') {
        if (s[j] == '?') {
          s[j] = s[i];
        } else if (s[i] != s[j]) {
          no();
          return;
        }
      }
    }
    reverse(s.begin(), s.end());
  }
  a -= count(s.begin(), s.end(), '0');
  b -= count(s.begin(), s.end(), '1');
  int ques = count(s.begin(), s.end(), '?');
  bool emptyMid = (s.size() % 2 == 1 && s[s.size() / 2] == '?');
  if (a < 0 || b < 0 || a + b != ques || (emptyMid && a % 2 == 0 && b % 2 == 0)) {
    no();
    return;
  }
  if (a % 2 == 1 || b % 2 == 1) {
    int i = s.size() / 2;
    if (s[i] != '?') {
      no();
      return;
    }
    s[i] = (a % 2 == 1 ? '0' : '1');
    if (a % 2 == 1) {
      a--;
    } else {
      b--;
    }
  }
  if (a % 2 == 1 || b % 2 == 1) {
    no();
    return;
  }
  for (int i = 0; i < (int) s.size(); i++) {
    if (s[i] == '?') {
      int j = s.size() - i - 1;
      if (a > 0) {
        a -= 2;
        s[i] = s[j] = '0';
      } else {
        b -= 2;
        s[i] = s[j] = '1';
      }
    }
  }
  cout << s << endl;
}

int main() {
  int tests;
  cin >> tests;
  while (tests-- > 0) {
    solve();
  }
  return 0;
}
```
[1512D - Corrupted Array](../problems/D._Corrupted_Array.md "Codeforces Round 713 (Div. 3)")

Author: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1512D - Corrupted Array](../problems/D._Corrupted_Array.md "Codeforces Round 713 (Div. 3)")

What is the sum of all the elements in b? This is twice the sum of all the elements in a + x.

Denote by B the sum of all the elements of b. Let's iterate over which of the array elements was added as the sum of the elements a (let's denote, for a). Then, x = B−2⋅A. It remains to check that the element x is present in the array b, this can be done using a hash table or a binary search tree.

 **Solution**
```cpp
#include <bits/stdc++.h>
using namespace std;

void no() {
  cout << "-1" << endl;
}

void solve() {
  int n;
  cin >> n;
  vector<int> b(n + 2);
  for (int &x : b) {
    cin >> x;
  }

  multiset<int> have(b.begin(), b.end());
  long long sum = accumulate(b.begin(), b.end(), 0LL);
  for (int x : b) {
    have.erase(have.find(x));
    sum -= x;
    if (sum % 2 == 0 && sum <= 2'000'000'000 && have.find(sum / 2) != have.end()) {
      have.erase(have.find(sum / 2));
      for (int y : have) {
        cout << y << " ";
      }
      cout << endl;
      return;
    }
    sum += x;
    have.insert(x);
  }
  no();
}

int main() {
  int tests;
  cin >> tests;
  while (tests-- > 0) {
    solve();
  }
  return 0;
}
```
[1512E - Permutation by Sum](../problems/E._Permutation_by_Sum.md "Codeforces Round 713 (Div. 3)")

Author: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1512E - Permutation by Sum](../problems/E._Permutation_by_Sum.md "Codeforces Round 713 (Div. 3)")

It is easy to show that if we choose k numbers from a permutation of length n, then the minimum sum of k numbers is k(k+1)2, the maximum sum is k(2n+1−k)2 and any sum between them is achievable (that is, you can choose exactly k numbers from n so that their sum is equal to the desired one).

This fact allows us to implement the following greedy solution: 

* Denote for low(k)=k∑i=1i=k(k+1)2, for high(n,k)=n∑i=n−k+1i=k(2n+1−k)2 and for k=r−l+1;
* We will consider the numbers i=n,n−1,…,1 and determine whether to put them in the segment [l,r] or not;
* If k>0, high(i,k)≥s and s−i≥low(k−1), then put the number i in the segment [l,r] , decrease s by i, decrease k by 1;
* Otherwise, we will not put the number i in the segment [l,r].

In the end, if s=0, then we have chosen r−l+1 a number with the sum of s, so the remaining number can be arranged in any order. If at the end s>0, then there is no way to select r−l+1 a number from 1,2,…,n with the sum of s.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n, l, r, s;
    cin >> n >> l >> r >> s;
    l--; r--;
    for (int first = 1; first + (r - l) <= n; first++) {
        int sum = 0;
        for (int i = l; i <= r; i++) {
            sum += first + (i - l);
        }
        if (sum <= s && s - sum <= r - l + 1) {
            int needAdd = r - (s - sum) + 1;
            vector<int> ans(n);
            set<int> non_blocked;
            for (int i = 1; i <= n; i++) {
                non_blocked.insert(i);
            }
            for (int i = l; i <= r; i++) {
                ans[i] = first + (i - l);
                if (i >= needAdd) {
                    ans[i]++;
                }
                non_blocked.erase(ans[i]);
            }
            if (ans[r] > n) {
                continue;
            }
            non_blocked.erase(ans[r]);
            for (int i = 0; i < l; i++) {
                ans[i] = *non_blocked.begin();
                non_blocked.erase(non_blocked.begin());
            }
            for (int i = r + 1; i < n; i++) {
                ans[i] = *non_blocked.begin();
                non_blocked.erase(non_blocked.begin());
            }
            for (int i : ans) {
                cout << i << " ";
            }
            cout << "n";
            return;
        }
    }
    cout << "-1n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n;
    cin >> n;
    while (n--) {
        solve();
    }
}
```
[1512F - Education](../problems/F._Education.md "Codeforces Round 713 (Div. 3)")

Author: [sodafago](https://codeforces.com/profile/sodafago "Specialist sodafago")

 **Tutorial**
### [1512F - Education](../problems/F._Education.md "Codeforces Round 713 (Div. 3)")

Since the array a does not decrease, if we want to get the position x at some point, it is best to get it as early as possible, because if we get it earlier, we will earn no less money.

Therefore, the solution looks like this — rise to some position and earn money on it for a laptop. Let's go through the number of the position and use simple formulas to calculate the number of days it takes to raise to this position and the number of days it takes to buy a laptop.

From all the options, choose the minimum one.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
    int n, c;
    cin >> n >> c;
    vector<int> a(n);
    vector<int> b(n - 1);
    for (int &e : a) {
        cin >> e;
    }
    for (int &e : b) {
        cin >> e;
    }
    b.push_back(0);
    ll ans = 1e18;
    ll cur = 0;
    ll bal = 0;
    for (int i = 0; i < n; i++) {
        ans = min(ans, cur + max(0ll, c - bal + a[i] - 1) / a[i]);
        ll newDays = max(0ll, b[i] - bal + a[i] - 1) / a[i];
        cur += newDays + 1;
        bal += a[i] * newDays - b[i];
    }
    cout << ans << "n";
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        solve();
    }
    return 0;
}
```
[1512G - Short Task](../problems/G._Short_Task.md "Codeforces Round 713 (Div. 3)")

Author: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1512G - Short Task](../problems/G._Short_Task.md "Codeforces Round 713 (Div. 3)")

Note that n≤d(n)≤107 (107 is the maximum value of c in the problem), so it is enough for every n=1..107 to calculate the value of d(n).

To calculate the value of d(n), you can use the sieve of Eratosthenes and get the solution for O(107log(107)).

Also, you can use the linear sieve of Eratosthenes to find the minimum divisor for each n=1..107 and use the multiplicativity of the function d(n): 

* d(a⋅b)=d(a)⋅d(b) if gcd(a,b)=1.
 **Solution**
```cpp
#include <bits/stdc++.h>
using namespace std;

const int N = (int) 1e7 + 100;

long long s[N];
int d[N];
int ans[N];

int main() {
  fill(d, d + N, -1);
  d[1] = 1;
  for (int i = 2; i * i < N; i++) {
    if (d[i] == -1) {
      d[i] = i;
      for (int j = i * i; j < N; j += i) {
        if (d[j] == -1) {
          d[j] = i;
        }
      }
    }
  }
  s[1] = 1;
  for (int i = 2; i < N; i++) {
    if (d[i] == -1) {
      d[i] = i;
      s[i] = i + 1;
    } else {
      int j = i;
      s[i] = 1;
      while (j % d[i] == 0) {
        j /= d[i];
        s[i] = s[i] * d[i] + 1;
      }
      s[i] *= s[j];
    }
  }
  fill(ans, ans + N, -1);
  for (int i = N - 1; i > 0; i--) {
    if (s[i] < N) {
      ans[s[i]] = i;
    }
  }
  int tests;
  cin >> tests;
  while (tests-- > 0) {
    int c;
    cin >> c;
    cout << ans[c] << endl;
  }
  return 0;
}
```
