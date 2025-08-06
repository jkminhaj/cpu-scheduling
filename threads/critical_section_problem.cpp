#include <iostream>
#include <thread>


using namespace std ;

long count = 0 ;

void task() 
{
    for(int i = 0 ; i<1000000 ; i++){
        count ++ ;
    }
}


int main () {

    thread t1(task);
    thread t2(task);


    // using join to wait t1 , t2 complete or main thread will exit 
    t1.join();
    t2.join();

    cout << count ;
    return 0 ;
}
