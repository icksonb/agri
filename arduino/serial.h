
class Serial
{
	public:
		Serial(unsigned int baud);
		void write(unsigned char data);
		void writeFlush(unsigned char data);
		unsigned char read(void);
		void string(char s[]);
};