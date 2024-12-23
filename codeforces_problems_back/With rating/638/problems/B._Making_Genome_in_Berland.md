<h1 style='text-align: center;'> B. Making Genome in Berland</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Berland scientists face a very important task - given the parts of short DNA fragments, restore the dinosaur DNA! The genome of a berland dinosaur has noting in common with the genome that we've used to: it can have 26 distinct nucleotide types, a nucleotide of each type can occur at most once. If we assign distinct English letters to all nucleotides, then the genome of a Berland dinosaur will represent a non-empty string consisting of small English letters, such that each letter occurs in it at most once.

Scientists have *n* genome fragments that are represented as substrings (non-empty sequences of consecutive nucleotides) of the sought genome.

You face the following problem: help scientists restore the dinosaur genome. It is guaranteed that the input is not contradictory and at least one suitable line always exists. When the scientists found out that you are a strong programmer, they asked you in addition to choose the one with the minimum length. If there are multiple such strings, choose any string.

## Input

The first line of the input contains a positive integer *n* (1 ≤ *n* ≤ 100) — the number of genome fragments.

Each of the next lines contains one descriptions of a fragment. Each fragment is a non-empty string consisting of distinct small letters of the English alphabet. It is not guaranteed that the given fragments are distinct. Fragments could arbitrarily overlap and one fragment could be a substring of another one.

It is guaranteed that there is such string of distinct letters that contains all the given fragments as substrings.

## Output

In the single line of the output print the genome of the minimum length that contains all the given parts. All the nucleotides in the genome must be distinct. If there are multiple suitable strings, print the string of the minimum length. If there also are multiple suitable strings, you can print any of them.

## Examples

## Input


```
3  
bcd  
ab  
cdef  

```
## Output


```
abcdef  

```
## Input


```
4  
x  
y  
z  
w  

```
## Output


```
xyzw  

```


#### tags 

#1500 #*special #dfs_and_similar #strings 