<h1 style='text-align: center;'> A. Glory Addicts</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

The hero is addicted to glory, and is fighting against a monster. 

The hero has $n$ skills. The $i$-th skill is of type $a_i$ (either fire or frost) and has initial damage $b_i$. 

The hero can perform all of the $n$ skills in any order (with each skill performed exactly once). When performing each skill, the hero can play a magic as follows: 

* If the current skill immediately follows another skill of a different type, then its damage is doubled.

 In other words, 1. If a skill of type fire and with initial damage $c$ is performed immediately after a skill of type fire, then it will deal $c$ damage;
2. If a skill of type fire and with initial damage $c$ is performed immediately after a skill of type frost, then it will deal $2c$ damage;
3. If a skill of type frost and with initial damage $c$ is performed immediately after a skill of type fire, then it will deal $2c$ damage;
4. If a skill of type frost and with initial damage $c$ is performed immediately after a skill of type frost , then it will deal $c$ damage.

Your task is to find the maximum damage the hero can deal. 

## Input

Each test contains multiple test cases. The first line contains an integer $t$ ($1 \leq t \leq 10^5$) — the number of test cases. The following lines contain the description of each test case.

The first line of each test case contains an integer $n$ ($1 \leq n \leq 10^5$), indicating the number of skills. 

The second line of each test case contains $n$ integers $a_1, a_2, \dots, a_n$ ($0 \leq a_i \leq 1$), where $a_i$ indicates the type of the $i$-th skill. Specifically, the $i$-th skill is of type fire if $a_i = 0$, and of type frost if $a_i = 1$. 

The third line of each test case contains $n$ integers $b_1, b_2, \dots, b_n$ ($1 \leq b_i \leq 10^9$), where $b_i$ indicates the initial damage of the $i$-th skill. 

It is guaranteed that the sum of $n$ over all test cases does not exceed $10^5$.

## Output

For each test case, output the maximum damage the hero can deal.

## Example

## Input


```

440 1 1 11 10 100 100060 0 0 1 1 13 4 5 6 7 831 1 11000000000 1000000000 1000000000111
```
## Output


```

2112
63
3000000000
1

```
## Note

In the first test case, we can order the skills by $[3, 1, 4, 2]$, and the total damage is $100 + 2 \times 1 + 2 \times 1000 + 10 = 2112$.

In the second test case, we can order the skills by $[1, 4, 2, 5, 3, 6]$, and the total damage is $3 + 2 \times 6 + 2 \times 4 + 2 \times 7 + 2 \times 5 + 2 \times 8 = 63$.

In the third test case, we can order the skills by $[1, 2, 3]$, and the total damage is $1000000000 + 1000000000 + 1000000000 = 3000000000$.

In the fourth test case, there is only one skill with initial damage $1$, so the total damage is $1$. 



#### tags 

#800 #greedy #implementation #sortings 