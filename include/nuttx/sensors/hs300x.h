/****************************************************************************
 * include/nuttx/sensors/hs300x.h
 *
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.  The
 * ASF licenses this file to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance with the
 * License.  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  See the
 * License for the specific language governing permissions and limitations
 * under the License.
 *
 ****************************************************************************/

#ifndef __INCLUDE_NUTTX_SENSORS_HS300X_H
#define __INCLUDE_NUTTX_SENSORS_HS300X_H

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/config.h>
#include <nuttx/sensors/ioctl.h>

#if defined(CONFIG_I2C) && defined(CONFIG_HS300X_I2C)

/* HS300X Registers frequency and addresses*/

#ifndef CONFIG_HS300X_I2C_FREQUENCY
#  define CONFIG_HS300X_I2C_FREQUENCY 400000
#endif

#ifndef CONFIG_SENSOR_DEVICE_HS300X_I2C_ADDR
#  define CONFIG_SENSOR_DEVICE_HS300X_I2C_ADDR 0x44
#endif


/****************************************************************************
 * Public Types
 ****************************************************************************/

struct i2c_master_s;

/****************************************************************************
 * Public Function Prototypes
 ****************************************************************************/

#ifdef __cplusplus
#define EXTERN extern "C"
extern "C"
{
#else
#define EXTERN extern
#endif

/****************************************************************************
 * Name: hs300x_register
 *
 * Description:
 *   Register the HS300x character device as 'devpath'
 *
 * Input Parameters:
 *   devpath - The full path to the driver to register. E.g., "/dev/i2c1"
 *   i2c - An instance of the I2C interface to use to communicate with HS300X
 *   addr - The I2C address of the HS300x.  The base I2C address of the HS300X
 *   is 0x44. 
 *
 * Returned Value:
 *   Zero (OK) on success; a negated errno value on failure.
 *
 ****************************************************************************/

int hs300x_register(FAR const char *devpath, FAR struct i2c_master_s *i2c,
                  uint8_t addr);

#undef EXTERN
#ifdef __cplusplus
}
#endif

#endif /* CONFIG_I2C && CONFIG_HS300X_I2C */
#endif /* __INCLUDE_NUTTX_SENSORS_HS300X_H */
