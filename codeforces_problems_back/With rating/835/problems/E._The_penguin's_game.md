<h1 style='text-align: center;'> E. The penguin's game</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Pay attention: this problem is interactive.

Penguin Xoriy came up with a new game recently. He has *n* icicles numbered from 1 to *n*. Each icicle has a temperature — an integer from 1 to 109. Exactly two of these icicles are special: their temperature is *y*, while a temperature of all the others is *x* ≠ *y*. You have to find those special icicles. You can choose a non-empty subset of icicles and ask the penguin what is the bitwise exclusive OR (XOR) of the temperatures of the icicles in this subset. ## Note

 that you can't ask more than 19 questions.

You are to find the special icicles.

## Input

The first line contains three integers *n*, *x*, *y* (2 ≤ *n* ≤ 1000, 1 ≤ *x*, *y* ≤ 109, *x* ≠ *y*) — the number of icicles, the temperature of non-special icicles and the temperature of the special icicles.

## Output

To give your answer to the penguin you have to print character "!" (without quotes), then print two integers *p*1, *p*2 (*p*1 < *p*2) — the indexes of the special icicles in ascending order. ## Note

 that "!" and *p*1 should be separated by a space; the indexes should be separated by a space too. After you gave the answer your program should terminate immediately.

## Interaction

To ask a question print character "?" (without quotes), an integer *c* (1 ≤ *c* ≤ *n*), and *c* distinct integers *p*1, *p*2, ..., *p**c* (1 ≤ *p**i* ≤ *n*) — the indexes of icicles that you want to know about. ## Note

 that "?" and *c* should be separated by a space; the indexes should be separated by a space too.

After you asked the question, read a single integer — the answer.

## Note

 that you can't ask more than 19 questions. If you ask more than 19 questions or at least one incorrect question, your solution will get "Wrong answer".

If at some moment your program reads  - 1 as an answer, it should immediately exit (for example, by calling exit(0)). You will get "Wrong answer" in this case, it means that you asked more than 19 questions, or asked an invalid question. If you ignore this, you can get other verdicts since your program will continue to read from a closed stream.

Your solution will get "Idleness Limit Exceeded", if you don't print anything or forget to flush the output, including for the final answer .

To flush you can use (just after printing): 

* fflush(stdout) in C++;
* System.out.flush() in Java;
* stdout.flush() in Python;
* flush(output) in Pascal;
* For other languages see the documentation.

Hacking

For hacking use the following format:

*n* *x* *y* *p*1 *p*2

Here 1 ≤ *p*1 < *p*2 ≤ *n* are the indexes of the special icicles.

Contestant programs will not be able to see this input.

## Example

## Input


```
4 2 1  
2  
1  
1
```
## Output


```
? 3 1 2 3  
? 1 1  
? 1 3  
! 1 3
```
## Note

The answer for the first question is ![](images/b32d8d96beb0d2be8d8a600f458c8cf2e2e28c54.png).

The answer for the second and the third questions is 1, therefore, special icicles are indexes 1 and 3.

You can read more about bitwise XOR operation here: [https://en.wikipedia.org/wiki/Bitwise_operation#XOR](https://en.wikipedia.org/wiki/Bitwise_operation#XOR).



#### tags 

#2400 #binary_search #constructive_algorithms #interactive 