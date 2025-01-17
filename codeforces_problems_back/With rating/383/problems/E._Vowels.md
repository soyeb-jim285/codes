<h1 style='text-align: center;'> E. Vowels</h1>

<h5 style='text-align: center;'>time limit per test: 4 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Iahubina is tired of so many complicated languages, so she decided to invent a new, simple language. She already made a dictionary consisting of *n* 3-words. A 3-word is a sequence of exactly 3 lowercase letters of the first 24 letters of the English alphabet (*a* to *x*). She decided that some of the letters are vowels, and all the others are consonants. The whole language is based on a simple rule: any word that contains at least one vowel is correct.

Iahubina forgot which letters are the vowels, and wants to find some possible correct sets of vowels. She asks Iahub questions. In each question, she will give Iahub a set of letters considered vowels (in this question). For each question she wants to know how many words of the dictionary are correct, considering the given set of vowels.

Iahubina wants to know the *xor* of the squared answers to all the possible questions. There are 224 different questions, they are all subsets of the set of the first 24 letters of the English alphabet. Help Iahub find that number.

## Input

The first line contains one integer, *n* (1 ≤ *n* ≤ 104). Each of the next *n* lines contains a 3-word consisting of 3 lowercase letters. There will be no two identical 3-words.

## Output

Print one number, the *xor* of the squared answers to the queries.

## Examples

## Input


```
5  
abc  
aaa  
ada  
bcd  
def  

```
## Output


```
0  

```


#### tags 

#2700 #combinatorics #divide_and_conquer #dp 