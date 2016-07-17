#ifndef __FIFO_HPQ_H__
#define __FIFO_HPQ_H__

//#define _XOPEN_SOURCE 600

//#include <unistd.h>
#include <stdio.h>
//#include <inttypes.h>
#include <string.h>
#include <stdint.h>
//#include <pthread.h>

//#define CONS_BATCH
//#define PROD_BATCH
//#define AVOID_DEADLOCK
//#define COMPRESSED_FIFO
#include "ctp_cmessage.h"

#ifdef WIN32
#define ATTR
#else
#define ATTR __attribute__ ((aligned(128)))
#endif

enum {
	MARKET_DATA_FIFO_ID = 0,
	ORDER_FIFO_ID,
	QUERY_FIFO_ID,
	TIMER_FIFO_ID,
	RESERVED_FIFO_ID1,
	RESERVED_FIFO_ID2,
	RESERVED_FIFO_ID3,
    MAX_FIFO_NUM
};

#define DUMMY_DATA ((void *) 1)

#define FIFO_NUMBER MAX_FIFO_NUM

#if !defined(COMPRESSED_FIFO)
// Use this!
typedef struct {
	int type;
	int time_interval;
    void *data;
} FIFO_ELEM;
#else
typedef struct {
    uint64_t data:48;
    uint64_t len:16;
} FIFO_ELEM;
#endif

#define likely(x) __builtin_expect((x), 1)
#define unlikely(x) __builtin_expect((x), 0)

#define FIFO_ELEM_DATA(p)       ((p)->data)
#define FIFO_ELEM_SIZE(p)       ((p)->len)

#define INSERT_FAILED   -1
#define EXTRACT_FAILED  -2
#define SUCCESS          0

/****** Should be 2^N *****/
#define MAX_CORE_NUM 8

#define CONS_WORK_CYCLES 0
#define PROD_WORK_CYCLES 0

#define BATCH_SIZE (128)
#define CONS_BATCH_SIZE BATCH_SIZE
#define PROD_BATCH_SIZE BATCH_SIZE
#define QUEUE_SIZE 4096

/***************************/

#define PROBAB (0)
#define PROBAB_MEMCPY 0
#define MEM_LEN (0)
#define PROBAB_MALLOC 0
#define PROBAB_YIELD 0
#define PROBAB_LOCK 0
#define PROBAB_WORKLOAD 10
#define WORKLOAD (40)
#define AVG_WORKLOAD (0)

#define LC_ELEMENT_TYPE FIFO_ELEM

#define PADDING   (64)
#define PAD(suffix, type) char padding ## suffix [PADDING - sizeof(type)]
#define PAD_2(suffix, type_1, type_2) char padding ## suffix [PADDING - sizeof(type_1) - sizeof(type_2)]
#define PAD_3(suffix, type_1, type_2, type_3) char padding ## suffix \
             [PADDING - sizeof(type_1) - sizeof(type_2) - sizeof(type_3)]
#define PAD_4(suffix, type_1, type_2, type_3, type_4) char padding ## suffix \
             [PADDING - sizeof(type_1) - sizeof(type_2) - sizeof(type_3) - sizeof(type_4)]

#if defined(CONS_BATCH) || defined(PROD_BATCH)

typedef struct {
    LC_ELEMENT_TYPE volatile *head;
    LC_ELEMENT_TYPE volatile *batch_head;
      PAD_2(1, LC_ELEMENT_TYPE *, LC_ELEMENT_TYPE *);
    LC_ELEMENT_TYPE volatile *tail;
    LC_ELEMENT_TYPE volatile *batch_tail;
      PAD_2(2, LC_ELEMENT_TYPE *, LC_ELEMENT_TYPE *);
    LC_ELEMENT_TYPE *head_orig;    /* read only */
    LC_ELEMENT_TYPE *tail_orig;    /* read only */
      PAD_2(3, LC_ELEMENT_TYPE *, LC_ELEMENT_TYPE *);
    LC_ELEMENT_TYPE data[QUEUE_SIZE];
} queue_t ATTR;

#else

// Use this!
typedef struct {
    //ELEMENT_TYPE  volatile *head;
    LC_ELEMENT_TYPE *head;
      PAD(1, LC_ELEMENT_TYPE);
    //ELEMENT_TYPE  volatile *tail;
    LC_ELEMENT_TYPE *tail;
      PAD(2, LC_ELEMENT_TYPE);
    uint64_t start_c;
    uint64_t stop_c;
    LC_ELEMENT_TYPE *head_orig;    /* read only */
    LC_ELEMENT_TYPE *tail_orig;    /* read only */
      PAD_4(3, uint64_t, uint64_t, LC_ELEMENT_TYPE *, LC_ELEMENT_TYPE *);
    LC_ELEMENT_TYPE data[QUEUE_SIZE];
} queue_t ATTR;

#endif

extern queue_t global_queue[FIFO_NUMBER];

#define FIFO_BUFFER ELEMENT_TYPE

#define QUEUE(p)	(global_queue[p])
#define QUEUE_PTR(p)	(&global_queue[p])
#define QUEUE_START(p)	(global_queue[p].start_c)
#define QUEUE_STOP(p)	(global_queue[p].stop_c)
#define QUEUE_HEAD(p)	(global_queue[p].head)
#define QUEUE_BATCH_HEAD(p)	(global_queue[p].batch_head)
#define QUEUE_TAIL(p)	(global_queue[p].tail)
#define QUEUE_BATCH_TAIL(p)	(global_queue[p].batch_tail)

#define QUEUE_HEAD_ORIG(p)	(global_queue[p].head_orig)
#define QUEUE_TAIL_ORIG(p)	(global_queue[p].tail_orig)

#define QUEUE_HEAD_VAL(p)	(*global_queue[p].head)
#define QUEUE_TAIL_VAL(p)	(*global_queue[p].tail)
#define QUEUE_DATA(p, i)	(global_queue[p].data[i])
#define QUEUE_DATA_PTR(p, i)	(&(global_queue[p].data[i]))

#define QUEUE_PTR_START(p)	(p->start_c)
#define QUEUE_PTR_STOP(p)	(p->stop_c)
#define QUEUE_PTR_HEAD(p)	(p->head)
#define QUEUE_PTR_TAIL(p)	(p->tail)
#define QUEUE_PTR_HEAD_ORIG(p)	(p->head_orig)
#define QUEUE_PTR_TAIL_ORIG(p)	(p->tail_orig)
#define QUEUE_PTR_HEAD_VAL(p)	(*(p->head))
#define QUEUE_PTR_TAIL_VAL(p)	(*(p->tail))
#define QUEUE_PTR_DATA(p, i)	(p->data[i])
#define QUEUE_PTR_DATA_PTR(p, i)	(&(p->data[i]))

typedef struct {
    uint32_t cpu_id;
    //pthread_barrier_t *barrier;
    void *barrier;
} INIT_INFO;

#define INIT_ID(p)	(init_info[p].cpu_id)
#define INIT_BAR(p)	(init_info[p].barrier)
#define INIT_PTR(p)	(&init_info[p])

//inline int insert_hpq(queue_t *, ELEMENT_TYPE);
int insert_hpq(queue_t *, LC_ELEMENT_TYPE);
int extract_hpq(queue_t *, LC_ELEMENT_TYPE *);

//inline int extract_hpq(queue_t *, ELEMENT_TYPE *);
void fifo_init_hpq(int);

#endif
