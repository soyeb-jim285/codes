# Tutorial_(en)

Sorry for the delay in publishing the editorial. If anything is unclear or missing, please let me know in the comments.

In all the problems, reading the hints is a must as the solution continues from there.

[1944A - Destroying Bridges](../problems/A._Destroying_Bridges.md "Codeforces Round 934 (Div. 2)")

Idea: [Dominater069](https://codeforces.com/profile/Dominater069 "Grandmaster Dominater069")  
Preparation: [Dominater069](https://codeforces.com/profile/Dominater069 "Grandmaster Dominater069")  
Editorial: [Dominater069](https://codeforces.com/profile/Dominater069 "Grandmaster Dominater069")

 **Hint 1**What is the minimum number of bridges to burn if we want to make exactly i islands visitable from 1?

 **O(n) Solution**Atleast i⋅(n−i) bridges need to burnt (the bridges connecting the i reachable islands and the n−i non-reachable islands). 

A simple O(n) solution is for every i from 1 to n, check if i⋅(n−i)≤k, in which case print i and break.

 **Hint 2**What is the answer when k≥n−1.

 **Hint 3**When k<n−1, is it possible to make any island non-visitable?

 **O(1) Solution**When k≥n−1, the answer is 1 since we can just destroy all bridges (1,i) for 2≤i≤n. 

Otherwise, suppose we tried to make some set of i islands non-visitable, and the other n−i nodes reachable from 1. Then we need to burn atleast i⋅(n−i) bridges (the bridges connecting the 2 sets). It is not hard to see that this function attains the minimum value when i=1 or i=n−1 for 1≤i<n. Hence the minimum number of bridges to burn always exceeds n−1.

 **Formal Proof**The function f(x)=x⋅(n−x) is a quadratic function in x, which attains maximum value at x=n2, and the value decreasing proportionally as the distance from n2 increases. This means that f(1)=f(n−1), and f(1)>f(i) for all (2≤i≤(n−2)).

 **Code (O(n))**
```cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while (t--){
        int n, k; cin >> n >> k;
        for (int i = 1; i <= n; i++){
            if (i * (n - i) <= k){
                cout << i << "n";
                break;
            }
        }
    }
    return 0;
}
```
 **Code (O(1))**
```cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while (t--){
        int n, k; cin >> n >> k;
        if (k >= n - 1) cout << 1 << "n";
        else cout << n << "n";
    }
    return 0;
}
```
[1944B - Equal XOR](../problems/B._Equal_XOR.md "Codeforces Round 934 (Div. 2)")

Idea : [satyam343](https://codeforces.com/profile/satyam343 "Master satyam343")  
Preparation : [satyam343](https://codeforces.com/profile/satyam343 "Master satyam343")  
Editorial : [Dominater069](https://codeforces.com/profile/Dominater069 "Grandmaster Dominater069")

 **Hint 1**Group numbers according to how many times they occur in a[1...n].

 **Hint 2**The group of numbers having 0 occurrences in a[1...n] is of the same size as the group of numbers having 2 occurences in a[1...n].

 **Hint 3**Try to use the 0 and 2 occurrence numbers first, and then if we still need more, we can use the 1 occurence numbers. Remember that we have to form sequences of size 2⋅k which is even.

 **Solution**We can append any 2 occurrence numbers to our sequence l and any 0 occurrence numbers to our sequence r without any issue because the xor value will cancel out. We do this while our sequence sizes are less than 2⋅k. At the end of this process, l and r will have the same size due to Hint 2.

Now, we use as many 1 occurrence numbers appending to both l and r as needed. Since we append to both sequences, the xor value of the 2 sequences will be the same.

If we had to solve for odd sequence sizes, we could take a 1 occurrence number at the very start to make it even, and then run the same process, but if there are no 1 occurrence numbers at all, we fail with this method.

 **Code**
```cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while (t--){
        int n, k; 
        cin >> n >> k; 
        k = 2 * k;
        
        vector <int> a(2 * n), occ(n + 1, 0);
        
        for (auto &x : a) cin >> x;
        for (int i = 0; i < n; i++) occ[a[i]]++;
        
        vector <int> g0, g1, g2;
        for (int i = 1; i <= n; i++){
            if (occ[i] == 0) g0.push_back(i);
            else if (occ[i] == 1) g1.push_back(i);
            else g2.push_back(i);
        }
        
        int v = 0;
        for (auto x : g2){
            if (v < k){
                v += 2;
                cout << x << " " << x << " ";
            }
        }
        for (auto x : g1){
            if (v < k){
                v++;
                cout << x << " ";
            }
        }
        cout << "n";
        
        v = 0;
        for (auto x : g0){
            if (v < k){
                v += 2;
                cout << x << " " << x << " ";
            }
        }
        for (auto x : g1){
            if (v < k){
                v++;
                cout << x << " ";
            }
        }
        cout << "n";
    }
    return 0;
}
```
[1943A - MEX Game 1](https://codeforces.com/contest/1943/problem/A "Codeforces Round 934 (Div. 1)")

Idea : [Dominater069](https://codeforces.com/profile/Dominater069 "Grandmaster Dominater069")  
Preparation : [Dominater069](https://codeforces.com/profile/Dominater069 "Grandmaster Dominater069")  
Editorial : [Dominater069](https://codeforces.com/profile/Dominater069 "Grandmaster Dominater069") 

 **Hint 1**Alice can adapt to Bob's strategy. Try to keep that in mind.

 **Big Hint 2**Whenever Bob chooses i, and if there are any copies of i left, Alice can take i on her next move.

 **Hint 3**Let f be the frequency array of a. You can ignore all f(i)≥2 due to the previous hint. Now the answer is some simple casework.

 **Solution**For any i s.t. fi≥2, whenever Bob chooses to remove an occurence of i, on the next move Alice simply chooses i herself (if she hasn't already taken i before that). Thus, we only focus on fi≤1 now. 

The answer is min(first i s.t. f(i)=0, second i s.t. f(i)=1).

Obviously, Alice can't do better than the mex of array (first i s.t. f(i)=0). Further, among f(i)=1, Alice can save atmost 1 i after which Bob will remove the smallest f(i)=1 he can find. This is optimal for Bob as well because he cannot do better when Alice removes the (first i s.t. f(i)=1) on her first move.

 **Code**
```cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        vector <int> f(n + 1, 0);
        
        for (int i = 0; i < n; i++){
            int x; cin >> x;
            f[x]++;
        }
        
        int c = 0;
        for (int i = 0; i <= n; i++){
            c += (f[i] == 1);
            if ((c == 2) || (f[i] == 0)){
                cout << i << "n";
                break;
            }
        }
    }
    return 0;
}
```
[1943B - Non-Palindromic Substring](https://codeforces.com/contest/1943/problem/B "Codeforces Round 934 (Div. 1)")

Idea : [errorgorn](https://codeforces.com/profile/errorgorn "International Grandmaster errorgorn"), [Dominater069](https://codeforces.com/profile/Dominater069 "Grandmaster Dominater069")  
Preparation : [Dominater069](https://codeforces.com/profile/Dominater069 "Grandmaster Dominater069")  
Editorial : [Dominater069](https://codeforces.com/profile/Dominater069 "Grandmaster Dominater069")

 **Hint 1**When is a string not k-good? (Ignore the trivial edge cases of k=1 and k=n).

 **Hint 2**What happens when s[i....j] and s[i+1....j+1] are both palindromes?

 **Solution**We first try to find the answer for a string

Let k=j−i+1, s[i....j] -> I and s[i+1...j+1] -> II are both palindromes.

Then si=sj (due to I)  
sj=si+2 (due to II)  
si+2=sj−2 (due to I)  
sj−2=si+4 (due to II)  
and so on.... you can see that it forces si=si+2=si+4=..... A similiar reasoning gives you si+1=si+3=si+5.

Further, if k is even, i and j have different parities, but si=sj implies that all characters must be equal actually.

We mentioned that the edge cases are 1 and n, but why exactly? How does the analysis fail for them?(Left as a exercise)

So, the condition for a string to be k-good can be written as follows : k=1 : never possible  
1<k<n, odd : not an alternating string  
1<k<n, even : not all characters same  
k=n : non-palindromic string

Now onto substring queries. The second and third things are easy to handle, you can store the next position where si≠si+2 and si≠si+1 respectively. Checking if a substring is a palindrome is standard with various methods such as string hashing or manacher's algorithm.

 **Code**
```cpp
#include <bits/stdc++.h>
using namespace std;

#define INF (int)1e18

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

vector<int> manacher_odd(string s) {
    int n = s.size();
    s = "$" + s + "^";
    vector<int> p(n + 2);
    int l = 1, r = 1;
    for(int i = 1; i <= n; i++) {
        p[i] = max(0, min(r - i, p[l + (r - i)]));
        while(s[i - p[i]] == s[i + p[i]]) {
            p[i]++;
        }
        if(i + p[i] > r) {
            l = i - p[i], r = i + p[i];
        }
    }
    return vector<int>(begin(p) + 1, end(p) - 1);
}

vector<int> manacher(string s) {
    string t;
    for(auto c: s) {
        t += string("#") + c;
    }
    auto res = manacher_odd(t + "#");
    return vector<int>(begin(res) + 1, end(res) - 1);
}

#define int long long

void Solve() 
{
    int n, q; cin >> n >> q;

    string s; cin >> s;
    auto v = manacher(s);
    for (auto &x : v) x--;

    // we also need to know if all same, and all alternating 
    set <int> s1, s2;
    for (int i = 0; i < n - 1; i++){
        if (s[i] != s[i + 1]) s1.insert(i);
        if (i != n - 1 && s[i] != s[i + 2]) s2.insert(i);
    }

    while (q--){
        int l, r; cin >> l >> r;
        l--;
        r--;

        if (l == r){
            cout << 0 << "n";
            continue;
        }
        
        int len = r - l + 1;

        int ans;
        auto it = s1.lower_bound(l);
        if (it == s1.end() || (*it) >= r){
            ans = 0;
        } else {
            it = s2.lower_bound(l);
            if (it == s2.end() || (*it) >= r - 1){
                ans = ((len - 1)/ 2) * (((len - 1) / 2) + 1);
            } else {
                ans =  len * (len - 1) / 2 - 1;
            }
        }

        if (v[l + r] < (r - l + 1)) ans += len;

        cout << ans << "n";
    }
}

int32_t main() 
{
    auto begin = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // freopen("in",  "r", stdin);
    // freopen("out", "w", stdout);
    
    cin >> t;
    for(int i = 1; i <= t; i++) 
    {
        //cout << "Case #" << i << ": ";
        Solve();
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.n"; 
    return 0;
}
```
[1943C - Tree Compass](https://codeforces.com/contest/1943/problem/C "Codeforces Round 934 (Div. 1)")

Idea: [Everule](https://codeforces.com/profile/Everule "Grandmaster Everule")  
Preparation: [Dominater069](https://codeforces.com/profile/Dominater069 "Grandmaster Dominater069")  
Editorial: [Dominater069](https://codeforces.com/profile/Dominater069 "Grandmaster Dominater069")

 **Hint 1**Try to solve for line case.

 **Hint 2**You may have to use more than 1 node for certain cases. 

 **Hint 3**Extend the solution for the line to the general tree version (consider the diamater).

 **Solution**For a line, an obvious bound on the answer is ⌈n2⌉, as we can colour atmost 2 nodes per operation. I claim this is achieveable except for when n mod 4=2, where we do 1 worse. That is however still provably optimal as you can bicolour the line and operations only colours nodes black which are in the same bicolouring. 

 **Construction for line**When n mod 2=1, simply use the centre of the line and do operations of the form (centre,i) (0≤i≤⌊n2⌋).  
When n mod 4=0, for convenience let the line be 1,2,....,n. Then, we can do operations like (2,1),(3,1),(6,1),(7,1).....  
When n mod 4=2, either of the above 2 methods can be adapted to work because we are allowed 1 "extra" operation.

Now that we have the solution for the line case, lets divide into 2 cases based on parity of diamater (maximum number of nodes on a path) : 

diameter mod 2=1 : Find the centre of the diamater. Then we can simply do operations of the form (centre,i) (for all 0≤i≤⌊diameter2⌋). If this doesn't colour all nodes, then one can easily check that the diamater we found is not the real diamater, as the node which is not coloured is an endpoint of a larger diameter.

diamater mod 2=0 : Find the 2 centres of the diameter. Then the following set of operations satisfy the requirements : (centre1,i) and (centre2,i) for all odd i satisfying 1≤i≤diameter2. The intuition behind this is to basically split the nodes into 2 sets according to a bicolouring, and then 1 centre colours all nodes of a certain colour, while the other centre colours all nodes of the other colour. 

 **Code**
```cpp
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define f first
#define s second

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve() 
{
    int n;
    cin >> n;
    
    vector<vector<int>> E(n);
    
    for (int i = 1; i < n; i++){
        int u, v; cin >> u >> v;
        
        u--; v--;
        E[u].push_back(v);
        E[v].push_back(u);
    }
    
    auto bfs = [&](int s){
      vector<int> d(n, -1);
      d[s] = 0;
      queue<int> Q;
      Q.push(s);
      while (!Q.empty()){
        int v = Q.front();
        Q.pop();
        for (int w : E[v]){
          if (d[w] == -1){
            d[w] = d[v] + 1;
            Q.push(w);
          }
        }
      }
      return d;
    };
    
    vector<int> d1 = bfs(0);
    int a = max_element(d1.begin(), d1.end()) - d1.begin();
    vector<int> d2 = bfs(a);
    int b = max_element(d2.begin(), d2.end()) - d2.begin();
    vector<int> d3 = bfs(b);
    int diam = d3[max_element(d3.begin(), d3.end()) - d3.begin()] + 1;
    //if 3 we want 1, 1 if 4 we want 1 2 
    
    vector <int> ans;
    for (int i = 0; i < n; i++){
        if ((d2[i] + d3[i] == diam - 1) && ((d2[i] == diam/2) || (d3[i] == diam/2))) 
            ans.push_back(i);
    }
    
    if (diam & 1) assert(ans.size() == 1);
    else assert(ans.size() == 2);
    
    vector <pair<int, int>> ok;
    
    if (diam & 1){
        //print everything from 0 to diam/2 
        for (int i = 0; i <= diam/2; i++){
            ok.push_back({ans[0], i});
        }
    } else {
        //2 => 2 ops, 4 => 2 ops , 6 => 4 ops, 8 => 4 ops 
        int ops = ((n - 2)/4) + 1;
        int need = (diam/2) - 1;
        while (need >= 0){
            ok.push_back({ans[0], need});
            ok.push_back({ans[1], need});
            
            need -= 2;
        }
    }
    
    cout << ok.size() << "n";
    for (auto [u, r] : ok){
        cout << u + 1 << " " << r << "n";
    }
}

int32_t main() 
{
    auto begin = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++) 
    {
        //cout << "Case #" << i << ": ";
        Solve();
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
   // cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.n"; 
    return 0;
}
```
[1943D1 - Counting Is Fun (Easy Version)](https://codeforces.com/contest/1943/problem/D1 "Codeforces Round 934 (Div. 1)")

Idea : [satyam343](https://codeforces.com/profile/satyam343 "Master satyam343")  
Preparation : [satyam343](https://codeforces.com/profile/satyam343 "Master satyam343")  
Editorial : [Dominater069](https://codeforces.com/profile/Dominater069 "Grandmaster Dominater069")

 **Hint 1**Try to come up with some necessary and sufficient conditions of a good array.

 **Hint 2**Apply dp once you have a good condition.

 **Solution**All operations which include i must also either include i−1 or i+1. Hence ai≤ai−1+ai+1 must hold. Throughout the editorial treat ai=0 for (i≤0) or (i>n).

But, is this sufficient? Infact, it is and we can prove it by strong induction.

 **Proof**Group arrays according to the sum of the array. We will now apply strong induction on the sum of the array. 

Base Cases (sum = 0, 1 or 2) are all trivial.

Now, assume that the condition is sufficient for all arrays with sum <x (x≥3).  
Let us consider some array a1,a2,....,an with sum x. Let ai be the first non-zero element of a.(Observe that ai+1 can't be 0).  
We claim that either operating on [i,i+1] or [i,i+2] will give still satisfy the condition aj≤aj−1+aj+1 for all j.

Let's check it. The only time [i,i+1] operation causes an issue is when ai+2>ai+1−1+ai+3, i.e. it should necessarily hold that ai+2>ai+3, but then ai+3≤ai+2−1, and so, ai+3≤ai+2−1+ai+4, meaning [i,i+2] is valid.

Now that we have the condition, we can define a dynamic programming as follows : 

dp(i,a,b) = number of ways to make an array upto the i-th index with ai−1=a, ai=b (since only the last 2 elements are relevant).

Let the new element be c, then it is a valid way iff b≤a+c. So we have a O(n4) by iterating over all possibilities.

As a final optimization, we can speed it up to O(n3) by using prefix sums. Note that the valid values of a for fixed b and c satisfy a≥max(0,b−c), and hence maintaining prefix sums over a, we can speed it up.

 **Code**
```cpp
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define f first
#define s second

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve() 
{
    int n, k, mod; cin >> n >> k >> mod;
    
    vector<vector<int>> dp(k + 1, vector<int>(k + 1, 0));
    dp[0][0] = 1; // dp[a][b]
    
    for (int i = 1; i <= n + 2; i++){
        vector<vector<int>> ndp(k + 1, vector<int>(k + 1, 0)); // dp[b][c]
        vector<vector<int>> pref(k + 1, vector<int>(k + 1, 0)); // pref[b][a]
        
        for (int b = 0; b <= k; b++){
            pref[b][0] = dp[0][b];
            for (int a = 1; a <= k; a++){
                pref[b][a] = (pref[b][a - 1] + dp[a][b]) % mod;
            }
        }
        
        for (int b = 0; b <= k; b++){
            for (int c = 0; c <= k; c++){
                if (b > c){
                    // a must be atleast b - c 
                    ndp[b][c] = (pref[b][k] - pref[b][b - c - 1] + mod) % mod;
                } else {
                    ndp[b][c] = pref[b][k];
                }
            }
        }
        
        dp = ndp;
    }
    
    cout << dp[0][0] << "n";
}

int32_t main() 
{
    auto begin = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // freopen("in",  "r", stdin);
    // freopen("out", "w", stdout);
    
    cin >> t;
    for(int i = 1; i <= t; i++) 
    {
        //cout << "Case #" << i << ": ";
        Solve();
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.n"; 
    return 0;
}
```
[1943D2 - Counting Is Fun (Hard Version)](https://codeforces.com/contest/1943/problem/D2 "Codeforces Round 934 (Div. 1)")

Idea : [satyam343](https://codeforces.com/profile/satyam343 "Master satyam343")  
Preparation : [satyam343](https://codeforces.com/profile/satyam343 "Master satyam343")  
Editorial : [Dominater069](https://codeforces.com/profile/Dominater069 "Grandmaster Dominater069")

 **Hint 1**Try to apply Principle of Inclusion Exclusion (PIE).

 **Hint 2**You do not need to store both last elements! Only the last is enough.

 **Solution**Since there are n3 states in our dp, we will have to optimize the number of states somehow.

Let us consider all arrays and not just good arrays. An element is bad if ai>ai−1+ai+1.

Suppose, f(x1,x2,....,xk) gave us the number of arrays where each of xi are distinct and bad. (Note that other positions may be bad as well). Then, by PIE, the answer is (−1)k⋅f(x1,x2,.....,xk). 

For example, for n=3, we would want to compute f([])−f([1])−f([2])−f([3])+f([1,2])+f([1,3])+f([2,3])−f([1,2,3]). Note that f([]) is simply (k+1)n as there are no restrictions placed on the array.

This has 2n calculations, so we need to optimize it. 

First optimization : obviously, only k matters and not the exact indices. This means we only have to maintain the count of the number of indices we have made sure are bad.

Second optimization : only parity of k matters, due to the only dependence of k being (−1)k.

We now define dp(i,last,x) = number of arrays such that ai=last and the parity of bad elements (that we know of) till i is x.

Transitions : 

 * Without (necessarily) creating a bad element : dp(i,last,x)+=dp(i−1,y,x) for all 0≤y≤k. We might accidentally create more bad elements, but remember that PIE allows us to not worry about that.
* With creating a bad element : We view it as a transition from index (i−2), ai−1>ai+ai−2 for it to bad, so fix ai=l1, ai−2=l2, and you get dp(i,l1,x)+=dp(i−2,l2,1−x)⋅(max(0,k−l1−l2)).  
The max(0,k−l1−l2) term comes from the ways to choose ai−1 such that ai−1>l1+l2.

Both the transitions are optimizable with some prefix sums and running totals to get a O(n2) solution.

 **Code**
```cpp
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define f first
#define s second

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve() 
{
    int n, k, mod; cin >> n >> k >> mod;
    
    vector<vector<int>> dp(2, vector<int>(k + 1, 0));
    auto prev2 = dp;
    dp[0][0] = 1;
    
    for (int i = 1; i <= n + 1; i++){
        vector<vector<int>> ndp(2, vector<int>(k + 1, 0));
        vector<int> sum(2, 0);
        
        for (int j = 0; j < 2; j++) for (int x = 0; x <= k; x++){
            sum[j] += dp[j][x]; sum[j] %= mod;
        }
        
        for (int j = 0; j < 2; j++){
            int s1 = 0, s2 = 0;
            
            for (int x = k; x >= 0; x--){
                ndp[j][x] += sum[j];  // normal transition
                
                ndp[j][x] += s2; ndp[j][x] %= mod; // with one wrong
                
                s1 += prev2[j ^ 1][k - x]; s1 %= mod;
                s2 += s1; s2 %= mod;
            }
        }
        
        prev2 = dp;
        dp = ndp;
    }
    
    int ans = (dp[0][0] - dp[1][0] + mod) % mod;
    cout << ans << "n";
}

int32_t main() 
{
    auto begin = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // freopen("in",  "r", stdin);
    // freopen("out", "w", stdout);
    
    cin >> t;
    for(int i = 1; i <= t; i++) 
    {
        //cout << "Case #" << i << ": ";
        Solve();
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.n"; 
    return 0;
}
```
[1943E1 - MEX Game 2 (Easy Version)](https://codeforces.com/contest/1943/problem/E1 "Codeforces Round 934 (Div. 1)")

Idea: [Dominater069](https://codeforces.com/profile/Dominater069 "Grandmaster Dominater069")  
Preparation: [Dominater069](https://codeforces.com/profile/Dominater069 "Grandmaster Dominater069")  
Editorial: [Dominater069](https://codeforces.com/profile/Dominater069 "Grandmaster Dominater069")

 **Hint 1**It might be optimal for Bob to reduce multiple elements at the same time, thus making Alice choose between which element she wants to take.

 **Hint 2**Suppose you are only checking whether ans≥i for now, what would Alice's strategy be?

 **Hint 3**Try fixing the element that Bob wants to make sure Alice is not able to get. What would be his strategy then?

 **Solution**For now, lets try to see if ans≥i. This is equivalent to Alice being able to take 1 occurence of everything when the game is reduced to numbers [0,i−1].

Alice's strategy here is actually easy to find. At every step, Alice will choose the minimum fj such that 0≤j<i, and she hasn't chosen i yet. You can reason this with greedy stays ahead, exchange argument, whatever you want.

This gives us a nice definition of Alice's moves, however we seemingly have to maintain the sorted sequence of fi always. But we can actually rewrite Bob's moves such that it does not affect the sorted order of fi and always keeps it sorted. Here, by sorted order, we mean some permutation p=[p1,p2,....,pi] of [0,i−1] such that fpi≤fpj whenever i≤j.

First, instead of subtracting k, we will do k subtractions of only 1. Then, the only case when sorted order can be destroyed is when there exists k1 and k2 such that fk1=fk2 and we do an operation on k1 but k2 occurs before k1 in the sorted order. This issue can simply be fixed by doing the operation on the smallest x (according to sorted order) such that fx=fk1.

Now, we have a good way of representing Alice moves. Suppose we fixed the element that Bob "wins" on. Then, Bob's strategy will obviously be to make the frequency of that element as small as possible, but he must make sure to never violate sorted condition. Since Bob will make at most m moves, you can just simulate his moves. 

The main details of the simulation is that you need to figure out upto what index all values will become equal when doing k operations (or nearly equal, off by 1), and then first take all elements to that state. Let w be the remaining operations from the k operations after this, and l the length of the equal sequence. Then you will reduce every frequency by w/l, and finally reduce the first w mod l numbers of this sequence. Check the code for more details.

A naive implementation takes O(m) per move, so O(m2) per element we fix => O(m3) total to check ans≥i. With a binary search on the answer, you get O(m3logm). It can be optimized further, but it wasnt needed to pass. Most other polynomial solutions should pass this.

 **Code**
```cpp
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define f first
#define s second

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve() 
{
    int n, k; cin >> n >> k;

    vector <int> a(n + 1);
    for (auto &x : a) cin >> x;

    auto check = [&](int x){
        vector <int> b;
        for (int i = 0; i < x; i++){
            b.push_back(a[i] - k);
        }

        sort(b.begin(), b.end());

        for (int fix = 1; fix < x; fix++){
            // this is element where bob wins 

            deque <int> c;
            for (int i = 0; i <= fix; i++){
                c.push_back(b[i]);
            }
            
            assert(c.size() >= 2);

            while (c.size() != 2){
                c.pop_front(); 

                // find suffix which works 
                int sz = c.size();
                int works = 0;
                int sum = 0;
                for (int j = 1; j < sz; j++){
                    // sum(elements of c - current element) 
                    // this shud be >= k 
                    sum += c[sz - j];
                    int loss = sum - c[sz - j - 1] * j;
                    if (loss >= k){
                        works = sz - j;
                        break;
                    }
                }

                int have = k;

                // make everything = c[works]
                for (int j = works + 1; j < sz; j++){
                    have -= c[j] - c[works];
                    c[j] = c[works];
                }

                assert(have >= 0);
                for (int j = works; j < sz; j++){
                    c[j] -= have / (sz - works);
                }
                have %= (sz - works);

                for (int j = works; j < sz; j++){
                    if (have){
                        c[j]--;
                        have--;
                    }
                }

                for (int j = 0; j < sz - 1; j++){
                    assert(c[j] <= c[j + 1]);
                }
            }

            c.pop_front();
            if (c[0] <= 0) return false;
        }

        return true;
    };

    int l = 1, r = n + 1;   
    while (l != r){
        int mid = (l + r + 1) / 2;

        if (check(mid)) l = mid;
        else r = mid - 1;
    }

    cout << l << "n";
}

int32_t main() 
{
    auto begin = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // freopen("in",  "r", stdin);
    // freopen("out", "w", stdout);
    
    cin >> t;
    for(int i = 1; i <= t; i++) 
    {
        //cout << "Case #" << i << ": ";
        Solve();
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.n"; 
    return 0;
}
```
[1943E2 - MEX Game 2 (Hard Version)](https://codeforces.com/contest/1943/problem/E2 "Codeforces Round 934 (Div. 1)")

Idea: [Dominater069](https://codeforces.com/profile/Dominater069 "Grandmaster Dominater069")  
Solution : [ffao](https://codeforces.com/profile/ffao "International Grandmaster ffao")  
Preparation: [Dominater069](https://codeforces.com/profile/Dominater069 "Grandmaster Dominater069")  
Editorial: [errorgorn](https://codeforces.com/profile/errorgorn "International Grandmaster errorgorn")

 **Solution**Instead of doing the check for ans≥i in O(m3), we will do it in O(m).

For an array f of length n. Let s=f1+f2+…+fn be the sum of the element. f will be called *flat* if fi=⌊s+i−1n⌋. That is, it has the form x,…,x,x+1,…x+1. All flat array can be characters by 2 integers (n,s) only.

Imagine simulating Bob's strategy without simulating Alice's moves of removing the first element of the array. For some prefix of the moves, the actual simulation will be a suffix of this simulation. This is because to subtract something from index ≤i, we must have fi+1=fi+2=…=fn. 

As an example, let k=4.

With Alice moves: [1,2,3,5,5]→[2,3,3,3]→[1,2,2]

Without Alice moves: [1,2,3,5,5]→[1,2,3,3,3]→[1,1,2,2,2]

[1,2,2] is not a suffix of [1,1,2,2,2] and is the first time such a thing happens.

Suppose that the first time this happens is after p moves. Then the resulting array is the flat array (n−p,fp+1+fp+2+…+fn−pk). To find the necessary value of p, we can binary search or run 2-pointers to check if the suffix of the array can reach fp with the amount of subtraction operations till then. (What we basically did is find the suffix of the array that actually gets operated on, since that makes it much more easier to solve)

Then, since the flat array (n,s) becomes (n−1,s−⌊sn⌋−k), we can figure out whether each flat array evantually becomes a losing or winning state as we can calculate for each n, the minimum s such that (n,s) is a winning state.

 **Code**
```cpp
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ll long long
#define ii pair<ll,ll>
#define iii pair<ii,ll>
#define fi first
#define se second
#define endl 'n'
#define debug(x) cout << #x << ": " << x << endl

#define pub push_back
#define pob pop_back
#define puf push_front
#define pof pop_front
#define lb lower_bound
#define ub upper_bound

#define rep(x,start,end) for(int x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

int n,k;
int arr[200005];
int temp[200005];

bool solve(vector<int> v){
    sort(all(v));
    
    rep(x,0,sz(v)) temp[x]=1e18;
    
    int l=1,curr=0;
    rep(x,1,sz(v)){
        curr+=v[x];
        
        while (l<x && (curr-v[l])-(x-l)*v[l] >= l*k){
            curr-=v[l];
            l++;
        }
        
        temp[x-l]=min(temp[x-l],curr-l*k);
    }
    
    rep(x,sz(v),1) temp[x-1]=min(temp[x-1],(temp[x]-temp[x]/(x+1))-k);
    
    return temp[0]>0;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin.exceptions(ios::badbit | ios::failbit);
    
    int TC;
    cin>>TC;
    while (TC--){
        cin>>n>>k;
        rep(x,0,n+1) cin>>arr[x];
        
        // solve(vector<int>(arr,arr+n+1));
        // continue;
        
        int lo=0,hi=n+2,mi;
        while (hi-lo>1){
            mi=hi+lo>>1;
            
            if (solve(vector<int>(arr,arr+mi))) lo=mi;
            else hi=mi;
        }
        
        cout<<lo<<endl;
    }
}
```
[1943F - Minimum Hamming Distance](https://codeforces.com/contest/1943/problem/F "Codeforces Round 934 (Div. 1)")

Idea: [satyam343](https://codeforces.com/profile/satyam343 "Master satyam343")  
Preparation: [satyam343](https://codeforces.com/profile/satyam343 "Master satyam343")  
Editorial: [satyam343](https://codeforces.com/profile/satyam343 "Master satyam343")

 **Hint 1 / Claim 1**Assumption: 0 is the mode of string t. If 1 occurs more times than 0 in t, we will flip all characters of s and t so that 0 is the mode of string t.

Let us say index i *nice* if there exists l and r(1≤l≤i≤r≤n) such that si is the mode of substring t[l,r].

So we might have some not *nice* indices i such that si= 1. We will not have any index i such that i is not *nice* and si= 0, as 0 is the mode of t. So, we need to fix the not *nice* indices.

Now we will start changing some 0 to 1. So it might be possible that in final t, the frequency of 1 is more than that of 0, and 0 is no longer the mode. So should we worry about indices i such that i was nice in the beginning, and now that we made some flips, i may become not *nice*? 

No! It will never be possible. 

In case 1 occurs more times than 0 in the updated t, we will have frequency[1]=frequency[0]+1 and t[1]=t[n]= 1(we will have such cases for pairs like (s= 011, t= 100; for this pair final t should be t= 101). So the substrings t[1,n−1] and t[2,n] will have equal numbers of 0 and 1, and thus all indices should be *nice*. So our claim is that we should change some 0 to 1, without caring about indices i(which were *nice* initially) becoming not *nice* such that si= 0.

 **Hint 2**We can use dynamic programming here.  
So let us have dp, such that dp[i][j] gives the minimum number of flips required to make t[1,i] *friend* of s[1,i] and the maximum suffix sum is j.  
String x is called to be *friend* of string y(|x|=|y|), if for every i(1≤i≤|x|), there exists indices l and r such that:  
1. 1≤l≤i≤r≤|x|  
2. xi is a mode of the string y[l,r] 

 **Solution**Please read hints 1 and 2 if you haven't as they contain some claims and definitions.

Note that when we find some sum, we add 1 when we get 1 and subtract −1 when we get 0.

Suppose we have found dp values for the first i−1 indices, and we want to find dp[i][j] for 0≤j≤n. Now, we need to perform the transitions. 

Let us try to have a O(n3) solution first, which we can optimise after making some observations.

Take some l(0≤l≤i−1). We will iterate over suff_sum=0 to n, here suff_sum is the maximum suffix sum of substring t[1,l], and use dp[l][suff_sum] to find optimal values for dp[i][x] for some x.

So we need to do some flips to substring t[l+1,i], as s[1,l] and t[1,l] are already *friends*. So we only care to make all indices j (l+1≤j≤i) *nice*. So there are two possibilities(either 1 occurs in substring s[l+1,i] or not): 

 1. If 1 does not occur, we can perform the transition without making any flips.
2. Assume 1 occurs in substring s[l+1,i]. So firstly, find the sum(say cur_sum) of substring t[l+1,i]. Now, if we do some flips to substring t[l+1,i], cur_sum will change accordingly. We will do a minimum number of flips such that suff_sum+cur_sum≥0. Note that we are talking here about updated cur_sum. So we can find the minimum number(say cost) of flips, which will be ⌊max(0,1−d)2⌋, where d=suff_sum+initial_cur_sum. So we know how many flips to make.

But which ones to flip? Here is one more claim. We should only flip the last cost 0 of substring t[l+1,i]. 

So this is a sufficient condition, as we can certainly say that t[1,i] will be *friend* of s[1,i] now. So we know the required number of flips, which is dp[l][suff_sum]+cost. We need to find one more thing — what would be the maximum suffix sum if we flip the last cost characters of t[l+1,i]? We can precompute.

But we have an issue now. We know that what we performed is sufficient. But is it necessary? What if we did not need to flip cost characters of t[l+1,i]?

It might be possible that we could have done less number of flips and still made all indices l+1≤j≤i *nice*. The reasoning behind this is we made sure that suff_sum+cur_sum≥0, but what if it was not needed? 

Like it is possible that total sum is negative, but all indices j(l+1≤j≤i) such that sj= 1 are satisfied. So here, we can use exchange arguments and conclude that all cases will be covered if we check for all pairs of (l,suff_sum) 0≤l,suff_sum≤i−1.

Now we need to optimise this to O(n2).

Notice that when we do the flips, there will be a suffix(possibly empty when cost=0) of t[l+1,i] containing only 1 s. Suppose we are at index i and need to find dp[i][j] for 0≤j≤i. We can iterate over all j(1≤j≤i), assume that all the characters in substring t[j,i] are 1 s, and find the dp values. Maximum suffix sum will be i−j+1+max_suffix_sum[j−1]. So we can find the smallest index p such that the sum of the elements in substring t[p,l] is greater than or equal to 0 if we make all the characters in substring t[j,i] 1. 

Notice that we already have the new suffix maximum, and we know the cost too, which is equal to the number of 0 s in the original substring t[j,i]. So our transition will be dp[i][new_suffix_max]=max(dp[i][new_suffix_max],imink=p−1best[k]+cost), where best[i]=imink=0dp[i][k].

So, our final complexity will be O(n2), as we can perform the transition in O(1) if we precompute the needed things.

 **Code**
```cpp
#include <bits/stdc++.h>   
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;   
using namespace std;
#define ll int
#define pb push_back                  
#define mp make_pair          
#define nline "n"                            
#define f first                                            
#define s second                                             
#define pll pair<ll,ll> 
#define all(x) x.begin(),x.end()     
const ll MOD=998244353;
const ll MAX=10005;  
ll dp[MAX][MAX];
ll suffix_min[MAX];
ll suffix_max[MAX];
ll can_go_till[MAX][MAX+5];
void solve(){     
    ll n; cin>>n; 
    ll shift=n;
    for(ll i=-n;i<=0;i++){
        can_go_till[0][shift+i]=0;
    }
    string s,t; cin>>s>>t;
    s=" "+s,t=" "+t;
    ll sum=0;
    for(ll i=1;i<=n;i++){
        sum+=2*(t[i]-'0')-1;
    }
    suffix_max[0]=0;
    if(sum>=0){   
        for(ll i=1;i<=n;i++){
            s[i]='0'+'1'-s[i];  
            t[i]='0'+'1'-t[i];
        }    
    }
    ll max_sum=0;
    for(ll i=1;i<=n;i++){
        max_sum+=2*(t[i]-'0')-1;
        max_sum=max(0,max_sum);
        suffix_max[i]=max_sum;
    }  
    for(ll i=1;i<=n;i++){
        sum=0;
        for(ll j=-n;j<=0;j++){
            can_go_till[i][shift+j]=i+1;
        }
        for(ll j=i;j>=1;j--){
            sum+=2*(t[j]-'0')-1;
            ll use=min(sum,0);
            can_go_till[i][shift+use]=j;
        }
        for(ll j=n-1;j>=0;j--){
            can_go_till[i][j]=min(can_go_till[i][j],can_go_till[i][j+1]);
        }
    }
    for(ll i=0;i<=n+1;i++){
        for(ll j=0;j<=n+1;j++){
            dp[i][j]=MOD;
        }
    }
    dp[0][0]=0;
    vector<ll> best(n+5,MOD);
    best[0]=0;
    for(ll i=1;i<=n;i++){
        for(ll l=0;l<=i-1;l++){ 
            dp[i][l+1]=dp[i-1][l]+(t[i]=='0');
        }
        for(ll l=0;l<=i;l++){
            ll new_sum=l+2*(t[i]-'0')-1;  
            if(s[i]=='1' and new_sum<=-1){
                continue; 
            }    
            new_sum=max(0,new_sum); 
            dp[i][new_sum]=min(dp[i][new_sum],dp[i-1][l]);
        }
        suffix_min[i]=MOD;
        for(ll j=i-1;j>=0;j--){
            suffix_min[j]=min(suffix_min[j+1],best[j]);
        }
        ll cnt=0;
        for(ll j=i;j>=1;j--){
            cnt+=(t[j]=='0');
            ll now=i-j+1;
            ll cur_suff_max=now+suffix_max[j-1];
            ll pos=max(0,can_go_till[j-1][shift-now]-1);
            dp[i][cur_suff_max]=min(dp[i][cur_suff_max],suffix_min[pos]+cnt);
        }
        for(ll j=0;j<=n;j++){
            best[i]=min(best[i],dp[i][j]); 
        }
    } 
    ll ans=MOD; 
    s[0]='1';
    for(ll i=n;i>=0;i--){  
        ans=min(ans,best[i]);    
        if(s[i]=='1'){
            cout<<ans<<nline;
            return;  
        }
    }
    return;          
}                                          
int main()                                                                               
{     
    ios_base::sync_with_stdio(false);                         
    cin.tie(NULL);                               
    #ifndef ONLINE_JUDGE                 
    freopen("input.txt", "r", stdin);                                           
    freopen("output.txt", "w", stdout);      
    freopen("error.txt", "w", stderr);                        
    #endif     
    ll test_cases=1;                 
    cin>>test_cases;
    while(test_cases--){
        solve();
    }
    cout<<fixed<<setprecision(10);
    cerr<<"Time:"<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"msn"; 
}  
```
