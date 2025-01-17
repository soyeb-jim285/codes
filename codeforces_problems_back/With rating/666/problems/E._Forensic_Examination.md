<h1 style='text-align: center;'> E. Forensic Examination</h1>

<h5 style='text-align: center;'>time limit per test: 6 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 768 megabytes</h5>

The country of Reberland is the archenemy of Berland. Recently the authorities of Berland arrested a Reberlandian spy who tried to bring the leaflets intended for agitational propaganda to Berland illegally . The most leaflets contain substrings of the Absolutely Inadmissible Swearword and maybe even the whole word.

Berland legal system uses the difficult algorithm in order to determine the guilt of the spy. The main part of this algorithm is the following procedure.

All the *m* leaflets that are brought by the spy are numbered from 1 to *m*. After that it's needed to get the answer to *q* queries of the following kind: "In which leaflet in the segment of numbers [*l*, *r*] the substring of the Absolutely Inadmissible Swearword [*p**l*, *p**r*] occurs more often?".

The expert wants you to automate that procedure because this time texts of leaflets are too long. Help him!

## Input

The first line contains the string *s* (1 ≤ |*s*| ≤ 5·105) — the Absolutely Inadmissible Swearword. The string *s* consists of only lowercase English letters.

The second line contains the only integer *m* (1 ≤ *m* ≤ 5·104) — the number of texts of leaflets for expertise.

Each of the next *m* lines contains the only string *t**i* — the text of the *i*-th leaflet. The sum of lengths of all leaflet texts doesn't exceed 5·104. The text of the leaflets consists of only lowercase English letters.

The next line contains integer *q* (1 ≤ *q* ≤ 5·105) — the number of queries for expertise.

Finally, each of the last *q* lines contains four integers *l*, *r*, *p**l*, *p**r* (1 ≤ *l* ≤ *r* ≤ *m*, 1 ≤ *p**l* ≤ *p**r* ≤ |*s*|), where |*s*| is the length of the Absolutely Inadmissible Swearword.

## Output

Print *q* lines. The *i*-th of them should contain two integers — the number of the text with the most occurences and the number of occurences of the substring [*p**l*, *p**r*] of the string *s*. If there are several text numbers print the smallest one.

## Examples

## Input


```
suffixtree  
3  
suffixtreesareawesome  
cartesiantreeisworsethansegmenttree  
nyeeheeheee  
2  
1 2 1 10  
1 3 9 10  

```
## Output


```
1 1  
3 4  

```


#### tags 

#3100 #data_structures #string_suffix_structures 