<h1 style='text-align: center;'> F. Magic Will Save the World</h1>

<h5 style='text-align: center;'>time limit per test: 4 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

A portal of dark forces has opened at the border of worlds, and now the whole world is under a terrible threat. To close the portal and save the world, you need to defeat $n$ monsters that emerge from the portal one after another.

Only the sorceress Vika can handle this. She possesses two magical powers — water magic and fire magic. In one second, Vika can generate $w$ units of water mana and $f$ units of fire mana. She will need mana to cast spells. Initially Vika have $0$ units of water mana and $0$ units of fire mana.

Each of the $n$ monsters that emerge from the portal has its own strength, expressed as a positive integer. To defeat the $i$-th monster with strength $s_i$, Vika needs to cast a water spell or a fire spell of at least the same strength. In other words, Vika can spend at least $s_i$ units of water mana on a water spell, or at least $s_i$ units of fire mana on a fire spell.

Vika can create and cast spells instantly. Vika can cast an unlimited number of spells every second as long she has enough mana for that.

The sorceress wants to save the world as quickly as possible, so tell her how much time she will need.

## Input

Each test consists of several test cases. The first line of each test contains a single integer $t$ ($1 \le t \le 100$) — the number of test cases. This is followed by a description of the test cases.

The first line of each test case contains two integers $w$, $f$ ($1 \le w, f \le 10^9$) — the amount of water and fire mana that Vika can generate per second.

The second line of each test case contains a single integer $n$ ($1 \le n \le 100$) — the number of monsters.

The third line of each test case contains $n$ integers $s_1, s_2, s_3, \dots, s_n$ ($1 \le s_i \le 10^4$) — the strengths of the monsters.

It is guaranteed that the sum of $n$ over all test cases does not exceed $100$.

## Output

For each test case, output a single integer — the minimum time in seconds that Vika will need to defeat all the monsters.

## Example

## Input


```

42 332 6 737 58193190 90223 9713 4410 10 2 45
```
## Output


```

3
2
1
5

```
## Note

In the first sample, after the first second, Vika can spend $2$ units of fire mana to kill the first monster. Then she has $2$ units of water mana and $1$ unit of fire mana. After the third second, she will have $6$ units of water mana and $7$ units of fire mana at her disposal. This will be enough to immediately kill the second and third monsters.



#### tags 

#1800 #binary_search #bitmasks #brute_force #dp 