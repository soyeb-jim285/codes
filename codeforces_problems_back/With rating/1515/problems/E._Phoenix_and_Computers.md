<h1 style='text-align: center;'> E. Phoenix and Computers</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

There are $n$ computers in a row, all originally off, and Phoenix wants to turn all of them on. He will manually turn on computers one at a time. At any point, if computer $i-1$ and computer $i+1$ are both on, computer $i$ $(2 \le i \le n-1)$ will turn on automatically if it is not already on. ## Note

 that Phoenix cannot manually turn on a computer that already turned on automatically.

If we only consider the sequence of computers that Phoenix turns on manually, how many ways can he turn on all the computers? Two sequences are distinct if either the set of computers turned on manually is distinct, or the order of computers turned on manually is distinct. Since this number may be large, please print it modulo $M$.

## Input

The first line contains two integers $n$ and $M$ ($3 \le n \le 400$; $10^8 \le M \le 10^9$) — the number of computers and the modulo. It is guaranteed that $M$ is prime.

## Output

Print one integer — the number of ways to turn on the computers modulo $M$.

## Examples

## Input


```

3 100000007

```
## Output


```

6

```
## Input


```

4 100000007

```
## Output


```

20

```
## Input


```

400 234567899

```
## Output


```

20914007

```
## Note

In the first example, these are the $6$ orders in which Phoenix can turn on all computers: 

* $[1,3]$. Turn on computer $1$, then $3$. ## Note

 that computer $2$ turns on automatically after computer $3$ is turned on manually, but we only consider the sequence of computers that are turned on manually.
* $[3,1]$. Turn on computer $3$, then $1$.
* $[1,2,3]$. Turn on computer $1$, $2$, then $3$.
* $[2,1,3]$
* $[2,3,1]$
* $[3,2,1]$


#### tags 

#2200 #combinatorics #dp #math 