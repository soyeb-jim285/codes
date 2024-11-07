# Tutorial

Thanks for the participation!

 
### [1883A - Morning](https://codeforces.com/contest/1883/problem/A "Codeforces Round 905 (Div. 3)")

Let's represent our pin code as a set of digits aa, bb, cc, dd. Replace all 00s with 1010 and notice that the answer is equal to |a−1||a−1| + |b−a||b−a| + |c−b||c−b| + |d−c||d−c|.

 Tutorial is loading... 
### [1883C - Raspberries](https://codeforces.com/contest/1883/problem/C "Codeforces Round 905 (Div. 3)")

Let's notice that if k=2,3,5k=2,3,5, since these are prime numbers, the product of the numbers will be divisible by kk if any number in the array is divisible by kk. From this, we can conclude that it is advantageous to perform operations only on one number.

If k=4k=4, we have several cases, and we need to take the minimum among them. Again, we can perform operations on one number and make it divisible by 44, or we need to perform operations such that there are two even numbers in the array (there is a special case when n=1n=1). To have two even numbers, let's count the number of even numbers in the original array as cntcnt, and if 2≤n2≤n, we can say that the answer is max(0,2−cnt)max(0,2−cnt).

 
### [1883D - In Love](https://codeforces.com/contest/1883/problem/D "Codeforces Round 905 (Div. 3)")

Let's learn how to solve the problem for a fixed set. The claim is that if the answer exists, we can take the segment with the minimum right boundary and the maximum left boundary (let's denote these boundaries as rr and ll). Therefore, if r<lr<l, it is obvious that this pair of segments is suitable for us. Otherwise, all pairs of segments intersect because they have common points in the range l…rl…r.

Now let's maintain all our operations. For this, we can simply store a multiset of left and right boundaries. With the help of this multiset, we can find the minimum and maximum elements of any of these sets in O(1)O(1). The addition and removal operations are also supported by this container.

 
### [1883E - Look Back](https://codeforces.com/contest/1883/problem/E "Codeforces Round 905 (Div. 3)")

Let's come up with a naive solution — we could go from left to right and multiply the element at index ii by 22 until it is greater than or equal to the previous element. But this solution will take a long time, as the numbers can become on the order of 2n2n during the operations.

Let's not explicitly multiply our numbers by 22, but represent each element as the product ai⋅2xiai⋅2xi, where xixi is the power to which we multiplied. Let's say we have calculated the value of xi−1xi−1, and now we want to calculate xixi. We have two cases:

* If ai−1≤aiai−1≤ai: Then we can say that xi=xi−1xi=xi−1 and subtract 11 until xi>0xi>0 and ai−1⋅2≤aiai−1⋅2≤ai.
* If ai−1>aiai−1>ai: Then we can say that xi=xi−1xi=xi−1 and add 11 until ai⋅2<ai−1ai⋅2<ai−1.

 Note that we do not want to change the values of the array aa to avoid getting large numbers later, so we use additional variables for this.

 
### [1883F - You Are So Beautiful](https://codeforces.com/contest/1883/problem/F "Codeforces Round 905 (Div. 3)")

Note that a subarray suits us if alal is the leftmost occurrence of the number alal in the array and arar is the rightmost occurrence of the number arar in the array. Let's create an array brbr filled with zeros and set br=1br=1 if arar is the rightmost occurrence of the number arar in the array (this can be done using sets or dictionaries). Now we need to consider all suitable left boundaries and see how many suitable right boundaries we have on the suffix, either by precomputing a suffix sum or by simply maintaining a variable while traversing from left to right.

 
### [1883G2 - Dances (Hard Version)](https://codeforces.com/contest/1883/problem/G2 "Codeforces Round 905 (Div. 3)")

Let's learn how to solve the problem for a fixed value of a1a1. Notice that we can perform a binary search on the answer. Let's learn how to check if we can remove kk elements from both arrays such that ai<biai<bi holds for the remaining elements. It will be advantageous to sort both arrays, remove the kk largest elements from the first array, and the kk smallest elements from the second array, and then simply check if the condition holds for our pair of arrays. Thus, for a fixed value of a1a1, we can solve the problem in O(nlogn)O(nlogn).

Let f(i)f(i) be the answer to the problem for a1=ia1=i. We make the following observation - there exists a value xx such that: f(1)=f(2)=…=f(x)=f(x+1)−1=f(x+2)−1=…=f(inf)−1f(1)=f(2)=…=f(x)=f(x+1)−1=f(x+2)−1=…=f(inf)−1. Indeed, changing one element of array aa cannot worsen the answer by more than 11. Then, we can use binary search to find this value xx. The overall complexity is O(nlognlogm)O(nlognlogm).

 
### [1887B - Time Travel](../problems/B._Time_Travel.md "Codeforces Round 905 (Div. 1)")

Let dvdv denote the minimum number of moves required to reach vertex vv. Initially, dv=∞dv=∞ for all vertices except 11, where d1=0d1=0. We will gradually mark the vertices for which we know the optimal answer. Similar to Dijkstra's algorithm, at each iteration, we will select the vertex vv with the minimum value of dvdv among the unmarked vertices. We will mark it and relax its neighbors: let (v,u)(v,u) be an edge belonging to record xx, we will find the minimum index ii such that dv<idv<i and ai=xai=x, then du=min(du,i)du=min(du,i). We can find ii using binary search, by saving the indices of occurrences in aa for each time moments. The time complexity of the solution is O(m(logk+logn))O(m(logk+logn)).

 
### [1887C - Minimum Array](../problems/C._Minimum_Array.md "Codeforces Round 905 (Div. 1)")

