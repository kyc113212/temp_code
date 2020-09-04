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
