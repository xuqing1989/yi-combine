#include<iostream>
#include<string>
#include<fstream>
#include<sstream>

using namespace std;

int main() {
	//3C_GF_cov1_100_1.txt
	string rootPath = "E:/matrices/cov1/";
	string p1[] = { "3C","3CR","CU" };
	string p2[] = { "GF","PV","SV" };
	//string p3[] = { "cov1" };
	string p4[] = {"100","250","500","1000"};
	for (int i1 = 0;i1 < 3;i1++) {
		for (int i2 = 0;i2 < 3;i2++) {
			//create file
			ofstream outfile(rootPath + "combined/" + p1[i1] + "_" + p2[i2] + "_cov1_" + "combined.txt");
			for (int i4 = 0;i4 < 4;i4++) {
				for (int j = 1;j <= 81;j++) {
					stringstream ss;
					string fname;
					ss << j;
					ss >> fname;
					string filename = p1[i1] + "_" + p2[i2] + "_cov1_" + p4[i4] + "_" + fname + ".txt";
					string fullPath = rootPath + filename;
					ifstream infile(fullPath);
					int counter = 0;
					while (!infile.eof()) {
						string temp;
						getline(infile, temp);
						if (temp.size() && (temp[2] == ' ' || temp[2] == '1')) {
							temp = filename + temp;
							counter++;
						}
						if (temp != "") {
							outfile << temp << endl;
						}
					}
					if (counter != 100) {
						cout << filename;
					}
				}
			}
		}
	}
	return 0;
}
