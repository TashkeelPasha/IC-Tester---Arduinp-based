#define OR_BTN_PIN A5
#define XOR_BTN_PIN A2
#define AND_BTN_PIN A1 
#define NAND_BTN_PIN A0 
#define RED_LED_PIN A4
#define GRN_LED_PIN A3
#define DEBOUNCE_DELAY 150

unsigned long lastMillis = 0;

unsigned orResultMatrix[4][3] = {
  { 0, 0, 0 },
  { 0, 1, 1 },
  { 1, 0, 1 },
  { 1, 1, 1 }
};

unsigned xorResultMatrix[4][3] = {
  { 0, 0, 0 },
  { 0, 1, 1 },
  { 1, 0, 1 },
  { 1, 1, 0 }
};

unsigned andResultMatrix[4][3] = {  
  { 0, 0, 0 },
  { 0, 1, 0 },
  { 1, 0, 0 },
  { 1, 1, 1 }
};

unsigned nandResultMatrix[4][3] = {
  { 0, 0, 1 },
  { 0, 1, 1 },
  { 1, 0, 1 },
  { 1, 1, 0 }
};

void setup()
{
  pinMode(OR_BTN_PIN, INPUT);
  pinMode(XOR_BTN_PIN, INPUT);
  pinMode(AND_BTN_PIN, INPUT); 
  pinMode(NAND_BTN_PIN, INPUT); 
  pinMode(RED_LED_PIN, OUTPUT);
  pinMode(GRN_LED_PIN, OUTPUT);
  
  turnLEDsOff();
  resetPins();
}

void resetPins(void)
{
  for(int i = 1; i <= 13; i++) 
    pinMode(i, INPUT);
}

void initPositiveFourGateTest(void)
{
  pinMode(1, INPUT);
  pinMode(2, INPUT);
  pinMode(3, OUTPUT); 
  pinMode(4, OUTPUT);
  pinMode(5, INPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, INPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, INPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
}

void initNegativeFourGateTest(void)
{
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, INPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, INPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, INPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, INPUT);
}

bool testTwoInputGate(unsigned testCase[4][3], unsigned a, unsigned b, unsigned y)
{
  bool result = true;
  
  for(int i = 0; i < 4; i++)
  {
    digitalWrite(a, testCase[i][0]);
    digitalWrite(b, testCase[i][1]);
    result = result & (digitalRead(y) == testCase[i][2]);
  }
  
  return result;
}

bool doFourGateTest(unsigned testCase[4][3], bool positive)
{
  bool result = true;
  
  if(positive)
  {
    initPositiveFourGateTest();
    result = result & testTwoInputGate(testCase, 13, 12, 11);
    result = result & testTwoInputGate(testCase, 10, 9, 8);
    result = result & testTwoInputGate(testCase, 7, 6, 5);
    result = result & testTwoInputGate(testCase, 4, 3, 2);
  }
  else
  {
    initNegativeFourGateTest();
    result = result & testTwoInputGate(testCase, 2, 3, 4);
    result = result & testTwoInputGate(testCase, 5, 6, 7);
    result = result & testTwoInputGate(testCase, 8, 9, 10);
    result = result & testTwoInputGate(testCase, 11, 12, 13);
  }
  
  resetPins();
  
  return result;
}

void turnLEDsOff(void)
{
  digitalWrite(GRN_LED_PIN, LOW);
  digitalWrite(RED_LED_PIN, LOW);
}

void displayTestResult(bool success)
{
  digitalWrite(GRN_LED_PIN, success);
  digitalWrite(RED_LED_PIN, !success);
}

void loop()
{
  unsigned long currentMillis = millis();
  
  if(currentMillis - lastMillis > DEBOUNCE_DELAY)
  {
    if(digitalRead(OR_BTN_PIN))
      displayTestResult(doFourGateTest(orResultMatrix, true));
    else if(digitalRead(XOR_BTN_PIN))
      displayTestResult(doFourGateTest(xorResultMatrix, true));
    else if(digitalRead(AND_BTN_PIN))  
      displayTestResult(doFourGateTest(andResultMatrix, true));  
    else if(digitalRead(NAND_BTN_PIN))  
      displayTestResult(doFourGateTest(nandResultMatrix, true));  
      
    lastMillis = currentMillis;
  }
}
