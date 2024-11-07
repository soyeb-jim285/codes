<h1 style='text-align: center;'> A. Ian and Array Sorting</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

To thank Ian, Mary gifted an array $a$ of length $n$ to Ian. To make himself look smart, he wants to make the array in non-decreasing order by doing the following finitely many times: he chooses two adjacent elements $a_i$ and $a_{i+1}$ ($1\le i\le n-1$), and increases both of them by $1$ or decreases both of them by $1$. ## Note

 that, the elements of the array can become negative.

As a smart person, you notice that, there are some arrays such that Ian cannot make it become non-decreasing order! Therefore, you decide to write a program to determine if it is possible to make the array in non-decreasing order.

## Input

The first line contains a single integer $t$ ($1 \leq t \leq 10^4$) — the number of test cases. The description of test cases follows.

The first line of each test case consists of a single integer $n$ ($2\le n\le 3\cdot10^5$) — the number of elements in the array.

The second line of each test case contains $n$ integers $a_1,a_2,\ldots,a_n$ ($1\le a_i\le 10^9$) — the elements of the array $a$.

It is guaranteed that the sum of $n$ over all test cases does not exceed $3\cdot10^5$. 

## Output

For each test case, output "YES" if there exists a sequence of operations which make the array non-decreasing, else output "NO".

You may print each letter in any case (for example, "YES", "Yes", "yes", "yEs" will all be recognized as positive answer).

## Example

## Input


```

531 3 222 141 3 5 742 1 4 355 4 3 2 1
```
## Output


```

YES
NO
YES
NO
YES

```
## Note

For the first test case, we can increase $a_2$ and $a_3$ both by $1$. The array is now $[1, 4, 3]$.

Then we can decrease $a_1$ and $a_2$ both by $1$. The array is now $[0, 3, 3]$, which is sorted in non-decreasing order. So the answer is "YES".

For the second test case, no matter how Ian perform the operations, $a_1$ will always be larger than $a_2$. So the answer is "NO" and Ian cannot pretend to be smart.

For the third test case, the array is already in non-decreasing order, so Ian does not need to do anything.



#### tags 

#1300 #greedy #math 