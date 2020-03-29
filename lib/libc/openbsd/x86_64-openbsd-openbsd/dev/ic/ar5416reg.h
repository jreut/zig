/*	$OpenBSD: ar5416reg.h,v 1.7 2019/02/01 16:15:07 stsp Exp $	*/

/*-
 * Copyright (c) 2009 Damien Bergamini <damien.bergamini@free.fr>
 * Copyright (c) 2008-2009 Atheros Communications Inc.
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#define AR5416_MAX_CHAINS	3

#define AR5416_PHY_CCA_MIN_GOOD_VAL_2GHZ	(-100)
#define AR5416_PHY_CCA_MIN_GOOD_VAL_5GHZ	(-110)
#define AR5416_PHY_CCA_MAX_GOOD_VAL_2GHZ	(-80)
#define AR5416_PHY_CCA_MAX_GOOD_VAL_5GHZ	(-90)

/*
 * ROM layout used by AR5416, AR9160 and AR9280.
 */
#define AR5416_EEP_START_LOC		256
#define AR5416_NUM_5G_CAL_PIERS		8
#define AR5416_NUM_2G_CAL_PIERS		4
#define AR5416_NUM_5G_20_TARGET_POWERS	8
#define AR5416_NUM_5G_40_TARGET_POWERS	8
#define AR5416_NUM_2G_CCK_TARGET_POWERS	3
#define AR5416_NUM_2G_20_TARGET_POWERS	4
#define AR5416_NUM_2G_40_TARGET_POWERS	4
#define AR5416_NUM_CTLS			24
#define AR5416_NUM_BAND_EDGES		8
#define AR5416_NUM_PD_GAINS		4
#define AR5416_PD_GAINS_IN_MASK		4
#define AR5416_PD_GAIN_ICEPTS		5

struct ar5416_base_eep_header {
	uint16_t	length;
	uint16_t	checksum;
	uint16_t	version;
	uint8_t		opCapFlags;
	uint8_t		eepMisc;
	uint16_t	regDmn[2];
	uint8_t		macAddr[6];
	uint8_t		rxMask;
	uint8_t		txMask;
	uint16_t	rfSilent;
	uint16_t	blueToothOptions;
	uint16_t	deviceCap;
	uint32_t	binBuildNumber;
	uint8_t		deviceType;
	/* End of common header. */
	uint8_t		pwdclkind;
	uint8_t		fastClk5g;
	uint8_t		divChain;
	uint8_t		rxGainType;
#define AR5416_EEP_RXGAIN_23DB_BACKOFF	0
#define AR5416_EEP_RXGAIN_13DB_BACKOFF	1
#define AR5416_EEP_RXGAIN_ORIG		2

	uint8_t		dacHiPwrMode_5G;
	uint8_t		openLoopPwrCntl;
	uint8_t		dacLpMode;
	uint8_t		txGainType;
	uint8_t		rcChainMask;
	uint8_t		desiredScaleCCK;
	uint8_t		pwrTableOffset;
	uint8_t		frac_n_5g;
	uint8_t		futureBase[21];
} __packed;

struct ar5416_modal_eep_header {
	uint32_t	antCtrlChain[AR5416_MAX_CHAINS];
	uint32_t	antCtrlCommon;
	uint8_t		antennaGainCh[AR5416_MAX_CHAINS];
	uint8_t		switchSettling;
	uint8_t		txRxAttenCh[AR5416_MAX_CHAINS];
	uint8_t		rxTxMarginCh[AR5416_MAX_CHAINS];
	uint8_t		adcDesiredSize;
	uint8_t		pgaDesiredSize;
	uint8_t		xlnaGainCh[AR5416_MAX_CHAINS];
	uint8_t		txEndToXpaOff;
	uint8_t		txEndToRxOn;
	uint8_t		txFrameToXpaOn;
	uint8_t		thresh62;
	uint8_t		noiseFloorThreshCh[AR5416_MAX_CHAINS];
	uint8_t		xpdGain;
	uint8_t		xpd;
	uint8_t		iqCalICh[AR5416_MAX_CHAINS];
	uint8_t		iqCalQCh[AR5416_MAX_CHAINS];
	uint8_t		pdGainOverlap;
	uint8_t		ob;
	uint8_t		db;
	uint8_t		xpaBiasLvl;
	uint8_t		pwrDecreaseFor2Chain;
	uint8_t		pwrDecreaseFor3Chain;
	uint8_t		txFrameToDataStart;
	uint8_t		txFrameToPaOn;
	uint8_t		ht40PowerIncForPdadc;
	uint8_t		bswAtten[AR5416_MAX_CHAINS];
	uint8_t		bswMargin[AR5416_MAX_CHAINS];
	uint8_t		swSettleHt40;
	uint8_t		xatten2Db[AR5416_MAX_CHAINS];
	uint8_t		xatten2Margin[AR5416_MAX_CHAINS];
	uint8_t		ob_ch1;
	uint8_t		db_ch1;
	uint8_t		flagBits;
#define AR5416_EEP_FLAG_USEANT1		0x01
#define AR5416_EEP_FLAG_FORCEXPAON	0x02
#define AR5416_EEP_FLAG_LOCALBIAS	0x04
#define AR5416_EEP_FLAG_FEMBANDSELECT	0x08
#define AR5416_EEP_FLAG_XLNABUFIN	0x10
#define AR5416_EEP_FLAG_XLNAISEL_M	0x60
#define AR5416_EEP_FLAG_XLNAISEL_S	5
#define AR5416_EEP_FLAG_XLNABUFMODE	0x80

	uint8_t		miscBits;
#define AR5416_EEP_MISC_TX_DAC_SCALE_CCK_M	0x03
#define AR5416_EEP_MISC_TX_DAC_SCALE_CCK_S	0
#define AR5416_EEP_MISC_TX_CLIP_M		0xfc
#define AR5416_EEP_MISC_TX_CLIP_S		2

	uint16_t	xpaBiasLvlFreq[3];
	uint8_t		futureModal[6];
	struct		ar_spur_chan spurChans[AR_EEPROM_MODAL_SPURS];
} __packed;

struct ar5416_cal_data_per_freq {
	uint8_t	pwrPdg[AR5416_NUM_PD_GAINS][AR5416_PD_GAIN_ICEPTS];
	uint8_t	vpdPdg[AR5416_NUM_PD_GAINS][AR5416_PD_GAIN_ICEPTS];
} __packed;

struct ar5416_cal_ctl_data {
	struct ar_cal_ctl_edges
	    ctlEdges[AR5416_MAX_CHAINS][AR5416_NUM_BAND_EDGES];
} __packed;

