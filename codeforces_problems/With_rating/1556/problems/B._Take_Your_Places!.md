<h1 style='text-align: center;'> B. Take Your Places!</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

 ![](images/549ebf4bcb27ba7116c6285640e66f2baaae595b.png) William has an array of $n$ integers $a_1, a_2, \dots, a_n$. In one move he can swap two neighboring items. Two items $a_i$ and $a_j$ are considered neighboring if the condition $|i - j| = 1$ is satisfied.

William wants you to calculate the minimal number of swaps he would need to perform to make it so that the array does not contain two neighboring items with the same parity.

### Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 10^4$). Description of the test cases follows.

The first line of each test case contains an integer $n$ $(1 \le n \le 10^5)$ which is the total number of items in William's array.

The second line contains $n$ integers $a_1, a_2, \dots, a_n$ $(1 \le a_i \le 10^9)$ which are William's array.

It is guaranteed that the sum of $n$ over all test cases does not exceed $10^5$.

### Output

For each test case output the minimal number of operations needed or $-1$ if it is impossible to get the array to a state when no neighboring numbers have the same parity.

## Example

### Input


```text
5
3
6 6 1
1
9
6
1 1 1 2 2 2
2
8 6
6
6 2 3 4 5 1
```
### Output


```text
1
0
3
-1
2
```
## Note

In the first test case the following sequence of operations would satisfy the requirements: 

1. swap(2, 3). Array after performing the operation: $[6, 1, 6]$

In the second test case the array initially does not contain two neighboring items of the same parity.

In the third test case the following sequence of operations would satisfy the requirements: 

1. swap(3, 4). Array after performing the operation: $[1, 1, 2, 1, 2, 2]$
2. swap(2, 3). Array after performing the operation: $[1, 2, 1, 1, 2, 2]$
3. swap(4, 5). Array after performing the operation: $[1, 2, 1, 2, 1, 2]$

In the fourth test case it is impossible to satisfy the requirements.

In the fifth test case the following sequence of operations would satisfy the requirements: 

1. swap(2, 3). Array after performing the operation: $[6, 3, 2, 4, 5, 1]$
2. swap(4, 5). Array after performing the operation: $[6, 3, 2, 5, 4, 1]$


#### Tags 

#1300 #NOT OK #implementation 

## Blogs
- [All Contest Problems](../Deltix_Round,_Summer_2021_(open_for_everyone,_rated,_Div._1_+_Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
