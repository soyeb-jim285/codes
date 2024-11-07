<h1 style='text-align: center;'> C. Complex Market Analysis</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

 ![](images/fc4e096d29160a279f12bb060f315eef08ce22b4.png) While performing complex market analysis William encountered the following problem:

For a given array $a$ of size $n$ and a natural number $e$, calculate the number of pairs of natural numbers $(i, k)$ which satisfy the following conditions: 

* $1 \le i, k$
* $i + e \cdot k \le n$.
* Product $a_i \cdot a_{i + e} \cdot a_{i + 2 \cdot e} \cdot \ldots \cdot a_{i + k \cdot e} $ is a prime number.

A prime number (or a prime) is a natural number greater than 1 that is not a product of two smaller natural numbers.

## Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 10\,000$). Description of the test cases follows.

The first line of each test case contains two integers $n$ and $e$ $(1 \le e \le n \le 2 \cdot 10^5)$, the number of items in the array and number $e$, respectively.

The second line contains $n$ integers $a_1, a_2, \dots, a_n$ $(1 \le a_i \le 10^6)$, the contents of the array.

It is guaranteed that the sum of $n$ over all test cases does not exceed $2 \cdot 10^5$.

## Output

For each test case output the answer in the following format:

## Output

 one line containing the number of pairs of numbers $(i, k)$ which satisfy the conditions.

## Example

## Input


```

6
7 3
10 2 1 3 1 19 3
3 2
1 13 1
9 3
2 4 2 1 1 1 1 4 2
3 1
1 1 1
4 1
1 2 1 1
2 2
1 2

```
## Output


```

2
0
4
0
5
0

```
## Note

In the first example test case two pairs satisfy the conditions: 

1. $i = 2, k = 1$, for which the product is: $a_{2} \cdot a_{5} = 2$ which is a prime number.
2. $i = 3, k = 1$, for which the product is: $a_{3} \cdot a_{6} = 19$ which is a prime number.

In the second example test case there are no pairs that satisfy the conditions.

In the third example test case four pairs satisfy the conditions: 

1. $i = 1, k = 1$, for which the product is: $a_{1} \cdot a_{4} = 2$ which is a prime number.
2. $i = 1, k = 2$, for which the product is: $a_{1} \cdot a_{4} \cdot a_{7} = 2$ which is a prime number.
3. $i = 3, k = 1$, for which the product is: $a_{3} \cdot a_{6} = 2$ which is a prime number.
4. $i = 6, k = 1$, for which the product is: $a_{6} \cdot a_{9} = 2$ which is a prime number.

In the fourth example test case there are no pairs that satisfy the conditions.

In the fifth example test case five pairs satisfy the conditions: 

1. $i = 1, k = 1$, for which the product is: $a_{1} \cdot a_{2} = 2$ which is a prime number.
2. $i = 1, k = 2$, for which the product is: $a_{1} \cdot a_{2} \cdot a_{3} = 2$ which is a prime number.
3. $i = 1, k = 3$, for which the product is: $a_{1} \cdot a_{2} \cdot a_{3} \cdot a_{4} = 2$ which is a prime number.
4. $i = 2, k = 1$, for which the product is: $a_{2} \cdot a_{3} = 2$ which is a prime number.
5. $i = 2, k = 2$, for which the product is: $a_{2} \cdot a_{3} \cdot a_{4} = 2$ which is a prime number.

In the sixth example test case there are no pairs that satisfy the conditions.



#### tags 

#1400 #binary_search #dp #implementation #number_theory #schedules #two_pointers 