struct ar5416_eeprom {
	struct	ar5416_base_eep_header baseEepHeader;
	uint8_t custData[64];
	struct	ar5416_modal_eep_header modalHeader[2];
	uint8_t calFreqPier5G[AR5416_NUM_5G_CAL_PIERS];
	uint8_t calFreqPier2G[AR5416_NUM_2G_CAL_PIERS];
	struct	ar5416_cal_data_per_freq
	    calPierData5G[AR5416_MAX_CHAINS][AR5416_NUM_5G_CAL_PIERS];
	struct	ar5416_cal_data_per_freq
	    calPierData2G[AR5416_MAX_CHAINS][AR5416_NUM_2G_CAL_PIERS];
	struct	ar_cal_target_power_leg
	    calTargetPower5G[AR5416_NUM_5G_20_TARGET_POWERS];
	struct	ar_cal_target_power_ht
	    calTargetPower5GHT20[AR5416_NUM_5G_20_TARGET_POWERS];
	struct	ar_cal_target_power_ht
	    calTargetPower5GHT40[AR5416_NUM_5G_40_TARGET_POWERS];
	struct	ar_cal_target_power_leg
	    calTargetPowerCck[AR5416_NUM_2G_CCK_TARGET_POWERS];
	struct	ar_cal_target_power_leg
	    calTargetPower2G[AR5416_NUM_2G_20_TARGET_POWERS];
	struct	ar_cal_target_power_ht
	    calTargetPower2GHT20[AR5416_NUM_2G_20_TARGET_POWERS];
	struct	ar_cal_target_power_ht
	    calTargetPower2GHT40[AR5416_NUM_2G_40_TARGET_POWERS];
	uint8_t	ctlIndex[AR5416_NUM_CTLS];
	struct	ar5416_cal_ctl_data ctlData[AR5416_NUM_CTLS];
	uint8_t padding;
} __packed;

/* Macro to "pack" registers to 16-bit to save some .rodata space. */
#define P(x)	(x)

/*
 * AR5416 initialization values.
 */
static const uint16_t ar5416_regs[] = {
	P(0x01030), P(0x01070), P(0x010b0), P(0x010f0), P(0x08014),
	P(0x0801c), P(0x08120), P(0x081d0), P(0x09804), P(0x09820),
	P(0x09824), P(0x09828), P(0x09834), P(0x09838), P(0x09844),
	P(0x09848), P(0x0a848), P(0x0b848), P(0x09850), P(0x09858),
	P(0x0985c), P(0x09860), P(0x09864), P(0x09868), P(0x0986c),
	P(0x09914), P(0x09918), P(0x09924), P(0x09944), P(0x09960),
	P(0x0a960), P(0x0b960), P(0x09964), P(0x099bc), P(0x099c0),
	P(0x099c4), P(0x099c8), P(0x099cc), P(0x099d0), P(0x099d4),
	P(0x099d8), P(0x0a204), P(0x0a208), P(0x0a20c), P(0x0b20c),
	P(0x0c20c), P(0x0a21c), P(0x0a230), P(0x0a274), P(0x0a300),
	P(0x0a304), P(0x0a308), P(0x0a30c), P(0x0a310), P(0x0a314),
	P(0x0a318), P(0x0a31c), P(0x0a320), P(0x0a324), P(0x0a328),
	P(0x0a32c), P(0x0a330), P(0x0a334)
};

static const uint32_t ar5416_vals_5g20[] = {
	0x00000230, 0x00000168, 0x00000e60, 0x0000a000, 0x03e803e8,
	0x128d93a7, 0x08f04800, 0x00003210, 0x00000300, 0x02020200,
	0x00000e0e, 0x0a020001, 0x00000e0e, 0x00000007, 0x1372161e,
	0x001a6a65, 0x001a6a65, 0x001a6a65, 0x6c48b4e0, 0x7ec82d2e,
	0x31395d5e, 0x00049d18, 0x0001ce00, 0x409a4190, 0x050cb081,
	0x000007d0, 0x000001b8, 0xd0058a0b, 0xffb81020, 0x00000900,
	0x00000900, 0x00000900, 0x00000000, 0x001a0a00, 0x038919be,
	0x06336f77, 0x6af6532c, 0x08f186c8, 0x00046384, 0x00000000,
	0x00000000, 0x00000880, 0xd6be4788, 0x002ec1e0, 0x002ec1e0,
	0x002ec1e0, 0x1883800a, 0x00000000, 0x0a1a9caa, 0x18010000,
	0x30032602, 0x48073e06, 0x560b4c0a, 0x641a600f, 0x7a4f6e1b,
	0x8c5b7e5a, 0x9d0f96cf, 0xb51fa69f, 0xcb3fbd07, 0x0000d7bf,
	0x00000000, 0x00000000, 0x00000000
};

static const uint32_t ar5416_vals_5g40[] = {
	0x00000460, 0x000002d0, 0x00001cc0, 0x00014000, 0x07d007d0,
	0x128d93cf, 0x08f04800, 0x00003210, 0x000003c4, 0x02020200,
	0x00000e0e, 0x0a020001, 0x00000e0e, 0x00000007, 0x1372161e,
	0x001a6a65, 0x001a6a65, 0x001a6a65, 0x6d48b4e0, 0x7ec82d2e,
	0x3139605e, 0x00049d18, 0x0001ce00, 0x409a4190, 0x050cb081,
	0x00000fa0, 0x00000370, 0xd0058a0b, 0xffb81020, 0x00000900,
	0x00000900, 0x00000900, 0x00000000, 0x001a0a00, 0x038919be,
	0x06336f77, 0x6af6532c, 0x08f186c8, 0x00046384, 0x00000000,
	0x00000000, 0x00000880, 0xd6be4788, 0x002ec1e0, 0x002ec1e0,
	0x002ec1e0, 0x1883800a, 0x00000000, 0x0a1a9caa, 0x18010000,
	0x30032602, 0x48073e06, 0x560b4c0a, 0x641a600f, 0x7a4f6e1b,
	0x8c5b7e5a, 0x9d0f96cf, 0xb51fa69f, 0xcb3fbcbf, 0x0000d7bf,
	0x00000000, 0x00000000, 0x00000000
};

static const uint32_t ar5416_vals_2g40[] = {
	0x000002c0, 0x00000318, 0x00007c70, 0x00016000, 0x10801600,
	0x12e013d7, 0x08f04810, 0x0000320a, 0x000003c4, 0x02020200,
	0x00000e0e, 0x0a020001, 0x00000e0e, 0x00000007, 0x137216a0,
	0x00197a68, 0x00197a68, 0x00197a68, 0x6d48b0de, 0x7ec82d2e,
	0x3139605e, 0x00049d18, 0x0001ce00, 0x409a4190, 0x050cb081,
	0x00001130, 0x00000268, 0xd0058a0b, 0xffb81020, 0x00012d80,
	0x00012d80, 0x00012d80, 0x00001120, 0x001a0a00, 0x038919be,
	0x06336f77, 0x6af6532c, 0x08f186c8, 0x00046384, 0x00000000,
	0x00000000, 0x00000880, 0xd03e4788, 0x002ac120, 0x002ac120,
	0x002ac120, 0x1883800a, 0x00000210, 0x0a1a7caa, 0x18010000,
	0x2e032402, 0x4a0a3c06, 0x621a540b, 0x764f6c1b, 0x845b7a5a,
	0x950f8ccf, 0xa5cf9b4f, 0xbddfaf1f, 0xd1ffc93f, 0x00000000,
	0x00000000, 0x00000000, 0x00000000
};

