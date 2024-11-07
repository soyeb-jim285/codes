<h1 style='text-align: center;'> B. Array Cloning Technique</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given an array $a$ of $n$ integers. Initially there is only one copy of the given array.

You can do operations of two types:

1. Choose any array and clone it. After that there is one more copy of the chosen array.
2. Swap two elements from any two copies (maybe in the same copy) on any positions.

You need to find the minimal number of operations needed to obtain a copy where all elements are equal.

### Input

The input consists of multiple test cases. The first line contains a single integer $t$ ($1 \le t \le 10^4$) — the number of test cases. Description of the test cases follows.

The first line of each test case contains a single integer $n$ ($1 \le n \le 10^5$) — the length of the array $a$.

The second line of each test case contains $n$ integers $a_1, a_2, \ldots, a_n$ ($-10^9 \le a_i \le 10^9$) — the elements of the array $a$.

It is guaranteed that the sum of $n$ over all test cases does not exceed $10^5$.

### Output

For each test case output a single integer — the minimal number of operations needed to create at least one copy where all elements are equal.

## Example

### Input


```text
61178960 1 3 3 7 02-1000000000 100000000044 3 2 152 5 7 6 371 1 1 1 1 1 1
```
### Output

```text

0
6
2
5
7
0

```
## Note

In the first test case all elements in the array are already equal, that's why the answer is $0$.

In the second test case it is possible to create a copy of the given array. After that there will be two identical arrays:

$[ \ 0 \ 1 \ 3 \ 3 \ 7 \ 0 \ ]$ and $[ \ 0 \ 1 \ 3 \ 3 \ 7 \ 0 \ ]$

After that we can swap elements in a way so all zeroes are in one array:

$[ \ 0 \ \underline{0} \ \underline{0} \ 3 \ 7 \ 0 \ ]$ and $[ \ \underline{1} \ 1 \ 3 \ 3 \ 7 \ \underline{3} \ ]$

Now let's create a copy of the first array:

$[ \ 0 \ 0 \ 0 \ 3 \ 7 \ 0 \ ]$, $[ \ 0 \ 0 \ 0 \ 3 \ 7 \ 0 \ ]$ and $[ \ 1 \ 1 \ 3 \ 3 \ 7 \ 3 \ ]$

Let's swap elements in the first two copies:

$[ \ 0 \ 0 \ 0 \ \underline{0} \ \underline{0} \ 0 \ ]$, $[ \ \underline{3} \ \underline{7} \ 0 \ 3 \ 7 \ 0 \ ]$ and $[ \ 1 \ 1 \ 3 \ 3 \ 7 \ 3 \ ]$.

Finally, we made a copy where all elements are equal and made $6$ operations.

It can be proven that no fewer operations are enough.



#### Tags 

#900 #NOT OK #constructive_algorithms #greedy #sortings 

## Blogs
- [All Contest Problems](../Codeforces_Round_781_(Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial](../blogs/Tutorial.md)
