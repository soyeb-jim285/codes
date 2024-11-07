<h1 style='text-align: center;'> B. Equal Candies</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

There are $n$ boxes with different quantities of candies in each of them. The $i$-th box has $a_i$ candies inside.

You also have $n$ friends that you want to give the candies to, so you decided to give each friend a box of candies. But, you don't want any friends to get upset so you decided to eat some (possibly none) candies from each box so that all boxes have the same quantity of candies in them. 
## Note

 that you may eat a different number of candies from different boxes and you cannot add candies to any of the boxes.

What's the minimum total number of candies you have to eat to satisfy the requirements?

### Input

The first line contains an integer $t$ ($1 \leq t \leq 1000$) — the number of test cases.

The first line of each test case contains an integer $n$ ($1 \leq n \leq 50$) — the number of boxes you have.

The second line of each test case contains $n$ integers $a_1, a_2, \dots, a_n$ ($1 \leq a_i \leq 10^7$) — the quantity of candies in each box.

### Output

For each test case, print a single integer denoting the minimum number of candies you have to eat to satisfy the requirements.

## Example

### Input


```text
551 2 3 4 561000 1000 5 1000 1000 1000101 2 3 5 1 2 7 9 13 538 8 8110000000
```
### Output

```text

10
4975
38
0
0

```
## Note

For the first test case, you can eat $1$ candy from the second box, $2$ candies from the third box, $3$ candies from the fourth box and $4$ candies from the fifth box. Now the boxes have $[1, 1, 1, 1, 1]$ candies in them and you ate $0 + 1 + 2 + 3 + 4 = 10$ candies in total so the answer is $10$.

For the second test case, the best answer is obtained by making all boxes contain $5$ candies in them, thus eating $995 + 995 + 0 + 995 + 995 + 995 = 4975$ candies in total.



#### Tags 

#800 #OK #greedy #math #sortings 

## Blogs
- [All Contest Problems](../Codeforces_Round_790_(Div._4).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
