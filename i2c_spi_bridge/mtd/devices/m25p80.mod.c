#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);

__visible struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0x4f2bf3fd, __VMLINUX_SYMBOL_STR(module_layout) },
	{ 0xaf90711f, __VMLINUX_SYMBOL_STR(driver_unregister) },
	{ 0x793f6270, __VMLINUX_SYMBOL_STR(spi_register_driver) },
	{ 0xe2d5255a, __VMLINUX_SYMBOL_STR(strcmp) },
	{ 0x510756ca, __VMLINUX_SYMBOL_STR(mtd_device_parse_register) },
	{ 0x425a4a45, __VMLINUX_SYMBOL_STR(spi_nor_scan) },
	{ 0x62d6b7f1, __VMLINUX_SYMBOL_STR(devm_kmalloc) },
	{ 0x9d669763, __VMLINUX_SYMBOL_STR(memcpy) },
	{ 0x6a379bd5, __VMLINUX_SYMBOL_STR(spi_sync) },
	{ 0xfa2a45e, __VMLINUX_SYMBOL_STR(__memzero) },
	{ 0x5f754e5a, __VMLINUX_SYMBOL_STR(memset) },
	{ 0xff81a565, __VMLINUX_SYMBOL_STR(dev_err) },
	{ 0x1c9eecbc, __VMLINUX_SYMBOL_STR(spi_write_then_read) },
	{ 0xfbf7d661, __VMLINUX_SYMBOL_STR(mtd_device_unregister) },
	{ 0x2e5810c6, __VMLINUX_SYMBOL_STR(__aeabi_unwind_cpp_pr1) },
	{ 0xb1ad28e0, __VMLINUX_SYMBOL_STR(__gnu_mcount_nc) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=mtd,spi-nor";

MODULE_ALIAS("spi:at25fs010");
MODULE_ALIAS("spi:at25fs040");
MODULE_ALIAS("spi:at25df041a");
MODULE_ALIAS("spi:at25df321a");
MODULE_ALIAS("spi:at25df641");
MODULE_ALIAS("spi:at26f004");
MODULE_ALIAS("spi:at26df081a");
MODULE_ALIAS("spi:at26df161a");
MODULE_ALIAS("spi:at26df321");
MODULE_ALIAS("spi:at45db081d");
MODULE_ALIAS("spi:en25f32");
MODULE_ALIAS("spi:en25p32");
MODULE_ALIAS("spi:en25q32b");
MODULE_ALIAS("spi:en25p64");
MODULE_ALIAS("spi:en25q64");
MODULE_ALIAS("spi:en25qh128");
MODULE_ALIAS("spi:en25qh256");
MODULE_ALIAS("spi:f25l32pa");
MODULE_ALIAS("spi:mr25h256");
MODULE_ALIAS("spi:mr25h10");
MODULE_ALIAS("spi:gd25q32");
MODULE_ALIAS("spi:gd25q64");
MODULE_ALIAS("spi:160s33b");
MODULE_ALIAS("spi:320s33b");
MODULE_ALIAS("spi:640s33b");
MODULE_ALIAS("spi:mx25l2005a");
MODULE_ALIAS("spi:mx25l4005a");
MODULE_ALIAS("spi:mx25l8005");
MODULE_ALIAS("spi:mx25l1606e");
MODULE_ALIAS("spi:mx25l3205d");
MODULE_ALIAS("spi:mx25l3255e");
MODULE_ALIAS("spi:mx25l6405d");
MODULE_ALIAS("spi:mx25l12805d");
MODULE_ALIAS("spi:mx25l12855e");
MODULE_ALIAS("spi:mx25l25635e");
MODULE_ALIAS("spi:mx25l25655e");
MODULE_ALIAS("spi:mx66l51235l");
MODULE_ALIAS("spi:mx66l1g55g");
MODULE_ALIAS("spi:n25q064");
MODULE_ALIAS("spi:n25q128a11");
MODULE_ALIAS("spi:n25q128a13");
MODULE_ALIAS("spi:n25q256a");
MODULE_ALIAS("spi:n25q512a");
MODULE_ALIAS("spi:n25q512ax3");
MODULE_ALIAS("spi:n25q00");
MODULE_ALIAS("spi:pm25lv512");
MODULE_ALIAS("spi:pm25lv010");
MODULE_ALIAS("spi:pm25lq032");
MODULE_ALIAS("spi:s25sl032p");
MODULE_ALIAS("spi:s25sl064p");
MODULE_ALIAS("spi:s25fl256s0");
MODULE_ALIAS("spi:s25fl256s1");
MODULE_ALIAS("spi:s25fl512s");
MODULE_ALIAS("spi:s70fl01gs");
MODULE_ALIAS("spi:s25sl12800");
MODULE_ALIAS("spi:s25sl12801");
MODULE_ALIAS("spi:s25fl129p0");
MODULE_ALIAS("spi:s25fl129p1");
MODULE_ALIAS("spi:s25sl004a");
MODULE_ALIAS("spi:s25sl008a");
MODULE_ALIAS("spi:s25sl016a");
MODULE_ALIAS("spi:s25sl032a");
MODULE_ALIAS("spi:s25sl064a");
MODULE_ALIAS("spi:s25fl008k");
MODULE_ALIAS("spi:s25fl016k");
MODULE_ALIAS("spi:s25fl064k");
MODULE_ALIAS("spi:s25fl132k");
MODULE_ALIAS("spi:sst25vf040b");
MODULE_ALIAS("spi:sst25vf080b");
MODULE_ALIAS("spi:sst25vf016b");
MODULE_ALIAS("spi:sst25vf032b");
MODULE_ALIAS("spi:sst25vf064c");
MODULE_ALIAS("spi:sst25wf512");
MODULE_ALIAS("spi:sst25wf010");
MODULE_ALIAS("spi:sst25wf020");
MODULE_ALIAS("spi:sst25wf040");
MODULE_ALIAS("spi:m25p05");
MODULE_ALIAS("spi:m25p10");
MODULE_ALIAS("spi:m25p20");
MODULE_ALIAS("spi:m25p40");
MODULE_ALIAS("spi:m25p80");
MODULE_ALIAS("spi:m25p16");
MODULE_ALIAS("spi:m25p32");
MODULE_ALIAS("spi:m25p64");
MODULE_ALIAS("spi:m25p128");
MODULE_ALIAS("spi:n25q032");
MODULE_ALIAS("spi:m25p05-nonjedec");
MODULE_ALIAS("spi:m25p10-nonjedec");
MODULE_ALIAS("spi:m25p20-nonjedec");
MODULE_ALIAS("spi:m25p40-nonjedec");
MODULE_ALIAS("spi:m25p80-nonjedec");
MODULE_ALIAS("spi:m25p16-nonjedec");
MODULE_ALIAS("spi:m25p32-nonjedec");
MODULE_ALIAS("spi:m25p64-nonjedec");
MODULE_ALIAS("spi:m25p128-nonjedec");
MODULE_ALIAS("spi:m45pe10");
MODULE_ALIAS("spi:m45pe80");
MODULE_ALIAS("spi:m45pe16");
MODULE_ALIAS("spi:m25pe20");
MODULE_ALIAS("spi:m25pe80");
MODULE_ALIAS("spi:m25pe16");
MODULE_ALIAS("spi:m25px16");
MODULE_ALIAS("spi:m25px32");
MODULE_ALIAS("spi:m25px32-s0");
MODULE_ALIAS("spi:m25px32-s1");
MODULE_ALIAS("spi:m25px64");
MODULE_ALIAS("spi:m25px80");
MODULE_ALIAS("spi:w25x10");
MODULE_ALIAS("spi:w25x20");
MODULE_ALIAS("spi:w25x40");
MODULE_ALIAS("spi:w25x80");
MODULE_ALIAS("spi:w25x16");
MODULE_ALIAS("spi:w25x32");
MODULE_ALIAS("spi:w25q32");
MODULE_ALIAS("spi:w25q32dw");
MODULE_ALIAS("spi:w25x64");
MODULE_ALIAS("spi:w25q64");
MODULE_ALIAS("spi:w25q80");
MODULE_ALIAS("spi:w25q80bl");
MODULE_ALIAS("spi:w25q128");
MODULE_ALIAS("spi:w25q256");
MODULE_ALIAS("spi:cat25c11");
MODULE_ALIAS("spi:cat25c03");
MODULE_ALIAS("spi:cat25c09");
MODULE_ALIAS("spi:cat25c17");
MODULE_ALIAS("spi:cat25128");
MODULE_ALIAS("spi:spi-nor");

MODULE_INFO(srcversion, "F64F2C522B0D1583D142225");
