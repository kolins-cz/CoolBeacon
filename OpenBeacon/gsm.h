#ifndef gsm_h
#define gsm_h


/*
    простенький класс для работы с SIM800

*/

#define RESPONCE_LENGTH 150

extern byte buf[];

class GSM: public AltSoftSerial
{
  public:
    GSM(void);
    static bool begin();
    static void end();
/*
    byte     available(void);
    byte     read(void);
    byte     peek(void);
    void     flush(void);
    size_t   write(uint8_t c);
*/
//    using AltSoftSerial::write;
//    using AltSoftSerial::read;
//    using AltSoftSerial::available;
//    using AltSoftSerial::flush;

    static void initGSM(void);
    static void readOut();
    static bool set_sleep(byte mode);
    static uint8_t wait_answer(const char* answer, unsigned int timeout);
    static uint8_t command(const char* cmd, const char* answer, uint16_t time);
    static uint8_t command(const char* cmd, const char* answer);
    static uint8_t command(const char* cmd);
    static bool sendSMS(char * text, char * phone);
    static bool sendUSSD(uint16_t text);
    int balance();
//  private:
    static char response[RESPONCE_LENGTH];
};

#endif