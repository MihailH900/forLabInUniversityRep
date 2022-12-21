#ifndef MY_STRING_H
#define MY_STRING_H

char* readline(char* in);
char* strtok(char* s, const char* delim);
unsigned long int strlen(const char* str);
size_t strspn(const char* s1, const char* s2);
char* strpbrk(const char* s1, const char* s2);
void* memchr(const void* memptr, int val, size_t num);
void* memcpy(void* m1, const void* m2, long unsigned int n);
unsigned long int strlen(const char* str);
char* strcat(char* s1, const char* s2);

#endif /*MY_STRING_H*/
