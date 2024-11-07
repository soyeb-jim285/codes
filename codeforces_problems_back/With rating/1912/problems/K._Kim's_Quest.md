<h1 style='text-align: center;'> K. Kim's Quest</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 1024 megabytes</h5>

In the long-forgotten halls of Kombinatoria's ancient academy, a gifted mathematician named Kim is faced with an unusual challenge. They found an old sequence of integers, which is believed to be a cryptic message from the legendary Kombinatoria's Oracle, and Kim wants to decipher its hidden meaning.

Kim's mission is to find specific patterns within the sequence, known as Harmonious Subsequences. These are extraordinary subsequences where the sum of every three consecutive numbers is even, and each subsequence must be at least three numbers in length. 

Given a sequence $a_i$ ($1 \le i \le n$) of length $n$, its subsequence of length $m$ is equal to $a_{b_1}, a_{b_2}, \ldots, a_{b_m}$ and is uniquely defined by a set of $m$ indices $b_j$, such that $1 \le b_1 < b_2 < \ldots < b_m \le n$. Subsequences given by different sets of indices $b_j$ are considered different.

There's a twist in Kim's quest: the number of these Harmonious Subsequences could be overwhelming. To report the findings effectively, Kim must calculate the total number of these subsequences, presenting the answer as a remainder after dividing by the number $998\,244\,353$.

## Input

The first line contains a single integer $n$ — the length of the sequence ($3 \le n \le 2 \cdot 10^5$).

The second line contains $n$ space-separated integers $a_i$ — the elements of the sequence ($1 \le a_i \le 2 \cdot 10^5$).

## Output

## Output

 one number — the number of Harmonious Subsequences, modulo $998\,244\,353$.

## Examples

## Input


```

31 2 3
```
## Output


```

1

```
## Input


```

52 8 2 6 4
```
## Output


```

16

```
## Input


```

55 7 1 3 5
```
## Output


```

0

```
## Input


```

113 1 4 1 5 9 2 6 5 3 6
```
## Output


```

386

```
## Input


```

54
2 1 1 1 1 2 1 2 2 2 2 1 1 1 2 1 1 2
2 1 2 2 2 2 2 2 2 1 1 1 2 2 1 1 1 1
2 2 1 1 2 2 2 2 2 1 1 1 2 2 1 2 1 1

```
## Output


```

0

```
## Note

In the provided input data for the fifth sample, the sequence of numbers is split into three separate lines for clarity, but it should be understood that in the actual test data, the sequence is given in one line. The actual number of Harmonious Subsequences in this example is $4\,991\,221\,765 = 5 \times 998\,244\,353$, hence the output is zero as a result of finding its remainder after dividing by the number $998\,244\,353$.



#### tags 

#1800 #bitmasks #combinatorics #dp 