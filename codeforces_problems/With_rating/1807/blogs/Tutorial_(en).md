# Tutorial_(en)

Thank you for participating!

[1807A - Plus or Minus](../problems/A._Plus_or_Minus.md "Codeforces Round 859 (Div. 4)")

Idea: [flamestorm](https://codeforces.com/profile/flamestorm "Candidate Master flamestorm")

 **Tutorial**
### [1807A - Plus or Minus](../problems/A._Plus_or_Minus.md "Codeforces Round 859 (Div. 4)")

You need to implement what is given in the statement; for example, you can use an if-statement to output + if $a+b=c$, and - otherwise.

 **Solution**
```cpp
#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX = 200007;
const int MOD = 1000000007;
 
void solve() {
	int a, b, c;
	cin >> a >> b >> c;
	if (a + b == c) {cout << "+n";}
	else {cout << "-n";}	
}
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
	// solve();
}


```
[1807B - Grab the Candies](../problems/B._Grab_the_Candies.md "Codeforces Round 859 (Div. 4)")

Idea: [mesanu](https://codeforces.com/profile/mesanu "Expert mesanu")

 **Tutorial**
### [1807B - Grab the Candies](../problems/B._Grab_the_Candies.md "Codeforces Round 859 (Div. 4)")

Let $s_e$ be the total number of candies with all bags with an even number of candies, and $s_o$ — the total of all bags with an odd number of candies. If $s_e \leq s_o$, then the answer is NO, because at the end Mihai (who takes only even numbers of candies) will have less candies than Bianca.

Otherwise if $s_e > s_o$ the answer is YES. The construction is to simply put all even bags first, and then all odd bags: since all even bags come before all odd bags and $s_e>s_o$, at any point in time Mihai will have more candies than Bianca.

The time complexity is $\mathcal{O}(n)$.

 **Solution**
```cpp
#include <bits/stdc++.h>
using namespace std;
 
void solve()
{
    int n;
    cin >> n;
    int x, odd = 0, even = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> x;
        if(x%2 == 0)
        {
            even+=x;
        }
        else
        {
            odd+=x;
        }
    }
    if(even > odd)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
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
[1807C - Find and Replace](../problems/C._Find_and_Replace.md "Codeforces Round 859 (Div. 4)")

Idea: [flamestorm](https://codeforces.com/profile/flamestorm "Candidate Master flamestorm")

 **Tutorial**
### [1807C - Find and Replace](../problems/C._Find_and_Replace.md "Codeforces Round 859 (Div. 4)")

Let's solve a harder problem: given a string $s$ and a binary string $t$, can we make $s$ into $t$ using the find and replace operations?

We can simply iterate through each character of $s$ and see the bit it has turned to in $t$ (that is, $s_i \to t_i$ for each $i$). Keep track of each change, and see if there is some letter that needs to be turned into both $\texttt{0}$ and $\texttt{1}$. If there is some letter, it is impossible, since each operation requires changing all occurrences of a letter into the same bit. Otherwise, it is possible, and we can directly change each letter into the bit it needs to be. (See the implementation for a better understanding.)

Now for this problem, since there are only two alternating binary strings of length $n$ ($\texttt{01010...}$ and $\texttt{10101...}$), we can simply check both. (Actually, we only have to check one — do you see why?) The time complexity is $\mathcal{O}(n)$.

 **Solution**
```cpp
#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX = 200007;
const int MOD = 1000000007;
 
void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	int mp[26];
	for (int i = 0; i < 26; i++) {
		mp[i] = -1;
	}
	for (int i = 0; i < n; i++) {
		int curr = (s[i] - 'a');
		if (mp[curr] == -1) {
			mp[curr] = (i % 2);
		}
		else {
			if (mp[curr] != (i % 2)) {cout << "NOn"; return;}
		}
	}
	cout << "YESn";
}
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
	// solve();
}


```
[1807D - Odd Queries](../problems/D._Odd_Queries.md "Codeforces Round 859 (Div. 4)")

Idea: [SlavicG](https://codeforces.com/profile/SlavicG "Candidate Master SlavicG")

 **Tutorial**
### [1807D - Odd Queries](../problems/D._Odd_Queries.md "Codeforces Round 859 (Div. 4)")

Note that for each question, the resulting array is $$[a_1, a_2, \dots, a_{l-1}, k, \dots, k, a_{r+1}, a_{r+2}, \dots, a_n].$$

So, the sum of the elements of the new array after each question is $$a_1 + \dots + a_{l-1} + (r-l+1) \cdot k + a_{r+1} + \dots + a_n.$$

We can compute $a_1 + \dots + a_{l-1}$ and $a_{r+1} + \dots + a_n$ in $\mathcal{O}(1)$ time by precomputing the sum of all prefixes and suffixes, or alternatively by using the prefix sums technique. So we can find the sum each time in $\mathcal{O}(1)$ per question, and just check if it's odd or not. The time complexity is $\mathcal{O}(n+q)$.

 **Solution**
```cpp
#include <iostream>
 
