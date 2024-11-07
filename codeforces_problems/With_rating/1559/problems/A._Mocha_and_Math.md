<h1 style='text-align: center;'> A. Mocha and Math</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Mocha is a young girl from high school. She has learned so much interesting knowledge from her teachers, especially her math teacher. Recently, Mocha is learning about binary system and very interested in bitwise operation.

This day, Mocha got a sequence $a$ of length $n$. In each operation, she can select an arbitrary interval $[l, r]$ and for all values $i$ ($0\leq i \leq r-l$), replace $a_{l+i}$ with $a_{l+i} \,\\&\, a_{r-i}$ at the same time, where $\\&$ denotes the [bitwise AND operation](https://en.wikipedia.org/wiki/Bitwise_operation#AND). This operation can be performed any number of times.

For example, if $n=5$, the array is $[a_1,a_2,a_3,a_4,a_5]$, and Mocha selects the interval $[2,5]$, then the new array is $[a_1,a_2\,\\&\, a_5, a_3\,\\&\, a_4, a_4\,\\&\, a_3, a_5\,\\&\, a_2]$.

Now Mocha wants to minimize the maximum value in the sequence. As her best friend, can you help her to get the answer?

### Input

Each test contains multiple test cases. 

The first line contains a single integer $t$ ($1 \le t \le 100$) — the number of test cases. Each test case consists of two lines.

The first line of each test case contains a single integer $n$ ($1 \le n \le 100$) — the length of the sequence.

The second line of each test case contains $n$ integers $a_1, a_2, \ldots, a_n$ ($0 \le a_i \le 10^9$).

### Output

For each test case, print one integer — the minimal value of the maximum value in the sequence.

## Example

### Input


```text
4
2
1 2
3
1 1 3
4
3 11 3 7
5
11 7 15 3 7
```
### Output


```text
0
1
3
3
```
## Note

In the first test case, Mocha can choose the interval $[1,2]$, then the sequence becomes $[ 0, 0]$, where the first element is $1\,\\&\,2$, and the second element is $2\,\\&\,1$.

In the second test case, Mocha can choose the interval $[1,3]$, then the sequence becomes $[ 1,1,1]$, where the first element is $1\,\\&\,3$, the second element is $1\,\\&\,1$, and the third element is $3\,\\&\,1$.



#### Tags 

#900 #NOT OK #bitmasks #constructive_algorithms #math 

## Blogs
- [All Contest Problems](../Codeforces_Round_738_(Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en) (en)](../blogs/Tutorial_(en)_(en).md)
