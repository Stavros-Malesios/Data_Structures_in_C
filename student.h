		#ifndef STUDENT_H
		#define STUDENT_H

		#define ID_LEN 8
		#define NAME_LEN 50

		typedef struct {
    			char id[ID_LEN];
    			char name[NAME_LEN];
    			int semester;
		} Student;

		/* helpers */
		Student* student_create(char *id, char *name, int semester);
		int  student_cmp_id(void *a, void *b);
		void student_print(void *s);
		void student_free(void *s);

		#endif

