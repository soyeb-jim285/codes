<h1 style='text-align: center;'> C. Light Switches</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

There is an apartment consisting of $n$ rooms, each with its light initially turned off.

To control the lights in these rooms, the owner of the apartment decided to install chips in the rooms so that each room has exactly one chip, and the chips are installed at different times. Specifically, these times are represented by the array $a_1, a_2, \ldots, a_n$, where $a_i$ is the time (in minutes) at which a chip is installed in the $i$-th room.

As soon as a chip is installed, it changes the room's light status every $k$ minutes — it turns on the light for $k$ minutes, then turns it off for the next $k$ minutes, then turns it back on for the next $k$ minutes, and so on. In other words, the light status is changed by the chip at minute $a_i$, $a_i + k$, $a_i + 2k$, $a_i + 3k$, $\ldots$ for the $i$-th room.

What is the earliest moment when all rooms in the apartment have their lights turned on?

### Input

The first line contains a single integer $t$ ($1 \le t \le 10^4$) — the number of test cases.

The first line of each test case contains two integers $n$ and $k$ ($1 \le k \le n \le 2 \cdot 10^5$) — the number of rooms in the apartment and the period of the chips.

The second line contains $n$ distinct integers $a_1, a_2, \ldots, a_n$ ($1 \le a_i \le 10^9$) — the moments when the chips are installed.

It is guaranteed that the sum of $n$ over all test cases does not exceed $2 \cdot 10^5$.

### Output

For each test case, print a single integer — the answer to the question (in minutes). If there is no such moment that the lights are turned on in all the rooms, print $-1$ instead.

## Example

### Input


```text
94 42 3 4 54 32 3 4 54 33 4 8 93 36 2 11 117 514 34 6 25 46 7 176 540 80 99 60 90 506 564 40 50 68 70 102 11 1000000000
```
### Output

```text

5
-1
10
8
1
47
100
-1
-1

```
## Note

In the first test case, all lights will be on by the minute $5$ without any of them being turned off by the chips. The answer is $5$.

In the second test case, due to $k=3$, the $1$-st light will be on at minutes $2, 3, 4, 8, 9, 10, 14, \ldots$; meanwhile, the $4$-th light will be on at minutes $5, 6, 7, 11, 12, 13, 17, \ldots$. These two sequences don't have any number in common, so they will never be on at the same time.

In the third test case, it can be seen that the $1$-st and $2$-nd lights will be turned off at minutes $6$ and $7$, but the chips will turn them back on at minutes $9$ and $10$. The $3$-rd and $4$-th lights will also be on at minute $10$, so the answer is $10$.



#### Tags 

#NOT OK #implementation #math 

## Blogs
- [All Contest Problems](../Codeforces_Round_963_(Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
