//
// Created by arvin on 2023-02-16.
//
#include "UdpPacketParser.h"

UdpPacketParser::UdpPacketParser(int source_port, int dest_port, int length, int checksum,
                                 char *data) : PacketParser(source_port, dest_port, length, checksum, data) {}


bool UdpPacketParser::parse(char const *packet) {
    return PacketParser::parse(packet);
}

void UdpPacketParser::display(std::ostream &os) const {
    PacketParser::display(os);
}

UdpPacketParser::~UdpPacketParser() = default;

