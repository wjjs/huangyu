/*
 *  linux/mykernel/myinterrupt.c
 *
 *  Kernel internal my_timer_handler
 *
 *  Copyright (C) 2013  Mengning
 *
 */
#include <linux/kernel_stat.h>
#include <linux/export.h>
#include <linux/interrupt.h>
#include <linux/percpu.h>
#include <linux/init.h>
#include <linux/mm.h>
#include <linux/swap.h>
#include <linux/pid_namespace.h>
#include <linux/notifier.h>
#include <linux/thread_info.h>
#include <linux/time.h>
#include <linux/jiffies.h>
#include <linux/posix-timers.h>
#include <linux/cpu.h>
#include <linux/syscalls.h>
#include <linux/delay.h>
#include <linux/tick.h>
#include <linux/kallsyms.h>
#include <linux/irq_work.h>
#include <linux/sched.h>
#include <linux/sched/sysctl.h>
#include <linux/slab.h>

#include <asm/uaccess.h>
#include <asm/unistd.h>
#include <asm/div64.h>
#include <asm/timex.h>
#include <asm/io.h>

#define CREATE_TRACE_POINTS
#include <trace/events/timer.h>

/*
 * Called by timer interrupt.
 */
/*
 *  linux/mykernel/myinterrupt.c
 *
 *  Kernel internal my_timer_handler
 *
 *  Copyright (C) 2013  Mengning
 *
 */
#include <linux/types.h>
#include <linux/string.h>
#include <linux/ctype.h>
#include <linux/tty.h>
#include <linux/vmalloc.h>

#include "mypcb.h"

extern tPCB task[MAX_TASK_NUM];
extern tPCB * my_current_task;
extern volatile int my_need_sched;
volatile int time_count = 0;

/*
 * Called by timer interrupt.
 * it runs in the name of current running process,
 * so it use kernel stack of current running process
 */
void my_timer_handler(void)
{
#if 1
    if(time_count%1000 == 0 && my_need_sched != 1)
    {
        printk(KERN_NOTICE ">>>my_timer_handler here<<<\n");
        my_need_sched = 1;
    } 
    time_count ++ ;  
#endif
    return;  	
}

void my_schedule(void)
{
    tPCB * next;
    tPCB * prev;

    if(my_current_task == NULL 
        || my_current_task->next == NULL)
    {
    	return;
    }
    printk(KERN_NOTICE ">>>my_schedule<<<\n");
    /* schedule */
    next = my_current_task->next;
    prev = my_current_task;
    if(next->state == 0)/* -1 unrunnable, 0 runnable, >0 stopped */
    {
    	my_current_task = next; 
    	printk(KERN_NOTICE ">>>switch %d to %d<<<\n",prev->pid,next->pid);
    	/* switch to next process */
    	asm volatile(	
        	"pushl %%ebp\n\t" 	    /* save ebp */
        	"movl %%esp,%0\n\t" 	/* save esp */
        	"movl %2,%%esp\n\t"     /* restore  esp */
        	"movl $1f,%1\n\t"       /* save eip $1f就是指标号1:的代码在内存中存储的地址 */
        	"pushl %3\n\t"          /* restore eip */
        	"ret\n\t" 	            /* restore  eip */
        	"1:\t"                  /* next process start here */
        	"popl %%ebp\n\t"
        	: "=m" (prev->thread.sp),"=m" (prev->thread.ip)
        	: "m" (next->thread.sp),"m" (next->thread.ip)
    	); 
 	
    }
    else
    {
        next->state = 0;
        my_current_task = next;
        printk(KERN_NOTICE ">>>switch %d to %d<<<\n",prev->pid,next->pid);
    	/* switch to new process */
    	asm volatile(	
        	"pushl %%ebp\n\t" 	    /* save the previous's ebp */
        	"movl %%esp,%0\n\t" 	/* save esp */
        	"movl %2,%%esp\n\t"     /* restore  esp */
        	"movl %2,%%ebp\n\t"     /* restore  ebp */
        	"movl $1f,%1\n\t"       /* save eip */	
        	"pushl %3\n\t" 
        	"ret\n\t" 	            /* restore  eip */
        	: "=m" (prev->thread.sp),"=m" (prev->thread.ip)
        	: "m" (next->thread.sp),"m" (next->thread.ip)
    	);          
    }   
    return;	
}