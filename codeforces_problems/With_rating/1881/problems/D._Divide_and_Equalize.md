<h1 style='text-align: center;'> D. Divide and Equalize</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given an array $a$ consisting of $n$ positive integers. You can perform the following operation on it: 

1. Choose a pair of elements $a_i$ and $a_j$ ($1 \le i, j \le n$ and $i \neq j$);
2. Choose one of the divisors of the integer $a_i$, i.e., an integer $x$ such that $a_i \bmod x = 0$;
3. Replace $a_i$ with $\frac{a_i}{x}$ and $a_j$ with $a_j \cdot x$.

 Determine whether it is possible to make all elements in the array the same by applying the operation a certain number of times (possibly zero).For example, let's consider the array $a$ = [$100, 2, 50, 10, 1$] with $5$ elements. Perform two operations on it: 

1. Choose $a_3 = 50$ and $a_2 = 2$, $x = 5$. Replace $a_3$ with $\frac{a_3}{x} = \frac{50}{5} = 10$, and $a_2$ with $a_2 \cdot x = 2 \cdot 5 = 10$. The resulting array is $a$ = [$100, 10, 10, 10, 1$];
2. Choose $a_1 = 100$ and $a_5 = 1$, $x = 10$. Replace $a_1$ with $\frac{a_1}{x} = \frac{100}{10} = 10$, and $a_5$ with $a_5 \cdot x = 1 \cdot 10 = 10$. The resulting array is $a$ = [$10, 10, 10, 10, 10$].

 After performing these operations, all elements in the array $a$ become equal to $10$.
### Input

The first line of the input contains a single integer $t$ ($1 \le t \le 2000$) — the number of test cases.

Then follows the description of each test case.

The first line of each test case contains a single integer $n$ ($1 \le n \le 10^4$) — the number of elements in the array $a$.

The second line of each test case contains exactly $n$ integers $a_i$ ($1 \le a_i \le 10^6$) — the elements of the array $a$.

It is guaranteed that the sum of $n$ over all test cases does not exceed $10^4$.

### Output

For each test case, output a single line: 

* "YES" if it is possible to make all elements in the array equal by applying the operation a certain (possibly zero) number of times;
* "NO" otherwise.

You can output the answer in any case (for example, the strings "yEs", "yes", "Yes", and "YES" will all be recognized as a positive answer).

## Example

### Input


```text
75100 2 50 10 131 1 148 2 4 2430 50 27 20275 4024 432 3 1
```
### Output

```text

YES
YES
NO
YES
NO
YES
NO

```
## Note

The first test case is explained in the problem statement.



#### Tags 

#1300 #OK #math #number_theory 

## Blogs
- [All Contest Problems](../Codeforces_Round_903_(Div._3).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
