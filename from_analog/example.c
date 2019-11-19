static struct spi_board_info bfin_spi_board_info[] __initdata = {
#if defined(CONFIG_AD525X_DPOT) || defined(CONFIG_AD525X_DPOT_MODULE)
	{
		.modalias = "ad5291",
		.max_speed_hz = 5000000,     /* max spi clock (SCK) speed in HZ */
		.bus_num = 0,
		.chip_select = 1,
	},
#endif
};
