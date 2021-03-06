/*
 * Zeta RF v2 Getting Started Code Example for VL (Variable Length) packets.
 * Basic example on how to receive messages using variable size packets.
 *
 * Usage: Simply run and all recieved messages will be printed!
 */

#include <iostream>
#include <iomanip>

#include <ZetaRf.hpp>

constexpr size_t MaxPacketLength {32};

ZetaRf868_VL<ZetaRf::nSEL<6>, ZetaRf::SDN<9>, ZetaRf::nIRQ<8>> zeta; // Wasn't using VL?! Check this

char data[MaxPacketLength] = "Hello World!";


bool setup()
{
  std::cout << "Starting Zeta Rx VL..." << std::endl;

  // Initialize Zeta module with a specific packet size
  if (!zeta.beginWithMaxPacketLengthOf(MaxPacketLength)) {
    std::cout << "ZetaRf begin failed. Check wiring?" << std::endl;
    return false;
  }

  // Print some info about the chip
  //EZRadioReply::PartInfo const& pi = zeta.readPartInformation();
  auto pi = zeta.readPartInformation();
  std::cout << "----------" << std::endl;
  std::cout << "Chip rev: " << (int)       pi.CHIPREV  << std::endl;
  std::cout << "Part    : " << std::hex << pi.PART     << std::dec << std::endl;
  std::cout << "PBuild  : " << (int)       pi.PBUILD   << std::endl;
  std::cout << "ID      : " <<             pi.ID       << std::endl;
  std::cout << "Customer: " << (int)       pi.CUSTOMER << std::endl;
  std::cout << "Rom ID  : " << (int)       pi.ROMID    << std::endl;
  std::cout << "Bond    : " << (int)       pi.BOND     << std::endl;
  std::cout << std::endl;

  /*auto fi = zeta.readFunctionRevisionInformation();
  std::cout << "Rev Ext   : " << (int)       fi.REVEXT     << std::endl;
  std::cout << "Rev Branch: " << (int)       fi.REVBRANCH  << std::endl;
  std::cout << "Rev Int   : " << (int)       fi.REVINT     << std::endl;
  std::cout << "Patch     : " << (int)       fi.PATCH      << std::endl;
  std::cout << "Func      : " << (int)       fi.FUNC       << std::endl;
  std::cout << "SVN Flags : " << (int)       fi.SVNFLAGS   << std::endl;
  std::cout << "SVN Rev   : " << std::hex << fi.SVNREV     << std::dec << std::endl;
  std::cout << "----------" << std::endl; //*/
  

  // Start continuous listening on channel 4 (auto-returns to listening after reception of a packet)
  //zeta.startListeningOnChannel(4);

  // Or just listen for one packet then wait (needed to be able to read a packet's RSSI)
  zeta.startListeningSinglePacketOnChannel(4);

  std::cout << "Init done." << std::endl;
  return true;
}



void loop()
{
  // At least one of the zeta.checkFor*Event*() methods must be called in order to update the library.
  // checkForEvent() returns any event of: Event::CrcError | Event::PacketTransmitted | Event::PacketReceived | Event::LatchedRssi
  //                                     | Event::TxFifoAlmostEmpty | Event::RxFifoAlmostFull | Event::FifoUnderflowOrOverflowError
  // checkForAnyEventOf(filter) enables you to filter events.
  // checkForAllEventsOf(filter) will return ZetaRf::Event::None unless all events in filter are present.
  //
  // Unfiltered events are accessible via zeta.events(). Use zeta.clearEvents([event]) to clear all or specified events.

  if (ZetaRf::Events const ev = zeta.checkForEvent()) {
    if (ev & ZetaRf::Event::DeviceBusy) {
      // DeviceBusy error usually means the radio module is unresponding and need a reset.
      std::cout << "Error: Device Busy! Restarting..." << std::endl;

      if (!zeta.beginWithMaxPacketLengthOf(MaxPacketLength)) {
        std::cout << "ZetaRf begin failed after comm error." << std::endl;
        while (true);
      }
      zeta.restartListeningSinglePacket();
    }

    if (ev & ZetaRf::Event::PacketReceived) {
      // We'll read data later
      // Get RSSI (only valid in single packet RX, before going back to RX)
      uint8_t const rssi = zeta.latchedRssiValue();

      // Restart listening on the same channel
      zeta.restartListeningSinglePacket();

      std::cout << "Packet received with RSSI: " << (int) rssi << std::endl;
    }

    if (ev & ZetaRf::Event::PacketTransmitted) {
      // Back to RX afer TX
      zeta.restartListeningSinglePacket();

      std::cout << "Packet transmitted" << std::endl;
    }
  }



  // Read incoming packet and print it
  if (zeta.available()) {
    uint8_t readSize {0};
    if (zeta.readVariableLengthPacketTo((uint8_t*)data, &readSize)) {

      //zeta.restartListeningSinglePacket(); // If not in checkForEvent

      // Print!
      std::cout << "RX (" << int(readSize) << ") >" << data << "<" << std::endl;

      // Print in HEX
      /*std::cout << "HEX >" << std::hex;
      for (uint8_t i = 0; i < zeta.packetLength(); i++) {
        std::cout << std::setfill('0') << std::setw(2) << (int) data[i];
      }
      std::cout << std::dec << "<" << std::endl; //*/
    }
  }


  delay(10); // Hooo, not too fast! But you could...
}

int main() {
  if (!setup()) return 1;

  while (true) loop();
}