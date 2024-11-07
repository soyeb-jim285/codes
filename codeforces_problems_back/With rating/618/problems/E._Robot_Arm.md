<h1 style='text-align: center;'> E. Robot Arm</h1>

<h5 style='text-align: center;'>time limit per test: 8 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Roger is a robot. He has an arm that is a series of *n* segments connected to each other. The endpoints of the *i*-th segment are initially located at points (*i* - 1, 0) and (*i*, 0). The endpoint at (*i* - 1, 0) is colored red and the endpoint at (*i*, 0) is colored blue for all segments. Thus, the blue endpoint of the *i*-th segment is touching the red endpoint of the (*i* + 1)-th segment for all valid *i*.

Roger can move his arm in two different ways: 

1. He can choose some segment and some value. This is denoted as choosing the segment number *i* and picking some positive *l*. This change happens as follows: the red endpoint of segment number *i* and segments from 1 to *i* - 1 are all fixed in place. Imagine a ray from the red endpoint to the blue endpoint. The blue endpoint and segments *i* + 1 through *n* are translated *l* units in the direction of this ray. ![](images/769987a159a15f789d8dfadd21afd6962a4b6ab4.png) ![](images/8230df8d2db49480879838aaf9b7a0499ca13a26.png) In this picture, the red point labeled *A* and segments before *A* stay in place, while the blue point labeled *B* and segments after *B* gets translated.
2. He can choose a segment and rotate it. This is denoted as choosing the segment number *i*, and an angle *a*. The red endpoint of the *i*-th segment will stay fixed in place. The blue endpoint of that segment and segments *i* + 1 to *n* will rotate clockwise by an angle of *a* degrees around the red endpoint. ![](images/df42fd9d157dc3768a32050a3da73125660b9bf2.png) ![](images/fb86077c0618f477f341925571b872a78c0b1742.png) In this picture, the red point labeled *A* and segments before *A* stay in place, while the blue point labeled *B* and segments after *B* get rotated around point *A*.

Roger will move his arm *m* times. These transformations are a bit complicated, and Roger easily loses track of where the blue endpoint of the last segment is. Help him compute the coordinates of the blue endpoint of the last segment after applying each operation. ## Note

 that these operations are cumulative, and Roger's arm may intersect itself arbitrarily during the moves.

## Input

The first line of the input will contain two integers *n* and *m* (1 ≤ *n*, *m* ≤ 300 000) — the number of segments and the number of operations to perform.

Each of the next *m* lines contains three integers *x**i*, *y**i* and *z**i* describing a move. If *x**i* = 1, this line describes a move of type 1, where *y**i* denotes the segment number and *z**i* denotes the increase in the length. If *x**i* = 2, this describes a move of type 2, where *y**i* denotes the segment number, and *z**i* denotes the angle in degrees. (1 ≤ *x**i* ≤ 2, 1 ≤ *y**i* ≤ *n*, 1 ≤ *z**i* ≤ 359)

## Output

Print *m* lines. The *i*-th line should contain two real values, denoting the coordinates of the blue endpoint of the last segment after applying operations 1, ..., *i*. Your answer will be considered correct if its absolute or relative error does not exceed 10- 4.

Namely, let's assume that your answer for a particular value of a coordinate is *a* and the answer of the jury is *b*. The checker program will consider your answer correct if ![](images/49eb236611e23b2e7c8e81e9516771daca716eec.png) for all coordinates.

## Examples

## Input


```
5 4  
1 1 3  
2 3 90  
2 5 48  
1 4 1  

```
## Output


```
8.0000000000 0.0000000000  
5.0000000000 -3.0000000000  
4.2568551745 -2.6691306064  
4.2568551745 -3.6691306064  

```
## Note

The following pictures shows the state of the arm after each operation. The coordinates of point *F* are printed after applying each operation. For simplicity, we only show the blue endpoints of a segment (with the exception for the red endpoint of the first segment). For instance, the point labeled *B* is the blue endpoint for segment 1 and also the red endpoint for segment 2.

Initial state: 

 ![](images/3e74a3e9bd0827b8630c38a637bd6448d706a6c4.png)  Extend segment 1 by 3.  ![](images/a3b5a85b77f2e3b012750a0fcc8c81d6afa77156.png)  Rotate segment 3 by 90 degrees clockwise.  ![](images/8800757f505e60acba45c4633a96742a1df7c3d3.png)  Rotate segment 5 by 48 degrees clockwise.  ![](images/263e9631119ca7ceb97fad93ee86eb92773993bf.png)  Extend segment 4 by 1.  ![](images/c9ecdd11fa47469e11f3d1f8eab9176e262d1db6.png) 

#### tags 

#2500 #data_structures #geometry 