/*
 / _____)             _              | |
( (____  _____ ____ _| |_ _____  ____| |__
 \____ \| ___ |    (_   _) ___ |/ ___)  _ \
 _____) ) ____| | | || |_| ____( (___| | | |
(______/|_____)_|_|_| \__)_____)\____)_| |_|
  (C)2018 Semtech

Description:
    TODO

License: Revised BSD License, see LICENSE.TXT file include in the project
*/


#ifndef _LORAGW_REG_H
#define _LORAGW_REG_H

/* -------------------------------------------------------------------------- */
/* --- DEPENDANCIES --------------------------------------------------------- */

#include <stdint.h>     /* C99 types */
#include <stdbool.h>    /* bool type */

#include "config.h"     /* library configuration options (dynamically generated) */

/* -------------------------------------------------------------------------- */
/* --- INTERNAL SHARED TYPES ------------------------------------------------ */

struct lgw_reg_s {
    int8_t   page;        /*!< page containing the register (-1 for all pages) */
    uint16_t addr;        /*!< base address of the register (15 bit) */
    uint8_t  offs;        /*!< position of the register LSB (between 0 to 7) */
    bool     sign;        /*!< 1 indicates the register is signed (2 complem.) */
    uint8_t  leng;        /*!< number of bits in the register */
    bool     rdon;        /*!< 1 indicates a read-only register */
    int32_t  dflt;        /*!< register default value */
};

/* -------------------------------------------------------------------------- */
/* --- INTERNAL SHARED FUNCTIONS -------------------------------------------- */

int reg_w_align32(void *spi_target, uint8_t spi_mux_target, struct lgw_reg_s r, int32_t reg_value);
int reg_r_align32(void *spi_target, uint8_t spi_mux_target, struct lgw_reg_s r, int32_t *reg_value);

/* -------------------------------------------------------------------------- */
/* --- PUBLIC CONSTANTS ----------------------------------------------------- */

#define LGW_REG_SUCCESS  0
#define LGW_REG_ERROR    -1

