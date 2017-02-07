
#define LOGGER_LEVEL LL_WARN

#include <ctime>

#include "Args.hpp"
#include "Simhasher.hpp"
using namespace simhash;

int main(int argc, char** argv) {
	std::shared_ptr<Args> args = std::make_shared<Args>();
	args->parseArgs(argc, argv);
	Simhasher simhasher(args->dictPath, args->modelPath, args->idfPath, args->stopWords);
	long start = clock();
	int i = 0;
	for (; i < 100 * 10000; i++) {
		string s("我是蓝翔技工拖拉机学院手扶拖拉机专业的。不用多久，我就会升职加薪，当上总经理，出任CEO，走上人生巅峰。");
		uint64_t result = 0;
		simhasher.make(s, args->wordsTopN, result);
		cout << result << endl;
	}
	long used = clock() - start;
	cout << "Use time: " << (used / CLOCKS_PER_SEC) << "s" << endl;
	return EXIT_SUCCESS;
}
