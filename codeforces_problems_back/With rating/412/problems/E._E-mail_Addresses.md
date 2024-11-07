<h1 style='text-align: center;'> E. E-mail Addresses</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

One of the most important products of the R1 company is a popular @r1.com mail service. The R1 mailboxes receive and send millions of emails every day.

Today, the online news thundered with terrible information. The R1 database crashed and almost no data could be saved except for one big string. The developers assume that the string contains the letters of some users of the R1 mail. Recovering letters is a tedious mostly manual work. So before you start this process, it was decided to estimate the difficulty of recovering. Namely, we need to calculate the number of different substrings of the saved string that form correct e-mail addresses.

We assume that valid addresses are only the e-mail addresses which meet the following criteria:

* the address should begin with a non-empty sequence of letters, numbers, characters '_', starting with a letter;
* then must go character '@';
* then must go a non-empty sequence of letters or numbers;
* then must go character '.';
* the address must end with a non-empty sequence of letters.

You got lucky again and the job was entrusted to you! Please note that the substring is several consecutive characters in a string. Two substrings, one consisting of the characters of the string with numbers *l*1, *l*1 + 1, *l*1 + 2, ..., *r*1 and the other one consisting of the characters of the string with numbers *l*2, *l*2 + 1, *l*2 + 2, ..., *r*2, are considered distinct if *l*1 ≠ *l*2 or *r*1 ≠ *r*2.

## Input

The first and the only line contains the sequence of characters *s*1*s*2... *s**n* (1 ≤ *n* ≤ 106) — the saved string. It is guaranteed that the given string contains only small English letters, digits and characters '.', '_', '@'.

## Output

Print in a single line the number of substrings that are valid e-mail addresses.

## Examples

## Input


```
[[email protected]](/cdn-cgi/l/email-protection)  

```
## Output


```
18  

```
## Input


```
[[email protected]](/cdn-cgi/l/email-protection)@[[email protected]](/cdn-cgi/l/email-protection)  

```
## Output


```
8  

```
## Input


```
[[email protected]](/cdn-cgi/l/email-protection)  

```
## Output


```
1  

```
## Input


```
.asd123__..@  

```
## Output


```
0  

```
## Note

In the first test case all the substrings that are correct e-mail addresses begin from one of the letters of the word agapov and end in one of the letters of the word com.

In the second test case note that the e-mail [[email protected]](/cdn-cgi/l/email-protection) is considered twice in the answer. ## Note

 that in this example the e-mail entries overlap inside the string.



#### tags 

#1900 #implementation 