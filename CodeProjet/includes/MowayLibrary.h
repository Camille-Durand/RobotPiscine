//********************************************************************************
//*    This program is free software; you can redistribute it and/or modify      *
//*    it under the terms of the GNU General Public License as published by      *
//*    the Free Software Foundation; either version 3 of the License, or         *
//*    (at your option) any later version.                                       *
//*                                                                              *
//*    This program is distributed in the hope that it will be useful,           *
//*    but WITHOUT ANY WARRANTY; without even the implied warranty of            *
//*    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the             *
//*    GNU General Public License for more details.                              *
//*                                                                              *
//*    You should have received a copy of the GNU General Public License along   *
//*    with this program; if not, write to the Free Software Foundation, Inc.,   *
//*    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.               *
//********************************************************************************

#define MOT_END       PORTEbits.RE7				//	PIN_E7
//Engine module adress
#define   MOT_DIR         0x10

//Comands
//Byte MOT_COMAND                nºbit    7   6   5   4   3   2   1   0
//                                       --------------------------------
//Movement commands
#define   COM_STR         0x00   //      "0   0   0   0   0   0   CT  RL"
#define   COM_CHA_VEL     0x01   //      "0   0   0   0   0   1   CT  RL"
#define   COM_ROT         0x02   //      "0   0   0   0   1   0   CT  RL"
#define   COM_CUR         0x03   //      "0   0   0   0   1   1   CT  RL"
#define   COM_STOP        0x04   //      "0   0   0   1   0   0   CT  RL"

//Information commands
#define   STATUS_T        0x00   //      "1   0   0   0   0   0   0   0 "
#define   STATUS_A        0x01   //      "1   0   0   0   0   0   0   1 "
#define   STATUS_V_R      0x02   //      "1   0   0   0   0   0   1   0 "
#define   STATUS_V_L      0x03   //      "1   0   0   0   0   0   1   1 "
#define   STATUS_D_R      0x04   //      "1   0   0   0   0   1   0   0 "
#define   STATUS_D_L      0x05   //      "1   0   0   0   0   1   0   1 "
#define   STATUS_KM       0x06   //      "1   0   0   0   0   1   1   0 "

//Reset commands
#define   RST_T           0x00   //      "1   1   1   1   0   0   0   0 "
#define   RST_D           0x01   //      "1   1   1   1   0   0   0   1 "
#define   RST_KM          0x02   //      "1   1   1   1   0   0   1   0 "


//Parameters
#define   RIGHT           1
#define   LEFT            0

#define   DISTANCE        0
#define   TIME            1
#define   ANGLE           0

#define   FWD             1
#define   BACK            0

#define   CENTER          1
#define   WHEEL           0


//*****************************************************
//*                   MOT_CONFIG()                    *
//*****************************************************
//*Description:This function is inunsigned charged of the      *
//*configuration for the PIC to make possible the     *
//*communication with the engine module.		      * 
//*****************************************************
//*Input variables:    								  *
//*Output variables:   							      *
//*****************************************************
void MOT_CONFIG(void);


//*****************************************************
//*        MOT_STR(unsigned char, unsigned char, unsigned char, unsigned char)            *
//*****************************************************
//*Description: Command to make Moway walk straight   *
//*on. It is necessary to specify the speed,          *
//*the direction, the kind of command and the time or *
//*the distance.							  		  *
//*****************************************************
//*Input variables:		- MOT_VEL    : 0    - 100     *
//*                     - FWDBACK    : FWD  - BACK    *
//*                     - COMTYPE    : TIME - DISTANCE*
//*                     - MOT_T_DIST : 0    - 255     *
//*Output variables:    ----------------------------- *
//*Output:	            - 0: Correct sending          *
//*                     - 1: Wrong sending		      *
//*                     - 2: Wrong data               *
//*****************************************************
unsigned char MOT_STR(unsigned char MOT_VEL,unsigned char FWDBACK,unsigned char COMTYPE, unsigned char MOT_T_DIST);


