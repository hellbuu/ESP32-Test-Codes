/*
task notification: gatilhos entre tasks conversando diretamente 
*/

#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

static TaskHandle_t manipulador = NULL;

void task1(void *params){
    while(1){
        xTaskNotifyGive(manipulador);
        vTaskDelay(2000 / portTICK_PERIOD_MS);
}
}

void task2(void *params){
    while(1){
        ulTaskNotifyTake(pdFALSE, portMAX_DELAY);
        printf("Notificação recebida.\n");
}
}

int app_main(){
    xTaskCreate(&task1, "task1", 4096, NULL, 2, &manipulador);
    xTaskCreate(&task2, "task2", 4096, NULL, 2, &manipulador);

    return 0;
}