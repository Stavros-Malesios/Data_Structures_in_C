#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

Student* student_create(char *id, char *name, int semester) {
    Student *s = malloc(sizeof(Student));
    if (!s) return NULL;

    strncpy(s->id, id, ID_LEN);
    strncpy(s->name, name, NAME_LEN);
    s->semester = semester;

    return s;
}

int student_cmp_id(void *a, void *b) {
    Student *s1 = (Student *)a;
    Student *s2 = (Student *)b;
    return strcmp(s1->id, s2->id);
}

void student_print(void *s) {
    Student *st = (Student *)s;
    printf("ID: %s | Name: %s | Semester: %d\n",
           st->id, st->name, st->semester);
}

void student_free(void *s) {
    free(s);
}
