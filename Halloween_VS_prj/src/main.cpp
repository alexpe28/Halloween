#include <Arduino.h>
#include <FS.h>
#include <SD.h>
#include <esp32_smartdisplay.h>
#include <ui/ui.h>

// void millisecond_display_update()
// {
//     char time_buffer[32];
//     sprintf(time_buffer, "%d", millis());
//     lv_label_set_text(ui_lblMillisecondsValue, time_buffer);
// }

// void OnButtonClicked(lv_event_t *e)
// {
//     static uint8_t cnt = 0;
//     cnt++;
//     lv_label_set_text_fmt(ui_lblCountValue, "%d", cnt);
// }

void setup()
{
    Serial.begin(115200);
    smartdisplay_init();
    ui_init();
    auto r = (byte)(0);
    auto g = (byte)(0);
    auto b = (byte)(0);
    smartdisplay_set_led_color(lv_color32_t({.ch = {.blue = b, .green = g, .red = r}}));

    SPI.begin(SD_SCK, SD_MISO, SD_MOSI); // передаём в SPI.begin значения используемых пинов
    if (!SD.begin(SD_SS))
    { // передаём в SD.begin значение используемого SS-пина
        String temp = "Card Mount Failed";
        Serial.println(temp);
        // tft.fillScreen(TFT_BLACK);
        // tft.setTextSize(2);
        // tft.setCursor(10, 50);
        // tft.setTextColor(0xC618);
        // tft.print(temp);
        return;
    }
    uint8_t cardType = SD.cardType();

    if (cardType == CARD_NONE)
    {
        String temp = "No SD card attached";
        Serial.println(temp);
        // tft.fillScreen(TFT_BLACK);
        // tft.setTextSize(2);
        // tft.setCursor(10, 50);
        // tft.setTextColor(0xC618);
        // tft.print(temp);
        return;
    }

    Serial.print("SD Card Type: ");
    if (cardType == CARD_MMC)
    {
        Serial.println("MMC");
    }
    else if (cardType == CARD_SD)
    {
        Serial.println("SDSC");
    }
    else if (cardType == CARD_SDHC)
    {
        Serial.println("SDHC");
    }
    else
    {
        Serial.println("UNKNOWN");
    }

    uint64_t cardSize = SD.cardSize() / (1024 * 1024);
    String temp = "SD Size: " + String(cardSize);
    Serial.println(temp);
}

void loop()
{
    lv_timer_handler();

    // auto r = (byte)(millis() / 75);
    // auto g = (byte)(millis() / 10);
    // auto b = (byte)(millis() / 150);

    // smartdisplay_set_led_color(lv_color32_t({.ch = {.blue = b, .green = g, .red = r}}));

    // millisecond_display_update();
}