//*****************************************************
//*     MOT_CHA_VEL(unsigned char, unsigned char, unsigned char, unsigned char, unsigned char)     *
//*****************************************************
//*Description: Command to make the Moway change the  *
//*speed of one of the engines. It is necessary to    *
//*specify the speed, the direction, if it is the     *
//*right or the left engine the one to be changed,    *
//*the kind of command and the time or the distance.  *
//*****************************************************
//*Input variables:     - MOT_VEL    : 0    - 100     *
//*                     - FWDBACK    : FWD  - BACK    *
//*                     - RL         : RIGHT- LEFT    *
//*                     - COMTYPE    : TIME - DISTANCE*
//*                     - MOT_T_DIST : 0    - 255     *
//*Output variables:    ----------------------------- *
//*Output:	            - 0: Correct sending          *
//*                     - 1: Wrong sending            *
//*                     - 2: Wrong data               *
//*****************************************************
unsigned char MOT_CHA_VEL(unsigned char MOT_VEL,unsigned char FWDBACK,unsigned char RL,unsigned char COMTYPE,unsigned char MOT_T_DIST);


//*****************************************************
//*     MOT_ROT(unsigned char, unsigned char, unsigned char, unsigned char, unsigned char, unsigned char)   *  
//*****************************************************
//*Description: Command to make Moway rotate. It is   *
//*necessary to specify the speed, the direction, if  *
//*the rotation is about the center or a wheel, the   *
//*kind of command and the time or the angle.         *
//*****************************************************
//*Input variables:		- MOT_VEL     : 0     - 100   *
//*                     - FWDBACK     : FWD   - BACK  *
//*                     - MOT_CENWHEEL: CENTER- WHEEL *
//*                     - RL          : RIGHT - LEFT  *
//*                     - COMTYPE     : TIME  - ANGLE *
//*                     - MOT_T_ANG   :(0-255)-(0-100)*
//*Output variables:    ----------------------------- *
//*Output:              - 0: Correct sending          *
//*                     - 1: Wrong sending	          *
//*                     - 2: Wrong data		          *
//*****************************************************
unsigned char MOT_ROT(unsigned char MOT_VEL,unsigned char FWDBACK,unsigned char MOT_CENWHEEL,unsigned char RL,unsigned char COMTYPE,unsigned char MOT_T_ANG);


//*****************************************************
//*     MOT_CUR(unsigned char, unsigned char, unsigned char, unsigned char, unsigned char, unsigned char)   *
//*****************************************************
//*Description: Command for curves. It is necessary	  *
//*to specify the speed, the direction, the radio,    *
//*if the curve is to the left or to the right, the   *
//*kind of command and the time or the distance.   	  *
//*****************************************************
//*Input variables:		- MOT_VEL : 0     - 100       *
//*                     - FWDBACK : FWD   - BACK      *
//*                     - MOT_RAD :                   *
//*                        - 0<(MOT_VEL-MOT_RAD)<100  *
//*                     - RL      : RIGHT- LEFT       *
//*                     - COMTYPE : TIME - DISTANCE   *
//*                     - MOT_T_DIST  : 0    - 255    *
//*Output variables:    ----------------------------- *
//*Output:	            - 0: Correct sending          *
//*                     - 1: Wrong sending        	  *
//*                     - 2: Wrong data		          *
//*****************************************************
unsigned char MOT_CUR(unsigned char MOT_VEL,unsigned char FWDBACK,unsigned char MOT_RAD,unsigned char RL,unsigned char COMTYPE, unsigned char MOT_T_DIST);


//*****************************************************
//*                    MOT_STOP()                     *
//*****************************************************
//*Description: Command to make Moway stop.           *
//*****************************************************
//*Input variables:     							  *
//*Output variables:     							  *
//*Output:              - 0: Correct sending          *
//*                     - 1: Wrong sending            *
//*                     - 2: Wrong data               *
//*****************************************************
unsigned char MOT_STOP(void);


//*****************************************************
//*                  MOT_RST(unsigned char)                    *
//*****************************************************
//*Description: Command to reset the time,            *
//*distance or the speedometer.                       *
//*****************************************************
//*Input variables:         -RST_COM:                 *
//*                         -RST_T                    *
//*                         -RST_D                    *
//*                         -RST_KM                   *
//*Output variables:                                  *
//*              		- 0: Correct sending          *
//*                     - 1: Wrong sending            *
//*****************************************************
unsigned char MOT_RST(unsigned char RST_COM);


