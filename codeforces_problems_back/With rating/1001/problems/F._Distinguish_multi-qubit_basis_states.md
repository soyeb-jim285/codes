<h1 style='text-align: center;'> F. Distinguish multi-qubit basis states</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given *N* qubits which are guaranteed to be in one of two basis states on *N* qubits. You are also given two bitstrings *bits*0 and *bits*1 which describe these basis states.

Your task is to perform necessary operations and measurements to figure out which state it was and to return 0 if it was the state described with *bits*0 or 1 if it was the state described with *bits*1. The state of the qubits after the operations does not matter.

## Input

You have to implement an operation which takes the following inputs:

* an array of qubits *qs*,
* two arrays of boolean values *bits*0 and *bits*1, representing the basis states in which the qubits can be. These arrays will have the same length as the array of qubits. *bits*0 and *bits*1 will differ in at least one position.

An array of boolean values represents a basis state as follows: the *i*-th element of the array is true if the *i*-th qubit is in state ![](images/08c9f8a718e14660a9d064a4b3c11e6340bef9c4.png), and false if it is in state ![](images/c1f9019c20fc8a9610d31c36ba7860cef0b7c55c.png). For example, array [true; false] describes 2-qubit state ![](images/8cd708066f09a8d46d85c4f2f1fb2e1d9977813b.png).

Your code should have the following signature:


```
namespace Solution {  
    open Microsoft.Quantum.Primitive;  
    open Microsoft.Quantum.Canon;  
  
    operation Solve (qs : Qubit[], bits0 : Bool[], bits1 : Bool[]) : Int  
    {  
        body  
        {  
            // your code here  
        }  
    }  
}
```


#### tags 

#1300 #*special 