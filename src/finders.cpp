#include <cstddef>
#include <cassert>
#include "../inc/finders.hpp"

bool findTwoIndx(const int *a_arr, int a_sum, size_t a_size, int *a_first, int *a_second)
{
    assert(a_arr && a_first && a_second);
    if( a_arr == nullptr || a_first == nullptr || a_second == nullptr || a_size < 2){

        return false;
    }

    for(size_t i = 0; i < a_size; i++){
        
        for(size_t j = i; j < a_size; j++){

            if(a_arr[i] + a_arr[j] == a_sum){

                *a_first = i;
                *a_second = j;
                return true;
            }
        }
    }                                                                                   
    return false;
}

bool findDupIndx(const int *a_arr, size_t a_size, int *a_elm)
{
    assert(a_arr && a_elm);
    if( a_arr == nullptr || a_elm == nullptr || a_size < 2){

        return false;
    }
    
    for(size_t i = 0; i < a_size; i++){
        
        for(size_t j = i + 1; j < a_size; j++){

            if(a_arr[i] == a_arr[j]){

                *a_elm = a_arr[i];
                return true;
            }
        }
    }
    return false;
}

bool findFirstUnicElm(const int *a_arr, size_t a_size, int *a_elm)
{
    assert(a_arr && a_elm);
    if( a_arr == nullptr || a_elm == nullptr || a_size < 2){

        return false;
    }
    
    for(size_t i = 0; i < a_size; i++){
        
        *a_elm = a_arr[i];
        size_t j;
        for(j = 0; j < a_size ; j++){

            if(i != j && *a_elm == a_arr[j]){      

                break;
            }
        }
        if( j == a_size){

            return true;
        }
    }
    return false;
}