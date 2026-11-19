#include "types.h"
#include "param.h"
#include "memlayout.h"
#include "riscv.h"
#include "spinlock.h"
#include "proc.h"
#include "defs.h"
#include "qlock.h"
	
struct qlock testqlock;

void
initqlock(struct qlock *q, char *name)
{

  initlock(&q->lk, name);
  q->locked =0;
 }


	
void
acquireq(struct qlock *q)
{
  acquire(&q->lk);
  while(q->locked) {
    sleep_prepare(q);
    release(&q->lk);
    sleep();
    acquire(&q->lk);
  }
  q->locked = 1;
  release(&q->lk);
}

void
releaseq(struct qlock *q)
{
  acquire(&q->lk);
  q->locked = 0;
  wakeup(q);
  release(&q->lk);
}

