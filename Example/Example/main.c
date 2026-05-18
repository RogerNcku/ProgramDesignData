#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/* ===== Sort demos ===== */
void runBucketSortDemo(void);
void runQuickSortDemo(void);
void runRadixSortDemo(void);
void runDecodeDemo(void);

/* ===== Stack / Queue demos ===== */
void runStackDemo(void);
void runQueueDemo(void);

static void sortingMenu(void) {
    int choice;

    while (1) {
        printf("\n===== Sorting Menu =====\n");
        printf("1. Bucket Sort\n");
        printf("2. Quick Sort\n");
        printf("3. Radix Sort\n");
        printf("0. Back\n");
        printf("Choose: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input!\n");
            return;
        }

        switch (choice) {
        case 1:
            printf("\n========== Bucket Sort ==========\n");
            runBucketSortDemo();
            break;
        case 2:
            printf("\n========== Quick Sort ==========\n");
            runQuickSortDemo();
            break;
        case 3:
            printf("\n========== Radix Sort ==========\n");
            runRadixSortDemo();
            break;

        case 0:
            return;
        default:
            printf("Invalid choice!\n");
        }
    }
}

int main(void) {
    int choice;

    while (1) {
        printf("\n===== Main Menu =====\n");
        printf("1. Sorting\n");
        printf("2. Stack\n");
        printf("3. Queue\n");
        printf("4. Decode\n");
        printf("0. Exit\n");
        printf("Choose: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input!\n");
            return 0;
        }

        switch (choice) {
        case 1:
            sortingMenu();
            break;
        case 2:
            printf("\n========== Stack Demo ==========\n");
            runStackDemo();
            break;
        case 3:
            printf("\n========== Queue Demo ==========\n");
            runQueueDemo();
            break;
        case 4:
            printf("\n========== Decode Demo ==========\n");
            runDecodeDemo();
            break;
        case 0:
            printf("Bye!\n");
            return 0;
        default:
            printf("Invalid choice!\n");
        }
    }
}


//#include <stdio.h>
//
///* 外部函式宣告 */
//void runBucketSortDemo(void);
//void runQuickSortDemo(void);
//void runRadixSortDemo(void);
//
//int main(void) {
//    printf("========== Bucket Sort ==========\n");
//    runBucketSortDemo();
//
//    printf("\n\n========== Quick Sort ==========\n");
//    runQuickSortDemo();
//
//    printf("\n\n========== Radix Sort ==========\n");
//    runRadixSortDemo();
//
//    return 0;
//}