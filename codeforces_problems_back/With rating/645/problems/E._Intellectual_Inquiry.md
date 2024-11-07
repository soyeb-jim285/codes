<h1 style='text-align: center;'> E. Intellectual Inquiry</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

After getting kicked out of her reporting job for not knowing the alphabet, Bessie has decided to attend school at the Fillet and Eggs Eater Academy. She has been making good progress with her studies and now knows the first *k* English letters.

Each morning, Bessie travels to school along a sidewalk consisting of *m* + *n* tiles. In order to help Bessie review, Mr. Moozing has labeled each of the first *m* sidewalk tiles with one of the first *k* lowercase English letters, spelling out a string *t*. Mr. Moozing, impressed by Bessie's extensive knowledge of farm animals, plans to let her finish labeling the last *n* tiles of the sidewalk by herself.

Consider the resulting string *s* (|*s*| = *m* + *n*) consisting of letters labeled on tiles in order from home to school. For any sequence of indices *p*1 < *p*2 < ... < *p**q* we can define subsequence of the string *s* as string *s**p*1*s**p*2... *s**p**q*. Two subsequences are considered to be distinct if they differ as strings. Bessie wants to label the remaining part of the sidewalk such that the number of distinct subsequences of tiles is maximum possible. However, since Bessie hasn't even finished learning the alphabet, she needs your help!

## Note

 that empty subsequence also counts.

## Input

The first line of the input contains two integers *n* and *k* (0 ≤ *n* ≤ 1 000 000, 1 ≤ *k* ≤ 26).

The second line contains a string *t* (|*t*| = *m*, 1 ≤ *m* ≤ 1 000 000) consisting of only first *k* lowercase English letters.

## Output

Determine the maximum number of distinct subsequences Bessie can form after labeling the last *n* sidewalk tiles each with one of the first *k* lowercase English letters. Since this number can be rather large, you should print it modulo 109 + 7.

Please note, that you are not asked to maximize the remainder modulo 109 + 7! The goal is to maximize the initial value and then print the remainder.

## Examples

## Input


```
1 3  
ac  

```
## Output


```
8  

```
## Input


```
0 2  
aaba  

```
## Output


```
10  

```
## Note

In the first sample, the optimal labeling gives 8 different subsequences: "" (the empty string), "a", "c", "b", "ac", "ab", "cb", and "acb".

 ![](images/7f3d59a722caecf7578480b7bd3acab5a87a2802.png) In the second sample, the entire sidewalk is already labeled. The are 10 possible different subsequences: "" (the empty string), "a", "b", "aa", "ab", "ba", "aaa", "aab", "aba", and "aaba". ## Note

 that some strings, including "aa", can be obtained with multiple sequences of tiles, but are only counted once.



#### tags 

#2200 #dp #greedy #strings 