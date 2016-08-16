#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <cstring>
#include <string>
#include <iostream>
#include <fstream>
#include <utility>
#include <vector>
#include <stdio.h>
#include <functional>
#include <map>
#include <sstream>
#include <iomanip>

using namespace std;

int main(int argc, char** argv) {

	 if (argc < 2) {
    	std::cout << "rectify_to_ellipse error";
    	return 0;
  	}

  	const float RATIO = 0.25;

  	ifstream in_file(argv[1]);
  	ofstream out_file(argv[2]);

  	int num;
    string img_name;
  	float x1, y1, w, h, score;
    
  	while(in_file >> img_name >> num) {
  		out_file << img_name << std::endl << num << std::endl;

  		for(int i = 0; i < num; ++i) {
  			in_file >> x1 >> y1 >> w >> h >> score;

  			out_file << setprecision(20) << setiosflags(ios::showpoint) 
                 << x1 << " " << y1 - RATIO * h  << " " 
                 << w  << " " << (1 + RATIO) * h << " " << score << std::endl;
  		}
  	}

  	in_file.close();
    out_file.close();
}
