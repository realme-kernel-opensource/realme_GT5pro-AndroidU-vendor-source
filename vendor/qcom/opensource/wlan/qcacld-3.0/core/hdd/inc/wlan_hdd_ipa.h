/*
 * Copyright (c) 2013-2019 The Linux Foundation. All rights reserved.
 * Copyright (c) 2022-2023 Qualcomm Innovation Center, Inc. All rights reserved.
 *
 * Permission to use, copy, modify, and/or distribute this software for
 * any purpose with or without fee is hereby granted, provided that the
 * above copyright notice and this permission notice appear in all
 * copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL
 * WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE
 * AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL
 * DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR
 * PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER
 * TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
 * PERFORMANCE OF THIS SOFTWARE.
 */

#ifndef HDD_IPA_H__
#define HDD_IPA_H__

/**
 * DOC: wlan_hdd_ipa.h
 *
 * WLAN IPA interface module headers
 */

#include <qdf_nbuf.h>

#ifdef IPA_OFFLOAD

/**
 * hdd_ipa_send_nbuf_to_network() - Send network buffer to kernel
 * @nbuf: network buffer
 * @dev: network adapter
 *
 * Called when a network buffer is received which should not be routed
 * to the IPA module.
 *
 * Return: None
 */
void hdd_ipa_send_nbuf_to_network(qdf_nbuf_t nbuf, qdf_netdev_t dev);

/**
 * hdd_ipa_set_mcc_mode() - To set mcc mode if IPA is enabled
 * @mcc_mode: mcc mode
 *
 * This routine is called to set mcc mode if IPA is enabled
 *
 * Return: None
 */
void hdd_ipa_set_mcc_mode(bool mcc_mode);

/**
 * hdd_ipa_get_tx_pipe() - Get tx pipe for the new connection
 * @hdd_ctx: pointer to hdd_context
 * @link: pointer to struct wlan_hdd_link_info
 * @tx_pipe: boolean output param to store which pipe to use for @link.
 *	     false is the primary tx pipe and true is the alternate tx pipe.
 *
 * Return: QDF_STATUS_SUCCESS for success, and otherwise for failure scenarios.
 *
 */
QDF_STATUS hdd_ipa_get_tx_pipe(struct hdd_context *hdd_ctx,
			       struct wlan_hdd_link_info *link,
			       bool *tx_pipe);

#else
static inline
void hdd_ipa_send_nbuf_to_network(qdf_nbuf_t skb, qdf_netdev_t dev)
{
}

static inline void hdd_ipa_set_mcc_mode(bool mcc_mode)
{
}

static inline QDF_STATUS
hdd_ipa_get_tx_pipe(struct hdd_context *hdd_ctx,
		    struct wlan_hdd_link_info *link,
		    bool *tx_pipe)
{
	return QDF_STATUS_SUCCESS;
}
#endif
#endif /* HDD_IPA_H__ */