//*****************************************************
//*                 MOT_FDBCK(unsigned char)                  *
//*****************************************************
//*Description: Command to know several parameters    *
//*from the engine module: the time, the walked angle,*
//*the speed of the two engines, the walked distance  *
//*and the speedometer value (2 output variables).    *
//*****************************************************
//*Input variables:			-STATUS_COM:              *
//*                         -STATUS_T                 *
//*                         -STATUS_A                 *
//*                         -STATUS_V_R               *
//*                         -STATUS_V_L               *
//*                         -STATUS_D_R               *
//*                         -STATUS_D_L               *
//*                         -STATUS_KM                *
//*Output variables:        					      *
//*Salida:              - Pointer to 2 unsigned char			  *
//*****************************************************
unsigned char* MOT_FDBCK(unsigned char STATUS_COM);









//*********Variables to indicate the obstacle sensor to be checked**********//
#define     OBS_CENTER_L   0
#define     OBS_SIDE_L     1
#define     OBS_CENTER_R   2
#define     OBS_SIDE_R     3

//*********Variables to indicate the accelerometer axes to be checked**********//
#define  ACCE_CHECK_X   0
#define  ACCE_CHECK_Y   1
#define  ACCE_CHECK_Z   2
   
//*********Variables to indicate the line to be checked**********//
#define  LINE_L         0
#define     LINE_R         1

//*********Variables to check speaker mode**********//
#define     SPEAKER_OFF    0     
#define     SPEAKER_ON     1     
#define  SPEAKER_TIME   2     



//*****************************************************
//*                  SEN_CONFIG()                     *
//*****************************************************
//*Descripción: The function configurates the pic I/Os*
//*         and the ADC.                          *
//*****************************************************
//*Input variables:                                   *
//*Output variables:                                  * 
//*****************************************************
void SEN_CONFIG(void);


//*****************************************************
//*                  SEN_LIGHT                        *
//*****************************************************
//*      Description:It returns the light percentage   *
//*      from the light sensor (0-100)             *
//*****************************************************
//*Input variables:                                   *
//*Output variables: -SEN_LIGHT_P                     *
//*****************************************************
unsigned char SEN_LIGHT(void);
 

//*****************************************************
//*                  SEN_BATTERY                      *     
//*****************************************************
//*Description:It returns the battery level           *
//*****************************************************
//*Input variables:                                   *
//*Output variables: -SEN_BATTERY_P                   *
//*****************************************************
unsigned char SEN_BATTERY(void);


//*****************************************************
//*                  SEN_TEMPERATURE                  *
//*****************************************************
//*Description:It returns the temperature             *
//*****************************************************
//*Input variables:                                   *
//*Output variables: -SEN_TEMPERATURE_P               *
//*****************************************************
unsigned char SEN_TEMPERATURE (void);


//*****************************************************
//*                  SEN_MIC_ANALOG                   *     
//*****************************************************
//*         Description:It returns the analog         *
//*            value form the microphone             *
//*****************************************************
//*Input variables:                                   *
//*Output variables: -SEN_MIC                         *
//*****************************************************
unsigned char SEN_MIC_ANALOG (void);


//*****************************************************
//*                  SEN_MIC_DIG                      *  
//*****************************************************  
//*         Description:It returns the digital        *
//*            value of the microphone            *
//*****************************************************
//*Input variables:                                   *
//*Output variables: -SEN_MIC                         *
//*****************************************************
unsigned char SEN_MIC_DIG (void);


//*****************************************************
//*                  SEN_SPEAKER                      *  
//*****************************************************
//* Description:It activates the buzzer to the        * 
//*         indicated time and frequency             *
//*****************************************************
//*Input variables:      -SEN_SPEAKER_FREQ            *          
//*                      -SEN_SPEAKER_TIME  (100ms)   *                           
//*                                            *
//*Output variables:                                  *
//*****************************************************
unsigned char SEN_SPEAKER ( unsigned char SEN_SPEAKER_FREQ, unsigned char SEN_SPEAKER_TIME, unsigned char SEN_SPEAKER_ON_OFF);


