<h1 style='text-align: center;'> D. X-Magic Pair</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

You are given a pair of integers $(a, b)$ and an integer $x$.

You can change the pair in two different ways: 

* set (assign) $a := |a - b|$;
* set (assign) $b := |a - b|$,

 where $|a - b|$ is the absolute difference between $a$ and $b$.The pair $(a, b)$ is called $x$-magic if $x$ is obtainable either as $a$ or as $b$ using only the given operations (i.e. the pair $(a, b)$ is $x$-magic if $a = x$ or $b = x$ after some number of operations applied). You can apply the operations any number of times (even zero).

Your task is to find out if the pair $(a, b)$ is $x$-magic or not.

You have to answer $t$ independent test cases.

## Input

The first line of the input contains one integer $t$ ($1 \le t \le 10^4$) — the number of test cases. The next $t$ lines describe test cases.

The only line of the test case contains three integers $a$, $b$ and $x$ ($1 \le a, b, x \le 10^{18}$).

## Output

For the $i$-th test case, print YES if the corresponding pair $(a, b)$ is $x$-magic and NO otherwise.

## Example

## Input


```

8
6 9 3
15 38 7
18 8 8
30 30 30
40 50 90
24 28 20
365 216 52
537037812705867558 338887693834423551 3199921013340

```
## Output


```

YES
YES
YES
YES
NO
YES
YES
YES

```


#### tags 

#1600 #math #number_theory 