#include <stdio.h>
#include <stdlib.h>
#include "employee.h"

int main() {
    Employee* head = loadFromFile();
    int choice, id;
    Employee* result;

    do {
        printf("\n==== Employee Management System ====\n");
        printf("1. Add Employee\n");
        printf("2. Delete Employee\n");
        printf("3. Search Employee\n");
        printf("4. Display Employees\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                head = addEmployee(head);
                break;

            case 2:
                printf("Enter ID to delete: ");
                scanf("%d", &id);
                head = deleteEmployee(head, id);
                break;

            case 3:
                printf("Enter ID to search: ");
                scanf("%d", &id);
                result = searchEmployee(head, id);
                if (result)
                    printf("Found: %s | Salary: %.2f\n",
                           result->name, result->salary);
                else
                    printf("Employee Not Found.\n");
                break;

            case 4:
                displayEmployees(head);
                break;

            case 5:
                saveToFile(head);
                freeMemory(head);
                printf("Data Saved. Exiting...\n");
                break;

            default:
                printf("Invalid Choice!\n");
        }

    } while (choice != 5);

    return 0;
}