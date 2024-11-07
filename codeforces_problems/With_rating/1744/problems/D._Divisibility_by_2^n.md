<h1 style='text-align: center;'> D. Divisibility by 2^n</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given an array of positive integers $a_1, a_2, \ldots, a_n$.

Make the product of all the numbers in the array (that is, $a_1 \cdot a_2 \cdot \ldots \cdot a_n$) divisible by $2^n$.

You can perform the following operation as many times as you like:

* select an arbitrary index $i$ ($1 \leq i \leq n$) and replace the value $a_i$ with $a_i=a_i \cdot i$.

You cannot apply the operation repeatedly to a single index. In other words, all selected values of $i$ must be different.

Find the smallest number of operations you need to perform to make the product of all the elements in the array divisible by $2^n$. 
## Note

 that such a set of operations does not always exist.

### Input

The first line of the input contains a single integer $t$ $(1 \leq t \leq 10^4$) — the number test cases.

Then the descriptions of the input data sets follow.

The first line of each test case contains a single integer $n$ ($1 \leq n \leq 2 \cdot 10^5$) — the length of array $a$.

The second line of each test case contains exactly $n$ integers: $a_1, a_2, \ldots, a_n$ ($1 \leq a_i \leq 10^9$).

It is guaranteed that the sum of $n$ values over all test cases in a test does not exceed $2 \cdot 10^5$.

### Output

For each test case, print the least number of operations to make the product of all numbers in the array divisible by $2^n$. If the answer does not exist, print -1.

## Example

### Input


```text
61223 2310 6 11413 17 1 151 1 12 1 1620 7 14 18 3 5
```
### Output

```text

0
1
1
-1
2
1

```
## Note

In the first test case, the product of all elements is initially $2$, so no operations needed.

In the second test case, the product of elements initially equals $6$. We can apply the operation for $i = 2$, and then $a_2$ becomes $2\cdot2=4$, and the product of numbers becomes $3\cdot4=12$, and this product of numbers is divided by $2^n=2^2=4$. 

In the fourth test case, even if we apply all possible operations, we still cannot make the product of numbers divisible by $2^n$  — it will be $(13\cdot1)\cdot(17\cdot2)\cdot(1\cdot3)\cdot(1\cdot4)=5304$, which does not divide by $2^n=2^4=16$.

In the fifth test case, we can apply operations for $i = 2$ and $i = 4$. 



#### Tags 

#1200 #NOT OK #greedy #math #sortings 

## Blogs
- [All Contest Problems](../Codeforces_Round_828_(Div._3).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
