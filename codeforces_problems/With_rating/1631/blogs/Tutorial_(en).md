# Tutorial_(en)


### [1631A - Min Max Swap](../problems/A._Min_Max_Swap.md "Codeforces Round 768 (Div. 2)")

Author: [humbertoyusta](https://codeforces.com/profile/humbertoyusta "Master humbertoyusta")

 **Hint 1**Think about how max(a1,a2,...,an,b1,b2,...,bn) will contribute to the answer.

 **Hint 2**The maximum of one array is always max(a1,a2,...,an,b1,b2,...,bn). How should you minimize then?

 **Solution**Let m1=max(a1,a2,...,an,b1,b2,...,bn). The answer will always be m1⋅m2 where m2 is the maximum of the array that does not contain m1.

Since m1 is fixed, the problem can be reduced to minimize m2, that is, minimize the maximum of the array that does not contain the global maximum.

WLOG assume that the global maximum will be in the array b, we can swap elements at each index x such that ax>bx, ending with ai≤bi for all i. It can be shown that the maximum of array a is minimized in this way.

Time complexity: O(n)

 **Code**
```cpp
#include<bits/stdc++.h>
using namespace std;
 
int calc_max(vector<int> a){
    int res = 0;
    for( auto i : a )
        res = max( res , i );
    return res;
}
 
int main(){
    int tc;
    cin >> tc;
    while( tc-- ){
        int n;
        cin >> n;
 
        vector<int> a(n), b(n);
        for( auto &i : a )
            cin >> i;
        for( auto &i : b )
            cin >> i;
 
        for(int i=0; i<n; i++)
            if( a[i] > b[i] )
                swap( a[i] , b[i] );
 
        cout << calc_max(a) * calc_max(b) << 'n';
    }
}
```
### [1631B - Fun with Even Subarrays](../problems/B._Fun_with_Even_Subarrays.md "Codeforces Round 768 (Div. 2)")

Author: [humbertoyusta](https://codeforces.com/profile/humbertoyusta "Master humbertoyusta")

 **Hint 1**It is not possible to modify an using the given operation.

 **Hint 2**Think about the leftmost x such that ax≠an.

 **Solution**For simplicity, let b1,b2,...,bn=an,an−1,...,a1 (let b be a reversed). The operation transforms to select a subarray [l,r] of length 2⋅k, so k=r−l+12, then for all i such that 0≤i<k, set bl+k+i=bl+i.

b1 can not be changed with the given operation. That reduces the problem to make all elements equal to b1.

Let x be the rightmost index such that for all 1≤i≤x, bi=b1 holds.

The problem will be solved when x=n.

If an operation is applied with l+k>x+1, bx+1 will not change and x will remain the same.

The largest range with l+k≤x+1 is [1,2⋅x], applying an operation to it will lead to bx+1,bx+2,...,b2⋅x=b1,b2,...,bx, so x will become at least 2⋅x and there is not any other range that will lead to a bigger value of x.

If 2⋅x>n, it is possible to apply the operation on [x−(n−x)+1,n], after applying it bx+1,...,bn=bx−(n−x)+1,...,bx and all elements will become equal.

The problem can now be solved by repeatedly finding x and applying the operation on [1,2⋅x] or on [x−(n−x)+1,n] if 2⋅x>n. 

Since x will become at least 2⋅x in each operation but the last one, the naive implementation will take O(nlogn), however, it is easy to implement it in O(n).

 **Code O(nlogn)**
```cpp
#include<bits/stdc++.h>
using namespace std;

int find_rightmost_x(vector<int> &b){
    int n = (int)b.size() - 1;

    int x = 1;
    while( x + 1 <= n && b[x+1] == b[1] )
        x ++;

    return x;
}

void apply(vector<int> &b,int l,int r){
    int k = ( r - l + 1 ) / 2;
    for(int i=0; i<k; i++)
        b[l+k+i] = b[l+i];
}

int main(){

    int tc;
    cin >> tc;
    while( tc-- ){

        int n;
        cin >> n;

        vector<int> a(n+1);
        for(int i=1; i<=n; i++)
            cin >> a[i];

        vector<int> b = a;
        reverse(b.begin()+1,b.end());

        int ans = 0;
        while( find_rightmost_x(b) != n ){
            int x = find_rightmost_x(b);
            if( 2 * x > n ){
                apply(b,x-(n-x)+1,n);
                ans ++;
            }
            else{
                apply(b,1,2*x);
                ans ++;
            }
        }
        cout << ans << 'n';
    }


    return 0;
}
```
 **Code O(n)**
```cpp
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int tc;
    cin >> tc;
    while(tc--)
    {
        int n;
        cin >> n;

        vector<int> a(n+1);
        for(int i=1; i<=n; i++)
            cin >> a[i];

        vector<int> b = a;
        reverse(b.begin()+1,b.end());

        int ans = 0, x = 1;

        while( x < n )
        {
            if( b[x+1] == b[1] ){
                x ++;
                continue;
            }
            ans ++;
            x *= 2;
        }

        cout << ans << 'n';
    }

    return 0;
}
```
### [1630A - And Matching](https://codeforces.com/contest/1630/problem/A "Codeforces Round 768 (Div. 1)")

Author: [humbertoyusta](https://codeforces.com/profile/humbertoyusta "Master humbertoyusta")

 **Hint 1**Try to find a pairing such that n/2∑1ai&bi=0

 **Hint 2**Try to find a pairing for k>0 by changing only a few elements from the previous pairing.

 **Solution****Constructive approach (easier)**Let's define c(x), the compliment of x, as the number x after changing all bits 0 to 1 and vice versa, for example c(1100102)=0011012.

It can be shown that c(x)=x⊕(n−1). Remember that n−1=11...112 since n is a power of 2.

We will separate the problem into three cases.

 * **Case k=0:**

In this case it is possible to pair x with c(x) for 0≤x<n2, getting n2−1∑x=0x&c(x)=0.
* **Case 0<k<n−1:**

In this case it is possible to pair each element with its compliment except 0, k, c(k) and n−1, and then pair 0 with c(k) and k with n−1, 0&c(k)=0 and k&(n−1)=k.
* **Case k=n−1:**

There are many constructions that work in this case, if n=4 there is no solution, if n≥8 it is possible to construct the answer in the following way:

It is possible to pair n−1 with n−2, n−3 with 1, 0 with 2 and all other elements with their compliments.


	+ (n−1)&(n−2)=n−2, for example 11112&11102=11102
	+ (n−3)&1=1, for example 11012&00012=00012
	+ 0&2=0, for example 00002&00102=00002
	+ All other elements can be paired with their complements and x&c(x)=0Note that (n−2)+1+0+0+...+0=n−1.

Each case can be implemented in O(n).

 **Code**
```cpp
#include<bits/stdc++.h>
using namespace std;

int c(int x,int n){
    return ( x ^ ( n - 1 ) );
}

int main(){

    int tc;
    cin >> tc;
    while( tc-- ){

        int n, k;
        cin >> n >> k;

        vector<int> a(n/2), b(n/2);

        if( k == 0 ){
            for(int i=0; i<n/2; i++){
                a[i] = i;
                b[i] = c(i,n);
            }
        }

        if( k > 0 && k < n - 1 ){
            int small_k = min( k , c(k,n) );
            for(int i=0; i<n/2; i++){
                if( i != 0 && i != small_k ){
                    a[i] = i;
                    b[i] = c(i,n);
                }
            }

            a[0] = 0;
            b[0] = c(k,n);

            a[small_k] = k;
            b[small_k] = n - 1;
        }

        if( k == n - 1 ){

            if( n == 4 ){
                cout << -1 << 'n';
                continue;
            }

            a[0] = n - 2;
            b[0] = n - 1;

            a[1] = 1;
            b[1] = n - 3;

            a[2] = 0;
            b[2] = 2;

            for(int i=3; i<n/2; i++){
                a[i] = i;
                b[i] = c(i,n);
            }
        }

        for(int i=0; i<n/2; i++){
            cout << a[i] << ' ' << b[i] << 'n';
        }
    }


    return 0;
}
```
 **Greedy approach (harder)**Let's define a such that ai=i−1 for 1≤i≤n2 and b such that bi=c(ai) for 1≤i≤n2.

For example, for n=16 they are:

 a=[00002,00012,00102,00112,01002,01012,01102,01112] b=[11112,11102,11012,11002,10112,10102,10012,10002] 

| 1st element to swap | 2nd element to swap | n/2∑i=1ai&bi after swap |
| --- | --- | --- |
| none | none | 0 |
| b1 | b2 | 1 |
| b2 | b3 | 3 |
| b3 | b4 | 1 |
| b4 | b5 | 7 |
| b5 | b6 | 1 |
| b6 | b7 | 3 |
| b7 | b8 | 1 |

All swaps are independent and are applied to the original a and b.

After swapping two adjacent elements of b (that have not been swapped) the sum will change in 2x−1 for some positive integer x.

Then it is possible to solve the problem by repeatedly swapping the pair that maximizes n/2∑i=1ai&bi after the swap such that n/2∑i=1ai&bi≤k is held and none of its elements have been swapped yet.

However, this only works for all values of k if n≥32, the case n≤16 can be handled with brute force. 

 **Randomized approach (harder)**Please read the previous solution. Arrays a and b from it will also be used here. 

It is possible to start with a and b and repeatedly select and index x randomly and swap bx with bx+1 if n/2∑i=1ai&bi≤k holds until n/2∑i=1ai&bi=k. 

We have no proof of this solution but it was stressed against each possible input to the problem and it worked quickly for n≥16, the case n≤8 can be handled with brute force.

### [1630B - Range and Partition](https://codeforces.com/contest/1630/problem/B "Codeforces Round 768 (Div. 1)")

Author: [humbertoyusta](https://codeforces.com/profile/humbertoyusta "Master humbertoyusta")

 **Hint 1**Focus on how to solve the problem for a fixed interval [x,y]

 **Hint 2**Think about the numbers inside the interval as +1, and the other numbers as −1

 **Hint 3**Try to relate a partition into valid subarrays with an increasing sequence of the prefix sums array

 **Hint 4**Note that if some value x (x>0) appears on the prefix sums array, x−1 appears before since the absolute value of the elements is 1 (+1 and -1)

 **Solution**Focus on how to solve the problem for a fixed interval [x,y]:

Let us define an array b such that bi=1 if x≤ai≤y or bi=−1 otherwise, for all 1≤i≤n.

Let's define psumi as b1+b2+...+bi.

We need to find a partition on k subarrays with positive sum of bi.

The sum of a subarray [l,r] is bl+bl+1+...+br=psumr−psuml−1. Then a subarray is valid if psumr>psuml−1.

We need to find an increasing sequence of psum of length k+1 starting at 0 and ending at n.

Let's define firstoccx to be the first occurrence of the integer x in psum.

If psumn<k there will be no valid sequence, otherwise the sequence 0,firstocc1,firstocc2,...,firstocck−1,n will satisfy all constraints. 

Note that, since |psumi−psumi−1|=1, for i>0, then firstoccv exists and firstoccv<firstoccv+1 for 0≤v≤psumn.

This solves the problem for a fixed interval.

It remains to find the smallest interval [x,y] such that psumn≥k.

For a given interval [x,y], since psumn=b1+b2+...+bn, psumn will be equal to the number of elements of a inside the interval minus the number of elements outside.

Then for each x, it is possible to find the smallest y such that psumn≥k using binary search or two pointers.

It is also possible to note that:

 psumn≥k n∑i=1bi≥k n∑i=1(−1+2⋅[x≤ai≤y])≥k n∑i=1[x≤ai≤y]≥⌈k+n2⌉We need to find the smallest interval with at least ⌈k+n2⌉ inside, let A be the array a sorted, the answer is the minimum interval among all intervals [Ai,Ai+⌈k+n2⌉−1] for 1≤i≤n−⌈k+n2⌉+1.

Complexity: O(nlogn) if solved with the previous formula or binary search, or O(n) is solved with two pointers.

 **Code (with the previous formula)**
```cpp
#include<bits/stdc++.h>
using namespace std;
 
int main() {
 
    int tc;
    cin >> tc;
    while( tc-- ){
 
        int n, k;
        cin >> n >> k;
 
        vector<int> a(n), sorted_a(n);
        for(int i=0; i<n; i++){
            cin >> a[i];
            sorted_a[i] = a[i];
        }
 
        sort(sorted_a.begin(),sorted_a.end());
 
        int req_sum = ( n + k + 1 ) / 2;
 
        pair<int,pair<int,int>> ans = { n + 1 , { -1 , -1 } };
 
        for(int i=0; i+req_sum-1<n; i++)
            ans = min( ans , { sorted_a[i+req_sum-1] - sorted_a[i] , { sorted_a[i] , sorted_a[i+req_sum-1] } } );
 
        cout << ans.second.first << ' ' << ans.second.second << 'n';
 
        int subarrays_found = 0, curr_sum = 0;
        int last_uncovered = 1;
 
        for(int i=0; i<n; i++){
 
            if( a[i] >= ans.second.first && a[i] <= ans.second.second ) curr_sum ++;
                else curr_sum --;
 
            if( curr_sum > 0 && subarrays_found + 1 < k ){
 
                cout << last_uncovered << ' ' << ( i + 1 ) << 'n';
                last_uncovered = i + 2;
 
                subarrays_found ++;
                curr_sum = 0;
            }
        }
 
        subarrays_found ++;
        cout << last_uncovered << ' ' << n << 'n';
 
    }
 
    return 0;
}
```
### [1630C - Paint the Middle](https://codeforces.com/contest/1630/problem/C "Codeforces Round 768 (Div. 1)")

Author: [humbertoyusta](https://codeforces.com/profile/humbertoyusta "Master humbertoyusta")

 **Hint 1**Think about all occurrences of some element, what occurrences are important?

 **Hint 2**Think about the first and last occurrence of each element as a segment.

 **Hint 3**Think about the segments that at least one of its endpoints will end up with ci=0.

 **Solution**For each x such that all the elements a1,a2,...,ax are different from ax+1,ax+2,...,an it is impossible to apply an operation with some indices from the first part, and some other from the second one.

Then it is possible to split the array in subarrays for each x such that the previous condition holds, and sum the answers from all of them.

Let's solve the problem independently for one of those subarrays, let's denote its length as m, the values of its elements as a1,...,am and their colors as c1,...,cm:

For every tuple (x,y,z) such that 1≤x<y<z≤m and ax=ay=az it is possible to apply an operation with indices x,y and z. Then only the first and last occurrences of each element are important.

For all pairs (x,y) such that 1≤x<y≤m, ax=ay, ax is the first occurrence and ay the last occurrence of that value, a segment [x,y] will be created.

Let's denote the left border of a segment i as li and the right border as ri.

Let's say that a set of segments S is connected if the union of its segments is the segment [min(li,∀i∈S),max(ri,∀i∈S)].

Instead of maximizing m∑i=1ci, it is possible to focus on minimizing m∑i=1[ci=0].

**Lemma 1:** If we have a connected set S, it is possible to apply some operations to its induced array to end up with at most |S|+1 elements with ci=0.

 **Proof**For each segment x in S if there exists a segment y such that ly<lx<rx<ry, it is possible to apply the operation with indices ly,lx,ry and with ly,rx,ry. Otherwise, add this segment to a set T.

Then is possible to repeatedly select the leftmost segment of T that have not been selected yet, and set the color of its right border to 1, this will be always possible until we select the rightmost segment since T is connected.

In the end, all the left borders of the segments of T will have ci=0, the same holds for the right border of the rightmost segment of T, which leads to a total of |T|+1 elements with ci=0, and |T|≤|S|.

Let X be a subarray that can be obtained by applying the given operation to the initial subarray any number of times.

Let S(X) be the set of segments that includes all segments i such that c[li]=0 or c[ri]=0 (or both), where c[i] is the color of the i-th segment of the subarray X.

**Lemma 2:** There is always an optimal solution in which S(X) is connected.

 **Proof**Suppose S(X) is not connected, if there are only two components of segments A and B, there will always be a segment from A to B due to the way the subarray was formed.

If A or B have some segment x such that there exists a segment y such that ly<lx<rx<ry you can erase it by applying the operation with indices ly,lx,ry and with ly,rx,ry. Then we can assume that ∑i∈A([c[li]=0]+[c[ri]=0])=|A|+1 and similarly for B.

The solution to A before merging is |A|+1, the solution to B is |B|+1, if we merge A and B with a segment we get a component C of size |A|+|B|+1, and its answer will be |A|+|B|+1+1 (using \bf{lemma 1}), the case with more than two components is similar, then we can always merge the components without making the answer worse.

Finally, the problem in each subarray can be reduced to find the smallest set (in number of segments), such that the union of its segments is the whole subarray. This can be computed with dp or sweep line.

 **DP solution**Let dp[x] be the minimum size of a set such that the union of its segments is the segment [1,x].

To compute dp, process all the segments in increasing order of ri, and compute the value of dp[ri]=min(dp[li+1],dp[li+2],...,dp[ri−1])+1.

Then the solution to the subarray is dp[m]+1, this dp can be computed in O(mlogm) with segment tree.

It is possible to compute a similar dp to solve the problem for the whole array without splitting the array, the time complexity is O(nlogn).

 **Code**
```cpp
#include<bits/stdc++.h>
using namespace std;
 
template <typename Tnode,typename Tup>
struct ST{
    vector<Tnode> st;
    int sz;
 
    ST(int n){
        sz = n;
        st.resize(4*n);
    }
 
    Tnode merge_(Tnode a, Tnode b){
        Tnode c;
        /// Merge a and b into c
        c = min( a , b );
        return c;
    }
 
    void update_node(int nod,Tup v){
        /// how v affects to st[nod]
        st[nod] = v;
    }
 
    void build(vector<Tnode> &arr){ build(1,0,sz-1,arr); }
 
    void build(int nod,int l,int r,vector<Tnode> &arr){
        if( l == r ){
            st[nod] = arr[l];
            return;
        }
        int mi = ( l + r ) >> 1;
            build((nod<<1),l,mi,arr);
            build((nod<<1)+1,mi+1,r,arr);
        st[nod] = merge_( st[(nod<<1)] , st[(nod<<1)+1] );
    }
 
    void update(int id,Tup v){ update(1,0,sz-1,id,v); }
 
    void update(int nod,int l,int r,int id,Tup v){
        if( l == r ){
            update_node(nod,v);
            return;
        }
        int mi = ( l + r ) >> 1;
        if( id <= mi ) update((nod<<1),l,mi,id,v);
            else update((nod<<1)+1,mi+1,r,id,v);
        st[nod] = merge_( st[(nod<<1)] , st[(nod<<1)+1] );
    }
 
    Tnode query(int l,int r){ return query(1,0,sz-1,l,r); }
 
    Tnode query(int nod,int l,int r,int x,int y){
 
        if( l >= x && r <= y ) return st[nod];
 
        int mi = ( l + r ) >> 1;
 
        if( y <= mi ) return query((nod<<1),l,mi,x,y);
 
        if( x > mi ) return query((nod<<1)+1,mi+1,r,x,y);
 
        return merge_( query((nod<<1),l,mi,x,y), query((nod<<1)+1,mi+1,r,x,y) );
    }
};
 
int main(){
 
    int n;
    cin >> n;
 
    vector<int> a(n), fst(n,-1), lst(n,-1);
    for(int i=0; i<n; i++){
        cin >> a[i];
        a[i] --;
        if( fst[a[i]] == -1 )
            fst[a[i]] = i;
        lst[a[i]] = i;
    }
 
    vector<pair<int,int>> segments;
    for(int i=0; i<n; i++)
        if( fst[i] != -1 )
            segments.push_back({lst[i]+1,fst[i]+1});
    sort(segments.begin(),segments.end());
 
    vector<int> dp(n+1,1000000007);
    dp[0] = 0;
 
    ST<int,int> st(n+1);
    st.build(dp);
    for( auto i : segments ){
        dp[i.first] = min( dp[i.first] , dp[i.second-1] + 1 + ( i.first != i.second ) );
        if( i.second + 1 <= i.first - 1 )
            dp[i.first] = min( dp[i.first] , st.query(i.second+1,i.first-1) + 1 );
        st.update(i.first,dp[i.first]);
    }
    cout << n - dp[n] << 'n';
 
    return 0;
}
```
 **Sweep line solution**It is possible to create an event where a segment starts and an event where a segment ends. 

Then process the events in order and each time a segment ends, if it is the rightmost segment added, add to the solution the segment with maximum ri among the segments that li is already processed.

It is possible to modify the sweep line to solve the problem for the whole array without splitting the array, the time complexity is O(n) or O(nlogn) depending on the implementation.

### [1630D - Flipping Range](https://codeforces.com/contest/1630/problem/D "Codeforces Round 768 (Div. 1)")

Author: [humbertoyusta](https://codeforces.com/profile/humbertoyusta "Master humbertoyusta")

 **Hint 1**What is the size of the smallest subarray that it is possible to multiply by −1 using some operations?

 **Hint 2**Let s be a string such that si=0 if that element is multiplied by −1 or si=1 otherwise, what such s are reachable?

 **Hint 3**Think about the parity of the sum of all si such that imodg=constant, where g is the size of the smallest subarray that it is possible to multiply by −1 using some operations

 **Solution**If we have x,y∈B (assume x>y), since all elements of B are at most ⌊n2⌋, it is possible to multiply all intervals of size x−y by either multiplying an interval of size x that starts at the position of the interval of size x−y, and an interval of size y that ends at the same position as the interval x, or multiply an interval of size x that ends at the same position as the interval of size x−y and another interval of size y that starts at the same position as the interval of size x.

For two elements x,y∈B (x>y), it is possible to add x−y to B, repeatedly doing this it is possible to get gcd(x,y).

Let g=gcd(b1,b2,...,bm:bi∈B), by applying the previous reduction g is the smallest element that can be obtained, and all other elements will be its multiples, then the problem is reduced to, multiplying intervals of size g by −1 any number of times, maximize n∑i=1ai.

Let's define the string s=000...00 of size n (0-indexed) such that si=0 if the i-th element is not multiplied by −1 or si=1 otherwise. The operation flips all values of s in a substring of size g. 

Let's define fx as the [xor](https://codeforces.com/https://en.wikipedia.org/wiki/Bitwise_operation#XOR) over all values si such that imodg=x, note that fx is defined for the values 0≤x≤g−1.

In any operation, all values of f change simultaneously, since they are all 0 at the beginning only the states of s such that all fi are equal are reachable. 

To prove that all states of s with all fi equal are reachable, let's start with any state of s such that f=000...00 and repeatedly select the rightmost i such that si=1 and i≥g−1 and flip the substring that ends in that position, after doing that as many times as possible, si=0 for g−1≤i≤n−1. If si=1 for any 0≤i<g, then fi=1 which is a contradiction since fg−1=0 and all fi change simultaneously, then s=000...00. The case with all values of f equal to 1 is similar.

After this, it is possible to solve the problem with dp. 

Let dpi,0 be the maximum sum of ai,ai−g,ai−2⋅g,...,ai−k⋅g such that i−k⋅g≡i(modg) and ⨁k≥0,i−k⋅g≥0fi−k⋅g=0 and dpi,1 be the same such that ⨁k≥0,i−k⋅g≥0fi−k⋅g=1.

The answer to the problem is max(n−1∑i=n−gdpi,0,n−1∑i=n−gdpi,1) (0-indexed). 

This dp can be computed in O(n).

 **Code**
```cpp
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    while(T--)
    {
        int n,m;
        cin >> n >> m;
        vector<int> a(n),b(m);
        for(int i=0;i<n;i++)
            cin >> a[i];

        int g=0;
        for(int i=0;i<m;i++)
        {
            cin >> b[i];
            g=__gcd(g,b[i]);
        }

        vector<vector<ll>> dp(g,vector<ll>(2));
        for(int i=0;i<g;i++)
            dp[i][1]=-2e9;
        for(int i=0;i<n;i++)
        {
            int rem=i%g;
            ll v0=max(dp[rem][0]+a[i],dp[rem][1]-a[i]);
            ll v1=max(dp[rem][0]-a[i],dp[rem][1]+a[i]);
            dp[rem][0]=v0;
            dp[rem][1]=v1;
        }

        ll sum0=0,sum1=0;
        for(int i=0;i<g;i++)
        {
            sum0+=dp[i][0];
            sum1+=dp[i][1];
        }

        cout << max(sum0,sum1) << 'n';
    }

    return 0;
}
```
### [1630E - Expected Components](https://codeforces.com/contest/1630/problem/E "Codeforces Round 768 (Div. 1)")

Author: [BrayanD](https://codeforces.com/profile/BrayanD "Master BrayanD")

 **Hint 1**[Burnside's lemma](https://codeforces.com/https://cp-algorithms.com/combinatorics/burnside.html)

 **Hint 2**Think about an easy way to count the number of components in a cyclic array.

 **Hint 3**The number of components in a cyclic array is equal to the number of adjacent positions with different values.

 **Solution**The problem can be solved by applying [Burnside's lemma](https://codeforces.com/https://cp-algorithms.com/combinatorics/burnside.html).

The number of different permutations of the cyclic array a is equal to the sum of number of fixed points for each permutation function divided by the number of permutations functions.

Let's focus on two parts.

First part (find the number of different permutations of a):

Let's define a permutation function Fx(arr) as the function that cyclically shifts the array arr by x positions.

In this problem for an array of size n we have n possible permutations functions and we would need to find the sum of the number of fixed points for each permutation function.

To find the number of fixed points for a permutation function Fx() we have that arri must be equal to arr(i+x)%n, if we add an edge (i,(i+x)%n) for each position i then by number theory we would obtain that gcd(n,x) cycles would be formed and each one of size ngcd(n,x), then we can note that each position i will belong to the (i%gcd(n,x))-th cycle, so we can say that the problem can be transformed into counting the number of permutations with repetition in an array of size gcd(n,x).

Let us denote cnt[v] as the number of values equal to v in array a, when we are processing the function Fx() and we reduce the problem to an array of size gcd(n,x) we should also decrease cnt[v] to cnt[v]n/gcd(n,x) since each component is made up of ngcd(n,x) values, also we must observe that for solving a problem for an array of size x, then nx should be a divisor of gcd(cnt[1],cnt[2],…,cnt[n]).

Let us denote cntx[v]=cnt[v]n/gcd(n,x)

So to count the number of permutations with repetition for Fx() that can be formed with the frequency array cntx we can use the formula n!x1!⋅x2!⋅…⋅xn!

Let us denote Gall=gcd(cnt[1],cnt[2],…,cnt[n])

Let us denote fdiv(val) as the number of divisors of val.

Let us denote totsz as the number of permutations with repetition for an array of size sz, from what has been said before we have that nsz must be divisible by Gall so we only need to calculate the permutations with repetition for fdiv(Gall) arrays.

Now suppose that the number of different values of array a is k then Gall must be at most nk because the gcd of several numbers is always less than or equal to the smallest of them.

Now to calculate the permutations with repetition for a cntx we do it in O(k), for that we need to precalculate some factorials and modular inverses before, and since we need to calculate them fdiv(Gall) times, then we have that in total the complexity would be O(fdiv(Gall)⋅k) but since Gall is at most nk and fdiv(nk) is at most nk, substituting it would be O(nk⋅k) equal to O(n)

So to find the sum of the number of fixed points we need the sum of totgcd(n,x) for 1≤x≤n and ngcd(n,x) divides to Gall, at the end of all we divide the sum of the number of fixed points by n and we would obtain the number of different permutations of a.

To find the gcd(n,x) for 1≤x≤n we do it with the Euclid's algorithm in complexity O(n⋅log) so in total the complexity is O(n⋅log)

Second part (find the expected value of components of different permutations of a):

Here we will use the Linear Expectation property and we will focus on calculating the contribution of each component separately, the first thing is to realize that the number of components is equal to the number of different adjacent values, so we only need to focus on two adjacent values, except if it is a single component, this would be a special case. If we have k different values we can use each different pair of them that in total would be k⋅(k−1) pairs, we can realize that when we put a pair its contribution would be equal to the number of ways to permute the remaining values, which if we are in an array of size nx and we use the values val1 and val2 it would be equal to:

totn/x⋅1(n/x)⋅(n/x−1)⋅cntx[val1]⋅cntx[val2]

because we removing a value val1 and another value val2 from the set, so if we have the formula:

n!x1!⋅x2!⋅…⋅xn!

and val1 and val2 are the first two elements then it would be:

(n−2)!(x1−1)!⋅(x2−1)!⋅…⋅xn!

which would be equivalent to:

n!x1!⋅x2!⋅…⋅xn!⋅1n⋅(n−1)⋅x1⋅x2

Now to calculate the contribution of the k⋅(k−1) pairs we can realize that taking common factor totn/x⋅1(n/x)⋅(n/x−1) in the previous expression it only remains to find the sum of cntx[i]⋅cntx[j] for all i≠j, this can be found in O(k) easily by keeping the prefix sum and doing some multiplication. Then at the end we multiply by n since there are n possible pairs of adjacent elements in the general array.

Let us define sumsz as the contribution of components of the permutations with repetition for an array of size sz, then:

sumn/x=totn/x⋅1(n/x)⋅(n/x−1)⋅(sum of (cntx[i]⋅cntx[j]) for i≠j)⋅n

Now for each possible permutation with repetition we have by the Burnside's lemma that in the end we divide it by n, so we should also divide by n the contribution of each component.

Let's define tot′x=totxn and sum′x=sumxn

Let's define totall as the sum of tot′gcd(n,x) for 1≤x≤n and ngcd(n,x) divide to Gall.

Let's define sumall as the sum of sum′gcd(n,x) for 1≤x≤n and ngcd(n,x) divide to Gall.

The final answer would be:

res=sumalltotall

The final complexity then is O(n⋅log)

 **Code**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6 + 100;

const int MOD = 998244353;

long long fact[MAXN];

long long F[MAXN];

long long qpow(long long a, long long b)
{
    long long res = 1;
    while(b)
    {
        if(b&1)res = res*a%MOD;
        a = a*a%MOD;
        b /= 2;
    }
    return res;
}

long long inv(long long x)
{
    return qpow(x,MOD-2);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    fact[0] = 1;

    for(int i = 1 ; i < MAXN ; i++)
    {
        fact[i] = fact[i-1]*i%MOD;
    }

    int T;
    cin >> T;

    while(T--)
    {
        int N;
        cin >> N;

        for(int i = 1 ; i <= N ; i++)
        {
            F[i] = 0;
        }

        for(int i = 1 ; i <= N ; i++)
        {
            int n;
            cin >> n;
            F[n]++;
        }

        vector<long long> vvv;

        for(int i = 1 ; i <= N ; i++)
        {
            if(F[i])vvv.push_back(F[i]);
        }

        int G = 0;

        for(auto x : vvv)
        {
            G = __gcd(G,x);
        }

        if(G == N)
        {
            cout << 1 << 'n';
            continue;
        }

        vector<long long> arr(N+1);
        vector<long long> arr2(N+1);

        for(int i = 1 ; i <= G ; i++)
        {
            if(G%i == 0)
            {
                long long tot = inv(fact[N/i-2]), acum = 0, sum = 0;

                for(auto x : vvv)
                {
                    tot = tot*fact[x/i]%MOD;
                    sum = (sum + acum*(x/i)*2)%MOD;
                    acum = (acum + (x/i))%MOD;
                }

                tot = inv(tot);

                arr2[i] = tot*(N/i-1)%MOD*(N/i)%MOD;

                tot = tot*sum%MOD*N%MOD;

                arr[i] = tot;
            }
        }

        long long res = 0;
        long long cont = 0;

        for(int i = 1 ; i <= N ; i++)
        {
            long long ggg = N/__gcd(N,i);

            if(G%ggg == 0)
            {
                res = (res + arr[ggg])%MOD;
                cont = (cont + arr2[ggg])%MOD;
            }
        }

        cout << res*inv(cont)%MOD << 'n';
    }

    return 0;
}
```
### [1630F - Making It Bipartite](https://codeforces.com/contest/1630/problem/F "Codeforces Round 768 (Div. 1)")

Author: [BrayanD](https://codeforces.com/profile/BrayanD "Master BrayanD")

 **Hint 1**Think about the directed graph where there is an directed edge from a to b if and only if b|a

 **Hint 2**Let us define the above graph as G, make a duplicate graph G′ from G, and then add directed edges (x′,x) for each node x′ of the graph G′. What happens in this graph?

 **Hint 3**Maximum [Antichain](https://codeforces.com/https://en.wikipedia.org/wiki/Antichain)

 **Solution**First of all, let's analyze what happens when there are 3 vertices x, y and z such that ax|ay, ax|az and ay|az, if this happens then the graph cannot be bipartite because there would be a cycle of size 3, therefore there cannot be such a triple (x, y, z), this condition, besides to being necessary, is sufficient since we can separate the graph into two sets, set A: vertices that have edges towards multiples, set B: vertices that have edges towards divisors, keep in mind that a vertex cannot exist in two sets at the same time if the condition is fulfilled, now note that there are no edges between elements of the same set because if this happens it would mean that they belong to different sets and it would be a contradiction, then the problem is to find the minimum number of vertices to remove such that in the remaining vertices there is no such triple of numbers (x, y, z). Now instead of minimizing the number of vertices to remove, let's try to maximize the number of vertices that will remain in the graph.

Let us define the directed graph G as the graph formed by n vertices, and directed edges (u, v) such that av|au, now the problem is reduced to finding the maximum number of vertices such that in the graph formed among them, no vertex has ingoing edges and outgoing edges at the same time, formally for each vertex x the following property must be kept indegreex=0 or outdegreex=0, in this way we guarantee that there is no triple (x, y, z) such that ax|ay, ax|az and ay|az.

Now let's define the graph G′ as a copy of the graph G. Formally for each directed edge (u, v) in the graph G there is an directed edge (u′, v′) in the graph G′. On the other hand, let's define the graph H=G+G′ and we will also add new directed edges (u′, u), this graph H is a DAG, it is easy to see that the edges always go from a vertex u to a vertex v only if au>av, except for the edges (u′, u), which in this case au′=au, these edges are the ones that connect G′ to G, but since they always go in one direction pointing towards G, the property of DAG is still fulfilled.

Now the only thing we have to do is find the largest antichain in the graph H, this can be done using the Dilworth's Theorem, modeling the problem as a bipartite matching, we can use some flow algorithm such as Dinic's Algorithm, or Hopcroft Karp's Algorithm, which is specific to find the maximum bipartite matching.

#### Proof:

First of all we realize that the graph G is a special graph since if there is an indirect path from a vertex u to a vertex v then there is always a direct edge between them, this is true because if we have 3 vertices x, y and z such that ax|ay and ay|az then always ax|az. With this we can say that two elements are not reachable with each other if and only if there are no edges between them. Now let's say that all the vertices in the graph G are white and all the vertices in the graph G′ are black, let us denote f(x) a function such that f(u′)=u, where the vertex u from the graph G is the projection of the vertex u′ from the graph G′. Now let's divide the proof into two parts.

#### First part:

**Lemma 1:** Every antichain of H can be transformed into a valid set of vertices such that they form a bipartite graph.

Proof of Lemma 1: Let's divide the antichain of H into two sets, white vertices and black vertices, Let us define the set of white vertices as W and the set of all black vertices as B, now we will create a set S = {f(x) | x∈B}. It is easy to see that no element in S belongs to W since if this happens it would mean that there is an element x such that x belongs to B and f(x) belongs to W and by the concept of antichain that would not be possible. It is also easy to see that the elements of the set S are an antichain since the set S is a projection of vertices from the set B of the graph G′ on G. Now we have that there are no edges between the vertices of the set S and there are no edges between the vertices of the set W, with this it is proved that the graph is bipartite.

#### Second part:

**Lemma 2:** Every valid set of vertices such that they form a bipartite graph can be transformed into an antichain of H.

Proof of Lemma 2: Let us denote f−1(x) a function such that f−1(u)=u′, where vertex u from graph G is the projection of vertex u′ from graph G′. Let us denote the set A as all vertices that have indegree greater than 0 and B to all vertices that have outdegree greater than 0, now we will create a set C = {f−1(x) | x∈A}, It is easy to see that set B is an antichain since if one vertex has an edge to another vertex then some of them would have indegree greater than 0 and would contradict the definition of set B, we can also see that the elements in set A are an antichain since all the elements have outdegree=0 so no vertex point towards any other vertex, with this we can define that all the elements in C are an antichain since they are a projection of vertices of the set A from the graph G on G′, Now we want to proof that the union of set B and C is an antichain, this is very simple to see since the vertices of set B belong to G and the vertices of C belong to G′, therefore there is no edge from any vertex in B to a vertex in C since there are no edges from G to G′. Now it only remains to proof that from set C no vertex of set B can be reached, this is proved taking into account that the vertices reachable from the set C in the graph G are the same that the vertices reachable from the set A in the graph G, and as no vertex of A has edges towards B, this cannot happen. Therefore the union of the sets B and C is an antichain of H.

Then we can say that the two problems are equivalent and it is shown that finding the maximum antichain we obtain the largest bipartite graph.

The graph G contains n vertices and around n⋅log(n) edges (since the numbers ax are different and the sum of the divisors from 1 to n is around n⋅log(n)). The graph G′ is a duplicate of G then we would have n⋅log(n)⋅2+n edges and 2⋅n vertices, if we use the Hopcroft Karp algorithm we would obtain a time complexity of O(n⋅log(n)⋅sqrt(n)) and a space complexity of O(n⋅log(n)).

 **Code**
```cpp
#include <bits/stdc++.h>

using namespace std;

struct HOPCROFT_KARP
{
    int n, m;
    vector<vector<int>> adj;
    vector<int> mu, mv, level, que;

    HOPCROFT_KARP(int n, int m) : n(n), m(m), adj(n), mu(n, -1), mv(m, -1), level(n), que(n) {}

    void add_edge(int u, int v)
    {
        adj[u].push_back(v);
    }

    void bfs()
    {
        int qf = 0, qt = 0;
        for(int u = 0 ; u < n ; ++u)
        {
            if(mu[u] == -1)que[qt++] = u, level[u] = 0;
            else level[u] = -1;
        }
        for( ; qf < qt ; ++qf)
        {
            int u = que[qf];
            for(auto w : adj[u])
            {
                int v = mv[w];
                if(v != -1 && level[v] == -1)
                    que[qt++] = v, level[v] = level[u] + 1;
            }
        }
    }

    bool dfs(int u)
    {
        for(auto w : adj[u])
        {
            int v = mv[w];
            if(v == -1 || (level[v] == level[u] + 1 && dfs(v)))
                return mu[u] = w, mv[w] = u, true;
        }
        return false;
    }

    int max_matching()
    {
        int match = 0;
        for(int c = 1 ; bfs(), c ; match += c)
            for(int u = c = 0 ; u < n ; ++u)
                if(mu[u] == -1)
                    c += dfs(u);
        return match;
    }

    pair<vector<int>, vector<int>> min_vertex_cover()
    {
        max_matching();
        vector<int> L, R, inR(m);
        for(int u = 0 ; u < n ; ++u)
        {
            if(level[u] == -1)L.push_back(u);
            else if(mu[u] != -1)inR[mu[u]] = true;
        }
        for(int v = 0 ; v < m ; ++v)
            if(inR[v])R.push_back(v);
        return { L, R };
    }
};

const int MAXN = 5e4 + 100;

int arr[MAXN];
vector<int> dv[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 1 ; i < MAXN ; i++)
    {
        for(int j = i*2 ; j < MAXN ; j+=i)
        {
            dv[j].push_back(i);
        }
    }

    for(int i = 0 ; i < MAXN ; i++)
    {
        arr[i] = -1;
    }

    int T;
    cin >> T;

    while(T--)
    {
        int N;
        cin >> N;

        vector<int> vect;

        for(int i = 0 ; i < N ; i++)
        {
            int n;
            cin >> n;
            vect.push_back(n);
            arr[n] = i;
        }

        vector<pair<int,int>> edge;

        for(int i = 0 ; i < N ; i++)
        {
            for(auto x : dv[vect[i]])
            {
                if(arr[x] != -1)
                {
                    edge.push_back({i, arr[x]});
                }
            }
        }

        for(auto x : vect)
        {
            arr[x] = -1;
        }

        HOPCROFT_KARP HK(2*N,2*N);

        for(auto x : edge)
        {
            int i = x.first;
            int j = x.second;
            HK.add_edge(i,j);
            HK.add_edge(i+N,j+N);
        }

        for(int i = 0 ; i < N ; i++)
        {
            HK.add_edge(i+N,i);
        }

        cout << HK.max_matching()-N << 'n';
    }

    return 0;
}
```
