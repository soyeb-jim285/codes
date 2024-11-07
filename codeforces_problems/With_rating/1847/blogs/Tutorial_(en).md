# Tutorial_(en)

[1847:A — The Man who became a God](../problems/A._The_Man_who_became_a_God_.md)

 * Author — [PoPularPlusPlus](https://codeforces.com/profile/PoPularPlusPlus "Master PoPularPlusPlus")

 **tutorial**
### [1847A - The Man who became a God](../problems/A._The_Man_who_became_a_God_.md "Codeforces Round 882 (Div. 2)")

Let us find $f(1,n)$. Now, you need to divide the array into more $K-1$ parts. When you split an array $b$ of size $m$ into two parts, the suspicion changes from $f(1,m)$ to $f(1,i)+f(i+1,m)$ ($1 \leq i < m$). Also, $f(1,m) = f(1,i) + |b_i - b_{i+1}| + f(i+1,m)$. Substituting this in previous change, we get $f(1,i) + |b_i - b_{i+1}| + f(i+1,m)$ changes to $f(1,i) + f(i+1,m)$. That is, $|b_i - b_{i+1}|$ gets subtracted. Now, to get minimum suspicion, we need to break the array $a$ at $i$ such that $|a_i-a_{i+1}|$ gets maximised.

Now, we have array $dif$ of size $n-1$ where $dif_i = |a_{i+1} - a_i|$ ($ 1 \leq i < n$). We can solve the problem using any of the two approaches.

- Find the least element in $dif$ and remove that from $dif$ and add that element to the answer. Do this exactly $k-1$ times. Time complexity - $O(n^2)$.

- We can sort $dif$ and don't take $k-1$ maximum elements (or take first $(n-1)-(k-1)$ elements. Time Complexity - $O(n \log n)$.

 **solution**
```cpp
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long 
#define pb(e) push_back(e)
#define sv(a) sort(a.begin(),a.end())
#define sa(a,n) sort(a,a+n)
#define mp(a,b) make_pair(a,b)
#define all(x) x.begin(),x.end()

void solve(){
	int n , k;
	cin >> n >> k;
	ll arr[n];
	for(int i = 0; i < n; i++)cin >> arr[i];
	vector<ll> v;
	ll sum = 0;
	for(int i = 1; i < n; i++){
		v.pb(abs(arr[i] - arr[i-1]));
		sum += v.back();
	}
	sort(all(v));
	for(int groups = 1; groups < k; groups++){
		sum -= v.back();
		v.pop_back();
	}
	cout << sum << 'n';
}

int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
	int t;cin >> t;while(t--)
	solve();
	return 0;
}

```
[1847:B — Hamon Odyssey](../problems/B._Hamon_Odyssey.md)

 * Author — [PoPularPlusPlus](https://codeforces.com/profile/PoPularPlusPlus "Master PoPularPlusPlus")

 **tutorial**
### [1847B - Hamon Odyssey](../problems/B._Hamon_Odyssey.md "Codeforces Round 882 (Div. 2)")

There are two cases in this problem. First, if $f(1,n) > 0$, then maximum number of groups becomes $1$. This is because there are some bits set in all the elements. Now, if we divide the array in more than one group, then these bits are taken more than once which will not give smallest AND. Second case is when $f(1,n) = 0$. This means the smallest AND is $0$. Now, we need to greedily divide the array into subarrays such that the AND of each subarray should be $0$. We keep taking elements in the subarray until the AND becomes $0$. When AND becomes $0$, we take remaining elements in the next subarray. If the last subarray has AND more than $0$, then we need to merge that subarray with the previous subarray.

Time complexity - $O(n)$.

 **solution**
```cpp
#include <iostream>
#include <vector>
using namespace std;
#define ll long long
#define ull unsigned long long 
#define pb(e) push_back(e)
#define sv(a) sort(a.begin(),a.end())
#define sa(a,n) sort(a,a+n)
#define mp(a,b) make_pair(a,b)
#define all(x) x.begin(),x.end()

void solve(){
	int n;
	cin >> n;
	int arr[n];
	for(int i = 0; i < n; i++)cin >> arr[i];
	int cur = arr[0];
	int part = 1;
	for(int i = 0; i < n; i++){
		cur &= arr[i];
		if(cur == 0){
			if(i == n-1)break;
			part++;
			cur = arr[i + 1];
		}
	}
	if(cur != 0)part--;
	part = max(part,1);
	cout << part << 'n';
}

int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
	int t;cin >> t;while(t--)
	solve();
	return 0;
}
```
[1847:C-Vampiric Powers, anyone?](../problems/C._Vampiric_Powers,_anyone_.md)

 * Author — [PoPularPlusPlus](https://codeforces.com/profile/PoPularPlusPlus "Master PoPularPlusPlus")

 **tutorial**
### [1847C — Vampiric Powers, anyone?](../problems/C._Vampiric_Powers,_anyone_.md)

At the end of the array, you can only achieve xor of any subarray of the original array.

 **proof**Lets denote f(u,v)= xor of all ai such that min(u,v)≤i<max(u,v). In the first operation you add f(n,i). I.e. [u1,v1)=[n,i). It can be proven that f(uk,vk)=f(vk−1,vk) in the k-th operation which is a range.

 **proof**Suppose we have taken k ranges that already satisfy this property. Now, I add a new k+1-th range. So, first I need to take the k-th range f(uk,vk). Now I'm xoring it with the range f(uk−1,vk−1). As [ uk,vk) and [ uk−1,vk−1) share an endpoint, the result for these ranges will be a range.

 **proof**For two ranges f(x,y) and f(y,z), if the two ranges do not intersect, the result will be the sum of the two ranges f(x,z). If the two ranges intersect, then the intersections will be cancelled out, and the result will be the difference f(x,z).

Now, we maintain a boolean array b where bi is 1 if there is some j such that a1⊕a2⊕⋯⊕aj=i. Initially, b is all 0. We loop j from 1 to n and check for each k if bk=1. If it is, then there is some position p<j such that a1⊕a2⊕⋯⊕ap=k. If we take xor of range from (p,j], then it will be k⊕a1⊕a2⊕⋯⊕aj (as a1⊕a2⊕⋯⊕ap gets cancelled). This a1⊕a2⊕⋯⊕aj can be stored as we loop ahead. We are looping all possible prefix xors and not all prefix positions because n is large. 

Time Complexity — O(n⋅28).

 **solution**
```cpp
#include <bits/stdc++.h>
using namespace std;
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int ntest;
    cin >> ntest;
    while (ntest--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto &i : a)
            cin >> i;
 
        int const max_value = 1 << 8;
        vector<char> has_pref(max_value);
        has_pref[0] = true;
        int cur_xor = 0;
        int ans = 0;
        for (auto i : a) {
            cur_xor ^= i;
            for (int pref = 0; pref < max_value; ++pref) {
                if (has_pref[pref]) {
                    ans = max(ans, pref ^ cur_xor);
                }
            }
            has_pref[cur_xor] = true;
        }
 
        cout << ans << 'n';
    }
}
```
[1847:D Professor Higashikata](../problems/D._Professor_Higashikata.md)

 * Author — [PoPularPlusPlus](https://codeforces.com/profile/PoPularPlusPlus "Master PoPularPlusPlus")

 **tutorial**
### [1847D - Professor Higashikata](../problems/D._Professor_Higashikata.md "Codeforces Round 882 (Div. 2)")

Lets assume you know string $t$. String $t$ is made by positions in $s$. Lets denote $f(i) = $ position in $s$ from which $t_i$ is made. For maximising $t$ you need to make the starting elements in $t$ as large as possible. Now, to make $t$ lexicographically as large as possible, we need to swap positions in $s$. We can swap positions greedily. We first try making $s_{f(1)} = 1$. Then we try making $s_{f(2)} = 1$ and so on. 

Now, suppose for two indices $i$,$j$ ($1 \leq i < j \leq |t|$) such that $f(i) = f(j)$, we know that index $j$ is waste. $t$ is basically the preference of indices in $s$ which should be equal to $1$. If $s_{f(j)}$ is to be set $1$, then it would already be set $1$ because before setting $s_{f(j)}$ equal to $1$ we would have already set $s_{f(i)}$ equal to $1$ because $f(i)$ is equal to $f(j)$. Hence, for each index $i$ in $s$, we only add its first occurrence in $t$. This makes the size of $t$ bound by size of $s$. Now, this $t$ can be found using various pbds like set,dsu,segment tree,etc. 

Now, before answering the queries, we find the answer for the current string $s$. We know that there are $x$ ones and $n-x$ zeros in $s$. So, for each $i$ ($1 \leq i \leq min(x,|t|)$), we make $s_{f(i)} = 1$. Hence, the number of swaps needed will become number of positions $i$ ($1\leq i \leq min(x,|t|)$) such that $s_i=0$.

Now, in each query, there is exactly one positions that is either getting flipped from $0$ to $1$ or from $1$ to $0$. That is, $x$ is either getting changed to $x+1$ or $x-1$. You already know the answer for $x$. Now, if $x$ is getting reduced, then you need to decrease the answer by one if $x <= |t|$ and $s_{f(x)}=0$. If $x$ is increasing by one, then you need to add one to the answer if $x < |t|$ and $s_{f(x+1)} = 0$. 

Time complexity - $O(n \log n + q)$. 

 **solution**
```cpp
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long 
#define pb(e) push_back(e)
#define sv(a) sort(a.begin(),a.end())
#define sa(a,n) sort(a,a+n)
#define mp(a,b) make_pair(a,b)
#define vf first
#define vs second
#define all(x) x.begin(),x.end()
 
void solve(){
	int n , m , q;
	cin >> n >> m >> q;
	string st;
	cin >> st;
	vector<pair<int,int>> ranges;
	for(int i = 0; i < m; i++){
		int l , r;
		cin >> l >> r;
		l--;
		r--;
		ranges.pb(mp(l,r));
	}
	set<int> s;
	for(int i = 0; i < n; i++)s.insert(i);
	vector<int> v;
	int pos_in_v[n];
	memset(pos_in_v,-1,sizeof pos_in_v);
	for(int i = 0; i < m; i++){
		auto it = s.lower_bound(ranges[i].vf);
		vector<int> toerase;
		while(it != s.end() && (*it) <= ranges[i].vs){
			toerase.pb((*it));
			v.pb(toerase.back());
			pos_in_v[toerase.back()] = v.size()-1;
			it++;
		}
		while(toerase.size()){
			s.erase(toerase.back());
			toerase.pop_back();
		}
	}
	int cnt = 0;
	for(int i = 0; i < n; i++){
		if(st[i] == '1')cnt++;
	}
	int ans = 0;
	for(int i = 0; i < min(cnt , (int)v.size()); i++){
		if(st[v[i]] == '0')ans++;
	}
	
	while(q--){
		int pos;
		cin >> pos;
		pos--;
		if(pos_in_v[pos] != -1 && pos_in_v[pos] < cnt){
			if(st[pos] == '0'){
				ans--;
			}
			else ans++;
		}
		if(st[pos] == '0'){
			st[pos] = '1';
			cnt++;
			if(cnt <= v.size() && st[v[cnt-1]] == '0')ans++;
		}
		else {
			st[pos] = '0';
			if(cnt > 0 && cnt <= v.size() && st[v[cnt-1]] == '0')ans--;
			cnt--;
		}
		cout << ans << 'n';
	}
}
 
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
	//int t;cin >> t;while(t--)
	solve();
	return 0;
}
```
[1847:E Triangle Platinum?](../problems/E._Triangle_Platinum_.md)

 * Author — [StArChAn](https://codeforces.com/profile/StArChAn "Expert StArChAn")

 **tutorial**
### [1847E - Triangle Platinum?](../problems/E._Triangle_Platinum_.md "Codeforces Round 882 (Div. 2)")

First, notice that we can uniquely determine the multiset of numbers any three $a_i, a_j, a_k$ except for the collision between triples $(1, 4, 4)$ and $(2, 2, 3)$. The issue is that even if we know the multiset we cannot always uniquely determine $a_i, a_j, a_k$. 

But what if all the elements of the multiset are equal? Then each element obviously has to be equal to the value of the multiset. So if for some three distinct $i, j, k$ the area of $a_i, a_j, a_k$ is one of $\sqrt{3}/4, \sqrt{3}, 9\sqrt{3}/4, 4\sqrt{3}$, then they are all equal to $1, 2, 3$ or $4$ respectively, depending on the area. 

Let us say we knew that $a_i = a_j = a_k = C$ for some $C \in [1, 4]$ after asking $q$ queries. By querying $(i, j, x)$ for every $x$ other than $i, j$ we can obtain the area of $C, C, a_x$ for each $x$. This will allow us to uniquely determine each $a_x$. But wait! There is an important edge case here. We also require $C, C, a_x$ to form a valid triangle. 

If $C \geq 2$, this is not an issue because $2, 2, 4$ can be just assigned an area of "$0$" and we can still uniquely retrieve the values. So using this procedure, it takes us $q+n-3$ queries to determine all the values.

The only possibility remaining is when $C = 1$. In this case, the issue is that only $[1, 1, 1]$ let us know the value of $a_x$. When $a_x > 1$, it's impossible to distinguish between $a_x = 2, 3, 4$. So if we asked all questions, we would know which indices have value $> 1$ and which indices have a value of $1$. 

Now if we could find two equal elements among these indices with value $> 1$, we can repeat a similar linear scan as above and find all values. But how do we find two equal values? Notice that every value is among $2, 3, 4$. So if we had $ \geq 4$ such indices with value $ > 1$ some two of them would be equal, and we could find them by bruting queries of the form $(i, m_1, m_2)$ over all pairs of indices $m_1, m_2$ with value $> 1$. 

After this we can then again query all the other $> 1$ indices and find answer. This would take around $q+n'+2(n-n')-\mathcal O(1)$ queries, where $n'$ is the number of ones. Unfortunately this would QLE if $n'$ were around $n/2$.

How do we fix this? The answer is surprisingly simple. When we were finding indices with value $ > 1$ we simply stop the minute we have at least $4$ such indices (it's ok even if we don't).

Now we brute over all pairs. If we find two equal, we are done within at most $q+n+16$ queries. On the other hand if we cannot find two equal it means that we can never distinguish between them. This is because any query of the form $(1, x, y)$ where $x \ne y$ are both $\geq 2$ is always a degenerate query hence will have answer $0$. So if we do not find two equal, we will print $-1$.

After all this work, there are still a few details left. First, $q$ must be small. Otherwise all the above work is useless. Second there should be three equal elements in the first place. 

The first observation is that if $n \geq 9$ then by Piegonhole Principle, some $\lceil n/4 \rceil \geq 3$ must be equal. So if $n \geq 9$ then by bruting over all $1 \leq i < j < k \leq 9$ triples $(i, j, k)$ we can always find some three equal. Here we would have $q = {9 \choose 3} = 84$ and we are asking at most $n+84+16$ queries, which fits comfortably.

But what if $n < 9$? In this case we can simply brute all possible ${9 \choose 3} = 84$ queries and then for each of the $4^n$ arrays possible check if the triples of that array match with the query answers obtained here. If there is exactly one such array, we have found it and we can print it, otherwise we print $-1$ because it is not possible to uniquely determine the values of the array. Notice that this takes at most $4^8 \cdot {8 \choose 3}$ operations, which is around $3.7 \cdot 10^6$ which fits in the TL.

This solves the problem. 

You might wonder why $5500$ queries were allowed even though the above solution does not use more than around $5100$ queries. This is because we allowed randomisation as a valid way of finding three equal values $a_i, a_j, a_k$. Suppose there are $c_1, c_2, c_3, c_4$ counts of $1, 2, 3, 4$ respectively. If we randomly queried a triple $(i, j, k)$ each time, the probability all would be equal is precisely: $$\frac{{c_1 \choose 3}+{c_2 \choose 3}+{c_3 \choose 3}+{c_4 \choose 3}}{{n \choose 3}}$$ It is easy to see that the above is minimised when the $c_i$ are roughly equal. When $n \geq 30$, the above is at most $\frac{1}{17}$, so we will find a equal triple very quickly. The other case is when $n < 30$. In this case, since ${30 \choose 3} < 5500$, we can simply query every triple and solve directly by finding three equal instead of relying on randomness. This sort of a method gives $q \leq 400$ with very high probability, so it will still pass with at most $5500$ queries.

 **deterministic solution**
```cpp
#include<bits/stdc++.h>
using namespace std;
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
int n, ans[5005], holy[10][10][10];
map<vector<int>, int> GG;
int area(int x, int y, int z)
{
    int ok = max(x, max(y, z));
    int sum = x+y+z;
    if(2*ok >= sum) return 0;
    return sum*(sum-2*x)*(sum-2*y)*(sum-2*z);
}
int query(vector<int> v)
{
    sort(v.begin(), v.end());
    if(GG.find(v) != GG.end()) return GG[v];
    cout << "? " << v[0] << " " << v[1] << " " << v[2] << endl;
    int ret; cin >> ret; assert(ret != -1); return GG[v] = ret;
}
void print(bool found = true)
{
    if(!found)
    {
        cout << "! -1" << endl;
        exit(0);
    }
    cout << "! ";
    for(int i = 1; i <= n; i++) cout << ans[i] << " ";
    cout << endl; exit(0);
}
bool works()
{
    for(int i = 1; i <= n; i++)
    {
        for(int j = i+1; j <= n; j++)
        {
            for(int k = j+1; k <= n; k++)
            {
                if(area(ans[i], ans[j], ans[k]) != holy[i][j][k])
                    return false;
            }
        }
    }
    return true;
}
void brute()
{
    for(int i = 1; i <= n; i++)
    {
        for(int j = i+1; j <= n; j++)
        {
            for(int k = j+1; k <= n; k++)
                holy[i][j][k] = query({i, j, k});
        }
    }
    int mask = 1<<(2*n);
    int lol = 0;
    int workser = -1;
    for(int i = 0; i < mask; i++)
    {
        int copy = i;
        for(int k = 1; k <= n; k++)
        {
            ans[k] = 1+copy%4;
            copy/=4;
        }
        if(works())
        {
            workser = i;
            lol++;
        }
    }
    assert(lol);
    if(lol > 1) print(false);
    int copy = workser;
    for(int k = 1; k <= n; k++)
    {
        ans[k] = 1+copy%4;
        copy/=4;
    }
    print();
}

signed main()
{
    ios_base::sync_with_stdio(false); cin >> n;
    if(n <= 8) brute();
    map<int, int> nice;
    for(int i = 1; i <= 4; i++) nice[area(i, i, i)] = i;
    int a, b, X;
    
    {
        bool found = false;
        for(int i = 1; i <= min(n, 9) && !found; i++)
        {
            for(int j = i+1; j <= min(n, 9) && !found; j++)
            {
                for(int k = j+1; k <= min(n, 9) && !found; k++)
                {
                    if(nice[query({i, j, k})])
                    {
                        a = i;
                        b = j;
                        X = nice[query({i, j, k})];
                        found = true;
                    }
                }
            }
        }
    }
    if(X > 1)
    {
        map<int, int> ok;
        for(int i = 1; i <= 4; i++) ok[area(i, X, X)] = i;
        for(int i = 1; i <= n; i++) ans[i] = ((i==a) || (i==b))? X : ok[query({a, b, i})];
        print();
        return 0;
    }
    vector<int> non_ones;
    for(int i = 1; i <= n; i++)
    {
        if(i == a || i == b || query({i, a, b}))
            ans[i] = 1;
        else
            non_ones.push_back(i);
        if(non_ones.size() == 4) break;
    }
    if(non_ones.empty()) print();
    map<int, int> ok;
    for(int i = 2; i <= 4; i++) ok[area(1, i, i)] = i;
    int x, y, Z; x = y = -1; Z = 0;
    for(int i = 0; i < non_ones.size() && (Z == 0); i++)
    {
        for(int j = i+1; j < non_ones.size() && (Z == 0); j++)
        {
            if(ok[query({a, non_ones[i], non_ones[j]})])
            {
                x = non_ones[i];
                y = non_ones[j];
                Z = ok[query({a, non_ones[i], non_ones[j]})];
            }
        }
    }
    if(x == -1) print(false);
    map<int, int> fin; ans[x] = ans[y] = Z; 
    for(int i = 1; i <= 4; i++) fin[area(Z, Z, i)] = i;
    for(int i = 1; i <= n; i++) ans[i] = ans[i]? ans[i] : fin[query({x, y, i})];
    print();
    return 0;
}
```
 **randomisation solution**
```cpp
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define f first
#define s second
 
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
const int N = 5005;
int ans[N];
int n;
int dp[5][5][5];
int holy[11][11][11];
 
int area(int a, int b, int c){
    if (a >= b + c) return 0;
    if (b >= a + c) return 0;
    if (c >= a + b) return 0;
    
    int s = (a + b + c);
    return s * (s - 2 * a) * (s - 2 * b) * (s - 2 * c);
}
 
int query(int a, int b, int c){
    cout << "? " << a << " " << b << " " << c << endl;
    int ans; cin >> ans;
    return ans;
}
 
void print(bool found = true){
    if (!found){
        cout << "! -1n";
        exit(0);
    } else {
        cout << "! ";
        for (int i = 1; i <= n; i++) cout << ans[i] << " ";
        cout << endl;
        exit(0);
    }
}
 
bool works(){
    for (int i = 1; i <= n; i++){
        for (int j = i + 1; j <= n; j++){
            for (int k = j + 1; k <= n; k++){
                if (area(ans[i], ans[j], ans[k]) != holy[i][j][k])
                    return false;
            }
        }
    }
    
    return true;
}
 
void brutesmall(){
    for (int i = 1; i <= n; i++){
        for (int j = i + 1; j <= n; j++){
            for (int k = j + 1; k <= n; k++){
                holy[i][j][k] = query(i, j, k);
            }
        }
    }
    
    int mask = 1 << (2 * n);
    int lol = 0;
    for (int i = 0; i < mask; i++){
        int copy = i;
        
        for (int i = 1; i <= n; i++){
            ans[i] = 1 + copy % 4;
            copy /= 4;
        }
        
        if (works()){
            lol++;
        }
    }
    
    if (lol > 1) print(false);
    
    for (int i = 0; i < mask; i++){
        int copy = i;
        
        for (int i = 1; i <= n; i++){
            ans[i] = 1 + copy % 4;
            copy /= 4;
        }
        
        if (works()){
            print();
        }
    }
}
 
void Solve() 
{
    cin >> n;
    
    for (int i = 1; i <= 4; i++){
        for (int j = 1; j <= 4; j++){
            for (int k = 1; k <= 4; k++){
                dp[i][j][k] = area(i, j, k);
            }
        }
    }
    
    if (n < 9){
        brutesmall();
    }
    
    vector <int> tuple(4, -1);
    while (true){
        if (tuple[0] != -1) break;
        int p1 = 1 + RNG() % n;
        int p2 = 1 + RNG() % n;
        int p3 = 1 + RNG() % n;
        
        if (p1 == p2 || p2 == p3 || p3 == p1) continue;
        int ar = query(p1, p2, p3);
        for (int j = 1; j <= 4; j++){
            if (ar == dp[j][j][j]){
                tuple[0] = p1;
                tuple[1] = p2;
                tuple[2] = p3;
                tuple[3] = j;
            }
        }
    }
    
    for (int i = 0; i < 3; i++) ans[tuple[i]] = tuple[3];
    
    if (tuple[3] == 1){
        vector <int> nv;
        for (int i = 1; i <= n; i++){
            if (ans[i] > 0) continue;
            
            int fetch = query(tuple[0], tuple[1], i);
            if (fetch == 0) {
                nv.push_back(i);
                if (nv.size() > 3) break;
            } else {
                ans[i] = 1;
            }
        }
        
        if (nv.size() == 0) print();
        
        vector <int> ntuple(3, -1);
        for (int i1 = 0; i1 < nv.size(); i1++){
            for (int i2 = i1 + 1; i2 < nv.size(); i2++){
                int ok = query(tuple[0], nv[i1], nv[i2]);
                
                for (int j = 2; j <= 4; j++){
                    if (ok == dp[1][j][j]){
                        ntuple[0] = nv[i1];
                        ntuple[1] = nv[i2];
                        ntuple[2] = j;
                    }
                }
            }
        }
        
        if (ntuple[0] == -1) print(false);
        ans[ntuple[0]] = ntuple[2];
        ans[ntuple[1]] = ntuple[2];
        
        tuple[0] = ntuple[0];
        tuple[1] = ntuple[1];
        tuple[2] = -1;
        tuple[3] = ntuple[2];
    }
    
    for (int i = 1; i <= n; i++){
        if (ans[i] > 0) continue;
        
        int fetch = query(tuple[0], tuple[1], i);
        for (int j = 1; j <= 4; j++){
            if (dp[tuple[3]][tuple[3]][j] == fetch)
                ans[i] = j;
        }
    }
    
    print();
}
 
int32_t main() 
{
    auto begin = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
 //   cin >> t;
    for(int i = 1; i <= t; i++) 
    {
        Solve();
    }
    return 0;
}

```
[1847:F The Boss's Identity](../problems/F._The_Boss's_Identity.md)

 * Idea — [astoria](https://codeforces.com/profile/astoria "Candidate Master astoria")
* Prepared by — [PoPularPlusPlus](https://codeforces.com/profile/PoPularPlusPlus "Master PoPularPlusPlus")

 **tutorial**
### [1847F - The Boss's Identity](../problems/F._The_Boss's_Identity.md "Codeforces Round 882 (Div. 2)")

Lets start with an example of $n=5$. Let $a = [a,b,c,d,e]$ where $a$,$b$,$c$,$d$ and $e$ are variables. First $20$ elements of $a$ will be [$a$,$b$,$c$,$d$,$e$,$ab$,$bc$,$cd$,$de$,$abe$,$abc$,$bcd$,$cde$,$abde$,$abce$,$abcd$,$bcde$,$abcde$,$abcde$,$abcde$]. By removing and rearranging some elements we can get 

 

| $b$ | $c$ | $d$ | $e$ |
| --- | --- | --- | --- |
| $\bf{ab}$ | $bc$ | $cd$ | $de$ |
| $\bf{eab}$ | $\bf{abc}$ | $bcd$ | $cde$ |
| $\bf{deab}$ | $\bf{eabc}$ | $\bf{abcd}$ | $bcde$ |

 Here you can observe that each group will have a size of $n−1$. The next group will be the previous group, _or_ed with the element immediately before the first element (circularly).

So we have the rule. Now let's solve the problem in binary (that is, every element is $0/1$). Let's take a look at the element $a$ in the rearranged version (the highlighted ones). If $a$ is $0$, it won't contribute anything to the subsequent groups, so we can ignore it. Otherwise, it will contribute by keeping moving to the right. This will end when it meets a cell in the group that is already $1$. And after that, we can drop the act of moving $a$.

This algorithm can actually help us construct the whole array sparsely and incrementally. We can maintain the list of $1$ in the initial array, and then update the array by moving all of them to the right. That is, if we have one group, we can obtain the next group by moving the $1$. After that, we can drop moving some $1$ if it meets another $1$.

The whole action is $O(n)$, as there are at most $n$ zeros to be updated.

So for the original problem, first of all, we can repeat the above algorithm $bitlength=31$ times, that is, repeat the algorithm for each bit. Secondly, there are at most $O(\log n)$ unique numbers for each position, so we can just find all $O(n \log n)$ last positions of all numbers, and put them in a array.

You can either find all $n \log n$ unique positions in ascending order and or in random order and sort the array. Then using binary search we can answer each query. 

Time complexity of the former version is $O(n \log n + q \log(n \log n))$ and the latter version is $O(n \log n \log(n \log n) + q \log(n \log n))$.

 **solution**
```cpp
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long 
#define pb(e) push_back(e)
#define sv(a) sort(a.begin(),a.end())
#define sa(a,n) sort(a,a+n)
#define mp(a,b) make_pair(a,b)
#define vf first
#define vs second
#define all(x) x.begin(),x.end()

const int B = 31;

struct item {
	ll pos , bit, idx;
};

item make(ll pos , ll bit , ll idx){
	item res;
	res.pos = pos;
	res.bit = bit;
	res.idx = idx;
	return res;
}

void solve(){
    int n;
	cin >> n;
	int qu;
	cin >> qu;
	int arr[n];
	for(int i = 0; i < n; i++)cin >> arr[i];
	if(n == 1){
		while(qu--){
			int x;
			cin >> x;
			if(x < arr[0])cout << 1 << 'n';
			else cout << -1 << 'n';
		}
		return;
	}
	vector<pair<ll,ll>> v;
	queue<item> q;
	bool vis[n][B];
	memset(vis,0,sizeof vis);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < B; j++){
			if((arr[i] & (1 << j)) > 0){
				vis[i][j] = 1;
			}
		}
		v.pb(mp(i , arr[i]));
	}
	for(int i = 0; i < n - 1; i++){
		v.pb(mp(n+i,arr[i]|arr[i+1]));
	}
	for(int j = 0; j < B; j++){
		if(vis[n-1][j])q.push(make(n+n-1,j,0));
	}
	for(int i = 0; i < n - 1; i++){
		for(int j = 0; j < B; j++){
			if(vis[i][j])q.push(make(n+n+i,j,(i+1)%(n-1)));
		}
	}
	int val[n-1];
	for(int i = 0; i < n-1; i++)val[i] = arr[i]|arr[i+1];
	while(q.size()){
		item it = q.front();
		q.pop();
		if((val[it.idx] & (1 << it.bit)) > 0){
			continue;
		}
		val[it.idx] += (1 << it.bit);
		if(v.back().vf == it.pos){
			v.pop_back();
		}
		v.pb(mp(it.pos , val[it.idx]));
		q.push(make(it.pos + n , it.bit , (it.idx + 1)%(n-1)));
	}
	
	// first part gets over where v[i].first contains position in ascending order and v[i].second contains the value to what has become on that position.
	
	
	for(int i = 1; i < v.size(); i++){
		v[i].vs = max(v[i].vs , v[i-1].vs);
	}

	while(qu--){
		int x;
		cin >> x;
		ll l = 0 , r = v.size()-1;
		ll res = -1;
		while(l <= r){
			int mid = (l + r)/2;
			if(v[mid].vs <= x){
				l = mid + 1;
			}
			else {
				r = mid - 1;
				res = v[mid].vf+1;
			}
		}
		cout << res << 'n';
	}
}

int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
	int t;cin >> t;while(t--)
	solve();
	return 0;
}
```
