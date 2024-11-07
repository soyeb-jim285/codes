<h1 style='text-align: center;'> A. Flying Saucer Segments</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

An expedition group flew from planet ACM-1 to Earth in order to study the bipedal species (its representatives don't even have antennas on their heads!).

The flying saucer, on which the brave pioneers set off, consists of three sections. These sections are connected by a chain: the 1-st section is adjacent only to the 2-nd one, the 2-nd one — to the 1-st and the 3-rd ones, the 3-rd one — only to the 2-nd one. The transitions are possible only between the adjacent sections.

The spacecraft team consists of *n* aliens. Each of them is given a rank — an integer from 1 to *n*. The ranks of all astronauts are distinct. The rules established on the Saucer, state that an alien may move from section *a* to section *b* only if it is senior in rank to all aliens who are in the segments *a* and *b* (besides, the segments *a* and *b* are of course required to be adjacent). Any alien requires exactly 1 minute to make a move. Besides, safety regulations require that no more than one alien moved at the same minute along the ship.

Alien *A* is senior in rank to alien *B*, if the number indicating rank *A*, is more than the corresponding number for *B*.

At the moment the whole saucer team is in the 3-rd segment. They all need to move to the 1-st segment. One member of the crew, the alien with the identification number CFR-140, decided to calculate the minimum time (in minutes) they will need to perform this task.

Help CFR-140, figure out the minimum time (in minutes) that all the astronauts will need to move from the 3-rd segment to the 1-st one. Since this number can be rather large, count it modulo *m*.

## Input

The first line contains two space-separated integers: *n* and *m* (1 ≤ *n*, *m* ≤ 109) — the number of aliens on the saucer and the number, modulo which you should print the answer, correspondingly.

## Output

Print a single number — the answer to the problem modulo *m*.

## Examples

## Input


```
1 10  

```
## Output


```
2  

```
## Input


```
3 8  

```
## Output


```
2  

```
## Note

In the first sample the only crew member moves from segment 3 to segment 2, and then from segment 2 to segment 1 without any problems. Thus, the whole moving will take two minutes.

To briefly describe the movements in the second sample we will use value ![](images/4c7c8e716067e9c6251e8ca82a4ca7fde74fbacb.png), which would correspond to an alien with rank *i* moving from the segment in which it is at the moment, to the segment number *j*. Using these values, we will describe the movements between the segments in the second sample: ![](images/7668900e59f9bc3ccc78b0a77dca322fcb02fa04.png), ![](images/1adb8798904e42944c35bd49feff02db6c3ea10b.png), ![](images/954e2f634474269f53df1edbf2e7b214d8a2611c.png), ![](images/7668900e59f9bc3ccc78b0a77dca322fcb02fa04.png), ![](images/be5f59dacfc6f7ded42f8f260c7b7aedf17ec1f0.png), ![](images/d4fd9e68a9c6a277942eb188291d6d2744ea21d3.png), ![](images/7668900e59f9bc3ccc78b0a77dca322fcb02fa04.png), ![](images/1adb8798904e42944c35bd49feff02db6c3ea10b.png), ![](images/b73a9870e1b41a5e048c3ab3e3fd4b92c336c9ec.png), ![](images/7668900e59f9bc3ccc78b0a77dca322fcb02fa04.png), ![](images/be5f59dacfc6f7ded42f8f260c7b7aedf17ec1f0.png), ![](images/954e2f634474269f53df1edbf2e7b214d8a2611c.png), ![](images/7668900e59f9bc3ccc78b0a77dca322fcb02fa04.png), ![](images/1adb8798904e42944c35bd49feff02db6c3ea10b.png), ![](images/49b1ffd4dcd2e0da0acec04559e0c3efc7854b07.png), ![](images/7668900e59f9bc3ccc78b0a77dca322fcb02fa04.png), ![](images/be5f59dacfc6f7ded42f8f260c7b7aedf17ec1f0.png), ![](images/ef8b3f32ee76c86f57fa63f7251fa290642f17f8.png), ![](images/7668900e59f9bc3ccc78b0a77dca322fcb02fa04.png), ![](images/1adb8798904e42944c35bd49feff02db6c3ea10b.png), ![](images/954e2f634474269f53df1edbf2e7b214d8a2611c.png), ![](images/7668900e59f9bc3ccc78b0a77dca322fcb02fa04.png), ![](images/be5f59dacfc6f7ded42f8f260c7b7aedf17ec1f0.png), ![](images/d4fd9e68a9c6a277942eb188291d6d2744ea21d3.png), ![](images/7668900e59f9bc3ccc78b0a77dca322fcb02fa04.png), ![](images/1adb8798904e42944c35bd49feff02db6c3ea10b.png); In total: the aliens need 26 moves. The remainder after dividing 26 by 8 equals 2, so the answer to this test is 2.



#### tags 

#1400 #math 