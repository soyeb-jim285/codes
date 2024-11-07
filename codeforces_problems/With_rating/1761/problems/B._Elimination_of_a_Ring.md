<h1 style='text-align: center;'> B. Elimination of a Ring</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Define a cyclic sequence of size $n$ as an array $s$ of length $n$, in which $s_n$ is adjacent to $s_1$.

Muxii has a ring represented by a cyclic sequence $a$ of size $n$.

However, the ring itself hates equal adjacent elements. So if two adjacent elements in the sequence are equal at any time, one of them will be erased immediately. The sequence doesn't contain equal adjacent elements initially.

Muxii can perform the following operation until the sequence becomes empty:

* Choose an element in $a$ and erase it.

For example, if ring is $[1, 2, 4, 2, 3, 2]$, and Muxii erases element $4$, then ring would erase one of the elements equal to $2$, and the ring will become $[1, 2, 3, 2]$.

Muxii wants to find the maximum number of operations he could perform.

## Note

 that in a ring of size $1$, its only element isn't considered adjacent to itself (so it's not immediately erased).

### Input

Each test contains multiple test cases. The first line contains a single integer $t$ ($1\leq t\leq 100$) — the number of test cases. The description of test cases follows.

The first line of each test case contains a single integer $n$ ($1\leq n\leq 100$) — the size of the cyclic sequence.

The second line of each test case contains $n$ integers $a_1,a_2,\ldots,a_n$ ($1\leq a_i\leq n$) — the sequence itself.

It's guaranteed that $a_i\ne a_{i+1}$ for $1\leq i<n$.

It's guaranteed that $a_n\ne a_1$ when $n>1$.

### Output

For each test case, output a single integer — the maximum number of operations Muxii can perform.

## Example

### Input


```text
341 2 3 241 2 1 211
```
### Output

```text

4
3
1

```
## Note

In the first test case, you can erase the second element first, then erase the remaining elements one by one in any order. In total, you can perform the operation $4$ times. 
## Note

 that if you erase the first element first, then the sequence will be turned into $[2,3,2]$ and then immediately become $[2,3]$.

In the second test case, you can erase the first element first, then the sequence becomes $[2,1]$. Then you can erase all remaining elements one by one in any order.



#### Tags 

#1000 #OK #constructive_algorithms #greedy #implementation 

## Blogs
- [All Contest Problems](../Pinely_Round_1_(Div._1_+_Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
