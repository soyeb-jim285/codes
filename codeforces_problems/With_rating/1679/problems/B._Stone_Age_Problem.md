<h1 style='text-align: center;'> B. Stone Age Problem</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Once upon a time Mike and Mike decided to come up with an outstanding problem for some stage of ROI (rare olympiad in informatics). One of them came up with a problem prototype but another stole the idea and proposed that problem for another stage of the same olympiad. Since then the first Mike has been waiting for an opportunity to propose the original idea for some other contest... Mike waited until this moment!

You are given an array $a$ of $n$ integers. You are also given $q$ queries of two types:

* Replace $i$-th element in the array with integer $x$.
* Replace each element in the array with integer $x$.

After performing each query you have to calculate the sum of all elements in the array.

### Input

The first line contains two integers $n$ and $q$ ($1 \le n, q \le 2 \cdot 10^5$) — the number of elements in the array and the number of queries, respectively.

The second line contains $n$ integers $a_1, \ldots, a_n$ ($1 \le a_i \le 10^9$) — elements of the array $a$.

Each of the following $q$ lines contains a description of the corresponding query. Description begins with integer $t$ ($t \in \{1, 2\}$) which denotes a type of the query:

* If $t = 1$, then two integers $i$ and $x$ are following ($1 \le i \le n$, $1 \le x \le 10^9$) — position of replaced element and it's new value.
* If $t = 2$, then integer $x$ is following ($1 \le x \le 10^9$) — new value of each element in the array.
### Output

Print $q$ integers, each on a separate line. In the $i$-th line print the sum of all elements in the array after performing the first $i$ queries.

## Example

### Input


```text
5 5
1 2 3 4 5
1 1 5
2 10
1 5 11
1 4 1
2 1
```
### Output


```text
19
50
51
42
5
```
## Note

Consider array from the example and the result of performing each query:

1. Initial array is $[1, 2, 3, 4, 5]$.
2. After performing the first query, array equals to $[5, 2, 3, 4, 5]$. The sum of all elements is $19$.
3. After performing the second query, array equals to $[10, 10, 10, 10, 10]$. The sum of all elements is $50$.
4. After performing the third query, array equals to $[10, 10, 10, 10, 11$]. The sum of all elements is $51$.
5. After performing the fourth query, array equals to $[10, 10, 10, 1, 11]$. The sum of all elements is $42$.
6. After performing the fifth query, array equals to $[1, 1, 1, 1, 1]$. The sum of all elements is $5$.


#### Tags 

#1200 #OK #data_structures #implementation 

## Blogs
- [All Contest Problems](../Codeforces_Round_791_(Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
