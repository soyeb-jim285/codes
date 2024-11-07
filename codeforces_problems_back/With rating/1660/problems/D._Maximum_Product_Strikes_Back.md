<h1 style='text-align: center;'> D. Maximum Product Strikes Back</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given an array $a$ consisting of $n$ integers. For each $i$ ($1 \le i \le n$) the following inequality is true: $-2 \le a_i \le 2$.

You can remove any number (possibly $0$) of elements from the beginning of the array and any number (possibly $0$) of elements from the end of the array. You are allowed to delete the whole array.

You need to answer the question: how many elements should be removed from the beginning of the array, and how many elements should be removed from the end of the array, so that the result will be an array whose product (multiplication) of elements is maximal. If there is more than one way to get an array with the maximum product of elements on it, you are allowed to output any of them. 

The product of elements of an empty array (array of length $0$) should be assumed to be $1$.

## Input

The first line of input data contains an integer $t$ ($1 \le t \le 10^4$) —the number of test cases in the test.

Then the descriptions of the input test cases follow.

The first line of each test case description contains an integer $n$ ($1 \le n \le 2 \cdot 10^5$) —the length of array $a$.

The next line contains $n$ integers $a_1, a_2, \dots, a_n$ ($|a_i| \le 2$) — elements of array $a$.

It is guaranteed that the sum of $n$ over all test cases does not exceed $2 \cdot 10^5$.

## Output

For each test case, output two non-negative numbers $x$ and $y$ ($0 \le x + y \le n$) — such that the product (multiplication) of the array numbers, after removing $x$ elements from the beginning and $y$ elements from the end, is maximal.

If there is more than one way to get the maximal product, it is allowed to output any of them. Consider the product of numbers on empty array to be $1$.

## Example

## Input


```

541 2 -1 231 1 -252 0 -2 2 -13-2 -1 -13-1 -2 -2
```
## Output


```

0 2
3 0
2 0
0 1
1 0

```
## Note

In the first case, the maximal value of the product is $2$. Thus, we can either delete the first three elements (obtain array $[2]$), or the last two and one first element (also obtain array $[2]$), or the last two elements (obtain array $[1, 2]$). Thus, in the first case, the answers fit: "3 0", or "1 2", or "0 2".

In the second case, the maximum value of the product is $1$. Then we can remove all elements from the array because the value of the product on the empty array will be $1$. So the answer is "3 0", but there are other possible answers.

In the third case, we can remove the first two elements of the array. Then we get the array: $[-2, 2, -1]$. The product of the elements of the resulting array is $(-2) \cdot 2 \cdot (-1) = 4$. This value is the maximum possible value that can be obtained. Thus, for this case the answer is: "2 0".



#### tags 

#1600 #brute_force #implementation #math #two_pointers 