static const uint32_t ar5416_vals_2g20[] = {
	0x00000160, 0x0000018c, 0x00003e38, 0x0000b000, 0x08400b00,
	0x12e013ab, 0x08f04810, 0x0000320a, 0x00000300, 0x02020200,
	0x00000e0e, 0x0a020001, 0x00000e0e, 0x00000007, 0x137216a0,
	0x00197a68, 0x00197a68, 0x00197a68, 0x6c48b0de, 0x7ec82d2e,
	0x31395d5e, 0x00049d18, 0x0001ce00, 0x409a4190, 0x050cb081,
	0x00000898, 0x00000134, 0xd0058a0b, 0xffb81020, 0x00012d80,
	0x00012d80, 0x00012d80, 0x00001120, 0x001a0a00, 0x038919be,
	0x06336f77, 0x6af6532c, 0x08f186c8, 0x00046384, 0x00000000,
	0x00000000, 0x00000880, 0xd03e4788, 0x002ac120, 0x002ac120,
	0x002ac120, 0x1883800a, 0x00000108, 0x0a1a7caa, 0x18010000,
	0x2e032402, 0x4a0a3c06, 0x621a540b, 0x764f6c1b, 0x845b7a5a,
	0x950f8ccf, 0xa5cf9b4f, 0xbddfaf1f, 0xd1ffc93f, 0x00000000,
	0x00000000, 0x00000000, 0x00000000
};

static const uint16_t ar5416_cm_regs[] = {
	P(0x0000c), P(0x00030), P(0x00034), P(0x00040), P(0x00044),
	P(0x00048), P(0x0004c), P(0x00050), P(0x00054), P(0x00800),
	P(0x00804), P(0x00808), P(0x0080c), P(0x00810), P(0x00814),
	P(0x00818), P(0x0081c), P(0x00820), P(0x00824), P(0x01040),
	P(0x01044), P(0x01048), P(0x0104c), P(0x01050), P(0x01054),
	P(0x01058), P(0x0105c), P(0x01060), P(0x01064), P(0x01230),
	P(0x01270), P(0x01038), P(0x01078), P(0x010b8), P(0x010f8),
	P(0x01138), P(0x01178), P(0x011b8), P(0x011f8), P(0x01238),
	P(0x01278), P(0x012b8), P(0x012f8), P(0x01338), P(0x01378),
	P(0x013b8), P(0x013f8), P(0x01438), P(0x01478), P(0x014b8),
	P(0x014f8), P(0x01538), P(0x01578), P(0x015b8), P(0x015f8),
	P(0x01638), P(0x01678), P(0x016b8), P(0x016f8), P(0x01738),
	P(0x01778), P(0x017b8), P(0x017f8), P(0x0103c), P(0x0107c),
	P(0x010bc), P(0x010fc), P(0x0113c), P(0x0117c), P(0x011bc),
	P(0x011fc), P(0x0123c), P(0x0127c), P(0x012bc), P(0x012fc),
	P(0x0133c), P(0x0137c), P(0x013bc), P(0x013fc), P(0x0143c),
	P(0x0147c), P(0x04030), P(0x0403c), P(0x07010), P(0x07038),
	P(0x08004), P(0x08008), P(0x0800c), P(0x08018), P(0x08020),
	P(0x08038), P(0x0803c), P(0x08048), P(0x08054), P(0x08058),
	P(0x0805c), P(0x08060), P(0x08064), P(0x080c0), P(0x080c4),
	P(0x080c8), P(0x080cc), P(0x080d0), P(0x080d4), P(0x080d8),
	P(0x080e0), P(0x080e4), P(0x080e8), P(0x080ec), P(0x080f0),
	P(0x080f4), P(0x080f8), P(0x080fc), P(0x08100), P(0x08104),
	P(0x08108), P(0x0810c), P(0x08110), P(0x08118), P(0x0811c),
	P(0x08124), P(0x08128), P(0x0812c), P(0x08130), P(0x08134),
	P(0x08138), P(0x0813c), P(0x08144), P(0x08168), P(0x0816c),
	P(0x08170), P(0x08174), P(0x08178), P(0x0817c), P(0x081c4),
	P(0x081ec), P(0x081f0), P(0x081f4), P(0x081f8), P(0x081fc),
	P(0x08200), P(0x08204), P(0x08208), P(0x0820c), P(0x08210),
	P(0x08214), P(0x08218), P(0x0821c), P(0x08220), P(0x08224),
	P(0x08228), P(0x0822c), P(0x08230), P(0x08234), P(0x08238),
	P(0x0823c), P(0x08240), P(0x08244), P(0x08248), P(0x0824c),
	P(0x08250), P(0x08254), P(0x08258), P(0x0825c), P(0x08260),
	P(0x08264), P(0x08270), P(0x08274), P(0x08278), P(0x0827c),
	P(0x08284), P(0x08288), P(0x0828c), P(0x08294), P(0x08298),
	P(0x08300), P(0x08304), P(0x08308), P(0x0830c), P(0x08310),
	P(0x08314), P(0x08318), P(0x08328), P(0x0832c), P(0x08330),
	P(0x08334), P(0x08338), P(0x0833c), P(0x08340), P(0x09808),
	P(0x0980c), P(0x09810), P(0x09814), P(0x0981c), P(0x0982c),
	P(0x09830), P(0x0983c), P(0x09840), P(0x0984c), P(0x09854),
	P(0x09900), P(0x09904), P(0x09908), P(0x0990c), P(0x0991c),
	P(0x09920), P(0x0a920), P(0x0b920), P(0x09928), P(0x0992c),
	P(0x09934), P(0x09938), P(0x0993c), P(0x09948), P(0x0994c),
	P(0x09954), P(0x09958), P(0x0c95c), P(0x0c968), P(0x09970),
	P(0x09974), P(0x09978), P(0x0997c), P(0x09980), P(0x09984),
	P(0x09988), P(0x0998c), P(0x09990), P(0x09994), P(0x09998),
	P(0x0999c), P(0x099a0), P(0x099a4), P(0x099a8), P(0x099ac),
	P(0x099b0), P(0x099dc), P(0x099e0), P(0x099e4), P(0x099e8),
	P(0x099ec), P(0x099fc), P(0x09b00), P(0x09b04), P(0x09b08),
	P(0x09b0c), P(0x09b10), P(0x09b14), P(0x09b18), P(0x09b1c),
	P(0x09b20), P(0x09b24), P(0x09b28), P(0x09b2c), P(0x09b30),
	P(0x09b34), P(0x09b38), P(0x09b3c), P(0x09b40), P(0x09b44),
	P(0x09b48), P(0x09b4c), P(0x09b50), P(0x09b54), P(0x09b58),
	P(0x09b5c), P(0x09b60), P(0x09b64), P(0x09b68), P(0x09b6c),
	P(0x09b70), P(0x09b74), P(0x09b78), P(0x09b7c), P(0x09b80),
	P(0x09b84), P(0x09b88), P(0x09b8c), P(0x09b90), P(0x09b94),
	P(0x09b98), P(0x09b9c), P(0x09ba0), P(0x09ba4), P(0x09ba8),
	P(0x09bac), P(0x09bb0), P(0x09bb4), P(0x09bb8), P(0x09bbc),
	P(0x09bc0), P(0x09bc4), P(0x09bc8), P(0x09bcc), P(0x09bd0),
	P(0x09bd4), P(0x09bd8), P(0x09bdc), P(0x09be0), P(0x09be4),
	P(0x09be8), P(0x09bec), P(0x09bf0), P(0x09bf4), P(0x09bf8),
	P(0x09bfc), P(0x0a210), P(0x0a214), P(0x0a218), P(0x0a220),
	P(0x0a224), P(0x0a228), P(0x0a22c), P(0x0a234), P(0x0a238),
	P(0x0a23c), P(0x0a240), P(0x0a244), P(0x0a248), P(0x0a24c),
	P(0x0a250), P(0x0a254), P(0x0a258), P(0x0a25c), P(0x0a260),
	P(0x0a268), P(0x0a26c), P(0x0b26c), P(0x0c26c), P(0x0d270),
	P(0x0a278), P(0x0a27c), P(0x0a338), P(0x0a33c), P(0x0a340),
	P(0x0a344), P(0x0a348), P(0x0a34c), P(0x0a350), P(0x0a354),
	P(0x0a358), P(0x0d35c), P(0x0d360), P(0x0d364), P(0x0d368),
	P(0x0d36c), P(0x0d370), P(0x0d374), P(0x0d378), P(0x0d37c),
	P(0x0d380), P(0x0d384), P(0x0a388), P(0x0a38c), P(0x0a390),
	P(0x0a394), P(0x0a398), P(0x0a39c), P(0x0a3a0), P(0x0a3a4),
	P(0x0a3a8), P(0x0a3ac), P(0x0a3b0), P(0x0a3b4), P(0x0a3b8),
	P(0x0a3bc), P(0x0a3c0), P(0x0a3c4), P(0x0a3c8), P(0x0a3cc),
	P(0x0a3d0), P(0x0a3d4), P(0x0a3dc), P(0x0a3e0)
};

