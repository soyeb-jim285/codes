# Tutorial_(en)

[1934A — Too Min Too Max](../problems/A._Too_Min_Too_Max.md)

 **Solution****Hint 1**What will be answer if there were only 4 elements in the array?

 **Solution**Suppose if there were only 4 elements in the array. Let them be a≤b≤c≤d. Then the answer will be maximum of the three cases which are listed as follows:-

 |a−b|+|b−c|+|c−d|+|d−a|=2∗d−2∗a |a−b|+|b−d|+|d−c|+|c−a|=2∗d−2∗a |a−c|+|c−b|+|b−d|+|d−a|=2∗(d+c)−2∗(a+b)so clearly 2∗(d+c)−2∗(a+b) is the maximum. 

So, to maximize this we can set d, c as large as possible and a, b as small as possible i.e. d=an, c=an−1, b=a2 and a=a1 where ai means ith element in sorted order of given array.

 **Code (C++)**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int testcases;
    cin >> testcases;
    for (int t = 1; t <= testcases; t++)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int j = 0; j < n; j++)
        {
            cin >> v[j];
        }
        sort(v.begin(), v.end());
        cout << 2 * (v[n - 1] - v[0]) + 2 * (v[n - 2] - v[1]) << endl;
    }
}

```
 **Code (Python)**
```cpp
t = int(input())
for i in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    a = sorted(a)
    ans = 2 * (a[n - 1] - a[0] + a[n - 2] - a[1])
    print(ans)
```
[1934B — Yet Another Coin Problem](../problems/B._Yet_Another_Coin_Problem.md)

 **Solution 1****Hint**At max how many 1, 3, 6, 10 are required?

 **Solution****Fact**: You will never need more than 2 ones, 1 threes, 4 sixes and 2 tens.

**Reason**: 

For 1: Suppose if you used k > 2 ones, then you could have used one 3 and k — 3 ones. 

For 3: Suppose if you used k > 1 threes, then you could have used one 6 and k — 2 threes.

For 6: Suppose if you used k > 4 sixes, then you could have used two 15's and k — 5 sixes.

For 10: Suppose if you used k > 2 tens, then you could have used two 15's and k — 3 tens.

now since bound on their count is less, we can bruteforce on these count.

 **Code (C++)**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int testcases;
    cin >> testcases;
    for (int t = 1; t <= testcases; t++)
    {
        int n;
        cin >> n;
        int ans = 1e9;
        for(int ones = 0; ones <= 2; ones++){
            for(int threes = 0; threes <= 1; threes++){
                for(int sixes = 0; sixes <= 4; sixes++){
                    for(int tens = 0; tens <= 2; tens++){
                        int brute_sum = 1*ones + 3*threes + 6*sixes + 10*tens;
                        if(brute_sum <= n && (n-brute_sum)%15 == 0){
                            ans = min(ans, ones + threes + sixes + tens + (n-brute_sum)/15);
                        }
                    }
                }
            }
        }
        cout << ans << endl;
    }
}
```
 **Solution 2****Hint**When will the greedy logic of choosing the higher-valued coin first work? 

 **Solution****Fact 1**: If coins of value 1, 3, 6 and 15 were only present the greedy logic of selecting the higher valued first would work.

**Reason**: We use coins of value one at most 2 times, coins of value three at most 1 time, coins of value six at most 2 times (if it was used 3 times, it would be better to use two coins 15+3) But we can't use the coin of value 3 and both coins of value 6 simultaneously, because we would prefer just using 15.  
It means that these coins may sum up to 1+1+3+6=11 or 1+1+6+6=14 at max. So, we may use the value 15 greedily, because the remaining part is less than 15. When we are left with only the values 1, 3, and 6, greedily solving is obviously correct, because each coin is a divisor of the next coin. 

**Fact 2**: We don't need more than 2 ten coins.

**Reason**: Better to use 2 fifteen coins instead of 3 ten coins.

Using the above two facts it can be shown that the answer will have k<3 ten coin, therefore, answer = min(answer(n−10∗k)+k assuming 1, 3, 6 and 15 coins are only present). 

 **Code (C++)**
