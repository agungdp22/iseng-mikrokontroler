// UDPSocket.cpp
//
// Class for managing a UDP socket, using the Ethernet classes
// This is needed because the revfrom function in utilitysocket.c in Ethernet does not
// work very well
//
// Author: Mike McCauley (mikem@airspayce.com)
// $Id: UDPSocket.cpp,v 1.1 2009/10/13 05:07:28 mikem Exp mikem $

#if (ARDUINO < 100)
#include "WProgram.h"
#endif
#include "UDPSocket.h"
#include "utility/socket.h"
extern "C" 
{
#include "md5.h"
#include "utility/w5100.h"
}

static uint16_t nextSock = 0;
static uint16_t nextPort = 1024;

UDPSocket::UDPSocket()
{
  sock = nextSock++;
}

void 
UDPSocket::begin()
{
    socket(sock, SnMR::UDP, nextPort++, 0);
//    socket(sock, Sn_MR_UDP, nextPort++, 0);
}

uint16_t 
UDPSocket::sendto(const uint8_t* data, uint16_t length, IP4Address address, uint16_t port)
{
  return ::sendto(sock, data, length, address, port);
}

uint16_t 
UDPSocket::available()
{
    return W5100.readSnRX_RSR((SOCKET)sock);
//    return getSn_RX_RSR(sock);
}

uint16_t 
UDPSocket::recvfrom(uint8_t* data, uint16_t maxLength, IP4Address address, uint16_t *port)
{
  uint16_t packetLen = available() - 8; //skip UDP header;
  if (packetLen < 0 ) return 0; // no real data here       
  if (packetLen > maxLength) 
  {
    // packet is too large - truncate
    // HACK - hand-parse the UDP packet using TCP recv method
    uint8_t tmpBuf[8];
    uint16_t i;
    // read 8 header bytes and get IP and port from it
    recv((SOCKET)sock, tmpBuf, 8);
    address[0] = tmpBuf[0];
    address[1] = tmpBuf[1];
    address[2] = tmpBuf[2];
    address[3] = tmpBuf[3];
    *port = tmpBuf[4];
    *port = (*port << 8) + tmpBuf[5];
                
    // now copy first (bufLen) bytes into buf                
    for(i = 0; i < maxLength; i++)
    {
      recv(sock, tmpBuf, 1);
      data[i] = tmpBuf[0];
    }
                
    //and just read the rest byte by byte and throw it away
    while (available())
      recv(sock, tmpBuf, 1);
                
    return (-1 * packetLen);
  }
  
  // Enough space
  return ::recvfrom(sock, data, maxLength, address, port);
}

