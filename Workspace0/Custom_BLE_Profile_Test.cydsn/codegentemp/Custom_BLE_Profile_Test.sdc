# THIS FILE IS AUTOMATICALLY GENERATED
# Project: H:\R_D\Smart_house_PSoC_part\Workspace0\Custom_BLE_Profile_Test.cydsn\Custom_BLE_Profile_Test.cyprj
# Date: Sat, 24 Mar 2018 09:33:11 GMT
#set_units -time ns
create_clock -name {CyRouted1} -period 83.333333333333329 -waveform {0 41.6666666666667} [list [get_pins {ClockBlock/dsi_in_0}]]
create_clock -name {CyWCO} -period 30517.578125 -waveform {0 15258.7890625} [list [get_pins {ClockBlock/wco}]]
create_clock -name {CyLFClk} -period 30517.578125 -waveform {0 15258.7890625} [list [get_pins {ClockBlock/lfclk}]]
create_clock -name {CyILO} -period 31250 -waveform {0 15625} [list [get_pins {ClockBlock/ilo}]]
create_clock -name {CyECO} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/eco}]]
create_clock -name {CyIMO} -period 83.333333333333329 -waveform {0 41.6666666666667} [list [get_pins {ClockBlock/imo}]]
create_clock -name {CyHFClk} -period 83.333333333333329 -waveform {0 41.6666666666667} [list [get_pins {ClockBlock/hfclk}]]
create_clock -name {CySysClk} -period 83.333333333333329 -waveform {0 41.6666666666667} [list [get_pins {ClockBlock/sysclk}]]
create_generated_clock -name {Clock} -source [get_pins {ClockBlock/hfclk}] -edges {1 25 49} [list [get_pins {ClockBlock/udb_div_0}]]

set_false_path -from [get_pins {__ONE__/q}]

# Component constraints for H:\R_D\Smart_house_PSoC_part\Workspace0\Custom_BLE_Profile_Test.cydsn\TopDesign\TopDesign.cysch
# Project: H:\R_D\Smart_house_PSoC_part\Workspace0\Custom_BLE_Profile_Test.cydsn\Custom_BLE_Profile_Test.cyprj
# Date: Sat, 24 Mar 2018 09:33:09 GMT
