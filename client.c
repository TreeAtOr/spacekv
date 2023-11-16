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


//here task names

//here task names

//here create database
void createDB() {

}
//here...

//here connect database
void connectDB() {

}
//...

//here disconnect database
void disconnectDB() {

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

		if (strcmp(command, "create")) createDB();
		if (strcmp(command, "connect")) connectDB();
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

	//create/connect shared memory 
	int shmid = shmget(key, SHMSIZE, 0666 | IPC_CREAT);
	printf("%d\n", shmid);
	if (shmid == -1) {
		printf("Shmid error \n");
		printf("ERRNO - %d\n", errno);
		return -1;
	}
	//create...

	//include the shared memory area in the address space of the current process
	if ((sgmb = (struct shmbuf*)shmat(shmid, NULL, 0)) == (struct shmbuf*)(-1)) {
		printf("Can't attach shared memory\n");
		return -1;
	}
	//include...


	return 0;
}


