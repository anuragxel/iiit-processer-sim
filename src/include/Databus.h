#ifndef _DATABUS_H
#define _DATABUS_H

class Databus
{
	private:
		int Content;
		bool Busy;
		bool Corrupt;
	public:
		Databus() {
			this->Content = 0;
			this->Busy = false;
			this->Corrupt = false;
		}
		~Databus() {

		}

		void setContent(int content) {
			if (this->Busy){
				this->Corrupt = true;
			}
			this->Content = content;
			this->Busy = true;
		}
		int getContent() {
			return this->Content & 255;
		}

		bool isBusy() {
			return this->Busy == true;
		}
		void setBusy() {
			this->Busy = true;
		}
		void setBusy(bool busy) {
			this->Busy = busy;
		}

		void resetBusy() {
			this->Busy = false;
		}
		bool getBusy () {
			return this->Busy;
		}

		void resetCorrupt() {
			this->Corrupt = false;
		}
};

#endif
