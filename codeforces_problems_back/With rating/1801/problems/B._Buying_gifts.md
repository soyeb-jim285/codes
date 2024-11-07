<h1 style='text-align: center;'> B. Buying gifts</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

 Little Sasha has two friends, whom he wants to please with gifts on the Eighth of March. To do this, he went to the largest shopping center in the city.There are $n$ departments in the mall, each of which has exactly two stores. For convenience, we number the departments with integers from $1$ to $n$. It is known that gifts in the first store of the $i$ department cost $a_i$ rubles, and in the second store of the $i$ department — $b_i$ rubles.

Entering the mall, Sasha will visit each of the $n$ departments of the mall, and in each department, he will enter exactly one store. When Sasha gets into the $i$-th department, he will perform exactly one of two actions:

1. Buy a gift for the first friend, spending $a_i$ rubles on it.
2. Buy a gift for the second friend, spending $b_i$ rubles on it.

Sasha is going to buy at least one gift for each friend. Moreover, he wants to pick up gifts in such a way that the price difference of the most expensive gifts bought for friends is as small as possible so that no one is offended.

More formally: let $m_1$  be the maximum price of a gift bought to the first friend, and $m_2$  be the maximum price of a gift bought to the second friend. Sasha wants to choose gifts in such a way as to minimize the value of $\lvert m_1 - m_2 \rvert$. 

## Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 1\,000$). The description of the test cases follows.

The first line of each test case contains a single integer $n$ ($2 \le n \le 500\,000$) — the number of departments in the mall.

Each of the following $n$ lines of each test case contains two integers $a_i$ and $b_i$ ($0 \le a_i, b_i \le 10^9$) — the prices of gifts in the first and second store of the $i$ department, respectively.

It is guaranteed that the sum of $n$ over all test cases does not exceed $500\,000$. 

## Output

Print one integer — the minimum price difference of the most expensive gifts bought to friends. 

## Example

 

## Input


```

221 22 151 52 73 34 102 5
```
## Output


```

0
1

```
 ## Note

In the first test case, Sasha has two possible options: buy a gift for the first friend in the first department, and the second friend  — in the second department, or vice versa. In the first case, $m_1 = m_2 = 1$, and in the second case — $m_1 = m_2 = 2$. In both cases, the answer is $0$. In the second test case, you can buy gifts for the first friend in the $2$, $4$ and $5$ departments, and for the second friend  — in the $1$ and $3$ departments.So $m_1 = \max(2, 4, 2) = 4$, $m_2 = \max(5, 3) = 5$. The answer is $\lvert 4 - 5 \rvert = 1$. 



#### tags 

#1800 #data_structures #greedy #sortings 