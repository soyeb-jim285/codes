<h1 style='text-align: center;'> E. Crypto Lights</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

 ![](images/bee80e302133e850aecc20e2e9b4bfe891165b84.png) To monitor cryptocurrency exchange rates trader William invented a wonderful device consisting of $n$ lights arranged in a row. The device functions in the following way:

Initially, all lights on William's device are turned off. At the beginning of a new iteration the device randomly, with a uniform distribution, picks a light that is turned off and turns it on, telling William which cryptocurrency he should invest in. After this iteration if any $k$ consecutive lights contain more than one turned on light, then the device finishes working.

William doesn't like uncertainty, so he wants you to calculate the expected value of the number of lights that are turned on in the device after it finishes working.

## Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 10$). Description of the test cases follows.

The only line for each test case contains two integers $n$ and $k$ ($2 \le k \le n \le 10^5$), which are the total number of lights and the length of subsegment of lights that are being checked, respectively.

## Output

For each test case print the answer, modulo $10^9+7$. 

Formally, let $M = 10^9+7$. It can be shown that the answer can be expressed as an irreducible fraction $\frac{p}{q}$, where $p$ and $q$ are integers and $q \not \equiv 0 \pmod{M}$. ## Output

 the integer equal to $p \cdot q^{-1} \bmod M$. In other words, output such an integer $x$ that $0 \le x < M$ and $x \cdot q \equiv p \pmod{M}$.

## Example

## Input


```

3
3 2
15 2
40 15

```
## Output


```

333333338
141946947
329622137

```
## Note

Explanation of the first sample test case:

Let's write out all possible sequences of light toggles, which will make the device complete its operation:

1. $(1, 2)$  — $2$ lights are turned on
2. $(1, 3, 2)$  — $3$ lights are turned on
3. $(2, 1)$  — $2$ lights are turned on
4. $(2, 3)$  — $2$ lights are turned on
5. $(3, 2)$  — $2$ lights are turned on
6. $(3, 1, 2)$  — $3$ lights are turned on

Then the final expected value will be equal to $\frac{2}{6}$ + $\frac{3}{6}$ + $\frac{2}{6}$ + $\frac{2}{6}$ + $\frac{2}{6}$ + $\frac{3}{6}$ = $\frac{14}{6}$ = $\frac{7}{3}$. 

Then the required output will be $333333338$, since $333333338 \cdot 3 \equiv 7 \pmod{10^9+7}$.



#### tags 

#2600 #combinatorics #dp #math #probabilities 