<h1 style='text-align: center;'> C. Downloading B++</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Only *T* milliseconds left before the start of well-known online programming contest Codehorses Round 2017.

Polycarp needs to download B++ compiler to take part in the contest. The size of the file is *f* bytes.

Polycarp's internet tariff allows to download data at the rate of one byte per *t*0 milliseconds. This tariff is already prepaid, and its use does not incur any expense for Polycarp. In addition, the Internet service provider offers two additional packages:

* download *a*1 bytes at the rate of one byte per *t*1 milliseconds, paying *p*1 burles for the package;
* download *a*2 bytes at the rate of one byte per *t*2 milliseconds, paying *p*2 burles for the package.

Polycarp can buy any package many times. When buying a package, its price (*p*1 or *p*2) is prepaid before usage. Once a package is bought it replaces the regular tariff until package data limit is completely used. After a package is consumed Polycarp can immediately buy a new package or switch to the regular tariff without loosing any time. While a package is in use Polycarp can't buy another package or switch back to the regular internet tariff.

Find the minimum amount of money Polycarp has to spend to download an *f* bytes file no more than in *T* milliseconds.

## Note

 that because of technical reasons Polycarp can download only integer number of bytes using regular tariff and both packages. I.e. in each of three downloading modes the number of downloaded bytes will be integer. It means that Polycarp can't download a byte partially using the regular tariff or/and both packages.

## Input

The first line contains three integer numbers *f*, *T* and *t*0 (1 ≤ *f*, *T*, *t*0 ≤ 107) — size of the file to download (in bytes), maximal time to download the file (in milliseconds) and number of milliseconds to download one byte using the regular internet tariff.

The second line contains a description of the first additional package. The line contains three integer numbers *a*1, *t*1 and *p*1 (1 ≤ *a*1, *t*1, *p*1 ≤ 107), where *a*1 is maximal sizes of downloaded data (in bytes), *t*1 is time to download one byte (in milliseconds), *p*1 is price of the package (in burles).

The third line contains a description of the second additional package. The line contains three integer numbers *a*2, *t*2 and *p*2 (1 ≤ *a*2, *t*2, *p*2 ≤ 107), where *a*2 is maximal sizes of downloaded data (in bytes), *t*2 is time to download one byte (in milliseconds), *p*2 is price of the package (in burles).

Polycarp can buy any package many times. Once package is bought it replaces the regular tariff until package data limit is completely used. While a package is in use Polycarp can't buy another package or switch back to the regular internet tariff.

## Output

Print the minimum amount of money that Polycarp needs to pay to download B++ compiler no more than in *T* milliseconds. If there is no solution, print the only integer -1.

## Examples

## Input


```
120 964 20  
26 8 8  
13 10 4  

```
## Output


```
40  

```
## Input


```
10 200 20  
1 1 1  
2 2 3  

```
## Output


```
0  

```
## Input


```
8 81 11  
4 10 16  
3 10 12  

```
## Output


```
28  

```
## Input


```
8 79 11  
4 10 16  
3 10 12  

```
## Output


```
-1  

```
## Note

In the first example Polycarp has to buy the first additional package 5 times and do not buy the second additional package. He downloads 120 bytes (of total 26·5 = 130 bytes) in 120·8 = 960 milliseconds (960 ≤ 964). He spends 8·5 = 40 burles on it.

In the second example Polycarp has enough time to download 10 bytes. It takes 10·20 = 200 milliseconds which equals to upper constraint on download time.

In the third example Polycarp has to buy one first additional package and one second additional package.

In the fourth example Polycarp has no way to download the file on time.



#### tags 

#2300 #binary_search #implementation 