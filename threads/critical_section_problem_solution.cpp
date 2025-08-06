#include <iostream>
#include <thread>
#include <mutex>

using namespace std ;

long count = 0 ;

mutex myMutex ;

void task() 
{
    for(int i = 0 ; i<1000000 ; i++){
        // this lock allows only single thread at a time while changing variable 
        myMutex.lock();
        count ++ ; // critical section
        myMutex.unlock();
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
