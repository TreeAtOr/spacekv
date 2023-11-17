#include <stdio.h>
#include <stdlib.h>
#include "shm.h"

struct set
{
    int key;
    int data;
};
struct set* array;
//int capacity = 0;
//capacity = ;
int size = 0;


int hashFunction(int key)
{
    return (key % returnSize());
}
//int checkPrime(int n)
//{
//    int i;
//    if (n == 1 || n == 0)
//    {
//        return 0;
//    }
//    for (i = 2; i < n / 2; i++)
//    {
//        if (n % i == 0)
//        {
//            return 0;
//        }
//    }
//    return 1;
//}
//int getPrime(int n)
//{
//    if (n % 2 == 0)
//    {
//        n++;
//    }
//    while (!checkPrime(n))
//    {
//        n += 2;
//    }
//    return n;
//}
//void init_array()
//{
//    capacity = getPrime(capacity);
//    array = (struct set*)malloc(capacity * sizeof(struct set));
//    for (int i = 0; i < capacity; i++)
//    {
//        array[i].key = 0;
//        array[i].data = 0;
//    }
//}

void insert(int key, int data)
{
    int index = hashFunction(key);
    if (addInf(key, data, index) == 0)
        printf("\n Key (%d) insert \n", key);
    else {
        printf("\n Key (%d) insert \n", key);
        printf("\n BUT Collision \n");
    }
}

void remove_element(int key)
{
    int index = hashFunction(key);
    if (deleteInf(index) == 0)
        printf("\n This key does not exist \n");
    else
        printf("\n Key (%d) remove \n", key);

}
void display()
{
    int i;
    for (i = 0; i < returnSize; i++)
    {
        int key = returnKey(i);
        int data = returnData(i);
        if (data == 0)
        {
            printf("\n array[%d]: / ", i);
        }
        else
        {
            printf("\n Key: %d array[%d]: %d \t", key, i, data);
        }
    }
}

//int size_of_hashtable()
//{
//    return size;
//}

int main()
{
    int choice, key, data, n;
    int c = 0;
    //init_array();

    do
    {
        printf("0.Exit"
            "\n1.Insert an element into a hash table"
            "\n2.Remove an element from the hash table"
            "\n3.Find out the size of the hash table"
            "\n4.Output a hash table"


            "\n5.Create new database"
            "\n6.Connect databse"
            "\n7.Disconnect database"

            "\n\n Please select the desired option: ");

        scanf("%d", &choice);
        switch (choice)
        {
        case 0:
            return 0;
        case 1:

            printf("Enter key -:\t");
            scanf("%d", &key);
            printf("Enter data-:\t");
            scanf("%d", &data);
            insert(key, data);

            break;

        case 2:

            printf("Enter the key you want to delete-:");
            scanf("%d", &key);
            remove_element(key);

            break;

        case 3:

            n = returnSize();
            printf("Hash Table size-:%d\n", n);

            break;

        case 4:

            display();

            break;

        case 5:
            int keeeeey;
            printf("Enter the database key -:\t");
            scanf("%d", keeeeey);
            createDB(keeeeey);
            break;

        case 6:
            int k;
            printf("Enter the database key -:\t");
            scanf("%d", k);
            connectDB(k);
            break;

        case 7:
            disconnectDB();
            break;

        default:

            printf("Data entered incorrectly\n");
        }

    } while (1);
}