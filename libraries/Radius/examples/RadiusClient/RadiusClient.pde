// RadiusClient.pde
//
// Sample Radius Client using the Radius library for ArduinoMega and Ethernet Shield
//
// Note that in order to use the Ethernet Shield with ArduinoMega, you need to make some hardware adjustments. 
// See http://mcukits.com/2009/04/06/arduino-ethernet-shield-mega-hack/ 
// and http://www.arduino.cc/cgi-bin/yabb2/YaBB.pl?num=1252386632
// Note that 3 pins on the Ethernet shield must be bent out of the way to make this work.

//
// Author: Mike McCauley (mikem@airspayce.com)
// $Id: $

// Prevent compile complaints with some versi0ns of arduino:
#undef abs
#include <stdlib.h>

#include "SPI.h"
#include "Ethernet.h"
#include "RadiusMsg.h"
#include "UDPSocket.h"

// This is the MAC address that your Ethernet shield will use
// Configure to suit your needs
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
// Configure IP to be a suitable address for your network
IP4Address ip = { 203, 63, 154, 2 };
// Configure server to be the IP address of your RADIUS server
IP4Address server = { 203, 63, 154, 29 };
// Configure gateway to be the IP address of your gateway router
IP4Address gateway = { 203, 63, 154, 248 };

// Manage a UDP Socket:
UDPSocket client;

void setup()
{
  Serial.begin(9600);

  Ethernet.begin(mac, ip, gateway);
  client.begin();
  delay(1000); // Lets the Ethernet card get set up.
}

void loop()
{
  // Build a new Access Request
  RadiusMsg  msg(RadiusCodeAccessRequest);
  msg.addAttr(RadiusAttrUserName, 0, "mikem");
  msg.addAttr(RadiusAttrUserPassword, 0, "fred");
  msg.addAttr(RadiusAttrNASPort, 0, 0x01020304);
  msg.sign((uint8_t*)"mysecret", 8);
  // Send it and blocking wait for a reply. Retransmissions will occur if necessary
  // Check the reply
  RadiusMsg reply;
  if (msg.sendWaitReply(&client, server, 1645, &reply)
      && reply.checkAuthenticatorsWithOriginal((uint8_t*)"mysecret", 8, &msg)
      && reply.code() == RadiusCodeAccessAccept)
  {
    Serial.println("Got Access-Accept");
    uint8_t buf[255];
    uint8_t bufLength = 255;
    uint32_t protocol;
    // Get an attribute from the reply
    if (reply.getAttr(RadiusAttrFramedProtocol, 0, &protocol))
    {
//       Serial.println("Got framed protocol: ");
//       Serial.println(protocol, DEC);
    }
  }
  delay(1000);
}
