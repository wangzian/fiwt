/*
 * File:   msg_recv.h
 * Author: Zheng GONG(matthewzhenggong@gmail.com)
 *
 * This file is part of FIWT.
 *
 * FIWT is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 3.0 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library.
 */

#ifndef MSG_RECV_H
#define	MSG_RECV_H

#include "XBeeZBS2.h"
#include "task.h"
#include "pt.h"

#ifdef	__cplusplus
extern "C" {
#endif

    typedef struct {
        struct pt PT;
        XBee_p _xbee;
        TaskHandle_p serov_Task;
        TaskHandle_p sen_Task;
        TaskHandle_p ekf_Task;
        TaskHandle_p send_Task;
        unsigned int rx_cnt;
        unsigned int tx_cnt;
        unsigned int cnt;
        XBeeSeries_t xbee_type;
        union {
           ZBRxResponse_t zbrx;
           RxA64Response_t rxa64;
           RxA16Response_t rxa16;
        } rx_rsp;
        union {
           ZBTxRequest_t zbtx;
           TxA16Request_t txa16;
        } tx_req;
    } msgRecvParam_t, *msgRecvParam_p;

    void msgRecvInit(msgRecvParam_p parameters, XBee_p, XBeeSeries_t, TaskHandle_p, TaskHandle_p, TaskHandle_p, TaskHandle_p);

    PT_THREAD(msgRecvLoop)(TaskHandle_p task);

#ifdef	__cplusplus
}
#endif

#endif	/* MSG_RECV_H */

