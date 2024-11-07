# Tutorial_(en)


### [1978A - Alice and Books](../problems/A._Alice_and_Books.md "Codeforces Round 953 (Div. 2)")

Note that we will always be required to take a book with the number n. Thus, the answer can be all pairs of the form (k,n), where k<n. We will find a pair with the maximum sum among these, and it will be the answer.

 **Code**
```cpp
#include <random>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
 
using namespace std;
 
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define ll long long
#define pii pair<int, int>
#define pb emplace_back
 
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto &c : a) cin >> c;
        int mx = 0;
        for (int i = 0; i < n - 1; i++) mx = max(mx, a[i]);
        cout << mx + a[n - 1] << "n";
    }
    return 0;
}
```
 
### [1978B - New Bakery](../problems/B._New_Bakery.md "Codeforces Round 953 (Div. 2)")

If b<a, then the answer is obviously equal to a⋅n. Otherwise, the profit will be maximized when k=min(b−a,n). Indeed, if we take k larger, then Bob will sell some buns for less than a coins, which is not profitable. If we take k smaller, then he will sell some buns for a coins, although he could have sold them for more. Knowing that a+(a+1)+…+(b−1)+b=a+b2⋅(b−a+1), we can find the answer. It will be equal to b+(b−k+1)2⋅k+(n−k)⋅a.

 **Code**
```cpp
#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n, a, b;
        cin >> n >> a >> b;
        if (b <= a) {
            cout << n * a << endl;
        } else {
            long long k = min(b &mdash; a + 1, n);
            cout << (b &mdash; k + 1) * n + k * (k &mdash; 1) / 2 << endl;
        }
    }
}
```
 
### [1978C - Manhattan Permutations](../problems/C._Manhattan_Permutations.md "Codeforces Round 953 (Div. 2)")

Notice that if k is odd, then there is no solution. Also notice that the maximum maxk is achieved with the permutation [n,n−1,n−2,...,1], so if k>maxk, then there is also no solution. It is claimed that for any other k, a solution exists.

Let's consider what happens if we swap x and 1 in the identity permutation. The Manhattan value for such a permutation will be equal to |x−1|+|x−1|=2⋅|x−1|. Then any even k from 0 to 2⋅(n−1) can be achieved. If k>2⋅(n−1), let's swap 1 and n elements. Notice that we have reduced the problem to a smaller size of (n−2), just now the indices start from 2 instead of 1. Now we can do exactly the same as with the identity permutation, i.e., swap 2 with some x (x>1 and x<n). The value of the permutation will change by |x−2|⋅2, so any even k from 0 to 2⋅(n−1)+2⋅(n−3) can be achieved. Notice that if we continue to do this further, in the end we will get the permutation [n,n−1,...,1], and we have proved that any even k from 0 to maxk is achievable. Hence, it is clear how to reconstruct the permutation itself in O(n) time.

 **Code**
```cpp
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--) {
        int n;
        ll k;
        cin >> n >> k;
        ll max_s = 0;
        for (int i = 0; i < n; i++) max_s += abs(n &mdash; 1 &mdash; i &mdash; i);
        if (k % 2 != 0 || k > max_s) {
            cout << "Non";
        } else {
            cout << "Yesn";
            vector<int> p(n);
            k /= 2;
            iota(p.begin(), p.end(), 0);
            for (int i = 0; k > 0; i++) {
                if (k >= n &mdash; 1 &mdash; 2 * i) {
                    swap(p[i], p[n &mdash; 1 &mdash; i]);
                    k -= n &mdash; 1 &mdash; 2 * i;
                } else {
                    swap(p[i], p[i + k]);
                    k = 0;
                }
            }
            for (int i = 0; i < n; i++) {
                cout << p[i] + 1 << " ";
            }
            cout << "n";
        }
    }
}
```
 
### [1978D - Elections](../problems/D._Elections.md "Codeforces Round 953 (Div. 2)")

