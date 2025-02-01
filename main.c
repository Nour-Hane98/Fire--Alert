#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_log.h"

#define TAG "FlameDetector"

// 🔹 Define the pins for the flame sensor and buzzer
#define FLAME_SENSOR_PIN  GPIO_NUM_13  // Flame sensor connected to GPIO 13
#define BUZZER_PIN        GPIO_NUM_15  // Buzzer connected to GPIO 15

void app_main(void) {
    // Log message for starting
    ESP_LOGI(TAG, "Starting ESP32 Flame Detector...");

    // Initialize the flame sensor pin as input
    gpio_set_direction(FLAME_SENSOR_PIN, GPIO_MODE_INPUT);
    // Initialize the buzzer pin as output
    gpio_set_direction(BUZZER_PIN, GPIO_MODE_OUTPUT);

    while (1) {
        // Read the flame sensor (HIGH = flame detected, LOW = no flame)
        int flameDetected = gpio_get_level(FLAME_SENSOR_PIN);

        if (flameDetected == 1) {  // HIGH means flame detected
            ESP_LOGI(TAG, "🔥 Fire detected! Activating alarm...");
            gpio_set_level(BUZZER_PIN, 1); // Activate buzzer
            vTaskDelay(pdMS_TO_TICKS(500)); // Keep the buzzer on for half a second
        } else {  // LOW means no flame detected
            ESP_LOGI(TAG, "✅ No fire detected.");
            gpio_set_level(BUZZER_PIN, 0); // Deactivate buzzer
        }


      

        vTaskDelay(pdMS_TO_TICKS(1000)); // Check every second
    }
}
