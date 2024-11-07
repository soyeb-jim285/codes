<h1 style='text-align: center;'> A. Lucky?</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

A ticket is a string consisting of six digits. A ticket is considered lucky if the sum of the first three digits is equal to the sum of the last three digits. Given a ticket, output if it is lucky or not. ## Note

 that a ticket can have leading zeroes.

## Input

The first line of the input contains an integer $t$ ($1 \leq t \leq 10^3$) — the number of testcases.

The description of each test consists of one line containing one string consisting of six digits.

## Output

## Output

 $t$ lines, each of which contains the answer to the corresponding test case. ## Output

 "YES" if the given ticket is lucky, and "NO" otherwise.

You can output the answer in any case (for example, the strings "yEs", "yes", "Yes" and "YES" will be recognized as a positive answer).

## Example

## Input


```

5213132973894045207000000055776
```
## Output


```

YES
NO
YES
YES
NO

```
## Note

In the first test case, the sum of the first three digits is $2 + 1 + 3 = 6$ and the sum of the last three digits is $1 + 3 + 2 = 6$, they are equal so the answer is "YES".

In the second test case, the sum of the first three digits is $9 + 7 + 3 = 19$ and the sum of the last three digits is $8 + 9 + 4 = 21$, they are not equal so the answer is "NO".

In the third test case, the sum of the first three digits is $0 + 4 + 5 = 9$ and the sum of the last three digits is $2 + 0 + 7 = 9$, they are equal so the answer is "YES".



#### tags 

#800 #implementation 