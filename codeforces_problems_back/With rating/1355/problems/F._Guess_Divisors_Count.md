<h1 style='text-align: center;'> F. Guess Divisors Count</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

This is an interactive problem.

We have hidden an integer $1 \le X \le 10^{9}$. You don't have to guess this number. You have to find the number of divisors of this number, and you don't even have to find the exact number: your answer will be considered correct if its absolute error is not greater than 7 or its relative error is not greater than $0.5$. More formally, let your answer be $ans$ and the number of divisors of $X$ be $d$, then your answer will be considered correct if at least one of the two following conditions is true:

* $| ans - d | \le 7$;
* $\frac{1}{2} \le \frac{ans}{d} \le 2$.

You can make at most $22$ queries. One query consists of one integer $1 \le Q \le 10^{18}$. In response, you will get $gcd(X, Q)$ — the greatest common divisor of $X$ and $Q$.

The number $X$ is fixed before all queries. In other words, interactor is not adaptive.

Let's call the process of guessing the number of divisors of number $X$ a game. In one test you will have to play $T$ independent games, that is, guess the number of divisors $T$ times for $T$ independent values of $X$.

## Input

The first line of input contains one integer $T$ ($1 \le T \le 100$) — the number of games.

## Interaction

To make a query print a line "? Q" ($1 \le Q \le 10^{18}$). After that read one integer $gcd(X, Q)$. You can make no more than $22$ such queries during one game.

If you are confident that you have figured out the number of divisors of $X$ with enough precision, you can print your answer in "! ans" format. $ans$ have to be an integer. If this was the last game, you have to terminate the program, otherwise you have to start the next game immediately. ## Note

 that the interactor doesn't print anything in response to you printing answer.

After printing a query do not forget to output end of line and flush the output. To do this, use:

* fflush(stdout) or cout.flush() in C++;
* System.out.flush() in Java;
* flush(output) in Pascal;
* stdout.flush() in Python;
* see documentation for other languages.

Hacks

To hack, use the following format:

The first line contains one integer $T$ ($1 \le T \le 100$) — the number of games.

Each of the next $T$ lines contains one integer $X$ ($1 \le X \le 10^{9}$) — the hidden number.

So the example has the form 


```
  
2  
998244353  
4194304  

```
## Example

## Input


```

2

1

1

1


1024

1048576

4194304

```
Output
```


? 982306799268821872

? 230856864650023977

? 134690134760714371

! 5
? 1024

? 1048576

? 1073741824

! 42

```
## Note

Why the limitation for number of queries is 22 exactly? Maybe the problem author is a Taylor Swift fan.

Let's look at the example.

In the first game $X = 998\,244\,353$ is hidden. Would be hard to guess this, right? This number is prime, so the number of its divisors is 2. The solution has made several random queries, and all the responses turned out to be 1 (strange things, not even one of three random numbers is divisible by $998\,244\,353$). It's fare to assume that the hidden number doesn't have many divisors, so the solution has answered 5. Why not. This answer will be considered correct since $| 5 - 2 | = 3 \le 7$.

In the second game $X = 4\,194\,304 = 2^{22}$ is hidden, it has 23 divisors. The solution has made queries $1024 = 2^{10}$, $1\,048\,576 =2^{20}$, $1\,073\,741\,824 = 2^{30}$ and got responses $1024 = 2^{10}$, $1\,048\,576 =2^{20}$, $4\,194\,304 = 2^{22}$, respectively. Then the solution got completely confused and answered the answer to The Ultimate Question of Life, the Universe, and Everything. This answer will be considered correct since $\frac{1}{2} \le \frac{42}{23} \le 2$.



#### tags 

#2600 #constructive_algorithms #interactive #number_theory 