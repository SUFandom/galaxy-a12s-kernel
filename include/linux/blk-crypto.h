/* SPDX-License-Identifier: GPL-2.0 */
/*
 * Copyright 2019 Google LLC
 */

#ifndef __LINUX_BLK_CRYPTO_H
#define __LINUX_BLK_CRYPTO_H

#include <linux/bio.h>

#ifdef CONFIG_BLK_INLINE_ENCRYPTION

int blk_crypto_submit_bio(struct bio **bio_ptr);

bool blk_crypto_endio(struct bio *bio);

int blk_crypto_init_key(struct blk_crypto_key *blk_key,
			const u8 *raw_key, unsigned int raw_key_size,
			bool is_hw_wrapped,
			enum blk_crypto_mode_num crypto_mode,
<<<<<<< HEAD
			unsigned int data_unit_size);

=======
			unsigned int dun_bytes,
			unsigned int data_unit_size);

int blk_crypto_start_using_mode(enum blk_crypto_mode_num crypto_mode,
				unsigned int dun_bytes,
				unsigned int data_unit_size,
				bool is_hw_wrapped_key,
				struct request_queue *q);

>>>>>>> 97fd50773c53 (Merge 4.19.198 into android-4.19-stable)
int blk_crypto_evict_key(struct request_queue *q,
			 const struct blk_crypto_key *key);

#else /* CONFIG_BLK_INLINE_ENCRYPTION */

static inline int blk_crypto_submit_bio(struct bio **bio_ptr)
{
	return 0;
}

static inline bool blk_crypto_endio(struct bio *bio)
{
	return true;
}

#endif /* CONFIG_BLK_INLINE_ENCRYPTION */

#ifdef CONFIG_BLK_INLINE_ENCRYPTION_FALLBACK

<<<<<<< HEAD
int blk_crypto_start_using_mode(enum blk_crypto_mode_num mode_num,
				unsigned int data_unit_size,
				struct request_queue *q);

=======
>>>>>>> 97fd50773c53 (Merge 4.19.198 into android-4.19-stable)
int blk_crypto_fallback_init(void);

#else /* CONFIG_BLK_INLINE_ENCRYPTION_FALLBACK */

<<<<<<< HEAD
static inline int
blk_crypto_start_using_mode(enum blk_crypto_mode_num mode_num,
			    unsigned int data_unit_size,
			    struct request_queue *q)
{
	return 0;
}

=======
>>>>>>> 97fd50773c53 (Merge 4.19.198 into android-4.19-stable)
static inline int blk_crypto_fallback_init(void)
{
	return 0;
}

#endif /* CONFIG_BLK_INLINE_ENCRYPTION_FALLBACK */

#endif /* __LINUX_BLK_CRYPTO_H */