Notice that if candidate i does not win initially (when no one is removed), then for their victory, we must definitely remove all candidates with numbers less than i. Because if someone remains unremoved with a number less than i, then the votes for candidate i will not increase, and the maximum number of votes for someone else will not decrease.

Let's find the winner of the election initially, for them the answer is 0, for all other candidates we need to remove all people with numbers less than i.

But sometimes these removals alone may not be enough, so we need to additionally remove several candidates so that their fans' votes go to us.

Notice that then it is enough to remove only one candidate with the maximum ai, then we will definitely win, so the answer for candidate i is either 0, or i, or i+1.

So we end up with a solution which works in O(n).

 **Code**
```cpp
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n, c;
    cin >> n >> c;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    if (n == 1) {
        cout << "0n";
        return;
    }

    int mx = *max_element(a.begin() + 1, a.end());
    int mxc = max(a[0] + c, mx);
    int winner = mxc == a[0] + c ? 0 : find(a.begin() + 1, a.end(), mx) - a.begin();
    ll sum = c;
    for (int i = 0; i < n; sum += a[i], ++i) {
        int answer;
        if (i == winner) {
            answer = 0;
        } else if (sum + a[i] >= mx) {
            answer = i;
        } else {
            answer = i + 1;
        }
        cout << answer << " n"[i == n - 1];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int test = 1;
    cin >> test;
    
    while (test--) {
        solve();
    }

    return 0;
}
```
 
### [1978E - Computing Machine](../problems/E._Computing_Machine.md "Codeforces Round 953 (Div. 2)")

Notice that it is advantageous to perform only operations of the first type first, and then only operations of the second type. Perform all possible operations of the first type on the string t and save it in t′. Perform all possible operations of the second type on the string s, using t′, and save it in s′. Calculate the prefix sums on the string s′. Let len be the length of the query range. The answer to queries with small length ranges (len<5) can be computed by simulating the proposed process. For longer strings, it can be guaranteed that in the string a with the maximum number of 1 characters, a3a4…alen−2 will match the characters s′3s′4…s′len−2, their count can be found using prefix sums. Separately check if a1, a2, alen−1, alen can become 1.

 **Code**
```cpp
#include <bits/stdc++.h>
using namespace std;
 
int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    string s, t;
    cin >> n >> s >> t;
    auto get_range = [&] (int i) {
      if (s[i] == '1') return make_pair(i, i);
      int l = -1, r = -1;
      if (i > 0 && t[i-1] == '1') l = i-1;
      else if (i > 1 && t[i-1] == '0' && s[i-2] == '0') l = i-2;
      if (i+1 < n && t[i+1] == '1') r = i+1;
      else if (i+2 < n && t[i+1] == '0' && s[i+2] == '0') r = i+2;
      if (l == -1) r = -1;
      if (r == -1) l = -1;
      return make_pair(l, r);
    };
 
    vector<int> pref(n+1);
    for (int i = 0; i < n; i++) pref[i+1] = pref[i] + (get_range(i).first != -1);
 
    int q;
    cin >> q;
    while (q--) {
      int l, r;
      cin >> l >> r;
      int ans = 0;
      if (r-l <= 5) {
        for (int i = l-1; i < r; i++) {
          auto [ll, rr] = get_range(i);
          if (ll >= l-1 && rr < r) ans++;
        }
      }
      else {
        ans = pref[r] - pref[l-1];
        for (int j: {l-1, l, r-2, r-1}) {
          auto [ll, rr] = get_range(j);
          if (ll != -1 && (ll < l-1 || rr >= r)) ans--;
        }
      }
      cout << ans << 'n';
    }
  }
}
```
 
### [1978F - Large Graph](../problems/F._Large_Graph.md "Codeforces Round 953 (Div. 2)")

Notice that since we have cyclic shifts to the right and k > 1, the diagonals parallel to the main one will be in the same connected component, except for the case with ones. Diagonals consisting of ones will be counted separately and forgotten.

