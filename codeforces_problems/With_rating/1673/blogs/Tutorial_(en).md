# Tutorial_(en)

I am sorry for the weak tests in B, for C being a little standardish and for misjudging the relative difficulties of E and F. Nevertheless, I hope you enjoyed the round. Here is the editorial. Do provide your feedback on each problem so that I can improve upon them the next time.

#### [A. Subtle Substring Subtraction](../problems/A._Subtle_Substring_Subtraction.md)

 **Hint 1**Greedy

 **Hint 2**The answer depends on whether the length of s is even or odd and on the first and last characters of s if the length is odd.

 **Tutorial**The problem can be solved greedily. Let n be the length of the given string. 

 * If the n is even, it is always optimal for Alice to remove the whole string.
* If the n is odd, it is always optimal for Alice to remove either s1s2…sn−1 or s2s3…sn based on which gives the higher score and then Bob can remove the remaining character (sn or s1 respectively). This is optimal because if Alice chooses to remove a substring of even length 2k such that 2k<n−1 then Bob can remove the remaining n−2k≥3 characters, one of which will always be either s1 or sn, thus increasing Bob's score and decreasing Alice's score.
 **Bonus tasks**Prove that -

 1. Bob can win if and only if the length of the string is 1.
2. A draw is impossible.
 **Solution**
```cpp
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int tc;
    cin >> tc;
    while(tc--)
    {
        string s;
        cin >> s;
        int n=s.length(),alice=0;
        for(int i=0;i<n;i++)
            alice += s[i]-'a'+1;
        if(n%2==0)
            cout << "Alice " << alice << 'n';
        else
        {
            int bob;
            if(s[0]<=s[n-1])
                bob = s[0]-'a'+1;
            else
                bob = s[n-1]-'a'+1;
            alice -= bob;
            if(alice > bob)
                cout << "Alice " << alice-bob << 'n';
            else if(alice < bob)
                cout << "Bob " << bob-alice << 'n';
            else
                cout << "Draw " << 0 << 'n';
        }
    }
}
```
 **Feedback*** Good problem: 


