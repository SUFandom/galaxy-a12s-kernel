# SPDX-License-Identifier: GPL-2.0
<<<<<<< HEAD
obj-$(CONFIG_ION) +=	ion.o ion-ioctl.o ion_heap.o
obj-$(CONFIG_ION_SYSTEM_HEAP) += ion_system_heap.o ion_page_pool.o
obj-$(CONFIG_ION_CARVEOUT_HEAP) += ion_carveout_heap.o
obj-$(CONFIG_ION_CHUNK_HEAP) += ion_chunk_heap.o
obj-$(CONFIG_ION_CMA_HEAP) += ion_cma_heap.o
obj-$(CONFIG_ION_HPA_HEAP) += ion_hpa_heap.o
obj-$(CONFIG_ION_TEST) += ion_test.o
obj-$(CONFIG_ION_EXYNOS) += ion_fdt_exynos.o ion_buffer_protect.o ion_exynos.o
obj-$(CONFIG_ION_EXYNOS) += ion_debug.o
=======
obj-$(CONFIG_ION) +=	ion-alloc.o
CFLAGS_ion.o = -I$(src)
ion-alloc-objs += ion.o ion-ioctl.o ion_heap.o
ion-alloc-$(CONFIG_ION_SYSTEM_HEAP) += ion_system_heap.o ion_page_pool.o
ion-alloc-$(CONFIG_ION_CARVEOUT_HEAP) += ion_carveout_heap.o
ion-alloc-$(CONFIG_ION_CHUNK_HEAP) += ion_chunk_heap.o
ion-alloc-$(CONFIG_ION_CMA_HEAP) += ion_cma_heap.o
>>>>>>> 97fd50773c53 (Merge 4.19.198 into android-4.19-stable)
