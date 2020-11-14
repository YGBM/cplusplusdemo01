#include <iostream>

int sum(int A[],int n){
    return n < 1 ? 0 : sum(A, n - 1) + A[n - 1];
}

namespace RecursionSum{
    void apply(){
        int arr[10] = {1,2,3,4,5,6,7,8,9,0};
        std::cout<< "the result: " <<sum(arr,10) << std::endl;
    }
}
