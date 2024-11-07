<h1 style='text-align: center;'> B. Party</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

A club plans to hold a party and will invite some of its $n$ members. The $n$ members are identified by the numbers $1, 2, \dots, n$. If member $i$ is not invited, the party will gain an unhappiness value of $a_i$.

There are $m$ pairs of friends among the $n$ members. As per tradition, if both people from a friend pair are invited, they will share a cake at the party. The total number of cakes eaten will be equal to the number of pairs of friends such that both members have been invited.

However, the club's oven can only cook two cakes at a time. So, the club demands that the total number of cakes eaten is an even number.

What is the minimum possible total unhappiness value of the party, respecting the constraint that the total number of cakes eaten is even?

## Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \leq t \leq 10^4$). The description of the test cases follows.

The first line of each test case contains two integers $n$ and $m$ ($1 \leq n \leq 10^5$, $0 \leq m \leq \min(10^5,\frac{n(n-1)}{2})$) — the number of club members and pairs of friends.

The second line of each test case contains $n$ integers $a_1,a_2, \dots,a_n$ ($0 \leq a_i \leq 10^4$) — the unhappiness value array.

Each of the next $m$ lines contains two integers $x$ and $y$ ($1 \leq x,y \leq n$, $x \neq y$) indicating that $x$ and $y$ are friends. Each unordered pair $(x,y)$ appears at most once in each test case.

It is guaranteed that both the sum of $n$ and the sum of $m$ over all test cases do not exceed $10^5$.

## Output

For each test case, print a line containing a single integer – the minimum possible unhappiness value of a valid party.

## Example

## Input


```

41 013 12 1 31 35 51 2 3 4 51 21 31 41 52 35 51 1 1 1 11 22 33 44 55 1
```
## Output


```

0
2
3
2

```
## Note

In the first test case, all members can be invited. So the unhappiness value is $0$.

In the second test case, the following options are possible: 

* invite $1$ and $2$ ($0$ cakes eaten, unhappiness value equal to $3$);
* invite $2$ and $3$ ($0$ cakes eaten, unhappiness value equal to $2$);
* invite only $1$ ($0$ cakes eaten, unhappiness value equal to $4$);
* invite only $2$ ($0$ cakes eaten, unhappiness value equal to $5$);
* invite only $3$ ($0$ cakes eaten, unhappiness value equal to $3$);
* invite nobody ($0$ cakes eaten, unhappiness value equal to $6$).

 The minimum unhappiness value is achieved by inviting $2$ and $3$.In the third test case, inviting members $3,4,5$ generates a valid party with the minimum possible unhappiness value.



#### tags 

#1300 #brute_force #graphs 