```cpp
#include<bits/stdc++.h>
 
using namespace std;
 
int getAns(int n){
    int ans=0;
    ans+=n/15;
    n%=15;
    ans+=n/6;
    n%=6;
    ans+=n/3;
    n%=3;
    ans+=n;
    return ans;
}
 
int main(){
    ios::sync_with_stdio(false), cin.tie(nullptr);
 
    int testcases;
    cin>>testcases;
    for(int i=1;i<=testcases;i++){
        int n;cin>>n;
        if(n<10){
            cout<<getAns(n)<<endl;
        }else if(n<20){
            cout<<min(getAns(n),getAns(n-10)+1)<<endl;
        }else{
            cout<<min({getAns(n),getAns(n-10)+1,getAns(n-20)+2})<<endl;
        }
    }
}
```
[1934C — Find a Mine](../problems/C._Find_a_Mine.md)

 **Hint 1**After querying "? 1 1" What do we know about the location of mines?

 **Answer**If the answer is a1 the location of one of the mines is (x,y) such that x+y=a1+2.

 **Solution 1****Solution**First, we query "? 1 1" then you get a value a1 and you know that at least one of the mine is on the line x+y=a1+2. 

Now we make two more queries on both ends of this line where it touches the grid. After these two queries, we get two possible locations of the mine. We query one of these positions if we receive 0 as the answer then this location otherwise the other location is the answer.

**Reason**: One of that two locations contains a mine. The other mine could spoil the result of the query only from one end. If it was closer from the other mine to both of the ends, it would mean that going from one end to the other is shorter through that mine, than through the diagonal. That's impossible.

 **Code (C++)**
```cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--){
        int n, m;
        cin >> n >> m;
        auto query = [&](int x, int y){
            if (x < 1 || x > n || y < 1 || y > m)
                return -1;
            cout << "? " << x << ' ' << y << endl;
            int z;
            cin >> z;
            return z;
        };
        int d = query(1, 1);
        int lx = max(1, 2 + d - m);
        int p = query(lx, 2 + d - lx);
        int rx = max(1, 2 + d - n);
        int q = query(2 + d - rx, rx);
        if (query(lx + p / 2, 2 + d - lx - p / 2) == 0){
            cout << "! " << lx + p / 2 << " " <<  2 + d - lx - p / 2<<endl;
        }else{
            cout << "! " << 2 + d - rx - q / 2 << " " << rx + q / 2 << endl;
        }
    }
}
```
 **Solution 2****Hint 2**What if we made the second query as "? n m"?

 **Answer**If the answer is a2 the location of one of the mines is (x,y) such that x+y=n+m−a2.

 **Solution**Using Hint 1 and Hint 2 if we get the same line equation i.e. n+m−a2=a1−2 we can just query one of the endpoints of this line and get the answer. 

Otherwise, we can query "? 1 m" and we will get one more line perpendicular to the earlier two. One of the mines has to be on this line therefore there will be a mine either on the intersection of line we got from query 1 and query 3 or on the intersection of line we got from query 2 and query 3. 

We can make our next query on any of these intersections if we get the answer as 0, then this point is the answer otherwise the other point is the answer.

 **Code (C++)**
```cpp
#include <bits/stdc++.h>

using namespace std;
 
using ll = long long;
 
ll query(ll x, ll y) {
    cout << "? " << x << ' ' << y << endl;
    ll d;
    cin >> d;
    return d;
}
 
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    
    ll t;
    cin >> t;
    
    while (t--) {
        ll n, m;
        cin >> n >> m;
        
        ll sum1 = query(1, 1) + 2;
        ll sum2 = n + m - query(n, m);
        ll dif1 = query(1, m) + 1 - m;
        
        auto simplify = [&](ll num, ll lim)->ll{
            return max(min(num, lim), 1LL);
        };
        ll x1 = simplify((sum1+dif1)/2, n), y1 = simplify((sum1-dif1)/2, m);
        ll x2 = simplify((sum2+dif1)/2, n), y2 = simplify((sum2-dif1)/2, m);
        
        if (query(x1, y1)) cout << "! " << x2 << ' ' << y2 << endl;
        else cout << "! " << x1 << ' ' << y1 << endl;
    }
    return 0;
}
```
[1934D1 — XOR Break — Solo Version](../problems/D1._XOR_Break_---_Solo_Version.md)

 **Hint**To generate any possible m, it takes at most two operations.

 **Solution**Let's determine the achievable values of m for a given n.

If n is a perfect power of 2, then it cannot be broken down further, and no m<n is achievable. Otherwise, if n has at least two set bits, let's denote the most significant bit as a and the second most significant bit as b.

**Fact 1**: All m values less than n are achievable if their most significant bit does not lie between b+1 and a−1.

**Reason**: For instance, 1001???? can be decomposed into 1000???? and 0001????, or 1001???? and 0000????. In either case, we can never flip the 6th or 7th bit.

Using the above fact, we can break the problem into two cases:

**Case 1**: If the most significant bit of m is at position ≤b.

