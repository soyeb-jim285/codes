<h1 style='text-align: center;'> C. Job Interview</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Monocarp is opening his own IT company. He wants to hire $n$ programmers and $m$ testers. 

There are $n+m+1$ candidates, numbered from $1$ to $n+m+1$ in chronological order of their arriving time. The $i$-th candidate has programming skill $a_i$ and testing skill $b_i$ (a person's programming skill is different from their testing skill). The skill of the team is the sum of the programming skills of all candidates hired as programmers, and the sum of the testing skills of all candidates hired as testers.

When a candidate arrives to interview, Monocarp tries to assign them to the most suitable position for them (if their programming skill is higher, then he hires them as a programmer, otherwise as a tester). If all slots for that position are filled, Monocarp assigns them to the other position.

Your task is, for each candidate, calculate the skill of the team if everyone except them comes to interview. ## Note

 that it means that exactly $n+m$ candidates will arrive, so all $n+m$ positions in the company will be filled.

## Input

The first line contains a single integer $t$ ($1 \le t \le 10^4$) — the number of test cases.

Each test case consists of three lines:

* the first line contains two integers $n$ and $m$ ($0 \le n, m \le 2 \cdot 10^5$; $2 \le n + m + 1 \le 2 \cdot 10^5$) — the number of programmers and the number of testers Monocarp wants to hire, respectively;
* the second line contains $n + m + 1$ integers $a_1, a_2, \dots, a_{n+m+1}$ ($1 \le a_i \le 10^9$), where $a_i$ is the programming skill of the $i$-th candidate;
* the third line contains $n + m + 1$ integers $b_1, b_2, \dots, b_{n+m+1}$ ($1 \le b_i \le 10^9$; $b_i \ne a_i$), where $b_i$ is the testing skill of the $i$-th candidate.

Additional constraint on the input: the sum of $(n + m + 1)$ over all test cases doesn't exceed $2 \cdot 10^5$.

## Output

For each test case, print $n + m + 1$ integers, where the $i$-th integer should be equal to the skill of the team if everyone except the $i$-th candidate comes to interview.

## Example

## Input


```

41 02 11 20 24 5 55 4 11 22 1 5 45 2 3 13 14 3 3 4 15 5 4 5 2
```
## Output


```

1 2 
5 6 9 
8 11 11 12 
13 13 13 12 15 

```
## Note

Let's consider the third test case of the example:

* if the $1$-st candidate does not arrive, the $2$-nd candidate gets hired as a tester, the $3$-rd candidate gets hired as a programmer, the $4$-th candidate gets hired as a tester. The total skill of the team will be $2 + 5 + 1 = 8$;
* if the $2$-nd candidate does not arrive, the $1$-st candidate gets hired as a tester, the $3$-rd candidate gets hired as a programmer, the $4$-th candidate gets hired as a tester. The total skill of the team will be $5 + 5 + 1 = 11$;
* if the $3$-rd candidate does not arrive, the $1$-st candidate gets hired as a tester, the $2$-nd candidate gets hired as a tester, the $4$-th candidate gets hired as a programmer. The total skill of the team will be $5 + 2 + 4 = 11$;
* if the $4$-th candidate does not arrive, the $1$-st candidate gets hired as a tester, the $2$-nd candidate gets hired as a tester, the $3$-rd candidate gets hired as a programmer. The total skill of the team will be $5 + 2 + 5 = 12$.


#### tags 

#1600 #binary_search #dp #greedy #implementation #two_pointers 