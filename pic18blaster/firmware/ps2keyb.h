#ifndef _ps2keyb_h_
#define _ps2keyb_h_

void  kbd_init(void);			// : ������
uchar kbd_getchar(void);		// : ASCII �R�[�h���擾.
uchar kbd_peekcode(void);		// : FIFO�L���[��TOP������.
uchar kbd_getcode(void);		// : FIFO�L���[�̎��o������.
uchar kbd_getpress(uchar c);	// : ���A���^�C�� �C�ӃL�[�̉������ �̎擾.


void  kbd_int_handler(void);	// �莞���荞��.
void  kbd_handler(void);		// �G�b�W���荞��.

#endif	//_ps2keyb_h_