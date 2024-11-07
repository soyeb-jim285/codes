<h1 style='text-align: center;'> E. Non-Decreasing Dilemma</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Alice has recently received an array $a_1, a_2, \dots, a_n$ for her birthday! She is very proud of her array, and when she showed her friend Bob the array, he was very happy with her present too!

However, soon Bob became curious, and as any sane friend would do, asked Alice to perform $q$ operations of two types on her array:

* $1$ $x$ $y$: update the element $a_x$ to $y$ (set $a_x = y$).
* $2$ $l$ $r$: calculate how many non-decreasing subarrays exist within the subarray $[a_l, a_{l+1}, \dots, a_r]$. More formally, count the number of pairs of integers $(p,q)$ such that $l \le p \le q \le r$ and $a_p \le a_{p+1} \le \dots \le a_{q-1} \le a_q$.

Help Alice answer Bob's queries!

### Input

The first line contains two integers $n$ and $q$ ($1 \le n, q \le 2 \cdot 10^5$) — the size of the array, and the number of queries, respectively.

The second line contains $n$ integers $a_1, a_2, \dots, a_n$ ($1 \le a_i \le 10^9$) — the elements of Alice's array.

The next $q$ lines consist of three integers each. The first integer of the $i$-th line is $t_i$, the operation being performed on the $i$-th step ($t_i = 1$ or $t_i = 2$).

If $t_i = 1$, the next two integers are $x_i$ and $y_i$ ($1 \le x_i \le n$; $1 \le y_i \le 10^9$), updating the element at position $x_i$ to $y_i$ (setting $a_{x_i} = y_i$).

If $t_i = 2$, the next two integers are $l_i$ and $r_i$ ($1 \le l_i \le r_i \le n$), the two indices Bob asks Alice about for the $i$-th query.

It's guaranteed that there is at least one operation of the second type.

### Output

For each query of type $2$, print a single integer, the answer to the query.

## Example

### Input


```text
5 6
3 1 4 1 5
2 2 5
2 1 3
1 4 4
2 2 5
1 2 6
2 2 5
```
### Output


```text
6
4
10
7
```
## Note

For the first query, $l = 2$ and $r = 5$, and the non-decreasing subarrays $[p,q]$ are $[2,2]$, $[3,3]$, $[4,4]$, $[5,5]$, $[2,3]$ and $[4,5]$.



#### Tags 

#2200 #NOT OK #data_structures #divide_and_conquer #math 

## Blogs
- [All Contest Problems](../Codeforces_Round_742_(Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
