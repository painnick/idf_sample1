#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "nvs_flash.h"
#include "ps3.h"

void controller_event_cb( ps3_t ps3, ps3_event_t event )
{
    if ( ps3.status.battery >= ps3_status_battery_high )
        printf("The controller still has sufficient battery charge");

    if ( ps3.status.charging )
        printf("Controller is charging");

    if ( ps3.button.triangle )
        printf("Currently pressing the trangle button");

    if ( ps3.analog.stick.lx < 0 )
        printf("Currently pulling analog stick to the left");

    if ( event.button_down.cross )
        printf("The user started pressing the X button");

    if ( event.button_up.cross )
        printf("The user released the X button");

    if ( event.analog_changed.stick.lx )
        printf("The user has moved the left stick sideways");
}

void app_main(void)
{
    // while (true) {
    //     printf("Hello from app_main!\n");
    //     sleep(1);
    // }

    nvs_flash_init();

    uint8_t base_mac[6] = {0x44, 0x44, 0x44, 0x44, 0x44, 0x44};

    ps3SetBluetoothMacAddress(base_mac);
    ps3SetEventCallback(controller_event_cb);
    ps3Init();

    while (!ps3IsConnected()){
        // Prevent the Task Watchdog from triggering
        vTaskDelay(10 / portTICK_PERIOD_MS);
    }
}
