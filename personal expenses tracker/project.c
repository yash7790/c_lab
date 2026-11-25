#include <stdio.h>
#include <string.h>

#define MAX 100
#define MAX_CATEGORIES 50

/* ---------------- EXPENSE DATA ---------------- */

int id[MAX];
float amount[MAX];
int expenseCategoryId[MAX];

int count = 0;
int nextId = 1;

/* ---------------- CATEGORY DATA ---------------- */

int categoryId[MAX_CATEGORIES];
char categoryName[MAX_CATEGORIES][30];

int categoryCount = 0;
int nextCategoryId = 1;

/* ---------------- POCKET MONEY ---------------- */

float pocketMoney = 0;


/* ---------------- FUNCTION DECLARATIONS ---------------- */

void clearInputBuffer();

void addExpense();
void viewExpense();
void viewCategories();
void categorySummary();
void searchExpense();
void deleteExpense();
void warning();
void highestExpense();

int findCategoryIndex(int catId);
int createCategory();
char *getCategoryName(int catId);


/* =========================================================
                    CLEAR INPUT BUFFER
   ========================================================= */

void clearInputBuffer()
{
    int ch;

    while((ch = getchar()) != '\n' && ch != EOF)
    {
        /* Remove invalid characters */
    }
}


/* =========================================================
                         MAIN
   ========================================================= */

int main()
{
    int choice;

    printf("\n");
    printf("====================================================\n");
    printf("             PERSONAL EXPENSE TRACKER               \n");
    printf("====================================================\n");

    /* Safe pocket money input */

    while(1)
    {
        printf("\nEnter Your Pocket Money: Rs. ");

        if(scanf("%f", &pocketMoney) != 1)
        {
            printf("Invalid Input! Enter numbers only.\n");
            clearInputBuffer();
            continue;
        }

        if(pocketMoney <= 0)
        {
            printf("Pocket Money must be greater than zero.\n");
            continue;
        }

        break;
    }


    do
    {
        printf("\n");
        printf("+--------------------------------------------------+\n");
        printf("|                    MAIN MENU                     |\n");
        printf("+--------------------------------------------------+\n");
        printf("|   1. Add New Expense                             |\n");
        printf("|   2. View All Expenses                           |\n");
        printf("|   3. Category Expense Summary                    |\n");
        printf("|   4. Search Expense                              |\n");
        printf("|   5. Delete Expense                              |\n");
        printf("|   6. Highest Expense & Sorting                   |\n");
        printf("|   7. Money Dashboard                             |\n");
        printf("|   8. Exit Program                                |\n");
        printf("+--------------------------------------------------+\n");

        printf("\nEnter Your Choice: ");

        if(scanf("%d", &choice) != 1)
        {
            printf("\nInvalid Input! Enter numbers only.\n");
            clearInputBuffer();
            continue;
        }


        switch(choice)
        {
            case 1:
                addExpense();
                break;

            case 2:
                viewExpense();
                break;

            case 3:
                categorySummary();
                break;

            case 4:
                searchExpense();
                break;

            case 5:
                deleteExpense();
                break;

            case 6:
                highestExpense();
                break;

            case 7:
                warning();
                break;

            case 8:
                printf("\n");
                printf("====================================================\n");
                printf("       THANK YOU FOR USING OUR TRACKER!\n");
                printf("          SAVE MONEY, SPEND WISELY!\n");
                printf("====================================================\n");
                break;

            default:
                printf("\nInvalid Choice! Please select 1 to 8.\n");
        }

    } while(choice != 8);

    return 0;
}


/* =========================================================
                   FIND CATEGORY
   ========================================================= */

int findCategoryIndex(int catId)
{
    int i;

    for(i = 0; i < categoryCount; i++)
    {
        if(categoryId[i] == catId)
        {
            return i;
        }
    }

    return -1;
}


/* =========================================================
                   GET CATEGORY NAME
   ========================================================= */

char *getCategoryName(int catId)
{
    int index;

    index = findCategoryIndex(catId);

    if(index != -1)
    {
        return categoryName[index];
    }

    return "Unknown";
}


/* =========================================================
                    CREATE CATEGORY
   ========================================================= */

int createCategory()
{
    int i;
    char newName[30];

    if(categoryCount >= MAX_CATEGORIES)
    {
        printf("\nCategory Storage Full!\n");
        return -1;
    }

    printf("\nEnter New Category Name: ");

    if(scanf("%29s", newName) != 1)
    {
        clearInputBuffer();
        return -1;
    }


    /* Check duplicate category */

    for(i = 0; i < categoryCount; i++)
    {
        if(strcmp(categoryName[i], newName) == 0)
        {
            printf("\nCategory Already Exists!\n");
            printf("Category ID: %d\n",
                   categoryId[i]);

            return categoryId[i];
        }
    }


    categoryId[categoryCount] = nextCategoryId;

    strcpy(categoryName[categoryCount],
           newName);


    printf("\n");
    printf("----------------------------------------------\n");
    printf("       NEW CATEGORY CREATED SUCCESSFULLY!\n");
    printf("----------------------------------------------\n");

    printf("Category ID   : %d\n",
           nextCategoryId);

    printf("Category Name : %s\n",
           newName);


    categoryCount++;
    nextCategoryId++;


    return categoryId[categoryCount - 1];
}


