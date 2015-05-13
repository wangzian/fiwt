#!/bin/env python
# -*- coding: utf-8 -*-
"""
Util functions
----------------------------------------

Author: Zheng GONG(matthewzhenggong@gmail.com)

This file is part of FIWT.

FIWT is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 3.0 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library.
"""

import sys
import time

is_windows = sys.platform.startswith('win')

if is_windows:

    def getMicroseconds():
        return int(time.clock() * 1e6)

    def getBindHost(host):
        return (host,host)
else:
    import netaddr

    def getMicroseconds():
        return int(time.time() * 1e6)

    def getBindHost(host):
        net = netaddr.IPNetwork(host+'/24')
        return (str(net.network), str(net.broadcast))

