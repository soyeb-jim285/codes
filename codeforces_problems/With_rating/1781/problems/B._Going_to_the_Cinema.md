<h1 style='text-align: center;'> B. Going to the Cinema</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

A company of $n$ people is planning a visit to the cinema. Every person can either go to the cinema or not. That depends on how many other people will go. Specifically, every person $i$ said: "I want to go to the cinema if and only if at least $a_i$ other people will go, not counting myself". That means that person $i$ will become sad if: 

* they go to the cinema, and strictly less than $a_i$ other people go; or
* they don't go to the cinema, and at least $a_i$ other people go.

In how many ways can a set of people going to the cinema be chosen so that nobody becomes sad?

### Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 10^4$). The description of the test cases follows.

Each test case consists of two lines. The first line contains a single integer $n$ ($2 \le n \le 2 \cdot 10^5$) — the number of people in the company.

The second line contains $n$ integers $a_1, a_2, \ldots, a_n$ ($0 \le a_i \le n - 1$) — integers from peoples' claims.

It is guaranteed that the sum of $n$ over all test cases does not exceed $2 \cdot 10^5$.

### Output

For each test case, print a single integer — the number of different ways to choose a set of people going to the cinema so that nobody becomes sad.

## Example

### Input


```text
421 170 1 2 3 4 5 686 0 3 3 6 7 2 753 0 0 3 3
```
### Output

```text

2
1
3
2

```
## Note

In the first test case, both people want to go to the cinema if and only if the other person goes. There are two valid options: either both people go, or neither of them goes. However, if just one of them goes, both will be sad.

In the second test case, everyone has to go to the cinema. In any other case, someone will be sad.

In the third test case, there are three valid options: person number $2$ goes to the cinema; or persons with indices $2, 3, 4, 7$ go; or all eight people go.



#### Tags 

#1000 #NOT OK #brute_force #greedy #sortings 

## Blogs
- [All Contest Problems](../VK_Cup_2022_-_Отборочный_раунд_(Engine).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
