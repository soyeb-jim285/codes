<h1 style='text-align: center;'> D. Digits</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

Diana loves playing with numbers. She's got $n$ cards with positive integer numbers $a_i$ written on them. She spends her free time multiplying the numbers on the cards. She picks a non-empty subset of the cards and multiplies all the numbers $a_i$ written on them.

Diana is happy when the product of the numbers ends with her favorite digit $d$. Now she is curious what cards she should pick so that the product of the numbers on them is the largest possible and the last decimal digit of the product is $d$. Please, help her.

## Input

The first line contains the integers $n$ and $d$ ($1\le n\le 10^5$, $0\le d\le 9$). The second line contains $n$ integers $a_i$ ($1\le a_i\le 1000$). 

## Output

On the first line, print the number of chosen cards $k$ ($1\le k\le n$). On the next line, print the numbers written on the chosen cards in any order. 

If it is impossible to choose a subset of cards with the product that ends with the digit $d$, print the single line with $-1$.

## Examples

## Input


```

6 4
4 11 8 2 1 13

```
## Output


```

5
1 2 4 11 13 

```
## Input


```

3 1
2 4 6

```
## Output


```

-1

```
## Input


```

5 7
1 3 1 5 3

```
## Output


```

-1

```
## Input


```

6 3
8 9 4 17 11 5

```
## Output


```

3
9 11 17 

```
## Input


```

5 6
2 2 2 2 2

```
## Output


```

4
2 2 2 2 

```
## Note

In the first example, $1 \times 2 \times 4 \times 11 \times 13 = 1144$, which is the largest product that ends with the digit 4. The same set of cards without the number 1 is also a valid answer, as well as a set of 8, 11, and 13 with or without 1 that also has the product of 1144.

In the second example, all the numbers on the cards are even and their product cannot end with an odd digit 1.

In the third example, the only possible products are 1, 3, 5, 9, 15, and 45, none of which end with the digit 7.

In the fourth example, $9 \times 11 \times 17 = 1683$, which ends with the digit 3. 

In the fifth example, $2 \times 2 \times 2 \times 2 = 16$, which ends with the digit 6.



#### tags 

#2100 #dp #math #number_theory 