<h1 style='text-align: center;'> D. The Fair Nut's getting crazy</h1>

<h5 style='text-align: center;'>time limit per test: 4 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

The Fair Nut has found an array $a$ of $n$ integers. We call subarray $l \ldots r$ a sequence of consecutive elements of an array with indexes from $l$ to $r$, i.e. $a_l, a_{l+1}, a_{l+2}, \ldots, a_{r-1}, a_{r}$. 

No one knows the reason, but he calls a pair of subsegments good if and only if the following conditions are satisfied:

1. These subsegments should not be nested. That is, each of the subsegments should contain an element (as an index) that does not belong to another subsegment.
2. Subsegments intersect and each element that belongs to the intersection belongs each of segments only once.

For example $a=[1, 2, 3, 5, 5]$. Pairs $(1 \ldots 3; 2 \ldots 5)$ and $(1 \ldots 2; 2 \ldots 3)$) — are good, but $(1 \dots 3; 2 \ldots 3)$ and $(3 \ldots 4; 4 \ldots 5)$ — are not (subsegment $1 \ldots 3$ contains subsegment $2 \ldots 3$, integer $5$ belongs both segments, but occurs twice in subsegment $4 \ldots 5$).

Help the Fair Nut to find out the number of pairs of good subsegments! The answer can be rather big so print it modulo $10^9+7$.

#### Input

The first line contains a single integer $n$ ($1 \le n \le 10^5$) — the length of array $a$.

The second line contains $n$ integers $a_1, a_2, \ldots, a_n$ ($-10^9 \le a_i \le 10^9$) — the array elements.

#### Output

Print single integer — the number of pairs of good subsegments modulo $10^9+7$.

## Examples

#### Input


```text
3  
1 2 3  

```
#### Output


```text
1  

```
#### Input


```text
5  
1 2 1 2 3  

```
#### Output


```text
4  

```
## Note

In the first example, there is only one pair of good subsegments: $(1 \ldots 2, 2 \ldots 3)$.

In the second example, there are four pairs of good subsegments: 

* $(1 \ldots 2, 2 \ldots 3)$
* $(2 \ldots 3, 3 \ldots 4)$
* $(2 \ldots 3, 3 \ldots 5)$
* $(3 \ldots 4, 4 \ldots 5)$


#### Tags 

#3500 #NOT OK #data_structures #implementation 

## Blogs
- [All Contest Problems](../Codeforces_Round_526_(Div._1).md)
- [Codeforces Round #526](../blogs/Codeforces_Round_526.md)
- [63753 (en)](../blogs/63753_(en).md)
- [63753 (ru)](../blogs/63753_(ru).md)
