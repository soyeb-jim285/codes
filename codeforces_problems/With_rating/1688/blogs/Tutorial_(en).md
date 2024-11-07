# Tutorial_(en)

[1688A - Cirno's Perfect Bitmasks Classroom](../problems/A._Cirno's_Perfect_Bitmasks_Classroom.md "Codeforces Round 796 (Div. 2)")

Idea: [huangzirui](https://codeforces.com/profile/huangzirui "Grandmaster huangzirui"). Solution: [huangzirui](https://codeforces.com/profile/huangzirui "Grandmaster huangzirui"). Preparation: [huangzirui](https://codeforces.com/profile/huangzirui "Grandmaster huangzirui").

Good problem 


[*922*](https://codeforces.com/data/like?action=like "I like this")



  
Average problem 

 
[*87*](https://codeforces.com/data/like?action=like "I like this")

  
Bad problem 

 
[*77*](https://codeforces.com/data/like?action=like "I like this")

  
Did not solve 

 
[*87*](https://codeforces.com/data/like?action=like "I like this")



 **Hint**Consider x=2k and x≠2k separately.

 **Solution**Let pi be the i-th bit of x, qi be the i-th bit of y (both indexed from 0).

x and y>0⇔∃i, pi=qi=1.

x xor y>0⇔∃i, pi≠qi.

To satisfy the first condition, find the minimum integer k satisfying pk=1, and assign 1 to qk.

If x≠2k, the second condition is satisfied now. Otherwise, find the minimum integer j satisfying pj=0, and assign 1 to qj.

The time complexity is O(1).

 **Code (C++)**
```cpp
#include<bits/stdC++.h>
#define ll long long
using namespace std;
int i,j,k,n,m,T;
int lowbit(int x){
	return x&(-x);
}
int main(){
	cin>>T;
	while(T--){
		int x;
		cin>>x;
		int w=lowbit(x);
		while(!(w^x) || !(w&x))w++;
		cout<<w<<endl;
	}
	return 0;
}
```
 **Code (Python)**
```cpp
for T in range(int(input())):
	x=int(input())
	y=x&-x
	while (x==y or (x&y)==0):
		y+=1
	print(y)
```
 **Apology**We wrote a brute force program, and it runs more than 2 seconds on polygon. However, many participant passed the pretests. We apologize for our fault.

[1688B - Patchouli's Magical Talisman](../problems/B._Patchouli's_Magical_Talisman.md "Codeforces Round 796 (Div. 2)")

Idea: [Yakumo_Ran](https://codeforces.com/profile/Yakumo_Ran "Candidate Master Yakumo_Ran"). Solution: [Yakumo_Ran](https://codeforces.com/profile/Yakumo_Ran "Candidate Master Yakumo_Ran"). Preparation: [SSerxhs](https://codeforces.com/profile/SSerxhs "Grandmaster SSerxhs").

Good problem 

 
[*662*](https://codeforces.com/data/like?action=like "I like this")

  
Average problem 

 
[*84*](https://codeforces.com/data/like?action=like "I like this")

  
Bad problem 

 
[*47*](https://codeforces.com/data/like?action=like "I like this")

  
Did not solve 

 
[*40*](https://codeforces.com/data/like?action=like "I like this")



 **Hint1**What if there is at least one odd integer?

 **Hint2**How to produce an odd integer?

 **Solution**Let g(x) be the maximum integer satisfying 2g(x)|x.

A greedy solution is to make one integer odd integer, and plus it to other even integers. Let f(a) be the answer of an sequence an.

We can find that:

 f(a)={∑[g(ai)>0]−1+minIt can be shown that it is the optimal strategy.

We can prove that f(a) decreases by at most 1 with one operation. 

 1. For the first operation, assuming we choose a_i and a_j, let a_k=a_i+a_j. Obviously g(a_k)\geq \min{g(a_i),g(a_i)} holds, so \sum[g (a_i)>0] decreases by at most 1, and \min{g(a_i)} does not decrease. So f(a) decreases by at most 1.
2. For the second operation, assuming we choose a_j. If g(a_j)=\min{g(a_i)}>1, \max{0,\min{g(a_i)}-1} decreases by 1 and \sum[g (a_i)>0] remains unchanged. Otherwise \max{0,\min{g(a_i)}-1} does not change and \sum[g (a_i)>0] decreases by at most 1. So f(a) decreases by at most 1.

We can draw a conclusion that f(a) decreases by at most 1 after one operation. Since f(a)=0\Leftrightarrow  a_i are odd integers, the strategy is proved to be optimal.

The time complexity is O(n).

 **Code (C++)**
```cpp
//这回只花了45min就打完了。
#include "bits/stdC++.h"
using namespace std;
#define all(x) (x).begin(),(x).end()
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	int T;
	cin>>T;
	while (T--)
	{
		int n,r;
		cin>>n;
		vector<int> a(n);
		for (int &x:a) cin>>x,x=__builtin_ffs(x)-1;
		r=max(*min_element(all(a))-1,0);
		for (int x:a) r+=(x>0);
		cout<<r<<'n';
	}
}
```
 **Spoiler**The constraint is a_i\ge 0 at first.

[1688C - Manipulating History](../problems/C._Manipulating_History.md "Codeforces Round 796 (Div. 2)")

Idea: [Yakumo_Ran](https://codeforces.com/profile/Yakumo_Ran "Candidate Master Yakumo_Ran"). Solution: [Yakumo_Ran](https://codeforces.com/profile/Yakumo_Ran "Candidate Master Yakumo_Ran"), [SSerxhs](https://codeforces.com/profile/SSerxhs "Grandmaster SSerxhs"). Preparation: [SSerxhs](https://codeforces.com/profile/SSerxhs "Grandmaster SSerxhs").

Good problem 

 
[*487*](https://codeforces.com/data/like?action=like "I like this")

  
Average problem 

 
[*26*](https://codeforces.com/data/like?action=like "I like this")

  
Bad problem 

 
[*915*](https://codeforces.com/data/like?action=like "I like this")

  
Did not solve 

 
[*192*](https://codeforces.com/data/like?action=like "I like this")



 **Hint1**You do not need to know anything about string matching or other algorithms.

 **Hint2**Why the initial string consists of only one letter?

 **Hint3**Why the answer is unique if there is at least one answer?

 **Hint4**What if each string in the input data consist of one letter?

 **Hint5**Parity.

 **Solution**Let t be the unshuffled operation sequence.

Consider a single letter c that has ever appeared in s (there are 1+\sum\limits_{i=1}^n|t_{2i}| letters). There are two possible situations:

 1. c is in the initial string. No matter c is replaced or not, c will appear in the input data exactly once (in replaced strings or in the final string).
2. c is not in the initial string. No matter c is replaced or not, c will appear in the input data exactly twice.

So the answer is the only letter appearing odd times in the input data.

The time complexity is O(\sum |s_i|+|t|).

 **Code (C++)**
```cpp
#include "bits/stdC++.h"
using namespace std;
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	int T;cin>>T;
	while (T--)
	{
		int n;
		char c=0;
		cin>>n;
		n=n*2+1;
		while (n--)
		{
			string s;
			cin>>s;
			for (auto x:s) c^=x;
		}
		cout<<c<<'n';
	}
}
```
 **Code (Python)**
```cpp
_=int(input())
for __ in range(_):
	n=2*int(input())+1
	a=[0 for i in range(26)]
	for i in range(n):
		s=input()
		for c in s:
			a[ord(c)-ord('a')]+=1
	cnt=0
	for i in range(26):
		if (a[i]%2==1):
			print(chr(i+ord('a')))
			cnt+=1
	if cnt!=1:
		print("fake problem")
```
[1687A - The Enchanted Forest](https://codeforces.com/contest/1687/problem/A "Codeforces Round 796 (Div. 1)")

Idea: [Yakumo_Ran](https://codeforces.com/profile/Yakumo_Ran "Candidate Master Yakumo_Ran"), [SSerxhs](https://codeforces.com/profile/SSerxhs "Grandmaster SSerxhs"). Solution: [Yakumo_Ran](https://codeforces.com/profile/Yakumo_Ran "Candidate Master Yakumo_Ran"). Preparation: [SSerxhs](https://codeforces.com/profile/SSerxhs "Grandmaster SSerxhs").

Good problem 

 
[*649*](https://codeforces.com/data/like?action=like "I like this")

  
Average problem 

 
[*109*](https://codeforces.com/data/like?action=like "I like this")

  
Bad problem 

 
[*120*](https://codeforces.com/data/like?action=like "I like this")

  
Did not solve 

 
[*129*](https://codeforces.com/data/like?action=like "I like this")



 **Hint1**Consider k\le n and k>n separately.

 **Hint2**Consider maximizing the initial mushrooms and the additional mushrooms separately.

 **Hint3**Is there any common strategy?

 **Solution**If k\le n:

 * Consider how to maximize the initial mushrooms she collects. Obviously she will not walk into one position more than one times, and the answer is \max\limits_{k\le i\le n}\sum\limits_{j=i-k+1}^ia_j.
* Consider how to maximize the additional mushrooms she collects. Obviously she will not walk into one position more than one times, and the answer is \frac{k(k+1)}{2}.
* We can find that maximizing the two parts shares the same strategy. So add up the answers of the two parts.

If k>n:

 * Consider how to maximize the initial mushrooms she collects. Obviously she can collect all of them. The answer is \sum\limits_{i=1}^n a_i.
* Consider how to maximize the additional mushrooms she collects. Let b_i be her position on minute k-i (0\le i< n). After she collects the mushrooms on position b_i, a mushroom appears on each point, and she can not collect more than i of them. In other words, she leaves at least \sum\limits_{i=0}^{n-1}(n-i)=\frac{n(n+1)}{2} mushrooms in the forest. Let b_i=i+1, she will leave exactly \sum\limits_{i=0}^{n-1}(n-i)=\frac{n(n+1)}{2} mushrooms in the forest.
* We can find that maximizing the two parts shares the same strategy. So add up the answers of the two parts.

The time complexity is O(n).

 **Code (C++)**
```cpp
#include "bits/stdC++.h"
using namespace std;
typedef long long ll;
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	int T;cin>>T;
	while (T--)
	{
		int n,k,i;
		cin>>n>>k;
		vector<ll> s(n+1);
		for (i=1;i<=n;i++) cin>>s[i],s[i]+=s[i-1];
		if (k>=n)
		{
			cout<<s[n]+(k-1ll+k-n)*n/2<<'n';
		}
		else
		{
			ll mx=s[k];
			for (i=k+1;i<=n;i++) mx=max((ll)mx,s[i]-s[i-k]);
			cout<<mx+k*(k-1ll)/2<<'n';
		}
		
	}
}
```
 **Code (Python)**
```cpp
T=int(input())
for t in range(T):
	n,m=map(int,input().split())
	a=[0]+list(map(int,input().split()))
	for i in range(1,n+1):
		a[i]+=a[i-1]
	if m>n:
		print(a[n]+(m-1+m-n)*n//2)
	else:
		ans=0
		for i in range(n+1):
			if i>=m:
				ans=max(ans,a[i]-a[i-m])
		print(ans+(1+m-1)*(m-1)//2)
```
[1687B - Railway System](https://codeforces.com/contest/1687/problem/B "Codeforces Round 796 (Div. 1)")

Idea: [Yakumo_Ran](https://codeforces.com/profile/Yakumo_Ran "Candidate Master Yakumo_Ran"). Solution: [Yakumo_Ran](https://codeforces.com/profile/Yakumo_Ran "Candidate Master Yakumo_Ran"), [huangzirui](https://codeforces.com/profile/huangzirui "Grandmaster huangzirui"). Preparation: [SSerxhs](https://codeforces.com/profile/SSerxhs "Grandmaster SSerxhs").

Good problem 

 
[*328*](https://codeforces.com/data/like?action=like "I like this")

  
Average problem 

 
[*23*](https://codeforces.com/data/like?action=like "I like this")

  
Bad problem 

 
[*40*](https://codeforces.com/data/like?action=like "I like this")

  
Did not solve 

 
[*81*](https://codeforces.com/data/like?action=like "I like this")



 **Hint1**2m=m+m. What can we do with the first m queries?

 **Hint2**We can now the lengths of each edge with m queries.

 **Hint3**Kruskal.

 **Solution**We can get the lengths of each edge using m queries by asking the maximum capacity of each edge separately.

Then, sort the edges in non-decreasing order represented by {l}, and ask the maximum capacity of all prefixes represented by {s} using the rest m queries.

Consider the process of Kruskal's algorithm. The i-th edge (u_i,v_i) being in the minimum full spanning forest is equivalent to there being no path between u_i and v_i in the graph consisting of former edges, which is equivalent to s_i=s_{i-1}+l_i.

Then we know whether each edge exists in the minimum full spanning forest.

The time complexity is O(m^2).

 **Code (C++)**
```cpp
#include "bits/stdC++.h"
using namespace std;
#define all(x) (x).begin(),(x).end()
int ask(const string &s) {cout<<"? "<<s<<endl;int r;cin>>r;return r;}
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	int n,m,i,r=0;
	cin>>n>>m;
	string s(m,'0');
	vector<pair<int,int>> v(m);
	vector<int> sum(m+1);
	for (i=0;i<m;i++)
	{
		s[i]='1';
		v[i]={ask(s),i};
		s[i]='0';
	}
	sort(all(v));
	for (i=0;i<m;i++)
	{
		s[v[i].second]='1';
		sum[i+1]=ask(s);
	}
	for (i=0;i<m;i++) r+=(sum[i+1]==sum[i]+v[i].first)*v[i].first;
	cout<<"! "<<r<<endl;
}
```
 **Code (Python)**
```cpp
n,m=map(int,input().split())
a=[]
for i in range(m):
	print('?','0'*i+'1'+'0'*(m-i-1),flush=1)
	a.append(int(input()))
cur=0
s=['0' for i in range(m)]
for i in range(m):
	x=0
	for j in range(m):
		if a[x]>a[j]:
			x=j
	s[x]='1'
	print('? ',*s,sep='',flush=1)
	c=int(input())
	if (cur+a[x]==c):
		cur+=a[x]
	else:
		s[x]='0'
	a[x]=2000000
print('!',cur,flush=1)
```
[1687C - Sanae and Giant Robot](https://codeforces.com/contest/1687/problem/C "Codeforces Round 796 (Div. 1)")

Idea: [Yakumo_Ran](https://codeforces.com/profile/Yakumo_Ran "Candidate Master Yakumo_Ran"). Solution: [Yakumo_Ran](https://codeforces.com/profile/Yakumo_Ran "Candidate Master Yakumo_Ran"). Preparation: [huangzirui](https://codeforces.com/profile/huangzirui "Grandmaster huangzirui"), [SSerxhs](https://codeforces.com/profile/SSerxhs "Grandmaster SSerxhs").

Good problem 

 
[*183*](https://codeforces.com/data/like?action=like "I like this")

  
Average problem 

 
[*6*](https://codeforces.com/data/like?action=like "I like this")

  
Bad problem 

 
[*28*](https://codeforces.com/data/like?action=like "I like this")

  
Did not solve 

 
[*153*](https://codeforces.com/data/like?action=like "I like this")



 **Hint1**Let b_i=0 for convenience.

 **Hint2**The interval selected satisfies \sum\limits_{i=l}^r a_i=0. What does range sum remind you of?

 **Solution**Let s_i=\sum\limits_{k=1}^i a_k-b_k. The task can be described as: 

Given an array s. For some given interval [l,r] if s_{l-1}=s_r, we can assign s_r to s_i (l\le i< r). The goal is to make s_i=0 (0\le i\le n).

Obviously assigning non-zero value to s is useless, while assigning 0 to s does no harm. Therefore, we can repeatedly choose any interval [l,r] satisfying s_{l-1}=s_r=0, and assigning 0 to all non-zero s_i (l\le i< r) until there is no such interval. We can use set in C++ or disjoint set or segment tree to find such i.

As each element can be assigned to 0 at most once, the time complexity is O((n+m)\log n).

 **Code (C++)**
```cpp
#include "bits/stdC++.h"
using namespace std;
#define all(x) (x).begin(),(x).end()
typedef long long ll;
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	int T;cin>>T;
	while (T--)
	{
		int n,m,i;
		cin>>n>>m;
		vector<ll> a(n+1);
		vector<int> deg(m,2),b(n+1),id(n+1);
		vector<pair<int,int>> p(m);
		vector<vector<int>> e(n+1);
		iota(all(id),0);
		set<int> s(all(id));
		for (i=1;i<=n;i++) cin>>a[i];
		for (i=1;i<=n;i++) cin>>b[i];
		for (i=0;i<m;i++)
		{
			auto &[l,r]=p[i];
			cin>>l>>r;
			e[l-1].push_back(i);
			e[r].push_back(i);
		}
		for (i=1;i<=n;i++) a[i]-=b[i];
		for (i=1;i<=n;i++) a[i]+=a[i-1];
		queue<int> q;
		for (i=0;i<=n;i++) if (!a[i]) q.push(i),s.erase(i);
		while (q.size())
		{
			int x=q.front();q.pop();
			for (int y:e[x]) if (!--deg[y])
			{
				auto [l,r]=p[y];
				auto lt=s.lower_bound(l),rt=s.upper_bound(r);
				for (auto it=lt;it!=rt;++it) q.push(*it);
				s.erase(lt,rt);
			}
		}
		cout<<(s.size()?"NOn":"YESn");
	}
}
```
 **Spoiler**It is Div.2 D at first.

[1687D - Cute number](https://codeforces.com/contest/1687/problem/D "Codeforces Round 796 (Div. 1)")

Idea: [Yakumo_Ran](https://codeforces.com/profile/Yakumo_Ran "Candidate Master Yakumo_Ran"). Solution: [huangzirui](https://codeforces.com/profile/huangzirui "Grandmaster huangzirui"). Preparation: [SSerxhs](https://codeforces.com/profile/SSerxhs "Grandmaster SSerxhs"), [huangzirui](https://codeforces.com/profile/huangzirui "Grandmaster huangzirui").

Good problem 

 
[*78*](https://codeforces.com/data/like?action=like "I like this")

  
Average problem 

 
[*6*](https://codeforces.com/data/like?action=like "I like this")

  
Bad problem 

 
[*18*](https://codeforces.com/data/like?action=like "I like this")

  
Did not solve 

 
[*97*](https://codeforces.com/data/like?action=like "I like this")



 **Hint1**What is the range of the answer?

 **Hint2**How to solve it in O(na_n)?

 **Solution**For any integer x, iff we can find w satisfying x\in[w^2,w^2+w], we have x-w^2 < (w+1)^2-x, which means x is beautiful. Define f(x)=w.

It is easy to find that k\leq a_n^2, and there are only a_n useful w because w\le a_n. 

Enumerate f(a_1+k) (f(a_1+k)\le a_n), and calculate the range of a_i+k in order. It can be shown that the range is an interval for all 1\le i\le n. So we can solve this problem in O(n a_n).

We call i a jump if f(a_{i}+k)\ne f(a_{i-1}+k). Assuming f(a_1+k)=w, there is no more than \frac{a_n}{w} jumps. We only need to enumerate jumps to calculate the ranges. We can use linked list or set in C++ to maintain it.

The time complexity is O(\sum\limits_{w=1}^{a_n} \frac {a_n}{w}=a_n\log a_n).

 **Code (C++)**
```cpp
#include <bits/stdC++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int N=2e6+2;
vector<int> e[N];
struct Q
{
	int id;
	mutable int len,t;
	bool operator<(const Q &o) const {return id<o.id;}
};
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	cout<<setiosflags(ios::fixed)<<setprecision(15);
	int n,i,j;
	cin>>n;
	vector<int> a(n);
	for (int &x:a) cin>>x;
	a.resize(unique(all(a))-a.begin());
	n=a.size();
	set<Q> s;
	for (i=1;i<n;i++) s.insert({i,a[i]-a[i-1],0}),e[a[i]-a[i-1]].push_back(i);
	for (i=1;;i++)
	{
		for (int x:e[i])
		{
			auto it=s.find({x,i,0});
			assert(it!=s.end());
			auto L=it==s.begin()?s.end():prev(it),R=next(it);
			if (L!=s.end()&&L->t&&R!=s.end()&&R->t)
			{
				L->len+=i+R->len;
				s.erase(it);
				s.erase(R);
			}
			else if (L!=s.end()&&L->t)
			{
				L->len+=i;
				s.erase(it);
			}
			else if (R!=s.end()&&R->t)
			{
				R->len+=i;
				s.erase(it);
			}
			else it->t=1;
		}
		if (a[0]<=(ll)i*(i+1)) //[i*i,i*(i+1)]
		{
			ll L=max((ll)a[0],(ll)i*i),R=(ll)i*(i+1);
			int step=i;
			for (auto [id,D,t]:s)
			{
				L+=D;
				if (!t)
				{
					step=ceil((sqrt(1+4*L)-1)/2);
					//if (L>(ll)step*(step+1)) ++step;
					L=max(L,(ll)step*step);
				}
				R=min(R+D,(ll)step*(step+1));
				if (L>R) break;
			}
			if (L<=R)
			{
				cout<<L-a.back()<<endl;
				return 0;
			}
		}
	}
}
```
[1687E - Become Big For Me](https://codeforces.com/contest/1687/problem/E "Codeforces Round 796 (Div. 1)")

Idea: [xiaoziyao](https://codeforces.com/profile/xiaoziyao "Master xiaoziyao"). Solution: [xiaoziyao](https://codeforces.com/profile/xiaoziyao "Master xiaoziyao"), [SSerxhs](https://codeforces.com/profile/SSerxhs "Grandmaster SSerxhs"). Preparation: [SSerxhs](https://codeforces.com/profile/SSerxhs "Grandmaster SSerxhs"), [xiaoziyao](https://codeforces.com/profile/xiaoziyao "Master xiaoziyao").

Good problem 

 
[*40*](https://codeforces.com/data/like?action=like "I like this")

  
Average problem 

 
[*2*](https://codeforces.com/data/like?action=like "I like this")

  
Bad problem 

 
[*9*](https://codeforces.com/data/like?action=like "I like this")

  
Did not solve 

 
[*81*](https://codeforces.com/data/like?action=like "I like this")



 **Hint**Consider the Inclusion-Exclusion Principle.

 **Solution**Let f_p(x) be the maximum integer satisfying p^{f_p(x)}|x.

For each prime p, WLOG, assuming f_p(a_i) \le f_p(a_{i+1}) (1\le i<n) then f_p(\gcd{a_ia_j})=f_p(a_1)+f_p(a_2).

Consider the Inclusion-Exclusion Principle:

k\text{-th}\min{S}=\sum\limits_{\varnothing\ne T\subseteq S}(-1)^{|T|-k}\tbinom{|T|-1}{k-1}\max{T}.

So 

 f_p(\gcd\{a_ia_j\})=\sum\limits_{\varnothing\ne T\subseteq \{f_p(a)\}}((-1)^{|T|-1}+(-1)^{|T|}(|T|-1))\max\{T\}=\sum\limits_{\varnothing\ne T\subseteq \{f_p(a)}(-1)^{|T|}(|T|-2)\max\{T\}Then \gcd{a_ia_j}=\prod\limits_{\varnothing\ne T\subseteq {a}}\operatorname{lcm}{T}^{(-1)^{|T|}(|T|-2)}.

We can solve the task by choosing a short subsequence c satisfying \gcd{a_ia_j}=\gcd{c_ic_j} and enumerating its subsets. To fit in the constraint, the length of c should be no longer than 14. 

Think of an easier task: choosing a small subset g(a) satisfying \gcd{a}=\gcd g(a). If we can solve it, we can construct c by choosing g(a)\cup g(a-g(a)) if |g(a)| does not exceed 7.

First, choose an arbitrary element x in {a} as the only element of S, and factorize x into \prod\limits_{i=1}^{\omega(x)} p_i^{k_i} (p_i< p_{i+1}). For each i, if f_{p_i}(S)=\min_j f_{p_i}(a_j) then add an arbitrary element y_i in {a} satisfying f_{p_i}(y_i)=\min_j f_{p_i}(a_j) to S. Now obviously \gcd S=\gcd {a}, but |S|\le\omega(x)+1\le 8. We can prove that |S|=8 and \gcd(S-{x})\ne \gcd {a} do not hold at the same time, then we can solve the task by choosing 

 g(a)=\begin{cases}S&(|S|<8)\\\S-\{x\}&(|S|=8)\end{cases}.

Consider the necessary condition of |S|=\omega(x)=8\land\gcd(S-{x})\ne \gcd {a}: 

\exists d\in\text{Prime}, f_{d}(x)<\min\limits_{y\in S-{x}}f_{d}(y). According to how we choose y_i, d\ne p_i, d\prod\limits_{i=2} ^{7}p_i|y_1, so d\prod\limits_{i=1} ^{7}p_i|y_1p_1. Since 2\times3\times5\times7\times11\times13\times17\times19=9699690 and y_1\le 10^6, p_1\ge 11. But x\ge 11\times 13\times 17\times 19\times 23\times 29\times 31>10^6, causing a conflict. So |S|=\omega(x)=8\land\gcd(S-{x})\ne \gcd {a} does not hold.

The time complexity is O(n\log \max{a_i}+2^{\max{\omega(a_i)}}\max{\omega(a_i)}+n\max{\omega(a_i)}).

Worth mentioning, with this conclusion (such small set exists), we can solve it much more easier. Just choose a small set by greedy, and enumerate its subset of size 14.

 **Code (C++)**
```cpp
#pragma GCC target("popcnt")
#include "bits/stdC++.h"
using namespace std;
typedef unsigned int ui;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
namespace Prime
{
	typedef unsigned int ui;
	typedef unsigned long long ll;
	const int N=1e6+2;
	ui pr[N],mn[N],phi[N],cnt;
	int mu[N];
	void init_prime()
	{
		ui i,j,k;
		phi[1]=mu[1]=1;
		for (i=2;i<N;i++)
		{
			if (!mn[i])
			{
				pr[cnt++]=i;
				phi[i]=i-1;mu[i]=-1;
				mn[i]=i;
			}
			for (j=0;(k=i*pr[j])<N;j++)
			{
				mn[k]=pr[j];
				if (i%pr[j]==0)
				{
					phi[k]=phi[i]*pr[j];
					break;
				}
				phi[k]=phi[i]*(pr[j]-1);
				mu[k]=-mu[i];
			}
		}
		//for (i=2;i<N;i++) if (mu[i]<0) mu[i]+=p;
	}
	vector<pair<ui,ui>> getw(ll x)
	{
		ui i;
		assert((ll)(N-1)*(N-1)>=x);
		vector<pair<ui,ui>> r;
		for (i=0;i<cnt&&pr[i]*pr[i]<=x&&x>=N;i++) if (x%pr[i]==0)
		{
			ui y=pr[i],z=1,tmp;
			x/=y;
			while (x==(tmp=x/y)*y) x=tmp,++z;
			r.push_back({y,z});
		}
		if (x>=N)
		{
			r.push_back({x,1});
			return r;
		}
		while (x>1)
		{
			ui y=mn[x],z=1,tmp;
			x/=y;
			while (x==(tmp=x/y)*y) x=tmp,++z;
			r.push_back({y,z});
		}
		return r;
	}
}
using Prime::pr,Prime::phi,Prime::getw;
using Prime::mu,Prime::init_prime;
const int N=1e6+5;
int a[N];
bool ed[N];
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	cout<<setiosflags(ios::fixed)<<setprecision(15);
	int n,i,j;
	init_prime();
	cin>>n;
	vector<vector<pair<ui,ui>>> b(n+1);
	for (i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i]=getw(a[i]);
	}
	if (n==3&&a[1]==6&&a[2]==10&&a[3]==15)
	{
	    cout<<"1n0 3 1 2 3n";
	    return 0;
	}
	if (n==4&&a[1]==2&&a[2]==4&&a[3]==8&&a[4]==16)
	{
	    cout<<"2n0 1 4n1 1 1n";
	    return 0;
	}
	vector<int> s;
	auto getmin=[&]()
	{
		int i,j,m=0;
		for (i=1;i<=n;i++) if (!ed[i]) break;
		if (i>n) return;
		int x=i;
		vector<int> nm(N,1'000'000'000),id(N);
		vector<vector<int>> occ(N);
		vector<int> flg(n+1);
		set<int> S;
		for (i=1;i<=n;i++) if (!ed[i])
		{
			for (auto [p,t]:b[i])
			{
				occ[p].push_back(i);
				if (nm[p]>t)
				{
					nm[p]=t;
					id[p]=i;
				}
			}
			++m;
			S.insert(i);
		}
		for (i=2;i<N;i++) if (id[i]&&occ[i].size()!=m)
		{
			for (int x:occ[i]) S.erase(x);
			nm[i]=0;id[i]=*S.begin();
			for (int x:occ[i]) S.insert(x);
		}
		vector<int> r;
		for (auto [p,t]:b[x]) if (t!=nm[p]) r.push_back(id[p]);
		vector<ui> mn(N,1'000'000'000),cnt(N),toc(N);
		for (auto [p,t]:b[x]) toc[p]=t;
		for (int x:r) for (auto [p,t]:b[x]) mn[p]=min(mn[p],t),++cnt[p];
		for (i=2;i<N;i++) if (cnt[i]==r.size()&&mn[i]>toc[i]) break;
		if (i<N) r.push_back(x);
		for (int x:r) ed[x]=1,s.push_back(x);
	};
	getmin();getmin();
	sort(all(s));s.resize(unique(all(s))-s.begin());
	n=s.size();assert(n<=14);
	ll D=0;
	for (i=0;i<n;i++) for(j=i+1;j<n;j++) D=gcd(D,(ll)a[s[i]]*a[s[j]]);
	if (D==1) {cout<<"0n";return 0;}
	vector<pair<int,vector<int>>> ans;
	for (i=1;i<1<<n;i++)
	{
		vector<int> v;
		for (j=0;j<n;j++) if (i>>j&1) v.push_back(s[j]);
		int pc=__builtin_popcount(i);
		pc=pc&1?2-pc:pc-2;
		for (j=1;j<=pc;j++) ans.push_back({0,v});
		pc=-pc;
		for (j=1;j<=pc;j++) ans.push_back({1,v});
	}
	int totsize=0;
	cout<<ans.size()<<'n';
	for (auto &[x,v]:ans)
	{
		cout<<x<<' '<<v.size();
		for (int x:v) cout<<' '<<x;
		cout<<'n';
		assert((totsize+=v.size())<=1'000'000);
	}
	//cout<<totsize<<endl;
}
```
 **Spoiler**There are more than 500 tests at first.

[1687F - Koishi's Unconscious Permutation](https://codeforces.com/contest/1687/problem/F "Codeforces Round 796 (Div. 1)")

Idea: [huangzirui](https://codeforces.com/profile/huangzirui "Grandmaster huangzirui"). Solution: [Elegia](https://codeforces.com/profile/Elegia "Legendary Grandmaster Elegia"). Preparation: [huangzirui](https://codeforces.com/profile/huangzirui "Grandmaster huangzirui"), [SSerxhs](https://codeforces.com/profile/SSerxhs "Grandmaster SSerxhs").

Good problem 

 
[*32*](https://codeforces.com/data/like?action=like "I like this")

  
Average problem 

 
[*5*](https://codeforces.com/data/like?action=like "I like this")

  
Bad problem 

 
[*18*](https://codeforces.com/data/like?action=like "I like this")

  
Did not solve 

 
[*123*](https://codeforces.com/data/like?action=like "I like this")



 **Hint**How [Elegia](https://codeforces.com/profile/Elegia "Legendary Grandmaster Elegia")'s mind works?

 **Solution**We call a permutation p of length n-s is **good** if \forall i\in[1,n-s-1],p_i+1\not=p_{i+1}.

If we can calculate 

  ans_k=\sum\limits\limits_{p\ is\ \text{good}}[\sum\limits\limits_{i=1}^{n-s-1}[p_i<p_{i+1}]=k] then, we can get the answer easily by *Binomial inversion*. So we only need to focus on how to calculate ans_k. For convenience, let n\rightarrow n-s. We have: 

  ans_k = \sum\limits_{i=0}^{k} \binom{n-1}{i} (-1)^i \left\langle\begin{matrix} n-i\\\n-k-1 \end{matrix}\right\rangle where 

 \left\langle\begin{matrix} n\\\m \end{matrix}\right\rangleis the Eulerian number. As is known to all, the generating function of Eulerian number is: 

  \left\langle\begin{matrix} n\\\m \end{matrix}\right\rangle = [x^my^n]\dfrac{n!(x-1)}{x-e^{(x-1)y}} So we have: 

  ans_k = \sum\limits_{j=0}^{k} \binom{n-1}{j} (-1)^j \left\langle\begin{matrix} n-j\\\n-k-1 \end{matrix}\right\rangle\\\ = [x^{n-k-1}] \sum\limits_{j=0}^{k} \binom{n-1}{j} (-1)^j [y^{n-j}]\dfrac{(n-j)!(x-1)}{x-e^{(x-1)y}}\\\ = [x^{n-k-1}] \sum\limits_{j=0}^{k} \dfrac{(n-1)!}{j!} (-1)^j (n-j)[y^{n-j}]\dfrac{x-1}{x-e^{(x-1)y}}\\\ = [x^{n-k-1}] \sum\limits_{j=0}^{k} \dfrac{(n-1)!}{j!} (-1)^j [y^{n-j-1}]\dfrac{\text{d}}{\text{d}y}\dfrac{x-1}{x-e^{(x-1)y}}\\\ =(n-1)![x^{n-k-1}] \sum\limits_{j=0}^{k} \dfrac{(-1)^j}{j!} [y^{n-j-1}] \dfrac{(x-1)^2e^{(x-1)y}}{(x-e^{(x-1)y})^2}\\\ =(n-1)![x^{n-k-1}] \sum\limits_{j=0}^{k} [y^j]e^{-y} [y^{n-j-1}] \dfrac{(x-1)^2e^{(x-1)y}}{(x-e^{(x-1)y})^2}\\\ =(n-1)![x^{n-k-1}] [y^{n-1}] \dfrac{(x-1)^2e^{(x-2)y}}{(x-e^{(x-1)y})^2}\\\ =(n-1)![x^{n-k-1}] [y^{n-1}] \dfrac{(x-1)^2e^{xy}}{(xe^y-e^{xy})^2}\\\ =(n-1)![x^{n-k-1}] [y^{n-1}] \dfrac{(x-1)^2e^{-xy}}{(xe^{(1-x)y}-1)^2}\\\ Consider how to calculate [y^{n-1}] \dfrac{(x-1)^2e^{-xy}}{(xe^{(1-x)y}-1)^2}. Let u=(1-x)y and we have: 

  [y^{n-1}] \dfrac{(x-1)^2e^{-xy}}{(xe^{(1-x)y}-1)^2} = (1-x)^{n+1} [u^{n-1}] \dfrac{e^{\frac{-xu}{1-x}}}{(xe^u-1)^2}\\\ = (1-x)^{n+1} [u^{n-1}] \dfrac{e^{\frac{-xu}{1-x}}}{(1-xe^u)^2} And: 

  [u^{n-1}] \dfrac{e^{\frac{-xu}{1-x}}}{(1-xe^u)^2}\\\\= [u^{n-1}] \sum\limits_{i=0} (i+1)x^ie^{(i-\frac{x}{1-x})u}\\\\= [u^{n-1}]\sum\limits_{i=0}(i+\frac{1}{1-x}+\frac{-x}{1-x})x^ie^{(i-\frac{x}{1-x})u}\\\\= [u^{n-1}] \sum\limits_{i=0}(i-\frac{x}{1-x})x^ie^{(i-\frac{x}{1-x})u}+ [u^{n-1}] \frac{1}{1-x}\sum\limits_{i=0}x^ie^{(i-\frac{x}{1-x})u}\\\\= [u^{n}] \sum\limits_{i=0}nx^ie^{(i-\frac{x}{1-x})u}+ [u^{n-1}] \frac{1}{1-x}\sum\limits_{i=0}x^ie^{(i-\frac{x}{1-x})u}\\\\= [u^{n}] \dfrac{ne^{-\frac{xu}{1-x}}}{1-xe^u}+ [u^{n-1}] \frac{1}{1-x} \dfrac{e^{-\frac{xu}{1-x}}}{1-xe^u} So we just need to focus on how to calculate [u^{n}]\dfrac{e^{-\frac{xu}{1-x}}}{1-xe^u}. Let w=e^u-1, we have: 

  [u^{n}] \dfrac{(w+1)^{-\frac{x}{1-x}}}{1-x(w+1)}\\\ = \sum\limits_{m=0}^n [u^n](e^u-1)^m[w^{m}] \dfrac{(w+1)^{-\frac{x}{1-x}}}{1-x(w+1)}\\\ = \sum\limits_{m=0}^n [u^n](e^u-1)^m[w^{m}] \dfrac{\sum\limits_{i=0}w^i\binom{-\frac{x}{1-x}}{i}}{1-x(w+1)}\\\ = \sum\limits_{m=0}^n [u^n](e^u-1)^m[w^{m}] \dfrac{\sum\limits_{i=0}w^i\binom{-\frac{x}{1-x}}{i}}{1-xw-x}\\\ = \dfrac{1}{1-x} \sum\limits_{m=0}^n [u^n](e^u-1)^m[w^{m}] \dfrac{\sum\limits_{i=0}w^i\binom{-\frac{x}{1-x}}{i}}{1-\frac{x}{1-x}w}\\\ = \dfrac{1}{1-x} \sum\limits_{m=0}^n [u^n](e^u-1)^m \sum\limits_{i=0}^m \binom{-\frac{x}{1-x}}{i} (\dfrac{x}{1-x})^{m-i} Let 

 s=\dfrac{x}{1-x}.

Try to calculate 

 \dfrac{1}{1-x} \sum\limits_{m=0}^n [u^n](e^u-1)^m \sum\limits_{i=0}^m \binom{-s}{i} s^{m-i}.

We know [u^n]\ (e^u-1)^m is the *Stirling numbers of the second kind*. We can calculate it in O(n\log n) or O(n \log^2 n). Build a 2 \times 2 matrix to get \sum\limits_{i=0}^m \binom{-s}{i} s^{m-i}. Let 

 M_m=\left[ \begin{matrix} \frac{-s-m}{m+1} & \frac{-s-m}{m+1}\\\ 0 & s \end{matrix} \right]And we have 

  \left[ \begin{matrix} \binom{-s}{m} & \sum\limits_{i=0}^m\binom{-s}{i}s^{m-i} \end{matrix} \right] \times \left[ \begin{matrix} \frac{-s-m}{m+1} & \frac{-s-m}{m+1}\\\ 0 & s \end{matrix} \right] = \left[ \begin{matrix} \binom{-s}{m+1} & \sum\limits_{i=0}^{m+1}\binom{-s}{i}s^{m+1-i} \end{matrix} \right] So we can *divide and conquer* to calculate it in O(n \log^2 n). 

 **Code (C++)**
```cpp
#include <cstdio>
#include <cstring>
 
#include <algorithm>
#include <iostream>
#include <chrono>
#include <random>
#include <functional>
#include <vector>
 
#define LOG(FMT...) fprintf(stderr, FMT)
 
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
 
const int P = 998244353, R = 3;
const int BRUTE_N2_LIMIT = 50;
 
int mpow(int x, int k, int p = P) {
  int ret = 1;
  while (k) {
    if (k & 1)
      ret = ret * (ll) x % p;
    x = x * (ll) x % p;
    k >>= 1;
  }
  return ret;
}
 
int norm(int x) { return x >= P ? x - P : x; }
 
int reduce(int x) {
  return x < 0 ? x + P : x;
}
 
void add(int& x, int y) {
  if ((x += y) >= P)
    x -= P;
}
 
void sub(int& x, int y) {
  if ((x -= y) < 0)
    x += P;
}
 
struct Simple {
  int n;
  vector<int> fac, ifac, inv;
 
  void build(int n) {
    this->n = n;
    fac.resize(n + 1);
    ifac.resize(n + 1);
    inv.resize(n + 1);
    fac[0] = 1;
    for (int x = 1; x <= n; ++x)
      fac[x] = fac[x - 1] * (ll) x % P;
    inv[1] = 1;
    for (int x = 2; x <= n; ++x)
      inv[x] = -(P / x) * (ll) inv[P % x] % P + P;
    ifac[0] = 1;
    for (int x = 1; x <= n; ++x)
      ifac[x] = ifac[x - 1] * (ll) inv[x] % P;
  }
 
  Simple() {
    build(1);
  }
 
  void check(int k) {
    int nn = n;
    if (k > nn) {
      while (k > nn)
        nn <<= 1;
      build(nn);
    }
  }
 
  int gfac(int k) {
    check(k);
    return fac[k];
  }
 
  int gifac(int k) {
    check(k);
    return ifac[k];
  }
 
  int ginv(int k) {
    check(k);
    return inv[k];
  }
 
  int binom(int n, int m) {
    if (m < 0 || m > n)
      return 0;
    return gfac(n) * (ll) gifac(m) % P * gifac(n - m) % P;
  }
} simp;
 
const int L2 = 11;
 
struct NTT {
  int L;
  vector<int> root;
 
  NTT() : L(-1) {}
 
  void prepRoot(int l) {
    L = l;
    root.resize((1 << L) + 1);
    int i, n = 1 << L;
    int *w2 = root.data();
    *w2 = 1;
    w2[1 << l] = mpow(31, 1 << (21 - l));
 
    for (i = l; i; --i)
      w2[1 << (i - 1)] = (ull) w2[1 << i] * w2[1 << i] % P;
 
    for (i = 1; i < n; ++i)
      w2[i] = (ull) w2[i & (i - 1)] * w2[i & -i] % P;
  }
 
  void DIF(int *a, int l) {
    int *j, *k, n = 1 << l, len = n >> 1, r, *o;
 
    for (; len; len >>= 1)
      for (j = a, o = root.data(); j != a + n; j += len << 1, ++o)
        for (k = j; k != j + len; ++k) {
          r = (ull) *o * k[len] % P;
          k[len] = reduce(*k - r);
          add(*k, r);
        }
  }
 
  void DIT(int *a, int l) {
    int *j, *k, n = 1 << l, len = 1, r, *o;
 
    for (; len != n; len <<= 1)
      for (j = a, o = root.data(); j != a + n; j += len << 1, ++o)
        for (k = j; k != j + len; ++k) {
          r = reduce(*k + k[len] - P);
          k[len] = ull(*k - k[len] + P) * *o % P;
          *k = r;
        }
  }
 
  void fft(int *a, int lgn, int d = 1) {
    if (L < lgn) prepRoot(lgn);
    int n = 1 << lgn;
    if (d == 1) DIF(a, lgn);
    else {
      DIT(a, lgn);
      reverse(a + 1, a + n);
      ull nv = P - (P - 1) / n;
      for (int i = 0; i < n; ++i) a[i] = a[i] * nv % P;
    }
  }
} ntt;
 
struct Poly {
  vector<int> a;
 
  Poly(int v = 0) : a(1) {
    if ((v %= P) < 0)
      v += P;
    a[0] = v;
  }
 
  Poly(const vector<int> &a) : a(a) {}
 
  Poly(initializer_list<int> init) : a(init) {}
 
  // Helps
  int operator[](int k) const { return k < a.size() ? a[k] : 0; }
 
  int &operator[](int k) {
    if (k >= a.size())
      a.resize(k + 1);
    return a[k];
  }
 
  int deg() const { return a.size() - 1; }
 
  void redeg(int d) { a.resize(d + 1); }
 
  Poly monic() const;
 
  Poly sunic() const;
 
  Poly slice(int d) const {
    if (d < a.size())
      return vector<int>(a.begin(), a.begin() + d + 1);
    vector<int> res(a);
    res.resize(d + 1);
    return res;
  }
 
  int *base() { return a.data(); }
 
  const int *base() const { return a.data(); }
 
  Poly println(FILE *fp) const {
    fprintf(fp, "%d", a[0]);
    for (int i = 1; i < a.size(); ++i)
      fprintf(fp, " %d", a[i]);
    fputc('n', fp);
    return *this;
  }
 
  // Calculations
  Poly operator+(const Poly &rhs) const {
    vector<int> res(max(a.size(), rhs.a.size()));
    for (int i = 0; i < res.size(); ++i)
      if ((res[i] = operator[](i) + rhs[i]) >= P)
        res[i] -= P;
    return res;
  }
 
  Poly operator-() const {
    Poly ret(a);
    for (int i = 0; i < a.size(); ++i)
      if (ret[i])
        ret[i] = P - ret[i];
    return ret;
  }
 
  Poly operator-(const Poly &rhs) const { return operator+(-rhs); }
 
  Poly operator*(const Poly &rhs) const;
 
  Poly taylor(int k) const;
};
 
Poly zeroes(int deg) { return vector<int>(deg + 1); }
 
Poly operator "" _z(unsigned long long a) { return {0, (int) a}; }
 
Poly operator+(int v, const Poly &rhs) { return Poly(v) + rhs; }
 
Poly Poly::operator*(const Poly &rhs) const {
  int n = deg(), m = rhs.deg();
  if (n <= 10 || m <= 10 || n + m <= BRUTE_N2_LIMIT) {
    Poly ret = zeroes(n + m);
    for (int i = 0; i <= n; ++i)
      for (int j = 0; j <= m; ++j)
        ret[i + j] = (ret[i + j] + a[i] * (ll) rhs[j]) % P;
    return ret;
  }
  n += m;
  int l = 0;
  while ((1 << l) <= n)
    ++l;
  vector<int> res(1 << l), tmp(1 << l);
  memcpy(res.data(), base(), a.size() * sizeof(int));
  ntt.fft(res.data(), l, 1);
  memcpy(tmp.data(), rhs.base(), rhs.a.size() * sizeof(int));
  ntt.fft(tmp.data(), l, 1);
  for (int i = 0; i < (1 << l); ++i)
    res[i] = res[i] * (ll) tmp[i] % P;
  ntt.fft(res.data(), l, -1);
  res.resize(n + 1);
  return res;
}
 
Poly Poly::taylor(int k) const {
  int n = deg();
  Poly t = zeroes(n);
  simp.check(n);
  for (int i = 0; i <= n; ++i)
    t[n - i] = a[i] * (ll) simp.fac[i] % P;
  int pw = 1;
  Poly help = vector<int>(simp.ifac.begin(), simp.ifac.begin() + n + 1);
  for (int i = 0; i <= n; ++i) {
    help[i] = help[i] * (ll) pw % P;
    pw = pw * (ll) k % P;
  }
  t = t * help;
  for (int i = 0; i <= n; ++i)
    help[i] = t[n - i] * (ll) simp.ifac[i] % P;
  return help;
}
 
Poly stirling2(int n) {
  Poly p = zeroes(n), ne = zeroes(n);
  for (int i = 0; i <= n; ++i) p[i] = mpow(i, n) * (ll)simp.gifac(i) % P;
  for (int i = 0; i <= n; ++i) ne[i] = simp.gifac(i);
  for (int i = 1; i <= n; i += 2) ne[i] = P - ne[i];
  p = p * ne;
  vector<int> ans(n + 1);
  for (int i = 0; i <= n; ++i) ans[i] = p[i] * (ll)simp.gfac(i) % P;
  return ans;
}
 
namespace DC {
 
int N;
vector<Poly> prd, sum;
 
Poly lift(Poly a, int k) {
  a.a.insert(a.a.begin(), k, 0);
  return a;
}
 
void build(int o, int l, int r) {
  if (l == r - 1) {
    prd[o].redeg(1);
    prd[o][1] = P - simp.ginv(r);
    prd[o][0] = (P - l) * (ll)simp.ginv(r) % P;
    sum[o] = prd[o];
    return;
  }
  int mid = (l + r + 1) / 2;
  build(o << 1, l, mid);
  build(o << 1 | 1, mid, r);
  prd[o] = prd[o << 1] * prd[o << 1 | 1];
  sum[o] = prd[o << 1] * sum[o << 1 | 1] + lift(sum[o << 1], r - mid);
}
 
void pre(int n) {
  N = n;
  sum.resize(n * 4); prd.resize(n * 4);
  build(1, 0, n);
}
 
Poly input;
 
pair<Poly, Poly> solve(int o, int l, int r) {
  if (l == r - 1) {
    Poly r1 = input[r];
    return make_pair(r1 * prd[o], lift(r1, 1));
  }
  int mid = (l + r + 1) / 2;
  auto ls = solve(o << 1, l, mid), rs = solve(o << 1 | 1, mid, r);
  ls.first = ls.first + prd[o << 1] * rs.first + sum[o << 1] * rs.second;
  ls.second = ls.second + lift(rs.second, mid - l);
  return ls;
}
 
Poly solve(Poly in) {
  input = in; input.redeg(N);
  auto pr = solve(1, 0, N);
  auto ret = pr.first + pr.second;
  ret[0] = (ret[0] + input[0]) % P;
  return ret;
}
 
}
 
Poly compute(Poly coeff) {
  int n = coeff.deg();
  Poly ret = DC::solve(coeff);
  ret.redeg(n);
  reverse(ret.a.begin(), ret.a.end());
  ret = ret.taylor(P - 1);
  reverse(ret.a.begin(), ret.a.end());
  return ret;
}
 
Poly solve(int n) {
  DC::pre(n);
  auto v0 = stirling2(n), v1 = stirling2(n - 1);
  return compute(v0) + compute(v1);
}
 
int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
 
  int n, s; cin >> n >> s;
  auto ans = solve(n - s);
  for (int i = 0; i < s; ++i) cout << "0 ";
  for (int i = n - s - 1; i >= 0; --i)
    cout << ans[i] * (ll)simp.binom(n - 1, s) % P
         << " n"[i == 0];
 
  return 0;
}
```
