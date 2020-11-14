#include <iostream>

void func_multi_dim_arr(){
    
    using namespace std;

    double runoobAarray[5] = {100.0,2.0,3.4,1.0,212.3};
    double *p;

    p = runoobAarray;
    
    for(int i = 0; i < 5; i++){
        cout << "*(p + " << i << ") : ";
        cout << *(p+i) << endl;
    }
}