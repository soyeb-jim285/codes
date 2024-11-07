<h1 style='text-align: center;'> B. Fortune Telling</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Haha, try to solve this, SelectorUnlimited!— antontrygubO_oYour friends Alice and Bob practice fortune telling.

Fortune telling is performed as follows. There is a well-known array $a$ of $n$ non-negative integers indexed from $1$ to $n$. The tellee starts with some non-negative number $d$ and performs one of the two operations for each $i = 1, 2, \ldots, n$, in the increasing order of $i$. The possible operations are:

* replace their current number $d$ with $d + a_i$
* replace their current number $d$ with $d \oplus a_i$ (hereinafter $\oplus$ denotes the [bitwise XOR operation](https://en.wikipedia.org/wiki/Exclusive_or))

Notice that the chosen operation may be different for different $i$ and for different tellees.

One time, Alice decided to start with $d = x$ and Bob started with $d = x + 3$. Each of them performed fortune telling and got a particular number in the end. Notice that the friends chose operations independently of each other, that is, they could apply different operations for the same $i$.

You learnt that either Alice or Bob ended up with number $y$ in the end, but you don't know whose of the two it was. Given the numbers Alice and Bob started with and $y$, find out who (Alice or Bob) could get the number $y$ after performing the operations. It is guaranteed that on the jury tests, exactly one of your friends could have actually gotten that number.

Hacks

You cannot make hacks in this problem.

## Input

On the first line of the input, you are given one number $t$ ($1 \le t \le 10^4$) — the number of test cases. The following $2 \cdot t$ lines contain test cases.

The first line of each test case contains three numbers $n$, $x$, $y$ ($1 \le n \le 10^5$, $0 \le x \le 10^9$, $0 \le y \le 10^{15}$) — the length of array $a$, Alice's initial number (Bob's initial number is therefore $x+3$), and the number that one of the two friends got in the end.

The second line of each test case contains $n$ numbers — the array $a$ ($0 \le a_i \le 10^9$).

It is guaranteed that the sum of $n$ over all test cases does not exceed $10^5$.

## Output

For each test case, print the name of the friend who could get the number $y$: "Alice" or "Bob".

## Example

## Input


```

41 7 922 0 21 34 0 11 2 3 42 1000000000 30000000001000000000 1000000000
```
## Output


```

Alice
Alice
Bob
Alice

```
## Note

In the first test case, Alice could get $9$ using the following operations: $7 + 2 = 9$.

In the second test case, Alice could get $2$ using this operations: $(0 + 1) \oplus 3 = 2$.

In the third test case, Bob started with $x+3 = 0+3=3$ and could get $1$ this way: $(((3 + 1) + 2) \oplus 3) \oplus 4 = 1$.



#### tags 

#1400 #bitmasks #math 