static const uint32_t ar5416_cm_vals[] = {
	0x00000000, 0x00020015, 0x00000005, 0x00000000, 0x00000008,
	0x00000008, 0x00000010, 0x00000000, 0x0000001f, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x002ffc0f,
	0x002ffc0f, 0x002ffc0f, 0x002ffc0f, 0x002ffc0f, 0x002ffc0f,
	0x002ffc0f, 0x002ffc0f, 0x002ffc0f, 0x002ffc0f, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00000002, 0x00000002, 0x00000000, 0x000004c2,
	0x00000000, 0x00000000, 0x00000000, 0x00000700, 0x00000000,
	0x00000000, 0x00000000, 0x40000000, 0x00000000, 0x00000000,
	0x000fc78f, 0x0000000f, 0x00000000, 0x2a82301a, 0x05dc01e0,
	0x1f402710, 0x01f40000, 0x00001e00, 0x00000000, 0x00400000,
	0xffffffff, 0x0000ffff, 0x003f3f3f, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00020000, 0x00020000, 0x00000001,
	0x00000052, 0x00000000, 0x00000168, 0x000100aa, 0x00003210,
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0xffffffff, 0x00000000, 0x00000000,
	0x32143320, 0xfaa4fa50, 0x00000100, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00100000, 0x0010f400, 0x00000100, 0x0001e800,
	0x00000000, 0x00000000, 0x00000000, 0x400000ff, 0x00080922,
	0x88000010, 0x00000000, 0x40000000, 0x003e4180, 0x00000000,
	0x0000002c, 0x0000002c, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000007, 0x00000302,
	0x00000e00, 0x00070000, 0x00000000, 0x000107ff, 0x00000000,
	0xad848e19, 0x7d14e000, 0x9c0a9f6b, 0x00000000, 0x0000a000,
	0x00000000, 0x00200400, 0x206a002e, 0x1284233c, 0x00000859,
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x10000fff,
	0x05100000, 0x05100000, 0x05100000, 0x00000001, 0x00000004,
	0x1e1f2022, 0x0a0b0c0d, 0x00000000, 0x9280b212, 0x00020028,
	0x5d50e188, 0x00081fff, 0x004b6a8e, 0x000003ce, 0x190fb515,
	0x00000000, 0x00000001, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000001, 0x001fff00, 0x00000000,
	0x03051000, 0x00000000, 0x00000200, 0xaaaaaaaa, 0x3c466478,
	0x000000aa, 0x00001042, 0x00000000, 0x00000001, 0x00000002,
	0x00000003, 0x00000004, 0x00000005, 0x00000008, 0x00000009,
	0x0000000a, 0x0000000b, 0x0000000c, 0x0000000d, 0x00000010,
	0x00000011, 0x00000012, 0x00000013, 0x00000014, 0x00000015,
	0x00000018, 0x00000019, 0x0000001a, 0x0000001b, 0x0000001c,
	0x0000001d, 0x00000020, 0x00000021, 0x00000022, 0x00000023,
	0x00000024, 0x00000025, 0x00000028, 0x00000029, 0x0000002a,
	0x0000002b, 0x0000002c, 0x0000002d, 0x00000030, 0x00000031,
	0x00000032, 0x00000033, 0x00000034, 0x00000035, 0x00000035,
	0x00000035, 0x00000035, 0x00000035, 0x00000035, 0x00000035,
	0x00000035, 0x00000035, 0x00000035, 0x00000035, 0x00000035,
	0x00000035, 0x00000035, 0x00000035, 0x00000035, 0x00000035,
	0x00000035, 0x00000035, 0x00000035, 0x00000035, 0x00000010,
	0x0000001a, 0x40806333, 0x00106c10, 0x009c4060, 0x018830c6,
	0x00000400, 0x00000bb5, 0x00000011, 0x20202020, 0x20202020,
	0x13c889af, 0x38490a20, 0x00007bb6, 0x0fff3ffc, 0x00000001,
	0x0000a000, 0x00000000, 0x0cc75380, 0x0f0f0f01, 0xdfa91f01,
	0x00000000, 0x0e79e5c6, 0x0e79e5c6, 0x0e79e5c6, 0x00820820,
	0x1ce739ce, 0x051701ce, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x3fffffff, 0x3fffffff, 0x3fffffff, 0x0003ffff,
	0x79a8aa1f, 0x07ffffef, 0x0fffffe7, 0x17ffffe5, 0x1fffffe4,
	0x37ffffe3, 0x3fffffe3, 0x57ffffe3, 0x5fffffe2, 0x7fffffe2,
	0x7f3c7bba, 0xf3307ff0, 0x08000000, 0x20202020, 0x20202020,
	0x1ce739ce, 0x000001ce, 0x00000001, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000246, 0x20202020,
	0x20202020, 0x20202020, 0x1ce739ce, 0x000001ce
};

