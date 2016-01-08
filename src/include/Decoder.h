#ifndef _DECODER_H
#define _DECODER_H

 #include <array>

class Decoder {
	private:
		std::array<int , 256> hashTable;
	public:
		Decoder();
		~Decoder();
		int getContent();

		Decoder(std::string);
		Decoder(std::fstream);
		Decoder(std::ifstream);
};

#endif
