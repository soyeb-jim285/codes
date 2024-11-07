<h1 style='text-align: center;'> A. Romaji</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Vitya has just started learning Berlanese language. It is known that Berlanese uses the Latin alphabet. Vowel letters are "a", "o", "u", "i", and "e". Other letters are consonant.

In Berlanese, there has to be a vowel after every consonant, but there can be any letter after any vowel. The only exception is a consonant "n"; after this letter, there can be any letter (not only a vowel) or there can be no letter at all. For example, the words "harakiri", "yupie", "man", and "nbo" are Berlanese while the words "horse", "king", "my", and "nz" are not.

Help Vitya find out if a word $s$ is Berlanese.

##### Input

The first line of the input contains the string $s$ consisting of $|s|$ ($1\leq |s|\leq 100$) lowercase Latin letters.

##### Output

Print "YES" (without quotes) if there is a vowel after every consonant except "n", otherwise print "NO".

You can print each letter in any case (upper or lower).

## Examples

##### Input


```text
sumimasen  

```
##### Output


```text
YES  

```
##### Input


```text
ninja  

```
##### Output


```text
YES  

```
##### Input


```text
codeforces  

```
##### Output


```text
NO  

```
## Note

In the first and second samples, a vowel goes after each consonant except "n", so the word is Berlanese.

In the third sample, the consonant "c" goes after the consonant "r", and the consonant "s" stands on the end, so the word is not Berlanese.



#### Tags 

#900 #OK #implementation #strings 

## Blogs
- [All Contest Problems](../Codeforces_Round_497_(Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