static const struct athn_ini ar5416_ini = {
	nitems(ar5416_regs),
	ar5416_regs,
	ar5416_vals_5g20,
	ar5416_vals_5g40,
	ar5416_vals_2g40,
	ar5416_vals_2g20,
	nitems(ar5416_cm_regs),
	ar5416_cm_regs,
	ar5416_cm_vals
};

/*
 * AR9160 initialization values.
 */
static const uint16_t ar9160_regs[] = {
	P(0x01030), P(0x01070), P(0x010b0), P(0x010f0), P(0x08014),
	P(0x0801c), P(0x08120), P(0x081d0), P(0x09804), P(0x09820),
	P(0x09824), P(0x09828), P(0x09834), P(0x09838), P(0x09844),
	P(0x09848), P(0x0a848), P(0x0b848), P(0x09850), P(0x09858),
	P(0x0985c), P(0x09860), P(0x09864), P(0x09868), P(0x0986c),
	P(0x09914), P(0x09918), P(0x09924), P(0x09944), P(0x09960),
	P(0x0a960), P(0x0b960), P(0x09964), P(0x0c968), P(0x099bc),
	P(0x099c0), P(0x099c4), P(0x099c8), P(0x099cc), P(0x099d0),
	P(0x099d4), P(0x099d8), P(0x0a204), P(0x0a208), P(0x0a20c),
	P(0x0b20c), P(0x0c20c), P(0x0a21c), P(0x0a230), P(0x0a274),
	P(0x0a300), P(0x0a304), P(0x0a308), P(0x0a30c), P(0x0a310),
	P(0x0a314), P(0x0a318), P(0x0a31c), P(0x0a320), P(0x0a324),
	P(0x0a328), P(0x0a32c), P(0x0a330), P(0x0a334)
};

static const uint32_t ar9160_vals_5g20[] = {
	0x00000230, 0x00000168, 0x00000e60, 0x0000a000, 0x03e803e8,
	0x128d93a7, 0x08f04800, 0x00003210, 0x00000300, 0x02020200,
	0x00000e0e, 0x0a020001, 0x00000e0e, 0x00000007, 0x0372161e,
	0x001a6a65, 0x001a6a65, 0x001a6a65, 0x6c48b4e2, 0x7ec82d2e,
	0x31395d5e, 0x00048d18, 0x0001ce00, 0x409a40d0, 0x050cb081,
	0x000007d0, 0x0000000a, 0xd00a8a07, 0xffb81020, 0x00009b40,
	0x00009b40, 0x00009b40, 0x00001120, 0x000003b5, 0x001a0600,
	0x038919be, 0x06336f77, 0x6af65329, 0x08f186c8, 0x00046384,
	0x00000000, 0x00000000, 0x00000880, 0xd6be4788, 0x002fc160,
	0x002fc160, 0x002fc160, 0x1883800a, 0x00000000, 0x0a1a9caa,
	0x18010000, 0x30032602, 0x48073e06, 0x560b4c0a, 0x641a600f,
	0x7a4f6e1b, 0x8c5b7e5a, 0x9d0f96cf, 0xb51fa69f, 0xcb3fbd07,
	0x0000d7bf, 0x00000000, 0x00000000, 0x00000000
};

static const uint32_t ar9160_vals_5g40[] = {
	0x00000460, 0x000002d0, 0x00001cc0, 0x00014000, 0x07d007d0,
	0x128d93cf, 0x08f04800, 0x00003210, 0x000003c4, 0x02020200,
	0x00000e0e, 0x0a020001, 0x00000e0e, 0x00000007, 0x0372161e,
	0x001a6a65, 0x001a6a65, 0x001a6a65, 0x6d48b4e2, 0x7ec82d2e,
	0x3139605e, 0x00048d18, 0x0001ce00, 0x409a40d0, 0x050cb081,
	0x00000fa0, 0x00000014, 0xd00a8a07, 0xffb81020, 0x00009b40,
	0x00009b40, 0x00009b40, 0x00001120, 0x000003b5, 0x001a0600,
	0x038919be, 0x06336f77, 0x6af65329, 0x08f186c8, 0x00046384,
	0x00000000, 0x00000000, 0x00000880, 0xd6be4788, 0x002fc160,
	0x002fc160, 0x002fc160, 0x1883800a, 0x00000000, 0x0a1a9caa,
	0x18010000, 0x30032602, 0x48073e06, 0x560b4c0a, 0x641a600f,
	0x7a4f6e1b, 0x8c5b7e5a, 0x9d0f96cf, 0xb51fa69f, 0xcb3fbcbf,
	0x0000d7bf, 0x00000000, 0x00000000, 0x00000000
};

static const uint32_t ar9160_vals_2g40[] = {
	0x000002c0, 0x00000318, 0x00007c70, 0x00016000, 0x10801600,
	0x12e013d7, 0x08f04810, 0x0000320a, 0x000003c4, 0x02020200,
	0x00000e0e, 0x0a020001, 0x00000e0e, 0x00000007, 0x037216a0,
	0x00197a68, 0x00197a68, 0x00197a68, 0x6d48b0e2, 0x7ec82d2e,
	0x3139605e, 0x00048d20, 0x0001ce00, 0x409a40d0, 0x050cb081,
	0x00001130, 0x00000016, 0xd00a8a0d, 0xffb81020, 0x00009b40,
	0x00009b40, 0x00009b40, 0x00001120, 0x000003ce, 0x001a0c00,
	0x038919be, 0x06336f77, 0x6af65329, 0x08f186c8, 0x00046384,
	0x00000000, 0x00000000, 0x00000880, 0xd03e4788, 0x002ac120,
	0x002ac120, 0x002ac120, 0x1883800a, 0x00000210, 0x0a1a7caa,
	0x18010000, 0x2e032402, 0x4a0a3c06, 0x621a540b, 0x764f6c1b,
	0x845b7a5a, 0x950f8ccf, 0xa5cf9b4f, 0xbddfaf1f, 0xd1ffc93f,
	0x00000000, 0x00000000, 0x00000000, 0x00000000
};

static const uint32_t ar9160_vals_2g20[] = {
	0x00000160, 0x0000018c, 0x00003e38, 0x0000b000, 0x08400b00,
	0x12e013ab, 0x08f04810, 0x0000320a, 0x00000300, 0x02020200,
	0x00000e0e, 0x0a020001, 0x00000e0e, 0x00000007, 0x037216a0,
	0x00197a68, 0x00197a68, 0x00197a68, 0x6c48b0e2, 0x7ec82d2e,
	0x31395d5e, 0x00048d20, 0x0001ce00, 0x409a40d0, 0x050cb081,
	0x00000898, 0x0000000b, 0xd00a8a0d, 0xffb81020, 0x00009b40,
	0x00009b40, 0x00009b40, 0x00001120, 0x000003ce, 0x001a0c00,
	0x038919be, 0x06336f77, 0x6af65329, 0x08f186c8, 0x00046384,
	0x00000000, 0x00000000, 0x00000880, 0xd03e4788, 0x002ac120,
	0x002ac120, 0x002ac120, 0x1883800a, 0x00000108, 0x0a1a7caa,
	0x18010000, 0x2e032402, 0x4a0a3c06, 0x621a540b, 0x764f6c1b,
	0x845b7a5a, 0x950f8ccf, 0xa5cf9b4f, 0xbddfaf1f, 0xd1ffc93f,
	0x00000000, 0x00000000, 0x00000000, 0x00000000
};

