<h1 style='text-align: center;'> A. Password</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Monocarp has forgotten the password to his mobile phone. The password consists of $4$ digits from $0$ to $9$ (note that it can start with the digit $0$).

Monocarp remembers that his password had exactly two different digits, and each of these digits appeared exactly two times in the password. Monocarp also remembers some digits which were definitely not used in the password.

You have to calculate the number of different sequences of $4$ digits that could be the password for Monocarp's mobile phone (i. e. these sequences should meet all constraints on Monocarp's password).

## Input

The first line contains a single integer $t$ ($1 \le t \le 200$) — the number of testcases.

The first line of each testcase contains a single integer $n$ ($1 \le n \le 8$) — the number of digits for which Monocarp remembers that they were not used in the password.

The second line contains $n$ different integers $a_1, a_2, \dots a_n$ ($0 \le a_i \le 9$) representing the digits that were not used in the password. ## Note

 that the digits $a_1, a_2, \dots, a_n$ are given in ascending order.

## Output

For each testcase, print one integer — the number of different $4$-digit sequences that meet the constraints.

## Example

## Input


```

280 1 2 4 5 6 8 918
```
## Output


```

6
216

```
## Note

In the first example, all possible passwords are: "3377", "3737", "3773", "7337", "7373", "7733".



#### tags 

#800 #brute_force #combinatorics #implementation #math 