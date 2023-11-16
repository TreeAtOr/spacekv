#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <errno.h>
extern int errno;
#include <stdlib.h>
#include <sys/time.h>
#include <string.h>

struct shmbuf {
	long type;//message type (for server = 0, client1 = 1, client2 = 2... )
	int command;
	int key;
	char data[16];
}shmbuf;

#define SHMSIZE sizeof(shmbuf)
int* notUsed;

//here task names

//here task names

//here create database
int createDB(key_t key, int size) {
	int shmid = shmget(key, size, 0666 | IPC_CREAT | IPC_EXCL);
	if (shmid == -1) {
		printf("Create error \n");
		printf("ERRNO - %d\n", errno);
		return -1;
	}
	else return shmid;
	//printf("%d\n", shmid);
}
//here...

//here connect database
int connectDB(key_t key, int size) {
	int shmid = shmget(key, size, 0666);
	if (shmid == -1) {
		printf("Create error \n");
		printf("ERRNO - %d\n", errno);
		return -1;
	}
	else return shmid;
}
//...

//here disconnect database
int disconnectDB() {
	if (shmdt(*notUsed) < 0) {
		printf("Can't detach shared memory\n");
		return -1;
	}
	return 0;
}
//...

//here add informations
void addInf() {

}
//...

//here delete informations
void deleteInf() {

}
//...

//here search
void search() {

}
//...


//here parser
#define PARSERSIZE 128


int parser() {
	printf("<<GG database>>\n");
	while (1) {
		char command[PARSERSIZE];
		printf("Enter command:\n");
		fgets(command, PARSERSIZE, stdin);

		key_t key;
		int shmid;
		int size;

		if (strcmp(command, "create")) shmid = createDB(key, size);
		if (strcmp(command, "connect")) shmid = connectDB(key, size);
		if (strcmp(command, "disconnect")) disconnectDB();
		if (strcmp(command, "add")) addInf();
		if (strcmp(command, "delete")) deleteInf();
		if (strcmp(command, "search")) search();
	}
}
//here parser


int main() {

	struct shmbuf* sgmb;

	key_t key;
	key = 11;

	int shmid;

	//include the shared memory area in the address space of the current process
	if ((sgmb = (struct shmbuf*)shmat(shmid, NULL, 0)) == (struct shmbuf*)(-1)) {
		printf("Can't attach shared memory\n");
		return -1;
	}
	//include...


	return 0;
}


