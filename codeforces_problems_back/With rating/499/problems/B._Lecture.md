<h1 style='text-align: center;'> B. Lecture</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You have a new professor of graph theory and he speaks very quickly. You come up with the following plan to keep up with his lecture and make notes.

You know two languages, and the professor is giving the lecture in the first one. The words in both languages consist of lowercase English characters, each language consists of several words. For each language, all words are distinct, i.e. they are spelled differently. Moreover, the words of these languages have a one-to-one correspondence, that is, for each word in each language, there exists exactly one word in the other language having has the same meaning.

You can write down every word the professor says in either the first language or the second language. Of course, during the lecture you write down each word in the language in which the word is shorter. In case of equal lengths of the corresponding words you prefer the word of the first language.

You are given the text of the lecture the professor is going to read. Find out how the lecture will be recorded in your notes.

## Input

The first line contains two integers, *n* and *m* (1 ≤ *n* ≤ 3000, 1 ≤ *m* ≤ 3000) — the number of words in the professor's lecture and the number of words in each of these languages.

The following *m* lines contain the words. The *i*-th line contains two strings *a**i*, *b**i* meaning that the word *a**i* belongs to the first language, the word *b**i* belongs to the second language, and these two words have the same meaning. It is guaranteed that no word occurs in both languages, and each word occurs in its language exactly once.

The next line contains *n* space-separated strings *c*1, *c*2, ..., *c**n* — the text of the lecture. It is guaranteed that each of the strings *c**i* belongs to the set of strings {*a*1, *a*2, ... *a**m*}.

All the strings in the input are non-empty, each consisting of no more than 10 lowercase English letters.

## Output

## Output

 exactly *n* words: how you will record the lecture in your notebook. ## Output

 the words of the lecture in the same order as in the input.

## Examples

## Input


```
4 3  
codeforces codesecrof  
contest round  
letter message  
codeforces contest letter contest  

```
## Output


```
codeforces round letter round  

```
## Input


```
5 3  
joll wuqrd  
euzf un  
hbnyiyc rsoqqveh  
hbnyiyc joll joll euzf joll  

```
## Output


```
hbnyiyc joll joll un joll  

```


#### tags 

#1000 #implementation #strings 