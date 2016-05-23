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
	{ 0x7134e791, __VMLINUX_SYMBOL_STR(i2c_del_driver) },
	{ 0x8939e0e5, __VMLINUX_SYMBOL_STR(i2c_register_driver) },
	{ 0x5d59d800, __VMLINUX_SYMBOL_STR(of_get_property) },
	{ 0x3424f1d5, __VMLINUX_SYMBOL_STR(put_device) },
	{ 0x3ef0cbee, __VMLINUX_SYMBOL_STR(devm_spi_register_master) },
	{ 0xd3ba825e, __VMLINUX_SYMBOL_STR(spi_alloc_master) },
	{ 0xfa2a45e, __VMLINUX_SYMBOL_STR(__memzero) },
	{ 0x92a9b6eb, __VMLINUX_SYMBOL_STR(i2c_master_send) },
	{ 0x9d669763, __VMLINUX_SYMBOL_STR(memcpy) },
	{ 0x134bc462, __VMLINUX_SYMBOL_STR(i2c_smbus_write_byte_data) },
	{ 0xb62b7490, __VMLINUX_SYMBOL_STR(spi_finalize_current_message) },
	{ 0x8e865d3c, __VMLINUX_SYMBOL_STR(arm_delay_ops) },
	{ 0x12a38747, __VMLINUX_SYMBOL_STR(usleep_range) },
	{ 0xf71a0746, __VMLINUX_SYMBOL_STR(i2c_master_recv) },
	{ 0xe707d823, __VMLINUX_SYMBOL_STR(__aeabi_uidiv) },
	{ 0x91715312, __VMLINUX_SYMBOL_STR(sprintf) },
	{ 0xdad6c911, __VMLINUX_SYMBOL_STR(spi_new_device) },
	{ 0x20c55ae0, __VMLINUX_SYMBOL_STR(sscanf) },
	{ 0x28ca1037, __VMLINUX_SYMBOL_STR(kmem_cache_alloc_trace) },
	{ 0x4479bcd2, __VMLINUX_SYMBOL_STR(kmalloc_caches) },
	{ 0x27e1a049, __VMLINUX_SYMBOL_STR(printk) },
	{ 0x2e5810c6, __VMLINUX_SYMBOL_STR(__aeabi_unwind_cpp_pr1) },
	{ 0xb1ad28e0, __VMLINUX_SYMBOL_STR(__gnu_mcount_nc) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";

MODULE_ALIAS("i2c:sc18is602");
MODULE_ALIAS("i2c:sc18is602b");
MODULE_ALIAS("i2c:sc18is603");

MODULE_INFO(srcversion, "2CCA6D838A8EB1F5BDFE2CA");
