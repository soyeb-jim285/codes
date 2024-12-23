<h1 style='text-align: center;'> C. Canine poetry</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

After his wife's tragic death, Eurydice, Orpheus descended to the realm of death to see her. Reaching its gates was uneasy, but passing through them proved to be even more challenging. Mostly because of Cerberus, the three-headed hound of Hades. 

Orpheus, a famous poet, and musician plans to calm Cerberus with his poetry and safely walk past him. He created a very peculiar poem for Cerberus. It consists only of lowercase English letters. 

We call a poem's substring a palindrome if and only if it reads the same backwards and forwards. A string $a$ is a substring of a string $b$ if $a$ can be obtained from $b$ by deleting several (possibly zero or all) characters from the beginning and several (possibly zero or all) characters from the end.

Unfortunately, Cerberus dislikes palindromes of length greater than $1$. For example in the poem abaa the hound of Hades wouldn't like substrings aba and aa.

Orpheus can only calm Cerberus if the hound likes his poetry. That's why he wants to change his poem so that it does not contain any palindrome substrings of length greater than $1$.

Orpheus can modify the poem by replacing a letter at any position with any lowercase English letter. He can use this operation arbitrarily many times (possibly zero). Since there can be many palindromes in his poem, he may have to make some corrections. But how many, exactly? Given the poem, determine the minimal number of letters that have to be changed so that the poem does not contain any palindromes of length greater than $1$.

### Input

The first line of the input contains a single integer $t$ ($1 \leq t \leq 10^5$) denoting the number of test cases, then $t$ test cases follow.

The first and only line of each test case contains a non-empty string of lowercase English letters, Orpheus' poem.

The sum of the length of Orpheus' poems in all test cases will not exceed $10^5$.

### Output

You should output $t$ lines, $i$-th line should contain a single integer, answer to the $i$-th test case.

## Example

### Input


```text
7
babba
abaac
codeforces
zeroorez
abcdcba
bbbbbbb
a
```
### Output


```text
1
1
0
1
1
4
0
```
## Note

In the first test case, we can replace the third character with c and obtain a palindrome-less poem bacba.

In the second test case, we can replace the third character with d and obtain a palindrome-less poem abdac.

In the third test case, the initial poem already doesn't contain any palindromes, so Orpheus doesn't need to change anything there.



#### Tags 

#1300 #NOT OK #dp #greedy #strings 

## Blogs
- [All Contest Problems](../Good_Bye_2020.md)
- [Good Bye 2020 (en)](../blogs/Good_Bye_2020_(en).md)
- [Good Bye 2020 Editorial (en)](../blogs/Good_Bye_2020_Editorial_(en).md)
