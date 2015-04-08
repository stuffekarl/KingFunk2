# THIS FILE IS AUTOMATICALLY GENERATED
# Project: C:\Users\Snufkin\Documents\GitHub\KingFunk2\CRT_timer\CRT_timer.cydsn\CRT_timer.cyprj
# Date: Wed, 08 Apr 2015 08:55:53 GMT
#set_units -time ns
create_clock -name {ADC_intClock(FFB)} -period 125 -waveform {0 62.5} [list [get_pins {ClockBlock/ff_div_7}]]
create_clock -name {UART_1_SCBCLK(FFB)} -period 8666.6666666666661 -waveform {0 4333.33333333333} [list [get_pins {ClockBlock/ff_div_3}]]
create_clock -name {CyHFCLK} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/hfclk}]]
create_generated_clock -name {ADC_intClock} -source [get_pins {ClockBlock/hfclk}] -edges {1 3 7} [list]
create_generated_clock -name {cl_deb} -source [get_pins {ClockBlock/hfclk}] -edges {1 2400001 4800001} [list [get_pins {ClockBlock/udb_div_0}]]
create_generated_clock -name {UART_1_SCBCLK} -source [get_pins {ClockBlock/hfclk}] -edges {1 209 417} -nominal_period 8666.6666666666661 [list]
create_clock -name {CyIMO} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/imo}]]
create_clock -name {CySYSCLK} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/sysclk}]]
create_clock -name {CyILO} -period 31250 -waveform {0 15625} [list [get_pins {ClockBlock/ilo}]]
create_clock -name {CyLFCLK} -period 31250 -waveform {0 15625} [list [get_pins {ClockBlock/lfclk}]]
create_clock -name {CyRouted1} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/dsi_in_0}]]


# Component constraints for C:\Users\Snufkin\Documents\GitHub\KingFunk2\CRT_timer\CRT_timer.cydsn\TopDesign\TopDesign.cysch
# Project: C:\Users\Snufkin\Documents\GitHub\KingFunk2\CRT_timer\CRT_timer.cydsn\CRT_timer.cyprj
# Date: Wed, 08 Apr 2015 08:55:49 GMT
