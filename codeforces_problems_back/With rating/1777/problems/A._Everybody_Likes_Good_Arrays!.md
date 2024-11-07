<h1 style='text-align: center;'> A. Everybody Likes Good Arrays!</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

An array $a$ is good if for all pairs of adjacent elements, $a_i$ and $a_{i+1}$ ($1\le i \lt n$) are of different parity. ## Note

 that an array of size $1$ is trivially good.

You are given an array of size $n$. 

In one operation you can select any pair of adjacent elements in which both elements are of the same parity, delete them, and insert their product in the same position.

Find the minimum number of operations to form a good array.

## Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 500$). The description of the test cases follows.

The first line of each test case contains an integer $n$ ($1 \le n \le 100$).

The second line of each test case contains $n$ integers $a_1,a_2,\ldots,a_n$ ($1 \le a_i \le 10^{9}$).

## Output

For each test case print an integer, the minimum number of operations required to form a good array.

## Example

## Input


```

351 7 11 2 1341 2 3 461 1 1 2 2 3
```
## Output


```

2
0
3

```
## Note

Consider the first test case. Select the $2$-nd and the $3$-rd integers and apply the operation on them. The array changes from $[1, \color{red}{7}, \color{red}{11}, 2, 13]$ to $[1, \color{red}{77}, 2, 13]$. Next, select the $1$-st and the $2$-nd integers, array changes from $[\color{red}{1}, \color{red}{77}, 2, 13]$ to $[\color{red}{77}, 2, 13]$. Thus we require $2$ operations. It can be proved that this is the minimum number of operations.

In the second test case, the given array is already good. So we require $0$ operations.



#### tags 

#800 #greedy #math 