#define SX1302_REG_COMMON_PAGE_PAGE 0
#define SX1302_REG_COMMON_CTRL0_CLK32_RIF_CTRL 1
#define SX1302_REG_COMMON_CTRL0_HOST_RADIO_CTRL 2
#define SX1302_REG_COMMON_CTRL0_RADIO_MISC_EN 3
#define SX1302_REG_COMMON_CTRL0_SX1261_MODE_RADIO_B 4
#define SX1302_REG_COMMON_CTRL0_SX1261_MODE_RADIO_A 5
#define SX1302_REG_COMMON_SPI_DIV_RATIO_SPI_HALF_PERIOD 6
#define SX1302_REG_COMMON_RADIO_SELECT_RADIO_SELECT 7
#define SX1302_REG_COMMON_GEN_GLOBAL_EN 8
#define SX1302_REG_COMMON_GEN_FSK_MODEM_ENABLE 9
#define SX1302_REG_COMMON_GEN_CONCENTRATOR_MODEM_ENABLE 10
#define SX1302_REG_COMMON_GEN_MBWSSF_MODEM_ENABLE 11
#define SX1302_REG_COMMON_VERSION_VERSION 12
#define SX1302_REG_COMMON_DUMMY_DUMMY 13
#define SX1302_REG_AGC_MCU_CTRL_FORCE_HOST_FE_CTRL 14
#define SX1302_REG_AGC_MCU_CTRL_MCU_CLEAR 15
#define SX1302_REG_AGC_MCU_CTRL_HOST_PROG 16
#define SX1302_REG_AGC_MCU_MCU_AGC_STATUS_PARITY_ERROR 17
#define SX1302_REG_AGC_MCU_MCU_AGC_STATUS_MCU_AGC_STATUS 18
#define SX1302_REG_AGC_MCU_PA_GAIN_PA_B_GAIN 19
#define SX1302_REG_AGC_MCU_PA_GAIN_PA_A_GAIN 20
#define SX1302_REG_AGC_MCU_RF_EN_A_RADIO_RST 21
#define SX1302_REG_AGC_MCU_RF_EN_A_RADIO_EN 22
#define SX1302_REG_AGC_MCU_RF_EN_A_PA_EN 23
#define SX1302_REG_AGC_MCU_RF_EN_A_LNA_EN 24
#define SX1302_REG_AGC_MCU_RF_EN_B_RADIO_RST 25
#define SX1302_REG_AGC_MCU_RF_EN_B_RADIO_EN 26
#define SX1302_REG_AGC_MCU_RF_EN_B_PA_EN 27
#define SX1302_REG_AGC_MCU_RF_EN_B_LNA_EN 28
#define SX1302_REG_AGC_MCU_LUT_TABLE_A_PA_LUT 29
#define SX1302_REG_AGC_MCU_LUT_TABLE_A_LNA_LUT 30
#define SX1302_REG_AGC_MCU_LUT_TABLE_B_PA_LUT 31
#define SX1302_REG_AGC_MCU_LUT_TABLE_B_LNA_LUT 32
#define SX1302_REG_AGC_MCU_UART_CFG_MSBF 33
#define SX1302_REG_AGC_MCU_UART_CFG_PAR_EN 34
#define SX1302_REG_AGC_MCU_UART_CFG_PAR_MODE 35
#define SX1302_REG_AGC_MCU_UART_CFG_START_LEN 36
#define SX1302_REG_AGC_MCU_UART_CFG_STOP_LEN 37
#define SX1302_REG_AGC_MCU_UART_CFG_WORD_LEN 38
#define SX1302_REG_AGC_MCU_MCU_MAIL_BOX_WR_DATA_BYTE3_MCU_MAIL_BOX_WR_DATA 39
#define SX1302_REG_AGC_MCU_MCU_MAIL_BOX_WR_DATA_BYTE2_MCU_MAIL_BOX_WR_DATA 40
#define SX1302_REG_AGC_MCU_MCU_MAIL_BOX_WR_DATA_BYTE1_MCU_MAIL_BOX_WR_DATA 41
#define SX1302_REG_AGC_MCU_MCU_MAIL_BOX_WR_DATA_BYTE0_MCU_MAIL_BOX_WR_DATA 42
#define SX1302_REG_AGC_MCU_MCU_MAIL_BOX_RD_DATA_BYTE3_MCU_MAIL_BOX_RD_DATA 43
#define SX1302_REG_AGC_MCU_MCU_MAIL_BOX_RD_DATA_BYTE2_MCU_MAIL_BOX_RD_DATA 44
#define SX1302_REG_AGC_MCU_MCU_MAIL_BOX_RD_DATA_BYTE1_MCU_MAIL_BOX_RD_DATA 45
#define SX1302_REG_AGC_MCU_MCU_MAIL_BOX_RD_DATA_BYTE0_MCU_MAIL_BOX_RD_DATA 46
#define SX1302_REG_CLK_CTRL_CLK_SEL_CLKDIV_EN 47
#define SX1302_REG_CLK_CTRL_CLK_SEL_CLK_RADIO_B_SEL 48
#define SX1302_REG_CLK_CTRL_CLK_SEL_CLK_RADIO_A_SEL 49
#define SX1302_REG_CLK_CTRL_DUMMY_DUMMY 50
#define SX1302_REG_TX_TOP_A_TX_TRIG_TX_TRIG_GPS 51
#define SX1302_REG_TX_TOP_A_TX_TRIG_TX_TRIG_DELAYED 52
#define SX1302_REG_TX_TOP_A_TX_TRIG_TX_TRIG_IMMEDIATE 53
#define SX1302_REG_TX_TOP_A_TIMER_TRIG_BYTE3_TIMER_DELAYED_TRIG 54
#define SX1302_REG_TX_TOP_A_TIMER_TRIG_BYTE2_TIMER_DELAYED_TRIG 55
#define SX1302_REG_TX_TOP_A_TIMER_TRIG_BYTE1_TIMER_DELAYED_TRIG 56
#define SX1302_REG_TX_TOP_A_TIMER_TRIG_BYTE0_TIMER_DELAYED_TRIG 57
#define SX1302_REG_TX_TOP_A_TX_START_DELAY_MSB_TX_START_DELAY 58
#define SX1302_REG_TX_TOP_A_TX_START_DELAY_LSB_TX_START_DELAY 59
#define SX1302_REG_TX_TOP_A_TX_CTRL_WRITE_BUFFER 60
#define SX1302_REG_TX_TOP_A_TX_RAMP_DURATION_TX_RAMP_DURATION 61
#define SX1302_REG_TX_TOP_A_GEN_CFG_0_TX_RADIO_SEL 62
#define SX1302_REG_TX_TOP_A_GEN_CFG_0_MODULATION_TYPE 63
#define SX1302_REG_TX_TOP_A_GEN_CFG_0_TX_POWER 64
#define SX1302_REG_TX_TOP_A_TX_RFFE_IF_CTRL_PLL_DIV_CTRL 65
#define SX1302_REG_TX_TOP_A_TX_RFFE_IF_CTRL_TX_CLK_EDGE 66
#define SX1302_REG_TX_TOP_A_TX_RFFE_IF_CTRL_TX_MODE 67
#define SX1302_REG_TX_TOP_A_TX_RFFE_IF_CTRL_TX_IF_DST 68
#define SX1302_REG_TX_TOP_A_TX_RFFE_IF_CTRL_TX_IF_SRC 69
#define SX1302_REG_TX_TOP_A_TX_RFFE_IF_IQ_GAIN_IQ_GAIN 70
#define SX1302_REG_TX_TOP_A_TX_RFFE_IF_IQ_OFFSET_IQ_OFFSET 71
#define SX1302_REG_TX_TOP_A_TX_RFFE_IF_FREQ_RF_H_FREQ_RF 72
#define SX1302_REG_TX_TOP_A_TX_RFFE_IF_FREQ_RF_M_FREQ_RF 73
#define SX1302_REG_TX_TOP_A_TX_RFFE_IF_FREQ_RF_L_FREQ_RF 74
#define SX1302_REG_TX_TOP_A_TX_RFFE_IF_FREQ_DEV_H_FREQ_DEV 75
#define SX1302_REG_TX_TOP_A_TX_RFFE_IF_FREQ_DEV_L_FREQ_DEV 76
#define SX1302_REG_TX_TOP_A_TX_RFFE_IF_TEST_MOD_FREQ 77
#define SX1302_REG_TX_TOP_A_PKT_LEN_PKT_LENGTH 78
#define SX1302_REG_TX_TOP_A_FSK_CFG_0_TX_MODE 79
#define SX1302_REG_TX_TOP_A_FSK_CFG_0_CRC_IBM 80
#define SX1302_REG_TX_TOP_A_FSK_CFG_0_DCFREE_ENC 81
#define SX1302_REG_TX_TOP_A_FSK_CFG_0_CRC_EN 82
#define SX1302_REG_TX_TOP_A_FSK_CFG_0_PKT_MODE 83
#define SX1302_REG_TX_TOP_A_PREAMBLE_SIZE_MSB_PREAMBLE_SIZE 84
#define SX1302_REG_TX_TOP_A_PREAMBLE_SIZE_LSB_PREAMBLE_SIZE 85
#define SX1302_REG_TX_TOP_A_BIT_RATE_MSB_BIT_RATE 86
#define SX1302_REG_TX_TOP_A_BIT_RATE_LSB_BIT_RATE 87
#define SX1302_REG_TX_TOP_A_FSK_BT_FSK_REF_PATTERN_SIZE 88
#define SX1302_REG_TX_TOP_A_FSK_BT_FSK_PREAMBLE_SEQ 89
#define SX1302_REG_TX_TOP_A_FSK_BT_FSK_REF_PATTERN_EN 90
#define SX1302_REG_TX_TOP_A_FSK_BT_FSK_GAUSSIAN_SELECT_BT 91
#define SX1302_REG_TX_TOP_A_FSK_BT_FSK_GAUSSIAN_EN 92
#define SX1302_REG_TX_TOP_A_FSK_REF_PATTERN_BYTE7_FSK_REF_PATTERN 93
#define SX1302_REG_TX_TOP_A_FSK_REF_PATTERN_BYTE6_FSK_REF_PATTERN 94
#define SX1302_REG_TX_TOP_A_FSK_REF_PATTERN_BYTE5_FSK_REF_PATTERN 95
#define SX1302_REG_TX_TOP_A_FSK_REF_PATTERN_BYTE4_FSK_REF_PATTERN 96
#define SX1302_REG_TX_TOP_A_FSK_REF_PATTERN_BYTE3_FSK_REF_PATTERN 97
#define SX1302_REG_TX_TOP_A_FSK_REF_PATTERN_BYTE2_FSK_REF_PATTERN 98
#define SX1302_REG_TX_TOP_A_FSK_REF_PATTERN_BYTE1_FSK_REF_PATTERN 99
#define SX1302_REG_TX_TOP_A_FSK_REF_PATTERN_BYTE0_FSK_REF_PATTERN 100
#define SX1302_REG_TX_TOP_A_TX_STATUS_TX_STATUS 101
#define SX1302_REG_TX_TOP_A_TXRX_CFG0_0_MODEM_BW 102
#define SX1302_REG_TX_TOP_A_TXRX_CFG0_0_MODEM_SF 103
#define SX1302_REG_TX_TOP_A_TXRX_CFG0_1_PPM_OFFSET_HDR_CTRL 104
#define SX1302_REG_TX_TOP_A_TXRX_CFG0_1_PPM_OFFSET 105
#define SX1302_REG_TX_TOP_A_TXRX_CFG0_1_POST_PREAMBLE_GAP_LONG 106
#define SX1302_REG_TX_TOP_A_TXRX_CFG0_1_CODING_RATE 107
#define SX1302_REG_TX_TOP_A_TXRX_CFG0_2_FINE_SYNCH_EN 108
#define SX1302_REG_TX_TOP_A_TXRX_CFG0_2_MODEM_EN 109
#define SX1302_REG_TX_TOP_A_TXRX_CFG0_2_CADRXTX 110
#define SX1302_REG_TX_TOP_A_TXRX_CFG0_2_IMPLICIT_HEADER 111
#define SX1302_REG_TX_TOP_A_TXRX_CFG0_2_CRC_EN 112
#define SX1302_REG_TX_TOP_A_TXRX_CFG0_3_PAYLOAD_LENGTH 113
#define SX1302_REG_TX_TOP_A_TXRX_CFG1_0_INT_STEP_ORIDE_EN 114
#define SX1302_REG_TX_TOP_A_TXRX_CFG1_0_INT_STEP_ORIDE 115
#define SX1302_REG_TX_TOP_A_TXRX_CFG1_1_MODEM_START 116
#define SX1302_REG_TX_TOP_A_TXRX_CFG1_1_HEADER_DIFF_MODE 117
#define SX1302_REG_TX_TOP_A_TXRX_CFG1_1_ZERO_PAD 118
#define SX1302_REG_TX_TOP_A_TXRX_CFG1_2_PREAMBLE_SYMB_NB 119
#define SX1302_REG_TX_TOP_A_TXRX_CFG1_3_PREAMBLE_SYMB_NB 120
#define SX1302_REG_TX_TOP_A_TXRX_CFG1_4_AUTO_ACK_INT_DELAY 121
#define SX1302_REG_TX_TOP_A_TXRX_CFG1_4_AUTO_ACK_RX 122
#define SX1302_REG_TX_TOP_A_TXRX_CFG1_4_AUTO_ACK_TX 123
#define SX1302_REG_TX_TOP_A_TX_CFG0_0_CHIRP_LOWPASS 124
#define SX1302_REG_TX_TOP_A_TX_CFG0_0_PPM_OFFSET_SIG 125
#define SX1302_REG_TX_TOP_A_TX_CFG0_0_CONTCHIRP 126
#define SX1302_REG_TX_TOP_A_TX_CFG0_0_CHIRP_INVERT 127
#define SX1302_REG_TX_TOP_A_TX_CFG0_0_CONTINUOUS 128
#define SX1302_REG_TX_TOP_A_TX_CFG0_1_POWER_RANGING 129
#define SX1302_REG_TX_TOP_A_TX_CFG1_0_FRAME_NB 130
#define SX1302_REG_TX_TOP_A_TX_CFG1_1_HOP_CTRL 131
#define SX1302_REG_TX_TOP_A_TX_CFG1_1_IFS 132
#define SX1302_REG_TX_TOP_A_FRAME_SYNCH_0_AUTO_SCALE 133
#define SX1302_REG_TX_TOP_A_FRAME_SYNCH_0_DROP_ON_SYNCH 134
#define SX1302_REG_TX_TOP_A_FRAME_SYNCH_0_GAIN 135
#define SX1302_REG_TX_TOP_A_FRAME_SYNCH_0_PEAK1_POS 136
#define SX1302_REG_TX_TOP_A_FRAME_SYNCH_1_FINETIME_ON_LAST 137
#define SX1302_REG_TX_TOP_A_FRAME_SYNCH_1_TIMEOUT_OPT 138
#define SX1302_REG_TX_TOP_A_FRAME_SYNCH_1_PEAK2_POS 139
#define SX1302_REG_TX_TOP_A_LORA_TX_STATE_STATUS 140
#define SX1302_REG_TX_TOP_A_LORA_TX_FLAG_FRAME_DONE 141
#define SX1302_REG_TX_TOP_A_LORA_TX_FLAG_CONT_DONE 142
#define SX1302_REG_TX_TOP_A_LORA_TX_FLAG_PLD_DONE 143
#define SX1302_REG_TX_TOP_A_DUMMY_DUMMY 144
#define SX1302_REG_TX_TOP_B_TX_TRIG_TX_TRIG_GPS 145
#define SX1302_REG_TX_TOP_B_TX_TRIG_TX_TRIG_DELAYED 146
#define SX1302_REG_TX_TOP_B_TX_TRIG_TX_TRIG_IMMEDIATE 147
#define SX1302_REG_TX_TOP_B_TIMER_TRIG_BYTE3_TIMER_DELAYED_TRIG 148
#define SX1302_REG_TX_TOP_B_TIMER_TRIG_BYTE2_TIMER_DELAYED_TRIG 149
#define SX1302_REG_TX_TOP_B_TIMER_TRIG_BYTE1_TIMER_DELAYED_TRIG 150
#define SX1302_REG_TX_TOP_B_TIMER_TRIG_BYTE0_TIMER_DELAYED_TRIG 151
#define SX1302_REG_TX_TOP_B_TX_START_DELAY_MSB_TX_START_DELAY 152
#define SX1302_REG_TX_TOP_B_TX_START_DELAY_LSB_TX_START_DELAY 153
#define SX1302_REG_TX_TOP_B_TX_CTRL_WRITE_BUFFER 154
#define SX1302_REG_TX_TOP_B_TX_RAMP_DURATION_TX_RAMP_DURATION 155
#define SX1302_REG_TX_TOP_B_GEN_CFG_0_TX_RADIO_SEL 156
#define SX1302_REG_TX_TOP_B_GEN_CFG_0_MODULATION_TYPE 157
#define SX1302_REG_TX_TOP_B_GEN_CFG_0_TX_POWER 158
#define SX1302_REG_TX_TOP_B_TX_RFFE_IF_CTRL_PLL_DIV_CTRL 159
#define SX1302_REG_TX_TOP_B_TX_RFFE_IF_CTRL_TX_CLK_EDGE 160
#define SX1302_REG_TX_TOP_B_TX_RFFE_IF_CTRL_TX_MODE 161
#define SX1302_REG_TX_TOP_B_TX_RFFE_IF_CTRL_TX_IF_DST 162
#define SX1302_REG_TX_TOP_B_TX_RFFE_IF_CTRL_TX_IF_SRC 163
#define SX1302_REG_TX_TOP_B_TX_RFFE_IF_IQ_GAIN_IQ_GAIN 164
#define SX1302_REG_TX_TOP_B_TX_RFFE_IF_IQ_OFFSET_IQ_OFFSET 165
#define SX1302_REG_TX_TOP_B_TX_RFFE_IF_FREQ_RF_H_FREQ_RF 166
#define SX1302_REG_TX_TOP_B_TX_RFFE_IF_FREQ_RF_M_FREQ_RF 167
#define SX1302_REG_TX_TOP_B_TX_RFFE_IF_FREQ_RF_L_FREQ_RF 168
#define SX1302_REG_TX_TOP_B_TX_RFFE_IF_FREQ_DEV_H_FREQ_DEV 169
#define SX1302_REG_TX_TOP_B_TX_RFFE_IF_FREQ_DEV_L_FREQ_DEV 170
#define SX1302_REG_TX_TOP_B_TX_RFFE_IF_TEST_MOD_FREQ 171
#define SX1302_REG_TX_TOP_B_PKT_LEN_PKT_LENGTH 172
#define SX1302_REG_TX_TOP_B_FSK_CFG_0_TX_MODE 173
#define SX1302_REG_TX_TOP_B_FSK_CFG_0_CRC_IBM 174
#define SX1302_REG_TX_TOP_B_FSK_CFG_0_DCFREE_ENC 175
#define SX1302_REG_TX_TOP_B_FSK_CFG_0_CRC_EN 176
#define SX1302_REG_TX_TOP_B_FSK_CFG_0_PKT_MODE 177
#define SX1302_REG_TX_TOP_B_PREAMBLE_SIZE_MSB_PREAMBLE_SIZE 178
#define SX1302_REG_TX_TOP_B_PREAMBLE_SIZE_LSB_PREAMBLE_SIZE 179
#define SX1302_REG_TX_TOP_B_BIT_RATE_MSB_BIT_RATE 180
#define SX1302_REG_TX_TOP_B_BIT_RATE_LSB_BIT_RATE 181
#define SX1302_REG_TX_TOP_B_FSK_BT_FSK_REF_PATTERN_SIZE 182
#define SX1302_REG_TX_TOP_B_FSK_BT_FSK_PREAMBLE_SEQ 183
#define SX1302_REG_TX_TOP_B_FSK_BT_FSK_REF_PATTERN_EN 184
#define SX1302_REG_TX_TOP_B_FSK_BT_FSK_GAUSSIAN_SELECT_BT 185
#define SX1302_REG_TX_TOP_B_FSK_BT_FSK_GAUSSIAN_EN 186
#define SX1302_REG_TX_TOP_B_FSK_REF_PATTERN_BYTE7_FSK_REF_PATTERN 187
#define SX1302_REG_TX_TOP_B_FSK_REF_PATTERN_BYTE6_FSK_REF_PATTERN 188
#define SX1302_REG_TX_TOP_B_FSK_REF_PATTERN_BYTE5_FSK_REF_PATTERN 189
#define SX1302_REG_TX_TOP_B_FSK_REF_PATTERN_BYTE4_FSK_REF_PATTERN 190
#define SX1302_REG_TX_TOP_B_FSK_REF_PATTERN_BYTE3_FSK_REF_PATTERN 191
#define SX1302_REG_TX_TOP_B_FSK_REF_PATTERN_BYTE2_FSK_REF_PATTERN 192
#define SX1302_REG_TX_TOP_B_FSK_REF_PATTERN_BYTE1_FSK_REF_PATTERN 193
#define SX1302_REG_TX_TOP_B_FSK_REF_PATTERN_BYTE0_FSK_REF_PATTERN 194
#define SX1302_REG_TX_TOP_B_TX_STATUS_TX_STATUS 195
#define SX1302_REG_TX_TOP_B_TXRX_CFG0_0_MODEM_BW 196
#define SX1302_REG_TX_TOP_B_TXRX_CFG0_0_MODEM_SF 197
#define SX1302_REG_TX_TOP_B_TXRX_CFG0_1_PPM_OFFSET_HDR_CTRL 198
#define SX1302_REG_TX_TOP_B_TXRX_CFG0_1_PPM_OFFSET 199
#define SX1302_REG_TX_TOP_B_TXRX_CFG0_1_POST_PREAMBLE_GAP_LONG 200
#define SX1302_REG_TX_TOP_B_TXRX_CFG0_1_CODING_RATE 201
#define SX1302_REG_TX_TOP_B_TXRX_CFG0_2_FINE_SYNCH_EN 202
#define SX1302_REG_TX_TOP_B_TXRX_CFG0_2_MODEM_EN 203
#define SX1302_REG_TX_TOP_B_TXRX_CFG0_2_CADRXTX 204
#define SX1302_REG_TX_TOP_B_TXRX_CFG0_2_IMPLICIT_HEADER 205
#define SX1302_REG_TX_TOP_B_TXRX_CFG0_2_CRC_EN 206
#define SX1302_REG_TX_TOP_B_TXRX_CFG0_3_PAYLOAD_LENGTH 207
#define SX1302_REG_TX_TOP_B_TXRX_CFG1_0_INT_STEP_ORIDE_EN 208
#define SX1302_REG_TX_TOP_B_TXRX_CFG1_0_INT_STEP_ORIDE 209
#define SX1302_REG_TX_TOP_B_TXRX_CFG1_1_MODEM_START 210
#define SX1302_REG_TX_TOP_B_TXRX_CFG1_1_HEADER_DIFF_MODE 211
#define SX1302_REG_TX_TOP_B_TXRX_CFG1_1_ZERO_PAD 212
#define SX1302_REG_TX_TOP_B_TXRX_CFG1_2_PREAMBLE_SYMB_NB 213
#define SX1302_REG_TX_TOP_B_TXRX_CFG1_3_PREAMBLE_SYMB_NB 214
#define SX1302_REG_TX_TOP_B_TXRX_CFG1_4_AUTO_ACK_INT_DELAY 215
#define SX1302_REG_TX_TOP_B_TXRX_CFG1_4_AUTO_ACK_RX 216
#define SX1302_REG_TX_TOP_B_TXRX_CFG1_4_AUTO_ACK_TX 217
#define SX1302_REG_TX_TOP_B_TX_CFG0_0_CHIRP_LOWPASS 218
#define SX1302_REG_TX_TOP_B_TX_CFG0_0_PPM_OFFSET_SIG 219
#define SX1302_REG_TX_TOP_B_TX_CFG0_0_CONTCHIRP 220
#define SX1302_REG_TX_TOP_B_TX_CFG0_0_CHIRP_INVERT 221
#define SX1302_REG_TX_TOP_B_TX_CFG0_0_CONTINUOUS 222
#define SX1302_REG_TX_TOP_B_TX_CFG0_1_POWER_RANGING 223
#define SX1302_REG_TX_TOP_B_TX_CFG1_0_FRAME_NB 224
#define SX1302_REG_TX_TOP_B_TX_CFG1_1_HOP_CTRL 225
#define SX1302_REG_TX_TOP_B_TX_CFG1_1_IFS 226
#define SX1302_REG_TX_TOP_B_FRAME_SYNCH_0_AUTO_SCALE 227
#define SX1302_REG_TX_TOP_B_FRAME_SYNCH_0_DROP_ON_SYNCH 228
#define SX1302_REG_TX_TOP_B_FRAME_SYNCH_0_GAIN 229
#define SX1302_REG_TX_TOP_B_FRAME_SYNCH_0_PEAK1_POS 230
#define SX1302_REG_TX_TOP_B_FRAME_SYNCH_1_FINETIME_ON_LAST 231
#define SX1302_REG_TX_TOP_B_FRAME_SYNCH_1_TIMEOUT_OPT 232
#define SX1302_REG_TX_TOP_B_FRAME_SYNCH_1_PEAK2_POS 233
#define SX1302_REG_TX_TOP_B_LORA_TX_STATE_STATUS 234
#define SX1302_REG_TX_TOP_B_LORA_TX_FLAG_FRAME_DONE 235
#define SX1302_REG_TX_TOP_B_LORA_TX_FLAG_CONT_DONE 236
#define SX1302_REG_TX_TOP_B_LORA_TX_FLAG_PLD_DONE 237
#define SX1302_REG_TX_TOP_B_DUMMY_DUMMY 238

