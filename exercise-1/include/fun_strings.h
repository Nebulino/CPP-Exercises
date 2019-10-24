//
// Created by Lillie on 10/15/2019.
//

#include <string.h>

#ifndef ES1_FUNSTRINGS_H
#define ES1_FUNSTRINGS_H

// #pragma once
// it's compiler_based

/**
 * Function that prints the string dividing it by char for each row
 * @param str : the string
 */
void print_string(const char *str);

/**
 * Function that return the length of the string
 * @param str : pointer to the string
 * @return : the length of the string
 */
unsigned int len_string(const char *str);

/**
 * Function that invert the string in place
 * @param str : the string
 */
void invert_string(char *str);

/**
 * Function that clone a string in input
 * @param str : the string
 * @return : the pointer for the new string
 */
char *string_clone(const char *str);

#endif
