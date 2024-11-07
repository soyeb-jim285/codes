<h1 style='text-align: center;'> H. Composite Spells</h1>

<h5 style='text-align: center;'>time limit per test: 4 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Monocarp plays a fantasy RPG. His character is a mage, so he casts spells. There are two types of spells he knows — basic spells and composite spells.

There are $n$ basic spells in Monocarp's spell book, numbered from $1$ to $n$. Each basic spell simply changes the health of the target: either decreases it or increases it. The $i$-th basic spell changes the target's health value by $b_i$ (increases by $b_i$ if $b_i$ is non-negative, or decreases by $|b_i|$ if $b_i$ is negative). If the target's health value goes to $0$ or below, it dies, and all next spells cast at it do nothing.

There are also $m$ composite spells in the spell book, numbered from $n+1$ to $n+m$. Each composite spell is a sequence of other spells, cast in specific order. A composite spell can consist both of basic spells and composite spells; the $i$-th spell consists of $s_i$ other spells, and each of those spells has index strictly less than $i$ (so there is no situation that composite spells infinitely cast each other). So, actually, each composite spell can be considered a finite sequence of basic spells, although its length might be huge. Note that the same spell can appear in a composite spell multiple times.

Monocarp has decided to cast the $(n+m)$-th spell from his spell book. The target of this spell is a monster with an initial health value of $hp$. Monocarp wants to know whether the monster will be killed or not, and if it will be killed, which basic spell will kill it.

## Input

The first line contains one integer $t$ ($1 \le t \le 1000$) — the number of test cases.

Each test case is given as follows:

* the first line contains two integers $n$ and $hp$ ($1 \le n \le 5000$; $1 \le hp \le 10^{9}$) — the number of basic spells and the initial health value of the monster;
* the second line contains $n$ integers $b_1, b_2, \dots, b_n$ ($-10^9 \le b_i \le 10^9$) — the descriptions of basic spells;
* the third line contains one integer $m$ ($1 \le m \le 5000$) — the number of composite spells;
* then $m$ lines follow, the $i$-th of these lines describes the $(n+i)$-th spell: it begins with an integer $s_{n+i}$ ($1 \le s_{n+i} \le 5000$) denoting the length of the spell (the number of spells it consists of); then a sequence of integers from $1$ to $(n+i-1)$ follows, denoting the sequence of spells.

Additional constraints on the input: 

* the sum of $n$ over all test cases does not exceed $5000$;
* the sum of $m$ over all test cases does not exceed $5000$;
* the total length of all composite spells over all test cases does not exceed $5000$.
## Output

For each test case, print one integer:

* if the monster dies, print the index of the basic spell that kills the monster;
* otherwise, print $-1$.
## Example

## Input


```

44 91 -2 3 -433 1 4 34 1 2 1 26 6 5 6 5 6 54 91 -2 3 -433 1 4 34 1 2 1 27 6 5 6 5 6 6 53 31-10 -20 3016 1 2 3 1 2 36 20-1 -5 -9 -7 -1 -143 6 5 24 3 3 7 66 4 8 4 4 6 73 6 5 7
```
## Output


```

4
4
-1
-1

```


#### tags 

#2600 #*special #dp 