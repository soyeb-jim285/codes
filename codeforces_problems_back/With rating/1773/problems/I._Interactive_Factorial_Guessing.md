<h1 style='text-align: center;'> I. Interactive Factorial Guessing</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 1024 megabytes</h5>

Oh no, this wicked jury hides something from you again, and you need to guess it interactively. 

This time, you need to find an integer $n$. To do that, you can make at most 10 queries of the form "What is the $k$-th decimal digit of the product of all integers from 1 to $n$ (also known as factorial and denoted as $n!$)?". 

## Interaction

In the first line, there is an integer $t$ ($1 \le t \le 100$) — the number of tests you shall process. 

For each test, the integer $n$ is chosen in advance. The length of $n!$ is at most $20\,000$, so $1 \le n \le 5982$.

You can make at most 10 queries of the form "? $k$" ($0 \le k < 20\,000$). In response to the query, you will get a single digit — the $k$-th decimal digit of $n!$ (the response is between 0 and 9 inclusive). Digits are numbered from 0, starting with the least significant digit. If $n!$ is too short, and there is no $k$-th digit, then 0 is returned. 

After your program finds the value of $n$ it shall answer with "! $n$". If the answer is correct, then you will receive "YES" and should proceed to the next test or terminate if it was the last one. If the answer is not correct, or you are trying to guess, and there are several possible answers consistent with the information you have received, you will get "NO". In that case, your submission will receive "Wrong answer" verdict and your code shall terminate immediately. 

## Example

Input
```

2

1

YES

0

2

YES

```
Output
```


? 0

! 1

? 0

? 19997

! 5982
```


#### tags 

#2500 #brute_force #games #implementation #interactive 