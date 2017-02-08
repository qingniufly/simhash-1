#ifndef ARGS_HPP
#define ARGS_HPP

#include <stdlib.h>
#include <string>
#include <iostream>

namespace simhash {

	class Args {
		public:
			std::string dictPath;
			std::string modelPath;
			std::string idfPath;
			std::string stopWords;
			int wordsTopN;
			int inputMode;
			std::string input;


			Args(){
				dictPath = "../../dict/jieba.dict.utf8";
				modelPath = "../../dict/hmm_model.utf8";
				idfPath = "../../dict/idf.utf8";
				stopWords = "../../dict/stop_words.utf8";
				wordsTopN = 5;
				inputMode = 0;	// 0 表示待转换为simhash的是一个句子
								// 1 表示从文件中读取输入，每行需要转换为一个simhash值
				input = "";
			}

			void printUsage() {
				std::cout
					<< "usage simhash <args>\n\n"
					<< "The args are:\n\n"
					<< "  -d	dict path\n"
					<< "  -m	model path\n"
					<< "  -i	idf path\n"
					<< "  -s	stopwords path\n"
					<< "  -w	top n keywords\n"
					<< "  -mode input mode (0 or 1, default 0), 0 for string, 1 for file\n"
					<< "  -in   input string or input file path\n"
					<< std::endl;
			}

			void parseArgs(int argc, char** argv) {
				if (argc < 2) {
					printUsage();
					exit(EXIT_FAILURE);
				}
				int ai = 1;
				while (ai < argc) {
					if (strcmp(argv[ai], "-d") == 0) {
						dictPath = std::string(argv[ai + 1]);
					} else if (strcmp(argv[ai], "-m") == 0) {
						modelPath = std::string(argv[ai + 1]);
					} else if (strcmp(argv[ai], "-i") == 0) {
						idfPath = std::string(argv[ai + 1]);
					} else if (strcmp(argv[ai], "-s") == 0) {
						stopWords = std::string(argv[ai + 1]);
					} else if (strcmp(argv[ai], "-w") == 0) {
						wordsTopN = atoi(argv[ai + 1]);
					} else if (strcmp(argv[ai], "-mode") == 0) {
						inputMode = atoi(argv[ai + 1]);
					} else if (strcmp(argv[ai], "-in") == 0) {
						input = std::string(argv[ai + 1]);
					} else {
						std::cout << "Unknown argument: " << argv[ai] << std::endl;
						printUsage();
						exit(EXIT_FAILURE);
					}
					ai = ai + 2;
				}
			}
	};
}

#endif
