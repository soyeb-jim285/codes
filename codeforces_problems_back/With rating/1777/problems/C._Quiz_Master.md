<h1 style='text-align: center;'> C. Quiz Master</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

A school has to decide on its team for an international quiz. There are $n$ students in the school. We can describe the students using an array $a$ where $a_i$ is the smartness of the $i$-th ($1 \le i \le n$) student. 

There are $m$ topics $1, 2, 3, \ldots, m$ from which the quiz questions will be formed. The $i$-th student is considered proficient in a topic $T$ if $(a_i \bmod T) = 0$. Otherwise, he is a rookie in that topic. 

We say that a team of students is collectively proficient in all the topics if for every topic there is a member of the team proficient in this topic.

Find a team that is collectively proficient in all the topics such that the maximum difference between the smartness of any two students in that team is minimized. ## Output

 this difference.

## Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 10^4$). The description of the test cases follows.

The first line of each test case contains $n$ and $m$ ($1 \le n,m \le 10^5$).

The second line of each test case contains $n$ integers $a_1, a_2, \ldots, a_n$ ($1 \le a_i \le 10^5$).

It is guaranteed that the sum of $n$ over all test cases does not exceed $10^5$.

It is guaranteed that the sum of $m$ over all test cases does not exceed $10^5$.

## Output

For each test case, print the answer on a new line. If there is no solution, output $-1$.

## Example

## Input


```

32 43 74 23 7 2 95 76 4 3 5 7
```
## Output


```

-1
0
3

```
## Note

In the first test case, we have participants with smartnesses $3$ and $7$, and $m = 4$. Thus, there is no student with smartness divisible by $2$. Since $2 \leq m$, there is no way to choose a team.

In the second test case, we can select the participant with smartness $2$ to be the only one on the team. This way the team will be collectively proficient in both topics $1$ and $2$.

In the third test case, consider the team with participants of smartnesses $4, 5, 6, 7$. This way the team will be collectively proficient in all topics $1, 2, \ldots, 7$.



#### tags 

#1700 #binary_search #math #number_theory #sortings #two_pointers 