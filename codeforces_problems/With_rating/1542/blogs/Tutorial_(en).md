# Tutorial_(en)

**A Tutorial**The answer is 'yes' if and only if there are exactly n odd numbers.

 **A Code**
```cpp
#include<bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin>>t;
	while(t--){
		int n,cnt[2]={0};
		cin>>n;
		for(int i=1,x;i<=n*2;i++)cin>>x,cnt[x%2]++;
		if(cnt[0]==n)puts("Yes");
		else puts("No");
	}
	return 0;
}
```
 **B Hint 1**What kind of element in the set is important?

 **B Hint 2**If x is in the set, but x−b is not, x is important. Why?

 **B Hint 3**How can we find all important elements?

 **B Tutorial**First check specially if b=1.

Let's consider when n is in S. The answer is when the smallest number m in S that n mod b=m mod b is less than n. It's easy to see that a new case of x mod b can only appear when you use ×a to generate a new element. So the smallest number m in S that m mod b=k must be a power of a.

Find all powers of a that is smaller than n. If there is one m=ak that n mod b=m mod b, the answer is yes. Otherwise it's no. Time complexity is O(logn).

 **B Code (Python)**
```cpp
t=(int)(input())
for i in range(t):
    w=input().split()
    n=(int)(w[0])
    a=(int)(w[1])
    b=(int)(w[2])
    if a==1 :
    	if (n-1)%b==0 :
    		print("Yes")
    	else :
    		print("No")
    	
    else :
    	t=1
    	flag=0
    	while t<=n :
    		if t%b==n%b:
    			flag=1
    			break
    		t=t*a
    	if flag==1:
    		print("Yes")
    	else :
    		print("No")

```
 **C Hint 1**f(n) is small.

 **C Hint 2**For a given x, when is f(n) equal to x? 

 **C Tutorial**Enumerate the value of f(i). Since f(n)=i means lcm(1,2,...,i−1)≤n, f(n) will not be too big (less than 100). The number of ks such that f(k)=i is ⌊n/lcm(1,2,...,i−1)⌋−⌊n/lcm(1,2,...,i)⌋. (k should be divisible by 1∼i−1 but not i) So the answer is ∑i>1i(⌊n/lcm(1,2,...,i−1)⌋−⌊n/lcm(1,2,...,i)⌋).

We can also write the answer in another form, which is equivalent to the previous form:

 ∑i≥1⌊n/lcm(1,2,...,i)⌋+n **C Code**
```cpp
#include<bits/stdc++.h>
#define int long long
#define re register
using namespace std;
int t,n;
const int M=1e9+7;
inline int gcd(re int x,re int y){
	return y?gcd(y,x%y):x;
}
inline int LCM(re int x,re int y){
	return x/gcd(x,y)*y;
}
signed main(){
	scanf("%lld",&t);
	while(t--){
		scanf("%lld",&n);
		re int G=1,ans=0;
		for(re int i=1;G<=n;++i){
			G=LCM(G,i);
			if(G>n)break;
			ans+=n/G;
		}
		printf("%lldn",(ans+n)%M);
	}
}
```
 **D Hint**For each x, count how many Bs make the final set contain x.

 **D Tutorial**For each x, count how many Bs make the final set contain x.

