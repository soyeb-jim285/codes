<h1 style='text-align: center;'> H. Oracle for f(x) = parity of the number of 1s in x</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Implement a quantum oracle on *N* qubits which implements the following function: ![](images/601fd91df91c2fbae106d1ddc30f35b042b484e0.png), i.e., the value of the function is 1 if *x* has odd number of 1s, and 0 otherwise.

## Input

You have to implement an operation which takes the following inputs:

* an array of qubits *x* (input register),
* a qubit *y* (output qubit).

The operation doesn't have an output; the "output" of your solution is the state in which it left the qubits.

Your code should have the following signature:


```
namespace Solution {  
    open Microsoft.Quantum.Primitive;  
    open Microsoft.Quantum.Canon;  
  
    operation Solve (x : Qubit[], y : Qubit) : ()  
    {  
        body  
        {  
            // your code here  
        }  
    }  
}
```


#### tags 

#1200 #*special 