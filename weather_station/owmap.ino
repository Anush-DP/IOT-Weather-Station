/*
   Copyright (C) 2019 Anush DP
   License: GNU GPL3
*/

int getWeatherData()   //client function to send/receive GET request data.
{
  if (client.connect("api.openweathermap.org", 80))
  { //starts client connection, checks for connection
    client.println("GET /data/2.5/weather?id=" + CityID + "&units=metric&APPID=" + APIKEY);
    client.println("Host: api.openweathermap.org");
    client.println("User-Agent: ArduinoWiFi/1.1");
    client.println("Connection: close");
    client.println();
  }
  while (client.connected() && !client.available())
    delay(1);                                          //waits for data
  while (client.connected() || client.available())
  { //connected or data available
    char c = client.read();                     //gets byte from ethernet buffer
    result = result + c;
  }

  client.stop();
  result.replace('[', ' ');
  result.replace(']', ' ');
  Serial.println(result);
  char jsonArray [result.length() + 1];
  result.toCharArray(jsonArray, sizeof(jsonArray));
  jsonArray[result.length() + 1] = '\0';
  StaticJsonBuffer<1024> json_buf;
  JsonObject &root = json_buf.parseObject(jsonArray);
  
  if (!root.success())
  {
    return;
  }
  
  retrun root["weather"][0]["id"];
}
