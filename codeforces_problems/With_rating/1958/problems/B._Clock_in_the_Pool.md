<h1 style='text-align: center;'> B. Clock in the Pool</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are swimming in the pool, and you need to control the time of swimming.

The pool has a clock that cycles between three different modes: showing water temperature, showing air temperature, and showing time. At the start of the $0$-th second it starts showing water temperature, at the start of the $k$-th second it switches to air temperature. At the start of the $2k$-th second, it switches to showing time.

At the start of the $3k$-th second the clock starts showing water temperature again, at the start of the $4k$-th second — air temperature, and so on.

You looked at the clock during the $m$-th second to check the time, but it may be that the clock is not showing time right now. How much time do you have to wait to see the time on the clock?

Answer $t$ independent test cases.

### Input

The first line contains a single integer $t$ ($1 \le t \le 10^4$) — the number of test cases. Next $t$ cases follow.

The first and only line of each test case contains two integers $k$ and $m$ ($1 \le k \le 10^8; 1 \le m \le 10^9$) — the length of the period of the clock and the moment of time you check the clock.

### Output

For each test case, print a single integer — the time you have to wait from the moment $m$ until the moment the clock starts showing the time.

You can assume that you are able to read the time instantly the moment it displays on the clock.

## Example

### Input


```text
51 15 145 1510 11099999999 1000000000
```
### Output

```text

1
0
10
0
99999989

```
## Note

In the first test case, the clock will start showing time during the $2$-nd second, so you have to wait $2 - 1 = 1$ second.

In the second test case, the clock shows time from the $10$-th until the $15$-th second, so during the $14$-th second it shows time, and you don't have to wait.

In the third test case, during the $15$-th second, the clock is already showing water temperature. So you have to wait till the $25$-th second, when the clock starts showing time again. You'll wait $25 - 15 = 10$ seconds.

In the fourth test case, the clock will start showing time at the start of the $110$-th second, so you'll wait $110 - 110 = 0$ seconds.



#### Tags 

#1400 #NOT OK #*special #math 

## Blogs
- [All Contest Problems](../Kotlin_Heroes:_Episode_10.md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial](../blogs/Tutorial.md)
