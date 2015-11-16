#include "singleton.h"
#include <unistd.h>

// using namespace std;

static void* thread1(void* argv) {
	Singleton *s = Singleton::getInstance();
	while (true) {
		s->recvChanged();
		cout<<"Thread1 : "<<s->isChanged()<<"\n"<<endl;
		sleep(5);
	}
	return NULL;
}

static void* thread2(void* argv) {
	Singleton *s = Singleton::getInstance();
	while (true) {
		cout<<"Thread2 : "<<s->isChanged()<<"\t";
		if (s->isChanged()) {
			cout<<"Find changed   "<<s->isChanged()<<"\n"<<endl;
			s->ackChanged();
		}else {
			cout<<"Is changed?  no\n"<<endl;
		}
		sleep(1);
	}
}

int main(int argc, char const *argv[])
{
	// Singleton *s = Singleton::getInstance();

	pthread_t trd1, trd2;
	void *t1, *t2;
	pthread_create(&trd1, NULL, thread1, NULL);
	sleep(1);
	pthread_create(&trd2, NULL, thread2, NULL);
	pthread_join(trd1, &t1);
	pthread_join(trd2, &t2);
	return 0;
}