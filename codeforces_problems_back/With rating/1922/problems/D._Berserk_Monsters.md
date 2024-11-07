<h1 style='text-align: center;'> D. Berserk Monsters</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Monocarp is playing a computer game (yet again). Guess what is he doing? That's right, killing monsters.

There are $n$ monsters in a row, numbered from $1$ to $n$. The $i$-th monster has two parameters: attack value equal to $a_i$ and defense value equal to $d_i$. In order to kill these monsters, Monocarp put a berserk spell on them, so they're attacking each other instead of Monocarp's character.

The fight consists of $n$ rounds. Every round, the following happens:

* first, every alive monster $i$ deals $a_i$ damage to the closest alive monster to the left (if it exists) and the closest alive monster to the right (if it exists);
* then, every alive monster $j$ which received more than $d_j$ damage during this round dies. I. e. the $j$-th monster dies if and only if its defense value $d_j$ is strictly less than the total damage it received this round.

For each round, calculate the number of monsters that will die during that round.

## Input

The first line contains one integer $t$ ($1 \le t \le 10^4$) — the number of test cases.

Each test case consists of three lines:

* the first line contains one integer $n$ ($1 \le n \le 3 \cdot 10^5$);
* the second line contains $n$ integers $a_1, a_2, \dots, a_n$ ($1 \le a_i \le 10^9$);
* the third line contains $n$ integers $d_1, d_2, \dots, d_n$ ($1 \le d_i \le 10^9$).

Additional constraint on the input: the sum of $n$ over all test cases does not exceed $3 \cdot 10^5$.

## Output

For each test case, print $n$ integers. The $i$-th integer should be equal to the number of monsters that die during the $i$-th round.

## Example

## Input


```

353 4 7 5 104 9 1 18 122 11 341 1 2 43 3 4 2
```
## Output


```

3 1 0 0 0 
0 0 
1 1 1 0 

```
## Note

Explanation for the first test case of the example:

During the first round, the following happens:

* the monster $1$ deals $3$ damage to the monster $2$;
* the monster $2$ deals $4$ damage to the monster $1$ and the monster $3$;
* the monster $3$ deals $7$ damage to the monster $2$ and the monster $4$;
* the monster $4$ deals $5$ damage to the monster $3$ and the monster $5$;
* the monster $5$ deals $10$ damage to the monster $4$;
* the monster $1$ does not die, since it received $4$ damage and its defense is $4$;
* the monster $2$ dies, since it received $10$ damage and its defense is $9$;
* the monster $3$ dies, since it received $9$ damage and its defense is $1$;
* the monster $4$ does not die, since it received $17$ damage and its defense is $18$;
* the monster $5$ dies, since it received $5$ damage and its defense is $1$.

After the first round, the monsters $1$ and $4$ stay alive.

During the second round, the following happens:

* the monster $1$ deals $3$ damage to the monster $4$;
* the monster $4$ deals $5$ damage to the monster $1$;
* the monster $1$ dies, since it received $5$ damage and its defense is $4$;
* the monster $4$ does not die, since it received $3$ damage and its defense is $18$.

During the next three rounds, only the $4$-th monster is alive, so nothing happens.



#### tags 

#1900 #brute_force #data_structures #dsu #implementation #math 