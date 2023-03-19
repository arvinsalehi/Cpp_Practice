#include "PacketParser.h"


PacketParser::PacketParser(int source_port, int dest_port, int length, int checksum, char *data) {
    this->source_port = source_port;
    this->dest_port = dest_port;
    this->length = length;
    this->checksum = checksum;
    this->data = data;
}

bool PacketParser::parse(const char *packet) {
    source_port = packet[0] * 0x100 + packet[1];
    dest_port = packet[2] * 0x100 + packet[3];
    length = packet[4] * 0x100 + packet[5];
    checksum = packet[6] * 0x100 + packet[7];
    data = new char[length];
    memcpy(data, &packet[8], length);
    return true;
}

void PacketParser::display(std::ostream &os) const {
    os << "Source port: " << source_port << std::endl;
    os << "Destination port: " << dest_port << std::endl;
    os << "Data length: " << length << std::endl;
    os << "Data: " << data << std::endl;
}

std::ostream &operator<<(std::ostream &os, PacketParser &parser) {
    parser.display(os);
    return os;
}

