<h1 style='text-align: center;'> A. Insert Digit</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You have a positive number of length $n$ and one additional digit.

You can insert this digit anywhere in the number, including at the beginning or at the end.

Your task is to make the result as large as possible.

For example, you have the number $76543$, and the additional digit is $4$. Then the maximum number you can get is $765443$, and it can be obtained in two ways — by inserting a digit after the $3$th or after the $4$th digit of the number.

### Input

The first line contains a single integer $t$ ($1 \le t \le 10^4$) — the number of test cases.

The descriptions of the test cases follow.

The first line of the description of each test case contains two integers $n$ and $d$ ($1 \le n \le 2 \cdot 10^5$; $0 \le d \le 9$) — the length of the number and an additional digit, respectively.

The second line of the description of each test case contains a string consisting of $n$ digits — the number that you have initially. It is guaranteed that the number does not contain leading zeros.

It is guaranteed that the sum of $n$ for all test cases does not exceed $2 \cdot 10^5$.

### Output

For each test case, output a string consisting of $n + 1$ digits — the maximum possible number that can be obtained.

## Example

### Input


```text
115 4765431 012 5443 66665 6135795 89753119 498765432101234567895 7737378 1200000007 0705895912 1828127127732
```
### Output

```text

765443
10
544
6666
613579
987531
98765443210123456789
773737
210000000
70589590
8281271277321

```


#### Tags 

#800 #OK #greedy #math #strings 

## Blogs
- [All Contest Problems](../Codeforces_Round_863_(Div._3).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
