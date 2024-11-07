<h1 style='text-align: center;'> H. Higher Order Functions</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 1024 megabytes</h5>

Helen studies functional programming and she is fascinated with a concept of higher order functions — functions that are taking other functions as parameters. She decides to generalize the concept of the function order and to test it on some examples. 

For her study, she defines a simple grammar of types. In her grammar, a type non-terminal $T$ is defined as one of the following grammar productions, together with $\textrm{order}(T)$, defining an order of the corresponding type:

* "()" is a unit type, $\textrm{order}(\textrm{"}\texttt{()}\textrm{"}) = 0$.
* "(" $T$ ")" is a parenthesized type, $\textrm{order}(\textrm{"}\texttt{(}\textrm{"}\,T\,\textrm{"}\texttt{)}\textrm{"}) = \textrm{order}(T)$.
* $T_1$ "->" $T_2$ is a functional type, $\textrm{order}(T_1\,\textrm{"}\texttt{->}\textrm{"}\,T_2) = max(\textrm{order}(T_1) + 1, \textrm{order}(T_2))$. The function constructor $T_1$ "->" $T_2$ is right-to-left associative, so the type "()->()->()" is the same as the type "()->(()->())" of a function returning a function, and it has an order of $1$. While "(()->())->()" is a function that has an order-1 type "(()->())" as a parameter, and it has an order of $2$.

 Helen asks for your help in writing a program that computes an order of the given type.

## Input

The single line of the input contains a string consisting of characters '(', ')', '-', and '>' that describes a type that is valid according to the grammar from the problem statement. The length of the line is at most $10^4$ characters.

## Output

Print a single integer — the order of the given type.

## Examples

## Input


```

()

```
## Output


```

0

```
## Input


```

()->()

```
## Output


```

1

```
## Input


```

()->()->()

```
## Output


```

1

```
## Input


```

(()->())->()

```
## Output


```

2

```
## Input


```

()->(((()->())->()->())->())

```
## Output


```

3

```


#### tags 

#1700 #implementation #strings 