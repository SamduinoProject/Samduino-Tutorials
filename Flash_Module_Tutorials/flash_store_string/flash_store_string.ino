char message[] = "this is a test to store to flash memory!";

void setup() 
{
  //init the serial for pc comms
  Serial.begin(9600);
  //init the flash module
  Flash.init();
  //write test message to flash at address 0
  Flash.write(0, message, sizeof(message));
}

void loop() 
{
  //make a new buffer to read from flash
  char readBuffer[sizeof(message)];
  //read our test message from address 0
  Flash.read(0, readBuffer, sizeof(message));
  Serial.println("read from flash: ");
  Serial.println(readBuffer);
  delay(1000);
}
