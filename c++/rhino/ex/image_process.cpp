//badger
int main(){
	Mat image;
	$CS path="/home/badger_code/document/code/cpp/lib/rhino/recource/badger.jpg";

	image=imread(path);

	int rows=image.rows;
	int cols=image.cols;

	int myArray[rows][cols];


	for (int i=0;i<rows;i++){
		for (int j=0;j<cols;j++) {
			myArray[i][j]=0;
		}
	}

	uint8_t* pixelPtr=(uint8_t*)image.data;

	int cn=image.channels();

	Scalar_<uint8_t> bgrPixel;

	for(int i=0;i<rows;i++){
		for(int j=0;j<cols;j++){
			bgrPixel.val[0]=pixelPtr[i*image.cols*cn+j*cn+0]; //b
			bgrPixel.val[1]=pixelPtr[i*image.cols*cn+j*cn+1]; //g
			bgrPixel.val[2]=pixelPtr[i*image.cols*cn+j*cn+2]; //r

			int average=(bgrPixel.val[0]+bgrPixel.val[1]+bgrPixel.val[2])/3;
			myArray[i][j]=average;
		}
	}

	Mat averaged_image(Size(rows,cols),CV_32S,myArray,Mat::AUTO_STEP);

	imwrite(path,averaged_image);

	imshow("averaged_image",averaged_image);

	waitKey(0);

	return 0;
}