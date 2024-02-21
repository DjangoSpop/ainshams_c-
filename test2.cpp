#include <iostream>




void add (int& N1 , int N2 =5)
{
N1+=N2;
N2++;



}


int main(){
int x = 1, y = 2;
add(x,y);
std::cout<<x<<std::endl;
add(y,x);
std::cout<<y<<std::endl;
add(x);
std::cout<<x<<std::endl;


    return 0;
}