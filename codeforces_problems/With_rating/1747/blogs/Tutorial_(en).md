# Tutorial_(en)

I hope you all liked the round. Please share your feedback in the comments section. 

[1747A — Two Groups](../problems/A._Two_Groups.md)
===================================================================

 **Hint**How about putting all positive numbers in one group and negative in second group

 **Tutorial**Let S denotes sum of element of array a. 

**Claim**: Answer is |S|.

**Proof**: Let sum of all positive elements is Spos and sum of all negative elements Sneg. Put all positive numbers in first group and negative numbers in second group. We get ||Spos|−|Sneg||=|S|.

Let's prove that we can not do better than that. Let S1 denotes sum of elements of first group and S2 denotes sum of elements of second group. We have |S1|−|S2|≤|S1+S2|=|S|. Hence |S| is the upperbound for the answer.

 **Solution**
```cpp
// Jai Shree Ram
#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,n)     for(int i=a;i<n;i++)
#define ll             long long
#define int            long long
#define pb             push_back
#define all(v)         v.begin(),v.end()
#define endl           "n"
#define x              first
#define y              second
#define gcd(a,b)       __gcd(a,b)
#define mem1(a)        memset(a,-1,sizeof(a))
#define mem0(a)        memset(a,0,sizeof(a))
#define sz(a)          (int)a.size()
#define pii            pair<int,int>
#define hell           1000000007
#define elasped_time   1.0 * clock() / CLOCKS_PER_SEC



template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.x>>a.y;return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.x<<" "<<a.y;return out;}
template<typename T,typename T1>T maxs(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T mins(T &a,T1 b){if(b<a)a=b;return a;}


int solve(){
 		int n; cin >> n;
 		int s = 0;
 		for(int i = 0; i < n; i++){
 			int x; cin >> x;
 			s += x;
 		}
 		cout << abs(s) << endl;
 return 0;	
}
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #ifdef SIEVE
    sieve();
    #endif
    #ifdef NCR
    init();
    #endif
    int t=1;cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
```
[1747B — BAN BAN](../problems/B._BAN_BAN.md)
================================================================

 **Hint 1**Instead of subsequences solve for substrings. That is there should not be any substring BAN after performing operations. 

 **Hint 2**In one operation you can destroy atmost 2 substrings. Find minimum operations to destroy n substrings.

 **Answer**⌈n2⌉

 **Hint 3**Congrats, you have solved for subsequences also!

 **Tutorial**No subsequences of string BAN would also mean no substrings of BAN in original string. Let minimum number of operations to have no substrings of BAN be x, it would be also be the lower bound for having no subsequences of string BAN. 

**Claim**: x=⌈n2⌉.

**Proof**: Swap i-th B from start with i-th N from end for 1≤i≤⌈n2⌉. We can see that, no substrings of BAN exists after performing ⌈n2⌉ operations. Since we can only destroy atmost 2 substrings in one operations, ⌈n2⌉ is minimum possible.

Now if you see clearly, after performing above operations, there does not exist any subsequence of string BAN in original string. Hence ⌈n2⌉ is also the answer for the original problem.

 **Solution**
