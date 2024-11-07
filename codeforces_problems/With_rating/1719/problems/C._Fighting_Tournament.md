<h1 style='text-align: center;'> C. Fighting Tournament</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Burenka is about to watch the most interesting sporting event of the year — a fighting tournament organized by her friend Tonya.

$n$ athletes participate in the tournament, numbered from $1$ to $n$. Burenka determined the strength of the $i$-th athlete as an integer $a_i$, where $1 \leq a_i \leq n$. All the strength values are different, that is, the array $a$ is a permutation of length $n$. We know that in a fight, if $a_i > a_j$, then the $i$-th participant always wins the $j$-th.

The tournament goes like this: initially, all $n$ athletes line up in ascending order of their ids, and then there are infinitely many fighting rounds. In each round there is exactly one fight: the first two people in line come out and fight. The winner goes back to the front of the line, and the loser goes to the back.

Burenka decided to ask Tonya $q$ questions. In each question, Burenka asks how many victories the $i$-th participant gets in the first $k$ rounds of the competition for some given numbers $i$ and $k$. Tonya is not very good at analytics, so he asks you to help him answer all the questions.

### Input

The first line contains one integer $t$ ($1 \leq t \leq 10^4$) — the number of test cases. Description of the test cases follows.

The first line of each test case contains two integers $n$ and $q$ ($2 \leq n \leq 10^5$, $1 \leq q \leq 10^5$) — the number of tournament participants and the number of questions.

The second line of each test case contains $n$ integers $a_1, a_2, \ldots, a_n$ ($1 \leq a_i \leq n$) — the array $a$, which is a permutation.

The next $q$ lines of a test case contain questions. Each line contains two integers $i$ and $k$ ($1 \leq i \leq n$, $1 \leq k \leq 10^9$) — the number of the participant and the number of rounds.

It is guaranteed that the sum of $n$ and the sum of $q$ over all test cases do not exceed $10^5$.

### Output

For each Burenka's question, print a single line containing one integer — the answer to the question.

## Example

### Input


```text
33 13 1 21 24 21 3 4 24 53 25 21 2 3 5 45 10000000004 6
```
### Output

```text

2
0
1
0
4

```
## Note

In the first test case, the first numbered athlete has the strength of $3$, in the first round he will defeat the athlete with the number $2$ and the strength of $1$, and in the second round, the athlete with the number $3$ and the strength of $2$.

In the second test case, we list the strengths of the athletes fighting in the first $5$ fights: $1$ and $3$, $3$ and $4$, $4$ and $2$, $4$ and $1$, $4$ and $3$. The participant with the number $4$ in the first $5$ rounds won $0$ times (his strength is $2$). The participant with the number $3$ has a strength of $4$ and won $1$ time in the first two fights by fighting $1$ time.



#### Tags 

#1400 #OK #binary_search #data_structures #implementation #two_pointers 

## Blogs
- [All Contest Problems](../Codeforces_Round_814_(Div._2).md)
- [Codeforces Round #814](../blogs/Codeforces_Round_814.md)
- [Tutorial](../blogs/Tutorial.md)
