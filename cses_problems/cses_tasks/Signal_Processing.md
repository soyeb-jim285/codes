![CSES](/logo.png?1) __

Login — __Dark mode

### CSES Problem Set

# Signal Processing

  * Task
  * Statistics

CSES - Signal Processing

  * **Time limit:** 1.00 s
  * **Memory limit:** 512 MB

You are given two integer sequences: a signal and a mask. Your task is to
process the signal by moving the mask through the signal from left to right.
At each mask position calculate the sum of products of aligned signal and mask
values in the part where the signal and the mask overlap.

# Input

The first input line consists of two integers $n$ and $m$: the length of the
signal and the length of the mask.

The next line consists of $n$ integers $a_1,a_2,\ldots,a_n$ defining the
signal.

The last line consists of $m$ integers $b_1,b_2,\ldots,b_m$ defining the mask.

# Output

Print $n+m-1$ integers: the sum of products of aligned values at each mask
position from left to right.

# Constraints

  * $1 \le n,m \le 2 \cdot 10^5$
  * $1 \le a_i,b_i \le 100$

# Example

Input:

``` 5 3 1 3 2 1 4 1 2 3 ```

Output:

``` 3 11 13 10 16 9 4 ```

Explanation: For example, at the second mask position the sum of aligned
products is $2 \cdot 1 + 3 \cdot 3 = 11$.

#### Advanced Techniques

... Knuth DivisionApples and BananasOne Bit PositionsSignal ProcessingNew
Roads QueriesDynamic ConnectivityParcel DeliveryTask Assignment...

* * *

