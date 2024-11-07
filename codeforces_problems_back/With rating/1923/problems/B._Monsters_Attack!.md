<h1 style='text-align: center;'> B. Monsters Attack!</h1>

<h5 style='text-align: center;'>time limit per test: 2.5 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are playing a computer game. The current level of this game can be modeled as a straight line. Your character is in point $0$ of this line. There are $n$ monsters trying to kill your character; the $i$-th monster has health equal to $a_i$ and is initially in the point $x_i$.

Every second, the following happens:

* first, you fire up to $k$ bullets at monsters. Each bullet targets exactly one monster and decreases its health by $1$. For each bullet, you choose its target arbitrary (for example, you can fire all bullets at one monster, fire all bullets at different monsters, or choose any other combination). Any monster can be targeted by a bullet, regardless of its position and any other factors;
* then, all alive monsters with health $0$ or less die;
* then, all alive monsters move $1$ point closer to you (monsters to the left of you increase their coordinates by $1$, monsters to the right of you decrease their coordinates by $1$). If any monster reaches your character (moves to the point $0$), you lose.

Can you survive and kill all $n$ monsters without letting any of them reach your character?

## Input

The first line of the input contains one integer $t$ ($1 \le t \le 3 \cdot 10^4$) — the number of test cases.

Each test case consists of three lines:

* the first line contains two integers $n$ and $k$ ($1 \le n \le 3 \cdot 10^5$; $1 \le k \le 2 \cdot 10^9$);
* the second line contains $n$ integers $a_1, a_2, \dots, a_n$ ($1 \le a_i \le 10^9$);
* the third line contains $n$ integers $x_1, x_2, \dots, x_n$ ($-n \le x_1 < x_2 < x_3 < \dots < x_n \le n$; $x_i \ne 0$).

Additional constraint on the input: the sum of $n$ over all test cases does not exceed $3 \cdot 10^5$.

## Output

For each test case, print YES if you can kill all $n$ monsters before they reach your character, or NO otherwise.

You can output each letter of the answer in any case (upper or lower). For example, the strings yEs, yes, Yes, and YES will all be recognized as positive responses.

## Example

## Input


```

53 21 2 3-1 2 32 11 1-1 14 103 4 2 5-3 -2 1 35 32 1 3 2 5-3 -2 3 4 52 11 21 2
```
## Output


```

YES
NO
YES
YES
NO

```
## Note

In the first example, you can act as follows:

* during the $1$-st second, fire $1$ bullet at the $1$-st monster and $1$ bullet at the $3$-rd monster. Then the $1$-st monster dies, the $2$-nd and the $3$-rd monster move closer;
* during the $2$-nd second, fire $2$ bullets at the $2$-nd monster. Then the $2$-nd monster dies, the $3$-rd monster moves closer;
* during the $3$-rd second, fire $2$ bullets at the $3$-rd monster. Then the $3$-rd monster dies.

In the second example, you can fire only $1$ bullet, so you can kill only one of the two monsters during the $1$-st second. Then, the remaining monster moves closer and kills your character.



#### tags 

#1100 #dp #greedy #implementation 