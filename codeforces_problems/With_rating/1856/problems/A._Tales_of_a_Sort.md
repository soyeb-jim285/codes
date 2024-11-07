<h1 style='text-align: center;'> A. Tales of a Sort</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Alphen has an array of positive integers $a$ of length $n$.

Alphen can perform the following operation: 

* For all $i$ from $1$ to $n$, replace $a_i$ with $\max(0, a_i - 1)$.

Alphen will perform the above operation until $a$ is sorted, that is $a$ satisfies $a_1 \leq a_2 \leq \ldots \leq a_n$. How many operations will Alphen perform? Under the constraints of the problem, it can be proven that Alphen will perform a finite number of operations.

### Input

Each test contains multiple test cases. The first line of input contains a single integer $t$ ($1 \le t \le 500$) — the number of test cases. The description of the test cases follows.

The first line of each test case contains a single integer $n$ ($2 \le n \le 50$) — the length of the array $a$.

The second line of each test case contains $n$ integers $a_1, a_2, \dots, a_n$ ($1 \le a_i \le 10 ^ 9$) — the elements of the array $a$.

### Output

For each test case, output a single integer — the number of operations that Alphen will perform.

## Example

### Input


```text
731 2 352 1 2 1 243 1 5 427 754 1 3 2 552 3 1 4 531000000000 1 2
```
### Output

```text

0
2
5
0
4
3
1000000000

```
## Note

In the first test case, we have $a=[1,2,3]$. Since $a$ is already sorted, Alphen will not need to perform any operations. So, the answer is $0$.

In the second test case, we have $a=[2,1,2,1,2]$. Since $a$ is not initially sorted, Alphen will perform one operation to make $a=[1,0,1,0,1]$. After performing one operation, $a$ is still not sorted, so Alphen will perform another operation to make $a=[0,0,0,0,0]$. Since $a$ is sorted, Alphen will not perform any other operations. Since Alphen has performed two operations in total, the answer is $2$.



#### Tags 

#800 #OK #implementation 

## Blogs
- [All Contest Problems](../Codeforces_Round_890_(Div._2)_supported_by_Constructor_Institute.md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
