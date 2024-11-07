<h1 style='text-align: center;'> B. Prime Square</h1>

<h5 style='text-align: center;'>time limit per test: 1.5 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Sasha likes investigating different math objects, for example, magic squares. But Sasha understands that magic squares have already been studied by hundreds of people, so he sees no sense of studying them further. Instead, he invented his own type of square — a prime square. 

A square of size $n \times n$ is called prime if the following three conditions are held simultaneously: 

* all numbers on the square are non-negative integers not exceeding $10^5$;
* there are no prime numbers in the square;
* sums of integers in each row and each column are prime numbers.

Sasha has an integer $n$. He asks you to find any prime square of size $n \times n$. Sasha is absolutely sure such squares exist, so just help him!

## Input

The first line contains a single integer $t$ ($1 \le t \le 10$) — the number of test cases.

Each of the next $t$ lines contains a single integer $n$ ($2 \le n \le 100$) — the required size of a square.

## Output

For each test case print $n$ lines, each containing $n$ integers — the prime square you built. If there are multiple answers, print any.

## Example

## Input


```

2
4
2

```
## Output


```

4 6 8 1
4 9 9 9
4 10 10 65
1 4 4 4
1 1
1 1

```


#### tags 

#900 #constructive_algorithms #math 