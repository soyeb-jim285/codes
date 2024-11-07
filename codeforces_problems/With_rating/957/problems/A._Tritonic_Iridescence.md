<h1 style='text-align: center;'> A. Tritonic Iridescence</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Overlooking the captivating blend of myriads of vernal hues, Arkady the painter lays out a long, long canvas.

Arkady has a sufficiently large amount of paint of three colours: cyan, magenta, and yellow. On the one-dimensional canvas split into *n* consecutive segments, each segment needs to be painted in one of the colours.

Arkady has already painted some (possibly none or all) segments and passes the paintbrush to you. You are to determine whether there are at least two ways of colouring all the unpainted segments so that no two adjacent segments are of the same colour. Two ways are considered different if and only if a segment is painted in different colours in them.

####### Input

The first line contains a single positive integer *n* (1 ≤ *n* ≤ 100) — the length of the canvas.

The second line contains a string *s* of *n* characters, the *i*-th of which is either 'C' (denoting a segment painted in cyan), 'M' (denoting one painted in magenta), 'Y' (one painted in yellow), or '?' (an unpainted one).

####### Output

If there are at least two different ways of painting, output "Yes"; otherwise output "No" (both without quotes).

You can print each character in any case (upper or lower).

## Examples

####### Input


```text
5  
CY??Y  

```
####### Output


```text
Yes  

```
####### Input


```text
5  
C?C?Y  

```
####### Output


```text
Yes  

```
####### Input


```text
5  
?CYC?  

```
####### Output


```text
Yes  

```
####### Input


```text
5  
C??MM  

```
####### Output


```text
No  

```
####### Input


```text
3  
MMY  

```
####### Output


```text
No  

```
## Note

For the first example, there are exactly two different ways of colouring: CYCMY and CYMCY.

For the second example, there are also exactly two different ways of colouring: CMCMY and CYCMY.

For the third example, there are four ways of colouring: MCYCM, MCYCY, YCYCM, and YCYCY.

For the fourth example, no matter how the unpainted segments are coloured, the existing magenta segments will prevent the painting from satisfying the requirements. The similar is true for the fifth example.



#### Tags 

#1300 #NOT OK #implementation 

## Blogs
- [All Contest Problems](../Codeforces_Round_472_(rated,_Div._2,_based_on_VK_Cup_2018_Round_2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
