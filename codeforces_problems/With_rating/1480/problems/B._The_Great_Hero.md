<h1 style='text-align: center;'> B. The Great Hero</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

The great hero guards the country where Homer lives. The hero has attack power $A$ and initial health value $B$. There are $n$ monsters in front of the hero. The $i$-th monster has attack power $a_i$ and initial health value $b_i$. 

The hero or a monster is said to be living, if his or its health value is positive (greater than or equal to $1$); and he or it is said to be dead, if his or its health value is non-positive (less than or equal to $0$).

In order to protect people in the country, the hero will fight with monsters until either the hero is dead or all the monsters are dead.

* In each fight, the hero can select an arbitrary living monster and fight with it. Suppose the $i$-th monster is selected, and the health values of the hero and the $i$-th monster are $x$ and $y$ before the fight, respectively. After the fight, the health values of the hero and the $i$-th monster become $x-a_i$ and $y-A$, respectively.

## Note

 that the hero can fight the same monster more than once.

For the safety of the people in the country, please tell them whether the great hero can kill all the monsters (even if the great hero himself is dead after killing the last monster).

### Input

Each test contains multiple test cases. The first line contains $t$ ($1 \le t \le 10^5$) — the number of test cases. Description of the test cases follows.

The first line of each test case contains three integers $A$ ($1 \leq A \leq 10^6$), $B$ ($1 \leq B \leq 10^6$) and $n$ ($1 \leq n \leq 10^5$) — the attack power of the great hero, the initial health value of the great hero, and the number of monsters.

The second line of each test case contains $n$ integers $a_1, a_2, \dots, a_n$ ($1 \leq a_i \leq 10^6$), where $a_i$ denotes the attack power of the $i$-th monster.

The third line of each test case contains $n$ integers $b_1, b_2, \dots, b_n$ ($1 \leq b_i \leq 10^6$), where $b_i$ denotes the initial health value of the $i$-th monster.

It is guaranteed that the sum of $n$ over all test cases does not exceed $10^5$.

### Output

For each test case print the answer: "YES" (without quotes) if the great hero can kill all the monsters. Otherwise, print "NO" (without quotes).

## Example

### Input


```text
5
3 17 1
2
16
10 999 3
10 20 30
100 50 30
1000 1000 4
200 300 400 500
1000 1000 1000 1000
999 999 1
1000
1000
999 999 1
1000000
999
```
### Output


```text
YES
YES
YES
NO
YES
```
## Note

In the first example: There will be $6$ fights between the hero and the only monster. After that, the monster is dead and the health value of the hero becomes $17 - 6 \times 2 = 5 > 0$. So the answer is "YES", and moreover, the hero is still living.

In the second example: After all monsters are dead, the health value of the hero will become $709$, regardless of the order of all fights. So the answer is "YES".

In the third example: A possible order is to fight with the $1$-st, $2$-nd, $3$-rd and $4$-th monsters. After all fights, the health value of the hero becomes $-400$. Unfortunately, the hero is dead, but all monsters are also dead. So the answer is "YES".

In the fourth example: The hero becomes dead but the monster is still living with health value $1000 - 999 = 1$. So the answer is "NO".



#### Tags 

#900 #NOT OK #greedy #implementation #sortings 

## Blogs
- [All Contest Problems](../Codeforces_Round_700_(Div._2).md)
- [Codeforces Round #700 (en)](../blogs/Codeforces_Round_700_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
