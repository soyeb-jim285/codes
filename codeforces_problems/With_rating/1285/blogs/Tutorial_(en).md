# Tutorial_(en)


### [1285A - Mezo Playing Zoma](../problems/A._Mezo_Playing_Zoma.md "Codeforces Round 613 (Div. 2)")

Let cLcL and cRcR be the number of 'L's and 'R's in the string respectively. Note that Zoma may end up at any integer point in the interval [−cL,cR][−cL,cR]. So, the answer equals cR−(−cL)+1=n+1cR−(−cL)+1=n+1.

 **code**
```cpp
#include <bits/stdc++.h>
using namespace std;
#define finish(x) return cout << x << endl, 0
#define ll long long

int n;
string s;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> s;
    cout << n + 1 << endl;
}
```
 
### [1285B - Just Eat It!](../problems/B._Just_Eat_It!.md "Codeforces Round 613 (Div. 2)")

If there is at least a prefix or a suffix with non-positive sum, we can delete that prefix/suffix and end up with an array with sum ≥≥ the sum of the whole array. So, if that's the case, the answer is "NO".

Otherwise, all the segments that Adel can choose will have sum << than the sum of the whole array because the elements that are not in the segment will always have a strictly positive sum. So, in that case, the answer is "YES".

Time complexity: O(n)O(n)

 **code**
```cpp
#include <bits/stdc++.h>
using namespace std;
#define finish(x) return cout << x << endl, 0
#define ll long long

int n;
vector <int> a;

bool solve(){
    cin >> n;
    a.resize(n);
    for(auto &i : a) cin >> i;
    ll sum = 0;
    for(int i = 0 ; i < n ; i++){
        sum += a[i];
        if(sum <= 0) return 0;
    }
    sum = 0;
    for(int i = n - 1 ; i >= 0 ; i--){
        sum += a[i];
        if(sum <= 0) return 0;
    }
    return 1;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--){
        if(solve()) cout << "YESn";
        else cout << "NOn";
    }
}
```
 
### [1285C - Fadi and LCM](../problems/C._Fadi_and_LCM.md "Codeforces Round 613 (Div. 2)")

There will always be a solution where aa and bb are coprime. To see why, let's prime factorize aa and bb. If they share a prime factor we can omit all its occurrences from one of them, precisely from the one that has fewer occurrences of that prime, without affecting their LCMLCM. Now, let's prime factorize XX. Since there will be at most 1111 distinct primes, we can distribute them between aa and bb with a bruteforce.

For an easier implementation, you can loop over all divisors dd of XX, check if LCM(d,Xd)LCM(d,Xd) equals XX, and minimize the answer with the pair (d,Xd)(d,Xd).

Time complexity: O(n−−√)O(n)

 **code**
```cpp
#include <bits/stdc++.h>
using namespace std;
#define finish(x) return cout << x << endl, 0
#define ll long long

ll x;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> x;
    vector <ll> f;
    for(ll i = 2 ; i * i <= x ; i++){
        if(x % i == 0){
            ll cur = 1;
            while(x % i == 0){
                x /= i;
                cur *= i;
            }
            f.push_back(cur);
        }
    }
    if(x > 1) f.push_back(x);
    int n = f.size();
    ll ansa = 1e18, ansb = 1e18;
    for(int i = 0 ; i < (1 << n) ; i++){
        ll a = 1, b = 1;
        for(int j = 0 ; j < n ; j++){
            if((i >> j) & 1) a *= f[j];
            else b *= f[j];
        }
        if(max(a, b) < max(ansa, ansb)){
            ansa = a;
            ansb = b;
        }
    }
    cout << ansa << " " << ansb << endl;
}
```
 **easier implementation**
```cpp
#include <bits/stdc++.h>
using namespace std;
#define finish(x) return cout << x << endl, 0
#define ll long long

ll x;

ll lcm(ll a, ll b){
    return a / __gcd(a, b) * b;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> x;
    ll ans;
    for(ll i = 1 ; i * i <= x ; i++){
        if(x % i == 0 && lcm(i, x / i) == x){
            ans = i;
        }
    }
    cout << ans << " " << x / ans << endl;
}
```
 
### [1285D - Dr. Evil Underscores](../problems/D._Dr._Evil_Underscores.md "Codeforces Round 613 (Div. 2)")

