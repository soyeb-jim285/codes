<h1 style='text-align: center;'> E. Distance Learning Courses in MAC</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

The New Year has arrived in the Master's Assistance Center, which means it's time to introduce a new feature!

Now students are given distance learning courses, with a total of $n$ courses available. For the $i$-th distance learning course, a student can receive a grade ranging from $x_i$ to $y_i$.

However, not all courses may be available to each student. Specifically, the $j$-th student is only given courses with numbers from $l_j$ to $r_j$, meaning the distance learning courses with numbers $l_j, l_j + 1, \ldots, r_j$.

The creators of the distance learning courses have decided to determine the final grade in a special way. Let the $j$-th student receive grades $c_{l_j}, c_{l_j + 1}, \ldots, c_{r_j}$ for their distance learning courses. Then their final grade will be equal to $c_{l_j}$ $|$ $c_{l_j + 1}$ $|$ $\ldots$ $|$ $c_{r_j}$, where $|$ denotes the [bitwise OR](https://en.wikipedia.org/wiki/Bitwise_operation#OR) operation.

Since the chatbot for solving distance learning courses is broken, the students have asked for your help. For each of the $q$ students, tell them the maximum final grade they can achieve.

## Input

Each test consists of multiple test cases. The first line contains a single integer $t$ ($1 \leq t \leq 2 \cdot 10^4$) — the number of test cases. The description of the test cases follows.

The first line of each test case contains a single integer $n$ ($1 \le n \le 2 \cdot 10^5$) — the number of distance learning courses.

Each of the following $n$ lines contains two integers $x_i$ and $y_i$ ($0 \le x_i \le y_i < 2^{30}$) — the minimum and maximum grade that can be received for the $i$-th course.

The next line contains a single integer $q$ ($1 \le q \le 2\cdot10^5$) — the number of students.

Each of the following $q$ lines contains two integers $l_j$ and $r_j$ ($1 \le l_j \le r_j \le n$) — the minimum and maximum course numbers accessible to the $j$-th student.

It is guaranteed that the sum of $n$ over all test cases and the sum of $q$ over all test cases do not exceed $2\cdot10^5$.

## Output

For each test case, output $q$ integers, where the $j$-th integer is the maximum final grade that the $j$-th student can achieve.

## Example

## Input


```

320 13 431 11 22 241 71 73 102 251 33 42 31 41 261 22 20 11 13 30 043 45 52 51 2
```
## Output


```

1 5 4 
15 11 15 15 7 
1 3 3 3 

```
## Note

In the first test case:

1. The maximum grade for the first student is $1$:
	* On the first distance learning course, he will receive a grade of $1$. Therefore, the final grade is $1$.
2. The maximum grade for the second student is $5$:
	* On the first distance learning course, he will receive a grade of $1$.
	* On the second distance learning course, he will receive a grade of $4$. Therefore, the final grade is $1$ $|$ $4$ $=$ $5$.
3. The maximum grade for the third student is $4$:
	* On the second distance learning course, he will receive a grade of $4$. Therefore, the final grade is $4$.

In the second test case:

1. The maximum grade for the first student is $15$:
	* On the first distance learning course, he will receive a grade of $7$.
	* On the second distance learning course, he will receive a grade of $4$.
	* On the third distance learning course, he will receive a grade of $8$. Therefore, the final grade is $7$ $|$ $4$ $|$ $8$ $=$ $15$.
2. The maximum grade for the second student is $11$:
	* On the third distance learning course, he will receive a grade of $9$.
	* On the fourth distance learning course, he will receive a grade of $2$. Therefore, the final grade is $9$ $|$ $2$ $=$ $11$.


#### tags 

#2400 #bitmasks #brute_force #data_structures #greedy #math 