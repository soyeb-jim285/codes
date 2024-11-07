<h1 style='text-align: center;'> A. Gift Carpet</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Recently, Tema and Vika celebrated Family Day. Their friend Arina gave them a carpet, which can be represented as an $n \cdot m$ table of lowercase Latin letters.

Vika hasn't seen the gift yet, but Tema knows what kind of carpets she likes. Vika will like the carpet if she can read her name on. She reads column by column from left to right and chooses one or zero letters from current column.

Formally, the girl will like the carpet if it is possible to select four distinct columns in order from left to right such that the first column contains "v", the second one contains "i", the third one contains "k", and the fourth one contains "a".

Help Tema understand in advance whether Vika will like Arina's gift.

## Input

Each test consists of multiple test cases. The first line of input contains a single integer $t$ ($1 \le t \le 100$) — the number of test cases. Then follows the description of the test cases.

The first line of each test case contains two integers $n$, $m$ ($1 \le n, m \le 20$) — the sizes of the carpet.

The next $n$ lines contain $m$ lowercase Latin letters each, describing the given carpet.

## Output

For each set of input data, output "YES" if Vika will like the carpet, otherwise output "NO".

You can output each letter in any case (lowercase or uppercase). For example, the strings "yEs", "yes", "Yes", and "YES" will be accepted as a positive answer.

## Example

## Input


```

51 4vika3 3badcarpet4 4vvvviiiikkkkaaaa4 4vkakiiaiavvkviaa4 7vbickdavbickdavbickdavbickda
```
## Output


```

YES
NO
YES
NO
YES

```
## Note

In the first sample, Vika can read her name from left to right.

In the second sample, Vika cannot read the character "v", so she will not like the carpet.



#### tags 

#800 #dp #greedy #implementation #strings 