// UDPSocket.h
//
/// Class for managing a UDP socket, using the Ethernet classes
/// This is needed because the recvfrom function in utilitysocket.c in Ethernet does not
/// work very well
//
// Author: Mike McCauley (mikem@airspayce.com)
// $Id: UDPSocket.h,v 1.1 2009/10/13 05:07:28 mikem Exp mikem $

#ifndef _UDPSOCKET_H_
#define _UDPSOCKET_H_

#if ARDUINO >= 100
#include <Arduino.h>
#else
#include <wiring.h>
#endif

/// IP4Address 
typedef uint8_t IP4Address[4];

/////////////////////////////////////////////////////////////////////
/// \class UDPSocket UDPSocket.h <UDPSocket.h>
/// \brief Class to encapsulate a UDP socket
///
/// This class is used by RadiusMsg to send and receive UDP requests on a LAN through
/// the Arduino Ethernet shield.
/// This is needed because the revfrom function in utilitysocket.c in the Ethernet library does not
/// work properly
class UDPSocket
{
private:
    /// The socket number
    uint8_t  sock;
  
public:
    /// Constructor
    UDPSocket();

    /// Initialise the socket
    void begin();

    /// Send octets to the given address
    /// \param[in] data Data octets to send in a UDP packet
    /// \param[in] length Number of octets of data
    /// \param[in] address IP4Address of teh destination host
    /// \param[in] port Port number of the destination pport
    uint16_t sendto(const uint8_t* data, uint16_t length, IP4Address address, uint16_t port);

    /// Checks whether a UDP packet is available.
    /// \return Returns the number of octets in the next available packet, else 0
    uint16_t available();

    /// \param[in] data 
    /// \param[in] maxLength
    /// \param[in] address Pointer to an IP4Address which wil be filled in with the senders IP address
    /// \param[in] port Pointer to a port number which will be filled in with the senders port number
    uint16_t recvfrom(uint8_t* data, uint16_t maxLength, IP4Address address, uint16_t* port);
};

#endif
