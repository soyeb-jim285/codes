<h1 style='text-align: center;'> B. Battle Cows</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

[The HU - Shireg Shireg](https://youtu.be/SNCx4n2m5_o)ඞThere are $n$ cows participating in a coding tournament. Cow $i$ has a Cowdeforces rating of $a_i$ (all distinct), and is initially in position $i$. The tournament consists of $n-1$ matches as follows: 

* The first match is between the cow in position $1$ and the cow in position $2$.
* Subsequently, each match $i$ is between the cow in position $i+1$ and the winner of match $i-1$.
* In each match, the cow with the higher Cowdeforces rating wins and proceeds to the next match.

You are the owner of cow $k$. For you, winning the tournament is not important; rather, you want your cow to win in as many matches as possible. As an acquaintance of the tournament organizers, you can ask them to swap the position of your cow with another cow only once, or you can choose to do nothing.

Find the maximum number of wins your cow can achieve.

## Input

Each test contains multiple test cases. The first line contains an integer $t$ ($1 \le t \le 10^4$) — the number of test cases. The description of the test cases follows.

The first line of each test case contains two integers $n$ and $k$ ($2 \le n \le 10^5, 1 \le k \le n$) — the number of cows and your cow's index.

The second line of each test case contains $n$ integers $a_1, a_2, \ldots, a_n$ ($1 \le a_i \le 10^9$) — the Cowdeforces rating of the cows. It is guaranteed that $a_i$'s are pairwise different.

It is guaranteed that the sum of $n$ over all test cases does not exceed $10^5$.

## Output

For each test case, print one integer: the maximum number of wins cow $k$ can achieve if you choose to swap (or do nothing) optimally.

## Example

## Input


```

36 112 10 14 11 8 36 57 2 727 10 12 132 21000000000 1
```
## Output


```

1
2
0

```
## Note

In the first test case, it is optimal to do nothing. Let $a'$ be the Cowdeforces rating of the cows in the original order (with your cow's rating bolded), then 

* Initially, $a' = [\mathbf{12}, 10, 14, 11, 8, 3]$.
* Your cow plays against the cow with Cowdeforces rating $10$ and wins. $a' = [\mathbf{12}, 14, 11, 8, 3]$.
* Your cow plays against the cow with Cowdeforces rating $14$ and loses.

 In total, your cow wins $1$ match.In the second test case, it is optimal to swap your cow to position $3$. Then, let $a'$ be the Cowdeforces rating of the cows in the order after the swap. 

* Initially, $a' = [7, 2, \mathbf{12}, 10, 727, 13]$.
* The cow with Cowdeforces rating $7$ plays against the cow with Cowdeforces rating $2$ and wins. $a' = [7, \mathbf{12}, 10, 727, 13]$.
* The cow with Cowdeforces rating $7$ plays against your cow, and your cow wins. $a' = [\mathbf{12}, 10, 727, 13]$.
* Your cow plays against the cow with Cowdeforces rating $10$ and wins. $a' = [\mathbf{12}, 727, 13]$.
* Your cow plays against the cow with Cowdeforces rating $727$ and loses.

 In total, your cow wins $2$ matches.

#### tags 

#1200 #binary_search #data_structures #greedy 