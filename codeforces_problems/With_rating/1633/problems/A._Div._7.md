<h1 style='text-align: center;'> A. Div. 7</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

You are given an integer $n$. You have to change the minimum number of digits in it in such a way that the resulting number does not have any leading zeroes and is divisible by $7$.

If there are multiple ways to do it, print any of them. If the given number is already divisible by $7$, leave it unchanged.

### Input

The first line contains one integer $t$ ($1 \le t \le 990$) — the number of test cases.

Then the test cases follow, each test case consists of one line containing one integer $n$ ($10 \le n \le 999$).

### Output

For each test case, print one integer without any leading zeroes — the result of your changes (i. e. the integer that is divisible by $7$ and can be obtained by changing the minimum possible number of digits in $n$).

If there are multiple ways to apply changes, print any resulting number. If the given number is already divisible by $7$, just print it.

## Example

### Input


```text
34223377
```
### Output

```text

42
28
777

```
## Note

In the first test case of the example, $42$ is already divisible by $7$, so there's no need to change it.

In the second test case of the example, there are multiple answers — $28$, $21$ or $63$.

In the third test case of the example, other possible answers are $357$, $371$ and $378$. 
## Note

 that you cannot print $077$ or $77$.



#### Tags 

#800 #NOT OK #brute_force 

## Blogs
- [All Contest Problems](../Educational_Codeforces_Round_122_(Rated_for_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
