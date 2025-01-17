<h1 style='text-align: center;'> G. Guess the String</h1>

<h5 style='text-align: center;'>time limit per test: 6 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

This is an interactive problem. You have to use flush operation right after printing each line. For example, in C++ you should use the function fflush(stdout), in Java or Kotlin — System.out.flush(), and in Python — sys.stdout.flush().

The jury has a string $s$ consisting of characters 0 and/or 1. The first character of this string is 0. The length of this string is $n$. You have to guess this string. Let's denote $s[l..r]$ as the substring of $s$ from $l$ to $r$ (i. e. $s[l..r]$ is the string $s_ls_{l+1} \dots s_r$).

Let the prefix function of the string $s$ be an array $[p_1, p_2, \dots, p_n]$, where $p_i$ is the greatest integer $j \in [0, i-1]$ such that $s[1..j] = s[i-j+1..i]$. Also, let the antiprefix function of the string $s$ be an array $[q_1, q_2, \dots, q_n]$, where $q_i$ is the greatest integer $j \in [0, i-1]$ such that $s[1..j]$ differs from $s[i-j+1..i]$ in every position.

For example, for the string 011001, its prefix function is $[0, 0, 0, 1, 1, 2]$, and its antiprefix function is $[0, 1, 1, 2, 3, 4]$.

You can ask queries of two types to guess the string $s$:

* $1$ $i$ — "what is the value of $p_i$?";
* $2$ $i$ — "what is the value of $q_i$?".

You have to guess the string by asking no more than $789$ queries. ## Note

 that giving the answer does not count as a query.

In every test and in every test case, the string $s$ is fixed beforehand.

## Interaction

Initially, the jury program sends one integer $t$ ($1 \le t \le 100$) — the number of test cases.

At the start of each test case, the jury program sends one integer $n$ ($2 \le n \le 1000$) — the length of the string.

After that, your program can submit queries to the jury program by printing one of the following lines (do not forget to flush the output after printing a line!):

* $1$ $i$ — the query "what is the value of $p_i$?";
* $2$ $i$ — the query "what is the value of $q_i$?".

For every query, the jury prints one integer on a separate line. It is either:

* the answer for your query, if the query is correct and you haven't exceeded the query limit;
* or the integer $-1$, if your query is incorrect (for example, the constraint $1 \le i \le n$ is not met) or if you have asked too many queries while processing the current test case.

To submit the answer, your program should send a line in the following format (do not forget to flush the output after printing a line!):

* $0$ $s$, where $s$ is a sequence of $n$ characters 0 and/or 1.

If your guess is correct, the jury program will print one integer $1$ on a separate line, indicating that you may proceed to the next test case (or terminate the program, if it was the last test case) and that the number of queries you have asked is reset. If it is not correct, the jury program will print one integer $-1$ on a separate line.

After your program receives $-1$ as the answer, it should immediately terminate. This will lead to your submission receiving the verdict "Wrong Answer". If your program does not terminate, the verdict of your submission is undefined.

## Example

Input
```

2 // 2 test cases
6 // n = 6

0 // p[3] = 0

1 // q[2] = 1

4 // q[6] = 4

1 // p[4] = 1

1 // answer is correct
5 // n = 5

1 // p[2] = 1

2 // q[4] = 2

2 // q[5] = 2

1 // answer is correct

```
Output
```



1 3      // what is p[3]?

2 2      // what is q[2]?

2 6      // what is q[6]?

1 4      // what is p[4]?

0 011001 // the guess is 011001


1 2      // what is p[2]?

2 4      // what is q[4]?

2 5      // what is q[5]?

0 00111  // the guess is 00111


```
## Note

The example contains one possible way of interaction in a test where $t = 2$, and the strings guessed by the jury are 011001 and 00111. ## Note

 that everything after the // sign is a comment that explains which line means what in the interaction. The jury program won't print these comments in the actual problem, and you shouldn't print them. The empty lines are also added for your convenience, the jury program won't print them, and your solution should not print any empty lines.



#### tags 

#2600 #constructive_algorithms #interactive #probabilities 