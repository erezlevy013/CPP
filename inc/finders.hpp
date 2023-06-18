#ifndef FINDERS_H
#define FINDERS_H

#include <cstddef>

bool findTwoIndx(const int *a_arr, int a_sum, size_t a_size, int *a_first, int *a_second);

bool findDupIndx(const int *a_arr, size_t a_size, int *a_elm);

bool findFirstUnicElm(const int *a_arr, size_t a_size, int *a_elm);



#endif