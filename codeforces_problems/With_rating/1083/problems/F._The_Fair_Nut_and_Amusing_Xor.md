<h1 style='text-align: center;'> F. The Fair Nut and Amusing Xor</h1>

<h5 style='text-align: center;'>time limit per test: 4 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

The Fair Nut has two arrays $a$ and $b$, consisting of $n$ numbers. He found them so long ago that no one knows when they came to him.

The Fair Nut often changes numbers in his arrays. He also is interested in how similar $a$ and $b$ are after every modification.

Let's denote similarity of two arrays as the minimum number of operations to apply to make arrays equal (every operation can be applied for both arrays). If it is impossible, similarity will be equal $-1$.

Per one operation you can choose a subarray with length $k$ ($k$ is fixed), and change every element $a_i$, which belongs to the chosen subarray, to $a_i \oplus x$ ($x$ can be chosen), where $\oplus$ denotes the [bitwise XOR operation](https://en.wikipedia.org/wiki/Bitwise_operation#XOR). 

Nut has already calculated the similarity of the arrays after every modification. Can you do it?

## Note

 that you just need to calculate those values, that is you do not need to apply any operations.

#### Input

The first line contains three numbers $n$, $k$ and $q$ ($1 \le k \le n \le 2 \cdot 10^5$, $0 \le q \le 2 \cdot 10^5$) — the length of the arrays, the length of the subarrays, to which the operations are applied, and the number of queries.

The second line contains $n$ integers $a_1, a_2, \ldots, a_n$ ($0 \le a_i < 2^{14}$) — elements of array $a$.

The third line contains $n$ integers $b_1, b_2, \ldots, b_n$ ($0 \le b_i < 2^{14}$) — elements of array $b$.

Each of the next $q$ lines describes query and contains string $s$ and two integers $p$ and $v$ ($1 \le p \le n$, $0 \le v < 2^{14}$) — array, which this query changes («a» or «b» without quotes), index of changing element and its new value.

#### Output

On the first line print initial similarity of arrays $a$ and $b$.

On the $i$-th of following $q$ lines print similarity of $a$ and $b$ after applying first $i$ modifications.

## Examples

#### Input


```text
3 3 1  
0 4 2  
1 2 3  
b 2 5  

```
#### Output


```text
-1  
1  

```
#### Input


```text
3 2 2  
1 3 2  
0 0 0  
a 1 0  
b 1 1  

```
#### Output


```text
2  
-1  
2  

```
## Note

In the first sample making arrays $[0, 4, 2]$ and $[1, 2, 3]$ is impossible with $k=3$. After the modification, you can apply the operation with $x=1$ to the whole first array (its length is equal to $k$), and it will be equal to the second array.

In order to make arrays equal in the second sample before changes, you can apply operations with $x=1$ on subarray $[1, 2]$ of $a$ and with $x=2$ on subarray $[2, 3]$ of $b$.

After all queries arrays will be equal $[0, 3, 2]$ and $[1, 0, 0]$. The same operations make them equal $[1, 2, 2]$.



#### Tags 

#3300 #NOT OK #data_structures 

## Blogs
- [All Contest Problems](../Codeforces_Round_526_(Div._1).md)
- [Codeforces Round #526](../blogs/Codeforces_Round_526.md)
- [63753 (en)](../blogs/63753_(en).md)
- [63753 (ru)](../blogs/63753_(ru).md)
