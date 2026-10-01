#ifndef __ASM_SH_SH7305_BOOT_H
#define __ASM_SH_SH7305_BOOT_H

#define SH7305_BOOT_MAGIC          0x46583937u
#define SH7305_BOOT_VERSION        2

#define FX9750_ROM_VA              0xc0000000UL
#define FX9750_ROM_MAX_SIZE        0x00400000UL

/*
 * Persistent 1 KiB physical-block map.
 *
 * Current kernel:
 *   0x160000 / 0x400 = 1408 entries
 *
 * Two pages provide room for 2048 entries / 2 MiB of P3 ROM.
 */
#define SH7305_BOOT_1KMAP_PHYS     0x08060000UL
#define SH7305_BOOT_1KMAP_P1       0x88060000UL
#define SH7305_BOOT_1KMAP_SIZE     0x00002000UL
#define SH7305_BOOT_1KMAP_MAX      2048u

#define SH7305_BOOT_PGD_PHYS       0x08065000UL
#define SH7305_BOOT_PTE_PHYS       0x08066000UL
#define FX9750_BOOTINFO_PHYS       0x08067000UL

#define SH7305_BOOT_PGD_P1         0x88065000UL
#define SH7305_BOOT_PTE_P1         0x88066000UL
#define FX9750_BOOTINFO_P1         0x88067000UL

#define SH7305_BOOT_RESERVED_SIZE  0x3000UL

struct fx9750_bootinfo {
	unsigned int magic;
	unsigned int version;

	unsigned int rom_va;
	unsigned int rom_size;
	unsigned int rom_pages;
	unsigned int entry_va;

	unsigned int ram_phys;
	unsigned int ram_size;

	unsigned int rom_1k_blocks;
	unsigned int rom_1k_map_p1;

	unsigned int reserved[6];
};

#endif
