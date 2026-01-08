#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "doubly_linked_list.h"
#include "student.h"

static void print_menu(void) {
    printf("\n======= Student List Menu =======\n");
    printf("1. Insert student\n");
    printf("2. Delete student by ID\n");
    printf("3. Search student by ID\n");
    printf("4. Search student by name\n");
    printf("5. Print all students\n");
    printf("6. Print students by semester\n");
    printf("0. Exit\n");
    printf("Choice: ");
}

int main(void) {
    Node *head = NULL;
    int choice;

    char id[ID_LEN];
    char name[NAME_LEN];
    int semester;

    do {
        print_menu();
        scanf("%d", &choice);

        switch (choice) {

        case 1: {   // Insert
            printf("ID: ");
            scanf("%s", id);

            printf("Name: ");
            scanf(" %[^\n]", name);

            printf("Semester: ");
            scanf("%d", &semester);

            Student *s = student_create(id, name, semester);
            if (!s) {
                printf("Memory allocation failed!\n");
                break;
            }

            head = list_insert_sorted(head, s, student_cmp_id);
            printf("Student inserted.\n");
            break;
        }

        case 2: {   // Delete
            printf("ID to delete: ");
            scanf("%s", id);

            Student key;
            snprintf(key.id, ID_LEN, "%s", id);

            head = list_delete(
                head,
                &key,
                student_cmp_id,
                student_free
            );

            printf("Delete operation completed.\n");
            break;
        }

        case 3: {   // Search by ID
            printf("ID to search: ");
            scanf("%s", id);

            Student key;
            snprintf(key.id, ID_LEN, "%s", id);

            Node *res = list_search(head, &key, student_cmp_id);
            if (res)
                student_print(res->data);
            else
                printf("Student not found.\n");
            break;
        }

        case 4: {   // Search by name
            printf("Name to search: ");
            scanf(" %[^\n]", name);

            Node *curr = head;
            int found = 0;

            while (curr) {
                Student *s = curr->data;
                if (strcmp(s->name, name) == 0) {
                    student_print(s);
                    found = 1;
                }
                curr = curr->next;
            }

            if (!found)
                printf("No student found with this name.\n");

            break;
        }

        case 5:     // Print all
            list_traverse(head, student_print);
            break;

        case 6: {   // Print by semester
            printf("Semester: ");
            scanf("%d", &semester);

            Node *curr = head;
            int found = 0;

            while (curr) {
                Student *s = curr->data;
                if (s->semester == semester) {
                    student_print(s);
                    found = 1;
                }
                curr = curr->next;
            }

            if (!found)
                printf("No students in this semester.\n");

            break;
        }

        case 0:
            printf("Exiting...\n");
            break;

        default:
            printf("Invalid choice.\n");
        }

    } while (choice != 0);

    list_free(head, student_free);
    return 0;
}

