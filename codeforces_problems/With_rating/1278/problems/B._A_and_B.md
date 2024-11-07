<h1 style='text-align: center;'> B. A and B</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given two integers $a$ and $b$. You can perform a sequence of operations: during the first operation you choose one of these numbers and increase it by $1$; during the second operation you choose one of these numbers and increase it by $2$, and so on. You choose the number of these operations yourself.

For example, if $a = 1$ and $b = 3$, you can perform the following sequence of three operations: 

1. add $1$ to $a$, then $a = 2$ and $b = 3$;
2. add $2$ to $b$, then $a = 2$ and $b = 5$;
3. add $3$ to $a$, then $a = 5$ and $b = 5$.

Calculate the minimum number of operations required to make $a$ and $b$ equal. 

### Input

The first line contains one integer $t$ ($1 \le t \le 100$) — the number of test cases.

The only line of each test case contains two integers $a$ and $b$ ($1 \le a, b \le 10^9$).

### Output

For each test case print one integer — the minimum numbers of operations required to make $a$ and $b$ equal. 

## Example

### Input


```text
3
1 3
11 11
30 20
```
### Output


```text
3
0
4
```
## Note

First test case considered in the statement.

In the second test case integers $a$ and $b$ are already equal, so you don't need to perform any operations.

In the third test case you have to apply the first, the second, the third and the fourth operation to $b$ ($b$ turns into $20 + 1 + 2 + 3 + 4 = 30$).



#### Tags 

#1500 #NOT OK #greedy #math 

## Blogs
- [All Contest Problems](../Educational_Codeforces_Round_78_(Rated_for_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
