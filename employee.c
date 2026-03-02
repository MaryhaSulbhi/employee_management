#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "employee.h"

#define FILE_NAME "employees.dat"

Employee* addEmployee(Employee* head) {
    Employee* newEmp = (Employee*)malloc(sizeof(Employee));

    printf("Enter ID: ");
    scanf("%d", &newEmp->id);

    printf("Enter Name: ");
    scanf(" %[^\n]", newEmp->name);

    printf("Enter Salary: ");
    scanf("%f", &newEmp->salary);

    newEmp->next = NULL;

    if (head == NULL)
        return newEmp;

    Employee* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newEmp;

    printf("Employee Added Successfully!\n");
    return head;
}

void displayEmployees(Employee* head) {
    if (head == NULL) {
        printf("No employees found.\n");
        return;
    }

    Employee* temp = head;
    while (temp != NULL) {
        printf("ID: %d | Name: %s | Salary: %.2f\n",
               temp->id, temp->name, temp->salary);
        temp = temp->next;
    }
}

Employee* searchEmployee(Employee* head, int id) {
    Employee* temp = head;

    while (temp != NULL) {
        if (temp->id == id) {
            return temp;
        }
        temp = temp->next;
    }

    return NULL;
}

Employee* deleteEmployee(Employee* head, int id) {
    if (head == NULL) return NULL;

    Employee *temp = head, *prev = NULL;

    if (temp->id == id) {
        head = temp->next;
        free(temp);
        printf("Employee Deleted.\n");
        return head;
    }

    while (temp != NULL && temp->id != id) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Employee Not Found.\n");
        return head;
    }

    prev->next = temp->next;
    free(temp);
    printf("Employee Deleted.\n");

    return head;
}

void saveToFile(Employee* head) {
    FILE* file = fopen(FILE_NAME, "wb");

    if (file == NULL) {
        printf("Error saving file.\n");
        return;
    }

    Employee* temp = head;
    while (temp != NULL) {
        fwrite(temp, sizeof(Employee), 1, file);
        temp = temp->next;
    }

    fclose(file);
}

Employee* loadFromFile() {
    FILE* file = fopen(FILE_NAME, "rb");
    if (file == NULL)
        return NULL;

    Employee* head = NULL;
    Employee temp;

    while (fread(&temp, sizeof(Employee), 1, file)) {
        Employee* newEmp = (Employee*)malloc(sizeof(Employee));
        *newEmp = temp;
        newEmp->next = NULL;

        if (head == NULL)
            head = newEmp;
        else {
            Employee* t = head;
            while (t->next != NULL)
                t = t->next;
            t->next = newEmp;
        }
    }

    fclose(file);
    return head;
}

void freeMemory(Employee* head) {
    Employee* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}