[*349*](https://codeforces.com/data/like?action=like "I like this")
* Ok problem: 

 
[*82*](https://codeforces.com/data/like?action=like "I like this")
* Bad problem: 

 
[*16*](https://codeforces.com/data/like?action=like "I like this")
* Did not attempt: 

 
[*2*](https://codeforces.com/data/like?action=like "I like this")
#### [B. A Perfectly Balanced String?](../problems/B._A_Perfectly_Balanced_String_.md)

 **Hint 1**The string is perfectly balanced if it is periodic and the repeating pattern contains all distinct alphabets.

 **Tutorial**Let the number of distinct characters in s be k and length of s be n. Then, s will be perfectly balanced if and only if si,si+1,…,si+k−1 are all pairwise distinct for every i in the range 1≤i≤n−k+1.

 **Proof why this condition is necessary**If there exists some i in the range 1≤i≤n−k+1 for which the characters si,si+1,…,si+k−1 are not pairwise distinct, there will be atleast one character u in the substring t=sisi+1…si+k−1 such that ft(u)≥2 and by pigeonhole principle, there will be atleast one character v present in s such that ft(v)=0. So, for the triple (t,u,v), ft(u)−ft(v)≥2, violating the criteria for the s to be perfectly balanced.

 **Proof why this condition is sufficient**Suppose the following condition is met. Let's pick up any substring t=sisi+1…sj. Let's divide t into ⌈j−i+1k⌉ blocks each of length k except probably the last block. For each of these blocks, the frequency of all characters is equal to 1 (because there are k distinct characters in a block as well as in s) and for the last block, the frequency of some characters is equal to 1 wheras the frequency of rest of the characters is equal to 0. So, the frequency of some characters in t will be equal to ⌈j−i+1k⌉ while that for the other characters will be equal to ⌈j−i+1k⌉−1. If we pick any two characters u and v, |ft(u)−ft(v)|≤1 meaning that s is perfectly balanced.

 **Bonus task**Prove that the condition is equivalent to the following two conditions -

 1. The first k characters of s are pairwise distinct.
2. For each i in the range 1≤i≤n−k, si=si+k.
 **Solution**
```cpp
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int tc;
    cin >> tc;
    while(tc--)
    {
        string s;
        cin >> s;
        int n = s.length();
        set<char> c;
        bool ok = true;
        int k;
        for(k=0;k<n;k++)
        {
            if(c.find(s[k])==c.end())
                c.insert(s[k]);
            else
                break;
        }
        for(int i=k;i<n;i++)
        {
            if(s[i]!=s[i-k])
                ok = false;
        }
        if(ok)
            cout << "YESn";
        else
            cout << "NOn";
    }
}
```
 **Feedback*** Good problem: 

 
[*599*](https://codeforces.com/data/like?action=like "I like this")
* Ok problem: 

 
[*59*](https://codeforces.com/data/like?action=like "I like this")
* Bad problem: 

 
[*92*](https://codeforces.com/data/like?action=like "I like this")
* Did not attempt: 

 
[*6*](https://codeforces.com/data/like?action=like "I like this")
#### [C. Palindrome Basis](../problems/C._Palindrome_Basis.md)

 **Hint 1**The number of palindromes less than 4⋅104 is relatively small.

 **Hint 2**The rest of the problem is quite similar to the classical partitions problem.

 **Tutorial**First, we need to observe that the number of palindromes less than 4⋅104 is relatively very small. The number of 5-digit palindromes are 300 (enumerate all 3-digit numbers less than 400 and append the first two digits in the reverse order). Similarly, the number of 4-digit, 3-digit, 2-digit and 1-digit palindromes are 90, 90, 9 and 9 respectively, giving a total of M=498 palindromes.

Now, the problem can be solved just like the classical partitions problem which can be solved using Dynamic Programming.

Let dpk,m= Number of ways to partition the number k using only the first m palindromes. It is not hard to see that dpk,m=dpk,m−1+dpk−pm,m where pm denotes the mth palindrome. The first term corresponds to the partitions of k using only the first m−1 palindromes and the second term corresponds to those partitions of k in which the mth palindrome has been used atleast once. As base cases, dpk,1=1 and dp1,m=1. The final answer for any n will be dpn,M.

The time and space complexity is O(n⋅M). 

 **Bonus Task**Try to optimize the space complexity to O(n).

 **Solution**
```cpp
#include <bits/stdc++.h>
using namespace std;

const int N = 40004, M = 502;
const long long MOD = 1000000007;
long long dp[N][M];

int reverse(int n)
{
    int r=0;
    while(n>0)
    {
        r=r*10+n%10;
        n/=10;
    }
    return r;
}

bool palindrome(int n)
{
    return (reverse(n)==n); 
}

int main()
{
    vector<int> palin;
    palin.push_back(0);
    for(int i=1;i<2*N;i++)
    {
        if(palindrome(i))
            palin.push_back(i);
    }
    for(int j=1;j<M;j++)
        dp[0][j]=1;
    for(int i=1;i<N;i++)
    {
        dp[i][0]=0;
        for(int j=1;j<M;j++)
        {
            if(palin[j]<=i)
                dp[i][j]=(dp[i][j-1]+dp[i-palin[j]][j])%MOD;
            else
                dp[i][j]=dp[i][j-1];
        }
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc;
    cin >> tc;
    while(tc--)
    {
        int n;
        cin >> n;
        cout << dp[n][M-1] << 'n';
    }
}
```
 **Feedback*** Good problem: 

 
[*444*](https://codeforces.com/data/like?action=like "I like this")
* Ok problem: 

 
[*41*](https://codeforces.com/data/like?action=like "I like this")
* Bad problem: 

 
[*27*](https://codeforces.com/data/like?action=like "I like this")
* Standardish problem and boring to solve: 

 
[*181*](https://codeforces.com/data/like?action=like "I like this")
* Standardish problem but learned something new today 

 
[*250*](https://codeforces.com/data/like?action=like "I like this")
* Did not attempt: 

 
[*44*](https://codeforces.com/data/like?action=like "I like this")
#### [D. Lost Arithmetic Progression](../problems/D._Lost_Arithmetic_Progression.md)

 **Hint 1**First check if all elements of C are present in B or not. If not, the answer is 0.

 **Hint 2**Then check if the answer is infinite or not. It depends on only the first and last elements of B and C.

 **Hint 3**If p is the common difference of A then lcm(p,q)=r. p must necessarily be a factor of r and O(√n) works here.

 **Tutorial**If all elements of C are not present in B, then the answer is 0. It is sufficient to check the following 4 conditions to check if all elements of C are present in B or not -

 * The first term of B≤ The first term of C, i.e., b≤c.
* The last term of B≥ The last term of C, i.e., b+(y−1)q≥c+(z−1)r.
* The common difference of C must be divisible by the common difference of B, i.e., rmodq=0.
* The first term of C must lie in B, i.e., (c−b)modq=0.

Now suppose the following conditions are satisfied. Let's denote an Arithmetic Progression (AP) with first term a, common difference d and n number of terms by [a,d,n].

If b>c−r then there are infinite number of progressions which can be A like [c,r,z], [c−r,r,z+1], [c−2r,r,z+2] and so on. Similarly, if b+(y−1)q<c+zr, there are infinite number of progressions which can be A like [c,r,z], [c,r,z+1], [c,r,z+2] and so on.

Otherwise, there are a finite number of progressions which can be A. Let's count them. Let A be the AP [a,p,x] and l=a+(x−1)p. It can be seen that lcm(p,q)=r, (c−a)modp=0, a>c−r and l<c+rz for any valid A. The first two conditions are trivial. The third condition is necessary because if a≤c−r then c−r will always be present in both A and B contradicting the fact that C contains all the terms common to A and B. Similarly, the fourth condition is also necessary. 

The only possible values p can take according to the first condition are factors of r which can be enumerated in O(√r). The lcm condition can be checked in O(logr). For a particular value of p, there are rp possible values of a satisfying conditions 2 and 3 and rp possible values of l satisfying conditions 2 and 4. Thus, the answer is ∑lcm(p,q)=r(rp)2.

Time complexity: O(t√rlogr)

 **Solution**
```cpp
#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007;

long long gcd(long long a,long long b)
{
    if(b==0)
        return a;
    else
        return gcd(b,a%b);
}

long long lcm(long long a,long long b)
{
    long long g = gcd(a,b);
    return (a*b)/g;
}

int main()
{
    int tc;
    cin >> tc;
    while(tc--)
    {
        long long b,c,q,r,y,z;
        cin >> b >> q >> y;
        cin >> c >> r >> z;
        long long e = b+q*(y-1);
        long long f = c+r*(z-1);
        if(c<b || c>e || f<b || f>e || r%q!=0 || (c-b)%q!=0)
            cout << 0 << 'n';
        else if(c-r<b || f+r>e)
            cout << -1 << 'n';
        else
        {
            long long ans = 0;
            for(long long p=1;p*p<=r;p++)
            {
                if(r%p==0)
                {
                    if(lcm(p,q)==r)
                    {
                        long long a = ((r/p)*(r/p))%MOD;
                        ans = (ans+a)%MOD;
                    }
                    if(p*p!=r && lcm(r/p,q)==r)
                    {
                        long long a = (p*p)%MOD;
                        ans = (ans+a)%MOD;
                    }
                }
            }
            cout << ans << 'n';
        }
    }
}
```
 **Feedback*** Good problem: 

 
[*166*](https://codeforces.com/data/like?action=like "I like this")
* Ok problem: 

 
[*40*](https://codeforces.com/data/like?action=like "I like this")
* Bad problem: 

 
[*114*](https://codeforces.com/data/like?action=like "I like this")
* Did not attempt: 

 
[*33*](https://codeforces.com/data/like?action=like "I like this")
#### [E. Power or XOR?](../problems/E._Power_or_XOR_.md)

 **Hint 1**All numbers in A are powers of 2 and the modulo is also a power of 2 and Bi≥1.

 **Hint 2**Fix all operators in a particular subsegment as Power and fix the operators around the segment as XOR. Find the contribution of this segment independent of other segments.

 **Hint 3**Maximum possible length for such a subsegment which can contribute to the answer is 20.

 **Hint 4**Use Lucas' Theorem or Submasks DP or precomputation in order to count the parity of the number of valid unambiguous expressions in which the subsegment appears as in Hint 2.

 **Tutorial**Let's consider a subsegment [Al∧Al+1∧Al+2∧…∧Ar]. Let all the ∧ symbols in this segment be replaced by Power and the ∧ symbols before Al and after Ar be replaced by XOR. Then the value of this segment will not be affected by the rest of the expression. Moreover, out of all the expressions in which this segment appears as above, it will contribute the same value to the final answer. Since the final answer is also a XOR, if the segment [l…r] appears in the above mentioned form in odd number of valid unambiguous expressions, it will contribute (…((AAl+1l)Al+2)…)Ar to the final answer else it will contribute nothing. We can find the contribution of each segment [l…r] independently for all values of 1≤l<r≤n. 

Now, there are two things we need to find out: 

 1. How much (…((AAl+1l)Al+2)…)Ar will contribute to the final answer, modulo MOD=21048576.
2. What is the parity of the count of valid unambiguous expressions, in which the segment [l...r] appears as ...⊕(…((AAl+1l)Al+2)…)Ar⊕….

**Part 1:** Notice that since all the elements of A are powers of 2, S(l,r)=(…((AAl+1l)Al+2)…)Ar will also be a power of 2. It means that XOR-ing it with answer will flip not more than 1 bit in the answer. The rest of the calculations is pretty straightforward. S(l,r)=2Bl⋅Al+1⋅Al+2⋅…⋅Ar by properties of exponents. So, if it contributes to the answer, it will flip the Bl⋅Al+1⋅Al+2⋅…⋅Ar−th bit of the answer. Now, note that if S≥21048576, it will have no effect on the answer because S(l,r)mod21048576 will then be 0. So, we care only for those (l,r) for which S(l,r)<21048576. Since Bi≥1, Ai≥2 and so, r−l≤20 because 220=1048576. Thus, it is sufficient to calculate S(l,r) for only 20 values of r per value of l.

**Part 2:** We have used r−l ∧ operators as Power and 0, 1 or 2 ∧ operators as XOR. Let's say that out of the m unused operators, we need to use at least q of them as XOR. Then the number of ways to do this is (mq)+(mq+1)+(mq+2)+…+(mm). Infact, instead of finding this value, we are only interested in finding whether it is even or odd. So, we need the value of [(mq)+(mq+1)+(mq+2)+…+(mm)]mod2= [(m−1q)+(m−1q−1)+(m−1q+1)+(m−1q)+(m−1q+2)+(m−1q+1)+…+(m−1m−1)+(m−1m−2)+(mm)]mod2= [(m−1q−1)+(m−1m−1)+(mm)]mod2= (m−1q−1)mod2 as (a+a)mod2=0 and (xx)=1 by definition. (m−1q−1)mod2 can be found using [Lucas' Theorem](https://codeforces.com/https://brilliant.org/wiki/lucas-theorem/). It turns out that (nr) is odd if and only if r is a submask of n, i.e., n|r=n. Note that there are also many other ways to find this value (like Submasks DP or using the fact that r−l≤20 for precomputation) but this is the easiest one.

Some final notes -

 1. We can maintain the final answer as a binary string of length 1048576. Find the value X=Bl⋅Al+1⋅Al+2⋅…⋅Ar and if the required parity is odd and X<1048576, flip the $X-$th bit of the string.
2. We need to be careful while calculating Bl⋅Al+1⋅Al+2⋅…⋅Ar since Ai can be as large as 21048575. But since we are interested in values that evaluate to something smaller than 1048576, we will never try to multiply Ai for anything with Bi>20.
3. Calculating the parity of (nr) in O(logn) may time out. The constraints are strict enough.

Total time Complexity — O(nloglogMOD)

 **Bonus Task**Try to solve the problem if Bi≥0 and if powers are calculated from right to left.

 **Solution**
```cpp
#include <bits/stdc++.h>
using namespace std;

const int N = 1048576;
long long b[N];
char ans[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k;
    cin >> n >> k;
    for(int i=0;i<n;i++)
    {
        cin >> b[i];
    }
    for(int i=0;i<1048576;i++)
        ans[i]='0';
    for(int l=0;l<n;l++)
    {
        long long p=1;
        for(int r=l;r<n;r++)
        {
            if(r==l)
                p*=b[r];
            else
            {
                if(b[r]>=20)
                    break;
                else
                    p*=(1ll<<b[r]);
            }
            if(p>=1048576)
                break;
            int m = n-r+l-3;
            int q = k-2;
            if(l==0)
            {
                m++;
                q++;
            }
            if(r==n-1)
            {
                m++;
                q++;
            }
            if(m>=q && (m==0 || (q>0 && ((m-1)|(q-1))==(m-1))))
                ans[p]='1'+'0'-ans[p];
        }
    }
    bool start=false;
    for(int i=1048575;i>=0;i--)
    {
        if(ans[i]=='0' && start)
            cout << 0;
        else if(ans[i]=='1')
        {
            cout << 1;
            start=true;
        }
    }
    if(!start)
        cout << 0;
    cout << 'n';
}
```
 **Feedback*** Good problem: 

 
[*56*](https://codeforces.com/data/like?action=like "I like this")
* Ok problem: 

 
[*25*](https://codeforces.com/data/like?action=like "I like this")
* Bad problem: 

 
[*18*](https://codeforces.com/data/like?action=like "I like this")
* Did not attempt: 

 
[*58*](https://codeforces.com/data/like?action=like "I like this")
#### [F. Anti-Theft Road Planning](../problems/F._Anti-Theft_Road_Planning.md)

 **Hint 1**The main goal is to assign numbers Ai,j from 0 to 1023 to all buildings such that all buildings get distinct numbers and assign the road lengths between buildings Bx1,y1 and Bx2,y2 as Ax1,y1⊕Ax2,y2. Among all such assignments, try to find the one which has the least sum of road lengths.

 **Hint 2**2-Dimensional Gray Code works

 **Tutorial**For now, lets ignore n<=32 and assume n=32.

Let's try to build the roads in such a way that no matter what path the thief takes to reach building Bi,j, the tracker will always return a fixed value Ai,j such that all Ai,j are distinct. Then by knowing the values returned by the tracker, one can easily find which building the theft occurred in. The main problem here is not to choose the lengths of the roads, since by choosing the length of road between buildings Bx1,y1 and Bx2,y2 as Ax1,y1⊕Ax2,y2, one can always achieve this property. But there is a constraint which needs to be satisfied: The total length of all roads must not exceed 48000. This is, in fact, a tight constraint (model solution uses 47616) due to which one needs to choose the values of Ai,j very efficiently.

Consider this problem — Find a permutation of numbers from 0 to 2m−1 such that the sum of XOR of consecutive integers is minimized. The answer to this is [Gray Code or Reflected Binary Code](https://codeforces.com/https://en.wikipedia.org/wiki/Gray_code). In the standard Gray Code, bit 0 is flipped 2m−1 times, bit 1 is flipped 2m−2 times, bit 2 is flipped 2m−3 times, …, bit m−1 is flipped 1 time. The idea is to use small bits more number of times compared to the larger ones. 

Our task is to implement this idea in 2-dimensions. Let's look at the algorithm used to build Gray Code. If we have the Gray Code for k bits, it can be extended to k+1 bits by taking a copy of it, reflecting it and appending 1 to the beginning of the reflected code and 0 to the beginning of the original one. Here, if we have the Gray Code for 2k×2k matrix, it can be first extended to a Gray Code for 2k×2k+1 matrix and this can further be extended to a Gray Code for 2k+1×2k+1 matrix. If we build a 2m×2m matrix using this algorithm, the total length of roads used will be 32⋅(4m)⋅(2m−1). In this problem, m=5. So, total length of roads used = 32⋅1024⋅31=47616.

Once this construction is complete, finding the buildings where thefts occurred is elementary since there can now be only one building corresponding to each value returned by the tracker.

Now, coming back to the original problem, we can simply take the first n rows and the first n columns from the constructed matrix. The cost won't increase and the properties still hold.

 **Solution**
```cpp
#include <bits/stdc++.h>
using namespace std;

const int N = 32;

int maxpower2(int n)
{
    int p=1;
    while(n%2==0)
    {
        p*=2;
        n/=2;
    }
    return p;
}

int main()
{
    int n,k;
    cin >> n >> k;
    int h[N][N-1];
    for(int i=0;i<N;i++)
    {
        for(int j=1;j<=N-1;j++)
        {
            h[i][j-1]=maxpower2(j)*maxpower2(j);
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-1;j++)
        {
            cout << h[i][j] << " ";
        }
        cout << endl;
    }
    int v[N-1][N];
    for(int i=1;i<=N-1;i++)
    {
        for(int j=0;j<N;j++)
        {
            v[i-1][j]=2*maxpower2(i)*maxpower2(i);
        }
    }
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    int b[n][n];
    b[0][0]=0;
    for(int j=1;j<n;j++)
    {
        b[0][j]=b[0][j-1]^h[0][j-1];
    }
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            b[i][j]=b[i-1][j]^v[i-1][j];
        }
    }
    map<int,pair<int,int> > m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            m[b[i][j]]={i,j};
        }
    }
    int y=0;
    while(k--)
    {
        int x;
        cin >> x;
        pair<int,int> ans = m[x^y];
        cout << ans.first+1 << " " << ans.second+1 << endl;
        y^=x;
    }
}
```
 **Feedback*** Good problem: 

 
[*103*](https://codeforces.com/data/like?action=like "I like this")
* Ok problem: 

 
[*23*](https://codeforces.com/data/like?action=like "I like this")
* Bad problem: 

 
[*10*](https://codeforces.com/data/like?action=like "I like this")
* Did not attempt: 

 
[*48*](https://codeforces.com/data/like?action=like "I like this")
