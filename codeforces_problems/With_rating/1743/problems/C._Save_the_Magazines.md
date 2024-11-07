<h1 style='text-align: center;'> C. Save the Magazines</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Monocarp has been collecting rare magazines for quite a while, and now he has decided to sell them. He distributed the magazines between $n$ boxes, arranged in a row. The $i$-th box contains $a_i$ magazines. Some of the boxes are covered with lids, others are not. 

Suddenly it started to rain, and now Monocarp has to save as many magazines from the rain as possible. To do this, he can move the lids between boxes as follows: if the $i$-th box was covered with a lid initially, he can either move the lid from the $i$-th box to the box $(i-1)$ (if it exists), or keep the lid on the $i$-th box. You may assume that Monocarp can move the lids instantly at the same moment, and no lid can be moved more than once. If a box will be covered with a lid after Monocarp moves the lids, the magazines in it will be safe from the rain; otherwise they will soak.

You have to calculate the maximum number of magazines Monocarp can save from the rain.

### Input

The first line contains a single integer $t$ ($1 \le t \le 10^4$) — the number of the testcases.

The first line of each testcase contains a single integer $n$ ($1 \le n \le 2 \cdot 10^5$) — the number of boxes.

The second line contains a string of $n$ characters 0 and/or 1. If the $i$-th character is 1, the $i$-th box is initially covered with a lid. If the $i$-th character is 0, the $i$-th box is initially not covered.

The third line contains a sequence of integers $a_1, a_2, \dots, a_n$ ($1 \le a_i \le 10^4$), where $a_i$ is the number of magazines in the $i$-th box.

The sum of $n$ over all testcases doesn't exceed $2 \cdot 10^5$.

### Output

For each testcase, print one integer — the maximum number of magazines Monocarp can save from the rain.

## Example

### Input


```text
450111010 5 8 9 6601101120 10 9 30 20 1940000100 100 100 100401115 4 5 1
```
### Output

```text

27
80
0
14

```
## Note

In the first testcase of the example, Monocarp can move the lid from the second box to the first box, so the boxes $1$, $3$ and $4$ are covered, and $10 + 8 + 9 = 27$ magazines are saved.

In the second testcase, Monocarp can move the lid from the second box to the first box, then from the third box to the second box, then from the fifth box to the fourth box, and then from the sixth box to the fifth box. The boxes $1$, $2$, $4$ and $5$ will be covered, so $20 + 10 + 30 + 20 = 80$ magazines can be saved.

There are no lids in the third testcase, so it's impossible to save even a single magazine.



#### Tags 

#1100 #OK #constructive_algorithms #dp #greedy 

## Blogs
- [All Contest Problems](../Educational_Codeforces_Round_137_(Rated_for_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