static const uint16_t ar9160_cm_regs[] = {
	P(0x0000c), P(0x00030), P(0x00034), P(0x00040), P(0x00044),
	P(0x00048), P(0x0004c), P(0x00050), P(0x00054), P(0x00800),
	P(0x00804), P(0x00808), P(0x0080c), P(0x00810), P(0x00814),
	P(0x00818), P(0x0081c), P(0x00820), P(0x00824), P(0x01040),
	P(0x01044), P(0x01048), P(0x0104c), P(0x01050), P(0x01054),
	P(0x01058), P(0x0105c), P(0x01060), P(0x01064), P(0x01230),
	P(0x01270), P(0x01038), P(0x01078), P(0x010b8), P(0x010f8),
	P(0x01138), P(0x01178), P(0x011b8), P(0x011f8), P(0x01238),
	P(0x01278), P(0x012b8), P(0x012f8), P(0x01338), P(0x01378),
	P(0x013b8), P(0x013f8), P(0x01438), P(0x01478), P(0x014b8),
	P(0x014f8), P(0x01538), P(0x01578), P(0x015b8), P(0x015f8),
	P(0x01638), P(0x01678), P(0x016b8), P(0x016f8), P(0x01738),
	P(0x01778), P(0x017b8), P(0x017f8), P(0x0103c), P(0x0107c),
	P(0x010bc), P(0x010fc), P(0x0113c), P(0x0117c), P(0x011bc),
	P(0x011fc), P(0x0123c), P(0x0127c), P(0x012bc), P(0x012fc),
	P(0x0133c), P(0x0137c), P(0x013bc), P(0x013fc), P(0x0143c),
	P(0x0147c), P(0x04030), P(0x0403c), P(0x07010), P(0x07038),
	P(0x08004), P(0x08008), P(0x0800c), P(0x08018), P(0x08020),
	P(0x08038), P(0x0803c), P(0x08048), P(0x08054), P(0x08058),
	P(0x0805c), P(0x08060), P(0x08064), P(0x080c0), P(0x080c4),
	P(0x080c8), P(0x080cc), P(0x080d0), P(0x080d4), P(0x080d8),
	P(0x080e0), P(0x080e4), P(0x080e8), P(0x080ec), P(0x080f0),
	P(0x080f4), P(0x080f8), P(0x080fc), P(0x08100), P(0x08104),
	P(0x08108), P(0x0810c), P(0x08110), P(0x08118), P(0x0811c),
	P(0x08124), P(0x08128), P(0x0812c), P(0x08130), P(0x08134),
	P(0x08138), P(0x0813c), P(0x08144), P(0x08168), P(0x0816c),
	P(0x08170), P(0x08174), P(0x08178), P(0x0817c), P(0x081c4),
	P(0x081ec), P(0x081f0), P(0x081f4), P(0x081f8), P(0x081fc),
	P(0x08200), P(0x08204), P(0x08208), P(0x0820c), P(0x08210),
	P(0x08214), P(0x08218), P(0x0821c), P(0x08220), P(0x08224),
	P(0x08228), P(0x0822c), P(0x08230), P(0x08234), P(0x08238),
	P(0x0823c), P(0x08240), P(0x08244), P(0x08248), P(0x0824c),
	P(0x08250), P(0x08254), P(0x08258), P(0x0825c), P(0x08260),
	P(0x08264), P(0x08270), P(0x08274), P(0x08278), P(0x0827c),
	P(0x08284), P(0x08288), P(0x0828c), P(0x08294), P(0x08298),
	P(0x08300), P(0x08304), P(0x08308), P(0x0830c), P(0x08310),
	P(0x08314), P(0x08318), P(0x08328), P(0x0832c), P(0x08330),
	P(0x08334), P(0x08338), P(0x0833c), P(0x08340), P(0x09808),
	P(0x0980c), P(0x09810), P(0x09814), P(0x0981c), P(0x0982c),
	P(0x09830), P(0x0983c), P(0x09840), P(0x0984c), P(0x09854),
	P(0x09900), P(0x09904), P(0x09908), P(0x0990c), P(0x0991c),
	P(0x09920), P(0x0a920), P(0x0b920), P(0x09928), P(0x0992c),
	P(0x09934), P(0x09938), P(0x0993c), P(0x09948), P(0x0994c),
	P(0x09954), P(0x09958), P(0x09940), P(0x0c95c), P(0x09970),
	P(0x09974), P(0x09978), P(0x0997c), P(0x09980), P(0x09984),
	P(0x09988), P(0x0998c), P(0x09990), P(0x09994), P(0x09998),
	P(0x0999c), P(0x099a0), P(0x099a4), P(0x099a8), P(0x099ac),
	P(0x099b0), P(0x099dc), P(0x099e0), P(0x099e4), P(0x099e8),
	P(0x099ec), P(0x099fc), P(0x09b00), P(0x09b04), P(0x09b08),
	P(0x09b0c), P(0x09b10), P(0x09b14), P(0x09b18), P(0x09b1c),
	P(0x09b20), P(0x09b24), P(0x09b28), P(0x09b2c), P(0x09b30),
	P(0x09b34), P(0x09b38), P(0x09b3c), P(0x09b40), P(0x09b44),
	P(0x09b48), P(0x09b4c), P(0x09b50), P(0x09b54), P(0x09b58),
	P(0x09b5c), P(0x09b60), P(0x09b64), P(0x09b68), P(0x09b6c),
	P(0x09b70), P(0x09b74), P(0x09b78), P(0x09b7c), P(0x09b80),
	P(0x09b84), P(0x09b88), P(0x09b8c), P(0x09b90), P(0x09b94),
	P(0x09b98), P(0x09b9c), P(0x09ba0), P(0x09ba4), P(0x09ba8),
	P(0x09bac), P(0x09bb0), P(0x09bb4), P(0x09bb8), P(0x09bbc),
	P(0x09bc0), P(0x09bc4), P(0x09bc8), P(0x09bcc), P(0x09bd0),
	P(0x09bd4), P(0x09bd8), P(0x09bdc), P(0x09be0), P(0x09be4),
	P(0x09be8), P(0x09bec), P(0x09bf0), P(0x09bf4), P(0x09bf8),
	P(0x09bfc), P(0x0a210), P(0x0a214), P(0x0a218), P(0x0a220),
	P(0x0a224), P(0x0a228), P(0x0a22c), P(0x0a234), P(0x0a238),
	P(0x0a23c), P(0x0a240), P(0x0a244), P(0x0a248), P(0x0a24c),
	P(0x0a250), P(0x0a254), P(0x0a258), P(0x0a25c), P(0x0a260),
	P(0x0a268), P(0x0a26c), P(0x0b26c), P(0x0c26c), P(0x0d270),
	P(0x0a278), P(0x0a27c), P(0x0a338), P(0x0a33c), P(0x0a340),
	P(0x0a344), P(0x0a348), P(0x0a34c), P(0x0a350), P(0x0a354),
	P(0x0a358), P(0x0d35c), P(0x0d360), P(0x0d364), P(0x0d368),
	P(0x0d36c), P(0x0d370), P(0x0d374), P(0x0d378), P(0x0d37c),
	P(0x0d380), P(0x0d384), P(0x0a388), P(0x0a38c), P(0x0a390),
	P(0x0a394), P(0x0a398), P(0x0a39c), P(0x0a3a0), P(0x0a3a4),
	P(0x0a3a8), P(0x0a3ac), P(0x0a3b0), P(0x0a3b4), P(0x0a3b8),
	P(0x0a3bc), P(0x0a3c0), P(0x0a3c4), P(0x0a3c8), P(0x0a3cc),
	P(0x0a3d0), P(0x0a3d4), P(0x0a3dc), P(0x0a3e0)
};

