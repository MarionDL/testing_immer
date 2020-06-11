/* 
 * File : vector_test.cpp
 * Author : Marion Dutu Launay
 * Date : 14.06.20
 * 
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <ctime>
#include <string>

#include <vector>
#include <immer/vector.hpp>
#include <immer/vector_transient.hpp>

std::vector<std::string> fill_std_vector(std::vector<std::string> dico_std) {

	/* Our timer */
	std::clock_t start_time;
	double duration;

	/* Input stream */
	std::ifstream s_std("dictionary.txt");
	std::string line;

	/* Start chrono */
	start_time = std::clock();

	/* Fill vector with dictionary words */
	while (getline(s_std, line)) {
		dico_std.push_back(line);
	}

	/* Compute elapsed time */
	duration = (std::clock() - start_time) / (double) CLOCKS_PER_SEC;
	std::cout << "Duration for standard vector (s) : " << std::endl << duration << std::endl;

	/* Close input stream */
	s_std.close();

	return dico_std;
}

immer::vector<std::string> fill_immer_vector(immer::vector<std::string> dico_im) {

	/* Our timer */
	std::clock_t start_time;
	double duration;

	std::ifstream s_im("dictionary.txt");
	std::string line;

	start_time = std::clock();

	/* Fill immutable vector. To do so, we must use the move() function */
	while (getline(s_im, line)) {
		dico_im = move(dico_im).push_back(line);
	}

	duration = (std::clock() - start_time) / (double) CLOCKS_PER_SEC;
	std::cout << "Duration for immutable vector (s) :" << std::endl << duration << std::endl;

	s_im.close();

	return dico_im;
}

immer::vector<std::string> fill_immer_tr_vector(immer::vector<std::string> dico_im) {

	/* Our timer */
	std::clock_t start_time;
	double duration;

	/* Immer transient vector */
	auto dico_im_tr = dico_im.transient();

	std::ifstream s_im_tr("dictionary.txt");
	std::string line;

	start_time = std::clock();

	/* Fill transient vector */
	while (getline(s_im_tr, line)) {
		dico_im_tr.push_back(line);
	}

	/* Make the vector persistent */
	dico_im = dico_im_tr.persistent();

	duration = (std::clock() - start_time) / (double) CLOCKS_PER_SEC;
	std::cout << "Duration for persistent vector (s) :" << std::endl << duration << std::endl;

	s_im_tr.close();

	return dico_im;
}

int main() {

	/* Standard vector */
	std::vector<std::string> dico_std;

	/* Immer vector */
	immer::vector<std::string> dico_im;

	fill_std_vector(dico_std);
	fill_immer_vector(dico_im);
	fill_immer_tr_vector(dico_im);

	return 0;
	
}