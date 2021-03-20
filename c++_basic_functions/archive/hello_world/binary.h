/******************************** TP numéro 2 : Ankur MAHTANI & Bastien PESAMOSCA - Exercice 1 ********************************/

typedef unsigned char ui8_t;
typedef unsigned short ui16_t;
typedef unsigned long ui32_t;

#ifndef _BINARY_H
#define _BINARY_H

ui8_t read_ui8(FILE *f);
ui16_t read_ui16(FILE *f);
ui32_t read_ui32(FILE *f);
ui32_t file_size(const char* fname);

#endif 
