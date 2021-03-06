// =====================================================================================================
// =====================================================================================================
// ===============================  Author:  John Kennedy Loria Segundo  ===============================
// ===================================  TrafficLights.c - ver.: 0.1  ===================================
// =====================  Initial Date: 02/12/2021 - Last Modify Date: ??/??/2021  =====================
// =====================================================================================================
// =====================================================================================================
//
//
//
//
//
// STATUS:
//
//                      IN DEVELOPMENT
//
//
//
// Code Function:
//
//
//
//
//
// Simplify code description:
//
//
//
//
//
// Logical description:
//
//
//
//
//
//
// Version observations:
// 
//
//              This code was created only for educational proposes, as a code exercise 
//              in C Lang for 8051 microcontroller (AT89S52).
//
//
//
//				This code use:
//
//				-		   Kit:		
//				-			µC:		8051 (Atmel - AT89S52)
//				-		 Clock:		1MHz (Xtal: 16MHz)
//				-		Editor:		VScode
//				-		Syntax:		C Language
//				-    Libraries:		at89x52.h (SDCC - GNU)
//				-	Compilator:		>> Not used yet <<
//				-	 Simulator:		SimulIDE
//
//
//
//									PROGRAM:
//  ----------------------------------------------------------------------------------------------------
//
//				Initial Stetaments: 
//
        #include "at89x52.h"
//
//
        unsigned short phases = 0x00 ;
		unsigned int timerCounter = 0x00 ;
//
//
        void setup(void) ;
        void pedestrianWalk(void) ;
//
//  ----------------------------------------------------------------------------------------------------
//
//				Memory Organization:
//
//
//
//
//
//  ----------------------------------------------------------------------------------------------------
//
//				timer0 subroutine:
//
	void timer0_isr(void) __interrupt (1) __using (1)
	{
		TF0 = 0 ;
		TR0 = 1 ;

		timerCounter = ++timerCounter ;

		if (timerCounter >= 0x00)
        {
			if (phases > 5)
			{
				phases = 0x00 ;
			}
			else
			{
				++phases ;
			}

			// I will need check phases and restart it

			timerCounter = 0x00 ;
		}

	}
//
//
//  ----------------------------------------------------------------------------------------------------
//
//				button interrupt sub-routine:
//
	void button_isr(void) __interrupt (0) __using (1)
	{

        pedestrianWalk(void) ;

	}
//
//
//  ----------------------------------------------------------------------------------------------------
//
//				Pedestrian Walk sub-routine:
//
	void pedestrianWalk(void)
	{

        

	}
//
//
//  ----------------------------------------------------------------------------------------------------
//
//				Initial Setup:
//
	void setup(void)
	{

    //    int phases = 0x00 ;

        P0 = 0x00 ;						// Start with all lights off
        P1 = 0xFF ;						// Uses Buttons as pull-up mode

        IE = 0x87 ;						// Enable Timer0 and Interrupt0

        PT0 = 1 ;						// Priorise Timer0 above others

        TMOD = 0x22	;					// Define Timer0 as 16bits without auto-charge

        TH0 = 0x00 ;					// 
        TL0 = 0x00 ;					// Set Timer0 to 0 seconds

        TF = 0 ;						// Clear Timer0 overflow flag
        TR = 1 ;						// Start Timer0

	}
//
//
//  ----------------------------------------------------------------------------------------------------
//
//				Main Routine:
//
	void main(void)
	{
		setup(void);

        while ( 1 )
        {
            switch ( phases )
            {
            case 1 :
                /* code */          	// red
                break;
            
            case 2 :
                /* code */          	// yellow
                break;
            
            case 4 :
                /* code */				// green
                break;
            
			case 5 :					// yellow (and return do 1)

				break;
            /*  default:
                break;   */
            }            
        }
//
//
//
//
	}
//
// 										Code ends!  =)
//  ----------------------------------------------------------------------------------------------------
//
//					Sketch notes:
//
//
//      [ x ] - Initial libraries for 8051 
//      [ x ] - timer
//      [ ? ] - Interrupt
//      [   ] - Switch Case sub routine
//
//
//