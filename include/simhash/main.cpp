
#define LOGGER_LEVEL LL_WARN

#include <ctime>
#include <iostream>
#include <fstream>

#include "Args.hpp"
#include "Simhasher.hpp"
using namespace simhash;

int main(int argc, char** argv) {
	std::shared_ptr<Args> args = std::make_shared<Args>();
	args->parseArgs(argc, argv);
	Simhasher simhasher(args->dictPath, args->modelPath, args->idfPath, args->stopWords);
	long start = clock();
	switch (args->inputMode) {
		case 0: {
					uint64_t result = 0;
//					cout << "输入是:\n" << args->input << endl;
					simhasher.make(args->input, args->wordsTopN, result);
					cout << result << endl;
					break;
				}
		case 1: {
					std::ifstream fin(args->input);
					string s;
					while (getline(fin, s)) {
//						cout << "输入是:\n" << s << endl;
						uint64_t result = 0;
						simhasher.make(s, args->wordsTopN, result);
						cout << result << "\t" << s << endl;
					}
					fin.close();
					break;
				}
	}
	long used = clock() - start;
	cout << "Use time: " << (used / CLOCKS_PER_SEC) << "s" << endl;


/**	
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
	*/

	return EXIT_SUCCESS;
}
