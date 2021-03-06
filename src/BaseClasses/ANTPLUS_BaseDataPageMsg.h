#ifndef ANTPLUS_BASEDATAPAGEMSG_h
#define ANTPLUS_BASEDATAPAGEMSG_h

#include <BaseClasses/ANTPLUS_CoreDataPage.h>

template<class T>
class BaseDataPageMsg : virtual public CoreDataPage<T> {
public:
    BaseDataPageMsg();
#ifndef UNIT_TEST
protected:
#endif // UNIT_TEST
    uint8_t get8BitValue(uint8_t byte, uint8_t mask = 0xFF, uint8_t shift = 0) override;
    uint16_t get16BitValue(uint8_t lsb_byte, uint8_t msb_byte, uint16_t mask = 0xFFFF, uint8_t shift = 0) override;
    uint32_t get24BitValue(uint8_t lsb_byte, uint8_t msb_byte, uint32_t mask = 0xFFFFFF, uint8_t shift = 0) override;
    uint32_t get32BitValue(uint8_t lsb_byte, uint8_t msb_byte, uint32_t mask = 0xFFFFFFFF, uint8_t shift = 0) override;
    void set8BitValue(uint8_t value, uint8_t byte, uint8_t mask = 0xFF, uint8_t shift = 0);
    void set16BitValue(uint16_t value, uint8_t lsb_byte, uint8_t msb_byte, uint16_t mask = 0xFFFF, uint8_t shift = 0);
    void set24BitValue(uint32_t value, uint8_t lsb_byte, uint8_t msb_byte, uint32_t mask = 0xFFFFFF, uint8_t shift = 0);
    void set32BitValue(uint32_t value, uint8_t lsb_byte, uint8_t msb_byte, uint32_t mask = 0xFFFFFFFF, uint8_t shift = 0);
};

#endif // ANTPLUS_BASEDATAPAGEMSG_h
