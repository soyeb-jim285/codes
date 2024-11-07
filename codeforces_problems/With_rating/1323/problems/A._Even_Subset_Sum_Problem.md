<h1 style='text-align: center;'> A. Even Subset Sum Problem</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

You are given an array $a$ consisting of $n$ positive integers. Find a non-empty subset of its elements such that their sum is even (i.e. divisible by $2$) or determine that there is no such subset.

Both the given array and required subset may contain equal values.

### Input

The first line contains a single integer $t$ ($1 \leq t \leq 100$), number of test cases to solve. Descriptions of $t$ test cases follow.

A description of each test case consists of two lines. The first line contains a single integer $n$ ($1 \leq n \leq 100$), length of array $a$.

The second line contains $n$ integers $a_1, a_2, \ldots, a_n$ ($1 \leq a_i \leq 100$), elements of $a$. The given array $a$ can contain equal values (duplicates).

### Output

For each test case output $-1$ if there is no such subset of elements. Otherwise output positive integer $k$, number of elements in the required subset. Then output $k$ distinct integers ($1 \leq p_i \leq n$), indexes of the chosen elements. If there are multiple solutions output any of them.

## Example

### Input


```text
3
3
1 4 3
1
15
2
3 5
```
### Output


```text
1
2
-1
2
1 2
```
## Note

There are three test cases in the example.

In the first test case, you can choose the subset consisting of only the second element. Its sum is $4$ and it is even.

In the second test case, there is only one non-empty subset of elements consisting of the first element, however sum in it is odd, so there is no solution.

In the third test case, the subset consisting of all array's elements has even sum.



#### Tags 

#800 #NOT OK #brute_force #dp #greedy #implementation 

## Blogs
- [All Contest Problems](../Codeforces_Round_626_(Div._2,_based_on_Moscow_Open_Olympiad_in_Informatics).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
