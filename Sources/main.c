//*******************************************************************************************************
// Filename: main.c
// Lab Project: 1
// AUTHORS:
//  Abdulla Al Braiki (ayalbrai@asu.edu)
//  Zachary Priddy (zpriddy@asu.edu) (http://www.zpriddy.com)
// Course: CSE325 Embedded Microprocessor Systems
// Semester: Fall 2013
//
// DESCRIPTION
// A first TWR-MCF5225X program. Uses the GPIO module and Port TC to flash the LED's on the TWR-MCF5225x micro-
// controller board.
//
// Computer Science & Engineering
// Arizona State University
// Tempe, AZ 85287-8809
//
//********************************************************************************************************

#include "support_common.h"
#define forever for(;;)
//**************************************************************************************************************
// FUNCTION: busy_delay()
// 
// DESCRIPTION
// Implements a very sleazy busy delay which just kills time. The main problem with this technique is that it is
// not entirely clear what the value of p_delay should be to delay for n microseconds or m milliseconds. We will
// see a better way to do this later on using the DMA timers (DTIM module).
//**************************************************************************************************************
static void busy_delay(int p_delay)
{
 for (int x = 1, i = 0; i < p_delay; ++i) x = x * 2 + 1;
}
/***************************************************************************************************************
// FUNCTION: led_off()
// 
// DESCRIPTION
// Turns LED 1, 2, 3, or 4 off.
// 
// INPUTS
// p_led should be 1, 2, 3, or 4.
//*************************************************************************************************************/
static void led_off(int p_led)
{
 MCF_GPIO_CLRTC &= ~(1 << (p_led - 1));
}

