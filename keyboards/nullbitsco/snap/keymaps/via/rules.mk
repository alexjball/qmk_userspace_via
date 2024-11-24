VIA_ENABLE = yes
ENCODER_MAP_ENABLE = yes
MOUSEKEY_ENABLE = yes
OLED_ENABLE = yes

# https://nullbits.co/snap/
# Uses SSD1306 OLED display https://www.amazon.com/dp/B08KLMJDGH
# https://docs.qmk.fm/features/oled_driver
OLED_DRIVER = ssd1306

WPM_ENABLE = no

SRC += keycode_lookup.c
