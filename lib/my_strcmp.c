/*
** EPITECH PROJECT, 2021
** B-MUL-100-RUN-1-1-myhunter-apolline.fontaine
** File description:
** my_strcmp.c
*/

int my_strcmp(char const *s1, char const *s2)
{
    int i1 = 0;
    int i2 = 0;

    while (s1[i1] != '\0' || s2[i2] != '\0') {
        if (s1[i1] == s2[i2]) {
            i1++;
            i2++;
        } else {
            return -1;
        }
    }
    return 0;
}
