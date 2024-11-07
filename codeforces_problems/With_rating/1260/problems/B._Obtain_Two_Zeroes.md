<h1 style='text-align: center;'> B. Obtain Two Zeroes</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given two integers $a$ and $b$. You may perform any number of operations on them (possibly zero).

During each operation you should choose any positive integer $x$ and set $a := a - x$, $b := b - 2x$ or $a := a - 2x$, $b := b - x$. 
## Note

 that you may choose different values of $x$ in different operations.

Is it possible to make $a$ and $b$ equal to $0$ simultaneously?

Your program should answer $t$ independent test cases.

### Input

The first line contains one integer $t$ ($1 \le t \le 100$) — the number of test cases.

Then the test cases follow, each test case is represented by one line containing two integers $a$ and $b$ for this test case ($0 \le a, b \le 10^9$).

### Output

For each test case print the answer to it — YES if it is possible to make $a$ and $b$ equal to $0$ simultaneously, and NO otherwise.

You may print every letter in any case you want (so, for example, the strings yEs, yes, Yes and YES will all be recognized as positive answer).

## Example

### Input


```text
3
6 9
1 1
1 2
```
### Output


```text
YES
NO
YES
```
## Note

In the first test case of the example two operations can be used to make both $a$ and $b$ equal to zero:

1. choose $x = 4$ and set $a := a - x$, $b := b - 2x$. Then $a = 6 - 4 = 2$, $b = 9 - 8 = 1$;
2. choose $x = 1$ and set $a := a - 2x$, $b := b - x$. Then $a = 2 - 2 = 0$, $b = 1 - 1 = 0$.


#### Tags 

#1300 #NOT OK #binary_search #math 

## Blogs
- [All Contest Problems](../Educational_Codeforces_Round_77_(Rated_for_Div._2).md)
- [Announcement #1 (en)](../blogs/Announcement_1_(en).md)
- [Announcement #2 (ru) (ru)](../blogs/Announcement_2_(ru)_(ru).md)
- [Tutorial](../blogs/Tutorial.md)
