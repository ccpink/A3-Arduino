#define DATA1          4  // to pin 7 on the 4511
#define DATA2          5  // to pin 1 on the 4511
#define DATA3          6  // to pin 2 on the 4511
#define DATA4          7  // to pin 6 on the 4511
          
#define outputA 10
#define outputB 11

int num_array[10][4] = {
{LOW,LOW,LOW,LOW},
{HIGH,LOW,LOW,LOW},
{LOW,HIGH,LOW,LOW},
{HIGH,HIGH,LOW,LOW},
{LOW,LOW,HIGH,LOW},
{HIGH,LOW,HIGH,LOW},
{LOW,HIGH,HIGH,LOW},
{HIGH,HIGH,HIGH,LOW},
{LOW,LOW,LOW,HIGH},
{HIGH,LOW,LOW,HIGH}
};

int counter = 0; 
int aState;
int aLastState;  

void setup()
{
  Serial.begin(9600);

  pinMode( DATA1, OUTPUT );
  pinMode( DATA2, OUTPUT );
  pinMode( DATA3, OUTPUT );
  pinMode( DATA4, OUTPUT );
  
  pinMode (outputA,INPUT);
  pinMode (outputB,INPUT);
}


void loop()
{
   aState = digitalRead(outputA); 
   //If the state has changed from the last reading
   if (aState != aLastState){     
     //check if it going up or down
     if (digitalRead(outputB) != aState) { 
      if(counter <= 8){ //If it's going up and If the counter 
                        //isn't already above 8 then incremeent the counter
       counter ++;
      }
     } else {
      if(counter >= 1){ //If it's going down and If the counter 
                        //isn't already below 1 then incremeent the counter
       counter --;
      }
     }
     Serial.print("Position: ");
     Serial.println(counter);
   } 
   aLastState = aState; 

//Get the values to be outputted to the TTL decoder
    digitalWrite(DATA1, num_array[counter][0]);
    digitalWrite(DATA2, num_array[counter][1]);
    digitalWrite(DATA3, num_array[counter][2]);
    digitalWrite(DATA4, num_array[counter][3]);

   

    
  
}

void testFunction(){
  
  // //Testing Purpose 0 - 9 Output correctly
//  for(int i = 0; i < 10; i++)
//  {
//    digitalWrite(DATA1, num_array[i][0]);
//    digitalWrite(DATA2, num_array[i][1]);
//    digitalWrite(DATA3, num_array[i][2]);
//    digitalWrite(DATA4, num_array[i][3]);
//
//    delay(1000);
//  }
}
