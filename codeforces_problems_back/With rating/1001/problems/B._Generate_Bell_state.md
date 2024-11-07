<h1 style='text-align: center;'> B. Generate Bell state</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given two qubits in state ![](images/089af33a3ed92e1b1c474ff5cc39bc9478708dc1.png) and an integer *index*. Your task is to create one of the [Bell states](https://en.wikipedia.org/wiki/Bell_state) on them according to the *index*:

* ![](images/3bd300187bec68a260f07bb41226aad198f9aef0.png)
* ![](images/2b05513e9a357b2122b3d30583a71885a247a3b8.png)
* ![](images/8c3b892f53b8bf7ed84f55a5087ada2ab50dd4d1.png)
* ![](images/d094280f4b9897c9aec5e2ba5e920d00e37656fc.png)
## Input

You have to implement an operation which takes an array of 2 qubits and an integer as an input and has no output. The "output" of your solution is the state in which it left the input qubits.

Your code should have the following signature:


```
namespace Solution {  
    open Microsoft.Quantum.Primitive;  
    open Microsoft.Quantum.Canon;  
  
    operation Solve (qs : Qubit[], index : Int) : ()  
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