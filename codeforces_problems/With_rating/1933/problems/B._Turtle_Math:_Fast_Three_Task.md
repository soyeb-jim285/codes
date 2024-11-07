<h1 style='text-align: center;'> B. Turtle Math: Fast Three Task</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given an array $a_1, a_2, \ldots, a_n$.

In one move, you can perform either of the following two operations:

* Choose an element from the array and remove it from the array. As a result, the length of the array decreases by $1$;
* Choose an element from the array and increase its value by $1$.

You can perform any number of moves. If the current array becomes empty, then no more moves can be made.

Your task is to find the minimum number of moves required to make the sum of the elements of the array $a$ divisible by $3$. It is possible that you may need $0$ moves.

## Note

 that the sum of the elements of an empty array (an array of length $0$) is equal to $0$.

### Input

The first line of the input contains a single integer $t$ ($1 \le t \le 10^4$) — the number of test cases.

The first line of each test case contains a single integer $n$ ($1 \le n \le 10^5$).

The second line of each test case contains $n$ integers $a_1, a_2, \ldots, a_n$ ($1 \le a_i \le 10^4$).

The sum of $n$ over all test cases does not exceed $2 \cdot 10^5$.

### Output

For each test case, output a single integer: the minimum number of moves.

## Example

### Input


```text
842 2 5 431 3 243 7 6 81142 2 4 225 572 4 8 1 9 3 424 10
```
### Output

```text

1
0
0
1
1
2
1
1

```
## Note

In the first test case, initially the array $a = [2, 2, 5, 4]$. One of the optimal ways to make moves is: 

* remove the current $4$th element and get $a = [2, 2, 5]$;

 As a result, the sum of the elements of the array $a$ will be divisible by $3$ (indeed, $a_1 + a_2 + a_3 = 2 + 2 + 5 = 9$).In the second test case, initially, the sum of the array is $1+3+2 = 6$, which is divisible by $3$. Therefore, no moves are required. Hence, the answer is $0$.

In the fourth test case, initially, the sum of the array is $1$, which is not divisible by $3$. By removing its only element, you will get an empty array, so its sum is $0$. Hence, the answer is $1$.



#### Tags 

#800 #NOT OK #implementation #math #number_theory 

## Blogs
- [All Contest Problems](../Codeforces_Round_929_(Div._3).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
