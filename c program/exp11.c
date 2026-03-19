#include <stdio.h>
#include <string.h>

struct employee {
    int id;
    char name[50];
    float salary;
};


void add_employee() {
    struct employee emp;
    FILE *file = fopen("employee_database.txt", "a");

    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }


    printf("Enter Employee ID: ");
    scanf("%d", &emp.id);
    printf("Enter Employee Name: ");
    getchar();
    gets(emp.name);
    printf("Enter Employee Salary: ");
    scanf("%f", &emp.salary);

    // Write employee data to the file
    fprintf(file, "%d %.2f %s\n", emp.id, emp.salary, emp.name);
    fclose(file);
    printf("Employee record added successfully!\n");
}


void display_employees() {
    struct employee emp;
    FILE *file = fopen("employee_database.txt", "r");

    if (file == NULL) {
        printf("No employee records found!\n");
        return;
    }

    printf("\nEmployee Records:\n");
    printf("ID\tName\t\tSalary\n");
    printf("---------------------------------\n");

    // Read and display each employee record from the file
    while (fscanf(file, "%d %f %[^\n]", &emp.id, &emp.salary, emp.name) != EOF) {
        printf("%d\t%-15s%.2f\n", emp.id, emp.name, emp.salary);
    }

    fclose(file);
}

// Function to edit an employee record
void edit_employee() {
    struct employee emp;
    int id_to_edit, found = 0;
    FILE *file = fopen("employee_database.txt", "r");
    FILE *temp = fopen("temp.txt", "w");

    if (file == NULL) {
        printf("No employee records found to edit!\n");
        return;
    }

    printf("Enter the Employee ID to edit: ");
    scanf("%d", &id_to_edit);

    while (fscanf(file, "%d %f %[^\n]", &emp.id, &emp.salary, emp.name) != EOF) {
        if (emp.id == id_to_edit) {
            found = 1;
            printf("Editing Employee ID %d:\n", emp.id);
            printf("Enter New Name: ");
            getchar();
            gets(emp.name);
            printf("Enter New Salary: ");
            scanf("%f", &emp.salary);
        }
        fprintf(temp, "%d %.2f %s\n", emp.id, emp.salary, emp.name);
    }

    fclose(file);
    fclose(temp);

    if (found) {
        remove("employee_database.txt");
        rename("temp.txt", "employee_database.txt");
        printf("Employee record updated successfully!\n");
    } else {
        remove("temp.txt");
        printf("Employee ID not found!\n");
    }
}

// Function to remove an employee record
void remove_employee() {
    struct employee emp;
    int id_to_remove, found = 0;
    FILE *file = fopen("employee_database.txt", "r");
    FILE *temp = fopen("temp.txt", "w");

    if (file == NULL) {
        printf("No employee records found to delete!\n");
        return;
    }

    printf("Enter the Employee ID to remove: ");
    scanf("%d", &id_to_remove);

    while (fscanf(file, "%d %f %[^\n]", &emp.id, &emp.salary, emp.name) != EOF) {
        if (emp.id == id_to_remove) {
            found = 1;
            printf("Removing Employee ID %d: %s\n", emp.id, emp.name);
            continue;
        }
        fprintf(temp, "%d %.2f %s\n", emp.id, emp.salary, emp.name);
    }

    fclose(file);
    fclose(temp);

    if (found) {
        remove("employee_database.txt");
        rename("temp.txt", "employee_database.txt");
        printf("Employee record removed successfully!\n");
    } else {
        remove("temp.txt");
        printf("Employee ID not found!\n");
    }
}

int main() {
    int choice;

    printf("\t\t *** Employee Database *** \n\n");

    while (1) {
        // Menu for user
        printf("\nEmployee Database Menu:\n");
        printf("1. Add Employee Record\n");
        printf("2. Display Employee Records\n");
        printf("3. Edit Employee Record\n");
        printf("4. Remove Employee Record\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_employee();
                break;
            case 2:
                display_employees();
                break;
            case 3:
                edit_employee();
                break;
            case 4:
                remove_employee();
                break;
            case 5:
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}


