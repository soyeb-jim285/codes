# Tutorial_1_(en)

[1975A - Bazoka and Mocha's Array](../problems/A._Bazoka_and_Mocha's_Array.md)

Idea: [Bazoka13](https://codeforces.com/profile/Bazoka13 "Master Bazoka13") Solution: [Bazoka13](https://codeforces.com/profile/Bazoka13 "Master Bazoka13") Prepared by: [Bazoka13](https://codeforces.com/profile/Bazoka13 "Master Bazoka13")

 **Hint 1**We can't do any insertions by the operation.

 **Hint 2**If the answer is yes, we can make a become non-decreasing in no more than one operation.

 **Solution**Read the hints.

If a is non-decreasing initially, the answer is yes.

If a isn't non-decreasing initially, we can find the smallest i such that ai>ai+1. Then we choose x=[a1,a2,...,ai] and y=[ai+1,ai+2,...,an]. If the array y+x is non-decreasing, the answer is yes. Otherwise, the answer is no.

 **Code**
```cpp
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int a[N];
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        int pos=0;
        for(int i=1;i<n;i++){
            if(a[i]>a[i+1]){
                pos=i;
                break;
            }
        }
        if(!pos)cout<<"Yesn";
        else{
            int fl=0;
            for(int i=pos+1;i<=n;i++){
                int j=(i%n)+1;
                if(a[i]>a[j])fl=1;
            }
            if(!fl)cout<<"Yesn";
            else cout<<"Non";
        }
    }
}
```
[1975B - 378QAQ and Mocha's Array](../problems/B._378QAQ_and_Mocha's_Array.md)

Idea: [Bazoka13](https://codeforces.com/profile/Bazoka13 "Master Bazoka13") Solution: [Bazoka13](https://codeforces.com/profile/Bazoka13 "Master Bazoka13") Prepared by: [Bazoka13](https://codeforces.com/profile/Bazoka13 "Master Bazoka13")

 **Hint 1**How to solve the problem if we only need to find a number i(1≤i≤n) such that ak is divisible by ai for all k(1≤k≤n)?

 **Hint 2**We only need to check whether all elements are divisible by the minimum element of the array.

 **Solution**Read the hints.

Suppose the minimum element of a is x. Then we iterate over a, if an element is not divisible by x, then we add it to b (b is initially empty).

If b is still empty after iterating a, the answer is yes. 

If b isn't empty, we check whether all elements of b are divisible by the minimum element of b. If so, the answer is yes. Otherwise, the answer is no.

 **Code**
```cpp
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5+10;
int a[N];
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int fl=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            if(a[i]==1)fl=1;
        }
        if(fl)cout<<"Yesn";
        else{
            sort(a+1,a+1+n);
            vector<int> b;
            for(int i=2;i<=n;i++){
                if(a[i]%a[1])b.push_back(a[i]);
            }
            sort(b.begin(),b.end());
            n = b.size();
            for(int j=1;j<n;j++){
                if(b[j]%b[0]){
                    fl=1;
                    break;
                }
            }
            if(!fl)cout<<"Yesn";
            else cout<<"Non";
        }

    }
}
```
[1975C - Chamo and Mocha's Array](../problems/C._Chamo_and_Mocha's_Array.md)

Idea: [Bazoka13](https://codeforces.com/profile/Bazoka13 "Master Bazoka13") Solution: [Bazoka13](https://codeforces.com/profile/Bazoka13 "Master Bazoka13") Prepared by: [Bazoka13](https://codeforces.com/profile/Bazoka13 "Master Bazoka13")

 **Hint 1**If a subarray of length at least 2 contains only the same elements, we can change all elements of the array to that element by operations.

 **Hint 2**Suppose the answer is x, we can perform no more than one operation on the original array a so that there is a subarray of length at least 2 that contains only x.

 **Hint 3**If we can make all elements of a subarray become x in one operation, then there must be a subarray of length 3 with a median of y (y≥x).

 **Solution**Read the hints.

If n=2, the answer is the minimum element.

If n≥3, we iterate over all subarrays of length 3, and the answer is the maximum value of the median of all subarrays of length 3.

 **Code**
```cpp
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int a[N];
int main(){
    int n,t;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++) 
            cin>>a[i];
        if(n==2)cout<<min(a[1],a[2])<<"n";
        else{
            int ans = min(a[1],a[2]);
            for(int i=1;i<=n-2;i++){
                vector<int> tmp;
                for(int k=0;k<=2;k++)
                    tmp.push_back(a[i+k]);
                sort(tmp.begin(),tmp.end());
                ans = max(ans,tmp[1]);
            }
            cout<<ans<<"n";
        }
    }
}
```
[1975D - Paint the Tree](../problems/D._Paint_the_Tree.md)

Idea: [SanweiTreap](https://codeforces.com/profile/SanweiTreap "Grandmaster SanweiTreap") Solution: [Atomic-Jellyfish](https://codeforces.com/profile/Atomic-Jellyfish "Grandmaster Atomic-Jellyfish") Prepared by: [Bazoka13](https://codeforces.com/profile/Bazoka13 "Master Bazoka13")

 **Hint 1**If two pieces overlap at the beginning, can you solve the problem?

 **Hint 2**Consider the first time a vertex is painted blue. After this event occurs, what happens next?

 **Solution**Read the hints.

In subsequent movements after the first time a vertex is painted blue, we can ignore the process of painting vertices red and then painting them blue.

We call the first vertex painted blue r. Then it is not difficult to find that PA arrived at this vertex earlier than PB. Considering all subsequent movements of PB, PA can restore these movements one by one after reaching r, then PB will pass through all vertices have been painted red.

If we know which vertex is r, this will be a classic problem, assuming the distance between the farthest vertex on the tree from r and r is d, then the answer is 2(n−1)−d. Then we consider the strategies of PA and PB at this time. The two must be close to each other, and then until the first vertex is painted blue. If another vertex is r, although the value of d may increase, every time the value of d increases by 1, the time when PA and PB meet will also increase by at least 1, so the answer will not decrease.

 **Code**
```cpp
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e5+10;
vector<int> g[N];
int dep[N],f[N],mx,n,a,b;
void dfs(int x,int fa){
    dep[x]=dep[fa]+1;
    mx = max(mx,dep[x]);
    f[x]=fa;
    for(auto i:g[x]){
        if(i==fa)continue;
        dfs(i,x);
    }
}
vector<int> move(int x,int y){
    if (dep[x] > dep[y]) swap(x, y);
    vector<int> track,ano;
    int tmp = dep[y] - dep[x], ans = 0;
    track.push_back(y);
    while(tmp--){
        y = f[y];
        track.push_back(y);
    }
    if (y == x) return track;
    ano.push_back(x);
    while (f[x] != f[y]) {
        x = f[x];
        y = f[y];
        ano.push_back(x);
        track.push_back(y);
    }
    track.push_back(f[y]);
    reverse(ano.begin(),ano.end());
    for(auto i:ano)track.push_back(i);
    return track;
}
int main(){
    int t;
    cin>>t;
    dep[0]=-1;
    while(t--){
        mx = -1;
        cin>>n;
        for(int i=1;i<=n;i++)g[i].clear();
        cin>>a>>b;
        for(int i=1;i<n;i++){
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        if(a==b){
            dfs(a,0);
            cout<<2*(n-1)-mx<<"n";
            continue;
        }
        dfs(1,0);
        auto tr = move(a,b);
        int m = tr.size();
        if(tr[0]!=a)reverse(tr.begin(),tr.end());
        int x = tr[(m-1)/2];
        mx = -1;
        dfs(x,0);
        cout<<2*(n-1)-mx+(m-1-(m-1)/2)<<"n";
    }
}
```
[1975E - Chain Queries](../problems/E._Chain_Queries.md)

Idea: [Bazoka13](https://codeforces.com/profile/Bazoka13 "Master Bazoka13") Solution: [Serval](https://codeforces.com/profile/Serval "Grandmaster Serval") Prepared by: [Bazoka13](https://codeforces.com/profile/Bazoka13 "Master Bazoka13")

 **Hint 1**Suppose the tree is a rooted tree, we only need to care about the number of black child vertices of each vertex.

 **Hint 2**If the black vertices form a chain, there is no black vertex that has three or more black child vertices. And there is at most one black vertex that has two black child vertices.

 **Hint 3**If the black vertices form a chain, there is at most one black vertex whose parent vertex is white.

 **Solution**Read the hints.

We can maintain the number of black vertices with 0/1/2/3+ black child vertices in O(1). When we flip the color of one vertex, only it and its parent node are affected.

If the black vertices form a chain: - no black vertex that has three or more black child vertices and there is at most one black vertex that has two black child vertices. - there is at most one black vertex whose parent vertex is white. - if there is one black vertex that has two black child vertices, its parent vertex must be white.

 **Code**
```cpp
#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+10;

int f[N];
vector<int> g[N];
int col[N],num[N];
int faw,sum_two,sum_more,tot_black,xor_two;
int n;
void init(){
    sum_two=0;
    tot_black=0;
    sum_more=0;
    faw=0;
    xor_two=0;
    for(int i=1;i<=n;i++){
        g[i].clear();
        num[i]=0;
    }
}

void dfs(int x,int fa){
    f[x]=fa;
    if(col[x]==1)tot_black++;
    int sum=0;
    for(auto i:g[x]){
        if(i==fa)continue;
        dfs(i,x);
        if(col[i]==1)sum++;
    }
    if(col[fa]==0&&col[x]==1)faw++;
    if(col[x]==1){
        if(sum==2)sum_two++,xor_two^=x;
        if(sum>2)sum_more++;
    }
    num[x]=sum;
}

void flip(int x){
    col[x]^=1;
    int d = col[x]==1?1:-1;
    tot_black+=d;
    if(col[f[x]]==0)faw+=d;
    if(num[x]==2)sum_two+=d,xor_two^=x;
    if(num[x]>2)sum_more+=d;
    faw-=d*num[x];
    if(col[x]==1){
        if(col[f[x]]==1&&num[f[x]]==2)sum_two--,sum_more++,xor_two^=f[x];
        num[f[x]]++;
        if(col[f[x]]==1&&num[f[x]]==2)sum_two++,xor_two^=f[x];
    }else{
        if(col[f[x]]==1&&num[f[x]]==2)sum_two--,xor_two^=f[x];
        num[f[x]]--;
        if(col[f[x]]==1&&num[f[x]]==2){
            sum_two++;
            sum_more--;
            xor_two^=f[x];
        }
    }
}

bool check(){
    if(!tot_black)return false;
    if(sum_more||sum_two>1)return false;
    if(faw>1)return false;
    if(sum_two&&col[f[xor_two]]==1)return false;
    return true;
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        init();
        int q;
        scanf("%d %d",&n,&q);
        for(int i=1;i<=n;i++) cin>>col[i];
        for(int i=1;i<n;i++){
            int u,v;
            scanf("%d %d",&u,&v);
            g[u].push_back(v);
            g[v].push_back(u);
        }
        dfs(1,0);
        while(q--){
            int x;
            scanf("%d",&x);
            flip(x);
            if(check()) printf("Yesn");
            else printf("Non");
        }
    }
}
```
[1975F - Set](../problems/F._Set.md)

Idea: [Toxel](https://codeforces.com/profile/Toxel "International Grandmaster Toxel") Solution: [errorgorn](https://codeforces.com/profile/errorgorn "International Grandmaster errorgorn"), [Toxel](https://codeforces.com/profile/Toxel "International Grandmaster Toxel") Prepared by: [Nerovix](https://codeforces.com/profile/Nerovix "International Master Nerovix")

 **Hint 1**Consider enumerating each number from 0 to n−1 whether it is contained by S, when we have enumerated the first x numbers, there are only 2n−x constraints.

 **Solution**Read the hints.

Consider enumerating each number from 0 to n−1 whether it is contained by S. Suppose that the current enumeration reaches i, and in the remaining constraints, T1 and T2 are two sets, the only difference between them is whether they contain i (T1 contains i):

 * S contains i. We can merge T1 and T2 into a new constraint T′ and vT′=(vT1»1)&vT2.
* S doesn't contain i. We can merge T1 and T2 into a new constraint T′ and vT′=vT1&vT2.

We can merge constraints quickly when the enumeration reaches a new number. And the time complexity is O(n⋅2n)

 **Code**
```cpp
#include<bits/stdc++.h>

using namespace std;

const int N = 24, S = (1 << 20) + 5;
int n = 0, f[N][S] = {};
vector<int> ans;

inline void dfs(int s = 0, int i = 0){
	if(i < n){
		int m = 1 << (n - i - 1);
		for(int t = 0 ; t < m ; t ++) f[i + 1][t] = f[i][t] & f[i][m | t];
		dfs(s << 1, i + 1);
		for(int t = 0 ; t < m ; t ++) f[i + 1][t] = f[i][t] & (f[i][m | t] >> 1);
		dfs(s << 1 | 1, i + 1);
	}
	else if(f[n][0] & 1) ans.push_back(s);
}

int main(){
	scanf("%d", &n);
	f[0][0] = 1;
	for(int s = 1 ; s < 1 << n ; s ++) scanf("%d", &f[0][s]);
	dfs();
	printf("%dn", int(ans.size()));
	for(int s : ans) printf("%dn", s);
	return 0;
}
```
[1975G - Zimpha Fan Club](../problems/G._Zimpha_Fan_Club.md)

Idea: [Atomic-Jellyfish](https://codeforces.com/profile/Atomic-Jellyfish "Grandmaster Atomic-Jellyfish"), [zimpha](https://codeforces.com/profile/zimpha "Grandmaster zimpha") Solution: [Atomic-Jellyfish](https://codeforces.com/profile/Atomic-Jellyfish "Grandmaster Atomic-Jellyfish") Prepared by: [Atomic-Jellyfish](https://codeforces.com/profile/Atomic-Jellyfish "Grandmaster Atomic-Jellyfish"), [errorgorn](https://codeforces.com/profile/errorgorn "International Grandmaster errorgorn"), [MagicalFlower](https://codeforces.com/profile/MagicalFlower "International Grandmaster MagicalFlower")

 **Hint 1**If s,t both have ∗, or both don't have ∗, then it will be a simple problem. Can you try to solve this problem?

 **Hint 2**According to the first hint, we have discussed two cases. In the remaining cases, without loss of generality, we think that only t has ∗. Suppose we write t as t′0∗t′1∗t′2∗⋯∗t′k. Where t′i does not take ∗, assuming that |t′i|≤50 is satisfied for all i, can you solve this problem?

 **Hint 3**There is a strictly subproblem of this problem, namely, given two strings s and t consisting only of characters from a to z and −, you need to find all positions in s where t can be matched.

This problem has a classic solution, where − is set to 0, and a to z are sequentially assigned values from 1 to 26, and then let fi=∑mj=1[si+j−1>0]×[tj>0](si+j−1−tj)2, then all positions of fi=0 satisfy s[i,i+m−1] can match $t$​.

Decompose the calculation formula, fi=∑mj=1s2i+j−1+s2j−2∑mj=1si+j−1tj−∑mj=1[si+j−1=0]t2j−∑mj=1s2i+j−1[tj=0]. For ∑mj=1s2i+j−1+s2j, you can prefix and process it, and for the remaining part, you can use FFT in O(nlogn) to be resolved.

What is the use of this solution in the original problem?

 **Solution**Read the hints.

In the following, we consider n,m to be of the same order.

Consider the case where s and t do not contain ∗. We only need to be compared bit by bit.

Consider the case where s,t both contain ∗, if the beginning of s is not ∗ or the beginning of t is not ∗:

 * If one of the first characters of s and t is ∗ or the first characters can match, delete the first characters of the two strings that are not ∗.
* Oherwise the answer is obviously `No`.

Performing the same operation on the last characters, it is not difficult to find that it will be reduced to two strings ∗s′ and t′∗, where s′ and t′ are arbitrary strings. Then it is not difficult to find that t′s′ matches two strings at the same time. Therefore, as long as the head and tail can be successfully deleted, the answer must be `Yes`.

Consider the hardest case. Without loss of generality, we assume that only t contains ∗, otherwise s,t can be exchanged. We still delete the beginning and the end first. It is not difficult to find that thereafter t can be written as ∗t′1∗t′2∗⋯∗t′k∗.

Then we will have a greedy solution. We iterate i from 1 to n, find the first matching position of t′i in s each time, and delete tthese matching characters and all preceding characters in s, that is, remove a prefix of s, and then until all matching is completed or no matching position is found in s.

Assume that we use FFT to brute force solve this problem every time. See Hint.3 for the specific solution, then the complexity is O(nklogn).

But it is not difficult to find that this is very wasteful. In fact, we can do this:

 * When matching t′i, only take out the first |2t′i| characters of s each time and try to match t′i. Because if the match is successful, then since all positions matching t′i are deleted, it is not difficult to find that at least |t′i| characters are deleted. And if the match fails, it is not difficult to find that the first |t′i| characters of s will no longer be useful and can also be deleted. Therefore we remove at least the first |t′i| characters in s in complexity O(|t′i|log|t′i|).

Since the total length of s is n, the total time complexity does not exceed O(nlogn).

 **Code**
```cpp
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll N = (1 << 22) + 5, Mod = 2013265921, G = 31;

inline ll power(ll x, ll y){
	ll ret = 1;
	while(y){
		if(y & 1) ret = ret * x % Mod;
		x = x * x % Mod, y >>= 1;
	}
	return ret;
}

ll p[N] = {}, w[N] = {}, g[N] = {}, iv[N] = {};

inline void dft(ll n, ll a[], bool idft){
	for(ll i = 0 ; i < n ; i ++) if(i < p[i]) swap(a[i], a[p[i]]);
	for(ll m = 1 ; m < n ; m <<= 1) for(ll j = 0, k = 0 ; j < n ; j += m << 1, k ++) for(ll i = j ; i < j + m ; i ++){
		ll x = a[i], y = a[i + m];
		a[i] = x + y, a[i] >= Mod && (a[i] -= Mod);
		a[i + m] = (x - y + Mod) * w[k] % Mod;
	}
	if(!idft) return;
	reverse(a + 1, a + n);
	for(int i = 0 ; i < n ; i ++) a[i] = a[i] * iv[n] % Mod;
}

inline ll sqr(ll x){
	return x * x;
}

ll n = 0, m = 0, a[3][N] = {}, b[3][N] = {}, c[N] = {}, d[N] = {};
char s[N] = {}, t[N] = {};

inline ll work(ll L, ll R, ll l, ll r){
	ll M = 1; while(M < R - L + r - l) M <<= 1;
	w[0] = 1;
	for(ll k = 1 ; k < M ; k <<= 1){
		ll bit = M / 2 / k;
        if(k == M / 2) for(ll i = 0; i < k ; i ++) p[i + k] = p[i] | bit;
        else for(ll i = 0 ; i < k ; i ++){
            w[i + k] = w[i] * g[k] % Mod;
            p[i + k] = p[i] | bit;
        }
    }
	for(ll i = 0 ; i < M ; i ++){
		p[i] = p[i >> 1] >> 1;
		if(i & 1) p[i] |= M >> 1;
	}
	ll z = 0;
	for(ll i = 0 ; i < M ; i ++){
		c[i] = 0;
		for(ll f = 0 ; f < 3 ; f ++)  a[f][i] = b[f][i] = 0;
	}
	for(ll i = L ; i < R ; i ++){
		ll x = (s[i] == '-') ? 0 : (s[i] - 'a' + 1);
		a[0][i - L] = x ? 0 : 1, a[1][i - L] = 2 * x, a[2][i - L] = sqr(x), d[i] = sqr(x);
	}
	d[R] = 0;
	for(ll i = l ; i < r ; i ++){
		ll x = (t[i] == '-') ? 0 : (t[i] - 'a' + 1);
		b[0][r - i] = sqr(x), b[1][r - i] = x, b[2][r - i] = x ? 0 : 1, z += sqr(x);
	}
	for(ll f = 0 ; f < 3 ; f ++){
		dft(M, a[f], 0), dft(M, b[f], 0);
		for(ll i = 0 ; i < M ; i ++) c[i] = (c[i] + a[f][i] * b[f][i]) % Mod;
	}
	dft(M, c, 1);
	for(ll i = 0 ; i < r - l ; i ++) z += d[i + L];
	for(ll i = L ; i <= R - (r - l) ; z -= d[i], z += d[i + (r - l)], i ++) if(z % Mod == c[i - L + r - l]) return i;
	return -1;
}

int main(){
	for(ll i = 1 ; i < N ; i <<= 1) g[i] = power(G, Mod / 4 / i), iv[i] = power(i, Mod - 2);
	scanf("%lld %lld", &n, &m);
	scanf("%s %s", s, t);
	while(n && m && s[n - 1] != '*' && t[m - 1] != '*'){
		if(s[n - 1] != t[m - 1] && s[n - 1] != '-' && t[m - 1] != '-'){
			printf("No");
			return 0;
		}
		else n --, m --;
	}
	reverse(s, s + n), reverse(t, t + m);
	while(n && m && s[n - 1] != '*' && t[m - 1] != '*'){
		if(s[n - 1] != t[m - 1] && s[n - 1] != '-' && t[m - 1] != '-'){
			printf("No");
			return 0;
		}
		else n --, m --;
	}
	reverse(s, s + n), reverse(t, t + m);
	if(min(n, m) == 0){
		while(n && s[n - 1] == '*') n --;
		while(m && t[m - 1] == '*') m --;
		if(max(n, m) == 0) printf("Yes");
		else printf("No");
		return 0;
	}
	bool u = 0, v = 0;
	for(ll i = 0 ; i < n ; i ++) if(s[i] == '*') u = 1;
	for(ll i = 0 ; i < m ; i ++) if(t[i] == '*') v = 1;
	if(u){
		if(v){
			printf("Yes");
			return 0;
		}
		else swap(n, m), swap(s, t);
	}
	ll L = 0, R = 0;
	for(ll l = 1, r = l ; l < m ; l = r + 1, r = l){
		while(t[r] != '*') r ++;
		if(r - l) while(1){
			R = min(n, L + 2 * (r - l));
			if(R - L < r - l){
				printf("No");
				return 0;
			}
			ll h = work(L, R, l, r);
			if(h == -1) L = R - (r - l) + 1;
			else{
				L = h + r - l;
				break;
			}
		}
	}
	printf("Yes");
	return 0;
}
```
[1975H - 378QAQ and Core](../problems/H._378QAQ_and_Core.md)

Idea: [Bazoka13](https://codeforces.com/profile/Bazoka13 "Master Bazoka13") Solution: [Toxel](https://codeforces.com/profile/Toxel "International Grandmaster Toxel") Prepared by: [Bazoka13](https://codeforces.com/profile/Bazoka13 "Master Bazoka13")

 **Solution**Consider the maximum character m of the string s.

If m only appears once, then obviously the string starting with it is the largest in lexicographical order. To make it the smallest, m should be arranged at the end. Other characters can be arranged arbitrarily.

If m appears more than twice, it can be proven that the beginning and end of the answer string must be m. If the beginning of the string is not m, moving the character at the beginning to somewhere before a non-first m can make the suffix lexicographical order starting with this m smaller, while the suffix lexicographical order starting with m after this remains unchanged. For suffixes that do not start with m, they are definitely not the largest, so they do not need to be considered. If the end of the string is not m, first remove it, and all suffix lexicographical orders become smaller. Similarly, it can also be placed in front of a certain m to reduce the lexicographical order.

In this case, the answer is always in the form of ms1ms2m…mstm. Where s1,s2,…,st contain characters that are less than m, it could also be an empty string. Now suppose that the set s1,s2,…,st is determined, and consider how to arrange their order. Suppose we are currently comparing two suffixes Si=msim…mstm and Sj=msjm…mstm, and suppose si+k and sj+k are the first two substrings that appear differently. Then msim…msi+k−1 and msjm…msj+k−1 must be equal, and the size relationship between Si and Sj is the same as the size relationship between msi+k and msj+k. In this way, all msi can be sorted according to lexicographical order, and regarded as a new character, and Solving the original problem for (ms1​)(ms2)…(mst​) is sufficient.

Now consider how to determine the set s1,s2,…,st. For a certain si, it should obviously be ordered, because this can make msi smaller. There is also another property. Suppose there are si=pic and sj such that msj is the current lexicographically largest string, and mpi<msj, where c is a character less than m. Putting c after sj can make the answer smaller.

The proof of the property is as follows. Without loss of generality, let f1=pic, f2=pi, f3=sjc, f4=sj, then we have mf2<mf1<mf4 and f3m<f4m. Consider the subproblem after iteration, by definition, f4 is the largest character in the problem. If f1 and f4 are used, and there is an f4 to the left of some f1 in the optimal solution string, then replacing this f1 and its nearest f4 on the left with f2 and f3 respectively, it is easy to prove that the largest suffix will definitely become smaller or unchanged. Otherwise, all f1 are to the left of all f4, at this time you can arbitrarily replace some f1 and f4 with f2 and f3 respectively, it is easy to prove that the largest suffix still becomes smaller or unchanged.

Based on the above discussion, we can now give the final greedy algorithm for the problem. Suppose the largest character m has t+1 occurrences. If t=0, then put the only m at the end, and the other characters can be arranged arbitrarily. Otherwise, suppose there are p characters less than m, if p≤t, it can be proved that there is at most one character between any two m. Consider |si|≥2, sj=ε (empty string), then they meet the above properties, and it is more optimal to exchange the last character of si to sj. Therefore, s1,…,sp is a single character, sp+1=⋯=st=ε, and recursively solve the subproblem. Note that to ensure time complexity, when t≫p, multiple rounds of recursion need to be combined.

If p>t, it can be similarly proved that there will not be an si that is an empty string. In addition, consider the first character of all si, for those among these t characters that are not the largest, using the same property, it can be proved that the length of the string they are in must be 1, and no other characters will follow. Also, since si is ordered, it can be proved that the first character of all si must be the smallest t characters less than m. Next, the remaining characters will only be filled after those largest characters among these t characters, and it can be similarly proved that those filled in the second position of these strings are also the smallest among the remaining characters, and so on, until all characters are used up.

Notice that the complexity of each recursion is linear, and each recursion at least halves the number of characters, so the total complexity is O(nlogn). 

 **Bonus**How to solve this problem in O(n)?

 **Code**
```cpp
#include<bits/stdc++.h>
using namespace std;
struct ch{
    string c;
    ch(){c = "";}
    ch(string cc){c=cc;}
    bool operator == (const ch& p)const{
        return c==p.c;
    }
    bool operator != (const ch& p)const{
        return c!=p.c;
    }
    void add(ch& p){
        c.append(p.c);
    }
};
vector<ch> solve(vector<ch> cs){
    int n = cs.size();
    int t = 0;
    if(cs.empty())return cs;
    for(int i=n-2;i>=0;i--){
        if(cs[i]!=cs[n-1])break;
        t++;
    }
    if(t==0){
        vector<ch> res;
        res.push_back(cs[n-1]);
        return res;
    }
    int p = n-(t+1);
    if(p<=t){
        vector<ch> res;
        vector<ch> nxt;
        int k = (t+1)/(p+1);
        int le = (t+1)%(p+1);
        ch m = cs[n-1];
        for(int j=1;j<k;j++){
            m.add(cs[n-1]);
        }
        for(int i=0;i<p;i++){
            ch tmp = m;
            tmp.add(cs[i]);
            nxt.push_back(tmp);
        }
        for(int i=0;i<le;i++){
            nxt.push_back(cs[n-1]);
        }
        auto nxt_solved = solve(nxt);
        for(auto i:nxt_solved)res.push_back(i);
        res.push_back(m);
        return res;
    }else{
        vector<ch> res;
        vector<ch> nxt;
        ch m = cs[n-1];
        for(int i=0;i<t;i++){
            nxt.push_back(m);
        }
        int now = 0,beg=0;
        for(int i=0;i<p;i++){
            nxt[now].add(cs[i]);
            if(now>=1){
                if(cs[i]!=cs[i-1]){
                    beg=now;
                }
            }
            now++;
            if(now>=t)now=beg;
        }
        auto nxt_solved = solve(nxt);
        for(auto i:nxt_solved)res.push_back(i);
        res.push_back(m);
        return res;
    }
}
vector<ch> trans(string s){
    vector<ch> tmp;
    for(auto i:s){
        string tmpp = "";
        tmpp+=i;
        tmp.push_back(tmpp);
    }
    return tmp;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        sort(s.begin(),s.end());
        auto tmp = trans(s);
        auto ans= solve(tmp); 
        for(auto c:ans)cout<<c.c;
        cout<<"n";
    }
}
```
[1975I - Mind Bloom](../problems/I._Mind_Bloom.md)

Idea: [Atomic-Jellyfish](https://codeforces.com/profile/Atomic-Jellyfish "Grandmaster Atomic-Jellyfish") Solution: [Atomic-Jellyfish](https://codeforces.com/profile/Atomic-Jellyfish "Grandmaster Atomic-Jellyfish") Prepared by: [Atomic-Jellyfish](https://codeforces.com/profile/Atomic-Jellyfish "Grandmaster Atomic-Jellyfish"), [errorgorn](https://codeforces.com/profile/errorgorn "International Grandmaster errorgorn")

 **Hint 0**Play "Slay the Spire". Unfortunately, it doesn't help much.

 **Hint 1**It may be helpful to calculate the probability that your hand becomes empty instead of the probability that the draw pile becomes empty.

 **Hint 2**The intended solution is a O(n5) DP. The constant factor is small enough to run.

 **Solution**If all the cards in your hand is 0, you immediately lose. Therefore, we only need to consider whether we can empty our hand by playing cards with non-0 value.

Consider a sequence of playing cards that will lead to use losing. The sum over the probabilities of all these losing sequences is the probability of us losing.

To simplify the process, we will consider drawing x random cards from the deck as drawing a random card from the deck x times.

Consider a sequence of played cards as z1,z2,…,zk where zi is the index of the card played. Consider how zi was drawn into our hand. It is not hard to see that either:

 * zi was in our hand at the start
* zi from drawn from card aj where j is the maximum index such that zj≤zi and j<i.

From our previous observation, we can motivate the following range DP. Let f(i,0/1,u,p,x) denote the a sequence of played cards with the following:

 * the minimum index of a card we played is i
* whether there are any cards with value greater than i that is one of the cards that were in our hand in the start
* before we played this sequence, we played a card of value u
* before we played this sequence, the deck has p cards
* The **net** number of cards that we draw is x

We will use g(i,0/1,u,p,x) to help us transition quickly. It is defined as the suffix sum (on dimension i) of f.

Consider transitioning based on the card of index i.

We have the following transition for f(∗,0,∗,∗,∗):

 * f(i,0,u,p,x)=∑x−(ci−1)y=0g(i+1,0,u,p,y)×g(i,0,ci,p−(ci−1)−y,x−(ci−1)−y)×u+y(p−y+1)c_i
* g(i,0,u,p,x)=g(i+1,0,u,p,x)+f(i,0,u,p,x)

For f(∗,1,∗,∗,∗), To handle the fact that there are some cards that are initially in our hands, let h denote the the number of j>i such that sj=1.

If si=1, we have the following transitions:

 * f(i,1,u,p,x)=∑x−ciy=hg(i+1,1,u,p,y)×g(i,0,ci,p−(ci−1)−y+h,x−ci−y)×1(p−y+1+h)c_i
* g(i,1,u,p,x)=f(i,1,u,p,x)

If si=0, we have the following transitions:

 * f(i,1,u,p,x)=∑x−(ci−1)y=hg(i+1,1,u,p,y)×g(i,0,ci,p−(ci−1)−y+h,x−(ci−1)−y)×u+y(p−y+1+h)c_i
* g(i,1,u,p,x)=g(i+1,1,u,p,x)+f(i,1,u,p,x)

The time complexity is O(n5).

Now consider adding the cards with value 1. It is possible that our game never terminates when we keep on drawing cards with value 1. We will instead force that when we play a card of value 1, we are not allowed to draw a card of value 1. It is not hard to observe that the answer will not change.

Consider dp(i,x) to be the probability that we have in our hand:

 * i card of value 0
* x card of value 1

It is not hard to observe that for the initial state, dp(i,o+x) is g(1,1,i+x,0,m)×(i+xi)×(m−o)x_.

Next, consider the transitions. There are only two cases, we draw a card with value 0, or a card with value greater than $0$：

 * dp(i,x)×1w+k−i→dp(i+1,x−1)
* ∀j+y>1,dp(i,x)×g(1,0,1,n−d−i−x,j+y−1)×1w+k−i×(j+yj)×(m−x+1)y_→dp(i+j,x+y−1)

Finally, the answer is ∑ki=0dp(i,0)×ki_.

The time complexity is O(n4).

Therefore, the total complexity is O(n5). If we use FFT, it can be O(n4logn), but it was not required in our solution and would probably make the code slower.

Furthermore, we can record v instead of u, which means there are v cards with i or greater index drawn from u draws. So it's not difficult to find v≤u. And when ci≤√n, we have v≤u≤ci≤√n. And when ci>√n, we have v≤nci−1≤√n, the complexity can become O(n4.5). If we use FFT, it can be O(n3.5logn).

Let k be the number of cards with value 0. It is not hard to see that:

 * the size of i is n−k
* the size of x is k
* the size of u is n−k
* the size of p is n

The number of states is (n−k)2k2n, which has a constant of 116. We also have that y≤x and u≤ci, which both gives us another constant of 12. Since we have a flag in our dp state, it has a factor of 2. This gives us a constant factor of rougly 132, which is extremely small. So it is reasonable to expect O(n5) to run about 1 second.

 **Code**
```cpp
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll N = 120 + 5, Mod = 1e9 + 7;

inline ll power(ll x, ll y){
	ll ret = 1;
	while(y){
		if(y & 1) ret = ret * x % Mod;
		x = x * x % Mod, y >>= 1;
	}
	return ret;
}

inline ll inv(ll x){
	return power(x, Mod - 2);
}

ll n = 0, m = 0, w = 0, o = 0, d = 0, r = 0, k = 0, c[N] = {}, v[N] = {};
ll iv[N] = {}, a[N][N] = {}, b[N][N] = {}, binom[N][N] = {};
ll f[2][2][N][N][N] = {}, g[2][2][N][N][N] = {}, dp[N][N] = {};
char s[N] = {};

inline void init(){
	n = m = w = o = d = r = k = 0;
	memset(c, 0, sizeof(c)), memset(v, 0, sizeof(v)), memset(s, 0, sizeof(s));
	memset(f, 0, sizeof(f)), memset(g, 0, sizeof(g)), memset(dp, 0, sizeof(dp));
}

inline void solve(){
	scanf("%lld", &n);
	v[0] = v[1] = 1;
	for(ll i = 1 ; i <= n ; i ++){
		scanf("%lld", &c[i]);
		v[c[i]] = 1;
	}
	scanf("%s", s + 1);
	for(ll i = 1 ; i <= n ; i ++){
		if(s[i] == '0') r ++;
		if(c[i] > 1) w ++;
		else if(c[i] == 1){
			if(s[i] == '1') o ++;
			m ++;
		}
		else{
			if(s[i] == '1') d ++;
			else k ++;
		}
	}
	if(c[n] <= 1){
		for(ll i = 1 ; i <= n ; i ++) if(s[i] == '0'){
			printf("0n");
			return;
		}
		printf("1n");
		return;
	}
	for(ll p = 0 ; p <= n ; p ++) for(ll u = 0 ; u <= c[n] ; u ++) if(v[u]){
		f[1][0][u][p][0] = f[1][1][u][p][0] = 1;
		g[1][0][u][p][0] = g[1][1][u][p][0] = 1;
	}
	for(ll i = n, h = 0 ; c[i] > 1 ; i --){
		for(ll p = 0 ; p <= n ; p ++) for(ll u = 0 ; u <= c[i] ; u ++) if(v[u]){
			g[0][0][u][p][0] = 1;
			if(s[i] == '0') g[0][1][u][p][0] = g[1][1][u][p][0];
		}
		for(ll p = 0 ; p <= n ; p ++) for(ll u = 0 ; u <= c[i] ; u ++) if(v[u]) for(ll x = 1 ; x <= k ; x ++){
			for(ll y = 0 ; y <= x - (c[i] - 1) ; y ++) f[0][0][u][p][x] = (f[0][0][u][p][x] + (g[1][0][u][p][y] * g[0][0][c[i]][p - (c[i] - 1) - y][x - (c[i] - 1) - y] % Mod) * ((u + y) * b[p - y + 1][c[i]] % Mod)) % Mod;
			g[0][0][u][p][x] = (g[1][0][u][p][x] + f[0][0][u][p][x]) % Mod;
		}
		for(ll p = 0 ; p <= n ; p ++) for(ll u = 0 ; u <= c[i] ; u ++) if(v[u]) for(ll x = 1 ; x <= k ; x ++){
			if(s[i] == '1'){
				for(ll y = h ; y <= x - c[i] ; y ++) f[0][1][u][p][x] = (f[0][1][u][p][x] + (g[1][1][u][p][y] * g[0][0][c[i]][p - (c[i] - 1) - y + h][x - c[i] - y] % Mod) * b[p - y + 1 + h][c[i]]) % Mod;
				g[0][1][u][p][x] = f[0][1][u][p][x];
			}
			else{
				for(ll y = h ; y <= x - (c[i] - 1) ; y ++) f[0][1][u][p][x] = (f[0][1][u][p][x] + (g[1][1][u][p][y] * g[0][0][c[i]][p - (c[i] - 1) - y + h][x - (c[i] - 1) - y] % Mod) * ((u + y) * b[p - y + 1 + h][c[i]] % Mod)) % Mod;
				g[0][1][u][p][x] = (g[1][1][u][p][x] + f[0][1][u][p][x]) % Mod;
			}
		}
		for(ll p = 0 ; p <= n ; p ++) for(ll u = 0 ; u <= c[i] ; u ++) if(v[u]) for(ll x = 0 ; x <= k ; x ++){
			f[1][0][u][p][x] = f[0][0][u][p][x], f[1][1][u][p][x] = f[0][1][u][p][x];
			g[1][0][u][p][x] = g[0][0][u][p][x], g[1][1][u][p][x] = g[0][1][u][p][x];
			f[0][0][u][p][x] = f[0][1][u][p][x] = g[0][0][u][p][x] = g[0][1][u][p][x] = 0;
		}
		if(s[i] == '1') h ++;
	}
	for(ll i = 0 ; i <= k ; i ++) for(ll x = 0 ; x <= m - o ; x ++) dp[i][o + x] = g[1][1][0][r][i + x] * (binom[i + x][i] * a[m - o][x] % Mod) % Mod;
	for(ll i = 0 ; i <= k ; i ++) for(ll x = 1 ; x <= m ; x ++) if(dp[i][x]){
		if(i < k) dp[i + 1][x - 1] = (dp[i + 1][x - 1] + dp[i][x] * iv[w + k - i]) % Mod;
		for(ll j = 0 ; i + j <= k ; j ++) for(ll y = 0 ; x + y - 1 <= m ; y ++) if(j + y > 1) dp[i + j][x + y - 1] = (dp[i + j][x + y - 1] + (dp[i][x] * g[1][0][1][n - d - i - x][j + y - 1] % Mod) * (iv[w + k - i] * (binom[j + y][j] * a[m - x + 1][y] % Mod) % Mod)) % Mod;
	}
	ll ans = 1;
	for(ll i = 0 ; i <= k ; i ++) ans = (ans + (Mod - dp[i][0]) * a[k][i]) % Mod;
	printf("%lldn", ans);
}

ll T = 0;

int main(){
	for(ll x = 0 ; x < N ; x ++){
		a[x][0] = b[x][0] = 1, iv[x] = inv(x), binom[x][0] = 1;
		for(ll y = 1 ; y <= x ; y ++){
			a[x][y] = a[x][y - 1] * (x - y + 1) % Mod, b[x][y] = inv(a[x][y]);
			binom[x][y] = (binom[x - 1][y - 1] + binom[x - 1][y]) % Mod;
		}
	}
	scanf("%lld", &T);
	for(ll i = 1 ; i <= T ; i ++) init(), solve();
	return 0;
}
```
Solution by [Melania](https://codeforces.com/profile/Melania "Grandmaster Melania")

 **Solution**Let S denote the set of cards currently in Jellyfish's hand.

We assume that a1=0 and an≥2. Initially, |S|∈[1,n−1]. Cases where these conditions do not hold are trivial.

We observe that Jellyfish cannot empty the draw pile if and only if she runs out of non-zero cards to play. In the following section, we compute the probability that she eventually runs out of non-zero cards.

It is clear that in any scenario where she runs out of non-zero cards, max(S) must gradually decrease to zero. We can break down the entire process into sub-procedures, where in each sub-procedure, max(S) decreases from i to ≤i−1, ultimately reaching zero.

Assume she is currently in a state where max(S)=i and |S∖i|=x. We denote Fi,x,y as the probability that she will eventually transition to a state where max(S)≤i−1, and in the very first state where max(S)≤i−1, the size of S is y.

 

---

For a fixed and given pair (i,x), we aim to compute all values of Fi,x,y simultaneously.

To determine the values of Fi,x,y, consider the situation after Jellyfish plays card ai. For the remaining n−x cards, each card is equally likely to be one of the ai cards drawn. Therefore, for any individual card outside of the initial x cards, the probability of possessing that card is p=ain−x.

We define the initial event where Jellyfish plays card ai as the starting point of our timeline. Following this event, we consider n−i+2 key moments when max(S) becomes ≤n for the first time, ≤n−1 for the first time, and so on, down to ≤i+1, ≤i, and finally ≤i−1 for the first time.

We denote Gj,y as the probability that Jellyfish will eventually reach a state where max(S)≤j, and in the very first state where max(S)≤j, the size of S is y. Initially, Gn,x+ai=1.

To understand the transitions of Gj,y, note that since all cards ≤j (excluding the initial x cards) are symmetrical, the probability of owning card j is exactly p=y−xj−x.

 * If Jellyfish does not own card j, then the first state where max(S)≤j−1 is simply the first state where max(S)≤j. This describes a transition of Gj−1,y←(1−p)Gj,y.
* If Jellyfish owns card j, we enumerate the number of cards |S|=z in her hand when she first reaches max(S)≤j−1. The probability of this happening is Fj,y−1,z. Thus, we have Gj−1,z←pGj,yFj,y−1,z.

Here’s a further explanation of why "all cards ≤j (excluding the initial x cards) are symmetrical": Because this state is the very first time max(S)≤j, it means that all cards played before this state and after Jellyfish initially plays ai are ≥j+1. From the perspective of those cards ≥j+1, all cards ≤j (excluding the initial x cards) are symmetrical.

 

---

In the end, the actual algorithm we derived for computing Fi,x,y is quite straightforward:

 * Iterate through j backwards from n to i.
* For each Gj,y, make two types of transitions:

 1. Gj−1,z←pGj,yFj,y−1,z, where p=y−xj−x;
2. Gj−1,y←(1−p)Gj,y.

Finally, Fi,x,y=Gi−1,y.

A small catch is that we could have self-loops. If ai=1, then in the final step where j=i, there will be some transitions where Fi,x,y←cFi,x,y. For a given Fi,x,y, if all the other known values that contribute to it sum to A and all the c coefficients sum to C, then we have Fi,x,y=A+CFi,x,y. This results in Fi,x,y=A1−C. We can address this by calculating the inverse.

It can be shown that if we also iterate through x from larger to smaller values, no Fi,x,y will use other values of Fi′,x′,y′ that are neither known nor equal to Fi,x,y itself. In other words, the value of Fi,x,y does not invoke other unknown values of Fi′,x′,y′.

 

---

After computing all values of Fi,x,y, we proceed to determine the final answer.

We define ansi,x as the average probability that Jellyfish will eventually run out of non-zero cards (thus losing the game) if she starts with all si cards in [1,i] (which she owns initially) plus an additional x cards drawn randomly from the remaining i−si cards in [1,i] (which she does not own initially).

 * If ci=1, the transition is given by: ansi,x=∑Fi,x−1,yansi−1,y;
* If ci=0, the transition is given by: ansi,x=(1−p)ansi−1,x+p∑Fi,x−1,yansi−1,y, where p=x−sii−si.

Finally, we compute 1−ansn,sn to obtain the probability that Jellyfish will eventually win the game.

The time complexity of this approach is O(n5+n3logp), and the space complexity is O(n3).

 

---

It is also possible to optimize the O(n5) time complexity to O(n4√n) by using Lagrange interpolation.

To achieve this speedup, we notice that the values of i and x do not play a crucial role in the transition of Gj,y. Specifically, the influence of the values i and x on the transition of Gj,y can be described as follows:

 * The initial value is Gn,x+ai=1.
* During the transition, p=y−xj−x and 1−p=j−yj−x.

We can fix the value of k=x+ai and treat x as a variable, maintaining a polynomial in x as the value of Gj,y.

We observe that it is only necessary to keep the point values between [k−1,k−√n] to track the polynomial accurately.

 * For ai>√n, since each transition involving multiplication by p will increase the value of y by at least ai, it is clear that the degree of the polynomial Gj,y is at most √n. Thus, keeping track of √n values is sufficient to restore the polynomial, and we can use linear Lagrange interpolation to obtain the point values outside these √n points.
* For ai≤√n, since x=k−ai, we only care about the point values in the range [k−1,k−√n]. Although the polynomial restored may be inaccurate beyond this range, these point values are the ones that matter for our calculations anyway.

By applying this optimization, we effectively reduce the time complexity to O(n4√n+n3logp).