```cpp
// Jai Shree Ram  
  
#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,n)     for(int i=a;i<n;i++)
#define ll             long long
#define int            long long
#define pb             push_back
#define all(v)         v.begin(),v.end()
#define endl           "n"
#define x              first
#define y              second
#define gcd(a,b)       __gcd(a,b)
#define mem1(a)        memset(a,-1,sizeof(a))
#define mem0(a)        memset(a,0,sizeof(a))
#define sz(a)          (int)a.size()
#define pii            pair<int,int>
#define hell           1000000007
#define elasped_time   1.0 * clock() / CLOCKS_PER_SEC



template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.x>>a.y;return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.x<<" "<<a.y;return out;}
template<typename T,typename T1>T maxs(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T mins(T &a,T1 b){if(b<a)a=b;return a;}


int solve(){
 		int n; cin >> n;
 		cout << n/2 + n % 2 << endl;
 		int l = 1, r = 3*n;
 		while(l < r){
 			cout << l << " " << r << endl;
 			l += 3;
 			r -= 3;
 		}
 return 0;
}
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #ifdef SIEVE
    sieve();
    #endif
    #ifdef NCR
    init();
    #endif
    int t=1;cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
```
[1747C — Swap Game](https://codeforces.com/contest/1747/problem/c)
==================================================================

 **Hint 1**Divide problem into two different cases. When a1>min(a) and when a1=min(a).

 **Hint 2**You do not need more hints to solve the problem.

 **Tutorial****Case 1**: a1>min(a) 

Alice can force the Bob to always decrease the minimum element by always choosing minimum element of a in her turn. Where as Bob can not do much, all other elements he would swap with would be greater than or equal to min(a). Even if there exists multiple minimums in a, In first move Alice would decrease from a1, hence in this case Alice would always win.

**Case 2**: a1=min(a) 

In this case optimal startegy for Bob would be to always chhose minimum element of the array, which is a1. Alice would always be swapping the element greater than a1 in her turn, hence in the case Bob would always win

 **Solution**
```cpp
// Jai Shree Ram  
  
#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,n)     for(int i=a;i<n;i++)
#define ll             long long
#define int            long long
#define pb             push_back
#define all(v)         v.begin(),v.end()
#define endl           "n"
#define x              first
#define y              second
#define gcd(a,b)       __gcd(a,b)
#define mem1(a)        memset(a,-1,sizeof(a))
#define mem0(a)        memset(a,0,sizeof(a))
#define sz(a)          (int)a.size()
#define pii            pair<int,int>
#define hell           1000000007
#define elasped_time   1.0 * clock() / CLOCKS_PER_SEC



template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.x>>a.y;return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.x<<" "<<a.y;return out;}
template<typename T,typename T1>T maxs(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T mins(T &a,T1 b){if(b<a)a=b;return a;}


int solve(){
 		int n; cin >> n;
 		vector<int> a(n);
 		for(auto &i:a)cin >> i;
 		sort(a.begin() + 1,a.end());
 		cout << (a[0] > a[1] ? "Alice" : "Bob") << endl;
 return 0;
}
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #ifdef SIEVE
    sieve();
    #endif
    #ifdef NCR
    init();
    #endif
    int t=1;cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
```
[1747D — Yet another Problem](../problems/D._Yet_Another_Problem.md)
============================================================================

 **Hint 1**Forget queries, they are just here to make problem look complicated. Solve for q=1.

 **Hint 2**XOR of array does not change after operations. Hence if initially XOR is not equal to 0, answer is −1. Is this condition sufficient?

 **Answer**No, We need one more condition

 **Hint 3**There must exist some prefix of odd size, such that xor of elements of that prefix is 0. 

 **Tutorial**First forget queries, solve for single array a.

Let's make some observations.

 1. Xor of array does not change after each operation
2. Look at the set of prefix XORs while doing operations. Its size always decreases or remains same after each operation. Infact we can further reduce it to parities. Let S0, S1 be sets of prefix XOR's of parities 0 and 1 respectively. After each operation new sets S′0, S′1 will be subsets of S0 and S1 respectively.

So necessary conditions for answer to exist is that xor of array should be 0 and S1 should contains 0.

Now comes to minimum operations.

**Claim:** If above conditions are satisfied, its always possible to make all elements 0 in less than or equal to 2 operations

**Proof:** Let length of array be n.

**Case 1:** n is odd

Just apply the operation on whole array.

**Case 2:** n is even

There will exists some odd size prefix j such that xor of its elements is 0. Apply operation on [1,j] and [j+1,n]. It can happen that j=1 or j=n−1, in that case we only need one operation, because other remaining element would already be equal to 0.

To solve for queries, you just need to check for odd prefix, which can be done using some data structure like std::map or std::set in C++. Do not forget to check the case when all elements are already 0.

 **Solution**
```cpp
#include<bits/stdc++.h>
using namespace std ;

#define ll              long long 
#define pb              push_back
#define all(v)          v.begin(),v.end()
#define sz(a)           (ll)a.size()
#define F               first
#define S               second
#define INF             2000000000000000000
#define popcount(x)     __builtin_popcountll(x)
#define pll             pair<ll,ll>
#define pii             pair<int,int>
#define ld              long double

template<typename T, typename U> static inline void amin(T &x, U y){ if(y < x) x = y; }
template<typename T, typename U> static inline void amax(T &x, U y){ if(x < y) x = y; }

#ifdef LOCAL
#define debug(...) debug_out(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) 3000
#endif

int _runtimeTerror_()
{
    int n, Q;
    cin >> n >> Q;
    map<int, int> odd, even;
    vector<int> last_nz(n + 1, 0), last(n + 1, -1), pxor(n + 1, 0);
    vector<int> a(n + 1);
    even[0] = 0;
    int cur = 0;
    for(int i=1;i<=n;++i) {
    	cin >> a[i];
    	cur ^= a[i];
    	pxor[i] = cur;
    	if(a[i] == 0) {
    		last_nz[i] = last_nz[i - 1];
    	}
    	else {
    		last_nz[i] = i;
    	}
    	if(i & 1) {
    		if(even.count(cur)) {
    			last[i] = even[cur];
    		}
    		odd[cur] = i;
    	}
    	else {
    		if(odd.count(cur)) {
    			last[i] = odd[cur];
    		}
    		even[cur] = i;
    	}
    }
    while(Q--) {
    	int l, r;
    	cin >> l >> r;
    	if(pxor[l - 1] != pxor[r]) {
    		cout << "-1n";
    	}
    	else if(last_nz[r] < l) {
    		cout << "0n";
    	}
    	else if(r % 2 == l % 2) {
    		cout << "1n";
    	}
    	else if(a[l] == 0 or a[r] == 0) {
    		cout << "1n";
    	}
    	else if(last[r] >= l) {
    		cout << "2n";
    	}
    	else {
    		cout << "-1n";
    	}
    }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifdef runSieve
        sieve();
    #endif
    #ifdef NCR
        initncr();
    #endif
    int TESTS = 1;
    //cin >> TESTS;
    while(TESTS--) {
        _runtimeTerror_();
    }
    return 0;
}	 	
```
[1747E — List Generation](../problems/E._List_Generation.md)
========================================================================

 **Hint 1**Change your point of view from array to grid. Think of pair of arrays as paths in grid of size (n+1)×(m+1). 

 **Hint 2**First try counting number of good pair of arrays.

 **answer**Number of good pairs of arrays comes out to be ∑k=0k=min(n,m(nk)⋅(mk)⋅2n+m−k−1

 **Tutorial**Given problem is equivalent to:

You are currently at cell (0,0). From any cell (x,y) you can jump to cell (x′,y′) such that x≤x′≤n , y≤y′≤m and (x,y)≠(x′,y′). Find sum of number of visited cells over all paths starting from (0,0) and ending at (n,m). Denote the required value by f(n,m).

Directly thinking in 2 dimensions is difficult, lets first solve for case when n=0 or m=0. WLOG, assuming m=0. We can solve this case using some binomials. 

f(n,0)=2n−1⋅n+32, n>0.

Now, we can divide all possible paths from (0,0) to (n,m) into several classes of one dimensional paths.

These classes are defined by what I call *breakpoints*. When we passes the breakpoint we turns right. Hence we can group paths by fixing the number of breakpoints. 

WLOG, Assuming n≥m. For k breakpoints there are (nk)⋅(mk) ways to select for 0≤k≤m. For a path with k breakpoints, n+m−k points are *optional*, that is there will exist 2n+m−k paths with k breakpoints. It is not difficult to see that sum of number of visited cells over paths with k breakpoints turned out to be f(n+m−k,0)+2n+m−k−1⋅k. Hence we can write f(n,m)=m∑k=0(nk)⋅(mk)⋅(f(n+m−k,0)+2n+m−k−1⋅k) 

Time complexity of the solution would be O(min(n,m)) 

 **Solution**
```cpp
// Jai Shree Ram  
  
#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,n)     for(int i=a;i<n;i++)
#define ll             long long
#define int            long long
#define pb             push_back
#define all(v)         v.begin(),v.end()
#define endl           "n"
#define x              first
#define y              second
#define gcd(a,b)       __gcd(a,b)
#define mem1(a)        memset(a,-1,sizeof(a))
#define mem0(a)        memset(a,0,sizeof(a))
#define sz(a)          (int)a.size()
#define pii            pair<int,int>
#define hell           1000000007
#define elasped_time   1.0 * clock() / CLOCKS_PER_SEC



template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.x>>a.y;return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.x<<" "<<a.y;return out;}
template<typename T,typename T1>T maxs(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T mins(T &a,T1 b){if(b<a)a=b;return a;}


const int MOD = hell;
 
struct mod_int {
    int val;
 
    mod_int(long long v = 0) {
        if (v < 0)
            v = v % MOD + MOD;
 
        if (v >= MOD)
            v %= MOD;
 
        val = v;
    }
 
    static int mod_inv(int a, int m = MOD) {
        int g = m, r = a, x = 0, y = 1;
 
        while (r != 0) {
            int q = g / r;
            g %= r; swap(g, r);
            x -= q * y; swap(x, y);
        }
 
        return x < 0 ? x + m : x;
    }
 
    explicit operator int() const {
        return val;
    }
 
    mod_int& operator+=(const mod_int &other) {
        val += other.val;
        if (val >= MOD) val -= MOD;
        return *this;
    }
 
    mod_int& operator-=(const mod_int &other) {
        val -= other.val;
        if (val < 0) val += MOD;
        return *this;
    }
 
    static unsigned fast_mod(uint64_t x, unsigned m = MOD) {
           #if !defined(_WIN32) || defined(_WIN64)
                return x % m;
           #endif
           unsigned x_high = x >> 32, x_low = (unsigned) x;
           unsigned quot, rem;
           asm("divl %4n"
            : "=a" (quot), "=d" (rem)
            : "d" (x_high), "a" (x_low), "r" (m));
           return rem;
    }
 
    mod_int& operator*=(const mod_int &other) {
        val = fast_mod((uint64_t) val * other.val);
        return *this;
    }
 
    mod_int& operator/=(const mod_int &other) {
        return *this *= other.inv();
    }
 
    friend mod_int operator+(const mod_int &a, const mod_int &b) { return mod_int(a) += b; }
    friend mod_int operator-(const mod_int &a, const mod_int &b) { return mod_int(a) -= b; }
    friend mod_int operator*(const mod_int &a, const mod_int &b) { return mod_int(a) *= b; }
    friend mod_int operator/(const mod_int &a, const mod_int &b) { return mod_int(a) /= b; }
 
    mod_int& operator++() {
        val = val == MOD - 1 ? 0 : val + 1;
        return *this;
    }
 
    mod_int& operator--() {
        val = val == 0 ? MOD - 1 : val - 1;
        return *this;
    }
 
    mod_int operator++(int32_t) { mod_int before = *this; ++*this; return before; }
    mod_int operator--(int32_t) { mod_int before = *this; --*this; return before; }
 
    mod_int operator-() const {
        return val == 0 ? 0 : MOD - val;
    }
 
    bool operator==(const mod_int &other) const { return val == other.val; }
    bool operator!=(const mod_int &other) const { return val != other.val; }
 
    mod_int inv() const {
        return mod_inv(val);
    }
 
    mod_int pow(long long p) const {
        assert(p >= 0);
        mod_int a = *this, result = 1;
 
        while (p > 0) {
            if (p & 1)
                result *= a;
 
            a *= a;
            p >>= 1;
        }
 
        return result;
    }
 
    friend ostream& operator<<(ostream &stream, const mod_int &m) {
        return stream << m.val;
    }
    friend istream& operator >> (istream &stream, mod_int &m) {
        return stream>>m.val;   
    }
};
#define NCR
const int N = 5e6 + 5;
mod_int fact[N],inv[N],invv[N];
void init(int n=N){
	fact[0]=inv[0]=inv[1]=1;
        invv[0] = invv[1] = 1;
	rep(i,1,N)fact[i]=i*fact[i-1];
	rep(i,2,N){
        invv[i] = (MOD - MOD/i)*invv[MOD % i];
        inv[i] = invv[i]*inv[i - 1];
    }
}
mod_int C(int n,int r){
	if(r>n || r<0)return 0;
	return fact[n]*inv[n-r]*inv[r];
}

int solve(){
 		int n,m; cin >> n >> m;
 		if(m > n)swap(n,m);
 		auto brute = [&](){
 			vector<vector<mod_int>>dp(n + 1,vector<mod_int>(m + 1));
 			vector<vector<mod_int>>exp(n + 1,vector<mod_int>(m + 1));
 			dp[0][0] = 1;
 			exp[0][0] = 0;
 			for(int i = 0; i <= n; i++){
 				for(int j = 0; j <= m; j++){
 					if(i + j == 0)continue;
 					for(int x = 0; x <= i; x++){
 						for(int y = 0; y <= j; y++){
 							if(x + y == i + j)continue;
 							dp[i][j] += dp[x][y];
 							exp[i][j] += (exp[x][y] + dp[x][y]);
 						}
 					}
 				}
 			}
 			return exp[n][m] + dp[n][m];
 		};
 		auto correct = [&](){
                        mod_int in = mod_int(2).inv();
 			auto d = [&](int x){
 				mod_int val = x + 1;
 				return val * in;
 			};
 			mod_int ans = 0;
                        mod_int pw = mod_int(2).pow(n + m);
 			for(int i = 0; i <= m; i++){
                                pw *= in;
 				ans += C(n,i)*C(m,i)*pw*(i + d(n + m - i) + 1);
 			}
 			return ans;
 		};
 		cout << correct() << endl;

 return 0;
}
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #ifdef SIEVE
    sieve();
    #endif
    #ifdef NCR
    init();
    #endif
    int t=1;cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
 
```