//*****************************************************
//*               SEN_OBS_ANALOG()                    *
//*****************************************************
//*  Description: It returns if an obstacle has been  *
//*  detected on the right or left side of the Moway. *
//*****************************************************
//*Input variables:     -OBS_SIDE_L                   *
//*                  -OBS_CENTRAL_L                *
//*                  -OBS_CENTRAL_R               *         
//*                  -OBS_SIDE_R               *                             
//*Output variables:   -SEN_OBS_CENTER_R              *
//*                     -SEN_OBS_CENTER_L         *
//*                  -SEN_OBS_SIDE_R               *
//*                     -SEN_OBS_SIDE_L               *
//*Output:              -0:External signal detected   *
//                        (Moway or interference)     *
//                      -(1-255):Correct reading      *
//*****************************************************
unsigned char SEN_OBS_ANALOG(unsigned char OBS_TO_CHECK);


unsigned char SEN_OBS_DIG (unsigned char OBS_TO_CHECK);


//*****************************************************
//*                 SEN_ACCE_XYZ_READ                 *
//*****************************************************
//*      Description: It returns the accelerometer      *
//*               x,y,z value.                      *
//*****************************************************
//*Input variables:     -ACCE_CHECK_X             *
//*                  -ACCE_CHECK_Y             *
//*                  -ACCE_CHECK_Z             *
//*Output variables:    -SEN_ACCE_X                   *
//*                     -SEN_ACCE_Y                   *
//*                     -SEN_ACCE_Z                   *
//*Output:                                     *
//*                       -0:Incorrect reading       *
//*                       -(1-255):Correct reading    *
//*****************************************************
unsigned char SEN_ACCE_XYZ_READ(unsigned char ACCE_TO_CHECK);


//;*****************************************************
//;*                 SEN_ACCE_CHECK_TAP               *  
//;*****************************************************
//;*Description: It verifies if Moway has beaten on not*
//;*****************************************************
//;*Input variables:                                   *
//;*Output variables: -SEN_ACCE_TAP                    *
//;*****************************************************
unsigned char SEN_ACCE_CHECK_TAP(void);


//*****************************************************
//*               SEN_LINE_ANALOG()                   *     
//*****************************************************
//*Description: It returns the clarity of the floor.  *
//*It can differenciate colors depending on the       *
//*material.                                          *
//*****************************************************
//*Input variables:     -LINE_R                   *
//*                  -LINE_L                       *
//*Output variables:    -SEN_LINE_R                   *
//*                     -SEN_LINE_L                   *
//*****************************************************
unsigned char SEN_LINE_ANALOG (unsigned char LINE_TO_CHECK);


//*****************************************************
//*               SEN_LINE_DIG()                      *     
//*****************************************************
//*Description: It returns if it has detected a black * 
//*line in a white floor.                             *
//*****************************************************
//*Input variables:     -LINE_R                   *
//*                  -LINE_L                       *                 
//*Output variables:    -SEN_LINE_R                   *
//*                     -SEN_LINE_L                   *
//*****************************************************
unsigned char SEN_LINE_DIG(unsigned char LINE_TO_CHECK);


//*****************************************************
//*                   LED_xx_xx()                     *           
//*****************************************************
//*Description: Functions for the use of the LEDs     *
//*****************************************************
//*Input variables:                                   *
//*Output variables:                                  *
//*****************************************************

//The switch on of the front LED
void LED_FRONT_ON(void);
//The switch off of the front LED
void LED_FRONT_OFF(void);
//The blinking of the front LED
void LED_FRONT_ON_OFF(void);
//The switch on of the brake LED
void LED_BRAKE_ON(void);
//The switch off of the brake LED
void LED_BRAKE_OFF(void);
//The blinking of the brake LED
void LED_BRAKE_ON_OFF(void);
//The switch on of the top red LED
void LED_TOP_RED_ON(void);
//The switch off of the top red LED
void LED_TOP_RED_OFF(void);
//The blinking of the top red LED
void LED_TOP_RED_ON_OFF(void);
//The switch on of the top green LED
void LED_TOP_GREEN_ON(void);
//The switch off of the top green LED
void LED_TOP_GREEN_OFF(void);
//The blinking of the top green LED
void LED_TOP_GREEN_ON_OFF(void);

