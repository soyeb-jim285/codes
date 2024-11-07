<h1 style='text-align: center;'> F. Vika and Wiki</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Recently, Vika was studying her favorite internet resource - Wikipedia.

On the expanses of Wikipedia, she read about an interesting mathematical operation [bitwise XOR](https://en.wikipedia.org/wiki/Bitwise_operation#XOR), denoted by $\oplus$. 

Vika began to study the properties of this mysterious operation. To do this, she took an array $a$ consisting of $n$ non-negative integers and applied the following operation to all its elements at the same time: $a_i = a_i \oplus a_{(i+1) \bmod n}$. Here $x \bmod y$ denotes the remainder of dividing $x$ by $y$. The elements of the array are numbered starting from $0$.

Since it is not enough to perform the above actions once for a complete study, Vika repeats them until the array $a$ becomes all zeros.

Determine how many of the above actions it will take to make all elements of the array $a$ zero. If this moment never comes, output $-1$.

###### Input

The first line contains a single integer $n$ ($1 \le n \le 2^{20}$) - the length of the array $a$.

It is guaranteed that $n$ can be represented as $2^k$ for some integer $k$ ($0 \le k \le 20$).

The second line contains $n$ integers $a_0, a_1, a_2, \dots, a_{n-1}$ ($0 \le a_i \le 10^9$) - the elements of the array $a$.

###### Output

###### Output

 a single number - the minimum number of actions required to make all elements of the array $a$ zero, or $-1$ if the array $a$ will never become zero.

## Examples

###### Input


```text
4
1 2 1 2
```
###### Output


```text
2
```
###### Input


```text
2
0 0
```
###### Output


```text
0
```
###### Input


```text
1
14
```
###### Output


```text
1
```
###### Input


```text
8
0 1 2 3 4 5 6 7
```
###### Output


```text
5
```
## Note

In the first example, after one operation, the array $a$ will become equal to $[3, 3, 3, 3]$. After one more operation, it will become equal to $[0, 0, 0, 0]$.

In the second example, the array $a$ initially consists only of zeros.

In the third example, after one operation, the array $a$ will become equal to $[0]$.



#### Tags 

#2400 #NOT OK #binary_search #bitmasks #combinatorics #divide_and_conquer #dp #math 

## Blogs
- [All Contest Problems](../Codeforces_Round_885_(Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial](../blogs/Tutorial.md)
