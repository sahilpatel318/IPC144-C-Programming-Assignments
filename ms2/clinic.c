/*/////////////////////////////////////////////////////////////////////////
                          <assessment name example: Assignment 1 MS-1 >
Full Name  : Sahil Hareshbhai Patel
Student ID#: 173793225
Email      : shpatel27@myseneca.ca
Section    : NJJ

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

// include the user library "core" so we can use those functions
#include "core.h"
// include the user library "clinic" where the function prototypes are declared
#include "clinic.h"


//////////////////////////////////////
// DISPLAY FUNCTIONS
//////////////////////////////////////

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display's the patient table header (table format)
void displayPatientTableHeader(void)
{
    printf("Pat.# Name            Phone#\n"
           "----- --------------- --------------------\n");
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Displays a single patient record in FMT_FORM | FMT_TABLE format
void displayPatientData(const struct Patient* patient, int fmt)
{
    if (fmt == FMT_FORM)
    {
        printf("Name  : %s\n"
               "Number: %05d\n"
               "Phone : ", patient->name, patient->patientNumber);
        displayFormattedPhone(patient->phone.number);
        printf(" (%s)\n", patient->phone.description);
    }
    else
    {
        printf("%05d %-15s ", patient->patientNumber,
               patient->name);
        displayFormattedPhone(patient->phone.number);
        printf(" (%s)\n", patient->phone.description);
    }
}


//////////////////////////////////////
// MENU & ITEM SELECTION FUNCTIONS
//////////////////////////////////////

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// main menu
void menuMain(struct ClinicData* data)
{
    int selection;

    do {
        printf("Veterinary Clinic System\n"
               "=========================\n"
               "1) PATIENT     Management\n"
               "2) APPOINTMENT Management\n"
               "-------------------------\n"
               "0) Exit System\n"
               "-------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 2);
        putchar('\n');
        switch (selection)
        {
        case 0:
            printf("Are you sure you want to exit? (y|n): ");
            selection = !(inputCharOption("yn") == 'y');
            putchar('\n');
            if (!selection)
            {
                printf("Exiting system... Goodbye.\n\n");
            }
            break;
        case 1:
            menuPatient(data->patients, data->maxPatient);
            break;
        case 2:
            printf("<<< Feature not yet available >>>\n\n");
            break;
        }
    } while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient Management
void menuPatient(struct Patient patient[], int max)
{
    int selection;

    do {
        printf("Patient Management\n"
               "=========================\n"
               "1) VIEW   Patient Data\n"
               "2) SEARCH Patients\n"
               "3) ADD    Patient\n"
               "4) EDIT   Patient\n"
               "5) REMOVE Patient\n"
               "-------------------------\n"
               "0) Previous menu\n"
               "-------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 5);
        putchar('\n');
        switch (selection)
        {
        case 1:
            displayAllPatients(patient, max, FMT_TABLE);
            suspend();
            break;
        case 2:
            searchPatientData(patient, max);
            break;
        case 3:
            addPatient(patient, max);
            suspend();
            break;
        case 4:
            editPatient(patient, max);
            break;
        case 5:
            removePatient(patient, max);
            suspend();
            break;
        }
    } while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient edit
void menuPatientEdit(struct Patient* patient)
{
    int selection;

    do {
        printf("Edit Patient (%05d)\n"
            "=========================\n", patient->patientNumber);

        printf("1) NAME : %s\n", patient->name);
        printf("2) PHONE: ");
        displayFormattedPhone(patient->phone.number);
        
        
        printf("\n"
               "-------------------------\n"
               "0) Previous menu\n"
               "-------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 2);
        putchar('\n');

        if (selection == 1)
        {
            printf("Name  : ");
            inputCString(patient->name, 1, NAME_LEN);
            putchar('\n');
            printf("Patient record updated!\n\n");
        }
        else if (selection == 2)
        {
            inputPhoneData(&patient->phone);
            printf("\nPatient record updated!\n\n");
        }

    } while (selection);
}


// ---------------------------------------------------------------------------
// !!! Put all the remaining function definitions below !!!
// Note: Maintain the same order/sequence as it is listed in the header file
// ---------------------------------------------------------------------------

// Display's all patient data in the FMT_FORM | FMT_TABLE format

void displayAllPatients(const struct Patient patient[], int max, int fmt) {

    int i ;
    displayPatientTableHeader();
    for (i=0; i < max; i++) {
        if (patient[i].patientNumber !=  0) {
            displayPatientData(&patient[i], fmt);
        }
    }
    printf("\n");
};

// Search for a patient record based on patient number or phone number
void searchPatientData(const struct Patient patient[], int max) {
    int choice;
    do {
        printf("Search Options\n");
        printf("==========================\n");
        printf("1) By patient number\n");
        printf("2) By phone number\n");
        printf("..........................\n");
        printf("0) Previous menu\n");
        printf("..........................\n");
        printf("Selection: ");
        choice = inputIntRange(0, 2);

        switch (choice) {
        case 1:
            searchPatientByPatientNumber(patient, max);
            break;
        case 2:
            searchPatientByPhoneNumber(patient, max);
            break;
        }
    } while (choice);
    printf("\n");
};


// Add a new patient record to the patient array
void addPatient(struct Patient patient[], int max) {
    int i ;
    int found = 0;

    for (i=0; ((i < max) && (!found)); i++) {
        if (patient[i].patientNumber == 0) {
            found = 1;
            
            
        }
    }
    i -= 1; // ++ increase the index to next one 
    if (found) {
        int patientId = nextPatientNumber(patient, max);
        patient[i].patientNumber = patientId;
        inputPatient(&patient[i]);
    }
    else {
        printf("ERROR: Patient listing is FULL!\n\n");
    }
    

};


// Edit a patient record from the patient array
void editPatient(struct Patient patient[], int max) {
    printf("Enter the patient number: ");
    int patNum = inputInt();
    int index = findPatientIndexByPatientNum(patNum, patient, max);
    if (index == -1) {
        printf("\nERROR: Patient record not found!\n\n");
    }
    else {
        printf("\n");
        menuPatientEdit(&patient[index]);
    }

};


// Remove a patient record from the patient array
void removePatient(struct Patient patient[], int max) {
    printf("Enter the patient number: ");
    int patNum = inputIntPositive();
    int index = findPatientIndexByPatientNum(patNum, patient, max);
    if (index == -1) {
        printf("\nERROR: Patient record not found!\n\n");
    }
    else {
        printf("\n");
        displayPatientData(&patient[index], FMT_FORM);
        printf("\nAre you sure you want to remove this patient record? (y/n): ");
        char option = inputCharOption("yn");
        if (option == 'y') {
            patient[index].patientNumber = 0;
            printf("Patient record has been removed!\n\n");
        }
        else {
            printf("Operation aborted.\n\n");
        }
    }
};



//////////////////////////////////////
// UTILITY FUNCTIONS
//////////////////////////////////////

// Search and display patient record by patient number (form)
void searchPatientByPatientNumber(const struct Patient patient[], int max) {
    printf("\nSearch by patient number: ");
    int patentNum = inputIntPositive();
    int index = findPatientIndexByPatientNum(patentNum, patient, max);
    if (index == -1) {
        printf("\n*** No records found ***\n");
    }
    else {
        printf("\n");
        displayPatientData(&patient[index], FMT_FORM);
       // printf("\nName  : %s\n", patient[index].name);
    //    printf("Number: %d\n", patient[index].patientNumber);
      //  printf("Phone : ");
        //displayFormattedPhone(patient[index].phone.number);
        //printf(" (%s)\n\n", patient[index].phone.description);
    }
    printf("\n");
    suspend();
};


// Search and display patient records by phone number (tabular)
void searchPatientByPhoneNumber(const struct Patient patient[], int max) {
    printf("\nSearch by phone number: ");
    char patentNum[PHONE_LEN+1];
    inputCString(patentNum, PHONE_LEN, PHONE_LEN);
    int found = 0;
    int index ;
    printf("\n");
    displayPatientTableHeader();
    for (index = 0;  index < max; index++) {
        if (strcmp(patient[index].phone.number , patentNum) == 0) {
            found = 1;
            
            displayPatientData(&patient[index], FMT_TABLE);
        }
    }
    
    if (!found) {
        printf("\n*** No records found ***\n");
    }
    printf("\n");
   
    suspend();
};

// Get the next highest patient number
int nextPatientNumber(const struct Patient patient[], int max) { 
    int i ;
    int unique = 0;
    for (i = 0; i < max; i++) {
        if (patient[i].patientNumber > unique) {
            unique = patient[i].patientNumber;
        }
    }
    return unique + 1; 
}

// Find the patient array index by patient number (returns -1 if not found)
int findPatientIndexByPatientNum(int patientNumber,
    const struct Patient patient[], int max) {
    int index ;
    for (index =0; index < max; index++) {
        if (patient[index].patientNumber == patientNumber) {
            return index;
        }
    }
    
    return -1;
};




//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

// Get user input for a new patient record
void inputPatient(struct Patient* patient) {
    printf("Patient Data Input\n");
    printf("------------------\n");
    printf("Number: %05d\n", patient->patientNumber);
    printf("Name  : ");
    scanf("%[^\n]", patient->name);
    printf("\n");
    inputPhoneData(&(*patient).phone);
    printf("\n*** New patient record added ***\n\n");


};

// Get user input for phone contact information
void inputPhoneData(struct Phone* phone) {
    printf("Phone Information\n"
        "-----------------\n"
        "How will the patient like to be contacted?\n"
        "1. Cell\n"
        "2. Home\n"
        "3. Work\n"
        "4. TBD\n"
        "Selection: ");
    
    int choice = inputIntRange(1, 4);
    switch (choice) {
    case 1:
        strcpy(phone->description , "CELL");
        break;
    case 2:
        strcpy(phone->description, "HOME");
        break;
    case 3:
        strcpy(phone->description, "WORK");
        break;
    case 4:
        strcpy(phone->description, "TBD");
        break;
      
    }
    if (choice == 4) {
        strcpy(phone->number, "");
    }
    else {
        
        printf("\nContact: %s\n", phone->description);
        printf("Number : ");
        inputCString(phone->number, PHONE_LEN, PHONE_LEN);
    }

};
