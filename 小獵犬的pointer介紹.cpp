#include <bits/stdc++.h>
/*notes for three types of pointer*/



int main(void){
    /*
     *1.  constant pointer
     *    the address which the pointer stored can't be modified once an address is assigned
     *    syntax :
     *         <data type> * const ptr
     * */    
    int val1;
    int val2;
    int * const constantPtr = &val1;
    // this is a constant pointer
    
    constantPtr = &val2;



    /*
     *2.  pointer to constant
     *    the value inside the address which pointer stored can't be modified
     *    syntax:
     *         const <dataType> * ptr
     * */
    const int * ptrToConstant;
    // this is a pointer to Constant;
    
    int val3 = 1;

    ptrToConstant = &val3;
    *ptrToConstant = 4;


    /*
     *3.  constant pointer to constant
     *    both the address which pointer stored 
     *    and the value stored in the address can't  be modified
     *    syntax:
     *         const <dataType> * const ptr;
     * */

    int val4 = 5;
    int val5 = 0;
    const int * const constPtrToConst = &val4;
    // this is a constant pointer to constant value
    
    constPtrToConst = &val5;
    *constPtrToConst = 6;


    return 0;


}
