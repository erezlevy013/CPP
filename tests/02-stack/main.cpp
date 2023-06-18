#include <iostream> /*cout*/
#include "Stack.hpp"
#include "Queue.hpp"

void CheckCapacityCtor()
{
    Stack s(10);
    if( s.Capacity() == 10 && s.Size() == 0){
        std::cout << "Success...\n";
    }else{
        std::cout << "Fail...\n";
    }
}

void CheckDefCtor()
{
    Stack s;
    if( s.Capacity() == 100 && s.Size() == 0){
        std::cout << "Success...\n";
    }else{
        std::cout << "Fail...\n";
    }
}

void CheckPushDefCtor()
{
    Stack s;
    s.Push(10);
    s.Push(20);
    s.Push(30);
    if( s.Capacity() == 100 && s.Size() == 3){
        std::cout << "Success...\n";
    }else{
        std::cout << "Fail...\n";
    }
}
void CheckPushAndPopDefCtor()
{
    Stack s;
    s.Push(10);
    s.Push(20);
    s.Push(30);
    int val;
    s.Pop(val);
    s.Pop(val);
    if( s.Capacity() == 100 && s.Size() == 1){
        std::cout << "Success...\n";
    }else{
        std::cout << "Fail...\n";
    }
}

void CheckPushCapacityCtor()
{
    Stack s(5);
    s.Push(10);
    s.Push(20);
    s.Push(30);
    if( s.Capacity() == 5 && s.Size() == 3){
        std::cout << "Success...\n";
    }else{
        std::cout << "Fail...\n";
    }
}
void CheckPushAndPopCapacityCtor()
{
    Stack s(5);
    s.Push(10);
    s.Push(20);
    s.Push(30);
    int val;
    s.Pop(val);
    s.Pop(val);
    if( s.Capacity() == 5 && s.Size() == 1){
        std::cout << "Success...\n";
    }else{
        std::cout << "Fail...\n";
    }
}

void CheckPushOver()
{
    Stack s(3);
    s.Push(10);
    s.Push(20);
    s.Push(30);
    if( s.Push(40) == false && s.Size() == 3 && s.Top() == 30){
        std::cout << "Success...\n";
    }else{
        std::cout << "Fail...\n";
    }
}

void CheckPopOver()
{
    Stack s(3);
    s.Push(10);
    int val;
    s.Pop(val);
    if( s.Pop(val) == false && s.Size() == 0 ){
        std::cout << "Success...\n";
    }else{
        std::cout << "Fail...\n";
    }
}

void CheckTop()
{
    Stack s(3);
    s.Push(10); 
    int val = s.Top();
    if( s.Top() == val ){
        std::cout << "Success...\n";
    }else{
        std::cout << "Fail...\n";
    }
}

void CheckDrain()
{
    Stack s1(10);
    s1.Push(1);
    s1.Push(2);
    s1.Push(3);
    s1.Push(4);
    s1.Push(5);
    Stack s2(5);
    s2.Push(6);
    s2.Push(7);
    s2.Push(8);
    s2.Push(9);
    s2.Push(10);
    Drain(s1, s2);
    s1.Print();
    if( s1.Top() == 10 ){
        std::cout << "Success...\n";
    }else{
        std::cout << "Fail...\n";
    }
}

void CheckDrainNoSpace()
{
    Stack s1(2);
    Stack s2(5);
    s2.Push(1);
    s2.Push(2);
    s2.Push(3);
    s2.Push(4);
    Drain(s1, s2);
   
}
 
void CheckCCtor()
{
    Stack s1(5);
    s1.Push(1);
    s1.Push(2);
    s1.Push(3);
    s1.Push(4);
    Stack s2 = s1;
    
    if( s2.Top() == 4 ){
        std::cout << "Success...\n";
    }else{
        std::cout << "Fail...\n";
    }
}

void CheckMCtor()
{
    Stack s2 (Stack(5));
    if( s2.Capacity()){
        std::cout << "Success...\n";
    }else{
        std::cout << "Fail...\n";
    }
}

// void CheckEnqueue()
// {
//     Queue q(10);
//     q.Enqueue(1);
//     q.Enqueue(2);
//     q.Enqueue(3);
//     q.Enqueue(4);
//     q.Enqueue(5);
//     if(q.Size() == 5){
//         std::cout << "Success...\n";
//     }else{
//         std::cout << "Fail...\n";
//     }
// }

// void CheckEnqueueOver()
// {
//     Queue q(3);
//     q.Enqueue(1);
//     q.Enqueue(2);
//     q.Enqueue(3);
//     if(q.Enqueue(4) == false ){
//         std::cout << "Success...\n";
//     }else{
//         std::cout << "Fail...\n";
//     }
// }

// void CheckDequeue()
// {
//     Queue q(3);
//     q.Enqueue(1);
//     q.Enqueue(2);
//     q.Enqueue(3);
//     int x;
//     if(q.Dequeue(x) == 1 ){
//         std::cout << "Success...\n";
//     }else{
//         std::cout << "Fail...\n";
//     }
// }

// void CheckDequeueOver()
// {
//     Queue q(5);
//     q.Enqueue(1);
//     int x;
//     q.Dequeue(x);
//     if(q.Dequeue(x)){
//         std::cout << "Success...\n";
//     }else{
//         std::cout << "Fail...\n";
//     }
// }

// void CheckEmpty()
// {
//     Queue q(5);
//     if(q.Empty()){
//         std::cout << "Success...\n";
//     }else{
//         std::cout << "Fail...\n";
//     }
// }
    
// void CheckFull()
// {
//     Queue q(3);
//     q.Enqueue(1);
//     q.Enqueue(2);
//     q.Enqueue(3);
//     if(q.Full()){
//         std::cout << "Success...\n";
//     }else{
//         std::cout << "Fail...\n";
//     }
// }
    
// void CheckPrint()
// {
//     Queue q(3);
//     q.Enqueue(1);
//     q.Enqueue(2);
//     q.Enqueue(3);
//     int x;
//     q.Dequeue(x);
//     q.Enqueue(4);
//     q.Enqueue(5);
//     q.Print();
// }

// void CheckMinFullSize()
// {
//     Queue q(3);
//     for(size_t i = 0; i < 3; i++){
//         q.Enqueue(i+1);
//     }
//     int x;
//     q.Dequeue(x);
//     for(size_t i = 0; i < 3; i++){
//         q.Enqueue(i+1);
//     }
    
// }

int main()
{
    CheckCapacityCtor();
    CheckDefCtor();
    CheckPushDefCtor();
    CheckPushAndPopDefCtor();
    CheckPushCapacityCtor();
    CheckPushAndPopCapacityCtor();
    CheckPushOver();
    CheckPopOver();
    CheckTop();
    CheckDrain();
    ///CheckDrainNoSpace(); /*assert*/

    CheckCCtor();
    CheckMCtor();

    // CheckEnqueue();
    // ///CheckEnqueueOver();
    // CheckDequeue();
    // ///CheckDequeueOver(); /*assert*/
    // CheckEmpty();
    // CheckPrint();
    // CheckMinFullSize();
 
    return 0;
}
