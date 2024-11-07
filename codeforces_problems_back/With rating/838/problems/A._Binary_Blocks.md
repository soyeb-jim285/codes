<h1 style='text-align: center;'> A. Binary Blocks</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given an image, that can be represented with a 2-d *n* by *m* grid of pixels. Each pixel of the image is either on or off, denoted by the characters "0" or "1", respectively. You would like to compress this image. You want to choose an integer *k* > 1 and split the image into *k* by *k* blocks. If *n* and *m* are not divisible by *k*, the image is padded with only zeros on the right and bottom so that they are divisible by *k*. Each pixel in each individual block must have the same value. The given image may not be compressible in its current state. Find the minimum number of pixels you need to toggle (after padding) in order for the image to be compressible for some *k*. More specifically, the steps are to first choose *k*, then the image is padded with zeros, then, we can toggle the pixels so it is compressible for this *k*. The image must be compressible in that state.

## Input

The first line of input will contain two integers *n*, *m* (2 ≤ *n*, *m* ≤ 2 500), the dimensions of the image.

The next *n* lines of input will contain a binary string with exactly *m* characters, representing the image.

## Output

Print a single integer, the minimum number of pixels needed to toggle to make the image compressible.

## Example

## Input


```
3 5  
00100  
10110  
11001  

```
## Output


```
5  

```
## Note

We first choose *k* = 2.

The image is padded as follows: 


```
  
001000  
101100  
110010  
000000  

```
We can toggle the image to look as follows: 


```
  
001100  
001100  
000000  
000000  

```
We can see that this image is compressible for *k* = 2.



#### tags 

#1400 #brute_force 