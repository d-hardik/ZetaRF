
#include "config868_variablelength_crc_preamble10_sync4_payload8.h"

// INPUT DATA
/*
// Crys_freq(Hz): 30000000    Crys_tol(ppm): 30    IF_mode: 2    High_perf_Ch_Fil: 1    OSRtune: 0    Ch_Fil_Bw_AFC: 0    ANT_DIV: 0    PM_pattern: 0
// MOD_type: 2    Rsymb(sps): 128000    Fdev(Hz): 70000    RXBW(Hz): 305000    Manchester: 1    AFC_en: 1    Rsymb_error: 0.0    Chip-Version: 2
// RF Freq.(MHz): 868    API_TC: 28    fhst: 250000    inputBW: 0    BERT: 0    RAW_dout: 0    D_source: 0    Hi_pfm_div: 0
//
// # WB filter 2 (BW = 274.83 kHz);  NB-filter 2 (BW = 274.83 kHz)
//
// Modulation index: 1
*/



// CONFIGURATION COMMANDS

/*
// Command:                  RF_POWER_UP
// Description:              Command to power-up the device and select the operational mode and functionality.
*/
#define RF_POWER_UP 0x02, 0x01, 0x00, 0x01, 0xC9, 0xC3, 0x80

/*
// Set properties:           RF_INT_CTL_ENABLE_2
// Number of properties:     2
// Group ID:                 0x01
// Start ID:                 0x00
// Default values:           0x04, 0x00,
// Descriptions:
//   INT_CTL_ENABLE - This property provides for global enabling of the three interrupt groups (Chip, Modem and Packet Handler) in order to generate HW interrupts at the NIRQ pin.
//   INT_CTL_PH_ENABLE - Enable individual interrupt sources within the Packet Handler Interrupt Group to generate a HW interrupt on the NIRQ output pin.
*/
#define RF_INT_CTL_ENABLE_2 0x11, 0x01, 0x02, 0x00, 0x05, 0x38

/*
// Set properties:           RF_INT_CTL_CHIP_ENABLE_1
// Number of properties:     1
// Group ID:                 0x01
// Start ID:                 0x03
// Default values:           0x04,
// Descriptions:
//   INT_CTL_CHIP_ENABLE - Enable individual interrupt sources within the Chip Interrupt Group to generate a HW interrupt on the NIRQ output pin.
*/
#define RF_INT_CTL_CHIP_ENABLE_1 0x11, 0x01, 0x01, 0x03, 0x6C

/*
// Set properties:           RF_FRR_CTL_A_MODE_4
// Number of properties:     4
// Group ID:                 0x02
// Start ID:                 0x00
// Default values:           0x01, 0x02, 0x09, 0x00,
// Descriptions:
//   FRR_CTL_A_MODE - Fast Response Register A Configuration.
//   FRR_CTL_B_MODE - Fast Response Register B Configuration.
//   FRR_CTL_C_MODE - Fast Response Register C Configuration.
//   FRR_CTL_D_MODE - Fast Response Register D Configuration.
*/
#define RF_FRR_CTL_A_MODE_4 0x11, 0x02, 0x04, 0x00, 0x09, 0x04, 0x06, 0x08

/*
// Set properties:           RF_EZCONFIG_XO_TUNE_1
// Number of properties:     1
// Group ID:                 0x24
// Start ID:                 0x03
// Default values:           0x40,
// Descriptions:
//   EZCONFIG_XO_TUNE - Configure the internal capacitor frequency tuning bank for the crystal oscillator.
*/
#define RF_EZCONFIG_XO_TUNE_1 0x11, 0x24, 0x01, 0x03, 0x52

