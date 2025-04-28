#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Employee {
    int id;
    char name[50];
    float basicSalary;
    float hra;
    float da;
    float grossSalary;
    float pf;
    float tds;
    float profTax;
    float rentalCost;
    float netSalary;
};

struct Employee emp[100];
int count = 0;

void calculateSalaries(int i) {
    emp[i].hra = emp[i].basicSalary * 0.20;
    emp[i].da = emp[i].basicSalary * 0.10;
    emp[i].grossSalary = emp[i].basicSalary + emp[i].hra + emp[i].da;

    emp[i].pf = emp[i].basicSalary * 0.12;
    emp[i].tds = emp[i].grossSalary * 0.05;
    emp[i].profTax = 200; // Fixed professional tax

    emp[i].netSalary = emp[i].grossSalary - emp[i].pf - emp[i].tds - emp[i].profTax - emp[i].rentalCost;
}

void addEmployee() {
    printf("Enter Employee ID: ");
    scanf("%d", &emp[count].id);
    printf("Enter Name: ");
    scanf(" %[^\n]", emp[count].name);
    printf("Enter Basic Salary: ");
    scanf("%f", &emp[count].basicSalary);
    printf("Enter Rental Cost: ");
    scanf("%f", &emp[count].rentalCost);

    calculateSalaries(count);
    count++;
    printf("Employee added successfully!\n");
}

void displayEmployees() {
    printf("\n%-5s %-10s %-10s %-10s %-10s %-10s %-10s %-10s %-10s %-10s\n", 
           "ID", "Name", "Basic", "HRA", "DA", "Gross", "PF", "TDS", "Rent", "Net");
    for (int i = 0; i < count; i++) {
        printf("%-5d %-10s %-10.2f %-10.2f %-10.2f %-10.2f %-10.2f %-10.2f %-10.2f %-10.2f\n",
               emp[i].id, emp[i].name, emp[i].basicSalary, emp[i].hra, emp[i].da, 
               emp[i].grossSalary, emp[i].pf, emp[i].tds, emp[i].rentalCost, emp[i].netSalary);
    }
}

void deleteEmployee() {
    int id, found = 0;
    printf("Enter Employee ID to delete: ");
    scanf("%d", &id);
    for (int i = 0; i < count; i++) {
        if (emp[i].id == id) {
            for (int j = i; j < count - 1; j++) {
                emp[j] = emp[j + 1];
            }
            count--;
            found = 1;
            printf("Employee deleted successfully!\n");
            break;
        }
    }
    if (!found) {
        printf("Employee not found!\n");
    }
}

int main() {
    int choice;
    do {
        printf("\n--- Employee Payroll Management System ---\n");
        printf("1. Add Employee\n");
        printf("2. Display Employees\n");
        printf("3. Delete Employee\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addEmployee(); break;
            case 2: displayEmployees(); break;
            case 3: deleteEmployee(); break;
            case 4: printf("Exiting...\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while (choice != 4);

    return 0;
}
