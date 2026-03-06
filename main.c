#include <stdio.h>
#include <string.h>

struct Expense {
    char name[50];
    float amount;
};

int main() {

    FILE *fp;
    struct Expense myExpenses[100];
    int count = 0;
    int choice = 1;
    float total = 0;

    printf("    Daily Expense Tracker    \n");

    fp = fopen("expenses.txt", "r");

    if (fp != NULL) {
    while (fscanf(fp, "%s %f", myExpenses[count].name, &myExpenses[count].amount) != EOF) {
        total += myExpenses[count].amount;
        count++;
    }
    fclose(fp);
}

    while (choice != 0) {
        printf("\n1. Add Expense\n0. Exit & Show Total\nChoice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            if (count < 100) {
                printf("Enter expense name: ");
                scanf(" %[^\n]", myExpenses[count].name);
                printf("Enter amount: ");
                scanf("%f", &myExpenses[count].amount);
                
                FILE *fp;
                fp = fopen("expenses.txt", "a");
                fprintf(fp, "%s %.2f\n", myExpenses[count].name, myExpenses[count].amount);
                fclose(fp);

                total += myExpenses[count].amount;
                count++;
            } else {
                printf("Expense list full!\n");
            }
        }
    }

    printf("\n    Summary    \n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s: %.2f\n", i + 1, myExpenses[i].name, myExpenses[i].amount);
    }
    printf("Total Expense: %.2f\n", total);


    return 0;









    
}