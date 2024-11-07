<h1 style='text-align: center;'> L. LOL Lovers</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 1024 megabytes</h5>

There are $n$ food items lying in a row on a long table. Each of these items is either a loaf of bread (denoted as a capital Latin letter 'L' with ASCII code 76) or an onion (denoted as a capital Latin letter 'O' with ASCII code 79). There is at least one loaf of bread and at least one onion on the table.

You and your friend want to divide the food on the table: you will take a prefix of this row (several leftmost items), and the friend will take the rest. However, there are several restrictions: 

1. Each person should have at least one item.
2. The number of your loaves should differ from the number of your friend's loaves.
3. The number of your onions should differ from the number of your friend's onions.

 Find any correct division and print the number of items you take or report that there is no answer.## Input

The first line contains one integer $n$ ($2 \le n \le 200$) — the number of food items on the table. The second line contains a string of length $n$ consisting of letters 'L' and 'O'. $i$-th symbol represents the type of the $i$-th food item on the table: 'L' stands for a loaf of bread, and 'O' stands for an onion. It is guaranteed that this string contains at least one letter 'L' and at least one letter 'O'.

## Output

Print one integer — a number $k$ such that, if you take $k$ leftmost items and your friend takes the remaining $n - k$ items, each of you and your friend get at least one item, your number of loaves is different from your friend's, and your number of onions is different from your friend's. If there are several possible answers, print any of them. If there are no possible answers, print the number $-1$.

## Examples

## Input


```

3LOL
```
## Output


```

-1

```
## Input


```

2LO
```
## Output


```

1

```
## Input


```

4LLLO
```
## Output


```

1

```
## Input


```

4OLOL
```
## Output


```

-1

```
## Input


```

10LLOOOOLLLO
```
## Output


```

5
```
## Note

In the first example, in any division the left and the right part contain one loaf of bread.

In the second example, the division is 'L' and 'O', and in these two strings the number of loaves is different (1 and 0) and the number of onions is different (0 and 1).

In the third example, any number 1, 2 or 3 is a correct answer.

 



#### tags 

#800 #strings 