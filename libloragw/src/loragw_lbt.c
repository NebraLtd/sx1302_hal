/*
 / _____)             _              | |
( (____  _____ ____ _| |_ _____  ____| |__
 \____ \| ___ |    (_   _) ___ |/ ___)  _ \
 _____) ) ____| | | || |_| ____( (___| | | |
(______/|_____)_|_|_| \__)_____)\____)_| |_|
  (C)2020 Semtech

Description:
    LoRa concentrator Listen-Before-Talk functions

License: Revised BSD License, see LICENSE.TXT file include in the project
*/


/* -------------------------------------------------------------------------- */
/* --- DEPENDANCIES --------------------------------------------------------- */

/* fix an issue between POSIX and C99 */
#if __STDC_VERSION__ >= 199901L
    #define _XOPEN_SOURCE 600
#else
    #define _XOPEN_SOURCE 500
#endif

#include <stdio.h>      /* printf */
#include <stdlib.h>     /* llabs */

#include "loragw_aux.h"
#include "loragw_lbt.h"
#include "loragw_sx1261.h"

/* -------------------------------------------------------------------------- */
/* --- PRIVATE MACROS ------------------------------------------------------- */

#if DEBUG_HAL == 1
    #define DEBUG_MSG(str)                fprintf(stderr, str)
    #define DEBUG_PRINTF(fmt, args...)    fprintf(stderr,"%s:%d: "fmt, __FUNCTION__, __LINE__, args)
#else
    #define DEBUG_MSG(str)
    #define DEBUG_PRINTF(fmt, args...)
#endif

/* -------------------------------------------------------------------------- */
/* --- PRIVATE FUNCTIONS DEFINITION ----------------------------------------- */

/* As given frequencies have been converted from float to integer, some aliasing
issues can appear, so we can't simply check for equality, but have to take some
margin */
static bool is_equal_freq(uint32_t a, uint32_t b) {
    int64_t diff;
    int64_t a64 = (int64_t)a;
    int64_t b64 = (int64_t)b;

    /* Calculate the difference */
    diff = llabs(a64 - b64);

    /* Check for acceptable diff range */
    return ((diff <= 10000) ? true : false);
}

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

static int is_lbt_channel(const struct lgw_conf_lbt_s * lbt_context, uint32_t freq_hz, uint8_t bandwidth) {
    int i;
    int lbt_channel_match = -1;

    if (bandwidth == BW_125KHZ) {
        for (i = 0; i <  lbt_context->nb_channel; i++) {
            if (is_equal_freq(freq_hz, lbt_context->channels[i].freq_hz) == true) {
                printf("LBT: select channel %d (%u Hz)\n", i, lbt_context->channels[i].freq_hz);
                lbt_channel_match = i;
                break;
            }
        }
    } else if (bandwidth == BW_250KHZ) {
        /* In case of 250KHz, the TX freq has to be in between 2 consecutive channels of 200KHz BW.
            The TX can only be over 2 channels, not more */
        for (i = 0; i < (lbt_context->nb_channel - 1); i++) {
            if ((is_equal_freq(freq_hz, (lbt_context->channels[i].freq_hz + lbt_context->channels[i+1].freq_hz) / 2) == true) && ((lbt_context->channels[i+1].freq_hz - lbt_context->channels[i].freq_hz) == 200E3)) {
                printf("LBT: select channels (%u-%u Hz)\n",  lbt_context->channels[i].freq_hz, lbt_context->channels[i+1].freq_hz);
                lbt_channel_match = i;
                break;
            }
        }
    } else {
        /* Nothing to do for now */
        printf("ERROR: Bandwidth Not supported for LBT (%u)\n", bandwidth);
    }

    /* Return the index of the LBT channel which matched */
    return lbt_channel_match;
}

/* -------------------------------------------------------------------------- */
/* --- PUBLIC FUNCTIONS DEFINITION ------------------------------------------ */

int lgw_lbt_start(const struct lgw_conf_lbt_s * lbt_context, uint32_t freq_hz, uint8_t bandwidth) {
    int err;
    int lbt_channel_selected;

    /* Check if we have a LBT channel for this transmit frequency */
    lbt_channel_selected = is_lbt_channel(lbt_context, freq_hz, bandwidth);
    if (lbt_channel_selected == -1) {
        printf("ERROR: Cannot start LBT - wrong channel\n");
        return -1;
    }

    /* Set LBT scan frequency */
    err = sx1261_set_rf_frequency(freq_hz, bandwidth);
    if (err != 0) {
        printf("ERROR: Cannot start LBT - unable to set sx1261 RF frequency to %u\n", freq_hz);
        return -1;
    }

    /* Start LBT */
    err = sx1261_lbt_start(lbt_context->channels[lbt_channel_selected].scan_time_us, lbt_context->rssi_target);
    if (err != 0) {
        printf("ERROR: Cannot start LBT - sx1261 LBT start\n");
        return -1;
    }

    return 0;
}

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

int lgw_lbt_stop(void) {
    return 0;
}

/* --- EOF ------------------------------------------------------------------ */