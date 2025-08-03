#include <iostream>
#include <queue>
using namespace std ;

int main()
{
    queue <int> atque ;
    queue <int> btque ;
    queue <int> ctque ;
    queue <int> wtque ;
    queue <int> tatque ;
    
    int time = 0 ;
    int process ;
    
    cout << "Please input the amount of processes : ";
    cin >> process ;
    
    cout << "Please input Arrival Time & Burst Time accordingly"<< endl ;
    cout << "eg. 5 65"<< endl ;

    for(int i = 0 ; i<process ; i++){
        int at , bt ;
        cin >> at >> bt ;
        atque.push(at) ;
        btque.push(bt) ;
    }
    
    queue <int> btque2(btque) ;
    
    // Completation time
    for(int i = 0 ; i<process ; i++){
        int nth_bt = btque.front();
        
        time += nth_bt ;
        
        ctque.push(time);
        
        btque.pop();
    }
    


    for(int i = 0 ; i<process ; i++){
        // tat = ct-at ; wt = tat -bt
        int nth_ct = ctque.front();
        int nth_at = atque.front();
        int nth_bt = btque2.front();

        int tat = nth_ct-nth_at ;
        int wt = tat - nth_bt ;
        cout << "P" << i+1 << " = " << "TAT : " << tat << " " << "WT : " << wt << endl ;

        ctque.pop();        
        atque.pop();
        btque2.pop();
    }

    return 0;
}
