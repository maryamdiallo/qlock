# QLock Implementation in xv6

## Overview
This project implements a QLock in the xv6 operating system. QLock controls access to shared resources using a spinlock and sleep/wakeup functions.

## Files
- `kernel/qlock.h` – Defines the QLock structure.
- `kernel/qlock.c` – Implements the QLock functions.
- `kernel/proc.c` – Contains the QLock test.
- `kernel/defs.h` – Declares the test function.
- `kernel/main.c` – Runs the test during startup.
- `Makefile` – Includes QLock in the kernel build.

## Testing
The QLock was tested using xv6-riscv and QEMU.

**Test Output:**
```
QLock Test Started
QLock acquired
Shared resources: 1
QLock released
QLock Test Completed
```

The test successfully initialized, acquired, and released the lock while updating a shared variable.

