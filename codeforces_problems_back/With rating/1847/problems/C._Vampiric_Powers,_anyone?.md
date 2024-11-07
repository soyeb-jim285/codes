<h1 style='text-align: center;'> C. Vampiric Powers, anyone?</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

[DIO](https://jojowiki.com/Dio_Brando) knows that the Stardust Crusaders have determined his location and will be coming to fight him. To foil their plans he decides to send out some [Stand](https://jojo.fandom.com/wiki/Stand) users to fight them. Initially, he summoned $n$ Stand users with him, the $i$-th one having a strength of $a_i$. Using his vampiric powers, he can do the following as many times as he wishes:

* Let the current number of Stand users be $m$.
* DIO chooses an index $i$ ($1 \le i \le m$).
* Then he summons a new Stand user, with index $m+1$ and strength given by: $$a_{m+1} = a_i \oplus a_{i+1} \oplus \ldots \oplus a_m,$$where the operator $\oplus$ denotes the [bitwise XOR operation](https://en.wikipedia.org/wiki/Bitwise_operation#XOR).
* Now, the number of Stand users becomes $m+1$.

Unfortunately for DIO, by using Hermit Purple's divination powers, the Crusaders know that he is plotting this, and they also know the strengths of the original Stand users. Help the Crusaders find the maximum possible strength of a Stand user among all possible ways that DIO can summon.

## Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 10\,000$). The description of the test cases follows.

The first line of each test case contains a single integer $n$ ($1 \le n \le 10^5$)  – the number of Stand users initially summoned.

The second line of each test case contains $n$ integers $a_1, a_2, \ldots, a_n$ ($0 \le a_i < 2^8$)  – the strength of each Stand user.

It is guaranteed that the sum of $n$ over all test cases does not exceed $10^5$.

## Output

For each test case, output a single integer, maximum strength of a Stand user among all possible ways that DIO can summon.

## Example

## Input


```

340 2 5 131 2 358 2 4 12 1
```
## Output


```

7
3
14

```
## Note

In the first test case, one of the ways to add new Stand users is as follows:

* Choose $i=n$. Now, $a$ becomes $[0,2,5,1,1]$.
* Choose $i=1$. Now, $a$ becomes $[0,2,5,1,1,7]$. $7$ is the maximum strength of a Stand user DIO can summon.

In the second test case, DIO does not need to add more Stand users because $3$ is the maximum strength of a Stand user DIO can summon. 



#### tags 

#1400 #bitmasks #brute_force #dp #greedy 