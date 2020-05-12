/* speed.c
   
*   created on: 4 May 2020
   
 *  Author : M Rajesh
   
   */


#include "speedometer.h"
#include "telltales.h"

/* This function monitors speed of vehicle, 
   odometer count, trip-1 and trip 2 count */
   
void speed(EngineDataOut *engineSpeed)
{


	/* Local variable for speed */
  volatile uint16_t speed = 0;
  
  /* Local variables for odometer count */
  uint16_t tempVar = 0;
  uint16_t countVal = 0;
  uint16_t odometerCount = 0;
  
  /*Local variables for trip-1 and trip-2 Count */
  uint16_t tripOneMeterCount = 0;
  uint16_t tripTwoMeterCount = 0;
  
  /* input switches for Reset trip-1 and trip-2 Count */
  uint16_t trip_1_Switch = 0;
  uint16_t trip_2_Switch = 0;
  
  
  /* Depending on input rpm  speed changes */


  speed = engineSpeed->rpm * RESOLUTION;


  servo_write((speed/MAX_SPEED)*180, ENGINE_SPEED_GAUGE);

  HAL_Delay(20);



  for(tempVar = 0; tempVar <= rpm; tempVar++)
  {
    countVal = countVal + 1;
    
    /* for every one kilometer odometer incremented */ 
    if(countVal == ONEKM)
    {
      /* for odometer count */
      odometerCount = odometerCount + 1;
      
      /* for trip-1 count */
      tripOneMeterCount = tripOneMeterCount + 1;
      
      /* for trip-2 count */
      tripTwoMeterCount = tripTwoMeterCount + 1;
      
      
      /* for Reset trip-1 count */
      if((trip_1_Switch == 1 || tripOneMeterCount == 99))
      {
    
        tripOneMeterCount = 0;
      }
      
      /* for Reset trip-2 count */
       if((trip_2_Switch == 1 || tripTwoMeterCount == 999))
      {   
         tripTwoMeterCount = 0;
      }
      
      countVal = 0;
    }
  }
   
}




 
 
 
 