/* =========================================================
                    VIEW CATEGORIES
   ========================================================= */

void viewCategories()
{
    int i;

    printf("\n");
    printf("+------------------------------------------+\n");
    printf("|           AVAILABLE CATEGORIES           |\n");
    printf("+------------------------------------------+\n");

    if(categoryCount == 0)
    {
        printf("\nNo Categories Created Yet!\n");
    }
    else
    {
        printf("\n%-10s %-25s\n",
               "ID",
               "CATEGORY");

        printf("------------------------------------------\n");


        for(i = 0; i < categoryCount; i++)
        {
            printf("%-10d %-25s\n",
                   categoryId[i],
                   categoryName[i]);
        }
    }


    printf("------------------------------------------\n");
    printf("0          ADD NEW CATEGORY\n");
    printf("------------------------------------------\n");
}


/* =========================================================
                       ADD EXPENSE
   ========================================================= */

void addExpense()
{
    int again;
    int selectedCategory;
    int categoryIndex;
    float enteredAmount;

    again = 1;


    while(again == 1)
    {
        if(count >= MAX)
        {
            printf("\nExpense Storage Full!\n");
            return;
        }


        printf("\n");
        printf("+--------------------------------------------------+\n");
        printf("|                 ADD NEW EXPENSE                  |\n");
        printf("+--------------------------------------------------+\n");


        viewCategories();


        /* ---------- CATEGORY INPUT ---------- */

        printf("\nEnter Category ID (0 = New Category): ");


        if(scanf("%d", &selectedCategory) != 1)
        {
            printf("\nInvalid Input!\n");
            printf("Please enter Category ID as a number.\n");

            clearInputBuffer();
            continue;
        }


        /* ---------- CREATE NEW CATEGORY ---------- */

        if(selectedCategory == 0)
        {
            selectedCategory = createCategory();

            if(selectedCategory == -1)
            {
                printf("\nUnable to create category.\n");
                continue;
            }
        }


        /* ---------- VALIDATE CATEGORY ---------- */

        categoryIndex =
            findCategoryIndex(selectedCategory);


        if(categoryIndex == -1)
        {
            printf("\nInvalid Category ID!\n");
            printf("Please select an ID from the list.\n");

            continue;
        }


        printf("\nExpense ID : %d\n",
               nextId);

        printf("Category   : %s\n",
               categoryName[categoryIndex]);


        /* ---------- AMOUNT INPUT ---------- */

        while(1)
        {
            printf("Enter Amount: Rs. ");


            if(scanf("%f", &enteredAmount) != 1)
            {
                printf("\nInvalid Input!\n");
                printf("Please enter amount in numbers only.\n");

                clearInputBuffer();
                continue;
            }


            if(enteredAmount <= 0)
            {
                printf("\nInvalid Amount!\n");
                printf("Amount must be greater than zero.\n");

                continue;
            }


            break;
        }


        /* ---------- SAVE EXPENSE ---------- */

        id[count] = nextId;

        expenseCategoryId[count] =
            selectedCategory;

        amount[count] =
            enteredAmount;


        nextId++;
        count++;


        printf("\n");
        printf("----------------------------------------------\n");
        printf("         EXPENSE ADDED SUCCESSFULLY!\n");
        printf("----------------------------------------------\n");


        printf("Expense ID : %d\n",
               id[count - 1]);

        printf("Category   : %s\n",
               getCategoryName(
                   expenseCategoryId[count - 1]));

        printf("Amount     : Rs. %.2f\n",
               amount[count - 1]);


        warning();


        /* ---------- ADD ANOTHER ---------- */

        while(1)
        {
            printf("\nAdd Another Expense? ");
            printf("(1 = Yes, 0 = No): ");


            if(scanf("%d", &again) != 1)
            {
                printf("Invalid Input! Enter 1 or 0.\n");

                clearInputBuffer();
                continue;
            }


            if(again != 0 && again != 1)
            {
                printf("Please enter only 1 or 0.\n");
                continue;
            }


            break;
        }
    }
}


/* =========================================================
                    VIEW ALL EXPENSES
   ========================================================= */

