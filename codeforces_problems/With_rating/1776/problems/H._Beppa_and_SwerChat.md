<h1 style='text-align: center;'> H. Beppa and SwerChat</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Beppa and her circle of geek friends keep up to date on a group chat in the instant messaging app SwerChat$^{\text{TM}}$.

The group has $n$ members, excluding Beppa. Each of those members has a unique ID between $1$ and $n$. When a user opens a group chat, SwerChat$^{\text{TM}}$ displays the list of other members of that group, sorted by decreasing times of last seen online (so the member who opened the chat most recently is the first of the list). However, the times of last seen are not displayed.

Today, Beppa has been busy all day: she has only opened the group chat twice, once at 9:00 and once at 22:00. Both times, she wrote down the list of members in the order they appeared at that time. Now she wonders: what is the minimum number of other members that must have been online at least once between 9:00 and 22:00?

Beppa is sure that no two members are ever online at the same time and no members are online when Beppa opens the group chat at 9:00 and 22:00.

### Input

Each test contains multiple test cases. The first line contains an integer $t$ ($1 \leq t \leq 10\,000$) — the number of test cases. The descriptions of the $t$ test cases follow.

The first line of each test case contains an integer $n$ ($1 \leq n \leq 10^5$) — the number of members of the group excluding Beppa.

The second line contains $n$ integers $a_1, \, a_2, \, \dots, \, a_n$ ($1 \le a_i \le n$) — the list of IDs of the members, sorted by decreasing times of last seen online at 9:00.

The third line contains $n$ integers $b_1, \, b_2, \, \dots, \, b_n$ ($1 \le b_i \le n$) — the list of IDs of the members, sorted by decreasing times of last seen online at 22:00.

For all $1\le i < j\le n$, it is guaranteed that $a_i \ne a_j$ and $b_i \ne b_j$.

It is also guaranteed that the sum of the values of $n$ over all test cases does not exceed $10^5$.

### Output

For each test case, print the minimum number of members that must have been online between 9:00 and 22:00.

## Example

### Input


```text
451 4 2 5 34 5 1 2 361 2 3 4 5 61 2 3 4 5 688 2 4 7 1 6 5 35 6 1 4 8 2 7 3111
```
### Output

```text

2
0
4
0

```
## Note

In the first test case, members $4, 5$ must have been online between 9:00 and 22:00.

In the second test case, it is possible that nobody has been online between 9:00 and 22:00.



#### Tags 

#1300 #NOT OK #two_pointers 

## Blogs
- [All Contest Problems](../SWERC_2022-2023_-_Online_Mirror_(Unrated,_ICPC_Rules,_Teams_Preferred).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