static const uint32_t ar9160_cm_vals[] = {
	0x00000000, 0x00020015, 0x00000005, 0x00000000, 0x00000008,
	0x00000008, 0x00000010, 0x00000000, 0x0000001f, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x002ffc0f,
	0x002ffc0f, 0x002ffc0f, 0x002ffc0f, 0x002ffc0f, 0x002ffc0f,
	0x002ffc0f, 0x002ffc0f, 0x002ffc0f, 0x002ffc0f, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00000002, 0x00000002, 0x00000020, 0x000004c2,
	0x00000000, 0x00000000, 0x00000000, 0x00000700, 0x00000000,
	0x00000000, 0x00000000, 0x40000000, 0x00000000, 0x00000000,
	0x000fc78f, 0x0000000f, 0x00000000, 0x2a82301a, 0x05dc01e0,
	0x1f402710, 0x01f40000, 0x00001e00, 0x00000000, 0x00400000,
	0xffffffff, 0x0000ffff, 0x003f3f3f, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00020000, 0x00020000, 0x00000001,
	0x00000052, 0x00000000, 0x00000168, 0x000100aa, 0x00003210,
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0xffffffff, 0x00000000, 0x00000000,
	0x32143320, 0xfaa4fa50, 0x00000100, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00100000, 0x0010f400, 0x00000100, 0x0001e800,
	0x00000000, 0x00000000, 0x00000000, 0x400000ff, 0x00080922,
	0x88a00010, 0x00000000, 0x40000000, 0x003e4180, 0x00000000,
	0x0000002c, 0x0000002c, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000007, 0x00000302,
	0x00000e00, 0x00ff0000, 0x00000000, 0x000107ff, 0x00000000,
	0xad848e19, 0x7d14e000, 0x9c0a9f6b, 0x00000000, 0x0000a000,
	0x00000000, 0x00200400, 0x206a01ae, 0x1284233c, 0x00000859,
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x10000fff,
	0x05100000, 0x05100000, 0x05100000, 0x00000001, 0x00000004,
	0x1e1f2022, 0x0a0b0c0d, 0x00000000, 0x9280b212, 0x00020028,
	0x5f3ca3de, 0x2108ecff, 0x00750604, 0x004b6a8e, 0x190fb515,
	0x00000000, 0x00000001, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000001, 0x201fff00, 0x006f0000,
	0x03051000, 0x00000000, 0x00000200, 0xaaaaaaaa, 0x3c466478,
	0x0cc80caa, 0x00001042, 0x00000000, 0x00000001, 0x00000002,
	0x00000003, 0x00000004, 0x00000005, 0x00000008, 0x00000009,
	0x0000000a, 0x0000000b, 0x0000000c, 0x0000000d, 0x00000010,
	0x00000011, 0x00000012, 0x00000013, 0x00000014, 0x00000015,
	0x00000018, 0x00000019, 0x0000001a, 0x0000001b, 0x0000001c,
	0x0000001d, 0x00000020, 0x00000021, 0x00000022, 0x00000023,
	0x00000024, 0x00000025, 0x00000028, 0x00000029, 0x0000002a,
	0x0000002b, 0x0000002c, 0x0000002d, 0x00000030, 0x00000031,
	0x00000032, 0x00000033, 0x00000034, 0x00000035, 0x00000035,
	0x00000035, 0x00000035, 0x00000035, 0x00000035, 0x00000035,
	0x00000035, 0x00000035, 0x00000035, 0x00000035, 0x00000035,
	0x00000035, 0x00000035, 0x00000035, 0x00000035, 0x00000035,
	0x00000035, 0x00000035, 0x00000035, 0x00000035, 0x00000010,
	0x0000001a, 0x40806333, 0x00106c10, 0x009c4060, 0x018830c6,
	0x00000400, 0x001a0bb5, 0x00000000, 0x20202020, 0x20202020,
	0x13c889af, 0x38490a20, 0x00007bb6, 0x0fff3ffc, 0x00000001,
	0x0000e000, 0x00000000, 0x0cc75380, 0x0f0f0f01, 0xdfa91f01,
	0x00000001, 0x0e79e5c6, 0x0e79e5c6, 0x0e79e5c6, 0x00820820,
	0x1ce739ce, 0x050701ce, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x3fffffff, 0x3fffffff, 0x3fffffff, 0x0003ffff,
	0x79bfaa03, 0x07ffffef, 0x0fffffe7, 0x17ffffe5, 0x1fffffe4,
	0x37ffffe3, 0x3fffffe3, 0x57ffffe3, 0x5fffffe2, 0x7fffffe2,
	0x7f3c7bba, 0xf3307ff0, 0x0c000000, 0x20202020, 0x20202020,
	0x1ce739ce, 0x000001ce, 0x00000001, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000246, 0x20202020,
	0x20202020, 0x20202020, 0x1ce739ce, 0x000001ce
};

static const struct athn_ini ar9160_ini = {
	nitems(ar9160_regs),
	ar9160_regs,
	ar9160_vals_5g20,
	ar9160_vals_5g40,
	ar9160_vals_2g40,
	ar9160_vals_2g20,
	nitems(ar9160_cm_regs),
	ar9160_cm_regs,
	ar9160_cm_vals
};

/*
 * BB/RF Gains common to AR5416 and AR9160.
 */
