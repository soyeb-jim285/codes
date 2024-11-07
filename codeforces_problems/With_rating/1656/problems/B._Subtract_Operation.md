<h1 style='text-align: center;'> B. Subtract Operation</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given a list of $n$ integers. You can perform the following operation: you choose an element $x$ from the list, erase $x$ from the list, and subtract the value of $x$ from all the remaining elements. Thus, in one operation, the length of the list is decreased by exactly $1$.

Given an integer $k$ ($k>0$), find if there is some sequence of $n-1$ operations such that, after applying the operations, the only remaining element of the list is equal to $k$.

### Input

The input consists of multiple test cases. The first line contains a single integer $t$ ($1 \leq t \leq 10^4$) — the number of test cases. Description of the test cases follows.

The first line of each test case contains two integers $n$ and $k$ ($2 \leq n \leq 2\cdot 10^5$, $1 \leq k \leq 10^9$), the number of integers in the list, and the target value, respectively.

The second line of each test case contains the $n$ integers of the list $a_1, a_2, \ldots, a_n$ ($-10^9 \leq a_i \leq 10^9$).

It is guaranteed that the sum of $n$ over all test cases is not greater that $2 \cdot 10^5$.

### Output

For each test case, print YES if you can achieve $k$ with a sequence of $n-1$ operations. Otherwise, print NO.

You may print each letter in any case (for example, "YES", "Yes", "yes", "yEs" will all be recognized as a positive answer).

## Example

### Input


```text
44 54 2 2 75 41 9 1 3 42 1717 02 1718 18
```
### Output

```text

YES
NO
YES
NO

```
## Note

In the first example we have the list $\{4, 2, 2, 7\}$, and we have the target $k = 5$. One way to achieve it is the following: first we choose the third element, obtaining the list $\{2, 0, 5\}$. Next we choose the first element, obtaining the list $\{-2, 3\}$. Finally, we choose the first element, obtaining the list $\{5\}$. 



#### Tags 

#1100 #NOT OK #data_structures #greedy #math #two_pointers 

## Blogs
- [All Contest Problems](../CodeTON_Round_1_(Div._1_+_Div._2,_Rated,_Prizes!).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