We will solve this problem recursively starting from the most significant bit. Let's split the elements into two groups, one with the elements which have the current bit on and one with the elements which have the current bit off. If either group is empty, we can assign the current bit of XX accordingly so that we have the current bit off in our answer, so we will just proceed to the next bit. Otherwise, both groups aren't empty, so whatever value we assign to the current bit of XX, we will have this bit on in our answer. Now, to decide which value to assign to the current bit of XX, we will solve the same problem recursively for each of the groups for the next bit; let ansonanson and ansoffansoff be the answers of the recursive calls for the on and the off groups respectively. Note that if we assign 11 to the current bit of XX, the answer will be 2i+ansoff2i+ansoff, and if we assign 00 to the current bit of XX, the answer will be 2i+anson2i+anson, where ii is the current bit. So, simply we will choose the minimum of these two cases for our answer to be 2i+min(anson,ansoff)2i+min(anson,ansoff).

Time complexity: O(nlog(maxai))O(nlog(maxai))

 **code**
```cpp
#include <bits/stdc++.h>
using namespace std;
#define finish(x) return cout << x << endl, 0
#define ll long long

int n;
vector <int> a;

int solve(vector <int> &c, int bit){
    if(bit < 0) return 0;
    vector <int> l, r;
    for(auto &i : c){
        if(((i >> bit) & 1) == 0) l.push_back(i);
        else r.push_back(i);
    }
    if(l.size() == 0) return solve(r, bit - 1);
    if(r.size() == 0) return solve(l, bit - 1);
    return min(solve(l, bit - 1), solve(r, bit - 1)) + (1 << bit);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    a.resize(n);
    for(auto &i : a) cin >> i;
    cout << solve(a, 30) << endl;
}
```
 
### [1285E - Delete a Segment](../problems/E._Delete_a_Segment.md "Codeforces Round 613 (Div. 2)")

Ok, looking for a new number of segments in a union is actually hard. Let nwinwi be the union of segments after erasing the ii-th one. Obviously, each of the segments in nw[i]nw[i] has its left and right borders. Let me show you how to calculate the number of any of these two kinds. Let's choose left borders. I will call the set of left borders of the set ss of segments lfslfs.

Build the initial union of all segments (that is a standart algorithm, google it if you want). Call it initinit. We are asked to find maxi|nw[i]|maxi|nw[i]|, but let's instead find maxi|nw[i]|−|init|maxi|nw[i]|−|init| (that is the difference of sizes of the initial union and the new one for ii). Surely, adding |init||init| to this value will be the answer. Moreover, maxi|nw[i]|−|init|=maxi|lfnw[i]|−|lfinit|maxi|nw[i]|−|init|=maxi|lfnw[i]|−|lfinit| and that's what we are going to calculate. Call that difference diffidiffi.

Let's do the following sweep line. Add queries of form (li,i,1)(li,i,1) and (ri,i,−1)(ri,i,−1). Process them in sorted order. Maintain the set of the open segments. This sweepline will add segment ii on a query of the first type and remove segment ii on a query of the second type. Initialize all the diffidiffi with zeroes, this sweepline will help us to calculate all the values altogether.

Look at the all updates on the same coordinate xx. The only case we care about is: the current set of open segments contain exactly one segment and there is at least one adding update. Let this currently open segment be jj. Consider what happens with nw[j]nw[j]. xx is not in the lfinitlfinit because at least that segment jj covers it. xx is also in lfnf[j]lfnf[j] because after erasing segment jj xx becomes a left border of some segment of the union (you are adding a segment with the left border xx and points slightly to the left of xx are no longer covered by segment jj). Thus, diffjdiffj increases by 11.

The other possible cases are: 

* there are no open segments currently — this is not important because xx was a left border and stays as a left border;
* there are more than two open segments — not important because xx will still be covered by at least one of them after erasing some other;
* there are no adding updates — xx was a left border but doesn't become a new one.

Thus, we handled all the left border count increasing cases. But there are also a decreasing case. Left border can get removed if the segment you are erasing had its left border in the initial union and was the only segment with such left border. You can get lfinitlfinit while getting initinit. Then for each of lfinitlfinit you can count how many segments start in it. Finally, iterate over ii and decrease diffidiffi by one if the value for the left border of the segment ii is exactly 11.

Finally, diffidiffi is obtained, (maxidiffi)+|init|(maxidiffi)+|init| is the answer.

Overall complexity: O(nlogn)O(nlog⁡n).