static const uint32_t ar5416_bb_rfgain_vals_5g[] = {
	0x00000000, 0x00000040, 0x00000080, 0x000001a1, 0x000001e1,
	0x00000021, 0x00000061, 0x00000168, 0x000001a8, 0x000001e8,
	0x00000028, 0x00000068, 0x00000189, 0x000001c9, 0x00000009,
	0x00000049, 0x00000089, 0x00000170, 0x000001b0, 0x000001f0,
	0x00000030, 0x00000070, 0x00000191, 0x000001d1, 0x00000011,
	0x00000051, 0x00000091, 0x000001b8, 0x000001f8, 0x00000038,
	0x00000078, 0x00000199, 0x000001d9, 0x00000019, 0x00000059,
	0x00000099, 0x000000d9, 0x000000f9, 0x000000f9, 0x000000f9,
	0x000000f9, 0x000000f9, 0x000000f9, 0x000000f9, 0x000000f9,
	0x000000f9, 0x000000f9, 0x000000f9, 0x000000f9, 0x000000f9,
	0x000000f9, 0x000000f9, 0x000000f9, 0x000000f9, 0x000000f9,
	0x000000f9, 0x000000f9, 0x000000f9, 0x000000f9, 0x000000f9,
	0x000000f9, 0x000000f9, 0x000000f9, 0x000000f9
};

static const uint32_t ar5416_bb_rfgain_vals_2g[] = {
	0x00000000, 0x00000040, 0x00000080, 0x00000141, 0x00000181,
	0x000001c1, 0x00000001, 0x00000041, 0x000001a8, 0x000001e8,
	0x00000028, 0x00000068, 0x000000a8, 0x00000169, 0x000001a9,
	0x000001e9, 0x00000029, 0x00000069, 0x00000190, 0x000001d0,
	0x00000010, 0x00000050, 0x00000090, 0x00000151, 0x00000191,
	0x000001d1, 0x00000011, 0x00000051, 0x00000198, 0x000001d8,
	0x00000018, 0x00000058, 0x00000098, 0x00000159, 0x00000199,
	0x000001d9, 0x00000019, 0x00000059, 0x00000099, 0x000000d9,
	0x000000f9, 0x000000f9, 0x000000f9, 0x000000f9, 0x000000f9,
	0x000000f9, 0x000000f9, 0x000000f9, 0x000000f9, 0x000000f9,
	0x000000f9, 0x000000f9, 0x000000f9, 0x000000f9, 0x000000f9,
	0x000000f9, 0x000000f9, 0x000000f9, 0x000000f9, 0x000000f9,
	0x000000f9, 0x000000f9, 0x000000f9, 0x000000f9
};

static const uint32_t ar5416_2_1_addac_vals[] = {
	0x00000000, 0x00000003, 0x00000000, 0x0000000c, 0x00000000,
	0x00000030, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000060, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x00000000
};

static const struct athn_addac ar5416_2_1_addac = {
	nitems(ar5416_2_1_addac_vals),
	ar5416_2_1_addac_vals
};

static const uint32_t ar5416_2_2_addac_vals[] = {
	0x00000000, 0x00000003, 0x00000000, 0x0000000c, 0x00000000,
	0x00000030, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000060, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00000058, 0x00000000, 0x00000000, 0x00000000,
	0x00000000
};

static const struct athn_addac ar5416_2_2_addac = {
	nitems(ar5416_2_2_addac_vals),
	ar5416_2_2_addac_vals
};

static const uint32_t ar9160_1_0_addac_vals[] = {
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x000000c0, 0x00000018, 0x00000004, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x000000c0, 0x00000019, 0x00000004, 0x00000000,
	0x00000000, 0x00000000, 0x00000004, 0x00000003, 0x00000008,
	0x00000000
};

static const struct athn_addac ar9160_1_0_addac = {
	nitems(ar9160_1_0_addac_vals),
	ar9160_1_0_addac_vals
};

static const uint32_t ar9160_1_1_addac_vals[] = {
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x000000c0, 0x00000018, 0x00000004, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x000000c0, 0x00000019, 0x00000004, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x00000000
};

static const struct athn_addac ar9160_1_1_addac = {
	nitems(ar9160_1_1_addac_vals),
	ar9160_1_1_addac_vals
};

static const uint32_t ar5416_bank6tpc_vals[] = {
	0x00000000, 0x00000000, 0x00000000, 0x00e00000, 0x005e0000,
	0x00120000, 0x00620000, 0x00020000, 0x00ff0000, 0x00ff0000,
	0x00ff0000, 0x40ff0000, 0x005f0000, 0x00870000, 0x00f90000,
	0x007b0000, 0x00ff0000, 0x00f50000, 0x00dc0000, 0x00110000,
	0x006100a8, 0x00423022, 0x201400df, 0x00c40002, 0x003000f2,
	0x00440016, 0x00410040, 0x0001805e, 0x0000c0ab, 0x000000e1,
	0x00007081, 0x000000d4
};

static const uint32_t ar9160_bank6tpc_vals[] = {
	0x00000000, 0x00000000, 0x00000000, 0x00e00000, 0x005e0000,
	0x00120000, 0x00620000, 0x00020000, 0x00ff0000, 0x00ff0000,
	0x00ff0000, 0x40ff0000, 0x005f0000, 0x00870000, 0x00f90000,
	0x007b0000, 0x00ff0000, 0x00f50000, 0x00dc0000, 0x00110000,
	0x006100a8, 0x00423022, 0x2014008f, 0x00c40002, 0x003000f2,
	0x00440016, 0x00410040, 0x0001805e, 0x0000c0ab, 0x000000e1,
	0x00007080, 0x000000d4
};

static const uint32_t ar5416_bank6_vals[] = {
	0x00000000, 0x00000000, 0x00000000, 0x00e00000, 0x005e0000,
	0x00120000, 0x00620000, 0x00020000, 0x00ff0000, 0x00ff0000,
	0x00ff0000, 0x40ff0000, 0x005f0000, 0x00870000, 0x00f90000,
	0x007b0000, 0x00ff0000, 0x00f50000, 0x00dc0000, 0x00110000,
	0x006100a8, 0x004210a2, 0x0014008f, 0x00c40003, 0x003000f2,
	0x00440016, 0x00410040, 0x0001805e, 0x0000c0ab, 0x000000f1,
	0x00002081, 0x000000d4
};

/*
 * Serializer/Deserializer programming.
 */

static const uint32_t ar5416_serdes_regs[] = {
	AR_PCIE_SERDES,
	AR_PCIE_SERDES,
	AR_PCIE_SERDES,
	AR_PCIE_SERDES,
	AR_PCIE_SERDES,
	AR_PCIE_SERDES,
	AR_PCIE_SERDES,
	AR_PCIE_SERDES,
	AR_PCIE_SERDES,
	AR_PCIE_SERDES2
};

static const uint32_t ar5416_serdes_vals[] = {
	0x9248fc00,
	0x24924924,
	/* RX shut off when elecidle is asserted. */
	0x28000039,
	0x53160824,
	0xe5980579,
	0x001defff,
	0x1aaabe40,
	0xbe105554,
	0x000e3007,
	0x00000000
};

static const struct athn_serdes ar5416_serdes = {
	nitems(ar5416_serdes_vals),
	ar5416_serdes_regs,
	ar5416_serdes_vals,
};