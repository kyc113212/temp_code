namespace my
{
	struct FlashMemorySpy : FlashMemory {
		virtual bool read(int block) override {
			lastReadBlock_ = block;
			return true;
		}
		virtual bool write(int) override { return false; }
		virtual bool erase(int) override { return false; }

		int lastReadBlock_ = -1;
	};
}

void test_2_1()
{
	// TODO: // 문제2.(2-1)
	// 요청이 다음의 순서대로 발생하는 상황: W,1,4 -> R,2,2 -> M,4,1 -> D,1,1
	my::FlashMemorySpy spy;
	FTL ftl(spy);
	ftl.writeBlock(1, 4);
	ftl.readBlock(2, 2);
	ftl.modifyBlock(4, 1);
	ftl.deleteBlock(1, 1);
}

void test_2_2()
{
	// TODO: 문제2.(2-2) 
	// 요청이 다음의 순서대로 발생하는 상황: W,0,8 -> D,6,2 -> M,4,2 -> R,2,2 -> D,2,2
	my::FlashMemorySpy spy;
	FTL ftl(spy);
	ftl.writeBlock(0, 8);
	ftl.deleteBlock(6, 2);
	ftl.modifyBlock(4, 2);
	ftl.readBlock(2, 2);
	ftl.deleteBlock(2, 2);
}








/////////////////////////////////////////////////////////////////////////////////////


namespace my{
	struct CommunicatorSpy : Communicator {
		public:
			CommunicatorSpy(int keys[]) : spyKeys(keys) {}
			virtual int getReqInput() override {
					return spyKeys[index++];
			}
			virtual void send(int result) override{
				rst = result;
			}
		
		private:
			int* spyKeys;
			int index = 0;
			int rst;
	};
}

void test_2_1(void)
{
	int input[] = {12, 24, 38, -38, -12};
	my::CommunicatorSpy spy(input);
	MemoryAllocator myl(spy);
	
	for(int i = 0; i<5; i++){
		myl.processRequest();
	}
	// TODO: // 문제2.(2-1)
	// 요청 값의 입력이 다음의 순서대로 발생하는 상황: 12 -> 24 -> 38 -> -38 -> -12
}

void test_2_2(void)
{
	// TODO: 문제2.(2-2) 
	// 요청 값의 입력이 다음의 순서대로 발생하는 상황: 18 -> 21 -> -18 -> 33 -> 41 -> -33
	int inputs[] = { 18, 21, -18, 33, 41, -33 };
	FakeInput fakeInput(inputs);
	MemoryAllocator memory(fakeInput);

	for (int i = 0; i < 6; ++i)
		memory.processRequest();
}