/*
// Command:                  RF_WRITE_TX_FIFO
// Description:              Writes data byte(s) to the TX FIFO.
*/
#define RF_WRITE_TX_FIFO 0x66, 0xFC, 0x0E, 0xAD, 0x5F, 0xA6, 0x26, 0x06, 0xE1, 0xAC, 0xA0, 0x0B, 0xE2, 0xB8, 0x28, 0x0F, 0xC6, 0x68, 0xE1, 0x0E, \
0x54, 0x4D, 0x69, 0x30, 0xBC, 0xEC, 0x6E, 0x20, 0xCC, 0x8B, 0x0E, 0x3D, 0x0F, 0x5C, 0xE8, 0x4C, 0x7E, 0x1B, 0x49, 0xC2, \
0xF9, 0x6D, 0x37, 0xF8, 0x2B, 0xB3, 0x7F, 0x1F, 0xF5, 0x8E, 0x1B, 0x59, 0x03, 0xAC, 0x0A, 0xF0, 0x84, 0x2A, 0x22, 0x54, \
0x75, 0x3D, 0xFE, 0xBA, 0x2A, 0xE6, 0xC6, 0x83, 0x77, 0xC5, 0x36, 0x26, 0xCF, 0xFF, 0x86, 0xF3, 0x9D, 0x63, 0xB3, 0xC9, \
0xBE, 0x8A, 0xB9, 0x28, 0xEE, 0x2C, 0x88, 0x75, 0xAE, 0x22, 0x07, 0x0A, 0xBF, 0x7B, 0x78, 0x77, 0x33, 0xE6, 0x9F, 0xA7, \
0xEA, 0x57, 0xF7, 0x96, 0xC1, 0x1F, 0x3F, 0x90, 0x4F, 0xC5, 0xF5, 0xBA, 0xEF, 0x5C

/*
// Command:                  RF_NOP
// Description:              No Operation command.
*/
#define RF_NOP 0x00

/*
// Command:                  RF_WRITE_TX_FIFO_1
// Description:              Writes data byte(s) to the TX FIFO.
*/
#define RF_WRITE_TX_FIFO_1 0x66, 0x10, 0x0A, 0x93, 0x37, 0x09, 0xAB, 0x1D, 0x3D, 0xE0, 0xF0, 0x3F, 0x28, 0x74, 0xFE, 0xDA, 0xBC, 0xE8, 0xDA, 0x62, \
0x6D, 0xD0, 0xA2, 0x1E, 0x6E, 0x16, 0x21, 0x03, 0x31, 0xB5, 0x28, 0xC6, 0xCF, 0x1B, 0xFF, 0xBB, 0xF0, 0xFA, 0x11, 0xCA, \
0xD8, 0xA7, 0x28, 0x04, 0x13, 0x5C, 0x81, 0x9B, 0x9B, 0x32, 0x7D, 0x99, 0xA8, 0x8D, 0xF0, 0x64, 0x89, 0x6C, 0x79, 0xDE, \
0x26, 0x12, 0x95, 0xBE, 0x07, 0x9D, 0x7E, 0xE6, 0xA1, 0x90, 0x8B, 0xF7, 0xFD, 0xB5, 0x97, 0x5E, 0x49, 0xFB, 0x8B, 0xB3, \
0x62, 0xE7, 0x30, 0x5D, 0x9C, 0x81, 0x63, 0xEA, 0xCD, 0xD0, 0x65, 0x09, 0xF7, 0x53, 0xB3, 0xEB, 0x4B, 0xC8, 0x68, 0x60, \
0xC4, 0xD0, 0x53, 0xA5, 0xCA, 0x6C, 0xF0, 0xED, 0xBA, 0xF0, 0x9B, 0xD0

/*
// Command:                  RF_EZCONFIG_CHECK
// Description:              Validates the EZConfig array was written correctly.
*/
#define RF_EZCONFIG_CHECK 0x19, 0xD0, 0xFD

/*
// Command:                  RF_GPIO_PIN_CFG
// Description:              Configures the GPIO pins.
*/
#define RF_GPIO_PIN_CFG 0x13, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00


namespace ZetaRfConfigs {

const uint8_t Config868_VariableLength_CRC_Preamble10_Sync4_Payload8::RadioConfigurationDataArray[]
{
    0x07, RF_POWER_UP, \
    0x06, RF_INT_CTL_ENABLE_2, \
    0x05, RF_INT_CTL_CHIP_ENABLE_1, \
    0x08, RF_FRR_CTL_A_MODE_4, \
    0x05, RF_EZCONFIG_XO_TUNE_1, \
    0x72, RF_WRITE_TX_FIFO, \
    0x01, RF_NOP, \
    0x70, RF_WRITE_TX_FIFO_1, \
    0x03, RF_EZCONFIG_CHECK, \
    0x08, RF_GPIO_PIN_CFG, \
    0x00
};

} // namespace ZetaRfConfigs
