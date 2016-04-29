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
	{ 0xb2c8749b, __VMLINUX_SYMBOL_STR(param_ops_ulong) },
	{ 0x9628707b, __VMLINUX_SYMBOL_STR(pmbus_do_remove) },
	{ 0x7134e791, __VMLINUX_SYMBOL_STR(i2c_del_driver) },
	{ 0x8939e0e5, __VMLINUX_SYMBOL_STR(i2c_register_driver) },
	{ 0x22d1dd79, __VMLINUX_SYMBOL_STR(pmbus_read_word_data) },
	{ 0xf8bfa097, __VMLINUX_SYMBOL_STR(pmbus_write_word_data) },
	{ 0xfa3e9bdd, __VMLINUX_SYMBOL_STR(pmbus_clear_cache) },
	{ 0x27652715, __VMLINUX_SYMBOL_STR(pmbus_read_byte_data) },
	{ 0xdfc4cdc7, __VMLINUX_SYMBOL_STR(pmbus_write_byte) },
	{ 0xe67d0659, __VMLINUX_SYMBOL_STR(pmbus_get_driver_info) },
	{ 0x2e5810c6, __VMLINUX_SYMBOL_STR(__aeabi_unwind_cpp_pr1) },
	{ 0x8e865d3c, __VMLINUX_SYMBOL_STR(arm_delay_ops) },
	{ 0xff81a565, __VMLINUX_SYMBOL_STR(dev_err) },
	{ 0xf44776d5, __VMLINUX_SYMBOL_STR(pmbus_do_probe) },
	{ 0x46282404, __VMLINUX_SYMBOL_STR(i2c_smbus_read_word_data) },
	{ 0xc87c1f84, __VMLINUX_SYMBOL_STR(ktime_get) },
	{ 0x62d6b7f1, __VMLINUX_SYMBOL_STR(devm_kmalloc) },
	{ 0xe2a2b1e1, __VMLINUX_SYMBOL_STR(dev_notice) },
	{ 0x2aa0e4fc, __VMLINUX_SYMBOL_STR(strncasecmp) },
	{ 0x97255bdf, __VMLINUX_SYMBOL_STR(strlen) },
	{ 0x8ca160d, __VMLINUX_SYMBOL_STR(_dev_info) },
	{ 0xd9711b11, __VMLINUX_SYMBOL_STR(i2c_smbus_read_block_data) },
	{ 0xb1ad28e0, __VMLINUX_SYMBOL_STR(__gnu_mcount_nc) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=pmbus_core";

MODULE_ALIAS("i2c:bmr450");
MODULE_ALIAS("i2c:bmr451");
MODULE_ALIAS("i2c:bmr462");
MODULE_ALIAS("i2c:bmr463");
MODULE_ALIAS("i2c:bmr464");
MODULE_ALIAS("i2c:zl2004");
MODULE_ALIAS("i2c:zl2005");
MODULE_ALIAS("i2c:zl2006");
MODULE_ALIAS("i2c:zl2008");
MODULE_ALIAS("i2c:zl2105");
MODULE_ALIAS("i2c:zl2106");
MODULE_ALIAS("i2c:zl6100");
MODULE_ALIAS("i2c:zl6105");
MODULE_ALIAS("i2c:zl9101");
MODULE_ALIAS("i2c:zl9117");

MODULE_INFO(srcversion, "51AC736AFF2E737D16128E0");
