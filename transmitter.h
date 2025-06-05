void USART_Init( long unsigned int baud, long unsigned int f_cpu);
void USART_Transmit(unsigned char data);
void USART_TransmitStr(char *str);
unsigned char USART_Receive(void);
