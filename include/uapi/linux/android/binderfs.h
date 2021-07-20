/* SPDX-License-Identifier: GPL-2.0 WITH Linux-syscall-note */
/*
 * Copyright (C) 2018 Canonical Ltd.
 *
 */

#ifndef _UAPI_LINUX_BINDER_CTL_H
#define _UAPI_LINUX_BINDER_CTL_H

#include <linux/android/binder.h>
#include <linux/types.h>
#include <linux/ioctl.h>

#define BINDERFS_MAX_NAME 255

/**
 * struct binderfs_device - retrieve information about a new binder device
 * @name:   the name to use for the new binderfs binder device
 * @major:  major number allocated for binderfs binder devices
 * @minor:  minor number allocated for the new binderfs binder device
 *
 */
struct binderfs_device {
	char name[BINDERFS_MAX_NAME + 1];
<<<<<<< HEAD
	__u32 major;
	__u32 minor;
=======
	__u8 major;
	__u8 minor;
>>>>>>> 97fd50773c53 (Merge 4.19.198 into android-4.19-stable)
};

/**
 * Allocate a new binder device.
 */
#define BINDER_CTL_ADD _IOWR('b', 1, struct binderfs_device)

#endif /* _UAPI_LINUX_BINDER_CTL_H */

