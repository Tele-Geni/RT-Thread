/*
 * Copyright (c) 2023, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2023-07-06     Supperthomas first version
 * 2023-12-03     Meco Man     support nano version
 */

#include <rtthread.h>
#include <rtdevice.h>
#include <board.h>
#include <ulog.h>

int main(void)
{
    ulog_global_filter_lvl_set(LOG_LVL_DBG);
    return 0;
}
