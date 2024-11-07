<h1 style='text-align: center;'> B. Integers Have Friends</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

British mathematician John Littlewood once said about Indian mathematician Srinivasa Ramanujan that "every positive integer was one of his personal friends."

It turns out that positive integers can also be friends with each other! You are given an array $a$ of distinct positive integers. 

Define a subarray $a_i, a_{i+1}, \ldots, a_j$ to be a friend group if and only if there exists an integer $m \ge 2$ such that $a_i \bmod m = a_{i+1} \bmod m = \ldots = a_j \bmod m$, where $x \bmod y$ denotes the remainder when $x$ is divided by $y$.

Your friend Gregor wants to know the size of the largest friend group in $a$.

### Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 2\cdot 10^4$). 

Each test case begins with a line containing the integer $n$ ($1 \le n \le 2 \cdot 10^5$), the size of the array $a$.

The next line contains $n$ positive integers $a_1, a_2, \ldots, a_n$ ($1 \le a_i \le {10}^{18}$), representing the contents of the array $a$. It is guaranteed that all the numbers in $a$ are distinct.

It is guaranteed that the sum of $n$ over all test cases is less than $2\cdot 10^5$.

### Output

Your output should consist of $t$ lines. Each line should consist of a single integer, the size of the largest friend group in $a$.

## Example

### Input


```text
4
5
1 5 2 4 6
4
8 2 5 10
2
1000 2000
8
465 55 3 54 234 12 45 78
```
### Output


```text
3
3
2
6
```
## Note

In the first test case, the array is $[1,5,2,4,6]$. The largest friend group is $[2,4,6]$, since all those numbers are congruent to $0$ modulo $2$, so $m=2$.

In the second test case, the array is $[8,2,5,10]$. The largest friend group is $[8,2,5]$, since all those numbers are congruent to $2$ modulo $3$, so $m=3$.

In the third case, the largest friend group is $[1000,2000]$. There are clearly many possible values of $m$ that work.



#### Tags 

#1800 #NOT OK #binary_search #data_structures #divide_and_conquer #math #number_theory #two_pointers 

## Blogs
- [All Contest Problems](../Codeforces_Round_736_(Div._1).md)
- [Codeforces Round #736 (en)](../blogs/Codeforces_Round_736_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
