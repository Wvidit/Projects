#ifndef NOISE_H
#define NOISE_H

#include <stdint.h>
#include <stdio.h>

void Add_noise(uint8_t (*src)[3], FILE* file_ptr, int rows);

#endif