Let's say we have picked the x in the I-th operation, call it X. Then, the subsequence we choose must satisfy the following conditions:

 * It must contain the i-th operation (otherwise X won't be added).
* Let s denote the number of numbers less than X in the current T. Whenever we meet a `-` element in S after the i-th operation, s should be greater than 0.

With those conditions, we can come up with the following dp.

Let f(i,j) denote the number of subsequences of a[1...i], that if we maintain T with the subsequence, s will become j.

Then we have the following transitions:

 * f(i−1,j)→f(i,j) (when we don't include the i-th element is S, here i≠I)
* f(i−1,j)→f(i,max(j−1,0)) (here, i<I, and the i-th element of A is `-`, so the number of numbers in T less than x decreases by one. If there is no such number, s remains 0)
* f(i−1,j)→f(i,j−1) (here, i>I, and and the i-th element of A is `-`, so the number of numbers in T less than x decreases by one.)
* f(i−1,j)→f(i,j) (here, the i-th element of A is `+` and its x is greater than X)
* f(i−1,j)→f(i,j+1) (here, the i-th element of A is `+` and its x is less than x or [equal to x but $i>I$] ) [this is to deal with same elements]

Then we add ans by X×∑i≥0f(n,i).

The time complexity is O(n3).

 **D Code (Python)**
```cpp
mod=998244353
n=(int)(input())
a=[0 for i in range(n+1)]
for i in range(1,n+1):
	m=input().split()
	if m[0]=="+":
		a[i]=(int)(m[1])
	
ans=0
for t in range(1,n+1):
	if a[t]==0:
		continue
	f=[[0 for i in range(n+2)] for j in range(n+2)]
	f[0][0]=1
	for i in range(1,n+1):
		for j in range(0,i+1):
			if a[i]==0:
				if ((i<=t) or (j>0)):
					f[i][max(j-1,0)]=(f[i][max(j-1,0)]+f[i-1][j])%mod
			else :
				if ((a[i]<a[t]) or ((a[i]==a[t]) and (i<t))):
					f[i][j+1]=(f[i][j+1]+f[i-1][j])%mod
				else :
					f[i][j]=(f[i][j]+f[i-1][j])%mod
			
			if (i!=t) :
				f[i][j]=(f[i][j]+f[i-1][j])%mod
				
			
		
	
	for i in range(0,n+1):
		ans=(ans+f[n][i]*a[t])%mod
	
 
print(ans)
```
 **E1 Hint**What does lexicographically mean?

 **E1 Tutorial**Let's first calculate the number of permutation pair (p,q)s (with length i) that p1<q1 but inv(p)>inv(q) (inv(p) is the number of inversions in p). Call it ti.

Let's enumerate p1=j and q1=k, then inv(p[2...i])−inv(q[2...i])>k−j. (inv(p)=inv(p[2...i])+j−1,inv(q)=inv(q[2...i])+k−1, with inv(p)>inv(q) we get the following.)

Precalculate f(i,j): the number of permutation ps of length i such that inv(p)=j. Let s(i,j) be ∑k≤jf(i,k), then:

 ti=∑1≤j≤i∑j<k≤i∑wf(i−1,w)s(i−1,w−(k−j)−1)f and s can be calculated in O(n4) or O(n3) in the following way: if you insert i into a permutation of length i−1 after the i−1−p-th element (0≤p≤i−1), it will bring p inversions into the permutation. So f(i,j)=∑j−i+1≤k≤jf(i−1,k).

After calculating t, calculating the answer it easy. Let ansi be the answer for n=i, then

 ansi=i×ansi−1+tiConsider if p1=q1. If so, there are i choices of p1, and ansi−1 choices of the following n−1 numbers. Otherwise, there are ti choices.

Total complexity is O(n5), but it can be optimized to O(n4) if you consider the difference between j−k only, and can be optimized to O(n3logn) using FFT with arbitary mod (which we hope can't pass E2!).

 **E1 Code**
```cpp
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,mod,f[55][2005]={1},s[55][2005]={1},ans[55];
int main(){
	cin>>n>>mod;
	for(int i=1;i<=n*(n-1)/2;i++)s[0][i]=1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=n*(n-1)/2;j++){
			if(j-i>=0)f[i][j]=(s[i-1][j]-s[i-1][j-i]+mod)%mod;
			else f[i][j]=s[i-1][j];
			s[i][j]=((j?s[i][j-1]:0)+f[i][j])%mod;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			for(int k=j+1;k<=i;k++){
				for(int o=0;o<=(i-1)*(i-2)/2;o++){
					int t=o-(k-j)-1;
					if(t<0)continue;
					ans[i]=(ans[i]+1ll*f[i-1][o]*s[i-1][t]%mod)%mod;
				}
			} 
		}
	}
	for(int i=2;i<=n;i++)ans[i]=(ans[i]+1ll*i*ans[i-1])%mod;
	cout<<ans[n];
}
```
 **E2 Hint**In E1 we calculated the number of permutation pairs from the number of permutations. Can we calculate the number of permutation pairs directly?

 **E2 Tutorial**We recommend you to read E1's editorial first.

Let's directly count the number of permutation pairs (p,q) of length n with inv(p)−inv(q)=k, instead of counting it indirectly from "the number of permutation ps of length i such that inv(p)=j.". Call this number f(n,k).

We have an n4 transition: f(n,k)=∑|i|<nf(n−1,k−i)×(n−|i|) (Consider where to insert n in the first and second permutation. If the two places are indices (I,J), then the delta of inv(p) is n−I, the other is n−J, so the delta of difference is J−I. In [1,n] there are n−|J−I| pairs of integers with difference J−I.)

Let's speed it up. When f(n,k) moves to f(n,k+1), it looks like this: (n=4, as an example)

 * f(n−1,k−3)×1+f(n−1,k−2)×2+f(n−1,k−1)×3+f(n−1,k)×4+f(n−1,k+1)×3+f(n−1,k+2)×2+f(n−1,k+3)×1
* f(n−1,k−2)×1+f(n−1,k−1)×2+f(n−1,k)×3+f(n−1,k+1)×4+f(n−1,k+2)×3+f(n−1,k+3)×2+f(n−1,k+4)×1

So with prefix sums s (s(i,j)=∑k≤jf(i,k)) we can write f(n,k+1)=f(n,k)−(s(n−1,k)−s(n−1,k−n))+(s(n−1,k+n)−s(n−1,k)).

Note that the second indice of the array might be negative, so we should shift it by 130000.

The memory complexity is O(n3), so we should only keep two layers of transition to optimize it to O(n2) (If implemented well, O(n3) memory solutions can also pass.)

 **E2 Code**
```cpp
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int B=130000;
int n,mod,w[2][2*B+5],s[2][2*B+5],ans[505];
int main(){
	cin>>n>>mod;
	w[0][B]=s[0][B]=1;
	for(int i=B;i<=2*B;i++)s[0][i]=1;
	for(int i=1;i<=n;i++){
		int curs=1,I=i&1,J=I^1;
		memset(w[I],0,sizeof(w[I])),memset(s[I],0,sizeof(s[I]));
		for(int u=i*(i-1)/2,j=-u+B;j<=u+B;j++){
			w[I][j]=curs;
			curs=(0ll+curs-s[J][j]+s[J][j-i]+s[J][j+i]-s[J][j]+2ll*mod)%mod;
		}
		for(int j=B-i*(i-1)/2,v=(i+2)*(i+1)/2+B;j<=v;j++)s[I][j]=(s[I][j-1]+w[I][j])%mod;
		for(int j=1;j<i;j++)ans[i]=(ans[i]+1ll*(s[J][(i+1)*i/2+B]-s[J][j+B]+mod)%mod*(i-j))%mod;
	}
	for(int i=2;i<=n;i++)ans[i]=(ans[i]+1ll*i*ans[i-1])%mod;
	cout<<ans[n];
}
```
