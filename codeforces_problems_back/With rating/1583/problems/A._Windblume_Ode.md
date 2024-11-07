<h1 style='text-align: center;'> A. Windblume Ode</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

A bow adorned with nameless flowers that bears the earnest hopes of an equally nameless person.

You have obtained the elegant bow known as the Windblume Ode. Inscribed in the weapon is an array of $n$ ($n \ge 3$) positive distinct integers (i.e. different, no duplicates are allowed).

Find the largest subset (i.e. having the maximum number of elements) of this array such that its sum is a composite number. A positive integer $x$ is called composite if there exists a positive integer $y$ such that $1 < y < x$ and $x$ is divisible by $y$.

If there are multiple subsets with this largest size with the composite sum, you can output any of them. It can be proven that under the constraints of the problem such a non-empty subset always exists.

## Input

Each test consists of multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 100$). Description of the test cases follows.

The first line of each test case contains an integer $n$ ($3 \leq n \leq 100$) — the length of the array.

The second line of each test case contains $n$ distinct integers $a_{1},a_{2},\dots,a_{n}$ ($1 \leq a_{i} \leq 200$) — the elements of the array.

## Output

Each test case should have two lines of output.

The first line should contain a single integer $x$: the size of the largest subset with composite sum. The next line should contain $x$ space separated integers representing the indices of the subset of the initial array.

## Example

## Input


```

4
3
8 1 2
4
6 9 4 2
9
1 2 3 4 5 6 7 8 9
3
200 199 198

```
## Output


```

2
2 1
4
2 1 4 3
9
6 9 1 2 3 4 5 7 8
3
1 2 3 

```
## Note

In the first test case, the subset $\{a_2, a_1\}$ has a sum of $9$, which is a composite number. The only subset of size $3$ has a prime sum equal to $11$. ## Note

 that you could also have selected the subset $\{a_1, a_3\}$ with sum $8 + 2 = 10$, which is composite as it's divisible by $2$.

In the second test case, the sum of all elements equals to $21$, which is a composite number. Here we simply take the whole array as our subset.



#### tags 

#800 #math #number_theory 