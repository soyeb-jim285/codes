<h1 style='text-align: center;'> E. Fedya the Potter</h1>

<h5 style='text-align: center;'>time limit per test: 2.5 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Fedya loves problems involving data structures. Especially ones about different queries on subsegments. Fedya had a nice array $a_1, a_2, \ldots a_n$ and a beautiful data structure. This data structure, given $l$ and $r$, $1 \le l \le r \le n$, could find the greatest integer $d$, such that $d$ divides each of $a_l$, $a_{l+1}$, ..., $a_{r}$. 

Fedya really likes this data structure, so he applied it to every non-empty contiguous subarray of array $a$, put all answers into the array and sorted it. He called this array $b$. It's easy to see that array $b$ contains $n(n+1)/2$ elements.

After that, Fedya implemented another cool data structure, that allowed him to find sum $b_l + b_{l+1} + \ldots + b_r$ for given $l$ and $r$, $1 \le l \le r \le n(n+1)/2$. Surely, Fedya applied this data structure to every contiguous subarray of array $b$, called the result $c$ and sorted it. Help Fedya find the lower median of array $c$.

Recall that for a sorted array of length $k$ the lower median is an element at position $\lfloor \frac{k + 1}{2} \rfloor$, if elements of the array are enumerated starting from $1$. For example, the lower median of array $(1, 1, 2, 3, 6)$ is $2$, and the lower median of $(0, 17, 23, 96)$ is $17$.

##### Input

First line contains a single integer $n$ — number of elements in array $a$ ($1 \le n \le 50\,000$). 

Second line contains $n$ integers $a_1, a_2, \ldots, a_n$ — elements of the array ($1 \le a_i \le 100\,000$).

##### Output

Print a single integer — the lower median of array $c$.

## Examples

##### Input


```text
2
6 3
```
##### Output


```text
6
```
##### Input


```text
2
8 8
```
##### Output


```text
8
```
##### Input


```text
5
19 16 2 12 15
```
##### Output


```text
12
```
## Note

In the first sample array $b$ is equal to ${3, 3, 6}$, then array $c$ is equal to ${3, 3, 6, 6, 9, 12}$, so the lower median is $6$.

In the second sample $b$ is ${8, 8, 8}$, $c$ is ${8, 8, 8, 16, 16, 24}$, so the lower median is $8$.



#### Tags 

#3400 #NOT OK #binary_search #implementation #math #number_theory 

## Blogs
- [All Contest Problems](../Codeforces_Round_530_(Div._1).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