Perform the first operation as 2b+1−1 and n⊕(2b+1−1) (10001???? -> 10000???? and 000011111 in binary form). Then, any submask of 2b+1−1 can be created in the next operation.

**Case 2**: If the most significant bit of m is at position a.

If the most significant bit of m is at position a, then m can be obtained in one operation as m and m⊕n, since m<n as given in the question, and n⊕m has its most significant bit <a.

 **Code**
```cpp
#include<bits/stdc++.h>

using namespace std;
 
using ll = long long;
 
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    
    ll t;
    cin >> t;
    
    while (t--) {
        ll n, m;
        cin >> n >> m;
        
        ll hi = 0, sec_hi = 0;
        for (ll p = (1LL<<62); p > 0; p >>= 1) {
            if (p & n) {
                if (!hi) hi = p;
                else if (!sec_hi) sec_hi = p;
            }
        }
        bool flag = (sec_hi && ((m & hi) || (m < sec_hi*2)));
        if (!flag) {
            cout << -1 << 'n';
            continue;
        }
        vector<ll> ans = {n, m};
        if (!(m & hi) && !(m & sec_hi)) ans = {n, m^sec_hi, m};
        
        cout << (ll)ans.size()-1 << 'n';
        for (auto &x: ans) cout << x << ' ';
        cout << 'n';
    }
    return 0;
}
```
[1934D2 — XOR Break — Game Version](../problems/D2._XOR_Break_---_Game_Version.md)

 **Hint 1**If both p1 and p2 are perfect powers of 2, it is a losing state since you cannot perform a break operation on either of those.

 **Hint 2**If either p1 or p2 has a bit count of 2, then this is a winning state.

 **Reason**You can force your opponent into the state described in Hint 1 using the number which has 2 bitcount.

 **Solution****Fact 1**: If p1 has an odd bit count, then it can only be broken into two numbers such that one has an odd bit count and the other has an even bit count.

**Fact 2**: If either p1 or p2 has an even bit count, then this is a winning state.

**Reason** : If either p1 or p2 has an even bit count, without loss of generality, assume it's p1. Then break it into 2msb of p1 and p1⊕2msb of p1, where msb is the most significant bit.

If the opponent chooses 2msb of p1, they instantly lose (using Hint 1), so they are forced to choose the other number with an odd bit count. From Fact 1, we can conclude that in the next turn, the state will remain conserved for the current player.

Because we eliminate the most significant bit in every query, this game will go on for at most 60 turns for the player who reached this position first. At one point, the player who is at this state will have a number with two set bits.

Hence, from Hint 2, we can say this player will win. So, as Alice, you will start first if n has an even number of bits and start second if it has an odd number of bits. Proceed using the strategy discussed above. So as Alice you have will start first if n has even number of bits and start second if it has odd number of bits. Any proceed using the strategy discussed above.

 **Code**
```cpp
#include<bits/stdc++.h>
 
using namespace std;
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int testcases;cin>>testcases;
 
    for(int testcase=1;testcase<=testcases;testcase++){
        long long n;cin>>n;
        long long curr=n;
        int parity=0;
        if(__builtin_popcountll(n)%2){
            cout<<"secoNd"<<endl;
        }else{
            cout<<"firSt"<<endl;
            parity=1;
        }
        int turn=0;
        while(1){
            if(turn%2==parity){
                long long p1,p2;cin>>p1>>p2;
                if (p1 == 0 && p2 == 0)
                    break;
                if(__builtin_popcountll(p1)%2==0){
                    curr=p1;
                }else{
                    curr=p2;
                }
            }else{
                int pos=0;
                for(int i=0;(1ll<<i)<curr;i++){
                    if(curr&(1ll<<i)){
                        pos=i;
                    }
                }
                long long p1=(1ll<<pos);
                long long p2=curr^p1;
                cout<<p1<<" "<<p2<<endl;
                curr = p1;
            }
            turn++;
        }
    }
}

```
[1934E — Weird LCM Operations](../problems/E._Weird_LCM_Operations.md)

 **Solution****Fact 1**: If for (x,y,z) their pairwise GCDs are equal to their common GCD (this means that (x,y,z) = (g∗X,g∗Y,g∗Z) where (X,Y,Z) are pairwise coprime), then making an operation on them (gives (g∗X∗Y,g∗X∗Z,g∗Y∗Z)) and looking at the subsequences of size EXACTLY 2, we find all three GCD: x, y, z. Let's call such tuple NICE.

**Result**: If we can split all values in the array into independent NICE tuples, then we can just perform an operation on each of them and the problem is solved.

