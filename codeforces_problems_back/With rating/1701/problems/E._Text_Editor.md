<h1 style='text-align: center;'> E. Text Editor</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You wanted to write a text $t$ consisting of $m$ lowercase Latin letters. But instead, you have written a text $s$ consisting of $n$ lowercase Latin letters, and now you want to fix it by obtaining the text $t$ from the text $s$.

Initially, the cursor of your text editor is at the end of the text $s$ (after its last character). In one move, you can do one of the following actions:

* press the "left" button, so the cursor is moved to the left by one position (or does nothing if it is pointing at the beginning of the text, i. e. before its first character);
* press the "right" button, so the cursor is moved to the right by one position (or does nothing if it is pointing at the end of the text, i. e. after its last character);
* press the "home" button, so the cursor is moved to the beginning of the text (before the first character of the text);
* press the "end" button, so the cursor is moved to the end of the text (after the last character of the text);
* press the "backspace" button, so the character before the cursor is removed from the text (if there is no such character, nothing happens).

Your task is to calculate the minimum number of moves required to obtain the text $t$ from the text $s$ using the given set of actions, or determine it is impossible to obtain the text $t$ from the text $s$.

You have to answer $T$ independent test cases.

## Input

The first line of the input contains one integer $T$ ($1 \le T \le 5000$) — the number of test cases. Then $T$ test cases follow.

The first line of the test case contains two integers $n$ and $m$ ($1 \le m \le n \le 5000$) — the length of $s$ and the length of $t$, respectively.

The second line of the test case contains the string $s$ consisting of $n$ lowercase Latin letters.

The third line of the test case contains the string $t$ consisting of $m$ lowercase Latin letters.

It is guaranteed that the sum of $n$ over all test cases does not exceed $5000$ ($\sum n \le 5000$).

## Output

For each test case, print one integer — the minimum number of moves required to obtain the text $t$ from the text $s$ using the given set of actions, or -1 if it is impossible to obtain the text $t$ from the text $s$ in the given test case.

## Example

## Input


```

69 4aaaaaaaaaaaaa7 3abacabaaaa5 4aabcdabcd4 2abbabb6 4barakabaka8 7questionproblem
```
## Output


```

5
6
3
4
4
-1

```


#### tags 

#2500 #brute_force #dp #greedy #strings 