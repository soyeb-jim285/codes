<h1 style='text-align: center;'> F. Greetings</h1>

<h5 style='text-align: center;'>time limit per test: 5 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

There are $n$ people on the number line; the $i$-th person is at point $a_i$ and wants to go to point $b_i$. For each person, $a_i < b_i$, and the starting and ending points of all people are distinct. (That is, all of the $2n$ numbers $a_1, a_2, \dots, a_n, b_1, b_2, \dots, b_n$ are distinct.) 

All the people will start moving simultaneously at a speed of $1$ unit per second until they reach their final point $b_i$. When two people meet at the same point, they will greet each other once. How many greetings will there be?

## Note

 that a person can still greet other people even if they have reached their final point.

## Input

The first line of the input contains a single integer $t$ ($1 \le t \le 10^4$) — the number of test cases. The description of test cases follows.

The first line of each test case contains a single integer $n$ ($1 \le n \le 2 \cdot 10^5$) — the number of people.

Then $n$ lines follow, the $i$-th of which contains two integers $a_i$ and $b_i$ ($-10^9 \leq a_i < b_i \leq 10^9$) — the starting and ending positions of each person.

For each test case, all of the $2n$ numbers $a_1, a_2, \dots, a_n, b_1, b_2, \dots, b_n$ are distinct.

The sum of $n$ over all test cases does not exceed $2 \cdot 10^5$.

## Output

For each test case, output a single integer denoting the number of greetings that will happen.

## Example

## Input


```

522 31 462 63 94 51 87 10-2 1004-10 10-5 5-12 12-13 135-4 9-2 53 46 78 1041 23 45 67 8
```
## Output


```

1
9
6
4
0

```
## Note

In the first test case, the two people will meet at point $3$ and greet each other.



#### tags 

#1500 #data_structures #divide_and_conquer #sortings 