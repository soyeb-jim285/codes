<h1 style='text-align: center;'> D. Brand New Problem</h1>

<h5 style='text-align: center;'>time limit per test: 5 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

A widely known among some people Belarusian sport programmer Lesha decided to make some money to buy a one square meter larger flat. To do this, he wants to make and carry out a Super Rated Match (SRM) on the site Torcoder.com. But there's a problem — a severe torcoder coordinator Ivan does not accept any Lesha's problem, calling each of them an offensive word "duped" (that is, duplicated). And one day they nearely quarrelled over yet another problem Ivan wouldn't accept.

You are invited to act as a fair judge and determine whether the problem is indeed brand new, or Ivan is right and the problem bears some resemblance to those used in the previous SRMs.

You are given the descriptions of Lesha's problem and each of Torcoder.com archive problems. The description of each problem is a sequence of words. Besides, it is guaranteed that Lesha's problem has no repeated words, while the description of an archive problem may contain any number of repeated words.

The "similarity" between Lesha's problem and some archive problem can be found as follows. Among all permutations of words in Lesha's problem we choose the one that occurs in the archive problem as a subsequence. If there are multiple such permutations, we choose the one with the smallest number of inversions. Then the "similarity" of a problem can be written as ![](images/e030ac55efb4d1b310573b6c32117d80ccefc0fd.png), where *n* is the number of words in Lesha's problem and *x* is the number of inversions in the chosen permutation. ## Note

 that the "similarity" *p* is always a positive integer.

The problem is called brand new if there is not a single problem in Ivan's archive which contains a permutation of words from Lesha's problem as a subsequence.

Help the boys and determine whether the proposed problem is new, or specify the problem from the archive which resembles Lesha's problem the most, otherwise.

## Input

The first line contains a single integer *n* (1 ≤ *n* ≤ 15) — the number of words in Lesha's problem. The second line contains *n* space-separated words — the short description of the problem.

The third line contains a single integer *m* (1 ≤ *m* ≤ 10) — the number of problems in the Torcoder.com archive. Next *m* lines contain the descriptions of the problems as "*k* *s*1 *s*2 ... *s**k*", where *k* (1 ≤ *k* ≤ 500000) is the number of words in the problem and *s**i* is a word of the problem description.

All words from all problem descriptions contain no more than 10 lowercase English letters. It is guaranteed that the total length of words in all problem descriptions does not exceed 500015.

## Output

If Lesha's problem is brand new, print string "Brand new problem!" (without quotes). 

Otherwise, on the first line print the index of the archive problem which resembles Lesha's problem most. If there are multiple such problems, print the one with the smallest index. On the second line print a string consisting of characters [:, character | repeated *p* times, and characters :], where *p* is the "similarity" between this problem and Lesha's one. The archive problems are numbered starting from one in the order in which they are given in the input.

## Examples

## Input


```
4  
find the next palindrome  
1  
10 find the previous palindrome or print better luck next time  

```
## Output


```
1  
[:||||||:]  

```
## Input


```
3  
add two numbers  
3  
1 add  
2 two two  
3 numbers numbers numbers  

```
## Output


```
Brand new problem!  

```
## Input


```
4  
these papers are formulas  
3  
6 what are these formulas and papers  
5 papers are driving me crazy  
4 crazy into the night  

```
## Output


```
1  
[:||||:]  

```
## Input


```
3  
add two decimals  
5  
4 please two decimals add  
5 decimals want to be added  
4 two add decimals add  
4 add one two three  
7 one plus two plus three equals six  

```
## Output


```
3  
[:|||:]  

```
## Note

Let us remind you that the number of inversions is the number of pairs of words that follow in the permutation not in their original order. Thus, for example, if the original problem is "add two numbers", then permutation "numbers add two" contains two inversions — pairs of words "numbers" and "add", "numbers" and "two". 

Sequence *b*1,  *b*2,  ...,  *b**k* is a subsequence of sequence *a*1, *a*2,  ...,  *a**n* if there exists such a set of indices 1 ≤ *i*1 <  *i*2 < ...   < *i**k* ≤ *n* that *a**i**j*  =  *b**j* (in other words, if sequence *b* can be obtained from *a* by deleting some of its elements).

In the first test case the first problem contains the "find the palindrome next" permutation as a subsequence, in which the number of inversions equals 1 (words "palindrome" and "next").

In the second test case there is no problem that contains a permutation of words from Lesha's problem as a subsequence.



#### tags 

#2600 #bitmasks #brute_force #dp 