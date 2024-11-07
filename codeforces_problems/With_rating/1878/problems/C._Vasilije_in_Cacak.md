<h1 style='text-align: center;'> C. Vasilije in Cacak</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Aca and Milovan, two fellow competitive programmers, decided to give Vasilije a problem to test his skills.

Vasilije is given three positive integers: $n$, $k$, and $x$, and he has to determine if he can choose $k$ distinct integers between $1$ and $n$, such that their sum is equal to $x$.

Since Vasilije is now in the weirdest city in Serbia where Aca and Milovan live, Cacak, the problem seems weird to him. So he needs your help with this problem.

### Input

The first line contains a single integer $t$ ($1 \le t \le 10^4$) — the number of test cases.

The only line of each test case contains three integers $n$, $k$ and $x$ ($1 \le n \le 2 \cdot 10^5$, $1 \le k \le n$, $1 \le x \le 4 \cdot 10^{10}$) — the maximum element he can choose, the number of elements he can choose and the sum he has to reach.

## Note

 that the sum of $n$ over all test cases may exceed $2 \cdot 10^5$.

### Output

For each test case output one line: "YES", if it is possible to choose $k$ distinct integers between $1$ and $n$, such that their sum is equal to $x$, and "NO", if it isn't. 

You can output the answer in any case (for example, the strings "yEs", "yes", "Yes", and "YES" will be recognized as a positive answer).

## Example

### Input


```text
125 3 105 3 310 10 556 5 202 1 26187856 87856 2609202300200000 190000 1900000000028 5 20042 2 20069 6 4047202 32455 613407217185977 145541 15770805980
```
### Output

```text

YES
NO
YES
YES
NO
NO
YES
NO
NO
NO
YES
YES

```
## Note

In the first test case $n = 5,\ k=3,\ x=10$, so we can choose the numbers: $2$, $3$, $5$, whose sum is $10$, so the answer is "YES".

In the second test case $n = 5, \ k=3, \ x=3$, there is no three numbers which satisfies the condition, so the answer is "NO". It can be shown that there are no three numbers whose sum is $3$.



#### Tags 

#900 #OK #math 

## Blogs
- [All Contest Problems](../Codeforces_Round_900_(Div._3).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
