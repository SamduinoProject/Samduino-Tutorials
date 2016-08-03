/*
Possible SDCard file option
FA_READ       
FA_OPEN_EXISTING  
FA_WRITE      
FA_CREATE_NEW   
FA_CREATE_ALWAYS  
FA_OPEN_ALWAYS    
 */

//message to write to SD card
char writeBuffer[] = "Test write to sd card from Samduino!";

void setup() 
{
  Serial.begin(9600);
  SDCard.init();
  //open the file with FA_WRITE and FA_CREATE_ALWAYS flags to essentially create or overwrite
  SDCard.openFile("testFileWrite.txt", FA_WRITE | FA_CREATE_ALWAYS);
  //write the message to the file
  SDCard.write(writeBuffer, sizeof(writeBuffer));
  //close it so that we can use the SDCard again later
  SDCard.closeFile();
}

void loop() 
{
  //make a read buffer
  char readBuffer[sizeof(writeBuffer)];
  //Open the file to read
  SDCard.openFile("testFileWrite.txt", FA_READ);
  //read from sd card
  SDCard.read(readBuffer, sizeof(writeBuffer));
  //close the file to free up the SD card
  SDCard.closeFile();
  //print what we read
  Serial.print("Read from SD card: ");
  Serial.println(readBuffer);
  delay(1000);
}
