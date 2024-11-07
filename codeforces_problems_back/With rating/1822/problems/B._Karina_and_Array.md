<h1 style='text-align: center;'> B. Karina and Array</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Karina has an array of $n$ integers $a_1, a_2, a_3, \dots, a_n$. She loves multiplying numbers, so she decided that the beauty of a pair of numbers is their product. And the beauty of an array is the maximum beauty of a pair of adjacent elements in the array.

For example, for $n = 4$, $a=[3, 5, 7, 4]$, the beauty of the array is $\max$($3 \cdot 5$, $5 \cdot 7$, $7 \cdot 4$) = $\max$($15$, $35$, $28$) = $35$.

Karina wants her array to be as beautiful as possible. In order to achieve her goal, she can remove some elements (possibly zero) from the array. After Karina removes all elements she wants to, the array must contain at least two elements.

Unfortunately, Karina doesn't have enough time to do all her tasks, so she asks you to calculate the maximum beauty of the array that she can get by removing any number of elements (possibly zero).

## Input

The first line of the input contains an integer $t$ ($1 \le t \le 10^4$) — the number of test cases. 

The description of the test cases follows.

The first line of a test case contains an integer $n$ ($2 \le n \le 2 \cdot 10^5$) — the length of the array $a$.

The second line of a test case contains $n$ integers $a_1, a_2, a_3, \dots, a_n$ ($-10^9 \le a_i \le 10^9$) — the elements of the array $a$.

The sum of all values of $n$ across all test cases does not exceed $2 \cdot 10^5$.

## Output

## Output

 $t$ integers, each of which is the answer to the corresponding test case — the maximum beauty of the array that Karina can get.

## Example

## Input


```

745 0 2 13-1 1 052 0 -1 -4 06-8 4 3 7 1 -960 3 -2 5 -4 -421000000000 9100000007-1 -7 -2 -5 -4 -6 -3
```
## Output


```

10
0
4
72
16
910000000000000000
42

```
## Note

In the first test case of the example, to get the maximum beauty, you need to remove the $2$-nd element.

In the second and third test cases of the example, there is no need to remove any elements to achieve maximum beauty.

In the fourth test case of the example, you need to leave only the first and last elements.



#### tags 

#800 #greedy #math #sortings 