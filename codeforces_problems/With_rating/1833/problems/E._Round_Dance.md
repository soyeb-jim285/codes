<h1 style='text-align: center;'> E. Round Dance</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

$n$ people came to the festival and decided to dance a few round dances. There are at least $2$ people in the round dance and each person has exactly two neighbors. If there are $2$ people in the round dance then they have the same neighbor on each side.

You decided to find out exactly how many dances there were. But each participant of the holiday remembered exactly one neighbor. Your task is to determine what the minimum and maximum number of round dances could be.

For example, if there were $6$ people at the holiday, and the numbers of the neighbors they remembered are equal $[2, 1, 4, 3, 6, 5]$, then the minimum number of round dances is$1$: 

* $1 - 2 - 3 - 4 - 5 - 6 - 1$

 and the maximum is $3$: * $1 - 2 - 1$
* $3 - 4 - 3$
* $5 - 6 - 5$
### Input

The first line contains a positive number $t$ ($1 \le t \le 10^4$) — the number of test cases. The following is a description of the test cases.

The first line of the description of each test case contains a positive number $n$ ($2 \le n \le 2 \cdot 10^5$) — the number of people at the holiday.

The second line of the description of each test case contains $n$ integers $a_i$ ($1 \le a_i \le n, a_i \neq i$) — the number of the neighbor that the $i$th person remembered.

It is guaranteed that the test cases are correct and corresponds to at least one division of people into round dances.

It is guaranteed that the sum of $n$ for all test cases does not exceed $2 \cdot 10^5$.

### Output

For each test case, output two integers — the minimum and maximum number of round dances that could be.

## Example

### Input


```text
1062 1 4 3 6 562 3 1 5 6 492 3 2 5 6 5 8 9 822 144 3 2 152 3 4 5 165 3 4 1 1 253 5 4 1 266 3 2 5 4 365 1 4 3 4 2
```
### Output

```text

1 3
2 2
1 3
1 1
1 2
1 1
1 1
2 2
1 2
1 1

```


#### Tags 

#1600 #OK #dfs_and_similar #dsu #graphs #shortest_paths 

## Blogs
- [All Contest Problems](../Codeforces_Round_874_(Div._3).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
