//=========================================
// Configurations for the ECE5745 Chip
//=========================================

#include "../defs.h"

void delay(const int d)
{

        /* Configure timer for a single-shot countdown */
        reg_timer0_config = 0;
        reg_timer0_data = d;
        reg_timer0_config = 1;

         // Loop, waiting for value to reach zero
        reg_timer0_update = 1;  // latch current value
        while (reg_timer0_value > 0) {
                reg_timer0_update = 1;
        }

}

void main()
{
        // Clock and Reset Configurations
        reg_mprj_io_11 = GPIO_MODE_USER_STD_INPUT_NOPULL; //Clock
        reg_mprj_io_10 = GPIO_MODE_USER_STD_INPUT_NOPULL; //Reset

        // Group 15 - Wavelet Compression Accelerator
        reg_mprj_io_37 = GPIO_MODE_USER_STD_OUTPUT; //Adapter Parity
        reg_mprj_io_35 = GPIO_MODE_USER_STD_INPUT_NOPULL; //Loopthrough Select
        reg_mprj_io_36 = GPIO_MODE_USER_STD_OUTPUT; //Minion Parity
        reg_mprj_io_8 = GPIO_MODE_USER_STD_INPUT_NOPULL; //SPI_CS
        reg_mprj_io_33 = GPIO_MODE_USER_STD_OUTPUT; //SPI_MISO
        reg_mprj_io_34 = GPIO_MODE_USER_STD_INPUT_NOPULL; //SPI_MOSI
        reg_mprj_io_9 = GPIO_MODE_USER_STD_INPUT_NOPULL; //SPI_SCLK

        // Group 16 - SpMV Accelerator
        reg_mprj_io_23 = GPIO_MODE_USER_STD_OUTPUT; //Adapter Parity
        reg_mprj_io_25 = GPIO_MODE_USER_STD_INPUT_NOPULL; //Loopthrough Select
        reg_mprj_io_24 = GPIO_MODE_USER_STD_OUTPUT; //Minion Parity
        reg_mprj_io_22 = GPIO_MODE_USER_STD_INPUT_NOPULL; //SPI_CS
        reg_mprj_io_20 = GPIO_MODE_USER_STD_OUTPUT; //SPI_MISO
        reg_mprj_io_19 = GPIO_MODE_USER_STD_INPUT_NOPULL; //SPI_MOSI
        reg_mprj_io_21 = GPIO_MODE_USER_STD_INPUT_NOPULL; //SPI_SCLK

        // Group 17 - BNN Accelerator
        reg_mprj_io_32 = GPIO_MODE_USER_STD_OUTPUT; //Adapter Parity
        reg_mprj_io_27 = GPIO_MODE_USER_STD_INPUT_NOPULL; //Loopthrough Select
        reg_mprj_io_26 = GPIO_MODE_USER_STD_OUTPUT; //Minion Parity
        reg_mprj_io_31 = GPIO_MODE_USER_STD_INPUT_NOPULL; //SPI_CS
        reg_mprj_io_29 = GPIO_MODE_USER_STD_OUTPUT; //SPI_MISO
        reg_mprj_io_28 = GPIO_MODE_USER_STD_INPUT_NOPULL; //SPI_MOSI
        reg_mprj_io_30 = GPIO_MODE_USER_STD_INPUT_NOPULL; //SPI_SCLK

        // Group 99 - GCD Accelerator
        reg_mprj_io_14 = GPIO_MODE_USER_STD_OUTPUT; //Adapter Parity
        reg_mprj_io_12 = GPIO_MODE_USER_STD_INPUT_NOPULL; //Loopthrough Select
        reg_mprj_io_13 = GPIO_MODE_USER_STD_OUTPUT; //Minion Parity
        reg_mprj_io_15 = GPIO_MODE_USER_STD_INPUT_NOPULL; //SPI_CS
        reg_mprj_io_17 = GPIO_MODE_USER_STD_OUTPUT; //SPI_MISO
        reg_mprj_io_18 = GPIO_MODE_USER_STD_INPUT_NOPULL; //SPI_MOSI
        reg_mprj_io_16 = GPIO_MODE_USER_STD_INPUT_NOPULL; //SPI_SCLK
        

        /* Apply configuration */
        reg_mprj_xfer = 1;
        while (reg_mprj_xfer == 1);

        // Blink LED to indicate finished
        reg_gpio_mode1 = 1;
        reg_gpio_mode0 = 0;
        reg_gpio_ien = 1;
        reg_gpio_oe = 1;

        while (1) {

                reg_gpio_out = 1; // OFF

                delay(8000000);

                reg_gpio_out = 0;  // ON

	        delay(8000000);

        }

}