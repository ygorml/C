/* ================================================================
   _____ ____  _   _______ ______ _____
  / ____/ __ \| | |__   __|____  |  __ \
 | |   | |  | | |    | |      / /| |__) |
 | |   | |  | | |    | |     / / |  _  /
 | |___| |__| | |____| |    / /  | | \ \
  \_____\____/|______|_|   /_/   |_|  \_\

Title: Voltage, Current and Resistance Calculator v0.1
Author: Ygor Moreira Lima
Site: www.laboratoriodebits.com.br
Date: 25/07/2021
Description: Calculates Voltage, Current or Resistance

================================================================ */

/* ============================================================= */
/* Libraries */
#include <stdio.h>
#include <stdlib.h>

/* ============================================================= */
/* Main Function */

int main(void) {
  int option = 0;
  float voltage = 0.0, resistance = 0.0, current = 0.0, power = 0.0;
  printf("Enter the voltage (value in volts):\n");
  scanf("%f", &voltage);
  printf("Enter the resistance (value in ohms):\n");
  scanf("%f", &resistance);
  printf("\n\n================================\n");
  option:
  printf("Choose:\n");
  printf("1 - Current that flows in the resistor\n");
  printf("2 - Power dissiped in the resistor\n");
  printf("3 - Voltage for a 100mA current\n");
  scanf("%d", &option);
  if (option > 3 || option < 1)
  {
    printf("Invalid selection.\n");
    goto option;
  }
  if (option == 1)
    printf("The current that flows in the resistor is %.2fA\n", (voltage/resistance));
  if (option == 2)
    printf("The power dissiped in the resistor is %.2fW\n", (voltage*voltage)/resistance);
  if (option == 3)
    printf("The voltage for a 100mA current is %.2fV\n", (0,1*resistance));

} /* end main */

/* --- EOF --- */
