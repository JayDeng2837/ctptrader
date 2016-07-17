#include "fifo_hpq.h"

queue_t global_queue[FIFO_NUMBER];

void fifo_init_hpq(int num)
{
    memset(QUEUE_PTR(num), 0, sizeof(queue_t));
    QUEUE_HEAD(num) = QUEUE_DATA_PTR(num, 0);
    QUEUE_TAIL(num) = QUEUE_DATA_PTR(num, 0);
#if defined(PROD_BATCH) || defined(CONS_BATCH)
    QUEUE_BATCH_HEAD(num) = QUEUE_HEAD(num);
    QUEUE_BATCH_TAIL(num) = QUEUE_TAIL(num);
#endif

    QUEUE_HEAD_ORIG(num) = QUEUE_DATA_PTR(num, 0);
    QUEUE_TAIL_ORIG(num) = QUEUE_DATA_PTR(num, QUEUE_SIZE);

}

#if defined(PROD_BATCH) || defined(CONS_BATCH)
inline int leqthan(LC_ELEMENT_TYPE volatile *point, LC_ELEMENT_TYPE volatile *batch_point)
{
    return (point == batch_point);
}
#endif

#if defined(PROD_BATCH)
inline int produce(queue_t * q, LC_ELEMENT_TYPE value)
{
    if (leqthan(q->tail, q->batch_tail)) {
        /*
         * XXX
         * Is PROD_BATCH_SIZE too large?
         * Joshua Chen
         */
        LC_ELEMENT_TYPE *batch_pos = (LC_ELEMENT_TYPE *) q->tail + PROD_BATCH_SIZE;

        if (batch_pos >= QUEUE_PTR_TAIL_ORIG(q)) {
            batch_pos = QUEUE_PTR_HEAD_ORIG(q);
        }

        if (NULL != (*batch_pos).data) {
            return INSERT_FAILED;
        } else {
            q->batch_tail = batch_pos;
        }
    }
    QUEUE_PTR_TAIL_VAL(q) = value;
    QUEUE_PTR_TAIL(q)++;
    if (QUEUE_PTR_TAIL(q) >= QUEUE_PTR_TAIL_ORIG(q)) {
        QUEUE_PTR_TAIL(q) = QUEUE_PTR_HEAD_ORIG(q);
    }
    return SUCCESS;
}
#else

// Use this!
int produce(queue_t * q, LC_ELEMENT_TYPE value)
{
    //while (QUEUE_PTR_TAIL_VAL(q).data);
    if (NULL != QUEUE_PTR_TAIL_VAL(q).data) {
        return INSERT_FAILED;
    }

    QUEUE_PTR_TAIL_VAL(q) = value;

    QUEUE_PTR_TAIL(q)++;
    if (QUEUE_PTR_TAIL(q) >= QUEUE_PTR_TAIL_ORIG(q)) {
        QUEUE_PTR_TAIL(q) = QUEUE_PTR_HEAD_ORIG(q);
    }

    return SUCCESS;
}
#endif

int insert_hpq(queue_t * q, LC_ELEMENT_TYPE value)
//inline int insert_hpq(queue_t *q, ELEMENT_TYPE value)
{
    return produce(q, value);
}

#if defined(CONS_BATCH)
inline uint64_t read_tsc()
{
    uint64_t time;
    uint32_t msw, lsw;
    __asm__ __volatile__("rdtsc\n\t" "movl %%edx, %0\n\t" "movl %%eax, %1\n\t":"=r"(msw), "=r"(lsw)::"%edx", "%eax");

    time = ((uint64_t) msw << 32) | lsw;
    return time;
}

inline void wait_ticks(uint64_t ticks)
{
    uint64_t curr_time;
    uint64_t time = read_tsc();

    time += ticks;
    do {
        curr_time = read_tsc();
    }
    while (curr_time < time);
}

inline void trashing_detect(queue_t * q)
{
    q->batch_head = q->head + CONS_BATCH_SIZE;
    if (q->batch_head >= QUEUE_PTR_TAIL_ORIG(q))
        q->batch_head = QUEUE_PTR_HEAD_ORIG(q);

#if defined(AVOID_DEADLOCK)
    //uint32_t batch_size = CONS_BATCH_SIZE >> 1;
    unsigned long batch_size = CONS_BATCH_SIZE;

    while (!(*q->batch_head).data) {
        wait_ticks(5000);
        q->batch_head = q->head + batch_size;
        if (q->batch_head >= QUEUE_PTR_TAIL_ORIG(q))
            q->batch_head = QUEUE_PTR_HEAD_ORIG(q);
        /* batch_size should be larger than 1 */
        if (batch_size > 1) {
            batch_size = batch_size >> 1;
        } else {
            if (0 != (*q->head).data) {
                break;
            }
        }
    }
#else
    while (!(*q->batch_head)) {
        wait_ticks(20000);
    }
#endif
}

inline LC_ELEMENT_TYPE consume(queue_t * q)
{
    LC_ELEMENT_TYPE value, *p;

    if (leqthan(q->head, q->batch_head)) {
        trashing_detect(q);
    }
    p = (LC_ELEMENT_TYPE *) QUEUE_PTR_HEAD(q);
    value = *p;
    p->data = 0;
    p->len = 0;
    p++;
    if (unlikely((p >= QUEUE_PTR_TAIL_ORIG(q))))
        p = QUEUE_PTR_HEAD_ORIG(q);

    QUEUE_PTR_HEAD(q) = p;
    return value;
}

#else

#if 0
inline ELEMENT_TYPE consume(queue_t * q)
{
    ELEMENT_TYPE value;

    while (!(QUEUE_PTR_HEAD_VAL(q).data)) ;

    value = QUEUE_PTR_HEAD_VAL(q);

    QUEUE_PTR_HEAD_VAL(q).data = 0x0;
    QUEUE_PTR_HEAD_VAL(q).len = 0;

    QUEUE_PTR_HEAD(q)++;
    if (QUEUE_PTR_HEAD(q) >= QUEUE_PTR_TAIL_ORIG(q)) {
        QUEUE_PTR_HEAD(q) = QUEUE_PTR_HEAD_ORIG(q);
    }

    return value;
}
#endif

// Use this!
int consume(queue_t * q, LC_ELEMENT_TYPE * value)
{
    LC_ELEMENT_TYPE head;

    //while (!(QUEUE_PTR_HEAD_VAL(q).data));
    if (NULL == QUEUE_PTR_HEAD_VAL(q).data) {
        return EXTRACT_FAILED;
    }

    head = QUEUE_PTR_HEAD_VAL(q);
	value->type = head.type;
	value->time_interval = head.time_interval;
    value->data = head.data;

    QUEUE_PTR_HEAD_VAL(q).data = 0x0;
    //QUEUE_PTR_HEAD_VAL(q).len = 0;

    QUEUE_PTR_HEAD(q)++;
    if (QUEUE_PTR_HEAD(q) >= QUEUE_PTR_TAIL_ORIG(q)) {
        QUEUE_PTR_HEAD(q) = QUEUE_PTR_HEAD_ORIG(q);
    }

    return SUCCESS;
}
#endif

int extract_hpq(queue_t * q, LC_ELEMENT_TYPE * value)
//inline int extract_hpq(queue_t *q, ELEMENT_TYPE *value)
{
//      *value = consume(q);
//      return 0;
    return consume(q, value);
}
