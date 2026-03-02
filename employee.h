#ifndef EMPLOYEE_H
#define EMPLOYEE_H

typedef struct Employee {
    int id;
    char name[50];
    float salary;
    struct Employee *next;
} Employee;

// Function declarations
Employee* loadFromFile();
void saveToFile(Employee* head);

Employee* addEmployee(Employee* head);
Employee* deleteEmployee(Employee* head, int id);
Employee* searchEmployee(Employee* head, int id);
void displayEmployees(Employee* head);
void freeMemory(Employee* head);

#endif