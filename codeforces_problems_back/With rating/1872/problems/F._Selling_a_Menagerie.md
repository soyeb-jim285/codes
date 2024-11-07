<h1 style='text-align: center;'> F. Selling a Menagerie</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are the owner of a menagerie consisting of $n$ animals numbered from $1$ to $n$. However, maintaining the menagerie is quite expensive, so you have decided to sell it!

It is known that each animal is afraid of exactly one other animal. More precisely, animal $i$ is afraid of animal $a_i$ ($a_i \neq i$). Also, the cost of each animal is known, for animal $i$ it is equal to $c_i$.

You will sell all your animals in some fixed order. Formally, you will need to choose some permutation$^\dagger$ $p_1, p_2, \ldots, p_n$, and sell animal $p_1$ first, then animal $p_2$, and so on, selling animal $p_n$ last.

When you sell animal $i$, there are two possible outcomes:

* If animal $a_i$ was sold before animal $i$, you receive $c_i$ money for selling animal $i$.
* If animal $a_i$ was not sold before animal $i$, you receive $2 \cdot c_i$ money for selling animal $i$. (Surprisingly, animals that are currently afraid are more valuable).

Your task is to choose the order of selling the animals in order to maximize the total profit. 

For example, if $a = [3, 4, 4, 1, 3]$, $c = [3, 4, 5, 6, 7]$, and the permutation you choose is $[4, 2, 5, 1, 3]$, then:

* The first animal to be sold is animal $4$. Animal $a_4 = 1$ was not sold before, so you receive $2 \cdot c_4 = 12$ money for selling it.
* The second animal to be sold is animal $2$. Animal $a_2 = 4$ was sold before, so you receive $c_2 = 4$ money for selling it.
* The third animal to be sold is animal $5$. Animal $a_5 = 3$ was not sold before, so you receive $2 \cdot c_5 = 14$ money for selling it.
* The fourth animal to be sold is animal $1$. Animal $a_1 = 3$ was not sold before, so you receive $2 \cdot c_1 = 6$ money for selling it.
* The fifth animal to be sold is animal $3$. Animal $a_3 = 4$ was sold before, so you receive $c_3 = 5$ money for selling it.

Your total profit, with this choice of permutation, is $12 + 4 + 14 + 6 + 5 = 41$. Note that $41$ is not the maximum possible profit in this example.

$^\dagger$ A permutation of length $n$ is an array consisting of $n$ distinct integers from $1$ to $n$ in any order. For example, $[2,3,1,5,4]$ is a permutation, but $[1,2,2]$ is not a permutation ($2$ appears twice in the array) and $[1,3,4]$ is also not a permutation ($n=3$, but $4$ is present in the array).

## Input

The first line of the input contains an integer $t$ ($1 \le t \le 10^4$) — the number of test cases.

Then follow the descriptions of the test cases.

The first line of each test case description contains an integer $n$ ($2 \le n \le 10^5$) — the number of animals.

The second line of the test case description contains $n$ integers $a_1, a_2, \dots, a_n$ ($1 \le a_i \le n$, $a_i \neq i$) — $a_i$ means the index of the animal that animal $i$ is afraid of.

The third line of the test case description contains $n$ integers $c_1, c_2, \dots, c_n$ ($1 \le c_i \le 10^9$) — the costs of the animals.

It is guaranteed that the sum of $n$ over all test cases does not exceed $10^5$.

## Output

## Output

 $t$ lines, each containing the answer to the corresponding test case. The answer should be $n$ integers — the permutation $p_1, p_2, \ldots, p_n$, indicating in which order to sell the animals in order to maximize the profit. If there are multiple possible answers, you can output any of them.

## Example

## Input


```

832 3 26 6 182 1 4 3 6 5 8 71 2 1 2 2 1 2 152 1 1 1 19 8 1 1 122 11000000000 99999999972 3 2 6 4 4 31 2 3 4 5 6 753 4 4 1 33 4 5 6 732 1 11 2 242 1 4 11 1 1 1
```
## Output


```

1 2 3
2 4 5 1 6 3 7 8
3 4 5 1 2
1 2
7 5 1 3 2 6 4
5 3 2 4 1
3 2 1
3 4 1 2
```


#### tags 

#1800 #dfs_and_similar #dsu #graphs #implementation #math 