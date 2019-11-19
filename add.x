typedef int int_ptr<>;

struct Matrix {
  int_ptr matrix;
  int size1;
  int size2;
};

program ADD_PROG{
	version ADDS_VERS{
		string DateAndTime() = 1;
		int_ptr Sort(int_ptr) = 2;
		string List() = 3;
		Matrix MatrixMultiply(Matrix, Matrix) = 4;
		string ReverseEncryptedEcho(string) = 5;
	} = 1;
} = 0x30071315;

