<h1 style='text-align: center;'> E. Evaluate It and Back Again</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 1024 megabytes</h5>

Aidan and Nadia are long-time friends with a shared passion for mathematics. Each of them has a favorite number: Aidan's favorite number is $p$, and Nadia's is $q$. 

To commemorate their friendship, their friends want to make a present: a plaque with an arithmetic expression whose value is equal to their favorite numbers. At first glance, it sounds impossible, but the answer is simple: Aidan reads left-to-right, while Nadia reads right-to-left, so the same expression can have different values for them.

For example, if 2023-12-13 is written on the plaque, then Aidan would calculate the result as $2023-12-13 = 1998$, and Nadia would calculate it as $31-21-3202=-3192$.

Find an arithmetic expression that, when read left-to-right, evaluates to $p$, and, when read right-to-left, evaluates to $q$. Its length must be at most $1000$ characters. It's guaranteed that such an expression exists for all valid inputs.

## Input

The first line of the input contains two integers $p$ and $q$ ($-10^{18} \le p, q \le 10^{18}$).

## Output

Print the expression without spaces or line breaks. It can only contain digits 0 through 9, '+', '-', and '*' characters.

The expression must contain at most $1000$ characters. Leading zeros in numbers are not allowed (the only exception is the notation '0' representing the number $0$) in both the expression and its reverse. Use of unary '+' or '-' is not allowed. The expression must be well-formed in both directions. The calculation uses the standard operator precedence. 

## Examples

## Input


```

1998 -3192
```
## Output


```

2023-12-13
```
## Input


```

413 908
```
## Output


```

12*34+5
```


#### tags 

#2200 #constructive_algorithms #implementation #math 