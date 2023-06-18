#include <iostream>
#include "../../inc/finders.hpp"


void checkFindTwoIndx_1(){

    int arr[] = {1,2,3,4,5,6,7,8,9,10}, p1, p2; 
    findTwoIndx(arr, 14, sizeof(arr)/sizeof(arr[0]), &p1, &p2);
    if( p1 == 3 && p2 == 9){

        std::cout << "Success" << "\n";
    }
    else{

        std::cout << "Failed checkFindTwoIndx_1()" << "\n";
    }
}

void checkFindTwoIndx_2(){

    int arr[] = {1,2,3,4,5,6,7,8,9,10}, p1, p2, ret = 0; 
    ret = findTwoIndx(arr, 0, sizeof(arr)/sizeof(arr[0]), &p1, &p2);
    if(!ret){

        std::cout << "Success" << "\n";
    }
    else{

        std::cout << "Failed checkFindTwoIndx_2()" << "\n";
    }
}

void checkFindTwoIndx_3(){

    int arr[] = {1,2,3,4,5,6,7,8,9,10}, p1, p2, ret = 0; 
    ret = findTwoIndx(arr, 2, sizeof(arr)/sizeof(arr[0]), nullptr, &p2);
    if(!ret){

        std::cout << "Success" << "\n";
    }
    else{

        std::cout << "Failed checkFindTwoIndx_3()" << "\n";
    }
}

void checkFindTwoIndx_4(){

    int arr[] = {1,2,3,4,5,6,7,8,9,10}, p1, p2, ret = 0; 
    ret = findTwoIndx(arr, 2, 1, &p1, &p2);
    if(!ret){

        std::cout << "Success" << "\n";
    }
    else{

        std::cout << "Failed checkFindTwoIndx_4()" << "\n";
    }
}

void checkFindTwoIndx_5(){

    int arr[] = {1,2,3,4,5,6,7,8,9,10}, p1, p2, ret = 0; 
    ret = findTwoIndx(arr, 2, sizeof(arr)/sizeof(arr[0]), &p1, nullptr);
    if(!ret){

        std::cout << "Success" << "\n";
    }
    else{

        std::cout << "Failed checkFindTwoIndx_5()" << "\n";
    }
}



void checkFindDupIndx_1(){

    int arr[] = {1,2,3,4,5,5}, elm, ret = 0; 
    ret = findDupIndx(arr, sizeof(arr)/sizeof(arr[0]), &elm);
    if(ret && elm == 5){

        std::cout << "Success" << "\n";
    }
    else{

        std::cout << "Failed checkFindDupIndx_1()" << "\n";
    }
}

void checkFindDupIndx_2(){

    int arr[] = {1,2,3,4,5}, elm, ret = 0; 
    ret = findDupIndx(arr, sizeof(arr)/sizeof(arr[0]), &elm);
    if(!ret){

        std::cout << "Success" << "\n";
    }
    else{

        std::cout << "Failed checkFindDupIndx_2()" << "\n";
    }
}

void checkFindDupIndx_3(){

    int arr[] = {1,2,3,4,5}, elm, ret = 0; 
    ret = findDupIndx(arr, 1, &elm);
    if(!ret){

        std::cout << "Success" << "\n";
    }
    else{

        std::cout << "Failed checkFindDupIndx_3()" << "\n";
    }
}

void checkFindDupIndx_4(){

    int arr[] = {1,2,3,4,5}, elm, ret = 0; 
    ret = findDupIndx(nullptr, sizeof(arr)/sizeof(arr[0]), &elm);
    if(!ret){

        std::cout << "Success" << "\n";
    }
    else{

        std::cout << "Failed checkFindDupIndx_4()" << "\n";
    }
}

void checkFindDupIndx_5(){

    int arr[] = {1,2,3,4,5}, elm, ret = 0; 
    ret = findDupIndx(arr, sizeof(arr)/sizeof(arr[0]), nullptr);
    if(!ret){

        std::cout << "Success" << "\n";
    }
    else{

        std::cout << "Failed checkFindDupIndx_5()" << "\n";
    }
}


void checkFindFirstUnicElm_1()
{
    int arr[] = {1,2,3,4,5}, elm, ret = 0; 
    ret = findFirstUnicElm(arr, sizeof(arr)/sizeof(arr[0]), &elm);
    if(ret && elm == 1){
        
        std::cout << "Success" << "\n";
    }
    else{

        std::cout << "Failed checkFindFirstUnicElm_1()" << "\n";
    }
}

void checkFindFirstUnicElm_2()
{
    int arr[] = {1,2,1,2,5}, elm, ret = 0; 
    ret = findFirstUnicElm(arr, sizeof(arr)/sizeof(arr[0]), &elm);
    if(ret && elm == 5){
        
        std::cout << "Success" << "\n";
    }
    else{

        std::cout << "Failed checkFindFirstUnicElm_2()" << "\n";
    }
}

void checkFindFirstUnicElm_3()
{
    int arr[] = {1,2,1,2}, elm, ret = 0; 
    ret = findFirstUnicElm(arr, sizeof(arr)/sizeof(arr[0]), &elm);
    if(!ret){
        
        std::cout << "Success" << "\n";
    }
    else{

        std::cout << "Failed checkFindFirstUnicElm_3()" << "\n";
    }
}

void checkFindFirstUnicElm_4()
{
    int arr[] = {1,2,1,2,5,6}, elm, ret = 0; 
    ret = findFirstUnicElm(nullptr, sizeof(arr)/sizeof(arr[0]), &elm);
    if(!ret){
        
        std::cout << "Success" << "\n";
    }
    else{

        std::cout << "Failed checkFindFirstUnicElm_4()" << "\n";
    }
}

void checkFindFirstUnicElm_5()
{
    int arr[] = {1,2,1,2,5,6}, elm, ret = 0; 
    ret = findFirstUnicElm(arr, 0, &elm);
    if(!ret){
        
        std::cout << "Success" << "\n";
    }
    else{

        std::cout << "Failed checkFindFirstUnicElm_5()" << "\n";
    }
}

void checkFindFirstUnicElm_6()
{
    int arr[] = {1,2,1,2,5,6}, ret = 0; 
    ret = findFirstUnicElm(arr, sizeof(arr)/sizeof(arr[0]), nullptr);
    if(!ret){
        
        std::cout << "Success" << "\n";
    }
    else{

        std::cout << "Failed checkFindFirstUnicElm_6()" << "\n";
    }
}


int main()
{
    checkFindTwoIndx_1();
    checkFindTwoIndx_2();
    ///checkFindTwoIndx_3();
    checkFindTwoIndx_4();
    ///checkFindTwoIndx_5();
    std::cout << "------------------------------------------------\n";
    checkFindDupIndx_1();
    checkFindDupIndx_2();
    checkFindDupIndx_3();
    ///checkFindDupIndx_4();
    ///checkFindDupIndx_5();
    std::cout << "------------------------------------------------\n";
    checkFindFirstUnicElm_1();
    checkFindFirstUnicElm_2();
    checkFindFirstUnicElm_3();
    ///checkFindFirstUnicElm_4();
    checkFindFirstUnicElm_5();
    ///checkFindFirstUnicElm_6();
    
    return 0;
}
