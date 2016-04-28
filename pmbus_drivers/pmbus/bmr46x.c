/*
 * Hardware monitoring driver for BMR46x
 *
 * Copyright (c) 2016 Ericsson AB.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/err.h>
#include <linux/i2c.h>
#include "pmbus.h"

static int bmr46x_read_word_data(struct i2c_client *client, int page, int reg)
{
    switch (reg) {
    case PMBUS_VOUT_OV_WARN_LIMIT:
    case PMBUS_VOUT_UV_WARN_LIMIT:
    case PMBUS_IOUT_OC_WARN_LIMIT:
    case PMBUS_IOUT_OC_LV_FAULT_LIMIT: /* NotImpl on BMR461 */
        return -ENXIO;
    default:
        if (reg >= PMBUS_VIRT_BASE)
            return -ENXIO;

        break;
    }

    return pmbus_read_word_data(client, page, reg);
}

static int bmr46x_write_word_data(struct i2c_client *client, int page, int reg, u16 word)
{
    switch (reg) {
    case PMBUS_VOUT_OV_WARN_LIMIT:
    case PMBUS_VOUT_UV_WARN_LIMIT:
    case PMBUS_IOUT_OC_WARN_LIMIT:
    case PMBUS_IOUT_OC_LV_FAULT_LIMIT: /* NotImpl on BMR461 */
        return -ENXIO;
    default:
        if (reg >= PMBUS_VIRT_BASE)
            return -ENXIO;

        break;
    }

    return pmbus_write_word_data(client, page, reg, word);
}

static struct pmbus_driver_info bmr46x_info = {
	.pages = 1,
	.func[0] = PMBUS_HAVE_VIN | PMBUS_HAVE_STATUS_INPUT
                 | PMBUS_HAVE_VOUT | PMBUS_HAVE_STATUS_VOUT
                 | PMBUS_HAVE_IOUT | PMBUS_HAVE_STATUS_IOUT
                 | PMBUS_HAVE_TEMP | PMBUS_HAVE_STATUS_TEMP,
	.read_word_data = bmr46x_read_word_data,
	.write_word_data = bmr46x_write_word_data,
};

static int bmr46x_probe(struct i2c_client *client,
			  const struct i2c_device_id *id)
{
	return pmbus_do_probe(client, id, &bmr46x_info);
}

static const struct i2c_device_id bmr46x_id[] = {
	{"bmr46x", 0},
	{}
};

MODULE_DEVICE_TABLE(i2c, bmr46x_id);

/* This is the driver that will be inserted */
static struct i2c_driver bmr46x_driver = {
	.driver = {
		   .name = "bmr46x",
		   },
	.probe = bmr46x_probe,
	.remove = pmbus_do_remove,
	.id_table = bmr46x_id,
};

module_i2c_driver(bmr46x_driver);

MODULE_AUTHOR("marko.silla@ericsson.com");
MODULE_DESCRIPTION("PMBus driver for BMR46x");
MODULE_LICENSE("GPL");