**Fact 2**: We don't touch any value ≤ n2. If there is x ≤ n2, then 2∗x≤n. If we don't touch x, then we will always have another value that is divisible by x (it's easy to see that performing an operation on a multiple of x leaves us with another multiple of x), so we will always have GCD equal to x taking a subsequence (x,x∗A).

**Fact 3**: A sequence of consecutive integers (x,x+1,x+2,...,x+11) can be partitioned into 4 disjoint sets of size 3, each forming a NICE tuple, if (x+11)%4 equals 2 or 1.

**For (x+11)%4=2**: The sets (x,x+1,x+2), (x+4,x+5,x+6) and (x+8,x+9,x+10) are NICE because, the first and third terms are always odd, and the second term is always even. The set (x+3,x+7,x+11) is NICE because it has the form of 2∗(2∗n−1), 2∗(2∗n), 2∗(2∗n+1), ensuring that the pairwise GCDs are equal to the common GCD.

**For (x+11)%4=1**: The sets (x,x+4,x+8), (x+1,x+2,x+3), (x+5,x+6,x+7) and (x+9,x+10,x+11) are NICE, the same logic like (x+11)%4=2 follows,

If n%4=3 we can do one operation as (1,2,n), and if n%4=0 we can do one operation as (1,n−1,n). Let's group the remaining elements into the groups of size 12, starting from the end, and continuing until we reach the number n2.

Eventually, we can count that we used no more than ⌊n6⌋+5 operations.

Solutions for n≤13 should be found manually.

 **Code**
```cpp
#include<bits/stdc++.h>
 
using namespace std;
vector<vector<vector<int>>> pans(14);
int main(){
 
    ios::sync_with_stdio(false), cin.tie(nullptr);
 
    int t;cin>>t;
 
    pans[3]={{1,2,3}};
    pans[4]={{1,3,4}};
    pans[5]={{3,4,5}};
    pans[6]={{1,3,5},{2,4,6}};
    pans[7]={{2,4,6},{3,5,7}};
    pans[8]={{2,6,8},{3,5,7}};
    pans[9]={{1,3,5},{2,4,6},{7,8,9}};
    pans[10]={{3,4,5},{2,6,8},{7,9,10}};
    pans[11]={{2,6,8},{3,5,7},{9,10,11}};
    pans[12]={{1,11,12},{6,8,10},{5,7,9}};
    pans[13]={{1,12,13},{7,9,11},{6,8,10}};
    for(int tt=0;tt<t;tt++){
        int n;cin>>n;
        if(n<=2){
            cout<<-1<<endl;
        }else if(n<14){
            cout<<pans[n].size()<<endl;
            for(auto w: pans[n]){
                cout<<w[0]<<" "<<w[1]<<" "<<w[2]<<endl;
            }
        }else{
            vector<int> v(n);
            for(int i=0;i<n;i++){
                v[i]=i+1;
            }
            vector<vector<int>> ans;
            while (2*v.size()>n){
                if(v.size()%4==2){
                    vector<int> buf;
                    for(int i=0;i<12;i++){
                        buf.push_back(v.back());
                        v.pop_back();
                    }
                    reverse(buf.begin(),buf.end());
                    ans.push_back({buf[0],buf[1],buf[2]});
                    ans.push_back({buf[4],buf[5],buf[6]});
                    ans.push_back({buf[8],buf[9],buf[10]});
                    ans.push_back({buf[3],buf[7],buf[11]});
                }else if(v.size()%4==1){
                    vector<int> buf;
                    for(int i=0;i<12;i++){
                        buf.push_back(v.back());
                        v.pop_back();
                    }
                    reverse(buf.begin(),buf.end());
                    ans.push_back({buf[1],buf[2],buf[3]});
                    ans.push_back({buf[5],buf[6],buf[7]});
                    ans.push_back({buf[9],buf[10],buf[11]});
                    ans.push_back({buf[0],buf[4],buf[8]});
                }else if(v.size()%4==3){
                    vector<int> buf;
                    buf.push_back(v.back());
                    v.pop_back();
                    buf.push_back(2);
                    buf.push_back(1);
                    reverse(buf.begin(),buf.end());
                    ans.push_back({buf[0],buf[1],buf[2]});
                }else{
                    vector<int> buf;
                    buf.push_back(v.back());
                    v.pop_back();
                    buf.push_back(v.back());
                    v.pop_back();
                    buf.push_back(1);
                    reverse(buf.begin(),buf.end());
                    ans.push_back({buf[0],buf[1],buf[2]});
                }
            }
            cout<<ans.size()<<endl;
            for(auto w: ans){
                cout<<w[0]<<" "<<w[1]<<" "<<w[2]<<endl;
            }
        }
    }
}
```
