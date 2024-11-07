<h1 style='text-align: center;'> C. Jellyfish and EVA</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

Monsters have invaded the town again! Asuka invites her good friend, Jellyfish, to drive EVA with her.

There are $n$ cities in the town. All the monsters are in city $n$. Jellyfish and Asuka are currently in city $1$ and need to move to city $n$ to defeat the monsters.

There are $m$ roads. The $i$-th road allows one to travel from city $a_i$ to city $b_i$. All the roads are directed. That is, one cannot travel from city $b_i$ to $a_i$ using the $i$-th road. Interestingly, all roads satisfy $a_i<b_i$.

Driving EVA requires two people to work together. However, Asuka and Jellyfish have not done any training together before.

Suppose that EVA is currently in city $u$. Jellyfish and Asuka will both choose an undestroyed road that starts at city $u$. Suppose Jellyfish and Asuka choose roads that end at cities $v_1$ and $v_2$ respectively. If $v_1 = v_2$, EVA moves to city $v_1$ successfully. Otherwise, EVA stays in city $u$ and both roads that they have chosen will be destroyed.

It is possible that EVA is currently in city $u$ ($u \neq n$) and there are no undestroyed roads that start at city $u$. In that case, the mission will be a failure. Otherwise, if they reach city $n$ in the end, the mission is considered a success.

Every time they choose the roads, Jellyfish knows that Asuka will choose a road randomly. Now, Jellyfish wants to know, if she chooses the roads optimally, what is the maximum probability of the mission being successful.

## Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \leq t \leq 2000$). The description of the test cases follows.

The first line of each test case contains two integers, $n$ and $m$ ($2 \leq n \leq 5000$, $0 \leq m \leq \min(\frac{n(n-1)}{2}, 2 \cdot 10^5)$) — the number of the cities and the number of the roads.

In the following $m$ lines of each test case, each line contains two integers $a$ and $b$ ($1 \leq a < b \leq n$) — representing a road from city $a$ to city $b$.

It is guaranteed that for each test case, each road appears at most once.

It is guaranteed that the sum of $n$ over all test cases will not exceed $5000$ and that the sum of $m$ over all test cases will not exceed $2 \cdot 10^5$.

## Output

## Output

 the maximum probability of the mission being successful if Jellyfish chooses the roads optimally.

Your answer will be accepted if the absolute or relative error does not exceed $10^{-9}$. Formally, let your answer be $a$, and the jury's answer be $b$. Your answer is considered correct if $\frac{|a-b|}{\max(1,|b|)} \leq 10^{-9}$.

## Example

## Input


```

33 21 21 37 81 21 31 41 52 63 64 66 710 201 21 31 41 51 62 62 72 82 93 43 73 83 104 64 84 106 107 87 97 10
```
## Output


```

0.500000000000
0.625000000000
0.491666666667

```
## Note

In the first test case, Jellyfish will choose $v_1=3$, and Asuka will choose $v_2=2$ with a possibility of $0.5$ and $v_2=3$ with a possibility of $0.5$. The mission is considered a success with a possibility of $0.5$.



#### tags 

#2300 #dp #graphs #greedy #math #probabilities 