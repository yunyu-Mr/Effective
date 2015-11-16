#ifndef __SINGLETON_H_
#define __SINGLETON_H_

#include <iostream>
#include <pthread.h>
using namespace std;

class Singleton
{
private:
	int id;
	bool changed;
	pthread_mutex_t mtx;

	Singleton() {
		// private constructor
		id = 0;
		changed = false;
		mtx = PTHREAD_MUTEX_INITIALIZER;
	}
	
	Singleton(Singleton const&);
	Singleton& operator=(Singleton const&);

private:
	static Singleton* instance;

public:
	static Singleton* getInstance() {
		if (instance == NULL) {
			instance = new Singleton();
		}
		return instance;
	}

	int getId() {return id; }
	void setId(int id) {this->id = id; }

	bool isChanged() {return changed;}

	void recvChanged() {
		pthread_mutex_lock(&mtx);
		changed = true;
		pthread_mutex_unlock(&mtx);
	}
	bool ackChanged() {
		pthread_mutex_lock(&mtx);
		changed = false;
		pthread_mutex_unlock(&mtx);
	}
};

Singleton* Singleton::instance = NULL;

#endif