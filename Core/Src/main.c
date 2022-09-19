#include "platform_specific.h"
#include "spi.h"
#include "SSD1331.h"
#include "i2c.h"
#include "encoder.h"
#include "menu.h"





int main(void) {

 	spi_init();
	ssd1331_init();
	ssd1331_clear_screen(BLACK);
	i2c_init();
	encoder_init();


while(1){

}
} /* main */


