//
// Created by arvin on 2023-02-16.
//

#ifndef LAB2_4_UDPPACKETPARSER_H
#define LAB2_4_UDPPACKETPARSER_H

#include "PacketParser.h"

class UdpPacketParser : public PacketParser {
public:
    explicit UdpPacketParser(int source_port = 0, int dest_port = 0,
                             int length = 0, int checksum=0, char *data = nullptr);

    bool parse(const char *packet) override;

    void display(std::ostream &os) const override;


    ~UdpPacketParser() override;
};

#endif //LAB2_4_UDPPACKETPARSER_H
