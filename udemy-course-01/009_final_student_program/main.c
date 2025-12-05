/******************************************************************************
* @file          :main.c
* @author        :Paul Barrionuevo
* @brief         :student tracker
                   @display all student recrods
                   @enters student record
                   @delete student record
*******************************************************************************/
#include <stdio.h>
#include <stdint.h>
#include <string.h> // Added for strcpy

#include "main.h"

void displayMenu();
void display_all_student_records(STUDENT_ENTRY_t *students, int lenSize);
int add_student(STUDENT_ENTRY_t *students, int lenSize); // Return new size
int remove_student(STUDENT_ENTRY_t *students, int lenSize);

int main()
{
    printf("** Student record manage program ** \n");
    displayMenu();
    return 0;
}

void displayMenu()
{
    STUDENT_ENTRY_t students[MAX_STUDENTS];
    int lenSize = 0; // Initialize with the number of pre-existing students
    int option;

    printf("Select one of the options:\n");

    do
    {
        printf("Display all records  -->1 \n");
        printf("Add a new record     -->2 \n");
        printf("Delete record        -->3 \n");
        printf("Exit application     -->0 \n");
        scanf("%d", &option);

        switch(option)
        {
            case 0:
                printf("Exiting app...\n");
                break;

            case 1:
                display_all_student_records(students, lenSize);
                break;

            case 2:
                if (lenSize < MAX_STUDENTS) {
                    lenSize = add_student(students, lenSize);
                } else {
                    printf("Error: Student list is empty!\n");
                }
                break;

            case 3:
                if (lenSize > 0) {
                    lenSize = remove_student(students, lenSize);
                } else {
                    printf("Error: Student list is full!\n");
                }
                break;

            default:
                printf("Invalid option\n");
                break;
        }
    } while (option != 0);
}

void display_all_student_records(STUDENT_ENTRY_t *students, int lenSize)
{
    printf("Number of students: %d\n", lenSize);
    if(lenSize == 0) printf("There are no students registered. \n");
    for (int i = 0; i < lenSize; i++)
    {
        printf("Student %d:\n", i + 1);
        printf("  Roll number: %d\n", students[i].rollNumber);
        printf("  Name: %s\n", students[i].name);
        printf("  Branch: %s\n", students[i].branch);
    }
}

int add_student(STUDENT_ENTRY_t *students, int lenSize)
{
    int newRollNumber;
    char newName[30];
    char newBranch[50];

    printf("Enter an ID number: ");
    scanf("%d", &newRollNumber);
    printf("Enter a Student name and last name: ");
    scanf("%s", newName); // Note: This will only read one word; consider fgets for full names
    printf("Enter an education branch: ");
    scanf("%s", newBranch); // Note: This will only read one word

    // Add student at the current lenSize index
    students[lenSize].rollNumber = newRollNumber;
    strcpy(students[lenSize].name, newName); // Copy string
    strcpy(students[lenSize].branch, newBranch); // Copy string

    printf("Student was added successfully\n");

    return lenSize + 1; // Return updated size
}

int remove_student(STUDENT_ENTRY_t *students, int lenSize)
{
    int id;
    printf("Enter the ID of the student you want to remove: ");
    scanf("%d", &id);

    // Search for the student with the given ID
    int foundIndex = -1;
    for (int i = 0; i < lenSize; i++)
    {
        if (id == students[i].rollNumber)
        {
            foundIndex = i;
            break;
        }
    }

    // If student is found, remove by shifting elements
    if (foundIndex != -1)
    {
        // Shift all subsequent students to the left
        for (int i = foundIndex; i < lenSize - 1; i++)
        {
            students[i] = students[i + 1];
        }
        printf("Student with ID %d removed successfully\n", id);
        return lenSize - 1; // Return updated size
    }
    else
    {
        printf("Error: Student with ID %d not found\n", id);
        return lenSize; // Return original size since no student was removed
    }
}