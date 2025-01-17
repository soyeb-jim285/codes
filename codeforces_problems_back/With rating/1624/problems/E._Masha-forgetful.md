<h1 style='text-align: center;'> E. Masha-forgetful</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Masha meets a new friend and learns his phone number — $s$. She wants to remember it as soon as possible. The phone number — is a string of length $m$ that consists of digits from $0$ to $9$. The phone number may start with 0.

Masha already knows $n$ phone numbers (all numbers have the same length $m$). It will be easier for her to remember a new number if the $s$ is represented as segments of numbers she already knows. Each such segment must be of length at least $2$, otherwise there will be too many segments and Masha will get confused.

For example, Masha needs to remember the number: $s = $ '12345678' and she already knows $n = 4$ numbers: '12340219', '20215601', '56782022', '12300678'. You can represent $s$ as a $3$ segment: '1234' of number one, '56' of number two, and '78' of number three. There are other ways to represent $s$.

Masha asks you for help, she asks you to break the string $s$ into segments of length $2$ or more of the numbers she already knows. If there are several possible answers, print any of them.

## Input

The first line of input data contains an integer $t$ ($1 \le t \le 10^4$) —the number of test cases.

Before each test case there is a blank line. Then there is a line containing integers $n$ and $m$ ($1 \le n, m \le 10^3$) —the number of phone numbers that Masha knows and the number of digits in each phone number. Then follow $n$ line, $i$-th of which describes the $i$-th number that Masha knows. The next line contains the phone number of her new friend $s$.

Among the given $n+1$ phones, there may be duplicates (identical phones).

It is guaranteed that the sum of $n \cdot m$ ($n$ multiplied by $m$) values over all input test cases does not exceed $10^6$.

## Output

You need to print the answers to $t$ test cases. The first line of the answer should contain one number $k$, corresponding to the number of segments into which you split the phone number $s$. Print -1 if you cannot get such a split.

If the answer is yes, then follow $k$ lines containing triples of numbers $l, r, i$. Such triplets mean that the next $r-l+1$ digits of number $s$ are equal to a segment (substring) with boundaries $[l, r]$ of the phone under number $i$. Both the phones and the digits in them are numbered from $1$. ## Note

 that $r-l+1 \ge 2$ for all $k$ lines.

## Example

## Input


```

5  
4 81234021920215601567820221230067812345678  
2 3134126123  
1 412101221  
4 3251064859957054  
4 779686369486033461422454541979482268
```
## Output


```

3
1 4 1
5 6 2
3 4 3
-1
2
1 2 1
2 3 1
-1
3
1 3 2
5 6 3
3 4 1

```
## Note

The example from the statement.

In the second case, it is impossible to represent by segments of known numbers of length 2 or more.

In the third case, you can get the segments '12' and '21' from the first phone number.



#### tags 

#2000 #brute_force #constructive_algorithms #dp #hashing #implementation #strings 