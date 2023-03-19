//
// Created by arvin on 2023-02-16.
//
#include "TcpPacketParser.h"

TcpPacketParser::TcpPacketParser(int source_port, int dest_port, int sequence_number, int ack_number, int length,
                                 int ignore,int ignore2,int checksum,
                                 char *data) : PacketParser(source_port, dest_port, length, checksum, data) {
    this->sequence_number = sequence_number;
    this->ack_number = ack_number;
    this->ignore = ignore;
    this->ignore2 = ignore2;
    this->data = data;
    this->checksum = checksum;
}

bool TcpPacketParser::parse(const char *packet) {
    source_port = packet[0] * 0x100 + packet[1];
    dest_port = packet[2] * 0x100 + packet[3];
    sequence_number = (packet[4] * 0x1000000) + (packet[5] * 0x10000) + (packet[6] * 0x100) + packet[7];
    ack_number = (packet[8] * 0x1000000) + (packet[9] * 0x10000) + (packet[10] * 0x100) + packet[11];
    ignore = (packet[12] * 0x1000000) + (packet[13] * 0x10000) + (packet[14] * 0x100) + packet[15];
    checksum = packet[16] * 0x100 + packet[17];
    ignore2 = packet[18] * 0x100 + packet[19];
    length = packet[20] * 0x100 + packet[21];
    if (checksum != (source_port + dest_port + sequence_number + ack_number + ignore + ignore2 + length)) {
        // Packet is corrupted
        return false;
    }
    data = new char[length];
    memcpy(data, &packet[22], length);
    return true;
}

void TcpPacketParser::display(std::ostream &os) const {
    os << "Source port: " << source_port << std::endl;
    os << "Destination port: " << dest_port << std::endl;
    os << "Sequence number: " << sequence_number << std::endl;
    os << "Acknowledge number: " << ack_number << std::endl;
    os << "Data length: " << length << std::endl;
    os << "Data: " << data << std::endl;
}


TcpPacketParser::~TcpPacketParser() = default;

