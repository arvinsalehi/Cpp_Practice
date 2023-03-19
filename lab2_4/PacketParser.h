//PacketParser.h - class declaration for a packet parser

#ifndef _PACKETPARSER_H_
#define _PACKETPARSER_H_

#include <iostream>
#include <cstring>

class PacketParser {
public:
    int source_port;
    int dest_port;
    int length;
    int checksum;
    char *data;

public:
    explicit PacketParser(int source_port = 0, int dest_port = 0, int length = 0, int checksum=0,char *data = nullptr);

    virtual bool parse(const char *packet);

    virtual void display(std::ostream &os) const;

    friend std::ostream &operator<<(std::ostream &os, PacketParser &parser);

    virtual ~PacketParser() = default;
};


#endif// _PACKETPARSER_H_