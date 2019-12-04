#include <stdio.h>
#include <stdlib.h>
/* struct Angajat
{char buletin;
char certificat_casatorie;
char diploma_licenta;
char diploma_master;
char diploma_doctor;
char fisa;
char certificat_copii;
}v[100]; */
struct Angajat
{int buletin:1;
int certificat_casatorie:1;
int diploma_licenta:1;
int diploma_master:1;
int diploma_doctor:1;
int fisa:1;
int certificat_copii:1;
}v[100];
int main()
{
    printf("%d", sizeof(struct Angajat));
    return 0;
}
