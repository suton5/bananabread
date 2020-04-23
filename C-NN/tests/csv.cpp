#include <fstream>
#include <iostream>

#include "csv.h"

int main()
{
	std::string csv_filename( "csv_test.csv" );
	std::cout << "Creating CSV..." << csv_filename << std::endl;
	std::ofstream csv_ofs;
	csv_ofs.open( csv_filename );

	csv_ofs << "col0,col1,col2,   col3,\t\tcol4" << '\n';
	csv_ofs << "r00,r01,r02,   r03,\t\tr04" << '\n';
	csv_ofs << "r10,r11,r12,   r13,\t\tr14" << '\n';
	csv_ofs << "0.201,0.01,0.01231,   15.231,\t\t5e+10" << '\n';

	csv_ofs.close();

	io::CSVReader<3> in( csv_filename );
	in.read_header( io::ignore_extra_column, "col0", "col3", "col4" );
	std::string col0, col3, col4;
	while( in.read_row( col0, col3, col4 ) )
	{
		std::cout << col0 << "," << col3 << "," << col4 << '\n';
	}

	std::remove( csv_filename.c_str() );

	std::cout << "SUCCEEDED: CSV test" << std::endl;
	return 0;
}
