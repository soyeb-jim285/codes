<h1 style='text-align: center;'> D. Wooden Toy Festival</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

In a small town, there is a workshop specializing in woodwork. Since the town is small, only three carvers work there.

Soon, a wooden toy festival is planned in the town. The workshop employees want to prepare for it.

They know that $n$ people will come to the workshop with a request to make a wooden toy. People are different and may want different toys. For simplicity, let's denote the pattern of the toy that the $i$-th person wants as $a_i$ ($1 \le a_i \le 10^9$).

Each of the carvers can choose an integer pattern $x$ ($1 \le x \le 10^9$) in advance, different carvers can choose different patterns. $x$ is the integer. During the preparation for the festival, the carvers will perfectly work out the technique of making the toy of the chosen pattern, which will allow them to cut it out of wood instantly. To make a toy of pattern $y$ for a carver who has chosen pattern $x$, it will take $|x - y|$ time, because the more the toy resembles the one he can make instantly, the faster the carver will cope with the work.

On the day of the festival, when the next person comes to the workshop with a request to make a wooden toy, the carvers can choose who will take on the job. At the same time, the carvers are very skilled people and can work on orders for different people simultaneously.

Since people don't like to wait, the carvers want to choose patterns for preparation in such a way that the maximum waiting time over all people is as small as possible.

## Output

 the best maximum waiting time that the carvers can achieve.

## Input

The first line of the input contains an integer $t$ ($1 \le t \le 10^4$) — the number of test cases.

Then follow the descriptions of the test cases.

The first line of a test case contains a single integer $n$ ($1 \le n \le 2 \cdot 10^5$) — the number of people who will come to the workshop.

The second line of a test case contains $n$ integers $a_1, a_2, a_3, \dots, a_n$ ($1 \le a_i \le 10^9$) — the patterns of toys.

The sum of all $n$ values over all test cases does not exceed $2 \cdot 10^5$.

## Output

## Output

 $t$ numbers, each of which is the answer to the corresponding test case — the best maximum waiting time that the carvers can achieve.

## Example

## Input


```

561 7 7 9 9 965 4 2 1 30 60914 19 37 59 1 4 4 98 731263 10 1 17 15 11
```
## Output


```

0
2
13
0
1

```
## Note

In the first example, the carvers can choose patterns $1$, $7$, $9$ for preparation.

In the second example, the carvers can choose patterns $3$, $30$, $60$ for preparation.

In the third example, the carvers can choose patterns $14$, $50$, $85$ for preparation.



#### tags 

#1400 #binary_search #greedy #sortings 