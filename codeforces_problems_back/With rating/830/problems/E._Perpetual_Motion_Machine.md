<h1 style='text-align: center;'> E. Perpetual Motion Machine</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

Developer Petr thinks that he invented a perpetual motion machine. Namely, he has a lot of elements, which work in the following way.

Each element has one controller that can be set to any non-negative real value. If a controller is set on some value *x*, then the controller consumes *x*2 energy units per second. At the same time, any two elements connected by a wire produce *y*·*z* energy units per second, where *y* and *z* are the values set on their controllers.

Petr has only a limited number of wires, so he has already built some scheme of elements and wires, and is now interested if it's possible to set the controllers in such a way that the system produces at least as much power as it consumes, and at least one controller is set on the value different from 0. Help him check this, and if it's possible, find the required integer values that should be set.

It is guaranteed that if there exist controllers' settings satisfying the above conditions, then there exist required integer values not greater than 106.

## Input

There are several (at least one) test cases in the input. The first line contains single integer — the number of test cases.

There is an empty line before each test case. The first line of test case contains two integers *n* and *m* (1 ≤ *n* ≤ 105, 0 ≤ *m* ≤ 105) — the number of elements in the scheme and the number of wires.

After that, *m* lines follow, each of them contains two integers *a* and *b* (1 ≤ *a*, *b* ≤ *n*) — two elements connected by a wire. No element is connected with itself, no two elements are connected by more than one wire.

It is guaranteed that the sum of *n* and the sum of *m* over all test cases do not exceed 105.

For hacks you can only use tests with one test case.

## Output

Print answer for each test case.

For each test case print "YES" if it's possible to set the controllers in such a way that the consumed power is not greater than the power produced, and the required values on the next line. The settings should be integers from 0 to 106, inclusive, and at least one value should be different from 0. If there are multiple answers, print any of them.

If it's not possible to set the controllers in the required way, print one line "NO".

## Example

## Input


```
4  
   
4 4  
1 2  
2 3  
3 4  
4 2  
   
3 2  
2 3  
3 1  
   
4 6  
1 2  
3 4  
4 2  
1 4  
1 3  
3 2  
   
10 9  
2 1  
3 2  
5 2  
6 2  
2 7  
2 8  
2 9  
2 10  
4 2  

```
## Output


```
YES  
1 2 2 1  
NO  
YES  
1 1 1 1  
YES  
1 5 1 1 1 1 1 1 1 1  

```
## Note

In the first example it's possible to set the controllers in the required way, for example, in the following way: set 1 on the first element, set 2 on the second and on the third, set 1 on the fourth. The consumed power is then equal to 12 + 22 + 22 + 12 = 10 energy units per second, the produced power is equal to 1·2 + 2·2 + 2·1 + 2·1 = 10 energy units per second. Thus the answer is "YES".

In the second test case it's not possible to set the controllers in the required way. For example, if we set all controllers to 0.5, then the consumed powers equals 0.75 energy units per second, while produced power equals 0.5 energy units per second.



#### tags 

#3100 #constructive_algorithms #dp #graphs #implementation #math #trees 