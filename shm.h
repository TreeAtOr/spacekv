#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/time.h>
#include <string.h>

#define MAXSIZE 10

extern int errno;

struct buf {
	int key;
	int data;
}buf;

struct buf* massiv;
int sizeArray = MAXSIZE * sizeof(struct buf);
int capacity = MAXSIZE;
int currentSize = 0;

void initArray() {
	for (int i = 0; i < MAXSIZE; i++)
	{
		massiv[i].key = 0;
		massiv[i].data = 0;
	}
}

//here create database
int createDB(key_t key) {
	printf("ASDASDASDAD\n");
	//sizeArray = size;
	int shmid = shmget(key, sizeArray, 0666 | IPC_CREAT | IPC_EXCL);
	if (shmid == -1) {
		printf("Create error \n");
		printf("ERRNO - %d\n", errno);
		return -1;
	}
	else
	{
		if ((massiv = (struct buf*)shmat(shmid, NULL, 0)) == (struct buf*)(-1)) {
			printf("Can't attach shared memory\n");
			return -1;
		}
		initArray();
		printf("Create and connect to database!\n");
		return shmid;
	}
}
//here...

//here connect database
int connectDB(key_t key) {
	//sizeArray = size;
	int shmid = shmget(key, sizeArray, 0666);
	if (shmid == -1) {
		printf("Create error \n");
		printf("ERRNO - %d\n", errno);
		return -1;
	}
	else
	{
		if ((massiv = (struct buf*)shmat(shmid, NULL, 0)) == (struct buf*)(-1)) {
			printf("Can't attach shared memory\n");
			return -1;
		}
		printf("Create and connect to database!\n");
		return shmid;
	}
}
//...

//here disconnect database
int disconnectDB() {
	if (shmdt(massiv) < 0) {
		printf("Can't detach shared memory\n");
		return -1;
	}
	return 0;
}
//...

//here add informations
int addInf(int key, int data, int index) {
	if (massiv[index].data == 0) {
		massiv[index].key = key;
		massiv[index].data = data;
		currentSize++;
		return 0;
	}
	else {
		massiv[index].key = key;
		massiv[index].data = data;
		currentSize++;
		return 1;
	}
}
//...

//here delete informations
int deleteInf(int index) {
	if (massiv[index].data == 0)
	{
		return 0;
	}
	else
	{
		massiv[index].key = 0;
		massiv[index].data = 0;
		currentSize--;
		return 1;
	}
}
//...

int returnSize() {
	return capacity;
}

//here search
int returnData(int index) {
	return massiv[index].data;
}
int returnKey(int index) {
	return massiv[index].key;
}
//...