After that, we can solve the problem for the one-dimensional case, where each element is a representative of its diagonal. By definition, if the GCD of some pair of elements is greater than 1, then this means that they are both divisible by some prime number. Let's find all the elements of the array-diagonals that are divisible by each prime number. Let the indices of the current prime number be c1,c2,…,ct. We will draw edges between ci and ci+1 if ci+1−ci⩽. It is claimed that the connected components in such a graph will coincide with the connected components if we draw edges between all valid pairs. Indeed, if there is an edge between two elements in the complete graph, this means that the distance between them is not greater than k, and we can reach them in the new graph either by one edge or through elements that are divisible by the same prime number.

Using the sieve of Eratosthenes, we can quickly factorize all numbers into prime divisors, after which the number of connected components in the graph can be calculated using DSU or DFS. The time complexity of this solution is O(n \log \log n).

 **Code**
```cpp
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <fstream>
#include <cassert>
#include <cstring>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <ctime>
 
using namespace std;
 
using ll = long long;
 
const int MAXA = 1e6;
 
int n, k;
vector<int> a;
vector<int> primes_x[MAXA + 1];
unordered_map<int, int> last_ind_p;
vector<bool> is_prime(MAXA + 1, true);
vector<int> primes;
 
void read() {
	cin >> n >> k;
	a.assign(n, 0);
	for (int& elem : a) {
		cin >> elem;
	}
}
 
vector<int> p, sz, p_rs;
 
int col(int A) {
	return (A == p[A] ? A : p[A] = col(p[A]));
}
 
void unique(int A, int B) {
	A = col(A); B = col(B);
	if (A == B) return;
	if (sz[A] < sz[B]) {
		swap(A, B);
	}
	p[B] = A;
	sz[A] += sz[B];
}
 
void solve() {
    last_ind_p.clear();
	vector<int> aa;
	for (int i = 1; i < n; i++) {
		aa.push_back(a[i]);
	}
	for (int i = 0; i < n; i++) {
		aa.push_back(a[i]);
	}
	a = aa;
	int n2 = n;
	n = a.size();
	p.assign(n, -1);
	p_rs.assign(n, -1);
	sz.assign(n, -1);
	for (int i = 0; i < n; i++) {
		p[i] = i;
		sz[i] = 1;
	}
 
	for (int i = 0; i < n2; i++) {
		p_rs[i] = i + 1;
		p_rs[2 * n2 - 2 - i] = i + 1;
	}
	vector<int> a2 = a;
	sort(a2.begin(), a2.end());
	a2.resize(unique(a2.begin(), a2.end()) - a2.begin());
    unordered_set<int> to_clean;
	for (int elem : a2) {
		int cur_elem = elem;
		for (ll p : primes) {
			if (p * p > elem) break;
			if (elem % p == 0) {
				primes_x[cur_elem].push_back(p);
                if (primes_x[cur_elem].size() == 1) {
                    to_clean.insert(cur_elem);
                }
			}
			while (elem % p == 0) {
				elem /= p;
			}
		}
		if (elem > 1) {
			primes_x[cur_elem].push_back(elem);
            if (primes_x[cur_elem].size() == 1) {
                to_clean.insert(cur_elem);
            }
		}
	}
 
	for (int i = 0; i < n; i++) {
		for (int cur_p : primes_x[a[i]]) {
			if (last_ind_p.count(cur_p) && i - last_ind_p[cur_p] <= k) {
				unique(last_ind_p[cur_p], i);
			}
			last_ind_p[cur_p] = i;
		}
	}
    for (int i : to_clean)
        primes_x[i].clear();
}
 
void write() {
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		if (p[i] == i) {
			if (a[i] > 1) {
				ans += 1;
			}
			else {
				ans += p_rs[i];
			}
		}
	}
	cout << ans << endl;
}
 
int main() {
    for (ll i = 2; i <= MAXA; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (ll j = i * i; j <= MAXA; j += i) {
                is_prime[j] = false;
            }
        }
    }
	ios_base::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        read();
        solve();
        write();
    }
}
```
