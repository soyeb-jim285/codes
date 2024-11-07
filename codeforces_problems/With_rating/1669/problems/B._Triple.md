<h1 style='text-align: center;'> B. Triple</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Given an array $a$ of $n$ elements, print any value that appears at least three times or print -1 if there is no such value.

### Input

The first line contains an integer $t$ ($1 \leq t \leq 10^4$) — the number of test cases.

The first line of each test case contains an integer $n$ ($1 \leq n \leq 2\cdot10^5$) — the length of the array.

The second line of each test case contains $n$ integers $a_1, a_2, \dots, a_n$ ($1 \leq a_i \leq n$) — the elements of the array.

It is guaranteed that the sum of $n$ over all test cases does not exceed $2\cdot10^5$.

### Output

For each test case, print any value that appears at least three times or print -1 if there is no such value.

## Example

### Input


```text
7
1
1
3
2 2 2
7
2 2 3 3 4 2 2
8
1 4 3 4 3 2 4 1
9
1 1 1 2 2 2 3 3 3
5
1 5 2 4 3
4
4 4 4 4
```
### Output


```text
-1
2
2
4
3
-1
4
```
## Note

In the first test case there is just a single element, so it can't occur at least three times and the answer is -1.

In the second test case, all three elements of the array are equal to $2$, so $2$ occurs three times, and so the answer is $2$.

For the third test case, $2$ occurs four times, so the answer is $2$.

For the fourth test case, $4$ occurs three times, so the answer is $4$.

For the fifth test case, $1$, $2$ and $3$ all occur at least three times, so they are all valid outputs.

For the sixth test case, all elements are distinct, so none of them occurs at least three times and the answer is -1.



#### Tags 

#800 #NOT OK #implementation #sortings 

## Blogs
- [All Contest Problems](../Codeforces_Round_784_(Div._4).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
