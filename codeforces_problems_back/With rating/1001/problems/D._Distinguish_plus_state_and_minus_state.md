<h1 style='text-align: center;'> D. Distinguish plus state and minus state</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given a qubit which is guaranteed to be either in ![](images/d92593c6760aba7602b98b147630fe99f3ba55f1.png) or in ![](images/84838ca6c00c18d1930add5214964c1673061c43.png) state. 

Your task is to perform necessary operations and measurements to figure out which state it was and to return 1 if it was a ![](images/891b1e75c93e44f237b7fde497062f8e85c1d952.png) state or -1 if it was ![](images/512ee4f1a3d6ab8d0377b1bd0119130f334815de.png) state. The state of the qubit after the operations does not matter.

## Input

You have to implement an operation which takes a qubit as an input and returns an integer. 

Your code should have the following signature:


```
namespace Solution {  
    open Microsoft.Quantum.Primitive;  
    open Microsoft.Quantum.Canon;  
  
    operation Solve (q : Qubit) : Int  
    {  
        body  
        {  
            // your code here  
        }  
    }  
}
```


#### tags 

#1400 #*special 