void viewExpense()
{
    int i;
    float total;

    total = 0;


    if(count == 0)
    {
        printf("\nNo Expenses Found!\n");
        return;
    }


    printf("\n");
    printf("+--------------------------------------------------+\n");
    printf("|                   EXPENSE LIST                   |\n");
    printf("+--------------------------------------------------+\n");


    printf("\n%-8s %-8s %-18s %-12s\n",
           "EXP ID",
           "CAT ID",
           "CATEGORY",
           "AMOUNT");


    printf("--------------------------------------------------\n");


    for(i = 0; i < count; i++)
    {
        printf("%-8d %-8d %-18s Rs. %-8.2f\n",
               id[i],
               expenseCategoryId[i],
               getCategoryName(
                   expenseCategoryId[i]),
               amount[i]);


        total += amount[i];
    }


    printf("--------------------------------------------------\n");

    printf("Number of Expenses : %d\n",
           count);

    printf("Total Money Spent   : Rs. %.2f\n",
           total);
}


/* =========================================================
                    CATEGORY SUMMARY
   ========================================================= */

void categorySummary()
{
    int i;
    int j;

    float categoryTotal;
    float grandTotal;

    grandTotal = 0;


    if(categoryCount == 0)
    {
        printf("\nNo Categories Found!\n");
        return;
    }


    printf("\n");
    printf("+--------------------------------------------------+\n");
    printf("|              CATEGORY EXPENSE SUMMARY            |\n");
    printf("+--------------------------------------------------+\n");


    printf("\n%-8s %-20s %-15s\n",
           "CAT ID",
           "CATEGORY",
           "TOTAL SPENT");


    printf("--------------------------------------------------\n");


    for(i = 0; i < categoryCount; i++)
    {
        categoryTotal = 0;


        for(j = 0; j < count; j++)
        {
            if(expenseCategoryId[j] ==
               categoryId[i])
            {
                categoryTotal += amount[j];
            }
        }


        printf("%-8d %-20s Rs. %-10.2f\n",
               categoryId[i],
               categoryName[i],
               categoryTotal);


        grandTotal += categoryTotal;
    }


    printf("--------------------------------------------------\n");

    printf("%-29s Rs. %.2f\n",
           "TOTAL EXPENSE:",
           grandTotal);

    printf("--------------------------------------------------\n");
}


/* =========================================================
                     SEARCH EXPENSE
   ========================================================= */

void searchExpense()
{
    int choice;
    int eid;
    int catId;
    int i;
    int found;

    found = 0;


    printf("\n");
    printf("+--------------------------------------------------+\n");
    printf("|                  SEARCH EXPENSE                  |\n");
    printf("+--------------------------------------------------+\n");


    printf("\n1. Search By Expense ID\n");
    printf("2. Search By Category ID\n");

    printf("\nEnter Choice: ");


    if(scanf("%d", &choice) != 1)
    {
        printf("\nInvalid Input!\n");
        clearInputBuffer();
        return;
    }


    if(choice == 1)
    {
        printf("\nEnter Expense ID: ");


        if(scanf("%d", &eid) != 1)
        {
            printf("\nInvalid Expense ID!\n");
            clearInputBuffer();
            return;
        }


        for(i = 0; i < count; i++)
        {
            if(id[i] == eid)
            {
                printf("\nExpense Found!\n");

                printf("----------------------------------------\n");

                printf("Expense ID  : %d\n",
                       id[i]);

                printf("Category ID : %d\n",
                       expenseCategoryId[i]);

                printf("Category    : %s\n",
                       getCategoryName(
                           expenseCategoryId[i]));

                printf("Amount      : Rs. %.2f\n",
                       amount[i]);

                printf("----------------------------------------\n");

                found = 1;
                break;
            }
        }
    }


    else if(choice == 2)
    {
        viewCategories();

        printf("\nEnter Category ID: ");


        if(scanf("%d", &catId) != 1)
        {
            printf("\nInvalid Input!\n");
            clearInputBuffer();
            return;
        }


        if(findCategoryIndex(catId) == -1)
        {
            printf("\nInvalid Category ID!\n");
            return;
        }


        printf("\nExpenses in Category: %s\n",
               getCategoryName(catId));

        printf("----------------------------------------\n");


        for(i = 0; i < count; i++)
        {
            if(expenseCategoryId[i] == catId)
            {
                printf("Expense ID : %-5d ",
                       id[i]);

                printf("Amount : Rs. %.2f\n",
                       amount[i]);

                found = 1;
            }
        }


        printf("----------------------------------------\n");
    }


    else
    {
        printf("\nInvalid Choice!\n");
        return;
    }


    if(found == 0)
    {
        printf("\nExpense Not Found!\n");
    }
}


/* =========================================================
                     DELETE EXPENSE
   ========================================================= */

