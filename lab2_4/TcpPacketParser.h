//
// Created by arvin on 2023-02-16.
//

#ifndef LAB2_4_TCPPACKETPARSER_H
#define LAB2_4_TCPPACKETPARSER_H

#include "PacketParser.h"

class TcpPacketParser : public PacketParser {
    //using PacketParser :: PacketParser;
    int sequence_number;
    int ack_number;
    int ignore;
    int ignore2;

public:
    explicit TcpPacketParser(int source_port = 0, int dest_port = 0, int sequence_number = 0, int ack_number = 0,
                             int length = 0, int ignore=0,int ignore2=0,int checksum=0,char *data = nullptr);

    bool parse(const char *packet) override;

    void display(std::ostream &os) const override;


    ~TcpPacketParser() override;
};


#endif //LAB2_4_TCPPACKETPARSER_H