#define LGW_TOTALREGS 239

/* -------------------------------------------------------------------------- */
/* --- PUBLIC FUNCTIONS PROTOTYPES ------------------------------------------ */

/**
@brief Connect LoRa concentrator by opening SPI link
@return status of register operation (LGW_REG_SUCCESS/LGW_REG_ERROR)
*/
int lgw_connect(void);

/**
@brief Disconnect LoRa concentrator by closing SPI link
@return status of register operation (LGW_REG_SUCCESS/LGW_REG_ERROR)
*/
int lgw_disconnect(void);

/**
@brief LoRa concentrator register write
@param register_id register number in the data structure describing registers
@param reg_value signed value to write to the register (for u32, use cast)
@return status of register operation (LGW_REG_SUCCESS/LGW_REG_ERROR)
*/
int lgw_reg_w(uint16_t register_id, int32_t reg_value);

/**
@brief LoRa concentrator register read
@param register_id register number in the data structure describing registers
@param reg_value pointer to a variable where to write register read value
@return status of register operation (LGW_REG_SUCCESS/LGW_REG_ERROR)
*/
int lgw_reg_r(uint16_t register_id, int32_t *reg_value);

/**
@brief LoRa concentrator register burst write
@param register_id register number in the data structure describing registers
@param data pointer to byte array that will be sent to the LoRa concentrator
@param size size of the transfer, in byte(s)
@return status of register operation (LGW_REG_SUCCESS/LGW_REG_ERROR)
*/
int lgw_reg_wb(uint16_t register_id, uint8_t *data, uint16_t size);

/**
@brief LoRa concentrator register burst read
@param register_id register number in the data structure describing registers
@param data pointer to byte array that will be written from the LoRa concentrator
@param size size of the transfer, in byte(s)
@return status of register operation (LGW_REG_SUCCESS/LGW_REG_ERROR)
*/
int lgw_reg_rb(uint16_t register_id, uint8_t *data, uint16_t size);


#endif

/* --- EOF ------------------------------------------------------------------ */