void deleteExpense()
{
    int eid;
    int i;
    int j;
    int found;

    found = 0;


    if(count == 0)
    {
        printf("\nNo Expenses Available To Delete!\n");
        return;
    }


    viewExpense();


    printf("\n");
    printf("+--------------------------------------------------+\n");
    printf("|                  DELETE EXPENSE                  |\n");
    printf("+--------------------------------------------------+\n");


    printf("\nEnter Expense ID To Delete: ");


    if(scanf("%d", &eid) != 1)
    {
        printf("\nInvalid Expense ID!\n");
        clearInputBuffer();
        return;
    }


    for(i = 0; i < count; i++)
    {
        if(id[i] == eid)
        {
            for(j = i; j < count - 1; j++)
            {
                id[j] =
                    id[j + 1];

                amount[j] =
                    amount[j + 1];

                expenseCategoryId[j] =
                    expenseCategoryId[j + 1];
            }


            count--;
            found = 1;

            break;
        }
    }


    if(found)
    {
        printf("\nExpense Deleted Successfully!\n");
    }
    else
    {
        printf("\nExpense ID Not Found!\n");
    }


    warning();
}


/* =========================================================
                     MONEY DASHBOARD
   ========================================================= */

void warning()
{
    int i;

    float total;
    float remaining;
    float percent;

    total = 0;


    for(i = 0; i < count; i++)
    {
        total += amount[i];
    }


    remaining =
        pocketMoney - total;


    if(pocketMoney > 0)
    {
        percent =
            (total / pocketMoney) * 100;
    }
    else
    {
        percent = 0;
    }


    printf("\n");
    printf("+--------------------------------------------------+\n");
    printf("|                  MONEY DASHBOARD                 |\n");
    printf("+--------------------------------------------------+\n");


    printf("\nPocket Money : Rs. %.2f\n",
           pocketMoney);

    printf("Total Spent  : Rs. %.2f\n",
           total);

    printf("Remaining    : Rs. %.2f\n",
           remaining);

    printf("Money Used   : %.2f%%\n",
           percent);


    printf("\n--------------------------------------------------\n");


    if(percent >= 100)
    {
        printf("WARNING! POCKET MONEY FINISHED!\n");
    }

    else if(percent >= 90)
    {
        printf("Critical Warning! Control Expenses!\n");
    }

    else if(percent >= 75)
    {
        printf("Warning! Pocket Money Almost Finished!\n");
    }

    else
    {
        printf("Great! You Are Managing Money Well!\n");
    }


    printf("--------------------------------------------------\n");
}


/* =========================================================
                HIGHEST EXPENSE + SORTING
   ========================================================= */

void highestExpense()
{
    int i;
    int j;

    int tempId[MAX];
    int tempCategory[MAX];

    float tempAmount[MAX];

    int swapId;
    int swapCategory;

    float swapAmount;


    if(count == 0)
    {
        printf("\nNo Expenses Found!\n");
        return;
    }


    /* Copy original data */

    for(i = 0; i < count; i++)
    {
        tempId[i] =
            id[i];

        tempCategory[i] =
            expenseCategoryId[i];

        tempAmount[i] =
            amount[i];
    }


    /* Descending sort */

    for(i = 0; i < count - 1; i++)
    {
        for(j = i + 1; j < count; j++)
        {
            if(tempAmount[i] < tempAmount[j])
            {
                swapAmount =
                    tempAmount[i];

                tempAmount[i] =
                    tempAmount[j];

                tempAmount[j] =
                    swapAmount;


                swapId =
                    tempId[i];

                tempId[i] =
                    tempId[j];

                tempId[j] =
                    swapId;


                swapCategory =
                    tempCategory[i];

                tempCategory[i] =
                    tempCategory[j];

                tempCategory[j] =
                    swapCategory;
            }
        }
    }


    printf("\n");
    printf("+--------------------------------------------------+\n");
    printf("|                  EXPENSE ANALYSIS                |\n");
    printf("+--------------------------------------------------+\n");


    printf("\nHighest Expense\n");

    printf("----------------------------------------\n");

    printf("Expense ID : %d\n",
           tempId[0]);

    printf("Category   : %s\n",
           getCategoryName(tempCategory[0]));

    printf("Amount     : Rs. %.2f\n",
           tempAmount[0]);

    printf("----------------------------------------\n");


    printf("\nExpenses In Descending Order:\n\n");


    printf("%-8s %-18s %-12s\n",
           "ID",
           "CATEGORY",
           "AMOUNT");


    printf("------------------------------------------\n");


    for(i = 0; i < count; i++)
    {
        printf("%-8d %-18s Rs. %-8.2f\n",
               tempId[i],
               getCategoryName(\
                
                   tempCategory[i]),
               tempAmount[i]);
    }


    printf("------------------------------------------\n");
}