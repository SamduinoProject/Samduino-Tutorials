//this is our example structure for holding unit id info
struct UnitId
{
  int id;
  uint8_t ipAddress[4];
  char descriptor[64];
  uint8_t flags;
};

void setup() 
{
  //init the serial for pc comms
  Serial.begin(9600);
  //init the flash module
  Flash.init();
  //create struct to store in flash
  UnitId unitId;
  //give the unit an ip address
  unitId.ipAddress[0] = 192;
  unitId.ipAddress[1] = 168;
  unitId.ipAddress[2] = 1;
  unitId.ipAddress[3] = 101;
  //give the unit an id
  unitId.id = 1234567;
  //copy a string into the descriptor
  memcpy(unitId.descriptor, "North west lower level temperature sensor", 42);
  //set some flags
  unitId.flags = 55;
  Flash.write(0, &unitId, sizeof(UnitId));
}

void loop() 
{
  //make a UnitId struct to test loading from flash
  UnitId unitId;
  //read our unitId struct from address 0
  Flash.read(0, &unitId, sizeof(UnitId));

  //print the ip address
  Serial.print("unitId ipAddress: ");
  Serial.print(unitId.ipAddress[0]);
  Serial.print(".");
  Serial.print(unitId.ipAddress[1]);
  Serial.print(".");
  Serial.print(unitId.ipAddress[2]);
  Serial.print(".");
  Serial.println(unitId.ipAddress[3]);

  //print the unit id
  Serial.print("unitId id: ");
  Serial.println(unitId.id);

  //print the descriptor string 
  Serial.print("UnitId descriptor: ");
  Serial.println(unitId.descriptor);

  //print the unit's set flags
  Serial.print("UnitId flags: ");
  Serial.println((int)unitId.flags);
  
  delay(1000);
}
