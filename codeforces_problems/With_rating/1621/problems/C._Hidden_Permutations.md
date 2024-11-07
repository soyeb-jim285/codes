<h1 style='text-align: center;'> C. Hidden Permutations</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

This is an interactive problem.

The jury has a permutation $p$ of length $n$ and wants you to guess it. For this, the jury created another permutation $q$ of length $n$. Initially, $q$ is an identity permutation ($q_i = i$ for all $i$).

You can ask queries to get $q_i$ for any $i$ you want. After each query, the jury will change $q$ in the following way: 

* At first, the jury will create a new permutation $q'$ of length $n$ such that $q'_i = q_{p_i}$ for all $i$.
* Then the jury will replace permutation $q$ with pemutation $q'$.

You can make no more than $2n$ queries in order to quess $p$.

### Input

The first line of input contains a single integer $t$ ($1 \leq t \leq 1000$) — the number of test cases.

## Interaction

## Interaction

 in each test case starts after reading the single integer $n$ ($1 \leq n \leq 10^4$) — the length of permutations $p$ and $q$.

To get the value of $q_i$, output the query in the format $?$ $i$ ($1 \leq i \leq n$). After that you will receive the value of $q_i$.

You can make at most $2n$ queries. After the incorrect query you will receive $0$ and you should exit immediately to get Wrong answer verdict.

When you will be ready to determine $p$, output $p$ in format $!$ $p_1$ $p_2$ $\ldots$ $p_n$. After this you should go to the next test case or exit if it was the last test case. Printing the permutation is not counted as one of $2n$ queries.

After printing a query do not forget to output end of line and flush the output. Otherwise, you will get Idleness limit exceeded. To do this, use:

* fflush(stdout) or cout.flush() in C++;
* System.out.flush() in Java;
* flush(output) in Pascal;
* stdout.flush() in Python;
* see documentation for other languages.

It is guaranteed that the sum of $n$ over all test cases doesn't exceed $10^4$. The interactor is not adaptive in this problem.

Hacks:

To hack, use the following format:

The first line contains the single integer $t$ — the number of test cases.

The first line of each test case contains the single integer $n$ — the length of the permutations $p$ and $q$. The second line of each test case contains $n$ integers $p_1, p_2, \ldots, p_n$ — the hidden permutation for this test case.

## Example

### Input


```text

2
4

3

2

1

4

2

4

4
```
#Output
```text

? 3

? 2

? 4

! 4 2 1 3

? 2

? 3

? 2

! 1 3 4 2
```
## Note

In the first test case the hidden permutation $p = [4, 2, 1, 3]$.

Before the first query $q = [1, 2, 3, 4]$ so answer for the query will be $q_3 = 3$.

Before the second query $q = [4, 2, 1, 3]$ so answer for the query will be $q_2 = 2$.

Before the third query $q = [3, 2, 4, 1]$ so answer for the query will be $q_4 = 1$.

In the second test case the hidden permutation $p = [1, 3, 4, 2]$.

Empty strings are given only for better readability. There will be no empty lines in the testing system.



#### Tags 

#1700 #NOT OK #dfs_and_similar #interactive #math 

## Blogs
- [All Contest Problems](../Hello_2022.md)
- [Hello 2022](../blogs/Hello_2022.md)
- [Hello 2022 Editorial (en)](../blogs/Hello_2022_Editorial_(en).md)
