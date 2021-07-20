/* SPDX-License-Identifier: GPL-2.0 */
/*
 * Common values for the Poly1305 algorithm
 */

#ifndef _CRYPTO_POLY1305_H
#define _CRYPTO_POLY1305_H

#include <linux/types.h>
#include <linux/crypto.h>

#define POLY1305_BLOCK_SIZE	16
#define POLY1305_KEY_SIZE	32
#define POLY1305_DIGEST_SIZE	16

<<<<<<< HEAD
struct poly1305_key {
	u32 r[5];	/* key, base 2^26 */
};

struct poly1305_state {
	u32 h[5];	/* accumulator, base 2^26 */
};

struct poly1305_desc_ctx {
	/* key */
	struct poly1305_key r;
	/* finalize key */
	u32 s[4];
	/* accumulator */
	struct poly1305_state h;
=======
/* The poly1305_key and poly1305_state types are mostly opaque and
 * implementation-defined. Limbs might be in base 2^64 or base 2^26, or
 * different yet. The union type provided keeps these 64-bit aligned for the
 * case in which this is implemented using 64x64 multiplies.
 */

struct poly1305_key {
	union {
		u32 r[5];
		u64 r64[3];
	};
};

struct poly1305_core_key {
	struct poly1305_key key;
	struct poly1305_key precomputed_s;
};

struct poly1305_state {
	union {
		u32 h[5];
		u64 h64[3];
	};
};

struct poly1305_desc_ctx {
>>>>>>> 97fd50773c53 (Merge 4.19.198 into android-4.19-stable)
	/* partial buffer */
	u8 buf[POLY1305_BLOCK_SIZE];
	/* bytes used in partial buffer */
	unsigned int buflen;
	/* how many keys have been set in r[] */
	unsigned short rset;
	/* whether s[] has been set */
	bool sset;
	/* finalize key */
	u32 s[4];
	/* accumulator */
	struct poly1305_state h;
	/* key */
	union {
		struct poly1305_key opaque_r[CONFIG_CRYPTO_LIB_POLY1305_RSIZE];
		struct poly1305_core_key core_r;
	};
};

<<<<<<< HEAD
/*
 * Poly1305 core functions.  These implement the ε-almost-∆-universal hash
 * function underlying the Poly1305 MAC, i.e. they don't add an encrypted nonce
 * ("s key") at the end.  They also only support block-aligned inputs.
 */
void poly1305_core_setkey(struct poly1305_key *key, const u8 *raw_key);
static inline void poly1305_core_init(struct poly1305_state *state)
{
	memset(state->h, 0, sizeof(state->h));
}
void poly1305_core_blocks(struct poly1305_state *state,
			  const struct poly1305_key *key,
			  const void *src, unsigned int nblocks);
void poly1305_core_emit(const struct poly1305_state *state, void *dst);

/* Crypto API helper functions for the Poly1305 MAC */
int crypto_poly1305_init(struct shash_desc *desc);
unsigned int crypto_poly1305_setdesckey(struct poly1305_desc_ctx *dctx,
					const u8 *src, unsigned int srclen);
int crypto_poly1305_update(struct shash_desc *desc,
			   const u8 *src, unsigned int srclen);
int crypto_poly1305_final(struct shash_desc *desc, u8 *dst);
=======
void poly1305_init_arch(struct poly1305_desc_ctx *desc, const u8 *key);
void poly1305_init_generic(struct poly1305_desc_ctx *desc, const u8 *key);

static inline void poly1305_init(struct poly1305_desc_ctx *desc, const u8 *key)
{
	if (IS_ENABLED(CONFIG_CRYPTO_ARCH_HAVE_LIB_POLY1305))
		poly1305_init_arch(desc, key);
	else
		poly1305_init_generic(desc, key);
}

void poly1305_update_arch(struct poly1305_desc_ctx *desc, const u8 *src,
			  unsigned int nbytes);
void poly1305_update_generic(struct poly1305_desc_ctx *desc, const u8 *src,
			     unsigned int nbytes);

static inline void poly1305_update(struct poly1305_desc_ctx *desc,
				   const u8 *src, unsigned int nbytes)
{
	if (IS_ENABLED(CONFIG_CRYPTO_ARCH_HAVE_LIB_POLY1305))
		poly1305_update_arch(desc, src, nbytes);
	else
		poly1305_update_generic(desc, src, nbytes);
}

void poly1305_final_arch(struct poly1305_desc_ctx *desc, u8 *digest);
void poly1305_final_generic(struct poly1305_desc_ctx *desc, u8 *digest);

static inline void poly1305_final(struct poly1305_desc_ctx *desc, u8 *digest)
{
	if (IS_ENABLED(CONFIG_CRYPTO_ARCH_HAVE_LIB_POLY1305))
		poly1305_final_arch(desc, digest);
	else
		poly1305_final_generic(desc, digest);
}
>>>>>>> 97fd50773c53 (Merge 4.19.198 into android-4.19-stable)

#endif
