<h1 style='text-align: center;'> C. Genetic engineering</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

"Multidimensional spaces are completely out of style these days, unlike genetics problems" — thought physicist Woll and changed his subject of study to bioinformatics. Analysing results of sequencing he faced the following problem concerning DNA sequences. We will further think of a DNA sequence as an arbitrary string of uppercase letters "A", "C", "G" and "T" (of course, this is a simplified interpretation).

Let *w* be a long DNA sequence and *s*1, *s*2, ..., *s**m* — collection of short DNA sequences. Let us say that the collection filters *w* iff *w* can be covered with the sequences from the collection. Certainly, substrings corresponding to the different positions of the string may intersect or even cover each other. More formally: denote by |*w*| the length of *w*, let symbols of *w* be numbered from 1 to |*w*|. Then for each position *i* in *w* there exist pair of indices *l*, *r* (1 ≤ *l* ≤ *i* ≤ *r* ≤ |*w*|) such that the substring *w*[*l* ... *r*] equals one of the elements *s*1, *s*2, ..., *s**m* of the collection.

Woll wants to calculate the number of DNA sequences of a given length filtered by a given collection, but he doesn't know how to deal with it. Help him! Your task is to find the number of different DNA sequences of length *n* filtered by the collection {*s**i*}.

Answer may appear very large, so output it modulo 1000000009.

## Input

First line contains two integer numbers *n* and *m* (1 ≤ *n* ≤ 1000, 1 ≤ *m* ≤ 10) — the length of the string and the number of sequences in the collection correspondently. 

Next *m* lines contain the collection sequences *s**i*, one per line. Each *s**i* is a nonempty string of length not greater than 10. All the strings consist of uppercase letters "A", "C", "G", "T". The collection may contain identical strings.

## Output

## Output

 should contain a single integer — the number of strings filtered by the collection modulo 1000000009 (109 + 9).

## Examples

## Input


```
2 1  
A  

```
## Output


```
1  

```
## Input


```
6 2  
CAT  
TACT  

```
## Output


```
2  

```
## Note

In the first sample, a string has to be filtered by "A". Clearly, there is only one such string: "AA".

In the second sample, there exist exactly two different strings satisfying the condition (see the pictures below).

 ![](images/c4efd5e2d2d17fab9f2f5b4cf0753e695a7768f9.png)  ![](images/b6d1d71ada81e95de0ea8b3af99918c7e77082c4.png) 

#### tags 

#2500 #dp #string_suffix_structures #trees 