/***************************************************************************************************************
// FUNCTION: led_on()
// 
// DESCRIPTION
// Turns LED 1, 2, 3, or 4 on.
// 
// INPUTS
// p_led should be 1, 2, 3, or 4.
//*************************************************************************************************************/
static void led_on(int p_led)
{
 MCF_GPIO_SETTC |= 1 << (p_led - 1);
}
/***************************************************************************************************************
// FUNCTION: main()
// 
// DESCRIPTION
// Flashes LED's 1 and 3 on and off at about a 2 Hz rate.
// 
// __declspace(noreturn) tells the compiler that even though main() returns an int, don't complain about the
// fact that we do not have a return statement at the end of the function. The C language specification states
// very clearly that main() must return an int. But, this program will never end, so we forgo the return state-
// ment.
//*************************************************************************************************************/
__declspec(noreturn) int main()
{
 // Program Port TC Pin Assignment Register (PTCPAR) so pins 0, 1, 2, and 3 are configured for the general-
 // purpose I/O (GPIO) function.
 MCF_GPIO_PTCPAR = MCF_GPIO_PTCPAR_PTCPAR0(MCF_GPIO_PTCPAR_DTIN0_GPIO) |
 MCF_GPIO_PTCPAR_PTCPAR1(MCF_GPIO_PTCPAR_DTIN1_GPIO) |
 MCF_GPIO_PTCPAR_PTCPAR1(MCF_GPIO_PTCPAR_DTIN2_GPIO) |
 MCF_GPIO_PTCPAR_PTCPAR1(MCF_GPIO_PTCPAR_DTIN3_GPIO);
 // Program Port TC Data Direction Register (DDRTC) so pins 0, 1, 2, and 3 are configured as output pins.
 MCF_GPIO_DDRTC = MCF_GPIO_DDRTC_DDRTC0 |
 MCF_GPIO_DDRTC_DDRTC1 |
 MCF_GPIO_DDRTC_DDRTC2 |
 MCF_GPIO_DDRTC_DDRTC3;
 // Turn off all LED's.
 led_off(1); led_off(2); led_off(3); led_off(4);
forever {
 // Turn on LED's 1 and 3.
  led_off(1); led_off(2); led_off(3); led_off(4);
 // Kill time for around a quarter of a second.
 busy_delay(500000);
 // Turn off LED's 1 and 3.
  led_off(1); led_off(2); led_off(3); led_off(4);
 // Kill time for around a quarter of a second.
 busy_delay(500000);
 
 //Turn on LEDs to display binary number 0001
  led_on(1);
   // Kill time for around a quarter of a second.
 busy_delay(500000);
  // Turn off all LED's.
   led_off(1); led_off(2); led_off(3); led_off(4);
 // Kill time for around a quarter of a second.
 busy_delay(500000);
 
  //Turn on LEDs to display binary number 0010
  led_on(2);
   // Kill time for around a quarter of a second.
 busy_delay(500000);
  // Turn off all LED's.
   led_off(1); led_off(2); led_off(3); led_off(4);
 // Kill time for around a quarter of a second.
 busy_delay(500000);
 
  //Turn on LEDs to display binary number 0011
  led_on(1); led_on(2);
   // Kill time for around a quarter of a second.
 busy_delay(500000);
  // Turn off all LED's.
   led_off(1); led_off(2); led_off(3); led_off(4);
 // Kill time for around a quarter of a second.
 busy_delay(500000);
 
  //Turn on LEDs to display binary number 0100
  led_on(3);
   // Kill time for around a quarter of a second.
 busy_delay(500000);
  // Turn off all LED's.
   led_off(1); led_off(2); led_off(3); led_off(4);
 // Kill time for around a quarter of a second.
 busy_delay(500000);
 
   //Turn on LEDs to display binary number 0101
  led_on(3); led_on(1);
   // Kill time for around a quarter of a second.
 busy_delay(500000);
  // Turn off all LED's.
   led_off(1); led_off(2); led_off(3); led_off(4);
 // Kill time for around a quarter of a second.
 busy_delay(500000);
 
    //Turn on LEDs to display binary number 0110
  led_on(3); led_on(2);
   // Kill time for around a quarter of a second.
 busy_delay(500000);
  // Turn off all LED's.
   led_off(1); led_off(2); led_off(3); led_off(4);
 // Kill time for around a quarter of a second.
 busy_delay(500000);
 
    //Turn on LEDs to display binary number 0111
  led_on(3); led_on(2); led_on(1);
   // Kill time for around a quarter of a second.
 busy_delay(500000);
  // Turn off all LED's.
   led_off(1); led_off(2); led_off(3); led_off(4);
 // Kill time for around a quarter of a second.
 busy_delay(500000);
 
     //Turn on LEDs to display binary number 1000
  led_on(4);
   // Kill time for around a quarter of a second.
 busy_delay(500000);
  // Turn off all LED's.
   led_off(1); led_off(2); led_off(3); led_off(4);
 // Kill time for around a quarter of a second.
 busy_delay(500000);
 
     //Turn on LEDs to display binary number 1001
  led_on(4); led_on(1);
   // Kill time for around a quarter of a second.
 busy_delay(500000);
  // Turn off all LED's.
   led_off(1); led_off(2); led_off(3); led_off(4);
 // Kill time for around a quarter of a second.
 busy_delay(500000);
 
     //Turn on LEDs to display binary number 1010
  led_on(4); led_on(2);
   // Kill time for around a quarter of a second.
 busy_delay(500000);
  // Turn off all LED's.
   led_off(1); led_off(2); led_off(3); led_off(4);
 // Kill time for around a quarter of a second.
 busy_delay(500000);
 
     //Turn on LEDs to display binary number 1011
  led_on(4); led_on(2); led_on(1);
   // Kill time for around a quarter of a second.
 busy_delay(500000);
  // Turn off all LED's.
   led_off(1); led_off(2); led_off(3); led_off(4);
 // Kill time for around a quarter of a second.
 busy_delay(500000);
 
     //Turn on LEDs to display binary number 1100
  led_on(4); led_on(3);
   // Kill time for around a quarter of a second.
 busy_delay(500000);
  // Turn off all LED's.
   led_off(1); led_off(2); led_off(3); led_off(4);
 // Kill time for around a quarter of a second.
 busy_delay(500000);
 
      //Turn on LEDs to display binary number 1101
  led_on(4); led_on(3); led_on(1);
   // Kill time for around a quarter of a second.
 busy_delay(500000);
  // Turn off all LED's.
   led_off(1); led_off(2); led_off(3); led_off(4);
 // Kill time for around a quarter of a second.
 busy_delay(500000);
 
       //Turn on LEDs to display binary number 1110
  led_on(4); led_on(3); led_on(2);
   // Kill time for around a quarter of a second.
 busy_delay(500000);
  // Turn off all LED's.
   led_off(1); led_off(2); led_off(3); led_off(4);
 // Kill time for around a quarter of a second.
 busy_delay(500000);
 
       //Turn on LEDs to display binary number 1111
  led_on(4); led_on(3); led_on(2); led_on(1);
   // Kill time for around a quarter of a second.
 busy_delay(500000);
  // Turn off all LED's.
   led_off(1); led_off(2); led_off(3); led_off(4);
 // Kill time for around a quarter of a second.
 busy_delay(500000);
 
  
 }
}