using namespace std;
long long n,a[200005],q,sum=0,pref[200005],t;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--)
    {
        sum = 0;
        cin >> n >> q;
        for(int i=1;i<=n;i++){
            cin >> a[i];
            sum+=a[i];
            pref[i]=pref[i-1];
            pref[i]+=a[i];
        }
        for(int i = 0; i < q; i++){
            long long l,r,k;
            cin >> l >> r >> k;
            long long ans = pref[n]-(pref[r]-pref[l-1])+k*(r-l+1);
            if(ans%2==1){
                cout<<"YES"<<endl;
            }
            else
            {
                cout<<"NO"<<endl;
            }
        }
    }
}
 


```
[1807E - Interview](../problems/E._Interview.md "Codeforces Round 859 (Div. 4)")

Idea: [SlavicG](https://codeforces.com/profile/SlavicG "Candidate Master SlavicG")

 **Tutorial**
### [1807E - Interview](../problems/E._Interview.md "Codeforces Round 859 (Div. 4)")

Consider this question: if we take some range $[a_l, \dots, a_r]$ of piles, how do we know if it contains the special pile? 

* If it doesn't contain the special pile, then the total weight should be $a_l + a_{l+1} + \dots + a_r$ grams, since each stone weighs one gram.
* If it does contain the special pile, then the total weight should be $a_l + a_{l+1} + \dots + a_r + 1$ grams, since each stone weighs one gram except for the special stone, which weighs two grams.

 So we can determine if a range $[a_l, \dots, a_r]$ contains the special pile using a single query.Now we can binary search for the answer: first check the range $[a_1, \dots, a_{\frac{n}{2}}]$. If it has the special pile, then split it into two parts and check if one of them has the special stone; otherwise, check the other half. This will take at most $\lceil \log_2(2 \cdot 10^5) \rceil = 18$ queries, which is well below the limit of $30$.

The time complexity is $\mathcal{O}(n)$ (for reading the input).

 **Solution**
```cpp
#include <bits/stdc++.h>
using ll=long long;
using ld=long double;
int const INF=1000000005;
ll const LINF=1000000000000000005;
ll const mod=1000000007;
ld const PI=3.14159265359;
ll const MAX_N=3e5+5;
ld const EPS=0.00000001;
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define endl 'n'
#define sz(a) (int)a.size()
#define CODE_START  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
ll t,n,a[2000005],pref[2000005];
int32_t main(){
//CODE_START;
#ifdef LOCAL
//ifstream cin("input.txt");
#endif
cin>>t;
while(t--){
    cin>>n;
    for(ll i=1;i<=n;i++)
    {
        cin>>a[i];
        pref[i]=pref[i-1]+a[i];
    }
    ll l=1,r=n,ans=0;
    while(l<=r){
            ll mid=(l+r)/2;
        cout<<"? "<<(mid-l+1)<<' ';
        for(ll i=l;i<=mid;i++)
        {
            cout<<i<<' ';
        }
        cout<<endl<<flush;
        ll x=0;
        cin>>x;
        if(x==pref[mid]-pref[l-1]){
            l=mid+1;
        }else {
            r=mid-1;
            ans=mid;
        }
    }
    cout<<"! "<<ans<<endl<<flush;
}
}


```
[1807F - Bouncy Ball](../problems/F._Bouncy_Ball.md "Codeforces Round 859 (Div. 4)")

Idea: [mesanu](https://codeforces.com/profile/mesanu "Expert mesanu")

 **Tutorial**
### [1807F - Bouncy Ball](../problems/F._Bouncy_Ball.md "Codeforces Round 859 (Div. 4)")

We can see that there are at most $4\cdot n \cdot m$ states the ball can be in, because there are $n \cdot m$ cells and $4$ states of direction. We can simulate the bouncing process, keeping count of the bounces until we arrive at the finish cell when we can output the answer, or we arrive at a previously visited state and end up in a loop, then we can output -1.

Bonus: Can you prove there are at most $2\cdot n \cdot m$ states for any given starting position?

 **Solution**
```cpp
#include <bits/stdc++.h>
using namespace std;
 
void solve()
{
    int n, m, x1, y1, x2, y2;
    string d_string;
    cin >> n >> m >> x1 >> y1 >> x2 >> y2;
    x1--;x2--;y1--;y2--;
    cin >> d_string;
    int d = (d_string[0] == 'U' ? 1+(d_string[1] == 'R' ? 2 : 0) : 0+(d_string[1] == 'R' ? 2 : 0));
    bool vis[n][m][4];
    memset(vis, false, sizeof(vis));
    int i = x1, j = y1;
    int bounces = 0;
    while(!vis[i][j][d])
    {
        if(i == x2 && j == y2){cout << bounces << endl; return;}
        int na = 0;
        if(d%2 == 1 && i == 0){d-=1;na++;}
        if(d%2 == 0 && i == n-1){d+=1;na++;}
        if(d >= 2 && j == m-1){d-=2;na++;}
        if(d < 2 && j == 0){d+=2;na++;}
        bounces+=min(1, na);
        if(vis[i][j][d])
        {
            break;
        }
        vis[i][j][d] = true;
        if(d%2 == 1){i--;}else{i++;}
        if(d >= 2){j++;}else{j--;}
    }
    cout << -1 << endl;
}
 
