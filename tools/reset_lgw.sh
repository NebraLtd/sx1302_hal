#!/bin/sh

# This script is intended to be used on a Raspberry Pi with a RAK2287/RAK5146 Pi HAT.
# It performs the following actions:
#       - export/unexport GPIO17 used to reset the SX1302 chip and to enable the LDOs
#       - export/unexport GPIO25 used to reset the ZOE-M8Q GPS module
#
# Usage examples:
#       ./reset_lgw.sh stop
#       ./reset_lgw.sh start

# GPIO mapping has to be adapted with HW
#

SX1302_RESET_PIN=17     # SX1302 reset
M8Q_GPS_RESET_PIN=13    # GPS reset

WAIT_GPIO() {
    sleep 0.1
}

init() {
    # setup GPIOs
    echo "$SX1302_RESET_PIN" > /sys/class/gpio/export; WAIT_GPIO
    echo "$M8Q_GPS_RESET_PIN" > /sys/class/gpio/export; WAIT_GPIO

    # set GPIOs as output
    echo "out" > /sys/class/gpio/gpio$SX1302_RESET_PIN/direction; WAIT_GPIO
    echo "out" > /sys/class/gpio/gpio$M8Q_RESET_PIN/direction; WAIT_GPIO
}

reset() {
    echo "SX1302 reset through GPIO$SX1302_RESET_PIN..."
    echo "GPS reset through GPIO$M8Q_GPS_RESET_PIN..."

    echo "1" > /sys/class/gpio/gpio$SX1302_RESET_PIN/value; WAIT_GPIO
    echo "0" > /sys/class/gpio/gpio$SX1302_RESET_PIN/value; WAIT_GPIO

    echo "0" > /sys/class/gpio/gpio$M8Q_GPS_RESET_PIN/value; WAIT_GPIO
    echo "1" > /sys/class/gpio/gpio$M8Q_GPS_RESET_PIN/value; WAIT_GPIO
}

term() {
    # cleanup all GPIOs
    if [ -d /sys/class/gpio/gpio$SX1302_RESET_PIN ]
    then
        echo "$SX1302_RESET_PIN" > /sys/class/gpio/unexport; WAIT_GPIO
    fi
    if [ -d /sys/class/gpio/gpio$M8Q_GPS_RESET_PIN ]
    then
        echo "$M8Q_GPS_RESET_RESET_PIN" > /sys/class/gpio/unexport; WAIT_GPIO
    fi
}

case "$1" in
    start)
    term # just in case
    init
    reset
    ;;
    stop)
    reset
    term
    ;;
    *)
    echo "Usage: $0 {start|stop}"
    exit 1
    ;;
esac

exit 0
