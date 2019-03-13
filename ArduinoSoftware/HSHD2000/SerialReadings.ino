String Command = "" ;

void SerialSetup(void) {
  Serial.begin (9600);
}

bool GetCommand(void)
{
  static bool Busy = false;
  if (Serial.available())
  {
    char RxByte = Serial.read();

    if (RxByte == '%' && Busy)
    {
      //als het commando compleet is kan die worden doorgestuurd;
      externalCommand(Command);
      Busy = false;
      return true;
    }
    if (Busy)
    {
      Command = Command + RxByte;
    }
    if (RxByte == '#')
    {
      Command = "";
      Busy = true;
    }
  }
  return false;
}



