<h1 style='text-align: center;'> B. Toys</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Vittorio has three favorite toys: a teddy bear, an owl, and a raccoon. Each of them has a name. 

Vittorio takes several sheets of paper and writes a letter on each side of every sheet so that it is possible to spell any of the three names by arranging some of the sheets in a row (sheets can be reordered and flipped as needed). The three names do not have to be spelled at the same time, it is sufficient that it is possible to spell each of them using all the available sheets (and the same sheet can be used to spell different names).

Find the minimum number of sheets required. In addition, produce a list of sheets with minimum cardinality which can be used to spell the three names (if there are multiple answers, print any).

##### Input

The first line contains a string $t$ consisting of uppercase letters of the English alphabet ($1\le |t| \le 1000$) — the name of the teddy bear.

The second line contains a string $o$ consisting of uppercase letters of the English alphabet ($1\le |o| \le 1000$) — the name of the owl.

The third line contains a string $r$ consisting of uppercase letters of the English alphabet ($1\le |r| \le 1000$) — the name of the raccoon.

The values $|t|$, $|o|$, $|r|$ denote the length of the three names $t$, $o$, $r$.

##### Output

The first line of the output contains a single integer $m$ — the minimum number of sheets required.

Then $m$ lines follow: the $j$-th of these lines contains a string of two uppercase letters of the English alphabet — the letters appearing on the two sides of the $j$-th sheet.

## Note

 that you can print the sheets and the two letters of each sheet in any order.

## Examples

##### Input


```text
AA
GA
MA
```
##### Output


```text
2
AG
AM
```
##### Input


```text
TEDDY
HEDWIG
RACCOON
```
##### Output


```text
8
AT
CH
CY
DG
DO
ER
IN
OW
```
##### Input


```text
BDC
CAA
CE
```
##### Output


```text
4
AD
AE
BB
CC
```
## Note

In the first sample, the solution uses two sheets: the first sheet has A on one side and G on the other side; the second sheet has A on one side and M on the other side.

The name AA can be spelled using the A side of both sheets. The name GA can be spelled using the G side of the first sheet and the A side of the second sheet. Finally, the name MA can be spelled using the M side of the second sheet and the A side of the first sheet.



#### Tags 

#NOT OK #greedy #strings 

## Blogs
- [All Contest Problems](../SWERC_2021-2022_-_Online_Mirror_(Unrated,_ICPC_Rules,_Teams_Preferred).md)
- [SWERC 2021-2022 (en)](../blogs/SWERC_2021-2022_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
