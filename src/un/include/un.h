#ifndef _UN_H_
#define _UN_H_
#ifdef WIN32
#include <wtypes.h>
#endif
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "un_common.h"
#include "un_error.h"
#ifdef WIN32
#include "un-win.h"
#elif defined(linux)
#include"un-linux.h"
#endif
#if defined (_MSC_VER) && ( _MSC_VER < 1600)
#include "un_stdint-2008.h"
#else
#include <stdint.h>
//#include "un_stdint-2008.h"
#endif
#ifdef __cplusplus
extern "C"{
#endif

	int un_thread_create(un_thread_t* thread,void(*entery)(void*arg),void* arg);
	int un_thread_join(un_thread_t* tid);
	//互斥
	int un_mutex_init(un_mutex_t* mutex);
	void un_mutex_destroy(un_mutex_t* mutex);
	void un_mutex_lock(un_mutex_t* mutex);
	void un_mutex_unlock(un_mutex_t* mutex);
	int un_mutex_trylock(un_mutex_t* mutex);
	//读写锁
	int un_rwlock_init(un_rwlock_t* rwlock);
	void un_rwlock_destroy(un_rwlock_t* rwlock);
	void un_rwlock_rdlock(un_rwlock_t* rwlock);
	int un_rwlock_tryrdlock(un_rwlock_t* rwlock);
	void un_rwlock_rdunlock(un_rwlock_t* rwlock);
	void un_rwlock_wrlock(un_rwlock_t* rwlock);
	int un_rwlock_trywrlock(un_rwlock_t* rwlock);
	void un_rwlock_wrunlock(un_rwlock_t* rwlock);
	//条件变量
	int un_cond_init(un_cond_t* cond);
	void un_cond_destroy(un_cond_t* cond);
	void un_cond_wait(un_cond_t* cond,un_mutex_t* mutex);
	int un_cond_timedwait(un_cond_t* cond,un_mutex_t* mutex, uint64_t timeout);
	void un_cond_signal(un_cond_t* cond);
	void un_cond_broadcast (un_cond_t* cond);
	//信号量
	int un_sem_init(un_sem_t* sem, unsigned int count);
	void un_sem_destroy(un_sem_t* sem);
	void un_sem_post(un_sem_t* sem);
	void un_sem_wait(un_sem_t* sem);
	int un_sem_trywait(un_sem_t* sem);

	//屏障

	int un_barrier_init(un_barrier_t* barrier,unsigned int wait_count_);
	void un_barrier_destroy(un_barrier_t* barrier);
	void un_barrier_wait(un_barrier_t* barrier);

	void un_sleep(uint64_t millseconds);
	unsigned long  un_thread_self();
	void un_once(un_once_t* once,void(*callback)(void));

#ifdef __cplusplus
}
#endif
//



#endif
