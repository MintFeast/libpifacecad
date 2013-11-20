/* pifacedigital.h
 * A simple static library for controlling PiFace Digital.
 * See mcp23s17.h for more register definitions.
 */

#ifndef _PIFACECAD_H
#define _PIFACECAD_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#define DELAY_PULSE_NS 1000 // 10us
#define DELAY_SETTLE_NS 4000 // 40us
#define DELAY_SETUP_0 15000000 // 15ms
#define DELAY_SETUP_1 5000000 // 5ms
#define DELAY_SETUP_2 1000000 // 1ms

// mcp23s17 GPIOB to HD44780 pin map
#define PIN_D4 0
#define PIN_D5 1
#define PIN_D6 2
#define PIN_D7 3
#define PIN_ENABLE 4
#define PIN_RW 5
#define PIN_RS 6
#define PIN_BACKLIGHT 7

// commands
#define LCD_CLEARDISPLAY 0x01
#define LCD_RETURNHOME 0x02
#define LCD_ENTRYMODESET 0x04
#define LCD_DISPLAYCONTROL 0x08
#define LCD_CURSORSHIFT 0x10
#define LCD_FUNCTIONSET 0x20
#define LCD_SETCGRAMADDR 0x40
#define LCD_SETDDRAMADDR 0x80
#define LCD_NEWLINE 0xC0

// flags for display entry mode
#define LCD_ENTRYRIGHT 0x00
#define LCD_ENTRYLEFT 0x02
#define LCD_ENTRYSHIFTINCREMENT 0x01
#define LCD_ENTRYSHIFTDECREMENT 0x00

// flags for display on/off control
#define LCD_DISPLAYON 0x04
#define LCD_DISPLAYOFF 0x00
#define LCD_CURSORON 0x02
#define LCD_CURSOROFF 0x00
#define LCD_BLINKON 0x01
#define LCD_BLINKOFF 0x00

// flags for display/cursor shift
#define LCD_DISPLAYMOVE 0x08
#define LCD_CURSORMOVE 0x00
#define LCD_MOVERIGHT 0x04
#define LCD_MOVELEFT 0x00

// flags for function set
#define LCD_8BITMODE 0x10
#define LCD_4BITMODE 0x00
#define LCD_2LINE 0x08
#define LCD_1LINE 0x00
#define LCD_5X10DOTS 0x04
#define LCD_5X8DOTS 0x00

//[0x00, 0x40, 0x14, 0x54]
static const uint8_t ROW_OFFSETS[2] = {0x00, 0x40};

#define LCD_MAX_LINES 2
#define LCD_WIDTH 16
#define LCD_RAM_WIDTH 80

int pifacecad_open_noinit(); // open without initialising
int pifacecad_open();
int pifacecad_close();

int pifacecad_lcd_init();

uint8_t pifacecad_read_switches();
uint8_t pifacecad_read_switch(uint8_t switch_num);

int pifacecad_lcd_write(const char * message);

int pifacecad_lcd_set_cursor(int col, int row);
int pifacecad_lcd_set_cursor_address(int address);
int pifacecad_lcd_get_cursor_address();

int pifacecad_lcd_clear();
int pifacecad_lcd_home();

int pifacecad_lcd_display_on();
int pifacecad_lcd_display_off();
int pifacecad_lcd_blink_on();
int pifacecad_lcd_blink_off();
int pifacecad_lcd_cursor_on();
int pifacecad_lcd_cursor_off();
int pifacecad_lcd_backlight_on();
int pifacecad_lcd_backlight_off();

int pifacecad_lcd_move_left();
int pifacecad_lcd_move_right();
int pifacecad_lcd_left_justify();
int pifacecad_lcd_right_justify();
int pifacecad_lcd_left_to_right();
int pifacecad_lcd_right_to_left();

int pifacecad_lcd_set_cgram_address(int address);
int pifacecad_lcd_set_ddram_address(int address);
int pifacecad_lcd_update_function_set(uint8_t state);
int pifacecad_lcd_update_entry_mode(uint8_t state);
int pifacecad_lcd_update_display_control(uint8_t state);

int pifacecad_lcd_send_command(uint8_t command);
int pifacecad_lcd_send_data(uint8_t data);
int pifacecad_lcd_send_byte(uint8_t byte);
int pifacecad_lcd_set_rs(uint8_t state);
int pifacecad_lcd_set_rw(uint8_t state);
int pifacecad_lcd_set_enable(uint8_t state);
int pifacecad_lcd_set_backlight(uint8_t state);

int pifacecad_lcd_pulse_enable();

int colrow2address(int col, int row);
int address2col(int address);
int address2row(int address);

// int pifacecad_lcd_set_viewport_corner(int col);
// int pifacecad_lcd_see_cursor(int col);

#ifdef __cplusplus
}
#endif

#endif