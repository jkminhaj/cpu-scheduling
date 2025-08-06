#include <iostream>
#include <thread>
#include <unistd.h> 

using namespace std ;

void taskA() 
{
    for(int i = 0 ; i<10 ; i++){
        sleep(1);
        cout << "Task A : " << i <<endl ;
    }
}

void taskB() 
{
    for(int i = 0 ; i<10 ; i++){
        sleep(1);
        cout << "Task B : " << i <<endl ;
    }
}

int main () {

    thread t1(taskA);
    thread t2(taskB);


    // using join to wait t1 , t2 complete or main thread will exit 
    t1.join();
    t2.join();
    return 0 ;
}