Author: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **code (pikmike)**
```cpp
#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define x first
#define y second

using namespace std;

const int INF = 2e9;

typedef pair<int, int> pt;
map<int, int> ls;

int get(vector<pt> a){
	int cnt = 0;
	int l = -INF, r = -INF;
	sort(a.begin(), a.end());
	forn(i, a.size()){
		if (a[i].x > r){
			if (r != -INF)
				ls[l] = 0;
			++cnt;
			l = a[i].x, r = a[i].y;
		}
		else{
			r = max(r, a[i].y);
		}
	}
	ls[l] = 0;
	return cnt;
}

void process(vector<pair<int, pt>> &qr, vector<int> &ans){
	set<int> open;
	forn(i, qr.size()){
		vector<int> op, cl;
		int j = i - 1;
		while (j + 1 < int(qr.size()) && qr[j + 1].x == qr[i].x){
			++j;
			if (qr[j].y.x == 1)
				op.push_back(qr[j].y.y);
			else
				cl.push_back(qr[j].y.y);
		}
		if (open.size() == 1 && !op.empty()){
			++ans[*open.begin()];
		}
		for (auto it : op){
			open.insert(it);
		}
		for (auto it : cl){
			open.erase(it);
		}
		i = j;
	}
}

void solve(){
	int n;
	scanf("%d", &n);
	vector<pt> a(n);
	forn(i, n) scanf("%d%d", &a[i].x, &a[i].y);
	
	vector<pair<int, pt>> qr;
	forn(i, n){
		qr.push_back({a[i].x, {1, i}});
		qr.push_back({a[i].y, {-1, i}});
	}
	sort(qr.begin(), qr.end());
	
	vector<int> ans(n, 0);
	ls.clear();
	int cur = get(a);
	
	process(qr, ans);
	forn(i, n) if (ls.count(a[i].x)) ++ls[a[i].x];
	forn(i, n) if (ls[a[i].x] == 1) --ans[i];
	
	printf("%dn", *max_element(ans.begin(), ans.end()) + cur);
}

int main(){
	int tc;
	scanf("%d", &tc);
	forn(i, tc)
		solve();
}
```
 
### [1285F - Classical?](../problems/F._Classical_.md "Codeforces Round 613 (Div. 2)")

Since LCM(x,y)=x∗yGCD(x,y)LCM(x,y)=x∗yGCD(x,y), it makes sense to try and fix GCD(x,y)GCD(x,y). Let's call it gg. Now, let's only care about the multiples of gg in the input. Assume we divide them all by gg. We now want the maximum product of 2 coprime numbers in this new array.

Let's sort the numbers and iterate from the biggest to the smallest, keeping a stack. Assume the current number you're iterating on is xx. While there is a number in the stack coprime to xx, you can actually pop the top of the stack; you'll never need it again. That's because this number together with a number smaller than xx can never give a better product than that of a greater, or equal, number together with xx! Now, we just need to figure out whether there's a number coprime to xx in the stack. This could be easily done with inclusion-exclusion. Assume the number of multiples of dd in the stack is cntdcntd; the number of elements in the stack coprime to xx is: ∑d|xμ(d)∗cntd∑d|xμ(d)∗cntd Where μμ is the Mobius function. So we'll just iterate on the integers from greatest to smallest, and while there's a number coprime to xx in the stack, we'll keep maximizing the answer, popping, and updating the array cntcnt. Then, we'll push xx to the stack and also update cntcnt.

The complexity is O(∑i=1nσ0(i)2)O(∑i=1nσ0(i)2) where σ0σ0 is the divisor count function. That's because each number enters the routine of calculating the maximum product of a coprime pair σ0σ0 times, and we iterate through its divisors in this routine.

 **code (mohammedehab2002)**
```cpp
#include <bits/stdc++.h>
using namespace std;
#define MX 100000
int arr[100005],u[MX+5],cnt[MX+5];
vector<int> d[MX+5];
bool b[MX+5];
int coprime(int x)
{
	int ret=0;
	for (int i:d[x])
	ret+=cnt[i]*u[i];
	return ret;
}
void update(int x,int a)
{
	for (int i:d[x])
	cnt[i]+=a;
}
int main()
{
	for (int i=1;i<=MX;i++)
	{
		for (int j=i;j<=MX;j+=i)
		d[j].push_back(i);
		if (i==1)
		u[i]=1;
		else if ((i/d[i][1])%d[i][1]==0)
		u[i]=0;
		else
		u[i]=-u[i/d[i][1]];
	}
	int n;
	scanf("%d",&n);
	long long ans=0;
	for (int i=0;i<n;i++)
	{
		int a;
		scanf("%d",&a);
		ans=max(ans,(long long)a);
		b[a]=1;
	}
	for (int g=1;g<=MX;g++)
	{
		stack<int> s;
		for (int i=MX/g;i>0;i--)
		{
			if (!b[i*g])
			continue;
			int c=coprime(i);
			while (c)
			{
				if (__gcd(i,s.top())==1)
				{
					ans=max(ans,1LL*i*s.top()*g);
					c--;
				}
				update(s.top(),-1);
				s.pop();
			}
			update(i,1);
			s.push(i);
		}
		while (!s.empty())
		{
			update(s.top(),-1);
			s.pop();
		}
	}
	printf("%I64d",ans);
}
```
