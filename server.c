#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <errno.h>
extern int errno;
#include <stdlib.h>
#include <sys/time.h>


struct shmbuf {
	long type;//message type (for server = 0, client1 = 1, client2 = 2... )
	int command;
	int key;
	char data[16];
}shmbuf;

#define SHMSIZE = sizeof()

int main() {

	struct shmbuf sgmb;

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
	if ((array = (int*)shmat(shmid, NULL, 0)) == (int*)(-1)) {
		printf("Can't attach shared memory\n");
		return -1;
	}
	//include...


	//int len = sizeof(int) + 1;
	//struct msgbuf msgb;

	//while (1) {
	//	msgInfo(msgid);

	//	if (msgrcv(msgid, &msgb, len, 0, 0) >= 0) {
	//		//msgInfo(msgid);
	//		printf("Received type %ld\n", msgb.type);
	//		printf("Received text %d\n", msgb.text);
	//		msgb.text = msgb.text * 2;
	//		if (msgsnd(msgid, &msgb, len, 0) < 0) {
	//			printf("Error send");
	//			return 0;
	//		}
	//		printf("Sended\n");
	//		//msgInfo(msgid);
	//		//return 0;
	//	}
	//}


	//if (msgrcv(msgid, &msgb, 255, 1, 0) < 0) {
	//	printf("Rcv Error\n");
	//	return 0;
	//}
	////printf("%s\n", msgbuf.text);

	return 0;
}

