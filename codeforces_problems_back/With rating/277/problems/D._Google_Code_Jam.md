<h1 style='text-align: center;'> D. Google Code Jam</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Many of you must be familiar with the Google Code Jam round rules. Let us remind you of some key moments that are crucial to solving this problem. During the round, the participants are suggested to solve several problems, each divided into two subproblems: an easy one with small limits (Small input), and a hard one with large limits (Large input). You can submit a solution for Large input only after you've solved the Small input for this problem. There are no other restrictions on the order of solving inputs. In particular, the participant can first solve the Small input, then switch to another problem, and then return to the Large input. Solving each input gives the participant some number of points (usually different for each problem). This takes into account only complete solutions that work correctly on all tests of the input. The participant gets the test result of a Small input right after he submits it, but the test result of a Large input are out only after the round's over. In the final results table the participants are sorted by non-increasing of received points. If the points are equal, the participants are sorted by ascending of time penalty. By the Google Code Jam rules the time penalty is the time when the last correct solution was submitted.

Vasya decided to check out a new tactics on another round. As soon as the round begins, the boy quickly read all the problems and accurately evaluated the time it takes to solve them. Specifically, for each one of the *n* problems Vasya knows five values:

* Solving the Small input of the *i*-th problem gives to the participant *scoreSmall**i* points, and solving the Large input gives *scoreLarge**i* more points. That is, the maximum number of points you can get for the *i*-th problem equals *scoreSmall**i* + *scoreLarge**i*.
* Writing the solution for the Small input of the *i*-th problem takes exactly *timeSmall**i* minutes for Vasya. Improving this code and turning it into the solution of the Large input takes another *timeLarge**i* minutes.
* Vasya's had much practice, so he solves all Small inputs from the first attempt. But it's not so easy with the Large input: there is the *probFail**i* probability that the solution to the Large input will turn out to be wrong at the end of the round. Please keep in mind that these solutions do not affect the participants' points and the time penalty.

A round lasts for *t* minutes. The time for reading problems and submitting solutions can be considered to equal zero. Vasya is allowed to submit a solution exactly at the moment when the round ends.

Vasya wants to choose a set of inputs and the order of their solution so as to make the expectation of the total received points maximum possible. If there are multiple ways to do this, he needs to minimize the expectation of the time penalty. Help Vasya to cope with this problem.

## Input

The first line contains two integers *n* and *t* (1 ≤ *n* ≤ 1000, 1 ≤ *t* ≤ 1560). Then follow *n* lines, each containing 5 numbers: *scoreSmall**i*, *scoreLarge**i*, *timeSmall**i*, *timeLarge**i*, *probFail**i* (1 ≤ *scoreSmall**i*, *scoreLarge**i* ≤ 109, 1 ≤ *timeSmall**i*, *timeLarge**i* ≤ 1560, 0 ≤ *probFail**i* ≤ 1).

*probFail**i* are real numbers, given with at most 6 digits after the decimal point. All other numbers in the input are integers.

## Output

Print two real numbers — the maximum expectation of the total points and the corresponding minimum possible time penalty expectation. The answer will be considered correct if the absolute or relative error doesn't exceed 10- 9.

## Examples

## Input


```
3 40  
10 20 15 4 0.5  
4 100 21 1 0.99  
1 4 1 1 0.25  

```
## Output


```
24.0 18.875  

```
## Input


```
1 1  
100000000 200000000 1 1 0  

```
## Output


```
100000000 1  

```
## Note

In the first sample one of the optimal orders of solving problems is:

1. The Small input of the third problem.
2. The Small input of the first problem.
3. The Large input of the third problem.
4. The Large input of the first problem.

## Note

 that if you solve the Small input of the second problem instead of two inputs of the third one, then total score expectation will be the same but the time penalty expectation will be worse (38).



#### tags 

#2800 #dp #probabilities 