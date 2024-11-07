<h1 style='text-align: center;'> A. Burenka Plays with Fractions</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Burenka came to kindergarden. This kindergarten is quite strange, so each kid there receives two fractions ($\frac{a}{b}$ and $\frac{c}{d}$) with integer numerators and denominators. Then children are commanded to play with their fractions.

Burenka is a clever kid, so she noticed that when she claps once, she can multiply numerator or denominator of one of her two fractions by any integer of her choice (but she can't multiply denominators by $0$). Now she wants know the minimal number of claps to make her fractions equal (by value). Please help her and find the required number of claps!

## Input

The first line contains one integer $t$ ($1 \leq t \leq 10^4$) — the number of test cases. Then follow the descriptions of each test case.

The only line of each test case contains four integers $a$, $b$, $c$ and $d$ ($0 \leq a, c \leq 10^9$, $1 \leq b, d \leq 10^9$) — numerators and denominators of the fractions given to Burenka initially.

## Output

For each test case print a single integer — the minimal number of claps Burenka needs to make her fractions equal.

## Example

## Input


```

82 1 1 16 3 2 11 2 2 30 1 0 1000 1 228 179100 3 25 6999999999 300000000 666666666 10000000033 15 0 84
```
## Output


```

1
0
2
0
1
1
1
1

```
## Note

In the first case, Burenka can multiply $c$ by $2$, then the fractions will be equal.

In the second case, fractions are already equal.

In the third case, Burenka can multiply $a$ by $4$, then $b$ by $3$. Then the fractions will be equal ($\frac{1 \cdot 4}{2 \cdot 3} = \frac{2}{3}$).



#### tags 

#900 #math #number_theory 