int32_t main(){
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}
```
[1807G1 - Subsequence Addition (Easy Version)](../problems/G1._Subsequence_Addition_(Easy_Version).md "Codeforces Round 859 (Div. 4)")

Idea: [flamestorm](https://codeforces.com/profile/flamestorm "Expert flamestorm")

 **Tutorial**
### [1807G1 - Subsequence Addition (Easy Version)](../problems/G1._Subsequence_Addition_(Easy_Version).md "Codeforces Round 859 (Div. 4)")

Firstly, let's note that it doesn't matter in what order we add the elements to the array, since if we can add an element in any position, if it's possible to get the said elements of the array, then we can obtain them in any order.

Now, let's note that it's always optimal to obtain the needed elements in sorted order (since we only use smaller values in order to obtain the current one), so we will consider the array $c$ as sorted. If the first element of the array isn't $1$ then we immediately know such an array doesn't exist. Otherwise, we can use dynamic programming for finding out if the remaining $n - 1$ elements are obtainable. Let's denote $dp_s$ a boolean array which tells us whether sum $s$ is obtainable. Initially, $dp_1 = 1$ (since the first element is guaranteed to be $1$). We will go in increasing order of $c_i$ and if we calculated an element to be obtainable in the past, we update all obtainable values with the new $c_i$ value. We do this in $O(n \cdot 5000)$, by going through all sums $s$ and updating $dp_s = dp_s | dp_{s - c_i}$ ($dp_s$ is true if it already was true, or if $dp_{s - c_i}$ was true and we add to that sum the new value $c_i$.

The total time complexity of this solution is $O(n \cdot 5000)$.

 **Solution**
```cpp
#include "bits/stdc++.h"
using namespace std;
 
#define ll long long
 
#define          all(v)              v.begin(), v.end()
#define         rall(v)              v.rbegin(),v.rend()
 
#define            pb                push_back
#define          sz(a)               (int)a.size()
 
void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(all(a));
    if(a[0] != 1) {
        cout << "NOn";
        return;
    }
    vector<int> dp(5005, 0);
    dp[1] = 1;
    for(int i = 1; i < n; ++i) {
        if(!dp[a[i]]) {
            cout << "NOn";
            return;
        }
        for(int j = 5000; j >= a[i]; --j) {
            dp[j] |= dp[j - a[i]];
        }
    }
    cout << "YESn";
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
[1807G2 - Subsequence Addition (Hard Version)](../problems/G2._Subsequence_Addition_(Hard_Version).md "Codeforces Round 859 (Div. 4)")

Idea: [flamestorm](https://codeforces.com/profile/flamestorm "Expert flamestorm")

 **Tutorial**
### [1807G2 - Subsequence Addition (Hard Version)](../problems/G2._Subsequence_Addition_(Hard_Version).md "Codeforces Round 859 (Div. 4)")

Let's prove that for an array $a$ that was created by using a number of operations, with a sum of elements $s$ we can add into $a$ any number $x$ ($1 \leq x \leq s$).

Suppose that it is true that in the array $a$ with some length $l$ we introduce a number $x$ ($1 \leq x \leq sum_a$). Then after introducing we can create using the initial elements of the array any number $b$ ($1 \leq b \leq sum_a$) and using the element $x$ and some subset of the initial elements we can create any number $b$ ($x \leq b \leq sum_a+x$), and because $x \leq sum_a$ we proved that for the new array of length $l+1$ we can still create any number between $1$ and $sum_a+x$.

Since it is true for the initial array, we can use induction and this fact to prove it is true for all arrays. So we just need to verify if our array satisfies this condition. We should sort the array and check for each $i$ ($2 \leq i \leq n$) if $c_i \leq \sum_{j = 1}^{i-1}c_j$.

 **Solution**
```cpp
#include "bits/stdc++.h"
using namespace std;
 
#define ll long long
 
#define          all(v)              v.begin(), v.end()
#define         rall(v)              v.rbegin(),v.rend()
 
#define            pb                push_back
#define          sz(a)               (int)a.size()
 
void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(all(a));
    if(a[0] != 1) {
        cout << "NOn";
        return;
    }
    long long sum = a[0];
    for(int i = 1; i < n; ++i) {
        if(sum < a[i]) {
            cout << "NOn";
            return;
        }
        sum += a[i];
    }
    cout << "YESn";
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