Let uu be a difference array of an array vv, i.e. u0=v0u0=v0, ui=vi−vi−1ui=vi−vi−1 for all i≥1i≥1. 

Note that minimizing an array is equivalent to minimizing its difference array. Let's see how the difference array changes: when asked, adding the number addadd on the segment [l;r][l;r] only 2 elements are updated in it: addadd is added to the llth index, and addadd is subtracted from the r+1r+1th index.

Let's learn how to compare difference arrays after the jjth and iith queries (j<ij<i). Let's consider an auxiliary array, which is a union of changes in the difference array for all queries with numbers from j+1j+1 to ii inclusive. Consider in this auxiliary array the minimum non-zero element by index. Note that if it is negative, then the difference array after the iith query will be smaller than after the jjth one, and if it is positive, then it will be larger.

Let's go through the queries and maintain the number of the minimum difference array. Let the current minimum difference array after request be number jj. Since changes to the difference array occur only in two indexes, we can maintain them in a dictionary containing changes to the difference array by index. When we want to process the next request, we update the values in the dictionary using two keys. After the change, you need to check the sign of the minimum non-zero element by index:

1. If it is negative, then this means that the current request has updated the minimum, and we clear the dictionary so that we can now store changes relative to this request in it.
2. If it is positive, then we leave the dictionary the same and continue to change it in subsequent queries.

As a result, using the found index of the minimum difference array, we restore the array itself.

 
### [1887D - Split](../problems/D._Split.md "Codeforces Round 905 (Div. 1)")

Let's fix element ii. Let's find all intervals [l,r][l,r] for which this element can be the maximum in the left part of a valid cut. Let xlxl be the nearest element to the left of ii greater than aiai, and xrxr be the nearest element to the right of ii greater than aiai. Then, for ii to be the maximum element in the left part of the cut, the following conditions must be satisfied: {xl<l≤ixr≤r

But these conditions are obviously not enough, as we need to guarantee that all elements in the right part of the cut are greater than all elements in the left part of the cut. However, since i is the maximum element in the left part of the cut, it is sufficient for all elements in the right part of the cut to be greater than ai. Therefore, if yr is the nearest element to the right of xr smaller than ai, then r≤yr.

Thus, element i can be the maximum element in the left part of the cut of interval [l,r] ⟺ the following conditions are satisfied: {xl<l≤ixr≤r<y

For each element i, we can find xl, xr, and y in O(logn) time. This can be done, for example, using a segment tree or std::set if the elements are iterated in ascending order.

It only remains to notice that if we consider the queries [l,r] as points (l,r), then each element i makes all points in some rectangle good. Thus, the problem reduces to checking whether a point lies in one of the rectangles. This is a classic problem that can be solved using sweep line and, for example, a segment tree. We obtained a solution with a time complexity of O(nlogn).

 Tutorial is loading... 
### [1887F - Minimum Segments](../problems/F._Minimum_Segments.md "Codeforces Round 905 (Div. 1)")

Let's consider a sequence a1,a2,…,an. Let nxti be the smallest j>i such that aj=ai, or n+1 if such j does not exist. It is claimed that the characteristic of the sequence can be uniquely determined from the values of nxt1,nxt2,…,nxtn. Let's write down the conditions on nxti that we can obtain from the characteristic r1,r2,…,rn: 

1. nxtn=n+1.
2. If ri=ri+1, then nxti∈[i+1,ri], since the number ai appears on the subsegment [i+1,ri].
3. If ri<ri+1, then nxti=ri+1, since we need to extend the segment to the nearest occurrence of the number ai.
4. For each i>r1, there exists j such that nxtj=i, since the first occurrence of each number is on the subsegment [1,r1].
5. All nxti≤n are distinct, since each element can have at most one nearest equal element on its left.

 These conditions are sufficient, as they can be used to obtain the characteristic equal to r.We want to construct the array nxt that satisfies these conditions.

We have some values of nxti that we already know, as well as values of nxti that should lie in the intervals [i+1,ri+1]. Note that the left and right boundaries of these intervals are non-decreasing, so if condition 4 did not exist, we could greedily assign values to nxti, moving through the intervals in descending order and assigning the largest unused value of nxti that lies in the interval.

Let's fix k as the number of intervals in which we will choose the number n+1. Obviously, it is more advantageous to place n+1 in the k rightmost intervals, as all intervals in which n+1 can be placed are nested within each other. After that, we can greedily assign the largest possible values of nxti to the intervals from right to left, thus obtaining an answer with the maximum number of nxti∈[r1+1,n] for a given k. If we manage to cover all numbers from [r1+1,n], then we have found a suitable sequence nxt.

Thus, we have a solution with O(n2) complexity: we iterate over k and solve it greedily. Let's learn how to optimize it.

Let's find the smallest k for which there is an answer without considering condition 4. Note that as k increases, the number of nxti∈[r1+1,n] obtained by the greedy algorithm does not increase, so it is sufficient to run it for the minimum k and check if condition 4 is satisfied for the obtained greedy algorithm answer for this k.

After we find the array nxt, it is easy to obtain the array a from it.

